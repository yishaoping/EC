# Stage 3 closure evidence review — 2026-10-21

## Verdict

The sealed run `AI/TMP/stage3_runs/run_qx63gyhc/` satisfies the Stage 3
dynamic closure checklist for the recorded v1Config/workload. This review is
read-only with respect to hardware, software, runner, generated collateral and
the original run. It performed no build, elaboration, RTL generation, Verilator
or simulation.

```ini
RUN=/data1/gzh/EC/AI/TMP/stage3_runs/run_qx63gyhc
STAGE3_DYNAMIC_VALIDATION=PASS
STAGE1_REGRESSION=NONE
STAGE2_REGRESSION=NONE
STAGE3_INVARIANTS=PASS
ALL_DIRECTED_CASES=PASS
OUTSTANDING_TRANSACTIONS=NONE
STAGE3_STATUS=CLOSED
STAGE3_CLOSURE=YES
```

## Evidence identity

| Check | Result | Evidence |
|---|---|---|
| HEAD | PASS; run/current `1ed07c28067fad6d8aed697323b465b925895914` | `AI/TMP/stage3_runs/run_qx63gyhc/inputs.json`, `AI/TMP/stage3_closure_review_20261021_bjm5zr2m/provenance.audit.json` |
| Source inputs | PASS; 11,480 hashes, no mismatch/add/remove | `build/system.build/provenance.json`, provenance audit |
| Source snapshot | PASS; `source.before.json` equals run inputs | `build/system.build/source.before.json` |
| Stage 3 scripts | PASS; all 4 captured hashes match current files | `inputs.json`, provenance audit |
| Workload | PASS; 40 source hashes and benchmark/dump/loadmem hashes match | `system/system.run/workload.json` |
| Generated model | PASS; 3,077 generated files match manifest | `build/system.build/provenance.json`, provenance audit |
| Simulator | PASS; SHA256 `443551829580ad98d1e49935f3469bd28ccd368d85bb8b59d1828f2a0f4a637d` | `system/system.run.wrapper.log`, provenance manifest |
| Phase seals | PASS; build, directed and system artifact hashes, input hashes, plan keys and upstream tokens all match | `build|directed|system/{result.json,seal.json,plan.json}` |

The independent review record is
`AI/TMP/stage3_closure_review_20261021_bjm5zr2m/provenance.audit.json`.
The original run remains immutable; its `summary.out` deliberately remains
`STAGE3_CLOSURE=NO` because that field was emitted before this review.

## Closure checklist

| Requirement | Result | Concrete evidence |
|---|---|---|
| BUILD and assertions | PASS | `build/result.json`: `status=PASS`, `exit_code=0`; build/lint commands contain `--assert`, `-Werror-UNOPTFLAT`, `-Werror-PINMISSING`, `--error-limit 0` |
| Directed inventory | PASS | `directed/directed.coverage.json`: 19 unique cases, each value `1`, `missing=[]`; `module.trace.log`: one PASS marker for each case at lines 51–1395 |
| Directed completion | PASS | `module.trace.log`: `STAGE3_COUNTERS ... assertions=0 errors=0`, `STAGE3_DIRECTED=PASS cycles=2389`, exactly one `[END] status=PASS` |
| Directed preservation correctness | PASS | Coverage protocol: `checkpoint_transactions=9`, `checkpoint_acks=9`, `victim_acks=20`; `duplicate_preserve=0`, `premature_overwrite=0`, `speculative_outer_write=0`, `stale_ack_effect=0`, `errors=[]` |
| Stage 1 architectural data | PASS | `system.run/scoreboard.json`: `architectural_data=PASS`, `ARCH_ERROR=0`, `software_end=PASS`; `stage1.recheck.json`: `architectural_errors=[]` |
| Stage 1 effect lifecycle | PASS | `effect_terminal`, `terminal_release`, `duplicate_effect`, `lost_effect` all PASS; `DUP_EFFECT=0`, `LOST_EFFECT=0`, `EFFECT_WITHOUT_TERMINAL=0`, `DUP_TERMINAL=0`, `TERMINAL_WITHOUT_STQ_RELEASE=0`, `DUP_STQ_RELEASE=0` |
| Stage 1 main/checker | PASS | `MAIN_CHECKER=PASS`; store `60568=60568`, load `95038=95038`, total `155606=155606`, all six diffs zero; accounting sets empty and duplicate identity available |
| AMO.W | PASS | `AMO_W=PASS`, `AMO_ERROR=0`; low and high lanes present in `amo_coverage` |
| Clear/S1/S2/refill | PASS | `CLEAR_S1_S2_REFILL=PASS`, `CLEAR_RACE_VIOLATION=0`; `CLEAR=1169`, `CLEAR_CHECK=1169`, `INSTALL=8980`, `REFILL=35244` |
| Stage 2 | PASS | `stage2.scoreboard.json`: `status=PASS`, `errors=[]`, `missing_coverage=[]`; `PRESERVE=1169`, `PRESERVE_RECEIPT=1169`, `PRESERVE_DONE=1169`, `WAIT_SAFE=1443`, `WAIT_PRESERVATION=987` |
| Stage 3 invariant | PASS | `stage3.scoreboard.json`: `status=PASS`, `errors=[]`, 2,539 checkpoint transactions/ACKs, 860 victim ACKs; all four correctness errors are zero |
| Replay | PASS | `REPLAY=PASS`, `REPLAY_GRANT=10685`, `REPLAY_RESULT=10685`, `REPLAY_UNCLOSED=0` |
| Progress and termination | PASS | `progress.json`: `status=PASS`, `cycles=5603176` below the 500,000,000 limit, no diagnostics; simulator exit 0 and `reason=serial_success` |
| Exit drain | PASS | `exit_real_outstanding=0`, `exit_blockers={}`; DCACHE and LSU sim-exit snapshots are all idle and `fence_ready=1` |
| Software/checker end | PASS | wrapper: `SOFTWARE_REPORT=PASS`, `[END] hart=0 status=PASS`, `STAGE1_SIM_EXIT ... io_success=1` |

## Metadata-clear repair witness

The previous `run_s76blyev` failure repeatedly held a same-set request behind
the metadata clear and eventually watchdogged. In the reviewed run the same
line/set witness is completed: for line `0x80011f80`, set `0x7e`, the trace
shows `PRESERVE_DONE` at line 6,951,735, then `CLEAR`/`CLEAR_CHECK` with
`fire=1`, `s1_any=0`, `s2_any=0`, `s1_old=0`, `s2_old=0`,
`mshr_conflict=0`, and `slot_conflict=0` at lines 6,951,741–6,951,742.
The retried store token `0x136f2` then reaches `EFFECT` (line 6,952,169),
`TERMINAL` (6,952,185), and `RELEASE` (6,952,193). There is no watchdog,
timeout, or outstanding tail. The repaired source is the captured
`chipyard/generators/boom/src/main/scala/lsu/dcache.scala` (current SHA256
`de44644f99c9b5b290df9a7d92ead36ab34348ed159fc4812cb734482e71b5c5`).

## Scope and remaining limits

`NONE` above means no regression or closure blocker was found for the sealed
v1Config workload and the specified directed suite. The evidence is bounded
dynamic validation, not a formal proof of every possible client, address,
interleaving or workload. No assertion was disabled, no speculative outer-write
bypass was added, and no source/model/result provenance was rewritten.

```ini
CLOSURE_BLOCKERS=NONE
NEXT_ACTION=MAINTAIN_STAGE3_CLOSED_STATUS
```
