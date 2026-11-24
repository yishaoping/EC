#include "VF0Harness.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>
static VF0Harness d;
static void tick() { d.clock=0;d.eval();d.clock=1;d.eval();d.clock=0;d.eval(); }
static void require(bool v,const char *s) { if(!v){std::fprintf(stderr,"F0_FAIL: %s\n",s);std::exit(1);} }
static void compare(unsigned mismatchIndex, bool expected) {
  d.io_clear=1;tick();d.io_clear=0; d.io_start=1;tick();d.io_start=0;
  for(unsigned i=0;i<=32;++i) {
    d.io_beat=1;d.io_index=i;d.io_mainInt=(i==0?0xffffULL:0);
    d.io_mainFP=(i==mismatchIndex?0x3ff0000000000000ULL:0);tick();
  }
  d.io_beat=0;tick();tick();require(d.io_complete,"ECP tail missing");
  d.io_checkerF0=0;d.io_compare=1;tick();d.io_compare=0;
  unsigned n=0;while(!d.io_done && n++<100)tick();
  require(d.io_done,"compare timeout"); require(bool(d.io_error)==expected,"f0/x0 comparison result");
  for(unsigned i=0;i<5;++i){tick();require(d.io_done,"result not held");}
  d.io_ack=1;tick();d.io_ack=0;tick();require(!d.io_done,"ACK did not release result");
}
int main(int argc,char **argv) {
  Verilated::commandArgs(argc,argv);
  d.io_start=0;d.io_clear=0;d.io_beat=0;d.io_index=0;
  d.io_seq=8;
  d.io_mainInt=0;d.io_mainFP=0;d.io_checkerF0=0;d.io_compare=0;d.io_ack=0;
  d.reset=1;for(int i=0;i<5;++i)tick();d.reset=0;tick();
  compare(99,false); // x0 transport/checker garbage is normalized.
  compare(0,true);   // Only f0 differs: the previously skipped comparison.
  compare(31,true);  // Terminal comparison must still contribute to FAIL.
  std::puts("PALIMPSEST_F0=PASS");d.final();return 0;
}
