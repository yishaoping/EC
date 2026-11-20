// Golden Gate-generated Driver Header
// This contains target-specific preprocessor macro definitions,
// and encodes all required bridge metadata to instantiate bridge drivers.
#ifdef GET_INCLUDES
#include "bridges/master.h"
#endif // GET_INCLUDES
#ifdef GET_SUBSTRUCT_CHECKS
static_assert(offsetof(SIMULATIONMASTER_struct, INIT_DONE) == 0 * sizeof(uint64_t), "invalid INIT_DONE");\
static_assert(offsetof(SIMULATIONMASTER_struct, PRESENCE_READ) == 1 * sizeof(uint64_t), "invalid PRESENCE_READ");\
static_assert(offsetof(SIMULATIONMASTER_struct, PRESENCE_WRITE) == 2 * sizeof(uint64_t), "invalid PRESENCE_WRITE");\
static_assert(sizeof(SIMULATIONMASTER_struct) == 3 * sizeof(uint64_t), "invalid structure"); \

#endif // SIMULATIONMASTER_checks
#ifdef GET_CORE_CONSTRUCTOR
registry.add_widget(new master_t(
  simif,
SIMULATIONMASTER_struct{
    .INIT_DONE = 672,
    .PRESENCE_READ = 676,
    .PRESENCE_WRITE = 680,
},
  0,
  args
  ));
#endif // GET_CORE_CONSTRUCTOR
#ifdef GET_INCLUDES
#include "bridges/peek_poke.h"
#endif // GET_INCLUDES
#ifdef GET_SUBSTRUCT_CHECKS
static_assert(offsetof(PEEKPOKEBRIDGEMODULE_struct, STEP) == 0 * sizeof(uint64_t), "invalid STEP");\
static_assert(offsetof(PEEKPOKEBRIDGEMODULE_struct, DONE) == 1 * sizeof(uint64_t), "invalid DONE");\
static_assert(offsetof(PEEKPOKEBRIDGEMODULE_struct, PRECISE_PEEKABLE) == 2 * sizeof(uint64_t), "invalid PRECISE_PEEKABLE");\
static_assert(sizeof(PEEKPOKEBRIDGEMODULE_struct) == 3 * sizeof(uint64_t), "invalid structure"); \

#endif // PEEKPOKEBRIDGEMODULE_checks
#ifdef GET_BRIDGE_CONSTRUCTOR
registry.add_widget(new peek_poke_t(
  simif,
PEEKPOKEBRIDGEMODULE_struct{
    .STEP = 588,
    .DONE = 592,
    .PRECISE_PEEKABLE = 600,
},
  0,
  args
  ,  std::map<std::string, peek_poke_t::Port, std::less<>>{std::make_pair(R"ESC(reset)ESC", peek_poke_t::Port{.address = 596ULL,.chunks = 1})}
,  std::map<std::string, peek_poke_t::Port, std::less<>>{}
));
#endif // GET_BRIDGE_CONSTRUCTOR
#ifdef GET_INCLUDES
#include "bridges/reset_pulse.h"
#endif // GET_INCLUDES
#ifdef GET_SUBSTRUCT_CHECKS
static_assert(offsetof(RESETPULSEBRIDGEMODULE_struct, pulseLength) == 0 * sizeof(uint64_t), "invalid pulseLength");\
static_assert(offsetof(RESETPULSEBRIDGEMODULE_struct, doneInit) == 1 * sizeof(uint64_t), "invalid doneInit");\
static_assert(sizeof(RESETPULSEBRIDGEMODULE_struct) == 2 * sizeof(uint64_t), "invalid structure"); \

