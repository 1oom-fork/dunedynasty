/* $Id$ */

#include "types.h"
#include "libemu.h"
#include "decompiled.h"

/**
 * Decompiled function f__07D4_0000_0027_FA61()
 *
 * @name f__07D4_0000_0027_FA61
 * @implements 07D4:0000:0027:FA61 ()
 * @implements 07D4:0027:000D:CDE2
 * @implements 07D4:0034:0015:CB18
 * @implements 07D4:0044:0005:E72D
 * @implements 07D4:0049:0005:EE7F
 * @implements 07D4:004E:0005:2369
 * @implements 07D4:0053:000A:5C8D
 * @implements 07D4:005D:000C:C981
 * @implements 07D4:0069:0009:B0BE
 * @implements 07D4:0072:000D:FD25
 * @implements 07D4:007F:000D:8CA0
 * @implements 07D4:008C:000F:1144
 * @implements 07D4:009B:0010:3059
 * @implements 07D4:00AB:0014:88E1
 * @implements 07D4:00AD:0012:2029
 * @implements 07D4:00BF:002C:F427
 * @implements 07D4:00C1:002A:1C8F
 * @implements 07D4:00D5:0016:0C55
 * @implements 07D4:00E1:000A:5C09
 * @implements 07D4:00EB:000E:5ED8
 * @implements 07D4:00FA:0009:FDC6
 * @implements 07D4:0103:000F:5B83
 * @implements 07D4:0112:001E:949E
 * @implements 07D4:0130:0012:BCD1
 * @implements 07D4:0136:000C:1489
 * @implements 07D4:0142:0013:9BCD
 * @implements 07D4:0146:000F:62FC
 * @implements 07D4:0155:0012:3299
 * @implements 07D4:0157:0010:9295
 * @implements 07D4:0167:0008:B465
 * @implements 07D4:0169:0006:86E5
 * @implements 07D4:016F:0005:852E
 * @implements 07D4:0174:0019:D3DB
 * @implements 07D4:017A:0013:BD94
 * @implements 07D4:0180:000D:6793
 * @implements 07D4:0186:0007:EFF5
 * @implements 07D4:018D:0014:4BDF
 * @implements 07D4:01A1:0040:5DDA
 * @implements 07D4:01C6:001B:835B
 * @implements 07D4:01E1:0024:9249
 * @implements 07D4:01E4:0021:3AC0
 * @implements 07D4:01E7:001E:B107
 * @implements 07D4:01F0:0015:AC7C
 * @implements 07D4:01F6:000F:E9F6
 * @implements 07D4:0205:0008:9BD5
 * @implements 07D4:020D:0085:A17E
 * @implements 07D4:0245:004D:D411
 * @implements 07D4:024B:0047:8A56
 * @implements 07D4:0273:001F:BB63
 * @implements 07D4:0292:0016:367F
 * @implements 07D4:02A8:001A:7955
 * @implements 07D4:02AE:0014:4168
 * @implements 07D4:02B4:000E:C5E6
 * @implements 07D4:02C2:0012:6EC2
 * @implements 07D4:02D4:000A:0B5A
 * @implements 07D4:02DE:000D:0FE3
 * @implements 07D4:02EB:0007:6375
 * @implements 07D4:02F2:0006:F7CE
 *
 * Called From: 0642:03D4:0008:75E4
 * Called From: 10E4:213A:000A:1679
 */
void f__07D4_0000_0027_FA61()
{
l__0000:
	emu_push(emu_bp);
	emu_bp = emu_sp;
	emu_subw(&emu_sp, 0x16);
	emu_push(emu_si);
	emu_push(emu_di);
	emu_cmpw(&emu_get_memory16(emu_ds, 0x00, 0x3A0E), 0x1);
	if (emu_flags.zf) goto l__0027;
	emu_cmpw(&emu_get_memory16(emu_ds, 0x00, 0x3A0E), 0x3);
	if (emu_flags.zf) goto l__0027;
	emu_cmpw(&emu_get_memory16(emu_ds, 0x00, 0x3A0E), 0x2);
	if (emu_flags.zf) goto l__0027;
	emu_cmpw(&emu_get_memory16(emu_ds, 0x00, 0x3A0E), 0x4);
	if (emu_flags.zf) goto l__0027;
	goto l__02F2;
l__0027:
	emu_get_memory16(emu_ss, emu_bp, -0x10) = 0x0;
	emu_push(emu_get_memory16(emu_ss, emu_bp,  0x6));
	emu_push(emu_cs); emu_push(0x0034); emu_cs = 0x2598; f__2598_0000_0017_EB80();
	goto l__0034;
l__0034:
	emu_pop(&emu_cx);
	emu_get_memory16(emu_ss, emu_bp, -0x12) = emu_ax;
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp,  0x6), 0x0);
	if (!emu_flags.zf) {
		emu_get_memory16(emu_ds, 0x00, 0x3A12) = 0x1;
	}
	goto l__0044;
l__0044:
	emu_push(emu_cs); emu_push(0x0049); emu_cs = 0x06F7; f__06F7_0602_0018_CEB0();
	goto l__0049;
l__0049:
	emu_push(emu_cs); emu_push(0x004E); emu_cs = 0x151A; f__151A_0196_0018_AF63();
	goto l__004E;
l__004E:
	emu_push(emu_cs); emu_push(0x0053); emu_cs = 0x0FE4; f__0FE4_0002_0021_D0A9();
	goto l__0053;
l__0053:
	emu_cmpw(&emu_get_memory16(emu_ds, 0x00, 0x3A12), 0x0);
	if (emu_flags.zf) goto l__005D;
	goto l__01F6;
l__005D:
	emu_ax = emu_get_memory16(emu_ds, 0x00, 0x39FE);
	emu_cmpw(&emu_ax, emu_get_memory16(emu_ds, 0x00, 0x39FC));
	if (!emu_flags.zf) goto l__0069;
	goto l__01F6;
l__0069:
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x39FE));
	emu_push(emu_cs); emu_push(0x0072); emu_cs = 0x0F3F; f__0F3F_0322_0011_5AAA();
	goto l__0072;
l__0072:
	emu_pop(&emu_cx);
	emu_get_memory16(emu_ss, emu_bp, -0xC) = emu_ax;
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x39FE));
	emu_push(emu_cs); emu_push(0x007F); emu_cs = 0x0F3F; f__0F3F_0335_0015_2275();
	goto l__007F;
l__007F:
	emu_pop(&emu_cx);
	emu_get_memory16(emu_ss, emu_bp, -0xE) = emu_ax;
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x39FC));
	emu_push(emu_cs); emu_push(0x008C); emu_cs = 0x0F3F; f__0F3F_0322_0011_5AAA();
	goto l__008C;
l__008C:
	emu_pop(&emu_cx);
	emu_subw(&emu_ax, emu_get_memory16(emu_ss, emu_bp, -0xC));
	emu_si = emu_ax;
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x39FC));
	emu_push(emu_cs); emu_push(0x009B); emu_cs = 0x0F3F; f__0F3F_0335_0015_2275();
	goto l__009B;
l__009B:
	emu_pop(&emu_cx);
	emu_subw(&emu_ax, emu_get_memory16(emu_ss, emu_bp, -0xE));
	emu_di = emu_ax;
	emu_orw(&emu_si, emu_si);
	if (!(emu_flags.sf != emu_flags.of)) goto l__00AB;
	emu_ax = emu_si;
	emu_negw(&emu_ax, emu_ax);
	goto l__00AD;
l__00AB:
	emu_ax = emu_si;
	goto l__00AD;
l__00AD:
	emu_dx = 0xF;
	emu_subw(&emu_dx, emu_ax);
	emu_get_memory16(emu_ss, emu_bp, -0x2) = emu_dx;
	emu_orw(&emu_di, emu_di);
	if (!(emu_flags.sf != emu_flags.of)) goto l__00BF;
	emu_ax = emu_di;
	emu_negw(&emu_ax, emu_ax);
	goto l__00C1;
l__00BF:
	emu_ax = emu_di;
	goto l__00C1;
l__00C1:
	emu_dx = 0xA;
	emu_subw(&emu_dx, emu_ax);
	emu_get_memory16(emu_ss, emu_bp, -0x4) = emu_dx;
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp, -0x2), 0x1);
	if ((emu_flags.sf != emu_flags.of)) {
		emu_get_memory16(emu_ds, 0x00, 0x3A12) = 0x1;
	}
	goto l__00D5;
l__00D5:
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp, -0x4), 0x1);
	if ((emu_flags.sf != emu_flags.of)) {
		emu_get_memory16(emu_ds, 0x00, 0x3A12) = 0x1;
	}
	goto l__00E1;
l__00E1:
	emu_cmpw(&emu_get_memory16(emu_ds, 0x00, 0x3A12), 0x0);
	if (emu_flags.zf) goto l__00EB;
	goto l__0174;
l__00EB:
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp, -0x2), 0xF);
	if (!emu_flags.zf) goto l__00FA;
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp, -0x4), 0xA);
	if (!emu_flags.zf) goto l__00FA;
	goto l__0174;
l__00FA:
	emu_ax = 0xFFFF;
	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x0103); emu_cs = 0x0F78; f__0F78_01B4_0016_23DD();
	goto l__0103;
l__0103:
	emu_pop(&emu_cx);
	emu_get_memory16(emu_ss, emu_bp, -0x10) = 0x1;
	emu_ax = 0x2;
	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x0112); emu_cs = 0x2642; f__2642_0002_005E_87F6();
	goto l__0112;
l__0112:
	emu_pop(&emu_cx);
	emu_ax = 0x2;
	emu_push(emu_ax);
	emu_xorw(&emu_ax, emu_ax);
	emu_push(emu_ax);
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x4);
	emu_cl = 0x4;
	emu_shlw(&emu_ax, emu_cl);
	emu_push(emu_ax);
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x2);
	emu_shlw(&emu_ax, 0x1);
	emu_push(emu_ax);
	emu_orw(&emu_di, emu_di);
	if (!(emu_flags.sf != emu_flags.of)) goto l__0130;
	emu_xorw(&emu_ax, emu_ax);
	goto l__0136;
l__0130:
	emu_ax = emu_di;
	emu_cl = 0x4;
	emu_shlw(&emu_ax, emu_cl);
	goto l__0136;
l__0136:
	emu_addw(&emu_ax, 0x28);
	emu_push(emu_ax);
	emu_orw(&emu_si, emu_si);
	if (!(emu_flags.sf != emu_flags.of)) goto l__0142;
	emu_xorw(&emu_ax, emu_ax);
	goto l__0146;
l__0142:
	emu_ax = emu_si;
	emu_shlw(&emu_ax, 0x1);
	goto l__0146;
l__0146:
	emu_push(emu_ax);
	emu_orw(&emu_di, emu_di);
	if (!(emu_flags.sf != emu_flags.of)) goto l__0155;
	emu_ax = emu_di;
	emu_negw(&emu_ax, emu_ax);
	emu_cl = 0x4;
	emu_shlw(&emu_ax, emu_cl);
	goto l__0157;
l__0155:
	emu_xorw(&emu_ax, emu_ax);
	goto l__0157;
l__0157:
	emu_addw(&emu_ax, 0x28);
	emu_push(emu_ax);
	emu_orw(&emu_si, emu_si);
	if (!(emu_flags.sf != emu_flags.of)) goto l__0167;
	emu_ax = emu_si;
	emu_negw(&emu_ax, emu_ax);
	emu_shlw(&emu_ax, 0x1);
	goto l__0169;
l__0167:
	emu_xorw(&emu_ax, emu_ax);
	goto l__0169;
l__0169:
	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x016F); emu_cs = 0x24D0; f__24D0_000D_0039_C17D();
	goto l__016F;
l__016F:
	emu_addw(&emu_sp, 0x10);
	goto l__017A;
l__0174:
	emu_get_memory16(emu_ds, 0x00, 0x3A12) = 0x1;
	goto l__017A;
l__017A:
	emu_orw(&emu_si, emu_si);
	if ((emu_flags.sf != emu_flags.of)) {
		emu_xorw(&emu_si, emu_si);
	}
	goto l__0180;
l__0180:
	emu_orw(&emu_di, emu_di);
	if ((emu_flags.sf != emu_flags.of)) {
		emu_xorw(&emu_di, emu_di);
	}
	goto l__0186;
l__0186:
	emu_get_memory16(emu_ss, emu_bp, -0x8) = 0x0;
	goto l__01F0;
l__018D:
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x8);
	emu_addw(&emu_ax, emu_get_memory16(emu_ss, emu_bp, -0xE));
	emu_cl = 0x6;
	emu_shlw(&emu_ax, emu_cl);
	emu_get_memory16(emu_ss, emu_bp, -0xA) = emu_ax;
	emu_get_memory16(emu_ss, emu_bp, -0x6) = 0x0;
	goto l__01E7;
l__01A1:
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp, -0x6), emu_si);
	if (!(emu_flags.sf != emu_flags.of)) {
		emu_ax = emu_si;
		emu_addw(&emu_ax, emu_get_memory16(emu_ss, emu_bp, -0x2));
		emu_cmpw(&emu_ax, emu_get_memory16(emu_ss, emu_bp, -0x6));
		if (!(emu_flags.zf || emu_flags.sf != emu_flags.of)) {
			emu_cmpw(&emu_get_memory16(emu_ss, emu_bp, -0x8), emu_di);
			if (!(emu_flags.sf != emu_flags.of)) {
				emu_ax = emu_di;
				emu_addw(&emu_ax, emu_get_memory16(emu_ss, emu_bp, -0x4));
				emu_cmpw(&emu_ax, emu_get_memory16(emu_ss, emu_bp, -0x8));
				if (!(emu_flags.zf || emu_flags.sf != emu_flags.of)) {
					emu_cmpw(&emu_get_memory16(emu_ds, 0x00, 0x3A12), 0x0);
					if (emu_flags.zf) goto l__01E4;
				}
			}
		}
	}
	goto l__01C6;
l__01C6:
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x6);
	emu_addw(&emu_ax, emu_get_memory16(emu_ss, emu_bp, -0xC));
	emu_addw(&emu_ax, emu_get_memory16(emu_ss, emu_bp, -0xA));
	emu_get_memory16(emu_ss, emu_bp, -0x16) = emu_ax;
	emu_ax = 0x1;
	emu_push(emu_ax);
	emu_xorw(&emu_ax, emu_ax);
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x16));
	emu_push(emu_cs); emu_push(0x01E1); emu_cs = 0x34CD; ovl__34CD(29);
	goto l__01E1;
l__01E1:
	emu_addw(&emu_sp, 0x6);
	goto l__01E4;
l__01E4:
	emu_incw(&emu_get_memory16(emu_ss, emu_bp, -0x6));
	goto l__01E7;
l__01E7:
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp, -0x6), 0xF);
	if ((emu_flags.sf != emu_flags.of)) goto l__01A1;
	emu_incw(&emu_get_memory16(emu_ss, emu_bp, -0x8));
	goto l__01F0;
l__01F0:
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp, -0x8), 0xA);
	if ((emu_flags.sf != emu_flags.of)) goto l__018D;
	goto l__01F6;
l__01F6:
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp, -0x10), 0x0);
	if (emu_flags.zf) goto l__024B;
	emu_ax = 0xFFFF;
	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x0205); emu_cs = 0x0F78; f__0F78_01B4_0016_23DD();
	goto l__0205;
l__0205:
	emu_pop(&emu_cx);
	emu_get_memory16(emu_ss, emu_bp, -0x14) = 0x0;
	goto l__0245;
l__020D:
	emu_ax = emu_get_memory16(emu_ds, 0x00, 0x39FC);
	emu_addw(&emu_ax, emu_get_memory16(emu_ss, emu_bp, -0x14));
	emu_addw(&emu_ax, 0x180);
	emu_dx = emu_ax;
	emu_bx = emu_dx;
	emu_cl = 0x3;
	emu_sarw(&emu_bx, emu_cl);
	emu_cl = emu_dl;
	emu_andb(&emu_cl, 0x7);
	emu_al = 0x1;
	emu_shlb(&emu_al, emu_cl);
	emu_orb(&emu_get_memory8(emu_ds, emu_bx, 0x8FE5), emu_al);
	emu_bx = emu_dx;
	emu_cl = 0x3;
	emu_sarw(&emu_bx, emu_cl);
	emu_cl = emu_dl;
	emu_andb(&emu_cl, 0x7);
	emu_al = 0x1;
	emu_shlb(&emu_al, emu_cl);
	emu_orb(&emu_get_memory8(emu_ds, emu_bx, 0x8DE5), emu_al);
	emu_incw(&emu_get_memory16(emu_ds, 0x00, 0x39E2));
	emu_incw(&emu_get_memory16(emu_ss, emu_bp, -0x14));
	goto l__0245;
l__0245:
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp, -0x14), 0xE);
	if ((emu_flags.sf != emu_flags.of)) goto l__020D;
	goto l__024B;
l__024B:
	emu_ax = emu_get_memory16(emu_ds, 0x00, 0x39FE);
	emu_get_memory16(emu_ds, 0x00, 0x39FC) = emu_ax;
	emu_ax = emu_get_memory16(emu_ds, 0x00, 0x3A02);
	emu_get_memory16(emu_ds, 0x00, 0x3A00) = emu_ax;
	emu_cmpw(&emu_get_memory16(emu_ds, 0x00, 0x37BA), 0x0);
	if (emu_flags.zf) goto l__02B4;
	emu_ax = emu_get_memory16(emu_ds, 0x00, 0x3348);
	emu_dx = emu_get_memory16(emu_ds, 0x00, 0x3346);
	emu_cmpw(&emu_ax, emu_get_memory16(emu_ds, 0x00, 0x76AE));
	if (!(emu_flags.zf || emu_flags.sf != emu_flags.of)) goto l__02B4;
	if (!(emu_flags.sf != emu_flags.of)) {
		emu_cmpw(&emu_dx, emu_get_memory16(emu_ds, 0x00, 0x76AC));
		if (!emu_flags.cf) goto l__02B4;
	}
	goto l__0273;
l__0273:
	emu_decw(&emu_get_memory16(emu_ds, 0x00, 0x37BA));
	emu_ax = emu_get_memory16(emu_ds, 0x00, 0x76AE);
	emu_dx = emu_get_memory16(emu_ds, 0x00, 0x76AC);
	emu_addw(&emu_dx, 0x3C);
	emu_adcw(&emu_ax, 0x0);
	emu_get_memory16(emu_ds, 0x00, 0x3348) = emu_ax;
	emu_get_memory16(emu_ds, 0x00, 0x3346) = emu_dx;
	emu_get_memory16(emu_ss, emu_bp, -0x14) = 0x0;
	goto l__02AE;
l__0292:
	emu_ax = 0x1;
	emu_push(emu_ax);
	emu_xorw(&emu_ax, emu_ax);
	emu_push(emu_ax);
	emu_ax = emu_get_memory16(emu_ds, 0x00, 0x39FE);
	emu_addw(&emu_ax, emu_get_memory16(emu_ss, emu_bp, -0x14));
	emu_addw(&emu_ax, 0x180);
	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x02A8); emu_cs = 0x34CD; ovl__34CD(29);
	goto l__02A8;
