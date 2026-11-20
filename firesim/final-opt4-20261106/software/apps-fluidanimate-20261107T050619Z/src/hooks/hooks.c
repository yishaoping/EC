#include "hooks.h"
#include "dac_roi.h"
#include <stdio.h>
void __parsec_bench_begin(enum __parsec_benchmark b) {
    printf("EC_PARSEC_BENCH_BEGIN id=%d\n", (int)b); fflush(stdout);
}
void __parsec_bench_end(void) { puts("EC_PARSEC_BENCH_END"); fflush(stdout); }
void __parsec_roi_begin(void) { ec_dac_roi_begin(); }
void __parsec_roi_end(void) { ec_dac_roi_end(); }
