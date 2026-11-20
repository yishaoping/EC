#include "TestHarness.h"
#include "bridges/clock.h"
#include <array>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>

class TestBucket final:public TestHarness {
 bool negative=false;
 public:TestBucket(widget_registry_t&r,const std::vector<std::string>&a,std::string_view n):TestHarness(r,a,n){for(auto&x:a)if(x=="+negative")negative=true;}
 void run_test()override {
  log=false;
  std::ifstream f("/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-address-bucket-r2-20261112/target-cycles.txt");
  uint64_t seq,rows=0,checked=0,digest=1469598103934665603ull;
  std::string word;mpz_t x,got;mpz_init(x);mpz_init(got);
  auto input=[&](const std::string&n){f>>word;mpz_set_str(x,word.c_str(),16);poke(n,x);};
  while(f>>std::dec>>seq) {
   expect(seq==rows,"monotonic target trace sequence");
   input("reset");input("io_process");input("io_retire");input("io_retireIndex");input("io_resetStats");input("io_currentIndex");
   for(unsigned i=0;i<256;i++)input("io_enables_"+std::to_string(i));
   for(unsigned i=0;i<256;i++)input("io_processData_"+std::to_string(i));
   (void)peek("io_current"); // wait for the target snapshot before wide words
   for(unsigned i=0;i<258;i++) {
    f>>word;
    // The original non-reset payload is uninitialized only at first boundary.
    // First resetStats edge initializes all words, then no values are skipped.
    if(seq==0)continue;
    mpz_set_str(x,word.c_str(),16);if(negative&&seq==10&&i==0)mpz_combit(x,0);
    std::string n=i<256?"io_debug_"+std::to_string(i):(i==256?"io_current":"io_retiring");
    peek(n,got);
    if(mpz_cmp(x,got)){
     std::cerr<<"BUCKET_TRACE_MISMATCH cycle="<<seq<<" port="<<n<<" expected="<<mpz_get_str(nullptr,16,x)<<" actual="<<mpz_get_str(nullptr,16,got)<<"\n";
     expect(false,"exact address bucket target boundary");return;
    }
    for(auto c:word){digest^=uint8_t(c);digest*=1099511628211ull;}checked++;
   }
   step(1);rows++;
  }
  auto&clk=get_bridge<clockmodule_t>();auto h0=clk.hcycle();auto start=std::chrono::steady_clock::now();
  for(unsigned i=0;i<64;i++) step(1);
  auto hc=clk.hcycle()-h0;double wall=std::chrono::duration<double>(std::chrono::steady_clock::now()-start).count();
  std::cout<<"BUCKET_RESULT {\"status\":\"PASS\",\"target_cycles\":"<<rows<<",\"checked_values\":"<<checked<<",\"initial_uninitialized_values_skipped\":258,\"event_digest\":\""<<std::hex<<digest<<std::dec<<"\",\"throughput_target_cycles\":64,\"throughput_host_cycles\":"<<hc<<",\"FMR_including_bridge_io\":"<<double(hc)/64<<",\"throughput_wall_seconds\":"<<wall<<"}\n";
  mpz_clear(x);mpz_clear(got);
 }
};TEST_MAIN(TestBucket)
