// Read-only observation of the original IOMSHR plus rebase owner lifecycle.
#define __wrap__ZN12VTestHarness9eval_stepEv observe_io_effect
#include "io_effect_observer.cc"
#undef __wrap__ZN12VTestHarness9eval_stepEv

#define BOOM(name) r.TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__##name

extern "C" void __wrap__ZN12VTestHarness9eval_stepEv(VTestHarness* sim) {
  observe_io_effect(sim);
  auto& r = *sim->rootp;
  static FILE* stream = [] {
    const char* name = std::getenv("PALIMPSEST_OVERLAP_LOG");
    FILE* f = name ? std::fopen(name, "wx") : nullptr;
    if (!f) { std::perror("PALIMPSEST_OVERLAP_LOG"); std::exit(2); }
    return f;
  }();
  const unsigned valid = BOOM(core__DOT__ic_master__DOT__packet_alloc_valid_reg);
  const uint32_t seq = BOOM(core__DOT__ic_master__DOT__packet_alloc_seq_reg);
  const unsigned pending = BOOM(core__DOT__rebasePending);
  const unsigned effect = BOOM(_dcache_io___05FioEffectPending);
  const unsigned reset = BOOM(dcache__DOT__sequenceReset);
  static unsigned pv = 2, pp = 2, pe = 2, pr = 2;
  static uint32_t ps = 0;
  if (valid == pv && (!valid || seq == ps) && pending == pp && effect == pe && reset == pr) return;
  std::fprintf(stream, "%llu %u %u %u %u %u %u\n",
               (unsigned long long)sc_time_stamp(), unsigned(sim->clock),
               valid, seq, pending, effect, reset);
  std::fflush(stream);
  pv = valid; ps = seq; pp = pending; pe = effect; pr = reset;
}
