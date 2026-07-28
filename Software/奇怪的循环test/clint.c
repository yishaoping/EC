/**
 * @file    clint.c
 * @brief   多核软件中断、周期定时器和 ecall trap 处理
 *
 * @details 默认 GuardianCouncil 测试在每个 hart 上自触发一次 MSIP，并
 *          安排最多 50 次机器定时器中断。test_workload.c 中的 ecall 也
 *          由本模块跳过。这样检查窗口同时覆盖异步 trap、mepc 更新以及
 *          mstatus/mie/mip 等机器态 CSR 的变化。
 */

#include "clint.h"
#include <inttypes.h>

// trap 处理器跨调用保存每个 hart 的触发次数；uart_lock 串行化多核日志。

volatile int timer_flags[NUM_TIMER_HARTS] = {0};
int uart_lock;

#define CLINT_MIP_MSIP        0x8U
#define CLINT_MIP_MTIP        0x80U
#define CLINT_MIE_MSIE        0x8U
#define CLINT_MIE_MTIE        0x80U
#define CLINT_MSTATUS_MIE_BIT 0x8U


// 以下辅助函数统一处理 64 位 CLINT 寄存器的分段 MMIO 访问。

/**
 * @brief  安全读取 64 位 mtime 计数器值
 * @return 当前 mtime 值（64位）
 *
 * @note   软件刻意使用两次 32 位 MMIO 读取。采用“高 -> 低 -> 再读高”
 *         可避免低 32 位进位时拼接出不一致的 64 位时间。
 */
uint64_t get_mtime(void)
{
    volatile uint32_t* mtime_low  = (uint32_t*)MTIME_ADDR;
    volatile uint32_t* mtime_high = (uint32_t*)(MTIME_ADDR + 4);
    uint32_t hi, lo;
    do {
        hi = *mtime_high;
        lo = *mtime_low;
    } while (hi != *mtime_high);   // 高位变化说明跨越了低位进位，整组重读
    return ((uint64_t)hi << 32) | lo;
}

/**
 * @brief  无瞬时误触发地写入指定 hart 的 mtimecmp。
 * @param  hart_id 目标 hart。
 * @param  cmp_val 新的 64 位比较值。
 *
 * @note   按 high=UINT32_MAX -> low -> final high 的顺序写，在更新期间
 *         暂时把比较值推到未来，避免撕裂写导致伪定时器中断。
 */
static inline void write_mtimecmp(uint64_t hart_id, uint64_t cmp_val)
{
    volatile uint32_t* mtimecmp_low  = (uint32_t*)(CLINT_BASE + TIMECMP_OFFSET(hart_id));
    volatile uint32_t* mtimecmp_high = (uint32_t*)(CLINT_BASE + TIMECMP_OFFSET(hart_id) + 4);

    *mtimecmp_high = UINT32_MAX;
    *mtimecmp_low  = (uint32_t)cmp_val;
    *mtimecmp_high = (uint32_t)(cmp_val >> 32);
    asm volatile("fence iorw, iorw" ::: "memory");
}

/** @brief 以保留 mie 其他位的读改写方式设置或清除 MTIE。 */
static inline void set_mtie(int enabled)
{
    unsigned int mie_val = read_csr(mie);

    if (enabled) {
        write_csr(mie, mie_val | CLINT_MIE_MTIE);
    } else {
        write_csr(mie, mie_val & ~CLINT_MIE_MTIE);
    }
}

/**
 * @brief  处理一次当前 hart 的机器定时器中断。
 * @details 先屏蔽 MTIE，再增加计数；未达到上限时重装 mtimecmp 并恢复 MTIE。
 */
static inline void handle_timer_interrupt(uint64_t hart_id)
{
    set_mtie(0);

    if (hart_id >= NUM_TIMER_HARTS) {
        return;
    }

    timer_flags[hart_id] += 1;
    if (timer_flags[hart_id] < timer_limitation) {
        write_mtimecmp(hart_id, get_mtime() + timer_cmp);
        set_mtie(1);
    }
}


// 测试启动阶段调用的中断配置接口。

/**
 * @brief  向当前 hart 自身发送一次机器软件中断（MSIP）。
 *
 * @note   通过 CLINT 的 MSIP 寄存器向自己发送软件中断。
 *         每个核心有独立的 MSIP 地址 = CLINT_BASE + hart_id * 4。
 */
void msip_cfg(void)
{
    uint64_t hart_id;
    asm volatile("csrr %0, mhartid" : "=r"(hart_id));

    volatile uint32_t* msip = (uint32_t*)(CLINT_BASE + MSIP_OFFSET(hart_id));
    *msip = 0x1;                            // handle_trap() 负责清零
    lock_acquire(&uart_lock);
    printf("Core%" PRIu64 ": MSIP at 0x%p\n", hart_id, (void*)msip);
    lock_release(&uart_lock);
}

