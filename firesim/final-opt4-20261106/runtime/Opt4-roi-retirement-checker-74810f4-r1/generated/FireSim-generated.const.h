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
    .INIT_DONE = 896,
    .PRESENCE_READ = 900,
    .PRESENCE_WRITE = 904,
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
    .STEP = 716,
    .DONE = 720,
    .PRECISE_PEEKABLE = 728,
},
  0,
  args
  ,  std::map<std::string, peek_poke_t::Port, std::less<>>{std::make_pair(R"ESC(reset)ESC", peek_poke_t::Port{.address = 724ULL,.chunks = 1})}
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
    .pulseLength = 912,
    .doneInit = 916,
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
    .in_bits = 256,
    .in_valid = 260,
    .in_ready = 264,
    .out_bits = 268,
    .out_valid = 272,
    .out_ready = 276,
    .step_size = 280,
    .done = 284,
    .start = 288,
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
    .out_bits = 736,
    .out_valid = 740,
    .out_ready = 744,
    .in_bits = 748,
    .in_valid = 752,
    .in_ready = 756,
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
    .initDone = 320,
    .traceEnable = 324,
    .hostTriggerPCStartHigh = 328,
    .hostTriggerPCStartLow = 332,
    .hostTriggerPCEndHigh = 336,
    .hostTriggerPCEndLow = 340,
    .hostTriggerCycleCountStartHigh = 344,
    .hostTriggerCycleCountStartLow = 348,
    .hostTriggerCycleCountEndHigh = 352,
    .hostTriggerCycleCountEndLow = 356,
    .hostTriggerStartInst = 360,
    .hostTriggerStartInstMask = 364,
    .hostTriggerEndInst = 368,
    .hostTriggerEndInstMask = 372,
    .triggerSelector = 376,
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
    .initDone = 384,
    .traceEnable = 388,
    .hostTriggerPCStartHigh = 392,
    .hostTriggerPCStartLow = 396,
    .hostTriggerPCEndHigh = 400,
    .hostTriggerPCEndLow = 404,
    .hostTriggerCycleCountStartHigh = 408,
    .hostTriggerCycleCountStartLow = 412,
    .hostTriggerCycleCountEndHigh = 416,
    .hostTriggerCycleCountEndLow = 420,
    .hostTriggerStartInst = 424,
    .hostTriggerStartInstMask = 428,
    .hostTriggerEndInst = 432,
    .hostTriggerEndInstMask = 436,
    .triggerSelector = 440,
},
  1,
  args
  ,  1
,  6144
,  1
,  ClockInfo{R"ESC(tileClockGroup_tile_1)ESC", 1, 2}
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
  2,
  args
  ,  2
,  6144
,  1
,  ClockInfo{R"ESC(tileClockGroup_tile_1)ESC", 1, 2}
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
    .initDone = 512,
    .traceEnable = 516,
    .hostTriggerPCStartHigh = 520,
    .hostTriggerPCStartLow = 524,
    .hostTriggerPCEndHigh = 528,
    .hostTriggerPCEndLow = 532,
    .hostTriggerCycleCountStartHigh = 536,
    .hostTriggerCycleCountStartLow = 540,
    .hostTriggerCycleCountEndHigh = 544,
    .hostTriggerCycleCountEndLow = 548,
    .hostTriggerStartInst = 552,
    .hostTriggerStartInstMask = 556,
    .hostTriggerEndInst = 560,
    .hostTriggerEndInstMask = 564,
    .triggerSelector = 568,
},
  3,
  args
  ,  3
,  6144
,  1
,  ClockInfo{R"ESC(tileClockGroup_tile_1)ESC", 1, 2}
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
    .initDone = 576,
    .traceEnable = 580,
    .hostTriggerPCStartHigh = 584,
    .hostTriggerPCStartLow = 588,
    .hostTriggerPCEndHigh = 592,
    .hostTriggerPCEndLow = 596,
    .hostTriggerCycleCountStartHigh = 600,
    .hostTriggerCycleCountStartLow = 604,
    .hostTriggerCycleCountEndHigh = 608,
    .hostTriggerCycleCountEndLow = 612,
    .hostTriggerStartInst = 616,
    .hostTriggerStartInstMask = 620,
    .hostTriggerEndInst = 624,
    .hostTriggerEndInstMask = 628,
    .triggerSelector = 632,
},
  4,
  args
  ,  4
