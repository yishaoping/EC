#include "VInstalledPair.h"
#include "verilated.h"
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
static uint64_t rng=0x692f19a58301ULL;
static uint32_t randomWord(){rng^=rng<<13;rng^=rng>>7;rng^=rng<<17;return uint32_t(rng);}
int main(int argc,char**argv){
  Verilated::commandArgs(argc,argv);VInstalledPair d;
  using Word=std::array<uint32_t,3>;std::array<Word,512> memory{};
  std::array<bool,512> known{};unsigned checks=0,resetWrites=0,collisions=0,clockless=0;
  auto check=[&](){unsigned a=d.io_readIndex;if(!known[a])return;
    for(unsigned k=0;k<3;k++)if(d.io_reference[k]!=memory[a][k] || d.io_candidate[k]!=memory[a][k]){
      std::fprintf(stderr,"FAIL addr=%u field=%u ref=%x cand=%x expected=%x\n",a,k,d.io_reference[k],d.io_candidate[k],memory[a][k]);std::exit(1);
    }++checks;
  };
  for(unsigned c=0;c<8192;c++){
    d.clock=0;d.reset=(c%103==0 || c<3);d.io_write=c<512 || (c%5!=0);
    d.io_index=c<512?c:randomWord()%512;
    d.io_readIndex=c<512?c:(c%3==0?d.io_index:randomWord()%512);
    Word value={randomWord(),randomWord(),randomWord()&0x1ffffU};
    if(c%127==0)value={0xffffffffU,0xffffffffU,0x1ffffU};
    for(unsigned k=0;k<3;k++)d.io_data[k]=value[k];
    d.eval();check();if(d.io_write && d.io_index==d.io_readIndex)++collisions;
    d.io_readIndex=randomWord()%512;d.eval();check();++clockless;
    d.clock=1;d.eval();if(d.io_write){memory[d.io_index]=value;known[d.io_index]=true;if(d.reset)++resetWrites;}
    check();d.clock=0;d.eval();check();
  }
  // Every unreset word is initialized through its real write interface before
  // complete scanning; no initial-zero or valid-gating assumption enters proof.
  d.io_write=0;d.clock=0;
  for(unsigned i=0;i<512;i++){if(!known[i])return 2;d.io_readIndex=i;d.eval();check();}
  std::printf("INSTALLED_IMAGE_BOUNDARY_PASS cycles=8192 entries=512 bits=81 observations=%u reset_writes=%u collisions=%u clockless=%u all_words=512\n",checks,resetWrites,collisions,clockless);
}
