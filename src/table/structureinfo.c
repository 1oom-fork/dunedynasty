/** @file src/table/structureinfo.c StructureInfo file table. */

#include <stdio.h>
#include "enum_string.h"
#include "enumeration.h"
#include "../input/scancode.h"

#include "../shape.h"
#include "../sprites.h"
#include "../structure.h"

const StructureInfo g_table_structureInfo_original[STRUCTURE_MAX] = {
	{ /* 0 */
		{ /* objectInfo */
		/* stringID_abbrev      */ STR_CONCRETE,
		/* name                 */ "Concrete",
		/* stringID_full        */ STR_SMALL_CONCRETE_SLAB,
		/* wsa                  */ "slab.wsa",
		{ /* flags */
		/* hasShadow            */ false,
		/* factory              */ false,
		/* notOnConcrete        */ true,
		/* busyStateIsIncoming  */ false,
		/* blurTile             */ false,
		/* hasTurret            */ false,
		/* conquerable          */ false,
		/* canBePickedUp        */ false,
		/* noMessageOnDeath     */ false,
		/* tabSelectable        */ false,
		/* scriptNoSlowdown     */ true,
		/* targetAir            */ false,
		/* priority             */ false
		},
		/* spawnChance          */ 0,
		/* hitpoints            */ 20,
		/* fogUncoverRadius     */ 1,
		/* spriteID             */ SHAPE_CONCRETE_SLAB,
		/* buildCredits         */ 5,
		/* buildTime            */ 16,
		/* availableCampaign    */ { 1, 1, 1, 1, 1, 1 },
		/* structuresRequired   */ FLAG_STRUCTURE_NONE,
		/* sortPriority         */ 100, /* was 2, but 100 is used (special case). */
		/* upgradeLevelRequired */ { 0, 0, 0, 0, 0, 0 },
		/* actionsPlayer        */ { ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK },
		/* available            */ 0,
		/* hintStringID         */ STR_HINT_CONCRETE,
		/* priorityBuild        */ 0,
		/* priorityTarget       */ 5,
		/* availableHouse       */ FLAG_HOUSE_ALL,
		},
		/* enterFilter          */ FLAG_UNIT_NONE,
		/* creditsStorage       */ 0,
		/* powerUsage           */ 0,
		/* layout               */ STRUCTURE_LAYOUT_1x1,
		/* iconGroup            */ ICM_ICONGROUP_CONCRETE_SLAB,
		{ /* animationIndex */
		/* [0]                  */ 2,
		/* [1]                  */ 2,
		/* [2]                  */ 2
		},
		{ /* buildableUnits */
		/* [0]                  */ UNIT_INVALID,
		/* [1]                  */ UNIT_INVALID,
		/* [2]                  */ UNIT_INVALID,
		/* [3]                  */ UNIT_INVALID,
		/* [4]                  */ UNIT_INVALID,
		/* [5]                  */ UNIT_INVALID,
		/* [6]                  */ UNIT_INVALID,
		/* [7]                  */ UNIT_INVALID,
		},
		{ /* upgradeCampaign */
		/* [0]                  */ { 0, 0, 0, 0, 0, 0 },
		/* [1]                  */ { 0, 0, 0, 0, 0, 0 },
		/* [2]                  */ { 0, 0, 0, 0, 0, 0 },
		},
		/* shortcut             */ SCANCODE_X
	},

	{ /* 1 */
		{ /* objectInfo */
		/* stringID_abbrev      */ STR_CONCRETE_4,
		/* name                 */ "Concrete4",
		/* stringID_full        */ STR_LARGE_CONCRETE_SLAB,
		/* wsa                  */ "4slab.wsa",
		{ /* flags */
		/* hasShadow            */ false,
		/* factory              */ false,
		/* notOnConcrete        */ true,
		/* busyStateIsIncoming  */ false,
		/* blurTile             */ false,
		/* hasTurret            */ false,
		/* conquerable          */ false,
		/* canBePickedUp        */ false,
		/* noMessageOnDeath     */ false,
		/* tabSelectable        */ false,
		/* scriptNoSlowdown     */ true,
		/* targetAir            */ false,
		/* priority             */ false
		},
		/* spawnChance          */ 0,
		/* hitpoints            */ 20,
		/* fogUncoverRadius     */ 1,
		/* spriteID             */ SHAPE_LARGE_CONCRETE_SLAB,
		/* buildCredits         */ 20,
		/* buildTime            */ 16,
		/* availableCampaign    */ { 4, 4, 4, 4, 4, 4 },
		/* structuresRequired   */ FLAG_STRUCTURE_NONE,
		/* sortPriority         */ 101, /* was 4, but 100 is used (special case).  Put this ABOVE concrete reliably. */
		/* upgradeLevelRequired */ { 1, 1, 1, 1, 1, 1 },
		/* actionsPlayer        */ { ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK },
		/* available            */ 0,
		/* hintStringID         */ STR_HINT_CONCRETE,
		/* priorityBuild        */ 0,
		/* priorityTarget       */ 10,
		/* availableHouse       */ FLAG_HOUSE_ALL,
		},
		/* enterFilter          */ FLAG_UNIT_NONE,
		/* creditsStorage       */ 0,
		/* powerUsage           */ 0,
		/* layout               */ STRUCTURE_LAYOUT_2x2,
		/* iconGroup            */ ICM_ICONGROUP_CONCRETE_SLAB,
		{ /* animationIndex */
		/* [0]                  */ 2,
		/* [1]                  */ 2,
		/* [2]                  */ 2
		},
		{ /* buildableUnits */
		/* [0]                  */ UNIT_INVALID,
		/* [1]                  */ UNIT_INVALID,
		/* [2]                  */ UNIT_INVALID,
		/* [3]                  */ UNIT_INVALID,
		/* [4]                  */ UNIT_INVALID,
		/* [5]                  */ UNIT_INVALID,
		/* [6]                  */ UNIT_INVALID,
		/* [7]                  */ UNIT_INVALID,
		},
		{ /* upgradeCampaign */
		/* [0]                  */ { 0, 0, 0, 0, 0, 0 },
		/* [1]                  */ { 0, 0, 0, 0, 0, 0 },
		/* [2]                  */ { 0, 0, 0, 0, 0, 0 },
		},
		/* shortcut             */ SCANCODE_Z
	},

	{ /* 2 */
		{ /* objectInfo */
		/* stringID_abbrev      */ STR_PALACE,
		/* name                 */ "Palace",
		/* stringID_full        */ STR_HOUSE_PALACE,
		/* wsa                  */ "palace.wsa",
		{ /* flags */
		/* hasShadow            */ false,
		/* factory              */ false,
		/* notOnConcrete        */ false,
		/* busyStateIsIncoming  */ false,
		/* blurTile             */ false,
		/* hasTurret            */ false,
		/* conquerable          */ false,
		/* canBePickedUp        */ false,
		/* noMessageOnDeath     */ false,
		/* tabSelectable        */ false,
		/* scriptNoSlowdown     */ true,
		/* targetAir            */ false,
		/* priority             */ false
		},
		/* spawnChance          */ 128,
		/* hitpoints            */ 1000,
		/* fogUncoverRadius     */ 5,
		/* spriteID             */ SHAPE_PALACE,
		/* buildCredits         */ 999,
		/* buildTime            */ 130,
		/* availableCampaign    */ { 8, 8, 8, 8, 8, 8 },
		/* structuresRequired   */ FLAG_STRUCTURE_STARPORT,
		/* sortPriority         */ 5,
		/* upgradeLevelRequired */ { 0, 0, 0, 0, 0, 0 },
		/* actionsPlayer        */ { ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK },
		/* available            */ 0,
		/* hintStringID         */ STR_HINT_PALACE,
		/* priorityBuild        */ 0,
		/* priorityTarget       */ 400,
		/* availableHouse       */ FLAG_HOUSE_ALL,
		},
		/* enterFilter          */ FLAG_UNIT_NONE,
		/* creditsStorage       */ 0,
		/* powerUsage           */ 80,
		/* layout               */ STRUCTURE_LAYOUT_3x3,
		/* iconGroup            */ ICM_ICONGROUP_HOUSE_PALACE,
		{ /* animationIndex */
		/* [0]                  */ 4,
		/* [1]                  */ 4,
		/* [2]                  */ 4
		},
		{ /* buildableUnits */
		/* [0]                  */ UNIT_INVALID,
		/* [1]                  */ UNIT_INVALID,
		/* [2]                  */ UNIT_INVALID,
		/* [3]                  */ UNIT_INVALID,
		/* [4]                  */ UNIT_INVALID,
		/* [5]                  */ UNIT_INVALID,
		/* [6]                  */ UNIT_INVALID,
		/* [7]                  */ UNIT_INVALID,
		},
		{ /* upgradeCampaign */
		/* [0]                  */ { 0, 0, 0, 0, 0, 0 },
		/* [1]                  */ { 0, 0, 0, 0, 0, 0 },
		/* [2]                  */ { 0, 0, 0, 0, 0, 0 },
		},
		/* shortcut             */ SCANCODE_A
	},

	{ /* 3 */
		{ /* objectInfo */
		/* stringID_abbrev      */ STR_LIGHT_FCTRY,
		/* name                 */ "Light Fctry",
		/* stringID_full        */ STR_LIGHT_VEHICLE_FACTORY,
		/* wsa                  */ "liteftry.wsa",
		{ /* flags */
		/* hasShadow            */ false,
		/* factory              */ true,
		/* notOnConcrete        */ false,
		/* busyStateIsIncoming  */ false,
		/* blurTile             */ false,
		/* hasTurret            */ false,
		/* conquerable          */ true,
		/* canBePickedUp        */ false,
		/* noMessageOnDeath     */ false,
		/* tabSelectable        */ false,
		/* scriptNoSlowdown     */ true,
		/* targetAir            */ false,
		/* priority             */ false
		},
		/* spawnChance          */ 64,
		/* hitpoints            */ 350,
		/* fogUncoverRadius     */ 3,
		/* spriteID             */ SHAPE_LIGHT_VEHICLE,
		/* buildCredits         */ 400,
		/* buildTime            */ 96,
		/* availableCampaign    */ { 3, 2, 2, 2, 2, 2 }, /* Non-H trait: light factory one level earlier. */
		/* structuresRequired   */ FLAG_STRUCTURE_REFINERY | FLAG_STRUCTURE_WINDTRAP,
		/* sortPriority         */ 14,
		/* upgradeLevelRequired */ { 0, 0, 0, 0, 0, 0 },
		/* actionsPlayer        */ { ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK },
		/* available            */ 0,
		/* hintStringID         */ STR_HINT_LIGHT_FACTORY,
		/* priorityBuild        */ 0,
		/* priorityTarget       */ 200,
		/* availableHouse       */ FLAG_HOUSE_ALL,
		},
		/* enterFilter          */ FLAG_UNIT_NONE,
		/* creditsStorage       */ 0,
		/* powerUsage           */ 20,
		/* layout               */ STRUCTURE_LAYOUT_2x2,
		/* iconGroup            */ ICM_ICONGROUP_LIGHT_VEHICLE_FACTORY,
		{ /* animationIndex */
		/* [0]                  */ 14,
		/* [1]                  */ 15,
		/* [2]                  */ 16
		},
		{ /* buildableUnits */
		/* [0]                  */ UNIT_TRIKE,
		/* [1]                  */ UNIT_RAIDER_TRIKE,
		/* [2]                  */ UNIT_QUAD,
		/* [3]                  */ UNIT_INVALID,
		/* [4]                  */ UNIT_INVALID,
		/* [5]                  */ UNIT_INVALID,
		/* [6]                  */ UNIT_INVALID,
		/* [7]                  */ UNIT_INVALID,
		},
		{ /* upgradeCampaign */
		/* [0]                  */ { 3, 3, 3, 3, 3, 3 },
		/* [1]                  */ { 0, 0, 0, 0, 0, 0 },
		/* [2]                  */ { 0, 0, 0, 0, 0, 0 },
		},
		/* shortcut             */ SCANCODE_F
	},

	{ /* 4 */
		{ /* objectInfo */
		/* stringID_abbrev      */ STR_HEAVY_FCTRY,
		/* name                 */ "Heavy Fctry",
		/* stringID_full        */ STR_HEAVY_VEHICLE_FACTORY,
		/* wsa                  */ "hvyftry.wsa",
		{ /* flags */
		/* hasShadow            */ false,
		/* factory              */ true,
		/* notOnConcrete        */ false,
		/* busyStateIsIncoming  */ false,
		/* blurTile             */ false,
		/* hasTurret            */ false,
		/* conquerable          */ true,
		/* canBePickedUp        */ false,
		/* noMessageOnDeath     */ false,
		/* tabSelectable        */ false,
		/* scriptNoSlowdown     */ true,
		/* targetAir            */ false,
		/* priority             */ false
		},
		/* spawnChance          */ 64,
		/* hitpoints            */ 200,
		/* fogUncoverRadius     */ 3,
		/* spriteID             */ SHAPE_HEAVY_VEHICLE,
		/* buildCredits         */ 600,
		/* buildTime            */ 144,
		/* availableCampaign    */ { 4, 4, 4, 4, 4, 4 },
		/* structuresRequired   */ FLAG_STRUCTURE_OUTPOST | FLAG_STRUCTURE_WINDTRAP | FLAG_STRUCTURE_LIGHT_VEHICLE,
		/* sortPriority         */ 28,
		/* upgradeLevelRequired */ { 0, 0, 0, 0, 0, 0 },
		/* actionsPlayer        */ { ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK },
		/* available            */ 0,
		/* hintStringID         */ STR_HINT_HEAVY_FACTORY,
		/* priorityBuild        */ 0,
		/* priorityTarget       */ 600,
		/* availableHouse       */ FLAG_HOUSE_ALL,
		},
		/* enterFilter          */ FLAG_UNIT_NONE,
		/* creditsStorage       */ 0,
		/* powerUsage           */ 35,
		/* layout               */ STRUCTURE_LAYOUT_3x2,
		/* iconGroup            */ ICM_ICONGROUP_HEAVY_VEHICLE_FACTORY,
		{ /* animationIndex */
		/* [0]                  */ 11,
		/* [1]                  */ 12,
		/* [2]                  */ 13
		},
		{ /* buildableUnits */
		/* [0]                  */ UNIT_SIEGE_TANK,
		/* [1]                  */ UNIT_LAUNCHER,
		/* [2]                  */ UNIT_HARVESTER,
		/* [3]                  */ UNIT_TANK,
		/* [4]                  */ UNIT_DEVASTATOR,
		/* [5]                  */ UNIT_DEVIATOR,
		/* [6]                  */ UNIT_MCV,
		/* [7]                  */ UNIT_SONIC_TANK,
		},
		{ /* upgradeCampaign */
		/* [0]                  */ { 4, 4, 4, 4, 4, 4 },
		/* [1]                  */ { 5, 5, 5, 5, 5, 5 },
		/* [2]                  */ { 6, 6, 7, 6, 6, 6 }, /* O trait: siege tanks one level later. */
		},
		/* shortcut             */ SCANCODE_H
	},

	{ /* 5 */
		{ /* objectInfo */
		/* stringID_abbrev      */ STR_HITECH,
		/* name                 */ "Hi-Tech",
		/* stringID_full        */ STR_HITECH_FACTORY,
		/* wsa                  */ "hitcftry.wsa",
		{ /* flags */
		/* hasShadow            */ false,
		/* factory              */ true,
		/* notOnConcrete        */ false,
		/* busyStateIsIncoming  */ false,
		/* blurTile             */ false,
		/* hasTurret            */ false,
		/* conquerable          */ true,
		/* canBePickedUp        */ false,
		/* noMessageOnDeath     */ false,
		/* tabSelectable        */ false,
		/* scriptNoSlowdown     */ true,
		/* targetAir            */ false,
		/* priority             */ false
		},
		/* spawnChance          */ 64,
		/* hitpoints            */ 400,
		/* fogUncoverRadius     */ 3,
		/* spriteID             */ SHAPE_HIGH_TECH,
		/* buildCredits         */ 500,
		/* buildTime            */ 120,
		/* availableCampaign    */ { 5, 5, 5, 5, 5, 5 },
		/* structuresRequired   */ FLAG_STRUCTURE_OUTPOST | FLAG_STRUCTURE_WINDTRAP | FLAG_STRUCTURE_LIGHT_VEHICLE,
		/* sortPriority         */ 30,
		/* upgradeLevelRequired */ { 0, 0, 0, 0, 0, 0 },
		/* actionsPlayer        */ { ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK },
		/* available            */ 0,
		/* hintStringID         */ STR_HINT_HITECH_FACTORY,
		/* priorityBuild        */ 0,
		/* priorityTarget       */ 200,
		/* availableHouse       */ FLAG_HOUSE_ALL,
		},
		/* enterFilter          */ FLAG_UNIT_NONE,
		/* creditsStorage       */ 0,
		/* powerUsage           */ 35,
		/* layout               */ STRUCTURE_LAYOUT_3x2,
		/* iconGroup            */ ICM_ICONGROUP_HI_TECH_FACTORY,
		{ /* animationIndex */
		/* [0]                  */ 8,
		/* [1]                  */ 9,
		/* [2]                  */ 10
		},
		{ /* buildableUnits */
		/* [0]                  */ UNIT_CARRYALL,
		/* [1]                  */ UNIT_ORNITHOPTER,
		/* [2]                  */ UNIT_INVALID,
		/* [3]                  */ UNIT_INVALID,
		/* [4]                  */ UNIT_INVALID,
		/* [5]                  */ UNIT_INVALID,
		/* [6]                  */ UNIT_INVALID,
		/* [7]                  */ UNIT_INVALID,
		},
		{ /* upgradeCampaign */
		/* [0]                  */ { 0, 7, 7, 7, 7, 7 }, /* H trait: no ornithopters. */
		/* [1]                  */ { 0, 0, 0, 0, 0, 0 },
		/* [2]                  */ { 0, 0, 0, 0, 0, 0 },
		},
		/* shortcut             */ SCANCODE_V
	},

	{ /* 6 */
		{ /* objectInfo */
		/* stringID_abbrev      */ STR_IX,
		/* name                 */ "IX",
		/* stringID_full        */ STR_HOUSE_OF_IX,
		/* wsa                  */ "ix.wsa",
		{ /* flags */
		/* hasShadow            */ false,
		/* factory              */ false,
		/* notOnConcrete        */ false,
		/* busyStateIsIncoming  */ false,
		/* blurTile             */ false,
		/* hasTurret            */ false,
		/* conquerable          */ false,
		/* canBePickedUp        */ false,
		/* noMessageOnDeath     */ false,
		/* tabSelectable        */ false,
		/* scriptNoSlowdown     */ true,
		/* targetAir            */ false,
		/* priority             */ false
		},
		/* spawnChance          */ 192,
		/* hitpoints            */ 400,
		/* fogUncoverRadius     */ 3,
		/* spriteID             */ SHAPE_HOUSE_OF_IX,
		/* buildCredits         */ 500,
		/* buildTime            */ 120,
		/* availableCampaign    */ { 7, 7, 7, 7, 7, 7 },
		/* structuresRequired   */ FLAG_STRUCTURE_REFINERY | FLAG_STRUCTURE_STARPORT | FLAG_STRUCTURE_WINDTRAP,
		/* sortPriority         */ 34,
		/* upgradeLevelRequired */ { 0, 0, 0, 0, 0, 0 },
		/* actionsPlayer        */ { ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK },
		/* available            */ 0,
		/* hintStringID         */ STR_HINT_HOUSE_IX,
		/* priorityBuild        */ 0,
		/* priorityTarget       */ 100,
		/* availableHouse       */ FLAG_HOUSE_ALL,
		},
		/* enterFilter          */ FLAG_UNIT_NONE,
		/* creditsStorage       */ 0,
		/* powerUsage           */ 40,
		/* layout               */ STRUCTURE_LAYOUT_2x2,
		/* iconGroup            */ ICM_ICONGROUP_IX_RESEARCH,
		{ /* animationIndex */
		/* [0]                  */ 20,
		/* [1]                  */ 20,
		/* [2]                  */ 20
		},
		{ /* buildableUnits */
		/* [0]                  */ UNIT_INVALID,
		/* [1]                  */ UNIT_INVALID,
		/* [2]                  */ UNIT_INVALID,
		/* [3]                  */ UNIT_INVALID,
		/* [4]                  */ UNIT_INVALID,
		/* [5]                  */ UNIT_INVALID,
		/* [6]                  */ UNIT_INVALID,
		/* [7]                  */ UNIT_INVALID,
		},
		{ /* upgradeCampaign */
		/* [0]                  */ { 0, 0, 0, 0, 0, 0 },
		/* [1]                  */ { 0, 0, 0, 0, 0, 0 },
		/* [2]                  */ { 0, 0, 0, 0, 0, 0 },
		},
		/* shortcut             */ SCANCODE_N
	},

	{ /* 7 */
		{ /* objectInfo */
		/* stringID_abbrev      */ STR_WOR,
		/* name                 */ "WOR",
		/* stringID_full        */ STR_WOR_TROOPER_FACILITY,
		/* wsa                  */ "wor.wsa",
		{ /* flags */
		/* hasShadow            */ false,
		/* factory              */ true,
		/* notOnConcrete        */ false,
		/* busyStateIsIncoming  */ false,
		/* blurTile             */ false,
		/* hasTurret            */ false,
		/* conquerable          */ false,
		/* canBePickedUp        */ false,
		/* noMessageOnDeath     */ false,
		/* tabSelectable        */ false,
		/* scriptNoSlowdown     */ true,
		/* targetAir            */ false,
		/* priority             */ false
		},
		/* spawnChance          */ 128,
		/* hitpoints            */ 400,
		/* fogUncoverRadius     */ 3,
		/* spriteID             */ SHAPE_WOR_TROOPER,
		/* buildCredits         */ 400,
		/* buildTime            */ 104,
		/* availableCampaign    */ { 2, 5, 5, 5, 5, 5 }, /* H trait: WOR three levels earlier. */
		/* structuresRequired   */ FLAG_STRUCTURE_OUTPOST | FLAG_STRUCTURE_BARRACKS | FLAG_STRUCTURE_WINDTRAP,
		/* sortPriority         */ 20,
		/* upgradeLevelRequired */ { 0, 0, 0, 0, 0, 0 },
		/* actionsPlayer        */ { ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK },
		/* available            */ 0,
		/* hintStringID         */ STR_HINT_WOR,
		/* priorityBuild        */ 0,
		/* priorityTarget       */ 175,
		/* availableHouse       */ FLAG_HOUSE_MERCENARY | FLAG_HOUSE_SARDAUKAR | FLAG_HOUSE_FREMEN | FLAG_HOUSE_ORDOS | FLAG_HOUSE_HARKONNEN,
		},
		/* enterFilter          */ FLAG_UNIT_NONE,
		/* creditsStorage       */ 0,
		/* powerUsage           */ 20,
		/* layout               */ STRUCTURE_LAYOUT_2x2,
		/* iconGroup            */ ICM_ICONGROUP_WOR_TROOPER_FACILITY,
		{ /* animationIndex */
		/* [0]                  */ 21,
		/* [1]                  */ 21,
		/* [2]                  */ 21
		},
		{ /* buildableUnits */
		/* [0]                  */ UNIT_TROOPER,
		/* [1]                  */ UNIT_TROOPERS,
		/* [2]                  */ UNIT_INVALID,
		/* [3]                  */ UNIT_INVALID,
		/* [4]                  */ UNIT_INVALID,
		/* [5]                  */ UNIT_INVALID,
		/* [6]                  */ UNIT_INVALID,
		/* [7]                  */ UNIT_INVALID,
		},
		{ /* upgradeCampaign */
		/* [0]                  */ { 4, 6, 6, 6, 6, 6 }, /* H trait: trooper squads two levels earlier. */
		/* [1]                  */ { 0, 0, 0, 0, 0, 0 },
		/* [2]                  */ { 0, 0, 0, 0, 0, 0 },
		},
		/* shortcut             */ SCANCODE_B
	},

	{ /* 8 */
		{ /* objectInfo */
		/* stringID_abbrev      */ STR_CONST_YARD,
		/* name                 */ "Const Yard",
		/* stringID_full        */ STR_CONSTRUCTION_YARD,
		/* wsa                  */ "construc.wsa",
		{ /* flags */
		/* hasShadow            */ false,
		/* factory              */ true,
		/* notOnConcrete        */ true,
		/* busyStateIsIncoming  */ false,
		/* blurTile             */ false,
		/* hasTurret            */ false,
		/* conquerable          */ true,
		/* canBePickedUp        */ false,
		/* noMessageOnDeath     */ false,
		/* tabSelectable        */ false,
		/* scriptNoSlowdown     */ true,
		/* targetAir            */ false,
		/* priority             */ false
		},
		/* spawnChance          */ 64,
		/* hitpoints            */ 400,
		/* fogUncoverRadius     */ 3,
		/* spriteID             */ SHAPE_CONSTRUCTION_YARD,
		/* buildCredits         */ 400,
		/* buildTime            */ 80,
		/* availableCampaign    */ { 99, 99, 99, 99, 99, 99 },
		/* structuresRequired   */ FLAG_STRUCTURE_NEVER,
		/* sortPriority         */ 0,
		/* upgradeLevelRequired */ { 0, 0, 0, 0, 0, 0 },
		/* actionsPlayer        */ { ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK },
		/* available            */ 0,
		/* hintStringID         */ STR_HINT_CONSTRUCTION_FACILITY,
		/* priorityBuild        */ 0,
		/* priorityTarget       */ 300,
		/* availableHouse       */ FLAG_HOUSE_ALL,
		},
		/* enterFilter          */ FLAG_UNIT_NONE,
		/* creditsStorage       */ 0,
		/* powerUsage           */ 0,
		/* layout               */ STRUCTURE_LAYOUT_2x2,
		/* iconGroup            */ ICM_ICONGROUP_CONSTRUCTION_YARD,
		{ /* animationIndex */
		/* [0]                  */ 22,
		/* [1]                  */ 22,
		/* [2]                  */ 22
		},
		{ /* buildableUnits */
		/* [0]                  */ UNIT_INVALID,
		/* [1]                  */ UNIT_INVALID,
		/* [2]                  */ UNIT_INVALID,
		/* [3]                  */ UNIT_INVALID,
		/* [4]                  */ UNIT_INVALID,
		/* [5]                  */ UNIT_INVALID,
		/* [6]                  */ UNIT_INVALID,
		/* [7]                  */ UNIT_INVALID,
		},
		{ /* upgradeCampaign */
		/* [0]                  */ { 4, 4, 4, 4, 4, 4 },
		/* [1]                  */ { 6, 6, 6, 6, 6, 6 },
		/* [2]                  */ { 0, 0, 0, 0, 0, 0 },
		},
		/* shortcut             */ SCANCODE_C
	},

	{ /* 9 */
		{ /* objectInfo */
		/* stringID_abbrev      */ STR_WINDTRAP,
		/* name                 */ "Windtrap",
		/* stringID_full        */ STR_WINDTRAP_POWER_CENTER,
		/* wsa                  */ "windtrap.wsa",
		{ /* flags */
		/* hasShadow            */ false,
		/* factory              */ false,
		/* notOnConcrete        */ false,
		/* busyStateIsIncoming  */ false,
		/* blurTile             */ false,
		/* hasTurret            */ false,
		/* conquerable          */ true,
		/* canBePickedUp        */ false,
		/* noMessageOnDeath     */ false,
		/* tabSelectable        */ false,
		/* scriptNoSlowdown     */ true,
		/* targetAir            */ false,
		/* priority             */ false
		},
		/* spawnChance          */ 64,
		/* hitpoints            */ 200,
		/* fogUncoverRadius     */ 2,
		/* spriteID             */ SHAPE_WINDTRAP,
		/* buildCredits         */ 300,
		/* buildTime            */ 48,
		/* availableCampaign    */ { 1, 1, 1, 1, 1, 1 },
		/* structuresRequired   */ FLAG_STRUCTURE_NONE,
		/* sortPriority         */ 6,
		/* upgradeLevelRequired */ { 0, 0, 0, 0, 0, 0 },
		/* actionsPlayer        */ { ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK },
		/* available            */ 0,
		/* hintStringID         */ STR_HINT_WINDTRAP,
		/* priorityBuild        */ 0,
		/* priorityTarget       */ 300,
		/* availableHouse       */ FLAG_HOUSE_ALL,
		},
		/* enterFilter          */ FLAG_UNIT_NONE,
		/* creditsStorage       */ 0,
		/* powerUsage           */ -100,
		/* layout               */ STRUCTURE_LAYOUT_2x2,
		/* iconGroup            */ ICM_ICONGROUP_WINDTRAP_POWER,
		{ /* animationIndex */
		/* [0]                  */ 26,
		/* [1]                  */ 26,
		/* [2]                  */ 26
		},
		{ /* buildableUnits */
		/* [0]                  */ UNIT_INVALID,
		/* [1]                  */ UNIT_INVALID,
		/* [2]                  */ UNIT_INVALID,
		/* [3]                  */ UNIT_INVALID,
		/* [4]                  */ UNIT_INVALID,
		/* [5]                  */ UNIT_INVALID,
		/* [6]                  */ UNIT_INVALID,
		/* [7]                  */ UNIT_INVALID,
		},
		{ /* upgradeCampaign */
		/* [0]                  */ { 0, 0, 0, 0, 0, 0 },
		/* [1]                  */ { 0, 0, 0, 0, 0, 0 },
		/* [2]                  */ { 0, 0, 0, 0, 0, 0 },
		},
		/* shortcut             */ SCANCODE_Q
	},

	{ /* 10 */
		{ /* objectInfo */
		/* stringID_abbrev      */ STR_BARRACKS,
		/* name                 */ "Barracks",
		/* stringID_full        */ STR_INFANTRY_BARRACKS,
		/* wsa                  */ "barrac.wsa",
		{ /* flags */
		/* hasShadow            */ false,
		/* factory              */ true,
		/* notOnConcrete        */ false,
		/* busyStateIsIncoming  */ false,
		/* blurTile             */ false,
		/* hasTurret            */ false,
		/* conquerable          */ false,
		/* canBePickedUp        */ false,
		/* noMessageOnDeath     */ false,
		/* tabSelectable        */ false,
		/* scriptNoSlowdown     */ true,
		/* targetAir            */ false,
		/* priority             */ false
		},
		/* spawnChance          */ 128,
		/* hitpoints            */ 300,
		/* fogUncoverRadius     */ 2,
		/* spriteID             */ SHAPE_BARRACKS,
		/* buildCredits         */ 300,
		/* buildTime            */ 72,
		/* availableCampaign    */ { 2, 2, 2, 2, 2, 2 },
		/* structuresRequired   */ FLAG_STRUCTURE_OUTPOST | FLAG_STRUCTURE_WINDTRAP,
		/* sortPriority         */ 18,
		/* upgradeLevelRequired */ { 0, 0, 0, 0, 0, 0 },
		/* actionsPlayer        */ { ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK },
		/* available            */ 0,
		/* hintStringID         */ STR_HINT_BARRACKS,
		/* priorityBuild        */ 0,
		/* priorityTarget       */ 100,
		/* availableHouse       */ FLAG_HOUSE_MERCENARY | FLAG_HOUSE_SARDAUKAR | FLAG_HOUSE_FREMEN | FLAG_HOUSE_ORDOS | FLAG_HOUSE_ATREIDES,
		},
		/* enterFilter          */ FLAG_UNIT_NONE,
		/* creditsStorage       */ 0,
		/* powerUsage           */ 10,
		/* layout               */ STRUCTURE_LAYOUT_2x2,
		/* iconGroup            */ ICM_ICONGROUP_INFANTRY_BARRACKS,
		{ /* animationIndex */
		/* [0]                  */ 28,
		/* [1]                  */ 28,
		/* [2]                  */ 28
		},
		{ /* buildableUnits */
		/* [0]                  */ UNIT_SOLDIER,
		/* [1]                  */ UNIT_INFANTRY,
		/* [2]                  */ UNIT_INVALID,
		/* [3]                  */ UNIT_INVALID,
		/* [4]                  */ UNIT_INVALID,
		/* [5]                  */ UNIT_INVALID,
		/* [6]                  */ UNIT_INVALID,
		/* [7]                  */ UNIT_INVALID,
		},
		{ /* upgradeCampaign */
		/* [0]                  */ { 2, 2, 2, 2, 2, 2 },
		/* [1]                  */ { 0, 0, 0, 0, 0, 0 },
		/* [2]                  */ { 0, 0, 0, 0, 0, 0 },
		},
		/* shortcut             */ SCANCODE_B
	},

	{ /* 11 */
		{ /* objectInfo */
		/* stringID_abbrev      */ STR_STARPORT,
		/* name                 */ "Starport",
		/* stringID_full        */ STR_STARPORT_FACILITY,
		/* wsa                  */ "starport.wsa",
		{ /* flags */
		/* hasShadow            */ false,
		/* factory              */ true,
		/* notOnConcrete        */ false,
		/* busyStateIsIncoming  */ true,
		/* blurTile             */ false,
		/* hasTurret            */ false,
		/* conquerable          */ true,
		/* canBePickedUp        */ false,
		/* noMessageOnDeath     */ false,
		/* tabSelectable        */ false,
		/* scriptNoSlowdown     */ true,
		/* targetAir            */ false,
		/* priority             */ false
		},
		/* spawnChance          */ 128,
		/* hitpoints            */ 500,
		/* fogUncoverRadius     */ 6,
		/* spriteID             */ SHAPE_STARPORT,
		/* buildCredits         */ 500,
		/* buildTime            */ 120,
		/* availableCampaign    */ { 6, 6, 6, 6, 6, 6 },
		/* structuresRequired   */ FLAG_STRUCTURE_REFINERY | FLAG_STRUCTURE_WINDTRAP,
		/* sortPriority         */ 32,
		/* upgradeLevelRequired */ { 0, 0, 0, 0, 0, 0 },
		/* actionsPlayer        */ { ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK },
		/* available            */ 0,
		/* hintStringID         */ STR_HINT_STARPORT,
		/* priorityBuild        */ 0,
		/* priorityTarget       */ 250,
		/* availableHouse       */ FLAG_HOUSE_ALL,
		},
		/* enterFilter          */ FLAG_UNIT_NONE,
		/* creditsStorage       */ 0,
		/* powerUsage           */ 50,
		/* layout               */ STRUCTURE_LAYOUT_3x3,
		/* iconGroup            */ ICM_ICONGROUP_STARPORT_FACILITY,
		{ /* animationIndex */
		/* [0]                  */ 5,
		/* [1]                  */ 6,
		/* [2]                  */ 7
		},
		{ /* buildableUnits */
		/* [0]                  */ UNIT_INVALID,
		/* [1]                  */ UNIT_INVALID,
		/* [2]                  */ UNIT_INVALID,
		/* [3]                  */ UNIT_INVALID,
		/* [4]                  */ UNIT_INVALID,
		/* [5]                  */ UNIT_INVALID,
		/* [6]                  */ UNIT_INVALID,
		/* [7]                  */ UNIT_INVALID,
		},
		{ /* upgradeCampaign */
		/* [0]                  */ { 0, 0, 0, 0, 0, 0 },
		/* [1]                  */ { 0, 0, 0, 0, 0, 0 },
		/* [2]                  */ { 0, 0, 0, 0, 0, 0 },
		},
		/* shortcut             */ SCANCODE_S
	},

	{ /* 12 */
		{ /* objectInfo */
		/* stringID_abbrev      */ STR_REFINERY,
		/* name                 */ "Refinery",
		/* stringID_full        */ STR_SPICE_REFINERY,
		/* wsa                  */ "refinery.wsa",
		{ /* flags */
		/* hasShadow            */ false,
		/* factory              */ false,
		/* notOnConcrete        */ false,
		/* busyStateIsIncoming  */ true,
		/* blurTile             */ false,
		/* hasTurret            */ false,
		/* conquerable          */ true,
		/* canBePickedUp        */ false,
		/* noMessageOnDeath     */ false,
		/* tabSelectable        */ false,
		/* scriptNoSlowdown     */ true,
		/* targetAir            */ false,
		/* priority             */ false
		},
		/* spawnChance          */ 128,
		/* hitpoints            */ 450,
		/* fogUncoverRadius     */ 4,
		/* spriteID             */ SHAPE_REFINERY,
		/* buildCredits         */ 400,
		/* buildTime            */ 80,
		/* availableCampaign    */ { 1, 1, 1, 1, 1, 1 },
		/* structuresRequired   */ FLAG_STRUCTURE_WINDTRAP,
		/* sortPriority         */ 8,
		/* upgradeLevelRequired */ { 0, 0, 0, 0, 0, 0 },
		/* actionsPlayer        */ { ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK },
		/* available            */ 0,
		/* hintStringID         */ STR_HINT_SPICE_REFINERY,
		/* priorityBuild        */ 0,
		/* priorityTarget       */ 300,
		/* availableHouse       */ FLAG_HOUSE_ALL,
		},
		/* enterFilter          */ FLAG_UNIT_HARVESTER,
		/* creditsStorage       */ 1005,
		/* powerUsage           */ 30,
		/* layout               */ STRUCTURE_LAYOUT_3x2,
		/* iconGroup            */ ICM_ICONGROUP_SPICE_REFINERY,
		{ /* animationIndex */
		/* [0]                  */ 17,
		/* [1]                  */ 18,
		/* [2]                  */ 19
		},
		{ /* buildableUnits */
		/* [0]                  */ UNIT_INVALID,
		/* [1]                  */ UNIT_INVALID,
		/* [2]                  */ UNIT_INVALID,
		/* [3]                  */ UNIT_INVALID,
		/* [4]                  */ UNIT_INVALID,
		/* [5]                  */ UNIT_INVALID,
		/* [6]                  */ UNIT_INVALID,
		/* [7]                  */ UNIT_INVALID,
		},
		{ /* upgradeCampaign */
		/* [0]                  */ { 0, 0, 0, 0, 0, 0 },
		/* [1]                  */ { 0, 0, 0, 0, 0, 0 },
		/* [2]                  */ { 0, 0, 0, 0, 0, 0 },
		},
		/* shortcut             */ SCANCODE_E
	},

	{ /* 13 */
		{ /* objectInfo */
		/* stringID_abbrev      */ STR_REPAIR2,
		/* name                 */ "Repair",
		/* stringID_full        */ STR_REPAIR_FACILITY,
		/* wsa                  */ "repair.wsa",
		{ /* flags */
		/* hasShadow            */ false,
		/* factory              */ false,
		/* notOnConcrete        */ false,
		/* busyStateIsIncoming  */ false,
		/* blurTile             */ false,
		/* hasTurret            */ false,
		/* conquerable          */ true,
		/* canBePickedUp        */ false,
		/* noMessageOnDeath     */ false,
		/* tabSelectable        */ false,
		/* scriptNoSlowdown     */ true,
		/* targetAir            */ false,
		/* priority             */ false
		},
		/* spawnChance          */ 128,
		/* hitpoints            */ 200,
		/* fogUncoverRadius     */ 3,
		/* spriteID             */ SHAPE_REPAIR,
		/* buildCredits         */ 700,
		/* buildTime            */ 80,
		/* availableCampaign    */ { 5, 5, 5, 5, 5, 5 },
		/* structuresRequired   */ FLAG_STRUCTURE_OUTPOST | FLAG_STRUCTURE_WINDTRAP | FLAG_STRUCTURE_LIGHT_VEHICLE,
		/* sortPriority         */ 24,
		/* upgradeLevelRequired */ { 0, 0, 0, 0, 0, 0 },
		/* actionsPlayer        */ { ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK },
		/* available            */ 0,
		/* hintStringID         */ STR_HINT_REPAIR_FACILITY,
		/* priorityBuild        */ 0,
		/* priorityTarget       */ 600,
		/* availableHouse       */ FLAG_HOUSE_ALL,
		},
		/* enterFilter          */ FLAG_UNIT_HARVESTER | FLAG_UNIT_QUAD | FLAG_UNIT_RAIDER_TRIKE | FLAG_UNIT_TRIKE | FLAG_UNIT_SONIC_TANK | FLAG_UNIT_DEVASTATOR | FLAG_UNIT_SIEGE_TANK | FLAG_UNIT_TANK | FLAG_UNIT_DEVIATOR | FLAG_UNIT_LAUNCHER,
		/* creditsStorage       */ 0,
		/* powerUsage           */ 20,
		/* layout               */ STRUCTURE_LAYOUT_3x2,
		/* iconGroup            */ ICM_ICONGROUP_VEHICLE_REPAIR_CENTRE,
		{ /* animationIndex */
		/* [0]                  */ 23,
		/* [1]                  */ 24,
		/* [2]                  */ 25
		},
		{ /* buildableUnits */
		/* [0]                  */ UNIT_INVALID,
		/* [1]                  */ UNIT_INVALID,
		/* [2]                  */ UNIT_INVALID,
		/* [3]                  */ UNIT_INVALID,
		/* [4]                  */ UNIT_INVALID,
		/* [5]                  */ UNIT_INVALID,
		/* [6]                  */ UNIT_INVALID,
		/* [7]                  */ UNIT_INVALID,
		},
		{ /* upgradeCampaign */
		/* [0]                  */ { 0, 0, 0, 0, 0, 0 },
		/* [1]                  */ { 0, 0, 0, 0, 0, 0 },
		/* [2]                  */ { 0, 0, 0, 0, 0, 0 },
		},
		/* shortcut             */ SCANCODE_G
	},

	{ /* 14 */
		{ /* objectInfo */
		/* stringID_abbrev      */ STR_WALL,
		/* name                 */ "Wall",
		/* stringID_full        */ STR_BASE_DEFENSE_WALL,
		/* wsa                  */ "wall.wsa",
		{ /* flags */
		/* hasShadow            */ false,
		/* factory              */ false,
		/* notOnConcrete        */ false,
		/* busyStateIsIncoming  */ false,
		/* blurTile             */ false,
		/* hasTurret            */ false,
		/* conquerable          */ false,
		/* canBePickedUp        */ false,
		/* noMessageOnDeath     */ false,
		/* tabSelectable        */ false,
		/* scriptNoSlowdown     */ true,
		/* targetAir            */ false,
		/* priority             */ false
		},
		/* spawnChance          */ 0,
		/* hitpoints            */ 50,
		/* fogUncoverRadius     */ 1,
		/* spriteID             */ SHAPE_WALL,
		/* buildCredits         */ 50,
		/* buildTime            */ 40,
		/* availableCampaign    */ { 4, 4, 4, 4, 4, 4 },
		/* structuresRequired   */ FLAG_STRUCTURE_OUTPOST | FLAG_STRUCTURE_WINDTRAP,
		/* sortPriority         */ 16,
		/* upgradeLevelRequired */ { 0, 0, 0, 0, 0, 0 },
		/* actionsPlayer        */ { ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK },
		/* available            */ 0,
		/* hintStringID         */ STR_HINT_WALL,
		/* priorityBuild        */ 0,
		/* priorityTarget       */ 30,
		/* availableHouse       */ FLAG_HOUSE_ALL,
		},
		/* enterFilter          */ FLAG_UNIT_NONE,
		/* creditsStorage       */ 0,
		/* powerUsage           */ 0,
		/* layout               */ STRUCTURE_LAYOUT_1x1,
		/* iconGroup            */ ICM_ICONGROUP_WALLS,
		{ /* animationIndex */
		/* [0]                  */ 0xFF,
		/* [1]                  */ 0xFF,
		/* [2]                  */ 0xFF
		},
		{ /* buildableUnits */
		/* [0]                  */ UNIT_INVALID,
		/* [1]                  */ UNIT_INVALID,
		/* [2]                  */ UNIT_INVALID,
		/* [3]                  */ UNIT_INVALID,
		/* [4]                  */ UNIT_INVALID,
		/* [5]                  */ UNIT_INVALID,
		/* [6]                  */ UNIT_INVALID,
		/* [7]                  */ UNIT_INVALID,
		},
		{ /* upgradeCampaign */
		/* [0]                  */ { 0, 0, 0, 0, 0, 0 },
		/* [1]                  */ { 0, 0, 0, 0, 0, 0 },
		/* [2]                  */ { 0, 0, 0, 0, 0, 0 },
		},
		/* shortcut             */ SCANCODE_W
	},

	{ /* 15 */
		{ /* objectInfo */
		/* stringID_abbrev      */ STR_TURRET,
		/* name                 */ "Turret",
		/* stringID_full        */ STR_CANNON_TURRET,
		/* wsa                  */ "turret.wsa",
		{ /* flags */
		/* hasShadow            */ false,
		/* factory              */ false,
		/* notOnConcrete        */ false,
		/* busyStateIsIncoming  */ false,
		/* blurTile             */ false,
		/* hasTurret            */ false,
		/* conquerable          */ true,
		/* canBePickedUp        */ false,
		/* noMessageOnDeath     */ false,
		/* tabSelectable        */ false,
		/* scriptNoSlowdown     */ true,
		/* targetAir            */ false,
		/* priority             */ false
		},
		/* spawnChance          */ 64,
		/* hitpoints            */ 200,
		/* fogUncoverRadius     */ 2,
		/* spriteID             */ SHAPE_TURRET,
		/* buildCredits         */ 125,
		/* buildTime            */ 64,
		/* availableCampaign    */ { 5, 5, 5, 5, 5, 5 },
		/* structuresRequired   */ FLAG_STRUCTURE_OUTPOST | FLAG_STRUCTURE_WINDTRAP,
		/* sortPriority         */ 22,
		/* upgradeLevelRequired */ { 0, 0, 0, 0, 0, 0 },
		/* actionsPlayer        */ { ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK },
		/* available            */ 0,
		/* hintStringID         */ STR_HINT_GUN_TURRET,
		/* priorityBuild        */ 75,
		/* priorityTarget       */ 150,
		/* availableHouse       */ FLAG_HOUSE_ALL,
		},
		/* enterFilter          */ FLAG_UNIT_NONE,
		/* creditsStorage       */ 0,
		/* powerUsage           */ 10,
		/* layout               */ STRUCTURE_LAYOUT_1x1,
		/* iconGroup            */ ICM_ICONGROUP_BASE_DEFENSE_TURRET,
		{ /* animationIndex */
		/* [0]                  */ 0xFF,
		/* [1]                  */ 0xFF,
		/* [2]                  */ 0xFF
		},
		{ /* buildableUnits */
		/* [0]                  */ UNIT_INVALID,
		/* [1]                  */ UNIT_INVALID,
		/* [2]                  */ UNIT_INVALID,
		/* [3]                  */ UNIT_INVALID,
		/* [4]                  */ UNIT_INVALID,
		/* [5]                  */ UNIT_INVALID,
		/* [6]                  */ UNIT_INVALID,
		/* [7]                  */ UNIT_INVALID,
		},
		{ /* upgradeCampaign */
		/* [0]                  */ { 0, 0, 0, 0, 0, 0 },
		/* [1]                  */ { 0, 0, 0, 0, 0, 0 },
		/* [2]                  */ { 0, 0, 0, 0, 0, 0 },
		},
		/* shortcut             */ SCANCODE_Y
	},

	{ /* 16 */
		{ /* objectInfo */
		/* stringID_abbrev      */ STR_RTURRET,
		/* name                 */ "R-Turret",
		/* stringID_full        */ STR_ROCKET_TURRET,
		/* wsa                  */ "rturret.wsa",
		{ /* flags */
		/* hasShadow            */ false,
		/* factory              */ false,
		/* notOnConcrete        */ false,
		/* busyStateIsIncoming  */ false,
		/* blurTile             */ false,
		/* hasTurret            */ false,
		/* conquerable          */ true,
		/* canBePickedUp        */ false,
		/* noMessageOnDeath     */ false,
		/* tabSelectable        */ false,
		/* scriptNoSlowdown     */ true,
		/* targetAir            */ false,
		/* priority             */ false
		},
		/* spawnChance          */ 64,
		/* hitpoints            */ 200,
		/* fogUncoverRadius     */ 5,
		/* spriteID             */ SHAPE_ROCKET_TURRET,
		/* buildCredits         */ 250,
		/* buildTime            */ 96,
		/* availableCampaign    */ { 0, 0, 0, 0, 0, 0 },
		/* structuresRequired   */ FLAG_STRUCTURE_OUTPOST | FLAG_STRUCTURE_WINDTRAP,
		/* sortPriority         */ 26,
		/* upgradeLevelRequired */ { 2, 2, 2, 2, 2, 2 },
		/* actionsPlayer        */ { ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK },
		/* available            */ 0,
		/* hintStringID         */ STR_HINT_ROCKET_TURRET,
		/* priorityBuild        */ 100,
		/* priorityTarget       */ 75,
		/* availableHouse       */ FLAG_HOUSE_ALL,
		},
		/* enterFilter          */ FLAG_UNIT_NONE,
		/* creditsStorage       */ 0,
		/* powerUsage           */ 25,
		/* layout               */ STRUCTURE_LAYOUT_1x1,
		/* iconGroup            */ ICM_ICONGROUP_BASE_ROCKET_TURRET,
		{ /* animationIndex */
		/* [0]                  */ 0xFF,
		/* [1]                  */ 0xFF,
		/* [2]                  */ 0xFF
		},
		{ /* buildableUnits */
		/* [0]                  */ UNIT_INVALID,
		/* [1]                  */ UNIT_INVALID,
		/* [2]                  */ UNIT_INVALID,
		/* [3]                  */ UNIT_INVALID,
		/* [4]                  */ UNIT_INVALID,
		/* [5]                  */ UNIT_INVALID,
		/* [6]                  */ UNIT_INVALID,
		/* [7]                  */ UNIT_INVALID,
		},
		{ /* upgradeCampaign */
		/* [0]                  */ { 0, 0, 0, 0, 0, 0 },
		/* [1]                  */ { 0, 0, 0, 0, 0, 0 },
		/* [2]                  */ { 0, 0, 0, 0, 0, 0 },
		},
		/* shortcut             */ SCANCODE_T
	},

	{ /* 17 */
		{ /* objectInfo */
		/* stringID_abbrev      */ STR_SPICE_SILO,
		/* name                 */ "Spice Silo",
		/* stringID_full        */ STR_SPICE_STORAGE_SILO,
		/* wsa                  */ "storage.wsa",
		{ /* flags */
		/* hasShadow            */ false,
		/* factory              */ false,
		/* notOnConcrete        */ false,
		/* busyStateIsIncoming  */ false,
		/* blurTile             */ false,
		/* hasTurret            */ false,
		/* conquerable          */ true,
		/* canBePickedUp        */ false,
		/* noMessageOnDeath     */ false,
		/* tabSelectable        */ false,
		/* scriptNoSlowdown     */ true,
		/* targetAir            */ false,
		/* priority             */ false
		},
		/* spawnChance          */ 0,
		/* hitpoints            */ 150,
		/* fogUncoverRadius     */ 2,
		/* spriteID             */ SHAPE_SILO,
		/* buildCredits         */ 150,
		/* buildTime            */ 48,
		/* availableCampaign    */ { 2, 2, 2, 2, 2, 2 },
		/* structuresRequired   */ FLAG_STRUCTURE_REFINERY | FLAG_STRUCTURE_WINDTRAP,
		/* sortPriority         */ 12,
		/* upgradeLevelRequired */ { 0, 0, 0, 0, 0, 0 },
		/* actionsPlayer        */ { ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK },
		/* available            */ 0,
		/* hintStringID         */ STR_HINT_SPICE_SILO,
		/* priorityBuild        */ 0,
		/* priorityTarget       */ 150,
		/* availableHouse       */ FLAG_HOUSE_ALL,
		},
		/* enterFilter          */ FLAG_UNIT_NONE,
		/* creditsStorage       */ 1000,
		/* powerUsage           */ 5,
		/* layout               */ STRUCTURE_LAYOUT_2x2,
		/* iconGroup            */ ICM_ICONGROUP_SPICE_STORAGE_SILO,
		{ /* animationIndex */
		/* [0]                  */ 27,
		/* [1]                  */ 27,
		/* [2]                  */ 27
		},
		{ /* buildableUnits */
		/* [0]                  */ UNIT_INVALID,
		/* [1]                  */ UNIT_INVALID,
		/* [2]                  */ UNIT_INVALID,
		/* [3]                  */ UNIT_INVALID,
		/* [4]                  */ UNIT_INVALID,
		/* [5]                  */ UNIT_INVALID,
		/* [6]                  */ UNIT_INVALID,
		/* [7]                  */ UNIT_INVALID,
		},
		{ /* upgradeCampaign */
		/* [0]                  */ { 0, 0, 0, 0, 0, 0 },
		/* [1]                  */ { 0, 0, 0, 0, 0, 0 },
		/* [2]                  */ { 0, 0, 0, 0, 0, 0 },
		},
		/* shortcut             */ SCANCODE_I
	},

	{ /* 18 */
		{ /* objectInfo */
		/* stringID_abbrev      */ STR_OUTPOST,
		/* name                 */ "Outpost",
		/* stringID_full        */ STR_RADAR_OUTPOST,
		/* wsa                  */ "headqrts.wsa",
		{ /* flags */
		/* hasShadow            */ false,
		/* factory              */ false,
		/* notOnConcrete        */ false,
		/* busyStateIsIncoming  */ false,
		/* blurTile             */ false,
		/* hasTurret            */ false,
		/* conquerable          */ false,
		/* canBePickedUp        */ false,
		/* noMessageOnDeath     */ false,
		/* tabSelectable        */ false,
		/* scriptNoSlowdown     */ true,
		/* targetAir            */ false,
		/* priority             */ false
		},
		/* spawnChance          */ 128,
		/* hitpoints            */ 500,
		/* fogUncoverRadius     */ 10,
		/* spriteID             */ SHAPE_OUTPOST,
		/* buildCredits         */ 400,
		/* buildTime            */ 80,
		/* availableCampaign    */ { 2, 2, 2, 2, 2, 2 },
		/* structuresRequired   */ FLAG_STRUCTURE_WINDTRAP,
		/* sortPriority         */ 10,
		/* upgradeLevelRequired */ { 0, 0, 0, 0, 0, 0 },
		/* actionsPlayer        */ { ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK, ACTION_ATTACK },
		/* available            */ 0,
		/* hintStringID         */ STR_HINT_OUTPOST,
		/* priorityBuild        */ 0,
		/* priorityTarget       */ 275,
		/* availableHouse       */ FLAG_HOUSE_ALL,
		},
		/* enterFilter          */ FLAG_UNIT_NONE,
		/* creditsStorage       */ 0,
		/* powerUsage           */ 30,
		/* layout               */ STRUCTURE_LAYOUT_2x2,
		/* iconGroup            */ ICM_ICONGROUP_RADAR_OUTPOST,
		{ /* animationIndex */
		/* [0]                  */ 3,
		/* [1]                  */ 3,
		/* [2]                  */ 3
		},
		{ /* buildableUnits */
		/* [0]                  */ UNIT_INVALID,
		/* [1]                  */ UNIT_INVALID,
		/* [2]                  */ UNIT_INVALID,
		/* [3]                  */ UNIT_INVALID,
		/* [4]                  */ UNIT_INVALID,
		/* [5]                  */ UNIT_INVALID,
		/* [6]                  */ UNIT_INVALID,
		/* [7]                  */ UNIT_INVALID,
		},
		{ /* upgradeCampaign */
		/* [0]                  */ { 0, 0, 0, 0, 0, 0 },
		/* [1]                  */ { 0, 0, 0, 0, 0, 0 },
		/* [2]                  */ { 0, 0, 0, 0, 0, 0 },
		},
		/* shortcut             */ SCANCODE_D
	}
};

