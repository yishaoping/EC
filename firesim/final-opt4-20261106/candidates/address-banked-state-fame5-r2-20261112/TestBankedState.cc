#include "TestHarness.h"
#include "bridges/clock.h"
#include <array>
#include <iostream>
#include <string>

class TestBankedState final : public TestHarness {
  unsigned banks = 0;
  bool negative = false;
public:
  TestBankedState(widget_registry_t &r, const std::vector<std::string> &a,
                  std::string_view n) : TestHarness(r, a, n) {
    for (const auto &x : a) {
      if (x.rfind("+banks=", 0) == 0) banks = std::stoul(x.substr(7));
      if (x == "+negative") negative = true;
    }
  }
  void run_test() override {
    log = false;
    if (!expect(banks == 2 || banks == 4 || banks == 16, "bank geometry")) return;
    const unsigned slots = banks * 16, tokens = 48;
    using Counts = std::array<uint64_t, 4>;
    std::array<std::array<Counts, 5>, 256> state{};
    std::array<uint32_t, 256> seq{};
    std::array<bool, 256> valid{};
    uint64_t rng = 0x8491167d12345678ull, checked = 0, digest = 1469598103934665603ull;
    auto next = [&]() { rng ^= rng << 13; rng ^= rng >> 7; rng ^= rng << 17; return rng; };
    const std::array<std::string,4> names = {"bytes", "words4", "words8", "lines"};
    const Counts bounds = {8, 3, 2, 1};
    auto counts = [&](unsigned cycle) {
      Counts out{};
      for (unsigned g = 0; g < 4; ++g) out[g] = cycle < 4 ? bounds[g] : next() % (bounds[g] + 1);
      return out;
    };
    auto poke_counts = [&](const std::string &p, const Counts &v) {
      for (unsigned g = 0; g < 4; ++g) poke(p + names[g], unsigned(v[g]));
    };
    // Never depend on uninitialized target payload. Stats reset explicitly
    // initializes payload; a later global reset intentionally invalidates
    // only RegInit valid bits, preserving sequence and invalid payload.
    poke("io_processCommit", 0); poke("io_safeAdvance", 0); poke("io_resetStats", 1);
    target_reset();
    poke("io_resetStats", 0);
    mpz_t expected, got, field;
    mpz_inits(expected, got, field, nullptr);
    auto &clk = get_bridge<clockmodule_t>();
    auto h0 = clk.hcycle();
    for (unsigned cycle = 0; cycle < tokens; ++cycle) {
      std::array<std::array<Counts, 3>, 256> delta{};
      for (unsigned family = 0; family < 3; ++family) {
        const std::string name = family == 0 ? "loadSources" : family == 1 ? "storeSources" : "strictSources";
        for (unsigned j = 0; j < (family == 2 ? 80 : 8); ++j) {
          unsigned key = cycle == 0 ? 0 : cycle == 1 ? 255 : cycle == 2 ? 16 :
            cycle == 3 ? j % slots : next() % 256;
          auto v = counts(cycle);
          auto p = "io_" + name + "_" + std::to_string(j) + "_";
          poke(p + "key", key); poke_counts(p + "counts_", v);
          for (unsigned g = 0; g < 4; ++g) delta[key][family][g] += v[g];
        }
      }
      auto ns = counts(cycle), nf = counts(cycle);
      poke_counts("io_newStore_", ns); poke_counts("io_newFirstStore_", nf);
      // Allocation, high sequence alias, retirement, simultaneous controls,
      // blocked retirement and reset priority across bank/lane boundaries.
      uint32_t ps = ((cycle / slots + 1) << 8) | (cycle < 8 ? cycle * 15 % slots : next() % 256);
      uint32_t rs = cycle < 8 ? 256u | ((cycle + 255) % slots) : next();
      bool pc = cycle % 7 != 4, sa = cycle % 3 == 2, se = cycle % 11 == 2;
      bool sr = cycle == 0 || cycle == 20 || cycle == 37;
      bool gr = cycle == 12 || cycle == 30;
      if (gr) pc = sa = sr = false;
      poke("io_processSeq", ps); poke("io_retiringSeq", rs);
      poke("io_processCommit", pc); poke("io_safeAdvance", sa);
      poke("io_safeError", se); poke("io_resetStats", sr); poke("reset", gr);
      for (unsigned i = 0; i < slots; ++i) {
        bool old_valid = valid[i], current = (ps & 255) == i, retiring = (rs & 255) == i;
        if (pc) {
          for (unsigned g = 0; g < 4; ++g) {
            if (current) {
              state[i][0][g] = (old_valid ? state[i][0][g] : 0) + ns[g];
              state[i][1][g] = (old_valid ? state[i][1][g] : 0) + nf[g];
            }
            for (unsigned k = 0; k < 3; ++k) {
              if (current || delta[i][k][g] != 0)
                state[i][k+2][g] = (current && !old_valid ? 0 : state[i][k+2][g]) + delta[i][k][g];
            }
          }
          if (current) { valid[i] = true; seq[i] = ps; }
        }
        if (sa && !se && retiring && old_valid) { state[i] = {}; valid[i] = false; }
        if (sr) { state[i] = {}; valid[i] = false; seq[i] = 0; }
        if (gr) valid[i] = false;
      }
      step(1);
      (void)peek("io_anchor");
      for (unsigned i = 0; i < slots; ++i) {
        mpz_set_ui(expected, 0);
        for (unsigned k = 0; k < 5; ++k) for (unsigned g = 0; g < 4; ++g) {
          uint64_t v = state[i][k][g];
          mpz_set_ui(field, v); mpz_mul_2exp(field, field, 64 * (k * 4 + g));
          mpz_ior(expected, expected, field); digest ^= v; digest *= 1099511628211ull;
        }
        mpz_set_ui(field, seq[i]); mpz_mul_2exp(field, field, 1280); mpz_ior(expected, expected, field);
        if (valid[i]) mpz_setbit(expected, 1312);
        // These bounded finite traces cannot reach 64-bit carry. The carry
        // output is observed exactly, but overflow reachability is unproven.
        digest ^= seq[i]; digest *= 1099511628211ull;
        digest ^= valid[i]; digest *= 1099511628211ull;
        if (negative && cycle == 7 && i == 0) mpz_combit(expected, 0);
        peek("io_observe_" + std::to_string(i), got);
        if (mpz_cmp(expected, got)) {
          std::cerr << "BANKED_STATE_TOKEN_MISMATCH cycle=" << cycle << " slot=" << i << "\n";
          expect(false, "complete bucket state at same target token");
          mpz_clears(expected, got, field, nullptr); return;
        }
        ++checked;
      }
    }
    std::cout << "BANKED_STATE_TOKEN_PASS {\"target_tokens\":" << tokens
              << ",\"banks\":" << banks << ",\"lanes\":16,\"slots\":" << slots
              << ",\"checked_outputs\":" << checked << ",\"observed_bits_per_slot\":1314"
              << ",\"host_cycles_including_bridge_io\":" << clk.hcycle() - h0
              << ",\"digest\":\"" << std::hex << digest << std::dec << "\"}\n";
    mpz_clears(expected, got, field, nullptr);
  }
};
TEST_MAIN(TestBankedState)
