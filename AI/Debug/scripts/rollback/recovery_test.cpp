#include "VRecoveryHarness.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>

static VRecoveryHarness d;
static unsigned cycles;
static void require(bool condition, const char *why) {
  if (!condition) { std::fprintf(stderr, "FAIL cycle=%u: %s\n", cycles, why); std::exit(1); }
}
static void tick() {
  d.clock = 0; d.eval(); d.clock = 1; d.eval(); ++cycles; d.clock = 0; d.eval();
}
static void reset() {
  d.io_allocate=0; d.io_safe=6; d.io_captureCP=0; d.io_cpSeq=0;
  d.io_cpPC=0; d.io_cpInt=0; d.io_cpFP=0; d.io_cpCSR=0;
  d.io_fail=0; d.io_quiesced=0; d.io_restartReady=0; d.io_identityUnavailable=0;
  d.io_compact=0;
  d.io_archive=0; d.io_escape=0; d.io_address=0x80001000ULL; d.io_seq=0;
  d.io_serial=0; d.io_value=0; d.io_query=0; d.io_responseReady=0;
  d.io_publishReady=0; d.io_publishAck=0;
  d.reset=1; for(int i=0;i<5;++i) tick(); d.reset=0; tick();
}
static void cp(unsigned seq) {
  d.io_cpSeq=seq; d.io_cpPC=seq*0x100;
  d.io_cpInt=seq*10; d.io_cpFP=seq*10+1; d.io_cpCSR=seq*10+2;
  d.eval(); require(d.io_cpReady, "CP full before capture");
  d.io_allocate=seq; d.io_captureCP=1; tick(); d.io_captureCP=0; d.io_allocate=0; tick();
}
static void archive(unsigned seq, unsigned serial, unsigned value) {
  d.io_seq=seq; d.io_serial=serial; d.io_value=value; d.io_archive=1; d.eval();
  unsigned n=0; while(!d.io_archiveReady && n++<100) tick();
  require(d.io_archiveReady, "archive backpressure never relieved");
  tick(); d.io_archive=0; tick();
}
static void query(bool found, unsigned seq, unsigned value) {
  d.io_query=1; d.eval(); unsigned n=0;
  while(!d.io_queryReady && n++<100) tick();
  require(d.io_queryReady, "query not accepted"); tick(); d.io_query=0; d.eval();
  n=0; while(!d.io_response && n++<100) tick();
  require(d.io_response, "no held history response");
  require(bool(d.io_found)==found, "wrong history found bit");
  if(found) {
    require(d.io_selected==seq, "wrong LatestSurviving Seq");
    require(d.io_data==value, "wrong historical bytes");
  }
  for(int i=0;i<7;++i) {
    tick(); require(d.io_response, "response dropped under backpressure");
    if(found) require(d.io_data==value, "held response changed");
  }
  d.io_responseReady=1; tick(); d.io_responseReady=0; tick();
}
static void fail(unsigned seq) {
  d.io_fail=seq; d.eval(); require(d.io_failReady,"error not accepted"); tick(); d.io_fail=0;
}
static void restart(unsigned expected) {
  d.io_quiesced=1;
  for(unsigned n=0;n<100 && !d.io_restore;++n) tick();
  require(d.io_restore,"restore never reached");
  require(d.io_pc==expected*0x100,"restored ECP rather than SCP PC");
  require(d.io_integer==expected*10,"integer restore payload");
  require(d.io_floating==expected*10+1,"f0 restore payload");
  require(d.io_csr==expected*10+2,"CSR restore payload");
  for(int i=0;i<5;++i) { tick(); require(!d.io_restart,"restart ignored ready"); }
  d.io_restartReady=1; d.eval(); require(d.io_restart,"resume not held"); tick();
  d.io_restartReady=0; tick(); require(!d.io_stop,"controller did not resume");
}
static void watermarkChangesDuringPublishScan() {
  reset();
  d.io_safe=5;
  const auto a=d.io_address;
  archive(7,31,0xa7);
  d.io_address=a+64;
  archive(9,32,0xb9); // Separate A7 and A8 by one scan slot.
  d.io_address=a;
  archive(8,33,0xa8);
  for(unsigned n=0;n<40;++n) tick();
  require(!d.io_publish,"pending version became eligible for publication");

  d.io_safe=6;
  tick(); // Mark the published prefix as changed.
  tick(); // Begin scanning at SW=6.
  tick(); // Scan A7 while it is still Pending.
  d.io_safe=7; tick();
  d.io_safe=8; tick(); // Scan A8 after SW crosses both versions.
  for(unsigned seq : {7u,8u}) {
    for(unsigned n=0;n<100&&!d.io_publish;++n) tick();
    require(d.io_publish,"UNCOVERED: newly safe history was not published");
    require(d.io_publishSeq==seq,"SW changed during scan and reordered same-address publication");
    d.io_publishReady=1; tick(); d.io_publishReady=0;
    for(unsigned n=0;n<5;++n) {
      tick(); require(!d.io_publish,"next publication preceded the previous owner's ACK");
    }
    d.io_publishAck=1; tick(); d.io_publishAck=0;
  }
  query(false,0,0);
  std::puts("CASE watermark_change_preserves_same_address_publish_order PASS");
}
int main(int argc,char **argv) {
  Verilated::commandArgs(argc,argv);
  watermarkChangesDuringPublishScan();
  // A Probe may arrive after drain completed but before restart is accepted.
  // The earlier quiesce receipt is not a promise that no new owner can exist.
  reset(); cp(7); cp(8); fail(8); d.io_quiesced=1;
  for(unsigned n=0;n<100 && !d.io_restore;++n) tick();
  require(d.io_restore,"late-owner test never reached restore");
  for(int i=0;i<5;++i) tick();
  d.io_quiesced=0; d.io_restartReady=1;
  for(int i=0;i<9;++i) {
    d.eval(); require(!d.io_restart && d.io_stop,"restart bypassed a late coherence owner");
    require(d.io_cpOccupancy==2 && d.io_pc==0x800,"late owner lost the pinned SCP");
    tick();
  }
  d.io_quiesced=1; d.eval(); require(d.io_restart,"late owner release did not resume");
  tick(); d.io_restartReady=0; tick(); require(!d.io_stop,"late owner recovery did not complete");
  std::puts("CASE restart_rechecks_late_owner PASS");
  reset(); cp(7); cp(8);
  archive(7,7,0xa7); archive(8,8,0xa8); query(true,8,0xa8);
  fail(8);
  for(int i=0;i<12;++i) tick();
  require(d.io_stop && !d.io_restore,"drain barrier bypassed");
  require(d.io_epoch==1 && d.io_generation==1,"EVT not published before drain");
  fail(8); // Duplicate error cannot restart lookup or change Epoch.
  query(true,7,0xa7); require(d.io_epoch==1,"duplicate error changed Epoch");
  restart(8); require(d.io_cpOccupancy==1,"pending-prefix SCP7 reclaimed");
  cp(9); require(d.io_epoch==1,"new Seq changed Epoch");
  d.io_quiesced=0; fail(9); for(int i=0;i<10;++i) tick();
  fail(7); for(int i=0;i<10;++i) tick();
  require(d.io_target==7,"earlier error did not retarget"); query(false,0,0);
  restart(7); require(d.io_epoch==3,"continuous rollback history lost");
  // Capacity/ACK test is independent: SW7 forbids subsequently rolling back7.
  reset(); cp(7); cp(8); archive(7,17,0xb7); archive(8,18,0xb8);
  d.io_safe=7; d.io_publishReady=1;
  for(unsigned n=0;n<100 && !d.io_publish;++n) tick();
  require(d.io_publish && d.io_publishSeq==7,"wrong safe publication"); tick();
  d.io_publishReady=0; query(true,8,0xb8);
  fail(8); for(int i=0;i<12;++i) tick();
  query(true,7,0xb7); // Published owner remains searchable before exact ACK.
  d.io_publishAck=1; tick(); d.io_publishAck=0; tick();
  query(false,0,0); // Safe baseline now belongs to outer memory, not this fixture.
  restart(8);
  d.io_allocate=9; tick(); d.io_allocate=0; fail(9);
  for(int i=0;i<10;++i) tick(); require(d.io_fatal,"missing SCP did not fail closed");
  // More than 32 consecutive retries have adjacent dead suffixes. They must
  // reuse one interval, while Pending7 and its actual historical A7 survive.
  reset(); cp(7); archive(7,1,0xa7);
  for(unsigned seq=8;seq<104;++seq) {
    cp(seq); fail(seq); restart(seq);
    require(!d.io_fatal&&d.io_cpOccupancy==1,"adjacent retry leaked EVT/SCP capacity");
    require(d.io_epoch==seq-7,"adjacent retry lost its fresh execution Epoch");
  }
  query(true,7,0xa7);
  // Thirty-two disjoint tombstones fit. A new disjoint interval must fail
  // closed instead of wrapping Epoch or waiting for nonexistent free space.
  reset(); d.io_safe=0;
  for(unsigned i=0;i<32;++i) {
    const unsigned seq=2*i+1;
    if(i) { d.io_allocate=seq-1; tick(); d.io_allocate=0; }
    d.io_safe=seq-1; tick(); cp(seq); fail(seq); restart(seq);
    require(!d.io_fatal,"EVT exhausted before its declared capacity");
    require(d.io_cpOccupancy==0,"restart leaked pinned SCP");
  }
  // Only this COMPONENT test explicitly certifies empty references. The real
  // hierarchy test supplies actual Probe/writeback/DRAM acknowledgements.
  d.io_compact=1; tick(); d.io_compact=0;
  require(d.io_epoch==0&&d.io_generation==0,"EVT component compaction did not reset labels");
  d.io_allocate=64; tick(); d.io_allocate=0; d.io_safe=64; tick();
  cp(65); fail(65); restart(65);
  require(!d.io_fatal&&d.io_epoch==1,"EVT component did not accept fresh interval after compaction");
  // Missing the required maintenance certificate remains a fail-closed
  // interface violation at the isolated component boundary.
  reset();
  for(unsigned i=0;i<32;++i) {
    const unsigned seq=2*i+1;
    if(i) { d.io_allocate=seq-1; tick(); d.io_allocate=0; }
    d.io_safe=seq-1; tick(); cp(seq); fail(seq); restart(seq);
  }
  d.io_allocate=64; tick(); d.io_allocate=0; d.io_safe=64; tick();
  cp(65); fail(65);
  for(int i=0;i<20;++i) tick();
  require(d.io_fatal && d.io_stop && !d.io_restart,"EVT exhaustion did not fail closed");
  // Four RAM credits are reserved for preservation. Ordinary ingress must
  // stop at that threshold; a preserve owner may still transfer a full line.
  reset(); d.io_safe=0;
  for(unsigned i=1;i<=4;++i) {
    d.io_address=0x80001000ULL+64*i; archive(i,i,0xc0+i);
  }
  for(int i=0;i<110;++i) tick();
  d.io_archive=1; d.io_seq=5; d.io_serial=5; d.io_value=0xc5;
  d.io_address=0x80002000ULL; d.eval();
  require(d.io_pressure && !d.io_archiveReady,"ordinary ingress consumed escape credits");
  for(int i=0;i<10;++i) { tick(); require(!d.io_archiveReady,"ordinary ingress bypassed reserve"); }
  d.io_escape=1;
  for(unsigned n=0;n<110 && !d.io_archiveReady;++n) tick();
  require(d.io_archiveReady,"escape owner could not use reserved storage");
  tick(); d.io_archive=0; d.io_escape=0;
  query(true,5,0xc5);
  d.io_address=0x80001040ULL; query(true,1,0xc1);
  // Identity loss must win over a simultaneous ready restart. Keep the
  // pinned SCP rather than discarding it on an apparent successful resume.
  reset(); cp(7); cp(8); fail(8); d.io_quiesced=1;
  for(unsigned n=0;n<100 && !d.io_restore;++n) tick();
  require(d.io_restore,"identity test never reached restore");
  for(int i=0;i<5;++i) tick();
  d.io_identityUnavailable=1; d.io_restartReady=1; d.eval();
  require(d.io_stop && d.io_fatal && !d.io_restart,"finite identity boundary lost to restart");
  tick(); d.io_identityUnavailable=0;
  for(int i=0;i<10;++i) {
    tick(); require(d.io_stop && d.io_fatal && !d.io_restart,"fatal identity stop was not sticky");
    require(d.io_cpOccupancy==2,"fatal identity stop released the pinned SCP");
  }
  std::puts("PALIMPSEST_COMPONENTS=PASS (real-cache/full-core tests still required)");
  d.final(); return 0;
}
