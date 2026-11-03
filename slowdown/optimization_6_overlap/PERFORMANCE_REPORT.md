# Opt4 slowdown optimization

Worktree `/data1/gzh/EC-opt4-perf`, branch `opt4/perf-20261103`.
Main/FPGA source and processes were left independent.

## Measured milestones

All measurements use pinned GAPBS BFS: 512 nodes, 8,192 edges, source 0,
checksum 43,439,728 / verified=1. Native ROI is 1,001,675 BOOM cycles.

| Version | ROI cycles | Slowdown | Reduction from frozen Opt4 |
| --- | ---: | ---: | ---: |
| Frozen Opt4 `476a76091` | 1,707,863 | 1.705007x | — |
| A: direct checker delivery + SourceC overlap | 1,426,845 | 1.424459x | 281,018 cycles / 16.45% |
| B: terminal bypass + fetch8 + prefix fusion | 1,174,774 | 1.172810x | 533,089 cycles / 31.21% |
| C: retain acknowledged safe L1 copy | Pending | Pending | Pending |

B clears both 1.5x and 1.3x. Its remaining overhead is 173,099 cycles relative to
native, versus 706,188 frozen: a 75.49% reduction of excess runtime. This is one
workload and one pinned simulator seed, without timing/FPGA signoff.

Four 100 MHz Rocket checkers, 200 MHz BOOM, L1D 32 KiB (256 sets, 2 ways,
64-byte blocks, 6 MSHRs), SVB16, and L2 1 MiB (1,024 sets, 16 ways, one bank)
are preserved. Generated CPU/cache and complete clock descriptions were compared
against the frozen reference. Checker fetch increases from four to eight bytes;
decode and retirement remain scalar, and ICache geometry is preserved.

## Implemented mechanisms

A delivers an owned, classified S2 instruction response directly into FQ and
launches its known successor on acceptance. Backpressure, missing/mismatched BJL,
faults and replays retain the registered fallback. Branch-log reservation occurs
only on actual accepted delivery, with redirect/clear cancellation. A also frees
SourceC admission during pure checkpoint waitAck, retaining the target-set lock,
full image and terminal ACK owner.

B enqueues store terminal results on the accepted physical-effect edge, enables
empty completion-queue flow-through, and lets a younger S0 store use only an
identity-matched terminal actually accepted on that edge. The ordinary STQ handler
remains the sole ownership release. Per-slot completion guards remain; replay/nack
priority suppresses forwarding. B also supplies two instruction words per fetch
and fuses a straight-line prefix with its first CFI when the real matching BJL
head is ready. Otherwise the original prefix/held fallback remains.

A and B each combine coherent mechanisms. Their measured increments are 281,018
and 252,071 cycles respectively; no isolated component ROI claim is supported.
SourceC overlap was exercised only three times in A and once in B. The much larger
frontend and terminal activity reductions support continued focus on those paths,
without treating local event counts as counterfactual cycle savings.

## Observed stalls and mechanism use

Priority categories are checker-local cycles per checked instruction, from complete
captured packages inside ROI. Package boundaries change as BOOM timing changes;
these are normalized distributions, not paired traces or additive BOOM savings.

| Category | Frozen | A | B |
| --- | ---: | ---: | ---: |
| Instruction starvation | 2.09273 | 0.72672 | 0.02017 |
| Issue available | 1.00018 | 1.00454 | 1.00501 |
| Dependency | 0.00040 | 0.10235 | 0.22094 |
| Setup / redirect / management | 0.15916 | 0.32014 | 0.33373 |
| LSL wait | 0.00009 | 0.00212 | 0.00236 |
| Other | 0 | 0.01904 | 0.03863 |

Captured packages/instructions: frozen 278/570,177; A 270/590,230;
B 269/624,770. One crossing package and four incomplete captures are excluded
in each report. Epoch is sampled metadata and can change within one package;
profile identity is hart/sequence. All accepted starts have zero counters, and
per-owner counters are monotonic with exact partition conservation.

B's complete SC49/SC50 traffic-window counters close: 61,219 physical store
effects, all with effect-edge terminal enqueue, 55,667 effect-edge terminal
deliveries, and 39,196 forwarded successor-store admissions. Applied-S3 queue
blocking is zero; queued/blocked terminal cycles are 6,528. Checker ICache acquire
counts are 27/19/24/22 and TLB-miss counts zero. L1 and L2 MSHR-full counters are
zero. Capacity expansion and further fetch-width growth have weak evidence here.

B's observed traditional preservation path has 851 complete WB-to-clear episodes:
55,505 cycles from WB acceptance to receipt, then 851 to clear, plus induced demand
refills outside that phase count. C tests keeping the acknowledged T copy in L1.
Dependency/management predicates now exceed frontend starvation, but they overlap
producer progress, tail waiting and architectural pipeline constraints; their causal
BOOM contribution has not been isolated. Captured result-enqueue backpressure is
zero, and admission-to-start is about 51 local cycles/package.

## Validation and evidence boundary

B software, integrity, same-line ordering, result/ACK protocol and mandatory
capture PASS; checksum correct; zero FAIL, CANCELLED and assertion. All 7,438
releases match ACKs, with no source conflict, invalid ACK or outstanding source at
exit. Integrity closes 293 allocations as 291 completions, one coalesced and one
flush-discarded. All 127 mandatory observer/producer identities close, including
SC48/49/50 phase, state, subset and same-enable window checks. Optional diagnostic
loss is explicit (731 examples) and does not affect mandatory validation.

Actual emitted IBuf RTL passed both fetch widths under mixed RVC/RVI, cross-word
instructions, BJL ownership, random ready/valid, kills and syscall suppression.
Actual emitted WB RTL passed 300 TtoT/TtoN publications, 100 probes while ACK was
pending, random array/C/LSU notification stalls, full data/identity checks and 900
blocked busy-source attempts. Reduced CPU contracts cover completion and retained
copy interleavings; these do not substitute for RTL runtime tests.

L2 shadow-model fidelity fails in frozen/A/B; derived cache-geometry estimates are
excluded. Benchmark/lifecycle PASS does not establish every injected rollback,
exception or full durable recovery/drain path. Version retention, watermark,
PASS/FAIL/CANCELLED, source ownership and same-line ordering remain functional
requirements rather than performance assumptions.

## Rejected and deferred work

Safe-predecessor capture into SPEC SVB remains withheld: exception flush can discard
safe SPEC entries before promotion, and selection is epoch-qualified. Broader
reliance needs retention/epoch/recovery proof and tests first. Increasing SVB capacity
had a small prior fixed-trace envelope (5,254 cycles); promotion-only exposure was
24,569, with no causal savings established. Cache/count/clock scaling is excluded.
The initial direct-delivery combinational loop was rejected by FIRRTL and corrected
before A; no failing hardware candidate is presented as a measured improvement.

Further store issue overlap could reduce the three-cycle hit-store interval, but
requires explicit ordering across misses, same-slot image-generation dependencies,
S3 turnover, probes, replay and exact terminal ownership. Dependency/management
optimization first needs finer measured attribution. These are future experiments,
not reasons to remove safety gates from the current validated version.

Exact patches, binary seals, generated configuration checks and compact results:
`results/direct_sourcec_v2/` and `results/terminal_fetch8_prefix/`.
Full ignored runs/builds are retained under the matching run IDs. A is committed as
`4250b35fe` and B as `40c8a18ca`. C's sealed binary SHA256 is
`66ab0661ba28dc040cc2fb6dae6bf5f6be6d21ed4bf035a94861dff7c9110e6a`;
its end-to-end simulation is running and the source change remains independent.
