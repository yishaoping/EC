# EC Performance-Only: BJL + result CDC structural candidate

Independent branch `ec-performance-only-rtl-timing-r2-20261115`, retaining the
validated BJL candidate `c88288e`. Production changes are limited to three files:

- `guardiancouncil/GH_FIFO.scala`: inherited BJL reset-masked payload memory.
- `guardiancouncil/GHM.scala`: four 34-bit, 256-entry result CDC queues use the
  already validated `LocalMemAsyncQueue`, with source-local payload selection.
- `diplomacy/DeviceTree.scala`: eliminate intermittently truncated DTB process
  output during elaboration; read a complete file and validate its header size.

The combined production Golden Gate conversion **has completed**, with matching
frozen parameters, class origins, shell-facing ports and target graph outside
the 12 proved queue boundaries. Full shell post-opt has not started because the
other session still owns the CAD leases; no new shell delta or routed timing
result is claimed.

This remains the authorized **Performance-Only** subset descended from frozen
EC `8491167d`, not a full PALIMPSEST functional/FPGA certification. The actual
structural/CDC integration base is the existing `full-r3` elaboration and its
11 immutable shell IPs, not a new cache configuration. DDR IP, Native, cache
capacity, checker behavior, release handshakes and target pipeline stages are
unchanged. No FPGA has been accessed.

## Real measurements and their limits

Vivado 2021.1, `xcu280-fsvh2892-2L-e`, actual complete target modules and paired
settings. **These are not generated-host or full-shell area deltas.**

| Complete target module | LUT before → after | FF before → after | BRAM before → after | F7 / F8 before → after |
|---|---:|---:|---:|---:|
| BJL 82 × 256, inherited `c88288e` | 6,033 → 963 | 21,016 → 286 | 0 → 0 | 2,788 / 1,312 → 8 / 4 |
| Result CDC 34 × 256, this candidate | 3,063 → 43 | 8,832 → 88 | 0 → 0.5 | 272 / 136 → 0 / 0 |

Result CDC uses no DSP/CARRY8/URAM in either implementation. Its reported
highest module fanout drops from 256 to 40. The new queue retains the original
capacity, Gray counters, synchronizers and two-sided reset handshake. The
checker result source is the slower checker clock; dequeue is the BOOM clock.
No checker ACK is fabricated and no release/valid/ready equation is changed.

The comparison reference for the forthcoming new full shell is the existing
structure candidate's **882,423 LUT / 647,405 FF / 696.5 BRAM** post-opt report:

```
/var/tmp/guozh-ec-rtl-structure-r1-20261114/cad-r1/top-postopt-utilization.rpt
```

That already includes earlier improvements from the 936,815 LUT CDC Mem
version. Do not count those gains again. BJL-only and combined whole-shell
gains are **not yet measured**; do not add the module deltas to this reference.

## Verification actually performed

- BJL: inherited 131,073 target-cycle all-output comparison, inductive
  reset-mask refinement and 4,096 actual Golden Gate tokens, including
  negative controls; see `../rtl-timing-r1/results.json`.
- Result CDC: 131,072 two-clock ticks comparing all outputs, including invalid
  payload, independent source/sink reset, full and backpressure.
- Actual 34 × 256 queue netlists: a bijection of 315 state words / 8,828 bits,
  identical clock/reset/init parameters, full-width lane-cone checks and SAT
  for the public outputs and every next-state/control equation. A deliberate
  valid inversion fails.
- Actual reverse-clock Golden Gate host: 8,192 tokens, 2,816 full samples,
  4,782 stalled samples and 7,218 valid payload samples; deliberate mismatch
  at token 100 fails. This harness enables MCRAM generation and disables model multithreading;
  full production `HostConfig` conversion has separately completed. Full
  system workload/checker runtime validation is still pending.
- Important evidence correction: both standalone queue host logs report
  **zero extracted SRAM models**. Their asynchronous memories are not marked
  with `FirrtlMemModelAnnotation`. The old receipt name containing `MCRAM`
  describes the enabled configuration, not proof that these queues were
  converted into independent time-multiplexed RAM models. The full-system
  count of 14 is likewise not evidence of BJL/result queue MCRAM extraction.
  The valid claims are actual Golden Gate token equivalence and the separately
  measured RegVec-to-memory physical mapping. Full shell area is still needed.
- The two `LocalMemAsyncQueue` production class files loaded from the existing
  CDC Mem baseline have identical SHA-256 hashes to those compiled for the
  new result-queue proof. This is checked in `result-cdc/class-identity.json`.
- Complete target elaboration: all eight BJL queues are memories, all four
  original data CDC memories are retained, and all four result queues select
  the verified memory implementation. Frozen parameters and class origins
  are checked.
