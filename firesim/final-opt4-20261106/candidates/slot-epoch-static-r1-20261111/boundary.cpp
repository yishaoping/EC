#include "VEpochPair.h"
#include "verilated.h"
#include <cstdint>
#include <cstdio>
#include <cstdlib>

static uint64_t rng=0x8491167d9ae9a7fcULL;
static uint32_t next(){rng^=rng<<13;rng^=rng>>7;rng^=rng<<17;return rng;}
int main(int argc,char** argv){
  Verilated::commandArgs(argc,argv);VEpochPair d;
  unsigned collisions=0,disjoint=0,resetWrites=0,overflowSeeds=0,clockless=0,seedIndex=0;
  auto check=[&](unsigned cycle,const char* phase){d.eval();if(!d.io_equal){std::fprintf(stderr,"FAIL cycle=%u phase=%s\n",cycle,phase);std::exit(1);}};
  d.clock=0;d.reset=1;d.io_enable=0;d.io_refill=0;
  for(int p=0;p<3;p++)d.io_index[p]=0;
  for(int r=0;r<12;r++)d.io_readIndex[r]=r;
  check(0,"initial");d.clock=1;check(0,"initial-reset");
  for(unsigned c=0;c<8192;c++){
    d.clock=0;d.reset=(c%997==0||c==512||c==513);
    d.io_enable=next()&7;d.io_refill=(c%31==0)?65535:(next()&65535);
    for(int p=0;p<3;p++)d.io_index[p]=next()&511;
    if(c%3==0){d.io_index[1]=d.io_index[0];d.io_index[2]=d.io_index[0];d.io_enable=7;collisions++;}
    else {d.io_index[1]=(d.io_index[0]+1)&511;d.io_index[2]=(d.io_index[0]+2)&511;disjoint++;}
    // Establish 0xffff then increment the same word on the next clock.
    if(c%31==0){d.io_enable=4;seedIndex=d.io_index[2];overflowSeeds++;}
    if(c%31==1){d.io_index[0]=seedIndex;d.io_enable=1;}
    for(int r=0;r<12;r++)d.io_readIndex[r]=(r<3)?d.io_index[r]:next()&511;
    if(d.reset&&d.io_enable)resetWrites++;
    check(c,"before-edge");d.clock=1;check(c,"after-edge");
    d.clock=0;for(int r=0;r<12;r++)d.io_readIndex[r]=next()&511;
    check(c,"asynchronous-read");clockless++;
  }
  std::printf("SLOT_EPOCH_BOUNDARY_PASS cycles=8192 entries=512 bits=16 writes=3 readers=12 snapshot=512 collisions=%u disjoint=%u reset_write=%u overflow_seeds=%u clockless=%u\n",collisions,disjoint,resetWrites,overflowSeeds,clockless);
  return 0;
}
