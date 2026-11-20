#include "dac_roi.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/resource.h>
#include "opt4_hw.h"
/* These calls must fail on an image without the real measurement/control
 * driver. A printf timestamp or host gettimeofday is never a substitute.
 * BEGIN arms the observer before the following marker executes. END/DRAIN
 * report the marker timestamp already captured by the passive observer.
 * BEGIN cannot return a timestamp for the marker that has not executed yet.
 */
static int fd = -1;
static struct ec_dac_boundary boundary;
static unsigned long checkers;
static void *service;
#define EC_DAC_QUERY_CHECKERS _IOR('E', 0x73, unsigned long)
static unsigned long ticks(void) {
    unsigned long n; __asm__ volatile("rdcycle %0":"=r"(n)::"memory"); return n;
}
static void fail(const char *what) { perror(what); _exit(125); }
void ec_dac_roi_begin(void) {
    if (fd >= 0) fail("nested DAC ROI");
    fd = open("/dev/ec_dac_roi", O_RDWR | O_CLOEXEC);
    if (fd < 0) fail("DAC ROI driver unavailable");
    if (ioctl(fd, EC_DAC_QUERY_CHECKERS, &checkers)) {
        if (errno != ENOTTY) fail("DAC hardware query");
        checkers = 0; /* Version-bound frozen B v5 driver has no query ioctl. */
    }
    if (checkers) {
        if (checkers != 4) { errno=ENOTSUP; fail("C4 v6 requires four checkers"); }
        service=mmap(NULL,4096,PROT_READ|PROT_EXEC,MAP_SHARED,fd,0);
        if (service==MAP_FAILED) fail("C4 service mapping");
        struct rlimit limit={RLIM_INFINITY,RLIM_INFINITY};
        if (setrlimit(RLIMIT_MEMLOCK,&limit) || mlockall(MCL_CURRENT|MCL_FUTURE))
            fail("C4 instruction residency");
    }
    boundary = (struct ec_dac_boundary){ .version = 1 };
    if (ioctl(fd, EC_DAC_BEGIN, &boundary) || boundary.status || boundary.outstanding)
        fail("DAC ROI begin/drain failed");
    if (checkers) {
        EC_CMD(0x31);
        EC_SET(0x70, 1);
    }
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
    if (checkers) {
        EC_SET(0x70, 2);
        __asm__ volatile(".rept 26\nnop\n.endr" ::: "memory");
        EC_CMD(0x32);
        unsigned long start=ticks();
        while (EC_RD(0x06,0) < 0x1ffff) {
            if (ticks()-start>20000000) { errno=ETIMEDOUT; fail("C4 real session completion"); }
        }
    }
    if (ioctl(fd, EC_DAC_END, &boundary) || boundary.status) fail("DAC ROI end/seal failed");
    if (ioctl(fd, EC_DAC_DRAIN, &boundary) || boundary.status || boundary.outstanding)
        fail("DAC validation drain failed");
    if (checkers) {
        EC_SET(0x16, 2);
        EC_CMD(0x30);
        munmap(service,4096);
        munlockall();
    }
    close(fd); fd = -1;
}
