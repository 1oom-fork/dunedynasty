/* actionpanel.c
 *
 * Notes about factory layout:
 *  At 320x200, widget->height is 32 >= 1 + SMALL_PRODUCTION_ICON_HEIGHT.
 *  At 320x240, widget->height is 69 >= 1 + 2 * SMALL_PRODUCTION_ICON_MIN_STRIDE.
 */

#include <assert.h>
#include <math.h>
#include "enum_string.h"
#include "../os/math.h"

#include "actionpanel.h"

#include "../audio/audio.h"
#include "../config.h"
#include "../enhancement.h"
#include "../gfx.h"
#include "../gui/font.h"
#include "../gui/gui.h"
#include "../gui/widget.h"
#include "../input/input.h"
#include "../input/mouse.h"
#include "../net/client.h"
#include "../net/server.h"
#include "../opendune.h"
#include "../pool/pool_house.h"
#include "../pool/pool_structure.h"
#include "../pool/pool_unit.h"
#include "../string.h"
#include "../table/widgetinfo.h"
#include "../timer/timer.h"
#include "../unit.h"
#include "../video/video.h"

enum {
	SMALL_PRODUCTION_ICON_WIDTH         = 32,
	SMALL_PRODUCTION_ICON_HEIGHT        = 24,
	SMALL_PRODUCTION_ICON_MIN_STRIDE    = 34,
	SMALL_PRODUCTION_ICON_MAX_STRIDE    = 43,
	LARGE_PRODUCTION_ICON_WIDTH         = 52,
	LARGE_PRODUCTION_ICON_HEIGHT        = 39,
	LARGE_PRODUCTION_ICON_MIN_STRIDE    = 52,
	LARGE_PRODUCTION_ICON_MAX_STRIDE    = 58,
	SCROLL_BUTTON_WIDTH     = 24,
	SCROLL_BUTTON_HEIGHT    = 15,
	SCROLL_BUTTON_MARGIN    = 5,
};

enum FactoryPanelLayout {
	FACTORYPANEL_LARGE_ICON_FLAG    = 0x01,
	FACTORYPANEL_SCROLL_FLAG        = 0x02,

	FACTORYPANEL_SMALL_ICONS_WITHOUT_SCROLL = 0x00,
};

FactoryWindowItem g_factoryWindowItems[MAX_FACTORY_WINDOW_ITEMS];
int g_factoryWindowTotal;
static int s_unitOffsetY;

static enum FactoryPanelLayout s_factory_panel_layout;

/*--------------------------------------------------------------*/

static void
ActionPanel_CalculateOptimalLayout(const Widget *widget)
{
	const int h = widget->height
		- 1 /* top margin. */
		- 1 /* bottom margin. */
		- (SCROLL_BUTTON_MARGIN + SCROLL_BUTTON_HEIGHT)
		;

	if (h >= 4 * LARGE_PRODUCTION_ICON_MIN_STRIDE) {
		/* Use large icons if possible. */
		s_factory_panel_layout
			= (FACTORYPANEL_SCROLL_FLAG | FACTORYPANEL_LARGE_ICON_FLAG);
	} else if (h >= 3 * SMALL_PRODUCTION_ICON_MIN_STRIDE) {
		/* Use small icons with the scroll and send order buttons if they fit. */
		s_factory_panel_layout
			= FACTORYPANEL_SCROLL_FLAG;
	} else {
		/* Otherwise, use small icons, without the scroll and send order buttons. */
		s_factory_panel_layout = FACTORYPANEL_SMALL_ICONS_WITHOUT_SCROLL;
	}
}

static int
ActionPanel_List_Height(const Widget *widget)
{
	int h = widget->height - 1;

	if (s_factory_panel_layout & FACTORYPANEL_SCROLL_FLAG)
		h -= SCROLL_BUTTON_MARGIN + SCROLL_BUTTON_HEIGHT;

	return h;
}

/*--------------------------------------------------------------*/

static void
ActionPanel_Title_Dimensions(uint16 *r_x, uint16 *r_y, uint16 *r_w, uint16 *r_h)
{
	*r_x = 16;
	*r_y = 2;
	*r_w = 64;
	*r_h = 6;
}

void
ActionPanel_DrawTitle(uint16 actionType, const ObjectInfo *oi)
{
	uint16 stringID = STR_NULL;

	switch (actionType) {
		case 4: stringID = STR_TARGET; break; /* Attack */
		case 5: stringID = STR_MOVEMENT; break; /* Movement */
		case 6: stringID = STR_HARVEST;  break; /* Harvest */

		case 2: /* Unit */
		case 3: /* Structure */
		case 7: /* Placement */
		case 8: /* House Missile */
			stringID = oi->stringID_abbrev;
			break;

		default:
			break;
	}

	if (stringID != STR_NULL) {
		uint16 x, y, w, h;
		ActionPanel_Title_Dimensions(&x, &y, &w, &h);
		GUI_DrawText_Wrapper(String_Get_ByIndex(stringID), x + w/2, y + 1, 29, 0, 0x111);
	}
}

static void
ActionPanel_DrawPalaceStatus(Widget *widget, const Structure *s)
{
	enum ShapeID shapeID;
	const char *deploy;

	switch (g_productionStringID) {
		case STR_LAUNCH:
			shapeID = SHAPE_DEATH_HAND;
			deploy = String_Get_ByIndex(STR_LAUNCH);
			break;

		case STR_FREMEN:
			shapeID = SHAPE_FREMEN_SQUAD;
			deploy = String_Get_ByIndex(STR_DEPLOY);
			break;

		case STR_SABOTEUR:
			shapeID = SHAPE_SABOTEUR;
			deploy = String_Get_ByIndex(STR_DEPLOY);
			break;

		default:
			return;
	}

	int x1 = widget->offsetX;
	int y1 = widget->offsetY;
	int w = widget->width;
	int h = widget->height;

	Shape_Draw(shapeID, x1, y1, 0, 0x4000);

	if (!s->countDown) {
		Prim_Rect(x1 + 1.0f, y1 + 1.0f, x1 + w - 1.0f, y1 + h - 1.0f, 0xFF, 2.0f);
	}

	uint16 countdown_max = g_table_houseInfo[s->o.houseID].specialCountDown;
	uint16 countdown_percent = 100 - s->countDown * 100 / countdown_max;
	if (s->countDown)
		GUI_DrawText_Wrapper(String_Get_ByIndex(STR_D_DONE), x1, y1 + 27, 0xf, 0, 0x21, countdown_percent);
	else
		GUI_DrawText_Wrapper(deploy, x1, y1 + 27, 0xf, 0, 0x21);
}

