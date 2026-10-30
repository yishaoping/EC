#ifndef OPT4_WAVEFORM_RUNTIME_H
#define OPT4_WAVEFORM_RUNTIME_H
// Included only by the build-local emulator copy. VERILATOR_THREADS=1.
// Ordinary $stop/assertions finish their current eval with fatalOnError(false).
// A true fatal cannot safely evaluate/dump again: close the last complete edge.
#include "verilated.h"
#include "verilated_fst_c.h"
#include <cstdio>
#include <cstdlib>
static VerilatedFstC* opt4_waveform_trace = nullptr;
void vl_fatal(const char* filename, int linenum, const char* hier, const char* msg) {
  (void)hier;
  std::fprintf(stderr, "%%Error: %s:%d: %s\n", filename ? filename : "", linenum, msg);
  std::fprintf(stderr, "[OPT4_WAVEFORM] fatal: closing FST at last completed dump\n");
  if (opt4_waveform_trace) {
    opt4_waveform_trace->flush();
    opt4_waveform_trace->close();
    opt4_waveform_trace = nullptr;
  }
  std::fflush(stdout);
  std::fflush(stderr);
  std::exit(1);
}
#endif
