/* $Id$ */

#include <stdio.h>
#include "../os/strings.h"
#include "types.h"
#include "libemu.h"
#include "../global.h"
#include "mentat.h"
#include "gui.h"
#include "widget.h"
#include "../house.h"
#include "../sprites.h"
#include "../string.h"
#include "../tools.h"
#include "../wsa.h"
#include "../unknown/unknown.h"

extern void f__2B4C_0002_0029_64AF();
extern void f__2B6C_0137_0020_C73F();
extern void f__2B6C_0169_001E_6939();
extern void f__B4DA_0000_002C_B3C2();
extern void f__B4DA_02E0_0023_E297();
extern void f__B4DA_0308_0018_F99F();
extern void f__B4DA_0A8E_0025_4AC8();
extern void f__B4DA_0AB8_002A_AAB2();
extern void f__B4E0_0000_000F_14AD();
extern void emu_Tools_Free();
extern void overlay(uint16 cs, uint8 force);




extern void emu_Input_History_Clear();


/**
 * Show the Mentat screen with a dialog (Proceed / Repeat).
 * @param houseID The house to show the mentat of.
 * @param stringID The string to show.
 * @param wsaFilename The WSA to show.
 * @param musicID The Music to play.
 */
static void GUI_Mentat_ShowDialog(uint8 houseID, uint16 stringID, csip32 wsaFilename, uint16 musicID)
{
	Widget *w1, *w2;
	csip32 w1csip, w2csip;

	if (g_global->debugSkipDialogs) return;

	Sprites_Load(1, 7, g_sprites);

	w1 = GUI_Widget_Allocate(1, GUI_Widget_GetShortcut(String_Get_ByIndex(175)[0]), 168, 168, 6, 0, 0, &w1csip);
	w2 = GUI_Widget_Allocate(2, GUI_Widget_GetShortcut(String_Get_ByIndex(176)[0]), 240, 168, 8, 0, 0, &w2csip);

	w1 = GUI_Widget_Link(w1, w2);
	w1csip = emu_Global_GetCSIP(w1);

	Unknown_B483_0363(0xFFFE);

	{
		csip32 nullcsip;
		nullcsip.csip = 0x0;
		Driver_Voice_0248(NULL, nullcsip, 0xFF, 0xFF);
	}

	Music_Play(musicID);

	do {
		char filename[10];
		snprintf(filename, sizeof(filename), "TEXT%c", emu_get_memorycsip(g_houseInfo[houseID].name)[0]);
		String_LoadFile(String_GenerateFilename(filename), stringID, (char *)emu_get_memorycsip(g_global->readBuffer), g_global->readBufferSize);
		String_TranslateSpecial((char *)emu_get_memorycsip(g_global->readBuffer), (char *)emu_get_memorycsip(g_global->readBuffer));
	} while (GUI_Mentat_Show(g_global->readBuffer, wsaFilename, w1, true) == 0x8002);

	emu_push(w2csip.s.cs); emu_push(w2csip.s.ip);
	emu_push(emu_cs); emu_push(0x0E1C); emu_cs = 0x23E1; emu_Tools_Free();
	emu_sp += 4;

	emu_push(w1csip.s.cs); emu_push(w1csip.s.ip);
	emu_push(emu_cs); emu_push(0x0E0F); emu_cs = 0x23E1; emu_Tools_Free();
	emu_sp += 4;

	if (musicID != 0xFFFF) Drivers_1DD7_0B53();

	Sprites_Load(0, 7, g_sprites);
}

/**
 * Handle clicks on the Mentat widget.
 * @return True, always.
 */
bool GUI_Widget_Mentat_Click()
{
	g_global->cursorSpriteID = 0;

	emu_push(emu_get_memory16(0x2DCE, 0x00, 0x442)); emu_push(emu_get_memory16(0x2DCE, 0x00, 0x440)); /* g_sprites */
	emu_push(0);
	emu_push(0);
	emu_push(emu_cs); emu_push(0x0368); emu_cs = 0x2B4C; f__2B4C_0002_0029_64AF();
	emu_sp += 8;

	Unknown_B483_0363(0xFFFE);

	{
		csip32 nullcsip;
		nullcsip.csip = 0x0;
		Driver_Voice_0248(NULL, nullcsip, 0xFF, 0xFF);
	}

	Music_Play(g_houseInfo[g_global->playerHouseID].musicBriefing);

	Sprites_UnloadTiles();

	Sprites_Load(1, 7, g_sprites);

	Tools_Var76B8_Set(2, false);

	emu_push(0);
	emu_push(emu_cs); emu_push(0x03C3); emu_cs = 0x34E0; overlay(0x34E0, 0); f__B4E0_0000_000F_14AD();
	emu_sp += 2;

	Tools_Var76B8_Set(2, true);

	Driver_Sound_Play(1, 0xFF);

	Sprites_Load(0, 7, g_sprites);

	Sprites_LoadTiles();

	g_global->variable_38C4 = 1;

	GUI_DrawInterfaceAndRadar(0);

	Music_Play(Tools_RandomRange(0, 5) + 8);

	return true;
}

