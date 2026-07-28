#ifndef MEEK_H
#define MEEK_H

#include <stdint.h>

#define NUM_CHECKERS 4

void rStartup(void);
void rCleanup(void);
int  checker(int hart_id);
uintptr_t handle_trap(uintptr_t epc, uintptr_t cause, uintptr_t tval,
                      uintptr_t regs[32]);

#endif
