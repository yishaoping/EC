#include "VStage3Harness.h"
#include "verilated.h"
#include <algorithm>
#include <array>
#include <cstdint>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <tuple>

using Line = std::array<uint64_t,8>;
// Must match aware [0,1), uncached [1,3), unaware coherent [3,4).
static constexpr int kCoherentSource=0, kUncachedSource=1, kPressureSource=2, kPeerSource=3;
struct Key { uint32_t gen=0, seq=0; uint16_t writer=0; bool valid=false; };
struct Upper { uint64_t addr; Line data; Key key; int op, param, source=kCoherentSource, beat=0; };
struct Reply { uint64_t addr=0, txn=0; Line data{}; int source=0, op=0, beat=0; bool commit=false; };
static Line bytes(uint64_t n) { Line d{}; for(unsigned i=0;i<8;++i) d[i]=n+0x101010101010101ULL*i; return d; }
static void check(bool ok, const std::string& why) { if(!ok) throw std::runtime_error(why); }

// No cache/gate model here: all admission, preservation, replacement, bank
// updates and receipts come from the production Scheduler and CacheCork.
struct Run {
  VStage3Harness t;
  uint64_t cycles=0, puts=0, grants=0, releases=0, reads=0, flushes=0, probes=0, writes=0, metas=0, memoryGets=0;
  uint32_t nextGen=1, nextSeq=1, watermark=0;
  bool holdWrites=false, memoryReady=true, flushing=false;
  uint64_t flushAddr=0;
  std::deque<Upper> aq, cq;
  std::deque<Reply> rq, wq, inject;
  std::deque<int> eq;
  std::map<uint64_t,Line> durable;
  std::set<std::pair<int,uint64_t>> issued;
  std::set<int> outstandingA;
  std::set<int> outstandingC;
  std::set<uint64_t> pendingProbes;
  std::map<uint64_t,int> probeSources;
  std::map<int,uint64_t> grantsBySource;
  uint32_t blockedPeerSeq=0;
  Reply assembling;
  int putBeat=0, grantBeat=0, readBeat=0;
  Line returned{};
  Key returnedKey{};
  std::string current;
  uint64_t lastVictimAddr=0, lastPutTxn=0;
  int lastPutSource=0;
  uint32_t sampledWatermark=0;
  unsigned validationAckRace=0,validationWriteRace=0;
  bool wasStalled=false;
  bool wasPending=false, wasBlocked=false;
  bool waitingFlush=false;
  bool flushReleaseIssued=false, flushReleaseSent=false, flushReleaseAck=false, flushCommitted=false;
  std::tuple<uint64_t,uint64_t,uint64_t,uint64_t,uint64_t> stalled;

