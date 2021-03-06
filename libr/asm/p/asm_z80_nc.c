/* radare - LGPL - Copyright 2012-2013 - pancake */

#include <r_types.h>
#include <r_util.h>
#include <r_lib.h>
#include <r_asm.h>
#include "../arch/z80_nc/disasm.c"

static int do_disassemble(RAsm *a, RAsmOp *op, const ut8 *buf, int len) {
	int dlen = z80dis (0, buf, op->buf_asm, len);
	if (dlen<0) dlen = 0;
	op->size = dlen;
	return op->size;
}

RAsmPlugin r_asm_plugin_z80 = {
	.name = "z80.nc",
	.desc = "Zilog Z80 non-commerical",
	.license = "NC-GPL2", //NON-COMMERCIAL",
	.arch = "z80",
	.bits = 8,
	.endian = R_SYS_ENDIAN_NONE,
	.disassemble = &do_disassemble,
};

#ifndef CORELIB
struct r_lib_struct_t radare_plugin = {
	.type = R_LIB_TYPE_ASM,
	.data = &r_asm_plugin_z80,
	.version = R2_VERSION
};
#endif
