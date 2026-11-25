#include "VSeqTransportHarness.h"
#include "verilated.h"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <initializer_list>

class Test {
public:
  VSeqTransportHarness dut;
  unsigned cycle = 0, clocks = 0, frozen = 0;
  void check(bool passed, const char *message) {
    if (passed) return;
    std::fprintf(stderr, "FAIL cycle=%u: %s ack=%u checkers=%x seq=%x release=%u anchors=%u\n",
                 cycle, message, dut.io_ack, dut.io_checkerAcks, dut.io_receivedSeq,
                 dut.io_release, dut.io_anchors);
    std::exit(1);
  }
  void step() {
    dut.clock = 0;
    dut.eval();
    for (unsigned i = 0; i < 4; ++i) {
      const unsigned bit = 1u << i;
      if (!(frozen & bit)) clocks = (clocks & ~bit) | (((cycle / (i + 1)) & 1) << i);
    }
    dut.io_clocks = clocks;
    dut.eval();
    dut.clock = 1;
    dut.eval();
    ++cycle;
    Verilated::timeInc(1);
    check(!Verilated::gotFinish(), "unexpected RTL finish");
  }
  void pulse(CData &input) {
    while (clocks & 1) step();
    input = 1;
    do { step(); } while (!(clocks & 1));
    input = 0;
    dut.eval();
  }
  void ticks(unsigned n) { while (n--) step(); }
  template <class Predicate> void until(Predicate done, const char *message) {
    for (unsigned count = 0; count < 4096 && !done(); ++count) step();
    check(done(), message);
  }
};

