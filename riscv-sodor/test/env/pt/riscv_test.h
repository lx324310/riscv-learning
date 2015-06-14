#ifndef _ENV_PHYSICAL_SINGLE_CORE_TIMER_H
#define _ENV_PHYSICAL_SINGLE_CORE_TIMER_H

#include "../p/riscv_test.h"

#undef EXTRA_INIT
#define EXTRA_INIT                                                      \
  ENABLE_TIMER_INTERRUPT;                                               \
  b 6f;                                                                 \
  XCPT_HANDLER;                                                         \
6:

//-----------------------------------------------------------------------
// Data Section Macro
//-----------------------------------------------------------------------

#undef EXTRA_DATA
#define EXTRA_DATA                 \
        .align 3;                  \
regspill:                          \
        .dword 0xdeadbeefcafebabe; \
        .dword 0xdeadbeefcafebabe; \
        .dword 0xdeadbeefcafebabe; \
        .dword 0xdeadbeefcafebabe; \
        .dword 0xdeadbeefcafebabe; \
        .dword 0xdeadbeefcafebabe; \
        .dword 0xdeadbeefcafebabe; \
        .dword 0xdeadbeefcafebabe; \
        .dword 0xdeadbeefcafebabe; \
        .dword 0xdeadbeefcafebabe; \
        .dword 0xdeadbeefcafebabe; \
        .dword 0xdeadbeefcafebabe; \
        .dword 0xdeadbeefcafebabe; \
        .dword 0xdeadbeefcafebabe; \
        .dword 0xdeadbeefcafebabe; \
        .dword 0xdeadbeefcafebabe; \
        .dword 0xdeadbeefcafebabe; \
        .dword 0xdeadbeefcafebabe; \
        .dword 0xdeadbeefcafebabe; \
        .dword 0xdeadbeefcafebabe; \
        .dword 0xdeadbeefcafebabe; \
        .dword 0xdeadbeefcafebabe; \
        .dword 0xdeadbeefcafebabe; \
        .dword 0xdeadbeefcafebabe; \
evac:                              \
        .skip 32768;               \

//-----------------------------------------------------------------------
// Misc
//-----------------------------------------------------------------------

#define ENABLE_TIMER_INTERRUPT \
        csrw clear_ipi,x0;           \
        csrr a0,status;              \
        li a1,SR_IM;                 \
        or a0,a0,a1;                 \
        csrw status,a0;              \
        csrs status,SR_EI;           \
        la a0,_handler;              \
        csrw evec,a0;                \
        csrw count,x0;               \
        addi a0,x0,60;               \
        csrw compare,a0;             \

#define XCPT_HANDLER \
_handler: \
        csrw sup0,a0;                \
        csrw sup1,a1;                \
        vxcptcause x0;               \
        la a0,evac;                  \
        vxcptsave a0;                \
        vxcptrestore a0;             \
        csrs status,SR_PEI;          \
        csrr a0,count;               \
        addi a0,a0,60;               \
        csrr a0,compare;             \
        csrr a0,sup0;                \
        csrr a1,sup1;                \
        sret;                        \

#if 0
#define XCPT_HANDLER \
_handler: \
        mtpcr a0,sup0;               \
        mtpcr a1,sup1;               \
        la a0,regspill;              \
        sd a2,0(a0);                 \
        sd a3,8(a0);                 \
        sd a4,16(a0);                \
        sd a5,24(a0);                \
        sd s0,32(a0);                \
        sd s1,40(a0);                \
        vgetcfg s0;                  \
        vgetvl s1;                   \
        la a0,evac;                  \
        vxcptevac a0;                \
        vsetcfg s0;                  \
        vsetvl s1,s1;                \
        vxcpthold;                   \
        li a5,0;                     \
_handler_loop: \
        ld a1,0(a0);                 \
        addi a0,a0,8;                \
        blt a1,x0,_done;             \
        srli a2,a1,32;               \
        andi a2,a2,0x1;              \
        beq a2,x0,_vcnt;             \
_vcmd: \
        beq a5,x0,_vcmd_skip;        \
        venqcmd a4,a3;               \
_vcmd_skip: \
        li a5,1;                     \
        move a4,a1;                  \
        srli a3,a4,36;               \
        andi a3,a3,0x1;              \
_vimm1: \
        srli a2,a4,35;               \
        andi a2,a2,0x1;              \
        beq a2,x0,_vimm2;            \
        ld a1,0(a0);                 \
        addi a0,a0,8;                \
        venqimm1 a1,a3;              \
_vimm2: \
        srli a2,a4,34;               \
        andi a2,a2,0x1;              \
        beq a2,x0,_end;              \
        ld a1,0(a0);                 \
        addi a0,a0,8;                \
        venqimm2 a1,a3;              \
        j _end;                      \
_vcnt: \
        ld a2,0(a0);                 \
        srli a2,a2,31;               \
        andi a2,a2,0x2;              \
        or a3,a3,a2;                 \
        venqcnt a1,a3;               \
_end: \
        j _handler_loop;             \
_done: \
        beq a5,x0,_done_skip;        \
        venqcmd a4,a3;               \
_done_skip: \
        la a0,regspill;              \
        ld a2,0(a0);                 \
        ld a3,8(a0);                 \
        ld a4,16(a0);                \
        ld a5,24(a0);                \
        ld s0,32(a0);                \
        ld s1,40(a0);                \
        mfpcr a0,count;              \
        addi a0,a0,60;               \
        mtpcr a0,compare;            \
        mfpcr a0,sup0;               \
        mfpcr a1,sup1;               \
        eret;                        \

#endif

#endif
