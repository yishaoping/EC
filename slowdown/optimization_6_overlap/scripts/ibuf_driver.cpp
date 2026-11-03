// Standalone RTL scoreboard for the actual emitted Rocket IBuf.
#include "VCheckerIBufWrapper.h"
#include "verilated.h"
#include <cstdint>
#include <cstdio>
#include <deque>
#include <random>
#include <stdexcept>
#include <vector>

#ifndef FETCH_HALVES
#define FETCH_HALVES 4
#endif
struct Half { uint64_t pc; uint16_t bits; bool owned; };
struct Frame { uint64_t pc, data; unsigned length, mask, ends; std::vector<Half> halves; };

static std::vector<Frame> frames(std::mt19937_64 &rng, unsigned session) {
  // Includes RVC/RVI CFIs, word/block-spanning RVI, and suppressed system ops.
  const uint32_t ops[] = {0x0001, 0x4085, 0x13, 0x00108093, 0xa001,
                         0x8082, 0x00000063, 0x0000006f, 0x9002,
                         0x00000073, 0x00100073};
  std::vector<Half> stream;
  uint64_t pc = 0x80000000 + session * 0x10000 + 2 * (session % FETCH_HALVES);
  for (unsigned i = 0; i < 5000; ++i) {
    const uint32_t raw = ops[rng() % (sizeof(ops)/sizeof(ops[0]))];
    const unsigned length = (raw & 3) == 3 ? 2 : 1;
    const bool branch = raw == 0xa001 || raw == 0x8082 || raw == 0x63 || raw == 0x6f;
    stream.push_back({pc, uint16_t(raw), branch && length == 1});
    if (length == 2) stream.push_back({pc+2, uint16_t(raw >> 16), branch});
    pc += 2 * length;
    if (branch && (rng() & 1)) pc = 0x80000000 + session * 0x10000 + 2 * (rng() % 8192);
  }
  std::vector<Frame> result;
  for (size_t i = 0; i < stream.size();) {
    Frame f{stream[i].pc, 0, 0, 0, 0, {}};
    const auto base = f.pc & ~uint64_t(2 * FETCH_HALVES - 1);
    const unsigned start = (f.pc - base) / 2;
    for (unsigned lane = 0; lane < FETCH_HALVES; ++lane) f.data |= uint64_t(1) << (16 * lane);
    while (i < stream.size() && start + f.length < FETCH_HALVES &&
           stream[i].pc == f.pc + 2 * f.length) {
      const auto h = stream[i++];
      const unsigned lane = start + f.length++;
      f.data = (f.data & ~(uint64_t(0xffff) << (16 * lane))) | (uint64_t(h.bits) << (16 * lane));
      f.mask |= 1u << lane;
      if (h.owned) f.ends |= 1u << lane;
      f.halves.push_back(h);
      if (h.owned) break; // one logged branch per frontend response
    }
    result.push_back(f);
  }
  return result;
}

