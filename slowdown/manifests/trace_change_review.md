# Trace-only change review

The six Current Scala files contain only observation declarations. The review
boundary is the pair of `SLOWDOWN_TRACE_BEGIN` and `SLOWDOWN_TRACE_END`
markers; `current_trace_only.patch` is generated from the root Git diff for
those six files.

The intended review checks are:

1. every added non-comment line is `val slowdown_* = chisel3.WireInit(...)`,
   `slowdown_*.suggestName(...)`, or `chisel3.dontTouch(...)`;
2. no assignment to an existing functional signal is changed;
3. no state transition, ready/valid equation, parameter, Config, software,
   test, or build script is changed;
4. the pre-existing Current patch is recorded separately in
   `current_preexisting_diff.patch` (it was empty at preparation start);
5. `trace_aliases.json` is the source-to-alias mapping used by the waveform
   hierarchy check.

`DIRECT_EVIDENCE`: `scripts/prepare_trace_visibility.py` compares the original
snapshot with the current source after deleting trace blocks. All nonblank
original lines are identical, every alias declaration matches the recorded
expression and line number, and no alias is referenced outside a trace block.
There are 381 added lines and no removed lines in the six-file Git patch.

`STATIC_INFERENCE`: WireInit copies an existing signal into a fresh wire;
dontTouch and suggestName retain/nickname that wire. The additions create no
registers, memories, IO ports, protocol feedback or stateful control. Removing
them restores the original functional source (apart from blank lines), so they
preserve simulated cycle semantics. Simulation wall time and waveform size may
increase; no claim is made about physical implementation timing.

`UNRESOLVED`: expressions/types, Chisel/FIRRTL acceptance, emitted names and
runtime visibility require the future user-run generation/build. This round
does not run any of those stages. The launcher's post-run hierarchy check must
find the minimum groups, and actual transitions still require offline review.

Before adding these fields, the previous audit's
`AI/TMP/baseline_current_gapbs512_diff_20261023_glZUqT5D/traces/current_dcache_req_freeze_inventory.txt`
and `set_freeze_analysis.md` were consulted. They exposed request valid/ready
only at the end snapshot and lacked contemporaneous address/set/tag and ROB
association. The new aliases target that gap. Existing S2 nack, replay, safe
watermark and preservation debug fields are reused via the reader's explicit
selection list; their RTL is unchanged. No bulk data-array retention is added.
