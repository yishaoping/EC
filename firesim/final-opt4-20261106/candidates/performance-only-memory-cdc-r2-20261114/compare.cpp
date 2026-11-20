#include "VQueuePair.h"
#include "verilated.h"
#include <cstdint>
#include <cstdio>
#include <cstdlib>

static uint64_t rng = 0x6fada3078491167dULL;
static uint32_t next() { rng ^= rng << 13; rng ^= rng >> 7; rng ^= rng << 17; return uint32_t(rng); }

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    VQueuePair d;
    uint64_t writes=0, reads=0, full=0, backpressure=0, resetchecks=0;
    int occupancy=0, peak=0;
    bool lastenq=false, lastdeq=false;
    d.io_enqClock=0; d.io_deqClock=0; d.io_enqReset=1; d.io_deqReset=1;
    d.io_enqValid=0; d.io_deqReady=0;
    for (int j=0; j<10; ++j) d.io_enqBits[j]=0;
    d.eval();
    for (uint64_t t=0; t<200000; ++t) {
        bool e=(t/2)%2, z=(t/3)%2;
        // Include initial, independent and simultaneous resets, including occupied queues.
        d.io_enqReset=t<80 || (t>=70000 && t<70044) || (t>=130000 && t<130036);
        d.io_deqReset=t<100 || (t>=100000 && t<100060) || (t>=130000 && t<130040);
        uint64_t phase=t%20000;
        d.io_enqValid=phase<12000 ? 1 : ((next()&3)!=0);
        d.io_deqReady=phase<6000 ? 0 : (phase<12000 ? 1 : ((next()&3)!=0));
        for (int j=0; j<10; ++j) d.io_enqBits[j]=next();
        d.io_enqBits[9] &= 0x1ffff;
        d.eval();
        bool wf=e&&!lastenq&&d.io_enqValid&&d.io_readyFlat&&!d.io_enqReset;
        bool rf=z&&!lastdeq&&d.io_deqReady&&d.io_validFlat&&!d.io_deqReset;
        if (wf) ++writes;
        if (rf) ++reads;
        if (e&&!lastenq&&d.io_enqValid&&!d.io_readyFlat) ++full;
        if (z&&!lastdeq&&d.io_validFlat&&!d.io_deqReady) ++backpressure;
        if (d.io_enqReset || d.io_deqReset) {occupancy=0; ++resetchecks;}
        else {occupancy+=int(wf)-int(rf); if (occupancy>peak) peak=occupancy;}
        d.io_enqClock=e; d.io_deqClock=z; d.eval();
        if (d.io_readyFlat!=d.io_readyLocal || d.io_validFlat!=d.io_validLocal) {
            std::fprintf(stderr,"CDC_CONTROL_MISMATCH tick=%llu\n",(unsigned long long)t);return 1;
        }
        for (int j=0; j<10; ++j) if (d.io_bitsFlat[j]!=d.io_bitsLocal[j]) {
            std::fprintf(stderr,"CDC_PAYLOAD_MISMATCH tick=%llu word=%d valid=%d\n",(unsigned long long)t,j,int(d.io_validFlat));return 2;
        }
        lastenq=e;lastdeq=z;
    }
    d.final();
    if (writes<10000 || reads<10000 || full<1000 || backpressure<1000 || peak<256) return 3;
    std::printf("LOCAL_CDC_PAIR_PASS ticks=200000 writes=%llu reads=%llu full=%llu backpressure=%llu peak=%d reset_checks=%llu invalid_payload_compared=1\n",
        (unsigned long long)writes,(unsigned long long)reads,(unsigned long long)full,(unsigned long long)backpressure,peak,(unsigned long long)resetchecks);
    return 0;
}
