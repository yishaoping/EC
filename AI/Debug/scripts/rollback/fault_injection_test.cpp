#include "VFaultInjectionHarness.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>
static VFaultInjectionHarness d;
static void tick() { d.clock=0;d.eval();d.clock=1;d.eval();d.clock=0;d.eval(); }
static void require(bool ok, const char* msg) {
  if (!ok) { std::fprintf(stderr,"FAULT_INJECTION_FAIL: %s\n", msg); std::exit(1); }
}
static void package(unsigned seq, bool fail) {
  d.io_clear=1;tick();d.io_clear=0;d.io_seq=seq;d.io_start=1;tick();d.io_start=0;
  for (unsigned i=0;i<=32;++i) {
    d.io_beat=1;d.io_index=i;d.io_mainInt=0;d.io_mainFP=0;tick();
  }
  d.io_beat=0;tick();tick();require(d.io_complete,"ECP incomplete");
  d.io_compare=1;tick();d.io_compare=0;
  for (unsigned n=0;!d.io_done && n<100;++n) tick();
  require(d.io_done && bool(d.io_error)==fail,"wrong real comparator result");
  for (unsigned n=0;n<8;++n) { tick();require(d.io_done && bool(d.io_error)==fail,"result not held"); }
  d.io_ack=1;tick();d.io_ack=0;tick();require(!d.io_done,"ACK did not release");
}
int main(int argc,char** argv) {
  Verilated::commandArgs(argc,argv);
  d.io_start=0;d.io_seq=1;d.io_clear=0;d.io_beat=0;d.io_compare=0;d.io_ack=0;
  d.io_index=0;d.io_mainInt=0;d.io_mainFP=0;d.io_checkerF0=0;
  d.reset=1;for(unsigned n=0;n<5;++n)tick();d.reset=0;tick();
  package(7,false);package(8,true);package(8,false);
  package(23,false);package(24,true);package(24,false);package(25,false);
  std::puts("PALIMPSEST_FAULT_INJECTION=PASS failures=2 once_per_seq=1");
  d.final();return 0;
}