l__02A8:
	emu_addw(&emu_sp, 0x6);
	emu_incw(&emu_get_memory16(emu_ss, emu_bp, -0x14));
	goto l__02AE;
l__02AE:
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp, -0x14), 0xE);
	if ((emu_flags.sf != emu_flags.of)) goto l__0292;
	goto l__02B4;
l__02B4:
	emu_push(emu_get_memory16(emu_ss, emu_bp,  0x6));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x10));
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x3A12));
	emu_push(emu_cs);
	emu_push(0x02C2); f__07D4_034D_001F_FF64();
	goto l__02C2;
l__02C2:
	emu_addw(&emu_sp, 0x6);
	emu_get_memory16(emu_ds, 0x00, 0x3A12) = 0x0;
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x12));
	emu_push(emu_cs); emu_push(0x02D4); emu_cs = 0x2598; f__2598_0000_0017_EB80();
	goto l__02D4;
l__02D4:
	emu_pop(&emu_cx);
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x3A00));
	emu_push(emu_cs); emu_push(0x02DE); emu_cs = 0x0F78; f__0F78_01B4_0016_23DD();
	goto l__02DE;
l__02DE:
	emu_pop(&emu_cx);
	emu_xorw(&emu_ax, emu_ax);
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x39FC));
	emu_push(emu_cs); emu_push(0x02EB); emu_cs = 0x0F78; f__0F78_0008_002C_AB63();
	goto l__02EB;
l__02EB:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	emu_push(emu_cs); emu_push(0x02F2); emu_cs = 0x2642; f__2642_0069_0008_D517();
	goto l__02F2;
l__02F2:
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
 * Decompiled function f__07D4_02F8_0055_0679()
 *
 * @name f__07D4_02F8_0055_0679
 * @implements 07D4:02F8:0055:0679 ()
 * @implements 07D4:031D:0030:7365
 * @implements 07D4:034B:0002:2597
 *
 * Called From: 151A:06AA:0009:9B66
 * Called From: B4CD:0477:0006:DF2B
 * Called From: B4CD:0477:0028:B587
 * Called From: B4CD:0477:0039:8ACB
 * Called From: B4CD:04AC:0009:86D1
 * Called From: B4CD:12FF:0017:38A6
 */
void f__07D4_02F8_0055_0679()
{
l__02F8:
	emu_push(emu_bp);
	emu_bp = emu_sp;
	emu_bx = emu_get_memory16(emu_ss, emu_bp,  0x6);
	emu_cl = 0x3;
	emu_sarw(&emu_bx, emu_cl);
	emu_al = emu_get_memory8(emu_ds, emu_bx, 0x93E5);
	emu_ah = 0x0;
	emu_cl = emu_get_memory8(emu_ss, emu_bp,  0x6);
	emu_andb(&emu_cl, 0x7);
	emu_dx = 0x1;
	emu_shlw(&emu_dx, emu_cl);
	emu_testw(&emu_ax, emu_dx);
	if (!emu_flags.zf) {
		emu_ax = emu_get_memory16(emu_ds, 0x00, 0x8D09);
		emu_incw(&emu_ax);
		if (emu_flags.zf) goto l__034B;
	}
	goto l__031D;
l__031D:
	emu_bx = emu_get_memory16(emu_ss, emu_bp,  0x6);
	emu_cl = 0x3;
	emu_sarw(&emu_bx, emu_cl);
	emu_cl = emu_get_memory8(emu_ss, emu_bp,  0x6);
	emu_andb(&emu_cl, 0x7);
	emu_al = 0x1;
	emu_shlb(&emu_al, emu_cl);
	emu_orb(&emu_get_memory8(emu_ds, emu_bx, 0x91E5), emu_al);
	emu_cmpw(&emu_get_memory16(emu_ds, 0x00, 0x3344), 0xC8);
	if ((emu_flags.sf != emu_flags.of)) {
		emu_bx = emu_get_memory16(emu_ds, 0x00, 0x3344);
		emu_shlw(&emu_bx, 0x1);
		emu_ax = emu_get_memory16(emu_ss, emu_bp,  0x6);
		emu_get_memory16(emu_ds, emu_bx, 0x8290) = emu_ax;
		emu_incw(&emu_get_memory16(emu_ds, 0x00, 0x3344));
	}
	goto l__034B;
l__034B:
	emu_pop(&emu_bp);

	/* Return from this function */
	emu_pop(&emu_ip);
	emu_pop(&emu_cs);
	return;
}

/**
 * Decompiled function f__07D4_034D_001F_FF64()
 *
 * @name f__07D4_034D_001F_FF64
 * @implements 07D4:034D:001F:FF64 ()
 * @implements 07D4:036C:0014:D20F
 * @implements 07D4:0380:000C:DE03
 * @implements 07D4:038C:000D:FEBC
 * @implements 07D4:0399:001A:BD55
 * @implements 07D4:03B3:0008:6BAE
 * @implements 07D4:03BB:0015:EAC6
 * @implements 07D4:03D0:00A9:21D8
 * @implements 07D4:042D:004C:FB93
 * @implements 07D4:044F:002A:46DC
 * @implements 07D4:0454:0025:993D
 * @implements 07D4:0479:00CB:2318
 * @implements 07D4:04BB:0089:9A1B
 * @implements 07D4:04DD:0067:E7F1
 * @implements 07D4:0544:0005:A9EE
 * @implements 07D4:0549:0031:9C05
 * @implements 07D4:057A:0025:B028
 * @implements 07D4:059F:0011:D2DF
 * @implements 07D4:05A2:000E:839B
 * @implements 07D4:05A5:000B:BF85
 * @implements 07D4:05B0:000D:659A
 * @implements 07D4:05B2:000B:F19B
 * @implements 07D4:05BD:000C:F735
 * @implements 07D4:05C0:0009:07CD
 * @implements 07D4:05C9:0008:86FD
 * @implements 07D4:05CF:0002:C83A
 * @implements 07D4:05E1:0012:E89D
 * @implements 07D4:05F3:0006:97B3
 * @implements 07D4:05F9:0014:253E
 * @implements 07D4:060D:0019:1306
 * @implements 07D4:0626:0023:48A1
 * @implements 07D4:0649:0023:9900
 * @implements 07D4:066C:000E:965C
 * @implements 07D4:067A:0028:4EFB
 * @implements 07D4:06A2:0028:D31F
 * @implements 07D4:06CA:001C:B1AC
 * @implements 07D4:06CD:0019:3A04
 * @implements 07D4:06E6:0028:D31F
 * @implements 07D4:070E:001C:B1A3
 * @implements 07D4:0711:0019:3A0B
 * @implements 07D4:072A:0028:D31F
 * @implements 07D4:0752:002E:5463
 * @implements 07D4:0755:002B:7689
 * @implements 07D4:0780:002E:9990
 * @implements 07D4:07AE:000D:6567
 * @implements 07D4:07B1:000A:B122
 * @implements 07D4:07BB:0013:9BDC
 * @implements 07D4:07BD:0011:D0EA
 * @implements 07D4:07CE:0012:F55E
 * @implements 07D4:07E0:0010:9EB6
 * @implements 07D4:07F0:0009:6097
 * @implements 07D4:07F9:0016:2EE4
 * @implements 07D4:080F:0009:BD42
 * @implements 07D4:0818:000B:84B1
 * @implements 07D4:0823:0013:FB83
 * @implements 07D4:0836:000B:F4B0
 * @implements 07D4:0841:0044:AA4E
 * @implements 07D4:0885:0014:5D4C
 * @implements 07D4:0899:0027:372D
 * @implements 07D4:08C0:0019:9BB9
 * @implements 07D4:08D9:001B:4B47
 * @implements 07D4:08DC:0018:1A52
 * @implements 07D4:08F4:001F:DD19
 * @implements 07D4:08FD:0016:5665
 * @implements 07D4:0913:0012:9B62
 * @implements 07D4:0925:0006:158A
 * @implements 07D4:092B:000C:84EC
 * @implements 07D4:0937:000C:4048
 * @implements 07D4:0943:0025:DC26
 * @implements 07D4:0968:001F:FE51
 * @implements 07D4:0987:0013:AC94
 * @implements 07D4:099A:0019:1306
 * @implements 07D4:09B3:0023:8A21
 * @implements 07D4:09D6:0031:066B
 * @implements 07D4:0A07:000B:C026
 * @implements 07D4:0A12:0045:4F52
 * @implements 07D4:0A57:001A:90D6
 * @implements 07D4:0A71:0015:14BA
 * @implements 07D4:0A87:0007:629A
 * @implements 07D4:0A8E:000C:2053
 * @implements 07D4:0A9B:0016:C9F0
 * @implements 07D4:0AB1:0025:DD85
 * @implements 07D4:0AD6:002C:03ED
 * @implements 07D4:0AF1:0011:EBB7
 * @implements 07D4:0AFD:0005:E18C
 * @implements 07D4:0B0C:0002:CE3A
 * @implements 07D4:0B0E:002B:9058
 * @implements 07D4:0B2A:000F:1371
 * @implements 07D4:0B39:000B:451F
 * @implements 07D4:0B44:0008:A09F
 * @implements 07D4:0B46:0006:F92D
 * @implements 07D4:0B4C:0066:F087
 * @implements 07D4:0B70:0042:98CD
 * @implements 07D4:0B81:0031:A814
 * @implements 07D4:0BB2:0010:7568
 * @implements 07D4:0BC2:000D:690C
 * @implements 07D4:0BCF:000D:3D03
 * @implements 07D4:0BDC:0017:79D0
 * @implements 07D4:0BF3:0008:710A
 * @implements 07D4:0BFB:000E:2753
 * @implements 07D4:0C09:0030:DC22
 * @implements 07D4:0C39:0008:E01C
 * @implements 07D4:0C41:0046:7ED9
 * @implements 07D4:0C87:0005:84EE
 * @implements 07D4:0C8C:0002:C03A
 * @implements 07D4:0C8E:000D:7DAB
 * @implements 07D4:0C9B:000D:C1BA
 * @implements 07D4:0CA8:002D:48A6
 * @implements 07D4:0CDC:0008:5AE5
 * @implements 07D4:0CE4:001B:A044
 * @implements 07D4:0CF0:000F:4EEF
 * @implements 07D4:0D49:0002:C03A
 * @implements 07D4:0D4B:0022:8E55
 * @implements 07D4:0D6D:0008:E391
 * @implements 07D4:0D75:0036:17D1
 * @implements 07D4:0DAB:0058:68F9
 * @implements 07D4:0DAE:0055:A271
 * @implements 07D4:0DD2:0031:A9D0
 * @implements 07D4:0E03:003B:26C8
 * @implements 07D4:0E06:0038:77DF
 * @implements 07D4:0E3E:000D:6567
 * @implements 07D4:0E41:000A:B122
 * @implements 07D4:0E4B:0013:19E5
 * @implements 07D4:0E4D:0011:52D3
 * @implements 07D4:0E5E:000E:0F59
 * @implements 07D4:0E64:0008:1222
 * @implements 07D4:0E6C:0028:D70C
 * @implements 07D4:0E94:001F:9139
 * @implements 07D4:0EB3:0028:1884
 * @implements 07D4:0ECB:0010:F9C8
 * @implements 07D4:0EDB:0013:61EC
 * @implements 07D4:0EEE:000D:FD8F
 * @implements 07D4:0EFB:0018:85E3
 * @implements 07D4:0F13:0039:35C0
 * @implements 07D4:0F33:0019:6454
 * @implements 07D4:0F4C:0023:CCB8
 * @implements 07D4:0F6F:002B:0C2A
 * @implements 07D4:0F9A:000F:8834
 * @implements 07D4:0F9D:000C:1D25
 * @implements 07D4:0FA0:0009:EE5D
 * @implements 07D4:0FA9:0016:F5D8
 * @implements 07D4:0FBF:0012:9B62
 * @implements 07D4:0FD1:0006:D61F
 * @implements 07D4:0FD7:000C:2B61
 * @implements 07D4:0FE3:0025:DC26
 * @implements 07D4:1008:001F:FE51
 * @implements 07D4:1027:0013:EFBC
 * @implements 07D4:103A:0019:1306
 * @implements 07D4:1053:0023:C889
 * @implements 07D4:1076:0031:05C3
 * @implements 07D4:10A7:000B:828E
 * @implements 07D4:10B2:002C:ED43
 * @implements 07D4:10DE:0007:62A3
 * @implements 07D4:10E5:000F:A7CE
 * @implements 07D4:10F1:0003:DD00
 * @implements 07D4:10F4:0006:F2E5
 * @implements 07D4:10FA:0015:B78B
 * @implements 07D4:110F:0006:C2E7
 * @implements 07D4:1115:001F:2FB5
 * @implements 07D4:1161:0010:4321
 * @implements 07D4:116B:0006:C6A4
 * @implements 07D4:1177:003C:1BA2
 * @implements 07D4:1190:0023:84F1
 * @implements 07D4:11A8:000B:451F
 * @implements 07D4:11B3:0008:6583
 * @implements 07D4:11BB:0049:B9BB
 * @implements 07D4:1204:0039:E0C5
 * @implements 07D4:1207:0036:A4AC
 * @implements 07D4:1218:0025:37A1
 * @implements 07D4:123D:000D:E564
 * @implements 07D4:1240:000A:B122
 * @implements 07D4:124A:0013:DA48
 * @implements 07D4:124C:0011:917E
 * @implements 07D4:125D:001D:1903
 * @implements 07D4:1263:0017:2F38
 * @implements 07D4:127A:0014:F74B
 * @implements 07D4:128E:000D:1EF9
 * @implements 07D4:1291:000A:0ABC
 * @implements 07D4:129B:0010:0725
 * @implements 07D4:12AB:0033:D6E7
 * @implements 07D4:12DE:000D:CD87
 * @implements 07D4:12EB:0008:FBF3
 * @implements 07D4:12EC:0007:A2F3
 * @implements 07D4:12F3:0033:2621
 * @implements 07D4:1318:000E:355E
 * @implements 07D4:131B:000B:0980
 * @implements 07D4:1326:0011:E99F
 * @implements 07D4:1337:002A:03E1
 * @implements 07D4:1339:0028:958D
 * @implements 07D4:1361:000B:2081
 * @implements 07D4:136C:0006:63C7
 * @implements 07D4:1372:0015:D44C
 * @implements 07D4:1387:0037:4BAC
 * @implements 07D4:13BE:000C:1881
 * @implements 07D4:13C1:0009:EBF9
 * @implements 07D4:13C8:0002:C33A
 * @implements 07D4:13CA:004F:072B
 * @implements 07D4:13D0:0049:AA00
 * @implements 07D4:13F9:0020:16B6
 * @implements 07D4:1419:0016:80CC
 * @implements 07D4:1426:0009:919E
 * @implements 07D4:142F:0009:D05C
 * @implements 07D4:1438:0010:9618
 * @implements 07D4:1448:0025:2165
 * @implements 07D4:146D:0008:C54E
 * @implements 07D4:1475:0009:F35C
 * @implements 07D4:147E:000A:9E24
 * @implements 07D4:1488:0042:D8CF
 * @implements 07D4:14AC:001E:5C2A
 * @implements 07D4:14CB:0051:4C81
 * @implements 07D4:151C:0028:94C8
 * @implements 07D4:1526:001E:A3D1
 * @implements 07D4:1544:000F:B089
 * @implements 07D4:1547:000C:3598
 * @implements 07D4:154A:0009:C6E0
 * @implements 07D4:1553:0009:652B
 * @implements 07D4:155C:0008:5999
 * @implements 07D4:1564:0009:50B8
 * @implements 07D4:156D:0007:F77C
 *
 * Called From: 07D4:02BF:000E:C5E6
 * Called From: 07D4:02BF:001A:7955
 */
void f__07D4_034D_001F_FF64()
{
l__034D:
	emu_push(emu_bp);
	emu_bp = emu_sp;
	emu_subw(&emu_sp, 0x56);
	emu_push(emu_si);
	emu_push(emu_di);
	emu_get_memory16(emu_ss, emu_bp, -0x12) = 0x0;
	emu_ax = 0x14;
	emu_push(emu_ax);
	emu_ax = 0xF;
	emu_push(emu_ax);
	emu_push(emu_ss);
	emu_movw(&emu_ax, emu_bp - 0x42);
	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x036C); emu_cs = 0x01F7; emu_Tools_Memset();
	goto l__036C;
l__036C:
	emu_addw(&emu_sp, 0x8);
	emu_ax = 0x14;
	emu_push(emu_ax);
	emu_xorw(&emu_ax, emu_ax);
	emu_push(emu_ax);
	emu_push(emu_ss);
	emu_movw(&emu_ax, emu_bp - 0x56);
	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x0380); emu_cs = 0x01F7; emu_Tools_Memset();
	goto l__0380;
l__0380:
	emu_addw(&emu_sp, 0x8);
	emu_ax = 0x2;
	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x038C); emu_cs = 0x2598; f__2598_0000_0017_EB80();
	goto l__038C;
l__038C:
	emu_pop(&emu_cx);
	emu_get_memory16(emu_ss, emu_bp, -0x14) = emu_ax;
	emu_ax = 0x2;
	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x0399); emu_cs = 0x07AE; f__07AE_0000_00DF_A32C();
	goto l__0399;
l__0399:
	emu_pop(&emu_cx);
	emu_get_memory16(emu_ss, emu_bp, -0x16) = emu_ax;
	emu_ax = emu_get_memory16(emu_ss, emu_bp,  0x6);
	emu_get_memory16(emu_ss, emu_bp, -0x12) = emu_ax;
	emu_cmpw(&emu_get_memory16(emu_ds, 0x00, 0x39E2), 0x0);
	if (!emu_flags.zf) goto l__03B3;
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp,  0x6), 0x0);
	if (!emu_flags.zf) goto l__03B3;
	goto l__05CF;
l__03B3:
	emu_get_memory16(emu_ss, emu_bp, -0x4) = 0x0;
	goto l__05C0;
l__03BB:
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x4);
	emu_cl = 0x4;
	emu_shlw(&emu_ax, emu_cl);
	emu_addw(&emu_ax, 0x28);
	emu_get_memory16(emu_ss, emu_bp, -0xC) = emu_ax;
	emu_get_memory16(emu_ss, emu_bp, -0x2) = 0x0;
	goto l__05A5;