- `target_audit.py`: the complete target graph outside the eight BJL/four result
  queue boundaries matches the existing baseline. It ignores source metadata,
  including decimal source lines in assertion diagnostic text, and module
  renumbering only. Registers, clocks, logic, connections, assertion conditions
  and every ROM byte remain part of the comparison. This is a compositional
  structural check, not a new workload or whole-checker runtime simulation.

## Additional correctness defect found and repaired

The first BJL elaboration embedded only the first **5,120 of 6,079 DTB bytes**;
the missing tail became zero-filled ROM contents. The expected independent
`dtc` output exactly matches the existing baseline. The original generator's
process-pipe capture reproduced truncation twice in 64 attempts. File output
with size/magic checking passed all 64 attempts byte for byte.

The defective candidate is retained under `full-bjl` with explicit rejection
state and `rom-audit/result.json`. It completed Golden Gate but was stopped
while waiting for the CAD lease: **no DUT or full-shell synthesis was launched
for that invalid ROM**. The corrected BJL elaboration has an exactly matching
ROM and has completed full Golden Gate conversion (14 annotated SRAM models
overall; not 14 BJL/result queue RAM models).

## Remaining physical pressure, from the existing measured netlist

The current reference still has eight BJL payload blocks at about 20,775–20,795
FF each, with four checker-local reset networks around 41,571–41,591 loads and
read-pointer fanout around 5,223–5,226. Those are the main inherited BJL targets,
not a measured residual count in the new candidate.

Other measured inclusive subtrees are DCache 187,097 LUT / 48,873 FF, of which
MSHRFile is 55,213 LUT / 13,984 FF and SVB is 46,027 LUT / 4,321 FF. They overlap
and must not be summed. The MSHR install address/way controls fan out to
2,258–3,212 loads across SLR1/2; one payload select reaches 3,103 loads. The
appliedEffect write-set/way controls have 1,344 loads. Four result CDCs each
consume 8,832 FF in this reference and are the new RTL target measured above.

The old physical reference has CLB site occupancy **97.78 / 94.93 / 99.13%**
despite about 64–69% per-SLR LUT use. The priority is removing array selection,
reset/control and interconnect pressure, not assuming LUT capacity implies
routability. SLR0 DDR calibration's historical failing 3.332 ns path belongs
to unchanged DDR IP and was dominated by routing delay; see the verified
source/path ownership in the r1 README. No new routed DDR result exists for
this candidate.

## Clock repair and deterministic continuation

`strict-host-clock.tcl` repairs the known unsupported `concat` XDC replay. It
accepts only a fresh raw post-opt checkpoint, resolves the original scoped
PCIe groups and checks their exact names against the eight recorded originals.
One supported `get_clocks -filter` union is emitted per group. It verifies the
actual `report_exceptions` database, not explicit cross-clock timing queries.
The DDR 3.332 ns period and generated-clock ancestry are checked, and neither
DDR nor the related host clocks may enter those asynchronous PCIe groups.

The inherited tiny real Vivado test proves the old syntax applies no valid
exceptions and the corrected syntax applies both original directions without
changing periods. The new report checker passes that real positive report and
rejects its negative report. **Replay on the new complete shell is pending**;
the continuation refuses placement unless that actual check passes.

The active, finite continuations are:

1. `ec-performance-only-combined-r2-20261115.service`: complete production
   Golden Gate conversion, then serial DUT / shell post-opt after the existing
   physical lease, existing Vivado exit and fit-CAD lease.
2. `ec-performance-only-combined-physical-r2-20261115.service`: wait for that
   measured capacity-passing post-opt; then acquire both leases and start
   fresh 10 MHz placement, fanout/SLR optimization and routing. It retains
   legal-route, setup/hold, pulse-width, clock coverage, DRC, methodology,
   bus-skew and independent DDR checks before writing a bitstream.

The physical candidate first uses `AltSpreadLogic_high`, with a bounded fresh
`SSI_SpreadSLLs` alternative if physical implementation fails. It never reads
an old failed routed checkpoint. Targeted replication excludes clock buffers
and ASYNC_REG synchronizers. Legal post-route hold repair uses `-hold_fix`.
An invalid clock-replay contract is retained and rejected, not retried under
another placement label.

The corrected BJL-only full Golden Gate output is preserved, but its idle
attribution-only post-opt queue was deferred so it cannot delay the combined
bitstream mainline. No existing Vivado was interrupted. These are dependency
waits and stage continuations, not a periodic patrol or background model agent.

Primary output locations:

```
/var/tmp/guozh-ec-rtl-timing-r2-20261115/full-combined-qualified
/var/tmp/guozh-ec-rtl-timing-r2-20261115/physical-qualified
/var/tmp/guozh-ec-rtl-timing-r2-20261115/qualified-full-9d43368/full-bjl
```

`results.json` records the bounded validation and module area. The evidence
bundle/manifest records the exact files; evolving CAD status remains in the
primary output directories. No usable bitstream, DDR timing closure or FPGA
experiment is claimed until the corresponding actual gates have passed.
