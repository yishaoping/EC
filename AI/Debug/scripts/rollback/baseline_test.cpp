// Reuse the existing terminal-memory/client agent. It models no directory,
// preservation, obsolete-hit or history logic; these are production RTL.
#define main stage3_legacy_main
#include "../stage3/stage3_test.cpp"
#undef main

static void bufferedProbePreservesBeforeCapture(bool tracked=false) {
  Run r;
  r.t.reset=1; r.pump(8); r.t.reset=0; r.pump(30);
  const uint64_t a=0x80006000ULL;
  const auto base=bytes(0xa0), incoming=bytes(0xb0);
  if(tracked) r.expectedOuter[a]=base;
  const char* name=tracked ? "tracked_c_buffer_across_evt" : "buffered_probe_preserves_before_capture";
  Line archived; archived.fill(0xa7);
  r.fill(a,Key{},base);
  r.acquire(a);
  r.begin(name);
  r.watermark=6;
  r.t.io_archiveAddress=a; r.t.io_archiveSeq=7; r.t.io_archiveSerial=1;
  r.t.io_archiveData=archived[0]; r.t.io_archiveValid=1;
  r.until([&]{return bool(r.t.io_archiveReady);},"archive ingress unavailable");
  r.tick(); r.t.io_archiveValid=0;
  r.pump(160);
  r.t.io_historyAddress=a; r.t.io_historyValid=1; r.t.eval();
  r.until([&]{return bool(r.t.io_historyReady);},"initial address query not accepted");
  r.tick(); r.t.io_historyValid=0;
  r.until([&]{return bool(r.t.io_historyResult);},"initial history result missing");
  check(r.t.io_historyFound&&r.t.io_historySeq==7,"UNCOVERED: pending Seq7 not present");
  r.tick();
  const auto beforeProbe=r.probes, beforeRead=r.reads, beforeWrite=r.writes;
  r.aq.push_back(Upper{a,{}, {},4,0,kUncachedSource});
  r.until([&]{return r.probes==beforeProbe+1;},"inner Probe");
  r.holdWrites=true;
  r.enqueue(a,tracked ? Key{2,8,0,true} : r.key(false),incoming,5,0);
  r.until([&]{return !r.cq.empty()&&r.cq.front().beat==2;},"UNCOVERED: full C buffer before admission");
  r.until([&]{return !r.wq.empty();},"blocked buffered Probe did not preserve dirty BASE");
  check(r.wq.front().addr==a&&r.wq.front().data==base,"checkpoint did not preserve dirty BASE");
  r.t.io_historyDeadUpper=8;
  for (unsigned lower : {8,7}) {
    r.t.io_historyDeadLower=lower;
    r.t.io_historyInstallOnly=1; r.t.io_historyValid=1; r.t.eval();
    check(r.t.io_historyReady&&r.t.io_pending,"EVT install waited for outer owner");
    check(r.cq.size()==1&&r.cq.front().beat==2,"UNCOVERED: C buffer not full at EVT install");
    r.tick();
    r.t.io_historyValid=0; r.t.io_historyInstallOnly=0; r.t.eval();
    r.phase(lower==8 ? "EVT_INSTALL_8" : "EVT_INSTALL_7",a);
    for (unsigned cycle=0; cycle<20; ++cycle) {
      check(!r.t.io_historyReady&&!r.t.io_historyResult,"EVT install bypassed address query barrier");
      r.tick();
    }
  }
  check(r.cq.size()==1&&r.cq.front().beat==2&&r.writes==beforeWrite&&r.reads==beforeRead,
    "Probe crossed the bank or completed before the predecessor ACK");
  r.holdWrites=false;
  r.until([&]{return r.durable.count(a)!=0;},"predecessor did not get a terminal ACK");
  check(r.durable[a]==base,"wrong predecessor became durable");
  if(tracked) {
    r.until([&]{return r.probes==beforeProbe+2;},"dead C did not replan the trusted read");
    r.enqueue(a,Key{},Line{},4,2); // Remaining Branch permission answers BtoN.
  }
  r.until([&]{return r.reads==beforeRead+1;},"Probe and blocked read did not finish");
  r.idle();
  check(r.returned==(tracked?base:incoming),"Probe returned an incorrect or dead image");
  // Let SW cross both tombstones without issuing another history query.
  // A dropped install would allow the parked Seq7 bytes to reach DRAM.
  r.validate(Key{1,8,0,true});
  for (unsigned cycle=0; cycle<200; ++cycle) {
    r.tick();
    check(tracked ? r.durable[a]==base : r.durable[a]!=archived,
      "dead history or C image overwrote the external baseline");
  }
  r.idle();
  r.t.io_historyValid=1; r.t.eval();
  r.until([&]{return bool(r.t.io_historyReady);},"address query blocked after C drained");
  r.tick(); r.t.io_historyValid=0;
  r.until([&]{return bool(r.t.io_historyResult);},"history query did not complete after C drained");
  check(!r.t.io_historyFound||r.t.io_historySeq==0,"history returned a dead sequence");
  r.tick();
  r.pass(name);
  r.t.final();
}

