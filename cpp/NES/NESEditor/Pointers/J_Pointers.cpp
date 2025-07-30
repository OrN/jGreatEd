/*
	A FDA Super Mario Bros 2 [J] [public version]
	Copyright (C) 2020 ALXR aka loginsin
	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.
	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "h/NES/NESEditor/CNesPointers.h"

VOID CNesPointers::LoadPointersNES()
{
	m_eptr[eVRAMAddrTableHi].eptr = NES_J_VRAM_NES_TBL_PTR_HI;
	m_eptr[eVRAMAddrTableLo].eptr = NES_J_VRAM_NES_TBL_PTR_LO;

	m_eptr[eStrPeachHurrahMessage].eptr = NES_J_STR_NES_PEACH_HURRAH_MESSAGE;
	m_eptr[eStrPeachThankYouMessage].eptr = NES_J_STR_NES_PEACH_THANKYOU_MESSAGE;
}

VOID CNesPointers::LoadPointersJ()
{
	m_eptr[ eFilesListPtrLo ].eptr = NES_J_FILES_LIST_PTR_LO;
	m_eptr[ eFilesListPtrHi ].eptr = NES_J_FILES_LIST_PTR_HI;

	m_eptr[ eStrTitleCopyright ].eptr = NES_J_STR_TITLE_COPYRIGHT;
	m_eptr[ eStrTitleMarioGame ].eptr = NES_J_STR_TITLE_MARIOGAME;
	m_eptr[ eStrTitleLuigiGame ].eptr = NES_J_STR_TITLE_LUIGIGAME;
	m_eptr[ eStrTitleTop ].eptr = NES_J_STR_TITLE_TOP;
	m_eptr[ eStrTitleTopEnding ].eptr = NES_J_STR_TITLE_TOP_ENDING;

	m_eptr[ eStrUIMario ].eptr = NES_J_STR_UI_MARIO;
	m_eptr[ eStrUILuigi ].eptr = NES_J_STR_UI_LUIGI;
	m_eptr[ eStrUIWorld ].eptr = NES_J_STR_UI_WORLD;
	m_eptr[ eStrUITime ].eptr = NES_J_STR_UI_TIME;

	m_eptr[ eStrLevelWorld ].eptr = NES_J_STR_LEVEL_WORLD;
	m_eptr[ eStrLevelFantasyWorld ].eptr = NES_J_STR_LEVEL_FANTASYWORLD;
	m_eptr[ eStrLevelLetsTry ].eptr = NES_J_STR_LEVEL_LETSTRY;
	m_eptr[ eStrLevelOneGame ].eptr = NES_J_STR_LEVEL_ONEGAME;

	m_eptr[ eStrGameOver ].eptr = NES_J_STR_GAMEOVER;
	m_eptr[ eStrGameOverContinue ].eptr = NES_J_STR_GAMEOVER_CONTINUE;
	m_eptr[ eStrGameOverRetry ].eptr = NES_J_STR_GAMEOVER_RETRY;
	m_eptr[ eStrGameOverSuperPlayer ].eptr = NES_J_STR_GAMEOVER_SUPERPLAYER;
	m_eptr[ eStrGameOverWeHope ].eptr = NES_J_STR_GAMEOVER_WEHOPE;
	m_eptr[ eStrGameOverSeeYou ].eptr = NES_J_STR_GAMEOVER_SEEYOU;
	m_eptr[ eStrGameOverMarioStaff ].eptr = NES_J_STR_GAMEOVER_MARIOSTAFF;

	m_eptr[ eStrPeachPeaceMessage ].eptr = NES_J_STR_PEACH_PEACE_MESSAGE;
	m_eptr[ eStrPeachKingdomMessage ].eptr = NES_J_STR_PEACH_KINGDOM_MESSAGE;
	m_eptr[ eStrPeachHurrahMessage ].eptr = NES_J_STR_PEACH_HURRAH_MESSAGE;
	m_eptr[ eStrPeachOnlyHeroMessage ].eptr = NES_J_STR_PEACH_ONLYHERO_MESSAGE;
	m_eptr[ eStrPeachTripMessage ].eptr = NES_J_STR_PEACH_TRIP_MESSAGE;
	m_eptr[ eStrPeachFriendshipMessage ].eptr = NES_J_STR_PEACH_FRIENDSHIP_MESSAGE;
	m_eptr[ eStrPeach100000PtsMessage ].eptr = NES_J_STR_PEACH_100000PTS_MESSAGE;
	m_eptr[ eStrPeachEachPlayerMessage ].eptr = NES_J_STR_PEACH_EACHPLAYER_MESSAGE;
	m_eptr[ eStrPeachThankYouMessage ].eptr = NES_J_STR_PEACH_THANKYOU_MESSAGE;
	m_eptr[ eStrPeachMarioMessage ].eptr = NES_J_STR_PEACH_MARIO_MESSAGE;
	m_eptr[ eStrPeachLuigiMessage ].eptr = NES_J_STR_PEACH_LUIGI_MESSAGE;

	m_eptr[ eStrToadThankYouMessage ].eptr = NES_J_STR_TOAD_THANKYOU_MESSAGE;
	m_eptr[ eStrToadOurPrincessMessage ].eptr = NES_J_STR_TOAD_OURPRINCESS_MESSAGE;
	m_eptr[ eStrToadAnotherCastleMessage ].eptr = NES_J_STR_TOAD_ANOTHERCASTLE_MESSAGE;

	m_eptr[ eBypassPeachName ].eptr = NES_J_BYPASS_PEACH_NAME;
	m_eptr[ eBypassToadName ].eptr = NES_J_BYPASS_TOAD_NAME;

	m_eptr[ eEnemyPtr ].eptr = NES_J_ENEMY_PTR;
	m_eptr[ eEnemyPtrHi ].eptr = NES_J_ENEMY_PTR_HI;
	m_eptr[ eLevelPtr ].eptr = NES_J_LEVEL_PTR;
	m_eptr[ eLevelPtrHi ].eptr = NES_J_LEVEL_PTR_HI;
	m_eptr[ eEnemyAddrHOffset ].eptr = NES_J_ENEMY_ADDR_H_OFFSET;
	m_eptr[ eLevelAddrHOffset ].eptr = NES_J_LEVEL_ADDR_H_OFFSET;
	m_eptr[ eWorldAreasOffsets ].eptr = NES_J_WORLD_AREAS_OFFSETS;
	m_eptr[ eWorldAreas ].eptr = NES_J_WORLD_AREAS;

	m_eptr[ eTileListBricksRowTileId ].eptr = NES_J_TILE_BRICK_ROW_BLOCK_ID;
	m_eptr[ eTileListBridgeTile1 ].eptr = NES_J_TILE_BRIDGE_TILE1;
	m_eptr[ eTileListBridgeTile2 ].eptr = NES_J_TILE_BRIDGE_TILE2;
	m_eptr[ eTileListBridgeHeight0 ].eptr = NES_J_TILE_BRIDGE_HEIGHT0;
	m_eptr[ eTileListBridgeHeight1 ].eptr = NES_J_TILE_BRIDGE_HEIGHT1;
	m_eptr[ eTileListBridgeHeight2 ].eptr = NES_J_TILE_BRIDGE_HEIGHT2;
	m_eptr[ eTileListWaterTile1 ].eptr = NES_J_TILE_WATER_TILE1;
	m_eptr[ eTileListWaterTile2 ].eptr = NES_J_TILE_WATER_TILE2;
	m_eptr[ eTileListQBlockRow ].eptr = NES_J_TILE_QBLOCK_ROW;
	m_eptr[ eTileListQBlockHeight1 ].eptr = NES_J_TILE_QBLOCK_ROW_HEIGHT1;
	m_eptr[ eTileListQBlockHeight2 ].eptr = NES_J_TILE_QBLOCK_ROW_HEIGHT2;
	m_eptr[ eTileListRope ].eptr = NES_J_TILE_ROPE;
	m_eptr[ eTileListResidualBall ].eptr = NES_J_TILE_RESIDUAL;
	m_eptr[ eTileListStaircase ].eptr = NES_J_TILE_STAIRCASE;
	m_eptr[ eTileListTreeLedgeLeft ].eptr = NES_J_TILE_TREE_LEDGE_LEFT;
	m_eptr[ eTileListTreeLedgeMiddle ].eptr = NES_J_TILE_TREE_LEDGE_MDL;
	m_eptr[ eTileListTreeLedgeRight ].eptr = NES_J_TILE_TREE_LEDGE_RIGHT;
	m_eptr[ eTileListTreeLedgeBottom ].eptr = NES_J_TILE_TREE_LEDGE_BTM;
	m_eptr[ eTileListMushroomLedgeLeft ].eptr = NES_J_TILE_MUSH_LEDGE_LEFT;
	m_eptr[ eTileListMushroomLedgeRight ].eptr = NES_J_TILE_MUSH_LEDGE_RIGHT;
	m_eptr[ eTileListMushroomLedgeMiddle ].eptr = NES_J_TILE_MUSH_LEDGE_MDL;
	m_eptr[ eTileListMushroomLedgeTop ].eptr = NES_J_TILE_MUSH_LEDGE_TOP;
	m_eptr[ eTileListMushroomLedgeBottom ].eptr = NES_J_TILE_MUSH_LEDGE_BTM;
	m_eptr[ eTileListBulletBillTop ].eptr = NES_J_TILE_BULL_BILL_TOP;
	m_eptr[ eTileListBulletBillMiddle ].eptr = NES_J_TILE_BULL_BILL_MDL;
	m_eptr[ eTileListBulletBillBottom ].eptr = NES_J_TILE_BULL_BILL_BTM;
	m_eptr[ eTileListWaterPipeBottom ].eptr = NES_J_TILE_WATER_PIPE_BTM;
	m_eptr[ eTileListWaterPipeTop ].eptr = NES_J_TILE_WATER_PIPE_TOP;
	m_eptr[ eTileListJumpspringTop ].eptr = NES_J_TILE_JUMPSPRING_TOP;
	m_eptr[ eTileListJumpspringBottom ].eptr = NES_J_TILE_JUMPSPRING_BTM;
	m_eptr[ eTileListFlagpoleTop ].eptr = NES_J_TILE_FLAGPOLE_TOP;
	m_eptr[ eTileListFlagpoleRope ].eptr = NES_J_TILE_FLAGPOLE_ROPE;
	m_eptr[ eTileListFlagpoleBottom ].eptr = NES_J_TILE_FLAGPOLE_BOTTOM;
	m_eptr[ eTileListStoneBlock ].eptr = NES_J_TILE_STONE_BLOCK;

	m_eptr[ eBlockSpecialWaterWorldId ].eptr = NES_J_BLOCK_W_WORLD_ID;
	m_eptr[ eBlockSpecialWaterWorld8 ].eptr = NES_J_BLOCK_W_WORLD_8;
	m_eptr[ eBlockCloud ].eptr = NES_J_BLOCK_CLOUD;
	m_eptr[ eBlockDefault ].eptr = NES_J_BLOCK_DEFAULT;

	m_eptr[ eBrickQMetatiles ].eptr = NES_J_BRICK_Q_METATILES;
	m_eptr[ eBricksMetatiles ].eptr = NES_J_BRICKS_METATILES;
	m_eptr[ eSolidMetatiles ].eptr = NES_J_SOLID_METATILES;
	m_eptr[ eCoinsMetatiles ].eptr = NES_J_COINS_METATILES;
	m_eptr[ eVertPipeMetatiles ].eptr = NES_J_PIPE_METATILES;
	m_eptr[ eHoleMetatiles ].eptr = NES_J_HOLE_METATILES;
	m_eptr[ ePulleyRopeMetatiles ].eptr = NES_J_PUL_ROPE_METATILES;
	m_eptr[ eLPipeShaftMetatiles ].eptr = NES_J_LPIPE_SHFT_METATILES;
	m_eptr[ eLPipeTopMetatiles ].eptr = NES_J_LPIPE_TOP_METATILES;
	m_eptr[ eLPipeBottomMetatiles ].eptr = NES_J_LPIPE_BTM_METATILES;

	m_eptr[ eSpecObjY ].eptr = NES_J_SPEC_OBJ_Y;
	m_eptr[ eSpecObjMetatiles ].eptr = NES_J_SPEC_OBJ_METATILES;
	m_eptr[ eCastleMetatiles ].eptr = NES_J_CASTLE_METATILES;

	m_eptr[ eStaircaseY ].eptr = NES_J_STAIRCASE_Y;
	m_eptr[ eStaircaseHeight ].eptr = NES_J_STAIRCASE_HEIGHT;
	m_eptr[ eBgColors ].eptr = NES_J_BG_COLORS;

	m_eptr[ eGFXEnemy ].eptr = NES_J_GFX_ENEMY;
	m_eptr[ eGFXEnemyOffsets ].eptr = NES_J_GFX_ENEMY_OFFSETS;
	m_eptr[ eGFXPowerUp ].eptr = NES_J_GFX_POWERUP;

	m_eptr[ eBgSceneDataOffset ].eptr = NES_J_BG_SCENE_DATA_OFFSET;
	m_eptr[ eBgSceneData ].eptr = NES_J_BG_SCENERY_DATA;
	m_eptr[ eBgSceneMTiles ].eptr = NES_J_BG_SCENERY_MTILES;
	m_eptr[ eFgSceneDataOffset ].eptr = NES_J_FG_SCENE_DATA_OFFSET;
	m_eptr[ eFgSceneData ].eptr = NES_J_FG_SCENERY_DATA;
	m_eptr[ eGroundMTiles ].eptr = NES_J_GROUND_MTILES;
	m_eptr[ eGroundBits ].eptr = NES_J_GROUND_BITS;
	m_eptr[ eBlockBounds ].eptr = NES_J_BLOCK_BOUNDS;

	m_eptr[ eMetatiesPtrHi ].eptr = NES_J_METATILES_PTR_HI;
	m_eptr[ eMetatiesPtrLo ].eptr = NES_J_METATILES_PTR_LO;
	m_eptr[ eVRAMAddrTableHi ].eptr = NES_J_VRAM_TBL_PTR_HI;
	m_eptr[ eVRAMAddrTableLo ].eptr = NES_J_VRAM_TBL_PTR_LO;

	m_eptr[ ePlayerSpriteTable ].eptr = NES_J_PLAYER_SPRITE_TABLE;
	m_eptr[ ePlayerTiles ].eptr = NES_J_PLAYER_SPRITE_TILES;

	m_eptr[ ePlayerEntranceCtrl ].eptr = NES_J_PLAYER_ENTRANCE_CTRL;
	m_eptr[ ePlayerEntranceX ].eptr = NES_J_PLAYER_ENTRANCE_X;
	m_eptr[ ePlayerTimerCtrl ].eptr = NES_J_PLAYER_TIMER_CTRL;
	m_eptr[ eUpSidePipeHeightHi ].eptr = NES_J_UPSIDE_PIPE_HI;
	m_eptr[ eUpSidePipeHeightLo ].eptr = NES_J_UPSIDE_PIPE_LO;

	m_eptr[ eJumpspringAttr ].eptr = NES_J_JUMPSPRING_ATTR;
	m_eptr[ eGJumpspringW0 ].eptr = NES_J_GJUMPSPRING_W0;
	m_eptr[ eGJumpspringW1 ].eptr = NES_J_GJUMPSPRING_W1;
	m_eptr[ eGJumpspringW2 ].eptr = NES_J_GJUMPSPRING_W2;

	m_eptr[ eFindAreaPointerPtr ].eptr = NES_J_FIND_AREA_POINTER_ROUTINE_PTR;
	m_eptr[ eFL05PaddingPtr ].eptr = NES_J_FL05_PADDING4;
	m_eptr[ eLoopAreaDataOffsetPtr ].eptr = NES_J_LOOP_AREA_BACKWARD_OFFSET;
	m_eptr[ eLoopAreaNumberPtr ].eptr = NES_J_LOOP_AREA_NUMBER;
	m_eptr[ eLoopPageNumberPtr ].eptr = NES_J_LOOP_PAGE_NUMBER;
	m_eptr[ eLoopYPtr ].eptr = NES_J_LOOP_Y_DATA;
	m_eptr[ eLoopSlaveDataPtr ].eptr = NES_J_LOOP_SLAVE_DATA;
	m_eptr[ eLoopLdaWorldCodePtr ].eptr = NES_J_LOOP_LDA_WORLD_ID_CODE;
	m_eptr[ eLoopCount ].eptr = NES_J_MAXIMUM_LOOP_COUNT;

	m_eptr[ eWarpControlCode1 ].eptr = NES_J_WARP_ZONE_CONTROL1;
	m_eptr[ eWarpControlCode2 ].eptr = NES_J_WARP_ZONE_CONTROL2;
	m_eptr[ eWarpControlCode3 ].eptr = NES_J_WARP_ZONE_CONTROL3;
	m_eptr[ eWarpControlWorld3 ].eptr = NES_J_WARP_CONTROL_WORLD_3;
	m_eptr[ eWarpControlWorld5 ].eptr = NES_J_WARP_CONTROL_WORLD_5;
	m_eptr[ eWarpWorlds ].eptr = NES_J_WARP_WORLDS;

	m_eptr[ eCoinsFor1Up ].eptr = NES_J_COINS_FOR_1UP;
	m_eptr[ eHardModeWorld ].eptr = NES_J_HARD_MODE_WORLD;
	m_eptr[ eHardModeLevel ].eptr = NES_J_HARD_MODE_LEVEL;
	m_eptr[ eBowserHammersWorld ].eptr = NES_J_BOWSER_HAMMERS;
	m_eptr[ ePalRotateColors ].eptr = NES_J_PAL_ROTATE_COL_PTR;

	m_eptr[ eSpinyEggPatchPlace ].eptr = NES_J_SPINY_EGG_PATCH_PLACE;
	m_eptr[ eSmallBBox ].eptr = NES_J_SMALLBBOX;
	m_eptr[ eInfiniteLivesPatchPlace ].eptr = NES_J_INFINITE_LIVES_PATCH_PLACE;

	m_eptr[ eDemoActionArray ].eptr = NES_J_DEMO_ACTION_ARRAY;
	m_eptr[ eDemoTimingArray ].eptr = NES_J_DEMO_TIMING_ARRAY;

	m_eptr[ eBowserIdentities ].eptr = NES_J_BOWSER_IDENTITIES;
	m_eptr[ eBowserHits ].eptr = NES_J_BOWSER_HITS;

	m_eptr[ eHPAreaSet0 ].eptr = NES_J_HALF_WAY_PAGES_0;
	m_eptr[ eHPAreaSet1 ].eptr = NES_J_HALF_WAY_PAGES_1;
	m_eptr[ eHPAreaSet2 ].eptr = NES_J_HALF_WAY_PAGES_2;

	m_eptr[ eHalfwayADData ].eptr = NES_J_HALFWAY_AD_DATA;
	m_eptr[ eHalfwayADCallPtr ].eptr = NES_J_HALFWAY_AD_CALL_PTR;
	m_eptr[ ePatchPal ].eptr = NES_J_PATCH_PAL;
	m_eptr[ eStyleVRAMTables ].eptr = NES_J_STYLE_VRAM_TABLES;
	m_eptr[ eBlankPal ].eptr = NES_J_BLANK_PALETTE;
	m_eptr[ eSpriteAttributes ].eptr = NES_J_SPRITE_ATTRIBUTE;
	m_eptr[ eRedPirahnaWorld ].eptr = NES_J_RED_PIRAHNA_WORLD;
	m_eptr[ eRedPirahnaAttr ].eptr = NES_J_RED_PIRAHNA_ATTR;
}

VOID CNesPointers::TestPointers(CNESFile& file)
{
	printf("Testing pointers...\n");

	const BYTE testDataFilesList[16] = { 0xe4, 0xc0, 0xe8, 0xc0, 0xea, 0xc0, 0xee, 0xc0, 0xc0, 0x01, 0xc0, 0x05, 0xc0, 0x0f, 0xc0, 0xff };
	TestPointerReferencedData(file, eFilesListPtrLo, false, testDataFilesList, 8);

	const BYTE testDataWorldAreasOffsets[16] = { 0x00, 0x00, 0x05, 0x05, 0x0a, 0x0a, 0x0e, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
	TestPointerReferencedData(file, eWorldAreasOffsets, false, testDataWorldAreasOffsets, 8);

	const BYTE testDataEnemyAddrHOffset[16] = { 0x14, 0x14, 0x04, 0x04, 0x12, 0x12, 0x00, 0x00, 0xd0, 0xd0, 0xc5, 0xc5, 0xf5, 0xf5, 0xc5, 0xc5 };
	TestPointerReferencedData(file, eEnemyAddrHOffset, false, testDataEnemyAddrHOffset, 8);

	const BYTE testDataLevelAddrHOffset[16] = { 0x14, 0x14, 0x04, 0x04, 0x12, 0x12, 0x00, 0x00, 0x53, 0x53, 0xc8, 0xc8, 0xc6, 0xc6, 0xc8, 0xc8 };
	TestPointerReferencedData(file, eLevelAddrHOffset, false, testDataLevelAddrHOffset, 8);

	const BYTE testDataWorldAreas[16] = { 0x20, 0x20, 0x2c, 0x2c, 0x40, 0x40, 0x21, 0x21, 0x60, 0x60, 0x22, 0x22, 0x2c, 0x2c, 0x00, 0x00 };
	TestPointerReferencedData(file, eWorldAreas, false, testDataWorldAreas, 8);

	const BYTE testDataEnemy[16] = { 0xd0, 0xd0, 0xc5, 0xc5, 0xf5, 0xf5, 0xc5, 0xc5, 0x1c, 0x1c, 0xc6, 0xc6, 0x5d, 0x5d, 0xc6, 0xc6 };
	TestPointerReferencedData(file, eEnemyPtr, false, testDataEnemy, 8);

	const BYTE testDataLevel[16] = { 0x53, 0x53, 0xc8, 0xc8, 0xc6, 0xc6, 0xc8, 0xc8, 0x43, 0x43, 0xc9, 0xc9, 0xde, 0xde, 0xc9, 0xc9 };
	TestPointerReferencedData(file, eLevelPtr, true, testDataLevel, 8);

	const BYTE testDataVRAM[16] = { 0x01, 0x01, 0x03, 0x03, 0x8d, 0x8d, 0x6b, 0x6b, 0xb1, 0xb1, 0x6b, 0x6b, 0xd5, 0xd5, 0x6b, 0x6b };
	TestPointerReferencedData(file, eVRAMAddrTableLo, false, testDataVRAM, 8);

	// FIX: Not sure?
	const BYTE testDataLoopSlaveData[16] = { 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02 };
	TestPointerReferencedData(file, eLoopSlaveDataPtr, false, testDataLoopSlaveData, 8);

	const BYTE testDataLoopCount[2] = { 0x0c, 0x0c };
	TestPointerReferencedData(file, eLoopCount, false, testDataLoopCount, 1);

	const BYTE testDataMetaTiles[16] = { 0xed, 0x69, 0x7d, 0x6a, 0x3d, 0x6b, 0x71, 0x6b, 0x69, 0x24, 0x6a, 0x24, 0x6b, 0x24, 0x6b, 0x24 };
	TestPointerReferencedData(file, eMetatiesPtrLo, false, testDataMetaTiles, 8);
}

VOID CNesPointers::TestPointerReferencedData(CNESFile& file, NES_EPOINTERS lo, bool debug, const BYTE* testData, int testCount)
{
	const char* name = "Unknown";
	NES_EPOINTERS hi = eFilesListPtrLo;
	PTR_TYPE type = PTR_LOHI_REFERENCE;

	switch (lo)
	{
		case eEnemyPtr:
			name = "Enemy";
			type = PTR_REFERENCE;
			break;
		case eLevelPtr:
			name = "Level";
			type = PTR_REFERENCE;
			break;
		case eEnemyAddrHOffset:
			name = "Enemy Address Horizontal Offset";
			type = PTR_REFERENCE;
			break;
		case eLevelAddrHOffset:
			name = "Level Address Horizontal Offset";
			type = PTR_REFERENCE;
			break;
		case eWorldAreasOffsets:
			name = "World Areas Offsets";
			type = PTR_REFERENCE;
			break;
		case eWorldAreas:
			name = "World Areas";
			type = PTR_REFERENCE;
			break;
		case eLoopSlaveDataPtr:
			name = "Loop Slave Data";
			type = PTR_REFERENCE;
			break;
		case eFilesListPtrLo:
			hi = eFilesListPtrHi;
			name = "Files List";
			type = PTR_INDIRECT_REFERENCE;
			break;
		case eVRAMAddrTableLo:
			hi = eVRAMAddrTableHi;
			name = "VRAM Address Table";
			break;
		case eLoopCount:
			name = "Loop Count";
			type = PTR_DIRECT_REFERENCE;
			break;
		case eMetatiesPtrLo:
			hi = eMetatiesPtrHi;
			name = "Metatiles";
			type = PTR_INDIRECT_REFERENCE;
			break;
	}

	USHORT uPtrHi, uPtrLo, uPtr;
	uPtrHi = Pointer(hi);
	uPtrLo = Pointer(lo);

	// Initialize pointer
	switch (type)
	{
		case PTR_REFERENCE:
			uPtr = uPtrLo;
			printf("Testing reference '%s', Ptr: 0x%04x, ", name, uPtr);
			break;
		case PTR_LOHI_REFERENCE:
			uPtr = MAKEWORD(uPtrLo, uPtrHi);
			printf("Testing LoHi reference '%s', Ptr: 0x%04x, ", name, uPtr);
			break;
		case PTR_INDIRECT_REFERENCE:
			printf("Testing indirect reference '%s', PtrLo: 0x%04x, PtrHi: 0x%04x ", name, uPtrLo, uPtrHi);
			break;
		case PTR_DIRECT_REFERENCE:
			uPtr = m_eptr[lo].ptr;
			printf("Testing direct reference '%s', Ptr: 0x%04x ", name, uPtr);
			break;
	}

	bool matches = true;

	for (int i = 0; i < testCount; i++)
	{
		BYTE dataLo = 0;
		BYTE dataHi = 0;

		// Grab data based on type
		switch (type)
		{
			case PTR_REFERENCE:
			case PTR_DIRECT_REFERENCE:
			case PTR_LOHI_REFERENCE:
				dataLo = file.Data<BYTE>(uPtr + i);
				dataHi = dataLo;
				break;
			case PTR_INDIRECT_REFERENCE:
				dataLo = file.Data<BYTE>(uPtrLo + i);
				dataHi = file.Data<BYTE>(uPtrHi + i);
				break;
		}
		
		// Print out the data
		if (debug)
			printf("0x%02x, 0x%02x, ", dataLo, dataHi);

		// Test the data
		int testPointer = i * 2;
		if (dataLo != testData[testPointer] || dataHi != testData[testPointer + 1])
			matches = false;
	}

	printf("... %s!\n", matches ? "GOOD" : "BAD");
}
