#include "VIoBoundaryHarness.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>

static VIoBoundaryHarness d;
static void check(bool ok,const char* why) {
  if(!ok) { std::fprintf(stderr,"FAIL: %s state=%u\n",why,unsigned(d.io_state)); std::exit(1); }
}
static void tick() {
  d.clock=0; d.eval(); d.clock=1; d.eval(); d.clock=0; d.eval();
  check(!Verilated::gotFinish(),"hardware assertion/finish");
}
static void reset() {
  d.io_protectedExecution=1; d.io_request=0; d.io_head=27;
  d.io_activeSeq=8; d.io_safe=7; d.io_boundaryReady=1;
  d.io_issueReady=1; d.io_postReady=1; d.io_producerIdle=1; d.io_packageOpen=1;
  d.io_retired_0_valid=0; d.io_retired_0_bits=0;
  d.io_retired_1_valid=0; d.io_retired_1_bits=0;
  d.io_stop=0; d.io_flush=0; d.io_effectPending=0;
  d.reset=1; tick(); tick(); d.reset=0; tick();
}
static void start() {
  d.io_request=1; d.eval();
  check(d.io_retirementHold&&d.io_dispatchHold&&d.io_interruptHold&&!d.io_permit,"initial ROB head escaped");
  tick(); d.io_request=0; d.eval();
  check(d.io_forceClose&&d.io_closeSeq==8&&d.io_snapshotBoundary,"prefix did not close at held head");
}
static void issue() {
  d.io_activeSeq=9; tick(); d.io_safe=8; tick();
  check(d.io_permit&&d.io_singleStep&&!d.io_retirementHold&&d.io_interruptHold,"I/O issue owner incorrect");
}
static void retire() {
  d.io_retired_1_bits=27; d.io_retired_1_valid=1; tick();
  d.io_retired_1_valid=0;
  check(d.io_forceClose&&d.io_closeSeq==9&&!d.io_permit&&d.io_retirementHold,"effect segment was not closed");
}
int main(int argc,char**argv) {
  Verilated::commandArgs(argc,argv);
  reset(); start();
  for(int i=0;i<8;++i) { tick(); check(!d.io_permit&&d.io_forceClose,"close did not hold for new SCP"); }
  d.io_activeSeq=9; tick();
  for(int i=0;i<8;++i) { tick(); check(!d.io_permit&&d.io_retirementHold,"Pending prefix was crossed"); }
  d.io_safe=8; d.io_producerIdle=0; tick(); check(!d.io_permit,"RSU owner was ignored");
  d.io_producerIdle=1; d.io_issueReady=0; tick(); check(!d.io_permit,"older store owner was ignored");
  d.io_issueReady=1; d.io_packageOpen=0; tick(); check(!d.io_permit,"I/O issued without new package/SCP");
  d.io_packageOpen=1; tick(); check(d.io_permit&&d.io_singleStep&&d.io_interruptHold,"verified I/O not enabled");
  d.io_retired_0_bits=28; d.io_retired_0_valid=1; tick(); d.io_retired_0_valid=0;
  check(d.io_permit&&!d.io_forceClose,"unrelated ROB retirement ended I/O owner");
  d.io_effectPending=1; retire();
  d.io_postReady=0; d.eval(); check(!d.io_snapshotBoundary,"post-ECP crossed incomplete device/store owner");
  d.io_postReady=1; d.io_activeSeq=10; tick();
  for(int i=0;i<8;++i) { tick(); check(d.io_retirementHold&&!d.io_permit,"effect Pending allowed younger retirement"); }
  d.io_safe=9; tick(); check(d.io_idle&&d.io_interruptHold,"journal lifetime lost at boundary completion");
  d.io_effectPending=0; tick(); check(!d.io_interruptHold&&!d.io_dispatchHold,"interrupt did not resume");

  // Flush/cancel in each live state must release the boundary FSM. A retained
  // external effect continues to mask interrupts across the restart window.
  for(unsigned phase=0;phase<5;++phase) {
    reset(); start();
    if(phase>=1) { d.io_activeSeq=9; tick(); }
    if(phase>=2) { d.io_safe=8; tick(); }
    if(phase>=3) retire();
    if(phase>=4) { d.io_activeSeq=10; tick(); }
    d.io_effectPending=1; d.io_flush=1; tick(); d.io_flush=0;
    check(d.io_idle&&!d.io_forceClose&&!d.io_dispatchHold&&d.io_interruptHold,"trap/flush left stale close owner");
    d.io_stop=1; tick(); check(!d.io_permit,"rollback permitted external operation");
    d.io_stop=0; tick(); check(d.io_interruptHold,"restart lost journal interrupt mask");
    d.io_effectPending=0; tick(); check(!d.io_interruptHold,"released journal still masks interrupt");
  }
  reset(); d.io_protectedExecution=0; tick();
  check(d.io_permit&&!d.io_retirementHold,"unprotected platform I/O blocked");
  std::puts("PALIMPSEST_IO_BOUNDARY=PASS"); d.final();
}