static void safeHistoryDisjointFromPendingProbe() {
  Run r;
  r.t.reset=1; r.pump(8); r.t.reset=0; r.pump(30);
  const uint64_t a=0x80006000ULL, b=a+128; // 2 sets, 64-byte blocks
  const auto base=bytes(0xa0), incoming=bytes(0xc0);
  Line archived; archived.fill(0xb7);
  r.fill(a,Key{},base);
  r.acquire(a);
  r.begin("safe_history_disjoint_from_pending_probe");
  const auto beforeProbe=r.probes, beforeRead=r.reads, beforeWrite=r.writes;
  r.aq.push_back(Upper{a,{}, {},4,0,kUncachedSource});
  r.until([&]{return r.probes==beforeProbe+1;},"inner Probe");
  r.t.io_archiveAddress=b; r.t.io_archiveSeq=7;
  r.t.io_archiveSerial=1; r.t.io_archiveData=archived[0]; r.t.io_archiveValid=1;
  r.until([&]{return bool(r.t.io_archiveReady);},"archive ingress unavailable");
  r.tick(); r.t.io_archiveValid=0;
  r.validate(Key{1,7,0,true});
  r.holdWrites=true;
  r.enqueue(a,r.key(false),incoming,5,0);
  r.until([&]{return !r.wq.empty();},"safe history blocked behind unrelated Probe");
  check(r.t.io_drain_probeValid&&!r.t.io_drain_probeAllow&&r.writes==beforeWrite,
    "UNCOVERED: C must be held throughout the disjoint history publication");
  check(r.wq.front().addr==b&&r.wq.front().data==archived,"wrong line published first");
  r.holdWrites=false;
  r.until([&]{return r.reads==beforeRead+1;},"safe history and unrelated Probe did not drain");
  r.idle();
  check(r.returned==incoming,"unrelated Probe returned stale data");
  check(r.durable.count(a)&&r.durable.count(b)&&r.durable[b]==archived,
    "missing terminal publication receipts");
  r.pass("safe_history_disjoint_from_pending_probe");
  r.t.final();
}

static void simultaneousSameLineHistoryAndProbe() {
  Run r;
  r.t.reset=1; r.pump(8); r.t.reset=0; r.pump(30);
  const uint64_t a=0x80006000ULL;
  Line latest; latest.fill(0xa7);
  r.fill(a,Key{},bytes(0xa0));
  r.acquire(a);
  r.begin("same_line_safe_history_supersedes_late_probe");
  const auto beforeProbe=r.probes, beforeRead=r.reads, beforeGets=r.memoryGets;
  r.aq.push_back(Upper{a,{}, {},4,0,kUncachedSource});
  r.until([&]{return r.probes==beforeProbe+1;},"inner Probe");
  r.t.io_archiveAddress=a; r.t.io_archiveSeq=7;
  r.t.io_archiveSerial=1; r.t.io_archiveData=latest[0]; r.t.io_archiveValid=1;
  r.until([&]{return bool(r.t.io_archiveReady);},"archive ingress unavailable");
  r.tick(); r.t.io_archiveValid=0;
  r.validate(Key{1,7,0,true});
  r.holdWrites=true;
  r.enqueue(a,Key{2,6,0,true},bytes(0xa6),5,0);
  r.until([&]{return !r.wq.empty();},"same-line history and Probe did not drain");
  check(r.wq.front().addr==a&&r.wq.front().data==latest&&r.pendingProbes.empty(),
    "latest safe line should be published after Probe terminal beat");
  r.pump(20);
  check(r.reads==beforeRead,"stale bytes escaped before newer history receipt");
  r.holdWrites=false;
  r.until([&]{return r.probes==beforeProbe+2;},"replan did not invalidate retained B permission");
  r.enqueue(a,Key{},Line{},4,2); // clean BtoN for the replanned eviction
  r.until([&]{return r.reads==beforeRead+1;},"read did not replan after same-line receipt");
  r.pump(200); r.idle();
  check(r.returned==latest&&r.memoryGets>beforeGets,"older Probe data escaped the baseline receipt");
  check(r.puts==1&&r.durable[a]==latest,"stale Probe bytes re-entered history and regressed DRAM");
  r.pass("same_line_safe_history_supersedes_late_probe");
  r.t.final();
}