  Key key(bool speculative=true) { return Key{nextGen++, speculative ? nextSeq++ : 0, 0, true}; }
  void validate(Key k) {
    watermark=std::max(watermark,k.seq);
    std::cout << "STAGE3_HOST VALIDATE case=" << current << " cycle=" << cycles
      << " gen=" << k.gen << " seq=" << k.seq << " watermark=" << watermark << std::endl;
  }
  void phase(const char* name,uint64_t addr=0) {
    std::cout << "CASE_PHASE case=" << current << " phase=" << name << " cycle=" << cycles
      << " addr=" << std::hex << addr << std::dec << std::endl;
  }
  void begin(const char* name) {
    current=name;
    std::cout << "CASE_BEGIN " << current << " cycle=" << cycles << std::endl;
  }
  void pass(const char* name) {
    // Keep the checker-facing CASE line exact; context is a separate event.
    phase(name);
    std::cout << "CASE " << name << " PASS" << std::endl;
  }
  bool drained() const {
    return !t.io_active&&!t.io_pending&&aq.empty()&&cq.empty()&&rq.empty()&&wq.empty()&&eq.empty()&&inject.empty()&&
      outstandingA.empty()&&outstandingC.empty()&&pendingProbes.empty()&&!flushing&&!putBeat&&!grantBeat&&!readBeat;
  }
  void waitSnapshot(const char* why) {
    if(flushing || waitingFlush || t.io_flushStatus_active) {
      const bool active=t.io_flushStatus_active, meta=active&&t.io_flushStatus_metaValid;
      const bool safe=!t.io_flushStatus_image_valid || !t.io_flushStatus_image_contentSeq ||
        t.io_flushStatus_image_contentSeq<=watermark;
      const char* blocker=flushing?"REQUEST_NOT_ACCEPTED":!active?"NO_ACTIVE_FLUSH_OR_RESPONSE":
        !meta?"DIRECTORY_LOOKUP":!t.io_flushStatus_probeAckLast?"INNER_PROBE_ACK_LAST":
        !safe?"VALIDATION":t.io_pending?"PRESERVATION_PENDING":
        !t.io_flushStatus_releaseIssued&&t.io_flushStatus_hit?"RELEASE_ADMISSION":
        !t.io_flushStatus_releaseSent&&t.io_flushStatus_hit?"SOURCEC_LAST_FIRE":
        !t.io_flushStatus_releaseAck?"MATCHING_RELEASE_ACK":
        !t.io_flushStatus_noWait?"MSHR_RESPONSE_TAIL":
        !t.io_flushStatus_commitReady&&t.io_flushStatus_hit?"DIRECTORY_COMMIT":
        "FLUSH_RESPONSE";
      static const char* states[]={"INVALID","BRANCH","BRANCH_C","TIP","TIP_C","TIP_CD","TIP_D","TRUNK_C","TRUNK_CD"};
      const unsigned state=t.io_flushStatus_state;
      std::cout << "FLUSH_BLOCKER=" << blocker << " case=" << current << " cycle=" << cycles
        << " MSHR_ID=" << uint32_t(t.io_flushStatus_mshr) << " MSHR_ACTIVE=" << active
        << " META_VALID=" << meta << " MSHR_STATE=" << (meta&&state<9?states[state]:"UNKNOWN")
        << " ADDRESS=" << std::hex << uint64_t(t.io_flushStatus_address) << std::dec
        << " SET=" << unsigned(t.io_flushStatus_set) << " WAY=" << unsigned(t.io_flushStatus_way)
        << " IMAGE_KEY=" << unsigned(t.io_flushStatus_image_valid) << ":" << uint32_t(t.io_flushStatus_image_writer)
        << ":" << uint32_t(t.io_flushStatus_image_generation) << ":" << uint32_t(t.io_flushStatus_image_contentSeq)
        << " SAFE=" << safe << " DIRTY=" << unsigned(t.io_flushStatus_dirty)
        << " CLIENTS=" << unsigned(t.io_flushStatus_clients)
        << " OUTER_PRESERVED=" << unsigned(t.io_flushStatus_outerPreserved)
        << " VALIDATION_PENDING=" << (meta&&!safe) << " PRESERVATION_PENDING=" << unsigned(t.io_pending)
        << " PROBE_SCHEDULED=" << unsigned(t.io_flushStatus_probeScheduled)
        << " PROBE_ACK_FIRST=" << unsigned(t.io_flushStatus_probeAckFirst)
        << " PROBE_ACK_LAST=" << unsigned(t.io_flushStatus_probeAckLast)
        << " SOURCEC_BUSY=" << unsigned(t.io_drain_sourceCBusy)
        << " SOURCEC_REQ=" << unsigned(t.io_drain_sourceCValid) << "/" << unsigned(t.io_drain_sourceCReady)
        << " RELEASE_ISSUED=" << (flushReleaseIssued||t.io_flushStatus_releaseIssued)
        << " RELEASE_SENT=" << (flushReleaseSent||t.io_flushStatus_releaseSent)
        << " RELEASE_ACK=" << (flushReleaseAck||(t.io_flushStatus_releaseIssued&&t.io_flushStatus_releaseAck))
        << " FLUSH_COMMIT_VALID=" << unsigned(t.io_flushStatus_commitValid)
        << " FLUSH_COMMIT_READY=" << unsigned(t.io_flushStatus_commitReady)
        << " FLUSH_DIRECTORY_INVALIDATED=" << flushCommitted << std::endl;
    }
    std::string blockers;
    const auto add=[&](bool blocked,const char* name) {
      if(blocked) { if(!blockers.empty()) blockers+=","; blockers+=name; }
    };
    add(!pendingProbes.empty(),"HOST_PENDING_PROBE");
    add(!outstandingA.empty(),"HOST_OUTSTANDING_A");
    add(!outstandingC.empty(),"HOST_OUTSTANDING_RELEASE");
    add(!aq.empty(),"HOST_A_QUEUE"); add(!cq.empty(),"HOST_C_QUEUE");
    add(!rq.empty(),"HOST_MEMORY_READ_QUEUE"); add(!wq.empty(),"HOST_MEMORY_WRITE_ACK_QUEUE");
    add(!eq.empty(),"HOST_E_QUEUE"); add(!inject.empty(),"HOST_INJECT_QUEUE");
    add(flushing,"HOST_FLUSH_REQUEST");
    add(putBeat||grantBeat||readBeat,"HOST_PARTIAL_TRANSFER");
    add(t.io_active,"HARDWARE_ACTIVE"); add(t.io_pending,"CHECKPOINT_PENDING");
    if(t.io_drain_candidate&&!t.io_drain_drained) {
      add(!t.io_drain_sourceDIdle,"CHECKPOINT_SOURCE_D");
      add(!t.io_drain_sourceCIdle,"CHECKPOINT_SOURCE_C");
      add(t.io_drain_sinkCBusy,"CHECKPOINT_SINK_C_BANK_QUEUE");
      add(!t.io_drain_quiescent,"CHECKPOINT_SELECTED_MSHR_RESPONSES");
    }
    add(t.io_blocked,"WAIT_VALIDATION");
    add(t.io_clientWaiting,"PARKED_CLIENT");
    static const char* states[]={"IDLE","READ","DELAY1","DELAY2","SEND","WAIT_ACK","FAILED"};
    const unsigned state=t.io_drain_state;
    std::cout << "DRAIN_BLOCKER=" << (blockers.empty()?"NONE":blockers)
      << " case=" << current << " cycle=" << cycles << " wait=" << why
      << " preservation_state=" << (state<7?states[state]:"UNKNOWN")
      << " candidate=" << unsigned(t.io_drain_candidate) << " safe=" << unsigned(t.io_drain_safe)
      << " selected=" << unsigned(t.io_drain_selected) << " drain=" << unsigned(t.io_drain_drained)
      << " drain_requested=" << unsigned(t.io_drain_requested) << " quiescent=" << unsigned(t.io_drain_quiescent)
      << " sourceD_idle=" << unsigned(t.io_drain_sourceDIdle) << " sourceD_busy=" << unsigned(t.io_drain_sourceDBusy)
      << " sourceC_idle=" << unsigned(t.io_drain_sourceCIdle) << " sourceC_busy=" << unsigned(t.io_drain_sourceCBusy)
      << " sinkC_bank_pending=" << unsigned(t.io_drain_sinkCBusy)
      << " mshr_pending=" << unsigned(t.io_drain_mshrPending) << " mshr_quiescent=" << unsigned(t.io_drain_mshrQuiescent)
      << " sourceD_req=" << unsigned(t.io_drain_sourceDValid) << "/" << unsigned(t.io_drain_sourceDReady)
      << " sourceD_fire=" << (t.io_drain_sourceDValid&&t.io_drain_sourceDReady)
      << " sourceC_req=" << unsigned(t.io_drain_sourceCValid) << "/" << unsigned(t.io_drain_sourceCReady)
      << " sourceC_fire=" << (t.io_drain_sourceCValid&&t.io_drain_sourceCReady)
      << " probe=" << unsigned(t.io_drain_probeValid) << "/" << unsigned(t.io_drain_probeAllow)
      << " scheduler_req=" << unsigned(t.io_drain_requestValid) << "/" << unsigned(t.io_drain_requestReady)
      << " scheduler_fire=" << (t.io_drain_requestValid&&t.io_drain_requestReady)
      << " issued=" << unsigned(t.io_drain_issued) << " ack_seen=" << unsigned(t.io_drain_ackSeen)
      << " matching_ack=" << unsigned(t.io_ack) << " pending=" << unsigned(t.io_pending)
      << " set=" << unsigned(t.io_pendingSet) << " way=" << unsigned(t.io_pendingWay)
      << " addr=" << std::hex << uint64_t(t.io_drain_address) << std::dec << " txn=" << uint64_t(t.io_txn)
      << " validation=" << unsigned(t.io_blocked) << " watermark=" << watermark
      << " client_waiting=" << unsigned(t.io_clientWaiting)
      << " client_validation=" << unsigned(t.io_clientValidationBlock)
      << " client_seq=" << uint32_t(t.io_clientValidationSeq)
      << " aq=" << aq.size() << " cq=" << cq.size() << " rq=" << rq.size() << " wq=" << wq.size()
      << " eq=" << eq.size() << " inject=" << inject.size() << " outstandingA=" << outstandingA.size()
      << " outstandingC=" << outstandingC.size() << " probes=" << pendingProbes.size()
      << " first_probe=" << std::hex << (pendingProbes.empty()?0:*pendingProbes.begin()) << std::dec
      << " flushing=" << flushing << " put_beat=" << putBeat << " grant_beat=" << grantBeat << " read_beat=" << readBeat
      << " memory_ready=" << memoryReady << " hold_write_acks=" << holdWrites
      << " preserve_req=" << uint64_t(t.io_counts_0) << " preserve_ack=" << uint64_t(t.io_counts_1) << std::endl;
  }
  void tick() {
    t.clock=0;
    t.io_safe=watermark; t.io_dr=!t.reset; t.io_br=!t.reset; t.io_mr=!t.reset&&memoryReady;
    t.io_av=!t.reset&&!aq.empty(); t.io_cv=!t.reset&&!cq.empty(); t.io_ev=!t.reset&&!eq.empty();
    t.io_esink=eq.empty()?0:eq.front();
    t.io_aa=0; t.io_ao=6; t.io_ap=1; t.io_al=0; t.io_ah=0; t.io_asrc=0;
    t.io_ca=0; t.io_co=7; t.io_cp=1; t.io_cl=0; t.io_ch=0; t.io_csrc=0;
    t.io_ck_valid=0; t.io_ck_writer=0; t.io_ck_generation=0; t.io_ck_contentSeq=0;
    if(!aq.empty()) {
      auto& a=aq.front(); t.io_aa=a.addr; t.io_ao=a.op; t.io_ap=a.param; t.io_asrc=a.source;
      t.io_al=a.data[2*a.beat]; t.io_ah=a.data[2*a.beat+1];
    }
    if(!cq.empty()) {
      auto& c=cq.front(); t.io_ca=c.addr; t.io_co=c.op; t.io_cp=c.param; t.io_csrc=c.source;
      t.io_cl=c.data[2*c.beat]; t.io_ch=c.data[2*c.beat+1];
      t.io_ck_valid=c.key.valid; t.io_ck_writer=c.key.writer;
      t.io_ck_generation=c.key.gen; t.io_ck_contentSeq=c.key.seq;
    }
    t.io_flush=!t.reset&&flushing; t.io_flushAddr=flushAddr;
    auto* q=t.reset?nullptr:!inject.empty()?&inject:!rq.empty()?&rq:(!holdWrites&&!wq.empty())?&wq:nullptr;
    t.io_rv=q!=nullptr; t.io_ro=0; t.io_rs=0; t.io_rt=0; t.io_rl=0; t.io_rh=0;
    if(q) {
      auto& r=q->front(); t.io_ro=r.op; t.io_rs=r.source; t.io_rt=r.txn;
      t.io_rl=r.data[2*r.beat]; t.io_rh=r.data[2*r.beat+1];
    }
    t.eval();
    // Reset is synchronous in the generated model. Before its first rising
    // edge, combinational outputs may still reflect randomized registers.
    // Those are not protocol handshakes: never mutate ANY host ledger/counter
    // or stalled-valid history while reset is asserted. Still clock the DUT.
    if(t.reset) {
      t.clock=1; t.eval(); Verilated::timeInc(1); ++cycles;
      return;
    }
    if(bool(t.io_pending)!=wasPending||t.io_ack) {
      std::cout << "STAGE3_HOST PRESERVATION case=" << current << " cycle=" << cycles
        << " pending=" << unsigned(t.io_pending) << " ack=" << unsigned(t.io_ack)
        << " txn=" << uint64_t(t.io_txn) << " set=" << unsigned(t.io_pendingSet)
        << " way=" << unsigned(t.io_pendingWay) << " gen=" << uint32_t(t.io_pendingKey_generation)
        << " seq=" << uint32_t(t.io_pendingKey_contentSeq) << std::endl;
    }
    wasPending=t.io_pending;
    if(bool(t.io_blocked)!=wasBlocked) {
      std::cout << "STAGE3_HOST VALIDATION_BLOCK case=" << current << " cycle=" << cycles
        << " blocked=" << unsigned(t.io_blocked) << " seq=" << uint32_t(t.io_blockedSeq)
        << " watermark=" << watermark << std::endl;
    }
    wasBlocked=t.io_blocked;
    const auto signals=std::make_tuple(uint64_t(t.io_ma),uint64_t(t.io_ms),uint64_t(t.io_mt),uint64_t(t.io_ml),uint64_t(t.io_mh));
    if(wasStalled) check(t.io_mv&&signals==stalled,"outer valid/provenance/data changed while stalled");
    wasStalled=t.io_mv&&!t.io_mr; stalled=signals;
    if(watermark!=sampledWatermark) {
      if(t.io_ack) ++validationAckRace;
      if(t.io_bankWrite) ++validationWriteRace;
    }
    sampledWatermark=watermark;
    if(t.io_pending) {
      check(!t.io_bankWrite,"bank mutation before checkpoint ACK");
      check(!t.io_metaWrite,"metadata mutation before checkpoint ACK");
    }
    if(t.io_av&&t.io_ar) {
      auto& a=aq.front();
      if(!a.beat) {
        const bool coherent=a.op==6||a.op==7;
        check(coherent ? (a.source==kCoherentSource||a.source==kPeerSource) :
          (a.source==kUncachedSource||a.source==kPressureSource),"inner A source/client capability mismatch");
        check(outstandingA.insert(a.source).second,"inner A source reused before D completion");
        std::cout << "STAGE3_HOST A case=" << current << " cycle=" << cycles
          << " source=" << a.source << " opcode=" << a.op << " addr=" << std::hex << a.addr << std::dec << std::endl;
      }
      if(a.op==0 && ++a.beat<4) {} else aq.pop_front();
    }
    if(t.io_cv&&t.io_cr) {
      auto& c=cq.front();
      check(c.source==kCoherentSource||c.source==kPeerSource,"inner C issued by uncached source");
      if(!c.beat) {
        if(c.op==6||c.op==7)
          check(outstandingC.insert(c.source).second,"inner Release source reused before ReleaseAck");
        else check(pendingProbes.count(c.addr)==1&&probeSources.at(c.addr)==c.source,
          "ProbeAck without matching Probe address/source");
        std::cout << "STAGE3_HOST C case=" << current << " cycle=" << cycles
          << " source=" << c.source << " opcode=" << c.op << " param=" << c.param
          << " addr=" << std::hex << c.addr << std::dec << " gen=" << c.key.gen << " seq=" << c.key.seq << std::endl;
      }
      const bool last=!(c.op&1)||c.beat==3;
      if(last&&(c.op==4||c.op==5)) {
        check(pendingProbes.erase(c.addr)==1,"duplicate ProbeAck completion");
        probeSources.erase(c.addr);
      }
      if((c.op&1)&&++c.beat<4) {} else cq.pop_front();
    }
    if(t.io_ev) eq.pop_front();
    if(t.io_flush&&t.io_flushReady) {
      phase("FLUSH_ACCEPT",flushAddr); flushing=false; waitingFlush=true;
      flushReleaseIssued=flushReleaseSent=flushReleaseAck=flushCommitted=false;
    }
    if(t.io_flushStatus_active&&t.io_flushStatus_metaValid) {
      flushReleaseIssued|=bool(t.io_flushStatus_releaseIssued);
      flushReleaseSent|=bool(t.io_flushStatus_releaseSent);
      // Initial w_releaseack=true on a miss means no Release was required.
      flushReleaseAck|=bool(t.io_flushStatus_releaseIssued&&t.io_flushStatus_releaseAck);
      if(t.io_flushStatus_hit&&t.io_flushStatus_commitReady) {
        phase("FLUSH_DIRECTORY_INVALIDATE",t.io_flushStatus_address); flushCommitted=true;
      }
    }
    if(t.io_flushed) { phase("FLUSH_RESPONSE",flushAddr); ++flushes; waitingFlush=false; }
    if(t.io_bv&&t.io_br) {
      ++probes;
      check(pendingProbes.insert(t.io_ba).second,"duplicate outstanding Probe");
      probeSources[t.io_ba]=t.io_bsrc;
      std::cout << "STAGE3_HOST B case=" << current << " cycle=" << cycles
        << " addr=" << std::hex << uint64_t(t.io_ba) << std::dec << " source=" << unsigned(t.io_bsrc)
        << " param=" << unsigned(t.io_bp) << std::endl;
    }
    if(t.io_bankWrite) ++writes;
    if(t.io_metaWrite) ++metas;
    if(t.io_dv&&t.io_dr) {
      bool completeA=false;
      if(t.io_dop==5 || t.io_dop==4) {
        if(t.io_dsrc==kPeerSource) {
          check(!blockedPeerSeq||watermark>=blockedPeerSeq,"unsafe peer Grant before validation");
          check(!t.io_dk_valid||!t.io_dk_contentSeq||t.io_dk_contentSeq<=watermark,
            "unsafe peer Grant image");
        }
        returned[2*grantBeat]=t.io_dl; returned[2*grantBeat+1]=t.io_dh;
        returnedKey=Key{uint32_t(t.io_dk_generation),uint32_t(t.io_dk_contentSeq),uint16_t(t.io_dk_writer),bool(t.io_dk_valid)};
        if(t.io_dop==4 || ++grantBeat==4) {
          ++grants; ++grantsBySource[t.io_dsrc]; grantBeat=0; eq.push_back(t.io_dsink); completeA=true;
        }
      } else if(t.io_dop==1 || t.io_dop==0) {
        returned[2*readBeat]=t.io_dl; returned[2*readBeat+1]=t.io_dh;
        returnedKey=Key{uint32_t(t.io_dk_generation),uint32_t(t.io_dk_contentSeq),uint16_t(t.io_dk_writer),bool(t.io_dk_valid)};
        if(t.io_dop==0 || ++readBeat==4) { ++reads; readBeat=0; completeA=true; }
      } else if(t.io_dop==6) {
        check(outstandingC.erase(t.io_dsrc)==1,"ReleaseAck without an outstanding inner Release");
        ++releases;
        std::cout << "STAGE3_HOST RELEASE_ACK case=" << current << " cycle=" << cycles
          << " source=" << unsigned(t.io_dsrc) << std::endl;
      }
      else throw std::runtime_error("unexpected inner D opcode");
      if(completeA) {
        check(outstandingA.erase(t.io_dsrc)==1,"inner D completion without outstanding A source");
        std::cout << "STAGE3_HOST D case=" << current << " cycle=" << cycles
          << " source=" << unsigned(t.io_dsrc) << " opcode=" << unsigned(t.io_dop) << std::endl;
      }
    }
    if(q && t.io_rv&&t.io_rr) {
      auto& r=q->front();
      if(r.op==1 && ++r.beat<4) {} else {
        if(r.commit) {
          durable[r.addr]=r.data;
          std::cout << "STAGE3_MEMORY_COMMIT addr=" << std::hex << r.addr << " source=" << r.source << " txn=" << r.txn << std::dec << "\n";
        }
        q->pop_front();
      }
    }
    if(t.io_mv&&t.io_mr) {
      const uint64_t addr=t.io_ma & ~uint64_t(63);
      if(t.io_mo==4) {
        ++memoryGets;
        Reply r; r.addr=addr; r.txn=t.io_mt; r.source=t.io_ms; r.op=1;
        r.data=durable.count(addr)?durable[addr]:Line{}; rq.push_back(r);
      } else if(t.io_mo==0) {
        if(!putBeat) {
          assembling=Reply{}; assembling.addr=addr; assembling.source=t.io_ms;
          assembling.txn=t.io_mt; assembling.op=0; assembling.commit=true;
          check(issued.insert({assembling.source,assembling.txn}).second,"duplicate outer write transaction");
          ++puts;
        }
        check(addr==assembling.addr&&t.io_ms==assembling.source&&t.io_mt==assembling.txn,"outer identity changed under backpressure");
        assembling.data[2*putBeat]=t.io_ml; assembling.data[2*putBeat+1]=t.io_mh;
        if(++putBeat==4) {
          putBeat=0; wq.push_back(assembling); lastPutTxn=assembling.txn; lastPutSource=assembling.source;
          if((assembling.source&1)==0) lastVictimAddr=addr;
        }
      } else check(false,"unexpected terminal A opcode");
    }
    t.clock=1; t.eval(); Verilated::timeInc(1); ++cycles;
    check(!Verilated::gotFinish(),"hardware assertion/finish");
    check(cycles<150000,"global timeout");
  }
  void pump(int n=20) { while(n-->0) tick(); }
  void until(std::function<bool()> predicate,const char* why,int budget=3000) {
    while(!predicate()&&budget-->0) tick();
    if(!predicate()) waitSnapshot(why);
    check(predicate(),std::string("timeout: ")+why);
  }
  void idle() {
    phase("DRAIN_BEGIN");
    until([&]{return drained();},"drain");
    pump(8); // includes the Directory's single pending write reaching SRAM
    check(drained(),"transaction reactivated after drain");
    check(t.io_counts_0==t.io_counts_1,"drain left an unacknowledged checkpoint transaction");
    phase("DRAINED");
  }
  void acquire(uint64_t a,int source=kCoherentSource) {
    const auto target=grants+1; aq.push_back(Upper{a,{}, {},6,1,source});
    until([&]{return grants==target;},"Acquire/GrantData"); idle();
  }
  void enqueue(uint64_t a,Key k,Line d,int op=7,int param=1,int source=kCoherentSource) {
    cq.push_back(Upper{a,d,k,op,param,source});
  }
  void release(uint64_t a,Key k,Line d,int op=7,int param=1,int source=kCoherentSource) {
    const auto target=releases+1; enqueue(a,k,d,op,param,source);
    until([&]{return releases==target;},"ReleaseAck"); idle();
  }
  void fill(uint64_t a,Key k,Line d) { acquire(a); release(a,k,d); }
  void flush(uint64_t a) {
    phase("FLUSH_BEGIN",a);
    const auto target=flushes+1; flushing=true; flushAddr=a;
    until([&]{return flushes==target;},"flush completion"); idle();
    phase("FLUSH_DONE",a);
  }
  void fake(int source,uint64_t txn) { Reply r; r.source=source; r.txn=txn; inject.push_back(r); pump(5); }
  void cleanup(std::initializer_list<std::pair<uint64_t,Key>> lines) {
    phase("CLEANUP_BEGIN");
    for(auto a:lines) validate(a.second);
    pump(); idle();
    for(auto a:lines) flush(a.first);
    phase("CLEANUP_DONE");
  }
  void warmSet(uint64_t a,uint64_t b) {
    for(int n=0;n<100;++n) {
      const auto before=memoryGets;
      for(auto addr:{a,b}) {
        const auto target=reads+1; aq.push_back(Upper{addr,{}, {},4,0,kUncachedSource});
        until([&]{return reads==target;},"warm clean set"); idle();
      }
      if(memoryGets==before) return; // both actual directory lookups hit
    }
    check(false,"could not populate both ways using real replacement policy");
  }
  void pending(Key k) {
    until([&]{return bool(t.io_pending);},"checkpoint reservation");
    check(t.io_pendingKey_generation==k.gen&&t.io_pendingKey_contentSeq==k.seq&&
      t.io_pendingKey_writer==k.writer,"pending predecessor full key");
  }
};

