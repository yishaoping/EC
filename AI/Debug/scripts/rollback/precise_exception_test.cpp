#include "VPreciseExceptionHarness.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>

static VPreciseExceptionHarness dut;
static unsigned retired, traps, cycle;

static void check(bool condition, const char *message) {
  if (condition) return;
  std::fprintf(stderr, "FAIL cycle=%u: %s (retired=%u traps=%u)\n",
               cycle, message, retired, traps);
  std::exit(1);
}

static void step() {
  dut.clock = 0;
  dut.eval();
  if (!dut.reset && !dut.io_resetBackend) {
    check((dut.io_retired & ~1u) == 0, "a bubble or faulting lane retired");
    retired += dut.io_retired;
    if (dut.io_trap) {
      check(dut.io_cause == 2 && dut.io_pcOffset == 8, "wrong faulting instruction");
      ++traps;
    }
  }
  dut.clock = 1;
  dut.eval();
  ++cycle;
  check(!Verilated::gotFinish(), "RTL assertion or unexpected finish");
}

static void dispatchAndCompleteOlder() {
  check(dut.io_ready && dut.io_empty, "ROB did not admit the directed row");
  dut.io_dispatch = 1;
  step();
  dut.io_dispatch = 0;
  check(!dut.io_trap && !dut.io_retired, "fault bypassed an older busy instruction");
  dut.io_completeOlder = 1;
  step();
  dut.io_completeOlder = 0;
  dut.eval();
  check(dut.io_retired == 1 && !dut.io_trap, "fault bypassed older retirement across a bubble");
  step();
}

static void restoreTrap(unsigned seq) {
  dut.io_stop = 1;
  dut.io_restoreTrapSeq = seq;
  step();
  dut.io_restoreTrapSeq = 0;
  for (unsigned i = 0; !dut.io_trapRestoreReady && i < 8; ++i) step();
  check(dut.io_trapRestoreReady, "no SCP for trap context");
  step();
  dut.io_stop = 0;
  dut.eval();
}

int main(int argc, char **argv) {
  Verilated::commandArgs(argc, argv);
  dut.io_dispatch = dut.io_completeOlder = dut.io_stop = dut.io_resetBackend = 0;
  dut.io_trackerTrap = dut.io_trackerReturn = dut.io_trackerRetire = 0;
  dut.io_saveTrapSeq = dut.io_restoreTrapSeq = 0;
  dut.reset = 1;
  step();
  dut.reset = 0;
  step();
  dispatchAndCompleteOlder();
  check(dut.io_trap && retired == 1 && traps == 0, "fault did not reach unblocked ROB head");

  // A FAIL arrives before the same edge that could deliver the exception.
  dut.io_stop = 1;
  for (unsigned i = 0; i < 8; ++i) step();
  check(retired == 1 && traps == 0 && !dut.io_empty, "stop retired or delivered the suffix");
  dut.io_resetBackend = 1;
  step();
  dut.io_resetBackend = 0;
  step();
  check(dut.io_empty && traps == 0, "restore left an old ROB exception");
  dut.io_stop = 0;
  step();
  dispatchAndCompleteOlder();
  step();
  for (unsigned i = 0; i < 8; ++i) step();
  check(retired == 2 && traps == 1, "re-execution did not deliver exactly one precise trap");

  dut.io_saveTrapSeq = 1;
  step();
  dut.io_saveTrapSeq = 0;
  dut.io_trackerTrap = 1;
  step();
  dut.io_trackerTrap = 0;
  check(dut.io_handler, "trap did not enter handler mode");
  dut.io_saveTrapSeq = 2;
  step();
  dut.io_saveTrapSeq = 0;
  restoreTrap(1);
  dut.io_trackerRetire = 1;
  dut.eval();
  check(!dut.io_handler && !dut.io_syscall, "discarded trap marked the resumed package");
  dut.io_trackerRetire = 0;
  dut.io_trackerTrap = 1;
  step();
  dut.io_trackerTrap = 0;
  dut.io_trackerReturn = 1;
  dut.io_trackerRetire = 1;
  step();
  dut.io_trackerReturn = 0;
  step();
  check(!dut.io_handler && !dut.io_syscall, "return failed to clear trap bookkeeping");
  restoreTrap(2);
  check(dut.io_handler && dut.io_syscall, "rollback past return lost the pinned handler context");
  step();
  check(dut.io_handler && dut.io_syscall, "restored exception age was lost");
  step();
  check(dut.io_handler && !dut.io_syscall, "restored exception was replayed a third time");
  std::puts("CASE checker_trap_context_restored PASS");
  std::puts("PALIMPSEST_PRECISE_EXCEPTION=PASS");
  dut.final();
}
