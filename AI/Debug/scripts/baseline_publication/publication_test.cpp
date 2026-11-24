#define main stage3_legacy_main
#include "../stage3/stage3_test.cpp"
#undef main

// Production L2/History/Scheduler, with actual TileLink requests and receipts.
// The agent only supplies memory/client traffic and checks every accepted beat.
static void multipleSafeVersionsBeforeTrustedPut() {
  Run r;
  r.t.reset=1;r.pump(8);r.t.reset=0;r.pump(30);
  const uint64_t a=0x80006000ULL;
  r.fill(a,Key{},bytes(0xa0));
  r.begin("same_address_multiversion_sw_scan_trusted_put");
  for(unsigned seq:{3,5,7}) {
    r.t.io_archiveAddress=a;r.t.io_archiveSeq=seq;r.t.io_archiveSerial=seq;
    r.t.io_archiveData=0xa0+seq;r.t.io_archiveValid=1;
    r.until([&]{return bool(r.t.io_archiveReady);},"archive admission");
    r.tick();r.t.io_archiveValid=0;r.pump(160);
  }
  check(r.puts==0,"unsafe historical version reached DRAM");
  const auto before=r.reads;
  r.aq.push_back(Upper{a,bytes(0xb0),{},0,0,kUncachedSource});
  r.holdWrites=true;
  Line expected;expected.fill(0xa3);r.expectedOuter[a]=expected;
  r.validate(Key{3,3,0,true});
  r.until([&]{return !r.wq.empty();},"first history publication missing");
  check(r.wq.front().data==expected&&r.t.io_pendingKey_contentSeq==3,"wrong first safe version");
  // SW changes after the first publication owner is accepted, while its ACK
  // is withheld. Versions 5 and 7 become safe together; neither the trusted
  // writer nor the dirty resident may regress the publication order.
  const auto firstTxn=r.t.io_txn;
  r.validate(Key{7,7,0,true});r.pump(35);
  check(r.puts==1&&r.reads==before&&r.t.io_txn==firstTxn,"SW update bypassed held owner");
  for(unsigned seq:{3,5,7}) {
    expected.fill(0xa0+seq);r.expectedOuter[a]=expected;
    r.until([&]{return !r.wq.empty();},"next safe publication missing");
    check(r.wq.front().addr==a&&r.wq.front().data==expected,"same-address publication regressed");
    r.pump(15);check(r.reads==before,"trusted Put bypassed pending history receipt");
    r.holdWrites=false;
    r.until([&]{return r.durable.count(a)&&r.durable[a]==expected;},"matching publication ACK missing");
    r.holdWrites=true;
  }
  r.holdWrites=false;
  r.until([&]{return r.reads==before+1;},"trusted Put blocked after all safe history receipts");
  r.pump(200);r.idle();
  check(r.puts==3&&r.durable[a]==expected,"resident published older bytes after latest history");
  r.expectedOuter[a]=bytes(0xb0);r.flush(a);r.pump(200);r.idle();
  check(r.puts==4&&r.durable[a]==bytes(0xb0),"trusted successor did not become final baseline");
  r.pass("same_address_multiversion_sw_scan_trusted_put");r.t.final();
}
static void multipleSafeVersionsWithLateProbe() {
  Run r;
  r.t.reset=1;r.pump(8);r.t.reset=0;r.pump(30);
  const uint64_t a=0x80006000ULL;
  r.fill(a,Key{},bytes(0xa0));r.acquire(a);
  r.begin("same_address_multiversion_sw_scan_late_probe");
  const auto beforeProbe=r.probes,beforeRead=r.reads;
  r.aq.push_back(Upper{a,{}, {},4,0,kUncachedSource});
  r.until([&]{return r.probes==beforeProbe+1;},"inner Probe missing");
  for(unsigned seq:{3,5,7}) {
    r.t.io_archiveAddress=a;r.t.io_archiveSeq=seq;r.t.io_archiveSerial=seq;
    r.t.io_archiveData=0xa0+seq;r.t.io_archiveValid=1;
    r.until([&]{return bool(r.t.io_archiveReady);},"archive admission");
    r.tick();r.t.io_archiveValid=0;r.pump(160);
  }
  r.holdWrites=true;
  Line expected;expected.fill(0xa3);r.expectedOuter[a]=expected;
  r.validate(Key{3,3,0,true});
  // A late coherent C transfer competes with the active History publisher,
  // and the SW change makes two more same-address versions safe together.
  r.enqueue(a,Key{6,6,0,true},bytes(0xa6),5,0);
  r.validate(Key{7,7,0,true});
  r.until([&]{return !r.wq.empty();},"first history publication missing");
  check(r.wq.front().data==expected,"wrong initial history owner");
  r.pump(20);
  check(r.puts==1&&r.reads==beforeRead,"late C or SW bypassed pending publication ACK");
  for(unsigned seq:{3,5,7}) {
    expected.fill(0xa0+seq);r.expectedOuter[a]=expected;
    r.until([&]{return !r.wq.empty();},"ordered history publication missing");
    check(r.wq.front().data==expected,"late C regressed publication order");
    r.holdWrites=false;
    r.until([&]{return r.durable.count(a)&&r.durable[a]==expected;},"history ACK missing");
    r.holdWrites=true;
  }
  r.holdWrites=false;
  r.until([&]{return r.probes==beforeProbe+2;},"obsolete C did not replan retained B permission");
  r.enqueue(a,Key{},Line{},4,2);
  r.until([&]{return r.reads==beforeRead+1;},"read did not resume after history/C completion");
  r.pump(250);r.idle();
  check(r.puts==3&&r.returned==expected&&r.durable[a]==expected,"late C escaped newer safe baseline");
  r.pass("same_address_multiversion_sw_scan_late_probe");r.t.final();
}
static void coalescingCannotReclaimPublicationOwner() {
  Run r;
  r.t.reset=1;r.pump(8);r.t.reset=0;r.pump(30);
  const uint64_t a=0x80006000ULL;
  r.begin("safe_coalesce_preserves_held_publication_owner");
  for(unsigned seq:{3,5,7}) {
    r.t.io_archiveAddress=a;r.t.io_archiveSeq=seq;r.t.io_archiveSerial=seq;
    r.t.io_archiveData=0xa0+seq;r.t.io_archiveValid=1;
    r.until([&]{return bool(r.t.io_archiveReady);},"archive admission");
    r.tick();r.t.io_archiveValid=0;r.pump(160);
  }
  r.holdWrites=true;
  Line old;old.fill(0xa3);r.expectedOuter[a]=old;
  r.validate(Key{3,3,0,true});
  r.until([&]{return !r.wq.empty();},"first history owner missing");
  const auto txn=r.t.io_txn;
  check(r.wq.front().data==old,"incorrect original publication payload");
  // Capturing a newer safe same-address image can merge unowned safe
  // history, but the accepted Seq3 publication must retain its old bytes and
  // exact terminal identity until ACK even though it is now dominated.
  r.validate(Key{9,9,0,true});
  r.t.io_archiveAddress=a;r.t.io_archiveSeq=9;r.t.io_archiveSerial=9;
  r.t.io_archiveData=0xa9;r.t.io_archiveValid=1;
  r.until([&]{return bool(r.t.io_archiveReady);},"capture blocked by unrelated WB owner");
  r.tick();r.t.io_archiveValid=0;r.pump(170);
  check(r.puts==1&&r.t.io_pendingKey_contentSeq==3&&r.t.io_txn==txn&&r.wq.front().data==old,
        "coalescing reclaimed or retagged the accepted publication owner");
  r.holdWrites=false;
  r.until([&]{return r.durable.count(a)&&r.durable[a]==old;},"original publication ACK lost");
  r.holdWrites=true;
  Line latest;latest.fill(0xa9);r.expectedOuter[a]=latest;
  r.until([&]{return !r.wq.empty();},"coalesced safe successor missing");
  check(r.wq.front().data==latest,"obsolete intermediate safe version survived coalescing");
  r.holdWrites=false;
  r.until([&]{return r.durable[a]==latest;},"coalesced safe image did not reach DRAM");
  r.pump(250);r.idle();
  check(r.puts==2&&r.durable[a]==latest,"coalescing duplicated or regressed durable image");
  r.t.io_historyAddress=a;r.t.io_historyValid=1;
  r.until([&]{return bool(r.t.io_historyReady);},"history query blocked after retirement");
  r.tick();r.t.io_historyValid=0;
  r.until([&]{return bool(r.t.io_historyResult);},"history query result missing");
  check(!r.t.io_historyFound,"acknowledged/dominated history leaked a live slot");
  r.tick();r.pass("safe_coalesce_preserves_held_publication_owner");r.t.final();
}
static void evtDuringMultiversionPublication() {
  Run r;
  r.t.reset=1;r.pump(8);r.t.reset=0;r.pump(30);
  const uint64_t a=0x80006000ULL;
  r.fill(a,Key{},bytes(0xa0));r.acquire(a);
  r.begin("same_address_multiversion_evt_outer_ack_late_c");
  const auto beforeProbe=r.probes,beforeRead=r.reads;
  r.aq.push_back(Upper{a,{}, {},4,0,kUncachedSource});
  r.until([&]{return r.probes==beforeProbe+1;},"inner Probe missing");
  for(unsigned seq:{3,5,7}) {
    r.t.io_archiveAddress=a;r.t.io_archiveSeq=seq;r.t.io_archiveSerial=seq;
    r.t.io_archiveData=0xa0+seq;r.t.io_archiveValid=1;
    r.until([&]{return bool(r.t.io_archiveReady);},"archive admission");
    r.tick();r.t.io_archiveValid=0;r.pump(160);
  }
  Line expected;expected.fill(0xa3);r.expectedOuter[a]=expected;
  r.holdWrites=true;r.validate(Key{3,3,0,true});
  r.enqueue(a,Key{6,6,0,true},bytes(0xa6),5,0);
  r.until([&]{return !r.wq.empty();},"safe predecessor did not acquire outer owner");
  const auto txn=r.t.io_txn;
  check(r.wq.front().data==expected&&r.puts==1,"wrong first publication");
  r.t.io_historyDeadLower=5;r.t.io_historyDeadUpper=8;
  r.t.io_historyInstallOnly=1;r.t.io_historyValid=1;r.t.eval();
  r.until([&]{return bool(r.t.io_historyReady);},"EVT installation blocked by outer owner");
  r.tick();r.t.io_historyValid=0;r.t.io_historyInstallOnly=0;r.pump(100);
  r.validate(Key{8,8,0,true});r.pump(100);
  check(r.t.io_pending&&r.t.io_txn==txn&&r.reads==beforeRead&&r.puts==1,
        "EVT/SW changed an accepted publication owner or bypassed its ACK");
  r.holdWrites=false;
  r.until([&]{return r.probes==beforeProbe+2;},"dead late C failed to replan permission");
  r.enqueue(a,Key{},Line{},4,2);
  r.until([&]{return r.reads==beforeRead+1;},"read did not complete after surviving owner ACK");
  r.pump(300);r.idle();
  check(r.puts==1&&r.returned==expected&&r.durable[a]==expected,
        "dead version or late C escaped surviving safe baseline");
  r.t.io_historyAddress=a;r.t.io_historyValid=1;
  r.until([&]{return bool(r.t.io_historyReady);},"history query blocked after owner completion");
  r.tick();r.t.io_historyValid=0;
  r.until([&]{return bool(r.t.io_historyResult);},"history query result missing");
  check(!r.t.io_historyFound,"dead or published history retained a slot");
  r.tick();r.pass("same_address_multiversion_evt_outer_ack_late_c");r.t.final();
}
int main(int argc,char**argv){
  Verilated::commandArgs(argc,argv);
  try {multipleSafeVersionsBeforeTrustedPut();Verilated::threadContextp()->time(0);multipleSafeVersionsWithLateProbe();Verilated::threadContextp()->time(0);coalescingCannotReclaimPublicationOwner();Verilated::threadContextp()->time(0);evtDuringMultiversionPublication();std::puts("PALIMPSEST_MULTI_OWNER_BASELINE=PASS");return 0;}
  catch(const std::exception&e){std::cerr<<"PALIMPSEST_MULTI_OWNER_BASELINE=FAIL reason="<<e.what()<<'\n';return 1;}
}