static void lateReleaseAfterNewerReceipt() {
  Run r;
  r.t.reset=1; r.pump(8); r.t.reset=0; r.pump(30);
  const uint64_t a=0x80006000ULL;
  Line latest; latest.fill(0xa7);
  r.fill(a,Key{1,5,0,true},bytes(0xa5));
  r.acquire(a);
  r.begin("late_release_after_newer_baseline_receipt");
  r.t.io_archiveAddress=a; r.t.io_archiveSeq=7;
  r.t.io_archiveSerial=1; r.t.io_archiveData=latest[0]; r.t.io_archiveValid=1;
  r.until([&]{return bool(r.t.io_archiveReady);},"archive ingress unavailable");
  r.tick(); r.t.io_archiveValid=0;
  r.validate(Key{1,7,0,true});
  r.until([&]{return r.durable.count(a)&&r.durable[a]==latest;},"A7 did not reach DRAM");
  r.until([&]{return !r.t.io_pending;},"A7 directory receipt did not complete");
  r.pump(200);

  r.release(a,Key{2,6,0,true},bytes(0xa6));
  r.pump(300); r.idle();
  check(r.durable[a]==latest,"late A6 ReleaseData regressed the acknowledged A7 baseline");
  const auto before=r.reads, beforeGets=r.memoryGets;
  r.aq.push_back(Upper{a,{}, {},4,0,kUncachedSource});
  r.until([&]{return r.reads==before+1;},"late ReleaseData blocked a read of the durable baseline");
  r.idle();
  check(r.returned==latest&&r.memoryGets>beforeGets,"late ReleaseData remained visible after the receipt");

  // A strictly newer live release must still be accepted and published.
  r.acquire(a);
  const Key after{1,8,0,true};
  const Line afterData=bytes(0xa8);
  r.release(a,after,afterData);
  r.validate(after);
  r.until([&]{return r.durable[a]==afterData;},"newer A8 ReleaseData was incorrectly discarded");
  r.idle();
  r.pass("late_release_after_newer_baseline_receipt");
  r.t.final();
}

static void newlySafeHistoryBeforeResidentPut() {
  Run r;
  r.t.reset=1; r.pump(8); r.t.reset=0; r.pump(30);
  const uint64_t a=0x80002000ULL;
  r.watermark=6; r.pump(100);
  r.fill(a,Key{},bytes(0xa0)); // dirty trusted BASE: no authored C sidecar
  r.t.io_archiveAddress=a; r.t.io_archiveSeq=7;
  r.t.io_archiveSerial=1; r.t.io_archiveData=0xa7; r.t.io_archiveValid=1;
  r.until([&]{return bool(r.t.io_archiveReady);},"history ingress unavailable");
  r.tick(); r.t.io_archiveValid=0; r.pump(200); r.idle();
  check(!r.durable.count(a),"pending history or dirty BASE published prematurely");
  r.begin("sw_edge_history_precedes_direct_resident_put");
  const auto before=r.reads;
  r.aq.push_back(Upper{a,bytes(0xb0),{},0,0,kUncachedSource});
  r.until([&]{return bool(r.t.io_drain_candidate);},"UNCOVERED: no direct preservation candidate");
  check(r.t.io_drain_safe&&r.t.io_pendingKey_contentSeq==0,
    "UNCOVERED: candidate is not the dirty trusted resident");
  // Advance SW at the precise edge at which a direct resident Put could
  // capture. The cold scanner has not raised its history publish.valid yet.
  r.validate(Key{1,7,0,true}); r.memoryReady=false; r.tick();
  r.until([&]{return bool(r.t.io_pending);},"newly safe history publisher did not acquire its owner");
  check(r.t.io_pendingKey_contentSeq==7,
    "direct resident Put overtook the newly-safe history scan at the SW edge");
  r.pump(25); check(r.reads==before,"trusted replacement bypassed outstanding baseline publication");
  r.memoryReady=true;
  r.until([&]{return r.reads==before+1;},"trusted replacement did not resume after history receipt");
  r.pump(150); r.idle();
  Line history; history.fill(0xa7);
  check(r.durable[a]==history,"history was not the acknowledged baseline before trusted writeback");
  r.flush(a); r.pump(200); r.idle();
  check(r.durable[a]==bytes(0xb0),"old safe history regressed the later trusted BASE writeback");
  r.pass("sw_edge_history_precedes_direct_resident_put");
  r.t.final();
}

