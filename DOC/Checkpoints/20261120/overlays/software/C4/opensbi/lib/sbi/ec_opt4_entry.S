#include <sbi/riscv_encoding.h>
.section .text
.option norvc
.balign 4
.global ec_opt4_enter
ec_opt4_enter:
    csrw satp, a0
    sfence.vma
    fence.i
    csrr t0, mhartid
    addi t0, t0, -1
    slli t0, t0, 3
    la t1, ec_opt4_context
    add t1, t1, t0
    csrr t2, satp
    sd t2, 120(t1)                /* actual installed satp, not the requested copy */
    fence rw,rw
    csrw mepc, a1
    li t0, MSTATUS_MPP | MSTATUS_MPIE | MSTATUS_MIE | MSTATUS_MPRV
    csrc mstatus, t0                 /* M -> U by standard mret; no CSR hack */
    mret

.balign 4
.global ec_opt4_trap
ec_opt4_trap:
    csrr t0, mhartid
    addi t0, t0, -1
    slli t0, t0, 3
    la t1, ec_opt4_context
    add t1, t1, t0
    csrr t2, mcause
    li t3, 8
    bne t2, t3, 1f
    li t3, 0x45434f50
    bne a7, t3, 1f
    li t4, 1
    j 2f
1:  ori t2, t2, 256
    sd t2, 88(t1)                 /* fault[hart-1], never treated as PASS */
    li t4, 0
2:  li a1, 2
    .insn r 0x2b, 2, 0x16, x0, a1, x0
    .insn r 0x2b, 0, 0x50, x0, x0, x0
    csrw satp, zero
    sfence.vma
    fence rw,rw
    beqz t4, 3f
    sd t4, 56(t1)                 /* publish only AFTER fetch context teardown */
    fence rw,rw
3:  wfi
    j 3b