#endif // RESETPULSEBRIDGEMODULE_checks
#ifdef GET_BRIDGE_CONSTRUCTOR
registry.add_widget(new reset_pulse_t(
  simif,
RESETPULSEBRIDGEMODULE_struct{
    .pulseLength = 688,
    .doneInit = 692,
},
  0,
  args
  ,  1023
,  50
));
#endif // GET_BRIDGE_CONSTRUCTOR
#ifdef GET_INCLUDES
#include "bridges/tsibridge.h"
#endif // GET_INCLUDES
#ifdef GET_SUBSTRUCT_CHECKS
static_assert(offsetof(TSIBRIDGEMODULE_struct, in_bits) == 0 * sizeof(uint64_t), "invalid in_bits");\
static_assert(offsetof(TSIBRIDGEMODULE_struct, in_valid) == 1 * sizeof(uint64_t), "invalid in_valid");\
static_assert(offsetof(TSIBRIDGEMODULE_struct, in_ready) == 2 * sizeof(uint64_t), "invalid in_ready");\
static_assert(offsetof(TSIBRIDGEMODULE_struct, out_bits) == 3 * sizeof(uint64_t), "invalid out_bits");\
static_assert(offsetof(TSIBRIDGEMODULE_struct, out_valid) == 4 * sizeof(uint64_t), "invalid out_valid");\
static_assert(offsetof(TSIBRIDGEMODULE_struct, out_ready) == 5 * sizeof(uint64_t), "invalid out_ready");\
static_assert(offsetof(TSIBRIDGEMODULE_struct, step_size) == 6 * sizeof(uint64_t), "invalid step_size");\
static_assert(offsetof(TSIBRIDGEMODULE_struct, done) == 7 * sizeof(uint64_t), "invalid done");\
static_assert(offsetof(TSIBRIDGEMODULE_struct, start) == 8 * sizeof(uint64_t), "invalid start");\
static_assert(sizeof(TSIBRIDGEMODULE_struct) == 9 * sizeof(uint64_t), "invalid structure"); \

#endif // TSIBRIDGEMODULE_checks
#ifdef GET_BRIDGE_CONSTRUCTOR
registry.add_widget(new tsibridge_t(
  simif,
  registry.get_widget<loadmem_t>(),
TSIBRIDGEMODULE_struct{
    .in_bits = 384,
    .in_valid = 388,
    .in_ready = 392,
    .out_bits = 396,
    .out_valid = 400,
    .out_ready = 404,
    .step_size = 408,
    .done = 412,
    .start = 416,
},
  0,
  args
  ,  true
,  -2147483648ULL
));
#endif // GET_BRIDGE_CONSTRUCTOR
#ifdef GET_INCLUDES
#include "bridges/fased_memory_timing_model.h"
#endif // GET_INCLUDES
#ifdef GET_BRIDGE_CONSTRUCTOR
registry.add_widget(new FASEDMemoryTimingModel(
  simif,
  AddressMap{
    std::vector<std::pair<std::string, uint32_t>>{
      { R"ESC(writeLatency)ESC", 0 },\
      { R"ESC(readLatency)ESC", 4 },\
      { R"ESC(writeMaxReqs)ESC", 8 },\
      { R"ESC(readMaxReqs)ESC", 12 },\
      { R"ESC(writeOutstandingHistogram_0)ESC", 16 },\
      { R"ESC(writeOutstandingHistogram_1)ESC", 20 },\
      { R"ESC(writeOutstandingHistogram_2)ESC", 24 },\
      { R"ESC(writeOutstandingHistogram_3)ESC", 28 },\
      { R"ESC(writeOutstandingHistogram_4)ESC", 32 },\
      { R"ESC(readOutstandingHistogram_0)ESC", 36 },\
      { R"ESC(readOutstandingHistogram_1)ESC", 40 },\
      { R"ESC(readOutstandingHistogram_2)ESC", 44 },\
      { R"ESC(readOutstandingHistogram_3)ESC", 48 },\
      { R"ESC(readOutstandingHistogram_4)ESC", 52 },\
      { R"ESC(totalWriteBeats)ESC", 56 },\
      { R"ESC(totalReadBeats)ESC", 60 },\
      { R"ESC(totalWrites)ESC", 64 },\
      { R"ESC(totalReads)ESC", 68 },\
      { R"ESC(relaxFunctionalModel)ESC", 72 },\
      { R"ESC(rrespError)ESC", 76 },\
      { R"ESC(brespError)ESC", 80 },\
    },
    std::vector<std::pair<std::string, uint32_t>>{
      { R"ESC(writeLatency)ESC", 0 },\
      { R"ESC(readLatency)ESC", 4 },\
      { R"ESC(writeMaxReqs)ESC", 8 },\
      { R"ESC(readMaxReqs)ESC", 12 },\
      { R"ESC(relaxFunctionalModel)ESC", 72 },\
    }
  },
  0,
  args
  ,  R"ESC(memory_stats0.csv)ESC"
,  1L << 35
));
#endif // GET_BRIDGE_CONSTRUCTOR
#ifdef GET_INCLUDES
#include "bridges/uart.h"
#endif // GET_INCLUDES
#ifdef GET_SUBSTRUCT_CHECKS
static_assert(offsetof(UARTBRIDGEMODULE_struct, out_bits) == 0 * sizeof(uint64_t), "invalid out_bits");\
static_assert(offsetof(UARTBRIDGEMODULE_struct, out_valid) == 1 * sizeof(uint64_t), "invalid out_valid");\
static_assert(offsetof(UARTBRIDGEMODULE_struct, out_ready) == 2 * sizeof(uint64_t), "invalid out_ready");\
static_assert(offsetof(UARTBRIDGEMODULE_struct, in_bits) == 3 * sizeof(uint64_t), "invalid in_bits");\
static_assert(offsetof(UARTBRIDGEMODULE_struct, in_valid) == 4 * sizeof(uint64_t), "invalid in_valid");\
static_assert(offsetof(UARTBRIDGEMODULE_struct, in_ready) == 5 * sizeof(uint64_t), "invalid in_ready");\
static_assert(sizeof(UARTBRIDGEMODULE_struct) == 6 * sizeof(uint64_t), "invalid structure"); \

