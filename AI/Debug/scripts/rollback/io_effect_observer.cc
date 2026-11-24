// Read-only Verilator wrapper for the production BOOM IOMSHR.
// Use a separate, flushed stream: simulator stdout/stderr can interleave.
#include "VTestHarness.h"
#include "VTestHarness___024root.h"
#include <cstdint>
#include <cstdio>
#include <cstdlib>

extern double sc_time_stamp();
extern "C" void __real__ZN12VTestHarness9eval_stepEv(VTestHarness*);

#define IO_FIELD(name) r.TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mmios_0__DOT__##name

namespace {
struct Ledger {
  FILE* stream;
  uint64_t count = 0, tick = 0;
  Ledger() {
    const char* filename = std::getenv("PALIMPSEST_IO_EFFECT_LOG");
    if (!filename || !(stream = std::fopen(filename, "wx"))) {
      std::perror("PALIMPSEST_IO_EFFECT_LOG (must be a new file)");
      std::exit(2);
    }
  }
  ~Ledger() {
    std::fprintf(stream, "IO_EFFECT_OBSERVER_END events=%llu last_tick=%llu\n",
                 (unsigned long long)count, (unsigned long long)tick);
    std::fclose(stream);
  }
};
}

extern "C" void __wrap__ZN12VTestHarness9eval_stepEv(VTestHarness* sim) {
  __real__ZN12VTestHarness9eval_stepEv(sim);
  auto& r = *sim->rootp;
  static Ledger ledger;
  ledger.tick = uint64_t(sc_time_stamp());
  const uint64_t state = IO_FIELD(state);
  const uint64_t journal = IO_FIELD(journalValid), replay = IO_FIELD(journalReplay);
  static uint64_t previous = ~0ULL, previousJournal = ~0ULL, previousReplay = ~0ULL;
  if (state == previous && journal == previousJournal && replay == previousReplay) return;
  std::fprintf(ledger.stream,
    "IO_EFFECT_OBSERVER tick=%llu clock=%u old_state=%llu state=%llu "
    "seq=%llx pc=%llx addr=%llx cmd=%llx size=%llx operand=%llx "
    "journal=%llu replay=%llu journal_seq=%llx journal_pc=%llx journal_addr=%llx "
    "journal_cmd=%llx journal_size=%llx journal_operand=%llx "
    "journal_word=%llx grant_word=%llx mem_access_fire=%u\n",
    (unsigned long long)ledger.tick, unsigned(sim->clock),
    (unsigned long long)previous, (unsigned long long)state,
    (unsigned long long)IO_FIELD(req_packet_seq),
    (unsigned long long)IO_FIELD(req_uop_debug_pc),
    (unsigned long long)IO_FIELD(req_addr),
    (unsigned long long)IO_FIELD(req_uop_mem_cmd),
    (unsigned long long)IO_FIELD(req_uop_mem_size),
    (unsigned long long)IO_FIELD(req_data),
    (unsigned long long)journal, (unsigned long long)replay,
    (unsigned long long)IO_FIELD(journalSeq),
    (unsigned long long)IO_FIELD(journalPC),
    (unsigned long long)IO_FIELD(journalAddress),
    (unsigned long long)IO_FIELD(journalCommand),
    (unsigned long long)IO_FIELD(journalSize),
    (unsigned long long)IO_FIELD(journalOperand),
    (unsigned long long)IO_FIELD(journalWord),
    (unsigned long long)IO_FIELD(grant_word), unsigned(previous == 1 && state == 2));
  std::fflush(ledger.stream);
  ++ledger.count;
  previous = state;
  previousJournal = journal;
  previousReplay = replay;
}
