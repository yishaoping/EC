#include "VHierarchyHarness.h"
#include "VHierarchyHarness___024root.h"
#include "verilated.h"
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <tuple>
#include <unordered_map>

using Line = std::array<uint64_t, 8>;
static constexpr uint64_t A=0x80001000ULL, B=0x80002000ULL;
struct Reply {
  unsigned opcode, source, beat;
  uint64_t txn, due;
  Line data;
};
class Test {
public:
  VHierarchyHarness d;
  uint64_t cycle=0, token=0, answer=0;
  bool active=false, issuing=false, restarted=false, terminal=false;
  bool holdMemory=false, holdWriteAck=false, wasStalled=false;
  bool pauseRequest=false;
  bool hostActive=false, hostIssuing=false;
  uint64_t hostAnswer=0;
  unsigned lookupRequests=0;
  unsigned frozenCheckers=0, checkerClockLevels=0;
  std::tuple<unsigned,unsigned,uint64_t,uint64_t,uint64_t,uint64_t> stalled;
  unsigned command=0, cooldown=0, responseDelay=11, writeBeat=0;
  uint64_t writeAddress=0, writeTxn=0;
  uint64_t unpublishedLine=0, unpublishedFirstWord=0xa1;
  unsigned writeSource=0;
  std::unordered_map<uint64_t, Line> dram;
  std::deque<Reply> replies;
  void check(bool ok, const char *why) {
    if (!ok) {
      std::fprintf(stderr,"FAIL cycle=%llu: %s safe=%u epoch=%u stop=%u fatal=%u\n",
        static_cast<unsigned long long>(cycle),why,d.io_safe,d.io_epoch,d.io_stop,d.io_fatal);
      std::exit(1);
    }
  }
  Line &line(uint64_t address) {
    uint64_t block=address & ~63ULL;
    auto it=dram.find(block);
    if (it==dram.end()) { Line base; base.fill(0xa1); it=dram.emplace(block,base).first; }
    return it->second;
  }
  void step() {
    d.clock=0;
    // Independent receiver clocks; freezing one must backpressure the real
    // DCache mailbox through both the request-high and request-low phases.
    for(unsigned i=0;i<4;++i) {
      const unsigned bit=1u<<i;
      if(!(frozenCheckers&bit)) {
        if((cycle/(i+1))&1) checkerClockLevels|=bit;
        else checkerClockLevels&=~bit;
      }
    }
    d.io_checkerClocks=checkerClockLevels;
    d.io_req=active && issuing && !cooldown && !pauseRequest;
    d.io_hostReq=hostActive && hostIssuing;
    d.io_mr=!holdMemory&&(cycle%7)!=3;
    const bool readyReply=!replies.empty() && cycle>=replies.front().due &&
      (!holdWriteAck || replies.front().opcode!=0);
    d.io_rv=readyReply; d.io_ro=0; d.io_rs=0; d.io_rt=0; d.io_rl=0; d.io_rh=0;
    if (readyReply) {
      const auto &r=replies.front();
      d.io_ro=r.opcode; d.io_rs=r.source; d.io_rt=r.txn;
      if (r.opcode==1) { d.io_rl=r.data[2*r.beat]; d.io_rh=r.data[2*r.beat+1]; }
    }
    d.eval();
    const auto header=std::make_tuple(unsigned(d.io_mo),unsigned(d.io_ms),
      uint64_t(d.io_ma),uint64_t(d.io_mt),uint64_t(d.io_ml),uint64_t(d.io_mh));
    if(!d.reset&&wasStalled) check(d.io_mv&&header==stalled,"accepted owner changed A under backpressure");
    wasStalled=!d.reset&&d.io_mv&&!d.io_mr; stalled=header;
    bool ah=d.io_mv && d.io_mr, dh=d.io_rv && d.io_rr;
    unsigned op=d.io_mo, source=d.io_ms;
    uint64_t address=d.io_ma, txn=d.io_mt, lo=d.io_ml, hi=d.io_mh;
    bool accepted=d.io_req && d.io_ready, nack=d.io_nack;
    const bool hostAccepted=d.io_hostReq && d.io_hostReady;
    const bool hostDone=d.io_hostDone;
    const uint64_t hostResult=d.io_hostResult;
    const bool historyRequest=d.io_historyRequest;
    unsigned previousSafe=d.io_safe;
    bool done=d.io_done && d.io_doneReady, response=d.io_response;
    uint64_t result=command==0 ? d.io_responseData : d.io_doneData, doneToken=d.io_doneToken;
    unsigned status=d.io_doneStatus;
    restarted=restarted || bool(d.io_restart);
    d.clock=1; d.eval(); ++cycle; Verilated::timeInc(1);
    if(!d.reset && !historyRequest && d.io_historyRequest) ++lookupRequests;
    check(!Verilated::gotFinish(),"RTL assertion/finish");
    if(d.reset) return;
    check(d.io_safe>=previousSafe && d.io_safe-previousSafe<=1,"SW violated monotonic single-step contract");
    check(!d.io_fatal,"unexpected fail-closed stop");
    if(dh) {
      auto &r=replies.front();
      if(r.opcode==1 && ++r.beat<4) { r.due=cycle+2; } else replies.pop_front();
    }
    if(ah) {
      if(op==4) { // terminal Get, translated from the real coherence Acquire
        check(writeBeat==0,"Get interleaved into a multibeat Put");
        replies.push_back(Reply{1,source,0,txn,cycle+responseDelay,line(address)});
      } else {
        check(op==0 || op==1,"unexpected terminal memory opcode");
        if(!writeBeat) { writeAddress=address; writeSource=source; writeTxn=txn; }
        check(address==writeAddress && source==writeSource && txn==writeTxn,
          "Put header/identity changed before its terminal beat");
        // Figure4 failure bytes must never cross the terminal memory port.
        check((address & ~63ULL)!=A || (lo!=0xa8 && hi!=0xa8),"discarded A8 reached DRAM");
        check(!unpublishedLine || (address & ~63ULL)!=unpublishedLine || (lo==(writeBeat?0xa1:unpublishedFirstWord)&&hi==0xa1),
          "Pending or dead history appeared on an accepted outer Put beat");
        line(address)[2*writeBeat]=lo; line(address)[2*writeBeat+1]=hi;
        if(++writeBeat==4) {
          replies.push_back(Reply{0,source,0,txn,cycle+responseDelay,Line{}}); writeBeat=0;
        }
      }
    }
    if(cooldown) --cooldown;
    if(accepted) issuing=false;
    if(hostAccepted) hostIssuing=false;
    if(hostDone) { check(hostActive,"orphan host response"); hostAnswer=hostResult; hostActive=false; }
    if(active && nack) { issuing=true; cooldown=5; }
    if(active && ((command!=0 && done) || (command==0 && response))) {
      if(command!=0) { check(doneToken==token,"store completed a different owner"); check(status==0,"store was not applied"); }
      answer=result; active=false; issuing=false; terminal=true;
    }
    d.clock=0; d.eval();
  }
  void ticks(unsigned n) { while(n--) step(); }
  template<class F> void until(F predicate,const char *why,unsigned bound=30000) {
    while(!predicate() && bound--) step(); check(predicate(),why);
  }
  void reset() {
    active=issuing=restarted=terminal=false; replies.clear(); dram.clear(); writeBeat=0;
    holdMemory=holdWriteAck=wasStalled=false; responseDelay=11;
    unpublishedLine=0; unpublishedFirstWord=0xa1;
    pauseRequest=false; lookupRequests=0;
    hostActive=hostIssuing=false; hostAnswer=0;
    d.io_holdInnerGrant=0;
    d.io_hostReq=0; d.io_hostWrite=0; d.io_hostAddress=A; d.io_hostData=0;
    frozenCheckers=checkerClockLevels=0; d.io_checkerClocks=0;
    d.io_req=0; d.io_address=A; d.io_data=0; d.io_command=0; d.io_seq=0; d.io_token=0; d.io_size=3;
    d.io_robIdx=0;
    d.io_doneReady=1; d.io_allocate=0; d.io_pass=0; d.io_fail=0; d.io_restartReady=0;
    d.reset=1; ticks(5); d.reset=0; ticks(300);
  }
  void allocate(unsigned seq) { d.io_allocate=seq; step(); d.io_allocate=0; ticks(2); }
  void pass(unsigned seq) {
    d.io_pass=seq; step(); d.io_pass=0;
    until([&]{return d.io_safe==seq;},"safe watermark did not advance");
  }
  void start(unsigned cmd,uint64_t address,unsigned seq,uint64_t data=0,unsigned size=3) {
    check(!active,"overlapping architectural stimulus");
    // The LSU supplies a lane-replicated operand from StoreGen. The fixture
    // enters at DCache and must provide the same word for subword stores.
    if (cmd == 1 && size < 3) {
      const unsigned width = 8u << size;
      const uint64_t lane = data & ((uint64_t{1} << width) - 1);
      data = 0;
      for (unsigned offset = 0; offset < 64; offset += width)
        data |= lane << offset;
    }
    command=cmd; d.io_command=cmd; d.io_address=address; d.io_seq=seq; d.io_data=data; d.io_size=size;
    d.io_token=++token; active=issuing=true; terminal=false; cooldown=0;
  }
  uint64_t access(unsigned cmd,uint64_t address,unsigned seq,uint64_t data=0,unsigned size=3) {
    start(cmd,address,seq,data,size); until([&]{return !active;},"architectural request did not complete");
    return answer;
  }
  void startHost(bool write,uint64_t address,uint64_t data=0) {
    check(!hostActive,"overlapping trusted host requests");
    d.io_hostWrite=write; d.io_hostAddress=address; d.io_hostData=data;
    hostActive=hostIssuing=true;
  }
  uint64_t hostAccess(bool write,uint64_t address,uint64_t data=0) {
    startHost(write,address,data);
    until([&]{return !hostActive;},"trusted host request did not finish",100000);
    return hostAnswer;
  }
  void trustedHostAfterRollback(bool passDuringGap=false) {
    reset(); allocate(1); pass(1); allocate(2);
    d.io_fail=2; step(); d.io_fail=0; resume(2,1); allocate(3);
    if(!passDuringGap) pass(3);
    access(1,A,3,0x80032d50); access(1,A+8,3,0);
    if(!passDuringGap)
      check(hostAccess(false,A)==0x80032d50,"host Get lost the Main tohost pointer");
    startHost(true,A,0);
    const unsigned before=lookupRequests;
    // Poll fromhost concurrently with the host's coherent tohost clear.
    // Withdraw retries after the cold query, as the real LSU may do.
    for(unsigned n=0;n<2000 && lookupRequests==before;++n) {
      if(!active) start(0,A+8,3);
      step();
    }
    check(lookupRequests==before+1,"UNCOVERED: host invalidation did not overlap a cold query");
    check(active && issuing,"UNCOVERED: cold request was already admitted before retry withdrawal");
    pauseRequest=true;
    until([&]{return !d.io_historyRequest&&!d.io_checkerHistoryAcks;},
      "cold lookup did not finish while LSU retries were withdrawn");
    if(passDuringGap) {
      check(d.io_lookupFound&&d.io_selectedSeq==3,
        "UNCOVERED: lookup did not retain Pending3 before SW advancement");
      pass(3);
    }
    until([&]{return !hostActive;},"host clear did not drain during cold retry gap",100000);
    hostAccess(true,A+8,1);
    ticks(30); pauseRequest=false;
    until([&]{return !active;},"cold poll did not resume after trusted host writes");
    check(answer==1,"cold recovery replaced trusted fromhost response with archived bytes");
    check(hostAccess(false,A)==0,"cold recovery resurrected a cleared tohost pointer");
    check(access(0,A+8,3)==1,"subsequent Main load lost trusted fromhost response");
    std::printf("CASE trusted_host_after_rollback pass_during_gap=%u PASS\n",passDuringGap);
  }
  void watermarkAfterGrantOffer() {
    reset();
    for(unsigned seq=1;seq<=6;++seq) { allocate(seq); pass(seq); }
    allocate(7); access(1,A,7,0xa7); allocate(8); access(1,A,8,0xa8);
    until([&]{return d.io_archiveReceipts!=0;},"Pending7 was not archived");
    fail8(); resume(); allocate(9);
    start(0,A,9);
    // First let the stale resident's ReleaseAck finish and the cold load
    // enter its new MSHR. The gate then holds the upcoming Grant, without
    // blocking the earlier coherence cleanup needed to issue that Acquire.
    until([&]{return !issuing;},"cold request was not admitted after old ReleaseAck");
    d.io_holdInnerGrant=1;
    until([&]{return bool(d.io_innerGrantPending);},"cold Acquire never offered a Grant");
    check(d.io_lookupFound&&d.io_selectedSeq==7,"UNCOVERED: missing Pending7 candidate");
    pass(7); ticks(30);
    check(d.io_safe==8&&active,"UNCOVERED: SW did not advance while Grant was held");
    d.io_holdInnerGrant=0;
    until([&]{return !active;},"cold load did not finish after held Grant");
    check(answer==0xa7,"SW advancement after Grant offer discarded the surviving predecessor");
    std::puts("CASE watermark_after_grant_offer PASS");
  }
  void fail8() { d.io_fail=8; step(); d.io_fail=0; }
  void slowCheckerContext() {
    reset();
    for(unsigned seq=1;seq<=6;++seq) { allocate(seq); pass(seq); }
    allocate(7); access(1,A,7,0xa7);
    allocate(8); access(1,A,8,0xa8);
    until([&]{return !d.io_historyRequest&&!d.io_checkerHistoryAcks;},
      "old context handshake did not finish");
    frozenCheckers=8; // Checker hart4 receives no edges while banks finish.
    fail8(); d.io_restartReady=1;
    until([&]{return bool(d.io_historyRequest);},"EVT request was not raised");
    ticks(700);
    check(d.io_historyRequest&&d.io_checkerHistoryAcks==7&&!restarted,
      "source withdrew EVT/restarted before the slow Checker receipt");
    check(d.io_checkerDead8==7,"slow receiver installed context without an edge");
    frozenCheckers=0;
    until([&]{return d.io_checkerHistoryAcks==15;},"slow Checker never acknowledged installed EVT");
    check(d.io_checkerDead8==15,"Checker ACK preceded its installed context");
    frozenCheckers=8;
    until([&]{return !d.io_historyRequest;},"source did not lower after all context receipts");
    ticks(200);
    check(d.io_checkerHistoryAcks==8&&!restarted,
      "restart/new mailbox bypassed the slow return-to-zero receipt");
    frozenCheckers=0;
    until([&]{return restarted;},"Checker ACK return-to-zero did not release restart");
    check(!d.io_checkerHistoryAcks&&d.io_checkerDead8==15,
      "context was cleared at handshake completion");
    d.io_restartReady=0; ticks(5); restarted=false;
    allocate(9);
    check(access(0,A,9)==0xa7,"slow Checker handshake broke Figure4 recovery");
  }
  void resume(unsigned target=8,unsigned epoch=1) {
    until([&]{return d.io_epoch==epoch;},"FAIL did not publish EVT");
    check(d.io_stop && !restarted,"restart bypassed host ready");
    ticks(50); check(!restarted,"restart valid did not honor backpressure");
    d.io_restartReady=1;
    until([&]{return restarted;},"rollback failed to drain/restart",400000);
    check(d.io_restoredSeq==target,"restored the wrong SCP");
    d.io_restartReady=0; ticks(5); check(!d.io_stop,"controller did not resume");
    restarted=false;
  }
  void figure4(bool waitArchive,bool concurrentMiss) {
    reset();
    for(unsigned seq=1;seq<=6;++seq) { allocate(seq); pass(seq); }
    allocate(7); access(1,A,7,0xa7);
    allocate(8); access(1,A,8,0xa8);
    check(d.io_safe==6,"scenario lost pending Seq7");
    check(line(A)[0]==0xa1,"unsafe predecessor was published to DRAM before validation");
    if(waitArchive) until([&]{return d.io_archiveReceipts!=0;},"real L2 never accepted archived predecessor");
    else check(d.io_archiveReceipts==0,
      "UNCOVERED: immediate FAIL stimulus did not overlap the SVB/archive transfer");
    if(concurrentMiss) {
      responseDelay=150;
      start(0,B,8);
      until([&]{return !issuing;},"concurrent miss was not accepted");
      until([&]{return !replies.empty();},"concurrent miss did not reach terminal memory");
    }
    fail8(); resume();
    if(concurrentMiss) { until([&]{return !active;},"accepted old miss lost its response responsibility"); responseDelay=11; }
    allocate(9);
    check(access(0,A,9)==0xa7,"real L1 load returned A8/A1 instead of LatestSurviving A7");
    check(d.io_lookupFound && d.io_selectedSeq==7 && d.io_selectedData==0xa7,
      "L2 history query did not return the actual Seq7 archive");
    check(access(0,A+8,9)==0xa1,"recovery corrupted an unmodified word of the line");
    check(line(A)[0]==0xa1,"rollback wrote unsafe A7/A8 to the DRAM baseline");
    ticks(30);
  }
  void outOfOrderPass() {
    reset();
    for(unsigned seq=1;seq<=4;++seq) allocate(seq);
    d.io_pass=3; step(); d.io_pass=0; ticks(8);
    check(d.io_safe==0,"out-of-order PASS crossed Pending1");
    pass(1); ticks(8); check(d.io_safe==1,"PASS3 crossed Pending2");
    pass(2); until([&]{return d.io_safe==3;},"remembered PASS3 was lost");
    pass(4);
  }
  void coldRecoveryWithRetryGap() {
    reset();
    for(unsigned seq=1;seq<=6;++seq) { allocate(seq); pass(seq); }
    allocate(7); access(1,A,7,0xa7);
    allocate(8); access(1,A,8,0xa8);
    fail8(); resume(); allocate(9);
    unsigned before=lookupRequests;
    start(0,A,9);
    until([&]{return lookupRequests==before+1;},"UNCOVERED: cold recovery never queried history");
    check(issuing,"cold access was accepted before its history query");
    // BOOM LSU arbitrates a fresh retry each cycle. The original lane may
    // not be valid when the query and the dead resident's ReleaseAck finish.
    pauseRequest=true;
    ticks(800);
    check(!d.io_historyRequest && issuing,"lookup did not finish within the retry gap");
    pauseRequest=false;
    until([&]{return !active;},"gapped cold access never finished");
    check(lookupRequests==before+1,"transient LSU retry gap discarded the cold lookup");
    check(answer==0xa7,"gapped cold access lost its pending predecessor");
    check(line(A)[0]==0xa1,"gapped cold access leaked pending or dead data");
    std::puts("CASE cold_recovery_lsu_retry_gap PASS");
  }
  void maskedAtomicAndRepeatedRollback() {
    reset();
    for(unsigned seq=1;seq<=6;++seq) { allocate(seq); pass(seq); }
    allocate(7);
    access(1,A+3,7,0x55,0); // SB changes exactly one byte of the complete line.
    check(access(0,A,7)==0x550000a1ULL,"byte mask changed adjacent bytes");
    check(access(8,A,7,2)==0x550000a1ULL,"AMOADD.D returned the wrong old word");
    check(access(0,A,7)==0x550000a3ULL,"AMO result was not installed");
    // Keep Seq7 pending while Seq8 changes another word in the same line.
    allocate(8);
    check(access(8,A+8,8,2)==0xa1,"cross-segment AMO returned the wrong old word");
    check(d.io_safe==6,"cross-segment AMO consumed Pending7");
    check(access(0,A+8,8)==0xa3,"cross-segment AMO did not apply exactly once");
    access(1,A+4,8,0x88,0);
    until([&]{return d.io_archiveReceipts!=0;},"masked/AMO predecessor not archived");
    fail8(); resume(); allocate(9);
    check(access(0,A,9)==0x550000a3ULL,"rollback lost latest same-segment masked/AMO bytes");
    check(access(0,A+8,9)==0xa1,"full-line archive corrupted untouched word");
    check(line(A)[0]==0xa1,"pending masked/AMO version escaped to DRAM");
    // Keep Seq7 pending across a second disjoint discarded suffix. A new
    // Current produced after the first restart must survive the next one.
    access(1,A,9,0xa9); allocate(10); access(1,A,10,0xaa);
    d.io_fail=10; step(); d.io_fail=0; resume(10,2); allocate(11);
    check(access(0,A,11)==0xa9,"second rollback revived a discarded Current");
    check(line(A)[0]==0xa1 && d.io_safe==6,"continuous rollback lost the pending prefix");
  }
  void dirtyVictimDuringRollback(bool earlierFail) {
    reset();
    // The production fixture has four L2 ways, one reserved for Checker
    // fetch. Three coherent dirty owners fill the ordinary set. A fourth
    // Acquire therefore probes a real L1 victim and emits a multibeat WB.
    constexpr uint64_t base=0x80100000ULL, stride=0x4000;
    allocate(1);
    for(unsigned i=0;i<3;++i) access(1,base+stride*i,1,0xc0+i);
    pass(1);
    for(unsigned seq=2;seq<=6;++seq) { allocate(seq); pass(seq); }
    allocate(7); allocate(8); // Pending7 survives FAIL8 throughout.
    responseDelay=200;
    start(0,base+3*stride,8);
    until([&]{return writeBeat!=0;},"UNCOVERED: no accepted dirty victim multibeat writeback");
    const uint64_t victim=writeAddress;
    check(victim>=base&&victim<base+3*stride&&(victim-base)%stride==0,"writeback was not a seeded dirty owner");
    const unsigned index=(victim-base)/stride;
    holdMemory=true;
    fail8();
    until([&]{return d.io_epoch==1;},"EVT waited for stalled safe writeback before publication");
    check(writeBeat!=0,"UNCOVERED: writeback completed before EVT update");
    check(d.io_safe==6,"rollback consumed Pending7");
    ticks(20); // stable accepted transaction across the actual context update
    if(earlierFail) {
      // An older error must replace the pinned SCP even while the outer
      // writeback owner and original miss cannot reach their terminal beats.
      d.io_fail=7; step(); d.io_fail=0;
      until([&]{return d.io_epoch==2;},"earlier FAIL did not extend EVT during the stalled writeback");
      until([&]{return d.io_historyRequest && d.io_checkerHistoryAcks==15;},
        "second EVT was not installed by all Checkers during stalled writeback");
      until([&]{return !d.io_historyRequest && !d.io_checkerHistoryAcks;},
        "second EVT did not complete its receipt handshake during stalled writeback");
      check(writeBeat!=0&&d.io_stop&&!restarted,"earlier FAIL abandoned the accepted writeback owner");
    }
    holdMemory=false;
    resume(earlierFail?7:8,earlierFail?2:1);
    until([&]{return !active;},"accepted request lost terminal response after dirty victim ACK");
    check(line(victim)[0]==0xc0+index,"rollback lost a surviving safe dirty victim");
    for(unsigned w=1;w<8;++w) check(line(victim)[w]==0xa1,"multibeat WB corrupted an untouched neighbor");
    allocate(9);
    for(unsigned i=0;i<3;++i)
      check(access(0,base+stride*i,9)==0xc0+i,"lazy recovery lost a safe probed/writeback image");
    responseDelay=11;
  }
  void pendingHistoryWithOuterOwner(bool earlierFail) {
    reset();
    // The production fixture has four L2 ways, one reserved for Checker
    // fetch. Three coherent dirty owners fill the ordinary set. A fourth
    // Acquire therefore probes a real L1 victim and emits a multibeat WB.
    constexpr uint64_t base=0x80100000ULL, stride=0x4000;
    allocate(1);
    for(unsigned i=0;i<3;++i) access(1,base+stride*i,1,0xc0+i);
    pass(1);
    for(unsigned seq=2;seq<=6;++seq) { allocate(seq); pass(seq); }
    constexpr uint64_t pending=0x80003040ULL; // Different L2 set from victim.
    unpublishedLine=pending;
    allocate(7); access(1,pending,7,0xa7);
    allocate(8); access(1,pending,8,0xa8);
    until([&]{return d.io_archiveReceipts!=0;},"UNCOVERED: Pending7 absent from L2 history");
    check(d.io_safe==6&&line(pending)[0]==0xa1,"Pending image published before validation");
    responseDelay=200;
    start(0,base+3*stride,8);
    until([&]{return writeBeat!=0;},"UNCOVERED: no accepted dirty victim multibeat writeback");
    const uint64_t victim=writeAddress;
    check(victim>=base&&victim<base+3*stride&&(victim-base)%stride==0,"writeback was not a seeded dirty owner");
    const unsigned index=(victim-base)/stride;
    holdMemory=true;
    fail8();
    until([&]{return d.io_epoch==1;},"EVT waited for stalled safe writeback before publication");
    check(writeBeat!=0,"UNCOVERED: writeback completed before EVT update");
    check(d.io_safe==6,"rollback consumed Pending7");
    ticks(20); // stable accepted transaction across the actual context update
    if(earlierFail) {
      // An older error must replace the pinned SCP even while the outer
      // writeback owner and original miss cannot reach their terminal beats.
      d.io_fail=7; step(); d.io_fail=0;
      until([&]{return d.io_epoch==2;},"earlier FAIL did not extend EVT during the stalled writeback");
      until([&]{return d.io_historyRequest && d.io_checkerHistoryAcks==15;},
        "second EVT was not installed by all Checkers during stalled writeback");
      until([&]{return !d.io_historyRequest && !d.io_checkerHistoryAcks;},
        "second EVT did not complete its receipt handshake during stalled writeback");
      check(writeBeat!=0&&d.io_stop&&!restarted,"earlier FAIL abandoned the accepted writeback owner");
    }
    holdMemory=false;
    resume(earlierFail?7:8,earlierFail?2:1);
    until([&]{return !active;},"accepted request lost terminal response after dirty victim ACK");
    check(line(victim)[0]==0xc0+index,"rollback lost a surviving safe dirty victim");
    for(unsigned w=1;w<8;++w) check(line(victim)[w]==0xa1,"multibeat WB corrupted an untouched neighbor");
    allocate(9);
    for(unsigned i=0;i<3;++i)
      check(access(0,base+stride*i,9)==0xc0+i,"lazy recovery lost a safe probed/writeback image");
    const uint64_t expected=earlierFail?0xa1:0xa7;
    check(access(0,pending,9)==expected,"outer owner/EVT overlap lost latest surviving image");
    check(access(0,pending+8,9)==0xa1,"overlap recovery corrupted an unmodified neighbor");
    check(line(pending)[0]==0xa1,"dead or Pending history escaped while old outer owner drained");
    std::printf("CASE pending_history_outer_owner earlier_fail=%u PASS\n",earlierFail);
    responseDelay=11;
  }
  void evtCapacityMaintenance(bool earlierFail=false) {
    reset();
    constexpr uint64_t retained=0x80003040ULL; // Different L2 set from B.
    // Safe gaps make genuinely disjoint dead intervals. The 32nd rollback
    // must perform actual cache/history reconciliation, then the 33rd must
    // restart normally. No host fake maintenance acknowledgement is supplied.
    for(unsigned i=0;i<34;++i) {
      const unsigned gap=2*i+1, bad=gap+1;
      allocate(gap);
      // This unmodified safe dirty line stays in L1 until the rare sweep,
      // ensuring that service really depends on a physical outer data ACK.
      if(i==0) access(1,retained,gap,0xc001);
      access(1,B,gap,0xd000+gap);
      if (!earlierFail || i!=31) pass(gap);
      allocate(bad); access(1,B,bad,0xe000+bad);
      d.io_fail=bad; step(); d.io_fail=0;
      if(i==31) {
        if(earlierFail) {
          until([&]{return d.io_epoch==32;},"full EVT did not accept FAIL64");
          ticks(100);
          check(d.io_safe==62&&!d.io_maintenanceRequest&&d.io_stop&&!restarted,
            "physical maintenance bypassed surviving Pending63");
          d.io_fail=63; step(); d.io_fail=0;
          until([&]{return d.io_epoch==33;},"earlier FAIL63 could not merge a full EVT");
          ticks(100);
          check(!d.io_maintenanceRequest,"merged EVT retained unnecessary physical maintenance");
          resume(63,33);
          allocate(65);
          check(access(0,B,65)==0xd000+61,"earlier FAIL recovered discarded gap63");
          check(line(B)[0]==0xd000+61,"earlier FAIL published discarded gap63/64");
          std::puts("CASE full_evt_earlier_fail_frees_interval PASS");
          return;
        }
        check(line(retained)[0]==0xa1,"UNCOVERED: retained safe dirty owner was published before maintenance");
        until([&]{return bool(d.io_maintenanceRequest);},"full EVT did not request real capacity service");
        holdMemory=true;
        until([&]{return d.io_mv&&d.io_mo==0;},"UNCOVERED: maintenance had no real safe data write",400000);
        ticks(40);
        check(d.io_epoch==32&&!restarted,"EVT retired references before physical acknowledgements");
        check(!d.io_maintenanceAck,"UNCOVERED: service ACKed without stalled memory/probe work");
        holdWriteAck=true;
        holdMemory=false;
        until([&]{return !replies.empty()&&replies.front().opcode==0;},
          "UNCOVERED: maintenance did not reach a terminal memory ACK",400000);
        ticks(40);
        check(d.io_epoch==32&&!d.io_maintenanceAck&&!restarted,
          "maintenance compacted while the memory terminal ACK was held");
        holdWriteAck=false;
        until([&]{return d.io_epoch==0;},"physical maintenance did not compact the EVT",400000);
        frozenCheckers=8;
        d.io_restartReady=1;
        until([&]{return bool(d.io_historyRequest);},"compacted context was not published");
        ticks(700);
        check(d.io_checkerHistoryAcks==7&&d.io_checkerDead8==8&&d.io_stop&&!restarted,
          "compaction/restart bypassed installation of the empty Checker context");
        frozenCheckers=0;
        d.io_restartReady=0;
      }
      const unsigned epoch=i<31?i+1:i-31;
      resume(bad,epoch);
      if(i==31) {
        check(!d.io_maintenanceRequest&&!d.io_maintenanceAck,"maintenance four-phase owner leaked after restart");
        check(line(B)[0]==0xd000+gap,"maintenance published failed bytes or lost latest safe baseline");
        check(line(retained)[0]==0xc001,"maintenance lost unmodified safe dirty data");
      }
      check(d.io_safe==bad,"safe frontier did not cover the discarded suffix");
    }
    allocate(69);
    check(access(0,B,69)==0xd000+67,"post-compaction lazy access revived a retired dead image");
  }