static void
ActionPanel_DrawStarportStatus(Widget *widget, const Structure *s)
{
	House *house = House_Get_ByIndex(s->o.houseID);
	int x1 = widget->offsetX;
	int y1 = widget->offsetY;
	int w = widget->width;
	int h = widget->height;

	enum ShapeID shapeID = SHAPE_CARRYALL;
	Shape_Draw(shapeID, x1, y1, 0, 0x4000);

	if (!House_StarportQueueEmpty(house)) {
		Prim_Rect(x1 + 1.0f, y1 + 1.0f, x1 + w - 1.0f, y1 + h - 1.0f, 0xFF, 2.0f);
	}

	uint16 delivery_time = g_table_houseInfo[house->index].starportDeliveryTime;
	GUI_DrawText_Wrapper("%ds", x1 + 36, y1 + 8, 29, 0, 0x11, delivery_time);
	GUI_DrawText_Wrapper("Send order", x1, y1 + 27, 0xf, 0, 0x21);
}

static void
ActionPanel_DrawFactoryStatus(Widget *widget, const Structure *s)
{
	int x1 = widget->offsetX;
	int y1 = widget->offsetY;
	int w = widget->width;
	int h = widget->height;

	if (g_productionStringID == STR_UPGRADINGD_DONE) {
		const int percentDone = 100 - s->upgradeTimeLeft;

		GUI_DrawText_Wrapper(String_Get_ByIndex(STR_UPGRADINGD_DONE),
				x1, y1 + 7, 0xF, 0, 0x21, percentDone);
		return;
	}

	int item;
	for (item = 0; item < g_factoryWindowTotal; item++) {
		if(s->objectType == g_factoryWindowItems[item].objectType){
			break;
		}
	}

	enum ShapeID shapeID = g_factoryWindowItems[item].shapeID;
	Shape_Draw(shapeID, x1, y1, 0, 0x4000);

	if (g_productionStringID == STR_PLACE_IT)
		//ActionPanel_HighlightIcon(g_playerHouseID, x1, y1, large_icon);
		Prim_Rect(x1 + 1.0f, y1 + 1.0f, x1 + w - 1.0f, y1 + h - 1.0f, 0xFF, 2.0f);

	/* On hold greys out the entire icon, which has 1px borders. */
	if (g_productionStringID == STR_ON_HOLD) {
		float x1f = x1 + (float)w/32.0f;
		float x2f = x1 + w - (float)w/32.0f;
		float y1f, y2f;
		y1f = y1 + 1.0f;
		y2f = y1 + 23.0f;
		Prim_FillRect_RGBA(x1f, y1f, x2f, y2f, 0x00, 0x00, 0x00, 0x80);
	}

	if (g_productionStringID == STR_D_DONE || g_productionStringID == STR_ON_HOLD) {
		int buildTime;

		if (s->o.type == STRUCTURE_CONSTRUCTION_YARD) {
			const StructureInfo *si = &g_table_structureInfo[s->objectType];

			buildTime = si->o.buildTime;
		}
		else {
			const UnitInfo *ui = &g_table_unitInfo[s->objectType];

			buildTime = ui->o.buildTime;
		}

		const int timeLeft = buildTime - (s->countDown + 255) / 256;
		const int percentDone = 100 * timeLeft / buildTime;

		GUI_DrawText_Wrapper(String_Get_ByIndex(g_productionStringID), x1, y1 + 27, 0xf, 0, 0x21, percentDone);

		if (!timeLeft)
			Prim_Rect(x1 + 1.0f, y1 + 1.0f, x1 + w - 1.0f, y1 + h - 1.0f, 0xFF, 2.0f);
	}
	else if (g_productionStringID == STR_PLACE_IT) {
		GUI_DrawText_Wrapper(String_Get_ByIndex(g_productionStringID), x1, y1 + 27, 0xf, 0, 0x21);
	}
	else {
		GUI_DrawText_Wrapper(String_Get_ByIndex(g_productionStringID), x1, y1 + 27, 0xf, 0, 0x21);
	}
}

void
ActionPanel_DrawStructureStatus(Widget *w, const Structure *s)
{
	House *h = House_Get_ByIndex(s->o.houseID);

	if (g_productionStringID == STR_PLACE_IT
	 || g_productionStringID == STR_COMPLETED
	 || g_productionStringID == STR_ON_HOLD
	 || g_productionStringID == STR_D_DONE
	 || g_productionStringID == STR_UPGRADINGD_DONE) {
		if (s->o.type != STRUCTURE_STARPORT) {
			ActionPanel_DrawFactoryStatus(w, s);
		}
	}
	if (s->o.type == STRUCTURE_STARPORT) {
		if  (h->starportLinkedID != 0xFFFF
		 && !House_StarportQueueEmpty(h)) {
			ActionPanel_DrawStarportStatus(w, s);
		}
	}
	if (g_productionStringID == STR_LAUNCH
	 || g_productionStringID == STR_FREMEN
	 || g_productionStringID == STR_SABOTEUR) {
		ActionPanel_DrawPalaceStatus(w, s);
	}
}

void
ActionPanel_DrawPortrait(uint16 action_type, enum ShapeID shapeID)
{
	switch (action_type) {
		case 2: /* Unit */
		case 3: /* Structure */
		case 7: /* Placement. */
			break;

		case 4: /* Attack */
			shapeID = SHAPE_ATTACK;
			break;

		case 5: /* Movement */
		case 6: /* Harvest */
			shapeID = SHAPE_MOVE;
			break;

		case 8: /* House Missile */
			shapeID = SHAPE_DEATH_HAND;
			break;

		default:
			return;
	}

	const WidgetInfo *wi = &g_table_gameWidgetInfo[GAME_WIDGET_PICTURE];
	Shape_Draw(shapeID, wi->offsetX, wi->offsetY, 0, 0x4000);
}

static void
ActionPanel_HealthBar_Dimensions(uint16 *r_x, uint16 *r_y, uint16 *r_w, uint16 *r_h)
{
	const WidgetInfo *wi = &g_table_gameWidgetInfo[GAME_WIDGET_PICTURE];
	*r_x = wi->offsetX + 34;
	*r_y = wi->offsetY;
	*r_w = 24;
	*r_h = 7;
}

