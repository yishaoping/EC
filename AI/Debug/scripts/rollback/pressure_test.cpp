// P4-02/P4-12/P5-08/P5-10: actual full history RAM + Scheduler/MSHR/Probe,
// metadata-only park, reserved Checker way, and real DRAM acknowledgement.
#define main stage3_legacy_main
#include "../stage3/stage3_test.cpp"
#undef main

static void archive(Run& r,uint64_t a,unsigned seq) {
  r.t.io_archiveAddress=a; r.t.io_archiveSeq=seq;
  r.t.io_archiveSerial=1; r.t.io_archiveData=0xa000+seq;
  r.t.io_archiveValid=1;
  r.until([&]{return bool(r.t.io_archiveReady);},"ordinary history credit missing");
  r.tick(); r.t.io_archiveValid=0;
  r.pump(150); // accepted owner reaches RAM through the indexed scan
}
static void fullHistoryProbeAndPark(Run& r) {
  r.t.io_archiveValid=0;
  r.t.reset=1; r.pump(8); r.t.reset=0; r.pump(30);
  const uint64_t victim=0x80001000ULL, miss=victim+0x80, text=victim+0x100;
  Key original{1,1,0,true}, probed{2,200,0,true};
  r.fill(victim,original,bytes(0xa1)); r.validate(original);
  r.until([&]{return r.durable[victim]==bytes(0xa1);},"safe predecessor not durable");
  r.pump(200); r.idle();
  r.acquire(victim); // Main owns T; it may author A200 before the Probe.
  r.begin("full_history_probe_park_checker_escape");
  // Distinct addresses prevent same-address coalescing from faking pressure.
  for(unsigned i=0;i<60;++i) archive(r,0x80010000ULL+64*i,10+i);
  check(r.t.io_historyPressure,"UNCOVERED: ordinary history did not reach reserve");
  r.t.io_archiveAddress=0x80020000ULL; r.t.io_archiveSeq=90;
  r.t.io_archiveValid=1; r.pump(5);
  check(!r.t.io_archiveReady,"ordinary ingress consumed reserved credit");
  r.t.io_archiveValid=0;
  // Real ReleaseData transfers consume the four escape entries in set 1,
  // leaving the coherent victim in set 0 untouched.
  for(unsigned i=0;i<4;++i)
    r.fill(0x80003040ULL+128*i,Key{1,100+i,0,true},bytes(0xb0+i));
  r.until([&]{return !r.t.io_historyEscapeAvailable;},"UNCOVERED: history not actually full");
  const auto beforeMain=r.grantsBySource[kCoherentSource], beforeReads=r.reads, beforeGets=r.memoryGets;
  r.aq.push_back(Upper{miss,{}, {},6,1,kCoherentSource});
  r.until([&]{return r.pendingProbes.count(victim)!=0;},"UNCOVERED: no accepted victim Probe");
  check(r.probeSources.at(victim)==kCoherentSource,"wrong Probe owner");
  r.enqueue(victim,probed,bytes(0xc8),5,1); // ProbeAckData TtoN, four beats
  r.until([&]{return r.pendingProbes.empty()&&r.cq.empty();},"Probe data did not drain");
  r.until([&]{return r.t.io_clientWaiting!=0;},"completed Probe did not release MSHR/set");
  check(r.grantsBySource[kCoherentSource]==beforeMain,"capacity waiter received a premature Grant");
  check(!r.t.io_pending,"no-credit waiter acquired preservation lock");
  const auto putsBefore=r.puts;
  r.aq.push_back(Upper{text,{}, {},4,0,kUncachedSource});
  r.until([&]{return r.reads==beforeReads+1;},"Checker escape Get blocked behind Main");
  check(r.t.io_clientWaiting!=0,"UNCOVERED: Main resumed before validation");
  check(r.memoryGets>beforeGets,"UNCOVERED: Checker request was not a real miss");
  // A Rocket page-table walk can use its coherent DCache, hence Acquire
  // rather than ICache Get. It needs the same reserved replacement way.
  const auto beforePeer=r.grantsBySource[kPeerSource], peerGets=r.memoryGets;
  r.aq.push_back(Upper{text+0x80,{}, {},6,1,kPeerSource});
  r.until([&]{return r.grantsBySource[kPeerSource]==beforePeer+1;},"Checker coherent translation miss blocked");
  check(r.memoryGets>peerGets&&r.t.io_clientWaiting!=0,"UNCOVERED: coherent Checker did not escape parked Main");
  check(r.grantsBySource[kCoherentSource]==beforeMain,"unsafe Main resumed during Checker escape");
  check(r.puts==putsBefore&&r.durable[victim]==bytes(0xa1),"unsafe Probe data reached DRAM");
  r.validate(probed);
  r.until([&]{return r.grantsBySource[kCoherentSource]==beforeMain+1;},"parked Main did not resume after validation",12000);
  r.until([&]{return r.durable[victim]==bytes(0xc8);},"verified Probe bytes were lost",12000);
  r.pump(400); r.idle();
  check(!r.t.io_clientWaiting,"wait slot leaked after replay");
  r.pass("full_history_probe_park_checker_escape");
}

// Seed a fresh escape way with Rocket BASE bytes. No older Checker
// permission needs a host-supplied Probe response in this case.
static void safeCheckerVictimUnderPressure(Run& stackRun) {
  stackRun.t.reset=1; stackRun.pump(8);
  stackRun.t.reset=0; stackRun.pump(30);
  const uint64_t stack=0x80041000ULL, nextStack=stack+0x80;
  stackRun.acquire(stack,kPeerSource);
  stackRun.release(stack,Key{},bytes(0x1234),7,1,kPeerSource);
  for(unsigned i=0;i<60;++i)
    archive(stackRun,0x80050000ULL+64*i,300+i);
  check(stackRun.t.io_historyPressure,"UNCOVERED: safe victim test never reached archive pressure");
  stackRun.begin("safe_checker_victim_during_history_pressure");
  const auto safeBefore=stackRun.grantsBySource[kPeerSource];
  const auto putsBeforeEscape=stackRun.puts;
  stackRun.aq.push_back(Upper{nextStack,{}, {},6,1,kPeerSource});
  stackRun.until([&]{return stackRun.grantsBySource[kPeerSource]==safeBefore+1;},
    "safe dirty Checker victim blocked by unrelated history pressure");
  check(stackRun.t.io_historyPressure&&stackRun.watermark==0,
    "UNCOVERED: history pressure released before the Checker Grant");
  check(stackRun.puts==putsBeforeEscape+1 && stackRun.durable[stack]==bytes(0x1234),
    "safe Checker victim did not complete its physical write before the Grant");
  stackRun.idle();
  stackRun.pass("safe_checker_victim_during_history_pressure");
}

static void runCase(int argc, char** argv, void (*test)(Run&)) {
  VerilatedContext context;
  context.threads(1);
  context.commandArgs(argc, argv);
  Run run(&context);
  test(run);
  run.t.final();
}

int main(int argc, char** argv) {
  auto* originalContext = Verilated::threadContextp();
  try {
    runCase(argc, argv, fullHistoryProbeAndPark);
    runCase(argc, argv, safeCheckerVictimUnderPressure);
    Verilated::threadContextp(originalContext);
    std::cout << "PALIMPSEST_PRESSURE=PASS\n";
    return 0;
  } catch(const std::exception& e) {
    std::cerr << "PALIMPSEST_PRESSURE=FAIL reason=" << e.what() << '\n';
    Verilated::threadContextp(originalContext);
    return 1;
  }
}
