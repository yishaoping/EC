#include "VSpeculativeVersionBuffer.h"
#include "verilated.h"
#include <cstdint>
#include <iostream>
#include <stdexcept>
// Component stimuli only: invalidate models the DCache's FAIL/CANCELLED input.
// No checker error injection, CPU rollback, L1 refill or architectural restart.
static void require(bool b,const char* s){if(!b)throw std::runtime_error(s);}
int main(int argc,char**argv){
 Verilated::commandArgs(argc,argv);VSpeculativeVersionBuffer d;unsigned cycle=0,passed=0;
 auto tick=[&](){d.clock=0;d.io_diagnosticCycle=cycle;d.eval();d.clock=1;d.eval();cycle++;d.clock=0;d.eval();};
 auto reset=[&](){d.io_capture_valid=0;d.io_safeWatermark=0;d.io_currentEpoch=1;d.io_diagnosticDump=0;d.io_resetStats=0;d.io_countStats=1;d.io_invalidate_valid=0;d.io_flush=0;d.io_promote_ready=0;d.io_ack_valid=0;d.io_releaseLines_0=0x80001000;d.io_releaseLines_1=0;d.io_releaseLines_2=0;d.io_releaseLines_3=0;d.reset=1;tick();tick();d.reset=0;tick();};
 auto capture=[&](unsigned seq,unsigned gen,unsigned value){d.io_capture_bits_line=0x80001000;d.io_capture_bits_key_valid=1;d.io_capture_bits_key_writer=0;d.io_capture_bits_key_generation=gen;d.io_capture_bits_key_contentSeq=seq;d.io_capture_bits_epoch=1;d.io_capture_bits_param=3;for(int i=0;i<4;i++){d.io_capture_bits_data_0[i]=value+i;d.io_capture_bits_data_1[i]=value+4+i;d.io_capture_bits_data_2[i]=value+8+i;d.io_capture_bits_data_3[i]=value+12+i;}d.io_capture_valid=1;d.eval();require(d.io_capture_ready,"capture blocked");tick();d.io_capture_valid=0;d.eval();};
 auto bytes=[&](unsigned value){for(int i=0;i<4;i++){require(d.io_promote_bits_data_0[i]==value+i,"old row0 lost");require(d.io_promote_bits_data_1[i]==value+4+i,"old row1 lost");require(d.io_promote_bits_data_2[i]==value+8+i,"old row2 lost");require(d.io_promote_bits_data_3[i]==value+12+i,"old row3 lost");}};
 auto ack=[&](){d.io_ack_bits_entry=d.io_promote_bits_entry;d.io_ack_bits_key_valid=d.io_promote_bits_key_valid;d.io_ack_bits_key_writer=d.io_promote_bits_key_writer;d.io_ack_bits_key_generation=d.io_promote_bits_key_generation;d.io_ack_bits_key_contentSeq=d.io_promote_bits_key_contentSeq;d.io_ack_valid=1;d.eval();require(d.io_acked,"matching ack rejected");tick();d.io_ack_valid=0;d.eval();};
 for(unsigned timing=0;timing<12;timing++){
  reset();capture(5,10,0x1100);capture(6,11,0x2200);
  require(d.io_occupancy==2&&d.io_releaseBlocked_0,"old versions not retained");
  for(int i=0;i<4;i++)tick();require(!d.io_promote_valid,"unsafe version promoted");
  // FAIL for younger package at the safe-watermark boundary preserves seq5.
  d.io_safeWatermark=5;d.io_invalidate_valid=1;d.io_invalidate_bits=5;tick();d.io_invalidate_valid=0;tick();
  require(d.io_promote_valid&&d.io_promote_bits_key_contentSeq==5,"safe predecessor unavailable");bytes(0x1100);
  for(unsigned i=0;i<timing;i++){tick();bytes(0x1100);require(d.io_releaseBlocked_0,"release escaped before send");}
  d.io_promote_ready=1;tick();d.io_promote_ready=0;
  // FAIL/flush before ACK cannot delete WB_WAIT ownership or bytes.
  d.io_invalidate_valid=1;d.io_invalidate_bits=0;d.io_flush=(timing%2)==0;tick();d.io_invalidate_valid=0;d.io_flush=0;
  require(d.io_occupancy==1&&d.io_releaseBlocked_0,"WB_WAIT deleted before ACK");bytes(0x1100);
  for(unsigned i=0;i<timing;i++)tick();
  // Exercise FAIL and flush on the ACK edge as well.
  d.io_invalidate_valid=(timing%3)==0;d.io_flush=(timing%4)==0;ack();d.io_invalidate_valid=0;d.io_flush=0;
  require(d.io_occupancy==0&&!d.io_releaseBlocked_0,"ACK did not release owner");passed++;
 }
 reset();capture(5,10,0x3300);d.io_invalidate_valid=1;d.io_invalidate_bits=4;tick();d.io_invalidate_valid=0;
 require(d.io_occupancy==0,"expected younger-than-watermark discard absent");
 std::cout<<"OBSERVED_LIMITATION unsafe_SPEC_predecessor_discarded_on_FAIL=1 (no rollback read interface)\n";passed++;
 reset();capture(5,10,0x4400);d.io_flush=1;tick();d.io_flush=0;require(d.io_occupancy==0,"SPEC flush did not discard");
 std::cout<<"OBSERVED_LIMITATION SPEC_snapshot_discarded_on_exception_flush=1\n";passed++;
 reset();capture(5,10,0x5500);capture(5,11,0x6600);d.io_safeWatermark=5;tick();tick();require(d.io_promote_valid&&d.io_promote_bits_key_generation==11,"same-sequence generation ordering");bytes(0x6600);d.io_promote_ready=1;tick();d.io_promote_ready=0;ack();require(d.io_occupancy==0,"coalesced predecessor leaked");passed++;
 reset();capture(4,10,0x7700);capture(5,11,0x8800);d.io_safeWatermark=5;tick();tick();require(d.io_promote_valid&&d.io_promote_bits_key_contentSeq==5,"consecutive version ordering");bytes(0x8800);d.io_promote_ready=1;tick();d.io_promote_ready=0;ack();require(d.io_occupancy==0,"safe superseded version leaked");passed++;
 std::cout<<"PASS emitted_SVB_component cases="<<passed<<" cycles="<<cycle<<" integrated_fault_recovery=NOT_TESTED\n";d.final();
}
