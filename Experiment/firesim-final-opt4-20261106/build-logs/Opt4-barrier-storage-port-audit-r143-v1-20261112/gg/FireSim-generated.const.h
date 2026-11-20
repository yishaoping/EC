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
    .INIT_DONE = 160,
    .PRESENCE_READ = 164,
    .PRESENCE_WRITE = 168,
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
    .hCycle_0 = 128,
    .hCycle_1 = 132,
    .hCycle_latch = 136,
    .tCycle_0 = 140,
    .tCycle_1 = 144,
    .tCycle_latch = 148,
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
    .PRECISE_PEEKABLE = 108,
},
  0,
  args
  ,  std::map<std::string, peek_poke_t::Port, std::less<>>{std::make_pair(R"ESC(reset)ESC", peek_poke_t::Port{.address = 20ULL,.chunks = 1}),std::make_pair(R"ESC(io_fatalProtocolError)ESC", peek_poke_t::Port{.address = 24ULL,.chunks = 1}),std::make_pair(R"ESC(io_currentCycle)ESC", peek_poke_t::Port{.address = 28ULL,.chunks = 2}),std::make_pair(R"ESC(io_safeWatermark)ESC", peek_poke_t::Port{.address = 36ULL,.chunks = 1}),std::make_pair(R"ESC(io_event_bits)ESC", peek_poke_t::Port{.address = 40ULL,.chunks = 1}),std::make_pair(R"ESC(io_event_valid)ESC", peek_poke_t::Port{.address = 44ULL,.chunks = 1}),std::make_pair(R"ESC(io_resetStats)ESC", peek_poke_t::Port{.address = 48ULL,.chunks = 1})}
,  std::map<std::string, peek_poke_t::Port, std::less<>>{std::make_pair(R"ESC(io_statsValid)ESC", peek_poke_t::Port{.address = 52ULL,.chunks = 2}),std::make_pair(R"ESC(io_safeCycleSum)ESC", peek_poke_t::Port{.address = 60ULL,.chunks = 2}),std::make_pair(R"ESC(io_requestCycleSum)ESC", peek_poke_t::Port{.address = 68ULL,.chunks = 2}),std::make_pair(R"ESC(io_dropped)ESC", peek_poke_t::Port{.address = 76ULL,.chunks = 2}),std::make_pair(R"ESC(io_pending)ESC", peek_poke_t::Port{.address = 84ULL,.chunks = 2}),std::make_pair(R"ESC(io_resolved)ESC", peek_poke_t::Port{.address = 92ULL,.chunks = 2}),std::make_pair(R"ESC(io_seen)ESC", peek_poke_t::Port{.address = 100ULL,.chunks = 2})}
));
#endif // GET_BRIDGE_CONSTRUCTOR
#ifdef GET_METASIM_INTERFACE_CONFIG
static constexpr TargetConfig conf_target{
.ctrl = AXI4Config{12, 25, 32},
.mem = AXI4Config{16, 34, 64},
.mem_num_channels = 0,
.cpu_managed = std::nullopt,
.fpga_managed = std::nullopt,
.target_name = R"ESC(Harness)ESC"
};
#undef GET_METASIM_INTERFACE_CONFIG
#endif // GET_METASIM_INTERFACE_CONFIG
