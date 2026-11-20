#include "VStoragePair.h"
#include "verilated.h"
#include <array>
#include <cstdio>
#include <cstdint>
static uint64_t rng=0xb5d11ce415ac729fULL;
static uint32_t next(){rng^=rng<<13;rng^=rng>>7;rng^=rng<<17;return uint32_t(rng);}
int main(int argc,char**argv){
 Verilated::commandArgs(argc,argv);VStoragePair m;
 std::array<std::array<uint32_t,5>,512> model{};
 for(int t=0;t<8192;t++){
  m.clock=0;m.reset=t<2 || t==1025 || t==4096;
  m.io_writeEnable=(next()%5)!=0;m.io_writeIndex=(t<1024?t%512:next()%512);
  std::array<uint32_t,5> data{};
  for(int w=0;w<5;w++)m.io_writeData[w]=data[w]=next();
  m.io_writeData[4]&=0x3ffff;data[4]&=0x3ffff;
  std::array<unsigned,8> idx{};
  uint16_t* ports[]={&m.io_readIndex_0,&m.io_readIndex_1,&m.io_readIndex_2,&m.io_readIndex_3,&m.io_readIndex_4,&m.io_readIndex_5,&m.io_readIndex_6,&m.io_readIndex_7};
  for(int r=0;r<8;r++)*ports[r]=idx[r]=(r==0?m.io_writeIndex:next()%512);
  auto check=[&](){
   m.eval();if(t>=2 && !m.io_equal){std::fprintf(stderr,"mismatch cycle%d\n",t);return false;}
   if(t>=2){std::array<uint32_t,5> sum{};for(auto i:idx)for(int w=0;w<5;w++)sum[w]^=model[i][w];
    for(int w=0;w<5;w++)if(m.io_checksum[w]!=sum[w]){std::fprintf(stderr,"model mismatch cycle%d word%d\n",t,w);return false;}}
   return true;
  };
  if(!check())return 1;
  if(m.reset)for(auto &x:model)x={};else if(m.io_writeEnable){
   // Mirror actual image/generation/packet/tracked aliases after each write.
   auto raw=data;std::array<uint32_t,5> canonical{};
   auto bit=[&](int b){return (raw[b/32]>>(b%32))&1;};
   auto put=[&](int b,unsigned v){canonical[b/32]|=(v&1)<<(b%32);};
   for(int b=65;b<146;b++)put(b,bit(b));
   for(int b=0;b<32;b++){put(33+b,bit(97+b));put(1+b,bit(65+b));}
   unsigned seq=0;for(int b=0;b<32;b++)seq|=bit(65+b)<<b;
   put(0,bit(145)&&(seq!=0));model[m.io_writeIndex]=canonical;
  }
  m.clock=1;if(!check())return 2;
 }
 std::puts("PASS_8192_CYCLES_512_ENTRIES_146_BITS_8_ASYNC_READERS_ALL512_GENERATION_TAPS_CANONICAL_SOURCE_ALIAS_RESET_COLLISIONS");m.final();return 0;
}