static void trustedPutWaitsForUnsafeHistory() {
  Run r;
  r.t.reset=1; r.pump(8); r.t.reset=0; r.pump(30);
  const uint64_t a=0x80004000ULL;
  r.begin("trusted_put_waits_for_unsafe_history");
  r.watermark=6;
  r.t.io_archiveAddress=a; r.t.io_archiveSeq=7;
  r.t.io_archiveSerial=1; r.t.io_archiveData=0xa7; r.t.io_archiveValid=1;
  r.until([&]{return bool(r.t.io_archiveReady);},"history ingress unavailable");
  r.tick(); r.t.io_archiveValid=0; r.pump(200);
  const auto before=r.reads;
  r.aq.push_back(Upper{a,bytes(0xb7),{},0,0,kUncachedSource});
  r.until([&]{return r.t.io_clientWaiting!=0||r.reads!=before;},
    "UNCOVERED: trusted write did not reach the sidecar check");
  check(r.t.io_clientWaiting!=0&&r.reads==before,"trusted Put overtook the unsafe same-address version");
  r.holdWrites=true;
  r.validate(Key{1,7,0,true});
  r.until([&]{return !r.wq.empty();},"safe history did not reach DRAM");
  r.pump(15); check(r.reads==before,"trusted Put passed a pending history receipt");
  r.holdWrites=false;
  r.until([&]{return r.reads==before+1;},"trusted Put did not resume after the history ACK");
  r.pump(150); r.idle();
  r.flush(a); r.pump(100); r.idle();
  check(r.durable[a]==bytes(0xb7),"older history overwrote the newer trusted Put");
  r.pass("trusted_put_waits_for_unsafe_history");
  r.t.final();
}

static void probePredecessorUnblocksDisjointPublication() {
  Run r;
  r.t.reset=1; r.pump(8); r.t.reset=0; r.pump(30);
  constexpr uint64_t head=0x80006000, published=head+64;
  const auto base=bytes(0xa0), newer=bytes(0xa1);
  Line safe; safe.fill(0xb7);
  r.fill(head,Key{},base);
  r.acquire(head);
  r.acquire(published,kPeerSource);
  r.begin("probe_predecessor_unblocks_disjoint_publication");
  r.watermark=6;
  r.t.io_archiveAddress=published; r.t.io_archiveSeq=7;
  r.t.io_archiveSerial=1; r.t.io_archiveData=safe[0]; r.t.io_archiveValid=1;
  r.until([&]{return bool(r.t.io_archiveReady);},"History ingress");
  r.tick(); r.t.io_archiveValid=0;
  r.pump(160);
  const auto probeCount=r.probes, readCount=r.reads;
  r.aq.push_back(Upper{head,{}, {},4,0,kUncachedSource});
  r.aq.push_back(Upper{published,{}, {},4,0,kPressureSource});
  r.until([&]{return r.probes==probeCount+2;},"both MSHRs issued Probe");
  r.validate(Key{1,7,0,true});
  r.pump(160);
  check(r.wq.empty()&&r.pendingProbes.size()==2,"publisher must wait for the same-set Probe");
  r.holdWrites=true;
  r.enqueue(head,Key{},newer,5,1,kCoherentSource);
  r.enqueue(published,Key{1,7,0,true},safe,5,1,kPeerSource);
  r.until([&]{return !r.wq.empty();},"C head predecessor did not acquire the writeback owner",500);
  check(r.wq.front().addr==head&&r.wq.front().data==base,"wrong bytes in prerequisite writeback");
  check(r.reads==readCount&&r.pendingProbes.size()==2,"Probe advanced before predecessor ACK");
  r.holdWrites=false;
  r.until([&]{return r.writes>=2;},"publication did not resume");
  r.until([&]{return r.reads==readCount+2;},"both clients must finish");
  r.idle();
  check(r.durable[published]==safe,"validated History bytes changed");
  r.flush(head);
  check(r.durable[head]==newer,"dirty Probe data was lost after the predecessor ACK");
  r.pass("probe_predecessor_unblocks_disjoint_publication");
  r.t.final();
}

