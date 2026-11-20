#include "TestHarness.h"
#include "bridges/clock.h"
#include <iostream>

class TestQueue final : public TestHarness {
  bool negative = false;
public:
  TestQueue(widget_registry_t &r, const std::vector<std::string> &a, std::string_view n)
      : TestHarness(r,a,n) {
    for (const auto &x : a) if (x == "+negative") negative = true;
  }
  void run_test() override {
    log = false;
    mpz_t input, a, b;
    mpz_inits(input,a,b,nullptr);
    uint64_t full=0, stalled=0, payloads=0;
    poke("io_enqReset",0); poke("io_deqReset",0);
    poke("io_enqValid",0); poke("io_deqReady",0);
    poke("io_enqBits",input);
    target_reset(20);
    for (unsigned t=0;t<8192;++t) {
      const bool er=t>=4000 && t<4020, dr=t>=6000 && t<6020;
      unsigned phase=t%2048;
      bool ev=phase<1536 || (random()&3)!=0;
      bool ready=phase>=700 && (phase<1536 || (random()&3)!=0);
      poke("io_enqReset",er); poke("io_deqReset",dr);
      poke("io_enqValid",ev); poke("io_deqReady",ready);
      mpz_set_ui(input,0);
      for (int w=0;w<5;++w) {
        mpz_mul_2exp(input,input,64); mpz_add_ui(input,input,random());
      }
      mpz_fdiv_r_2exp(input,input,305);
      poke("io_enqBits",input);
      step(1);
      (void)peek_poke.peek("io_readyFlat",true);
      if (!expect(!peek_poke.timeout() && !peek_poke.unstable(),"precise host token")) return;
      auto rf=peek("io_readyFlat"), rl=peek("io_readyLocal");
      auto vf=peek("io_validFlat"), vl=peek("io_validLocal");
      if (negative && t==100) rl^=1;
      if (!expect(rf==rl && vf==vl,"same-cycle queue control")) {
        std::cerr << "LOCAL_CDC_HOST_MISMATCH token=" << t << "\n"; return;
      }
      if (vf) {
        peek("io_bitsFlat",a); peek("io_bitsLocal",b);
        if (!expect(mpz_cmp(a,b)==0,"same-cycle queue payload")) {
          std::cerr << "LOCAL_CDC_HOST_MISMATCH token=" << t << "\n"; return;
        }
        ++payloads;
      }
      full+=ev&&!rf; stalled+=vf&&!ready;
    }
    if (!expect(full>500 && stalled>500 && payloads>2000,"full, backpressure and payload coverage")) return;
    std::cout << "LOCAL_CDC_HOST_TOKEN_PASS tokens=8192 full=" << full
              << " stalled=" << stalled << " payloads=" << payloads << "\n";
    mpz_clears(input,a,b,nullptr);
  }
};
TEST_MAIN(TestQueue)