  void realTrackedC() {
    reset();
    constexpr uint64_t address = A;
    check(hostAccess(true, address, 0xabc0) == 0, "host seed failed");
    unpublishedLine=address; unpublishedFirstWord=0xabc0;
    for (unsigned seq = 1; seq <= 6; ++seq) { allocate(seq); pass(seq); }
    allocate(7); access(1, address, 7, 0xa7);
    allocate(8); access(1, address, 8, 0xa8);
    until([&] { return d.io_archiveReceipts != 0; }, "missing Pending7 receipt");
    holdWriteAck = true;
    startHost(false, address);
    const auto full = [&] {
      auto* r = d.rootp;
      return r->HierarchyHarness__DOT__l2__DOT__mods_0__DOT__bufferedC__DOT__ptr_match &&
             r->HierarchyHarness__DOT__l2__DOT__mods_0__DOT__bufferedC__DOT__maybe_full;
    };
    const auto tracked = [&] {
      auto* r = d.rootp;
      return full() && r->HierarchyHarness__DOT__l2__DOT__mods_0__DOT__bufferedC__DOT__ram_user_cache_image_valid[0] &&
             r->HierarchyHarness__DOT__l2__DOT__mods_0__DOT__bufferedC__DOT__ram_user_cache_image_valid[1] &&
             r->HierarchyHarness__DOT__l2__DOT__mods_0__DOT__bufferedC__DOT__ram_user_cache_image_contentSeq[0] == 8 &&
             r->HierarchyHarness__DOT__l2__DOT__mods_0__DOT__bufferedC__DOT__ram_user_cache_image_contentSeq[1] == 8;
    };
    until(tracked, "UNCOVERED: real L1 Seq8 C did not fill L2 buffer");
    until([&] { return !replies.empty() && replies.front().opcode == 0; },
          "UNCOVERED: no BASE ACK to hold");
    check(tracked() && replies.front().txn == writeTxn && writeAddress == address,
          "expected same-address accepted BASE write while Seq8 filled C");
    check(line(address)[0] == 0xabc0, "wrong same-address BASE published");
    auto retained = line(address);
    for (unsigned word = 1; word < 8; ++word) check(retained[word] == 0xa1, "wrong BASE neighbor");
    fail8();
    until([&] { return d.io_epoch == 1; }, "first EVT did not install");
    check(tracked() && !restarted, "first EVT discarded the C channel owner");
    d.io_fail = 7; step(); d.io_fail = 0;
    until([&] { return d.io_epoch == 2; }, "earlier EVT did not install");
    until([&] { return !d.io_historyRequest && !d.io_checkerHistoryAcks; },
          "earlier EVT handshake did not clear");
    check(tracked() && d.io_stop && !restarted, "earlier EVT overtook C and outer ACK");
    holdWriteAck = false;
    resume(7, 2);
    until([&] { return !hostActive; }, "trusted host did not complete after real C drained");
    check(hostAnswer == 0xabc0, "trusted host observed dead data");
    allocate(9);
    check(access(0, address, 9) == 0xabc0 && line(address) == retained,
          "recovery changed the retained BASE");
    std::puts("CASE real_tracked_c_outer_owner PASS");
  }

