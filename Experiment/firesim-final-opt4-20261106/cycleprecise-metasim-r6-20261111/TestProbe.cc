#include "TestHarness.h"
#include "bridges/clock.h"
#include <array>
#include <chrono>
#include <iostream>
class TestProbe final: public TestHarness {
public: using TestHarness::TestHarness;
void run_test() override {
 log=false; target_reset(); mpz_t value;mpz_init(value);
 for(unsigned a=0;a<512;a++){
  poke("io_writeAddress",a);mpz_set_ui(value,0x10000000u+a);mpz_setbit(value,80);
  poke("io_writeData",value);poke("io_writeEnable",1);step(1);
 }
 poke("io_writeEnable",0);
 for(unsigned t=0;t<64;t++){
  std::array<unsigned,35> addresses;
  for(int i=0;i<35;i++){addresses[i]=random()%512;poke("io_address_"+std::to_string(i),addresses[i]);}
  step(1);
  for(int i=0;i<35;i++){mpz_set_ui(value,0x10000000u+addresses[i]);mpz_setbit(value,80);expect("io_data_"+std::to_string(i),value);}
 }
 auto &clk=get_bridge<clockmodule_t>();uint64_t host0=clk.hcycle();
 auto start=std::chrono::steady_clock::now();step(10000);
 double wall=std::chrono::duration<double>(std::chrono::steady_clock::now()-start).count();
 uint64_t hosts=clk.hcycle()-host0;
 std::cout<<"SPACE_TIME_RESULT {\"checked_values\":2240,\"free_target_cycles\":10000,\"measured_host_cycles\":"<<hosts<<",\"fmr_including_counter_read_overhead\":"<<double(hosts)/10000<<",\"free_step_wall_seconds\":"<<wall<<",\"target_cycles_per_second\":"<<10000/wall<<"}\n";
 mpz_clear(value);
}};
TEST_MAIN(TestProbe)
