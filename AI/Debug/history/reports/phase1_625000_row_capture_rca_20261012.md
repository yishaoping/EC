# Phase-1 625000 Failure RCA

Date: 2026-10-12 (Asia/Shanghai)

This is a read-only analysis of the post-Scheme-A run. No functional source,
generated RTL, simulator, or test was modified or regenerated in this RCA.

## Conclusion

The failure is a direct MSHR assertion, not a watchdog:

```text
[625000] BoomMSHR.sv:579
  mshrs_3.assert__assert_4
source: mshrs.scala:208 assert(!io.refill_fault, "active refill owner mismatch")
```

The first bad state is earlier than the assertion. MSHR3 accepts a normal load
LineBuffer read in `s_drain_rpq_loads` at FST 1250537 (cycle 625268). The
shared `io.lb_read.fire` capture sets the install-only `rowValid` register at
FST 1250539 (cycle 625269), while the MSHR is still state 3 and
`installStarted=0`. The held row survives metadata read/clear and writeback.
At FST 1250563 (cycle 625281), state `s_commit_line` presents `refill.valid`
with `installActive=0`, producing `io_refill_fault_3=1`. The generated
assertion observes that fault on the following sequential assertion sample
(trace count approximately 625282); the saved waveform ends at FST 1250564
because Verilator stops on the assertion.

This is an install/refill lifecycle and row-provenance bug. It is not the
previous physical-tag interpretation bug.

## Evidence boundary

The assertion, generated RTL, source, and waveform all come from the same run
and source snapshot recorded in:

`AI/TMP/rca_phase1_625000_20261012_212146/manifest.json`

Key evidence:

- `test.log`: direct `mshrs_3.assert__assert_4` failure.
- `BoomMSHR.sv`: generated control and assertion.
- `first-divergence.txt`, `transaction-detail.txt`,
  `slot-window-complete.txt`: focused failure window.
- `all-mshr-row-lifecycle.txt`, `row-capture-events.json`: complete FST
  lifecycle scan.
- `verified-observations.json`: parsed counts and owner predicates.

The emulator dumps FST low/high phases at `trace_count*2` and
`trace_count*2+1`; therefore FST 1250563 is the high phase of trace count
625281. The log's `[625000]` value is formatted/truncated time, not the exact
first-divergence count.

## Failure and owner predicates

At the final observed fault, MSHR3 carries:

| field | value |
|---|---:|
| request | normal `M_XRD` (`0x0`) |
| request address | `0x80007da8` |
| physical line | `0x80007d80` |
| array address | `0x3d80` (set 246) |
| way | way 1 (`way_en=2`) |
| MSHR | 3 |
| transaction | 937 (`0x3a9`) |
| incoming/reservation epoch | 13 |
| resident epoch | 12 |
| new owner | 1 |
| line generation dependency | 40971 (`0xa00b`) |
| request image-valid | 0 |
| FSM | `s_commit_line` (state 11) |
| `rowValid` / `installStarted` | 1 / 0 |

The DCache checks show:

| predicate | observed |
|---|---:|
| physical tag from `line_addr` matches `reservedTag` | yes (`0x20001`) |
| line alignment and set match | yes |
| reservation/epoch/transaction/MSHR match | yes |
| `installReservationMatch` / `installOwnerMatch` | 1 / 1 |
| `installActive` | **0** |
| `refill_fault_3` | **1** |

Thus the only failed owner predicate in this transaction is the absence of an
active install reservation. The line address sideband is correct and is not
the cause of this failure.

## Timeline (FST window 1240564..1250564, cycles 620282..625282)

The following MSHR3 primary transactions are the compact landmarks in the
5000-cycle window. `generation dependency` is the field visible in the MSHR
descriptor; it is not proof that a complete imported ImageKey was established.

| cycle | request/line | version fields visible | owner / transaction | state and result |
|---:|---|---|---|---|
| 620346 | `0x8005ef40` / line same | gen 42563, image-valid not captured | MSHR3, epoch14, txn930 | refill completed; last row at 620404 |
| 621018 | `0x8005f0c0` / line same | gen 42611 | MSHR3, epoch9, txn931 | refill completed; last row at 621095 |
| 621710 | `0x8005f240` / line same | gen 34467 | MSHR3, epoch9, txn932 | refill completed; last row at 621768 |
| 622384 | `0x8005f3c0` / line same | gen 30419 | MSHR3, epoch10, txn933 | refill completed; last row at 622443 |
| 623059 | `0x8005f540` / line same | gen 40707 | MSHR3, epoch15, txn934 | refill completed; last row at 623117 |
| 623749 | `0x8005f6c0` / line same | gen 42803 | MSHR3, epoch12, txn935 | refill completed; last row at 623807 |
| 624521 | `0x8005f728` / line same | gen 44856, image-valid 1 | MSHR3, epoch12, txn936 | prior transaction reaches normal path |
| 625253 | `0x80007da8` / `0x80007d80` | gen 40971, image-valid 0 | MSHR3, epoch13, txn937, new owner | state 1 `s_refill_req`; reservation created |

For transaction 937:

