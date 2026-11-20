#include "TestHarness.h"
#include "bridges/clock.h"
#include <array>
#include <iostream>
#include <string>

class TestHistogram final : public TestHarness {
  unsigned slots = 0;
  bool negative = false;
public:
  TestHistogram(widget_registry_t &r, const std::vector<std::string> &a,
                std::string_view n) : TestHarness(r, a, n) {
    for (const auto &x : a) {
      if (x.rfind("+slots=", 0) == 0) slots = std::stoul(x.substr(7));
      if (x == "+negative") negative = true;
    }
  }
  void run_test() override {
    log = false;
    if (!expect(slots == 2 || slots == 4 || slots == 256, "actual slot count")) return;
    target_reset();
    uint64_t rng = 0x8491167d12345678ull, checked = 0, digest = 1469598103934665603ull;
    auto next = [&]() { rng ^= rng << 13; rng ^= rng >> 7; rng ^= rng << 17; return rng; };
    mpz_t expected, got, field;
    mpz_inits(expected, got, field, nullptr);
    auto &clk = get_bridge<clockmodule_t>();
    auto h0 = clk.hcycle();
    const unsigned tokens = 32;
    for (unsigned cycle = 0; cycle < tokens; ++cycle) {
      std::array<std::array<uint64_t, 4>, 256> oracle{};
      for (unsigned j = 0; j < 80; ++j) {
        // Equal keys, absent keys, all-full contributions, every destination,
        // and mixed bounds exercise sorting/compaction and token ordering.
        unsigned key = cycle == 0 ? 0 : cycle == 1 ? 255 :
          cycle == 2 ? slots - 1 : cycle == 3 ? j % slots : next() % 256;
        std::array<unsigned, 4> count = {
          unsigned(cycle < 4 ? 8 : next() % 9),
          unsigned(cycle < 4 ? 3 : next() % 4),
          unsigned(cycle < 4 ? 2 : next() % 3),
          unsigned(cycle < 4 ? 1 : next() % 2)};
        std::string p = "io_sources_" + std::to_string(j) + "_";
        poke(p + "key", key);
        poke(p + "bytes", count[0]); poke(p + "words4", count[1]);
        poke(p + "words8", count[2]); poke(p + "lines", count[3]);
        for (unsigned g = 0; g < 4; ++g) oracle[key][g] += count[g];
      }
      // Close exactly one target input token before observing its outputs.
      step(1);
      (void)peek("io_anchor");
      for (unsigned i = 0; i < slots; ++i) {
        mpz_set_ui(expected, 0);
        for (unsigned g = 0; g < 4; ++g) {
          mpz_set_ui(field, oracle[i][g]);
          mpz_mul_2exp(field, field, 64 * g); mpz_ior(expected, expected, field);
        }
        if (negative && cycle == 7 && i == 0) mpz_combit(expected, 0);
        peek("io_result_" + std::to_string(i), got);
        if (mpz_cmp(expected, got)) {
          std::cerr << "HISTOGRAM_TOKEN_MISMATCH cycle=" << cycle << " slot=" << i << "\n";
          expect(false, "same target-token histogram output");
          mpz_clears(expected, got, field, nullptr); return;
        }
        for (unsigned g = 0; g < 4; ++g) {
          digest ^= oracle[i][g]; digest *= 1099511628211ull;
        }
        ++checked;
      }
    }
    std::cout << "HISTOGRAM_TOKEN_PASS {\"target_tokens\":" << tokens
              << ",\"slots\":" << slots << ",\"sources\":80,\"checked_outputs\":"
              << checked << ",\"host_cycles_including_bridge_io\":" << clk.hcycle() - h0
              << ",\"digest\":\"" << std::hex << digest << std::dec << "\"}\n";
    mpz_clears(expected, got, field, nullptr);
  }
};
TEST_MAIN(TestHistogram)
