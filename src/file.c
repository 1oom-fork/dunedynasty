/* $Id$ */

/** @file src/file.c %File access routines. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fourcc.h"
#include "types.h"
#include "os/endian.h"
#include "os/error.h"
#include "os/file.h"
#include "os/math.h"
#include "os/strings.h"

#include "file.h"

#define DUNE2_DATA_PREFIX   "data"
#define DUNE2_SAVE_PREFIX   "save"

/**
 * Static information about opened files.
 */
typedef struct File {
	FILE *fp;
	uint32 size;
	uint32 start;
	uint32 position;
} File;

static File s_file[FILE_MAX];

char g_dune_data_dir[1024];
char g_personal_data_dir[1024];

extern FileInfo g_table_fileInfo[FILEINFO_MAX];

void
File_MakeCompleteFilename(char *buf, size_t len, bool is_global_data, const char *filename, bool convert_to_lowercase)
{
	int i;

	if (is_global_data) {
		i = snprintf(buf, len, "%s/%s/", g_dune_data_dir, DUNE2_DATA_PREFIX);
	}
	else {
		i = snprintf(buf, len, "%s/%s/", g_personal_data_dir, DUNE2_SAVE_PREFIX);
	}

	strncpy(buf + i, filename, len - i);
	buf[len - 1] = '\0';

	if (convert_to_lowercase) {
		for (int j = i; buf[j] != '\0'; j++) {
			if ('A' <= buf[j] && buf[j] <= 'Z')
				buf[j] = buf[j] + 'a' - 'A';
		}
	}
}

FILE *
File_Open_CaseInsensitive(bool is_global_data, const char *filename, const char *mode)
{
	char buf[1024];
	FILE *fp;

	File_MakeCompleteFilename(buf, sizeof(buf), is_global_data, filename, false);
	fp = fopen(buf, mode);
	if (fp != NULL)
		return fp;

	File_MakeCompleteFilename(buf, sizeof(buf), is_global_data, filename, true);
	fp = fopen(buf, mode);
	return fp;
}

/**
 * Find the FileInfo index for the given filename.
 *
 * @param filename The filename to get the index for.
 * @return The index or 0xFFFF if not found.
 */
static uint16 FileInfo_FindIndex_ByName(const char *filename)
{
	uint16 index;

	for (index = 0; index < FILEINFO_MAX; index++) {
		if (!strcasecmp(g_table_fileInfo[index].filename, filename)) return index;
	}

	return FILEINFO_INVALID;
}

/**
 * Internal function to truly open a file.
 *
 * @param filename The name of the file to open.
 * @param mode The mode to open the file in. Bit 1 means reading, bit 2 means writing.
 * @return An index value refering to the opened file, or FILE_INVALID.
 */