StructureInfo g_table_structureInfo[STRUCTURE_MAX];

/** Array with position offset per tile in a structure layout. */
const uint16 g_table_structure_layoutTiles[STRUCTURE_LAYOUT_MAX][9] = {
	{0,    0,    0,    0,     0,     0,     0,     0,     0}, /* STRUCTURE_LAYOUT_1x1 */
	{0,    1,    0,    0,     0,     0,     0,     0,     0}, /* STRUCTURE_LAYOUT_2x1 */
	{0, 64+0,    0,    0,     0,     0,     0,     0,     0}, /* STRUCTURE_LAYOUT_1x2 */
	{0,    1, 64+0, 64+1,     0,     0,     0,     0,     0}, /* STRUCTURE_LAYOUT_2x2 */
	{0,    1, 64+0, 64+1, 128+0, 128+1,     0,     0,     0}, /* STRUCTURE_LAYOUT_2x3 */
	{0,    1,    2, 64+0,  64+1,  64+2,     0,     0,     0}, /* STRUCTURE_LAYOUT_3x2 */
	{0,    1,    2, 64+0,  64+1,  64+2, 128+0, 128+1, 128+2}, /* STRUCTURE_LAYOUT_3x3 */
};

/** Array with position offset of edge tiles in a structure layout. */
const uint16 g_table_structure_layoutEdgeTiles[STRUCTURE_LAYOUT_MAX][8] = {
	{0, 0,    0,     0,     0,     0,     0, 0}, /* STRUCTURE_LAYOUT_1x1 */
	{0, 1,    1,     1,     1,     0,     0, 0}, /* STRUCTURE_LAYOUT_2x1 */
	{0, 0,    0,  64+0,  64+0,  64+0,     0, 0}, /* STRUCTURE_LAYOUT_1x2 */
	{0, 1,    1,  64+1,  64+1,  64+0,  64+0, 0}, /* STRUCTURE_LAYOUT_2x2 */
	{0, 1, 64+1, 128+1, 128+1, 128+0,  64+0, 0}, /* STRUCTURE_LAYOUT_2x3 */
	{1, 2,    2,  64+2,  64+1,  64+0,     0, 0}, /* STRUCTURE_LAYOUT_3x2 */
	{1, 2, 64+2, 128+2, 128+1, 128+0,  64+0, 0}, /* STRUCTURE_LAYOUT_3x3 */
};