| cycle | event |
|---:|---|
| 625253 | primary descriptor captured; `req_tag_match=0`, old tag `0x20015`, old coherence state 3 |
| 625254 | state 2 `s_refill_resp`; Acquire/Grant path active |
| 625260, 625262, 625265, 625267 | four GrantData beats captured into LineBuffer |
| 625268 | state 3 `s_drain_rpq_loads`; Grant E/finish is accepted and a normal load reads LineBuffer offset 2 |
| **625269** | **first divergence: `rowValid` rises to 1 in state 3, `installStarted=0`** |
| 625270..625273 | metadata read/response/clear states 4..7; bad row remains held |
| 625274 | state 9 writeback request for old victim tag `0x20015` |
| 625275..625280 | state 10 waits for writeback; WB response at 625280 |
| 625281 | state 11 `s_commit_line`; `rowValid=1`, `installStarted=0`, `installActive=0`, refill valid/fault asserted |
| ~625282 | `assert(!io.refill_fault)` fires on the next assertion sample |

The old victim physical line implied by tag/set is `0x80057d80`; this is
writeback context, not the incoming line identity.

## First-divergence causal chain

```text
ordinary RPQ load in s_drain_rpq_loads
  -> shared LineBuffer io.lb_read.fire
  -> rowValid/rowData capture has no state/purpose guard
  -> install row is falsely marked available before install.fire
  -> metadata and victim writeback retain the false rowValid
  -> s_commit_line emits refill with installActive=0
  -> DCache owner predicate rejects it
  -> io_refill_fault_3
  -> mshrs.scala:208 assertion
```

The relevant source is `mshrs.scala:360-405` (load drain) and
`mshrs.scala:448-484` (install row). The generated RTL makes the issue
unambiguous:

- `io_lb_read_valid` is selected from state 3 for RPQ loads or state 11 for
  install reads.
- The common fire wire (`_T_296`) updates `rowValid` and `rowData` without a
  state-11/install-purpose qualifier.
- `io_refill_valid` depends on `rowValid`, `grant_had_data`, and state 11, but
  not on `installStarted`.

Lexically declaring `rowValid` inside the Chisel `s_commit_line` branch does
not give it branch lifetime; it is a hardware register with module lifetime.

## Full-run uniqueness and long-run comparison

The complete FST scan found 22,449 `rowValid` rising captures. 22,448 were in
the install state. The only non-install capture is:

```text
FST 1250539 / cycle 625269 / MSHR3 / state 3 /
installStarted=0 / preceding lb_read valid=1, ready=1
```

The same run contains 22,448 refill row writes and 5,612 completed four-row
line installs before the stop. In the final 5,000-cycle window there are 144
row writes and 36 completed line installs. This supports the conclusion that
Scheme A fixed the earlier physical-tag failure and allowed normal refills to
run for a long time. It does not establish that all later version, certificate,
probe, outer, or backpressure paths are correct.

The paths still not validated by this run include preservation certificate
establishment/invalidations, complete ImageKey provenance for imported lines,
repeated owner handoff under contention, and stale outer response cases. The
current `safePacketWatermark` is 0 and local dirty packet attribution is 0 at
the fault; neither is evidence of a watermark root cause.

## Invariant review

- **Install owner controls refill:** violated. A refill was presented before
  `install.fire` made `installActive` true.
- **One transaction owns one install row:** violated at the row-buffer
  provenance level; a load response was reused as an install row.
- **Physical line identity remains stable:** satisfied for the observed
  transaction (`line_addr=0x80007d80`, set 246, aligned), so this is not the
  Scheme-A address bug.
- **MSHR/transaction/epoch/owner reservation identity:** satisfied in the
  faulting predicate except `installActive`.
- **Refill does not invent version facts:** not falsified by this assertion;
  `req_image_valid=0` and the visible generation are only a dependency
  snapshot. Full ImageKey/certificate state is not exposed in this trace.
- **Validation only advances watermark:** not implicated; no validation
  transition precedes the first divergence.
- **Speculative state cannot pollute safe state:** not implicated as the first
  divergence; no safe/certificate transition is observed before cycle 625269.

## Category ranking

1. **A, refill/install lifecycle: effectively confirmed (about 99%).** The
   shared read-capture register accepts a non-install load and later presents
   it as an install row. The owner assertion is the correct downstream guard.
2. **E, timing/provenance race: secondary (about 1%).** The state-dependent
   ready/fire interaction exposes the missing purpose qualifier. It is a
   deterministic control bug, not evidence of an unrelated asynchronous race.
3. **B, version identity: no first-cause evidence.** The descriptor contains
   an old-victim dependency generation, but the fault occurs before any
   incoming identity commit. It remains an unverified risk for later testing.
4. **C, L2/outer interaction: no first-cause evidence.** GrantData beats,
   Grant E, and the victim writeback response complete before the bad refill.
5. **D, validation/watermark: no first-cause evidence.** The watermark is
   unchanged/zero in the captured state and no validation event precedes the
   divergence.

## Minimal repair direction (no patch in this RCA)

The row capture must carry explicit install-read provenance. The structural
fix should either use a dedicated install-read channel or qualify the capture
and held-row state with the actual install state/purpose, `grant_had_data`,
`installStarted`, and a live transaction owner. The held row must be cleared or
reinitialized at transaction admission, and the refill offer should retain an
active-install guard as a defensive invariant. Merely delaying the assertion,
masking `refill_fault`, or adding a cycle-specific condition would preserve the
wrong-row hazard and is not a valid fix.

Follow-up validation should first prove, with assertions and a focused trace,
that every `rowValid` rising edge is an install-row `lb_read.fire`, that all
four rows use the same MSHR/epoch/transaction/line, and that no refill is
offered before `install.fire`. Only after that should the original long
regression be used to assess remaining version/certificate behavior.
