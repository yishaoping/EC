#include "VGHM.h"
#include "verilated.h"
#include <iostream>
#include <stdexcept>
struct Test {
 VerilatedContext ctx;VGHM d{&ctx};int phase=0;int beats=0,anchors=0;bool pause=false;
 void require(bool v,const char*m){if(!v)throw std::runtime_error(m);}
 template<class W> void bits(W &w,int lo,int width,uint64_t value){for(int k=0;k<width;k++){auto &word=w[(lo+k)/32];unsigned mask=1u<<((lo+k)%32);word=(word&~mask)|((value>>k&1)?mask:0);}}
 template<class W> uint64_t get(W &w,int lo,int width){uint64_t v=0;for(int k=0;k<width;k++)v|=uint64_t(w[(lo+k)/32]>>((lo+k)%32)&1)<<k;return v;}
 void step(){d.clock=0;d.io_ghm_clock_0=0;d.io_ghm_clock_1=0;d.io_ghm_clock_2=0;d.io_ghm_clock_3=0;d.io_ghm_clock_4=0;d.eval();bool ck=(phase++%2)==0&&!pause;if(ck&&get(d.io_ghm_packet_outs_0,304,1)&&(d.io_ghe_event_in_0&16)){if(get(d.io_ghm_packet_outs_0,128,8)){beats++;}else anchors++;}d.clock=1;d.io_ghm_clock_0=1;d.io_ghm_clock_1=ck;d.io_ghm_clock_2=ck;d.io_ghm_clock_3=ck;d.io_ghm_clock_4=ck;d.eval();ctx.timeInc(1);}
 void cycles(int n){while(n--)step();}
 void reset(){
  beats=0; anchors=0; phase=0; pause=false;
#include "../ghm_init.h"
  d.reset=1;d.io_ghm_reset_0=1;d.io_ghm_reset_1=1;d.io_ghm_reset_2=1;d.io_ghm_reset_3=1;d.io_ghm_reset_4=1;cycles(12);d.reset=0;d.io_ghm_reset_0=0;d.io_ghm_reset_1=0;d.io_ghm_reset_2=0;d.io_ghm_reset_3=0;d.io_ghm_reset_4=0;cycles(20);}
 void allocate(int seq,int count){bits(d.io_checker_segment_id_bigcore_0,32,32,seq);bits(d.io_ic_counter_0,16,16,count);d.io_ic_status_bigcore_0=2;d.io_checker_big_owner_bigcore_0=16;d.io_ghm_status_in_0=0x80000000;}
 void seal(int seq,int count){bits(d.io_ic_counter_0,16,16,0x8000|count);bits(d.io_producer_seal_bigcore_0,33,33,(1ull<<32)|seq);}
 unsigned count(){return d.io_icsl_counter_0&0xffff;}
 void send(unsigned payload){for(int k=0;d.io_bigcore_hang_0&&k<2000;k++)step();require(!d.io_bigcore_hang_0,"source backpressure never released");bits(d.io_ghm_packet_in_0,0,32,payload);bits(d.io_ghm_packet_in_0,128,8,0x8a);step();bits(d.io_ghm_packet_in_0,0,32,0);bits(d.io_ghm_packet_in_0,128,8,0);}
 void run(){reset();allocate(1,558);d.io_ghe_event_in_0=0;for(int i=0;i<5;i++)send(i+1);cycles(300);require(count()==558,"live count not published while status zero");seal(1,600);cycles(180);require(count()==600,"live final progress failed");require(!(count()&0x8000),"END overtook blocked real data");d.io_ghe_event_in_0=16;
  for(int k=0;k<100&&beats<5;k++)step();require(beats==5,"data missing before END");d.io_ghe_event_in_0=0;cycles(80);require(count()==0x8258,"END incorrectly depends on consumer ready or wrong count");require(d.io_producer_sealed_out_0==((1ull<<32)|1),"seal seq mismatch");require(d.io_ghm_cdc_empty_out_0,"local tail not drained");bits(d.io_ic_counter_0,16,16,1);cycles(160);require(count()==0x8258,"late live count rolled final backwards");std::cout<<"PASS ordered END / blocked data / sticky final / status-zero progress\n";
  // A zero-length next package must still deliver an anchor before END.
  bits(d.io_checker_segment_id_bigcore_0,32,32,0);bits(d.io_producer_seal_bigcore_0,33,33,0);bits(d.io_ic_counter_0,16,16,0);cycles(100);allocate(2,0);seal(2,0);cycles(180);require(count()==0,"zero live sample lost or END bypassed anchor");int oldanchors=anchors;d.io_ghe_event_in_0=16;for(int k=0;k<100&&anchors==oldanchors;k++)step();require(anchors==oldanchors+1,"no empty startup anchor");d.io_ghe_event_in_0=0;cycles(80);require(count()==0x8000,"zero final was not valid");require((d.io_icsl_counter_0>>20&0xffffffff)==2,"new count identity lost");std::cout<<"PASS zero-count anchor before END / slot reuse\n";
  // Old checker stays sealed while another checker owns a newer package.
  bits(d.io_checker_segment_id_bigcore_0,64,32,3);bits(d.io_ic_counter_0,32,16,0x8000);bits(d.io_producer_seal_bigcore_0,66,33,(1ull<<32)|3);d.io_ghm_status_in_0=0;cycles(100);require(d.io_producer_sealed_out_0==((1ull<<32)|2)&&d.io_ghm_cdc_empty_out_0,"next package revoked old seal or local empty");std::cout<<"PASS per-slot seal / no global-empty dependency\n";
  // Full live-count CDC: pause checker clock, then recover latest progress.
  reset();allocate(1,1);d.io_ghe_event_in_0=16;cycles(100);pause=true;for(int i=2;i<=200;i++){bits(d.io_ic_counter_0,16,16,i);step();}pause=false;cycles(600);require(count()==200,"backpressured live count lost latest progress");seal(1,200);cycles(100);require(count()==(0x8000|200),"final lost after control CDC backpressure");std::cout<<"PASS count CDC full / independent clocks / recovery\n";
  // Cancel/reuse while old END is held behind a completely full data queue.
  reset();allocate(1,256);int queued=0;
  for(int k=0;k<256&&!d.io_bigcore_hang_0;k++){send(k+1);queued++;}
  require(d.io_bigcore_hang_0,"did not fill data CDC");seal(1,256);cycles(10);
  bits(d.io_checker_segment_id_bigcore_0,32,32,0);bits(d.io_producer_seal_bigcore_0,33,33,0);cycles(2);allocate(2,5);cycles(300);
  require(count()==5&&(d.io_icsl_counter_0>>20&0xffffffff)==2,"next live seq not delivered");
  d.io_ghe_event_in_0=16;cycles(800);require(beats==queued,"cancel tail records lost");require(count()==5,"stale END overwrote reused count");
  seal(2,5);cycles(100);require(count()==0x8005&&d.io_producer_sealed_out_0==((1ull<<32)|2),"END stuck after cancellation/reuse");
  std::cout<<"PASS END held over source release / full data CDC / stale END vs new live seq\n";
 }
};
int main(int argc,char**argv){Verilated::commandArgs(argc,argv);try{Test t;t.run();return 0;}catch(std::exception&e){std::cerr<<"FAIL "<<e.what()<<"\n";return 1;}}