static uint8 _File_Open(const char *filename, bool is_global_data, uint8 mode)
{
	const char *mode_str = (mode == 2) ? "wb" : ((mode == 3) ? "wb+" : "rb");

	const char *pakName;
	uint8 fileIndex;
	uint16 fileInfoIndex;

	if ((mode & 1) == 0 && (mode & 2) == 0) return FILE_INVALID;

	/* Find a free spot in our limited array */
	for (fileIndex = 0; fileIndex < FILE_MAX; fileIndex++) {
		if (s_file[fileIndex].fp == NULL) break;
	}
	if (fileIndex == FILE_MAX) return FILE_INVALID;

	/* Check if we can find the file outside any PAK file */
	s_file[fileIndex].fp = File_Open_CaseInsensitive(is_global_data, filename, mode_str);
	if (s_file[fileIndex].fp != NULL) {
		s_file[fileIndex].start    = 0;
		s_file[fileIndex].position = 0;
		s_file[fileIndex].size     = 0;

		/* We can only check the size of the file if we are reading (or appending) */
		if ((mode & 1) != 0) {
			fseek(s_file[fileIndex].fp, 0, SEEK_END);
			s_file[fileIndex].size = ftell(s_file[fileIndex].fp);
			fseek(s_file[fileIndex].fp, 0, SEEK_SET);
		}

		return fileIndex;
	}

	/* We never allow writing of files inside PAKs */
	if ((mode & 2) != 0) return FILE_INVALID;

	/* Check if the file could be inside any of our PAK files */
	fileInfoIndex = FileInfo_FindIndex_ByName(filename);
	if (fileInfoIndex == FILEINFO_INVALID) return FILE_INVALID;

	/* If the file is not inside another PAK, then the file doesn't exist (as it wasn't in the directory either) */
	if (!g_table_fileInfo[fileInfoIndex].flags.inPAKFile) return FILE_INVALID;

	pakName = g_table_fileInfo[g_table_fileInfo[fileInfoIndex].parentIndex].filename;
	s_file[fileIndex].fp = File_Open_CaseInsensitive(is_global_data, pakName, "rb");
	if (s_file[fileIndex].fp == NULL) return FILE_INVALID;

	/* If this file is not yet read from the PAK, read the complete index
	 *  of the PAK and index all files */
	if (!g_table_fileInfo[fileInfoIndex].flags.isLoaded) {
		uint16 pakIndexLast;

		pakIndexLast = FILEINFO_INVALID;

		while (true) {
			char pakFilename[1024];
			uint32 pakPosition;
			uint16 pakIndex;
			uint16 i;

			if (fread(&pakPosition, sizeof(uint32), 1, s_file[fileIndex].fp) != 1) {
				fclose(s_file[fileIndex].fp);
				s_file[fileIndex].fp = NULL;
				return FILE_INVALID;
			}
			if (pakPosition == 0) break;

			/* Read the name of the file inside the PAK */
			for (i = 0; i < sizeof(pakFilename); i++) {
				if (fread(&pakFilename[i], 1, 1, s_file[fileIndex].fp) != 1) {
					fclose(s_file[fileIndex].fp);
					s_file[fileIndex].fp = NULL;
					return FILE_INVALID;
				}
				if (pakFilename[i] == '\0') break;

				/* We always work in lowercase */
				if (pakFilename[i] >= 'A' && pakFilename[i] <= 'Z') pakFilename[i] += 32;
			}
			if (i == sizeof(pakFilename)) {
				fclose(s_file[fileIndex].fp);
				s_file[fileIndex].fp = NULL;
				return FILE_INVALID;
			}

			/* Check if we expected this file in this PAK */
			pakIndex = FileInfo_FindIndex_ByName(pakFilename);
			if (pakIndex == FILEINFO_INVALID) continue;
			if (g_table_fileInfo[pakIndex].parentIndex != g_table_fileInfo[fileInfoIndex].parentIndex) continue;

			/* Update the information of the file */
			g_table_fileInfo[pakIndex].flags.isLoaded = true;
			g_table_fileInfo[pakIndex].filePosition = pakPosition;
			if (pakIndexLast != FILEINFO_INVALID) g_table_fileInfo[pakIndexLast].fileSize = pakPosition - g_table_fileInfo[pakIndexLast].filePosition;

			pakIndexLast = pakIndex;
		}

		/* Make sure we set the right size of the last entry */
		if (pakIndexLast != FILEINFO_INVALID) {
			fseek(s_file[fileIndex].fp, 0, SEEK_END);
			g_table_fileInfo[pakIndexLast].fileSize = ftell(s_file[fileIndex].fp) - g_table_fileInfo[pakIndexLast].filePosition;
		}
	}

	/* Check if the file is inside the PAK file */
	if (!g_table_fileInfo[fileInfoIndex].flags.isLoaded) {
		fclose(s_file[fileIndex].fp);
		s_file[fileIndex].fp = NULL;
		return FILE_INVALID;
	}

	s_file[fileIndex].start    = g_table_fileInfo[fileInfoIndex].filePosition;
	s_file[fileIndex].position = 0;
	s_file[fileIndex].size     = g_table_fileInfo[fileInfoIndex].fileSize;

	/* Go to the start of the file now */
	fseek(s_file[fileIndex].fp, s_file[fileIndex].start, SEEK_SET);
	return fileIndex;
}

/**
 * Check if a file exists either in a PAK or on the disk.
 *
 * @param filename The filename to check for.
 * @return True if and only if the file can be found.
 */
bool
File_Exists_Ex(const char *filename, bool is_global_data)
{
	uint8 index;

	index = _File_Open(filename, is_global_data, 1);
	if (index == FILE_INVALID) {
		return false;
	}
	File_Close(index);

	return true;
}

/**
 * Open a file for reading/writing/appending.
 *
 * @param filename The name of the file to open.
 * @param mode The mode to open the file in. Bit 1 means reading, bit 2 means writing.
 * @return An index value refering to the opened file, or FILE_INVALID.
 */
