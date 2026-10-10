#include "VIBuf.h"
#include "verilated.h"
#include <cassert>
#include <cstdint>
#include <iostream>

static void tick(VIBuf &d) {
  d.clock = 0; d.eval(); d.clock = 1; d.eval(); d.clock = 0; d.eval();
}

static void response(VIBuf &d, uint64_t pc, uint32_t data, int prefix, int owned) {
  d.io_imem_valid = 1; d.io_imem_bits_pc = pc; d.io_imem_bits_data = data;
  d.io_imem_bits_prefixLength = prefix; d.io_imem_bits_bjlEndMask = owned;
  d.io_imem_bits_btb_taken = 0; d.io_imem_bits_mask = pc & 2 ? 2 : 3;
  d.eval();
}

static void insn(VIBuf &d, uint64_t pc, bool rvc, bool owned) {
  d.eval();
  assert(d.io_inst_0_valid && d.io_pc == pc);
  assert(bool(d.io_inst_0_bits_rvc) == rvc);
  assert(bool(d.io_inst_0_bits_bjlOwned) == owned);
}

static void reset(VIBuf &d) {
  d.io_imem_valid = 0; d.io_imem_bits_replay = 0;
  d.io_inst_0_ready = 1; d.reset = 1; tick(d); d.reset = 0;
}

int main(int argc, char **argv) {
  Verilated::commandArgs(argc, argv); VIBuf d;
  reset(d);
  response(d, 0x80004898, 0x8082fa6d, 1, 1);
  insn(d, 0x80004898, true, true); assert(d.io_imem_ready); tick(d);
  d.io_imem_valid = 0; d.eval(); assert(!d.io_inst_0_valid);
  response(d, 0x8000489a, 0x8082fa6d, 1, 2);
  insn(d, 0x8000489a, true, true); tick(d);
  d.io_imem_valid = 0; d.eval(); assert(!d.io_inst_0_valid);
  reset(d);
  response(d, 0x80001000, 0x80820001, 2, 2);
  insn(d, 0x80001000, true, false); tick(d);
  d.io_imem_valid = 0; insn(d, 0x80001002, true, true); tick(d);
  d.eval(); assert(!d.io_inst_0_valid);
  reset(d);
  response(d, 0x80002002, 0x80670001, 1, 0);
  assert(!d.io_inst_0_valid && d.io_imem_ready); tick(d);
  response(d, 0x80002004, 0x00010000, 1, 1);
  insn(d, 0x80002002, false, true);
  assert(d.io_inst_0_bits_inst_bits == 0x00008067); tick(d);
  d.io_imem_valid = 0; d.eval(); assert(!d.io_inst_0_valid);
  reset(d);
  response(d, 0x80003000, 0x00008067, 2, 2);
  d.io_inst_0_ready = 0; insn(d, 0x80003000, false, true);
  for (int i = 0; i < 5; ++i) { tick(d); insn(d, 0x80003000, false, true); }
  d.io_inst_0_ready = 1; tick(d); d.io_imem_valid = 0;
  d.eval(); assert(!d.io_inst_0_valid);
  reset(d);
  response(d, 0x80004002, 0x80670001, 1, 0); tick(d);
  d.io_imem_valid = 0; d.io_kill = 1; tick(d); d.io_kill = 0;
  response(d, 0x80005000, 0x00010001, 1, 0);
  insn(d, 0x80005000, true, false);
  std::cout << "PASS: disjoint RVC prefixes, buffered ownership, cross-block CFI, backpressure, redirect kill\n";
}