l__03D0:
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x4);
	emu_cl = 0x6;
	emu_shlw(&emu_ax, emu_cl);
	emu_dx = emu_get_memory16(emu_ds, 0x00, 0x39FE);
	emu_addw(&emu_dx, emu_ax);
	emu_addw(&emu_dx, emu_get_memory16(emu_ss, emu_bp, -0x2));
	emu_get_memory16(emu_ss, emu_bp, -0x10) = emu_dx;
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp, -0x2), 0xF);
	if (!(emu_flags.sf != emu_flags.of)) goto l__0454;
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp,  0x6), 0x0);
	if (!emu_flags.zf) goto l__0454;
	emu_bx = emu_get_memory16(emu_ss, emu_bp, -0x10);
	emu_cl = 0x3;
	emu_sarw(&emu_bx, emu_cl);
	emu_al = emu_get_memory8(emu_ds, emu_bx, 0x8FE5);
	emu_ah = 0x0;
	emu_cl = emu_get_memory8(emu_ss, emu_bp, -0x10);
	emu_andb(&emu_cl, 0x7);
	emu_dx = 0x1;
	emu_shlw(&emu_dx, emu_cl);
	emu_testw(&emu_ax, emu_dx);
	if (emu_flags.zf) goto l__0454;
	emu_bx = emu_get_memory16(emu_ss, emu_bp, -0x4);
	emu_shlw(&emu_bx, 0x1);
	emu_movw(&emu_ax, emu_bp - 0x56);
	emu_addw(&emu_bx, emu_ax);
	emu_ax = emu_get_memory16(emu_ss, emu_bx, 0x0);
	emu_cmpw(&emu_ax, emu_get_memory16(emu_ss, emu_bp, -0x2));
	if ((emu_flags.sf != emu_flags.of)) {
		emu_bx = emu_get_memory16(emu_ss, emu_bp, -0x4);
		emu_shlw(&emu_bx, 0x1);
		emu_movw(&emu_ax, emu_bp - 0x56);
		emu_addw(&emu_bx, emu_ax);
		emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x2);
		emu_get_memory16(emu_ss, emu_bx, 0x0) = emu_ax;
	}
	goto l__042D;
l__042D:
	emu_bx = emu_get_memory16(emu_ss, emu_bp, -0x4);
	emu_shlw(&emu_bx, 0x1);
	emu_movw(&emu_ax, emu_bp - 0x42);
	emu_addw(&emu_bx, emu_ax);
	emu_ax = emu_get_memory16(emu_ss, emu_bx, 0x0);
	emu_cmpw(&emu_ax, emu_get_memory16(emu_ss, emu_bp, -0x2));
	if (!(emu_flags.zf || emu_flags.sf != emu_flags.of)) {
		emu_bx = emu_get_memory16(emu_ss, emu_bp, -0x4);
		emu_shlw(&emu_bx, 0x1);
		emu_movw(&emu_ax, emu_bp - 0x42);
		emu_addw(&emu_bx, emu_ax);
		emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x2);
		emu_get_memory16(emu_ss, emu_bx, 0x0) = emu_ax;
	}
	goto l__044F;
l__044F:
	emu_get_memory16(emu_ss, emu_bp, -0x12) = 0x1;
	goto l__0454;
l__0454:
	emu_bx = emu_get_memory16(emu_ss, emu_bp, -0x10);
	emu_cl = 0x3;
	emu_sarw(&emu_bx, emu_cl);
	emu_al = emu_get_memory8(emu_ds, emu_bx, 0x8DE5);
	emu_ah = 0x0;
	emu_cl = emu_get_memory8(emu_ss, emu_bp, -0x10);
	emu_andb(&emu_cl, 0x7);
	emu_dx = 0x1;
	emu_shlw(&emu_dx, emu_cl);
	emu_testw(&emu_ax, emu_dx);
	if (!emu_flags.zf) goto l__0479;
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp,  0x6), 0x0);
	if (!emu_flags.zf) goto l__0479;
	goto l__05A2;
l__0479:
	emu_bx = emu_get_memory16(emu_ss, emu_bp, -0x10);
	emu_cl = 0x3;
	emu_sarw(&emu_bx, emu_cl);
	emu_cl = emu_get_memory8(emu_ss, emu_bp, -0x10);
	emu_andb(&emu_cl, 0x7);
	emu_al = 0x1;
	emu_shlb(&emu_al, emu_cl);
	emu_orb(&emu_get_memory8(emu_ds, emu_bx, 0x8FE5), emu_al);
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp, -0x2), 0xF);
	if (!(emu_flags.sf != emu_flags.of)) goto l__04DD;
	emu_get_memory16(emu_ss, emu_bp, -0x12) = 0x1;
	emu_bx = emu_get_memory16(emu_ss, emu_bp, -0x4);
	emu_shlw(&emu_bx, 0x1);
	emu_movw(&emu_ax, emu_bp - 0x56);
	emu_addw(&emu_bx, emu_ax);
	emu_ax = emu_get_memory16(emu_ss, emu_bx, 0x0);
	emu_cmpw(&emu_ax, emu_get_memory16(emu_ss, emu_bp, -0x2));
	if ((emu_flags.sf != emu_flags.of)) {
		emu_bx = emu_get_memory16(emu_ss, emu_bp, -0x4);
		emu_shlw(&emu_bx, 0x1);
		emu_movw(&emu_ax, emu_bp - 0x56);
		emu_addw(&emu_bx, emu_ax);
		emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x2);
		emu_get_memory16(emu_ss, emu_bx, 0x0) = emu_ax;
	}
	goto l__04BB;
l__04BB:
	emu_bx = emu_get_memory16(emu_ss, emu_bp, -0x4);
	emu_shlw(&emu_bx, 0x1);
	emu_movw(&emu_ax, emu_bp - 0x42);
	emu_addw(&emu_bx, emu_ax);
	emu_ax = emu_get_memory16(emu_ss, emu_bx, 0x0);
	emu_cmpw(&emu_ax, emu_get_memory16(emu_ss, emu_bp, -0x2));
	if (!(emu_flags.zf || emu_flags.sf != emu_flags.of)) {
		emu_bx = emu_get_memory16(emu_ss, emu_bp, -0x4);
		emu_shlw(&emu_bx, 0x1);
		emu_movw(&emu_ax, emu_bp - 0x42);
		emu_addw(&emu_bx, emu_ax);
		emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x2);
		emu_get_memory16(emu_ss, emu_bx, 0x0) = emu_ax;
	}
	goto l__04DD;
l__04DD:
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x2);
	emu_cl = 0x4;
	emu_shlw(&emu_ax, emu_cl);
	emu_get_memory16(emu_ss, emu_bp, -0xA) = emu_ax;
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x10);
	emu_cl = 0x2;
	emu_shlw(&emu_ax, emu_cl);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ds, 0x00, 0x39EA));
	emu_addw(&emu_bx, emu_ax);
	emu_al = emu_get_memory8(emu_es, emu_bx, 0x1);
	emu_shrw(&emu_ax, 0x1);
	emu_andw(&emu_ax, 0x7F);
	emu_si = emu_ax;
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x10);
	emu_cl = 0x2;
	emu_shlw(&emu_ax, emu_cl);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ds, 0x00, 0x39EA));
	emu_addw(&emu_bx, emu_ax);
	emu_ax = emu_get_memory16(emu_es, emu_bx, 0x0);
	emu_andw(&emu_ax, 0x1FF);
	emu_get_memory16(emu_ss, emu_bp, -0x1A) = emu_ax;
	emu_cmpw(&emu_get_memory16(emu_ds, 0x00, 0x37A0), 0x0);
	if (!emu_flags.zf) goto l__0549;
	emu_cmpw(&emu_get_memory16(emu_ds, 0x00, 0x39F2), emu_si);
	if (!emu_flags.zf) goto l__0549;
	emu_ax = 0xC;
	emu_push(emu_ax);
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0xC);
	emu_addw(&emu_ax, 0xF);
	emu_push(emu_ax);
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0xA);
	emu_addw(&emu_ax, 0xF);
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0xC));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0xA));
	emu_ax = 0x353F;
	emu_es = emu_ax;

	/* Call based on memory/register values */
	emu_ip = emu_get_memory16(emu_es, 0x00, 0x6668);
	emu_push(emu_cs);
	emu_cs = emu_get_memory16(emu_es, 0x00, 0x666A);
	emu_push(0x0544);
	switch ((emu_cs << 16) + emu_ip) {
		case 0x22A60D31: f__22A6_0D31_0015_A4C3(); break;
		default:
			/* In case we don't know the call point yet, call the dynamic call */
			emu_last_cs = 0x07D4; emu_last_ip = 0x053F; emu_last_length = 0x0067; emu_last_crc = 0xE7F1;
			emu_call();
			return;
	}
	goto l__0544;
l__0544:
	emu_addw(&emu_sp, 0xA);
	goto l__05A2;
l__0549:
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x10);
	emu_cl = 0x2;
	emu_shlw(&emu_ax, emu_cl);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ds, 0x00, 0x39EA));
	emu_addw(&emu_bx, emu_ax);
	emu_al = emu_get_memory8(emu_es, emu_bx, 0x2);
	emu_ah = 0x0;
	emu_andw(&emu_ax, 0x7);
	emu_di = emu_ax;
	emu_push(emu_di);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0xC));
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0xA);
	emu_cl = 0x3;
	emu_shrw(&emu_ax, emu_cl);
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x1A));
	emu_ax = 0x353F;
	emu_es = emu_ax;

	/* Call based on memory/register values */
	emu_ip = emu_get_memory16(emu_es, 0x00, 0x665C);
	emu_push(emu_cs);
	emu_cs = emu_get_memory16(emu_es, 0x00, 0x665E);
	emu_push(0x057A);
	switch ((emu_cs << 16) + emu_ip) {
		case 0x22A60B60: f__22A6_0B60_006A_2F61(); break;
		default:
			/* In case we don't know the call point yet, call the dynamic call */
			emu_last_cs = 0x07D4; emu_last_ip = 0x0575; emu_last_length = 0x0031; emu_last_crc = 0x9C05;
			emu_call();
			return;
	}
	goto l__057A;
l__057A:
	emu_addw(&emu_sp, 0x8);
	emu_orw(&emu_si, emu_si);
	if (emu_flags.zf) goto l__05A2;
	emu_cmpw(&emu_get_memory16(emu_ds, 0x00, 0x37A0), 0x0);
	if (!emu_flags.zf) goto l__05A2;
	emu_push(emu_di);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0xC));
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0xA);
	emu_cl = 0x3;
	emu_shrw(&emu_ax, emu_cl);
	emu_push(emu_ax);
	emu_push(emu_si);
	emu_ax = 0x353F;
	emu_es = emu_ax;

	/* Call based on memory/register values */
	emu_ip = emu_get_memory16(emu_es, 0x00, 0x665C);
	emu_push(emu_cs);
	emu_cs = emu_get_memory16(emu_es, 0x00, 0x665E);
	emu_push(0x059F);
	switch ((emu_cs << 16) + emu_ip) {
		case 0x22A60B60: f__22A6_0B60_006A_2F61(); break;
		default:
			/* In case we don't know the call point yet, call the dynamic call */
			emu_last_cs = 0x07D4; emu_last_ip = 0x059A; emu_last_length = 0x0025; emu_last_crc = 0xB028;
			emu_call();
			return;
	}
	goto l__059F;
l__059F:
	emu_addw(&emu_sp, 0x8);
	goto l__05A2;
l__05A2:
	emu_incw(&emu_get_memory16(emu_ss, emu_bp, -0x2));
	goto l__05A5;
l__05A5:
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp,  0xA), 0x0);
	if (!emu_flags.zf) goto l__05B0;
	emu_ax = 0x1;
	goto l__05B2;
l__05B0:
	emu_xorw(&emu_ax, emu_ax);
	goto l__05B2;
l__05B2:
	emu_addw(&emu_ax, 0xF);
	emu_cmpw(&emu_ax, emu_get_memory16(emu_ss, emu_bp, -0x2));
	if ((emu_flags.zf || emu_flags.sf != emu_flags.of)) goto l__05BD;
	goto l__03D0;
l__05BD:
	emu_incw(&emu_get_memory16(emu_ss, emu_bp, -0x4));
	goto l__05C0;
l__05C0:
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp, -0x4), 0xA);
	if (!(emu_flags.sf != emu_flags.of)) goto l__05C9;
	goto l__03BB;
l__05C9:
	emu_get_memory16(emu_ds, 0x00, 0x39E2) = 0x0;
	goto l__05CF;
l__05CF:
	goto l__05E1;
l__05E1:
	emu_ax = 0x19;
	emu_push(emu_ax);
	emu_ax = 0xFFFF;
	emu_push(emu_ax);
	emu_push(emu_ss);
	emu_movw(&emu_ax, emu_bp - 0x1E);
	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x05F3); emu_cs = 0x0FE4; emu_Unit_FindFirst();
	goto l__05F3;
l__05F3:
	emu_addw(&emu_sp, 0x8);
	goto l__07BD;
l__05F9:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_testw(&emu_get_memory16(emu_es, emu_bx, 0x4), 0x1000);
	if (!emu_flags.zf) goto l__060D;
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp,  0x6), 0x0);
	if (!emu_flags.zf) goto l__060D;
	goto l__07B1;
l__060D:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_andw(&emu_get_memory16(emu_es, emu_bx, 0x4), 0xEFFF);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0xC));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0xA));
	emu_push(emu_cs); emu_push(0x0626); emu_cs = 0x0F3F; f__0F3F_0086_0017_EA43();
	goto l__0626;
l__0626:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	emu_get_memory16(emu_ss, emu_bp, -0x10) = emu_ax;
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x10);
	emu_cl = 0x2;
	emu_shlw(&emu_ax, emu_cl);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ds, 0x00, 0x39EA));
	emu_addw(&emu_bx, emu_ax);
	emu_testb(&emu_get_memory8(emu_es, emu_bx, 0x2), 0x8);
	if (!emu_flags.zf) goto l__0649;
	emu_cmpw(&emu_get_memory16(emu_ds, 0x00, 0x37A0), 0x0);
	if (!emu_flags.zf) goto l__0649;
	goto l__07B1;
l__0649:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_al = emu_get_memory8(emu_es, emu_bx, 0x2);
	emu_ax = emu_al;
	emu_dx = 0x5A;
	emu_imuluw(&emu_ax, emu_dx);
	emu_addw(&emu_ax, 0x0);
	emu_get_memory16(emu_ss, emu_bp, -0x24) = 0x2D07;
	emu_get_memory16(emu_ss, emu_bp, -0x26) = emu_ax;
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x20));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_push(emu_cs); emu_push(0x066C); emu_cs = 0x1A34; emu_Unit_GetHouseID();
	goto l__066C;
l__066C:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	emu_push(emu_ax);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x26));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0x44));
	emu_push(emu_cs);
	emu_push(0x067A); f__07D4_18BD_0016_68BB();
	goto l__067A;
l__067A:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	emu_get_memory16(emu_ss, emu_bp, -0x28) = emu_dx;
	emu_get_memory16(emu_ss, emu_bp, -0x2A) = emu_ax;
	emu_get_memory16(emu_ds, 0x00, 0x8DE3) = 0x200;
	emu_push(emu_ss);
	emu_movw(&emu_ax, emu_bp - 0x4);
	emu_push(emu_ax);
	emu_push(emu_ss);
	emu_movw(&emu_ax, emu_bp - 0x2);
	emu_push(emu_ax);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0xC));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0xA));
	emu_push(emu_cs);
	emu_push(0x06A2); f__07D4_196B_0073_56C1();
	goto l__06A2;
l__06A2:
	emu_addw(&emu_sp, 0xC);
	emu_orw(&emu_ax, emu_ax);
	if (emu_flags.zf) goto l__06CD;
	emu_ax = emu_get_memory16(emu_ds, 0x00, 0x8DE3);
	emu_orw(&emu_ax, 0xC000);
	emu_push(emu_ax);
	emu_ax = 0x2;
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x4));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x2));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x28));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x2A));
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x6C91));
	emu_push(emu_cs); emu_push(0x06CA); emu_cs = 0x2903; f__2903_0158_001A_2931();
	goto l__06CA;
l__06CA:
	emu_addw(&emu_sp, 0xE);
	goto l__06CD;
l__06CD:
	emu_push(emu_ss);
	emu_movw(&emu_ax, emu_bp - 0x4);
	emu_push(emu_ax);
	emu_push(emu_ss);
	emu_movw(&emu_ax, emu_bp - 0x2);
	emu_push(emu_ax);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0x5C));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0x5A));
	emu_push(emu_cs);
	emu_push(0x06E6); f__07D4_196B_0073_56C1();
	goto l__06E6;
l__06E6:
	emu_addw(&emu_sp, 0xC);
	emu_orw(&emu_ax, emu_ax);
	if (emu_flags.zf) goto l__0711;
	emu_ax = emu_get_memory16(emu_ds, 0x00, 0x8DE3);
	emu_orw(&emu_ax, 0xC000);
	emu_push(emu_ax);
	emu_ax = 0x2;
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x4));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x2));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x28));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x2A));
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x6C91));
	emu_push(emu_cs); emu_push(0x070E); emu_cs = 0x2903; f__2903_0158_001A_2931();
	goto l__070E;
l__070E:
	emu_addw(&emu_sp, 0xE);
	goto l__0711;
l__0711:
	emu_push(emu_ss);
	emu_movw(&emu_ax, emu_bp - 0x4);
	emu_push(emu_ax);
	emu_push(emu_ss);
	emu_movw(&emu_ax, emu_bp - 0x2);
	emu_push(emu_ax);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0x60));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0x5E));
	emu_push(emu_cs);
	emu_push(0x072A); f__07D4_196B_0073_56C1();
	goto l__072A;
l__072A:
	emu_addw(&emu_sp, 0xC);
	emu_orw(&emu_ax, emu_ax);
	if (emu_flags.zf) goto l__0755;
	emu_ax = emu_get_memory16(emu_ds, 0x00, 0x8DE3);
	emu_orw(&emu_ax, 0xC000);
	emu_push(emu_ax);
	emu_ax = 0x2;
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x4));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x2));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x28));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x2A));
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x6C91));
	emu_push(emu_cs); emu_push(0x0752); emu_cs = 0x2903; f__2903_0158_001A_2931();
	goto l__0752;
l__0752:
	emu_addw(&emu_sp, 0xE);
	goto l__0755;
l__0755:
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x20);
	emu_dx = emu_get_memory16(emu_ss, emu_bp, -0x22);
	emu_cmpw(&emu_ax, emu_get_memory16(emu_ds, 0x00, 0x3A0C));
	if (!emu_flags.zf) goto l__07B1;
	emu_cmpw(&emu_dx, emu_get_memory16(emu_ds, 0x00, 0x3A0A));
	if (!emu_flags.zf) goto l__07B1;
	emu_push(emu_ss);
	emu_movw(&emu_ax, emu_bp - 0x4);
	emu_push(emu_ax);
	emu_push(emu_ss);
	emu_movw(&emu_ax, emu_bp - 0x2);
	emu_push(emu_ax);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0xC));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0xA));
	emu_push(emu_cs);
	emu_push(0x0780); f__07D4_196B_0073_56C1();
	goto l__0780;
l__0780:
	emu_addw(&emu_sp, 0xC);
	emu_orw(&emu_ax, emu_ax);
	if (emu_flags.zf) goto l__07B1;
	emu_ax = 0xC000;
	emu_push(emu_ax);
	emu_ax = 0x2;
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x4));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x2));
	emu_ax = 0x2DCE;
	emu_es = emu_ax;
	emu_push(emu_get_memory16(emu_es, 0x00, 0x45A));
	emu_push(emu_get_memory16(emu_es, 0x00, 0x458));
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x6C91));
	emu_push(emu_cs); emu_push(0x07AE); emu_cs = 0x2903; f__2903_0158_001A_2931();
	goto l__07AE;
l__07AE:
	emu_addw(&emu_sp, 0xE);
	goto l__07B1;
l__07B1:
	emu_push(emu_ss);
	emu_movw(&emu_ax, emu_bp - 0x1E);
	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x07BB); emu_cs = 0x0FE4; emu_Unit_FindNext();
	goto l__07BB;