int main(int argc, char **argv) {
  Verilated::commandArgs(argc, argv);
  try {
    VCheckerIBufWrapper d;
    d.clock = 0; d.reset = 1; d.io_kill = 0; d.io_checker_mode = 1;
    d.io_imem_valid = 0; d.io_inst_0_ready = 0;
    d.io_imem_bits_btb_cfiType = 0; d.io_imem_bits_btb_taken = 0;
    d.io_imem_bits_btb_mask = 0; d.io_imem_bits_btb_bridx = 0;
    d.io_imem_bits_btb_target = 0; d.io_imem_bits_btb_entry = 0;
    d.io_imem_bits_btb_bht_history = 0; d.io_imem_bits_btb_bht_value = 0;
    d.io_imem_bits_pc = 0; d.io_imem_bits_data = 0; d.io_imem_bits_mask = 0;
    d.io_imem_bits_xcpt_pf_inst = 0; d.io_imem_bits_xcpt_gf_inst = 0;
    d.io_imem_bits_xcpt_ae_inst = 0; d.io_imem_bits_replay = 0;
    d.io_imem_bits_prefixLength = 0; d.io_imem_bits_bjlEndMask = 0;
    auto edge = [&]() { d.clock = 1; d.eval(); d.clock = 0; d.eval(); };
    for (unsigned i = 0; i < 5; ++i) edge();
    d.reset = 0;
    std::mt19937_64 rng(20261103);
    auto input = frames(rng, 0);
    std::deque<Half> expected;
    size_t next = 0;
    bool holding = false;
    unsigned retired = 0, compressed = 0, branches = 0, stalls = 0, kills = 0;
    for (unsigned cycle = 0; cycle < 200000; ++cycle) {
      if (kills < 3 && cycle == 1100u * (kills + 1)) {
        d.io_kill = 1; d.io_imem_valid = 0; d.io_inst_0_ready = 0;
        d.eval(); edge(); d.io_kill = 0;
        expected.clear(); holding = false; next = 0;
        input = frames(rng, ++kills);
      }
      if (!holding && next < input.size() && rng() % 4) holding = true;
      d.io_imem_valid = holding;
      d.io_inst_0_ready = rng() % 5 != 0;
      if (holding) {
        const auto &f = input[next];
        d.io_imem_bits_pc = f.pc; d.io_imem_bits_data = f.data;
        d.io_imem_bits_mask = f.mask; d.io_imem_bits_prefixLength = f.length;
        d.io_imem_bits_bjlEndMask = f.ends;
      }
      d.eval();
      const bool accepted = holding && d.io_imem_ready;
      if (accepted) for (auto h : input[next].halves) expected.push_back(h);
      if (d.io_inst_0_valid && d.io_inst_0_ready) {
        if (expected.empty()) throw std::runtime_error("RTL emitted an unowned instruction");
        const auto h = expected.front();
        const bool rvc = (h.bits & 3) != 3;
        const unsigned length = rvc ? 1 : 2;
        if (expected.size() < length) throw std::runtime_error("RTL emitted an incomplete RVI");
        if (!rvc && expected[1].pc != h.pc + 2) throw std::runtime_error("noncontiguous RVI");
        uint32_t raw = h.bits | (rvc ? 0 : uint32_t(expected[1].bits) << 16);
        const bool owner = expected[length-1].owned;
        if (raw == 0x9002) raw = 0x0001;
        else if (raw == 0x73 || raw == 0x00100073) raw = 0x13;
        const uint32_t mask = rvc ? 0xffff : 0xffffffff;
        if (d.io_pc != h.pc || bool(d.io_inst_0_bits_rvc) != rvc ||
            (d.io_inst_0_bits_raw & mask) != raw || bool(d.io_inst_0_bits_bjlOwned) != owner) {
          std::fprintf(stderr, "cycle=%u pc=%llx/%llx raw=%08x/%08x rvc=%u/%u owner=%u/%u\n",
              cycle, (unsigned long long)d.io_pc, (unsigned long long)h.pc,
              unsigned(d.io_inst_0_bits_raw & mask), raw, unsigned(d.io_inst_0_bits_rvc),
              rvc, unsigned(d.io_inst_0_bits_bjlOwned), owner);
          throw std::runtime_error("IBuf independent stream scoreboard mismatch");
        }
        for (unsigned i = 0; i < length; ++i) expected.pop_front();
        ++retired; compressed += rvc; branches += owner;
      }
      stalls += holding && !accepted;
      edge();
      if (accepted) { holding = false; ++next; }
      if (next == input.size() && expected.empty()) {
        d.io_imem_valid = 0; d.io_inst_0_ready = 1;
        for (unsigned quiet = 0; quiet < 5; ++quiet) {
          d.eval();
          if (d.io_inst_0_valid) throw std::runtime_error("RTL duplicated the drained stream tail");
          edge();
        }
        std::printf("PASS fetch_halves=%d retired=%u compressed=%u branch_owned=%u input_stalls=%u kills=%u cycles=%u\n",
            FETCH_HALVES, retired, compressed, branches, stalls, kills, cycle+1);
        d.final();
        return 0;
      }
    }
    throw std::runtime_error("instruction stream failed to drain");
  } catch (const std::exception &e) {
    std::fprintf(stderr, "FAIL %s\n", e.what());
    return 1;
  }
}