static void
ActionPanel_DrawProgressBar(int curr, int max, uint16 x, uint16 y, uint16 w, uint16 h, uint8 colour)
{
	const int wh = max(1, w * curr / max);

	Prim_DrawBorder(x, y, w + 2, h + 2, 1, false, true, 1);
	Prim_FillRect_i(x + 1, y + 1, x + wh, y + h, colour);
}

static void
ActionPanel_DrawCustomHealthBar(int curr, int max, uint16 x, uint16 y, uint16 w, uint16 h)
{
	if (curr > max)
		curr = max;

	if (max < 1)
		max = 1;

	uint8 colour = 4;
	if (curr <= max / 2) colour = 5;
	if (curr <= max / 4) colour = 8;

	ActionPanel_DrawProgressBar(curr, max, x, y, w, h, colour);
}

void
ActionPanel_DrawHealthBar(int curr, int max)
{
	uint16 x, y, w, h;
	ActionPanel_HealthBar_Dimensions(&x, &y, &w, &h);

	ActionPanel_DrawCustomHealthBar(curr, max, x, y, w, h);

	Shape_Draw(SHAPE_HEALTH_INDICATOR, x, y + 9, 0, 0x4000);
	GUI_DrawText_Wrapper(String_Get_ByIndex(STR_DMG), x + 4, y + 14, 29, 0, 0x11);
}

void
ActionPanel_DrawStructureDescription(Widget *widget, Structure *s)
{
	const StructureInfo *si = &g_table_structureInfo[s->o.type];
	const Object *o = &s->o;
	const ObjectInfo *oi = &si->o;
	const House *h = House_Get_ByIndex(s->o.houseID);

	/* Position to draw text so that it is not overlapped by the
	 * repair/upgrade button.  When the button is 10 pixels tall, as
	 * in the original game, y = 40.
	 */
	const int x = widget->offsetX;
	const int y = widget->offsetY;

	switch (o->type) {
		case STRUCTURE_SLAB_1x1:
		case STRUCTURE_SLAB_2x2:
		case STRUCTURE_PALACE:
		case STRUCTURE_LIGHT_VEHICLE:
		case STRUCTURE_HEAVY_VEHICLE:
		case STRUCTURE_HIGH_TECH:
		case STRUCTURE_HOUSE_OF_IX:
		case STRUCTURE_WOR_TROOPER:
		case STRUCTURE_CONSTRUCTION_YARD:
		case STRUCTURE_BARRACKS:
		case STRUCTURE_WALL:
		case STRUCTURE_TURRET:
		case STRUCTURE_ROCKET_TURRET:
			return;

		case STRUCTURE_REPAIR:
			{
				uint16 percent;
				uint16 steps;
				Unit *u;

				u = Structure_GetLinkedUnit(s);
				if (u == NULL) break;

				steps = g_table_unitInfo[u->o.type].o.buildTime / 4;
				percent = (steps - (s->countDown >> 8)) * 100 / steps;

				Shape_Draw(g_table_unitInfo[u->o.type].o.spriteID, x, y, 0, 0);
				GUI_DrawText_Wrapper(String_Get_ByIndex(STR_D_DONE), x, y + 27, 29, 0, 0x11, percent);
			}
			break;

		case STRUCTURE_WINDTRAP:
			{
				uint16 powerOutput = o->hitpoints * -si->powerUsage / oi->hitpoints;
				uint16 powerAverage = (h->windtrapCount == 0) ? 0 : h->powerUsage / h->windtrapCount;
				uint8 fg = (powerOutput >= powerAverage) ? 29 : 6;

				Prim_Hline(21, y + 7, 72, 16);
				if (enhancement_fix_typos && (g_gameConfig.language == LANGUAGE_ENGLISH)) {
					GUI_DrawText_Wrapper("Power Info", 46, y, 29, 0, 0x111);
					GUI_DrawText_Wrapper("Needed:", 21, y + 1 * g_fontCurrent->height, 29, 0, 0x11);
					GUI_DrawText_Wrapper("Output:", 21, y + 2 * g_fontCurrent->height, 29, 0, 0x11);
					GUI_DrawText_Wrapper("%d", 72, y + 1 * g_fontCurrent->height, 29, 0, 0x211, powerAverage);
					GUI_DrawText_Wrapper("%d", 72, y + 2 * g_fontCurrent->height, fg, 0, 0x211, powerOutput);
				} else {
					GUI_DrawText_Wrapper(String_Get_ByIndex(STR_POWER_INFONEEDEDOUTPUT), 18, y, 29, 0, 0x11);
					GUI_DrawText_Wrapper("%d", 62, y + 1 * g_fontCurrent->height, 29, 0, 0x11, powerAverage);
					GUI_DrawText_Wrapper("%d", 62, y + 2 * g_fontCurrent->height, fg, 0, 0x11, powerOutput);
				}
			}
			break;

		case STRUCTURE_STARPORT:
			if (h->starportLinkedID != 0xFFFF) {
				if (House_StarportQueueEmpty(h))
					GUI_DrawText_Wrapper(String_Get_ByIndex(STR_FRIGATEARRIVAL_INTMINUS_D), x, y, 29, 0, 0x11, h->starportTimeLeft);
			} else {
				GUI_DrawText_Wrapper(String_Get_ByIndex(STR_FRIGATE_INORBIT_ANDAWAITINGORDER), x, y, 29, 0, 0x11);
			}
			break;

		case STRUCTURE_REFINERY:
		case STRUCTURE_SILO:
			{
				uint16 creditsStored;

				creditsStored = h->credits * si->creditsStorage / h->creditsStorage;
				if (h->credits > h->creditsStorage) creditsStored = si->creditsStorage;

				Prim_Hline(21, y + 7, 72, 16);
				if (enhancement_fix_typos && (g_gameConfig.language == LANGUAGE_ENGLISH)) {
					GUI_DrawText_Wrapper("Spice", 46, y, 29, 0, 0x111);
					GUI_DrawText_Wrapper("Holds:", 21, y + 1 * g_fontCurrent->height, 29, 0, 0x11);
					GUI_DrawText_Wrapper("Max:", 21, y + 2 * g_fontCurrent->height, 29, 0, 0x11);
					GUI_DrawText_Wrapper("%d", 72, y + 1 * g_fontCurrent->height, 29, 0, 0x211, creditsStored);
					GUI_DrawText_Wrapper("%d", 72, y + 2 * g_fontCurrent->height, 29, 0, 0x211, (si->creditsStorage / 100) * 100);
				} else {
					GUI_DrawText_Wrapper(String_Get_ByIndex(STR_SPICEHOLDS_4DMAX_4D), 18, y, 29, 0, 0x11, creditsStored, (si->creditsStorage <= 1000) ? si->creditsStorage : 1000);
				}
			}
			break;

		case STRUCTURE_OUTPOST:
			{
				Prim_Hline(21, y + 7, 72, 16);
				if (enhancement_fix_typos && (g_gameConfig.language == LANGUAGE_ENGLISH)) {
					GUI_DrawText_Wrapper("Radar Scan", 46, y, 29, 0, 0x111);
					GUI_DrawText_Wrapper("Friend:", 21, y + 1 * g_fontCurrent->height, 29, 0, 0x11);
					GUI_DrawText_Wrapper("Enemy:", 21, y + 2 * g_fontCurrent->height, 29, 0, 0x11);
					GUI_DrawText_Wrapper("%d", 72, y + 1 * g_fontCurrent->height, 29, 0, 0x211, h->unitCountAllied);
					GUI_DrawText_Wrapper("%d", 72, y + 2 * g_fontCurrent->height, 29, 0, 0x211, h->unitCountEnemy);
				} else {
					GUI_DrawText_Wrapper(String_Get_ByIndex(STR_RADAR_SCANFRIEND_2DENEMY_2D), 18, y, 29, 0, 0x11, h->unitCountAllied, h->unitCountEnemy);
				}
			}
			break;
	}
}

