#include "VBoomWritebackUnit.h"
#include "verilated.h"
#include <array>
#include <cstdint>
#include <deque>
#include <iostream>
#include <random>
#include <stdexcept>
struct Read {unsigned due,beat;};
int main(int argc,char** argv){
 Verilated::commandArgs(argc,argv);VBoomWritebackUnit d;std::mt19937 rng(20261103);
 unsigned cycle=0,snapshots=0,late_after_cancel=0;std::deque<Read> reads;
 std::array<std::array<uint32_t,4>,4> bytes{};
 auto check=[](bool ok,const char* s){if(!ok)throw std::runtime_error(s);};
 auto tick=[&](){
  d.clock=0;for(int j=0;j<4;j++)d.io_data_resp[j]=0;
  if(!reads.empty()&&reads.front().due==cycle){for(int j=0;j<4;j++)d.io_data_resp[j]=bytes[reads.front().beat][j];reads.pop_front();}
  d.eval();bool req=d.io_req_valid&&d.io_req_ready;
  bool rd=d.io_data_req_valid&&d.io_data_req_ready&&d.io_meta_read_ready;
  if(rd)reads.push_back({cycle+2,unsigned((d.io_data_req_bits_addr>>4)&3)});
  bool snapshot=d.io_snapshot_valid&&d.io_snapshot_ready;
  check(!d.io_release_valid,"capture emitted C release");
  d.clock=1;d.eval();cycle++;return std::array<bool,2>{req,snapshot};
 };
 d.reset=1;d.io_req_valid=0;d.io_svb_req_valid=0;d.io_mem_grant=0;d.io_snapshot_ready=0;
 d.io_meta_read_ready=1;d.io_data_req_ready=1;d.io_release_ready=1;d.io_lsu_release_ready=1;
 for(int i=0;i<5;i++)tick();d.reset=0;
 for(unsigned tx=0;tx<160;tx++){
  for(auto& row:bytes)for(auto& word:row)word=rng();
  unsigned seq=tx+1,gen=tx+100,tag=0x200+tx,idx=tx%256,epoch=tx+7;
  d.io_req_bits_tag=tag;d.io_req_bits_idx=idx;d.io_req_bits_param=3;d.io_req_bits_way_en=1;
  d.io_req_bits_voluntary=0;d.io_req_bits_svb_capture=1;d.io_req_is_mshr=0;
  d.io_image_key_valid=1;d.io_image_key_writer=0;d.io_image_key_generation=gen;d.io_image_key_contentSeq=seq;
  d.io_owner_epoch=epoch;d.io_image_generation=gen;d.io_image_valid=1;d.io_packet_seq=seq+1;d.io_packet_tracked=1;
  d.io_req_valid=1;d.io_snapshot_ready=0;check(tick()[0],"request not accepted");d.io_req_valid=0;
  bool cancelled=false,completed=false;unsigned hold=0;
  for(unsigned age=0;age<160&&!completed;age++){
   if(tx%2==0&&age==tx%8)cancelled=true;
   d.io_meta_read_ready=rng()%4!=0;d.io_data_req_ready=d.io_meta_read_ready;
   d.clock=0;d.eval();
   if(d.io_snapshot_valid){
    check(d.io_snapshot_line==((uint64_t(tag)<<14)|(uint64_t(idx)<<6)),"snapshot line changed");
    check(d.io_snapshot_key_generation==gen&&d.io_snapshot_key_contentSeq==seq&&d.io_snapshot_epoch==epoch,"snapshot key/epoch changed");
    for(int j=0;j<4;j++){
     check(d.io_snapshot_data_0[j]==bytes[0][j],"snapshot bytes0 changed");
     check(d.io_snapshot_data_1[j]==bytes[1][j],"snapshot bytes1 changed");
     check(d.io_snapshot_data_2[j]==bytes[2][j],"snapshot bytes2 changed");
     check(d.io_snapshot_data_3[j]==bytes[3][j],"snapshot bytes3 changed");
    }
    check(!d.io_req_ready,"reader reused before snapshot consumed");
    hold++;
   }
   d.io_snapshot_ready=hold>5;
   auto events=tick();
   if(events[1]){snapshots++;late_after_cancel+=cancelled;completed=true;}
  }
  check(completed,"snapshot failed to drain");d.io_snapshot_ready=0;tick();d.eval();
  check(!d.io_snapshot_valid&&d.io_req_ready,"snapshot duplicated or reader not released");
  check(reads.empty(),"array response left behind");
 }
 check(snapshots==160&&late_after_cancel==80,"wrong transaction counts");
 std::cout<<"PASS actual_BoomWritebackUnit snapshots="<<snapshots<<" responses_after_controller_cancel="<<late_after_cancel<<" cycles="<<cycle<<" (controller cancellation is modeled; WB RTL unchanged)\n";d.final();
}
