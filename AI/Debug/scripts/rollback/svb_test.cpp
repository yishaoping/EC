#include "VSvbHarness.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>

static VSvbHarness d;
static unsigned cycles;
static void require(bool ok, const char *why) {
  if (!ok) { std::fprintf(stderr, "SVB_FAIL cycle=%u: %s\n", cycles, why); std::exit(1); }
}
static void tick() {
  d.clock=0; d.eval(); d.clock=1; d.eval(); ++cycles; d.clock=0; d.eval();
}
static void reset() {
  d.io_capture=0; d.io_address=0x80001000ULL; d.io_seq=0;
  d.io_serial=0; d.io_value=0; d.io_safe=6; d.io_firstDead=0;
  d.io_invalidate=0; d.io_query=0; d.io_responseReady=0;
  d.io_archiveReady=0; d.io_ack=0;
  d.reset=1; for(int i=0;i<5;++i) tick(); d.reset=0; tick();
}
static void capture(unsigned seq, unsigned serial, unsigned value) {
  d.io_seq=seq; d.io_serial=serial; d.io_value=value; d.io_capture=1; d.eval();
  require(d.io_ready,"capture unexpectedly blocked"); tick(); d.io_capture=0; tick();
}
static void query(bool found, unsigned seq=0, unsigned serial=0, unsigned value=0) {
  d.io_query=1; d.eval(); require(d.io_queryReady,"query not ready");
  tick(); d.io_query=0; d.eval();
  for(int i=0;i<7;++i) {
    require(d.io_response,"response not held");
    require(bool(d.io_found)==found,"wrong recovery found flag");
    if(found) {
      require(d.io_selected==seq && d.io_selectedSerial==serial,"wrong LatestSurviving key");
      require(d.io_data==value,"wrong full-line snapshot bytes");
    }
    tick();
  }
  d.io_responseReady=1; tick(); d.io_responseReady=0; tick();
}
static void discard(unsigned seq) {
  d.io_firstDead=seq; d.io_invalidate=1; tick(); d.io_invalidate=0; tick();
}
static void transfer(unsigned seq) {
  unsigned n=0; while(!d.io_archive && n++<100) tick();
  require(d.io_archive && d.io_archiveSeq==seq,"archive order/owner mismatch");
  d.io_archiveReady=1; tick(); d.io_archiveReady=0; tick();
}
static void ack() { d.io_ack=1; tick(); d.io_ack=0; tick(); }
int main(int argc,char **argv) {
  Verilated::commandArgs(argc,argv);
  reset(); capture(7,17,0xa7); capture(8,18,0xa8); query(true,8,18,0xa8);
  discard(8); require(d.io_occupancy==1,"FAIL8 reclaimed pending A7 or kept SPEC A8");
  query(true,7,17,0xa7); transfer(7);
  require(d.io_releaseBlocked,"source freed before archive receipt");
  query(true,7,17,0xa7); ack();
  require(d.io_occupancy==0 && !d.io_releaseBlocked,"exact ACK did not release owner");
  query(false);
  // A tombstoned WB_WAIT entry remains owned through its delayed original ACK.
  reset(); capture(8,28,0xb8); transfer(8); discard(8);
  require(d.io_occupancy==1,"discard reused an accepted archive slot");
  query(false); for(int i=0;i<20;++i) tick();
  require(d.io_occupancy==1,"WB_WAIT timeout released responsibility");
  ack(); require(d.io_occupancy==0,"late exact receipt lost");
  // Same-Seq coalescing replaces intermediate snapshots. The held oldest
  // archive and the latest snapshot must both stay until their own terminal.
  reset(); capture(7,37,0xc7); capture(7,38,0xc8);
  capture(7,39,0xc9); capture(7,40,0xca);
  require(d.io_occupancy==2,"coalescing lost the archive owner or retained intermediate snapshots");
  query(true,7,40,0xca);
  transfer(7); ack();
  query(true,7,40,0xca);
  // Distinct addresses cannot coalesce. Keep archive acceptance stalled and
  // fill the remaining entries, then check both denial and the oldest bytes.
  for (unsigned i = 1; i < 4; ++i) {
    d.io_address=0x80001000ULL + 64*i;
    capture(7,40+i,0xca+i);
  }
  require(d.io_occupancy==4 && !d.io_ready,"full SVB accepted a fifth owner");
  d.io_address=0x80001000ULL; query(true,7,40,0xca);
  d.io_address=0x80002000ULL; query(false);
  std::puts("PALIMPSEST_SVB_COMPONENT=PASS (cache hierarchy still requires validation)");
  d.final(); return 0;
}