/** Array with number of tiles in a layout. */
const uint16 g_table_structure_layoutTileCount[STRUCTURE_LAYOUT_MAX] = {
	1, /* STRUCTURE_LAYOUT_1x1 */
	2, /* STRUCTURE_LAYOUT_2x1 */
	2, /* STRUCTURE_LAYOUT_1x2 */
	4, /* STRUCTURE_LAYOUT_2x2 */
	6, /* STRUCTURE_LAYOUT_2x3 */
	6, /* STRUCTURE_LAYOUT_3x2 */
	9, /* STRUCTURE_LAYOUT_3x3 */
};

/** Array with TileDiff of a layout. */
const tile32 g_table_structure_layoutTileDiff[STRUCTURE_LAYOUT_MAX] = {
	{0x0080, 0x0080}, /* STRUCTURE_LAYOUT_1x1 */
	{0x0100, 0x0080}, /* STRUCTURE_LAYOUT_2x1 */
	{0x0080, 0x0100}, /* STRUCTURE_LAYOUT_1x2 */
	{0x0100, 0x0100}, /* STRUCTURE_LAYOUT_2x2 */
	{0x0100, 0x0180}, /* STRUCTURE_LAYOUT_2x3 */
	{0x0280, 0x0100}, /* STRUCTURE_LAYOUT_3x2 */
	{0x0180, 0x0180}, /* STRUCTURE_LAYOUT_3x3 */
};

