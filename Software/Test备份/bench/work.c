#include "work.h"

/*
 * 该工作负载用于同时覆盖多类 Rocket/BOOM 指令路径：
 * 浮点运算、CSR 访问、异常入口、缓存/不可缓存访存、LR/SC 和 AMO。
 * 汇编块中的寄存器约束和 memory clobber 用于防止编译器重排测试指令。
 */
void run_work(uint64_t hart_id)
{
    uint64_t Hart_id = hart_id;
    float a = 0.1;
    float b = 0.2;
    float c = 0.3;
    float d = (a + b + c) * 1.7 * 3.2;
    uint64_t csr_value = 0;

    asm volatile("csrr %0, cycle" : "=r"(csr_value));
    asm volatile("csrr %0, instret" : "=r"(csr_value));
    asm volatile("csrr %0, mhartid" : "=r"(Hart_id));

    double e = (c - b + a) * 1.1;
    double f = ((e + d) * (d - b)) / 2.1;
    double g = (c + 1.1) / 2;
    double h = a - 0.05;
    double i = f + 1.1;
    double j = a + b + c + d + e + f + g + h + i;

    if ((j * Hart_id) == 0) {
        for (int loop = 0; loop < 3; loop++) {
            e = loop * 1.2 + 3;
            b = j + 1.7;
            a = (e + b) * 2.2;
            asm volatile("csrr %0, cycle" : "=r"(csr_value));
            asm volatile("csrr %0, instret" : "=r"(csr_value));
            asm volatile("csrr %0, mhartid" : "=r"(Hart_id));
            a = a + csr_value;
            __asm__ volatile("ecall");
            if (a > Hart_id) {
                __asm__ volatile(
                    "li   t0, 0x81000000\n"
                    "li   t1, 0x55552000\n"
                    "li   t2, 0x55553000\n"
                    "1:\n"
                    "li   a5, 0x810008FF\n"
                    "lr.w a0, (t0)\n"
                    "sc.w a0, t1, (t0)\n"
                    "sd   t1, 0(t0)\n"
                    "sd   t2, 16(t0)\n"
                    "sd   t1, 32(t0)\n"
                    "sd   t2, 64(t0)\n"
                    "divw t3, t1, t2\n"
                    "addi t0, t0, 0x10\n"
                    "frflags a3\n"
                    "fsflags a3\n"
                    "csrrc a3, fflags, a3\n"
                    "csrrwi a3, frm, 0x3\n"
                    "csrrsi a3, fflags, 0x1F\n"
                    "csrrci a3, fflags, 0x0F\n"
                    "blt  t0, a5, 1b\n"
                    "li   t0, 0x81000000\n"
                    "2:\n"
                    "li   a5, 0x810008FF\n"
                    "lr.w a0, (t0)\n"
                    "sc.w a0, t1, (t0)\n"
                    "ld   t1, 0(t0)\n"
                    "ld   t2, 16(t0)\n"
                    "ld   t1, 32(t0)\n"
                    "ld   t2, 64(t0)\n"
                    "mulw t3, t1, t2\n"
                    "divw t3, t1, t2\n"
                    "frflags a3\n"
                    "li   a3, 0x55\n"
                    "fsflags a3\n"
                    "divu t2, t2, t1\n"
                    "addi t0, t0, 0x10\n"
                    "blt  t0, a5, 2b\n"
                    "li   t0, 0x81000000\n"
                    "li   t1, 0x81000100\n"
                    "li   t2, 1\n"
                    "3:\n"
                    "li   a5, 0x810008FF\n"
                    "amoadd.w.aq t1, t2, (t0)\n"
                    "addi t2, t2, 0x01\n"
                    "addi t0, t0, 0x10\n"
                    "blt  t0, a5, 3b\n"
                    :
                    :
                    : "a0", "a3", "a5", "t0", "t1", "t2", "t3", "memory");
            }
        }
    }
}
