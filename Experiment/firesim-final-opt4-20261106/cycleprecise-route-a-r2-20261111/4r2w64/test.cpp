#include "VSpaceTimePair.h"
#include "verilated.h"
#include <array>
#include <chrono>
#include <iostream>
#include <random>
#include <stdexcept>
using Data=std::array<uint32_t,3>;
VSpaceTimePair d;
std::mt19937_64 gen(8491167);
void set_r_addr(int i,uint32_t x){switch(i){
case 0: d.io_model_read_cmds_0_bits_addr=x;d.io_reference_read_cmds_0_addr=x;break;
case 1: d.io_model_read_cmds_1_bits_addr=x;d.io_reference_read_cmds_1_addr=x;break;
case 2: d.io_model_read_cmds_2_bits_addr=x;d.io_reference_read_cmds_2_addr=x;break;
case 3: d.io_model_read_cmds_3_bits_addr=x;d.io_reference_read_cmds_3_addr=x;break;
}}
void set_r_en(int i,uint32_t x){switch(i){
case 0: d.io_model_read_cmds_0_bits_en=x;d.io_reference_read_cmds_0_en=x;break;
case 1: d.io_model_read_cmds_1_bits_en=x;d.io_reference_read_cmds_1_en=x;break;
case 2: d.io_model_read_cmds_2_bits_en=x;d.io_reference_read_cmds_2_en=x;break;
case 3: d.io_model_read_cmds_3_bits_en=x;d.io_reference_read_cmds_3_en=x;break;
}}
void set_w_addr(int i,uint32_t x){switch(i){
case 0: d.io_model_write_cmds_0_bits_addr=x;d.io_reference_write_cmds_0_addr=x;break;
case 1: d.io_model_write_cmds_1_bits_addr=x;d.io_reference_write_cmds_1_addr=x;break;
}}
void set_w_en(int i,uint32_t x){switch(i){
case 0: d.io_model_write_cmds_0_bits_en=x;d.io_reference_write_cmds_0_en=x;break;
case 1: d.io_model_write_cmds_1_bits_en=x;d.io_reference_write_cmds_1_en=x;break;
}}
void set_w_mask(int i,uint32_t x){switch(i){
case 0: d.io_model_write_cmds_0_bits_mask=x;d.io_reference_write_cmds_0_mask=x;break;
case 1: d.io_model_write_cmds_1_bits_mask=x;d.io_reference_write_cmds_1_mask=x;break;
}}
void r_valid(int i,bool x){switch(i){
case 0: d.io_model_read_cmds_0_valid=x;break;
case 1: d.io_model_read_cmds_1_valid=x;break;
case 2: d.io_model_read_cmds_2_valid=x;break;
case 3: d.io_model_read_cmds_3_valid=x;break;
}}
bool r_ready(int i){switch(i){
case 0: return d.io_model_read_cmds_0_ready;
case 1: return d.io_model_read_cmds_1_ready;
case 2: return d.io_model_read_cmds_2_ready;
case 3: return d.io_model_read_cmds_3_ready;
}return false;}
void w_valid(int i,bool x){switch(i){
case 0: d.io_model_write_cmds_0_valid=x;break;
case 1: d.io_model_write_cmds_1_valid=x;break;
}}
bool w_ready(int i){switch(i){
case 0: return d.io_model_write_cmds_0_ready;
case 1: return d.io_model_write_cmds_1_ready;
}return false;}
void resp_ready(int i,bool x){switch(i){
case 0: d.io_model_read_resps_0_ready=x;break;
case 1: d.io_model_read_resps_1_ready=x;break;
case 2: d.io_model_read_resps_2_ready=x;break;
case 3: d.io_model_read_resps_3_ready=x;break;
}}
bool resp_valid(int i){switch(i){
case 0: return d.io_model_read_resps_0_valid;
case 1: return d.io_model_read_resps_1_valid;
case 2: return d.io_model_read_resps_2_valid;
case 3: return d.io_model_read_resps_3_valid;
}return false;}
Data response(int i,bool ref){Data v{};switch(i){
case 0:
v[0]=ref ? uint32_t(d.io_reference_read_resps_0 >> 0) : uint32_t(d.io_model_read_resps_0_bits >> 0);
v[1]=ref ? uint32_t(d.io_reference_read_resps_0 >> 32) : uint32_t(d.io_model_read_resps_0_bits >> 32);
break;
case 1:
v[0]=ref ? uint32_t(d.io_reference_read_resps_1 >> 0) : uint32_t(d.io_model_read_resps_1_bits >> 0);
v[1]=ref ? uint32_t(d.io_reference_read_resps_1 >> 32) : uint32_t(d.io_model_read_resps_1_bits >> 32);
break;
case 2:
v[0]=ref ? uint32_t(d.io_reference_read_resps_2 >> 0) : uint32_t(d.io_model_read_resps_2_bits >> 0);
v[1]=ref ? uint32_t(d.io_reference_read_resps_2 >> 32) : uint32_t(d.io_model_read_resps_2_bits >> 32);
break;
case 3:
v[0]=ref ? uint32_t(d.io_reference_read_resps_3 >> 0) : uint32_t(d.io_model_read_resps_3_bits >> 0);
v[1]=ref ? uint32_t(d.io_reference_read_resps_3 >> 32) : uint32_t(d.io_model_read_resps_3_bits >> 32);
break;
}return v;}
void set_data(int i,Data v){switch(i){
case 0:
d.io_model_write_cmds_0_bits_data=uint64_t(v[0]) | (uint64_t(v[1])<<32);
d.io_reference_write_cmds_0_data=uint64_t(v[0]) | (uint64_t(v[1])<<32);
break;
case 1:
d.io_model_write_cmds_1_bits_data=uint64_t(v[0]) | (uint64_t(v[1])<<32);
d.io_reference_write_cmds_1_data=uint64_t(v[0]) | (uint64_t(v[1])<<32);
break;
}}
int main(int argc,char**argv){
  const bool negative=argc>1; const int R=4,W=2; Data mem[512]{};
  bool initialized[512]{}; uint64_t hosts=0,compared=0,conflicts=0,resets=0,collisions=0;
  auto began=std::chrono::steady_clock::now();
  d.clock=0;d.reset=1;d.io_targetClock=0;d.io_targetReset=0;d.io_model_reset_valid=0;
  for(int i=0;i<R;i++){r_valid(i,0);resp_ready(i,0);} for(int i=0;i<W;i++)w_valid(i,0);
  for(int i=0;i<5;i++){d.clock=0;d.eval();d.clock=1;d.eval();}d.clock=0;d.reset=0;d.eval();
  for(int t=0;t<8192;t++){
    bool tr=t>=512 && t%173==0;resets+=tr;d.io_targetReset=tr;d.io_model_reset_bits=tr;
    bool rd[R]{},wr[W]{},resp[R]{},rst=false;int ra[R],wa[W];bool wen[W];Data wd[W];
    for(int i=0;i<W;i++){
      wa[i]=t<512 ? t : gen()%512; if(i>0 && t%7==0)wa[i]=wa[0];
      wen[i]=t<512 || gen()%4; wd[i]={uint32_t(gen()),uint32_t(gen()),uint32_t(gen())&0};
      if(64<=64)wd[i][2]=0;
      set_w_addr(i,wa[i]);set_w_en(i,wen[i]);set_w_mask(i,1);set_data(i,wd[i]);
      if(i>0 && wa[i]==wa[0] && wen[i] && wen[0])collisions++;
    }
    for(int i=0;i<R;i++){
      ra[i]=t>=512 && i==0 ? wa[0] : gen()%512;
      conflicts+=t>=512 && ra[i]==wa[0] && wen[0];set_r_addr(i,ra[i]);set_r_en(i,1);
    }
    d.clock=0;d.eval();Data expected[R];
    for(int i=0;i<R;i++){expected[i]=response(i,true);if(initialized[ra[i]] && expected[i]!=mem[ra[i]])throw std::runtime_error("reference mismatch");}
    int h=0;
    while(true){
      if(++h>1000)throw std::runtime_error("watchdog");
      d.io_model_reset_valid=!rst;
      for(int i=0;i<R;i++){r_valid(i,!rd[i] && gen()%5!=0);resp_ready(i,!resp[i] && gen()%4!=0);}
      for(int i=0;i<W;i++)w_valid(i,!wr[i] && gen()%5!=0);
      d.clock=0;d.eval();
      if(d.io_model_reset_valid && d.io_model_reset_ready)rst=true;
      for(int i=0;i<R;i++){
        if(d.io_model_read_resps_0_valid){} // model evaluated above before edge
        bool valid=false;switch(i){case 0:valid=d.io_model_read_resps_0_valid;break;case 1:valid=d.io_model_read_resps_1_valid;break;case 2:valid=d.io_model_read_resps_2_valid;break;case 3:valid=d.io_model_read_resps_3_valid;break;}
        bool ready=false;switch(i){case 0:ready=d.io_model_read_resps_0_ready;break;case 1:ready=d.io_model_read_resps_1_ready;break;case 2:ready=d.io_model_read_resps_2_ready;break;case 3:ready=d.io_model_read_resps_3_ready;break;}
        if(valid && ready){Data got=response(i,false);if(negative && t==513 && i==0)got[0]^=1;
          if(initialized[ra[i]] && got!=expected[i]){std::cerr<<"MISMATCH target="<<t<<" read="<<i<<"\n";return 2;}
          compared+=initialized[ra[i]];resp[i]=true;
        }
        bool v=false;switch(i){case 0:v=d.io_model_read_cmds_0_valid;break;case 1:v=d.io_model_read_cmds_1_valid;break;case 2:v=d.io_model_read_cmds_2_valid;break;case 3:v=d.io_model_read_cmds_3_valid;break;} if(v && r_ready(i))rd[i]=true;
      }
      for(int i=0;i<W;i++){bool v=false;switch(i){case 0:v=d.io_model_write_cmds_0_valid;break;case 1:v=d.io_model_write_cmds_1_valid;break;}if(v && w_ready(i))wr[i]=true;}
      d.clock=1;d.eval();d.clock=0;d.eval();hosts++;
      bool done=rst;for(int i=0;i<R;i++)done&=rd[i]&&resp[i];for(int i=0;i<W;i++)done&=wr[i];if(done)break;
    }
    d.io_targetClock=1;d.eval();d.io_targetClock=0;d.eval();
    for(int i=0;i<W;i++)if(wen[i]&&!tr){mem[wa[i]]=wd[i];initialized[wa[i]]=true;}
  }
  double wall=std::chrono::duration<double>(std::chrono::steady_clock::now()-began).count();
  std::cout<<"{\"status\":\"PASS\",\"target_cycles\":8192,\"host_cycles\":"<<hosts
   <<",\"fmr_host_over_target\":"<<double(hosts)/8192<<",\"compared_read_values\":"<<compared
   <<",\"read_write_conflicts\":"<<conflicts<<",\"same_address_writes\":"<<collisions
   <<",\"target_reset_tokens\":"<<resets<<",\"wall_seconds\":"<<wall
   <<",\"target_cycles_per_second\":"<<8192/wall<<"}\n";
}
