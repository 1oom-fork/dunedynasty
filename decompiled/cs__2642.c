/* $Id$ */

#include "types.h"
#include "libemu.h"
#include "decompiled.h"

/**
 * Decompiled function f__2642_0002_005E_87F6()
 *
 * @name f__2642_0002_005E_87F6
 * @implements 2642:0002:005E:87F6 ()
 * @implements 2642:0060:0009:B39F
 *
 * Called From: 07D4:010D:000F:5B83
 * Called From: 07D4:12E6:000D:CD87
 * Called From: 07D4:1443:0010:9618
 * Called From: 07D4:1517:0051:4C81
 * Called From: 07D4:15ED:000A:E2DD
 * Called From: 10E4:095E:0012:67CD
 * Called From: 10E4:0B39:000A:E6DD
 * Called From: 10E4:0B39:0009:F09D
 * Called From: 10E4:1B44:000F:8BED
 * Called From: B4DA:0FCD:000A:A344
 * Called From: B4DA:1039:000A:A344
 * Called From: B4DA:1332:000A:A344
 * Called From: B536:00A1:0010:094E
 * Called From: B536:01A3:0060:01F3
 * Called From: B536:0327:0013:1C1F
 */
void f__2642_0002_005E_87F6()
{
l__0002:
	emu_push(emu_bp);
	emu_bp = emu_sp;
	emu_subw(&emu_sp, 0x6);
	emu_push(emu_si);
	emu_push(emu_di);
	emu_si = emu_get_memory16(emu_ss, emu_bp,  0x6);
	emu_bx = emu_si;
	emu_cl = 0x4;
	emu_shlw(&emu_bx, emu_cl);
	emu_ax = emu_get_memory16(emu_ds, emu_bx, 0x4062);
	emu_cl = 0x3;
	emu_shlw(&emu_ax, emu_cl);
	emu_di = emu_ax;
	emu_bx = emu_si;
	emu_cl = 0x4;
	emu_shlw(&emu_bx, emu_cl);
	emu_ax = emu_get_memory16(emu_ds, emu_bx, 0x4064);
	emu_get_memory16(emu_ss, emu_bp, -0x2) = emu_ax;
	emu_bx = emu_si;
	emu_cl = 0x4;
	emu_shlw(&emu_bx, emu_cl);
	emu_ax = emu_get_memory16(emu_ds, emu_bx, 0x4066);
	emu_cl = 0x3;
	emu_shlw(&emu_ax, emu_cl);
	emu_get_memory16(emu_ss, emu_bp, -0x4) = emu_ax;
	emu_bx = emu_si;
	emu_cl = 0x4;
	emu_shlw(&emu_bx, emu_cl);
	emu_ax = emu_get_memory16(emu_ds, emu_bx, 0x4068);
	emu_get_memory16(emu_ss, emu_bp, -0x6) = emu_ax;
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x2);
	emu_addw(&emu_ax, emu_get_memory16(emu_ss, emu_bp, -0x6));
	emu_decw(&emu_ax);
	emu_push(emu_ax);
	emu_ax = emu_di;
	emu_addw(&emu_ax, emu_get_memory16(emu_ss, emu_bp, -0x4));
	emu_decw(&emu_ax);
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x2));
	emu_push(emu_di);
	emu_push(emu_cs); emu_push(0x0060); emu_cs = 0x2B6C; emu_GUI_Mouse_Hide_InRegion();
l__0060:
	emu_addw(&emu_sp, 0x8);
	emu_pop(&emu_di);
	emu_pop(&emu_si);
	emu_sp = emu_bp;
	emu_pop(&emu_bp);

	/* Return from this function */
	emu_pop(&emu_ip);
	emu_pop(&emu_cs);
	return;
}

/**
 * Decompiled function f__2642_0069_0008_D517()
 *
 * @name f__2642_0069_0008_D517
 * @implements 2642:0069:0008:D517 ()
 * @implements 2642:0071:0002:2597
 *
 * Called From: 07D4:02ED:0007:6375
 * Called From: 07D4:136D:0006:63C7
 * Called From: 07D4:1470:0008:C54E
 * Called From: 07D4:1557:0009:652B
 * Called From: 07D4:161A:0008:C54E
 * Called From: 10E4:098E:0008:C54E
 * Called From: 10E4:0B80:0008:C54E
 * Called From: 10E4:1B71:0008:C54E
 * Called From: B4DA:0FFA:0008:C54E
 * Called From: B4DA:1066:0008:C54E
 * Called From: B4DA:135F:0008:C54E
 * Called From: B536:0087:000F:9A7C
 * Called From: B536:02FC:0015:7F44
 * Called From: B536:04F5:004E:C8CD
 */
void f__2642_0069_0008_D517()
{
l__0069:
	emu_push(emu_bp);
	emu_bp = emu_sp;
	emu_push(emu_cs); emu_push(0x0071); emu_cs = 0x2B6C; emu_GUI_Mouse_Show_InRegion();
l__0071:
	emu_pop(&emu_bp);

	/* Return from this function */
	emu_pop(&emu_ip);
	emu_pop(&emu_cs);
	return;
}
