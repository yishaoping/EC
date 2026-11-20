
#include "TestHarness.h"
#include "bridges/clock.h"
#include <chrono>
#include <iostream>
#include <stdexcept>
static void require(bool b,const char*s){if(!b)throw std::runtime_error(s);}
struct Signal {
 TestHarness&t;std::string name;mpz_t cached;
 Signal(TestHarness&t,std::string name):t(t),name(name){mpz_init(cached);}
 ~Signal(){mpz_clear(cached);}
 Signal&operator=(uint64_t x){mpz_import(cached,1,-1,sizeof(x),0,0,&x);t.poke(name,cached);return *this;}
 Signal&operator=(Signal&x){return operator=(uint64_t(x));}
 operator uint64_t(){mpz_t x;mpz_init(x);t.peek(name,x);uint64_t r=mpz_get_ui(x);mpz_clear(x);return r;}
 struct Word{Signal&s;int i;
  void operator=(uint32_t v){for(int b=0;b<32;b++){if((v>>b)&1)mpz_setbit(s.cached,32*i+b);else mpz_clrbit(s.cached,32*i+b);}s.t.poke(s.name,s.cached);}
  operator uint32_t(){mpz_t x;mpz_init(x);s.t.peek(s.name,x);mpz_fdiv_q_2exp(x,x,32*i);uint32_t r=mpz_get_ui(x);mpz_clear(x);return r;}
 };
 Word operator[](int i){return Word{*this,i};}
};
struct Interface {
 Signal reset;
 Signal io_capture_ready;
 Signal io_capture_valid;
 Signal io_capture_bits_line;
 Signal io_capture_bits_key_valid;
 Signal io_capture_bits_key_writer;
 Signal io_capture_bits_key_generation;
 Signal io_capture_bits_key_contentSeq;
 Signal io_capture_bits_epoch;
 Signal io_capture_bits_param;
 Signal io_capture_bits_data_0;
 Signal io_capture_bits_data_1;
 Signal io_capture_bits_data_2;
 Signal io_capture_bits_data_3;
 Signal io_safeWatermark;
 Signal io_currentEpoch;
 Signal io_diagnosticDump;
 Signal io_diagnosticCycle;
 Signal io_resetStats;
 Signal io_countStats;
 Signal io_invalidate_valid;
 Signal io_invalidate_bits;
 Signal io_flush;
 Signal io_promote_ready;
 Signal io_promote_valid;
 Signal io_promote_bits_line;
 Signal io_promote_bits_key_valid;
 Signal io_promote_bits_key_writer;
 Signal io_promote_bits_key_generation;
 Signal io_promote_bits_key_contentSeq;
 Signal io_promote_bits_epoch;
 Signal io_promote_bits_param;
 Signal io_promote_bits_data_0;
 Signal io_promote_bits_data_1;
 Signal io_promote_bits_data_2;
 Signal io_promote_bits_data_3;
 Signal io_promote_bits_entry;
 Signal io_selected;
 Signal io_activeEntry;
 Signal io_activeLine;
 Signal io_activeKey_valid;
 Signal io_activeKey_writer;
 Signal io_activeKey_generation;
 Signal io_activeKey_contentSeq;
 Signal io_activeEpoch;
 Signal io_queued;
 Signal io_coalesced;
 Signal io_discarded;
 Signal io_releaseLines_0;
 Signal io_releaseLines_1;
 Signal io_releaseLines_2;
 Signal io_releaseLines_3;
 Signal io_releaseBlocked_0;
 Signal io_releaseBlocked_1;
 Signal io_releaseBlocked_2;
 Signal io_releaseBlocked_3;
 Signal io_releaseBlockingEntry_0;
 Signal io_releaseBlockingEntry_1;
 Signal io_releaseBlockingEntry_2;
 Signal io_releaseBlockingEntry_3;
 Signal io_releaseBlockingLine_0;
 Signal io_releaseBlockingLine_1;
 Signal io_releaseBlockingLine_2;
 Signal io_releaseBlockingLine_3;
 Signal io_releaseBlockingSeq_0;
 Signal io_releaseBlockingSeq_1;
 Signal io_releaseBlockingSeq_2;
 Signal io_releaseBlockingSeq_3;
 Signal io_releaseBlockingGeneration_0;
 Signal io_releaseBlockingGeneration_1;
 Signal io_releaseBlockingGeneration_2;
 Signal io_releaseBlockingGeneration_3;
 Signal io_ack_valid;
 Signal io_ack_bits_entry;
 Signal io_ack_bits_key_valid;
 Signal io_ack_bits_key_writer;
 Signal io_ack_bits_key_generation;
 Signal io_ack_bits_key_contentSeq;
 Signal io_occupancy;
 Signal io_maxOccupancy;
 Signal io_maxDepth;
 Signal io_depth;
 Signal io_occupancyHistogram_0;
 Signal io_occupancyHistogram_1;
 Signal io_occupancyHistogram_2;
 Signal io_occupancyHistogram_3;
 Signal io_occupancyHistogram_4;
 Signal io_occupancyHistogram_5;
 Signal io_occupancyHistogram_6;
 Signal io_occupancyHistogram_7;
 Signal io_occupancyHistogram_8;
 Signal io_occupancyHistogram_9;
 Signal io_occupancyHistogram_10;
 Signal io_occupancyHistogram_11;
 Signal io_occupancyHistogram_12;
 Signal io_occupancyHistogram_13;
 Signal io_occupancyHistogram_14;
 Signal io_occupancyHistogram_15;
 Signal io_occupancyHistogram_16;
 Signal io_occupancyHistogram_17;
 Signal io_occupancyHistogram_18;
 Signal io_occupancyHistogram_19;
 Signal io_occupancyHistogram_20;
 Signal io_occupancyHistogram_21;
 Signal io_occupancyHistogram_22;
 Signal io_occupancyHistogram_23;
 Signal io_occupancyHistogram_24;
 Signal io_occupancyHistogram_25;
 Signal io_occupancyHistogram_26;
 Signal io_occupancyHistogram_27;
 Signal io_occupancyHistogram_28;
 Signal io_occupancyHistogram_29;
 Signal io_occupancyHistogram_30;
 Signal io_occupancyHistogram_31;
 Signal io_occupancyHistogram_32;
 Signal io_depthHistogram_0;
 Signal io_depthHistogram_1;
 Signal io_depthHistogram_2;
 Signal io_depthHistogram_3;
 Signal io_depthHistogram_4;
 Signal io_depthHistogram_5;
 Signal io_depthHistogram_6;
 Signal io_depthHistogram_7;
 Signal io_depthHistogram_8;
 Signal io_depthHistogram_9;
 Signal io_depthHistogram_10;
 Signal io_depthHistogram_11;
 Signal io_depthHistogram_12;
 Signal io_depthHistogram_13;
 Signal io_depthHistogram_14;
 Signal io_depthHistogram_15;
 Signal io_depthHistogram_16;
 Signal io_depthHistogram_17;
 Signal io_depthHistogram_18;
 Signal io_depthHistogram_19;
 Signal io_depthHistogram_20;
 Signal io_depthHistogram_21;
 Signal io_depthHistogram_22;
 Signal io_depthHistogram_23;
 Signal io_depthHistogram_24;
 Signal io_depthHistogram_25;
 Signal io_depthHistogram_26;
 Signal io_depthHistogram_27;
 Signal io_depthHistogram_28;
 Signal io_depthHistogram_29;
 Signal io_depthHistogram_30;
 Signal io_depthHistogram_31;
 Signal io_depthHistogram_32;
 Signal io_observationSerial;
 Signal io_allocation;
 Signal io_allocatedEntry;
 Signal io_entryAccounting_0;
 Signal io_entryAccounting_1;
 Signal io_entryAccounting_2;
 Signal io_entryAccounting_3;
 Signal io_entryAccounting_4;
 Signal io_fullFallback;
 Signal io_promotion;
 Signal io_acked;
 Signal io_recoveryFromSvb;
 Interface(TestHarness&t):reset(t,"reset"),io_capture_ready(t,"io_capture_ready"),io_capture_valid(t,"io_capture_valid"),io_capture_bits_line(t,"io_capture_bits_line"),io_capture_bits_key_valid(t,"io_capture_bits_key_valid"),io_capture_bits_key_writer(t,"io_capture_bits_key_writer"),io_capture_bits_key_generation(t,"io_capture_bits_key_generation"),io_capture_bits_key_contentSeq(t,"io_capture_bits_key_contentSeq"),io_capture_bits_epoch(t,"io_capture_bits_epoch"),io_capture_bits_param(t,"io_capture_bits_param"),io_capture_bits_data_0(t,"io_capture_bits_data_0"),io_capture_bits_data_1(t,"io_capture_bits_data_1"),io_capture_bits_data_2(t,"io_capture_bits_data_2"),io_capture_bits_data_3(t,"io_capture_bits_data_3"),io_safeWatermark(t,"io_safeWatermark"),io_currentEpoch(t,"io_currentEpoch"),io_diagnosticDump(t,"io_diagnosticDump"),io_diagnosticCycle(t,"io_diagnosticCycle"),io_resetStats(t,"io_resetStats"),io_countStats(t,"io_countStats"),io_invalidate_valid(t,"io_invalidate_valid"),io_invalidate_bits(t,"io_invalidate_bits"),io_flush(t,"io_flush"),io_promote_ready(t,"io_promote_ready"),io_promote_valid(t,"io_promote_valid"),io_promote_bits_line(t,"io_promote_bits_line"),io_promote_bits_key_valid(t,"io_promote_bits_key_valid"),io_promote_bits_key_writer(t,"io_promote_bits_key_writer"),io_promote_bits_key_generation(t,"io_promote_bits_key_generation"),io_promote_bits_key_contentSeq(t,"io_promote_bits_key_contentSeq"),io_promote_bits_epoch(t,"io_promote_bits_epoch"),io_promote_bits_param(t,"io_promote_bits_param"),io_promote_bits_data_0(t,"io_promote_bits_data_0"),io_promote_bits_data_1(t,"io_promote_bits_data_1"),io_promote_bits_data_2(t,"io_promote_bits_data_2"),io_promote_bits_data_3(t,"io_promote_bits_data_3"),io_promote_bits_entry(t,"io_promote_bits_entry"),io_selected(t,"io_selected"),io_activeEntry(t,"io_activeEntry"),io_activeLine(t,"io_activeLine"),io_activeKey_valid(t,"io_activeKey_valid"),io_activeKey_writer(t,"io_activeKey_writer"),io_activeKey_generation(t,"io_activeKey_generation"),io_activeKey_contentSeq(t,"io_activeKey_contentSeq"),io_activeEpoch(t,"io_activeEpoch"),io_queued(t,"io_queued"),io_coalesced(t,"io_coalesced"),io_discarded(t,"io_discarded"),io_releaseLines_0(t,"io_releaseLines_0"),io_releaseLines_1(t,"io_releaseLines_1"),io_releaseLines_2(t,"io_releaseLines_2"),io_releaseLines_3(t,"io_releaseLines_3"),io_releaseBlocked_0(t,"io_releaseBlocked_0"),io_releaseBlocked_1(t,"io_releaseBlocked_1"),io_releaseBlocked_2(t,"io_releaseBlocked_2"),io_releaseBlocked_3(t,"io_releaseBlocked_3"),io_releaseBlockingEntry_0(t,"io_releaseBlockingEntry_0"),io_releaseBlockingEntry_1(t,"io_releaseBlockingEntry_1"),io_releaseBlockingEntry_2(t,"io_releaseBlockingEntry_2"),io_releaseBlockingEntry_3(t,"io_releaseBlockingEntry_3"),io_releaseBlockingLine_0(t,"io_releaseBlockingLine_0"),io_releaseBlockingLine_1(t,"io_releaseBlockingLine_1"),io_releaseBlockingLine_2(t,"io_releaseBlockingLine_2"),io_releaseBlockingLine_3(t,"io_releaseBlockingLine_3"),io_releaseBlockingSeq_0(t,"io_releaseBlockingSeq_0"),io_releaseBlockingSeq_1(t,"io_releaseBlockingSeq_1"),io_releaseBlockingSeq_2(t,"io_releaseBlockingSeq_2"),io_releaseBlockingSeq_3(t,"io_releaseBlockingSeq_3"),io_releaseBlockingGeneration_0(t,"io_releaseBlockingGeneration_0"),io_releaseBlockingGeneration_1(t,"io_releaseBlockingGeneration_1"),io_releaseBlockingGeneration_2(t,"io_releaseBlockingGeneration_2"),io_releaseBlockingGeneration_3(t,"io_releaseBlockingGeneration_3"),io_ack_valid(t,"io_ack_valid"),io_ack_bits_entry(t,"io_ack_bits_entry"),io_ack_bits_key_valid(t,"io_ack_bits_key_valid"),io_ack_bits_key_writer(t,"io_ack_bits_key_writer"),io_ack_bits_key_generation(t,"io_ack_bits_key_generation"),io_ack_bits_key_contentSeq(t,"io_ack_bits_key_contentSeq"),io_occupancy(t,"io_occupancy"),io_maxOccupancy(t,"io_maxOccupancy"),io_maxDepth(t,"io_maxDepth"),io_depth(t,"io_depth"),io_occupancyHistogram_0(t,"io_occupancyHistogram_0"),io_occupancyHistogram_1(t,"io_occupancyHistogram_1"),io_occupancyHistogram_2(t,"io_occupancyHistogram_2"),io_occupancyHistogram_3(t,"io_occupancyHistogram_3"),io_occupancyHistogram_4(t,"io_occupancyHistogram_4"),io_occupancyHistogram_5(t,"io_occupancyHistogram_5"),io_occupancyHistogram_6(t,"io_occupancyHistogram_6"),io_occupancyHistogram_7(t,"io_occupancyHistogram_7"),io_occupancyHistogram_8(t,"io_occupancyHistogram_8"),io_occupancyHistogram_9(t,"io_occupancyHistogram_9"),io_occupancyHistogram_10(t,"io_occupancyHistogram_10"),io_occupancyHistogram_11(t,"io_occupancyHistogram_11"),io_occupancyHistogram_12(t,"io_occupancyHistogram_12"),io_occupancyHistogram_13(t,"io_occupancyHistogram_13"),io_occupancyHistogram_14(t,"io_occupancyHistogram_14"),io_occupancyHistogram_15(t,"io_occupancyHistogram_15"),io_occupancyHistogram_16(t,"io_occupancyHistogram_16"),io_occupancyHistogram_17(t,"io_occupancyHistogram_17"),io_occupancyHistogram_18(t,"io_occupancyHistogram_18"),io_occupancyHistogram_19(t,"io_occupancyHistogram_19"),io_occupancyHistogram_20(t,"io_occupancyHistogram_20"),io_occupancyHistogram_21(t,"io_occupancyHistogram_21"),io_occupancyHistogram_22(t,"io_occupancyHistogram_22"),io_occupancyHistogram_23(t,"io_occupancyHistogram_23"),io_occupancyHistogram_24(t,"io_occupancyHistogram_24"),io_occupancyHistogram_25(t,"io_occupancyHistogram_25"),io_occupancyHistogram_26(t,"io_occupancyHistogram_26"),io_occupancyHistogram_27(t,"io_occupancyHistogram_27"),io_occupancyHistogram_28(t,"io_occupancyHistogram_28"),io_occupancyHistogram_29(t,"io_occupancyHistogram_29"),io_occupancyHistogram_30(t,"io_occupancyHistogram_30"),io_occupancyHistogram_31(t,"io_occupancyHistogram_31"),io_occupancyHistogram_32(t,"io_occupancyHistogram_32"),io_depthHistogram_0(t,"io_depthHistogram_0"),io_depthHistogram_1(t,"io_depthHistogram_1"),io_depthHistogram_2(t,"io_depthHistogram_2"),io_depthHistogram_3(t,"io_depthHistogram_3"),io_depthHistogram_4(t,"io_depthHistogram_4"),io_depthHistogram_5(t,"io_depthHistogram_5"),io_depthHistogram_6(t,"io_depthHistogram_6"),io_depthHistogram_7(t,"io_depthHistogram_7"),io_depthHistogram_8(t,"io_depthHistogram_8"),io_depthHistogram_9(t,"io_depthHistogram_9"),io_depthHistogram_10(t,"io_depthHistogram_10"),io_depthHistogram_11(t,"io_depthHistogram_11"),io_depthHistogram_12(t,"io_depthHistogram_12"),io_depthHistogram_13(t,"io_depthHistogram_13"),io_depthHistogram_14(t,"io_depthHistogram_14"),io_depthHistogram_15(t,"io_depthHistogram_15"),io_depthHistogram_16(t,"io_depthHistogram_16"),io_depthHistogram_17(t,"io_depthHistogram_17"),io_depthHistogram_18(t,"io_depthHistogram_18"),io_depthHistogram_19(t,"io_depthHistogram_19"),io_depthHistogram_20(t,"io_depthHistogram_20"),io_depthHistogram_21(t,"io_depthHistogram_21"),io_depthHistogram_22(t,"io_depthHistogram_22"),io_depthHistogram_23(t,"io_depthHistogram_23"),io_depthHistogram_24(t,"io_depthHistogram_24"),io_depthHistogram_25(t,"io_depthHistogram_25"),io_depthHistogram_26(t,"io_depthHistogram_26"),io_depthHistogram_27(t,"io_depthHistogram_27"),io_depthHistogram_28(t,"io_depthHistogram_28"),io_depthHistogram_29(t,"io_depthHistogram_29"),io_depthHistogram_30(t,"io_depthHistogram_30"),io_depthHistogram_31(t,"io_depthHistogram_31"),io_depthHistogram_32(t,"io_depthHistogram_32"),io_observationSerial(t,"io_observationSerial"),io_allocation(t,"io_allocation"),io_allocatedEntry(t,"io_allocatedEntry"),io_entryAccounting_0(t,"io_entryAccounting_0"),io_entryAccounting_1(t,"io_entryAccounting_1"),io_entryAccounting_2(t,"io_entryAccounting_2"),io_entryAccounting_3(t,"io_entryAccounting_3"),io_entryAccounting_4(t,"io_entryAccounting_4"),io_fullFallback(t,"io_fullFallback"),io_promotion(t,"io_promotion"),io_acked(t,"io_acked"),io_recoveryFromSvb(t,"io_recoveryFromSvb"){}
};
class SVBTest final:public TestHarness{public:using TestHarness::TestHarness;void run_test()override{log=false;Interface d(*this);unsigned cycle=0,passed=0;

