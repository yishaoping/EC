#include "VQueuePair.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>
#include <cstdint>
int main(int argc,char**argv){
 Verilated::commandArgs(argc,argv);VQueuePair d;
 uint64_t seed=0x8491167d6fada307ULL;unsigned full=0,backpressure=0,deliver=0,checks=0;
 auto rnd=[&](){seed^=seed<<13;seed^=seed>>7;seed^=seed<<17;return seed;};
 auto eval=[&](unsigned t){d.eval();++checks;
   if(d.io_readyFlat!=d.io_readyLocal||d.io_validFlat!=d.io_validLocal||d.io_bitsFlat!=d.io_bitsLocal){
     std::printf("RESULT_CDC_MISMATCH tick=%u checks=%u\n",t,checks);std::exit(1);}
 };
 for(unsigned t=0;t<131072;++t){
   // Checker/result source is slower than the BOOM sink; also exercise phase
   // offsets and independent source/sink reset during activity.
   d.io_enqClock=(t/4)&1;d.io_deqClock=(t/2)&1;
   d.io_enqReset=t<64||(t>=40000&&t<40064);
   d.io_deqReset=t<64||(t>=80000&&t<80064);
   if(t%8==0){auto r=rnd();d.io_enqValid=(t%16384)<12000||(r&1);d.io_enqBits=r&0x3ffffffffULL;}
   if(t%4==0)d.io_deqReady=(t%16384)>=8000&&((rnd()&7)!=0);
   eval(t);
   full+=d.io_enqValid&&!d.io_readyFlat;backpressure+=d.io_validFlat&&!d.io_deqReady;
   deliver+=d.io_validFlat&&d.io_deqReady;
 }
 if(full<1000||backpressure<1000||deliver<1000)return 2;
 std::printf("RESULT_CDC_ALL_OUTPUT_PASS ticks=131072 checks=%u full=%u backpressure=%u delivery_samples=%u\n",checks,full,backpressure,deliver);
}
