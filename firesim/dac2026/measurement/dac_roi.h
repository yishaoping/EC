#ifndef EC_DAC_ROI_H
#define EC_DAC_ROI_H
#include <stdint.h>
#include <sys/ioctl.h>
/* ABI contract only: no existing EC Linux driver currently implements it.
 * A backend must close/drain the previous package, arm a fresh observer epoch,
 * keep checker harts outside the Linux application cpuset, then acknowledge.
 * END freezes the BOOM ROI boundary and seals its producer; it does not throw
 * away outstanding tasks. DRAIN separately waits for compare+release+transport.
 */
struct ec_dac_boundary { uint64_t version, epoch, target_tick, outstanding, status; };
#define EC_DAC_BEGIN _IOWR('E', 0x70, struct ec_dac_boundary)
#define EC_DAC_END   _IOWR('E', 0x71, struct ec_dac_boundary)
#define EC_DAC_DRAIN _IOWR('E', 0x72, struct ec_dac_boundary)
void ec_dac_roi_begin(void);
void ec_dac_roi_end(void);
#endif