l__07BB:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	goto l__07BD;
l__07BD:
	emu_get_memory16(emu_ss, emu_bp, -0x20) = emu_dx;
	emu_get_memory16(emu_ss, emu_bp, -0x22) = emu_ax;
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x22);
	emu_orw(&emu_ax, emu_get_memory16(emu_ss, emu_bp, -0x20));
	if (emu_flags.zf) goto l__07CE;
	goto l__05F9;
l__07CE:
	emu_get_memory16(emu_ds, 0x00, 0x39E4) = 0x0;
	emu_ax = emu_get_memory16(emu_ds, 0x00, 0x3A0A);
	emu_orw(&emu_ax, emu_get_memory16(emu_ds, 0x00, 0x3A0C));
	if (emu_flags.zf) goto l__07E0;
	goto l__08FD;
l__07E0:
	emu_cmpw(&emu_get_memory16(emu_ds, 0x00, 0x3A08), 0x0);
	if (!emu_flags.zf) goto l__07F0;
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp,  0x8), 0x0);
	if (!emu_flags.zf) goto l__07F0;
	goto l__08FD;
l__07F0:
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x3A00));
	emu_push(emu_cs); emu_push(0x07F9); emu_cs = 0x34CD; ovl__34CD(30);
	goto l__07F9;
l__07F9:
	emu_pop(&emu_cx);
	emu_orw(&emu_ax, emu_dx);
	if (!emu_flags.zf) goto l__080F;
	emu_cmpw(&emu_get_memory16(emu_ds, 0x00, 0x3A0E), 0x2);
	if (emu_flags.zf) goto l__080F;
	emu_cmpw(&emu_get_memory16(emu_ds, 0x00, 0x37A0), 0x0);
	if (!emu_flags.zf) goto l__080F;
	goto l__08FD;
l__080F:
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x3A00));
	emu_push(emu_cs); emu_push(0x0818); emu_cs = 0x0F3F; f__0F3F_0322_0011_5AAA();
	goto l__0818;
l__0818:
	emu_pop(&emu_cx);
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x39FC));
	emu_push(emu_cs); emu_push(0x0823); emu_cs = 0x0F3F; f__0F3F_0322_0011_5AAA();
	goto l__0823;
l__0823:
	emu_pop(&emu_cx);
	emu_pop(&emu_dx);
	emu_subw(&emu_dx, emu_ax);
	emu_cl = 0x4;
	emu_shlw(&emu_dx, emu_cl);
	emu_si = emu_dx;
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x3A00));
	emu_push(emu_cs); emu_push(0x0836); emu_cs = 0x0F3F; f__0F3F_0335_0015_2275();
	goto l__0836;
l__0836:
	emu_pop(&emu_cx);
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x39FC));
	emu_push(emu_cs); emu_push(0x0841); emu_cs = 0x0F3F; f__0F3F_0335_0015_2275();
	goto l__0841;
l__0841:
	emu_pop(&emu_cx);
	emu_pop(&emu_dx);
	emu_subw(&emu_dx, emu_ax);
	emu_cl = 0x4;
	emu_shlw(&emu_dx, emu_cl);
	emu_addw(&emu_dx, 0x28);
	emu_di = emu_dx;
	emu_ax = emu_get_memory16(emu_ds, 0x00, 0x3A04);
	emu_cl = 0x4;
	emu_shlw(&emu_ax, emu_cl);
	emu_dx = emu_si;
	emu_addw(&emu_dx, emu_ax);
	emu_decw(&emu_dx);
	emu_get_memory16(emu_ss, emu_bp, -0x1A) = emu_dx;
	emu_ax = emu_get_memory16(emu_ds, 0x00, 0x3A06);
	emu_cl = 0x4;
	emu_shlw(&emu_ax, emu_cl);
	emu_dx = emu_di;
	emu_addw(&emu_dx, emu_ax);
	emu_decw(&emu_dx);
	emu_get_memory16(emu_ss, emu_bp, -0x1C) = emu_dx;
	emu_ax = 0xC7;
	emu_push(emu_ax);
	emu_ax = 0xEF;
	emu_push(emu_ax);
	emu_ax = 0x28;
	emu_push(emu_ax);
	emu_xorw(&emu_ax, emu_ax);
	emu_push(emu_ax);
	emu_ax = 0x353F;
	emu_es = emu_ax;

	/* Call based on memory/register values */
	emu_ip = emu_get_memory16(emu_es, 0x00, 0x66C4);
	emu_push(emu_cs);
	emu_cs = emu_get_memory16(emu_es, 0x00, 0x66C6);
	emu_push(0x0885);
	switch ((emu_cs << 16) + emu_ip) {
		case 0x22A610DD: f__22A6_10DD_0023_B468(); break;
		default:
			/* In case we don't know the call point yet, call the dynamic call */
			emu_last_cs = 0x07D4; emu_last_ip = 0x0880; emu_last_length = 0x0044; emu_last_crc = 0xAA4E;
			emu_call();
			return;
	}
	goto l__0885;
l__0885:
	emu_addw(&emu_sp, 0x8);
	emu_ax = 0xFF;
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x1C));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x1A));
	emu_push(emu_di);
	emu_push(emu_si);
	emu_push(emu_cs); emu_push(0x0899); emu_cs = 0x251B; f__251B_0000_001E_7202();
	goto l__0899;
l__0899:
	emu_addw(&emu_sp, 0xA);
	emu_cmpw(&emu_get_memory16(emu_ds, 0x00, 0x38EC), 0x0);
	if (!emu_flags.zf) goto l__08DC;
	emu_cmpw(&emu_get_memory16(emu_ds, 0x00, 0x3A0E), 0x2);
	if (!emu_flags.zf) goto l__08DC;
	emu_ax = 0xFF;
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x1C));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x1A));
	emu_push(emu_di);
	emu_push(emu_si);
	emu_ax = 0x353F;
	emu_es = emu_ax;

	/* Call based on memory/register values */
	emu_ip = emu_get_memory16(emu_es, 0x00, 0x6654);
	emu_push(emu_cs);
	emu_cs = emu_get_memory16(emu_es, 0x00, 0x6656);
	emu_push(0x08C0);
	switch ((emu_cs << 16) + emu_ip) {
		case 0x22A6094D: f__22A6_094D_000C_EC7D(); break;
		default:
			/* In case we don't know the call point yet, call the dynamic call */
			emu_last_cs = 0x07D4; emu_last_ip = 0x08BB; emu_last_length = 0x0027; emu_last_crc = 0x372D;
			emu_call();
			return;
	}
	goto l__08C0;
l__08C0:
	emu_addw(&emu_sp, 0xA);
	emu_ax = 0xFF;
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x1C));
	emu_push(emu_si);
	emu_push(emu_di);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x1A));
	emu_ax = 0x353F;
	emu_es = emu_ax;

	/* Call based on memory/register values */
	emu_ip = emu_get_memory16(emu_es, 0x00, 0x6654);
	emu_push(emu_cs);
	emu_cs = emu_get_memory16(emu_es, 0x00, 0x6656);
	emu_push(0x08D9);
	switch ((emu_cs << 16) + emu_ip) {
		case 0x22A6094D: f__22A6_094D_000C_EC7D(); break;
		default:
			/* In case we don't know the call point yet, call the dynamic call */
			emu_last_cs = 0x07D4; emu_last_ip = 0x08D4; emu_last_length = 0x0019; emu_last_crc = 0x9BB9;
			emu_call();
			return;
	}
	goto l__08D9;
l__08D9:
	emu_addw(&emu_sp, 0xA);
	goto l__08DC;
l__08DC:
	emu_ax = 0xC7;
	emu_push(emu_ax);
	emu_ax = 0x13F;
	emu_push(emu_ax);
	emu_xorw(&emu_ax, emu_ax);
	emu_push(emu_ax);
	emu_xorw(&emu_ax, emu_ax);
	emu_push(emu_ax);
	emu_ax = 0x353F;
	emu_es = emu_ax;

	/* Call based on memory/register values */
	emu_ip = emu_get_memory16(emu_es, 0x00, 0x66C4);
	emu_push(emu_cs);
	emu_cs = emu_get_memory16(emu_es, 0x00, 0x66C6);
	emu_push(0x08F4);
	switch ((emu_cs << 16) + emu_ip) {
		case 0x22A610DD: f__22A6_10DD_0023_B468(); break;
		default:
			/* In case we don't know the call point yet, call the dynamic call */
			emu_last_cs = 0x07D4; emu_last_ip = 0x08EF; emu_last_length = 0x0018; emu_last_crc = 0x1A52;
			emu_call();
			return;
	}
	goto l__08F4;
l__08F4:
	emu_addw(&emu_sp, 0x8);
	emu_get_memory16(emu_ds, 0x00, 0x3A08) = 0x0;
	goto l__08FD;
l__08FD:
	emu_cmpw(&emu_get_memory16(emu_ds, 0x00, 0x39E6), 0x0);
	if (!emu_flags.zf) goto l__0913;
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp,  0x6), 0x0);
	if (!emu_flags.zf) goto l__0913;
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp, -0x12), 0x0);
	if (!emu_flags.zf) goto l__0913;
	goto l__0E64;
l__0913:
	emu_ax = 0xFFFF;
	emu_push(emu_ax);
	emu_ax = 0xFFFF;
	emu_push(emu_ax);
	emu_push(emu_ss);
	emu_movw(&emu_ax, emu_bp - 0x1E);
	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x0925); emu_cs = 0x0FE4; emu_Unit_FindFirst();
	goto l__0925;
l__0925:
	emu_addw(&emu_sp, 0x8);
	goto l__0E4D;
l__092B:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_cmpw(&emu_get_memory16(emu_es, emu_bx, 0x0), 0x14);
	if (!(emu_flags.sf != emu_flags.of)) goto l__0937;
	goto l__0E41;
l__0937:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_cmpw(&emu_get_memory16(emu_es, emu_bx, 0x0), 0x65);
	if ((emu_flags.zf || emu_flags.sf != emu_flags.of)) goto l__0943;
	goto l__0E41;
l__0943:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_ax = emu_get_memory16(emu_es, emu_bx, 0x4);
	emu_andw(&emu_ax, 0x1004);
	emu_cmpw(&emu_ax, 0x1000);
	if (emu_flags.zf) goto l__099A;
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp,  0x6), 0x0);
	if (!emu_flags.zf) goto l__099A;
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0xC));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0xA));
	emu_push(emu_cs); emu_push(0x0968); emu_cs = 0x0F3F; f__0F3F_0086_0017_EA43();
	goto l__0968;
l__0968:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	emu_cl = 0x3;
	emu_sarw(&emu_ax, emu_cl);
	emu_bx = emu_ax;
	emu_al = emu_get_memory8(emu_ds, emu_bx, 0x8FE5);
	emu_ah = 0x0;
	emu_push(emu_ax);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0xC));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0xA));
	emu_push(emu_cs); emu_push(0x0987); emu_cs = 0x0F3F; f__0F3F_0086_0017_EA43();
	goto l__0987;
l__0987:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	emu_andb(&emu_al, 0x7);
	emu_dx = 0x1;
	emu_cl = emu_al;
	emu_shlw(&emu_dx, emu_cl);
	emu_pop(&emu_ax);
	emu_testw(&emu_ax, emu_dx);
	if (!emu_flags.zf) goto l__099A;
	goto l__0E41;
l__099A:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_andw(&emu_get_memory16(emu_es, emu_bx, 0x4), 0xEFFF);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0xC));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0xA));
	emu_push(emu_cs); emu_push(0x09B3); emu_cs = 0x0F3F; f__0F3F_0086_0017_EA43();
	goto l__09B3;
l__09B3:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	emu_get_memory16(emu_ss, emu_bp, -0x10) = emu_ax;
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x10);
	emu_cl = 0x2;
	emu_shlw(&emu_ax, emu_cl);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ds, 0x00, 0x39EA));
	emu_addw(&emu_bx, emu_ax);
	emu_testb(&emu_get_memory8(emu_es, emu_bx, 0x2), 0x8);
	if (!emu_flags.zf) goto l__09D6;
	emu_cmpw(&emu_get_memory16(emu_ds, 0x00, 0x37A0), 0x0);
	if (!emu_flags.zf) goto l__09D6;
	goto l__0E41;
l__09D6:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_al = emu_get_memory8(emu_es, emu_bx, 0x2);
	emu_ax = emu_al;
	emu_dx = 0x5A;
	emu_imuluw(&emu_ax, emu_dx);
	emu_addw(&emu_ax, 0x0);
	emu_get_memory16(emu_ss, emu_bp, -0x24) = 0x2D07;
	emu_get_memory16(emu_ss, emu_bp, -0x26) = emu_ax;
	emu_push(emu_ss);
	emu_movw(&emu_ax, emu_bp - 0x4);
	emu_push(emu_ax);
	emu_push(emu_ss);
	emu_movw(&emu_ax, emu_bp - 0x2);
	emu_push(emu_ax);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0xC));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0xA));
	emu_push(emu_cs);
	emu_push(0x0A07); f__07D4_196B_0073_56C1();
	goto l__0A07;
l__0A07:
	emu_addw(&emu_sp, 0xC);
	emu_orw(&emu_ax, emu_ax);
	if (!emu_flags.zf) goto l__0A12;
	goto l__0E41;
l__0A12:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_al = emu_get_memory8(emu_es, emu_bx, 0x6C);
	emu_ax = emu_al;
	emu_cl = 0x2;
	emu_shlw(&emu_ax, emu_cl);
	emu_dx = 0x2DCE;
	emu_bx = emu_ax;
	emu_es = emu_dx;
	emu_ax = emu_get_memory16(emu_es, emu_bx, 0x0);
	emu_addw(&emu_get_memory16(emu_ss, emu_bp, -0x2), emu_ax);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_al = emu_get_memory8(emu_es, emu_bx, 0x6C);
	emu_ax = emu_al;
	emu_cl = 0x2;
	emu_shlw(&emu_ax, emu_cl);
	emu_dx = 0x2DCE;
	emu_bx = emu_ax;
	emu_es = emu_dx;
	emu_ax = emu_get_memory16(emu_es, emu_bx, 0x2);
	emu_addw(&emu_get_memory16(emu_ss, emu_bp, -0x4), emu_ax);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_al = emu_get_memory8(emu_es, emu_bx, 0x64);
	emu_ah = 0x0;
	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x0A57); emu_cs = 0x34CD; ovl__34CD(19);
	goto l__0A57;
l__0A57:
	emu_pop(&emu_cx);
	emu_di = emu_ax;
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_cmpb(&emu_get_memory8(emu_es, emu_bx, 0x6D), 0x0);
	if (!(emu_flags.sf != emu_flags.of)) goto l__0A71;
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x26));
	emu_cmpw(&emu_get_memory16(emu_es, emu_bx, 0x4C), 0x0);
	if (emu_flags.zf) goto l__0A71;
	goto l__0B0E;
l__0A71:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x26));
	emu_si = emu_get_memory16(emu_es, emu_bx, 0x44);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x26));
	emu_bx = emu_get_memory16(emu_es, emu_bx, 0x4A);
	emu_cmpw(&emu_bx, 0x4);
	if ((emu_flags.cf || emu_flags.zf)) goto l__0A87;
	/* Unresolved jump */ emu_ip = 0x0B04; emu_last_cs = 0x07D4; emu_last_ip = 0x0A84; emu_last_length = 0x0015; emu_last_crc = 0x14BA; emu_call();
l__0A87:
	emu_shlw(&emu_bx, 0x1);

	/* Jump based on memory/register values */
	emu_ip = emu_get_memory16(emu_cs, emu_bx, 0x1590);
	switch (emu_ip) {
		case 0x0A8E: goto l__0A8E;
		case 0x0AB1: goto l__0AB1;
		case 0x0AD6: goto l__0AD6;
		default:
			/* In case we don't know the call point yet, call the dynamic call */
			emu_last_cs = 0x07D4; emu_last_ip = 0x0A89; emu_last_length = 0x0007; emu_last_crc = 0x629A;
			emu_call();
			return;
	}
l__0A8E:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x26));
	emu_cmpw(&emu_get_memory16(emu_es, emu_bx, 0x3C), 0x5);
	if (!emu_flags.zf) goto l__0A9B;
	goto l__0B0C;
l__0A9B:
	emu_bx = emu_di;
	emu_cl = 0x2;
	emu_shlw(&emu_bx, emu_cl);
	emu_addw(&emu_si, emu_get_memory16(emu_ds, emu_bx, 0x32A4));
	emu_bx = emu_di;
	emu_cl = 0x2;
	emu_shlw(&emu_bx, emu_cl);
	emu_ax = emu_get_memory16(emu_ds, emu_bx, 0x32A6);
	goto l__0AFD;
l__0AB1:
	emu_bx = emu_di;
	emu_cl = 0x2;
	emu_shlw(&emu_bx, emu_cl);
	emu_ax = emu_get_memory16(emu_ds, emu_bx, 0x32C4);
	emu_dx = 0x3;
	emu_imuluw(&emu_ax, emu_dx);
	emu_addw(&emu_si, emu_ax);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_al = emu_get_memory8(emu_es, emu_bx, 0x6D);
	emu_ax = emu_al;
	emu_andw(&emu_ax, 0x3);
	emu_bx = emu_ax;
	emu_al = emu_get_memory8(emu_ds, emu_bx, 0x334A);
	emu_ax = emu_al;
	goto l__0AF1;
l__0AD6:
	emu_bx = emu_di;
	emu_cl = 0x2;
	emu_shlw(&emu_bx, emu_cl);
	emu_ax = emu_get_memory16(emu_ds, emu_bx, 0x32C4);
	emu_cl = 0x2;
	emu_shlw(&emu_ax, emu_cl);
	emu_addw(&emu_si, emu_ax);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_al = emu_get_memory8(emu_es, emu_bx, 0x6D);
	emu_ax = emu_al;
	emu_andw(&emu_ax, 0x3);
	goto l__0AF1;
l__0AF1:
	emu_addw(&emu_si, emu_ax);
	emu_bx = emu_di;
	emu_cl = 0x2;
	emu_shlw(&emu_bx, emu_cl);
	emu_ax = emu_get_memory16(emu_ds, emu_bx, 0x32C6);
	goto l__0AFD;
l__0AFD:
	emu_get_memory16(emu_ds, 0x00, 0x8DE3) = emu_ax;
	goto l__0B0C;
l__0B0C:
	goto l__0B2A;
l__0B0E:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_al = emu_get_memory8(emu_es, emu_bx, 0x6D);
	emu_ax = emu_al;
	emu_negw(&emu_ax, emu_ax);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x26));
	emu_dx = emu_get_memory16(emu_es, emu_bx, 0x4C);
	emu_addw(&emu_dx, emu_ax);
	emu_decw(&emu_dx);
	emu_si = emu_dx;
	emu_get_memory16(emu_ds, 0x00, 0x8DE3) = 0x0;
	goto l__0B2A;
l__0B2A:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_cmpb(&emu_get_memory8(emu_es, emu_bx, 0x59), 0x0);
	if (emu_flags.zf) goto l__0B39;
	emu_ax = 0x2;
	goto l__0B46;
l__0B39:
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x20));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_push(emu_cs); emu_push(0x0B44); emu_cs = 0x1A34; emu_Unit_GetHouseID();
	goto l__0B44;