int main(int argc,char** argv) {
  Verilated::commandArgs(argc,argv);
  Run r;
  try {
    r.t.reset=1; r.pump(8); r.t.reset=0; r.pump(20);
    check(r.probes==0&&r.grants==0&&r.releases==0&&r.reads==0&&r.puts==0&&r.memoryGets==0&&
      r.outstandingA.empty()&&r.outstandingC.empty()&&r.pendingProbes.empty(),"reset polluted host transaction accounting");
    r.phase("RESET_DONE");
    const uint64_t a=0x80000000,b=a+128,c=a+256;
    r.begin("same_line_safe_dirty_wait_ack");
    auto p=r.key(false), q=r.key(); const auto pd=bytes(0x100),qd=bytes(0x200);
    r.fill(a,p,pd); r.acquire(a);
    const auto ack0=r.releases, req0=r.t.io_counts_0;
    r.holdWrites=true; r.memoryReady=false; r.enqueue(a,q,qd); r.pending(p);
    const auto txn=r.t.io_txn; r.pump(40);
    check(r.releases==ack0&&r.t.io_counts_0==req0,"Q overwrote predecessor under backpressure");
    r.fake(5,txn); check(r.t.io_pending,"early matching ACK released unsent Put");
    r.pass("outer_backpressure_exactly_once");
    r.memoryReady=true;
    r.until([&]{return !r.wq.empty();},"complete checkpoint Put");
    check(r.wq.front().data==pd,"checkpoint bytes are not predecessor P");
    r.pump(40); check(r.releases==ack0&&r.t.io_pending,"Q installed before delayed ACK");
    r.pass("delayed_ack_freezes_predecessor");
    const auto w0=r.writes,m0=r.metas;
    // New requests are queued behind the reserved predecessor, never substituted.
    r.aq.push_back(Upper{a,{}, {},4,0,kUncachedSource}); r.pump(20);
    check(r.writes==w0&&r.metas==m0&&r.t.io_pendingKey_generation==p.gen,"new same-line request mutated pending P");
    r.pass("pending_same_line_request");
    // Keep both requests outstanding behind P, with distinct TL source IDs.
    r.aq.push_back(Upper{b,{}, {},4,0,kPressureSource}); r.pump(20);
    check(r.writes==w0&&r.t.io_pendingKey_generation==p.gen,"replacement pressure changed pending victim");
    r.pass("pending_replacement_pressure");
    r.validate(q); r.holdWrites=false; // validation and true outer ACK same tick
    r.until([&]{return r.releases==ack0+1;},"Q completion after preservation");
    r.idle();
    check(r.validationAckRace>0,"validation and matching ACK were not simultaneous");
    r.pass("validation_and_ack_same_cycle"); r.pass("same_line_safe_dirty_wait_ack");
    check(r.t.io_counts_0==req0+1,"checkpoint request duplicated");
    r.begin("duplicate_ack_ignored");
    const auto done=r.t.io_counts_1; r.fake(5,txn);
    check(r.t.io_counts_1==done&&!r.t.io_pending,"duplicate ACK changed completion");
    r.pass("duplicate_ack_ignored");
    // Pressure may select either way. Re-establish a known exact predecessor
    // before the same-address ABA experiment; never assume LFSR's victim.
    r.begin("full_provenance_collision");
    r.cleanup({{a,q},{b,{}}}); r.fill(a,q,qd); r.acquire(a);
    auto q2=r.key(); r.holdWrites=true; r.enqueue(a,q2,bytes(0x300)); r.pending(q);
    r.until([&]{return !r.wq.empty();},"second checkpoint");
    const auto txn2=r.t.io_txn;
    check(txn2!=txn&&r.wq.front().data==qd,"new version aliases previous transaction");
    r.fake(5,txn); check(r.t.io_pending&&r.t.io_counts_1==done,"stale ACK freed new transaction");
    r.pass("stale_ack_ignored"); r.pass("full_provenance_collision");
    r.holdWrites=false; r.until([&]{return r.cq.empty();},"Q2 install"); r.idle();
    r.begin("repeated_speculative_same_line");
    r.acquire(a); auto q3=r.key(); q3.seq=q2.seq; const auto repeatedPuts=r.puts;
    check(q3.gen>q2.gen,"same-package write did not allocate a fresh generation");
    const auto repeatedPreserves=r.t.io_counts_0;
    const auto repeatedReleases=r.releases, repeatedWrites=r.writes;
    r.enqueue(a,q3,bytes(0x350));
    r.until([&]{return r.releases==repeatedReleases+1;},"same-package ReleaseAck"); r.idle();
    check(r.puts==repeatedPuts&&r.t.io_counts_0==repeatedPreserves,
      "same-package update emitted an unnecessary preservation Put");
    check(r.writes>repeatedWrites,"same-package update did not reach the bank");
    r.acquire(a);
    check(r.returned==bytes(0x350)&&r.returnedKey.valid&&r.returnedKey.gen==q3.gen&&
      r.returnedKey.seq==q3.seq&&r.returnedKey.writer==q3.writer,"same-package update did not publish the new image");
    // Readback acquired T ownership again. Return the unchanged permissions via
    // a real clean TtoN Release before cleanup; this host only answers Probes
    // explicitly in the ProbeAckData CASE. This does not validate or export Q3.
    r.release(a,q3,{},6);
    check(r.puts==repeatedPuts&&r.t.io_counts_0==repeatedPreserves,"readback permission return exported speculative bytes");
    r.cleanup({{a,q3},{b,{}}});
    check(r.durable[a]==bytes(0x350),"validated supersede flush did not commit the new bytes");
    r.pass("repeated_speculative_same_line");

    // A clean outer image needs no checkpoint, even when Q is speculative.
    r.begin("same_line_already_outer_preserved");
    r.acquire(a); const auto noReq=r.t.io_counts_0,noPut=r.puts;
    auto cleanQ=r.key(); r.release(a,cleanQ,bytes(0x400));
    check(r.t.io_counts_0==noReq&&r.puts==noPut,"clean predecessor redundantly preserved");
    r.cleanup({{a,cleanQ}});
    // A trusted A write over an already-dirty resident first checkpoints P,
    // then revokes P's receipt for its new BASE bytes. A following Q must
    // checkpoint those exact bytes again, rather than inherit P's receipt.
    const auto tp=r.key(false); const auto td=bytes(0x420);
    r.fill(a,tp,bytes(0x410)); const auto writeReply=r.reads;
    r.aq.push_back(Upper{a,td,{},0,0,kUncachedSource});
    r.until([&]{return r.reads==writeReply+1;},"trusted write over dirty P"); r.idle();
    r.acquire(a); check(r.returned==td&&!r.returnedKey.valid,"trusted write did not publish BASE bytes");
    const auto tq=r.key(); const auto trustedAck=r.releases, trustedReq=r.t.io_counts_0;
    r.holdWrites=true; r.enqueue(a,tq,bytes(0x430)); r.pending({});
    r.until([&]{return !r.wq.empty();},"trusted BASE preservation");
    check(r.wq.front().data==td&&r.releases==trustedAck,
      "trusted dirty update retained an obsolete preservation receipt");
    r.holdWrites=false; r.until([&]{return r.releases==trustedAck+1;},"Q after trusted BASE ACK"); r.idle();
    check(r.t.io_counts_0==trustedReq+1,"trusted dirty BASE checkpoint missing or duplicated");
    r.cleanup({{a,tq}});
    r.pass("same_line_already_outer_preserved");

    // Fill BOTH physical ways of the same set. Either LFSR victim is unsafe.
    r.begin("speculative_set_victim_blocks_outer");
    r.warmSet(a,b);
    auto v1=r.key(),v2=r.key(); r.fill(a,v1,bytes(0x500)); r.fill(b,v2,bytes(0x600));
    const auto before=r.puts,g0=r.grants; r.holdWrites=true;
    r.aq.push_back(Upper{c,{}, {},6,1});
    r.until([&]{return bool(r.t.io_blocked);},"speculative set-victim barrier");
    r.pump(30); check(r.puts==before&&r.grants==g0,"speculative victim leaked or replaced");
    r.pass("speculative_set_victim_blocks_outer");
    r.validate(v1); r.validate(v2);
    r.until([&]{return !r.wq.empty();},"validated victim writeback");
    const auto victim=r.wq.front(); check((victim.source&1)==0&&victim.addr!=c,"not a set-victim writeback");
    check(victim.data==(victim.addr==a?bytes(0x500):bytes(0x600)),"wrong victim bytes");
    r.pump(30); check(r.grants==g0,"refill overtook victim ACK");
    r.pass("same_set_different_line_replacement"); r.pass("safe_dirty_set_victim_wait_ack");
    r.fake(victim.source,victim.txn-1); check(r.grants==g0,"stale victim ACK permitted refill");
    r.holdWrites=false; r.until([&]{return r.grants==g0+1;},"replacement after real ACK"); r.idle();
    r.pass("validated_victim_preserve_ack_replace");
    r.release(c,{}, {},6); r.cleanup({{a,v1},{b,v2},{c,{}}});

    // Full-set clean replacement has an existing lower copy and no dirty Put.
    r.begin("safe_clean_victim_no_write");
    r.warmSet(a,b);
    const auto cleanPuts=r.puts; r.acquire(c);
    check(r.puts==cleanPuts,"safe clean victim caused an outer data write");
    r.pass("safe_clean_victim_no_write"); r.release(c,{}, {},6); r.cleanup({{a,{}},{b,{}},{c,{}}});

    // Flush uses exactly the same speculative victim barrier as replacement.
    r.begin("flush_clear_normal_writeback_barrier");
    auto f=r.key(); r.fill(a,f,bytes(0x700));
    const auto pf=r.puts,ff=r.flushes; r.flushing=true; r.flushAddr=a; r.holdWrites=true;
    r.until([&]{return bool(r.t.io_blocked);},"flush validation barrier"); r.pump(30);
    check(r.puts==pf&&r.flushes==ff,"flush exported unvalidated bytes");
    r.validate(f); r.until([&]{return !r.wq.empty();},"flush validated writeback");
    r.pump(20); check(r.flushes==ff,"flush completed before outer ACK");
    r.holdWrites=false; r.until([&]{return r.flushes==ff+1;},"flush ACK"); r.idle();
    r.pass("flush_clear_normal_writeback_barrier");

    // ProbeAckData's direct bank path must preserve a DIFFERENT safe key first.
    r.begin("validation_and_refill_replacement_same_cycle");
    auto pp=r.key(false),pq=r.key(); r.fill(a,pp,bytes(0x800)); r.acquire(a);
    const auto probe0=r.probes,read0=r.reads; r.aq.push_back(Upper{a,{}, {},4,0,kUncachedSource});
    r.until([&]{return r.probes==probe0+1;},"inner probe");
    r.holdWrites=true; r.enqueue(a,pq,bytes(0x900),5,0); r.pending(pp);
    r.until([&]{return !r.wq.empty();},"probe predecessor checkpoint");
    check(r.wq.front().data==bytes(0x800),"ProbeAck preserved Q instead of P");
    r.holdWrites=false;
    r.until([&]{return !r.t.io_pending&&bool(r.t.io_bankWrite);},"probe physical bank write");
    r.validate(pq); r.tick(); // watermark update and real ProbeAck bank write
    check(r.validationWriteRace>0,"validation and physical write were not simultaneous");
    r.until([&]{return r.reads==read0+1;},"probe bank/refill completion"); r.idle();
    check(r.returned==bytes(0x900),"probe data missing after validation/checkpoint race");
    r.pass("validation_and_refill_replacement_same_cycle");
    r.release(a,pq,bytes(0x900),6,2); r.cleanup({{a,pq}}); // BtoN after TtoB probe

    // Ordinary coherent peers cannot own an unsafe BOOM image. Parking must
    // free the set/MSHR while same-set BOOM and other-set preservation proceed.
    r.begin("lineage_unaware_peer_waits_validation");
    auto origin=r.key(); r.fill(a,origin,bytes(0xa00));
    r.blockedPeerSeq=origin.seq;
    const auto peerGrants=r.grantsBySource[kPeerSource];
    r.aq.push_back(Upper{a,{}, {},6,1,kPeerSource});
    r.until([&]{return r.t.io_clientWaiting==1;},"unaware peer parked"); r.pump(12);
    const auto parked=[&] {
      check(r.t.io_clientWaiting==1&&r.t.io_clientValidationBlock&&
        r.t.io_clientValidationSeq==origin.seq,"peer validation wait lost");
      check(r.grantsBySource[kPeerSource]==peerGrants,"peer granted before validation");
      check(r.t.io_drain_mshrPending==0&&r.t.io_drain_sourceDIdle,
        "parked peer retained MSHR/SourceD");
    };
    parked();
    const auto acquireBusy=[&](uint64_t addr) {
      const auto n=r.grants; r.aq.push_back(Upper{addr,{}, {},6,1});
      r.until([&]{return r.grants==n+1;},"BOOM Acquire while peer parked"); r.pump(12);
    };
    const auto releaseBusy=[&](uint64_t addr,Key k,Line data) {
      const auto n=r.releases; r.enqueue(addr,k,data);
      r.until([&]{return r.releases==n+1;},"BOOM Release while peer parked"); r.pump(12);
    };
    auto newer=r.key(); newer.seq=origin.seq;
    acquireBusy(a); releaseBusy(a,newer,bytes(0xb00)); parked();
    const uint64_t other=a+64; // other set; same-set BOOM was checked above
    auto safeP=r.key(false),otherQ=r.key(); otherQ.seq=origin.seq;
    acquireBusy(other); releaseBusy(other,safeP,bytes(0xd00)); acquireBusy(other);
    const auto beforePreserve=r.t.io_counts_0, beforeRelease=r.releases;
    r.holdWrites=true; r.enqueue(other,otherQ,bytes(0xe00));
    r.pending(safeP); r.until([&]{return !r.wq.empty();},"preserve while peer parked");
    check(r.wq.front().addr==other&&r.wq.front().data==bytes(0xd00),"wrong parked-peer predecessor");
    r.pump(20); check(r.releases==beforeRelease,"overwrite before preservation ACK");
    r.holdWrites=false; r.until([&]{return r.releases==beforeRelease+1;},"outer ACK progress while peer parked");
    r.pump(12); check(r.t.io_counts_0==beforePreserve+1,"missing preservation progress"); parked();
    r.validate(origin);
    r.until([&]{return r.grantsBySource[kPeerSource]==peerGrants+1;},"validated peer retry"); r.idle();
    check(r.returned==bytes(0xb00)&&r.returnedKey.seq==origin.seq&&
      r.returnedKey.gen==newer.gen,"peer replay used stale directory/image");
    const auto peerCheckpoints=r.t.io_counts_0;
    r.release(a,{},bytes(0xc00),7,1,kPeerSource);
    check(r.t.io_counts_0==peerCheckpoints+1,"safe predecessor not preserved before BASE ReleaseData");
    r.acquire(a,kPeerSource);
    check(r.returned==bytes(0xc00)&&!r.returnedKey.valid,"ordinary peer BASE Release roundtrip");
    const auto peerProbe=r.probes,peerRead=r.reads;
    r.aq.push_back(Upper{a,{}, {},4,0,kUncachedSource});
    r.until([&]{return r.probes==peerProbe+1;},"ordinary peer Probe");
    check(r.probeSources.at(a)==kPeerSource,"Probe routed to wrong client");
    r.enqueue(a,{},bytes(0xc80),5,0,kPeerSource);
    r.until([&]{return r.reads==peerRead+1;},"ordinary BASE ProbeAckData"); r.idle();
    check(r.returned==bytes(0xc80)&&!r.returnedKey.valid,"ordinary BASE ProbeAckData roundtrip");
    r.release(a,{}, {},6,2,kPeerSource); r.cleanup({{a,{}},{other,otherQ}});
    check(r.durable[a]==bytes(0xc80)&&r.durable[other]==bytes(0xe00),"peer/preservation durable bytes");

    // Also exercise late discovery: a safe directory entry becomes unsafe only
    // in BOOM ProbeAckData. Finish C/E and commit the probed ownership, then park.
    auto late=r.key(); r.fill(a,{},bytes(0xf00)); r.acquire(a);
    r.blockedPeerSeq=late.seq;
    const auto lateProbe=r.probes,lateGrants=r.grantsBySource[kPeerSource];
    r.aq.push_back(Upper{a,{}, {},6,1,kPeerSource});
    r.until([&]{return r.probes==lateProbe+1;},"late unsafe BOOM Probe");
    check(r.probeSources.at(a)==kCoherentSource,"late Probe routed incorrectly");
    r.enqueue(a,late,bytes(0xf80),5,1); // TtoN, no ownership retained by BOOM
    r.until([&]{return r.t.io_clientWaiting==1;},"late unsafe peer parked"); r.pump(12);
    check(r.grantsBySource[kPeerSource]==lateGrants&&r.t.io_drain_mshrPending==0&&
      r.t.io_drain_sourceDIdle&&!r.t.io_drain_sinkCBusy&&r.pendingProbes.empty(),
      "late park retained protocol resources or granted peer");
    r.validate(late);
    r.until([&]{return r.grantsBySource[kPeerSource]==lateGrants+1;},"late peer validation retry"); r.idle();
    check(r.returned==bytes(0xf80)&&r.returnedKey.gen==late.gen,"late retry lost ProbeAckData bytes");
    r.release(a,{}, {},6,1,kPeerSource); r.cleanup({{a,late}});
    r.blockedPeerSeq=0;
    r.pass("lineage_unaware_peer_waits_validation");

    check(r.t.io_counts_0==r.t.io_counts_1&&!r.t.io_pending,"unclosed preservation");
    std::cout << "STAGE3_COUNTERS req=" << r.t.io_counts_0 << " ack=" << r.t.io_counts_1
      << " pending_cycles=" << r.t.io_counts_2 << " validation=" << r.t.io_counts_3
      << " stale=" << r.t.io_counts_4 << " duplicate=" << r.t.io_counts_5
      << " outer_put=" << r.puts << " validation_ack_race=" << r.validationAckRace
      << " validation_write_race=" << r.validationWriteRace << " assertions=0 errors=0\n";
    std::cout << "STAGE3_DIRECTED=PASS cycles=" << r.cycles << "\n[END] status=PASS\n";
    r.t.final(); return 0;
  } catch(const std::exception& e) {
    std::cerr << "STAGE3_DIRECTED=FAIL case=" << r.current << " reason=" << e.what() << "\n[END] status=FAIL\n";
    r.t.final(); return 1;
  }
}