#endif // UARTBRIDGEMODULE_checks
#ifdef GET_BRIDGE_CONSTRUCTOR
registry.add_widget(new uart_t(
  simif,
UARTBRIDGEMODULE_struct{
    .out_bits = 608,
    .out_valid = 612,
    .out_ready = 616,
    .in_bits = 620,
    .in_valid = 624,
    .in_ready = 628,
},
  0,
  args
  ));
#endif // GET_BRIDGE_CONSTRUCTOR
#ifdef GET_INCLUDES
#include "bridges/blockdev.h"
#endif // GET_INCLUDES
#ifdef GET_SUBSTRUCT_CHECKS
static_assert(offsetof(BLOCKDEVBRIDGEMODULE_struct, read_latency) == 0 * sizeof(uint64_t), "invalid read_latency");\
static_assert(offsetof(BLOCKDEVBRIDGEMODULE_struct, write_latency) == 1 * sizeof(uint64_t), "invalid write_latency");\
static_assert(offsetof(BLOCKDEVBRIDGEMODULE_struct, bdev_nsectors) == 2 * sizeof(uint64_t), "invalid bdev_nsectors");\
static_assert(offsetof(BLOCKDEVBRIDGEMODULE_struct, bdev_max_req_len) == 3 * sizeof(uint64_t), "invalid bdev_max_req_len");\
static_assert(offsetof(BLOCKDEVBRIDGEMODULE_struct, bdev_req_valid) == 4 * sizeof(uint64_t), "invalid bdev_req_valid");\
static_assert(offsetof(BLOCKDEVBRIDGEMODULE_struct, bdev_req_write) == 5 * sizeof(uint64_t), "invalid bdev_req_write");\
static_assert(offsetof(BLOCKDEVBRIDGEMODULE_struct, bdev_req_offset) == 6 * sizeof(uint64_t), "invalid bdev_req_offset");\
static_assert(offsetof(BLOCKDEVBRIDGEMODULE_struct, bdev_req_len) == 7 * sizeof(uint64_t), "invalid bdev_req_len");\
static_assert(offsetof(BLOCKDEVBRIDGEMODULE_struct, bdev_req_tag) == 8 * sizeof(uint64_t), "invalid bdev_req_tag");\
static_assert(offsetof(BLOCKDEVBRIDGEMODULE_struct, bdev_req_ready) == 9 * sizeof(uint64_t), "invalid bdev_req_ready");\
static_assert(offsetof(BLOCKDEVBRIDGEMODULE_struct, bdev_data_valid) == 10 * sizeof(uint64_t), "invalid bdev_data_valid");\
static_assert(offsetof(BLOCKDEVBRIDGEMODULE_struct, bdev_data_data_upper) == 11 * sizeof(uint64_t), "invalid bdev_data_data_upper");\
static_assert(offsetof(BLOCKDEVBRIDGEMODULE_struct, bdev_data_data_lower) == 12 * sizeof(uint64_t), "invalid bdev_data_data_lower");\
static_assert(offsetof(BLOCKDEVBRIDGEMODULE_struct, bdev_data_tag) == 13 * sizeof(uint64_t), "invalid bdev_data_tag");\
static_assert(offsetof(BLOCKDEVBRIDGEMODULE_struct, bdev_data_ready) == 14 * sizeof(uint64_t), "invalid bdev_data_ready");\
static_assert(offsetof(BLOCKDEVBRIDGEMODULE_struct, bdev_rresp_data_upper) == 15 * sizeof(uint64_t), "invalid bdev_rresp_data_upper");\
static_assert(offsetof(BLOCKDEVBRIDGEMODULE_struct, bdev_rresp_data_lower) == 16 * sizeof(uint64_t), "invalid bdev_rresp_data_lower");\
static_assert(offsetof(BLOCKDEVBRIDGEMODULE_struct, bdev_rresp_tag) == 17 * sizeof(uint64_t), "invalid bdev_rresp_tag");\
static_assert(offsetof(BLOCKDEVBRIDGEMODULE_struct, bdev_rresp_valid) == 18 * sizeof(uint64_t), "invalid bdev_rresp_valid");\
static_assert(offsetof(BLOCKDEVBRIDGEMODULE_struct, bdev_rresp_ready) == 19 * sizeof(uint64_t), "invalid bdev_rresp_ready");\
static_assert(offsetof(BLOCKDEVBRIDGEMODULE_struct, bdev_wack_tag) == 20 * sizeof(uint64_t), "invalid bdev_wack_tag");\
static_assert(offsetof(BLOCKDEVBRIDGEMODULE_struct, bdev_wack_valid) == 21 * sizeof(uint64_t), "invalid bdev_wack_valid");\
static_assert(offsetof(BLOCKDEVBRIDGEMODULE_struct, bdev_wack_ready) == 22 * sizeof(uint64_t), "invalid bdev_wack_ready");\
static_assert(offsetof(BLOCKDEVBRIDGEMODULE_struct, bdev_reqs_pending) == 23 * sizeof(uint64_t), "invalid bdev_reqs_pending");\
static_assert(offsetof(BLOCKDEVBRIDGEMODULE_struct, bdev_wack_stalled) == 24 * sizeof(uint64_t), "invalid bdev_wack_stalled");\
static_assert(offsetof(BLOCKDEVBRIDGEMODULE_struct, bdev_rresp_stalled) == 25 * sizeof(uint64_t), "invalid bdev_rresp_stalled");\
static_assert(sizeof(BLOCKDEVBRIDGEMODULE_struct) == 26 * sizeof(uint64_t), "invalid structure"); \