l__0B44:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	goto l__0B46;
l__0B46:
	emu_push(emu_ax);
	emu_push(emu_si);
	emu_push(emu_cs);
	emu_push(0x0B4C); f__07D4_18BD_0016_68BB();
	goto l__0B4C;
l__0B4C:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	emu_get_memory16(emu_ss, emu_bp, -0x28) = emu_dx;
	emu_get_memory16(emu_ss, emu_bp, -0x2A) = emu_ax;
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_cmpb(&emu_get_memory8(emu_es, emu_bx, 0x2), 0x19);
	if (!emu_flags.zf) {
		emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
		emu_testw(&emu_get_memory16(emu_es, emu_bx, 0x4), 0x800);
		if (!emu_flags.zf) {
			emu_orw(&emu_get_memory16(emu_ds, 0x00, 0x8DE3), 0x100);
		}
	}
	goto l__0B70;
l__0B70:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x26));
	emu_testw(&emu_get_memory16(emu_es, emu_bx, 0xC), 0x20);
	if (!emu_flags.zf) {
		emu_orw(&emu_get_memory16(emu_ds, 0x00, 0x8DE3), 0x200);
	}
	goto l__0B81;
l__0B81:
	emu_ax = 0x1;
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x3C40));
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x3C3E));
	emu_push(emu_ds);
	emu_ax = 0x8420;
	emu_push(emu_ax);
	emu_ax = emu_get_memory16(emu_ds, 0x00, 0x8DE3);
	emu_orw(&emu_ax, 0xE000);
	emu_push(emu_ax);
	emu_ax = 0x2;
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x4));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x2));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x28));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x2A));
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x6C91));
	emu_push(emu_cs); emu_push(0x0BB2); emu_cs = 0x2903; f__2903_0158_001A_2931();
	goto l__0BB2;
l__0BB2:
	emu_addw(&emu_sp, 0x18);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_cmpb(&emu_get_memory8(emu_es, emu_bx, 0x2), 0x10);
	if (emu_flags.zf) goto l__0BC2;
	goto l__0C8E;
l__0BC2:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_cmpb(&emu_get_memory8(emu_es, emu_bx, 0x4F), 0x5);
	if (emu_flags.zf) goto l__0BCF;
	goto l__0C8E;
l__0BCF:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_cmpb(&emu_get_memory8(emu_es, emu_bx, 0x6D), 0x0);
	if (!(emu_flags.sf != emu_flags.of)) goto l__0BDC;
	goto l__0C8E;
l__0BDC:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_cmpb(&emu_get_memory8(emu_es, emu_bx, 0x4F), 0x5);
	if (emu_flags.zf) goto l__0BF3;
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_cmpb(&emu_get_memory8(emu_es, emu_bx, 0x4F), 0x1);
	if (emu_flags.zf) goto l__0BF3;
	goto l__0C8E;
l__0BF3:
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x10));
	emu_push(emu_cs); emu_push(0x0BFB); emu_cs = 0x34CD; ovl__34CD(13);
	goto l__0BFB;
l__0BFB:
	emu_pop(&emu_cx);
	emu_cmpw(&emu_ax, 0x8);
	if (emu_flags.zf) goto l__0C09;
	emu_cmpw(&emu_ax, 0x9);
	if (emu_flags.zf) goto l__0C09;
	goto l__0C8C;
l__0C09:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_al = emu_get_memory8(emu_es, emu_bx, 0x6D);
	emu_ax = emu_al;
	emu_bx = 0x3;
	emu_cwd();
	emu_idivw(&emu_ax, emu_bx);
	emu_si = emu_dx;
	emu_addw(&emu_si, 0xDF);
	emu_bx = emu_di;
	emu_cl = 0x2;
	emu_shlw(&emu_bx, emu_cl);
	emu_ax = emu_get_memory16(emu_ds, emu_bx, 0x32A4);
	emu_dx = 0x3;
	emu_imuluw(&emu_ax, emu_dx);
	emu_addw(&emu_si, emu_ax);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x20));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_push(emu_cs); emu_push(0x0C39); emu_cs = 0x1A34; emu_Unit_GetHouseID();
	goto l__0C39;
l__0C39:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	emu_push(emu_ax);
	emu_push(emu_si);
	emu_push(emu_cs);
	emu_push(0x0C41); f__07D4_18BD_0016_68BB();
	goto l__0C41;
l__0C41:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	emu_get_memory16(emu_ss, emu_bp, -0x28) = emu_dx;
	emu_get_memory16(emu_ss, emu_bp, -0x2A) = emu_ax;
	emu_bx = emu_di;
	emu_cl = 0x2;
	emu_shlw(&emu_bx, emu_cl);
	emu_ax = emu_get_memory16(emu_ds, emu_bx, 0x32A6);
	emu_orw(&emu_ax, 0xC000);
	emu_push(emu_ax);
	emu_ax = 0x2;
	emu_push(emu_ax);
	emu_bx = emu_di;
	emu_cl = 0x2;
	emu_shlw(&emu_bx, emu_cl);
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x4);
	emu_addw(&emu_ax, emu_get_memory16(emu_ds, emu_bx, 0x3350));
	emu_push(emu_ax);
	emu_bx = emu_di;
	emu_cl = 0x2;
	emu_shlw(&emu_bx, emu_cl);
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x2);
	emu_addw(&emu_ax, emu_get_memory16(emu_ds, emu_bx, 0x334E));
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x28));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x2A));
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x6C91));
	emu_push(emu_cs); emu_push(0x0C87); emu_cs = 0x2903; f__2903_0158_001A_2931();
	goto l__0C87;
l__0C87:
	emu_addw(&emu_sp, 0xE);
	goto l__0C8E;
l__0C8C:
	goto l__0C8E;
l__0C8E:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_cmpb(&emu_get_memory8(emu_es, emu_bx, 0x6D), 0x0);
	if (!(emu_flags.sf != emu_flags.of)) goto l__0C9B;
	goto l__0DAE;
l__0C9B:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x26));
	emu_cmpw(&emu_get_memory16(emu_es, emu_bx, 0x46), 0xFFFF);
	if (!emu_flags.zf) goto l__0CA8;
	goto l__0DAE;
l__0CA8:
	emu_xorw(&emu_ax, emu_ax);
	emu_get_memory16(emu_ss, emu_bp, -0x2E) = emu_ax;
	emu_get_memory16(emu_ss, emu_bp, -0x2C) = emu_ax;
	emu_get_memory16(emu_ss, emu_bp, -0x28) = 0x0;
	emu_get_memory16(emu_ss, emu_bp, -0x2A) = 0x0;
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x26));
	emu_si = emu_get_memory16(emu_es, emu_bx, 0x46);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x26));
	emu_testw(&emu_get_memory16(emu_es, emu_bx, 0xC), 0x40);
	if (emu_flags.zf) { /* Unresolved jump */ emu_ip = 0x0CD5; emu_last_cs = 0x07D4; emu_last_ip = 0x0CCA; emu_last_length = 0x002D; emu_last_crc = 0x48A6; emu_call(); return; }
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_al = emu_get_memory8(emu_es, emu_bx, 0x67);
	goto l__0CDC;
l__0CDC:
	emu_ah = 0x0;
	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x0CE4); emu_cs = 0x34CD; ovl__34CD(19);
	goto l__0CE4;
l__0CE4:
	emu_pop(&emu_cx);
	emu_di = emu_ax;
	emu_get_memory16(emu_ss, emu_bp, -0x18) = emu_si;
	emu_cx = 0x4;
	emu_bx = 0x1580;
	goto l__0CF0;
l__0CF0:
	emu_ax = emu_get_memory16(emu_cs, emu_bx, 0x0);
	emu_cmpw(&emu_ax, emu_get_memory16(emu_ss, emu_bp, -0x18));
	if (emu_flags.zf) { /* Unresolved jump */ emu_ip = 0x0CFF; emu_last_cs = 0x07D4; emu_last_ip = 0x0CF6; emu_last_length = 0x000F; emu_last_crc = 0x4EEF; emu_call(); return; }
	emu_addw(&emu_bx, 0x2);
	if (--emu_cx != 0) goto l__0CF0;
	goto l__0D49;
l__0D49:
	goto l__0D4B;
l__0D4B:
	emu_bx = emu_di;
	emu_cl = 0x2;
	emu_shlw(&emu_bx, emu_cl);
	emu_ax = emu_get_memory16(emu_ds, emu_bx, 0x32A6);
	emu_get_memory16(emu_ds, 0x00, 0x8DE3) = emu_ax;
	emu_bx = emu_di;
	emu_cl = 0x2;
	emu_shlw(&emu_bx, emu_cl);
	emu_addw(&emu_si, emu_get_memory16(emu_ds, emu_bx, 0x32A4));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x20));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_push(emu_cs); emu_push(0x0D6D); emu_cs = 0x1A34; emu_Unit_GetHouseID();
	goto l__0D6D;
l__0D6D:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	emu_push(emu_ax);
	emu_push(emu_si);
	emu_push(emu_cs);
	emu_push(0x0D75); f__07D4_18BD_0016_68BB();
	goto l__0D75;
l__0D75:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	emu_get_memory16(emu_ss, emu_bp, -0x28) = emu_dx;
	emu_get_memory16(emu_ss, emu_bp, -0x2A) = emu_ax;
	emu_push(emu_ds);
	emu_ax = 0x8420;
	emu_push(emu_ax);
	emu_ax = emu_get_memory16(emu_ds, 0x00, 0x8DE3);
	emu_orw(&emu_ax, 0xE000);
	emu_push(emu_ax);
	emu_ax = 0x2;
	emu_push(emu_ax);
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x4);
	emu_addw(&emu_ax, emu_get_memory16(emu_ss, emu_bp, -0x2E));
	emu_push(emu_ax);
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x2);
	emu_addw(&emu_ax, emu_get_memory16(emu_ss, emu_bp, -0x2C));
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x28));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x2A));
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x6C91));
	emu_push(emu_cs); emu_push(0x0DAB); emu_cs = 0x2903; f__2903_0158_001A_2931();
	goto l__0DAB;
l__0DAB:
	emu_addw(&emu_sp, 0x12);
	goto l__0DAE;
l__0DAE:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_testw(&emu_get_memory16(emu_es, emu_bx, 0x4), 0x8);
	if (emu_flags.zf) goto l__0E06;
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_al = emu_get_memory8(emu_es, emu_bx, 0x6D);
	emu_ax = emu_al;
	emu_andw(&emu_ax, 0x3);
	emu_get_memory16(emu_ss, emu_bp, -0x2C) = emu_ax;
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp, -0x2C), 0x3);
	if (emu_flags.zf) {
		emu_get_memory16(emu_ss, emu_bp, -0x2C) = 0x1;
	}
	goto l__0DD2;
l__0DD2:
	emu_ax = 0xC000;
	emu_push(emu_ax);
	emu_ax = 0x2;
	emu_push(emu_ax);
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x4);
	emu_addw(&emu_ax, 0xFFF2);
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x2));
	emu_bx = emu_get_memory16(emu_ss, emu_bp, -0x2C);
	emu_cl = 0x2;
	emu_shlw(&emu_bx, emu_cl);
	emu_ax = 0x2DCE;
	emu_es = emu_ax;
	emu_push(emu_get_memory16(emu_es, emu_bx, 0x712));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0x710));
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x6C91));
	emu_push(emu_cs); emu_push(0x0E03); emu_cs = 0x2903; f__2903_0158_001A_2931();
	goto l__0E03;
l__0E03:
	emu_addw(&emu_sp, 0xE);
	goto l__0E06;
l__0E06:
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x20);
	emu_dx = emu_get_memory16(emu_ss, emu_bp, -0x22);
	emu_cmpw(&emu_ax, emu_get_memory16(emu_ds, 0x00, 0x3A0C));
	if (!emu_flags.zf) goto l__0E41;
	emu_cmpw(&emu_dx, emu_get_memory16(emu_ds, 0x00, 0x3A0A));
	if (!emu_flags.zf) goto l__0E41;
	emu_ax = 0xC000;
	emu_push(emu_ax);
	emu_ax = 0x2;
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x4));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x2));
	emu_ax = 0x2DCE;
	emu_es = emu_ax;
	emu_push(emu_get_memory16(emu_es, 0x00, 0x45A));
	emu_push(emu_get_memory16(emu_es, 0x00, 0x458));
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x6C91));
	emu_push(emu_cs); emu_push(0x0E3E); emu_cs = 0x2903; f__2903_0158_001A_2931();
	goto l__0E3E;
l__0E3E:
	emu_addw(&emu_sp, 0xE);
	goto l__0E41;
l__0E41:
	emu_push(emu_ss);
	emu_movw(&emu_ax, emu_bp - 0x1E);
	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x0E4B); emu_cs = 0x0FE4; emu_Unit_FindNext();
	goto l__0E4B;
l__0E4B:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	goto l__0E4D;
l__0E4D:
	emu_get_memory16(emu_ss, emu_bp, -0x20) = emu_dx;
	emu_get_memory16(emu_ss, emu_bp, -0x22) = emu_ax;
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x22);
	emu_orw(&emu_ax, emu_get_memory16(emu_ss, emu_bp, -0x20));
	if (emu_flags.zf) goto l__0E5E;
	goto l__092B;
l__0E5E:
	emu_get_memory16(emu_ds, 0x00, 0x39E6) = 0x0;
	goto l__0E64;
l__0E64:
	emu_get_memory16(emu_ss, emu_bp, -0xE) = 0x0;
	goto l__0FA0;
l__0E6C:
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0xE);
	emu_dx = 0x14;
	emu_imuluw(&emu_ax, emu_dx);
	emu_dx = emu_get_memory16(emu_ds, 0x00, 0x395C);
	emu_bx = emu_get_memory16(emu_ds, 0x00, 0x395A);
	emu_addw(&emu_bx, emu_ax);
	emu_get_memory16(emu_ss, emu_bp, -0x1A) = emu_dx;
	emu_get_memory16(emu_ss, emu_bp, -0x1C) = emu_bx;
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x1C));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0x12));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0x10));
	emu_push(emu_cs); emu_push(0x0E94); emu_cs = 0x0F3F; f__0F3F_0086_0017_EA43();
	goto l__0E94;
l__0E94:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	emu_cl = 0x3;
	emu_sarw(&emu_ax, emu_cl);
	emu_bx = emu_ax;
	emu_al = emu_get_memory8(emu_ds, emu_bx, 0x8FE5);
	emu_ah = 0x0;
	emu_push(emu_ax);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x1C));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0x12));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0x10));
	emu_push(emu_cs); emu_push(0x0EB3); emu_cs = 0x0F3F; f__0F3F_0086_0017_EA43();
	goto l__0EB3;
l__0EB3:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	emu_andb(&emu_al, 0x7);
	emu_dx = 0x1;
	emu_cl = emu_al;
	emu_shlw(&emu_dx, emu_cl);
	emu_pop(&emu_ax);
	emu_testw(&emu_ax, emu_dx);
	if (!emu_flags.zf) {
		emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x1C));
		emu_get_memory8(emu_es, emu_bx, 0x7) = 0x1;
	}
	goto l__0ECB;
l__0ECB:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x1C));
	emu_ax = emu_get_memory16(emu_es, emu_bx, 0xC);
	emu_orw(&emu_ax, emu_get_memory16(emu_es, emu_bx, 0xE));
	if (!emu_flags.zf) goto l__0EDB;
	goto l__0F9D;
l__0EDB:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x1C));
	emu_cmpb(&emu_get_memory8(emu_es, emu_bx, 0x7), 0x0);
	if (!emu_flags.zf) goto l__0EEE;
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp,  0x6), 0x0);
	if (!emu_flags.zf) goto l__0EEE;
	goto l__0F9D;
l__0EEE:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x1C));
	emu_cmpw(&emu_get_memory16(emu_es, emu_bx, 0xA), 0x0);
	if (!emu_flags.zf) goto l__0EFB;
	goto l__0F9D;
l__0EFB:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x1C));
	emu_get_memory8(emu_es, emu_bx, 0x7) = 0x0;
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x1C));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0x12));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0x10));
	emu_push(emu_cs); emu_push(0x0F13); emu_cs = 0x0F3F; f__0F3F_0086_0017_EA43();
	goto l__0F13;
l__0F13:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	emu_get_memory16(emu_ss, emu_bp, -0x10) = emu_ax;
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x10);
	emu_cl = 0x2;
	emu_shlw(&emu_ax, emu_cl);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ds, 0x00, 0x39EA));
	emu_addw(&emu_bx, emu_ax);
	emu_testb(&emu_get_memory8(emu_es, emu_bx, 0x2), 0x8);
	if (emu_flags.zf) {
		emu_cmpw(&emu_get_memory16(emu_ds, 0x00, 0x37A0), 0x0);
		if (emu_flags.zf) goto l__0F9D;
	}
	goto l__0F33;
l__0F33:
	emu_push(emu_ss);
	emu_movw(&emu_ax, emu_bp - 0x4);
	emu_push(emu_ax);
	emu_push(emu_ss);
	emu_movw(&emu_ax, emu_bp - 0x2);
	emu_push(emu_ax);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x1C));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0x12));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0x10));
	emu_push(emu_cs);
	emu_push(0x0F4C); f__07D4_196B_0073_56C1();
	goto l__0F4C;
l__0F4C:
	emu_addw(&emu_sp, 0xC);
	emu_orw(&emu_ax, emu_ax);
	if (emu_flags.zf) goto l__0F9D;
	emu_get_memory16(emu_ds, 0x00, 0x8DE3) = 0xC000;
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x1C));
	emu_al = emu_get_memory8(emu_es, emu_bx, 0x6);
	emu_ah = 0x0;
	emu_push(emu_ax);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x1C));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0xA));
	emu_push(emu_cs);
	emu_push(0x0F6F); f__07D4_18BD_0016_68BB();
	goto l__0F6F;
l__0F6F:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	emu_get_memory16(emu_ss, emu_bp, -0x1E) = emu_dx;
	emu_get_memory16(emu_ss, emu_bp, -0x20) = emu_ax;
	emu_push(emu_ds);
	emu_ax = 0x8420;
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x8DE3));
	emu_ax = 0x2;
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x4));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x2));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x1E));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x20));
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x6C91));
	emu_push(emu_cs); emu_push(0x0F9A); emu_cs = 0x2903; f__2903_0158_001A_2931();
	goto l__0F9A;
l__0F9A:
	emu_addw(&emu_sp, 0x12);
	goto l__0F9D;
l__0F9D:
	emu_incw(&emu_get_memory16(emu_ss, emu_bp, -0xE));
	goto l__0FA0;
l__0FA0:
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp, -0xE), 0x20);
	if (!(emu_flags.sf != emu_flags.of)) goto l__0FA9;
	goto l__0E6C;
l__0FA9:
	emu_cmpw(&emu_get_memory16(emu_ds, 0x00, 0x39E8), 0x0);
	if (!emu_flags.zf) goto l__0FBF;
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp,  0x6), 0x0);
	if (!emu_flags.zf) goto l__0FBF;
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp, -0x12), 0x0);
	if (!emu_flags.zf) goto l__0FBF;
	goto l__1263;
