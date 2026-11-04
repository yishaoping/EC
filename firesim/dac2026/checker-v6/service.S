/* User-mode management page, mapped RX in the exact BOOM mm. No stack or
 * Linux ABI calls: COPY overwrites the integer/FP register context. */
.section .text
.balign 4096
.option norvc
.global ec_opt4_service
ec_opt4_service:
    li a1, 1
    .insn r 0x2b, 2, 0x01, x0, a1, x0 /* AS-R */
    .insn r 0x2b, 2, 0x16, x0, a1, x0 /* monitor this satp */
    .insn r 0x2b, 0, 0x40, x0, x0, x0 /* GO */
    .insn r 0x2b, 0, 0x51, x0, x0, x0 /* initialized */
    .insn r 0x2b, 0, 0x75, x0, x0, x0 /* management context */
    .insn r 0x2b, 0, 0x73, x0, x0, x0 /* COPY from BOOM */
    .insn r 0x2b, 0, 0x64, x0, x0, x0 /* pc_special = following instruction */
1:
    .insn r 0x2b, 4, 0x61, a0, x0, x0 /* CPS ready */
    andi a0, a0, 24
    li a1, 8
    bne a0, a1, 2f
    .insn r 0x2b, 0, 0x60, x0, x0, x0 /* real COPY */
    .word 0x00001067                 /* original R_INSTRUCTION_JLR */
    j 1b
2:
    .insn r 0x2b, 4, 0x07, a0, x0, x0 /* FINISH alone cannot authorize teardown */
    li a1, 2
    bne a0, a1, 1b
    csrr a0, 0xcc0                  /* real local cleanup + result handoff + CDC empty */
    beqz a0, 1b
    .insn r 0x2b, 0, 0x72, x0, x0, x0 /* select the saved management context */
    .insn r 0x2b, 0, 0x60, x0, x0, x0 /* restore checker service registers */
    nop
    nop
    nop
    nop
    nop
5:
    .insn r 0x2b, 4, 0x07, a0, x0, x0 /* preserve the original GHT completion gate */
    li a1, 2
    bne a0, a1, 5b
3:
    .insn r 0x2b, 0, 0x43, x0, x0, x0 /* session RELEASE, not package PASS */
    li a7, 0x45434f50
    ecall                           /* M-mode firmware parks only after session end */
4:  j 4b
.global ec_opt4_service_end
ec_opt4_service_end:
