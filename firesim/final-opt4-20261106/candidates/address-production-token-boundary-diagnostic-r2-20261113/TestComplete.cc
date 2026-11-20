#include "TestHarness.h"
#include "bridges/clock.h"
#include "trace-ports.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class TestComplete final : public TestHarness {
  simif_t &interface;
  std::string trace;
  unsigned mode = 0;
public:
  TestComplete(simif_t &s, widget_registry_t &r, const std::vector<std::string> &args,
               std::string_view name) : TestHarness(r, args, name), interface(s) {
    for (const auto &arg : args) {
      if (arg.rfind("+trace=", 0) == 0) trace = arg.substr(7);
      if (arg.rfind("+boundary-mode=", 0) == 0) mode = std::stoul(arg.substr(15));
    }
  }
  void run_test() override {
    log = false;
    std::ifstream file(trace);
    if (!expect(file.good(), "immutable trace exists")) return;
    std::vector<std::vector<std::string>> rows;
    std::string line, word;
    while (std::getline(file, line)) {
      std::istringstream input(line);
      std::vector<std::string> row;
      while (input >> word) row.push_back(word);
      rows.push_back(row);
    }
    const auto ni = std::size(input_ports), no = std::size(output_ports);
    if (!expect(rows.size() == 3003 && mode <= 3, "diagnostic bounds")) return;
    for (const auto &row : rows)
      if (!expect(row.size() == ni + no, "unaltered complete token width")) return;
    mpz_t value, expected, got;
    mpz_inits(value, expected, got, nullptr);
    auto &clk = get_bridge<clockmodule_t>();
    for (unsigned cycle = 0; cycle < 32; ++cycle) {
      for (size_t i = 0; i < ni; ++i) {
        mpz_set_str(value, rows[cycle][i].c_str(), 16);
        poke(input_ports[i], value);
      }
      if (mode == 2 || mode == 3) {
        (void)peek_poke.peek(output_ports[0], true);
        std::cout << "BOUNDARY_PRE cycle=" << cycle << " timeout=" << peek_poke.timeout()
                  << " unstable=" << peek_poke.unstable() << "\n";
      }
      if (mode != 3) step(1);
      bool timeout = false, unstable = false;
      if (mode == 1) {
        (void)peek_poke.peek(output_ports[0], true);
        timeout = peek_poke.timeout(); unstable = peek_poke.unstable();
      }
      auto tc = clk.tcycle(), hc = clk.hcycle();
      // These two addresses are pinned by the exact generated const header.
      auto done = interface.read(16), precise = interface.read(528);
      unsigned matches[3] = {0, 0, 0};
      for (size_t i = 0; i < no; ++i) {
        peek(output_ports[i], got);
        for (int offset = -1; offset <= 1; ++offset) {
          int index = int(cycle) + offset;
          if (index < 0) continue;
          mpz_set_str(expected, rows[index][ni + i].c_str(), 16);
          matches[offset + 1] += mpz_cmp(expected, got) == 0;
        }
        mpz_set_str(expected, rows[cycle][ni + i].c_str(), 16);
        if (mpz_cmp(expected, got) && cycle >= 3) {
          char *a = mpz_get_str(nullptr, 16, expected), *b = mpz_get_str(nullptr, 16, got);
          std::cout << "BOUNDARY_VALUE cycle=" << cycle << " port=" << output_ports[i]
                    << " expected=" << a << " got=" << b << "\n";
          free(a); free(b);
        }
      }
      std::cout << "BOUNDARY_ROW mode=" << mode << " cycle=" << cycle
                << " harness_horizon=" << cycles() << " clock_tcycle=" << tc
                << " host_cycle=" << hc << " done=" << done << " precise=" << precise
                << " timeout=" << timeout << " unstable=" << unstable
                << " match_previous=" << matches[0] << " match_current=" << matches[1]
                << " match_next=" << matches[2] << " outputs=" << no << "\n";
      if (mode == 3) step(1);
    }
    mpz_clears(value, expected, got, nullptr);
    std::cout << "BOUNDARY_DIAGNOSTIC_COMPLETE mode=" << mode
              << " tokens=32 public_outputs=" << no << " validation_claim=false\n";
  }
};

std::unique_ptr<simulation_t> create_simulation(simif_t &s, widget_registry_t &r,
    const std::vector<std::string> &args) {
  return std::make_unique<TestComplete>(s, r, args, s.get_target_name());
}