 auto tick=[&](){d.io_diagnosticCycle=cycle;step(1);cycle++;};
 auto reset=[&](){d.io_capture_valid=0;d.io_safeWatermark=0;d.io_diagnosticDump=0;d.io_resetStats=0;d.io_countStats=1;d.io_invalidate_valid=0;d.io_flush=0;d.io_promote_ready=0;d.io_ack_valid=0;d.io_releaseLines_0=0x80001000;d.io_releaseLines_1=0;d.io_releaseLines_2=0;d.io_releaseLines_3=0;d.reset=1;tick();tick();d.reset=0;tick();};
 auto capture=[&](unsigned seq,unsigned gen,unsigned value){d.io_capture_bits_line=0x80001000;d.io_capture_bits_key_valid=1;d.io_capture_bits_key_writer=0;d.io_capture_bits_key_generation=gen;d.io_capture_bits_key_contentSeq=seq;d.io_capture_bits_epoch=1;d.io_capture_bits_param=3;for(int i=0;i<4;i++){d.io_capture_bits_data_0[i]=value+i;d.io_capture_bits_data_1[i]=value+4+i;d.io_capture_bits_data_2[i]=value+8+i;d.io_capture_bits_data_3[i]=value+12+i;}d.io_capture_valid=1;require(d.io_capture_ready,"capture blocked");tick();d.io_capture_valid=0;};
 auto bytes=[&](unsigned value){for(int i=0;i<4;i++){require(d.io_promote_bits_data_0[i]==value+i,"old row0 lost");require(d.io_promote_bits_data_1[i]==value+4+i,"old row1 lost");require(d.io_promote_bits_data_2[i]==value+8+i,"old row2 lost");require(d.io_promote_bits_data_3[i]==value+12+i,"old row3 lost");}};
 auto ack=[&](){d.io_ack_bits_entry=d.io_promote_bits_entry;d.io_ack_bits_key_valid=d.io_promote_bits_key_valid;d.io_ack_bits_key_writer=d.io_promote_bits_key_writer;d.io_ack_bits_key_generation=d.io_promote_bits_key_generation;d.io_ack_bits_key_contentSeq=d.io_promote_bits_key_contentSeq;d.io_ack_valid=1;require(d.io_acked,"matching ack rejected");tick();d.io_ack_valid=0;};
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
 reset();capture(5,10,0x4400);d.io_flush=1;tick();require(d.io_occupancy==1&&!d.io_capture_ready&&d.io_releaseBlocked_0,"flush lost SPEC ownership or admitted capture");d.io_flush=0;tick();require(d.io_occupancy==1&&!d.io_promote_valid,"unsafe SPEC escaped after flush");d.io_safeWatermark=5;tick();tick();require(d.io_promote_valid,"retained SPEC did not become publishable");bytes(0x4400);d.io_promote_ready=1;tick();d.io_promote_ready=0;ack();require(d.io_occupancy==0&&!d.io_releaseBlocked_0,"flushed retained SPEC did not drain after PASS/ACK");
 std::cout<<"OBSERVED_FROZEN_SEMANTICS SPEC_retained_across_flush_and_promoted_after_PASS=1\n";passed++;
 reset();capture(5,10,0x5500);capture(5,11,0x6600);d.io_safeWatermark=5;tick();tick();require(d.io_promote_valid&&d.io_promote_bits_key_generation==11,"same-sequence generation ordering");bytes(0x6600);d.io_promote_ready=1;tick();d.io_promote_ready=0;ack();require(d.io_occupancy==0,"coalesced predecessor leaked");passed++;
 reset();capture(4,10,0x7700);capture(5,11,0x8800);d.io_safeWatermark=5;tick();tick();require(d.io_promote_valid&&d.io_promote_bits_key_contentSeq==5,"consecutive version ordering");bytes(0x8800);d.io_promote_ready=1;tick();d.io_promote_ready=0;ack();require(d.io_occupancy==0,"safe superseded version leaked");passed++;
 std::cout<<"PASS emitted_SVB_component cases="<<passed<<" cycles="<<cycle<<" integrated_fault_recovery=NOT_TESTED\n";
auto&clk=get_bridge<clockmodule_t>();uint64_t start=clk.hcycle();
auto begin=std::chrono::steady_clock::now();step(10000);
double wall=std::chrono::duration<double>(std::chrono::steady_clock::now()-begin).count();
std::cout<<"SVB_HOST_MODEL_FREE_RUN target_cycles=10000 host_cycles="<<clk.hcycle()-start<<" wall_seconds="<<wall<<"\n";
}};TEST_MAIN(SVBTest)
