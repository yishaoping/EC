#include "VTranslationRecoveryHarness.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>

static VTranslationRecoveryHarness d;
static unsigned cycle;

static void check(bool pass, const char *reason) {
  if (pass) return;
  std::fprintf(stderr, "FAIL cycle=%u %cTLB %s miss=%u walk=%u idle=%u addr=%llx\n", cycle, d.io_instruction ? 'I' : 'D',
               reason, d.io_miss, d.io_walk, d.io_idle, (unsigned long long)d.io_resultAddr);
  std::exit(1);
}

static void step() {
  d.clock = 0; d.eval();
  d.clock = 1; d.eval();
  ++cycle;
  check(!Verilated::gotFinish(), "unexpected RTL finish");
}

static void requestWalk() {
  d.io_lookup = 1; d.eval();
  check(d.io_idle && d.io_miss, "expected a miss in an idle TLB");
  step();
  d.io_lookup = 0; d.eval();
  check(d.io_walk, "miss did not request a walk");
}

static void reply(unsigned ppn) {
  d.io_ppn = ppn;
  d.io_reply = 1;
  step();
  d.io_reply = 0;
  d.eval();
}

static void exercise(unsigned level, bool homogeneous, bool fenceOnWalkFire, bool fenceOnResponse) {
  d.reset = 1; step(); d.reset = 0; step();
  d.io_level = level;
  d.io_homogeneous = homogeneous;
  requestWalk();
  d.io_walkReady = 1;
  d.io_fence = fenceOnWalkFire;
  step();
  d.io_walkReady = 0;
  d.io_fence = 0;
  if (!fenceOnWalkFire && !fenceOnResponse) {
    d.io_fence = 1; step(); d.io_fence = 0;
  }
  step();
  check(!d.io_idle, "old walk owner was released without a response");
  d.io_fence = fenceOnResponse;
  reply(0x80000);
  d.io_fence = 0;
  d.eval();
  check(d.io_idle && d.io_miss, "stale walk installed a TLB entry after restore fence");
  requestWalk();
  d.io_walkReady = 1; step(); d.io_walkReady = 0;
  reply(0x80200);
  check(!d.io_miss && d.io_resultAddr == 0x80200000ULL, "fresh walk did not install restored mapping");
}

int main(int argc, char **argv) {
  Verilated::commandArgs(argc, argv);
  d.io_lookup = d.io_fence = d.io_walkReady = d.io_reply = 0;
  d.io_vaddr = 0x40000000;
  d.io_ppn = 0;
  for (unsigned instruction = 0; instruction <= 1; ++instruction) {
    d.io_instruction = instruction;
    exercise(2, true, false, false);
    exercise(1, true, true, false);
    exercise(2, false, false, false);
    exercise(2, false, false, true);
  }
  std::puts("PALIMPSEST_TRANSLATION_RECOVERY=PASS");
  d.final();
}