/**
 * @brief  把当前 hart 的 mtimecmp 安排在当前 mtime + timer_cmp。
 *
 * @note   timer_cmp 的单位是平台 mtime tick，不应直接理解为 hart CPU cycle。
 */
void mtimecmp_cfg(void)
{
    uint64_t hart_id;
    asm volatile("csrr %0, mhartid" : "=r"(hart_id));

    volatile uint32_t* mtimecmp_low = (uint32_t*)(CLINT_BASE + TIMECMP_OFFSET(hart_id));

    uint64_t current = get_mtime();
    uint64_t cmp_val = current + timer_cmp;

    write_mtimecmp(hart_id, cmp_val);
    lock_acquire(&uart_lock);
    printf("Core%" PRIu64 ": mtimecmp@0x%p\n", hart_id, (void*)mtimecmp_low);
    lock_release(&uart_lock);
}

/**
 * @brief  在当前 hart 的 mie 中置位机器定时器中断使能（MTIE）。
 *
 * @note   设置 mie 寄存器的 MTIE 位 (bit 7) 以允许机器定时器中断。
 *         使用 read-modify-write 方式保留其他中断使能位不变。
 */
void csr_timer_cfg(void)
{
    uint64_t hart_id;
    asm volatile("csrr %0, mhartid" : "=r"(hart_id));
    unsigned int csr_tmp;

    csr_tmp = read_csr(mie);
    write_csr(mie, (csr_tmp | CLINT_MIE_MTIE)); // 保留 mie 中其他中断使能位
}

/**
 * @brief  使能当前 hart 的机器软件中断和机器态全局中断。
 *
 * @note   1. 设置 mie[3] = MSIE（机器软件中断使能）
 *          2. 设置 mstatus[3] = MIE（机器全局中断使能）
 */
void csr_software_cfg(void)
{
    uint64_t hart_id;
    asm volatile("csrr %0, mhartid" : "=r"(hart_id));
    unsigned int csr_tmp;

    // mie[3]=MSIE：允许 CLINT MSIP 进入 trap。
    csr_tmp = read_csr(mie);
    write_csr(mie, (csr_tmp | CLINT_MIE_MSIE)); // 置位 mie[3] = MSIE

    // mstatus[3]=MIE：打开机器态全局中断门控。
    csr_tmp = read_csr(mstatus);
    write_csr(mstatus, (csr_tmp | CLINT_MSTATUS_MIE_BIT)); // 置位 mstatus[3] = MIE

    lock_acquire(&uart_lock);
    printf("Core%" PRIu64 ": Software configuration complete\n", hart_id);
    lock_release(&uart_lock);
}


// 启动环境的 trap_entry 最终调用该统一 C 处理函数。

/**
 * @brief  统一的中断和异常处理入口
 *
 * @details 根据传入 mcause 的最高位区分中断和异常：
 *          - interrupt=1: 中断处理
 *            - mip[3]=MSIP:   清除当前核心的 MSIP 位
 *            - mip[7]=MTIP:   更新 mtimecmp，达到 timer_limitation 后禁用定时器
 *          - interrupt=0: 异常处理
 *            - cause_code=11: M-mode ecall，返回 epc+4 以跳过 32 位 ecall
 *
 * @note    trap_entry 会将本函数返回值写回 mepc。
 */
uint64_t handle_trap(uint64_t epc, uint64_t mcause_val, uint64_t tval, uint64_t *regs)
{
    (void)tval;
    (void)regs;

    uint64_t hart_id;
    asm volatile("csrr %0, mhartid" : "=r"(hart_id));

    uint64_t interrupt  = mcause_val >> 63;                      // RV64 mcause[63]
    uint64_t cause_code = mcause_val & 0x7FFFFFFFFFFFFFFF;       // mcause[62:0]

    if (interrupt) {
        // MSIP 优先处理；本测试的 MSIP 是每个 hart 向自身发送的。
        if ((read_csr(mip) & CLINT_MIP_MSIP) != 0) {             // 检查 mip[3]=MSIP
            volatile uint32_t* msip = (uint32_t*)(CLINT_BASE + MSIP_OFFSET(hart_id));
            *msip = 0x0;                                         // 写零撤销软件中断
        }
        // 若不是 MSIP，再处理 MTIP 并按计数决定是否重装。
        else if ((read_csr(mip) & CLINT_MIP_MTIP) != 0) {        // 检查 mip[7]=MTIP
            handle_timer_interrupt(hart_id);
        }
    } else {
        // 负载只显式制造机器态 ecall；其他同步异常保持原 epc。
        switch (cause_code) {
        case 11:                                                 // 环境调用异常 (ecall)
            return epc + 4;                                      // mepc 指向下一条指令
        default:
            break;
        }
    }

    return epc;
}
