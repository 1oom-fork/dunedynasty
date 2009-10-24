/* $Id$ */

#include "types.h"
#include "libemu.h"
#include "decompiled.h"

/**
 * Decompiled function f__B4AB_0000_000D_6028()
 *
 * @name f__B4AB_0000_000D_6028
 * @implements B4AB:0000:000D:6028 ()
 * @implements B4AB:000D:000B:171B
 * @implements B4AB:0018:0014:83FC
 * @implements B4AB:002C:001D:7130
 * @implements B4AB:0049:000C:5C07
 * @implements B4AB:0055:0006:9AE8
 * @implements B4AB:005B:0005:FB00
 * @implements B4AB:0060:0005:0EE9
 * @implements B4AB:0065:0002:E53A
 * @implements B4AB:00B1:0005:5EF6
 * @implements B4AB:00B6:0002:2597
 *
 * Called From: 34AB:0020:0005:0000
 */
void f__B4AB_0000_000D_6028()
{
l__0000:
	emu_push(emu_bp);
	emu_bp = emu_sp;
	emu_push(emu_ds);
	emu_ax = 0x1C14;
	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x000D); emu_cs = 0x0FCB; f__0FCB_000D_0019_5047();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34AB) { overlay(0x34AB, 1); }
	goto l__000D;
l__000D:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	emu_ax = 0xFFFE;
	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x0018); emu_cs = 0x3483; overlay(0x3483, 0); f__B483_04CB_0015_EBB4();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34AB) { overlay(0x34AB, 1); }
	goto l__0018;
l__0018:
	emu_pop(&emu_cx);
	emu_ax = emu_get_memory16(emu_ds, 0x00, 0x3A38);
	emu_orw(&emu_ax, emu_ax);
	if (emu_ax == 0) goto l__002C;
	emu_cmpw(&emu_ax, 0x1);
	if (emu_ax == 0x1) { /* Unresolved jump */ emu_ip = 0x008C; emu_last_cs = 0xB4AB; emu_last_ip = 0x0023; emu_last_length = 0x0014; emu_last_crc = 0x83FC; emu_call(); return; }
	emu_cmpw(&emu_ax, 0x2);
	if (emu_ax == 0x2) { /* Unresolved jump */ emu_ip = 0x0067; emu_last_cs = 0xB4AB; emu_last_ip = 0x0028; emu_last_length = 0x0014; emu_last_crc = 0x83FC; emu_call(); return; }
	/* Unresolved jump */ emu_ip = 0x008C; emu_last_cs = 0xB4AB; emu_last_ip = 0x002A; emu_last_length = 0x0014; emu_last_crc = 0x83FC; emu_call();
l__002C:
	emu_push(emu_ds);
	emu_ax = 0x1AF9;
	emu_push(emu_ax);
	emu_push(emu_ds);
	emu_ax = 0x1AE1;
	emu_push(emu_ax);
	emu_ax = 0xFFFF;
	emu_push(emu_ax);
	emu_push(emu_ds);
	emu_ax = 0x1A91;
	emu_push(emu_ax);
	emu_push(emu_ds);
	emu_ax = 0x1A31;
	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x0049); emu_cs = 0x34ED; overlay(0x34ED, 0); f__B4ED_0000_0079_AC5D();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34AB) { overlay(0x34AB, 1); }
	goto l__0049;
l__0049:
	emu_addw(&emu_sp, 0x12);
	emu_ax = 0x1E;
	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x0055); emu_cs = 0x3483; overlay(0x3483, 0); f__B483_0283_0014_983A();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34AB) { overlay(0x34AB, 1); }
	goto l__0055;
l__0055:
	emu_pop(&emu_cx);
	emu_push(emu_cs); emu_push(0x005B); emu_cs = 0x34ED; overlay(0x34ED, 0); f__B4ED_0200_000F_1FF4();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34AB) { overlay(0x34AB, 1); }
	goto l__005B;
l__005B:
	emu_push(emu_cs); emu_push(0x0060); emu_cs = 0x1DD7; f__1DD7_0B53_0025_36F7();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34AB) { overlay(0x34AB, 1); }
	goto l__0060;
l__0060:
	emu_push(emu_cs); emu_push(0x0065); emu_cs = 0x34ED; overlay(0x34ED, 0); f__B4ED_0184_0010_CD7E();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34AB) { overlay(0x34AB, 1); }
	goto l__0065;
l__0065:
	goto l__00B1;
l__00B1:
	emu_push(emu_cs); emu_push(0x00B6); emu_cs = 0x3491; overlay(0x3491, 0); f__B491_0819_000C_0B7D();
	/* Check if this overlay should be reloaded */
	if (emu_cs == 0x34AB) { overlay(0x34AB, 1); }
	goto l__00B6;
l__00B6:
	emu_pop(&emu_bp);

	/* Return from this function */
	emu_pop(&emu_ip);
	emu_pop(&emu_cs);
	return;
}
