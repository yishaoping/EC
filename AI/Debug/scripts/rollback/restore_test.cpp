#include "VRestoreHarness.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <initializer_list>
static VRestoreHarness d;
static void check(bool c,const char*w){if(!c){std::fprintf(stderr,"FAIL: %s\n",w);std::exit(1);}}
static void tick(){d.clock=0;d.eval();d.clock=1;d.eval();d.clock=0;d.eval();}
int main(int argc,char**argv){
  Verilated::commandArgs(argc,argv);d.io_restore=0;d.io_seed=0;d.io_address=0;
  d.reset=1;for(int i=0;i<4;++i)tick();d.reset=0;tick();
  for(uint64_t seed:{0x123456789abcdef0ULL,0xfedcba9876543210ULL}){
    d.io_seed=seed;d.io_restore=1;
    for(int i=0;i<33;++i){check(!d.io_done,"done preceded last PRF write");tick();}
    check(d.io_done,"missing actual PRF done");
    for(unsigned p=0;p<=32;++p){d.io_address=p;tick();
      check(d.io_data==(p?seed^((p-1)*0x101ULL):0ULL),"PRF import mapping/data mismatch");}
    for(unsigned p=1;p<=32;++p){d.io_address=p;tick();
      check(d.io_fpData==(seed^((p-1)*0x101ULL)),"recoded FP import lost f0/f31/data");}
    for(int i=0;i<7;++i){tick();check(d.io_done,"done dropped before request release");}
    d.io_restore=0;tick();check(!d.io_done,"new restore inherited old done");
  }
  std::puts("PALIMPSEST_RESTORE_COMPONENT=PASS");d.final();
}
