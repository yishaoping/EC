# Package ownership repair, 2026-09-30

## Preserved baseline

The failing 254-package run is archived as
`test_20260930_1524_254pkg.vcd` and `test_20260930_1524_254pkg.log` in this
directory. See `test_20260930_1524_254pkg.md` for original paths and SHA-256
hashes. The VCD is 1,553,429,949 bytes.

## Waveform evidence

The first `PackageAddressStats.malformedEvent` pulse is at VCD time 383643.
`trafficCounting` becomes 1 at 383633. LSU address events become valid at
383639, 383641, 383643, and 383645, before the first `packet_alloc_valid`
assertion at 383661. Their event sequence remains zero. The error is therefore
caused by measured address events entering the package table before a valid
package sequence exists. The first event is not a cache-line crossing.

The previous source also sampled `io.core.active_packet_seq` live at ROB
retirement for both LDQ and STQ address events. A queue entry can retire after
R_IC has advanced to another package, so this field was not a stable owner tag.
The continuous active-sequence change also caused DCache requests outside
`fsm_check` to inherit the last package ID.

## Source changes

- Restored the BOOM-to-LSU sequence qualification in `exu/core.scala`: LSU's
  coherence request sequence is nonzero only during `fsm_check`, except for the
  explicit new-package allocation pulse.
- Added a packet sequence field to each LDQ entry. LDQ and existing STQ entries
  capture the qualified sequence when address translation first succeeds.
- Address-statistics events now use the sequence stored in their own LSQ entry.
  A zero-sequence startup operation has no package ownership and is not sent to
  the package address table.
- Ordinary architectural Store/Load and strict Store token qualification now
  require both the active measurement window and a nonzero saved package tag.
  This retains delayed retirement of a valid tagged entry after the checker
  state changes, while excluding unowned operations from package-scoped totals.
- Preserved the earlier cross-package shadow-writeback fixes: no reissue during
  metadata clear, and `TLPermissions.TtoN` matches the local metadata invalidation.
- Preserved the prior strict-token replay/STQ execute-head repair.

## Verification

```text
sbt 'project boom' compile
```

Result: success. The repository EC invariant script passed its known protocol
checks. `git diff --check` on the touched Scala files is clean; the repository
script also reports existing whitespace findings in the unrelated
`Experiment/流量分析.typ` file.

No simulation or RTL generation was run. The next run should confirm:

1. `[ADDRESS_STATS] status=PASS valid=1 error=0`;
2. `boom_arch == boom_strict == checker_sum` under the package-owned measurement
   window;
3. the benchmark's known-good `verified=1` and parent checksum;
4. package allocations and accepted results remain sequence matched, with
   allocation/completion/pass totals equal.