/**
 * Show the Mentat screen.
 * @param spriteBuffer The buffer of the strings.
 * @param wsaFilename The WSA to show.
 * @param w The widgets to handle. Can be NULL for no widgets.
 * @param unknown A boolean.
 * @return Return value of GUI_Widget_HandleEvents() or f__B4DA_0AB8_002A_AAB2() (latter when no widgets).
 */
uint16 GUI_Mentat_Show(csip32 stringBuffer, csip32 wsaFilename, Widget *w, bool unknown)
{
	uint16 ret;

	Sprites_UnloadTiles();

	emu_push(g_global->playerHouseID);
	emu_push(wsaFilename.s.cs); emu_push(wsaFilename.s.ip);
	emu_push(emu_cs); emu_push(0x0E5F); emu_cs = 0x34DA; overlay(0x34DA, 0); f__B4DA_0000_002C_B3C2();
	emu_sp += 6;

	Unknown_Set_Global_6C91(2);

	Unknown_07AE_00E4(8);

	if (wsaFilename.csip != 0x0) {
		csip32 wsa;
		csip32 memBlock;
		csip32 null;

		null.csip = 0x0;

		emu_push(5);
		emu_push(emu_cs); emu_push(0x0E98); emu_cs = 0x252E; emu_Memory_GetBlock1();
		emu_sp += 2;

		memBlock.s.cs = emu_dx;
		memBlock.s.ip = emu_ax;

		wsa = WSA_LoadFile((char *)emu_get_memorycsip(wsaFilename), memBlock, g_global->variable_6CD3[2][0], 0, null);

		WSA_DisplayFrame(wsa, 0, g_global->variable_992D * 8, g_global->variable_992B, 2, 0);
		WSA_Unload(wsa);
	}

	emu_push(2);
	emu_push(emu_cs); emu_push(0x0EE9); emu_cs = 0x34DA; overlay(0x34DA, 0); f__B4DA_0A8E_0025_4AC8();
	emu_sp += 2;

	Unknown_Set_Global_6C91(0);

	emu_push(emu_cs); emu_push(0x0EF8); emu_cs = 0x2B6C; f__2B6C_0137_0020_C73F();

	GUI_Unknown_24D0_000D(0, 0, 0, 0, 40, 200, 2, 0);

	emu_push(emu_cs); emu_push(0x0F20); emu_cs = 0x2B6C; f__2B6C_0169_001E_6939();

	Unknown_259E_0006(g_global->variable_3C32, 15);

	emu_push(0); emu_push(0);
	emu_push(1);
	emu_push(stringBuffer.s.cs); emu_push(stringBuffer.s.ip);
	emu_push(0); emu_push(0);
	emu_push(wsaFilename.s.cs); emu_push(wsaFilename.s.ip);
	emu_push(emu_cs); emu_push(0x0F55); emu_cs = 0x34DA; overlay(0x34DA, 0); f__B4DA_0AB8_002A_AAB2();
	emu_sp += 18;
	ret = emu_ax;

	if (w != NULL) {
		do {
			GUI_Widget_DrawAll(w);
			ret = GUI_Widget_HandleEvents(w);

			GUI_PaletteAnimate();

			emu_push(0);
			emu_push(emu_cs); emu_push(0x0F8B); emu_cs = 0x34DA; overlay(0x34DA, 0); f__B4DA_0308_0018_F99F();
			emu_sp += 2;
		} while ((ret & 0x8000) == 0);
	}

	emu_push(emu_cs); emu_push(0x0F97); emu_cs = 0x29E8; emu_Input_History_Clear();

	if (unknown) {
		emu_push(emu_cs); emu_push(0x0FA2); emu_cs = 0x34DA; overlay(0x34DA, 0); f__B4DA_02E0_0023_E297();

		Sprites_LoadTiles();
	}

	return ret;
}

/**
 * Show the briefing screen.
 */
void GUI_Mentat_ShowBriefing()
{
	csip32 picture;
	picture.s.cs = 0x353F;
	picture.s.ip = 0x8D0D; /* g_global->scenario.pictureBriefing */
	GUI_Mentat_ShowDialog((uint8)g_global->playerHouseID, g_global->campaignID * 4 + 4, picture, g_houseInfo[g_global->playerHouseID].musicBriefing);
}

/**
 * Show the win screen.
 */
void GUI_Mentat_ShowWin()
{
	csip32 picture;
	picture.s.cs = 0x353F;
	picture.s.ip = 0x8D1B; /* g_global->scenario.pictureWin */
	GUI_Mentat_ShowDialog((uint8)g_global->playerHouseID, g_global->campaignID * 4 + 5, picture, g_houseInfo[g_global->playerHouseID].musicWin);
}

/**
 * Show the lose screen.
 */
void GUI_Mentat_ShowLose()
{
	csip32 picture;
	picture.s.cs = 0x353F;
	picture.s.ip = 0x8D29; /* g_global->scenario.pictureLose */
	GUI_Mentat_ShowDialog((uint8)g_global->playerHouseID, g_global->campaignID * 4 + 6, picture, g_houseInfo[g_global->playerHouseID].musicLose);
}
