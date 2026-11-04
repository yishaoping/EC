#include "dac_roi.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/* These calls must fail on an image without the real measurement/control
 * driver. A printf timestamp or host gettimeofday is never a substitute.
 * BEGIN arms the observer before the following marker executes. END/DRAIN
 * report the marker timestamp already captured by the passive observer.
 * BEGIN cannot return a timestamp for the marker that has not executed yet.
 */
static int fd = -1;
static struct ec_dac_boundary boundary;
static void fail(const char *what) { perror(what); _exit(125); }
void ec_dac_roi_begin(void) {
    if (fd >= 0) fail("nested DAC ROI");
    fd = open("/dev/ec_dac_roi", O_RDWR | O_CLOEXEC);
    if (fd < 0) fail("DAC ROI driver unavailable");
    boundary = (struct ec_dac_boundary){ .version = 1 };
    if (ioctl(fd, EC_DAC_BEGIN, &boundary) || boundary.status || boundary.outstanding)
        fail("DAC ROI begin/drain failed");
    /* Standard RISC-V NOP markers work on B, D and C without a RoCC opcode.
     * Tap architectural acceptance of this exact marker on application hart0.
     * Driver BEGIN arms the observer; the marker establishes ROI start time.
     */
#ifdef __riscv
    __asm__ volatile(".word 0x6b100013" ::: "memory");
#else
#error DAC ROI hooks are for RISC-V targets
#endif
}
void ec_dac_roi_end(void) {
    if (fd < 0) fail("DAC ROI end without begin");
#ifdef __riscv
    __asm__ volatile(".word 0x6b200013" ::: "memory");
#endif
    if (ioctl(fd, EC_DAC_END, &boundary) || boundary.status) fail("DAC ROI end/seal failed");
    if (ioctl(fd, EC_DAC_DRAIN, &boundary) || boundary.status || boundary.outstanding)
        fail("DAC validation drain failed");
    close(fd); fd = -1;
}
