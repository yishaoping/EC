#ifndef GHT_H
#define GHT_H

#include <stdint.h>

#include "rocc.h"

static inline uint64_t ght_get_status(void)
{
    uint64_t status;
    ROCC_INSTRUCTION_DSS(1, status, 0X00, 0X00, 0x06);
    return status;
}

static inline void ght_set_satp_priv(void)
{
    ROCC_INSTRUCTION_S(1, 0x01, 0x16);
}

static inline void ght_unset_satp_priv(void)
{
    ROCC_INSTRUCTION_S(1, 0x02, 0x16);
}

static inline void ght_cfg_filter(uint64_t index, uint64_t func,
                                  uint64_t opcode, uint64_t sel_d)
{
    uint64_t set_ref = ((index & 0x1f) << 4) |
                       ((sel_d & 0xf) << 17) |
                       ((opcode & 0x7f) << 21) |
                       ((func & 0xf) << 28) | 0x02;
    ROCC_INSTRUCTION_SS(1, set_ref, 0X02, 0x06);
}

static inline void ght_cfg_filter_rvc(uint64_t index, uint64_t func,
                                      uint64_t opcode, uint64_t msb,
                                      uint64_t sel_d)
{
    uint64_t set_ref = ((index & 0x1f) << 4) |
                       ((sel_d & 0xf) << 17) |
                       (((opcode | ((msb & 1) << 2)) & 0x7f) << 21) |
                       (((func | 0x8) & 0xf) << 28) | 0x02;
    ROCC_INSTRUCTION_SS(1, set_ref, 0X02, 0x06);
}

static inline void ght_cfg_se(uint64_t se_id, uint64_t end_id,
                              uint64_t policy, uint64_t start_id)
{
    uint64_t set_se = ((se_id & 0x1f) << 4) |
                      ((start_id & 0xf) << 17) |
                      ((policy & 0x7f) << 21) |
                      ((end_id & 0xf) << 28) | 0x04;
    ROCC_INSTRUCTION_SS(1, set_se, 0X02, 0x06);
}

static inline void ght_cfg_mapper(uint64_t inst_type,
                                  uint64_t ses_receiving_inst)
{
    uint64_t set_mapper = ((inst_type & 0xff) << 4) |
                          ((ses_receiving_inst & 0xFFFF) << 16) | 0x03;
    ROCC_INSTRUCTION_SS(1, set_mapper, 0X02, 0x06);
}

static inline void ght_debug_filter_width(uint64_t width)
{
    uint64_t set_debug_width = ((width & 0xf) << 4) | 0x05;
    ROCC_INSTRUCTION_SS(1, set_debug_width, 0X02, 0x06);
}

static inline uint64_t ght_get_initialisation(void)
{
    uint64_t status;
    ROCC_INSTRUCTION_D(1, status, 0x1b);
    return status;
}

static inline void ght_set_numberofcheckers(uint64_t num)
{
    ROCC_INSTRUCTION_S(1, num, 0x1c);
}

static inline void r_set_corex_p_s(uint64_t core_id)
{
    uint64_t mask = core_id << 3;
    ght_cfg_mapper(0b10000001 | mask, 0b0001 << (core_id - 1));
    ght_cfg_mapper(0b10000010 | mask, 0b0001 << (core_id - 1));
    ght_cfg_mapper(0b10000011 | mask, 0b0001 << (core_id - 1));
    ght_cfg_mapper(0b01000001 | mask, 0b0001 << (core_id - 1));
    ght_cfg_mapper(0b01000010 | mask, 0b0001 << (core_id - 1));
    ght_cfg_mapper(0b01000011 | mask, 0b0001 << (core_id - 1));
    ght_cfg_mapper(0b10000111 | mask, 0b0001 << (core_id - 1));
    ght_cfg_mapper(0b01000111 | mask, 0b0001 << (core_id - 1));
    ght_cfg_mapper(0b11000111 | mask, 0b0001 << (core_id - 1));
    ght_cfg_mapper(0b10000101 | mask, 0b0001 << (core_id - 1));
    ght_cfg_mapper(0b01000101 | mask, 0b0001 << (core_id - 1));
    ght_cfg_mapper(0b11000101 | mask, 0b0001 << (core_id - 1));
}

#endif
