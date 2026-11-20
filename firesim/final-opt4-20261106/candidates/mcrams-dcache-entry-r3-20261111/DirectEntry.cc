#include "VEntryDUT.h"
#include "verilated.h"
#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <stdexcept>
using Data=std::array<uint32_t,3>;
int main(){
 VEntryDUT d;std::mt19937_64 random(8491167);std::ofstream trace("target-cycles.txt");
 Data memory[512]{},captured[35]{};bool written[512]{},captureValid[35]{};
 uint64_t cycle=0,checked=0,skipped=0,conflicts=0,resets=0,pairs=0,sweep=0;
 auto require=[](bool ok,const char*n){if(!ok)throw std::runtime_error(n);};
 auto hexdata=[&](Data v){trace<<std::hex<<std::setfill('0')<<std::setw(8)<<v[2]<<std::setw(8)<<v[1]<<std::setw(8)<<v[0]<<std::setfill(' ');};
 auto run=[&](bool reset,bool wen,unsigned wa,Data wd,std::array<unsigned,35> ra){
  d.clock=0;d.reset=reset;d.io_writeEnable=wen;d.io_writeAddress=wa;
  for(unsigned k=0;k<3;k++)d.io_writeData[k]=wd[k];
  d.io_address_0=ra[0];
  d.io_address_1=ra[1];
  d.io_address_2=ra[2];
  d.io_address_3=ra[3];
  d.io_address_4=ra[4];
  d.io_address_5=ra[5];
  d.io_address_6=ra[6];
  d.io_address_7=ra[7];
  d.io_address_8=ra[8];
  d.io_address_9=ra[9];
  d.io_address_10=ra[10];
  d.io_address_11=ra[11];
  d.io_address_12=ra[12];
  d.io_address_13=ra[13];
  d.io_address_14=ra[14];
  d.io_address_15=ra[15];
  d.io_address_16=ra[16];
  d.io_address_17=ra[17];
  d.io_address_18=ra[18];
  d.io_address_19=ra[19];
  d.io_address_20=ra[20];
  d.io_address_21=ra[21];
  d.io_address_22=ra[22];
  d.io_address_23=ra[23];
  d.io_address_24=ra[24];
  d.io_address_25=ra[25];
  d.io_address_26=ra[26];
  d.io_address_27=ra[27];
  d.io_address_28=ra[28];
  d.io_address_29=ra[29];
  d.io_address_30=ra[30];
  d.io_address_31=ra[31];
  d.io_address_32=ra[32];
  d.io_address_33=ra[33];
  d.io_address_34=ra[34];
  d.eval();
  std::array<Data,35> observed,capture,expected;std::array<bool,35> valid;
  for(unsigned k=0;k<3;k++){observed[0][k]=d.io_data_0[k];capture[0][k]=d.io_captured_0[k];}
  for(unsigned k=0;k<3;k++){observed[1][k]=d.io_data_1[k];capture[1][k]=d.io_captured_1[k];}
  for(unsigned k=0;k<3;k++){observed[2][k]=d.io_data_2[k];capture[2][k]=d.io_captured_2[k];}
  for(unsigned k=0;k<3;k++){observed[3][k]=d.io_data_3[k];capture[3][k]=d.io_captured_3[k];}
  for(unsigned k=0;k<3;k++){observed[4][k]=d.io_data_4[k];capture[4][k]=d.io_captured_4[k];}
  for(unsigned k=0;k<3;k++){observed[5][k]=d.io_data_5[k];capture[5][k]=d.io_captured_5[k];}
  for(unsigned k=0;k<3;k++){observed[6][k]=d.io_data_6[k];capture[6][k]=d.io_captured_6[k];}
  for(unsigned k=0;k<3;k++){observed[7][k]=d.io_data_7[k];capture[7][k]=d.io_captured_7[k];}
  for(unsigned k=0;k<3;k++){observed[8][k]=d.io_data_8[k];capture[8][k]=d.io_captured_8[k];}
  for(unsigned k=0;k<3;k++){observed[9][k]=d.io_data_9[k];capture[9][k]=d.io_captured_9[k];}
  for(unsigned k=0;k<3;k++){observed[10][k]=d.io_data_10[k];capture[10][k]=d.io_captured_10[k];}
  for(unsigned k=0;k<3;k++){observed[11][k]=d.io_data_11[k];capture[11][k]=d.io_captured_11[k];}
  for(unsigned k=0;k<3;k++){observed[12][k]=d.io_data_12[k];capture[12][k]=d.io_captured_12[k];}
  for(unsigned k=0;k<3;k++){observed[13][k]=d.io_data_13[k];capture[13][k]=d.io_captured_13[k];}
  for(unsigned k=0;k<3;k++){observed[14][k]=d.io_data_14[k];capture[14][k]=d.io_captured_14[k];}
  for(unsigned k=0;k<3;k++){observed[15][k]=d.io_data_15[k];capture[15][k]=d.io_captured_15[k];}
  for(unsigned k=0;k<3;k++){observed[16][k]=d.io_data_16[k];capture[16][k]=d.io_captured_16[k];}
  for(unsigned k=0;k<3;k++){observed[17][k]=d.io_data_17[k];capture[17][k]=d.io_captured_17[k];}
  for(unsigned k=0;k<3;k++){observed[18][k]=d.io_data_18[k];capture[18][k]=d.io_captured_18[k];}
  for(unsigned k=0;k<3;k++){observed[19][k]=d.io_data_19[k];capture[19][k]=d.io_captured_19[k];}
  for(unsigned k=0;k<3;k++){observed[20][k]=d.io_data_20[k];capture[20][k]=d.io_captured_20[k];}
  for(unsigned k=0;k<3;k++){observed[21][k]=d.io_data_21[k];capture[21][k]=d.io_captured_21[k];}
  for(unsigned k=0;k<3;k++){observed[22][k]=d.io_data_22[k];capture[22][k]=d.io_captured_22[k];}
  for(unsigned k=0;k<3;k++){observed[23][k]=d.io_data_23[k];capture[23][k]=d.io_captured_23[k];}
  for(unsigned k=0;k<3;k++){observed[24][k]=d.io_data_24[k];capture[24][k]=d.io_captured_24[k];}
  for(unsigned k=0;k<3;k++){observed[25][k]=d.io_data_25[k];capture[25][k]=d.io_captured_25[k];}
  for(unsigned k=0;k<3;k++){observed[26][k]=d.io_data_26[k];capture[26][k]=d.io_captured_26[k];}
  for(unsigned k=0;k<3;k++){observed[27][k]=d.io_data_27[k];capture[27][k]=d.io_captured_27[k];}
  for(unsigned k=0;k<3;k++){observed[28][k]=d.io_data_28[k];capture[28][k]=d.io_captured_28[k];}
  for(unsigned k=0;k<3;k++){observed[29][k]=d.io_data_29[k];capture[29][k]=d.io_captured_29[k];}
  for(unsigned k=0;k<3;k++){observed[30][k]=d.io_data_30[k];capture[30][k]=d.io_captured_30[k];}
  for(unsigned k=0;k<3;k++){observed[31][k]=d.io_data_31[k];capture[31][k]=d.io_captured_31[k];}
  for(unsigned k=0;k<3;k++){observed[32][k]=d.io_data_32[k];capture[32][k]=d.io_captured_32[k];}
  for(unsigned k=0;k<3;k++){observed[33][k]=d.io_data_33[k];capture[33][k]=d.io_captured_33[k];}
  for(unsigned k=0;k<3;k++){observed[34][k]=d.io_data_34[k];capture[34][k]=d.io_captured_34[k];}
  for(unsigned i=0;i<35;i++){
   expected[i]=written[ra[i]]?memory[ra[i]]:Data{};
   bool conflict=wen&&!reset&&ra[i]==wa;conflicts+=conflict;
   valid[i]=!conflict||!written[ra[i]];
   if(valid[i])require(observed[i]==expected[i],"direct data scoreboard mismatch");
   if(captureValid[i])require(capture[i]==captured[i],"direct capture scoreboard mismatch");
  }
  trace<<std::dec<<cycle<<" "<<reset;
  for(auto a:ra)trace<<" "<<std::hex<<a;
  trace<<" "<<std::hex<<wa<<" ";hexdata(wd);trace<<" "<<wen;
  for(auto x:observed){trace<<" ";hexdata(x);}for(auto x:capture){trace<<" ";hexdata(x);}
  for(auto x:valid){trace<<" "<<x;checked+=x;skipped+=!x;}
  for(auto x:captureValid){trace<<" "<<x;checked+=x;skipped+=!x;}
  trace<<"\n";
  for(unsigned i=0;i<35;i++){captured[i]=reset?Data{}:expected[i];captureValid[i]=reset||valid[i];}
  if(reset){for(auto &x:written)x=false;resets++;}else if(wen){memory[wa]=wd;written[wa]=true;}
  d.clock=1;d.eval();d.clock=0;d.eval();cycle++;
 };
 auto addresses=[&](unsigned wa,bool same){std::array<unsigned,35> ra;for(unsigned i=0;i<35;i++)ra[i]=same?wa:random()%512;return ra;};
 for(unsigned i=0;i<5;i++)run(true,false,0,{},addresses(0,true));
 // Every address is written, then the write is withdrawn, and a new target
 // boundary checks the committed data through all35 actual read ports.
 for(unsigned a=0;a<512;a++){
  Data wd={uint32_t(random()),uint32_t(random()),uint32_t(random())&0x1ffffu};
  run(false,true,a,wd,addresses(a,true));
  run(false,false,a,{},addresses(a,true));pairs++;
 }
 for(unsigned t=0;t<1024;t++){
  bool rst=t%173==0;bool wen=random()%4!=0;unsigned wa=random()%512;
  Data wd={uint32_t(random()),uint32_t(random()),uint32_t(random())&0x1ffffu};
  auto ra=addresses(wa,t%11==0);ra[0]=wa;run(rst,wen,wa,wd,ra);
 }
 for(unsigned a=0;a<512;a++){run(false,false,a,{},addresses(a,true));sweep++;}
 run(true,true,0,{1,2,3},addresses(0,true));run(false,false,0,{},addresses(0,true));
 run(false,false,0,{},addresses(0,true));run(false,false,511,{},addresses(511,true));
 trace.close();
 std::ofstream result("reference-summary.json");
 result<<"{\"scoreboard_pass\":true,\"target_cycles\":"<<cycle<<",\"compared_values\":"<<checked<<",\"undefined_values_skipped\":"<<skipped<<",\"read_write_conflicts\":"<<conflicts<<",\"reset_cycles\":"<<resets<<",\"read_after_write_pairs\":"<<pairs<<",\"sweep_addresses\":"<<sweep<<"}\n";
 std::cout<<"REFERENCE_PASS cycles="<<cycle<<" checked="<<checked<<" skipped="<<skipped<<" pairs="<<pairs<<" sweep="<<sweep<<"\n";
}
