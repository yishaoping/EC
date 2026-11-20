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
    .INIT_DONE = 1056,
    .PRESENCE_READ = 1060,
    .PRESENCE_WRITE = 1064,
},
  0,
  args
  ));
#endif // GET_CORE_CONSTRUCTOR
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
    .hCycle_0 = 1024,
    .hCycle_1 = 1028,
    .hCycle_latch = 1032,
    .tCycle_0 = 1036,
    .tCycle_1 = 1040,
    .tCycle_latch = 1044,
},
  0,
  args
  ));
#endif // GET_BRIDGE_CONSTRUCTOR
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
    .STEP = 12,
    .DONE = 16,
    .PRECISE_PEEKABLE = 528,
},
  0,
  args
  ,  std::map<std::string, peek_poke_t::Port, std::less<>>{std::make_pair(R"ESC(reset)ESC", peek_poke_t::Port{.address = 20ULL,.chunks = 1}),std::make_pair(R"ESC(io_fatalProtocolError)ESC", peek_poke_t::Port{.address = 24ULL,.chunks = 1}),std::make_pair(R"ESC(io_sequenceBaseline)ESC", peek_poke_t::Port{.address = 28ULL,.chunks = 1}),std::make_pair(R"ESC(io_safeWatermark)ESC", peek_poke_t::Port{.address = 32ULL,.chunks = 1}),std::make_pair(R"ESC(io_events_0_bits_packetSeq)ESC", peek_poke_t::Port{.address = 36ULL,.chunks = 1}),std::make_pair(R"ESC(io_events_0_bits_isStore)ESC", peek_poke_t::Port{.address = 40ULL,.chunks = 1}),std::make_pair(R"ESC(io_events_0_bits_size)ESC", peek_poke_t::Port{.address = 44ULL,.chunks = 1}),std::make_pair(R"ESC(io_events_0_bits_addr)ESC", peek_poke_t::Port{.address = 48ULL,.chunks = 2}),std::make_pair(R"ESC(io_events_0_valid)ESC", peek_poke_t::Port{.address = 56ULL,.chunks = 1}),std::make_pair(R"ESC(io_events_1_bits_packetSeq)ESC", peek_poke_t::Port{.address = 60ULL,.chunks = 1}),std::make_pair(R"ESC(io_events_1_bits_isStore)ESC", peek_poke_t::Port{.address = 64ULL,.chunks = 1}),std::make_pair(R"ESC(io_events_1_bits_size)ESC", peek_poke_t::Port{.address = 68ULL,.chunks = 1}),std::make_pair(R"ESC(io_events_1_bits_addr)ESC", peek_poke_t::Port{.address = 72ULL,.chunks = 2}),std::make_pair(R"ESC(io_events_1_valid)ESC", peek_poke_t::Port{.address = 80ULL,.chunks = 1}),std::make_pair(R"ESC(io_events_2_bits_packetSeq)ESC", peek_poke_t::Port{.address = 84ULL,.chunks = 1}),std::make_pair(R"ESC(io_events_2_bits_isStore)ESC", peek_poke_t::Port{.address = 88ULL,.chunks = 1}),std::make_pair(R"ESC(io_events_2_bits_size)ESC", peek_poke_t::Port{.address = 92ULL,.chunks = 1}),std::make_pair(R"ESC(io_events_2_bits_addr)ESC", peek_poke_t::Port{.address = 96ULL,.chunks = 2}),std::make_pair(R"ESC(io_events_2_valid)ESC", peek_poke_t::Port{.address = 104ULL,.chunks = 1}),std::make_pair(R"ESC(io_stop)ESC", peek_poke_t::Port{.address = 108ULL,.chunks = 1}),std::make_pair(R"ESC(io_start)ESC", peek_poke_t::Port{.address = 112ULL,.chunks = 1}),std::make_pair(R"ESC(io_resetStats)ESC", peek_poke_t::Port{.address = 116ULL,.chunks = 1})}
