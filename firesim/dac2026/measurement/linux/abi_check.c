/* Compile only with the RV64 Linux toolchain; do not execute. */
#include <stddef.h>
#include "../dac_roi.h"
enum { app_begin = EC_DAC_BEGIN, app_end = EC_DAC_END, app_drain = EC_DAC_DRAIN };
#undef EC_DAC_BEGIN
#undef EC_DAC_END
#undef EC_DAC_DRAIN
#define ec_dac_boundary ec_kernel_boundary
#include "ec_dac_roi_uapi.h"
#undef ec_dac_boundary
_Static_assert(sizeof(struct ec_dac_boundary) == 40, "application ABI size");
_Static_assert(sizeof(struct ec_kernel_boundary) == 40, "kernel ABI size");
/* Expand kernel ioctl expressions with their original struct spelling. */
#define ec_dac_boundary ec_kernel_boundary
_Static_assert(EC_DAC_BEGIN == app_begin, "BEGIN ioctl ABI mismatch");
_Static_assert(EC_DAC_END == app_end, "END ioctl ABI mismatch");
_Static_assert(EC_DAC_DRAIN == app_drain, "DRAIN ioctl ABI mismatch");
#undef ec_dac_boundary
#define CHECK_FIELD(name) _Static_assert(offsetof(struct ec_dac_boundary, name) == \
    offsetof(struct ec_kernel_boundary, name), "boundary field offset mismatch: " #name)
CHECK_FIELD(version);
CHECK_FIELD(epoch);
CHECK_FIELD(target_tick);
CHECK_FIELD(outstanding);
CHECK_FIELD(status);
