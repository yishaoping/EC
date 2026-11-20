#include "TestHarness.h"
#include <iostream>
class TestQueue final:public TestHarness {
 bool negative=false;
public:
 TestQueue(widget_registry_t&r,const std::vector<std::string>&a,std::string_view n):TestHarness(r,a,n){for(auto&x:a)if(x=="+negative")negative=true;}
 void run_test() override {
  log=false;mpz_t input;mpz_init(input);poke("inputs",input);target_reset(20);
  unsigned full=0,stalled=0,payload=0;
  for(unsigned t=0;t<8192;++t){
   unsigned phase=t%2048;bool ev=phase<1800||(random()&1),ready=phase>=1200;
   bool er=t>=4000&&t<4020,dr=t>=6000&&t<6020;
   mpz_set_ui(input,random());mpz_mul_2exp(input,input,16);mpz_add_ui(input,input,random());mpz_fdiv_r_2exp(input,input,34);
   mpz_mul_2exp(input,input,4);mpz_add_ui(input,input,er|(dr<<1)|(ev<<2)|(ready<<3));
   poke("inputs",input);step(1);unsigned out=peek("outputs");bool eq=(out>>2)&1;
   if(negative&&t==100)eq=!eq;
   if(!expect(eq&&!peek_poke.timeout()&&!peek_poke.unstable(),"checker-to-BOOM result tokens")){
    std::cerr<<"RESULT_CDC_HOST_MISMATCH token="<<t<<"\n";return;
   }
   full+=ev&&!((out>>1)&1);stalled+=(out&1)&&!ready;payload+=out&1;
  }
  if(!expect(full>500&&stalled>500&&payload>2000,"result full/backpressure/payload coverage"))return;
  std::cout<<"RESULT_CDC_HOST_TOKEN_PASS tokens=8192 full="<<full<<" stalled="<<stalled<<" payload="<<payload<<"\n";
  mpz_clear(input);
 }
};
TEST_MAIN(TestQueue)