void
ActionPanel_DrawActionDescription(uint16 stringID, int x, int y, uint8 fg)
{
	GUI_DrawText_Wrapper(String_Get_ByIndex(stringID), x, y, fg, 0, 0x11);
}

void
ActionPanel_DrawMissileCountdown(uint8 fg, int count)
{
	if (count <= 0)
		count = 0;

	GUI_DrawText_Wrapper(String_Get_ByIndex(STR_PICK_TARGETTMINUS_D), 19, 44, fg, 0, 0x11, count);
}

/*--------------------------------------------------------------*/

static int
ActionPanel_ProductionButtonStride(const Widget *widget, int *ret_items_per_screen)
{
	const int h = ActionPanel_List_Height(widget);
	const int min_item_height = (s_factory_panel_layout & FACTORYPANEL_LARGE_ICON_FLAG) ? LARGE_PRODUCTION_ICON_MIN_STRIDE : SMALL_PRODUCTION_ICON_MIN_STRIDE;
	const int max_item_height = (s_factory_panel_layout & FACTORYPANEL_LARGE_ICON_FLAG) ? LARGE_PRODUCTION_ICON_MAX_STRIDE : SMALL_PRODUCTION_ICON_MAX_STRIDE;
	const int items_per_screen = h / max_item_height;

	/* Try to squeeze in 1 more item. */
	int reth = h / (items_per_screen + 1);
	if (reth < min_item_height)
		reth = max_item_height;

	if (ret_items_per_screen != NULL)
		*ret_items_per_screen = h / reth;

	return reth;
}

static void
ActionPanel_List_ButtonDimensions(const Widget *widget, int scrollOffsetY,
		int item, int *x1, int *y1, int *x2, int *y2, int *w, int *h)
{
	int items_per_screen;
	const int stride = ActionPanel_ProductionButtonStride(widget, &items_per_screen);
	const int width  = (s_factory_panel_layout & FACTORYPANEL_LARGE_ICON_FLAG) ? LARGE_PRODUCTION_ICON_WIDTH  : SMALL_PRODUCTION_ICON_WIDTH;
	const int height = (s_factory_panel_layout & FACTORYPANEL_LARGE_ICON_FLAG) ? LARGE_PRODUCTION_ICON_HEIGHT : SMALL_PRODUCTION_ICON_HEIGHT;
	const int x = (s_factory_panel_layout & FACTORYPANEL_LARGE_ICON_FLAG) ? (widget->offsetX + 4) : (widget->offsetX + 2);
	const int widget_padding = ActionPanel_List_Height(widget) - items_per_screen * stride;
	int y = widget->offsetY + 1 + scrollOffsetY + stride * item;

	if (items_per_screen <= 0) {
		y += (widget_padding - height) / 2;
	} else {
		const int item_padding = stride - 6 - 2 - height;
		y += (widget_padding + item_padding) / 2 + 6 + 2;
	}

	if (x1 != NULL) *x1 = x;
	if (y1 != NULL) *y1 = y;
	if (x2 != NULL) *x2 = x + width - 1;
	if (y2 != NULL) *y2 = y + height - 1;
	if (w != NULL) *w = width;
	if (h != NULL) *h = height;
}

static void
ActionPanel_ScrollButtonDimensions(const Widget *widget, bool up,
		int *x1, int *y1, int *x2, int *y2)
{
	int x, y;

	if (s_factory_panel_layout == FACTORYPANEL_SMALL_ICONS_WITHOUT_SCROLL) {
		x = widget->offsetX + widget->width - SCROLL_BUTTON_WIDTH - 1;
		y = widget->offsetY + widget->height / 2 - (up ? SCROLL_BUTTON_HEIGHT : 0);
	} else {
		x = widget->offsetX + (up ? 5 : 31);
		y = widget->offsetY + ActionPanel_List_Height(widget) + SCROLL_BUTTON_MARGIN / 2;
	}

	if (x1 != NULL) *x1 = x;
	if (y1 != NULL) *y1 = y;
	if (x2 != NULL) *x2 = x + SCROLL_BUTTON_WIDTH  - 1;
	if (y2 != NULL) *y2 = y + SCROLL_BUTTON_HEIGHT - 1;
}

static void
ActionPanel_ClampScrollOffset(const Widget *widget, int itemCount, int *scrollOffsetY)
{
	int items_per_screen;
	const int stride = ActionPanel_ProductionButtonStride(widget, &items_per_screen);
	const int first_item = itemCount - (items_per_screen <= 1 ? 1 : items_per_screen);
	int y1;

	ActionPanel_List_ButtonDimensions(widget, *scrollOffsetY, first_item, NULL, &y1, NULL, NULL, NULL, NULL);

	if (y1 < widget->offsetY + 16)
		*scrollOffsetY = -stride * first_item;

	if (*scrollOffsetY > 0)
		*scrollOffsetY = 0;
}

