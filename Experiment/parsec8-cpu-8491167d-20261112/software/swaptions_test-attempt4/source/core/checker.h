#ifndef CHECKER_H
#define CHECKER_H

/* 执行单个 checker hart 的 GHE/GHT 校验流程。 */
int checker(int hart_id);

/* checker 完成后进入永久空闲循环。 */
void idle(void);

#endif