int main(int argc, char **argv) {
  Verilated::commandArgs(argc, argv);
  Test t;
  auto &d = t.dut;
  d.io_segment = d.io_resultValid = d.io_resultSeq = d.io_owned = d.io_request = 0;
  d.io_ingressReady = 0;
  d.io_managementTrap = 0;
  d.io_localStart = d.io_localTrap = d.io_localRet = 0;
  d.io_localCancel = d.io_localReturned = 0;
  d.io_dataBeat = d.io_arfBeat = 0;
  d.io_producerHasData = 0;
  d.io_arfIsCps = 0;
  d.io_payload = 0;
  d.io_session = 0;
  d.reset = 1; t.ticks(20); d.reset = 0; t.ticks(100);
  constexpr uint32_t old = 0xfffffffeu;
  d.io_segment = old;
  d.io_owned = 1;
  t.ticks(35);
  d.io_segment = 0;
  d.io_resultSeq = old;
  // Send a result across one Checker edge, independently of the forward queues.
  while (t.clocks & 1) t.step();
  d.io_resultValid = 1;
  do { t.step(); } while (!(t.clocks & 1));
  d.io_resultValid = 0;
  t.until([&]{ return d.io_release && d.io_resultSeen == old; }, "missing original result/release");
  t.frozen = 8;
  d.io_request = 1;
  t.ticks(100);
  t.check(!d.io_ack && !(d.io_checkerAcks & 1), "reset accepted with held result release");
  d.io_owned = 0;
  t.ticks(100);
  t.check(!d.io_ack && !(d.io_checkerAcks & 1), "reset accepted with undelivered anchor/END");
  d.io_managementTrap = 1;
  d.eval();
  t.check(!d.io_contextIdle, "management trap admitted a new package");
  d.io_ingressReady = 1;
  t.until([&]{ return (d.io_checkerAcks & 7) == 7; }, "active Checker never drained and acknowledged");
  t.check(!d.io_ack && d.io_checkerAcks == 7 && d.io_anchors == 1, "slow Checker bypass or bad old anchor");
  t.frozen = 0;
  t.until([&]{ return d.io_ack; }, "missing transport receipt");
  t.check(d.io_receivedSeq == 0 && !d.io_receivedEnd, "old consumer high watermark survived reset");
  t.frozen = 8;
  d.io_request = 0;
  t.ticks(100);
  t.check(d.io_ack && (d.io_checkerAcks & 8), "old ACK not held while Checker clock paused");
  t.frozen = 0;
  t.until([&]{ return !d.io_ack && !d.io_checkerAcks; }, "transport receipt did not return low");
  d.io_segment = 1;
  t.until([&]{ return d.io_receivedEnd && d.io_receivedSeq == 1; }, "reused Seq1 END rejected");
  t.check(d.io_anchors == 2, "reused Seq1 missing anchor");
  t.check(d.io_managementTrap && !d.io_contextIdle, "Seq reset destroyed the management trap context");
  std::puts("CASE management_trap_transport_reset PASS");

  // An owned package trap and a cancellation return still hold their tags.
  // Let every forward FIFO empty, so only the real R_ICSL lifecycle blocks.
  d.io_segment = 0;
  d.io_managementTrap = 0;
  t.pulse(d.io_localStart);
  t.check(!d.io_packageIdle && !d.io_contextIdle, "active package looked idle");
  d.io_managementTrap = 1;
  t.pulse(d.io_localTrap);
  t.check(d.io_trapDepth == 1, "owned trap was not retained");
  t.pulse(d.io_localCancel);
  d.io_request = 1; t.ticks(100);
  t.check(!d.io_packageIdle && !(d.io_checkerAcks & 1) && !d.io_ack,
          "transport reset bypassed an owned trap");
  d.io_managementTrap = 0;
  t.pulse(d.io_localRet);
  t.ticks(100);
  t.check(!d.io_trapDepth && d.io_specialReturn && !d.io_packageIdle && !d.io_ack,
          "matching xRET bypassed the pending management-PC return");
  t.pulse(d.io_localReturned);
  t.until([&]{ return d.io_ack; }, "clean package did not release transport receipt");
  t.check(d.io_packageIdle && d.io_contextIdle, "package return did not restore admission");
  d.io_request = 0;
  t.until([&]{ return !d.io_ack && !d.io_checkerAcks; }, "second receipt did not return low");
  std::puts("CASE owned_trap_return_blocks_transport_reset PASS");
  // Exercise every persistent Seq bit on actual DATA, ARF, END/count and
  // result CDC paths. Each reset waits for source-side pointer receipts;
  // restarting with Seq1 must not expose any old payload or result.
  for (uint32_t seq : {0x80000001u, 0xfffffefdu, 0xfffffffeu}) {
    d.io_segment = d.io_owned = d.io_request = 0;
    d.io_managementTrap = 0;
    d.io_ingressReady = 0;
    t.frozen = 0;
    d.reset = 1; t.ticks(20); d.reset = 0; t.ticks(100);
    t.frozen = 1;
    d.io_segment = seq;
    d.io_owned = 1;
    d.io_payload = 0xa55a123400000000ULL | seq;
    d.io_dataBeat = d.io_arfBeat = 1;
    t.step();
    d.io_dataBeat = d.io_arfBeat = 0;
    t.ticks(40);
    t.check(!d.io_producerBusy && !d.io_anchors && !d.io_arfCount,
            "paused Checker consumed old DATA/ARF");
    d.io_segment = 0;
    d.io_request = 1;
    t.ticks(80);
    t.check(!d.io_ack && !(d.io_checkerAcks & 1),
            "transport reset passed undelivered high Seq payloads");
    t.frozen = 0;
    t.ticks(30);
    t.check(!d.io_arfCount, "ARF passed its blocked DATA anchor");
    d.io_ingressReady = 1;
    t.until([&]{ return d.io_receivedEnd && d.io_receivedSeq == seq && d.io_arfCount == 1; },
            "high Seq DATA/ARF/END not delivered");
    t.check(d.io_dataSeq == seq && d.io_dataWord == d.io_payload &&
            d.io_arfSeq == seq && d.io_arfWord == d.io_payload && d.io_anchors == 1,
            "32-bit Seq or payload truncated/corrupted");
    d.io_resultSeq = seq;
    while (t.clocks & 1) t.step();
    d.io_resultValid = 1;
    do { t.step(); } while (!(t.clocks & 1));
    d.io_resultValid = 0;
    t.until([&]{ return d.io_release && d.io_resultSeen == seq; }, "high Seq result lost");
    t.ticks(100);
    t.check(!d.io_ack, "transport reset bypassed held old result release");
    d.io_owned = 0;
    t.until([&]{ return d.io_ack; }, "source pointer receipts did not complete");
    t.check(d.io_receivedSeq == 0 && !d.io_receivedEnd, "high Seq consumer tag survived reset");
    d.io_request = 0;
    t.until([&]{ return !d.io_ack && !d.io_checkerAcks; }, "four-phase reset ACK not released");
    const unsigned oldAnchors = d.io_anchors, oldArfs = d.io_arfCount;
    d.io_payload = 0x1122334455667788ULL;
    d.io_segment = 1;
    d.io_dataBeat = d.io_arfBeat = 1; t.step();
    d.io_dataBeat = d.io_arfBeat = 0;
    t.until([&]{ return d.io_receivedEnd && d.io_receivedSeq == 1 && d.io_arfCount == oldArfs + 1; },
            "Seq1 reuse did not deliver fresh DATA/ARF/END");
    t.check(d.io_dataSeq == 1 && d.io_arfSeq == 1 && d.io_dataWord == d.io_payload &&
            d.io_arfWord == d.io_payload && d.io_anchors == oldAnchors + 1 && !d.io_release,
            "old high Seq payload/result contaminated Seq1 reuse");
    d.io_segment = 0; t.ticks(100);
    t.check(d.io_anchors == oldAnchors + 1 && d.io_arfCount == oldArfs + 1 && !d.io_release,
            "late old transport item after Seq1 reuse");
    std::printf("CASE seq32_all_channels old=%08x reused=1 PASS\n", seq);
  }
  d.io_segment=d.io_owned=d.io_request=0;
  d.io_session=0;d.io_ingressReady=0;d.reset=1;t.ticks(20);d.reset=0;t.ticks(100);
  d.io_session=1;t.ticks(40);
  d.io_segment=42;d.io_owned=1;d.io_payload=0x42424242;
  d.io_dataBeat=d.io_arfBeat=1;t.step();d.io_dataBeat=d.io_arfBeat=0;
  // Production R_IC retains checker_segment_id until result release. Ending
  // producer input must not clear this outstanding Checker owner in the fixture.
  t.ticks(40);d.io_session=2;
  t.ticks(100);t.check(!d.io_sessionDone,"session finished with blocked transport");
  d.io_ingressReady=1;
  t.until([&]{return d.io_receivedEnd && d.io_receivedSeq==42 && d.io_arfCount==1;},
          "final session package did not drain its ingress");
  t.ticks(100);
  t.check(!d.io_sessionDone,"session FINISH overtook a pending Checker package");
  d.io_resultSeq=42;
  while(t.clocks&1)t.step();d.io_resultValid=1;
  do{t.step();}while(!(t.clocks&1));d.io_resultValid=0;
  t.until([&]{return d.io_release && d.io_resultSeen==42;},"final session result lost");
  t.ticks(100);t.check(!d.io_sessionDone,"session FINISH overtook Main owner release");
  d.io_owned=0;d.io_segment=0;
  t.until([&]{return d.io_sessionDone;},"session FINISH missing after actual release");
  std::puts("CASE session_finish_waits_for_package_release PASS");

  d.io_session = 0;
  d.reset = 1; t.ticks(20); d.reset = 0; t.ticks(100);
  d.io_segment = 1;
  d.io_producerHasData = 1;
  d.io_payload = 0x76543210;
  unsigned queuedArfs = 0;
  while (!d.io_arfBusy && queuedArfs < 16) {
    d.io_arfBeat = 1;
    t.step();
    ++queuedArfs;
  }
  d.io_arfBeat = 0;
  t.check(d.io_arfBusy && !d.io_arfCount && !d.io_anchors, "ARF queue did not fill before DATA");
  t.check(!d.io_producerBusy, "full ARF queue prevented delivery of its DATA anchor");
  d.io_dataBeat = 1;
  t.step();
  d.io_dataBeat = d.io_producerHasData = 0;
  t.until([&]{ return d.io_receivedEnd && d.io_arfCount == queuedArfs && !d.io_arfBusy; },
          "DATA anchor did not drain the full ARF queue");
  t.check(d.io_anchors == 1 && d.io_dataSeq == 1 && d.io_arfSeq == 1 &&
          d.io_dataWord == d.io_payload && d.io_arfWord == d.io_payload,
          "DATA/ARF ownership changed while releasing backpressure");
  std::puts("CASE full_arf_queue_allows_data_anchor PASS");

  d.io_segment = 2;
  d.io_producerHasData = d.io_arfIsCps = 1;
  d.io_arfBeat = 1;
  t.step();
  d.io_arfBeat = 0;
  t.until([&]{ return d.io_arfCount == queuedArfs + 1; },
          "CPS waited for unrelated predecessor data in the producer");
  t.check(d.io_producerHasData && d.io_anchors == 2 && d.io_dataSeq == 2 &&
          d.io_arfSeq == 2 && d.io_arfWord == d.io_payload &&
          !(d.io_receivedEnd && d.io_receivedSeq == 2),
          "CPS did not receive a sequence-qualified startup marker");
  d.io_producerHasData = 0;
  t.until([&]{ return d.io_receivedEnd && d.io_receivedSeq == 2; },
          "CPS marker was mistaken for package completion");
  std::puts("CASE cps_anchor_bypasses_unrelated_producer_data PASS");
  std::puts("PALIMPSEST_SEQ_TRANSPORT=PASS");
  d.final();
}