l__0FBF:
	emu_ax = 0xFFFF;
	emu_push(emu_ax);
	emu_ax = 0xFFFF;
	emu_push(emu_ax);
	emu_push(emu_ss);
	emu_movw(&emu_ax, emu_bp - 0x1E);
	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x0FD1); emu_cs = 0x0FE4; emu_Unit_FindFirst();
	goto l__0FD1;
l__0FD1:
	emu_addw(&emu_sp, 0x8);
	goto l__124C;
l__0FD7:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_cmpw(&emu_get_memory16(emu_es, emu_bx, 0x0), 0xF);
	if ((emu_flags.zf || emu_flags.sf != emu_flags.of)) goto l__0FE3;
	goto l__1240;
l__0FE3:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_ax = emu_get_memory16(emu_es, emu_bx, 0x4);
	emu_andw(&emu_ax, 0x1004);
	emu_cmpw(&emu_ax, 0x1000);
	if (emu_flags.zf) goto l__103A;
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp,  0x6), 0x0);
	if (!emu_flags.zf) goto l__103A;
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0xC));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0xA));
	emu_push(emu_cs); emu_push(0x1008); emu_cs = 0x0F3F; f__0F3F_0086_0017_EA43();
	goto l__1008;
l__1008:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	emu_cl = 0x3;
	emu_sarw(&emu_ax, emu_cl);
	emu_bx = emu_ax;
	emu_al = emu_get_memory8(emu_ds, emu_bx, 0x8FE5);
	emu_ah = 0x0;
	emu_push(emu_ax);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0xC));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0xA));
	emu_push(emu_cs); emu_push(0x1027); emu_cs = 0x0F3F; f__0F3F_0086_0017_EA43();
	goto l__1027;
l__1027:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	emu_andb(&emu_al, 0x7);
	emu_dx = 0x1;
	emu_cl = emu_al;
	emu_shlw(&emu_dx, emu_cl);
	emu_pop(&emu_ax);
	emu_testw(&emu_ax, emu_dx);
	if (!emu_flags.zf) goto l__103A;
	goto l__1240;
l__103A:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_andw(&emu_get_memory16(emu_es, emu_bx, 0x4), 0xEFFF);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0xC));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0xA));
	emu_push(emu_cs); emu_push(0x1053); emu_cs = 0x0F3F; f__0F3F_0086_0017_EA43();
	goto l__1053;
l__1053:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	emu_get_memory16(emu_ss, emu_bp, -0x10) = emu_ax;
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x10);
	emu_cl = 0x2;
	emu_shlw(&emu_ax, emu_cl);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ds, 0x00, 0x39EA));
	emu_addw(&emu_bx, emu_ax);
	emu_testb(&emu_get_memory8(emu_es, emu_bx, 0x2), 0x8);
	if (!emu_flags.zf) goto l__1076;
	emu_cmpw(&emu_get_memory16(emu_ds, 0x00, 0x37A0), 0x0);
	if (!emu_flags.zf) goto l__1076;
	goto l__1240;
l__1076:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_al = emu_get_memory8(emu_es, emu_bx, 0x2);
	emu_ax = emu_al;
	emu_dx = 0x5A;
	emu_imuluw(&emu_ax, emu_dx);
	emu_addw(&emu_ax, 0x0);
	emu_get_memory16(emu_ss, emu_bp, -0x24) = 0x2D07;
	emu_get_memory16(emu_ss, emu_bp, -0x26) = emu_ax;
	emu_push(emu_ss);
	emu_movw(&emu_ax, emu_bp - 0x4);
	emu_push(emu_ax);
	emu_push(emu_ss);
	emu_movw(&emu_ax, emu_bp - 0x2);
	emu_push(emu_ax);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0xC));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0xA));
	emu_push(emu_cs);
	emu_push(0x10A7); f__07D4_196B_0073_56C1();
	goto l__10A7;
l__10A7:
	emu_addw(&emu_sp, 0xC);
	emu_orw(&emu_ax, emu_ax);
	if (!emu_flags.zf) goto l__10B2;
	goto l__1240;
l__10B2:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x26));
	emu_si = emu_get_memory16(emu_es, emu_bx, 0x44);
	emu_get_memory16(emu_ss, emu_bp, -0x28) = 0x0;
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_al = emu_get_memory8(emu_es, emu_bx, 0x64);
	emu_ah = 0x0;
	emu_di = emu_ax;
	emu_get_memory16(emu_ds, 0x00, 0x8DE3) = 0xC000;
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x26));
	emu_bx = emu_get_memory16(emu_es, emu_bx, 0x4A);
	emu_cmpw(&emu_bx, 0x5);
	if ((emu_flags.cf || emu_flags.zf)) goto l__10DE;
	/* Unresolved jump */ emu_ip = 0x1171; emu_last_cs = 0x07D4; emu_last_ip = 0x10DB; emu_last_length = 0x002C; emu_last_crc = 0xED43; emu_call();
l__10DE:
	emu_shlw(&emu_bx, 0x1);

	/* Jump based on memory/register values */
	emu_ip = emu_get_memory16(emu_cs, emu_bx, 0x1574);
	switch (emu_ip) {
		case 0x10E5: goto l__10E5;
		case 0x10F4: goto l__10F4;
		case 0x110F: goto l__110F;
		default:
			/* In case we don't know the call point yet, call the dynamic call */
			emu_last_cs = 0x07D4; emu_last_ip = 0x10E0; emu_last_length = 0x0007; emu_last_crc = 0x62A3;
			emu_call();
			return;
	}
l__10E5:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_testw(&emu_get_memory16(emu_es, emu_bx, 0x4), 0x40);
	if (!emu_flags.zf) {
		emu_incw(&emu_si);
	}
	goto l__10F1;
l__10F1:
	goto l__1177;
l__10F4:
	emu_push(emu_di);
	emu_push(emu_cs); emu_push(0x10FA); emu_cs = 0x34CD; ovl__34CD(19);
	goto l__10FA;
l__10FA:
	emu_pop(&emu_cx);
	emu_di = emu_ax;
	emu_bx = emu_di;
	emu_cl = 0x2;
	emu_shlw(&emu_bx, emu_cl);
	emu_ax = emu_get_memory16(emu_ds, emu_bx, 0x32E4);
	emu_get_memory16(emu_ss, emu_bp, -0x28) = emu_ax;
	emu_addw(&emu_si, emu_get_memory16(emu_ss, emu_bp, -0x28));
	goto l__1161;
l__110F:
	emu_push(emu_di);
	emu_push(emu_cs); emu_push(0x1115); emu_cs = 0x34CD; ovl__34CD(12);
	goto l__1115;
l__1115:
	emu_pop(&emu_cx);
	emu_di = emu_ax;
	emu_bx = emu_di;
	emu_cl = 0x2;
	emu_shlw(&emu_bx, emu_cl);
	emu_ax = emu_get_memory16(emu_ds, emu_bx, 0x3304);
	emu_get_memory16(emu_ss, emu_bp, -0x28) = emu_ax;
	emu_addw(&emu_si, emu_get_memory16(emu_ss, emu_bp, -0x28));
	emu_bx = emu_di;
	emu_cl = 0x2;
	emu_shlw(&emu_bx, emu_cl);
	emu_ax = emu_get_memory16(emu_ds, emu_bx, 0x3306);
	goto l__116B;
l__1161:
	emu_bx = emu_di;
	emu_cl = 0x2;
	emu_shlw(&emu_bx, emu_cl);
	emu_ax = emu_get_memory16(emu_ds, emu_bx, 0x32E6);
	goto l__116B;
l__116B:
	emu_orw(&emu_get_memory16(emu_ds, 0x00, 0x8DE3), emu_ax);
	goto l__1177;
l__1177:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x26));
	emu_testw(&emu_get_memory16(emu_es, emu_bx, 0x36), 0x2000);
	if (!emu_flags.zf) {
		emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
		emu_testw(&emu_get_memory16(emu_es, emu_bx, 0x4), 0x20);
		if (!emu_flags.zf) {
			emu_addw(&emu_si, 0x5);
		}
	}
	goto l__1190;
l__1190:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_cmpb(&emu_get_memory8(emu_es, emu_bx, 0x2), 0x0);
	if (emu_flags.zf) {
		emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x22));
		emu_testw(&emu_get_memory16(emu_es, emu_bx, 0x4), 0x100);
		if (!emu_flags.zf) {
			emu_addw(&emu_si, 0x3);
		}
	}
	goto l__11A8;
l__11A8:
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x20));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x22));
	emu_push(emu_cs); emu_push(0x11B3); emu_cs = 0x1A34; emu_Unit_GetHouseID();
	goto l__11B3;
l__11B3:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	emu_push(emu_ax);
	emu_push(emu_si);
	emu_push(emu_cs);
	emu_push(0x11BB); f__07D4_18BD_0016_68BB();
	goto l__11BB;
l__11BB:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	emu_get_memory16(emu_ss, emu_bp, -0x2A) = emu_dx;
	emu_get_memory16(emu_ss, emu_bp, -0x2C) = emu_ax;
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x26));
	emu_testw(&emu_get_memory16(emu_es, emu_bx, 0xC), 0x1);
	if (emu_flags.zf) goto l__1207;
	emu_ax = 0x1;
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x3C3C));
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x3C3A));
	emu_ax = emu_get_memory16(emu_ds, 0x00, 0x8DE3);
	emu_andw(&emu_ax, 0xDFFF);
	emu_orw(&emu_ax, 0x300);
	emu_push(emu_ax);
	emu_ax = 0x2;
	emu_push(emu_ax);
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x4);
	emu_addw(&emu_ax, 0x3);
	emu_push(emu_ax);
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x2);
	emu_incw(&emu_ax);
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x2A));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x2C));
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x6C91));
	emu_push(emu_cs); emu_push(0x1204); emu_cs = 0x2903; f__2903_0158_001A_2931();
	goto l__1204;
l__1204:
	emu_addw(&emu_sp, 0x14);
	goto l__1207;
l__1207:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x26));
	emu_testw(&emu_get_memory16(emu_es, emu_bx, 0xC), 0x20);
	if (!emu_flags.zf) {
		emu_orw(&emu_get_memory16(emu_ds, 0x00, 0x8DE3), 0x200);
	}
	goto l__1218;
l__1218:
	emu_push(emu_ds);
	emu_ax = 0x8420;
	emu_push(emu_ax);
	emu_ax = emu_get_memory16(emu_ds, 0x00, 0x8DE3);
	emu_orw(&emu_ax, 0x2000);
	emu_push(emu_ax);
	emu_ax = 0x2;
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x4));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x2));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x2A));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x2C));
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x6C91));
	emu_push(emu_cs); emu_push(0x123D); emu_cs = 0x2903; f__2903_0158_001A_2931();
	goto l__123D;
l__123D:
	emu_addw(&emu_sp, 0x12);
	goto l__1240;
l__1240:
	emu_push(emu_ss);
	emu_movw(&emu_ax, emu_bp - 0x1E);
	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x124A); emu_cs = 0x0FE4; emu_Unit_FindNext();
	goto l__124A;
l__124A:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	goto l__124C;
l__124C:
	emu_get_memory16(emu_ss, emu_bp, -0x20) = emu_dx;
	emu_get_memory16(emu_ss, emu_bp, -0x22) = emu_ax;
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x22);
	emu_orw(&emu_ax, emu_get_memory16(emu_ss, emu_bp, -0x20));
	if (emu_flags.zf) goto l__125D;
	goto l__0FD7;
l__125D:
	emu_get_memory16(emu_ds, 0x00, 0x39E8) = 0x0;
	goto l__1263;
l__1263:
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp, -0x12), 0x0);
	if (emu_flags.zf) goto l__1291;
	emu_ax = 0x200;
	emu_push(emu_ax);
	emu_xorw(&emu_ax, emu_ax);
	emu_push(emu_ax);
	emu_push(emu_ds);
	emu_ax = 0x8DE5;
	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x127A); emu_cs = 0x01F7; emu_Tools_Memset();
	goto l__127A;
l__127A:
	emu_addw(&emu_sp, 0x8);
	emu_ax = 0x200;
	emu_push(emu_ax);
	emu_xorw(&emu_ax, emu_ax);
	emu_push(emu_ax);
	emu_push(emu_ds);
	emu_ax = 0x8FE5;
	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x128E); emu_cs = 0x01F7; emu_Tools_Memset();
	goto l__128E;
l__128E:
	emu_addw(&emu_sp, 0x8);
	goto l__1291;
l__1291:
	emu_cmpw(&emu_get_memory16(emu_ds, 0x00, 0x3344), 0x0);
	if (!emu_flags.zf) goto l__129B;
	goto l__13D0;
l__129B:
	emu_xorw(&emu_si, emu_si);
	emu_xorw(&emu_di, emu_di);
	emu_get_memory16(emu_ss, emu_bp, -0x1A) = 0x2;
	emu_get_memory16(emu_ss, emu_bp, -0xE) = 0x0;
	goto l__131B;
l__12AB:
	emu_bx = emu_get_memory16(emu_ss, emu_bp, -0xE);
	emu_shlw(&emu_bx, 0x1);
	emu_ax = emu_get_memory16(emu_ds, emu_bx, 0x8290);
	emu_get_memory16(emu_ss, emu_bp, -0x10) = emu_ax;
	emu_bx = emu_get_memory16(emu_ss, emu_bp, -0x10);
	emu_cl = 0x3;
	emu_sarw(&emu_bx, emu_cl);
	emu_cl = emu_get_memory8(emu_ss, emu_bp, -0x10);
	emu_andb(&emu_cl, 0x7);
	emu_al = 0x1;
	emu_shlb(&emu_al, emu_cl);
	emu_notb(&emu_al, emu_al);
	emu_andb(&emu_get_memory8(emu_ds, emu_bx, 0x91E5), emu_al);
	emu_orw(&emu_si, emu_si);
	if (!emu_flags.zf) goto l__12EC;
	emu_si = 0x1;
	emu_ax = 0x2;
	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x12DE); emu_cs = 0x2598; f__2598_0000_0017_EB80();
	goto l__12DE;
l__12DE:
	emu_pop(&emu_cx);
	emu_get_memory16(emu_ss, emu_bp, -0x1A) = emu_ax;
	emu_ax = 0x3;
	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x12EB); emu_cs = 0x2642; f__2642_0002_005E_87F6();
	goto l__12EB;
l__12EB:
	emu_pop(&emu_cx);
	goto l__12EC;
l__12EC:
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x10));
	emu_push(emu_cs);
	emu_push(0x12F3); f__07D4_1625_001A_07E5();
	goto l__12F3;
l__12F3:
	emu_pop(&emu_cx);
	emu_orw(&emu_di, emu_di);
	if (emu_flags.zf) {
		emu_bx = emu_get_memory16(emu_ss, emu_bp, -0x10);
		emu_cl = 0x3;
		emu_sarw(&emu_bx, emu_cl);
		emu_al = emu_get_memory8(emu_ds, emu_bx, 0x93E5);
		emu_ah = 0x0;
		emu_cl = emu_get_memory8(emu_ss, emu_bp, -0x10);
		emu_andb(&emu_cl, 0x7);
		emu_dx = 0x1;
		emu_shlw(&emu_dx, emu_cl);
		emu_testw(&emu_ax, emu_dx);
		if (!emu_flags.zf) {
			emu_di = 0x1;
		}
	}
	goto l__1318;
l__1318:
	emu_incw(&emu_get_memory16(emu_ss, emu_bp, -0xE));
	goto l__131B;
l__131B:
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0xE);
	emu_cmpw(&emu_ax, emu_get_memory16(emu_ds, 0x00, 0x3344));
	if (!(emu_flags.sf != emu_flags.of)) goto l__1326;
	goto l__12AB;
l__1326:
	emu_orw(&emu_di, emu_di);
	if (emu_flags.zf) goto l__1339;
	emu_ax = 0x1;
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x39FC));
	emu_push(emu_cs); emu_push(0x1337); emu_cs = 0x0F78; f__0F78_0008_002C_AB63();
	goto l__1337;
l__1337:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	goto l__1339;
l__1339:
	emu_orw(&emu_si, emu_si);
	if (emu_flags.zf) goto l__1372;
	emu_xorw(&emu_ax, emu_ax);
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x6C91));
	emu_ax = 0x40;
	emu_push(emu_ax);
	emu_ax = 0x8;
	emu_push(emu_ax);
	emu_ax = 0x88;
	emu_push(emu_ax);
	emu_ax = 0x20;
	emu_push(emu_ax);
	emu_ax = 0x88;
	emu_push(emu_ax);
	emu_ax = 0x20;
	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x1361); emu_cs = 0x24D0; f__24D0_000D_0039_C17D();
	goto l__1361;
l__1361:
	emu_addw(&emu_sp, 0x10);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x1A));
	emu_push(emu_cs); emu_push(0x136C); emu_cs = 0x2598; f__2598_0000_0017_EB80();
	goto l__136C;
l__136C:
	emu_pop(&emu_cx);
	emu_push(emu_cs); emu_push(0x1372); emu_cs = 0x2642; f__2642_0069_0008_D517();
	goto l__1372;
l__1372:
	emu_cmpw(&emu_get_memory16(emu_ds, 0x00, 0x3344), 0xC8);
	if (!emu_flags.zf) goto l__13CA;
	emu_get_memory16(emu_ds, 0x00, 0x3344) = 0x0;
	emu_get_memory16(emu_ss, emu_bp, -0xE) = 0x0;
	goto l__13C1;
l__1387:
	emu_bx = emu_get_memory16(emu_ss, emu_bp, -0xE);
	emu_cl = 0x3;
	emu_sarw(&emu_bx, emu_cl);
	emu_al = emu_get_memory8(emu_ds, emu_bx, 0x91E5);
	emu_ah = 0x0;
	emu_cl = emu_get_memory8(emu_ss, emu_bp, -0xE);
	emu_andb(&emu_cl, 0x7);
	emu_dx = 0x1;
	emu_shlw(&emu_dx, emu_cl);
	emu_testw(&emu_ax, emu_dx);
	if (emu_flags.zf) goto l__13BE;
	emu_bx = emu_get_memory16(emu_ds, 0x00, 0x3344);
	emu_shlw(&emu_bx, 0x1);
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0xE);
	emu_get_memory16(emu_ds, emu_bx, 0x8290) = emu_ax;
	emu_incw(&emu_get_memory16(emu_ds, 0x00, 0x3344));
	emu_cmpw(&emu_get_memory16(emu_ds, 0x00, 0x3344), 0xC8);
	if (!emu_flags.zf) goto l__13BE;
	goto l__13C8;
l__13BE:
	emu_incw(&emu_get_memory16(emu_ss, emu_bp, -0xE));
	goto l__13C1;
l__13C1:
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp, -0xE), 0x1000);
	if ((emu_flags.sf != emu_flags.of)) goto l__1387;
	goto l__13C8;
l__13C8:
	goto l__13D0;
l__13CA:
	emu_get_memory16(emu_ds, 0x00, 0x3344) = 0x0;
	goto l__13D0;