,  6144
,  1
,  ClockInfo{R"ESC(tileClockGroup_tile_1)ESC", 1, 2}
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
    .hCycle_0 = 768,
    .hCycle_1 = 772,
    .hCycle_latch = 776,
    .tCycle_0 = 780,
    .tCycle_1 = 784,
    .tCycle_latch = 788,
},
  0,
  args
  ));
#endif // GET_BRIDGE_CONSTRUCTOR
#ifdef GET_INCLUDES
#include "bridges/synthesized_prints.h"
#endif // GET_INCLUDES
#ifdef GET_SUBSTRUCT_CHECKS
static_assert(offsetof(PRINTBRIDGEMODULE_struct, startCycleL) == 0 * sizeof(uint64_t), "invalid startCycleL");\
static_assert(offsetof(PRINTBRIDGEMODULE_struct, startCycleH) == 1 * sizeof(uint64_t), "invalid startCycleH");\
static_assert(offsetof(PRINTBRIDGEMODULE_struct, endCycleL) == 2 * sizeof(uint64_t), "invalid endCycleL");\
static_assert(offsetof(PRINTBRIDGEMODULE_struct, endCycleH) == 3 * sizeof(uint64_t), "invalid endCycleH");\
static_assert(offsetof(PRINTBRIDGEMODULE_struct, doneInit) == 4 * sizeof(uint64_t), "invalid doneInit");\
static_assert(offsetof(PRINTBRIDGEMODULE_struct, flushNarrowPacket) == 5 * sizeof(uint64_t), "invalid flushNarrowPacket");\
static_assert(sizeof(PRINTBRIDGEMODULE_struct) == 6 * sizeof(uint64_t), "invalid structure"); \

#endif // PRINTBRIDGEMODULE_checks
#ifdef GET_BRIDGE_CONSTRUCTOR
registry.add_widget(new synthesized_prints_t(
  simif,
  *registry.get_stream_engine(),
PRINTBRIDGEMODULE_struct{
    .startCycleL = 800,
    .startCycleH = 804,
    .endCycleL = 808,
    .endCycleH = 812,
    .doneInit = 816,
    .flushNarrowPacket = 820,
},
  0,
  args
  ,  std::vector<synthesized_prints_t::Print>{synthesized_prints_t::Print{.print_offset = 1,.format_string = R"ESC(EC_OPT4_ROI token=%x epoch=%x state=%x begin=%x end=%x generated=%x completed=%x passed=%x failed=%x cancelled=%x dropped=%x busy=%d faults=%x\n)ESC",.argument_widths = std::vector<unsigned>{64,
64,
64,
64,
64,
64,
64,
64,
64,
64,
64,
1,
64}}}
,  128
,  65534
,  5
,  6144
,  ClockInfo{R"ESC(buildtop_reference_clock)ESC", 1, 1}
));
#endif // GET_BRIDGE_CONSTRUCTOR
#ifdef GET_INCLUDES
#include "bridges/synthesized_prints.h"
#endif // GET_INCLUDES
#ifdef GET_SUBSTRUCT_CHECKS
static_assert(offsetof(PRINTBRIDGEMODULE_struct, startCycleL) == 0 * sizeof(uint64_t), "invalid startCycleL");\
static_assert(offsetof(PRINTBRIDGEMODULE_struct, startCycleH) == 1 * sizeof(uint64_t), "invalid startCycleH");\
static_assert(offsetof(PRINTBRIDGEMODULE_struct, endCycleL) == 2 * sizeof(uint64_t), "invalid endCycleL");\
static_assert(offsetof(PRINTBRIDGEMODULE_struct, endCycleH) == 3 * sizeof(uint64_t), "invalid endCycleH");\
static_assert(offsetof(PRINTBRIDGEMODULE_struct, doneInit) == 4 * sizeof(uint64_t), "invalid doneInit");\
static_assert(offsetof(PRINTBRIDGEMODULE_struct, flushNarrowPacket) == 5 * sizeof(uint64_t), "invalid flushNarrowPacket");\
static_assert(sizeof(PRINTBRIDGEMODULE_struct) == 6 * sizeof(uint64_t), "invalid structure"); \

