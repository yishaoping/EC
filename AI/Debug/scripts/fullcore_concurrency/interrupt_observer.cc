// Read-only MSIP/interrupt and IOMSHR observation for a complete Core program.
#define __wrap__ZN12VTestHarness9eval_stepEv observe_io_effect
#include "../rollback/io_effect_observer.cc"
#undef __wrap__ZN12VTestHarness9eval_stepEv
#define BOOM(name) r.TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__##name
#define CORE(name) BOOM(core__DOT__##name)

namespace {
struct InterruptLedger {
  FILE* stream = nullptr;
  uint64_t count = 0;
  uint64_t lastTick = 0;
  ~InterruptLedger() {
    if (stream) {
      std::fprintf(stream, "IRQ_OBSERVER_END events=%llu last_tick=%llu\n",
                   (unsigned long long)count, (unsigned long long)lastTick);
      std::fclose(stream);
    }
  }
};
}

extern "C" void __wrap__ZN12VTestHarness9eval_stepEv(VTestHarness* sim) {
  observe_io_effect(sim);
  auto& r = *sim->rootp;
  static InterruptLedger ledger;
  if (!ledger.stream) {
    const char* name = std::getenv("PALIMPSEST_IRQ_LOG");
    ledger.stream = name ? std::fopen(name, "wx") : nullptr;
    if (!ledger.stream) { std::perror("PALIMPSEST_IRQ_LOG"); std::exit(2); }
  }
  ledger.lastTick = uint64_t(sc_time_stamp());
  const unsigned pending = r.TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__ipi_0;
  const unsigned irq = CORE(_csr_io_interrupt);
  const uint64_t cause = CORE(_csr_io_interrupt_cause);
  const unsigned stop = CORE(_rollback_io_stop);
  const unsigned boundary = CORE(ioBoundary__DOT__state);
  const unsigned effect = IO_FIELD(journalValid);
  const unsigned safe = IO_FIELD(journalSafe);
  const unsigned owner = IO_FIELD(state) != 0 && IO_FIELD(req_packet_seq) != 0;
  const unsigned effectPending = BOOM(_dcache_io___05FioEffectPending);
  const unsigned starting = CORE(ioBoundary__DOT__starting);
  // The interruptHold wire is an optimized alias of these actual signals.
  const unsigned hold = starting || boundary != 0 || effectPending;
  const uint32_t seq = IO_FIELD(journalSeq);
  const unsigned trap = CORE(_csr_io_trace_0_exception);
  const uint64_t trapCause = CORE(csr__DOT__cause);
  const unsigned ret = CORE(csr__DOT__insn_ret);
  const uint64_t epc = CORE(csr__DOT__palimpsestRegisters_10);
  static unsigned pp=2, pi=2, ps=2, pb=9, pe=2, pt=2, pSafe=2, pPending=2, pStart=2, pRet=2, pOwner=2;
  static uint32_t pq=0;
  static uint64_t pCause=0, pEpc=0;
  if (pending==pp && irq==pi && stop==ps && boundary==pb &&
      effect==pe && seq==pq && trap==pt && safe==pSafe &&
      effectPending==pPending && starting==pStart && ret==pRet &&
      trapCause==pCause && epc==pEpc && owner==pOwner) return;
  std::fprintf(ledger.stream,
      "IRQ tick=%llu clock=%u pending=%u irq=%u cause=%llx stop=%u boundary=%u effect=%u seq=%x trap=%u safe=%u effect_pending=%u starting=%u hold=%u trap_cause=%llx ret=%u epc=%llx owner=%u\n",
      (unsigned long long)ledger.lastTick, unsigned(sim->clock), pending, irq,
      (unsigned long long)cause, stop, boundary, effect, seq, trap,
      safe, effectPending, starting, hold, (unsigned long long)trapCause, ret,
      (unsigned long long)epc, owner);
  std::fflush(ledger.stream);
  ++ledger.count;
  pp=pending; pi=irq; ps=stop; pb=boundary; pe=effect; pq=seq; pt=trap;
  pSafe=safe; pPending=effectPending; pStart=starting; pRet=ret;
  pCause=trapCause; pEpc=epc;
  pOwner=owner;
}
