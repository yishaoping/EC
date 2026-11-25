#include "VCSRShadowHarness.h"
#include "verilated.h"
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <initializer_list>
static VCSRShadowHarness d;
static void tick(){d.clock=0;d.eval();d.clock=1;d.eval();d.clock=0;d.eval();}
static void require(bool x,const char*s){if(!x){std::fprintf(stderr,"CSR_SHADOW_FAIL: %s\n",s);std::exit(1);}}
static void frame(bool cps,uint64_t scratch,uint64_t sscratch=0){
 uint64_t v[14]={0,8,0x80000144,scratch,0x800005e8,0,0,0,0,0,0,0,0,0};
 v[8]=sscratch;d.io_cps=cps;d.io_beat=1;
 for(unsigned i=0;i<7;++i){d.io_index=i+1;d.io_pair[0]=v[2*i];d.io_pair[1]=v[2*i]>>32;d.io_pair[2]=v[2*i+1];d.io_pair[3]=v[2*i+1]>>32;tick();}
 d.io_beat=0;tick();
}
static void write(unsigned mode,uint64_t value){d.io_mode=mode;d.io_address=0x340;d.io_data=value;d.io_write=1;tick();d.io_write=0;tick();}
static void bank_case(unsigned address,uint64_t value,uint64_t expected){
 d.io_mode=1;d.io_address=address;d.io_data=value;d.io_write=1;tick();d.io_write=0;tick();
 d.eval();require(d.io_read==expected,"normal replay read/write bank differs");
 d.io_mode=2;d.eval();require(d.io_read==expected,"handler replay sees another CSR bank");
 d.io_mode=0;d.io_data=0x8888;d.io_write=1;tick();d.io_write=0;tick();
 d.io_mode=2;d.eval();require(d.io_read==expected,"management CSR write leaked into replay bank");
}
static void compare(uint64_t scratch){frame(false,scratch);d.io_compare=1;bool error=false;unsigned n=0;for(;n<40&&!d.io_done;++n){error|=d.io_error;tick();}error|=d.io_error;require(d.io_done,"CSR compare did not finish");require(!error,"normal replay CSR write left stale architectural shadow");d.io_compare=0;tick();}
int main(int argc,char**argv){
 Verilated::commandArgs(argc,argv);d.io_operation=5;d.io_mode=0;d.io_write=0;d.io_address=0x340;d.io_data=0;d.io_beat=0;d.io_cps=0;d.io_index=0;d.io_pair=VlWide<4>{};d.io_compare=0;d.io_clear=0;
 d.reset=1;for(unsigned n=0;n<5;++n)tick();d.reset=0;tick();
 frame(true,0x80032f60);write(1,0);
 // Normal replay and handler replay must use the same modeled CSR bank.
 d.io_mode=2;d.eval();require(d.io_read==0,"normal CSR write did not reach shadow");compare(0);
 d.io_clear=1;tick();d.io_clear=0;frame(true,0x1234);
 write(0,0x8888);d.io_mode=2;d.eval();require(d.io_read==0x1234,"management write modified package shadow");
 write(2,0x5678);d.eval();require(d.io_read==0x5678,"privileged replay CSR write missing");compare(0x5678);
 d.io_clear=1;tick();d.io_clear=0;frame(true,0x1234);
 bank_case(0x340,0x123456789abcdef0ULL,0x123456789abcdef0ULL);
 bank_case(0x140,0x1234567887654321ULL,0x1234567887654321ULL);
 // Sv39 uses the actual MPRV translation control in ordinary replay.
 d.io_mode=1;d.io_address=0x300;d.io_data=1ULL<<17;d.io_write=1;tick();d.io_write=0;tick();
 require(d.io_physicalMprv,"normal mstatus write no longer controls physical MPRV");
 d.io_data=0;d.io_write=1;tick();d.io_write=0;tick();require(!d.io_physicalMprv,"MPRV did not clear");
 // Ordinary CPS seeds both scratch CSRs before the first replayed read.
 d.io_clear=1;tick();d.io_clear=0;
 d.io_mode=0;d.io_cps=1;d.io_index=8;d.io_beat=1;
 d.io_pair[0]=0x89abcdef;d.io_pair[1]=0x01234567;
 d.io_pair[2]=0x76543210;d.io_pair[3]=0xfedcba98;
 tick();d.io_beat=0;
 d.io_mode=1;d.io_address=0x340;d.eval();
 require(d.io_read==0x0123456789abcdefULL,"ordinary CPS did not seed mscratch");
 d.io_address=0x140;d.eval();
 require(d.io_read==0xfedcba9876543210ULL,"ordinary CPS did not seed sscratch");
 d.io_mode=0;d.eval();
 require(d.io_read==0x8888,"ordinary CPS modified management sscratch");
 // Every architectural scratch command uses CPS state even when the
 // physical management stack differs; ordinary physical writes still work.
 for(unsigned address: {0x340u,0x140u}) for(unsigned mode: {1u,2u}) {
   for(unsigned operation: {5u,6u,7u}) {
     const uint64_t oldValue=0x123456789abcdef0ULL, management=0x80032f60;
     const uint64_t operand=operation==5?0x8765432187654321ULL:0x00ff00ff00ff00ffULL;
     const uint64_t expected=operation==5?operand:operation==6?(oldValue|operand):(oldValue&~operand);
     d.io_operation=5;d.io_mode=0;d.io_address=address;d.io_data=management;d.io_write=1;tick();d.io_write=0;tick();
     d.io_clear=1;tick();d.io_clear=0;frame(true,oldValue,oldValue);
     d.io_mode=mode;d.io_address=address;d.eval();
     require(d.io_read==oldValue,"scratch RMW returned a stale pre-write value");
     d.io_data=operand;d.io_operation=operation;d.io_write=1;tick();d.io_write=0;tick();
     d.io_mode=2;d.eval();require(d.io_read==expected,"scratch W/S/C lost CPS-based architectural state");
     // A later management write cannot corrupt this package result.
     d.io_operation=5;d.io_mode=0;d.io_data=0x9999;d.io_write=1;tick();d.io_write=0;tick();
     d.io_mode=2;d.eval();require(d.io_read==expected,"management write leaked into scratch W/S/C result");
   }
 }
 // Supervisor scratch read-modify-write also reaches the real ECP comparator.
 d.io_operation=5;d.io_mode=0;d.io_address=0x140;d.io_data=0x8888;d.io_write=1;tick();d.io_write=0;tick();
 d.io_clear=1;tick();d.io_clear=0;frame(true,0,0x1234);
 d.io_mode=1;d.io_address=0x140;d.io_operation=6;d.io_data=0x80;d.io_write=1;tick();d.io_write=0;tick();
 frame(false,0,0x12b4);d.io_compare=1;bool failed=false;for(unsigned n=0;n<40&&!d.io_done;++n){failed|=d.io_error;tick();}failed|=d.io_error;
 require(d.io_done&&!failed,"supervisor scratch RMW ECP mismatch");d.io_compare=0;tick();
 std::puts("PALIMPSEST_CSR_SHADOW=PASS scratch_mirror=1 management_isolated=1 physical_mprv_preserved=1 scratch_commands=12 sscratch_ecp=1");d.final();return 0;
}