,  std::map<std::string, peek_poke_t::Port, std::less<>>{std::make_pair(R"ESC(io_idle)ESC", peek_poke_t::Port{.address = 120ULL,.chunks = 1}),std::make_pair(R"ESC(io_pending)ESC", peek_poke_t::Port{.address = 124ULL,.chunks = 2}),std::make_pair(R"ESC(io_error)ESC", peek_poke_t::Port{.address = 132ULL,.chunks = 2}),std::make_pair(R"ESC(io_statsValid)ESC", peek_poke_t::Port{.address = 140ULL,.chunks = 1}),std::make_pair(R"ESC(io_firstStoreCounters_0)ESC", peek_poke_t::Port{.address = 144ULL,.chunks = 2}),std::make_pair(R"ESC(io_firstStoreCounters_1)ESC", peek_poke_t::Port{.address = 152ULL,.chunks = 2}),std::make_pair(R"ESC(io_firstStoreCounters_2)ESC", peek_poke_t::Port{.address = 160ULL,.chunks = 2}),std::make_pair(R"ESC(io_firstStoreCounters_3)ESC", peek_poke_t::Port{.address = 168ULL,.chunks = 2}),std::make_pair(R"ESC(io_firstStoreCounters_4)ESC", peek_poke_t::Port{.address = 176ULL,.chunks = 2}),std::make_pair(R"ESC(io_firstStoreCounters_5)ESC", peek_poke_t::Port{.address = 184ULL,.chunks = 2}),std::make_pair(R"ESC(io_firstStoreCounters_6)ESC", peek_poke_t::Port{.address = 192ULL,.chunks = 2}),std::make_pair(R"ESC(io_firstStoreCounters_7)ESC", peek_poke_t::Port{.address = 200ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_0)ESC", peek_poke_t::Port{.address = 208ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_1)ESC", peek_poke_t::Port{.address = 216ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_2)ESC", peek_poke_t::Port{.address = 224ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_3)ESC", peek_poke_t::Port{.address = 232ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_4)ESC", peek_poke_t::Port{.address = 240ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_5)ESC", peek_poke_t::Port{.address = 248ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_6)ESC", peek_poke_t::Port{.address = 256ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_7)ESC", peek_poke_t::Port{.address = 264ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_8)ESC", peek_poke_t::Port{.address = 272ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_9)ESC", peek_poke_t::Port{.address = 280ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_10)ESC", peek_poke_t::Port{.address = 288ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_11)ESC", peek_poke_t::Port{.address = 296ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_12)ESC", peek_poke_t::Port{.address = 304ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_13)ESC", peek_poke_t::Port{.address = 312ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_14)ESC", peek_poke_t::Port{.address = 320ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_15)ESC", peek_poke_t::Port{.address = 328ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_16)ESC", peek_poke_t::Port{.address = 336ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_17)ESC", peek_poke_t::Port{.address = 344ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_18)ESC", peek_poke_t::Port{.address = 352ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_19)ESC", peek_poke_t::Port{.address = 360ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_20)ESC", peek_poke_t::Port{.address = 368ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_21)ESC", peek_poke_t::Port{.address = 376ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_22)ESC", peek_poke_t::Port{.address = 384ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_23)ESC", peek_poke_t::Port{.address = 392ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_24)ESC", peek_poke_t::Port{.address = 400ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_25)ESC", peek_poke_t::Port{.address = 408ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_26)ESC", peek_poke_t::Port{.address = 416ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_27)ESC", peek_poke_t::Port{.address = 424ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_28)ESC", peek_poke_t::Port{.address = 432ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_29)ESC", peek_poke_t::Port{.address = 440ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_30)ESC", peek_poke_t::Port{.address = 448ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_31)ESC", peek_poke_t::Port{.address = 456ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_32)ESC", peek_poke_t::Port{.address = 464ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_33)ESC", peek_poke_t::Port{.address = 472ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_34)ESC", peek_poke_t::Port{.address = 480ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_35)ESC", peek_poke_t::Port{.address = 488ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_36)ESC", peek_poke_t::Port{.address = 496ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_37)ESC", peek_poke_t::Port{.address = 504ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_38)ESC", peek_poke_t::Port{.address = 512ULL,.chunks = 2}),std::make_pair(R"ESC(io_counters_39)ESC", peek_poke_t::Port{.address = 520ULL,.chunks = 2})}
));
#endif // GET_BRIDGE_CONSTRUCTOR
#ifdef GET_METASIM_INTERFACE_CONFIG
static constexpr TargetConfig conf_target{
.ctrl = AXI4Config{12, 25, 32},
.mem = AXI4Config{16, 34, 64},
.mem_num_channels = 0,
.cpu_managed = std::nullopt,
.fpga_managed = std::nullopt,
.target_name = R"ESC(CompleteHost)ESC"
};
#undef GET_METASIM_INTERFACE_CONFIG
#endif // GET_METASIM_INTERFACE_CONFIG
