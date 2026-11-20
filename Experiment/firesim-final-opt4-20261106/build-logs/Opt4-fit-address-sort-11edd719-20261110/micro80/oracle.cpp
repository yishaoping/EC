#include "VScatter.h"
#include "verilated.h"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
static uint64_t rng = 0x736f72742d383000ULL;
static uint32_t next32() { rng ^= rng<<13; rng ^= rng>>7; rng ^= rng<<17; return uint32_t(rng); }
template<class T> static void put(T &p,int bit,int width,uint32_t x) {
  for(int b=0;b<width;b++) { uint32_t m=1u<<((bit+b)%32); auto &w=p[(bit+b)/32]; w=(w&~m)|((x&(1u<<b))?m:0); }
}
int main(int argc,char**argv) {
  Verilated::commandArgs(argc,argv); VScatter dut; const int bound[]={8,3,2,1}, widths[]={4,2,2,1}, offset[]={0,4,6,8};
  for(int trial=0;trial<8192;trial++) {
    for(int w=0;w<20;w++)dut.io_keys[w]=0; for(int w=0;w<23;w++)dut.io_terms[w]=0;
    uint64_t expected[256][4]={};
    for(int i=0;i<80;i++) {
      int key;
      switch(trial%8) {
        case 0:key=255;break; case 1:key=trial%256;break;
        case 2:key=i%3;break; case 3:key=255-i;break;
        case 4:key=i;break; default:key=next32()%256;
      }
      put(dut.io_keys,i*8,8,key);
      for(int g=0;g<4;g++) {
        int count=(trial%8==0)?bound[g]:int(next32()%(bound[g]+1));
        if(trial%8==1 && i!=trial%80)count=0;
        put(dut.io_terms,i*9+offset[g],widths[g],count); expected[key][g]+=count;
      }
    }
    dut.eval();
    for(int b=0;b<256;b++)for(int g=0;g<4;g++) {
      int word=b*8+g*2; uint64_t got=(uint64_t(dut.io_result[word+1])<<32)|dut.io_result[word];
      if(got!=expected[b][g]) { std::fprintf(stderr,"SCATTER_MISMATCH trial=%d bucket=%d granule=%d expected=%llu got=%llu\n",trial,b,g,(unsigned long long)expected[b][g],(unsigned long long)got); return 2; }
    }
  }
  puts("SCATTER_80_256_PASS vectors=8192 outputs_per_vector=1024 full_count_bounds=8,3,2,1"); return 0;
}
