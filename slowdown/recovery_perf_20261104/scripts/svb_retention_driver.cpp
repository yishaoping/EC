#include "VSpeculativeVersionBuffer.h"
#include "verilated.h"
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <string>

static VSpeculativeVersionBuffer d;
static unsigned checks = 0;
static void check(bool ok, const char* text) {
  ++checks;
  if (!ok) { std::fprintf(stderr, "FAIL: %s at cycle %llu\n", text,
      (unsigned long long)d.io_diagnosticCycle); std::exit(1); }
}
static void tick() {
  d.clock=0; d.eval(); d.clock=1; d.eval();
  ++d.io_diagnosticCycle; d.clock=0; d.eval();
}
static void clear_inputs() {
  d.reset=0; d.io_capture_valid=0; d.io_safeWatermark=0;
  d.io_currentEpoch=0; d.io_diagnosticDump=0; d.io_diagnosticCycle=0;
  d.io_resetStats=0; d.io_countStats=0; d.io_invalidate_valid=0;
  d.io_invalidate_bits=0; d.io_flush=0; d.io_promote_ready=0;
  d.io_releaseLines_0=0; d.io_releaseLines_1=0;
  d.io_releaseLines_2=0; d.io_releaseLines_3=0;
  d.io_ack_valid=0; d.io_ack_bits_entry=0; d.io_ack_bits_key_valid=0;
  d.io_ack_bits_key_writer=0; d.io_ack_bits_key_generation=0;
  d.io_ack_bits_key_contentSeq=0;
}
static uint32_t word(unsigned seq, unsigned index) {
  return 0x12345678u ^ (seq*0x1020304u) ^ (index*0xabcdef01u);
}
static void capture(unsigned seq, uint64_t line, unsigned gen) {
  d.io_capture_valid=1; d.io_capture_bits_line=line;
  d.io_capture_bits_key_valid=1; d.io_capture_bits_key_writer=7;
  d.io_capture_bits_key_generation=gen; d.io_capture_bits_key_contentSeq=seq;
  d.io_capture_bits_epoch=d.io_currentEpoch; d.io_capture_bits_param=0;
  for (unsigned i=0;i<4;++i) {
    d.io_capture_bits_data_0[i]=word(seq,i);
    d.io_capture_bits_data_1[i]=word(seq,i+4);
    d.io_capture_bits_data_2[i]=word(seq,i+8);
    d.io_capture_bits_data_3[i]=word(seq,i+12);
  }
  d.eval(); check(d.io_capture_ready,"capture space"); tick(); d.io_capture_valid=0; d.eval();
}
static void expect_payload(unsigned seq, uint64_t line, unsigned gen) {
  check(d.io_promote_bits_key_valid && d.io_promote_bits_key_writer==7 &&
    d.io_promote_bits_key_contentSeq==seq && d.io_promote_bits_key_generation==gen &&
    d.io_promote_bits_line==line,"retained snapshot identity");
  for(unsigned i=0;i<4;++i) {
    check(d.io_promote_bits_data_0[i]==word(seq,i),"snapshot row0 bytes");
    check(d.io_promote_bits_data_1[i]==word(seq,i+4),"snapshot row1 bytes");
    check(d.io_promote_bits_data_2[i]==word(seq,i+8),"snapshot row2 bytes");
    check(d.io_promote_bits_data_3[i]==word(seq,i+12),"snapshot row3 bytes");
  }
}
static void reset_case() {
  clear_inputs(); d.reset=1; for(int i=0;i<4;++i)tick(); d.reset=0; tick();
}
static void wait_payload(unsigned seq, uint64_t line, unsigned gen) {
  for(int i=0;i<8 && !d.io_promote_valid;++i)tick();
  check(d.io_promote_valid,"bounded publication progress");expect_payload(seq,line,gen);
}
static void complete(unsigned seq,unsigned gen) {
  const unsigned entry=d.io_promote_bits_entry;
  d.io_promote_ready=1;tick();d.io_promote_ready=0;
  d.io_ack_bits_entry=entry;d.io_ack_bits_key_valid=1;d.io_ack_bits_key_writer=7;
  d.io_ack_bits_key_generation=gen;d.io_ack_bits_key_contentSeq=seq;
  d.io_ack_valid=1;d.eval();check(d.io_acked,"exact publication ACK");
  tick();d.io_ack_valid=0;d.eval();
}
static void safe_publication_cases() {
  // Flush before scheduler selection must retain already-safe bytes. Resetting
  // epoch/sequence to the same values is also a boundary, not a new owner.
  for(unsigned seq: {0u,3u}) {
    reset_case();d.io_safeWatermark=3;capture(seq,0x80001000ull,300+seq);
    d.io_flush=1;d.io_invalidate_valid=1;d.io_invalidate_bits=0;
    tick();d.io_flush=0;d.io_invalidate_valid=0;d.io_safeWatermark=0;
    d.io_currentEpoch=seq?1:0;d.io_releaseLines_0=0x80001000ull;d.eval();
    check(d.io_occupancy==1 && !d.io_capture_ready,"safe SPEC survives epoch reset; admission drains");
    wait_payload(seq,0x80001000ull,300+seq);
    for(int i=0;i<1024;++i) {
      check(d.io_releaseBlocked_0 && !d.io_capture_ready,"safe owner blocks younger release/capture");
      expect_payload(seq,0x80001000ull,300+seq);tick();
    }
    complete(seq,300+seq);tick();
    check(d.io_occupancy==0 && d.io_capture_ready && !d.io_releaseBlocked_0,"boundary drains after ACK");
  }
  // A safe-at-capture owner can coalesce into a later snapshot that became
  // safe after capture. The successor inherits the durable obligation.
  reset_case();d.io_safeWatermark=1;capture(1,0x80002000ull,401);
  wait_payload(1,0x80002000ull,401); // Keep unrelated WB arbitration blocked.
  d.io_safeWatermark=2;capture(2,0x80003000ull,402);
  capture(3,0x80003000ull,403);d.io_safeWatermark=3;d.eval();
  check(d.io_coalesced==1,"new safe successor coalesces predecessor");tick();
  check(d.io_occupancy==2,"coalesce retains active owner and one successor");
  d.io_flush=1;d.io_invalidate_valid=1;d.io_invalidate_bits=0;tick();
  d.io_flush=0;d.io_invalidate_valid=0;d.io_safeWatermark=0;d.io_currentEpoch=1;
  check(d.io_occupancy==2,"successor inherits safe publication across FAIL/flush");
  complete(1,401);wait_payload(3,0x80003000ull,403);complete(3,403);tick();
  check(d.io_occupancy==0 && d.io_capture_ready,"all inherited publication obligations ACKed");
  // Coincident flush/coalesce must not lose the safe source to a successor
  // that is being discarded. Unsafe same-line bytes are never published.
  reset_case();d.io_safeWatermark=1;capture(1,0x80002000ull,501);
  wait_payload(1,0x80002000ull,501);
  d.io_safeWatermark=2;capture(2,0x80003000ull,502);capture(3,0x80003000ull,503);
  d.io_safeWatermark=3;d.io_flush=1;d.eval();
  check(d.io_coalesced==0,"flush suppresses unsafe coalescing target");tick();
  d.io_flush=0;d.io_safeWatermark=0;d.io_currentEpoch=1;
  check(d.io_occupancy==3,"all snapshots already safe at flush retain publication responsibility");
  complete(1,501);wait_payload(3,0x80003000ull,503);complete(3,503);tick();
  check(d.io_occupancy==0,"safe source published once");
  std::puts("PASS safe_SPEC_flush=2048 same_epoch_reset=1 inherited_publication=1 simultaneous_flush_coalesce=1");
}
int main(int argc,char**argv) {
  Verilated::commandArgs(argc,argv); clear_inputs(); d.reset=1;
  for(int i=0;i<4;++i)tick(); d.reset=0; tick();
  // Persistent unsafe snapshots fill all 16 entries. No PASS is invented.
  for(unsigned seq=1;seq<=16;++seq)capture(seq,0x80000000ull+64*seq,100+seq);
  check(d.io_occupancy==16 && !d.io_capture_ready,"full buffer ownership");
  d.io_releaseLines_0=0x80000000ull+64;
  d.eval();
  for(int i=0;i<1024;++i) {
    check(!d.io_promote_valid && !d.io_selected && d.io_occupancy==16 && d.io_releaseBlocked_0,
      "unsafe versions persist while checking incomplete"); tick();
  }
  // FAIL/rollback boundary invalidates younger versions, retaining predecessors.
  d.io_invalidate_valid=1; d.io_invalidate_bits=4; tick(); d.io_invalidate_valid=0;
  check(d.io_occupancy==4 && d.io_capture_ready,"rollback keeps predecessors");
  d.io_safeWatermark=4;
  for(int i=0;i<8 && !d.io_promote_valid;++i)tick();
  check(d.io_promote_valid,"safe predecessor becomes publishable");
  expect_payload(4,0x80000100ull,104);
  unsigned entry=d.io_promote_bits_entry;
  // Once verified, all predecessors remain publication obligations even if
  // an invalidate boundary is lower. WB_WAIT and safe SPEC both survive.
  d.io_invalidate_valid=1; d.io_invalidate_bits=0; tick(); d.io_invalidate_valid=0;
  check(d.io_occupancy==4,"WB owner and verified SPEC survive invalidate");
  for(int i=0;i<1024;++i) {
    check(d.io_promote_valid && d.io_promote_bits_entry==entry,"held promotion under backpressure");
    expect_payload(4,0x80000100ull,104);tick();
  }
  d.io_promote_ready=1; tick(); d.io_promote_ready=0;
  check(!d.io_promote_valid && d.io_occupancy==4,"sent owner waits for ACK");
  d.io_flush=1; tick(); d.io_flush=0; d.io_currentEpoch=1;
  d.io_releaseLines_0=0x80000100ull;
  d.eval();
  for(int i=0;i<1024;++i) {
    check(d.io_occupancy==4 && d.io_releaseBlocked_0 && !d.io_promote_valid,
      "flush and epoch retain sent owner until matching ACK");
    expect_payload(4,0x80000100ull,104);tick();
  }
  d.io_ack_bits_entry=entry;d.io_ack_bits_key_valid=1;d.io_ack_bits_key_writer=7;
  d.io_ack_bits_key_generation=104;d.io_ack_bits_key_contentSeq=4;d.io_ack_valid=1;
  if(argc>1 && std::string(argv[1])=="wrong_key")d.io_ack_bits_key_generation=105;
  if(argc>1 && std::string(argv[1])=="wrong_entry")d.io_ack_bits_entry=(entry+1)&15;
  d.eval();
  if(argc>1) { tick(); std::fprintf(stderr,"FAIL: wrong ACK escaped assertion\n");return 2; }
  check(d.io_acked,"matching ACK accepted");tick();d.io_ack_valid=0;d.eval();
  check(d.io_occupancy==3 && !d.io_releaseBlocked_0,"only matching ACK reclaims WB owner");
  for(unsigned seq: {3u,2u,1u}) {
    wait_payload(seq,0x80000000ull+64*seq,100+seq);complete(seq,100+seq);
  }
  check(d.io_occupancy==0,"all verified publications completed");
  tick(); // boundary admission reopens after the retained owner has drained
  // Multiple versions of one line: rollback removes newer bytes, old payload
  // remains exact and is the one selected after its real safe boundary.
  capture(5,0x80000400ull,205);capture(6,0x80000400ull,206);
  d.io_invalidate_valid=1;d.io_invalidate_bits=5;tick();d.io_invalidate_valid=0;
  check(d.io_occupancy==1,"same-line rollback retains old version");
  for(int i=0;i<512;++i) { check(!d.io_promote_valid,"old predecessor waits for PASS");tick(); }
  d.io_safeWatermark=5;
  for(int i=0;i<8 && !d.io_promote_valid;++i)tick();
  check(d.io_promote_valid,"rollback predecessor selected");expect_payload(5,0x80000400ull,205);
  std::printf("PASS persistent_full=1024 promote_backpressure=1024 delayed_ack=1024 same_line_rollback=512 checks=%u\n",checks);
  safe_publication_cases();
  d.final();return 0;
}
