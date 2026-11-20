// External CPU-only observer. The generated model and every target input are
// read-only. Only this replacement main is compiled; the original archive is reused.
#include "verilated.h"
#include "verilated_vpi.h"
#include "Vemul.h"
#include "Vemul___024root.h"
#include "Vemul_GHBarrierLatencyStats.h"
#include <cstdio>
#include <cstdlib>
#include <cinttypes>
#include <string>
#include <unistd.h>
#define BOOM(x) r.emul__DOT__FPGATop__DOT__sim__DOT__target__DOT__FireSim___DOT__lazyModule__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__##x
#define SYS(x) r.emul__DOT__FPGATop__DOT__sim__DOT__target__DOT__FireSim___DOT__lazyModule__DOT__system__DOT__##x
#define CLOCK(x) r.emul__DOT__FPGATop__DOT__sim__DOT__target__DOT__FireSim___DOT__##x
extern "C" void (*vlog_startup_routines[])() VL_ATTR_WEAK;

struct Snapshot {
    bool clk, reset_n, perf_reset, alloc;
    uint32_t alloc_seq;
    uint64_t fastest, csr, completed, passed, failed, cancelled, dropped;
    bool accepted[4];
    uint64_t payload[4];
};
static Snapshot capture(const Vemul___024root& r) {
    Snapshot s{};
    s.clk=CLOCK(clockBridge_clocks_0_buffer_O);
    s.reset_n=SYS(resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0);
    s.perf_reset=BOOM(ghe_debug_perf_ctrl)&1U;
    s.alloc=BOOM(core__DOT__ic_master__DOT__packet_alloc_valid_reg);
    s.alloc_seq=BOOM(core__DOT__ic_master__DOT__packet_alloc_seq_reg);
    s.fastest=r.emul__DOT__FPGATop__DOT__ClockBridgeModule_0__DOT__tCycleFastest;
    s.csr=r.__PVT__emul__DOT__FPGATop__DOT__sim__DOT__target__DOT__FireSim___DOT__lazyModule__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__crossPackageBarrierStats->io_currentCycle;
    s.completed=BOOM(dcache__DOT__completedPackages);
    s.passed=BOOM(dcache__DOT__passedPackages);
    s.failed=BOOM(dcache__DOT__failedPackages);
    s.cancelled=BOOM(dcache__DOT__cancelledPackages);
    s.dropped=BOOM(dcache__DOT__packageResultDropped);
    s.accepted[0]=BOOM(dcache__DOT__resultAccepted_0);
    s.accepted[1]=BOOM(dcache__DOT__resultAccepted_1);
    s.accepted[2]=BOOM(dcache__DOT__resultAccepted_2);
    s.accepted[3]=BOOM(dcache__DOT__resultAccepted_3);
    s.payload[0]=BOOM(dcache_io___05Fchecker_results_0);
    s.payload[1]=BOOM(dcache_io___05Fchecker_results_1);
    s.payload[2]=BOOM(dcache_io___05Fchecker_results_2);
    s.payload[3]=BOOM(dcache_io___05Fchecker_results_3);
    return s;
}
struct Observer {
    FILE* out=nullptr;
    std::string path;
    uint64_t edges=0, errors=0, allocations=0, accepted=0, records=0;
    uint64_t pass=0, fail=0, cancel=0, reset_edges=0, nonreset_edges=0;
    uint64_t last_fastest=0;
    explicit Observer(const char* p) {
        if(p && *p) {
            path=p; out=fopen(p,"wx");
            if(!out) {perror("observer open"); std::exit(90);}
            setvbuf(out,nullptr,_IOFBF,64*1024);
            fprintf(out,"{\"schema\":\"ec-gg-external-events/1\",\"kind\":\"HEADER\",\"scope\":\"CPU metasim BOOM input acceptance only\",\"functional_baseline\":\"8491167d84b6d9521b151a743673c1516926a1f8\"}\n");
        }
    }
    void error(const char* reason,uint64_t tick,uint64_t got,uint64_t expected) {
        ++errors;
        if(errors<101) fprintf(out,"{\"kind\":\"SAMPLE_ERROR\",\"record\":%" PRIu64 ",\"reason\":\"%s\",\"fastest_target_cycle\":%" PRIu64 ",\"got\":%" PRIu64 ",\"expected\":%" PRIu64 "}\n",++records,reason,tick,got,expected);
    }
    void after(const Snapshot& a,const Vemul___024root& r,uint64_t host_time) {
        const auto b=capture(r);
        // The generated model's actual BUFGCE output, not host-clock changes,
        // identifies each BOOM sampling edge. Pre-eval values are validated
        // against the corresponding post-edge state transitions on every edge.
        const bool edge=!a.clk && b.clk;
        if(!edge) {
            if(a.reset_n && b.reset_n && b.completed!=a.completed)
                error("completion_counter_changed_without_boom_edge",b.fastest,b.completed,a.completed);
            return;
        }
        ++edges; last_fastest=b.fastest;
        if(b.fastest!=a.fastest+1) error("base_counter_edge_alignment",b.fastest,b.fastest,a.fastest+1);
        if(!a.reset_n || !b.reset_n || a.perf_reset) {++reset_edges;return;}
        ++nonreset_edges;
        uint64_t n=0,np=0,nf=0,nc=0;
        for(unsigned i=0;i<4;++i) if(a.accepted[i]) {
            ++n;
            const unsigned status=(a.payload[i]>>32)&3;
            if(!(a.payload[i]>>34) || !(a.payload[i]&0xffffffffULL) || status==3)
                error("accepted_payload_invalid",b.fastest,a.payload[i],0);
            np+=status==0;nf+=status==1;nc+=status==2;
        }
        if(b.completed!=a.completed+n) error("accepted_vs_completion_counter",b.fastest,b.completed,a.completed+n);
        if(b.passed!=a.passed+np) error("accepted_vs_pass_counter",b.fastest,b.passed,a.passed+np);
        if(b.failed!=a.failed+nf) error("accepted_vs_fail_counter",b.fastest,b.failed,a.failed+nf);
        if(b.cancelled!=a.cancelled+nc) error("accepted_vs_cancel_counter",b.fastest,b.cancelled,a.cancelled+nc);
        if(n && BOOM(dcache__DOT__lastCheckerResultCycle)!=a.csr)
            error("accepted_cycle_vs_stored_timestamp",b.fastest,BOOM(dcache__DOT__lastCheckerResultCycle),a.csr);
        if(a.alloc) {
            ++allocations;
            fprintf(out,"{\"kind\":\"BOOM_ALLOC\",\"record\":%" PRIu64 ",\"fastest_target_cycle\":%" PRIu64 ",\"boom_csr_cycle\":%" PRIu64 ",\"host_time\":%" PRIu64 ",\"package_seq\":%u}\n",++records,b.fastest,a.csr,host_time,a.alloc_seq);
        }
        for(unsigned i=0;i<4;++i) if(a.accepted[i]) {
            ++accepted;
            fprintf(out,"{\"kind\":\"BOOM_RESULT_ACCEPTED\",\"record\":%" PRIu64 ",\"fastest_target_cycle\":%" PRIu64 ",\"boom_csr_cycle\":%" PRIu64 ",\"host_time\":%" PRIu64 ",\"checker\":%u,\"package_seq\":%u,\"status\":%u,\"raw_payload\":%" PRIu64 "}\n",++records,b.fastest,a.csr,host_time,i+1,unsigned(a.payload[i]&0xffffffffULL),unsigned((a.payload[i]>>32)&3),a.payload[i]);
        }
        pass+=np;fail+=nf;cancel+=nc;
        if((edges&1023)==0 || n || a.alloc) fflush(out);
    }
    void finish() {
        if(!out)return;
        fprintf(out,"{\"kind\":\"END\",\"record\":%" PRIu64 ",\"boom_edges\":%" PRIu64 ",\"last_fastest_target_cycle\":%" PRIu64 ",\"nonreset_edges\":%" PRIu64 ",\"reset_edges\":%" PRIu64 ",\"sample_errors\":%" PRIu64 ",\"allocations\":%" PRIu64 ",\"accepted\":%" PRIu64 ",\"passed\":%" PRIu64 ",\"failed\":%" PRIu64 ",\"cancelled\":%" PRIu64 "}\n",++records,edges,last_fastest,nonreset_edges,reset_edges,errors,allocations,accepted,pass,fail,cancel);
        fflush(out);fsync(fileno(out));fclose(out);out=nullptr;
    }
};
static Observer* exit_observer=nullptr;
static void external_observer_atexit() { if(exit_observer) exit_observer->finish(); }
int main(int argc,char** argv,char**) {
    Verilated::debug(0);
    const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};
    contextp->threads(1);contextp->commandArgs(argc,argv);
    const std::unique_ptr<Vemul> topp{new Vemul{contextp.get(),""}};
    Observer observer(std::getenv("EC_EXTERNAL_OBSERVER_FILE"));
    exit_observer=&observer;std::atexit(external_observer_atexit);
    if(vlog_startup_routines) for(auto routinep=&vlog_startup_routines[0];*routinep;routinep++)(*routinep)();
    VerilatedVpi::callCbs(cbStartOfSimulation);
    while(VL_LIKELY(!contextp->gotFinish())) {
        VerilatedVpi::callTimedCbs();
        VerilatedVpi::callCbs(cbNextSimTime);
        VerilatedVpi::callCbs(cbAtStartOfSimTime);
        Snapshot before{};
        if(observer.out)before=capture(*topp->rootp);
        topp->eval();
        if(observer.out)observer.after(before,*topp->rootp,contextp->time());
        VerilatedVpi::callValueCbs();
        VerilatedVpi::callCbs(cbAtEndOfSimTime);
        VerilatedVpi::callCbs(cbReadWriteSynch);
        VerilatedVpi::callCbs(cbReadOnlySynch);
        if(!topp->eventsPending())break;
        contextp->time(std::min(topp->nextTimeSlot(),VerilatedVpi::cbNextDeadline()));
    }
    topp->final();VerilatedVpi::callCbs(cbEndOfSimulation);
    observer.finish();exit_observer=nullptr;contextp->statsPrintSummary();return 0;
}