uint8
File_Open_Ex(const char *filename, bool is_global_data, uint8 mode)
{
	uint8 res;

	res = _File_Open(filename, is_global_data, mode);

	if (res == FILE_INVALID) {
		Error("ERROR: unable to open file '%s'.\n", filename);
		exit(1);
	}

	return res;
}

/**
 * Close an opened file.
 *
 * @param index The index given by File_Open() of the file.
 */
void File_Close(uint8 index)
{
	if (index >= FILE_MAX) return;
	if (s_file[index].fp == NULL) return;

	fclose(s_file[index].fp);
	s_file[index].fp = NULL;
}

/**
 * Read bytes from a file into a buffer.
 *
 * @param index The index given by File_Open() of the file.
 * @param buffer The buffer to read into.
 * @param length The amount of bytes to read.
 * @return The amount of bytes truly read, or 0 if there was a failure.
 */
uint32 File_Read(uint8 index, void *buffer, uint32 length)
{
	if (index >= FILE_MAX) return 0;
	if (s_file[index].fp == NULL) return 0;
	if (s_file[index].position >= s_file[index].size) return 0;
	if (length == 0) return 0;

	if (length > s_file[index].size - s_file[index].position) length = s_file[index].size - s_file[index].position;

	if (fread(buffer, length, 1, s_file[index].fp) != 1) {
		Error("ERROR: read error\n");
		File_Close(index);

		length = 0;
	}

	s_file[index].position += length;
	return length;
}

/**
 * Write bytes from a buffer to a file.
 *
 * @param index The index given by File_Open() of the file.
 * @param buffer The buffer to write from.
 * @param length The amount of bytes to write.
 * @return The amount of bytes truly written, or 0 if there was a failure.
 */
uint32 File_Write(uint8 index, void *buffer, uint32 length)
{
	if (index >= FILE_MAX) return 0;
	if (s_file[index].fp == NULL) return 0;

	if (fwrite(buffer, length, 1, s_file[index].fp) != 1) {
		Error("ERROR: write error\n");
		File_Close(index);

		length = 0;
	}

	s_file[index].position += length;
	if (s_file[index].position > s_file[index].size) s_file[index].size = s_file[index].position;
	return length;
}

/**
 * Seek inside a file.
 *
 * @param index The index given by File_Open() of the file.
 * @param position Position to fix to.
 * @param mode Mode of seeking. 0 = SEEK_SET, 1 = SEEK_CUR, 2 = SEEK_END.
 * @return The new position inside the file, relative from the start.
 */
uint32 File_Seek(uint8 index, uint32 position, uint8 mode)
{
	if (index >= FILE_MAX) return 0;
	if (s_file[index].fp == NULL) return 0;
	if (mode > 2) { File_Close(index); return 0; }

	switch (mode) {
		case 0:
			fseek(s_file[index].fp, s_file[index].start + position, SEEK_SET);
			s_file[index].position = position;
			break;
		case 1:
			fseek(s_file[index].fp, (int32)position, SEEK_CUR);
			s_file[index].position += (int32)position;
			break;
		case 2:
			fseek(s_file[index].fp, s_file[index].start + s_file[index].size - position, SEEK_SET);
			s_file[index].position = s_file[index].size - position;
			break;
	}

	return s_file[index].position;
}

/**
 * Get the size of a file.
 *
 * @param index The index given by File_Open() of the file.
 * @return The size of the file.
 */
uint32 File_GetSize(uint8 index)
{
	if (index >= FILE_MAX) return 0;
	if (s_file[index].fp == NULL) return 0;

	return s_file[index].size;
}

/**
 * Delete a file from the disk.
 *
 * @param filename The filename to remove.
 */
void
File_Delete_Personal(const char *filename)
{
	char filenameComplete[1024];

	File_MakeCompleteFilename(filenameComplete, sizeof(filenameComplete), false, filename, false);
	if (unlink(filenameComplete) == 0)
		return;

	File_MakeCompleteFilename(filenameComplete, sizeof(filenameComplete), false, filename, true);
	unlink(filenameComplete);
}

/**
 * Reads length bytes from filename into buffer.
 *
 * @param filename Then name of the file to read.
 * @param buffer The buffer to read into.
 * @param length The amount of bytes to read.
 * @return The amount of bytes truly read, or 0 if there was a failure.
 */