static bool
ActionPanel_Scroll(const Widget *widget, int itemCount, int *scrollOffsetY)
{
	int delta = g_mouseDZ;
	int x1, y1, x2, y2;

	ActionPanel_ScrollButtonDimensions(widget, true, &x1, &y1, &x2, &y2);
	if ((widget->state.buttonState & 0x44) && Mouse_InRegion_Div(widget->div, x1, y1, x2, y2))
		delta = 1;

	ActionPanel_ScrollButtonDimensions(widget, false, &x1, &y1, &x2, &y2);
	if ((widget->state.buttonState & 0x44) && Mouse_InRegion_Div(widget->div, x1, y1, x2, y2))
		delta = -1;

	if (delta == 0)
		return false;

	const int stride = ActionPanel_ProductionButtonStride(widget, NULL);

	*scrollOffsetY = stride * (*scrollOffsetY / stride + delta);
	ActionPanel_ClampScrollOffset(widget, itemCount, scrollOffsetY);

	return true;
}

void
ActionPanel_BeginPlacementMode(void)
{
	Structure *ns = Structure_Get_ByIndex(g_playerHouse->structureActiveID);

	g_structureActive = ns;
	g_structureActiveType = ns->o.type;
	g_selectionState = Structure_IsValidBuildLocation(g_playerHouseID, g_selectionRectanglePosition, g_structureActiveType);
	g_structureActivePosition = g_selectionPosition;

	GUI_ChangeSelectionType(SELECTIONTYPE_PLACE);
}

static int
ActionPanel_GetClickedItem(const Widget *widget, int itemCount, int scrollOffsetY)
{
	int mouseY;
	Mouse_TransformToDiv(widget->div, NULL, &mouseY);

	if (mouseY >= widget->offsetY + ActionPanel_List_Height(widget))
		return itemCount;

	int item;
	for (item = 0; item < itemCount; item++) {
		int x1, y1, x2, y2;

		ActionPanel_List_ButtonDimensions(widget, scrollOffsetY, item, &x1, &y1, &x2, &y2, NULL, NULL);
		if (Mouse_InRegion_Div(widget->div, x1, y1, x2, y2))
			break;
	}
	return item;
}

static int
ActionPanel_Factory_GetItemByScancode(uint16 scancode)
{
	int item;
	for (item = 0; item < g_factoryWindowTotal; item++) {
		if (g_factoryWindowItems[item].shortcut == scancode)
			break;
	}
	return item;
}

bool
ActionPanel_ClickUnits(const Widget *widget, uint16 scancode)
{
	if (scancode) return false;

	int unit_count = Unit_CountSelected();
	if (!unit_count) return false;

	ActionPanel_CalculateOptimalLayout(widget);
	ActionPanel_ClampScrollOffset(widget, unit_count, &s_unitOffsetY);
	if (ActionPanel_Scroll(widget, unit_count, &s_unitOffsetY))
		return true;

	if (!(widget->state.buttonState & 0x04)) return false;

	uint16 item = UNIT_INDEX_INVALID;
	int mouseY;
	Mouse_TransformToDiv(widget->div, NULL, &mouseY);

	if (mouseY >= widget->offsetY + ActionPanel_List_Height(widget))
		return false;

	int pi;
	int pos = 0;
	const Unit *u = Unit_FirstSelected(&pi);
	for (; u != NULL; u = Unit_NextSelected(&pi), ++pos) {
		int x1, y1, x2, y2;

		ActionPanel_List_ButtonDimensions(widget, s_unitOffsetY, pos, &x1, &y1, &x2, &y2, NULL, NULL);
		if (Mouse_InRegion_Div(widget->div, x1, y1, x2, y2)) {
			item = u->o.index;
			break;
		}
	}

	if (item == UNIT_INDEX_INVALID) return false;

	bool shift_mod = Input_Test(SCANCODE_LSHIFT);
	bool ctrl_mod = Input_Test(SCANCODE_LCTRL);

	if (ctrl_mod) {
		if (shift_mod) {
			Unit_UnselectType(u->o.type);
		} else {
			Unit_UnselectAllButKeepType(u->o.type);
		}
	} else {
		if (shift_mod) {
			Unit_Unselect(Unit_Get_ByIndex(item));
		} else {
			Unit_UnselectAll();
			Unit_Select(Unit_Get_ByIndex(item));
		}
	}

	return true;
}

bool
ActionPanel_ClickFactory(const Widget *widget, Structure *s, uint16 scancode)
{
	if (s->o.flags.s.upgrading)
		return false;

	if (!scancode && widget->state.keySelected) {
		if (g_productionStringID == STR_PLACE_IT)
			Client_Send_EnterPlacementMode(&s->o);
		return true;
	}

	if (g_factoryWindowTotal < 0) {
		Structure_InitFactoryItems(s);
		ActionPanel_CalculateOptimalLayout(widget);
		ActionPanel_ClampScrollOffset(widget, g_factoryWindowTotal, &s->factoryOffsetY);
	}

	if (scancode == SCANCODE_ESCAPE){
		if(s->queue.last == NULL)
			Client_Send_PauseCancelItem(&s->o, s->objectType);
		else
			Client_Send_PauseCancelItem(&s->o, s->queue.last->objectType);
		return true;
	}

	int item;

	if (scancode) {
		item = ActionPanel_Factory_GetItemByScancode(scancode);
	}
	else {
		if (ActionPanel_Scroll(widget, g_factoryWindowTotal, &s->factoryOffsetY))
			return true;
		else if (!(widget->state.buttonState & 0x44))
			return false;

		item = ActionPanel_GetClickedItem(widget, g_factoryWindowTotal, s->factoryOffsetY);
	}

	if (item >= g_factoryWindowTotal) {
		return false;
	}

	/* Upgrade required. */
	if (g_factoryWindowItems[item].available == -1) {
		if (item < g_factoryWindowTotal)
			Audio_PlaySound(EFFECT_ERROR_OCCURRED);

		return false;
	}

	const uint16 clicked_type = g_factoryWindowItems[item].objectType;
	bool action_successful = true;

	bool action_purchase_resume = false;
	bool action_pause_cancel = false;

	if (scancode){
		action_pause_cancel = Input_Test(SCANCODE_LSHIFT);
		action_purchase_resume = !action_pause_cancel;
	}
	else{
		action_purchase_resume = (widget->state.buttonState & 0x04); //lmb
		action_pause_cancel = (widget->state.buttonState & 0x40);    //rmb
	}

	if (action_purchase_resume) {
		switch (g_productionStringID) {
			case STR_PLACE_IT:
				if ((s->objectType == clicked_type) && (s->o.linkedID != 0xFF) && (s->countDown == 0)) {
					Client_Send_EnterPlacementMode(&s->o);
					break;
				}
				/* Fall through. */
			case STR_ON_HOLD:
				if ((s->objectType == clicked_type) && (s->o.linkedID != 0xFF) && s->o.flags.s.onHold) {
					Client_Send_PurchaseResumeItem(&s->o, clicked_type);
					break;
				}
				/* Fall through */
			case STR_BUILD_IT:
			case STR_COMPLETED:
			case STR_D_DONE:
				if (g_factoryWindowItems[item].available > 0) {
					Client_Send_PurchaseResumeItem(&s->o, clicked_type);
				} else {
					action_successful = false;
				}
				break;

			default:
				break;
		}
	} else if (action_pause_cancel) {
		if ((clicked_type < STRUCTURE_MAX) && true /* (s->numQueued[clicked_type] > 0) */) {
			Client_Send_PauseCancelItem(&s->o, clicked_type);
		} else {
			action_successful = false;
		}
	}

	if (!action_successful) {
		Audio_PlaySound(EFFECT_ERROR_OCCURRED);
	}

	return false;
}

