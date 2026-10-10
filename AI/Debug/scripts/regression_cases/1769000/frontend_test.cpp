#include "VFrontend.h"
#include "verilated.h"
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

struct Resp { uint64_t pc; unsigned prefix, mask, owned; };
struct Bench {
  VFrontend d;
  uint64_t line = 0;
  int beat = -1;
  std::vector<Resp> out;
  uint16_t half(uint64_t pc) {
    if (pc == 0x80004898) return 0xfa6d;
    if (pc == 0x8000489a) return 0x8082;
    if (pc == 0x80006002) return 0x8067;
    if (pc == 0x80006004) return 0x0000;
    if (pc == 0x80007000) return 0x1067;
    if (pc == 0x80007002) return 0x0000;
    if (pc == 0x80008202) return 0x8082;
    return 0x0001;
  }
  void step() {
    d.clock = 0;
    d.auto_icache_master_out_a_ready = 1;
    d.auto_icache_master_out_d_valid = beat >= 0;
    d.auto_icache_master_out_d_bits_opcode = 1;
    d.auto_icache_master_out_d_bits_size = 6;
    uint64_t data = 0;
    if (beat >= 0) for (int i = 0; i < 4; ++i)
      data |= uint64_t(half(line + beat * 8 + i * 2)) << (i * 16);
    d.auto_icache_master_out_d_bits_data = data;
    d.eval();
    bool a = d.auto_icache_master_out_a_valid;
    uint64_t addr = d.auto_icache_master_out_a_bits_address;
    if (!d.reset && !d.io_cpu_req_valid && d.io_cpu_resp_valid && d.io_cpu_resp_ready)
      out.push_back({d.io_cpu_resp_bits_pc, d.io_cpu_resp_bits_prefixLength,
        d.io_cpu_resp_bits_mask, d.io_cpu_resp_bits_bjlEndMask});
    d.clock = 1; d.eval(); d.clock = 0; d.eval();
    if (beat >= 0 && ++beat == 8) beat = -1;
    if (a) { assert(beat < 0); line = addr & ~uint64_t(63); beat = 0; }
  }
  void cycles(int n) { for (int i = 0; i < n; ++i) step(); }
  void redirect(uint64_t pc) {
    d.io_cpu_req_valid = 1; d.io_cpu_req_bits_pc = pc; step(); d.io_cpu_req_valid = 0;
  }
  void record(uint64_t pc, uint64_t npc, bool rvc, bool taken) {
    d.io_packet_bj_0[0] = npc; d.io_packet_bj_0[1] = npc >> 32;
    d.io_packet_bj_0[2] = pc;
    d.io_packet_bj_0[3] = (pc >> 32) | (uint64_t(taken) << 8) | (uint64_t(rvc) << 9);
    step(); for (int i = 0; i < 4; ++i) d.io_packet_bj_0[i] = 0;
  }
};

int main(int argc, char **argv) {
  Verilated::commandArgs(argc, argv); Bench b;
  b.d.io_ptw_status_prv = 3; b.d.io_cpu_resp_ready = 1;
  b.d.reset = 1; b.cycles(5); b.d.reset = 0;
  b.d.io_cpu_checker_mode = 1; b.d.io_cpu_checker_seq = 1;
  b.redirect(0x80004898); b.record(0x80004898, 0x8000489a, true, false);
  for (int i = 0; i < 1000 && b.out.empty(); ++i) b.step();
  assert(b.out.size() == 1 && b.out[0].pc == 0x80004898 &&
    b.out[0].prefix == 1 && b.out[0].mask == 1 && b.out[0].owned == 1);
  b.cycles(30); assert(b.out.size() == 1);
  b.record(0x8000489a, 0x800009f0, true, true);
  for (int i = 0; i < 1000 && b.out.size() < 2; ++i) b.step();
  assert(b.out.size() >= 2);
  assert(b.out[1].pc == 0x8000489a && b.out[1].prefix == 1 &&
    b.out[1].mask == 2 && b.out[1].owned == 2);
  b.d.io_cpu_bjl_commit = 1; b.step(); b.step(); b.d.io_cpu_bjl_commit = 0;
  b.redirect(0x80006002); b.out.clear();
  b.record(0x80006002, 0x80001000, false, true);
  for (int i = 0; i < 1000 && b.out.size() < 2; ++i) b.step();
  assert(b.out.size() >= 2);
  assert(b.out[0].pc == 0x80006002 && b.out[0].prefix == 1 && b.out[0].owned == 0);
  assert(b.out[1].pc == 0x80006004 && b.out[1].prefix == 1 && b.out[1].owned == 1);
  b.d.io_cpu_bjl_commit = 1; b.step(); b.d.io_cpu_bjl_commit = 0;
  b.redirect(0x80004898); b.out.clear();
  b.record(0x80004898, 0x80009000, true, true);
  for (int i = 0; i < 1000 && b.out.size() < 2; ++i) b.step();
  assert(b.out.size() >= 2 && b.out[0].pc == 0x80004898 && b.out[0].prefix == 1);
  assert(b.out[1].pc == 0x80009000);
  b.d.io_cpu_bjl_commit = 1; b.step(); b.d.io_cpu_bjl_commit = 0;
  b.redirect(0x80008200); b.out.clear();
  for (int i = 0; i < 1000 && b.out.empty(); ++i) b.step();
  assert(b.out.size() == 1 && b.out[0].pc == 0x80008200 &&
    b.out[0].prefix == 1 && b.out[0].owned == 0);
  b.cycles(30); assert(b.out.size() == 1);
  b.record(0x80008202, 0x80009200, true, true);
  for (int i = 0; i < 1000 && b.out.size() < 2; ++i) b.step();
  assert(b.out.size() >= 2 && b.out[1].pc == 0x80008202 && b.out[1].owned == 2);
  b.d.io_cpu_bjl_commit = 1; b.step(); b.d.io_cpu_bjl_commit = 0;
  b.redirect(0x80007000); b.out.clear();
  for (int i = 0; i < 1000 && b.out.empty(); ++i) b.step();
  assert(b.out[0].pc == 0x80007000 && b.out[0].prefix == 2 && b.out[0].owned == 0);
  b.d.io_cpu_resp_ready = 0; b.cycles(100);
  b.d.io_cpu_checker_clear = 1; b.cycles(5);
  assert(!b.d.io_cpu_checker_clear_done);
  b.d.io_cpu_if_check_completed = 1;
  b.redirect(0x80008000); b.cycles(5);
  assert(b.d.io_cpu_checker_clear_done);
  std::cout << "PASS: real ICache miss/refill, late second RVC head, split CFI, special JALR, FQ backpressure, clear after redirect\n";
}
