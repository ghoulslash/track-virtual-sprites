#include "../include/global.h"
#include "../include/global.fieldmap.h"

#include "../include/event_data.h"

#include "../include/event_object_movement.h"
#include "../include/sprite.h"

#include "../include/new/ram_locs.h"

#include "../include/script.h"
#include "../include/overworld.h"
#include "../include/palette.h"

#define V_SPRITE_COUNT 20
struct vSpriteData {
	/*0x0*/ u16 owNum;	//[table][sprite]
	/*0x2*/ u8 x;	//grid x
	/*0x3*/ u8 y;	//grid y
	/*0x4*/ u8 spriteId;
	/*0x5*/ u8 facing:4;
	/*0x4*/ u8 behaviour:4;	//limits virtual behaviour to 1-15 (all except vs seeker arm raise)
	/*0x6*/ u8 mapGroup;
	/*0x7*/ u8 mapNum;
};  /*0x8*/ //size
//124 bytes
struct VirtualSprites {
	struct vSpriteData vSprite[V_SPRITE_COUNT];	//20 sprites * 8 bytes = 160 bytes
}; //size 160 bytes


/*===========================*/
//	CUSTOMIZATION
/*===========================*/
// flag that, if set, keeps virtual sprites on the map
#define FLAG_KEEP_V_SPRITES 0x26E

// new, .sav compatable RAM for your virtual sprite data (total 161 bytes needed)
#define gVirtualSpriteCount (*((u8*) 0x203c8ff))
#define gVirtualSprites ((struct VirtualSprites*) 0x203c900)
