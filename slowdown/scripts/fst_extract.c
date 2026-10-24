/*
 * Offline observation reader. Built only when the user runs the experiment.
 * Hierarchy mode never traverses value blocks. Every potential native-reader
 * side effect is confined by the launcher's read-only-root sandbox.
 */
#define _GNU_SOURCE
#include "fstapi.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  uint64_t start, end;
  unsigned count;
  unsigned char *selected;
  char **last;
  int seeded;
} Trace;
static void die(const char *s) { fprintf(stderr, "%s\n", s); exit(2); }
static int selected_name(const char *name) {
  if (strstr(name, "slowdown_")) return 1;
  /* Reuse these pre-existing dontTouch fields; no new hardware observation
   * state is needed for S2 replay/nack or preservation lifecycle evidence. */
  static const char *existing[] = {
    "debug_s2_request_token", "debug_s2_transaction_token", "debug_s2_admission",
    "debug_s2_addr", "debug_s2_type", "debug_s2_stq_idx", "debug_s2_packet_seq",
    "debug_s2_nack", "debug_s2_nack_miss", "debug_s2_nack_victim", "debug_s2_nack_wb", "debug_s2_nack_data",
    "debug_s2_send_resp", "debug_s2_send_nack", "debug_s1_valid", "debug_s1_addr",
    "debug_s1_packet_seq", "debug_safe_packet_watermark",
    "debug_cross_package_wb_valid", "debug_cross_package_wb_ready", "debug_cross_package_wb_fire",
    "debug_cross_package_wb_done", "debug_cross_package_meta_clear_pending",
    "debug_cross_package_meta_clear_block", "debug_cross_package_meta_clear_fire",
    "debug_store_terminal_fire", "debug_store_terminal_token", "debug_store_terminal_status",
    "debug_l1_cross_package_blocked", "debug_replay_cancel", "debug_replay_effect_done"
  };
  for (unsigned i = 0; i < sizeof(existing) / sizeof(existing[0]); i++) {
    size_t n = strlen(existing[i]);
    if (!strncmp(name, existing[i], n) &&
        (!name[n] || name[n] == ' ' || name[n] == '[' ||
         (name[n] == '_' && name[n+1] >= '0' && name[n+1] <= '9'))) return 1;
  }
  return 0;
}
static void seed(Trace *t) {
  if (t->seeded) return;
  for (unsigned h = 1; h <= t->count; h++)
    if (t->selected[h] && t->last[h])
      printf("V\t%" PRIu64 "\t%u\t%s\n", t->start, h, t->last[h]);
  t->seeded = 1;
}
static void change(void *opaque, uint64_t time, fstHandle handle,
                   const unsigned char *value) {
  Trace *t = opaque;
  if (handle > t->count || !t->selected[handle]) return;
  if (time >= t->start) seed(t);
  if (t->last[handle] && !strcmp(t->last[handle], (const char *)value)) return;
  free(t->last[handle]);
  t->last[handle] = strdup((const char *)value);
  if (!t->last[handle]) die("out of memory");
  if (time >= t->start && time <= t->end)
    printf("V\t%" PRIu64 "\t%u\t%s\n", time, handle, value);
}
int main(int argc, char **argv) {
  if (argc < 3 || (strcmp(argv[2], "hierarchy") && strcmp(argv[2], "trace"))) {
    fprintf(stderr, "usage: fst_extract FILE hierarchy | FILE trace [START END]\n");
    return 2;
  }
  void *r = fstReaderOpen(argv[1]);
  if (!r) die("cannot open FST");
  Trace t = {0};
  t.count = fstReaderGetMaxHandle(r);
  t.selected = calloc((size_t)t.count + 1, 1);
  t.last = calloc((size_t)t.count + 1, sizeof(char *));
  if (!t.selected || !t.last) die("out of memory");
  t.start = argc > 3 ? strtoull(argv[3], NULL, 0) : fstReaderGetStartTime(r);
  t.end = argc > 4 ? strtoull(argv[4], NULL, 0) : fstReaderGetEndTime(r);
  if (t.start > t.end) die("invalid time range");
  printf("META\t%" PRIu64 "\t%" PRIu64 "\t%d\n",
         fstReaderGetStartTime(r), fstReaderGetEndTime(r),
         (int)fstReaderGetTimescale(r));
  printf("WINDOW\t%" PRIu64 "\t%" PRIu64 "\n", t.start, t.end);
  char *stack[256] = {0};
  unsigned depth = 0, found = 0;
  struct fstHier *h;
  while ((h = fstReaderIterateHier(r))) {
    if (h->htyp == FST_HT_SCOPE) {
      if (depth == 256) die("hierarchy too deep");
      stack[depth++] = strdup(h->u.scope.name);
    } else if (h->htyp == FST_HT_UPSCOPE) {
      if (depth) free(stack[--depth]);
    } else if (h->htyp == FST_HT_VAR && selected_name(h->u.var.name)) {
      printf("H\t%u\t%u\t", h->u.var.handle, h->u.var.length);
      for (unsigned i = 0; i < depth; i++) printf("%s.", stack[i]);
      puts(h->u.var.name);
      if (h->u.var.handle > t.count) die("invalid FST handle");
      t.selected[h->u.var.handle] = 1;
      found++;
    }
  }
  if (!found) die("no slowdown aliases in waveform hierarchy");
  if (!strcmp(argv[2], "trace")) {
    fstReaderClrFacProcessMaskAll(r);
    for (unsigned i = 1; i <= t.count; i++)
      if (t.selected[i]) fstReaderSetFacProcessMask(r, i);
    fstReaderSetLimitTimeRange(r, 0, t.end);
    if (!fstReaderIterBlocks(r, change, &t, NULL)) die("FST iteration failed");
    seed(&t);
  }
  while (depth) free(stack[--depth]);
  for (unsigned i = 1; i <= t.count; i++) free(t.last[i]);
  free(t.last); free(t.selected);
  fstReaderClose(r);
  return 0;
}
