.text
.align 2
.thumb
.thumb_func

.global SpawnVSpritesWithOverworld
.global CreateVSpriteNPC
.global SaveSpriteId

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
.align 2
.pool
@ hook at 0805EA78 via r1
SaveSpriteId:
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	mov r1, r10	@vId
	cmp r6, #64
	beq Delete
	mov r0, r6	@spriteId
	push {r2-r7}
	bl SaveVirtualSpriteId
	pop {r2-r7}
	lsl r0, r6, #0x04
	add r0, r0, r6
	lsl r0, r0, #0x02
	ldr r1, =(0x0202063c)
	ldr r5, =(0x0805ea88 +1)
	bx r5
Delete:
	bl DeleteVirtualSpriteData
	ldr r0, =(0x805EB24 +1)
	bx r0
	

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
.align 2
.pool
@ hook at 08056578 via r0
SpawnVSpritesWithOverworld:
	push {lr}
	bl ScriptContext2_RunScript
	bl RunTasks
	bl ConditionalSpawnVirtualSprite
	ldr r0, =(0x08056582 +1)
	bx r0
	
ScriptContext2_RunScript:
	ldr r0, =(0x08069AA8 +1)
	bx r0

RunTasks:
	ldr r0, =(0x08077578 +1)
	bx r0
	
	
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
.align 2
.pool
@ hook at 0811BB08 via r0 - not sure this function is useful to save the data for, only for link stuff.
CreateVSpriteNPC:
	mov r0, #25	@graphics Id
	mov r1, r4	@virtual sprite id
	bl CreateVirtualSprite
	ldr r1, =(0x0811BB10 +1)
	bx r1
	
	