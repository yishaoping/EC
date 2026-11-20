#include "TestHarness.h"
#include "bridges/clock.h"
#include <array>
#include <iostream>
#include <chrono>
#include <stdexcept>
class TestEntry final: public TestHarness {
 bool negative;
 using Data=std::array<uint32_t,3>;
 Data memory[512]{}; bool written[512]{};
 void mpz_data(mpz_t &v,Data d){mpz_set_ui(v,d[2]);mpz_mul_2exp(v,v,32);mpz_add_ui(v,v,d[1]);mpz_mul_2exp(v,v,32);mpz_add_ui(v,v,d[0]);}
public:
 TestEntry(widget_registry_t&r,const std::vector<std::string>&a,std::string_view n):TestHarness(r,a,n),negative(false){for(auto&x:a)if(x=="+negative")negative=true;}
 void run_test() override {
  log=false; poke("io_writeEnable",0); target_reset();
  mpz_t v;mpz_init(v);uint64_t checked=0,conflicts=0,resets=0,steps=0,skipped=0,sweep=0,digest=1469598103934665603ull;
  for(unsigned t=0;t<2048;t++) {
    bool resetNow=t>=512 && t<1536 && (t%173==0); resets+=resetNow;
    bool wen=t<1536 && (t<512 || (random()%4!=0));unsigned wa=t<512?t:random()%512;
    Data wd={uint32_t(random()),uint32_t(random()),uint32_t(random())&0x1ffffu};
    std::array<unsigned,35> ra; std::array<Data,35> old;
    for(unsigned i=0;i<35;i++){
      ra[i]=t>=1536?(t-1536):(i==0 || t%11==0)?wa:random()%512;conflicts+=wen&&ra[i]==wa;
      old[i]=written[ra[i]]?memory[ra[i]]:Data{};
      poke("io_address_"+std::to_string(i),ra[i]);
    }
    poke("reset",resetNow);poke("io_writeAddress",wa);mpz_data(v,wd);poke("io_writeData",v);poke("io_writeEnable",wen);
    step(1);steps++;
    if(resetNow){for(auto &x:written)x=false;}
    else if(wen){memory[wa]=wd;written[wa]=true;}
    for(unsigned i=0;i<35;i++){
      Data capture=resetNow?Data{}:old[i];
      if(negative && t==513 && i==0)capture[0]^=1;
      mpz_data(v,capture);if(!expect("io_captured_"+std::to_string(i),v)){std::cerr<<"ENTRY_CAPTURE_MISMATCH t="<<t<<" read="<<i<<"\n";return;}checked++;
      // The target declares read-under-write undefined. Do not turn a
      // same-cycle write conflict into an invented post-edge guarantee.
      // All pre-edge captures and all non-conflicting outputs remain checked.
      if(wen && !resetNow && ra[i]==wa) { skipped++; }
      else {
        Data after=written[ra[i]]?memory[ra[i]]:Data{};
        mpz_data(v,after);if(!expect("io_data_"+std::to_string(i),v)){std::cerr<<"ENTRY_ASYNC_MISMATCH t="<<t<<" read="<<i<<"\n";return;}checked++;
        for(auto w:after){digest^=w;digest*=1099511628211ull;}
      }
      for(auto w:capture){digest^=w;digest*=1099511628211ull;}
    }
    if(t>=1536)sweep++;
  }
  poke("reset",0);poke("io_writeEnable",0);
  auto&clk=get_bridge<clockmodule_t>();uint64_t h0=clk.hcycle();auto ts=std::chrono::steady_clock::now();step(4096);
  double wall=std::chrono::duration<double>(std::chrono::steady_clock::now()-ts).count();uint64_t hc=clk.hcycle()-h0;
  std::cout<<"ENTRY_RESULT {\"status\":\"PASS\",\"target_test_cycles\":"<<steps<<",\"sweep_addresses\":"<<sweep<<",\"undefined_async_skipped\":"<<skipped<<",\"checked_values\":"<<checked<<",\"read_write_conflicts\":"<<conflicts<<",\"reset_cycles\":"<<resets<<",\"event_digest\":\""<<std::hex<<digest<<std::dec<<"\",\"throughput_target_cycles\":4096,\"throughput_host_cycles\":"<<hc<<",\"fmr_with_counter_overhead\":"<<double(hc)/4096<<",\"throughput_wall_seconds\":"<<wall<<",\"target_cycles_per_second\":"<<4096/wall<<"}\n";
  mpz_clear(v);
 }
};
TEST_MAIN(TestEntry)