#endif // BLOCKDEVBRIDGEMODULE_checks
#ifdef GET_BRIDGE_CONSTRUCTOR
registry.add_widget(new blockdev_t(
  simif,
BLOCKDEVBRIDGEMODULE_struct{
    .read_latency = 128,
    .write_latency = 132,
    .bdev_nsectors = 136,
    .bdev_max_req_len = 140,
    .bdev_req_valid = 144,
    .bdev_req_write = 148,
    .bdev_req_offset = 152,
    .bdev_req_len = 156,
    .bdev_req_tag = 160,
    .bdev_req_ready = 164,
    .bdev_data_valid = 168,
    .bdev_data_data_upper = 172,
    .bdev_data_data_lower = 176,
    .bdev_data_tag = 180,
    .bdev_data_ready = 184,
    .bdev_rresp_data_upper = 188,
    .bdev_rresp_data_lower = 192,
    .bdev_rresp_tag = 196,
    .bdev_rresp_valid = 200,
    .bdev_rresp_ready = 204,
    .bdev_wack_tag = 208,
    .bdev_wack_valid = 212,
    .bdev_wack_ready = 216,
    .bdev_reqs_pending = 220,
    .bdev_wack_stalled = 224,
    .bdev_rresp_stalled = 228,
},
  0,
  args
  ,  1
,  24
));
#endif // GET_BRIDGE_CONSTRUCTOR
#ifdef GET_INCLUDES
#include "bridges/tracerv.h"
#endif // GET_INCLUDES
#ifdef GET_SUBSTRUCT_CHECKS
static_assert(offsetof(TRACERVBRIDGEMODULE_struct, initDone) == 0 * sizeof(uint64_t), "invalid initDone");\
static_assert(offsetof(TRACERVBRIDGEMODULE_struct, traceEnable) == 1 * sizeof(uint64_t), "invalid traceEnable");\
static_assert(offsetof(TRACERVBRIDGEMODULE_struct, hostTriggerPCStartHigh) == 2 * sizeof(uint64_t), "invalid hostTriggerPCStartHigh");\
static_assert(offsetof(TRACERVBRIDGEMODULE_struct, hostTriggerPCStartLow) == 3 * sizeof(uint64_t), "invalid hostTriggerPCStartLow");\
static_assert(offsetof(TRACERVBRIDGEMODULE_struct, hostTriggerPCEndHigh) == 4 * sizeof(uint64_t), "invalid hostTriggerPCEndHigh");\
static_assert(offsetof(TRACERVBRIDGEMODULE_struct, hostTriggerPCEndLow) == 5 * sizeof(uint64_t), "invalid hostTriggerPCEndLow");\
static_assert(offsetof(TRACERVBRIDGEMODULE_struct, hostTriggerCycleCountStartHigh) == 6 * sizeof(uint64_t), "invalid hostTriggerCycleCountStartHigh");\
static_assert(offsetof(TRACERVBRIDGEMODULE_struct, hostTriggerCycleCountStartLow) == 7 * sizeof(uint64_t), "invalid hostTriggerCycleCountStartLow");\
static_assert(offsetof(TRACERVBRIDGEMODULE_struct, hostTriggerCycleCountEndHigh) == 8 * sizeof(uint64_t), "invalid hostTriggerCycleCountEndHigh");\
static_assert(offsetof(TRACERVBRIDGEMODULE_struct, hostTriggerCycleCountEndLow) == 9 * sizeof(uint64_t), "invalid hostTriggerCycleCountEndLow");\
static_assert(offsetof(TRACERVBRIDGEMODULE_struct, hostTriggerStartInst) == 10 * sizeof(uint64_t), "invalid hostTriggerStartInst");\
static_assert(offsetof(TRACERVBRIDGEMODULE_struct, hostTriggerStartInstMask) == 11 * sizeof(uint64_t), "invalid hostTriggerStartInstMask");\
static_assert(offsetof(TRACERVBRIDGEMODULE_struct, hostTriggerEndInst) == 12 * sizeof(uint64_t), "invalid hostTriggerEndInst");\
static_assert(offsetof(TRACERVBRIDGEMODULE_struct, hostTriggerEndInstMask) == 13 * sizeof(uint64_t), "invalid hostTriggerEndInstMask");\
static_assert(offsetof(TRACERVBRIDGEMODULE_struct, triggerSelector) == 14 * sizeof(uint64_t), "invalid triggerSelector");\
static_assert(sizeof(TRACERVBRIDGEMODULE_struct) == 15 * sizeof(uint64_t), "invalid structure"); \