int main(int argc, char **argv) {
  Verilated::commandArgs(argc, argv);
  try {
    bufferedProbePreservesBeforeCapture(true);
    Verilated::threadContextp()->time(0);
    bufferedProbePreservesBeforeCapture();
    Verilated::threadContextp()->time(0);
    safeHistoryDisjointFromPendingProbe();
    Verilated::threadContextp()->time(0);
    probePredecessorUnblocksDisjointPublication();
    Verilated::threadContextp()->time(0);
    simultaneousSameLineHistoryAndProbe();
    Verilated::threadContextp()->time(0);
    lateReleaseAfterNewerReceipt();
    Verilated::threadContextp()->time(0);
    newlySafeHistoryBeforeResidentPut();
    Verilated::threadContextp()->time(0);
    trustedPutWaitsForUnsafeHistory();
    Verilated::threadContextp()->time(0);
    Run r;
    r.t.io_archiveValid=0;
    r.t.reset=1; r.pump(8); r.t.reset=0; r.pump(30);
    const uint64_t a=0x80001000ULL;
    Key old{1,6,0,true}, newer{2,7,0,true};
    r.fill(a,old,bytes(0xa6));
    r.validate(old);
    r.until([&]{return r.durable[a]==bytes(0xa6);},"initial baseline was not published");
    r.until([&]{return !r.t.io_pending;},"initial baseline receipt did not finish");
    r.pump(150); r.idle(); // allow the passive post-ACK scan to finish

    r.begin("new_baseline_supersedes_resident_and_held_mshr");
    r.t.io_archiveAddress=a; r.t.io_archiveSeq=7;
    r.t.io_archiveSerial=2; r.t.io_archiveData=0xa7; r.t.io_archiveValid=1;
    r.until([&]{return bool(r.t.io_archiveReady);},"archive ingress unavailable");
    r.tick(); r.t.io_archiveValid=0;
    r.holdWrites=true;
    r.validate(newer);
    const auto oldReads=r.reads, oldGets=r.memoryGets;
    // This read is admitted while the cold history scanner is still finding
    // A7. Its old hit must be replanned after the exact DRAM receipt.
    r.aq.push_back(Upper{a,{}, {},4,0,kUncachedSource});
    r.until([&]{return !r.wq.empty();},"A7 never reached real memory Put");
    r.pump(20);
    check(r.reads==oldReads,"old resident escaped while new baseline receipt was pending");
    check(r.t.io_drain_mshrPending!=0,"UNCOVERED: no in-flight MSHR at baseline publication");
    r.holdWrites=false;
    r.until([&]{return r.reads==oldReads+1;},"held MSHR did not resume after baseline receipt");
    r.idle();
    Line expected; expected.fill(0xa7);
    check(r.returned==expected,"obsolete resident bytes satisfied coherent read");
    check(r.durable[a]==expected,"older resident writeback regressed DRAM");
    check(r.memoryGets>oldGets,"obsolete hit did not obtain the new outer baseline");
    const auto before=r.reads;
    r.aq.push_back(Upper{a,{}, {},4,0,kUncachedSource});
    r.until([&]{return r.reads==before+1;},"second baseline read stalled"); r.idle();
    check(r.returned==expected && r.durable[a]==expected,"baseline changed after refill hit");
    r.pass("new_baseline_supersedes_resident_and_held_mshr");
    std::cout << "PALIMPSEST_BASELINE=PASS\n";
    r.t.final(); return 0;
  } catch(const std::exception &e) {
    std::cerr << "PALIMPSEST_BASELINE=FAIL reason=" << e.what() << '\n';
    return 1;
  }
}
