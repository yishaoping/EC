#include "VSelectionProbe.h"
#include "verilated.h"
#include <cstdint>
#include <cstdio>
static uint64_t rng=0xf2d2ca3e21c4b320ULL;
static uint32_t random32(){rng^=rng<<13;rng^=rng>>7;rng^=rng<<17;return rng;}
int main(int argc,char**argv){Verilated::commandArgs(argc,argv);VSelectionProbe dut;
for(unsigned t=0;t<8192;t++){unsigned valid[32],seq[32],gen[32];unsigned best=0;bool found=false;
for(unsigned i=0;i<32;i++) {valid[i]=t%8==0?0:t%8==1?1:random32()&1;seq[i]=t%8==2?0:t%8==3?0xffffffffu:random32();gen[i]=t%8==4?0:t%8==5?0xffffffffu:random32();if(t%8==6){seq[i]=t;gen[i]=t;}
const bool newer = !found || seq[i]>seq[best] || (seq[i]==seq[best] && (gen[i]>gen[best] || (gen[i]==gen[best] && i>best))); if(valid[i] && newer) {best=i;found=true;}}
dut.io_valid_0=valid[0];dut.io_seq_0=seq[0];dut.io_generation_0=gen[0];
dut.io_valid_1=valid[1];dut.io_seq_1=seq[1];dut.io_generation_1=gen[1];
dut.io_valid_2=valid[2];dut.io_seq_2=seq[2];dut.io_generation_2=gen[2];
dut.io_valid_3=valid[3];dut.io_seq_3=seq[3];dut.io_generation_3=gen[3];
dut.io_valid_4=valid[4];dut.io_seq_4=seq[4];dut.io_generation_4=gen[4];
dut.io_valid_5=valid[5];dut.io_seq_5=seq[5];dut.io_generation_5=gen[5];
dut.io_valid_6=valid[6];dut.io_seq_6=seq[6];dut.io_generation_6=gen[6];
dut.io_valid_7=valid[7];dut.io_seq_7=seq[7];dut.io_generation_7=gen[7];
dut.io_valid_8=valid[8];dut.io_seq_8=seq[8];dut.io_generation_8=gen[8];
dut.io_valid_9=valid[9];dut.io_seq_9=seq[9];dut.io_generation_9=gen[9];
dut.io_valid_10=valid[10];dut.io_seq_10=seq[10];dut.io_generation_10=gen[10];
dut.io_valid_11=valid[11];dut.io_seq_11=seq[11];dut.io_generation_11=gen[11];
dut.io_valid_12=valid[12];dut.io_seq_12=seq[12];dut.io_generation_12=gen[12];
dut.io_valid_13=valid[13];dut.io_seq_13=seq[13];dut.io_generation_13=gen[13];
dut.io_valid_14=valid[14];dut.io_seq_14=seq[14];dut.io_generation_14=gen[14];
dut.io_valid_15=valid[15];dut.io_seq_15=seq[15];dut.io_generation_15=gen[15];
dut.io_valid_16=valid[16];dut.io_seq_16=seq[16];dut.io_generation_16=gen[16];
dut.io_valid_17=valid[17];dut.io_seq_17=seq[17];dut.io_generation_17=gen[17];
dut.io_valid_18=valid[18];dut.io_seq_18=seq[18];dut.io_generation_18=gen[18];
dut.io_valid_19=valid[19];dut.io_seq_19=seq[19];dut.io_generation_19=gen[19];
dut.io_valid_20=valid[20];dut.io_seq_20=seq[20];dut.io_generation_20=gen[20];
dut.io_valid_21=valid[21];dut.io_seq_21=seq[21];dut.io_generation_21=gen[21];
dut.io_valid_22=valid[22];dut.io_seq_22=seq[22];dut.io_generation_22=gen[22];
dut.io_valid_23=valid[23];dut.io_seq_23=seq[23];dut.io_generation_23=gen[23];
dut.io_valid_24=valid[24];dut.io_seq_24=seq[24];dut.io_generation_24=gen[24];
dut.io_valid_25=valid[25];dut.io_seq_25=seq[25];dut.io_generation_25=gen[25];
dut.io_valid_26=valid[26];dut.io_seq_26=seq[26];dut.io_generation_26=gen[26];
dut.io_valid_27=valid[27];dut.io_seq_27=seq[27];dut.io_generation_27=gen[27];
dut.io_valid_28=valid[28];dut.io_seq_28=seq[28];dut.io_generation_28=gen[28];
dut.io_valid_29=valid[29];dut.io_seq_29=seq[29];dut.io_generation_29=gen[29];
dut.io_valid_30=valid[30];dut.io_seq_30=seq[30];dut.io_generation_30=gen[30];
dut.io_valid_31=valid[31];dut.io_seq_31=seq[31];dut.io_generation_31=gen[31];
dut.eval();if(!dut.io_equivalent||dut.io_chosenValid!=found||dut.io_chosenIdx!=(found?best:0)) {fprintf(stderr,"FAIL vector=%u\n",t);return 1;}}
puts("SVB_SELECTION_PASS vectors=8192 slots=32 seq=32 generation=32 ties=1 invalid=1 extrema=1");return 0;}