uint32
File_ReadBlockFile_Ex(const char *filename, bool is_global_data, void *buffer, uint32 length)
{
	uint8 index;

	index = File_Open_Ex(filename, is_global_data, 1);
	length = File_Read(index, buffer, length);
	File_Close(index);
	return length;
}

/**
 * Reads the whole file in the memory.
 *
 * @param filename The name of the file to open.
 * @param mallocFlags The type of memory to allocate.
 * @return The CS:IP of the allocated memory where the file has been read.
 */
void *File_ReadWholeFile(const char *filename)
{
	uint8 index;
	uint32 length;
	void *buffer;

	index = File_Open(filename, 1);
	length = File_GetSize(index);

	buffer = malloc(length + 1);
	File_Read(index, buffer, length);

	/* In case of text-files it can be very important to have a \0 at the end */
	((char *)buffer)[length] = '\0';

	File_Close(index);

	return buffer;
}

/**
 * Reads the whole file into buffer.
 *
 * @param filename The name of the file to open.
 * @param buf The buffer to read into.
 * @return The length of the file.
 */
uint32 File_ReadFile(const char *filename, void *buf)
{
	uint8 index;
	uint32 length;

	index = File_Open(filename, 1);
	length = File_Seek(index, 0, 2);
	File_Seek(index, 0, 0);
	File_Read(index, buf, length);
	File_Close(index);

	return length;
}

/**
 * Open a chunk file (starting with FORM) for reading.
 *
 * @param filename The name of the file to open.
 * @return An index value refering to the opened file, or FILE_INVALID.
 */
uint8
ChunkFile_Open_Ex(const char *filename, bool is_global_data)
{
	uint8 index;
	uint32 header;

	index = File_Open_Ex(filename, is_global_data, 1);
	File_Close(index);

	index = File_Open_Ex(filename, is_global_data, 1);

	File_Read(index, &header, 4);

	if (header != HTOBE32(CC_FORM)) {
		File_Close(index);
		return FILE_INVALID;
	}

	File_Seek(index, 4, 1);

	return index;
}

/**
 * Close an opened chunk file.
 *
 * @param index The index given by ChunkFile_Open() of the file.
 */
void ChunkFile_Close(uint8 index)
{
	if (index == FILE_INVALID) return;

	File_Close(index);
}

/**
 * Seek to the given chunk inside a chunk file.
 *
 * @param index The index given by ChunkFile_Open() of the file.
 * @param chunk The chunk to seek to.
 * @return The length of the chunk (0 if not found).
 */
uint32 ChunkFile_Seek(uint8 index, uint32 chunk)
{
	uint32 value = 0;
	uint32 length = 0;
	bool first = true;

	while (true) {
		if (File_Read(index, &value, 4) != 4 && !first) return 0;

		if (value == 0 && File_Read(index, &value, 4) != 4 && !first) return 0;

		if (File_Read(index, &length, 4) != 4 && !first) return 0;

		length = HTOBE32(length);

		if (value == chunk) {
			File_Seek(index, -8, 1);
			return length;
		}

		if (first) {
			File_Seek(index, 12, 0);
			first = false;
			continue;
		}

		length += 1;
		length &= 0xFFFFFFFE;
		File_Seek(index, length, 1);
	}
}

/**
 * Read bytes from a chunk file into a buffer.
 *
 * @param index The index given by ChunkFile_Open() of the file.
 * @param chunk The chunk to read from.
 * @param buffer The buffer to read into.
 * @param length The amount of bytes to read.
 * @return The amount of bytes truly read, or 0 if there was a failure.
 */
uint32 ChunkFile_Read(uint8 index, uint32 chunk, void *buffer, uint32 buflen)
{
	uint32 value = 0;
	uint32 length = 0;
	bool first = true;

	while (true) {
		if (File_Read(index, &value, 4) != 4 && !first) return 0;

		if (value == 0 && File_Read(index, &value, 4) != 4 && !first) return 0;

		if (File_Read(index, &length, 4) != 4 && !first) return 0;

		length = HTOBE32(length);

		if (value == chunk) {
			buflen = min(buflen, length);

			File_Read(index, buffer, buflen);

			length += 1;
			length &= 0xFFFFFFFE;

			if (buflen < length) File_Seek(index, length - buflen, 1);

			return buflen;
		}

		if (first) {
			File_Seek(index, 12, 0);
			first = false;
			continue;
		}

		length += 1;
		length &= 0xFFFFFFFE;
		File_Seek(index, length, 1);
	}
}
