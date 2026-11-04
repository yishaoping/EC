#include "ec_dac_roi.h"
#include <cerrno>
#include <cstring>
#include <fcntl.h>
#include <filesystem>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <unistd.h>

char ec_dac_roi_t::KIND;
ec_dac_roi_t::ec_dac_roi_t(simif_t &sim, const DACROIBRIDGEMODULE_struct &m,
                           unsigned index, const std::vector<std::string> &args)
    : bridge_driver_t(sim, &KIND), mmio(m) {
  if (index != 0) throw std::runtime_error("ROI bridge currently supports one B node only");
  for (const auto &arg : args) {
    const std::string prefix = "+ec-dac-roi-log=";
    if (arg.rfind(prefix, 0) == 0) {
      if (!filename.empty()) throw std::runtime_error("duplicate ROI log option");
      filename = arg.substr(prefix.size());
    }
    const std::string seconds = "+ec-dac-snapshot-seconds=";
    if (arg.rfind(seconds, 0) == 0) {
      auto value = arg.substr(seconds.size());
      if (value.empty() || value.find_first_not_of("0123456789") != std::string::npos)
        throw std::runtime_error("invalid snapshot interval");
      auto count = std::stoul(value);
      if (!count || count > 60) throw std::runtime_error("snapshot interval outside 1..60 seconds");
      interval = std::chrono::seconds(count);
    }
  }
  if (filename.empty()) throw std::runtime_error("B ROI bridge requires +ec-dac-roi-log=FILE");
}
void ec_dac_roi_t::fail(const std::string &why) {
  failed = true;
  std::cerr << "EC_DAC_ROI_OBSERVER_FAILED: " << why << std::endl;
}
void ec_dac_roi_t::init() {
  const std::filesystem::path path(filename);
  const auto parent = std::filesystem::canonical(path.parent_path());
  const std::string root = "/data1/gzh/EC/Experiment/";
  if (parent.string() != "/data1/gzh/EC/Experiment" &&
      parent.string().rfind(root, 0) != 0)
    throw std::runtime_error("raw ROI logs must reside under /data1/gzh/EC/Experiment");
  filename = (parent / path.filename()).string();
  fd = open(filename.c_str(), O_WRONLY | O_CREAT | O_EXCL | O_CLOEXEC | O_NOFOLLOW, 0600);
  if (fd < 0) throw std::runtime_error("cannot create exclusive ROI log: " + std::string(std::strerror(errno)));
  // Persist the new directory entry as well as the individual records.
  int directory = open(parent.c_str(), O_RDONLY | O_DIRECTORY | O_CLOEXEC);
  if (directory < 0) { close(fd); fd = -1; throw std::runtime_error("cannot open ROI log directory"); }
  int synced = fsync(directory); close(directory);
  if (synced) { close(fd); fd = -1; throw std::runtime_error("ROI log directory fsync failed"); }
  last_request = std::chrono::steady_clock::now();
  write(mmio.initialized, 1);
  write(mmio.snapshot_request, 1);
}
void ec_dac_roi_t::save(const std::array<uint64_t, 9> &v) {
  // Every uint64 is decimal text; no conversion through double/JS Number.
  std::ostringstream line;
  line << "{\"schema\":\"ec-dac-b-raw-roi/1\",\"configuration\":\"B\","
       << "\"formal_sample\":false,\"synthetic\":false,\"sequence\":" << v[0]
       << ",\"under_reset\":" << v[1] << ",\"state_transition\":" << v[2]
       << ",\"epoch\":" << v[3] << ",\"state\":" << v[4]
       << ",\"source_boom_tick\":" << v[5] << ",\"roi_begin_tick\":" << v[6]
       << ",\"roi_end_tick\":" << v[7] << ",\"faults\":" << v[8]
       << ",\"timebase_verified\":false,\"runtime_validated\":false}\n";
  auto text = line.str();
  size_t offset = 0;
  while (offset < text.size()) {
    ssize_t amount = ::write(fd, text.data() + offset, text.size() - offset);
    if (amount < 0 && errno == EINTR) continue;
    if (amount <= 0) { fail("raw log write failed"); return; }
    offset += static_cast<size_t>(amount);
  }
  if (fsync(fd)) fail("raw log fsync failed");
}
void ec_dac_roi_t::consume() {
  const std::array<uint64_t, 9> lows = {mmio.value_0_lo, mmio.value_1_lo, mmio.value_2_lo,
    mmio.value_3_lo, mmio.value_4_lo, mmio.value_5_lo, mmio.value_6_lo, mmio.value_7_lo, mmio.value_8_lo};
  const std::array<uint64_t, 9> highs = {mmio.value_0_hi, mmio.value_1_hi, mmio.value_2_hi,
    mmio.value_3_hi, mmio.value_4_hi, mmio.value_5_hi, mmio.value_6_hi, mmio.value_7_hi, mmio.value_8_hi};
  // The FIFO front is stable until POP. A snapshot cannot tear during MMIO.
  for (unsigned batch = 0; batch < 64 && !failed && read(mmio.available); ++batch) {
    std::array<uint64_t, 9> values{};
    for (size_t i = 0; i < values.size(); ++i)
      values[i] = uint64_t(read(lows[i])) | (uint64_t(read(highs[i])) << 32);
    if (values[0] != expected_sequence) { fail("missing or duplicate observer record"); return; }
    save(values);
    if (failed) return;
    if (expected_sequence == UINT64_MAX) { fail("observer sequence overflow"); return; }
    ++expected_sequence;
    write(mmio.pop, 1); // Never acknowledge an event before durable saving.
    if (values[8]) { fail("target ROI controller fault"); return; }
  }
  if (read(mmio.overflow)) fail("bridge sequence overflow");
}
void ec_dac_roi_t::tick() {
  if (failed || fd < 0) return;
  consume();
  const auto now = std::chrono::steady_clock::now();
  if (!failed && now - last_request >= interval) {
    write(mmio.snapshot_request, 1);
    last_request = now;
  }
}
void ec_dac_roi_t::finish() {
  if (fd >= 0 && !failed) consume();
  if (fd >= 0 && fsync(fd)) fail("final ROI fsync failed");
}
ec_dac_roi_t::~ec_dac_roi_t() { if (fd >= 0) close(fd); }
