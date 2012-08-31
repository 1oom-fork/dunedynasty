/* audio.c */

#include <assert.h>
#include <stdio.h>
#include <sys/stat.h>
#include "../os/math.h"

#include "audio.h"

#include "../config.h"
#include "../file.h"
#include "../gui/gui.h"
#include "../opendune.h"
#include "../sprites.h"
#include "../string.h"
#include "../table/widgetinfo.h"
#include "../tile.h"
#include "../tools.h"

bool g_enable_audio;

bool g_enable_music = true;
bool g_enable_effects = true;
bool g_enable_sounds = true;
bool g_enable_voices = true;
bool g_enable_subtitles = false;

float music_volume = 0.85f;
float sound_volume = 0.65f;
float voice_volume = 1.0f;

static enum HouseType s_curr_sample_set = HOUSE_INVALID;

static enum SampleID s_voice_queue[256];
static int s_voice_head = 0;
static int s_voice_tail = 0;

void
Audio_ScanMusic(void)
{
	bool verbose = false;
	struct stat st;
	char buf[1024];

	for (enum MusicID musicID = MUSIC_STOP; musicID < MUSICID_MAX; musicID++) {
		MusicInfo *m = &g_table_music[musicID];

		ExtMusicInfo *ext[] = {
			&m->fed2k_mt32,
			&m->d2tm_adlib,
			&m->d2tm_mt32,
			&m->d2tm_sc55,
			&m->dune2000,
			NULL
		};

		for (int i = 0; ext[i]; i++) {
			if (ext[i]->filename == NULL)
				continue;

			if (!ext[i]->enable) {
				if (verbose) fprintf(stdout, "[disable] %s\n", ext[i]->filename);
				continue;
			}

			snprintf(buf, sizeof(buf), "%s.flac", ext[i]->filename);
			if (stat(buf, &st) == 0) {
				if (verbose) fprintf(stdout, "[enable]  %s.flac\n", ext[i]->filename);
				continue;
			}

			snprintf(buf, sizeof(buf), "%s.ogg", ext[i]->filename);
			if (stat(buf, &st) == 0) {
				if (verbose) fprintf(stdout, "[enable]  %s.ogg\n", ext[i]->filename);
				continue;
			}

			snprintf(buf, sizeof(buf), "%s.AUD", ext[i]->filename);
			if (stat(buf, &st) == 0) {
				if (verbose) fprintf(stdout, "[enable]  %s.AUD\n", ext[i]->filename);
				continue;
			}

			ext[i]->enable = false;
			if (verbose) fprintf(stdout, "[missing] %s\n", ext[i]->filename);
		}
	}
}

void
Audio_PlayMusic(enum MusicID musicID)
{
	AudioA5_StopMusic();

	if (musicID == MUSIC_STOP)
		return;

	if ((!g_enable_audio) || (!g_enable_music) || (musicID == MUSIC_INVALID))
		return;

	const MusicInfo *m = &g_table_music[musicID];

	union {
		const MidiFileInfo *mid;
		const ExtMusicInfo *ext;
	} data[NUM_MUSIC_SETS];

	int num_types = 0;

	if (m->dune2_adlib.enable)  data[num_types++].mid = &m->dune2_adlib;
	if (m->fed2k_mt32.enable)   data[num_types++].ext = &m->fed2k_mt32;
	if (m->d2tm_adlib.enable)   data[num_types++].ext = &m->d2tm_adlib;
	if (m->d2tm_mt32.enable)    data[num_types++].ext = &m->d2tm_mt32;
	if (m->d2tm_sc55.enable)    data[num_types++].ext = &m->d2tm_sc55;
	if (m->dune2000.enable)     data[num_types++].ext = &m->dune2000;

	if (num_types <= 0)
		return;

	const int i = Tools_RandomRange(0, num_types - 1);

	if (data[i].mid == &m->dune2_adlib) {
		AudioA5_InitMusic(data[i].mid);
	}
	else {
		AudioA5_InitExternalMusic(data[i].ext);
	}
}

void
Audio_PlayMusicIfSilent(enum MusicID musicID)
{
	if (!Audio_MusicIsPlaying())
		Audio_PlayMusic(musicID);
}

void
Audio_PlayEffect(enum SoundID effectID)
{
	if ((!g_enable_audio) || (!g_enable_effects))
		return;

	AudioA5_PlaySoundEffect(effectID);
}

static char
Audio_GetSamplePrefix(enum HouseType houseID)
{
	switch (g_gameConfig.language) {
		case LANGUAGE_FRENCH:
			return 'F';

		case LANGUAGE_GERMAN:
			return 'G';

		default:
			if (houseID < HOUSE_MAX)
				return g_table_houseInfo[houseID].prefixChar;
			break;
	}

	return 'Z';
}

static void
Audio_LoadSample(const char *filename, enum SampleID sampleID)
{
	if (filename == NULL || !File_Exists(filename))
		return;

	const uint8 file_index = File_Open(filename, 1);
	const uint32 file_size = File_GetSize(file_index);

	AudioA5_StoreSample(sampleID, file_index, file_size);
	File_Close(file_index);
}

