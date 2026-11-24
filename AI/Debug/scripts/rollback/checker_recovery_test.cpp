#include "VCheckerRecoveryHarness.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>

class Test {
public:
  VCheckerRecoveryHarness d;
  unsigned cycles=0;
  bool freeze=false;
  void check(bool ok,const char *why) {
    if(!ok) { std::fprintf(stderr,"CHECKER_RECOVERY_FAIL cycle=%u: %s\n",cycles,why); std::exit(1); }
  }
  void tick() {
    d.clock=0;
    if(!freeze) d.io_checkerClock=(cycles/3)&1;
    d.eval(); d.clock=1; d.eval(); ++cycles; Verilated::timeInc(1);
    d.clock=0; d.eval();
    check(!Verilated::gotFinish(),"RTL assertion/finish");
    if(!d.reset) check(!d.io_fatal,"unexpected fatal recovery");
  }
  void ticks(unsigned n) { while(n--) tick(); }
  template<class F> void until(F predicate,const char *why) {
    unsigned n=3000;
    while(!predicate()&&n--) tick(); check(predicate(),why);
  }
  void reset() {
    freeze=false; d.io_checkerClock=0;
    d.io_capture=0; d.io_clear=0; d.io_start=0; d.io_beat=0; d.io_index=0;
    d.io_mainInt=0; d.io_mainFP=0; d.io_compare=0; d.io_resultEnable=0;
    d.io_releaseOwnership=0; d.io_quiesced=0; d.io_restoreDone=0; d.io_restartReady=0;
    d.reset=1; ticks(30); d.reset=0; ticks(60);
    d.io_capture=1; tick(); d.io_capture=0; ticks(2);
  }
  void compare(bool mismatch) {
    d.io_clear=1; ticks(6); d.io_clear=0;
    d.io_start=1; ticks(6); d.io_start=0;
    for(unsigned i=0;i<=32;++i) {
      d.io_beat=1; d.io_index=i;
      d.io_mainInt=i==0?0xffff:0; // x0 must not produce an error.
      d.io_mainFP=mismatch&&i==0?0x3ff0000000000000ULL:0;
      ticks(6);
    }
    d.io_beat=0; ticks(18); check(d.io_complete,"real ECP frame did not complete");
    d.io_compare=1; ticks(6); d.io_compare=0;
    until([&]{return bool(d.io_compared);},"production RSUSL comparator did not finish");
    check(bool(d.io_mismatch)==mismatch,"comparator f0 result is incorrect");
    ticks(60);
    check(!d.io_resultCount&&!d.io_stop,"result crossed GHM before local permission");
  }
  void pass() {
    reset(); compare(false); d.io_resultEnable=1;
    until([&]{return d.io_resultCount==1;},"PASS did not cross real GHM result CDC");
    check(d.io_resultSeq==8&&d.io_resultStatus==0,"PASS lost sequence/status");
    ticks(120);
    check(d.io_release&&d.io_owned&&!d.io_stop&&!d.io_epoch&&!d.io_restartCount,
      "PASS caused rollback or release was not held for Main ownership");
    d.io_releaseOwnership=1;
    until([&]{return !d.io_owned&&!d.io_release;},"GHM release did not complete its held handshake");
    ticks(120); check(d.io_resultCount==1&&!d.io_stop,"PASS result was duplicated");
  }
  void fail() {
    reset(); compare(true);
    freeze=true; d.io_resultEnable=1; ticks(120);
    check(!d.io_resultCount&&!d.io_stop,"result bypassed stopped Checker enqueue clock");
    freeze=false;
    until([&]{return d.io_stop&&d.io_resultCount==1&&d.io_epoch==1;},
      "real f0 mismatch/GHM result did not select SCP8 and publish EVT");
    check(d.io_resultSeq==8&&d.io_resultStatus==1&&d.io_dead8,"FAIL lost its sequenced invalidation");
    d.io_quiesced=1; ticks(90);
    check(d.io_release&&d.io_owned&&!d.io_restore,"restore bypassed suffix result ownership release");
    d.io_quiesced=0; d.io_releaseOwnership=1;
    until([&]{return !d.io_owned&&!d.io_release;},"FAIL did not release GHM/Main owner");
    ticks(60); check(!d.io_restore,"restore bypassed cache quiescence");
    d.io_quiesced=1;
    until([&]{return bool(d.io_restore);},"SCP restore did not follow explicit quiescence");
    check(d.io_restoredSeq==8&&d.io_pc==0x80000800ULL&&
      d.io_integer==0x80&&d.io_floating==0xf080,"wrong architectural SCP restore payload");
    ticks(90); check(!d.io_restartValid,"restart bypassed restore owner acknowledgement");
    d.io_restoreDone=1;
    until([&]{return bool(d.io_restartValid);},"completed restore did not offer restart");
    ticks(60); check(d.io_stop&&!d.io_restartCount,"restart ignored ready backpressure");
    d.io_restartReady=1;
    until([&]{return d.io_restartCount==1;},"restart did not handshake");
    d.io_restartReady=0; ticks(120);
    check(!d.io_stop&&d.io_epoch==1&&d.io_resultCount==1&&d.io_restartCount==1,
      "one mismatch caused duplicate result/EVT/restart");
  }
};
int main(int argc,char **argv) {
  Verilated::commandArgs(argc,argv);
  Test t; t.pass(); t.fail();
  std::puts("PALIMPSEST_CHECKER_RECOVERY=PASS (component join; Rocket/BOOM full-core still required)");
  t.d.final(); return 0;
}
