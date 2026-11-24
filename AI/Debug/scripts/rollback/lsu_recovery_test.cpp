#include "VLsuRecoveryHarness.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>

static VLsuRecoveryHarness d;
static unsigned cycle;
static void check(bool ok, const char *why) {
  if (!ok) { std::fprintf(stderr, "FAIL cycle=%u: %s\n", cycle, why); std::exit(1); }
}
static void tick() {
  d.clock=0; d.eval(); d.clock=1; d.eval(); ++cycle;
  check(!Verilated::gotFinish(), "unexpected RTL finish");
}
static void reset() {
  d.io_dispatch=d.io_execute=d.io_stop=d.io_resetBackend=0;
  d.reset=1; for(unsigned i=0;i<4;++i)tick(); d.reset=0; tick();
}
int main(int argc, char **argv) {
  Verilated::commandArgs(argc, argv);
  for (unsigned kind=0;kind<5;++kind) {
    d.io_kind=kind; reset();
    if(kind<4) {d.io_dispatch=1;tick();d.io_dispatch=0;}
    // An older execution unit's Valid result can coincide with a held Error.
    // The stopped suffix must create neither cache nor translation work.
    d.io_stop=1;d.io_execute=1;tick();d.io_execute=0;
    for(unsigned i=0;i<8;++i) {
      tick();check(!d.io_request && !d.io_walk && !d.io_busyClear,
                   "stopped execution request created work or completion");
    }
    check(d.io_drained,"discarded execution request obstructed drain");
    d.io_resetBackend=1;tick();d.io_resetBackend=0;tick();
    d.io_stop=0;tick();
    std::printf("CASE stopped_execution_kind=%u PASS\n",kind);
  }
  d.io_kind=0;reset();d.io_dispatch=1;tick();d.io_dispatch=0;
  d.io_execute=1;d.clock=0;d.eval();
  check(d.io_request,"normal load no longer reaches cache");
  tick();d.io_execute=0;
  std::puts("PALIMPSEST_LSU_RECOVERY=PASS");d.final();
}
