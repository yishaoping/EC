#include "TestHarness.h"
#include "bridges/clock.h"
#include "trace-ports.h"
#include <fstream>
#include <iostream>
#include <string>

class TestMixed final : public TestHarness {
  std::string trace;
  bool negative = false;
public:
  TestMixed(widget_registry_t &r, const std::vector<std::string> &a,
               std::string_view n) : TestHarness(r, a, n) {
    for (const auto &x : a) {
      if (x.rfind("+trace=", 0) == 0) trace = x.substr(7);
      if (x == "+negative") negative = true;
    }
  }
  void run_test() override {
    log = false;
    std::ifstream input(trace);
    if (!expect(input.good(), "reference target trace exists")) return;
    mpz_t value, expected, got;
    mpz_inits(value, expected, got, nullptr);
    uint64_t checked = 0, digest = 1469598103934665603ull;
    auto &clk = get_bridge<clockmodule_t>();
    auto before = clk.hcycle();
    for (unsigned cycle = 0; cycle < 3003; ++cycle) {
      for (const auto &port : input_ports) {
        std::string word;
        if (!expect(bool(input >> word), "complete input token")) return;
        mpz_set_str(value, word.c_str(), 16);
        poke(port, value);
      }
      step(1);
      // step() reaches the requested cycle horizon. Each output channel may
      // still be producing its next registered token. The mpz peek overload
      // reads MMIO immediately, so first require the bridge's common precise
      // token boundary, then read all seven unchanged 64-bit expectations.
      (void)peek_poke.peek(output_ports[0], true);
      if (!expect(!peek_poke.timeout() && !peek_poke.unstable(),
                  "all public output channels precise at target edge")) return;
      for (const auto &port : output_ports) {
        std::string word;
        if (!expect(bool(input >> word), "complete output reference")) return;
        mpz_set_str(expected, word.c_str(), 16);
        peek(port, got);
        // First three explicit reset tokens establish all initialized state.
        // Invalid payload is checked separately by the full target miter.
        if (cycle < 3) continue;
        if (negative && cycle == 100 && port == std::string("io_address_statsValid"))
          mpz_combit(expected, 0);
        if (mpz_cmp(expected, got)) {
          std::cerr << "MIXED_STATS_HOST_MISMATCH cycle=" << cycle << " port=" << port
                    << " expected=" << mpz_get_str(nullptr, 16, expected)
                    << " got=" << mpz_get_str(nullptr, 16, got) << "\n";
          expect(false, "complete module same target token");
          mpz_clears(value, expected, got, nullptr); return;
        }
        digest ^= mpz_get_ui(got); digest *= 1099511628211ull;
        ++checked;
      }
    }
    std::string extra;
    if (!expect(!(input >> extra), "exact trace length")) return;
    std::cout << "MIXED_STATS_HOST_TOKEN_PASS {\"target_tokens\":3003,\"checked_outputs\":"
              << checked << ",\"host_cycles_including_bridge_io\":" << clk.hcycle() - before
              << ",\"digest\":\"" << std::hex << digest << std::dec << "\"}\n";
    mpz_clears(value, expected, got, nullptr);
  }
};
TEST_MAIN(TestMixed)
