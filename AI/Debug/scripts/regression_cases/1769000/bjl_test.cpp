#include "VR_BJLR.h"
#include "verilated.h"
#include <cassert>
#include <cstdint>
#include <iostream>

static void tick(VR_BJLR &d) {
  d.clock = 0; d.eval();
  d.clock = 1; d.eval();
  d.clock = 0; d.eval();
}

static void packet(WData *p, uint64_t pc, uint64_t npc, bool taken = false) {
  p[0] = npc; p[1] = npc >> 32;
  p[2] = pc; p[3] = (pc >> 32) | (uint64_t(taken) << 8) | (1U << 9);
}

int main(int argc, char **argv) {
  Verilated::commandArgs(argc, argv);
  VR_BJLR d;
  d.reset = 1; tick(d); tick(d); d.reset = 0;
  packet(d.io_bj_npc_0, 0x80004898, 0x8000489a);
  packet(d.io_bj_npc_1, 0x8000489a, 0x800009f0, true);
  d.io_bj_valid_0 = 1; d.io_bj_valid_1 = 1; d.eval();
  assert(!d.io_bj_req_ready);
  tick(d); d.io_bj_valid_0 = 0; d.io_bj_valid_1 = 0; d.eval();
  assert(d.io_bj_req_ready && d.io_bj_resp_cpc == 0x80004898);
  d.io_bj_req_valid = 1; tick(d);
  assert(d.io_bj_resp_cpc == 0x8000489a);
  tick(d); d.io_bj_req_valid = 0; d.eval();
  assert(!d.io_bj_req_ready);
  packet(d.io_bj_npc_0, 0x800009f0, 0x800009f2);
  d.io_bj_valid_0 = 1; d.eval(); assert(!d.io_bj_req_ready);
  tick(d); d.io_bj_valid_0 = 0; d.eval();
  assert(d.io_bj_resp_cpc == 0x800009f0);
  d.io_bj_commit_valid = 1; d.io_bj_rollback = 1; tick(d);
  d.io_bj_commit_valid = 0; d.io_bj_rollback = 0; d.eval();
  assert(d.io_bj_resp_cpc == 0x8000489a);
  d.io_bj_req_valid = 1; tick(d); d.io_bj_req_valid = 0;
  d.io_bj_commit_valid = 1; d.io_bj_rollback = 1; tick(d);
  d.io_bj_commit_valid = 0; d.io_bj_rollback = 0; d.eval();
  assert(d.io_bj_resp_cpc == 0x800009f0);
  d.io_bj_req_valid = 1; tick(d); d.io_bj_req_valid = 0;
  d.io_bj_commit_valid = 1; tick(d); d.io_bj_commit_valid = 0; d.eval();
  assert(!d.io_bj_req_ready);
  std::cout << "PASS: resident reserve, delayed next head, commit+rollback post-commit cursor\n";
}