l__13D0:
	emu_testw(&emu_get_memory16(emu_ds, 0x00, 0x37BA), 0x1);
	if (emu_flags.zf) goto l__1426;
	emu_ax = emu_get_memory16(emu_ds, 0x00, 0x37BC);
	emu_orw(&emu_ax, emu_get_memory16(emu_ds, 0x00, 0x37BE));
	if (emu_flags.zf) goto l__1426;
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp, -0x36), 0xE);
	if (!(emu_flags.zf || emu_flags.sf != emu_flags.of)) {
		emu_cmpw(&emu_get_memory16(emu_ss, emu_bp, -0x4A), 0x0);
		if ((emu_flags.sf != emu_flags.of)) {
			emu_cmpw(&emu_get_memory16(emu_ss, emu_bp,  0x8), 0x0);
			if (emu_flags.zf) {
				emu_cmpw(&emu_get_memory16(emu_ss, emu_bp,  0x6), 0x0);
				if (emu_flags.zf) goto l__1426;
			}
		}
	}
	goto l__13F9;
l__13F9:
	emu_ax = 0x132;
	emu_push(emu_ax);
	emu_xorw(&emu_ax, emu_ax);
	emu_push(emu_ax);
	emu_ax = 0xF;
	emu_push(emu_ax);
	emu_ax = 0x8B;
	emu_push(emu_ax);
	emu_ax = 0x70;
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x37BE));
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x37BC));
	emu_push(emu_cs); emu_push(0x1419); emu_cs = 0x10E4; f__10E4_1EF1_0040_01F8();
	goto l__1419;
l__1419:
	emu_addw(&emu_sp, 0xE);
	emu_get_memory16(emu_ss, emu_bp, -0x36) = 0xFFFF;
	emu_get_memory16(emu_ss, emu_bp, -0x4A) = 0xE;
	goto l__1426;
l__1426:
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp, -0x12), 0x0);
	if (!emu_flags.zf) goto l__142F;
	goto l__155C;
l__142F:
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp,  0xA), 0x0);
	if (emu_flags.zf) goto l__1438;
	goto l__155C;
l__1438:
	emu_cmpw(&emu_get_memory16(emu_ds, 0x00, 0x3A14), 0x0);
	if (emu_flags.zf) goto l__147E;
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x6D5D));
	emu_push(emu_cs); emu_push(0x1448); emu_cs = 0x2642; f__2642_0002_005E_87F6();
	goto l__1448;
l__1448:
	emu_pop(&emu_cx);
	emu_xorw(&emu_ax, emu_ax);
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x6C91));
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x9931));
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x992F));
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x992B));
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x992D));
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x992B));
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x992D));
	emu_push(emu_cs); emu_push(0x146D); emu_cs = 0x2C17; f__2C17_000C_002F_3016();
	goto l__146D;
l__146D:
	emu_addw(&emu_sp, 0x10);
	emu_push(emu_cs); emu_push(0x1475); emu_cs = 0x2642; f__2642_0069_0008_D517();
	goto l__1475;
l__1475:
	emu_get_memory16(emu_ds, 0x00, 0x3A14) = 0x0;
	goto l__155C;
l__147E:
	emu_xorw(&emu_si, emu_si);
	emu_get_memory16(emu_ss, emu_bp, -0xE) = 0x0;
	goto l__154A;
l__1488:
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp,  0x8), 0x0);
	if (!emu_flags.zf) {
		emu_bx = emu_get_memory16(emu_ss, emu_bp, -0xE);
		emu_shlw(&emu_bx, 0x1);
		emu_movw(&emu_ax, emu_bp - 0x42);
		emu_addw(&emu_bx, emu_ax);
		emu_get_memory16(emu_ss, emu_bx, 0x0) = 0x0;
		emu_bx = emu_get_memory16(emu_ss, emu_bp, -0xE);
		emu_shlw(&emu_bx, 0x1);
		emu_movw(&emu_ax, emu_bp - 0x56);
		emu_addw(&emu_bx, emu_ax);
		emu_get_memory16(emu_ss, emu_bx, 0x0) = 0xE;
	}
	goto l__14AC;
l__14AC:
	emu_bx = emu_get_memory16(emu_ss, emu_bp, -0xE);
	emu_shlw(&emu_bx, 0x1);
	emu_movw(&emu_ax, emu_bp - 0x56);
	emu_addw(&emu_bx, emu_ax);
	emu_ax = emu_get_memory16(emu_ss, emu_bx, 0x0);
	emu_bx = emu_get_memory16(emu_ss, emu_bp, -0xE);
	emu_shlw(&emu_bx, 0x1);
	emu_movw(&emu_dx, emu_bp - 0x42);
	emu_addw(&emu_bx, emu_dx);
	emu_cmpw(&emu_ax, emu_get_memory16(emu_ss, emu_bx, 0x0));
	if (!(emu_flags.sf != emu_flags.of)) goto l__14CB;
	goto l__1547;
l__14CB:
	emu_bx = emu_get_memory16(emu_ss, emu_bp, -0xE);
	emu_shlw(&emu_bx, 0x1);
	emu_movw(&emu_ax, emu_bp - 0x42);
	emu_addw(&emu_bx, emu_ax);
	emu_ax = emu_get_memory16(emu_ss, emu_bx, 0x0);
	emu_shlw(&emu_ax, 0x1);
	emu_get_memory16(emu_ss, emu_bp, -0x2) = emu_ax;
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0xE);
	emu_cl = 0x4;
	emu_shlw(&emu_ax, emu_cl);
	emu_addw(&emu_ax, 0x28);
	emu_get_memory16(emu_ss, emu_bp, -0x4) = emu_ax;
	emu_bx = emu_get_memory16(emu_ss, emu_bp, -0xE);
	emu_shlw(&emu_bx, 0x1);
	emu_movw(&emu_ax, emu_bp - 0x56);
	emu_addw(&emu_bx, emu_ax);
	emu_ax = emu_get_memory16(emu_ss, emu_bx, 0x0);
	emu_bx = emu_get_memory16(emu_ss, emu_bp, -0xE);
	emu_shlw(&emu_bx, 0x1);
	emu_movw(&emu_dx, emu_bp - 0x42);
	emu_addw(&emu_bx, emu_dx);
	emu_subw(&emu_ax, emu_get_memory16(emu_ss, emu_bx, 0x0));
	emu_incw(&emu_ax);
	emu_shlw(&emu_ax, 0x1);
	emu_get_memory16(emu_ss, emu_bp, -0x6) = emu_ax;
	emu_get_memory16(emu_ss, emu_bp, -0x8) = 0x10;
	emu_orw(&emu_si, emu_si);
	if (!emu_flags.zf) goto l__1526;
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x6D5D));
	emu_push(emu_cs); emu_push(0x151C); emu_cs = 0x2642; f__2642_0002_005E_87F6();
	goto l__151C;
l__151C:
	emu_pop(&emu_cx);
	emu_si = 0x1;
	emu_get_memory16(emu_ds, 0x00, 0x37A4) = 0x0;
	goto l__1526;
l__1526:
	emu_xorw(&emu_ax, emu_ax);
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x6C91));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x8));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x6));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x4));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x2));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x4));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x2));
	emu_push(emu_cs); emu_push(0x1544); emu_cs = 0x24D0; f__24D0_000D_0039_C17D();
	goto l__1544;
l__1544:
	emu_addw(&emu_sp, 0x10);
	goto l__1547;
l__1547:
	emu_incw(&emu_get_memory16(emu_ss, emu_bp, -0xE));
	goto l__154A;
l__154A:
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp, -0xE), 0xA);
	if (!(emu_flags.sf != emu_flags.of)) goto l__1553;
	goto l__1488;
l__1553:
	emu_orw(&emu_si, emu_si);
	if (!emu_flags.zf) {
		emu_push(emu_cs); emu_push(0x155C); emu_cs = 0x2642; f__2642_0069_0008_D517();
	}
	goto l__155C;
l__155C:
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x14));
	emu_push(emu_cs); emu_push(0x1564); emu_cs = 0x2598; f__2598_0000_0017_EB80();
	goto l__1564;
l__1564:
	emu_pop(&emu_cx);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x16));
	emu_push(emu_cs); emu_push(0x156D); emu_cs = 0x07AE; f__07AE_0000_00DF_A32C();
	goto l__156D;
l__156D:
	emu_pop(&emu_cx);
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
 * Decompiled function f__07D4_159A_001D_F971()
 *
 * @name f__07D4_159A_001D_F971
 * @implements 07D4:159A:001D:F971 ()
 * @implements 07D4:15B7:0008:AD1A
 * @implements 07D4:15BB:0004:EAF9
 * @implements 07D4:15BF:0005:BFA8
 * @implements 07D4:15C4:0016:4DD5
 * @implements 07D4:15C7:0013:6F1B
 * @implements 07D4:15DA:000E:A50F
 * @implements 07D4:15E8:000A:E2DD
 * @implements 07D4:15F2:0025:4D45
 * @implements 07D4:1617:0008:C54E
 * @implements 07D4:161F:0006:F7CE
 *
 * Called From: 10E4:2130:0012:8D21
 * Called From: B4CD:0F70:0008:D74D
 */
void f__07D4_159A_001D_F971()
{
l__159A:
	emu_push(emu_bp);
	emu_bp = emu_sp;
	emu_subw(&emu_sp, 0x2);
	emu_push(emu_si);
	emu_push(emu_di);
	emu_di = emu_get_memory16(emu_ss, emu_bp,  0x6);
	emu_get_memory16(emu_ss, emu_bp, -0x2) = 0x0;
	emu_orw(&emu_di, emu_di);
	if (!emu_flags.zf) goto l__15BB;
	emu_ax = 0x2;
	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x15B7); emu_cs = 0x2598; f__2598_0000_0017_EB80();
	goto l__15B7;
l__15B7:
	emu_pop(&emu_cx);
	emu_get_memory16(emu_ss, emu_bp, -0x2) = emu_ax;
	goto l__15BB;
l__15BB:
	emu_xorw(&emu_si, emu_si);
	goto l__15C7;
l__15BF:
	emu_push(emu_si);
	emu_push(emu_cs);
	emu_push(0x15C4); f__07D4_1625_001A_07E5();
	goto l__15C4;
l__15C4:
	emu_pop(&emu_cx);
	emu_incw(&emu_si);
	goto l__15C7;
l__15C7:
	emu_cmpw(&emu_si, 0x1000);
	if ((emu_flags.sf != emu_flags.of)) goto l__15BF;
	emu_ax = 0x1;
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x39FC));
	emu_push(emu_cs); emu_push(0x15DA); emu_cs = 0x0F78; f__0F78_0008_002C_AB63();
	goto l__15DA;
l__15DA:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	emu_orw(&emu_di, emu_di);
	if (!emu_flags.zf) goto l__161F;
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x2));
	emu_push(emu_cs); emu_push(0x15E8); emu_cs = 0x2598; f__2598_0000_0017_EB80();
	goto l__15E8;
l__15E8:
	emu_pop(&emu_cx);
	emu_ax = 0x3;
	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x15F2); emu_cs = 0x2642; f__2642_0002_005E_87F6();
	goto l__15F2;
l__15F2:
	emu_pop(&emu_cx);
	emu_xorw(&emu_ax, emu_ax);
	emu_push(emu_ax);
	emu_ax = 0x2;
	emu_push(emu_ax);
	emu_ax = 0x40;
	emu_push(emu_ax);
	emu_ax = 0x8;
	emu_push(emu_ax);
	emu_ax = 0x88;
	emu_push(emu_ax);
	emu_ax = 0x20;
	emu_push(emu_ax);
	emu_ax = 0x88;
	emu_push(emu_ax);
	emu_ax = 0x20;
	emu_push(emu_ax);
	emu_push(emu_cs); emu_push(0x1617); emu_cs = 0x24D0; f__24D0_000D_0039_C17D();
	goto l__1617;
l__1617:
	emu_addw(&emu_sp, 0x10);
	emu_push(emu_cs); emu_push(0x161F); emu_cs = 0x2642; f__2642_0069_0008_D517();
	goto l__161F;
l__161F:
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
 * Decompiled function f__07D4_1625_001A_07E5()
 *
 * @name f__07D4_1625_001A_07E5
 * @implements 07D4:1625:001A:07E5 ()
 * @implements 07D4:163F:0008:04D1
 * @implements 07D4:1647:000C:40AE
 * @implements 07D4:1653:0012:553F
 * @implements 07D4:1665:0008:F68F
 * @implements 07D4:166D:0023:2B60
 * @implements 07D4:1690:002A:C5EA
 * @implements 07D4:16B0:000A:AEB9
 * @implements 07D4:16BA:0008:A909
 * @implements 07D4:16C2:0020:50B6
 * @implements 07D4:16E2:0050:F2D5
 * @implements 07D4:16F3:003F:17D9
 * @implements 07D4:1732:0019:5B9D
 * @implements 07D4:1743:0008:9905
 * @implements 07D4:174B:0027:57D5
 * @implements 07D4:1772:000B:ED14
 * @implements 07D4:177D:000F:406D
 * @implements 07D4:178C:0011:6FA3
 * @implements 07D4:179D:000B:ED14
 * @implements 07D4:17A8:0012:DA6D
 * @implements 07D4:17B8:0002:F6BA
 * @implements 07D4:17BA:0008:D904
 * @implements 07D4:17C2:0037:AF83
 * @implements 07D4:17F9:0018:6A1E
 * @implements 07D4:180F:0002:CB3A
 * @implements 07D4:1811:0011:2BD8
 * @implements 07D4:1822:006E:C38D
 * @implements 07D4:1827:0069:7F32
 * @implements 07D4:1890:0005:8AEE
 * @implements 07D4:1895:001B:E447
 * @implements 07D4:18B0:000D:BA27
 * @implements 07D4:18B3:000A:6E63
 * @implements 07D4:18B7:0006:F7CE
 *
 * Called From: 07D4:12F0:0008:FBF3
 * Called From: 07D4:12F0:0007:A2F3
 * Called From: 07D4:15C1:0005:BFA8
 * Called From: 0F78:0087:002F:3722
 */
void f__07D4_1625_001A_07E5()
{
l__1625:
	emu_push(emu_bp);
	emu_bp = emu_sp;
	emu_subw(&emu_sp, 0x12);
	emu_push(emu_si);
	emu_push(emu_di);
	emu_get_memory16(emu_ss, emu_bp, -0x6) = 0xC;
	emu_di = 0xFFFF;
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp,  0x6), 0x1000);
	if ((emu_flags.zf || emu_flags.sf != emu_flags.of)) goto l__163F;
	goto l__18B7;
l__163F:
	emu_push(emu_get_memory16(emu_ss, emu_bp,  0x6));
	emu_push(emu_cs); emu_push(0x1647); emu_cs = 0x0F3F; f__0F3F_0322_0011_5AAA();
	goto l__1647;
l__1647:
	emu_pop(&emu_cx);
	emu_get_memory16(emu_ss, emu_bp, -0x2) = emu_ax;
	emu_push(emu_get_memory16(emu_ss, emu_bp,  0x6));
	emu_push(emu_cs); emu_push(0x1653); emu_cs = 0x0F3F; f__0F3F_0335_0015_2275();
	goto l__1653;
l__1653:
	emu_pop(&emu_cx);
	emu_get_memory16(emu_ss, emu_bp, -0x4) = emu_ax;
	emu_ax = emu_get_memory16(emu_ds, 0x00, 0x8D09);
	emu_incw(&emu_ax);
	emu_si = emu_ax;
	emu_push(emu_get_memory16(emu_ss, emu_bp,  0x6));
	emu_push(emu_cs); emu_push(0x1665); emu_cs = 0x34CD; ovl__34CD(11);
	goto l__1665;
l__1665:
	emu_pop(&emu_cx);
	emu_orw(&emu_ax, emu_ax);
	if (!emu_flags.zf) goto l__166D;
	goto l__18B7;
l__166D:
	emu_orw(&emu_si, emu_si);
	if (!emu_flags.zf) goto l__1690;
	emu_bx = emu_get_memory16(emu_ss, emu_bp,  0x6);
	emu_cl = 0x3;
	emu_sarw(&emu_bx, emu_cl);
	emu_al = emu_get_memory8(emu_ds, emu_bx, 0x93E5);
	emu_ah = 0x0;
	emu_cl = emu_get_memory8(emu_ss, emu_bp,  0x6);
	emu_andb(&emu_cl, 0x7);
	emu_dx = 0x1;
	emu_shlw(&emu_dx, emu_cl);
	emu_testw(&emu_ax, emu_dx);
	if (emu_flags.zf) goto l__1690;
	goto l__18B7;
l__1690:
	emu_ax = emu_get_memory16(emu_ss, emu_bp,  0x6);
	emu_cl = 0x2;
	emu_shlw(&emu_ax, emu_cl);
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ds, 0x00, 0x39EA));
	emu_addw(&emu_bx, emu_ax);
	emu_testb(&emu_get_memory8(emu_es, emu_bx, 0x2), 0x8);
	if (!emu_flags.zf) {
		emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ds, 0x00, 0x3A3A));
		emu_testw(&emu_get_memory16(emu_es, emu_bx, 0x4), 0x10);
		if (!emu_flags.zf) goto l__16BA;
	}
	goto l__16B0;
l__16B0:
	emu_cmpw(&emu_get_memory16(emu_ds, 0x00, 0x37A0), 0x0);
	if (!emu_flags.zf) goto l__16BA;
	goto l__17BA;
l__16BA:
	emu_push(emu_get_memory16(emu_ss, emu_bp,  0x6));
	emu_push(emu_cs); emu_push(0x16C2); emu_cs = 0x34CD; ovl__34CD(13);
	goto l__16C2;
l__16C2:
	emu_pop(&emu_cx);
	emu_get_memory16(emu_ss, emu_bp, -0x8) = emu_ax;
	emu_cmpw(&emu_si, 0x1);
	if ((emu_flags.zf || emu_flags.sf != emu_flags.of)) goto l__16E2;
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x8);
	emu_dx = 0x1C;
	emu_imuluw(&emu_ax, emu_dx);
	emu_dx = emu_get_memory16(emu_ds, 0x00, 0x8D09);
	emu_bx = emu_ax;
	emu_addw(&emu_dx, emu_get_memory16(emu_ds, emu_bx, 0x3A56));
	emu_decw(&emu_dx);
	emu_di = emu_dx;
	goto l__16F3;
l__16E2:
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x8);
	emu_dx = 0x1C;
	emu_imuluw(&emu_ax, emu_dx);
	emu_bx = emu_ax;
	emu_ax = emu_get_memory16(emu_ds, emu_bx, 0x3A54);
	emu_get_memory16(emu_ss, emu_bp, -0x6) = emu_ax;
	goto l__16F3;
l__16F3:
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x8);
	emu_dx = 0x1C;
	emu_imuluw(&emu_ax, emu_dx);
	emu_bx = emu_ax;
	emu_cmpw(&emu_get_memory16(emu_ds, emu_bx, 0x3A54), 0xFFFF);
	if (emu_flags.zf) {
		emu_ax = emu_get_memory16(emu_ss, emu_bp,  0x6);
		emu_cl = 0x2;
		emu_shlw(&emu_ax, emu_cl);
		emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ds, 0x00, 0x39EA));
		emu_addw(&emu_bx, emu_ax);
		emu_al = emu_get_memory8(emu_es, emu_bx, 0x2);
		emu_ah = 0x0;
		emu_andw(&emu_ax, 0x7);
		emu_get_memory16(emu_ss, emu_bp, -0x12) = emu_ax;
		emu_cmpw(&emu_si, 0x1);
		if ((emu_flags.zf || emu_flags.sf != emu_flags.of)) goto l__1732;
		emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x12);
		emu_shlw(&emu_ax, 0x1);
		emu_dx = emu_si;
		emu_addw(&emu_dx, emu_ax);
		emu_addw(&emu_dx, 0x1D);
		emu_di = emu_dx;
	}
	goto l__1743;
