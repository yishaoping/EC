#pragma once
#include "core/bridge_driver.h"
#include <array>
#include <chrono>

struct DACROIBRIDGEMODULE_struct {
  uint64_t initialized, snapshot_request, available, overflow;
  uint64_t value_0_lo, value_0_hi, value_1_lo, value_1_hi, value_2_lo, value_2_hi;
  uint64_t value_3_lo, value_3_hi, value_4_lo, value_4_hi, value_5_lo, value_5_hi;
  uint64_t value_6_lo, value_6_hi, value_7_lo, value_7_hi, value_8_lo, value_8_hi;
  uint64_t pop;
};

// B-only raw observer transport. It never commits a formal experiment sample.
class ec_dac_roi_t : public bridge_driver_t {
public:
  static char KIND;
  ec_dac_roi_t(simif_t &, const DACROIBRIDGEMODULE_struct &, unsigned,
               const std::vector<std::string> &);
  ~ec_dac_roi_t() override;
  void init() override;
  void tick() override;
  void finish() override;
  bool terminate() override { return failed; }
  int exit_code() override { return failed ? 126 : 0; }
private:
  DACROIBRIDGEMODULE_struct mmio;
  int fd = -1;
  bool failed = false;
  uint64_t expected_sequence = 0;
  std::string filename;
  std::chrono::seconds interval{20};
  std::chrono::steady_clock::time_point last_request;
  void consume();
  void save(const std::array<uint64_t, 9> &);
  void fail(const std::string &);
};