static void
ActionPanel_ClickStarportPlus(const Structure *s, int entry)
{
	const FactoryWindowItem *item = &g_factoryWindowItems[entry];

	if ((g_starportAvailable[item->objectType] > 0) && (item->credits <= g_playerHouse->credits)) {
		Client_Send_PurchaseResumeItem(&s->o, item->objectType);
	} else {
		Audio_PlaySound(EFFECT_ERROR_OCCURRED);
	}
}

static void
ActionPanel_ClickStarportMinus(const Structure *s, int entry)
{
	const FactoryWindowItem *item = &g_factoryWindowItems[entry];

	if (g_playerHouse->starportCount[item->objectType] > 0)
		Client_Send_PauseCancelItem(&s->o, item->objectType);
}

bool
ActionPanel_ClickStarport(const Widget *widget, Structure *s, uint16 scancode)
{
	if (scancode == SCANCODE_D) {
		if (!House_StarportQueueEmpty(g_playerHouse))
			Client_Send_SendStarportOrder(&s->o);
		return true;
	}

	if (g_factoryWindowTotal < 0) {
		Structure_InitFactoryItems(s);
		ActionPanel_CalculateOptimalLayout(widget);
		ActionPanel_ClampScrollOffset(widget, g_factoryWindowTotal, &s->factoryOffsetY);
	}

	bool action_plus;
	bool action_minus;

	if (scancode){
		action_minus = Input_Test(SCANCODE_LSHIFT);
		action_plus = !action_minus;
	}
	else{
		action_plus = (widget->state.buttonState & 0x04);   //lmb
		action_minus = (widget->state.buttonState & 0x40);  //rmb
	}

	int item;

	if (scancode == 0) {
		if (ActionPanel_Scroll(widget, g_factoryWindowTotal, &s->factoryOffsetY))
			return true;
		else if (!(widget->state.buttonState & 0x44))
			return false;

		item = ActionPanel_GetClickedItem(widget, g_factoryWindowTotal, s->factoryOffsetY);
	}
	else {
		item = ActionPanel_Factory_GetItemByScancode(scancode);
	}

	if (!(0 <= item && item < g_factoryWindowTotal))
		return false;

	if (action_plus) {
		ActionPanel_ClickStarportPlus(s, item);
	} else if (action_minus) {
		ActionPanel_ClickStarportMinus(s, item);
	}

	return false;
}

bool
ActionPanel_ClickPalace(const Widget *widget, Structure *s, uint16 scancode)
{
	if (scancode != 0) {
		if (scancode == SCANCODE_S) {
			Client_Send_ActivateSuperweapon(&s->o);
			return true;
		}
		return false;
	}

	const bool lmb = (widget->state.buttonState & 0x04);
	int x1, x2, y1, y2;

	g_factoryWindowTotal = 0;

	ActionPanel_List_ButtonDimensions(widget, s->factoryOffsetY, 0, &x1, &y1, &x2, &y2, NULL, NULL);
	if (lmb && Mouse_InRegion_Div(widget->div, x1, y1, x2, y2)) {
		Client_Send_ActivateSuperweapon(&s->o);
		return true;
	}

	return false;
}

static void
ActionPanel_DrawStructureLayout(enum StructureType s, int x1, int y1)
{
	if (!(s_factory_panel_layout & FACTORYPANEL_LARGE_ICON_FLAG))
		return;

	const StructureInfo *si = &g_table_structureInfo[s];
	const int lw = g_table_structure_layoutSize[si->layout].width;
	const int lh = g_table_structure_layoutSize[si->layout].height;
	const int size = 6;

	x1 += 31;
	y1 += 4;

	/* Use shadow effect for transluscent outline. */
	Shape_Draw(SHAPE_STRUCTURE_LAYOUT_OUTLINE, x1 - 1, y1 - 1, 0, 0x340);

	/* Shift layout to the right. */
	for (int ly = 0; ly < lh; ly++) {
		for (int lx = 3 - lw; lx < 3; lx++) {
			Shape_Draw(SHAPE_STRUCTURE_LAYOUT_BLOCK, x1 + size * lx, y1 + size * ly, 0, 0);
		}
	}
}

static void
ActionPanel_DrawScrollButtons(const Widget *widget, int itemCount)
{
	int items_per_screen;

	ActionPanel_ProductionButtonStride(widget, &items_per_screen);
	if (itemCount <= items_per_screen)
		return;

	const bool pressed = (widget->state.hover1);
	int x1, y1, x2, y2;

	ActionPanel_ScrollButtonDimensions(widget, true, &x1, &y1, &x2, &y2);
	if (pressed && Mouse_InRegion_Div(widget->div, x1, y1, x2, y2)) {
		Shape_Draw(SHAPE_SAVE_LOAD_SCROLL_UP_PRESSED, x1, y1, 0, 0);
	} else if ((s_factory_panel_layout != FACTORYPANEL_SMALL_ICONS_WITHOUT_SCROLL)
			|| Mouse_InRegion_Div(widget->div, x1, y1, x2, y2 + 15)) {
		Shape_Draw(SHAPE_SAVE_LOAD_SCROLL_UP, x1, y1, 0, 0);
	}

	ActionPanel_ScrollButtonDimensions(widget, false, &x1, &y1, &x2, &y2);
	if (pressed && Mouse_InRegion_Div(widget->div, x1, y1, x2, y2)) {
		Shape_Draw(SHAPE_SAVE_LOAD_SCROLL_DOWN_PRESSED, x1, y1, 0, 0);
	} else if ((s_factory_panel_layout != FACTORYPANEL_SMALL_ICONS_WITHOUT_SCROLL)
			|| Mouse_InRegion_Div(widget->div, x1, y1 - 15, x2, y2)) {
		Shape_Draw(SHAPE_SAVE_LOAD_SCROLL_DOWN, x1, y1, 0, 0);
	}
}

