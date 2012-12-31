/** @file src/opendune.h Gameloop and other main definitions. */

#ifndef OPENDUNE_H
#define OPENDUNE_H

#include <inttypes.h>
#include "types.h"

typedef enum GameMode {
	GM_NORMAL    = 0,
	GM_RESTART   = 1,
	GM_PICKHOUSE = 2,
	GM_WIN       = 3,
	GM_LOSE      = 4,
	GM_QUITGAME  = 5
} GameMode;

enum GameOverlay {
	GAMEOVERLAY_NONE,
	GAMEOVERLAY_MENTAT,
	GAMEOVERLAY_OPTIONS,
	GAMEOVERLAY_LOAD_GAME,
	GAMEOVERLAY_SAVE_GAME,
	GAMEOVERLAY_SAVE_ENTRY,
	GAMEOVERLAY_GAME_CONTROLS,
	GAMEOVERLAY_CONFIRM_RESTART,
	GAMEOVERLAY_CONFIRM_PICK_HOUSE,
	GAMEOVERLAY_CONFIRM_QUIT,
};

/**
 * Types of Language available in the game.
 */
typedef enum Language {
	LANGUAGE_ENGLISH     = 0,
	LANGUAGE_FRENCH      = 1,
	LANGUAGE_GERMAN      = 2,
	LANGUAGE_ITALIAN     = 3,
	LANGUAGE_SPANSIH     = 4,

	LANGUAGE_MAX         = 5,
	LANGUAGE_INVALID     = 0xFF
} Language;

/** X and Y coordinate. */
typedef struct XYPosition {
	uint16 x; /*!< X coordinate. */
	uint16 y; /*!< Y coordinate. */
} XYPosition;

extern uint32 g_hintsShown1;
extern uint32 g_hintsShown2;
extern GameMode g_gameMode;
extern enum GameOverlay g_gameOverlay;
extern uint16 g_campaignID;
extern uint16 g_scenarioID;
extern uint16 g_activeAction;
extern int64_t g_tickScenarioStart;
extern bool   g_debugGame;
extern bool   g_debugScenario;
extern bool   g_debugSkipDialogs;

extern uint16 g_validateStrictIfZero;
extern uint16 g_selectionType;
extern uint16 g_selectionTypeNew;
extern bool g_viewport_forceRedraw;
extern bool g_viewport_fadein;

extern int16 g_musicInBattle;

extern void *g_readBuffer;
extern uint32 g_readBufferSize;

extern void Main(void);
extern void GameLoop_Uninit(void);
extern void GameLoop_TweakWidgetDimensions(void);
extern void GameLoop_Main(bool new_game);
extern void Game_Prepare(void);
extern void Game_Init(void);
extern void Game_LoadScenario(uint8 houseID, uint16 scenarioID);
extern void PrepareEnd(void);

#endif /* OPENDUNE_H */
