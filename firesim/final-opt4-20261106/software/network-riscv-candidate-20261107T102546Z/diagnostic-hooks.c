#include "hooks.h"
#include <unistd.h>
void __parsec_bench_begin(enum __parsec_benchmark b) {(void)b;}
void __parsec_bench_end(void) {}
void __parsec_roi_begin(void) {static const char m[]="EC_NETWORK_DIAGNOSTIC_ROI_BEGIN\n";write(2,m,sizeof(m)-1);}
void __parsec_roi_end(void) {static const char m[]="EC_NETWORK_DIAGNOSTIC_ROI_END\n";write(2,m,sizeof(m)-1);}