void
ActionPanel_HighlightIcon(enum HouseType houseID, int x1, int y1, bool large_icon)
{
	static int64_t paletteChangeTimer;
	static int paletteColour;
	static int paletteChange = 8;

	unsigned char r, g, b;

	if (paletteChangeTimer <= Timer_GetTicks()) {
		paletteChangeTimer = Timer_GetTicks() + 3;
		paletteColour += paletteChange;
	}

	if (paletteColour < 0 || paletteColour > 63) {
		paletteChange = -paletteChange;
		paletteColour += paletteChange;
	}

	switch (houseID) {
		case HOUSE_HARKONNEN:
			r = 4 * 63;
			g = 4 * paletteColour;
			b = 4 * paletteColour;
			break;

		case HOUSE_ATREIDES:
			r = 4 * paletteColour;
			g = 4 * paletteColour;
			b = 4 * 63;
			break;

		case HOUSE_ORDOS:
			r = 4 * paletteColour;
			g = 4 * 63;
			b = 4 * paletteColour;
			break;

		case HOUSE_FREMEN:
			r = 4 * 63;
			g = 4 * 63 - 2 * paletteColour;
			b = 4 * 63 - 4 * paletteColour;
			break;

		case HOUSE_SARDAUKAR:
			r = 4 * 63;
			g = 4 * 63 - 4 * paletteColour;
			b = 4 * 63 - 1 * paletteColour;
			break;

		case HOUSE_MERCENARY:
			r = 4 * 63;
			g = 4 * 63 - 1 * paletteColour;
			b = 4 * 63 - 4 * paletteColour;
			break;

		default:
			return;
	}

	if (large_icon) {
		Prim_Rect_RGBA(x1 + 1.0f, y1 + 0.5f, x1 + 52.0f, y1 + 38.0f, r, g, b, 0xFF, 3.0f);
	} else {
		Prim_Rect_RGBA(x1 + 1.0f, y1 + 1.0f, x1 + 31.0f, y1 + 23.0f, r, g, b, 0xFF, 2.0f);
	}
}

void
ActionPanel_DrawUnits(const Widget *widget)
{
	int unit_count = Unit_CountSelected();
	if (!unit_count) return;

	ActionPanel_CalculateOptimalLayout(widget);
	ActionPanel_ClampScrollOffset(widget, unit_count, &s_unitOffsetY);

	const ScreenDiv *div = &g_screenDiv[SCREENDIV_SIDEBAR];
	int height = widget->height;

	const int itemlist_height = ActionPanel_List_Height(widget);

	Prim_DrawBorder(widget->offsetX, widget->offsetY, widget->width, height, 1, false, true, 0);
	Video_SetClippingArea(0, div->scaley * (widget->offsetY + 1), TRUE_DISPLAY_WIDTH, div->scaley * itemlist_height);

	int pi;
	int pos = 0;
	const Unit *u = Unit_FirstSelected(&pi);
	for (; u != NULL; u = Unit_NextSelected(&pi), ++pos) {
		const UnitInfo *ui = &g_table_unitInfo[u->o.type];
		const enum ShapeID shapeID = ui->o.spriteID;

		int x1, y1, w, h;

		ActionPanel_List_ButtonDimensions(widget, s_unitOffsetY, pos, &x1, &y1, NULL, NULL, &w, &h);
		if (y1 > widget->offsetY + itemlist_height)
			break;

		if (y1 < widget->offsetY)
			continue;

		Shape_DrawScale(shapeID, x1, y1, w, h, 0, 0);
		ActionPanel_DrawCustomHealthBar(u->o.hitpoints, ui->o.hitpoints, x1, y1 - 5, w - 2, 3);
	}

	Video_SetClippingArea(0, div->scaley * (widget->offsetY + 1), TRUE_DISPLAY_WIDTH, div->scaley * (widget->height - 2));
	ActionPanel_DrawScrollButtons(widget, unit_count);
	Video_SetClippingArea(0, 0, TRUE_DISPLAY_WIDTH, TRUE_DISPLAY_HEIGHT);
}

