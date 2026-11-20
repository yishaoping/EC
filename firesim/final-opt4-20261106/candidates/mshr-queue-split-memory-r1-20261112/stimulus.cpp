#include "VQueuePair.h"
#include "verilated.h"
#include <cstdint>
#include <cstdio>

static uint64_t rng=0x6a09e667f3bcc909ULL;
static uint32_t random32() { rng^=rng<<13; rng^=rng>>7; rng^=rng<<17; return uint32_t(rng); }
int main(int argc,char** argv) {
  Verilated::commandArgs(argc,argv);
  VQueuePair d;
  unsigned events=0;
  for(unsigned cycle=0;cycle<65536;cycle++) {
    d.clock=0;
    d.reset=(cycle<3 || cycle%4096<3);
    for(unsigned i=0;i<@ENQ_WORDS@;i++) d.io_enqBits[i]=random32();
    for(unsigned i=0;i<@BRANCH_WORDS@;i++) d.io_branch[i]=0;
    unsigned phase=(cycle/128)%8;
    d.io_enqValid=phase==0 ? 1 : (random32()%4!=0);
    d.io_deqReady=phase==0 ? 0 : phase==1 ? 1 : (random32()%3!=0);
    d.io_holdHead=phase==2 || (phase>=4 && random32()%5==0);
    d.io_flush=(phase==3 && cycle%11==0) || (phase==5 && random32()%4==0);
    if(phase>=4) for(unsigned i=0;i<@BRANCH_WORDS@;i++) d.io_branch[i]=random32();
    d.eval();
    if(!d.reset && d.io_mismatch) {
      std::printf("MSHR_QUEUE_MISMATCH cycle=%u bits=%x phase=%u\n",cycle,unsigned(d.io_mismatch),phase);
      return 1;
    }
    events|=d.io_events;
    d.clock=1;d.eval();
  }
  if(events!=255) { std::printf("MISSING_EVENT_COVERAGE events=%x\n",events);return 2; }
  std::printf("MSHR_QUEUE_FINITE_PASS cycles=65536 events=%x invalid_payloads_compared=1\n",events);
  d.final();
  return 0;
}