/** Array with size of a layout. */
const XYSize g_table_structure_layoutSize[STRUCTURE_LAYOUT_MAX] = {
	{1, 1}, /* STRUCTURE_LAYOUT_1x1 */
	{2, 1}, /* STRUCTURE_LAYOUT_2x1 */
	{1, 2}, /* STRUCTURE_LAYOUT_1x2 */
	{2, 2}, /* STRUCTURE_LAYOUT_2x2 */
	{2, 3}, /* STRUCTURE_LAYOUT_2x3 */
	{3, 2}, /* STRUCTURE_LAYOUT_3x2 */
	{3, 3}, /* STRUCTURE_LAYOUT_3x3 */
};

/** Array with position offset per tile around a structure layout. */
const int16 g_table_structure_layoutTilesAround[STRUCTURE_LAYOUT_MAX][16] = {
	{-64, -64+1,     1,  64+1,  64+0,  64-1,    -1, -64-1,     0,     0,     0,     0,     0,     0,  0,     0}, /* STRUCTURE_LAYOUT_1x1 */
	{-64, -64+1, -64+2,     2,  64+2,  64+1,  64+0,  64-1,    -1, -64-1,     0,     0,     0,     0,  0,     0}, /* STRUCTURE_LAYOUT_2x1 */
	{-64, -64+1,     1,  64+1, 128+1, 128+0, 128-1,  64-1,    -1, -64-1,     0,     0,     0,     0,  0,     0}, /* STRUCTURE_LAYOUT_1x2 */
	{-64, -64+1, -64+2,     2,  64+2, 128+2, 128+1, 128+0, 128-1,  64-1,    -1, -64-1,     0,     0,  0,     0}, /* STRUCTURE_LAYOUT_2x2 */
	{-64, -64+1, -64+2,     2,  64+2, 128+2, 192+2, 192+1, 192+0, 192-1, 128-1,  64-1,    -1, -64-1,  0,     0}, /* STRUCTURE_LAYOUT_2x3 */
	{-64, -64+1, -64+2, -64+3,     3,  64+3, 128+3, 128+2, 128+1, 128+0, 128-1,  64-1,    -1, -64-1,  0,     0}, /* STRUCTURE_LAYOUT_3x2 */
	{-64, -64+1, -64+2, -64+3,     3,  64+3, 128+3, 192+3, 192+2, 192+1, 192+0, 192-1, 128-1,  64-1, -1, -64-1}, /* STRUCTURE_LAYOUT_3x3 */
};

