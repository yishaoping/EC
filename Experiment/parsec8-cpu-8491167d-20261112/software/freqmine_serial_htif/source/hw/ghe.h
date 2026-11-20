#ifndef GHE_H
#define GHE_H
#include <stdint.h>
#include "rocc.h"

/* Both versions implement funct 0x76 and its low five bits. Always release
 * the reset register; Current's optional observer controls are hart-0 only,
 * before/after the ROI. They never define timing or software PASS. */
static inline void ghe_common_observer_init(void)
{
    ROCC_INSTRUCTION_S(1, 1, 0x76);
    ROCC_INSTRUCTION_S(1, 0, 0x76);
}
static inline void ghe_common_observer_start(void)
{
    ROCC_INSTRUCTION_S(1, 0x20, 0x76);
    ROCC_INSTRUCTION_S(1, 0, 0x76);
}
static inline void ghe_common_observer_stop(void)
{
    ROCC_INSTRUCTION_S(1, 0x40, 0x76);
    ROCC_INSTRUCTION_S(1, 0, 0x76);
}

static inline void ghe_asR(void) { ROCC_INSTRUCTION_S(1, 0x01, 0x01); }
static inline uint64_t ghe_checkght_status(void)
{
    uint64_t status;
    ROCC_INSTRUCTION_D(1, status, 0x07);
    return status;
}
static inline void ghe_release(void) { ROCC_INSTRUCTION(1, 0x43); }
static inline void ghe_go(void) { ROCC_INSTRUCTION(1, 0x40); }
static inline void ghe_initailised(uint64_t initialised)
{
    if (initialised == 0) { ROCC_INSTRUCTION(1, 0x50); }
    if (initialised == 1) { ROCC_INSTRUCTION(1, 0x51); }
}
static inline uint64_t ghe_rsur_status(void)
{
    uint64_t status;
    ROCC_INSTRUCTION_D(1, status, 0x61);
    return status;
}
static inline uint64_t elu_checkstatus(void)
{
    uint64_t status;
    ROCC_INSTRUCTION_D(1, status, 0x66);
    return status;
}
static inline void ghe_set_checker_mask(uint64_t mask)
{
    ROCC_INSTRUCTION_S(1, mask, 0x7D);
}
static inline uint64_t ghe_get_checker_mask(void)
{
    uint64_t mask;
    ROCC_INSTRUCTION_D(1, mask, 0x7E);
    return mask;
}
#endif