void
ActionPanel_DrawFactory(const Widget *widget, Structure *s)
{
	if (g_factoryWindowTotal < 0) {
		Structure_InitFactoryItems(s);
		ActionPanel_CalculateOptimalLayout(widget);
		ActionPanel_ClampScrollOffset(widget, g_factoryWindowTotal, &s->factoryOffsetY);
	}

	const ScreenDiv *div = &g_screenDiv[SCREENDIV_SIDEBAR];
	int height = widget->height;

	const int itemlist_height = ActionPanel_List_Height(widget);

	Prim_DrawBorder(widget->offsetX, widget->offsetY, widget->width, height, 1, false, true, 0);
	Video_SetClippingArea(0, div->scaley * (widget->offsetY + 1), TRUE_DISPLAY_WIDTH, div->scaley * itemlist_height);

	const int xcentre = widget->offsetX + widget->width / 2;

	for (int item = 0; item < g_factoryWindowTotal; item++) {
		const uint16 object_type = g_factoryWindowItems[item].objectType;
		const enum ShapeID shapeID = g_factoryWindowItems[item].shapeID;

		const char *name;
		int x1, y1, w, h;
		int fg = 0xF;

		ActionPanel_List_ButtonDimensions(widget, s->factoryOffsetY, item, &x1, &y1, NULL, NULL, &w, &h);
		if (y1 > widget->offsetY + itemlist_height)
			break;

		if (y1 < widget->offsetY)
			continue;

		if (s->o.type == STRUCTURE_CONSTRUCTION_YARD) {
			name = String_Get_ByIndex(g_table_structureInfo[object_type].o.stringID_abbrev);
		} else {
			name = String_Get_ByIndex(g_table_unitInfo[object_type].o.stringID_abbrev);
		}

		if ((s->o.type == STRUCTURE_STARPORT) && (g_starportAvailable[object_type] < 0)) {
			Shape_DrawGreyScale(shapeID, x1, y1, w, h, 0, 0);
		} else if (g_factoryWindowItems[item].available < 0) {
			Shape_DrawGreyScale(shapeID, x1, y1, w, h, 0, 0);

			/* Draw layout. */
			if (s->o.type == STRUCTURE_CONSTRUCTION_YARD)
				ActionPanel_DrawStructureLayout(object_type, x1, y1);
		} else {
			Shape_DrawScale(shapeID, x1, y1, w, h, 0, 0);

			/* Draw layout. */
			if (s->o.type == STRUCTURE_CONSTRUCTION_YARD)
				ActionPanel_DrawStructureLayout(object_type, x1, y1);
		}

		/* Draw production status. */
		if (s->o.type == STRUCTURE_STARPORT) {
			if ((g_starportAvailable[object_type] < 0) && (s_factory_panel_layout & FACTORYPANEL_LARGE_ICON_FLAG)) {
				GUI_DrawText_Wrapper("OUT OF", xcentre, y1 +  7, 6, 0, 0x132);
				GUI_DrawText_Wrapper("STOCK",  xcentre, y1 + 18, 6, 0, 0x132);
			}
		} else if (g_factoryWindowItems[item].available < 0) {
			if (s_factory_panel_layout & FACTORYPANEL_LARGE_ICON_FLAG) {
				const int yupper = y1 + 7;
				const int ylower = y1 + 18;

				GUI_DrawText_Wrapper("UPGRADE", xcentre, yupper, 6, 0, 0x132);
				GUI_DrawText_Wrapper("NEEDED", xcentre, ylower, 6, 0, 0x132);
			}

			/* Make upgrade cost yellow to distinguish it from unit cost. */
			fg = 5;
		}

		/* Draw abbreviated name. */
		if (y1 - 8 >= widget->offsetY + 2)
			GUI_DrawText_Wrapper(name, xcentre, y1 - 9, 5, 0, 0x161);

		/* Draw credits. */
		if (s_factory_panel_layout & FACTORYPANEL_LARGE_ICON_FLAG) {
			GUI_DrawText_Wrapper("%d", x1 + 1, y1 + h - 8, fg, 0, 0x31, g_factoryWindowItems[item].credits);
			GUI_DrawText_Wrapper("%c", x1 + 1, y1 + 2, fg, 0, 0x31, GUI_Widget_ScancodeToChar(g_factoryWindowItems[item].shortcut));
		} else if ((s->objectType != object_type) || (g_productionStringID != STR_PLACE_IT)) {
			GUI_DrawText_Wrapper("%d", widget->offsetX + widget->width - 3, y1 + 2, fg, 0, 0x231, g_factoryWindowItems[item].credits);
			GUI_DrawText_Wrapper("%c", widget->offsetX + widget->width - 3, y1 + h - 8, fg, 0, 0x231, GUI_Widget_ScancodeToChar(g_factoryWindowItems[item].shortcut));
		}

		/* Draw build queue count. */
		int count;
		if (s->o.type == STRUCTURE_STARPORT) {
			count = g_playerHouse->starportCount[object_type];
		} else {
			count = BuildQueue_Count(&s->queue, object_type);
		}

		if (count > 0) {
			if ((s->objectType == object_type) && (s->o.linkedID != 0xFF))
				count++;

			if (s_factory_panel_layout & FACTORYPANEL_LARGE_ICON_FLAG) {
				GUI_DrawText_Wrapper("x%d", widget->offsetX + widget->width - 5, y1 + h - 10, 15, 0, 0x232, count);
			} else {
				GUI_DrawText_Wrapper("x%d", widget->offsetX + widget->width - 3, y1 + h - 10, 15, 0, 0x232, count);
			}
		}
	}

	Video_SetClippingArea(0, div->scaley * (widget->offsetY + 1), TRUE_DISPLAY_WIDTH, div->scaley * (widget->height - 2));
	ActionPanel_DrawScrollButtons(widget, g_factoryWindowTotal);
	Video_SetClippingArea(0, 0, TRUE_DISPLAY_WIDTH, TRUE_DISPLAY_HEIGHT);
}

void
ActionPanel_DrawPalace(const Widget *widget, Structure *s)
{
	const ScreenDiv *div = &g_screenDiv[SCREENDIV_SIDEBAR];
	enum ShapeID shapeID;
	const char *name;
	const char *deploy;
	uint16 type;
	int x, y, w, h;
	int fg = 0xF;
	VARIABLE_NOT_USED(s);

	switch (g_productionStringID) {
		case STR_LAUNCH:
			shapeID = SHAPE_DEATH_HAND;
			name = g_table_unitInfo[UNIT_MISSILE_HOUSE].o.name;
			deploy = String_Get_ByIndex(STR_LAUNCH);
			break;

		case STR_FREMEN:
			shapeID = SHAPE_FREMEN_SQUAD;
			name = String_Get_ByIndex(g_productionStringID);
			deploy = String_Get_ByIndex(STR_DEPLOY);
			break;

		case STR_SABOTEUR:
			type = g_table_houseInfo[g_playerHouseID].superWeapon.saboteur.unit;
			shapeID = g_table_unitInfo[type].o.spriteID;
			name = String_Get_ByIndex(g_productionStringID);
			deploy = String_Get_ByIndex(STR_DEPLOY);
			break;

		default:
			return;
	}

	if (g_factoryWindowTotal != 0) {
		g_factoryWindowTotal = 0;
		ActionPanel_CalculateOptimalLayout(widget);
	}

	ActionPanel_List_ButtonDimensions(widget, s->factoryOffsetY, 0, &x, &y, NULL, NULL, &w, &h);
	Prim_DrawBorder(widget->offsetX, widget->offsetY, widget->width, widget->height, 1, false, true, 0);
	Video_SetClippingArea(0, div->scaley * widget->offsetY, TRUE_DISPLAY_WIDTH, div->scaley * (widget->height - 2));

	const int xcentre = widget->offsetX + widget->width / 2;

	Shape_DrawScale(shapeID, x, y, w, h, 0, 0);

	/* Draw abbreviated name. */
	if (y - 8 >= widget->offsetY + 2)
		GUI_DrawText_Wrapper(name, xcentre, y - 9, 5, 0, 0x161);

	if (y + h + 1 + 6 < widget->offsetY + widget->height)
		GUI_DrawText_Wrapper(deploy, xcentre, y + h + 1, 0xF, 0, 0x161);

	if (s_factory_panel_layout & FACTORYPANEL_LARGE_ICON_FLAG) {
		GUI_DrawText_Wrapper("%c", x + 1, y + 2, fg, 0, 0x31, 'S');
	} else {
		GUI_DrawText_Wrapper("%c", widget->offsetX + widget->width - 3, y + h - 8, fg, 0, 0x231, 'S');
	}

	Video_SetClippingArea(0, 0, TRUE_DISPLAY_WIDTH, TRUE_DISPLAY_HEIGHT);
}
