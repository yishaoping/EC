#include "hooks.h"
#include <unistd.h>
void __parsec_bench_begin(enum __parsec_benchmark b){(void)b;}
void __parsec_bench_end(void){}
void __parsec_roi_begin(void){write(2,"EC_DIAGNOSTIC_ROI_BEGIN\n",24);}
void __parsec_roi_end(void){write(2,"EC_DIAGNOSTIC_ROI_END\n",22);}
