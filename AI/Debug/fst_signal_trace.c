/*
 * Stream selected FST signals without expanding the trace to VCD.
 *
 * Build:
 *   cc -O2 -I/usr/local/share/verilator/include/gtkwave \
 *      Debug/fst_signal_trace.c \
 *      /usr/local/share/verilator/include/gtkwave/fstapi.c \
 *      -lz -llz4 -o Debug/fst_signal_trace
 *
 * Example:
 *   Debug/fst_signal_trace test.vcd 1067000 1070000 \
 *      'core\.(package_|io_package_result_|icsl\.fsm_state)' \
 *      'core\.ic_master\.(io_ic_status_1|io_clear_ic_status_1)'
 */
#define _GNU_SOURCE
#include "fstapi.h"
#include <inttypes.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  fstHandle handle;
  char *name;
  unsigned length;
  char *last;
} Signal;

typedef struct {
  Signal *signals;
  size_t count;
  size_t cap;
  uint64_t start;
  uint64_t end;
} Trace;

static void fail(const char *msg) {
  fprintf(stderr, "%s\n", msg);
  exit(2);
}

static void add_signal(Trace *trace, fstHandle handle, const char *name,
                       unsigned length) {
  if (trace->count == trace->cap) {
    trace->cap = trace->cap ? trace->cap * 2 : 64;
    trace->signals = realloc(trace->signals, trace->cap * sizeof(*trace->signals));
    if (!trace->signals) fail("out of memory");
  }
  Signal *s = &trace->signals[trace->count++];
  s->handle = handle;
  s->name = strdup(name);
  s->length = length;
  s->last = NULL;
}

static void hier_path(char **stack, size_t depth, const char *leaf,
                      char *out, size_t out_len) {
  size_t used = 0;
  out[0] = 0;
  for (size_t i = 0; i < depth; ++i) {
    int n = snprintf(out + used, out_len - used, "%s%s", used ? "." : "",
                     stack[i]);
    if (n < 0 || (size_t)n >= out_len - used) return;
    used += (size_t)n;
  }
  snprintf(out + used, out_len - used, "%s%s", used ? "." : "", leaf);
}

static void value_change(void *opaque, uint64_t time, fstHandle handle,
                         const unsigned char *value) {
  Trace *trace = opaque;
  for (size_t i = 0; i < trace->count; ++i) {
    Signal *s = &trace->signals[i];
    if (s->handle != handle) continue;
    const char *v = (const char *)value;
    int changed = !s->last || strcmp(s->last, v) != 0;
    if (time >= trace->start && time <= trace->end && changed) {
      printf("%" PRIu64 " %s = %s\n", time, s->name, v);
    }
    if (changed) {
      free(s->last);
      s->last = strdup(v);
    }
  }
}

int main(int argc, char **argv) {
  if (argc < 4) {
    fprintf(stderr, "usage: %s FST START END [regex ...]\n", argv[0]);
    return 2;
  }
  Trace trace = {0};
  trace.start = strtoull(argv[2], NULL, 0);
  trace.end = strtoull(argv[3], NULL, 0);
  regex_t *patterns = NULL;
  size_t pattern_count = argc > 4 ? (size_t)(argc - 4) : 0;
  if (pattern_count) {
    patterns = calloc(pattern_count, sizeof(*patterns));
    if (!patterns) fail("out of memory");
    for (size_t i = 0; i < pattern_count; ++i) {
      int rc = regcomp(&patterns[i], argv[i + 4], REG_EXTENDED | REG_NOSUB);
      if (rc) fail("invalid regular expression");
    }
  }

  void *ctx = fstReaderOpen(argv[1]);
  if (!ctx) fail("cannot open FST");
  fprintf(stderr, "trace time range: %" PRIu64 "..%" PRIu64 "\n",
          fstReaderGetStartTime(ctx), fstReaderGetEndTime(ctx));
  char **stack = NULL;
  size_t depth = 0, stack_cap = 0;
  struct fstHier *h;
  while ((h = fstReaderIterateHier(ctx)) != NULL) {
    if (h->htyp == FST_HT_SCOPE) {
      if (depth == stack_cap) {
        stack_cap = stack_cap ? stack_cap * 2 : 32;
        stack = realloc(stack, stack_cap * sizeof(*stack));
        if (!stack) fail("out of memory");
      }
      stack[depth++] = strdup(h->u.scope.name);
    } else if (h->htyp == FST_HT_UPSCOPE) {
      if (depth) free(stack[--depth]);
    } else if (h->htyp == FST_HT_VAR) {
      char path[8192];
      hier_path(stack, depth, h->u.var.name, path, sizeof(path));
      int match = pattern_count == 0;
      for (size_t i = 0; i < pattern_count; ++i) {
        if (regexec(&patterns[i], path, 0, NULL, 0) == 0) {
          match = 1;
          break;
        }
      }
      if (match) add_signal(&trace, h->u.var.handle, path, h->u.var.length);
    }
  }
  fprintf(stderr, "selected %zu signals\n", trace.count);
  /* Process only selected handles.  This keeps a large FST stream bounded by
   * the requested signal set rather than decoding every hierarchy node. */
  fstReaderClrFacProcessMaskAll(ctx);
  for (size_t i = 0; i < trace.count; ++i)
    fstReaderSetFacProcessMask(ctx, trace.signals[i].handle);
  fstReaderSetUnlimitedTimeRange(ctx);
  if (!fstReaderIterBlocks(ctx, value_change, &trace, NULL))
    fail("FST block iteration failed");
  if (getenv("FST_TRACE_FINAL")) {
    printf("FINAL @ %" PRIu64 "\n", fstReaderGetEndTime(ctx));
    for (size_t i = 0; i < trace.count; ++i) {
      Signal *s = &trace.signals[i];
      printf("%s = %s\n", s->name, s->last ? s->last : "<unset>");
    }
  }
  for (size_t i = 0; i < trace.count; ++i) {
    free(trace.signals[i].name);
    free(trace.signals[i].last);
  }
  free(trace.signals);
  for (size_t i = 0; i < depth; ++i) free(stack[i]);
  free(stack);
  for (size_t i = 0; i < pattern_count; ++i) regfree(&patterns[i]);
  free(patterns);
  fstReaderClose(ctx);
  return 0;
}
