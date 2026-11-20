#include "VAsyncMemoryProbe.h"
#include "verilated.h"
#include <cstdint>
#include <cstdio>
#include <limits>

static uint64_t seed=0xb73e4a829de15067ULL;
static uint64_t random64(){seed^=seed<<13;seed^=seed>>7;seed^=seed<<17;return seed;}
int main(int argc,char**argv){
  Verilated::commandArgs(argc,argv); VAsyncMemoryProbe d;
  uint64_t* input[]={&d.io_writeData_0_0,&d.io_writeData_0_1,&d.io_writeData_0_2,&d.io_writeData_0_3,&d.io_writeData_1_0,&d.io_writeData_1_1,&d.io_writeData_1_2,&d.io_writeData_1_3};
  uint64_t* delta[]={&d.io_delta_0_0,&d.io_delta_0_1,&d.io_delta_0_2,&d.io_delta_0_3,&d.io_delta_1_0,&d.io_delta_1_1,&d.io_delta_1_2,&d.io_delta_1_3};
  uint64_t* current[]={&d.io_current_0_0,&d.io_current_0_1,&d.io_current_0_2,&d.io_current_0_3,&d.io_current_1_0,&d.io_current_1_1,&d.io_current_1_2,&d.io_current_1_3};
  uint64_t* retiring[]={&d.io_retiring_0_0,&d.io_retiring_0_1,&d.io_retiring_0_2,&d.io_retiring_0_3,&d.io_retiring_1_0,&d.io_retiring_1_1,&d.io_retiring_1_2,&d.io_retiring_1_3};
  uint64_t* next[]={&d.io_next_0_0,&d.io_next_0_1,&d.io_next_0_2,&d.io_next_0_3,&d.io_next_1_0,&d.io_next_1_1,&d.io_next_1_2,&d.io_next_1_3};
  CData* overflow[]={&d.io_overflow_0_0,&d.io_overflow_0_1,&d.io_overflow_0_2,&d.io_overflow_0_3,&d.io_overflow_1_0,&d.io_overflow_1_1,&d.io_overflow_1_2,&d.io_overflow_1_3};
  uint64_t words[256][8]={}; bool initialized[256]={};
  unsigned before_checks=0,after_checks=0,overflows=0,invalid_checks=0,same_address=0;
  for(unsigned t=0;t<8192;t++){
    unsigned a=t<256?t:((t%5==0)?255:((t*37+11)&255));
    unsigned b=t%7==0?a:((t*59+255)&255);
    d.clock=0;d.reset=t%113==0;d.io_currentIndex=a;d.io_retiringIndex=b;
    d.io_writeEnable=t<256 || t%4!=0;d.io_currentValid=t%3!=0;d.io_retiringValid=t%5!=0;
    same_address+=(a==b);
    for(unsigned j=0;j<8;j++){
      switch((t+j)%6){case 0:*input[j]=UINT64_MAX;break;case 1:*input[j]=UINT64_MAX-1;break;case 2:*input[j]=0;break;case 3:*input[j]=uint64_t(1)<<63;break;default:*input[j]=random64();}
      switch((t+j)%7){case 0:*delta[j]=UINT64_MAX;break;case 1:*delta[j]=1;break;case 2:*delta[j]=0;break;case 3:*delta[j]=8;break;case 4:*delta[j]=640;break;default:*delta[j]=random64();}
    }
    auto check=[&]()->bool{
      for(unsigned j=0;j<8;j++){
        if(initialized[a] && *current[j]!=words[a][j])return false;
        if(initialized[b] && *retiring[j]!=(d.io_retiringValid?words[b][j]:0))return false;
        if(initialized[a] || !d.io_currentValid){
          unsigned __int128 sum=(unsigned __int128)(d.io_currentValid?words[a][j]:0)+*delta[j];
          if(*next[j]!=(uint64_t)sum || bool(*overflow[j])!=bool(sum>>64))return false;
          overflows+=bool(sum>>64);invalid_checks+=!d.io_currentValid;
        }
      }
      return true;
    };
    d.eval();if(!check()){std::fprintf(stderr,"ASYNC_FAIL before t=%u a=%u b=%u\n",t,a,b);return 1;}before_checks++;
    d.clock=1;d.eval();
    if(d.io_writeEnable){for(unsigned j=0;j<8;j++)words[a][j]=*input[j];initialized[a]=true;}
    if(!check()){std::fprintf(stderr,"ASYNC_FAIL after t=%u a=%u b=%u\n",t,a,b);return 1;}after_checks++;
    // Changing an address without a clock edge must change the async output.
    d.clock=0;d.io_currentIndex=b;d.io_retiringIndex=a;d.eval();
    for(unsigned j=0;j<8;j++){
      if(initialized[b] && *current[j]!=words[b][j])return 2;
      if(initialized[a] && *retiring[j]!=(d.io_retiringValid?words[a][j]:0))return 3;
    }
  }
  if(overflows==0 || same_address==0 || invalid_checks==0)return 4;
  std::printf("ASYNC_ACTUAL_SIZE_PASS vectors=8192 slots=256 words=2048 bits=64 before=%u after=%u carries=%u invalid=%u same_address=%u reset clockless_reads\n",before_checks,after_checks,overflows,invalid_checks,same_address);
  d.final();return 0;
}
