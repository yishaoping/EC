/* SPDX-License-Identifier: GPL-2.0 */
#ifndef EC_DAC_ROI_REGS_H
#define EC_DAC_ROI_REGS_H
/* Proposed target interface, NOT PRESENT in v3 RTL. No fixed physical address.
 * All accesses are naturally aligned atomic RV64 little-endian transactions.
 * RESPONSE registers are one immutable snapshot per command acknowledgement.
 * The passive host bridge independently consumes the original source events.
 */
#define DAC_MAGIC_VALUE 0x4543444143524f49ULL
#define DAC_ABI_VERSION 1
#define DAC_MAGIC          0x00
#define DAC_VERSION        0x08
#define DAC_CAPS           0x10
#define DAC_CHECKERS       0x18
#define DAC_COMMAND        0x20
#define DAC_REQUEST_EPOCH  0x28
#define DAC_REQUEST_SATP   0x30
#define DAC_REQUEST_HART   0x38
#define DAC_ACK            0x40
#define DAC_ERROR          0x48
#define DAC_STATE          0x50
#define DAC_EPOCH          0x58
#define DAC_BEGIN_TICK     0x60
#define DAC_END_TICK       0x68
#define DAC_DRAIN_TICK     0x70
#define DAC_OUTSTANDING    0x78
#define DAC_GENERATED      0x80
#define DAC_COMPLETED      0x88
#define DAC_FAULTS         0x90
#define DAC_REGISTER_BYTES 0x98

#define DAC_CAP_MARKERS        (1ULL << 0)
#define DAC_CAP_SATP_U_HART     (1ULL << 1)
#define DAC_CAP_BOOM_TICKS      (1ULL << 2)
#define DAC_CAP_REAL_DRAIN      (1ULL << 3)
#define DAC_CAP_BASELINE        (1ULL << 4)
#define DAC_CAP_CORRECTION      (1ULL << 5)
#define DAC_CAP_EXEC_COMPARE    (1ULL << 6)
#define DAC_CAP_LINUX_CONTEXT   (1ULL << 7)
#define DAC_CAP_PRODUCER_SEAL   (1ULL << 8)
#define DAC_CAP_ATOMIC_REPLY    (1ULL << 9)
#define DAC_CAP_ABORT_DRAIN     (1ULL << 10)
#define DAC_CAP_COMMON (DAC_CAP_MARKERS | DAC_CAP_SATP_U_HART | \
	DAC_CAP_BOOM_TICKS | DAC_CAP_REAL_DRAIN | DAC_CAP_PRODUCER_SEAL | \
	DAC_CAP_ATOMIC_REPLY | DAC_CAP_ABORT_DRAIN)

#define DAC_CMD_ARM   1
#define DAC_CMD_END   2
#define DAC_CMD_DRAIN 3
#define DAC_CMD_ABORT 4
#define DAC_HW_IDLE    0
#define DAC_HW_ARMED   1
#define DAC_HW_RUNNING 2
#define DAC_HW_ENDED   3
#define DAC_HW_DRAINED 4
#define DAC_HW_POISON  5
#endif