l__1732:
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x12);
	emu_dx = 0x1E;
	emu_imuluw(&emu_ax, emu_dx);
	emu_bx = emu_ax;
	emu_ax = emu_get_memory16(emu_ds, emu_bx, 0x3802);
	emu_get_memory16(emu_ss, emu_bp, -0x6) = emu_ax;
	goto l__1743;
l__1743:
	emu_push(emu_get_memory16(emu_ss, emu_bp,  0x6));
	emu_push(emu_cs); emu_push(0x174B); emu_cs = 0x34CD; ovl__34CD(26);
	goto l__174B;
l__174B:
	emu_pop(&emu_cx);
	emu_get_memory16(emu_ss, emu_bp, -0xA) = emu_dx;
	emu_get_memory16(emu_ss, emu_bp, -0xC) = emu_ax;
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0xC);
	emu_orw(&emu_ax, emu_get_memory16(emu_ss, emu_bp, -0xA));
	if (emu_flags.zf) goto l__17B8;
	emu_cmpw(&emu_si, 0x1);
	if ((emu_flags.zf || emu_flags.sf != emu_flags.of)) goto l__178C;
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0xC));
	emu_cmpb(&emu_get_memory8(emu_es, emu_bx, 0x2), 0x19);
	if (!emu_flags.zf) goto l__1772;
	emu_ax = emu_si;
	emu_addw(&emu_ax, 0x35);
	emu_di = emu_ax;
	/* Unresolved jump */ emu_ip = 0x178A; emu_last_cs = 0x07D4; emu_last_ip = 0x1770; emu_last_length = 0x0027; emu_last_crc = 0x57D5; emu_call();
l__1772:
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0xA));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0xC));
	emu_push(emu_cs); emu_push(0x177D); emu_cs = 0x1A34; emu_Unit_GetHouseID();
	goto l__177D;
l__177D:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	emu_shlw(&emu_ax, 0x1);
	emu_dx = emu_si;
	emu_addw(&emu_dx, emu_ax);
	emu_addw(&emu_dx, 0x1D);
	emu_di = emu_dx;
	goto l__17B8;
l__178C:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0xC));
	emu_cmpb(&emu_get_memory8(emu_es, emu_bx, 0x2), 0x19);
	if (!emu_flags.zf) goto l__179D;
	emu_get_memory16(emu_ss, emu_bp, -0x6) = 0xFF;
	goto l__17B8;
l__179D:
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0xA));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0xC));
	emu_push(emu_cs); emu_push(0x17A8); emu_cs = 0x1A34; emu_Unit_GetHouseID();
	goto l__17A8;
l__17A8:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	emu_dx = 0x1E;
	emu_imuluw(&emu_ax, emu_dx);
	emu_bx = emu_ax;
	emu_ax = emu_get_memory16(emu_ds, emu_bx, 0x3802);
	emu_get_memory16(emu_ss, emu_bp, -0x6) = emu_ax;
	goto l__17B8;
l__17B8:
	goto l__1827;
l__17BA:
	emu_push(emu_get_memory16(emu_ss, emu_bp,  0x6));
	emu_push(emu_cs); emu_push(0x17C2); emu_cs = 0x34CD; ovl__34CD(30);
	goto l__17C2;
l__17C2:
	emu_pop(&emu_cx);
	emu_get_memory16(emu_ss, emu_bp, -0xE) = emu_dx;
	emu_get_memory16(emu_ss, emu_bp, -0x10) = emu_ax;
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x10);
	emu_orw(&emu_ax, emu_get_memory16(emu_ss, emu_bp, -0xE));
	if (emu_flags.zf) goto l__1811;
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x10));
	emu_al = emu_get_memory8(emu_es, emu_bx, 0x8);
	emu_ax = emu_al;
	emu_cmpw(&emu_ax, emu_get_memory16(emu_ds, 0x00, 0x3A38));
	if (!emu_flags.zf) goto l__1811;
	emu_cmpw(&emu_si, 0x1);
	if ((emu_flags.zf || emu_flags.sf != emu_flags.of)) goto l__17F9;
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x10));
	emu_al = emu_get_memory8(emu_es, emu_bx, 0x8);
	emu_ax = emu_al;
	emu_shlw(&emu_ax, 0x1);
	emu_dx = emu_si;
	emu_addw(&emu_dx, emu_ax);
	emu_addw(&emu_dx, 0x1D);
	emu_di = emu_dx;
	goto l__180F;
l__17F9:
	emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp, -0x10));
	emu_al = emu_get_memory8(emu_es, emu_bx, 0x8);
	emu_ax = emu_al;
	emu_dx = 0x1E;
	emu_imuluw(&emu_ax, emu_dx);
	emu_bx = emu_ax;
	emu_ax = emu_get_memory16(emu_ds, emu_bx, 0x3802);
	emu_get_memory16(emu_ss, emu_bp, -0x6) = emu_ax;
	goto l__180F;
l__180F:
	goto l__1827;
l__1811:
	emu_cmpw(&emu_si, 0x1);
	if ((emu_flags.zf || emu_flags.sf != emu_flags.of)) goto l__1822;
	emu_ax = emu_get_memory16(emu_ds, 0x00, 0x8D09);
	emu_addw(&emu_ax, emu_get_memory16(emu_ds, 0x00, 0x3AFE));
	emu_decw(&emu_ax);
	emu_di = emu_ax;
	goto l__1827;
l__1822:
	emu_get_memory16(emu_ss, emu_bp, -0x6) = 0xC;
	goto l__1827;
l__1827:
	emu_bx = emu_get_memory16(emu_ds, 0x00, 0x8D09);
	emu_cl = 0x3;
	emu_shlw(&emu_bx, emu_cl);
	emu_ax = emu_get_memory16(emu_ds, emu_bx, 0x3C0E);
	emu_subw(&emu_get_memory16(emu_ss, emu_bp, -0x2), emu_ax);
	emu_bx = emu_get_memory16(emu_ds, 0x00, 0x8D09);
	emu_cl = 0x3;
	emu_shlw(&emu_bx, emu_cl);
	emu_ax = emu_get_memory16(emu_ds, emu_bx, 0x3C10);
	emu_subw(&emu_get_memory16(emu_ss, emu_bp, -0x4), emu_ax);
	emu_cmpw(&emu_di, 0xFFFF);
	if (emu_flags.zf) goto l__1895;
	emu_dx = emu_get_memory16(emu_ds, 0x00, 0x8D09);
	emu_incw(&emu_dx);
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x2);
	emu_imuluw(&emu_ax, emu_dx);
	emu_get_memory16(emu_ss, emu_bp, -0x2) = emu_ax;
	emu_dx = emu_get_memory16(emu_ds, 0x00, 0x8D09);
	emu_incw(&emu_dx);
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x4);
	emu_imuluw(&emu_ax, emu_dx);
	emu_get_memory16(emu_ss, emu_bp, -0x4) = emu_ax;
	emu_ax = 0x4000;
	emu_push(emu_ax);
	emu_ax = 0x3;
	emu_push(emu_ax);
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x4));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x2));
	emu_bx = emu_di;
	emu_cl = 0x2;
	emu_shlw(&emu_bx, emu_cl);
	emu_ax = 0x2DCE;
	emu_es = emu_ax;
	emu_push(emu_get_memory16(emu_es, emu_bx, 0x442));
	emu_push(emu_get_memory16(emu_es, emu_bx, 0x440));
	emu_push(emu_get_memory16(emu_ds, 0x00, 0x6C91));
	emu_push(emu_cs); emu_push(0x1890); emu_cs = 0x2903; f__2903_0158_001A_2931();
	goto l__1890;
l__1890:
	emu_addw(&emu_sp, 0xE);
	goto l__18B3;
l__1895:
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x6));
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x4);
	emu_addw(&emu_ax, 0x88);
	emu_push(emu_ax);
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x2);
	emu_addw(&emu_ax, 0x100);
	emu_push(emu_ax);
	emu_ax = 0x353F;
	emu_es = emu_ax;

	/* Call based on memory/register values */
	emu_ip = emu_get_memory16(emu_es, 0x00, 0x66A0);
	emu_push(emu_cs);
	emu_cs = emu_get_memory16(emu_es, 0x00, 0x66A2);
	emu_push(0x18B0);
	switch ((emu_cs << 16) + emu_ip) {
		case 0x22A60F76: f__22A6_0F76_002C_45CC(); break;
		default:
			/* In case we don't know the call point yet, call the dynamic call */
			emu_last_cs = 0x07D4; emu_last_ip = 0x18AB; emu_last_length = 0x001B; emu_last_crc = 0xE447;
			emu_call();
			return;
	}
	goto l__18B0;
l__18B0:
	emu_addw(&emu_sp, 0x6);
	goto l__18B3;
l__18B3:
	emu_incw(&emu_get_memory16(emu_ds, 0x00, 0x37A6));
	goto l__18B7;
l__18B7:
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
 * Decompiled function f__07D4_18BD_0016_68BB()
 *
 * @name f__07D4_18BD_0016_68BB
 * @implements 07D4:18BD:0016:68BB ()
 * @implements 07D4:18D0:0003:9D04
 * @implements 07D4:18D3:0026:670B
 * @implements 07D4:18F9:000B:8253
 * @implements 07D4:1904:0009:6BA3
 * @implements 07D4:190E:0057:050D
 * @implements 07D4:1943:0022:E93A
 * @implements 07D4:1952:0013:DC4D
 * @implements 07D4:195C:0009:9B3E
 * @implements 07D4:1965:0006:F7CE
 *
 * Called From: 07D4:0677:000E:965C
 * Called From: 07D4:0B49:0008:A09F
 * Called From: 07D4:0B49:0006:F92D
 * Called From: 07D4:0C3E:0008:E01C
 * Called From: 07D4:0D72:0008:E391
 * Called From: 07D4:0F6C:0023:CCB8
 * Called From: 07D4:11B8:0008:6583
 */
void f__07D4_18BD_0016_68BB()
{
l__18BD:
	emu_push(emu_bp);
	emu_bp = emu_sp;
	emu_subw(&emu_sp, 0xE);
	emu_push(emu_si);
	emu_push(emu_di);
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp,  0x6), 0x163);
	if ((emu_flags.zf || emu_flags.sf != emu_flags.of)) goto l__18D3;
	emu_xorw(&emu_dx, emu_dx);
	emu_xorw(&emu_ax, emu_ax);
	goto l__18D0;
l__18D0:
	goto l__1965;
l__18D3:
	emu_bx = emu_get_memory16(emu_ss, emu_bp,  0x6);
	emu_cl = 0x2;
	emu_shlw(&emu_bx, emu_cl);
	emu_ax = 0x2DCE;
	emu_es = emu_ax;
	emu_ax = emu_get_memory16(emu_es, emu_bx, 0x442);
	emu_dx = emu_get_memory16(emu_es, emu_bx, 0x440);
	emu_get_memory16(emu_ss, emu_bp, -0x2) = emu_ax;
	emu_get_memory16(emu_ss, emu_bp, -0x4) = emu_dx;
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x4);
	emu_orw(&emu_ax, emu_get_memory16(emu_ss, emu_bp, -0x2));
	if (!emu_flags.zf) goto l__18F9;
	/* Unresolved jump */ emu_ip = 0x18CC; emu_last_cs = 0x07D4; emu_last_ip = 0x18F7; emu_last_length = 0x0026; emu_last_crc = 0x670B; emu_call();
l__18F9:
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x2));
	emu_push(emu_get_memory16(emu_ss, emu_bp, -0x4));
	emu_push(emu_cs); emu_push(0x1904); emu_cs = 0x2903; f__2903_00CA_0015_756E();
	goto l__1904;
l__1904:
	emu_pop(&emu_cx);
	emu_pop(&emu_cx);
	emu_testw(&emu_ax, 0x1);
	if (!emu_flags.zf) goto l__190E;
	goto l__195C;
l__190E:
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x2);
	emu_dx = emu_get_memory16(emu_ss, emu_bp, -0x4);
	emu_get_memory16(emu_ss, emu_bp, -0x8) = emu_ax;
	emu_get_memory16(emu_ss, emu_bp, -0xA) = emu_dx;
	emu_addw(&emu_get_memory16(emu_ss, emu_bp, -0xA), 0xA);
	emu_get_memory16(emu_ss, emu_bp, -0xC) = emu_ds;
	emu_get_memory16(emu_ss, emu_bp, -0xE) = 0x8420;
	emu_ax = emu_get_memory16(emu_ss, emu_bp,  0x8);
	emu_cl = 0x4;
	emu_shlw(&emu_ax, emu_cl);
	emu_get_memory16(emu_ss, emu_bp, -0x6) = emu_ax;
	emu_push(emu_ds);
	emu_push(emu_es);
	emu_push(emu_di);
	emu_push(emu_si);
	emu_push(emu_ax);
	emu_push(emu_bx);
	emu_push(emu_cx);
	emu_lfp(&emu_ds, &emu_si, &emu_get_memory16(emu_ss, emu_bp, -0xA));
	emu_lfp(&emu_es, &emu_di, &emu_get_memory16(emu_ss, emu_bp, -0xE));
	emu_bx = emu_get_memory16(emu_ss, emu_bp, -0x6);
	emu_cx = 0x10;
	goto l__1943;
l__1943:
	emu_lodsb(emu_ds);
	emu_cmpb(&emu_al, 0x90);
	if (!(emu_flags.sf != emu_flags.of)) {
		emu_cmpb(&emu_al, 0x98);
		if ((emu_flags.zf || emu_flags.sf != emu_flags.of)) {
			emu_cmpb(&emu_al, 0xFF);
			if (emu_flags.zf) { /* Unresolved jump */ emu_ip = 0x1955; emu_last_cs = 0x07D4; emu_last_ip = 0x194E; emu_last_length = 0x0022; emu_last_crc = 0xE93A; emu_call(); return; }
			emu_addb(&emu_al, emu_bl);
		}
	}
	goto l__1952;
l__1952:
	emu_stosb();
	if (--emu_cx != 0) goto l__1943;
	emu_pop(&emu_cx);
	emu_pop(&emu_bx);
	emu_pop(&emu_ax);
	emu_pop(&emu_si);
	emu_pop(&emu_di);
	emu_pop(&emu_es);
	emu_pop(&emu_ds);
	goto l__195C;
l__195C:
	emu_dx = emu_get_memory16(emu_ss, emu_bp, -0x2);
	emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x4);
	goto l__18D0;
l__1965:
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
 * Decompiled function f__07D4_196B_0073_56C1()
 *
 * @name f__07D4_196B_0073_56C1
 * @implements 07D4:196B:0073:56C1 ()
 * @implements 07D4:19AF:002F:75C1
 * @implements 07D4:19C0:001E:03DD
 * @implements 07D4:19DA:0004:EAB9
 * @implements 07D4:19DC:0002:C2BA
 * @implements 07D4:19DE:0005:A97A
 * @implements 07D4:19E3:0004:893F
 *
 * Called From: 07D4:069F:0028:4EFB
 * Called From: 07D4:06E3:001C:B1AC
 * Called From: 07D4:06E3:0019:3A04
 * Called From: 07D4:0727:001C:B1A3
 * Called From: 07D4:0727:0019:3A0B
 * Called From: 07D4:077D:002E:5463
 * Called From: 07D4:077D:002B:7689
 * Called From: 07D4:0A04:0031:066B
 * Called From: 07D4:0F49:0019:6454
 * Called From: 07D4:10A4:0031:05C3
 * Called From: 176C:06F4:0029:3063
 */
void f__07D4_196B_0073_56C1()
{
l__196B:
	emu_push(emu_bp);
	emu_bp = emu_sp;
	emu_subw(&emu_sp, 0x4);
	emu_cl = 0x4;
	emu_ax = emu_get_memory16(emu_ss, emu_bp,  0x6);
	emu_shrw(&emu_ax, emu_cl);
	emu_bx = emu_get_memory16(emu_ds, 0x00, 0x39FE);
	emu_andw(&emu_bx, 0x3F);
	emu_shlw(&emu_bx, emu_cl);
	emu_subw(&emu_ax, emu_bx);
	emu_get_memory16(emu_ss, emu_bp, -0x2) = emu_ax;
	emu_cl = 0x4;
	emu_ax = emu_get_memory16(emu_ss, emu_bp,  0x8);
	emu_shrw(&emu_ax, emu_cl);
	emu_bx = emu_get_memory16(emu_ds, 0x00, 0x39FE);
	emu_andw(&emu_bx, 0xFC0);
	emu_cl = 0x2;
	emu_shrw(&emu_bx, emu_cl);
	emu_subw(&emu_ax, emu_bx);
	emu_get_memory16(emu_ss, emu_bp, -0x4) = emu_ax;
	emu_ax = emu_get_memory16(emu_ss, emu_bp,  0xA);
	emu_orw(&emu_ax, emu_get_memory16(emu_ss, emu_bp,  0xC));
	if (!emu_flags.zf) {
		emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp,  0xA));
		emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x2);
		emu_get_memory16(emu_es, emu_bx, 0x0) = emu_ax;
	}
	goto l__19AF;
l__19AF:
	emu_ax = emu_get_memory16(emu_ss, emu_bp,  0xE);
	emu_orw(&emu_ax, emu_get_memory16(emu_ss, emu_bp,  0x10));
	if (!emu_flags.zf) {
		emu_lfp(&emu_es, &emu_bx, &emu_get_memory16(emu_ss, emu_bp,  0xE));
		emu_ax = emu_get_memory16(emu_ss, emu_bp, -0x4);
		emu_get_memory16(emu_es, emu_bx, 0x0) = emu_ax;
	}
	goto l__19C0;
l__19C0:
	emu_cmpw(&emu_get_memory16(emu_ss, emu_bp, -0x2), 0xFFF0);
	if (!(emu_flags.sf != emu_flags.of)) {
		emu_cmpw(&emu_get_memory16(emu_ss, emu_bp, -0x2), 0x100);
		if ((emu_flags.zf || emu_flags.sf != emu_flags.of)) {
			emu_cmpw(&emu_get_memory16(emu_ss, emu_bp, -0x4), 0xFFF0);
			if (!(emu_flags.sf != emu_flags.of)) {
				emu_cmpw(&emu_get_memory16(emu_ss, emu_bp, -0x4), 0xB0);
				if ((emu_flags.zf || emu_flags.sf != emu_flags.of)) goto l__19DE;
			}
		}
	}
	goto l__19DA;
l__19DA:
	emu_xorw(&emu_ax, emu_ax);
	goto l__19DC;
l__19DC:
	goto l__19E3;
l__19DE:
	emu_ax = 0x1;
	goto l__19DC;
l__19E3:
	emu_sp = emu_bp;
	emu_pop(&emu_bp);

	/* Return from this function */
	emu_pop(&emu_ip);
	emu_pop(&emu_cs);
	return;
}
