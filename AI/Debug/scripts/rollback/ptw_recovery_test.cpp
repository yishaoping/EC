#include "VPtwRecoveryHarness.h"
#include "verilated.h"
#include <cstdint>
#include <cstdio>
#include <cstdlib>

static VPtwRecoveryHarness d;
static unsigned cycle;
static constexpr unsigned root = 0x80020, oldMid = 0x80021, oldLeaf = 0x80022;
static constexpr unsigned newMid = 0x80023, newLeaf = 0x80024;
static constexpr unsigned virtualPage = 0x40000;

static void check(bool pass, const char *message) {
  if (pass) return;
  std::fprintf(stderr, "FAIL cycle=%u %s valid=%u kill=%u done=%u addr=%llx ppn=%llx\n", cycle,
               message, d.io_memValid, d.io_memKill, d.io_done,
               (unsigned long long)d.io_memAddr, (unsigned long long)d.io_ppn);
  std::exit(1);
}

static void step() {
  d.clock = 0; d.eval();
  d.clock = 1; d.eval();
  ++cycle;
  check(!Verilated::gotFinish(), "unexpected RTL finish");
}

static void start(unsigned page) {
  d.io_vpn = page;
  d.io_walk = 1;
  d.eval();
  check(d.io_ready, "PTW did not accept the next walk");
  step();
  d.io_walk = 0;
  d.eval();
}

static void request(uint64_t addr) {
  for (unsigned wait = 0; wait < 16 && !d.io_done; ++wait) {
    if (!d.io_memValid) {
      step();
      continue;
    }
    const uint64_t candidate = d.io_memAddr;
    d.io_memReady = 1;
    step();
    d.io_memReady = 0;
    d.eval();
    // PTW can issue a physical request before resolving a cache hit.
    // The DCache discards it if the following s1_kill is asserted.
    if (d.io_memKill) continue;
    check(candidate == addr, "walk used a stale page table");
    step();
    step();
    return;
  }
  check(false, "walk completed without reading the expected page table");
}

static void reply(unsigned ppn, bool leaf) {
  d.io_memData = (uint64_t(ppn) << 10) | (leaf ? 0xcf : 1);
  d.io_memResponse = 1;
  step();
  d.io_memResponse = 0;
  step();
}

static void done(unsigned ppn) {
  for (unsigned i = 0; i < 16 && !d.io_done; ++i) step();
  check(d.io_done && !d.io_exception && d.io_ppn == ppn, "wrong or missing translation");
}

static void flush() {
  d.io_fence = 1;
  step();
  d.io_fence = 0;
  d.eval();
}

static void walkVia(unsigned mid, unsigned leaf, unsigned ppn, unsigned offset = 0) {
  request((root << 12) + 8);
  reply(mid, false);
  request(mid << 12);
  reply(leaf, false);
  request((leaf << 12) + 8 * offset);
  reply(ppn, true);
  done(ppn);
}

int main(int argc, char **argv) {
  Verilated::commandArgs(argc, argv);
  d.io_walk = d.io_fence = d.io_memReady = d.io_memResponse = 0;
  d.io_root = root;
  d.reset = 1; step(); d.reset = 0; step();

  // Fence before the first old response. Both internal cache fill paths run
  // later in this walk, but the next traversal must read the changed root.
  start(virtualPage);
  request((root << 12) + 8);
  flush();
  reply(oldMid, false);
  request(oldMid << 12);
  reply(oldLeaf, false);
  request(oldLeaf << 12);
  reply(0x80000, true);
  done(0x80000);
  step(); step();
  start(virtualPage);
  walkVia(newMid, newLeaf, 0x80200);
  step(); step();

  // Ensure that the leaf cache is enabled and usable with the BOOM params.
  start(virtualPage);
  done(0x80200);
  step(); step();

  // A neighbouring page reuses the non-leaf cache. Fence on the cycle that
  // the leaf response returns to the TLB and attempts to fill the L2 TLB.
  start(virtualPage + 1);
  request((newLeaf << 12) + 8);
  reply(0x80300, true);
  done(0x80300);
  flush();
  step();
  start(virtualPage + 1);
  walkVia(oldMid, oldLeaf, 0x80400, 1);
  std::puts("PALIMPSEST_PTW_RECOVERY=PASS");
  d.final();
}
