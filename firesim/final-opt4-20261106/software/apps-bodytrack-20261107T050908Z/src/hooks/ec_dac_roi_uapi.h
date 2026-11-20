/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
#ifndef _UAPI_LINUX_EC_DAC_ROI_H
#define _UAPI_LINUX_EC_DAC_ROI_H
#include <linux/ioctl.h>
#include <linux/types.h>
/* Layout and ioctl numbers are identical to measurement/dac_roi.h, version 1. */
struct ec_dac_boundary {
	__u64 version, epoch, target_tick, outstanding, status;
};
#define EC_DAC_BEGIN _IOWR('E', 0x70, struct ec_dac_boundary)
#define EC_DAC_END   _IOWR('E', 0x71, struct ec_dac_boundary)
#define EC_DAC_DRAIN _IOWR('E', 0x72, struct ec_dac_boundary)
#endif
