#include "TestHarness.h"
#include "bridges/clock.h"
#include <array>
#include <fstream>
#include <iostream>
#include <chrono>
class TestEntry final:public TestHarness{
 bool negative;
 public:TestEntry(widget_registry_t&r,const std::vector<std::string>&a,std::string_view n):TestHarness(r,a,n),negative(false){for(auto&x:a)if(x=="+negative")negative=true;}
 void run_test()override{
 log=false;std::ifstream file("/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-dcache-entry-r3-20261111/target-cycles.txt");std::string word;uint64_t seq,checked=0,skipped=0,rows=0,digest=1469598103934665603ull;
 const std::array<std::string,39>inputs={"reset","io_address_0","io_address_1","io_address_2","io_address_3","io_address_4","io_address_5","io_address_6","io_address_7","io_address_8","io_address_9","io_address_10","io_address_11","io_address_12","io_address_13","io_address_14","io_address_15","io_address_16","io_address_17","io_address_18","io_address_19","io_address_20","io_address_21","io_address_22","io_address_23","io_address_24","io_address_25","io_address_26","io_address_27","io_address_28","io_address_29","io_address_30","io_address_31","io_address_32","io_address_33","io_address_34","io_writeAddress","io_writeData","io_writeEnable"};const std::array<std::string,70>outputs={"io_data_0","io_data_1","io_data_2","io_data_3","io_data_4","io_data_5","io_data_6","io_data_7","io_data_8","io_data_9","io_data_10","io_data_11","io_data_12","io_data_13","io_data_14","io_data_15","io_data_16","io_data_17","io_data_18","io_data_19","io_data_20","io_data_21","io_data_22","io_data_23","io_data_24","io_data_25","io_data_26","io_data_27","io_data_28","io_data_29","io_data_30","io_data_31","io_data_32","io_data_33","io_data_34","io_captured_0","io_captured_1","io_captured_2","io_captured_3","io_captured_4","io_captured_5","io_captured_6","io_captured_7","io_captured_8","io_captured_9","io_captured_10","io_captured_11","io_captured_12","io_captured_13","io_captured_14","io_captured_15","io_captured_16","io_captured_17","io_captured_18","io_captured_19","io_captured_20","io_captured_21","io_captured_22","io_captured_23","io_captured_24","io_captured_25","io_captured_26","io_captured_27","io_captured_28","io_captured_29","io_captured_30","io_captured_31","io_captured_32","io_captured_33","io_captured_34"};
 mpz_t value,got;mpz_init(value);mpz_init(got);
 while(file>>std::dec>>seq){
  if(seq!=rows){expect(false,"trace sequence");return;}
  for(auto&name:inputs){file>>word;mpz_set_str(value,word.c_str(),16);poke(name,value);}
  // A narrow peek waits on stable peeks before reading the wide MMIO words.
  (void)peek("io_data_0");
  std::array<std::string,70>expected;std::array<unsigned,70>valid;
  for(auto&x:expected)file>>x;for(auto&x:valid)file>>x;
  for(unsigned i=0;i<70;i++){
   if(!valid[i]){skipped++;continue;}
   mpz_set_str(value,expected[i].c_str(),16);if(negative&&seq==10&&i==0)mpz_combit(value,0);
   peek(outputs[i],got);
   if(mpz_cmp(got,value)){std::cerr<<"ENTRY_TRACE_MISMATCH cycle="<<seq<<" port="<<outputs[i]<<" expected="<<mpz_get_str(nullptr,16,value)<<" actual="<<mpz_get_str(nullptr,16,got)<<"\n";expect(false,"target-boundary comparison");return;}
   for(auto ch:expected[i]){digest^=uint8_t(ch);digest*=1099511628211ull;}checked++;
  }
  step(1);rows++;
 }
 // Benchmark only repeated stable no-write input tokens, outside trace checks.
 auto&clk=get_bridge<clockmodule_t>();uint64_t h0=clk.hcycle();auto ts=std::chrono::steady_clock::now();
 for(unsigned i=0;i<512;i++){
  for(auto&name:inputs){mpz_set_ui(value,0);poke(name,value);}step(1);
 }
 double wall=std::chrono::duration<double>(std::chrono::steady_clock::now()-ts).count();uint64_t hc=clk.hcycle()-h0;
 std::cout<<"ENTRY_RESULT {\"status\":\"PASS\",\"target_test_cycles\":"<<rows<<",\"checked_values\":"<<checked<<",\"undefined_values_skipped\":"<<skipped<<",\"event_digest\":\""<<std::hex<<digest<<std::dec<<"\",\"throughput_target_cycles\":512,\"throughput_host_cycles\":"<<hc<<",\"fmr_including_peekpoke_io\":"<<double(hc)/512<<",\"throughput_wall_seconds\":"<<wall<<",\"target_cycles_per_second\":"<<512/wall<<"}\n";
 mpz_clear(value);mpz_clear(got);
 }
};TEST_MAIN(TestEntry)
