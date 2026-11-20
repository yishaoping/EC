#include "VAddressBucketSequenceMemory.h"
#include "verilated.h"
#include <cstdint>
#include <cstdio>

static uint32_t rng=0x71ebac93;
static uint32_t random32(){rng^=rng<<13;rng^=rng>>17;rng^=rng<<5;return rng;}
int main(int argc,char**argv){
  Verilated::commandArgs(argc,argv);VAddressBucketSequenceMemory d;
  CData* readIndex[]={&d.io_readIndex_0,&d.io_readIndex_1,&d.io_readIndex_2,&d.io_readIndex_3,&d.io_readIndex_4,&d.io_readIndex_5,&d.io_readIndex_6,&d.io_readIndex_7,&d.io_readIndex_8,&d.io_readIndex_9,&d.io_readIndex_10,&d.io_readIndex_11,&d.io_readIndex_12,&d.io_readIndex_13,&d.io_readIndex_14,&d.io_readIndex_15,&d.io_readIndex_16,&d.io_readIndex_17,&d.io_readIndex_18,&d.io_readIndex_19,&d.io_readIndex_20,&d.io_readIndex_21,&d.io_readIndex_22,&d.io_readIndex_23,&d.io_readIndex_24,&d.io_readIndex_25,&d.io_readIndex_26,&d.io_readIndex_27,&d.io_readIndex_28,&d.io_readIndex_29,&d.io_readIndex_30,&d.io_readIndex_31,&d.io_readIndex_32,&d.io_readIndex_33,&d.io_readIndex_34,&d.io_readIndex_35,&d.io_readIndex_36,&d.io_readIndex_37,&d.io_readIndex_38,&d.io_readIndex_39,&d.io_readIndex_40,&d.io_readIndex_41,&d.io_readIndex_42,&d.io_readIndex_43,&d.io_readIndex_44,&d.io_readIndex_45,&d.io_readIndex_46,&d.io_readIndex_47,&d.io_readIndex_48,&d.io_readIndex_49,&d.io_readIndex_50,&d.io_readIndex_51,&d.io_readIndex_52,&d.io_readIndex_53,&d.io_readIndex_54,&d.io_readIndex_55,&d.io_readIndex_56,&d.io_readIndex_57,&d.io_readIndex_58,&d.io_readIndex_59,&d.io_readIndex_60,&d.io_readIndex_61,&d.io_readIndex_62,&d.io_readIndex_63,&d.io_readIndex_64,&d.io_readIndex_65,&d.io_readIndex_66,&d.io_readIndex_67,&d.io_readIndex_68,&d.io_readIndex_69,&d.io_readIndex_70,&d.io_readIndex_71,&d.io_readIndex_72,&d.io_readIndex_73,&d.io_readIndex_74,&d.io_readIndex_75,&d.io_readIndex_76,&d.io_readIndex_77,&d.io_readIndex_78,&d.io_readIndex_79,&d.io_readIndex_80,&d.io_readIndex_81,&d.io_readIndex_82,&d.io_readIndex_83,&d.io_readIndex_84,&d.io_readIndex_85,&d.io_readIndex_86,&d.io_readIndex_87,&d.io_readIndex_88,&d.io_readIndex_89};
  IData* readData[]={&d.io_readData_0,&d.io_readData_1,&d.io_readData_2,&d.io_readData_3,&d.io_readData_4,&d.io_readData_5,&d.io_readData_6,&d.io_readData_7,&d.io_readData_8,&d.io_readData_9,&d.io_readData_10,&d.io_readData_11,&d.io_readData_12,&d.io_readData_13,&d.io_readData_14,&d.io_readData_15,&d.io_readData_16,&d.io_readData_17,&d.io_readData_18,&d.io_readData_19,&d.io_readData_20,&d.io_readData_21,&d.io_readData_22,&d.io_readData_23,&d.io_readData_24,&d.io_readData_25,&d.io_readData_26,&d.io_readData_27,&d.io_readData_28,&d.io_readData_29,&d.io_readData_30,&d.io_readData_31,&d.io_readData_32,&d.io_readData_33,&d.io_readData_34,&d.io_readData_35,&d.io_readData_36,&d.io_readData_37,&d.io_readData_38,&d.io_readData_39,&d.io_readData_40,&d.io_readData_41,&d.io_readData_42,&d.io_readData_43,&d.io_readData_44,&d.io_readData_45,&d.io_readData_46,&d.io_readData_47,&d.io_readData_48,&d.io_readData_49,&d.io_readData_50,&d.io_readData_51,&d.io_readData_52,&d.io_readData_53,&d.io_readData_54,&d.io_readData_55,&d.io_readData_56,&d.io_readData_57,&d.io_readData_58,&d.io_readData_59,&d.io_readData_60,&d.io_readData_61,&d.io_readData_62,&d.io_readData_63,&d.io_readData_64,&d.io_readData_65,&d.io_readData_66,&d.io_readData_67,&d.io_readData_68,&d.io_readData_69,&d.io_readData_70,&d.io_readData_71,&d.io_readData_72,&d.io_readData_73,&d.io_readData_74,&d.io_readData_75,&d.io_readData_76,&d.io_readData_77,&d.io_readData_78,&d.io_readData_79,&d.io_readData_80,&d.io_readData_81,&d.io_readData_82,&d.io_readData_83,&d.io_readData_84,&d.io_readData_85,&d.io_readData_86,&d.io_readData_87,&d.io_readData_88,&d.io_readData_89};
  uint32_t ref[256]={};bool initialized[256]={};
  unsigned same=0,resetWrites=0,disabled=0,clockless=0;
  for(unsigned t=0;t<8192;t++){
    d.clock=0;d.reset=t%113==0;d.io_writeEnable=t<256 || t%4!=0;
    unsigned a=t<256?t:((t%5==0)?255:((t*37+11)&255));
    d.io_writeIndex=a;
    const uint32_t edge[]={0,0xffffffff,0xffffff00,0x80000000,0x7fffffff,255,256};
    d.io_writeData=t%3==0?edge[t%7]:random32();
    for(unsigned r=0;r<90;r++){
      unsigned idx=(t%7==0)?a:((t*59+r*37+255)&255);
      *readIndex[r]=idx;same+=idx==a;
    }
    auto check=[&](){for(unsigned r=0;r<90;r++){
      unsigned i=*readIndex[r];if(initialized[i] && *readData[r]!=ref[i])return false;
    }return true;};
    d.eval();if(!check()){std::fprintf(stderr,"SEQUENCE_FAIL before t=%u\n",t);return 1;}
    d.clock=1;d.eval();
    if(d.io_writeEnable){ref[a]=d.io_writeData;initialized[a]=true;resetWrites+=d.reset;}else disabled++;
    if(!check()){std::fprintf(stderr,"SEQUENCE_FAIL after t=%u\n",t);return 2;}
    d.clock=0;
    for(unsigned r=0;r<90;r++)*readIndex[r]=(t+r)&255;
    d.eval();if(!check())return 3;clockless++;
  }
  if(!same||!resetWrites||!disabled||clockless!=8192)return 4;
  std::printf("SEQUENCE_ACTUAL_SIZE_PASS vectors=8192 slots=256 bits=32 readers=90 same=%u reset_write=%u disabled=%u clockless=%u\n",same,resetWrites,disabled,clockless);
  d.final();return 0;
}
