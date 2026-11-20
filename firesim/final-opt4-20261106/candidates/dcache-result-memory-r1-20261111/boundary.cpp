#include "VResultMemoryPair.h"
#include "verilated.h"
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
static uint64_t rng=0x6a09e667f3bcc909ULL;
static uint64_t random64(){rng^=rng<<13;rng^=rng>>7;rng^=rng<<17;return rng;}
int main(int argc,char **argv){
  Verilated::commandArgs(argc,argv);VResultMemoryPair d;
  std::array<uint64_t,512> model{};std::array<bool,512> valid{};
  auto readCheck=[&](unsigned a,unsigned b){
    d.io_readSet_0=a/8;d.io_readWay_0=a%8;
    d.io_readSet_1=b/8;d.io_readWay_1=b%8;d.eval();
    if((valid[a]&&(d.io_reference_0!=model[a]||d.io_candidate_0!=model[a]))||
       (valid[b]&&(d.io_reference_1!=model[b]||d.io_candidate_1!=model[b]))){
      std::fprintf(stderr,"RESULT_MEMORY_FAIL a=%u b=%u reset=%u wr=%u\n",a,b,d.reset,d.io_writeEnable);std::exit(2);
    }
  };
  // Initialize through the real write port before observing arbitrary payload.
  for(unsigned cycle=0;cycle<8192;++cycle){
    unsigned w=cycle<512?cycle:random64()%512;
    unsigned a=cycle<512?w:random64()%512,b=random64()%512;
    if(cycle%7==0)a=w;if(cycle%11==0)b=w;
    d.clock=0;d.reset=cycle%257==0 || cycle==512 || cycle==513;
    d.io_writeEnable=cycle<512 || cycle%5!=0;
    d.io_writeSet=w/8;d.io_writeWay=w%8;
    d.io_writeData=cycle%13==0?~uint64_t(0):(cycle%17==0?0:random64());
    readCheck(a,b); // Old word before the active edge, even on write collisions.
    d.clock=1;d.eval();
    if(d.io_writeEnable){model[w]=d.io_writeData;valid[w]=true;}
    readCheck(a,b); // New word after the edge; reset does not clear payload.
    d.clock=0;d.eval();
    // Independent read addresses and all set/way boundaries, without an edge.
    readCheck(0,511);readCheck(7,504);
  }
  for(unsigned a=0;a<512;++a)readCheck(a,511-a);
  std::puts("RESULT_MEMORY_ACTUAL_SIZE_PASS cycles=8192 entries=512 bits=64 reads=2 reset_write_preserved=1 pre_post_edge=1");
  d.final();return 0;
}