#endif // TRACERVBRIDGEMODULE_checks
#ifdef GET_BRIDGE_CONSTRUCTOR
registry.add_widget(new tracerv_t(
  simif,
  *registry.get_stream_engine(),
TRACERVBRIDGEMODULE_struct{
    .initDone = 448,
    .traceEnable = 452,
    .hostTriggerPCStartHigh = 456,
    .hostTriggerPCStartLow = 460,
    .hostTriggerPCEndHigh = 464,
    .hostTriggerPCEndLow = 468,
    .hostTriggerCycleCountStartHigh = 472,
    .hostTriggerCycleCountStartLow = 476,
    .hostTriggerCycleCountEndHigh = 480,
    .hostTriggerCycleCountEndLow = 484,
    .hostTriggerStartInst = 488,
    .hostTriggerStartInstMask = 492,
    .hostTriggerEndInst = 496,
    .hostTriggerEndInstMask = 500,
    .triggerSelector = 504,
},
  0,
  args
  ,  0
,  6144
,  3
,  ClockInfo{R"ESC(buildtop_reference_clock)ESC", 1, 1}
));
#endif // GET_BRIDGE_CONSTRUCTOR
#ifdef GET_INCLUDES
#include "bridges/ec_dac_roi.h"
#endif // GET_INCLUDES
#ifdef GET_SUBSTRUCT_CHECKS
static_assert(offsetof(DACROIBRIDGEMODULE_struct, initialized) == 0 * sizeof(uint64_t), "invalid initialized");\
static_assert(offsetof(DACROIBRIDGEMODULE_struct, snapshot_request) == 1 * sizeof(uint64_t), "invalid snapshot_request");\
static_assert(offsetof(DACROIBRIDGEMODULE_struct, available) == 2 * sizeof(uint64_t), "invalid available");\
static_assert(offsetof(DACROIBRIDGEMODULE_struct, overflow) == 3 * sizeof(uint64_t), "invalid overflow");\
static_assert(offsetof(DACROIBRIDGEMODULE_struct, value_0_lo) == 4 * sizeof(uint64_t), "invalid value_0_lo");\
static_assert(offsetof(DACROIBRIDGEMODULE_struct, value_0_hi) == 5 * sizeof(uint64_t), "invalid value_0_hi");\
static_assert(offsetof(DACROIBRIDGEMODULE_struct, value_1_lo) == 6 * sizeof(uint64_t), "invalid value_1_lo");\
static_assert(offsetof(DACROIBRIDGEMODULE_struct, value_1_hi) == 7 * sizeof(uint64_t), "invalid value_1_hi");\
static_assert(offsetof(DACROIBRIDGEMODULE_struct, value_2_lo) == 8 * sizeof(uint64_t), "invalid value_2_lo");\
static_assert(offsetof(DACROIBRIDGEMODULE_struct, value_2_hi) == 9 * sizeof(uint64_t), "invalid value_2_hi");\
static_assert(offsetof(DACROIBRIDGEMODULE_struct, value_3_lo) == 10 * sizeof(uint64_t), "invalid value_3_lo");\
static_assert(offsetof(DACROIBRIDGEMODULE_struct, value_3_hi) == 11 * sizeof(uint64_t), "invalid value_3_hi");\
static_assert(offsetof(DACROIBRIDGEMODULE_struct, value_4_lo) == 12 * sizeof(uint64_t), "invalid value_4_lo");\
static_assert(offsetof(DACROIBRIDGEMODULE_struct, value_4_hi) == 13 * sizeof(uint64_t), "invalid value_4_hi");\
static_assert(offsetof(DACROIBRIDGEMODULE_struct, value_5_lo) == 14 * sizeof(uint64_t), "invalid value_5_lo");\
static_assert(offsetof(DACROIBRIDGEMODULE_struct, value_5_hi) == 15 * sizeof(uint64_t), "invalid value_5_hi");\
static_assert(offsetof(DACROIBRIDGEMODULE_struct, value_6_lo) == 16 * sizeof(uint64_t), "invalid value_6_lo");\
static_assert(offsetof(DACROIBRIDGEMODULE_struct, value_6_hi) == 17 * sizeof(uint64_t), "invalid value_6_hi");\
static_assert(offsetof(DACROIBRIDGEMODULE_struct, value_7_lo) == 18 * sizeof(uint64_t), "invalid value_7_lo");\
static_assert(offsetof(DACROIBRIDGEMODULE_struct, value_7_hi) == 19 * sizeof(uint64_t), "invalid value_7_hi");\
static_assert(offsetof(DACROIBRIDGEMODULE_struct, value_8_lo) == 20 * sizeof(uint64_t), "invalid value_8_lo");\
static_assert(offsetof(DACROIBRIDGEMODULE_struct, value_8_hi) == 21 * sizeof(uint64_t), "invalid value_8_hi");\
static_assert(offsetof(DACROIBRIDGEMODULE_struct, pop) == 22 * sizeof(uint64_t), "invalid pop");\
static_assert(sizeof(DACROIBRIDGEMODULE_struct) == 23 * sizeof(uint64_t), "invalid structure"); \