static void
Audio_LoadSampleForHouse(enum HouseType houseID, enum SampleID sampleID)
{
	const SoundData *s = &g_table_voices[sampleID];
	const char *filename;
	char buf[16];

	/* [+-/?]FILENAME. */
	filename = s->string + 1;
	switch (s->string[0]) {
		case '+':
			/* +: common to all houses. */
			if (s_curr_sample_set != HOUSE_INVALID)
				return;

			/* +%c: common to all houses, substitue with language prefix. */
			if (s->string[1] == '%') {
				char prefix = Audio_GetSamplePrefix(HOUSE_INVALID);
				snprintf(buf, sizeof(buf), s->string + 1, prefix);
				filename = buf;
			}
			break;

		case '-':
			/* -: common to all houses. */
			if (s_curr_sample_set != HOUSE_INVALID)
				return;
			break;

		case '/':
			/* /: mercenary only. */
			if (houseID != HOUSE_MERCENARY)
				return;
			break;

		case '?':
			/* ?%c: load as required, substitute with house or language prefix. */
			if (s->string[1] == '%') {
				char prefix = Audio_GetSamplePrefix(houseID);
				snprintf(buf, sizeof(buf), s->string + 1, prefix);
				filename = buf;
			}
			break;

		case '%':
			/* %c: substitute with house or language prefix. */
			{
				char prefix = Audio_GetSamplePrefix(houseID);
				snprintf(buf, sizeof(buf), s->string, prefix);
				filename = buf;
			}
			break;

		default:
			return;
	}

	Audio_LoadSample(filename, sampleID);
}

void
Audio_LoadSampleSet(enum HouseType houseID)
{
	if (!g_enable_audio)
		return;

	if (s_curr_sample_set == houseID)
		return;

	for (enum SampleID sampleID = 0; sampleID < SAMPLEID_MAX; sampleID++) {
		Audio_LoadSampleForHouse(houseID, sampleID);
	}

	s_curr_sample_set = houseID;
}

void
Audio_PlaySample(enum SampleID sampleID, int volume, float pan)
{
	if ((!g_enable_audio) || (!g_enable_sounds) || (sampleID == SAMPLE_INVALID))
		return;

	AudioA5_PlaySample(sampleID, (float)volume / 255.0f, pan);
}

void
Audio_PlaySoundAtTile(enum SoundID soundID, tile32 position)
{
	if (soundID == SOUND_INVALID)
		return;

	assert(soundID < SOUNDID_MAX);

	const enum SampleID sampleID = g_table_voiceMapping[soundID];

	if (!g_enable_sounds || (sampleID == SAMPLE_INVALID)) {
		Audio_PlayEffect(soundID);
	}

	if (g_enable_sounds && (sampleID != SAMPLE_INVALID)) {
		int volume = 255;
		float pan = 0.0f;

		if (position.tile != 0) {
			const WidgetInfo *wi = &g_table_gameWidgetInfo[GAME_WIDGET_VIEWPORT];
			const int cx = Tile_GetPackedX(g_viewportPosition) + wi->width / (2 * TILE_SIZE);
			const int cy = Tile_GetPackedY(g_viewportPosition) + wi->height / (2 * TILE_SIZE);
			const uint16 packed = Tile_PackXY(cx, cy);

			const int ux = Tile_GetPosX(position);

			volume = Tile_GetDistancePacked(packed, Tile_PackTile(position));
			if (volume > 64)
				volume = 64;

			volume = 255 - (volume * 255 / 80);
			pan = clamp(-0.5f, 0.05f * (ux - cx), 0.5f);
		}

		Audio_PlaySample(sampleID, volume, pan);
	}
}

void
Audio_PlaySound(enum SoundID soundID)
{
	tile32 tile;

	tile.tile = 0;
	Audio_PlaySoundAtTile(soundID, tile);
}

void
Audio_PlaySoundCutscene(enum SoundID soundID)
{
	if ((!g_enable_sounds) || (soundID == SOUND_INVALID))
		return;

	const enum SampleID sampleID = g_table_voiceMapping[soundID];
	if (sampleID != SAMPLE_INVALID)
		AudioA5_PlaySampleRaw(sampleID, voice_volume, -1000.0f, 1, 11);
}

static bool
Audio_QueueVoice(enum SampleID sampleID)
{
	const int index = (s_voice_tail + 1) & 0xFF;

	if (index == s_voice_head)
		return false;

	s_voice_queue[s_voice_tail] = sampleID;
	s_voice_tail = index;
	return true;
}

void
Audio_PlayVoice(enum VoiceID voiceID)
{
	if (voiceID == VOICE_INVALID)
		return;

	if (voiceID == VOICE_STOP) {
		s_voice_head = s_voice_tail;
		return;
	}

	assert(voiceID < VOICEID_MAX);
	const Feedback *s = &g_feedback[voiceID];

	if (s->soundId != SOUND_INVALID)
		Audio_PlayEffect(s->soundId);

	if (g_enable_voices) {
		for (int i = 0; i < NUM_SPEECH_PARTS; i++) {
			const enum SampleID sampleID = s->voiceId[i];

			if (sampleID == SAMPLE_INVALID)
				break;

			if (!Audio_QueueVoice(sampleID))
				break;
		}

		Audio_Poll();
	}

	if (g_enable_subtitles) {
		g_viewportMessageText = String_Get_ByIndex(s->messageId);
		g_viewportMessageCounter = 4;
	}
}

bool
Audio_Poll(void)
{
	if ((!g_enable_audio) || (!g_enable_voices))
		return false;

	bool playing = AudioA5_PollNarrator();
	if (playing)
		return true;

	if (s_voice_head != s_voice_tail) {
		playing = AudioA5_PlaySample(s_voice_queue[s_voice_head], 1.0f, 0.0f);

		if (playing)
			s_voice_head = (s_voice_head + 1) & 0xFF;
	}

	return playing;
}
