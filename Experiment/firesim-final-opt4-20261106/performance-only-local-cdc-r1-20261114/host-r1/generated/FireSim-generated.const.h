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
    .INIT_DONE = 288,
    .PRESENCE_READ = 292,
    .PRESENCE_WRITE = 296,
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
    .hCycle_0 = 256,
    .hCycle_1 = 260,
    .hCycle_latch = 264,
    .tCycle_0 = 268,
    .tCycle_1 = 272,
    .tCycle_latch = 276,
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
    .PRECISE_PEEKABLE = 176,
},
  0,
  args
  ,  std::map<std::string, peek_poke_t::Port, std::less<>>{std::make_pair(R"ESC(reset)ESC", peek_poke_t::Port{.address = 20ULL,.chunks = 1}),std::make_pair(R"ESC(io_deqReady)ESC", peek_poke_t::Port{.address = 24ULL,.chunks = 1}),std::make_pair(R"ESC(io_enqBits)ESC", peek_poke_t::Port{.address = 28ULL,.chunks = 10}),std::make_pair(R"ESC(io_enqValid)ESC", peek_poke_t::Port{.address = 68ULL,.chunks = 1}),std::make_pair(R"ESC(io_deqReset)ESC", peek_poke_t::Port{.address = 72ULL,.chunks = 1}),std::make_pair(R"ESC(io_enqReset)ESC", peek_poke_t::Port{.address = 76ULL,.chunks = 1})}
,  std::map<std::string, peek_poke_t::Port, std::less<>>{std::make_pair(R"ESC(io_bitsLocal)ESC", peek_poke_t::Port{.address = 80ULL,.chunks = 10}),std::make_pair(R"ESC(io_bitsFlat)ESC", peek_poke_t::Port{.address = 120ULL,.chunks = 10}),std::make_pair(R"ESC(io_validLocal)ESC", peek_poke_t::Port{.address = 160ULL,.chunks = 1}),std::make_pair(R"ESC(io_validFlat)ESC", peek_poke_t::Port{.address = 164ULL,.chunks = 1}),std::make_pair(R"ESC(io_readyLocal)ESC", peek_poke_t::Port{.address = 168ULL,.chunks = 1}),std::make_pair(R"ESC(io_readyFlat)ESC", peek_poke_t::Port{.address = 172ULL,.chunks = 1})}
));
#endif // GET_BRIDGE_CONSTRUCTOR
#ifdef GET_METASIM_INTERFACE_CONFIG
static constexpr TargetConfig conf_target{
.ctrl = AXI4Config{12, 25, 32},
.mem = AXI4Config{16, 34, 64},
.mem_num_channels = 0,
.cpu_managed = std::nullopt,
.fpga_managed = std::nullopt,
.target_name = R"ESC(QueuePairHost)ESC"
};
#undef GET_METASIM_INTERFACE_CONFIG
#endif // GET_METASIM_INTERFACE_CONFIG
