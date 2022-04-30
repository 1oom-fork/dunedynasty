#ifndef TABLE_WIDGETINFO_H
#define TABLE_WIDGETINFO_H

#include "types.h"
#include "../gui/widget.h"
#include "enum_widget.h"

typedef struct WidgetInfo {
	int16 index;            /*!< ?? */
	ClickProc *clickProc;   /*!< Function to execute when widget is pressed. */
	int16 shortcut;         /*!< ?? */
	uint16 flags;           /*!< ?? */
	int16  spriteID;        /*!< ?? */
	uint16 offsetX;         /*!< ?? */
	uint16 offsetY;         /*!< ?? */
	uint16 width;           /*!< ?? */
	uint16 height;          /*!< ?? */
	uint16 stringID;        /*!< ?? */

	enum ScreenDivID div;
} WidgetInfo;

extern WidgetInfo g_table_gameWidgetInfo[GAME_WIDGET_MAX + 1];

#endif
