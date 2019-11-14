#pragma once

#include "../global.h"
#include "../list_menu.h"

struct Clock
{
	u16 year;
	u8 _; //For some reason always set to 4
	u8 month;
	u8 day;
	u8 dayOfWeek;
	u8 hour;
	u8 minute;
	u8 second;
};

#define gSaveBlock1Ptr ((struct SaveBlock1*) *((u32*) 0x3005008))
#define gSaveBlock2Ptr ((struct SaveBlock2*) *((u32*) 0x300500C))
#define gSaveBlock3Ptr ((struct SaveBlock3*) *((u32*) 0x3005010))

#define Clock ((struct Clock*) 0x300553C)

#define gEnemyParty ((struct Pokemon*) 0x202402C)
#define gPlayerParty ((struct Pokemon*) 0x2024284)

//gBitTable;

/*u8*/  //#define gDecompressionBuffer 	 ((u8*) 0x201C000)
/*u32*/ #define gTrainerId 				*((u32*) 0x2020000)

		#define gWindows ((struct Window*) 0x20204B4)
/*u8*/  #define gSprites ((struct Sprite*) 0x202063C)

/*u8*/  #define gStringVar1 ((u8*) 0x2021CD0)
/*u8*/  #define gStringVar2 ((u8*) 0x2021CF0)
/*u8*/  #define gStringVar3 ((u8*) 0x2021D04)
/*u8*/  #define gStringVar4 ((u8*) 0x2021D18)

		#define ColorFilter *((u8*)0x2036E28)

		#define gWarp1 ((struct WarpData*) 0x2031dbc)

		#define gPlayerAvatar ((struct PlayerAvatar*) 0x02037078)

		#define gBoxStatusAndType ((u8*) 0x0203709C)

		#define gStartMenu ((struct StartMenu*) 0x020370F0)


/*u8*/  #define gUnknown_2024005 ((u8*) 0x2024005) //Length 0x3
/*u8*/  #define gUnknown_2024008 ((u8*) 0x2024008) //Length 0x10

/*u8*/  //#define sLearningMoveTableID *((u8*) 0x2024028)
/*u8*/  #define gPlayerPartyCount *((u8*) 0x2024029)
/*u8*/  #define gEnemyPartyCount *((u8*) 0x202402A)

/*u8*/  #define gMultiuseSpriteTemplate ((struct SpriteTemplate*) 0x20244DC)

		//SaveBlock1ActualLocation 0x202552C
		extern struct MapHeader gMapHeader;
		#define gEventObjects ((struct EventObject*) 0x2036E38)
/*
		#define Var8000 (*((u16*) 0x20370B8))
		#define Var8001 (*((u16*) 0x20370BA))
		#define Var8002 (*((u16*) 0x20370BC))
		#define Var8003 (*((u16*) 0x20370BE))
		#define Var8004 (*((u16*) 0x20370C0))
		#define Var8005 (*((u16*) 0x20370C2))
		#define Var8006 (*((u16*) 0x20370C4))
		#define Var8007 (*((u16*) 0x20370C6))
		#define Var8008 (*((u16*) 0x20370C8))
		#define Var800D (*((u16*) 0x20370D0))
		#define Var8010 (*((u16*) 0X20370D6))


#define gSpecialVar_LastResult (*((u16*) 0x20370D0))
#define gSpecialVar_LastTalked (*((u16*) 0x20370D2))
#define gSpecialVar_MonBoxId (*((u16*) 0x20370D6))
#define gSpecialVar_MonBoxPos (*((u16*) 0x20370D8))
*/

/*u8*/  #define gPlttBufferUnfaded ((u16*) 0x20371F8)
/*u8*/  #define gPlttBufferUnfaded2 ((u16*) 0x20373F8)
/*u8*/  #define gPlttBufferFaded ((u16*) 0x20375F8)
/*u8*/  #define gPlttBufferFaded2 ((u16*) 0x20377F8)

/*u8*/  #define gPaletteFade ((struct PaletteFadeControl*) 0x2037AB8)
/*u32*/	#define sPlttBufferTransferPending (*((u32*) 0x2037AC8))

		#define gWeatherPtr ((struct Weather*) 0x2037F34)

/*u8*/  #define sPaletteGammaTypes ((u8*) 0x20386A4)
		extern u16 gScanlineEffectRegBuffers[2][0x3C0];

		//#define gEncounterRate ((struct EncounterRate*) 0x20386D0)
		#define sWildEncountersDisabled (*((u8*) 0x20386DC))

