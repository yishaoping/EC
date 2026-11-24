#include "VIoHarness.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>
static VIoHarness d;
static unsigned effects;
static void check(bool c,const char*w) {
  if(!c) { std::fprintf(stderr,"FAIL: %s effects=%u\n",w,effects); std::exit(1); }
}
static void tick() {
  d.clock=0; d.eval();
  if(!d.reset&&d.io_external&&d.io_externalReady) ++effects;
  d.clock=1; d.eval(); d.clock=0; d.eval();
  check(!Verilated::gotFinish(),"hardware assertion/finish");
}
static void request(unsigned seq) {
  d.io_seq=seq; d.io_request=1; d.eval();
  check(d.io_ready,"journal refused matching request"); tick(); d.io_request=0;
}
static void finish(unsigned kind) {
  const bool reads=kind!=1, writes=kind!=0;
  for(int i=0;i<6;++i) {
    tick(); check(reads?d.io_response:d.io_completed,"terminal not held");
    if(reads) check(d.io_result==0x1234,"device old value changed on replay");
    if(kind==2) check(!d.io_completed,"AMO terminal overtook held old-value response");
  }
  if(reads) {
    d.io_responseReady=1; tick(); d.io_responseReady=0;
    check(!d.io_response,"old-value response repeated after handshake");
  }
  if(writes) {
    for(int i=0;i<6;++i) { tick(); check(d.io_completed,"write terminal lost under backpressure"); }
    d.io_doneReady=1; tick(); d.io_doneReady=0;
  }
  tick(); check(!d.io_busy,"terminal owner did not retire");
}
static void mismatch(unsigned kind) {
  d.io_request=1; d.io_seq=9; d.io_address+=8;
  for(int i=0;i<5;++i) {
    tick(); check(!d.io_ready&&!d.io_external,"mismatching effect escaped journal");
    check(d.io_replayFault&&d.io_replayFaultSeq==9,"mismatch did not request SCP retry");
  }
  d.io_address-=8;
  if(kind!=0) {
    d.io_operand^=1;
    for(int i=0;i<5;++i) {
      tick(); check(!d.io_ready&&!d.io_external,"wrong operand replayed");
      check(d.io_replayFault&&d.io_replayFaultSeq==9,"wrong operand did not request SCP retry");
    }
    d.io_operand^=1;
  }
  d.io_request=0;
  d.eval(); check(!d.io_replayFault,"idle journal kept generating a retry");
}
int main(int argc,char**argv) {
  Verilated::commandArgs(argc,argv);
  // RD, WR and AMOADD.D: the AMO has independent read/write owners.
  for(unsigned kind=0;kind<3;++kind){
    effects=0;d.io_request=0;d.io_seq=8;d.io_safe=7;d.io_dead=0;
    d.io_write=kind==1;d.io_amo=kind==2;
    d.io_address=0x80000000;d.io_operand=0xabcd;d.io_externalReady=0;d.io_ack=0;
    d.io_input=0x1234;d.io_responseReady=0;d.io_doneReady=0;
    d.reset=1;for(int i=0;i<4;++i)tick();d.reset=0;tick();request(8);
    for(int i=0;i<9;++i){
      tick();check(d.io_external,"A valid dropped under backpressure");
      check(d.io_effectPending,"accepted device owner lost interrupt hold before A");
    }
    d.io_externalReady=1;tick();d.io_externalReady=0;
    d.io_dead=8; // FAIL8 while the real device ACK is still delayed
    for(int i=0;i<7;++i){
      tick();check(d.io_effectPending,"device owner lost interrupt hold before delayed D");
    }
    d.io_ack=1;tick();d.io_ack=0;finish(kind);
    check(d.io_effectPending&&!d.io_busy,"isolated journal lost its interrupt responsibility");
    mismatch(kind);
    request(9);for(int i=0;i<5;++i){tick();check(!d.io_external,"rollback duplicated device side effect");}
    finish(kind);check(effects==1,"exactly-once effect broken");
    d.io_dead=9;tick();request(10);finish(kind);
    check(effects==1,"second rollback duplicated external effect");
    d.io_safe=10;tick();check(!d.io_effectPending,"verified journal did not release interrupt hold");
    request(11);d.io_externalReady=1;tick();d.io_externalReady=0;
    d.io_ack=1;tick();d.io_ack=0;finish(kind);check(effects==2,"verified journal blocked next effect");
  }
  std::puts("PALIMPSEST_IO_COMPONENT=PASS");d.final();
}