#endif // DACROIBRIDGEMODULE_checks
#ifdef GET_BRIDGE_CONSTRUCTOR
registry.add_widget(new ec_dac_roi_t(
  simif,
DACROIBRIDGEMODULE_struct{
    .initialized = 256,
    .snapshot_request = 260,
    .available = 264,
    .overflow = 268,
    .value_0_lo = 272,
    .value_0_hi = 276,
    .value_1_lo = 280,
    .value_1_hi = 284,
    .value_2_lo = 288,
    .value_2_hi = 292,
    .value_3_lo = 296,
    .value_3_hi = 300,
    .value_4_lo = 304,
    .value_4_hi = 308,
    .value_5_lo = 312,
    .value_5_hi = 316,
    .value_6_lo = 320,
    .value_6_hi = 324,
    .value_7_lo = 328,
    .value_7_hi = 332,
    .value_8_lo = 336,
    .value_8_hi = 340,
    .pop = 344,
},
  0,
  args
  ));
#endif // GET_BRIDGE_CONSTRUCTOR
#ifdef GET_INCLUDES
#include "bridges/clock.h"
#endif // GET_INCLUDES
#ifdef GET_SUBSTRUCT_CHECKS
static_assert(offsetof(CLOCKBRIDGEMODULE_struct, hCycle_0) == 0 * sizeof(uint64_t), "invalid hCycle_0");\
static_assert(offsetof(CLOCKBRIDGEMODULE_struct, hCycle_1) == 1 * sizeof(uint64_t), "invalid hCycle_1");\
static_assert(offsetof(CLOCKBRIDGEMODULE_struct, hCycle_latch) == 2 * sizeof(uint64_t), "invalid hCycle_latch");\
static_assert(offsetof(CLOCKBRIDGEMODULE_struct, tCycle_0) == 3 * sizeof(uint64_t), "invalid tCycle_0");\
static_assert(offsetof(CLOCKBRIDGEMODULE_struct, tCycle_1) == 4 * sizeof(uint64_t), "invalid tCycle_1");\
static_assert(offsetof(CLOCKBRIDGEMODULE_struct, tCycle_latch) == 5 * sizeof(uint64_t), "invalid tCycle_latch");\
static_assert(sizeof(CLOCKBRIDGEMODULE_struct) == 6 * sizeof(uint64_t), "invalid structure"); \

