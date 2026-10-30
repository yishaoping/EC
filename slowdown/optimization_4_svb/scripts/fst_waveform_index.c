/* Offline bounded FST index/final-state reader. No HDL model, no simulation.
 * H lists every opt4 alias; F is the final value of selected causal controls.
 * Value blocks stream once; no full textual waveform or cacheline data dump.
 */
#define _GNU_SOURCE
#include "fstapi.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { unsigned count; char **last; unsigned char *selected; } Index;
static void die(const char *msg) { fprintf(stderr, "%s\n", msg); exit(2); }
static int selected(const char *name) {
  static const char *patterns[] = {"CORE_WATCHDOG_SNAPSHOT", "DCACHE_WATCHDOG_SNAPSHOT",
    "SVB_HANG_ENTRY", "MSHR_HANG_ENTRY", "FASTLINE_BLOCK_OTHER_LINE",
    "opt4_wave_Rob_native_", "opt4_wave_LSU_native_", "opt4_wave_BoomCore_native_",
    "opt4_wave_BoomWritebackUnit_native_", "opt4_wave_BoomProbeUnit_native_",
    "opt4_wave_BoomMSHR_native_"};
  for (unsigned i = 0; i < sizeof(patterns)/sizeof(patterns[0]); i++)
    if (strstr(name, patterns[i])) return 1;
  return 0;
}
static void change(void *opaque, uint64_t time, fstHandle handle, const unsigned char *value) {
  (void)time;
  Index *idx = opaque;
  if (!handle || handle > idx->count || !idx->selected[handle]) return;
  free(idx->last[handle]); idx->last[handle] = strdup((const char *)value);
  if (!idx->last[handle]) die("out of memory");
}
int main(int argc, char **argv) {
  if (argc != 2) die("usage: fst_waveform_index FILE.fst");
  void *reader = fstReaderOpen(argv[1]);
  if (!reader) die("cannot open FST");
  printf("META\t%" PRIu64 "\t%" PRIu64 "\t%d\n", fstReaderGetStartTime(reader),
         fstReaderGetEndTime(reader), (int)fstReaderGetTimescale(reader));
  Index idx = {0}; idx.count = fstReaderGetMaxHandle(reader);
  idx.last = calloc((size_t)idx.count+1, sizeof(char *));
  idx.selected = calloc((size_t)idx.count+1, 1);
  if (!idx.last || !idx.selected) die("out of memory");
  char *stack[256] = {0}; unsigned depth = 0, found = 0;
  struct fstHier *h;
  while ((h = fstReaderIterateHier(reader))) {
    if (h->htyp == FST_HT_SCOPE) {
      if (depth == 256) die("hierarchy too deep");
      stack[depth++] = strdup(h->u.scope.name);
    } else if (h->htyp == FST_HT_UPSCOPE) {
      if (depth) free(stack[--depth]);
    } else if (h->htyp == FST_HT_VAR && strstr(h->u.var.name, "opt4_wave_")) {
      if (!h->u.var.handle || h->u.var.handle > idx.count) die("invalid handle");
      printf("H\t%u\t%u\t", h->u.var.handle, h->u.var.length);
      for (unsigned i=0; i<depth; i++) printf("%s.", stack[i]);
      puts(h->u.var.name); found++;
      if (selected(h->u.var.name)) idx.selected[h->u.var.handle] = 1;
    }
  }
  if (!found) die("no Opt4 waveform aliases");
  fstReaderClrFacProcessMaskAll(reader);
  for (unsigned h=1; h<=idx.count; h++) if (idx.selected[h]) fstReaderSetFacProcessMask(reader, h);
  if (!fstReaderIterBlocks(reader, change, &idx, NULL)) die("FST value iteration failed");
  for (unsigned h=1; h<=idx.count; h++) {
    if (idx.selected[h] && idx.last[h]) printf("F\t%u\t%s\n", h, idx.last[h]);
    free(idx.last[h]);
  }
  while (depth) free(stack[--depth]);
  free(idx.last); free(idx.selected); fstReaderClose(reader);
  return 0;
}
