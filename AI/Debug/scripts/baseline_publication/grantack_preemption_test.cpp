#define main stage3_legacy_main
#include "../stage3/stage3_test.cpp"
#undef main

// Delay a real outer refill while an independent inner ReleaseData nests on
// its set. Publication must drain the refill's GrantAck without letting the
// nested data operation cross the existing baseline barrier.
int main(int argc, char** argv) {
  Verilated::commandArgs(argc,argv);
  Run r;
  try {
    r.t.reset=1; r.pump(8); r.t.reset=0; r.pump(30);
    const uint64_t a=0x80006000ULL, b=a+128;
    r.fill(a,Key{1,0,0,true},bytes(0xa0));
    // fill returned T with a TtoN Release. Reacquire real T permission
    // before presenting the later data Release; never invent a C owner.
    r.acquire(a);
    r.begin("grantack_same_set_release_history");
    // Model an earlier local version archived by the real SVB ingress while
    // Main retains T. The later C carries version7. Making version3 safe
    // overlaps C admission, so publication must drain the pending outer E.
    r.t.io_archiveAddress=a; r.t.io_archiveSeq=3; r.t.io_archiveSerial=3;
    r.t.io_archiveData=0xa3; r.t.io_archiveValid=1;
    r.until([&]{return bool(r.t.io_archiveReady);},"real SVB archive admission");
    r.tick(); r.t.io_archiveValid=0; r.pump(160);
    const auto grants=r.grants, releases=r.releases;
    r.aq.push_back(Upper{b,{}, {},6,1,kPeerSource});
    r.until([&]{return !r.rq.empty();},"real outer refill request");
    auto delayed=r.rq; r.rq.clear();
    check(delayed.front().addr==b,"outer refill address mismatch");
    check(r.pendingProbes.empty(),"UNCOVERED: refill evicted the releasing client");
    Line predecessor; predecessor.fill(0xa3);
    r.expectedOuter[a]=predecessor;
    r.enqueue(a,Key{7,7,0,true},bytes(0xa7));
    r.validate(Key{3,3,0,true});
    r.until([&]{return r.cq.empty();},"nested C complete admission");
    r.pump(160);
    check(r.releases==releases,"nested C completed before outer refill drained");
    r.rq=delayed;
    r.until([&]{return r.grants==grants+1 && r.releases==releases+1;},
      "nested C/outer GrantAck/History circular wait",5000);
    r.pump(220); r.idle();
    check(r.durable.count(a)&&r.durable[a]==predecessor,"safe predecessor was bypassed by pending C");
    r.expectedOuter[a]=bytes(0xa7); r.validate(Key{7,7,0,true});
    r.until([&]{return r.durable[a]==bytes(0xa7);},"validated successor did not publish");
    r.pump(220); r.idle();
    // The peer still owns B after its Grant. Return its permission through
    // real C before cleanup, rather than leaving a flush Probe unanswered.
    r.release(b,Key{},Line{},6,1,kPeerSource);
    r.flush(a); r.flush(b); r.idle();
    r.pass("grantack_same_set_release_history");
    r.t.final(); std::puts("PALIMPSEST_GRANTACK_PREEMPTION=PASS"); return 0;
  } catch(const std::exception& e) {
    std::cerr<<"PALIMPSEST_GRANTACK_PREEMPTION=FAIL reason="<<e.what()<<'\n'; return 1;
  }
}
