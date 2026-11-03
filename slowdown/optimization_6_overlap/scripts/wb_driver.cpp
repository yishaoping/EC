#include "VBoomWritebackUnit.h"
#include "verilated.h"
#include <array>
#include <cstdint>
#include <deque>
#include <iostream>
#include <random>
#include <stdexcept>

using Row = std::array<uint32_t, 4>;
struct Read { unsigned due; unsigned beat; };
struct Tx { uint32_t seq, gen, tag; unsigned idx, epoch, param; bool voluntary; std::array<Row,4> bytes; };

int main(int argc, char** argv) {
  Verilated::commandArgs(argc, argv);
  VBoomWritebackUnit d;
  std::mt19937 rng(20261103);
  unsigned cycle=0, beats=0, receipts=0, probes=0, source_blocks=0;
  std::deque<Read> reads;
  Tx active{}; unsigned seen=0; bool live=false;
  auto require=[](bool ok, const char* msg) { if (!ok) throw std::runtime_error(msg); };
  auto tick=[&]() {
    d.clock=0;
    for (int j=0;j<4;j++) d.io_data_resp[j]=0;
    if (!reads.empty() && reads.front().due==cycle) {
      for (int j=0;j<4;j++) d.io_data_resp[j]=active.bytes[reads.front().beat][j];
      reads.pop_front();
    }
    d.eval();
    bool req=d.io_req_valid && d.io_req_ready;
    bool rd=d.io_data_req_valid && d.io_data_req_ready && d.io_meta_read_ready;
    bool rel=d.io_release_valid && d.io_release_ready;
    bool done=d.io_done_valid;
    if (req) { live=true; seen=0; }
    if (rd) reads.push_back({cycle+2, unsigned((d.io_data_req_bits_addr>>4)&3)});
    if (d.io_release_valid) {
      require(live, "release without current data owner");
      require(d.io_release_bits_param==active.param, "permission report changed");
      require(d.io_release_bits_opcode==(active.voluntary?7:5), "wrong C opcode");
      require(d.io_release_bits_address==((active.tag<<14)|(active.idx<<6)), "wrong release address");
      require(d.io_release_bits_user_cache_image_valid && d.io_release_bits_user_cache_image_writer==0 &&
              d.io_release_bits_user_cache_image_generation==active.gen &&
              d.io_release_bits_user_cache_image_contentSeq==active.seq, "wrong snapshot image");
      for (int j=0;j<4;j++) require(d.io_release_bits_data[j]==active.bytes[seen][j], "release bytes changed under backpressure");
    }
    if (rel) { ++seen; ++beats; if (seen==4) live=false; }
    d.clock=1; d.eval(); ++cycle;
    if (done) ++receipts;
    return req;
  };
  d.reset=1; d.io_req_valid=0; d.io_svb_req_valid=0; d.io_mem_grant=0;
  d.io_snapshot_ready=0; d.io_meta_read_ready=1; d.io_data_req_ready=1;
  d.io_release_ready=1; d.io_lsu_release_ready=1;
  for(int i=0;i<5;i++)tick();
  d.reset=0;
  auto start=[&](Tx t) {
    active=t;
    d.io_req_bits_tag=t.tag; d.io_req_bits_idx=t.idx; d.io_req_bits_param=t.param;
    d.io_req_bits_way_en=1; d.io_req_bits_voluntary=t.voluntary;
    d.io_req_bits_svb_capture=0; d.io_req_is_mshr=0;
    d.io_image_key_valid=1; d.io_image_key_writer=0;
    d.io_image_key_generation=t.gen; d.io_image_key_contentSeq=t.seq;
    d.io_owner_epoch=t.epoch; d.io_image_generation=t.gen; d.io_image_valid=1;
    d.io_packet_seq=t.seq; d.io_packet_tracked=1; d.io_req_valid=1;
    require(tick(), "unexpected request backpressure"); d.io_req_valid=0;
  };
  auto transfer=[&]() {
    for (unsigned i=0;live && i<500;i++) {
      bool rd=rng()%4!=0;
      d.io_meta_read_ready=rd; d.io_data_req_ready=rd;
      d.io_release_ready=rng()%3!=0; d.io_lsu_release_ready=rng()%3!=0;
      tick();
    }
    require(!live && seen==4, "transfer failed to progress");
    require(reads.empty(), "array responses left behind");
    d.io_release_ready=1; d.io_lsu_release_ready=1;
  };
  for (unsigned i=0;i<300;i++) {
    Tx t{}; t.seq=i+1;t.gen=i+100;t.tag=0x200+i;t.idx=i%256;t.epoch=i+7;
    t.param=(i%2==0)?3:1; t.voluntary=true; // TtoT or TtoN
    for(auto& row:t.bytes)for(auto& w:row)w=rng();
    start(t); transfer();
    require(d.io_pending_idx_valid && d.io_pending_sent, "source lost before ACK");
    // Busy voluntary source must refuse another voluntary publication.
    for(unsigned j=0;j<3;j++) { d.io_req_valid=1;d.io_req_bits_voluntary=1;d.eval();
      require(!d.io_req_ready, "busy source accepted second voluntary owner");++source_blocks;tick(); }
    d.io_req_valid=0;
    // A probe uses the row-reader while the original voluntary ACK owner stays.
    if (i%3==0) {
      Tx p=t;p.voluntary=false;p.seq=2000+i;p.gen=3000+i;p.tag+=0x500;p.param=2;
      for(auto& row:p.bytes)for(auto& w:row)w=rng();
      start(p); transfer(); ++probes;
      require(d.io_pending_key_contentSeq==t.seq && d.io_pending_key_generation==t.gen &&
              d.io_done_epoch==t.epoch, "probe overwrote outstanding receipt identity");
    }
    for(unsigned j=0;j<rng()%8;j++)tick();
    d.io_mem_grant=1;tick();d.io_mem_grant=0;d.eval();
    require(d.io_done_valid && d.io_done_bits_contentSeq==t.seq && d.io_done_bits_generation==t.gen &&
            d.io_done_epoch==t.epoch,"receipt wrong or missing");
    tick();d.eval();require(!d.io_pending_idx_valid && !d.io_done_valid,"ACK owner not released exactly once");
  }
  require(receipts==300,"receipt count mismatch");
  std::cout<<"PASS actual_BoomWritebackUnit transactions=300 probes_during_ack="<<probes
           <<" beats="<<beats<<" receipts="<<receipts<<" source_blocks="<<source_blocks
           <<" cycles="<<cycle<<"\n";
  d.final();
}
