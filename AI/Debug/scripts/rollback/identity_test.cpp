#include "VIdentityHarness.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>

static VIdentityHarness d;
static void require(bool condition, const char *why) {
  if (!condition) { std::fprintf(stderr, "FAIL: %s\n", why); std::exit(1); }
}
static void tick() {
  d.clock=0; d.eval(); d.clock=1; d.eval(); d.clock=0; d.eval();
}
int main(int argc, char **argv) {
  Verilated::commandArgs(argc, argv);
  d.io_consume=0; d.reset=1; for(int i=0;i<4;++i) tick();
  d.reset=0; tick();
  // Transaction labels are scoped by retired owners. Each group below has
  // completed before the next allocation; cross multiple four-bit wraps.
  unsigned expected=1;
  const unsigned groups[]={3,1,2,3,3,2,1,3,3,2,3,1,2,3,3,3,1,2,3,3};
  for(unsigned count: groups) {
    if(expected>12) expected=1;
    require(d.io_available && d.io_next==expected,"allocator lost group base");
    require(!d.io_stop && !d.io_fatal,"premature finite-bound stop");
    d.io_consume=count; tick(); d.io_consume=0; expected+=count;
    if(expected>12) expected=1;
    require(d.io_next==expected,"wrong variable-width allocation");
    tick(); require(d.io_next==expected,"idle consumed an identity");
  }
  require(d.io_available && !d.io_stop && !d.io_fatal,"cyclic labels stopped execution");
  for(int i=0;i<100;++i) {
    tick(); require(d.io_next==expected && !d.io_stop && !d.io_fatal,
      "idle changed a label or stopped the core");
  }
  std::puts("PALIMPSEST_IDENTITY_COMPONENT=PASS"); d.final(); return 0;
}
