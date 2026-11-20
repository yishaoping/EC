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
    .PRECISE_PEEKABLE = 604,
},
  0,
  args
  ,  std::map<std::string, peek_poke_t::Port, std::less<>>{std::make_pair(R"ESC(reset)ESC", peek_poke_t::Port{.address = 20ULL,.chunks = 1}),std::make_pair(R"ESC(io_writeEnable)ESC", peek_poke_t::Port{.address = 24ULL,.chunks = 1}),std::make_pair(R"ESC(io_writeData)ESC", peek_poke_t::Port{.address = 28ULL,.chunks = 3}),std::make_pair(R"ESC(io_writeAddress)ESC", peek_poke_t::Port{.address = 40ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_0)ESC", peek_poke_t::Port{.address = 44ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_1)ESC", peek_poke_t::Port{.address = 48ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_2)ESC", peek_poke_t::Port{.address = 52ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_3)ESC", peek_poke_t::Port{.address = 56ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_4)ESC", peek_poke_t::Port{.address = 60ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_5)ESC", peek_poke_t::Port{.address = 64ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_6)ESC", peek_poke_t::Port{.address = 68ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_7)ESC", peek_poke_t::Port{.address = 72ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_8)ESC", peek_poke_t::Port{.address = 76ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_9)ESC", peek_poke_t::Port{.address = 80ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_10)ESC", peek_poke_t::Port{.address = 84ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_11)ESC", peek_poke_t::Port{.address = 88ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_12)ESC", peek_poke_t::Port{.address = 92ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_13)ESC", peek_poke_t::Port{.address = 96ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_14)ESC", peek_poke_t::Port{.address = 100ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_15)ESC", peek_poke_t::Port{.address = 104ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_16)ESC", peek_poke_t::Port{.address = 108ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_17)ESC", peek_poke_t::Port{.address = 112ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_18)ESC", peek_poke_t::Port{.address = 116ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_19)ESC", peek_poke_t::Port{.address = 120ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_20)ESC", peek_poke_t::Port{.address = 124ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_21)ESC", peek_poke_t::Port{.address = 128ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_22)ESC", peek_poke_t::Port{.address = 132ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_23)ESC", peek_poke_t::Port{.address = 136ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_24)ESC", peek_poke_t::Port{.address = 140ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_25)ESC", peek_poke_t::Port{.address = 144ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_26)ESC", peek_poke_t::Port{.address = 148ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_27)ESC", peek_poke_t::Port{.address = 152ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_28)ESC", peek_poke_t::Port{.address = 156ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_29)ESC", peek_poke_t::Port{.address = 160ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_30)ESC", peek_poke_t::Port{.address = 164ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_31)ESC", peek_poke_t::Port{.address = 168ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_32)ESC", peek_poke_t::Port{.address = 172ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_33)ESC", peek_poke_t::Port{.address = 176ULL,.chunks = 1}),std::make_pair(R"ESC(io_address_34)ESC", peek_poke_t::Port{.address = 180ULL,.chunks = 1})}
,  std::map<std::string, peek_poke_t::Port, std::less<>>{std::make_pair(R"ESC(io_data_0)ESC", peek_poke_t::Port{.address = 184ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_1)ESC", peek_poke_t::Port{.address = 196ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_2)ESC", peek_poke_t::Port{.address = 208ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_3)ESC", peek_poke_t::Port{.address = 220ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_4)ESC", peek_poke_t::Port{.address = 232ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_5)ESC", peek_poke_t::Port{.address = 244ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_6)ESC", peek_poke_t::Port{.address = 256ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_7)ESC", peek_poke_t::Port{.address = 268ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_8)ESC", peek_poke_t::Port{.address = 280ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_9)ESC", peek_poke_t::Port{.address = 292ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_10)ESC", peek_poke_t::Port{.address = 304ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_11)ESC", peek_poke_t::Port{.address = 316ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_12)ESC", peek_poke_t::Port{.address = 328ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_13)ESC", peek_poke_t::Port{.address = 340ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_14)ESC", peek_poke_t::Port{.address = 352ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_15)ESC", peek_poke_t::Port{.address = 364ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_16)ESC", peek_poke_t::Port{.address = 376ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_17)ESC", peek_poke_t::Port{.address = 388ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_18)ESC", peek_poke_t::Port{.address = 400ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_19)ESC", peek_poke_t::Port{.address = 412ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_20)ESC", peek_poke_t::Port{.address = 424ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_21)ESC", peek_poke_t::Port{.address = 436ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_22)ESC", peek_poke_t::Port{.address = 448ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_23)ESC", peek_poke_t::Port{.address = 460ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_24)ESC", peek_poke_t::Port{.address = 472ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_25)ESC", peek_poke_t::Port{.address = 484ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_26)ESC", peek_poke_t::Port{.address = 496ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_27)ESC", peek_poke_t::Port{.address = 508ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_28)ESC", peek_poke_t::Port{.address = 520ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_29)ESC", peek_poke_t::Port{.address = 532ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_30)ESC", peek_poke_t::Port{.address = 544ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_31)ESC", peek_poke_t::Port{.address = 556ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_32)ESC", peek_poke_t::Port{.address = 568ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_33)ESC", peek_poke_t::Port{.address = 580ULL,.chunks = 3}),std::make_pair(R"ESC(io_data_34)ESC", peek_poke_t::Port{.address = 592ULL,.chunks = 3})}
));
#endif // GET_BRIDGE_CONSTRUCTOR
#ifdef GET_METASIM_INTERFACE_CONFIG
static constexpr TargetConfig conf_target{
.ctrl = AXI4Config{12, 25, 32},
.mem = AXI4Config{16, 34, 64},
.mem_num_channels = 0,
.cpu_managed = std::nullopt,
.fpga_managed = std::nullopt,
.target_name = R"ESC(Probe)ESC"
};
#undef GET_METASIM_INTERFACE_CONFIG
#endif // GET_METASIM_INTERFACE_CONFIG
