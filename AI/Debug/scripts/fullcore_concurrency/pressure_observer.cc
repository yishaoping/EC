#define __wrap__ZN12VTestHarness9eval_stepEv observe_io_effect
#include "../rollback/io_effect_observer.cc"
#undef __wrap__ZN12VTestHarness9eval_stepEv
#define BOOM(name) r.TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__##name
#define HISTORY(name) r.TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__versionHistory__DOT__##name
extern "C" void __wrap__ZN12VTestHarness9eval_stepEv(VTestHarness* sim) {
 observe_io_effect(sim);auto& r=*sim->rootp;
 static FILE* f=[] {const char* name=std::getenv("PALIMPSEST_IRQ_LOG");FILE* p=name?std::fopen(name,"wx"):nullptr;
 if(!p){std::perror("pressure log");std::exit(2);}return p;}();
 const uint64_t tick=uint64_t(sc_time_stamp());
 if(tick>=54000 && tick<=130000 && tick%64==0 && sim->clock){
   std::fprintf(f,"CAPACITY_SEAL tick=%llu capacity=%u seq=%u seal=%llx ghm_seq=%u ghm_end=%u end_sent=%u count=%u\n",
     (unsigned long long)tick,unsigned(BOOM(core__DOT__capacityClosing)),
     unsigned(BOOM(core__DOT__ic_master__DOT__packet_alloc_seq_reg)),
     (unsigned long long)BOOM(producerSeals_1),
     unsigned(r.TestHarness__DOT__chiptop__DOT__system__DOT__ghm_receivedCount_seq),
     unsigned(r.TestHarness__DOT__chiptop__DOT__system__DOT__ghm_receivedCount_done),
     unsigned(r.TestHarness__DOT__chiptop__DOT__system__DOT__ghm_end_seq_sent),
     unsigned(r.TestHarness__DOT__chiptop__DOT__system__DOT__ghm_receivedCount_count));
   std::fflush(f);
 }
 const unsigned free=HISTORY(freeCount),state=HISTORY(state),capacity=BOOM(core__DOT__capacityClosing);
 const unsigned stop=BOOM(core__DOT___rollback_io_stop);
 const uint32_t seq=BOOM(core__DOT__ic_master__DOT__packet_alloc_seq_reg);
 static unsigned pf=99,pc=2,ps=2;static uint32_t pq=0;
 if(free==pf&&capacity==pc&&stop==ps&&seq==pq)return;
 std::fprintf(f,"HISTORY tick=%llu clock=%u free=%u state=%u capacity=%u stop=%u seq=%u\n",(unsigned long long)sc_time_stamp(),unsigned(sim->clock),free,state,capacity,stop,seq);
 std::fflush(f);pf=free;pc=capacity;ps=stop;pq=seq;
}