#endif // PRINTBRIDGEMODULE_checks
#ifdef GET_BRIDGE_CONSTRUCTOR
registry.add_widget(new synthesized_prints_t(
  simif,
  *registry.get_stream_engine(),
PRINTBRIDGEMODULE_struct{
    .startCycleL = 832,
    .startCycleH = 836,
    .endCycleL = 840,
    .endCycleH = 844,
    .doneInit = 848,
    .flushNarrowPacket = 852,
},
  1,
  args
  ,  std::vector<synthesized_prints_t::Print>{synthesized_prints_t::Print{.print_offset = 1,.format_string = R"ESC(EC_OPT4_PACKAGE_RESULT hart=%d seq=%x status=%d full_compare=%d cancelled=%d\n)ESC",.argument_widths = std::vector<unsigned>{3,
32,
2,
1,
1}},
synthesized_prints_t::Print{.print_offset = 41,.format_string = R"ESC(EC_OPT4_PACKAGE_RESULT hart=%d seq=%x status=%d full_compare=%d cancelled=%d\n)ESC",.argument_widths = std::vector<unsigned>{3,
32,
2,
1,
1}},
synthesized_prints_t::Print{.print_offset = 81,.format_string = R"ESC(EC_OPT4_PACKAGE_BEGIN hart=%d seq=%x satp=%x prv=%d\n)ESC",.argument_widths = std::vector<unsigned>{3,
32,
64,
2}},
synthesized_prints_t::Print{.print_offset = 183,.format_string = R"ESC(EC_OPT4_PACKAGE_BEGIN hart=%d seq=%x satp=%x prv=%d\n)ESC",.argument_widths = std::vector<unsigned>{3,
32,
64,
2}},
synthesized_prints_t::Print{.print_offset = 285,.format_string = R"ESC(EC_OPT4_PACKAGE_RESULT hart=%d seq=%x status=%d full_compare=%d cancelled=%d\n)ESC",.argument_widths = std::vector<unsigned>{3,
32,
2,
1,
1}},
synthesized_prints_t::Print{.print_offset = 325,.format_string = R"ESC(EC_OPT4_PACKAGE_BEGIN hart=%d seq=%x satp=%x prv=%d\n)ESC",.argument_widths = std::vector<unsigned>{3,
32,
64,
2}},
synthesized_prints_t::Print{.print_offset = 427,.format_string = R"ESC(EC_OPT4_PACKAGE_BEGIN hart=%d seq=%x satp=%x prv=%d\n)ESC",.argument_widths = std::vector<unsigned>{3,
32,
64,
2}},
synthesized_prints_t::Print{.print_offset = 529,.format_string = R"ESC(EC_OPT4_PACKAGE_RESULT hart=%d seq=%x status=%d full_compare=%d cancelled=%d\n)ESC",.argument_widths = std::vector<unsigned>{3,
32,
2,
1,
1}}}
,  128
,  65534
,  6
,  6144
,  ClockInfo{R"ESC(tileClockGroup_tile_1)ESC", 1, 2}
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
    .W_ADDRESS_H = 640,
    .W_ADDRESS_L = 644,
    .W_LENGTH = 648,
    .ZERO_OUT_DRAM = 652,
    .W_DATA = 656,
    .ZERO_FINISHED = 660,
    .R_ADDRESS_H = 664,
    .R_ADDRESS_L = 668,
    .R_DATA = 672,
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
  864ULL,
  6144,
  64
),
CPUManagedStreams::StreamParameters(
  std::string(R"ESC(TRACERVBRIDGEMODULE_1_to_cpu_stream)ESC"),
  524288ULL,
  868ULL,
  6144,
  64
),
CPUManagedStreams::StreamParameters(
  std::string(R"ESC(TRACERVBRIDGEMODULE_2_to_cpu_stream)ESC"),
  1048576ULL,
  872ULL,
  6144,
  64
),
CPUManagedStreams::StreamParameters(
  std::string(R"ESC(TRACERVBRIDGEMODULE_3_to_cpu_stream)ESC"),
  1572864ULL,
  876ULL,
  6144,
  64
),
CPUManagedStreams::StreamParameters(
  std::string(R"ESC(TRACERVBRIDGEMODULE_4_to_cpu_stream)ESC"),
  2097152ULL,
  880ULL,
  6144,
  64
),
CPUManagedStreams::StreamParameters(
  std::string(R"ESC(PRINTBRIDGEMODULE_0_to_cpu_stream)ESC"),
  2621440ULL,
  884ULL,
  6144,
  64
),
CPUManagedStreams::StreamParameters(
  std::string(R"ESC(PRINTBRIDGEMODULE_1_to_cpu_stream)ESC"),
  3145728ULL,
  888ULL,
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