  void alternatingColdHandoff(bool olderTakesOver) {
    reset();
    for(unsigned seq=1;seq<=6;++seq) { allocate(seq); pass(seq); }
    allocate(7); access(1,A,7,0xa7); allocate(8); access(1,A,8,0xa8);
    fail8(); resume(); allocate(9);
    constexpr uint64_t first=0x80004000ULL, other=0x80005000ULL;
    line(first).fill(0x1111); line(other).fill(0x2222);
    start(0,first,9);
    // A denied LSU offer can change. An older request can take over; a
    // younger retry must leave the result available for the original owner.
    bool retryOther = true;
    for(unsigned n=0;n<8000&&active;++n) {
      if (issuing) {
        bool lookupReady = d.rootp->HierarchyHarness__DOT__l1__DOT__memoryRecoveryState == 7;
        bool offerOther = lookupReady && (olderTakesOver || retryOther);
        retryOther = !offerOther;
        d.io_address = offerOther ? other : first;
        d.io_robIdx = offerOther == olderTakesOver ? 1 : 2;
      }
      step();
    }
    std::printf("COLD_HANDOFF lookups=%u active=%u issuing=%u\n",lookupRequests,active,issuing);
    check(!active,"cold-query handoff livelocked under LSU arbitration");
    check(answer == (olderTakesOver ? 0x2222 : 0x1111),"cold-query handoff returned incorrect baseline");
    d.io_robIdx = 0;
    check(access(0, olderTakesOver ? first : other, 9) == (olderTakesOver ? 0x1111 : 0x2222),
      "second cold address did not make progress after handoff");
    std::printf("CASE alternating_cold_handoff older_takes_over=%u PASS\n", unsigned(olderTakesOver));
  }