/*u8*/  //#define gFieldEffectArguments ((struct FieldEffectArguments*) 0x20386E0)

		#define gShopDataPtr ((struct ShopData*) 0x2039934)

		#define gNamingScreenData ((struct NamingScreenData*) (*(u32*) 0x203998C))
/*u8*/ //#define gSafariBallNumber 	(*((u8*) 0x02039994))	// see src/scripting.c
/*u16*/ #define gSafariSteps	   (*((u16*) 0x02039996))

/*u8*/  #define gAbilitiesPerBank ((u8*) 0x2039A30)
		//#define gStringInfo ((struct BattleMsgData*) *((u32*) 0x2039A34))

		#define sHofFadingRelated (*((u32*) 0x0203AB34))
		#define gHasHallOfFameRecords (*(u8*) 0x0203AB44)

/*u8*/	#define gQuestLogMode (*((u8*) 0x203ADFA))
		//#define gPartyMenuView ((struct PartyMenuViewing*) 0x203B09C)
		#define gBrmData ((struct BrmData*)  ((u32*) 0x203b0a0))
		//#define gSelectedOrderFromParty ((u8*) 0x203B0D4)
		#define gSummaryScreenData ((struct MonSummaryData*) *((u32*) 0x203B140))
		#define gCurrentPartyIndex (*(u8*) 0x203B16C)

/*u8*/  #define gUnknown_0203B0DC ((u8*) 0x203B0DC)

		#define AlphaBlendingCoeffA *((u8*)0x3000052)
		#define PalTagsStart *((u8*)0x3003E58)

		#define PalTags ((u16*)0x3000DE8)

		#define gMultiuseListMenuTemplate ((struct ListMenuTemplate*) ((u32*) 0x3005E70))

		#define gScriptEnv1 ((struct ScriptContext*) 0x03000EB0)
		#define gScriptEnv2 ((struct ScriptContext*) 0x03000F28)
		#define gLoadPointer (*((const u8**) 0x03000f14))
		#define sScriptContext2Enabled (*((u8*) 0x3000F28))
		#define gKeypadInitialCountdown ((*u16) 0x030030e0)
		#define gMain (((struct Main*) 0x30030F0)[0])
		#define gKeypadFollowUpCountdown ((*u16) 0x0300352c)
/*u32*/ #define gBattleMainFunc (*((u32*) 0x3004F84))
/*u8*/  #define gLeveledUpInBattle (*((u8*) 0x3004FD4))
		#define gBattleBankFunc ((u32*) 0x3004FE0)
		#define gHealthboxIDs ((u8*) 0x3004FF0)
		#define gMultiUsePlayerCursor (*((u8*) 0x3004FF4))
		#define gNumberOfMovesToChoose (*((u8*) 0x3004FF8))

		#define gOverworldTilemapBg3 (*((u32*) 0x300501C))

/*u8*/  #define gSelectedEventObject (*((u8*) 0x3005074))
		//#define gTasks ((struct Task*) 0x3005090) //struct Task gTasks[ACTIVE_SENTINEL];

		#define gCurrentMapName gMapHeader.regionMapSectionId

		//#define gGbaTimer ((struct GbaTimer*) 0x4000108)
		#define gKeyReg (*((u16*) 0x4000130))

		extern struct MusicPlayerInfo gMPlay_BGM;

		#define gBattleCircusFlags (*((u32*) 0x203E044))
		#define gFishingByte *((u8*) 0x203E048)

		//Expanded text buffers					//Size					//buffercommand X	//String Arg
/*u8*/  #define gStringVar7 ((u8*) 0x2022BC4)	//32 bytes					//Buffer 0x5 	//FD 07
/*u8*/  #define gStringVar8 ((u8*) 0x2022BE4)	//32 bytes					//Buffer 0x6	//FD 08
/*u8*/  #define gStringVar9 ((u8*) 0x2022C04)	//32 bytes					//Buffer 0x7	//FD 09
/*u8*/  #define gStringVarA ((u8*) 0x2022C24)	//32 bytes					//Buffer 0x8	//FD 0A
/*u8*/  #define gStringVarB ((u8*) 0x2022C44)	//32 bytes					//Buffer 0x9	//FD 0B
/*u8*/  #define gStringVarC ((u8*) 0x2022C64)	//100 bytes					//Buffer 0xA	//FD 0C
/*u8*/  #define gStringVarD ((u8*) 0x2022CC8)	//100 bytes (to 0x2022D2C)	//Buffer 0xB	//FD 0D
