#include "defines.h"

// File Functions
void CreateNewVirtualSprite(u16 newGfx, u8 vId, u8 x, u8 y, u8 z, u8 direction);
void SaveVirtualSpriteInfo(u16 graphicsId, u8 vId, u8 x0, u8 y0, u8 z, u8 direction);
void SaveVirtualSpriteId(u8 spriteId, u8 vId);
bool8 ScrCmd_createvobject(struct ScriptContext *ctx);
bool8 ScrCmd_turnvobject(struct ScriptContext *ctx);
void DeleteVirtualSpriteData(u8 vId);
void DestroyVirtualSprite(u8 vId);
void sp06A_DestroyVSprite(void);
void sp06B_DestroyAllVSprites(void);
void ConditionalSpawnVirtualSprite(void);
void mapldr_default(void);
void CB2_ReturnToFieldLocal(void);

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
void CreateNewVirtualSprite(u16 newGfx, u8 vId, u8 x, u8 y, u8 z, u8 direction)
{
	SaveVirtualSpriteInfo(newGfx, vId, x, y, z, direction);
	CreateVirtualSprite(newGfx, vId, x, y, z, direction);
	lnpc_look(vId, direction);
};

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
void SaveVirtualSpriteInfo(u16 graphicsId, u8 vId, u8 x0, u8 y0, u8 z, u8 direction)
{
	gVirtualSpriteCount++;
	gVirtualSprites->vSprite[vId].owNum = graphicsId;
	gVirtualSprites->vSprite[vId].x = x0;
	gVirtualSprites->vSprite[vId].y = y0;
	gVirtualSprites->vSprite[vId].facing = direction;
	gVirtualSprites->vSprite[vId].behaviour = z;
	gVirtualSprites->vSprite[vId].mapGroup = gSaveBlock1Ptr->location.mapGroup;
	gVirtualSprites->vSprite[vId].mapNum = gSaveBlock1Ptr->location.mapNum;
};

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
void SaveVirtualSpriteId(u8 spriteId, u8 vId)
{
	gVirtualSprites->vSprite[vId].spriteId = spriteId;
}

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
bool8 ScrCmd_createvobject(struct ScriptContext *ctx)
{
	u8 graphicsId = ScriptReadByte(ctx);
    u8 vId = ScriptReadByte(ctx);
    u16 x = VarGet(ScriptReadHalfword(ctx));
    u32 y = VarGet(ScriptReadHalfword(ctx));
    u8 z = ScriptReadByte(ctx);
    u8 direction = ScriptReadByte(ctx);
	
	u8 tableId = vSpriteTableRam;
	u16 newGfx = graphicsId;
	newGfx |= (tableId << 8);
	vSpriteTableRam = 0;
	
	if (gVirtualSprites->vSprite[vId].owNum != 0)
		DestroyVirtualSprite(vId);	//destroy virtual sprite with same Id first	
	CreateNewVirtualSprite(newGfx, vId, (u8) x, (u8) y, z, direction);
    return FALSE;
}

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
bool8 ScrCmd_turnvobject(struct ScriptContext *ctx)
{
    u8 vId = ScriptReadByte(ctx);
    u8 direction = ScriptReadByte(ctx);

	gVirtualSprites->vSprite[vId].facing = direction;

    lnpc_look(vId, direction);
    return FALSE;
}

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
void DeleteVirtualSpriteData(u8 vId)
{
	gVirtualSprites->vSprite[vId].x = 0;
	gVirtualSprites->vSprite[vId].y = 0;
	gVirtualSprites->vSprite[vId].owNum = 0;
	gVirtualSprites->vSprite[vId].spriteId = 0;
	gVirtualSprites->vSprite[vId].facing = 0;
	gVirtualSprites->vSprite[vId].behaviour = 0;
	gVirtualSprites->vSprite[vId].mapGroup = 0;
	gVirtualSprites->vSprite[vId].mapNum = 0;
}

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
void DestroyVirtualSprite(u8 vId)
{
	DestroySpriteAndFreeResources(&gSprites[gVirtualSprites->vSprite[vId].spriteId]);
	DeleteVirtualSpriteData(vId);
}


/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
// Destroy Specific Virtual Sprite
void sp06A_DestroyVSprite(void)
{
	u8 vId = Var8000;
	
	DestroyVirtualSprite(vId);
	gVirtualSpriteCount--;
}

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
// Destory all virtual sprites
void sp06B_DestroyAllVSprites(void)
{
	int i;
	
	for (i = 0; i < V_SPRITE_COUNT; ++i)
	{
		if (gVirtualSprites->vSprite[i].owNum != 0)
			DestroyVirtualSprite(i);
	}
	gVirtualSpriteCount = 0;
}



/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
// Re-spawn virtual sprites
void ConditionalSpawnVirtualSprite(void)
{
	u8 i;	
	u8 count = gVirtualSpriteCount;
	
	if (FlagGet(FLAG_KEEP_V_SPRITES))
	{
		for (i = 0; i < count; ++i)
		{
			if (gVirtualSprites->vSprite[i].owNum == 0)
				continue;	//no sprite to make here
			else if (gVirtualSprites->vSprite[i].mapGroup != gSaveBlock1Ptr->location.mapGroup ||
					gVirtualSprites->vSprite[i].mapNum != gSaveBlock1Ptr->location.mapNum)	//map doesnt match
				continue;
			else
			{
				CreateNewVirtualSprite(gVirtualSprites->vSprite[i].owNum, i,
					gVirtualSprites->vSprite[i].x, gVirtualSprites->vSprite[i].y,
					gVirtualSprites->vSprite[i].behaviour, gVirtualSprites->vSprite[i].facing);
			}
		}
	}
	else if (count > 0)
		sp06B_DestroyAllVSprites();	//if flag not set but sprite data exists, erase the data
}


/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
// keep virtual sprites around through door warp
void mapldr_default(void)
{
    Overworld_PlaySpecialMapMusic();
	render_prev_quest_text_if_appropriate();
	start_map_chg_seq_and_pal_fill_depending_on_room_and_tile(0);
	ScriptContext2_Enable();
	
	ConditionalSpawnVirtualSprite();
}


/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//keep sprites around after returning to overworld from menu/battle
void CB2_ReturnToFieldLocal(void)
{
    if (map_loading_iteration_2_link(&gMain.state))
    {
        SetFieldVBlankCallback_0();
		
		ConditionalSpawnVirtualSprite();
		
        SetMainCallback2(CB2_Overworld);
    }
}


/*	Uneeded with CB2_ReturnToFieldLocal
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//keep sprites around after trainerbattles
void FieldCallback_ReturnToEventScript2(void)
{
    ScriptContext2_Enable();
    Overworld_PlaySpecialMapMusic();
    PalFillBlack();
	
	ConditionalSpawnVirtualSprite();
	
    CreateTask(task0A_asap_script_env_2_enable_and_set_ctx_running, 10);
}
*/




