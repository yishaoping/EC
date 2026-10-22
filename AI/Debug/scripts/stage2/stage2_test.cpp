#include "VStage2Harness.h"
#include "verilated.h"
#include <array>
#include <cstdint>
#include <deque>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

static std::string activeCase = "setup";
static void check(bool ok, const std::string& why) {
  if (!ok) {
    std::cerr << "STAGE2_CHECK_FAIL case=" << activeCase
              << " reason=" << why << std::endl;
    throw std::runtime_error(why);
  }
}
struct Key { uint32_t gen=0, seq=0; uint16_t writer=0; bool valid=false; };
static bool sameKey(const Key& a, const Key& b) {
  return a.gen==b.gen && a.seq==b.seq && a.writer==b.writer && a.valid==b.valid;
}
struct Image { std::array<uint64_t,8> words{}; Key key; };
struct Reply { unsigned op, source, param, beat=0; Image image; bool stale=false; };
struct Event { bool sdWrite, sdAck, sdPop, probeAccept, sdAccept; unsigned sdBeat, sdOpcode; uint64_t sdData, sdHi; };
static void checkImage(const Image& image, uint64_t first) {
  for (unsigned i=0;i<8;i++) check(image.words[i]==(i?0:first),"full predecessor image mismatch");
}
class Test {
 public:
  VStage2Harness t;
  uint64_t cycle=0, token=0, result=0;
  bool active=false, issuing=false, ackAllowed=true, cAllowed=true;
  unsigned command=0, cooldown=0, releases=0, probes=0, cbeat=0;
  uint64_t address=0, operand=0, seq=0;
  std::map<uint64_t,Image> memory;
  std::deque<Reply> replies;
  Image cimage, lastRelease;
  bool effectForbidden=false;
  uint64_t caddress=0;
  unsigned copcode=0, csource=0;
  unsigned msAcquires=0, msDirs=0, msWrites=0, msReplies=0, msAcquireParam=0;
  unsigned msDirState=0, msReplyOpcode=0;
  uint32_t msDirSeq=0;
  bool msDirTracked=false, msDirDirty=false, msReplyDenied=false;
  uint64_t msWritten=0, msReturned=0;
  Key msDirKey, msReplyKey;
  void guardEffect() {
    check(!effectForbidden,"overlapping effect guard"); effectForbidden=true;
    std::cout<<"STAGE2_STIM FORBID req="<<std::hex<<token<<std::dec<<std::endl;
  }
  void allowEffect() {
    check(effectForbidden,"effect guard not active"); effectForbidden=false;
    std::cout<<"STAGE2_STIM ALLOW req="<<std::hex<<token<<std::dec<<std::endl;
  }
  Test() {
    t.clock=0; t.reset=1;
    t.io_req=0; t.io_addr=0; t.io_data=0; t.io_cmd=0; t.io_seq=0; t.io_token=0;
    t.io_alloc=0; t.io_pass=0; t.io_doneReady=1; t.io_forceOrder=1;
    t.io_probe=0; t.io_probeAddr=0; t.io_probeParam=2;
    t.io_sdReq=0; t.io_sdClean=0; t.io_sdRead=0; t.io_sdGrant=0; t.io_sdBankReady=1; t.io_sdAckReady=1; t.io_sdData=0;
    t.io_msAllocate=0; t.io_msDirectory=0; t.io_msGrant=0; t.io_msDeny=0; t.io_msReady=0;
    t.io_msOpcode=0; t.io_msOldData=0; t.io_msOperand=0;
    t.io_msOldKey_valid=0; t.io_msOldKey_generation=0; t.io_msOldKey_writer=0; t.io_msOldKey_contentSeq=0;
    for (int i=0;i<12;i++) step();
    t.reset=0;
    for (int i=0;i<100;i++) step();
  }
  Event step() {
    t.io_aReady=1; t.io_cReady=cAllowed && cycle%4!=0;
    t.io_dValid=0; t.io_dOpcode=0; t.io_dParam=0; t.io_dSource=0;
    t.io_dLo=0; t.io_dHi=0;
    t.io_dKey_valid=0; t.io_dKey_writer=0; t.io_dKey_generation=0; t.io_dKey_contentSeq=0;
    if (!replies.empty() && (replies.front().op!=6 || ackAllowed || replies.front().stale)) {
      const auto& d=replies.front(); const auto& k=d.image.key;
      t.io_dValid=1; t.io_dOpcode=d.op; t.io_dParam=d.param; t.io_dSource=d.source;
      t.io_dLo=d.image.words[d.beat*2]; t.io_dHi=d.image.words[d.beat*2+1];
      t.io_dKey_valid=k.valid; t.io_dKey_writer=k.writer;
      t.io_dKey_generation=k.gen; t.io_dKey_contentSeq=k.seq;
    }
    if (!t.reset && active && issuing && cooldown==0) {
      t.io_req=1; t.io_addr=address; t.io_data=operand; t.io_cmd=command;
      t.io_seq=seq; t.io_token=token;
    } else t.io_req=0;
    t.clock=0; t.eval();
    const bool accepted=t.io_req && t.io_ready;
    const bool dh=t.io_dValid && t.io_dReady;
    const bool ah=t.io_aValid && t.io_aReady;
    const bool ch=t.io_cValid && t.io_cReady;
    const bool done=t.io_done && t.io_doneToken==token;
    const bool response=t.io_response;
    const bool nack=t.io_nack;
    const uint64_t answer=done?t.io_result:t.io_responseData;
    const unsigned as=t.io_aSource, ap=t.io_aParam, cs=t.io_cSource, cop=t.io_cOpcode;
    const uint64_t aa=t.io_aAddr & ~63ULL, ca=t.io_cAddr & ~63ULL;
    const uint64_t cl=t.io_cLo, chi=t.io_cHi;
    const Key ck{uint32_t(t.io_cKey_generation),uint32_t(t.io_cKey_contentSeq),uint16_t(t.io_cKey_writer),bool(t.io_cKey_valid)};
    const Event e{bool(t.io_sdWrite),bool(t.io_sdAck),bool(t.io_sdPop),bool(t.io_probe && t.io_probeReady),bool(t.io_sdReq && t.io_sdReady),unsigned(t.io_sdBeat),unsigned(t.io_sdOpcode),t.io_sdWriteData,t.io_sdWriteHi};
    if (!t.reset) {
      if (t.io_msAcquire) { ++msAcquires; msAcquireParam=t.io_msAcquireParam; }
      if (t.io_msDir) {
        ++msDirs; msDirSeq=t.io_msDirSeq; msDirTracked=t.io_msDirTracked;
        msDirState=t.io_msDirState; msDirDirty=t.io_msDirDirty;
        msDirKey=Key{uint32_t(t.io_msDirKey_generation),uint32_t(t.io_msDirKey_contentSeq),
                     uint16_t(t.io_msDirKey_writer),bool(t.io_msDirKey_valid)};
      }
      if (t.io_msWrite) { ++msWrites; msWritten=t.io_msWriteData; }
      if (t.io_msReply) {
        ++msReplies; msReturned=t.io_msReplyData; msReplyDenied=t.io_msReplyDenied;
        msReplyOpcode=t.io_msReplyOpcode;
        msReplyKey=Key{uint32_t(t.io_msReplyKey_generation),uint32_t(t.io_msReplyKey_contentSeq),
                       uint16_t(t.io_msReplyKey_writer),bool(t.io_msReplyKey_valid)};
      }
    }
    t.clock=1; t.eval(); ++cycle; Verilated::timeInc(1);
    if (Verilated::gotFinish()) throw std::runtime_error("RTL stopped/asserted");
    if (t.reset) return e;
    if (dh) {
      auto& d=replies.front();
      if (d.op==6 && !d.stale && effectForbidden) allowEffect();
      if (d.op==5 && ++d.beat<4) {} else replies.pop_front();
    }
    if (ah) {
      // D opcodes: Grant=4, GrantData=5, ReleaseAck=6.
      replies.push_back(Reply{ap==2?4U:5U,as,ap==0?1U:0U,0,memory[aa]});
    }
    if (ch) {
      const bool data=(cop==5 || cop==7); // C ProbeAckData / ReleaseData
      if (cbeat==0) { cimage=Image{}; caddress=ca; copcode=cop; csource=cs; }
      else check(caddress==ca && copcode==cop && csource==cs && sameKey(cimage.key,ck),
                 "C transaction header/image changed between accepted beats");
      cimage.key=ck;
      if (data) { cimage.words[cbeat*2]=cl; cimage.words[cbeat*2+1]=chi; }
      if (!data || ++cbeat==4) {
        if (data) memory[ca]=cimage;
        if (cop==6 || cop==7) {
          ++releases; lastRelease=cimage;
          replies.push_back(Reply{6,cs,0,0,cimage});
        } else ++probes;
        cbeat=0;
      }
    }
    if (cooldown) --cooldown;
    if (accepted) issuing=false;
    if (active && nack) { issuing=true; cooldown=5; }
    if (active && (done || (response && (command==0 || command==6)))) {
      result=answer; active=false; issuing=false;
    }
    return e;
  }
  void ticks(unsigned n) { while (n--) step(); }
  template<class F> void until(F f, const std::string& why, unsigned bound=8000) {
    while (!f() && bound--) step();
    check(f(), "timeout: "+why);
  }
  void start(unsigned cmd, uint64_t addr, unsigned package, uint64_t data=0) {
    check(!active,"overlapping stimulus");
    command=cmd; address=addr; seq=package; operand=data; ++token;
    active=true; issuing=true; cooldown=0;
  }
  uint64_t op(unsigned cmd, uint64_t addr, unsigned package, uint64_t data=0) {
    start(cmd,addr,package,data); until([&]{return !active;},"request terminal"); return result;
  }
  void pass(unsigned package) {
    t.io_pass=package; step(); t.io_pass=0;
    until([&]{return t.io_safe>=package;},"functional safe watermark");
  }
  void staleAck() {
    check(!replies.empty() && replies.front().op==6,"stale ACK needs a pending release");
    Reply d=replies.front(); --d.image.key.gen; d.stale=true; replies.push_front(d);
    ticks(20); check(active,"stale ACK released new image");
  }
  void prematureAck() {
    // The preservation request may spend several cycles behind the WB arbiter
    // before its first C beat becomes visible. Wait for the actual held-valid
    // handshake instead of sampling one arbitrary cycle; this keeps the test
    // about ACK-before-C-fire rather than scheduler latency.
    bool stalled=false, validSeen=false, fireSeen=false;
    for (unsigned bound=0; bound<800 && !stalled; ++bound) {
      step();
      validSeen = validSeen || bool(t.io_cValid);
      fireSeen = fireSeen || bool(t.io_cValid && t.io_cReady);
      stalled = t.io_cValid && !t.io_cReady;
    }
    if (!stalled) {
      // Keep the precondition failure actionable. A missing C valid means the
      // preservation request was never admitted; a continuously-ready C means
      // the test missed the only point at which an early ACK is meaningful.
      const std::string reason = !validSeen
        ? "preservation C beat was never issued"
        : fireSeen ? "preservation C beat never stalled before completion"
                   : "preservation C beat did not expose held valid";
      std::cerr << "STAGE2_CHECK_FAIL case=" << activeCase
                << " reason=" << reason
                << " c_valid_seen=" << validSeen
                << " c_fire_seen=" << fireSeen
                << " releases=" << releases
                << " active=" << active << std::endl;
      throw std::runtime_error(reason);
    }
    Image image;
    image.key=Key{uint32_t(t.io_cKey_generation),uint32_t(t.io_cKey_contentSeq),
                  uint16_t(t.io_cKey_writer),bool(t.io_cKey_valid)};
    // Mark as fault injection so the test does not grant effect permission.
    replies.push_front(Reply{6,unsigned(t.io_cSource),0,0,image,true});
    ticks(20); check(active,"matching-key ACK before full C transfer released image");
  }
  void invalidate(uint64_t addr) {
    const unsigned before=probes;
    t.io_probeAddr=addr; t.io_probeParam=2; t.io_probe=1;
    bool accepted=false;
    for (unsigned bound=0;bound<8000 && !accepted;bound++) accepted=step().probeAccept;
    check(accepted,"probe admission timeout"); t.io_probe=0;
    until([&]{return probes>before;},"ProbeAck[Data]"); ticks(10);
  }
  void read(uint64_t addr, uint64_t expected) {
    check(op(0,addr,0)==expected,"data mismatch at "+std::to_string(addr));
  }
  void trustedA(unsigned opcode, bool denied) {
    check(!t.io_msActive,"previous L2 MSHR transaction still active");
    msAcquires=msDirs=msWrites=msReplies=0;
    msWritten=msReturned=0;
    const Key old{0x81234567U,0x10203U,0x91abU,true};
    constexpr uint64_t oldData=0x1020304050607080ULL, operandData=0x1112131415161718ULL;
    t.io_msOldKey_valid=old.valid; t.io_msOldKey_generation=old.gen;
    t.io_msOldKey_writer=old.writer; t.io_msOldKey_contentSeq=old.seq;
    t.io_msOldData=oldData; t.io_msOperand=operandData;
    t.io_msOpcode=opcode; t.io_msDeny=denied; t.io_msReady=0;
    t.io_msAllocate=1; step(); t.io_msAllocate=0;
    t.io_msDirectory=1; step(); t.io_msDirectory=0;
    ticks(5); check(msAcquires==0 && msDirs==0,"MSHR schedule bypassed ready");
    t.io_msReady=1; until([&]{return msAcquires==1;},"L2 BtoT acquire");
    check(msAcquireParam==2,"resident BRANCH did not request BtoT upgrade");
    t.io_msReady=0; ticks(7);
    check(msDirs==0 && msReplies==0 && msWrites==0,"MSHR executed before outer response");
    t.io_msGrant=1; step(); t.io_msGrant=0;
    ticks(5); check(msDirs==0 && msReplies==0 && msWrites==0,"MSHR ignored retirement backpressure");
    t.io_msReady=1;
    until([&]{return msDirs>=1 && msReplies>=1 && (denied || msWrites>=1) && !t.io_msActive;},"L2 trusted A retirement");
    ticks(12); t.io_msReady=0;
    check(msAcquires==1 && msDirs==1 && msReplies==1 && msWrites==(denied?0U:1U),"duplicate/lost/denied L2 bank retirement");
    // Independent oracle: a denied operation cannot create new bytes or lose
    // the seeded speculative identity. Successful controls must create BASE.
    const Key expected=denied?old:Key{};
    check(sameKey(msDirKey,expected),"denied/success directory image identity mismatch");
    check(msDirSeq==(denied?old.seq:0) && msDirTracked==denied,"directory packet provenance lost");
    check(msDirState==(denied?1U:3U) && msDirDirty==!denied,"directory permission/dirty mismatch");
    check(msReplyDenied==denied && msReplyOpcode==(opcode==2?1U:0U),"A response denial/opcode mismatch");
    check(sameKey(msReplyKey,expected),"SourceD reply lost directory image identity");
    const uint64_t newData=opcode==2?oldData+operandData:operandData;
    if (!denied) check(msWritten==newData,"successful control had no data effect");
    if (opcode==2) check(msReturned==oldData,"AMO did not return original data");
    std::cout<<"STAGE2_MSHR opcode="<<opcode<<" denied="<<denied
             <<" acquires="<<msAcquires<<" directory="<<msDirs<<" replies="<<msReplies<<" writes="<<msWrites
             <<" gen="<<std::hex<<msDirKey.gen<<" seq="<<msDirKey.seq<<" writer="<<msDirKey.writer
             <<" data="<<msWritten<<std::dec<<std::endl;
  }
};
int main(int argc,char** argv) {
  Verilated::commandArgs(argc,argv);
  try {
    Test x; constexpr uint64_t A=0x80001000ULL;
    activeCase = "safe_predecessor_backpressure_delayed_stale_ack";
    for (unsigned p=1;p<=8;p++) { x.t.io_alloc=p; x.step(); }
    x.t.io_alloc=0;
    x.op(1,A,0,0x10); x.read(A,0x10); x.op(1,A+0x1000,0,0x20);
    unsigned n=x.releases;
    x.ackAllowed=false; x.cAllowed=false; x.start(1,A,1,0x11);
    x.guardEffect();
    x.ticks(80); check(x.active && x.releases==n,"C backpressure bypass");
    x.prematureAck();
    x.cAllowed=true; x.until([&]{return x.releases>n;},"safe predecessor release");
    checkImage(x.memory[A],0x10);
    x.ticks(80); check(x.active,"request-sent used as preservation completion");
    x.invalidate(A+0x1000);
    check(x.memory[A+0x1000].words[0]==0x20 && x.active,"probe blocked behind voluntary ACK");
    x.staleAck(); x.ackAllowed=true; x.until([&]{return !x.active;},"matched receipt"); x.read(A,0x11);
    std::cout<<"CASE safe_predecessor_backpressure_delayed_stale_ack PASS\n";
    activeCase = "same_package_repeat";
    n=x.releases; x.op(1,A,1,0x12); x.op(1,A,1,0x13); x.read(A,0x13);
    check(x.releases==n,"same package requested preservation");
    std::cout<<"CASE same_package_repeat PASS\n";
    activeCase = "cross_package_wait_safe_then_receipt";
    x.ackAllowed=false; x.start(1,A,2,0x21); x.guardEffect(); x.ticks(100);
    check(x.active && x.releases==n,"unsafe cross-package overwrite");
    x.pass(1); x.until([&]{return x.releases>n;},"safe transition release");
    checkImage(x.memory[A],0x13);
    x.ticks(60); check(x.active,"cross-package resumed before ACK");
    x.staleAck(); x.ackAllowed=true; x.until([&]{return !x.active;},"cross-package terminal"); x.read(A,0x21);
    std::cout<<"CASE cross_package_wait_safe_then_receipt PASS\n";
    activeCase = "normal_amo_sc_success_failure";
    check(x.op(8,A,2,1)==0x21,"AMO old value"); x.read(A,0x22);
    check(x.op(6,A,2)==0x22,"LR old value"); check(x.op(7,A,2,0x23)==0,"SC success");
    check(x.op(7,A,2,0xbad)==1,"SC failure"); x.read(A,0x23);
    std::cout<<"CASE normal_amo_sc_success_failure PASS\n";
    activeCase = "cross_package_amo_sc_invalidation_refill";
    n=x.releases; x.ackAllowed=false; x.start(8,A,3,1); x.guardEffect(); x.ticks(100);
    check(x.active && x.releases==n,"AMO bypassed gate"); x.pass(2);
    x.until([&]{return x.releases>n;},"AMO predecessor"); x.ticks(40); check(x.active,"AMO early effect");
    x.ackAllowed=true; x.until([&]{return !x.active;},"AMO receipt"); check(x.result==0x23,"AMO preserved old result"); x.read(A,0x24);
    n=x.releases; x.start(7,A,4,0xbad); x.ticks(80); check(x.active && x.releases==n,"SC bypassed unsafe gate");
    x.pass(3); x.until([&]{return !x.active;},"SC cross-package retry"); check(x.result==1,"SC must fail without reservation"); x.read(A,0x24);
    x.pass(4); x.invalidate(A); x.read(A,0x24); x.op(1,A,5,0x51);
    std::cout<<"CASE cross_package_amo_sc_invalidation_refill PASS\n";
    activeCase = "speculative_refill_replay_gate";
    x.invalidate(A); n=x.releases; x.start(1,A,6,0x61); x.guardEffect(); x.ticks(300);
    check(x.active && x.releases==n,"refilled unsafe image bypassed replay gate");
    x.pass(5); x.allowEffect(); x.until([&]{return !x.active;},"blocked replay after safe"); x.read(A,0x61);
    std::cout<<"CASE speculative_refill_replay_gate PASS\n";
    activeCase = "continuous_replacement_refill_seq0_terminal_backpressure";
    // More conflicting lines than any v1 L1 associativity; force WB/reallocation.
    for (unsigned i=1;i<=20;i++) x.op(1,A+0x10000ULL*i,6,0x600+i);
    x.read(A,0x61);
    x.start(1,A,7,0x71); x.ticks(80); check(x.active,"continuous overwrite did not wait for pkg6");
    x.pass(6); x.until([&]{return !x.active;},"continuous overwrite"); x.read(A,0x71);
    x.start(1,A,0,0x70); x.ticks(80); check(x.active,"trusted seq0 erased unsafe ownership");
    x.pass(7); x.until([&]{return !x.active;},"trusted overwrite");
    x.op(1,A,8,0x81); x.read(A,0x81);
    x.t.io_doneReady=0; x.start(8,A,8,1); x.ticks(100); check(x.active,"terminal backpressure missing");
    x.t.io_doneReady=1; x.until([&]{return !x.active;},"held AMO terminal");
    check(x.result==0x81,"held AMO old value"); x.read(A,0x82); x.pass(8);
    x.until([&]{return bool(x.t.io_ordered);},"L1 drain");
    std::cout<<"CASE continuous_replacement_refill_seq0_terminal_backpressure PASS\n";
    activeCase = "real_sourced_commit_before_ack";
    // Real SourceD: all four bank writes must precede even ACK.valid.
    x.t.io_sdBankReady=0; x.t.io_sdAckReady=0; x.t.io_sdReq=1; x.t.io_sdData=0x100;
    bool sdAccepted=false;
    for(unsigned bound=0;bound<100 && !sdAccepted;bound++) sdAccepted=x.step().sdAccept;
    check(sdAccepted,"SourceD admission"); x.t.io_sdReq=0;
    unsigned popped=0,written=0;
    for (unsigned i=0;i<200 && written<4;i++) {
      x.t.io_sdBankReady=i>=30 && i%5==0; x.t.io_sdData=0x100+popped;
      auto e=x.step();
      check(!e.sdAck || written==4,"SourceD ACK before final bank write");
      if (e.sdPop) ++popped;
      if (e.sdWrite) { check(e.sdBeat==written && e.sdData==0x100+written &&
        e.sdHi==~uint64_t(0x100+written),"SourceD full-width beat/data provenance"); ++written; }
    }
    check(written==4 && popped==4,"SourceD did not commit four beats");
    x.until([&]{return bool(x.t.io_sdAck);},"SourceD late ACK");
    for(unsigned i=0;i<30;i++) { x.step(); check(x.t.io_sdAck && x.t.io_sdKey_generation==123 &&
      x.t.io_sdKey_valid && x.t.io_sdKey_contentSeq==1 && x.t.io_sdKey_writer==0,"ACK not held with matching full key"); }
    x.t.io_sdAckReady=1; x.step(); x.ticks(20); check(!x.t.io_sdAck,"duplicate SourceD ACK");
    // A clean release must produce one ACK, zero writes, and no garbage bypass.
    x.t.io_sdClean=1; x.t.io_sdReq=1; x.t.io_sdAckReady=0;
    sdAccepted=false;
    for(unsigned bound=0;bound<100 && !sdAccepted;bound++) sdAccepted=x.step().sdAccept;
    check(sdAccepted,"SourceD clean admission"); x.t.io_sdReq=0;
    for(unsigned i=0;i<30;i++) { auto e=x.step(); check(!e.sdWrite,"clean release wrote data"); }
    check(x.t.io_sdAck && x.t.io_sdOpcode==6,"clean release receipt missing");
    x.t.io_sdAckReady=1; x.step(); x.ticks(10);
    x.t.io_sdRead=1; x.t.io_sdData=0x100; x.t.io_sdReq=1; x.t.io_sdAckReady=0;
    sdAccepted=false;
    for(unsigned bound=0;bound<100 && !sdAccepted;bound++) sdAccepted=x.step().sdAccept;
    check(sdAccepted,"SourceD read admission"); x.t.io_sdReq=0;
    x.until([&]{return bool(x.t.io_sdAck);},"read after clean release");
    check(x.t.io_sdOpcode==1 && x.t.io_sdReturn==0x100 && x.t.io_sdReturnHi==~uint64_t(0x100),
          "clean release corrupted full-width data bypass");
    x.t.io_sdAckReady=1; x.step();
    x.ticks(10); x.t.io_sdRead=0; x.t.io_sdClean=1; x.t.io_sdAckReady=0;
    for(unsigned request=0;request<3;request++) {
      x.t.io_sdReq=1; sdAccepted=false;
      for(unsigned bound=0;bound<100 && !sdAccepted;bound++) sdAccepted=x.step().sdAccept;
      check(sdAccepted,"SourceD queued clean release admission"); x.t.io_sdReq=0; x.ticks(6);
    }
    // Fill the receipt queue, park a third C in s4, then issue a multibeat D.
    x.t.io_sdGrant=1; x.t.io_sdReq=1; sdAccepted=false;
    for(unsigned bound=0;bound<100 && !sdAccepted;bound++) sdAccepted=x.step().sdAccept;
    check(sdAccepted,"SourceD multibeat grant admission"); x.t.io_sdReq=0; x.ticks(10);
    x.t.io_sdAckReady=1;
    unsigned ackCount=0, grantCount=0;
    for(unsigned bound=0;bound<300 && (ackCount<3 || grantCount<4);bound++) {
      auto e=x.step(); check(!e.sdWrite,"clean/grant queue test wrote data");
      if(e.sdAck) { if(e.sdOpcode==6) ++ackCount; else if(e.sdOpcode==5) ++grantCount; }
    }
    check(ackCount==3 && grantCount==4,"SourceD receipt-credit/multibeat D deadlock or loss");
    std::cout<<"CASE real_sourced_commit_before_ack PASS\n";
    activeCase = "denied_a_put_preserves_image";
    // Same harness and simulator process: real L2 MSHR + real SourceD.
    x.trustedA(0,true); x.trustedA(0,false);
    std::cout<<"CASE denied_a_put_preserves_image PASS\n";
    activeCase = "denied_a_amo_preserves_image";
    x.trustedA(2,true); x.trustedA(2,false);
    std::cout<<"CASE denied_a_amo_preserves_image PASS\nSTAGE2_DIRECTED=PASS cycles="<<x.cycle<<"\n";
    x.t.final(); return 0;
  } catch (const std::exception& e) {
    std::cerr<<"STAGE2_DIRECTED=FAIL reason="<<e.what()<<"\n"; return 1;
  }
}