#endif // CLOCKBRIDGEMODULE_checks
#ifdef GET_BRIDGE_CONSTRUCTOR
registry.add_widget(new clockmodule_t(
  simif,
CLOCKBRIDGEMODULE_struct{
    .hCycle_0 = 640,
    .hCycle_1 = 644,
    .hCycle_latch = 648,
    .tCycle_0 = 652,
    .tCycle_1 = 656,
    .tCycle_latch = 660,
},
  0,
  args
  ));
#endif // GET_BRIDGE_CONSTRUCTOR
#ifdef GET_INCLUDES
#include "bridges/loadmem.h"
#endif // GET_INCLUDES
#ifdef GET_SUBSTRUCT_CHECKS
static_assert(offsetof(LOADMEMWIDGET_struct, W_ADDRESS_H) == 0 * sizeof(uint64_t), "invalid W_ADDRESS_H");\
static_assert(offsetof(LOADMEMWIDGET_struct, W_ADDRESS_L) == 1 * sizeof(uint64_t), "invalid W_ADDRESS_L");\
static_assert(offsetof(LOADMEMWIDGET_struct, W_LENGTH) == 2 * sizeof(uint64_t), "invalid W_LENGTH");\
static_assert(offsetof(LOADMEMWIDGET_struct, ZERO_OUT_DRAM) == 3 * sizeof(uint64_t), "invalid ZERO_OUT_DRAM");\
static_assert(offsetof(LOADMEMWIDGET_struct, W_DATA) == 4 * sizeof(uint64_t), "invalid W_DATA");\
static_assert(offsetof(LOADMEMWIDGET_struct, ZERO_FINISHED) == 5 * sizeof(uint64_t), "invalid ZERO_FINISHED");\
static_assert(offsetof(LOADMEMWIDGET_struct, R_ADDRESS_H) == 6 * sizeof(uint64_t), "invalid R_ADDRESS_H");\
static_assert(offsetof(LOADMEMWIDGET_struct, R_ADDRESS_L) == 7 * sizeof(uint64_t), "invalid R_ADDRESS_L");\
static_assert(offsetof(LOADMEMWIDGET_struct, R_DATA) == 8 * sizeof(uint64_t), "invalid R_DATA");\
static_assert(sizeof(LOADMEMWIDGET_struct) == 9 * sizeof(uint64_t), "invalid structure"); \

