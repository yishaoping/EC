#include <stdint.h>
#include <stdio.h>
#include "dac_roi.h"
/* Measurement-chain smoke input. Compile is allowed; execution is manual only. */
int main(void) {
    volatile uint64_t sum=0;
    ec_dac_roi_begin();
    for (uint64_t i=1;i<=1000;++i) sum+=i;
    ec_dac_roi_end();
    printf("DAC_SMOKE checksum=%llu expected=500500\n",(unsigned long long)sum);
    return sum==500500?0:1;
}