  void refillMigratedCurrent() {
    reset();
    allocate(1);
    access(1,A,1,0x7777);
    // Keep Seq 1 pending while the same-set misses drive A out of L1 and L2.
    for (unsigned i=1; i<=32; ++i)
      access(0, A + i*4096, 1);
    check(d.io_safe==0 && line(A)[0]==0xa1,"unsafe Current reached DRAM");
    check(access(0,A,1)==0x7777,"ordinary refill lost migrated Current");
    access(1,A+1,1,0x88,0);
    check(access(0,A,1)==0x8877,"same-sequence byte update lost its predecessor");
    // Evict the new dirty L1 owner before checking the terminal memory.
    for (unsigned i=33; i<=40; ++i)
      access(0, A + i*4096, 1);
    check(line(A)[0]==0xa1,"byte update reached DRAM before validation");
    pass(1);
    until([&]{return line(A)[0]==0x8877;},"updated Current never reached DRAM");
    std::puts("CASE refill_migrated_current PASS");
  }

};
int main(int argc,char **argv) {
  Verilated::commandArgs(argc,argv);
  Test t;
  t.realTrackedC();
  t.alternatingColdHandoff(true);
  t.alternatingColdHandoff(false);
  t.refillMigratedCurrent();
  t.watermarkAfterGrantOffer();
  t.trustedHostAfterRollback();
  t.trustedHostAfterRollback(true);
  t.outOfOrderPass();
  t.coldRecoveryWithRetryGap();
  t.slowCheckerContext();
  t.figure4(true,false);  // A7 has migrated to production L2 history.
  t.figure4(false,false); // FAIL overlaps automatic SVB archive migration.
  t.figure4(true,true);   // Accepted old miss owns its real late memory response.
  t.maskedAtomicAndRepeatedRollback();
  t.dirtyVictimDuringRollback(false);
  t.dirtyVictimDuringRollback(true);
  t.pendingHistoryWithOuterOwner(false);
  t.pendingHistoryWithOuterOwner(true);
  t.evtCapacityMaintenance();
  t.evtCapacityMaintenance(true);
  std::puts("PALIMPSEST_HIERARCHY_FIGURE4=PASS (BOOM end-to-end execution still required)");
  t.d.final(); return 0;
}