#endif // LOADMEMWIDGET_checks
#ifdef GET_CORE_CONSTRUCTOR
registry.add_widget(new loadmem_t(
  simif,
LOADMEMWIDGET_struct{
    .W_ADDRESS_H = 512,
    .W_ADDRESS_L = 516,
    .W_LENGTH = 520,
    .ZERO_OUT_DRAM = 524,
    .W_DATA = 528,
    .ZERO_FINISHED = 532,
    .R_ADDRESS_H = 536,
    .R_ADDRESS_L = 540,
    .R_DATA = 544,
},
  0,
  args
  ,  conf_target.mem
,  2
));
#endif // GET_CORE_CONSTRUCTOR
#ifdef GET_INCLUDES
#include "bridges/cpu_managed_stream.h"
#endif // GET_INCLUDES
#ifdef GET_MANAGED_STREAM_CONSTRUCTOR
registry.add_widget(new CPUManagedStreamWidget(
  simif,
  0,
  args
  ,  std::vector<CPUManagedStreams::StreamParameters>{}
,  std::vector<CPUManagedStreams::StreamParameters>{CPUManagedStreams::StreamParameters(
  std::string(R"ESC(TRACERVBRIDGEMODULE_0_to_cpu_stream)ESC"),
  0ULL,
  696ULL,
  6144,
  64
)}
));
#endif // GET_MANAGED_STREAM_CONSTRUCTOR
#ifdef GET_METASIM_INTERFACE_CONFIG
static constexpr TargetConfig conf_target{
.ctrl = AXI4Config{12, 25, 32},
.mem = AXI4Config{16, 34, 64},
.mem_num_channels = 1,
.cpu_managed = AXI4Config{6, 64, 512},
.fpga_managed = std::nullopt,
.target_name = R"ESC(FireSim)ESC"
};
#undef GET_METASIM_INTERFACE_CONFIG
#endif // GET_METASIM_INTERFACE_CONFIG
