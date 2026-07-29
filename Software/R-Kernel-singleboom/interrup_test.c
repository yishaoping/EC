#include "encoding.h"
#include "spin_lock.h"
#include <inttypes.h>
#define U32         *(volatile unsigned int *)
#define DEBUG_SIG   0x70000000
#define DEBUG_VAL   0x70000004

void handle_trap();
void csr_cfg();
void mtimecmp_cfg();
void msip_cfg();

volatile int timer_flags = 0;
int *uart_lock;

//--------------------------------------------------------------------------
// handle_trap function

// void handle_trap()
// {
//     //enter handle_trap()
//     U32(DEBUG_SIG) = 0x5;

//     //clear msip interrupt
//     U32(0x2000000)  = 0x0;

//     if((read_csr(mip) & 0x00000080) != 0x0)
//     {
//         //clear mtime register
//         U32(0x200BFF8) = 0x0;
//         U32(0x200BFFC) = 0x0;
//         U32(DEBUG_SIG) = 0xFF;
//     }
// }

// 新增安全读取mtime的函数（64位）
unsigned long long get_mtime() {
    volatile unsigned int hi, lo, check_hi;
    do {
        hi = U32(0x200BFFC); // mtime高32位
        lo = U32(0x200BFF8); // mtime低32位
        check_hi = U32(0x200BFFC); // 再次检查高32位
    } while (hi != check_hi); // 防止读取时计数器进位
    return ((unsigned long long)hi << 32) | lo;
}

void handle_trap() {
    // 进入中断处理
    // U32(DEBUG_SIG) = 0x5;

    // 处理软件中断
    if ((read_csr(mip) & 0x8) != 0) { // 检查MSIP
        U32(0x2000000) = 0x0;        // 清除软件中断
        // U32(DEBUG_SIG) = 0x10;        // 标记软件中断处理
        // lock_acquire(&uart_lock);
        // printf("get software interrupt!\n");
        // lock_release(&uart_lock);
    }

    // 处理定时器中断
    if ((read_csr(mip) & 0x80) != 0) { // 检查MTIP
        // 安全读取当前时间
        unsigned long long current_time = get_mtime();
        timer_flags += 1;
        // lock_acquire(&uart_lock);
        // printf("get timer interrupt%d!\n", timer_flags);
        // lock_release(&uart_lock);
        // 更新mtimecmp（当前时间 + 间隔0x10）
        if(timer_flags < 3){
            U32(0x2004000) = (unsigned int)(current_time + 0x30);     // 写入低32位
            U32(0x2004004) = (unsigned int)((current_time + 0x30) >> 32); // 写入高32位
        }
        
        
        // U32(DEBUG_SIG) = 0xFF;       // 标记定时器中断处理
        // 达到条件后禁用定时器中断
        else if (timer_flags >= 3) {
            unsigned int mie_val = read_csr(mie);
            write_csr(mie, mie_val & ~0x80); // 清除 MTIE (Bit7)
            // printf("Timer interrupts disabled.\n");
            // 清除 MIE 位（Bit3）
            unsigned int mstatus_val = read_csr(mstatus);
            write_csr(mstatus, mstatus_val & ~0x8); 
        }
    }
}

//--------------------------------------------------------------------------
// CSR interrupt configuration function
 
void csr_timer_cfg()
{
    unsigned int csr_tmp;

    //mie.MEIE
    csr_tmp = read_csr(mie);
    // U32(DEBUG_VAL) = csr_tmp;
    //write_csr(mie,0x0);
    write_csr(mie,(csr_tmp | 0x80));

    printf("csr timer configuration complete\n");
}

void csr_software_cfg()
{
    unsigned int csr_tmp;

    //mie.MEIE
    csr_tmp = read_csr(mie);
    // U32(DEBUG_VAL) = csr_tmp;
    //write_csr(mie,0x0);
    write_csr(mie,(csr_tmp | 0x8));

    //mstatus.MIE
    csr_tmp = read_csr(mstatus);
    // U32(DEBUG_VAL) = csr_tmp;
    //write_csr(mstatus,0x0);
    write_csr(mstatus,(csr_tmp | 0x8));
    printf("csr software configuration complete\n");
}


//--------------------------------------------------------------------------
// mtimecmp configuration function

// void mtimecmp_cfg()
// {
//     //mtiemcmp0 - low bit
//     U32(DEBUG_VAL) = U32(0x2004000);
//     U32(0x2004000)  = 0x00000010;

//     //mtiemcmp1 - high bit
//     U32(DEBUG_VAL) = U32(0x2004004);
//     U32(0x2004004)  = 0x00000000;
    
//     //clear mtime register
//     U32(0x200BFF8)  = 0x0;
//     U32(0x200BFFC)  = 0x0;

//     printf("mtimecmp configuration complete\n");
// }
// 修改后的定时器配置函数
void mtimecmp_cfg() {
    // 初始设置mtimecmp为当前时间 + 0x10
    unsigned long long current_time = get_mtime();
    U32(0x2004000) = (unsigned int)(current_time + 0x30);     // 低32位
    U32(0x2004004) = (unsigned int)((current_time + 0x30) >> 32); // 高32位
    printf("mtimecmp configured to %" PRIu64 "\n", current_time + 0x30);
}

//--------------------------------------------------------------------------
// msip configuration function

void msip_cfg()
{
    U32(0x2000000)  = 0x1;
}

//--------------------------------------------------------------------------
// Main

void main()
{
    unsigned int i;

    //configuration
    mtimecmp_cfg();
    csr_software_cfg();

    

    //msip software interrupt
    msip_cfg();

    csr_timer_cfg();
    //delay
    for(i=0;i<20;i++)
    {
        U32(0x81000000+i*4) = i;
    }

    while(1) {
        if(timer_flags >= 3){ break; }
        asm volatile ("wfi");
    }

    printf("interrupt test complete!\n");

    return 0;
}