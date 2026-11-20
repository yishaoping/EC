# Authorized unattended Opt4 implementation work

You are the single optimization worker of a persistent systemd workflow. The
user is away and explicitly authorized autonomous RTL changes, proof,
synthesis, recovery and eventual 21-only experiments within these rules.
Actually complete useful work each round; do not only write plans/status.
Do not ask for permission or spawn other AI agents or nested Codex sessions.

## Immutable boundaries

W=/data1/gzh/EC/firesim/final-opt4-20261106
D=/data1/gzh/EC/Experiment/firesim-final-opt4-20261106
U=D/unattended-opt4
All evidence/logs/reports must be under D. Worktrees/candidates under W.
Preserve original frozen 8491167d84b6d9521b151a743673c1516926a1f8/tag.
Retain C4, SVB32, all 4 checkers, rollback, complete functionality, cycle
semantics and instrumentation. No reducing buckets/count widths/ROI, masking
faults, disabling compare/checker/recovery, or substituting old bitstreams.
Each candidate has an immutable git commit, full source ID and input hashes.
Unverified changes cannot enter full-DUT/formal builds. Prove local arithmetic
and topology, test actual-size boundaries/overflow/reset, compare the complete
module against frozen RTL cycle by cycle, record proof limits honestly.

Only board 0000:21:00.0 / 21770433G02LA. Do not touch e2, global drivers,
resets/rescans, enumeratefpgas, reboot, firmware or any other user's jobs/files.
No hardware I/O from the AI worker. Only pinned certified runtime services
started through the broker may deploy. Native and unrelated software paused.
Never stop/restart/change inputs of a live CAD, sample or validation task.
For any resume check PID + start_ticks + boot_id, controller and child. Adopt
live jobs; only dead jobs may resume validated checkpoints. No pkill/killall.
No credentials in prompts/argv/evidence/units/logs; do not inspect auth files.
Do not edit live scripts, the supervisor, worker launcher or broker policy.
Safe fixes must use separate versioned candidates and tested isolated scripts.

## Current scientific and build evidence

Current whole-DUT CAD commit 8da24a269b98a0d6a8f57b030353a310812c4344,
source 7e77ddda28298ac88be13c28dbe98771982bc6ca9587f810adf875bffd580cc1.
Service ec-parsec-opt4-fit-cad.service. Keep it running. Its pipeline already
reuses exactly 11 shell IP DCPs, omits irrelevant functional netlist exports,
does top synthesis/link with zero functional blackboxes, opt_design, real
postopt capacity gate, place/route, timing/DRC, bitstream. NOT FIT stops before
placement. Its states/logs: D/Opt4-fit-cad-state.json and
D/build-logs/Opt4-fit-cad-8da24a26. Do not infer FIT from module reports.

Address full OOC baseline: frozen 1,702,895 LUT / 58,190 CARRY8;
8da address 1,500,571 LUT / 57,446 CARRY8;
round3 aca893e0aa3f7e23e16067ab40713afea41558e8 actually mapped:
1,153,226 LUT / 55,392 CARRY8 / 390,181 FF / 216 BRAM / 0 DSP.
Round3 state D/Opt4-fit-address-round3-state.json uses full_address_map.
Heap candidate c41d42f61aa79d8249125c9e911438b797d007ce has a live complete
module map; adopt it rather than duplicate. Locate its precise state/service.

11edd71981aa30ff3a26aab1f2f7327ac0266ee1 is in
W/Opt4-fit-address-sort-20261110, source ID
f8a4239fe5a4818e15d98791f76d9d877172f342cdc0bc036ac6811e68de3cec.
80 inputs padded to 128, bitonic key/payload sort, bounded segmented prefix,
last-key scatter replaces repeated per-bucket reductions; register/state/
overflow/event logic outside that block unchanged. It passed generated
comparator and zero-one SAT, bounded 3/4-input scatter SAT, negative mutation,
2,336 scan-width bounds, actual 8192 vectors x 1024 outputs and frozen complete
module 6144 cycles x 52 outputs. This is not full-DUT formal equivalence.
Its 80x256 combinational core mapped 388,563 LUT / 1,160 CARRY8; cannot subtract
that from full-module totals. FULL MODULE SYNTHESIS STILL RUNNING in
ec-parsec-opt4-fit-address-sort.service, D/Opt4-fit-address-sort-state.json.
Do not change its worktree/scripts/inputs. Its measured full_module_map is
needed. W/scripts/continue_opt4_fit_sort_system.py already waits for exact
validation plus >=25% module LUT reduction, prepares separate integration/
GoldenGate then waits for 8da actual NOT_FIT_POSTOPT before next full CAD.
It never supersedes a fitting current version. The 25% threshold was a prior
heuristic, not a user mandate; if rejected, judge all measured candidates,
prepare an isolated improved successor rather than blindly stall/rebuild.

Resource attribution: D/build-logs/Opt4-fit-address-attribution-20261110.
First-fit address raw LUT cells: bucketStrictWriteRead 939,525,
io 218,784, bucketStoreFirst 161,641, bucketLoadFirst 158,077. Physical total
1,500,571; raw LUT cells != physical CLBs. Repeated dynamic reads/updates over
3072x64-bit state and qualifiedBucketError (96 sequence/valid dynamic reads)
remain potential structural hotspots. Try sharing decodes/one-hot accesses
and equivalent mux structures; no narrower state or serialized cycle changes.
Do not repeat split/prefix/DSP counter ideas already measured worse without
new structural evidence. Read prior candidate reports first.
Frozen hierarchy ranking exists at
D/build-logs/Opt4-fit-sort-system-continuation-11edd719/frozen-resource-ranking.json.
Rows are inclusive, overlap, and do not predict optimized whole-system FIT.
8da already changes barriers/scanners; use new real whole report when ready.

## Required forward actions, in priority order

1. Adopt live jobs and finish collecting 11edd full-module resources. Do not
wait idly: independently develop a next structural candidate on another git
worktree, narrow proof, actual-size comparison and module map. Look for
million-LUT/large CARRY8 reductions. Consult ec-debug-analysis skill.
2. Current whole system FIT -> implement immediately; NOT FIT -> rank actual
postopt hierarchy and advance best VERIFIED candidate. No unnecessary full
resynthesis of a bound valid DCP. Keep at most one whole CAD and at most four
new CPU jobs. Existing whole/module jobs are additional loads: honor actual
MemAvailable >=96 GiB whole / >=48 GiB module and disk >=100/40 GiB, max32
new CPU threads overall per job. No OOM/oversubscription or threshold lowering.
3. Complete future-candidate runtime binding before bitstream. Existing 8da
runtime only accepts 8da. New fixed-template generator
W/scripts/prepare_opt4_candidate_runtime.py and broker requests for 11edd are
installed. Source/ABI checks fail closed. Inspect request results. All 7 ABI/
target-description files must really match to reuse a host driver; otherwise
actually rebuild the driver and establish a distinct tested binding. Do not
forge byte_equal or alter receipts to make an incompatible build pass.
4. Audit the REAL rollback validation path before formal experiments. Existing
normal strict comparison/drain success IS NOT evidence of fault-triggered
architectural rollback/restart. Find an existing supported injection and
completion observation interface in RTL/firmware, prepare a separate honest
diagnostic software profile bound to the actual bitstream, validate recovery
and output. No treating a fault flag/cancellation as rollback. If no supported
interface exists, document concrete source evidence and safest minimally
intrusive verified way, without silently modifying live/frozen hardware.
5. Certified FIT/timing/DRC bitstream -> 21 safe boundary -> smoke/full checker/
rollback/drain/output gates -> 13 ordinary PARSEC r1 coverage -> r2/r3. Use
same Native program/input/ROI profiles, fluidanimate-stable-formal. Any app
failure skips just that app, keeps raw evidence and next runnable app. Atomic
results with correct source/software hashes; no partial sample in statistics.

## Detached jobs and broker protocol

Do not run long synthesis/proof/compiles as a background child of this worker.
Write a versioned Python/bash controller under W, bound to immutable source
inputs and resume checkpoints. Create U/requests/<unique>.json atomically:

{"action":"cpu_job","spec":{"name":"unique-lowercase-version",
 "kind":"proof|module|rtl|cad|analysis","cwd":"absolute path under W",
 "argv":["/usr/bin/python3","/absolute/versioned/controller.py"],
 "inputs":{"/absolute/versioned/controller.py":"sha256", "other source":"sha256"},
 "outputs":["absolute final receipt"],"checkpoints":["absolute state"]}}

Use actual one kind value. No inline -c shell. Inputs must include entry script;
bind all actual design/config inputs too. Broker executes as guozh in a separate
enabled systemd service. Logs/states U/jobs/<name>; request result in
U/request-results/<unique>.json. An immutable name/spec conflict requires a new
version. DEFERRED is not running; verify service PID/state before claiming start.
Successful exact completed jobs are reused. Failed jobs require analysis and
new validated recovery controller, never unconditional blind retry. A live
controller/child must be adopted, including across supervisor reload.

Runtime descriptor is W/runtime-candidates/<commit-prefix>.json with exact
commit/source_id/profile/worktree/cad_state/rtl_state/state_prefix and board
BDF/serial. Submit {"action":"prepare_runtime","descriptor":"path"} early,
and {"action":"start_runtime","descriptor":"path"}; the latter stays
DEFERRED until real timing/DRC/bitstream. No manual hardware commands.

Normal task status queries no more than once per 300 seconds; rely on service
events, receipt files and merged new log tails. Do not rehash huge artifacts
or reread whole logs every poll. Snapshot U/snapshot.json and append-only
U/ledger.jsonl are maintained automatically. Silence is diagnostic evidence
only, never permission to kill effective CAD. Distinguish CPU ticks from
actual synthesis phase/netlist/checkpoint progress. Fix recoverable errors in
isolated scripts, use verified checkpoints; preserve first-failure evidence.

The service launcher and broker must remain independent of SSH. Current
provider transport initially uses a saved SSH proxy; direct DNS is poisoned
and correct IP TLS currently reset. This is a remaining external-transport
dependency: safely seek an independently working authenticated connection if
possible, do not expose API keys or disable TLS checks. CAD continues if the
provider is offline; supervisor retains and retries model failures.

Finish each round with the specified JSON. Include actual changed files,
proof/map evidence, concrete launched jobs and next useful action. A single
NOT FIT, failed candidate, queue receipt or model error is not fundamental.
Use FUNDAMENTAL_BLOCKER only with concrete source/resource/proof evidence
that no authorized safe action can progress; it will be reviewed next round.
Do not claim any bitstream, deployment or valid FPGA sample without evidence.


## Parent integration update 2026-11-11 00:14 UTC
The parent has adopted your bucket-tag-system-r1 9ae9a7fc RTL preparation.
Do not duplicate it. New CAD continuation request bucket-tag-cad-r1-9ae9a7fc
is submitted; its script is W/candidates/bucket-tag-cad-r1-20261111/build.py.
It waits for your bound RTL then synthesizes exactly 9ae9a7fc, reuses 11 shell
DCPs only, and gates NOT FIT before place. It does not stack epoch or updates.
CPU broker now supports 6 campaign jobs, one new CAD; explicit
evidence_inputs under D/build-logs are independently hash-validated. Inputs
under W remain separate. A named overlap_completed_dut=8da24a26 full hash
allows new DUT synthesis while predecessor has completed DUT/top and is
only in implementation, with >=192GiB memory and >=150GiB free disk.
Dedicated user ccache and user ledger append have passed actual probes.
Parent is doing new-DUT EDIF/name attribution for MSHR/BOOM/L2; do not
duplicate attribution. Continue address-update-share-r2 proof/map and
structural candidates; never promote r1 with unresolved reset invariant.
Keep real rollback/restart validation gap visible; fault flag is insufficient.

Parent new structural work: W/Opt4-fit-svb-tree-r1-20261111 commit f2d2ca3ea0b12c918f2ccd2d1131be2709960470 (parent exact 9ae9a7fc) changes only SVB newest-safe selector to balanced tuple max; all state/update/ports unchanged. Job svb-tree-r1-f2d2ca3e submitted (proof,32-slot SAT,mutation,8192vectors,selection and fullSVB mapping). Do not duplicate/edit live inputs. Complete source/functional equivalence proof and real area assessment before ANY integrated build. Parent DUT attribution done: D/build-logs/Opt4-fit-dut-attribution-8da24a26-20261111/result.json. MSHR0 contains cross-module DCache names; do not assume all its physical area is MSHR-local. Fresh raw primitive disjoint groups: address1,462,518; BoomMSHR203,735; SVB183,120. Raw LUT != packed physical LUT. SVB state and activeIdx contain expensive pairwise tuple-order networks; new candidate addresses this. Continue MSHR/Dcache/L2 cone sharing and async-storage feasibility without changing latency.

Resource update: hard maximum 8 broker jobs, extra jobs beyond 6 require >=192GiB MemAvailable. Actual controllers remain 8-thread limited. The host has 256 logical CPUs and Native is paused. Only one new whole CAD, and only its DUT synthesis may overlap the completed predecessor opt. No concurrent implementation.

SVB recovery: r1 compile import failed; r2 source/probe compile and emits passed, standalone fullSVB lacked TileVisibilityNodeKey; r3 now uses a standalone LazyModule TileLink visibility harness and is submitted. Same f2d2ca3e hardware unchanged. Preserve all failure evidence. Do not edit r3 live inputs; complete or version recovery.

SVB r3 metadata harness exposed 128-bit cache row versus default 64-bit bus. r4 harness now negotiates tile.dcache.rowBits/8, matching target cache; f2d2ca3e source unchanged. r4 submitted. Earlier emitter failures archived; do not treat as RTL equivalence failure.

SVB r4 standalone harness paddr40 conflicted with Sv39; actual current GoldenGate BoomMSHR A.address is [34:0], cache row128. r5 harness binds paddr35/row128, matching actual target; fullSVB coreMaxAddrBits remains40. Same hardware f2d2ca3e, no DUT/config change. Please adopt r5 if live; proof32 then module maps.

Parent new exact 9ae-parent candidate 7e68d3df224fd37fd3f462b9deff376566ed9a79 in W/Opt4-fit-retire-read-r1-20261111: shared 256-slot retirement decoder + one-hot reads over 5x4x64bit banks; writes/state/overflow unchanged. This is different from old index-share (which only changed histogram input decode and mapped worse). Submitted retire-read-r1-7e68d3df; SAT256x64, mutation, actual8192, full frozen6144cycle comparison then complete address map. No stacking with SVB or update-share. Adopt if live, do not duplicate.

Parent SVB compositional proof completed: D/build-logs/Opt4-fit-svb-tree-compositional-proof-r1-20261111/result.json. SAT proves arbitrary69bit merge dominance/validity/index transport, actual generated CandidateSelection.v topology parsed:32 exact leaves,31 disjoint merges, exact key/idx/valid wiring and rootinvalidzero. Unique slot in low5bits proves exact pairwise noNewer argmax compositionally. Direct32 SAT r5 is still running and not called pass. Independent r6 waits for r5controller/child exit; if r5passes reuses; if sat32 times out, uses exact-RTL-bound compositional certificate then8192vectors and completeSVB mapping. Never kills r5 or duplicates its map. Different proof scope explicit. Adopt r6 when live.

## Real complete-top post-opt verdict 2026-11-11 00:45 UTC
8da24a26 complete top NOT FIT:3215683 LUT/1303680,92789CARRY8,195DSP,1796777FF,1028.5BRAM,0URAM. Excess1912003LUT. Reports D/build-logs/Opt4-fit-cad-8da24a26/top-postopt-{utilization,hierarchical}.rpt; saved optimized DCP. No more waiting for speculative top elimination: opt removed almost no DUT LUT. Existing capacity gate is finishing report_drc and then exits NOT_FIT before placement. Preserve evidence, do not resume place. New9ae fullDUT synth is already genuinely RUNNING_DUT_SYNTH; adopt it, do not duplicate. Largest disjoint postopt target branches: address1265491, BOOMcore244938, MSHRFile222552, L2168544, SVB117870. DCache parent2124812 includesaddress/MSHR/SVB; never sum ancestors. Need major structural gain, not promises from OOC subtraction.


Coordination 2026-11-11T00:51Z: interactive session owns svb-tree-r7 and svb-invalidation-validation-r2 repair/launch. Do not duplicate these jobs. Consult recovery-owner-20261111.json and resulting states. Continue other independent structural candidates, preserve live 9ae CAD.

Interactive session queued bucket-tag-software-prep-r1-9ae9a7fc to create the actual 13-app suite before bitstream. Do not duplicate. Uses canonical generated bundle, actual ABI compatibility and exact three-round Native refs; no FPGA IO.

Followup evidence 2026-11-11T01:01:08.718386+00:00: 8da complete-top post-opt NOT_FIT, gate naturally exited (capacity.complete); do not restart. Actual 3215683LUT,92789CARRY8,195DSP,excess1912003. Even zero addressStats leaves646512LUT excess. Keep broad non-address work. svb-tree-r7 completed: selector43898->3230LUT/5952->124CARRY8, completecandidateSVB130912LUT; same-harness baseline queued as svb-reference-map-r1-9ae9a7fc, do not compare candidateOOC vs oldpostopt. 13-app actual software-suite nowprepared at runtime/Opt4-fit-9ae9a7fc/software-suite.json, do not duplicate preparation. r2realSVB testqueued, no architectural rollback claim. Fullreport /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/opt4-acceleration-20261111T010108Z/REPORT.md


This is round 15. Latest durable snapshot:
{
  "available_memory_gib": 355.06,
  "board_allowlist": [
    "0000:21:00.0"
  ],
  "free_disk_gib": 378.96,
  "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
  "loadavg": "36.56 36.48 35.58 48/25374 1953699",
  "schema": "ec-opt4-unattended-snapshot/1",
  "states": {
    "Opt4-fit-address-async-current-r1-state.json": {
      "controller": {
        "cpu_ticks": 170,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 1893386,
        "process_state": "S",
        "rss_bytes": 16801792,
        "start_ticks": "16878859"
      },
      "hardware_commit": "c61d0b2a431451ca70093dcf6eeaed5945fc2ec1",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": true,
      "log_tail": "timized\nCommand: synth_design -top PackageAddressStats -part xcu280-fsvh2892-2L-e -mode out_of_context -directive RuntimeOptimized\nStarting synth_design\nAttempting to get a license for feature 'Synthesis' and/or device 'xcu280'\nINFO: [Common 17-349] Got license for feature 'Synthesis' and/or device 'xcu280'\nINFO: [Synth 8-7079] Multithreading enabled for synth_design using a maximum of 4 processes.\nINFO: [Synth 8-7078] Launching helper process for spawning children vivado processes\nINFO: [Synth 8-7075] Helper process launched with PID 1900665\n---------------------------------------------------------------------------------\nStarting Synthesize : Time (s): cpu = 00:00:05 ; elapsed = 00:00:05 . Memory (MB): peak = 2497.574 ; gain = 0.000 ; free physical = 85444 ; free virtual = 349750\n---------------------------------------------------------------------------------\nINFO: [Synth 8-6157] synthesizing module 'PackageAddressStats' [/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-async-current-r1-20261111/address/PackageAddressStats.v:319]\nINFO: [Synth 8-6157] synthesizing module 'AddressCurrentBucketMemory' [/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-async-current-r1-20261111/address/PackageAddressStats.v:1]\nINFO: [Synth 8-6155] done synthesizing module 'AddressCurrentBucketMemory' (1#1) [/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-async-current-r1-20261111/address/PackageAddressStats.v:1]\nINFO: [Synth 8-6155] done synthesizing module 'PackageAddressStats' (2#1) [/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-async-current-r1-20261111/address/PackageAddressStats.v:319]\n---------------------------------------------------------------------------------\nFinished Synthesize : Time (s): cpu = 00:20:37 ; elapsed = 00:21:38 . Memory (MB): peak = 9834.871 ; gain = 7337.297 ; free physical = 66150 ; free virtual = 327208\n---------------------------------------------------------------------------------\n---------------------------------------------------------------------------------\nFinished Constraint Validation : Time (s): cpu = 00:21:05 ; elapsed = 00:22:13 . Memory (MB): peak = 9834.871 ; gain = 7337.297 ; free physical = 72816 ; free virtual = 333914\n---------------------------------------------------------------------------------\n",
      "pid": 1893386,
      "source_id": "10e7dc799c504012de1f3f5adf1e34dd494ae1de6e40751cf37dac56991a860c",
      "stage_log": {
        "bytes": 3039,
        "mtime_ns": 1794358728742927730,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-async-current-r1-20261111/map-full-module/map-full-module-attempt-1.log"
      },
      "stage_process": {
        "cpu_ticks": 0,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 1900434,
        "process_state": "S",
        "rss_bytes": 3989504,
        "start_ticks": "16910061"
      },
      "start_ticks": "16878859",
      "status": "RUNNING_MAP-FULL-MODULE",
      "updated_utc": "2026-11-11T01:05:20.364169+00:00",
      "worker_processes": [
        {
          "comm": "vivado",
          "cpu_ticks": 0,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 0,
            "rchar": 66522,
            "read_bytes": 4096,
            "syscr": 169,
            "syscw": 16,
            "wchar": 345,
            "write_bytes": 0
          },
          "pid": 1900434,
          "process_state": "S",
          "rss_bytes": 3989504,
          "start_ticks": "16910061"
        },
        {
          "comm": "loader",
          "cpu_ticks": 0,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 0,
            "rchar": 1499877,
            "read_bytes": 0,
            "syscr": 450,
            "syscw": 16,
            "wchar": 232,
            "write_bytes": 0
          },
          "pid": 1900450,
          "process_state": "S",
          "rss_bytes": 3915776,
          "start_ticks": "16910063"
        },
        {
          "comm": "vivado",
          "cpu_ticks": 176932,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 271204352,
            "rchar": 5174680148,
            "read_bytes": 925696,
            "syscr": 478255,
            "syscw": 721815,
            "wchar": 4209049010,
            "write_bytes": 4209147904
          },
          "pid": 1900469,
          "process_state": "S",
          "rss_bytes": 4161941504,
          "start_ticks": "16910071"
        }
      ]
    },
    "Opt4-fit-address-async-sequence-r1-state.json": {
      "controller": {
        "cpu_ticks": 88,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 1945040,
        "process_state": "S",
        "rss_bytes": 16695296,
        "start_ticks": "17042597"
      },
      "hardware_commit": "94b749cf20b50487d82c7378071250fa9bd5eb3b",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": true,
      "log_tail": "tautological-compare -Wno-uninitialized -Wno-unused-parameter -Wno-unused-variable    -O0 -DVL_TIME_CONTEXT   -fcoroutines-ts -include-pch Vtb__pch.h.slow.gch -c -o Vtb___024root__DepSet_ha183790c__25__Slow.o Vtb___024root__DepSet_ha183790c__25__Slow.cpp\nccache clang++ -O0  -I.  -MMD -I/usr/local/share/verilator/include -I/usr/local/share/verilator/include/vltstd -DVM_COVERAGE=0 -DVM_SC=0 -DVM_TIMING=1 -DVM_TRACE=0 -DVM_TRACE_FST=0 -DVM_TRACE_VCD=0 -faligned-new -fbracket-depth=4096 -fcf-protection=none -Qunused-arguments -Wno-bool-operation -Wno-c++11-narrowing -Wno-constant-logical-operand -Wno-non-pod-varargs -Wno-parentheses-equality -Wno-shadow -Wno-sign-compare -Wno-tautological-bitwise-compare -Wno-tautological-compare -Wno-uninitialized -Wno-unused-parameter -Wno-unused-variable    -O0 -DVL_TIME_CONTEXT   -fcoroutines-ts -include-pch Vtb__pch.h.slow.gch -c -o Vtb___024root__DepSet_ha183790c__26__Slow.o Vtb___024root__DepSet_ha183790c__26__Slow.cpp\nccache clang++ -O0  -I.  -MMD -I/usr/local/share/verilator/include -I/usr/local/share/verilator/include/vltstd -DVM_COVERAGE=0 -DVM_SC=0 -DVM_TIMING=1 -DVM_TRACE=0 -DVM_TRACE_FST=0 -DVM_TRACE_VCD=0 -faligned-new -fbracket-depth=4096 -fcf-protection=none -Qunused-arguments -Wno-bool-operation -Wno-c++11-narrowing -Wno-constant-logical-operand -Wno-non-pod-varargs -Wno-parentheses-equality -Wno-shadow -Wno-sign-compare -Wno-tautological-bitwise-compare -Wno-tautological-compare -Wno-uninitialized -Wno-unused-parameter -Wno-unused-variable    -O0 -DVL_TIME_CONTEXT   -fcoroutines-ts -include-pch Vtb__pch.h.slow.gch -c -o Vtb___024root__DepSet_ha183790c__27__Slow.o Vtb___024root__DepSet_ha183790c__27__Slow.cpp\nccache clang++ -O0  -I.  -MMD -I/usr/local/share/verilator/include -I/usr/local/share/verilator/include/vltstd -DVM_COVERAGE=0 -DVM_SC=0 -DVM_TIMING=1 -DVM_TRACE=0 -DVM_TRACE_FST=0 -DVM_TRACE_VCD=0 -faligned-new -fbracket-depth=4096 -fcf-protection=none -Qunused-arguments -Wno-bool-operation -Wno-c++11-narrowing -Wno-constant-logical-operand -Wno-non-pod-varargs -Wno-parentheses-equality -Wno-shadow -Wno-sign-compare -Wno-tautological-bitwise-compare -Wno-tautological-compare -Wno-uninitialized -Wno-unused-parameter -Wno-unused-variable    -O0 -DVL_TIME_CONTEXT   -fcoroutines-ts -include-pch Vtb__pch.h.slow.gch -c -o Vtb___024root__DepSet_ha183790c__28__Slow.o Vtb___024root__DepSet_ha183790c__28__Slow.cpp\n",
      "pid": 1945040,
      "source_id": "a22e245c0631d0aabb52cbddf1d254a735541dc51279ca9638e841695851da94",
      "stage_log": {
        "bytes": 31998,
        "mtime_ns": 1794359148581390579,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-async-sequence-r1-20261111/compare/compare-compile-attempt-1.log"
      },
      "stage_process": {
        "cpu_ticks": 5,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 1952048,
        "process_state": "S",
        "rss_bytes": 13570048,
        "start_ticks": "17079241"
      },
      "start_ticks": "17042597",
      "status": "RUNNING_COMPARE-COMPILE",
      "updated_utc": "2026-11-11T01:05:31.983482+00:00",
      "worker_processes": [
        {
          "comm": "perl",
          "cpu_ticks": 5,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 0,
            "rchar": 782338,
            "read_bytes": 0,
            "syscr": 210,
            "syscw": 0,
            "wchar": 0,
            "write_bytes": 0
          },
          "pid": 1952048,
          "process_state": "S",
          "rss_bytes": 13570048,
          "start_ticks": "17079241"
        },
        {
          "comm": "verilator_bin",
          "cpu_ticks": 7392,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 0,
            "rchar": 111116218,
            "read_bytes": 0,
            "syscr": 1728,
            "syscw": 4443,
            "wchar": 254080481,
            "write_bytes": 255107072
          },
          "pid": 1952050,
          "process_state": "S",
          "rss_bytes": 3641339904,
          "start_ticks": "17079247"
        },
        {
          "comm": "make",
          "cpu_ticks": 2,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 0,
            "rchar": 17198728,
            "read_bytes": 0,
            "syscr": 6062,
            "syscw": 947,
            "wchar": 85684464,
            "write_bytes": 85839872
          },
          "pid": 1953547,
          "process_state": "S",
          "rss_bytes": 4042752,
          "start_ticks": "17086520"
        },
        {
          "comm": "clang++",
          "cpu_ticks": 53,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 0,
            "rchar": 445027,
            "read_bytes": 0,
            "syscr": 175,
            "syscw": 0,
            "wchar": 0,
            "write_bytes": 0
          },
          "pid": 1953670,
          "process_state": "R",
          "rss_bytes": 183869440,
          "start_ticks": "17086847"
        },
        {
          "comm": "clang++",
          "cpu_ticks": 11,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 0,
            "rchar": 431411,
            "read_bytes": 0,
            "syscr": 172,
            "syscw": 0,
            "wchar": 0,
            "write_bytes": 0
          },
          "pid": 1953692,
          "process_state": "R",
          "rss_bytes": 119242752,
          "start_ticks": "17086890"
        },
        {
          "comm": "clang++",
          "cpu_ticks": 7,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 0,
            "rchar": 431411,
            "read_bytes": 0,
            "syscr": 172,
            "syscw": 0,
            "wchar": 0,
            "write_bytes": 0
          },
          "pid": 1953693,
          "process_state": "R",
          "rss_bytes": 105549824,
          "start_ticks": "17086893"
        },
        {
          "comm": "clang++",
          "cpu_ticks": 6,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 0,
            "rchar": 431411,
            "read_bytes": 0,
            "syscr": 172,
            "syscw": 0,
            "wchar": 0,
            "write_bytes": 0
          },
          "pid": 1953694,
          "process_state": "R",
          "rss_bytes": 98803712,
          "start_ticks": "17086895"
        },
        {
          "comm": "clang++",
          "cpu_ticks": 2,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 0,
            "rchar": 431411,
            "read_bytes": 0,
            "syscr": 172,
            "syscw": 0,
            "wchar": 0,
            "write_bytes": 0
          },
          "pid": 1953696,
          "process_state": "R",
          "rss_bytes": 56004608,
          "start_ticks": "17086898"
        },
        {
          "comm": "clang++",
          "cpu_ticks": 4,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 0,
            "rchar": 431411,
            "read_bytes": 0,
            "syscr": 172,
            "syscw": 0,
            "wchar": 0,
            "write_bytes": 0
          },
          "pid": 1953697,
          "process_state": "R",
          "rss_bytes": 92372992,
          "start_ticks": "17086899"
        },
        {
          "comm": "clang++",
          "cpu_ticks": 3,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 0,
            "rchar": 431411,
            "read_bytes": 0,
            "syscr": 172,
            "syscw": 0,
            "wchar": 0,
            "write_bytes": 0
          },
          "pid": 1953698,
          "process_state": "R",
          "rss_bytes": 90632192,
          "start_ticks": "17086899"
        },
        {
          "comm": "clang++",
          "cpu_ticks": 0,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 0,
            "rchar": 21609,
            "read_bytes": 0,
            "syscr": 39,
            "syscw": 0,
            "wchar": 0,
            "write_bytes": 0
          },
          "pid": 1953699,
          "process_state": "D",
          "rss_bytes": 29401088,
          "start_ticks": "17086901"
        }
      ]
    },
    "Opt4-fit-address-bucket-tag-r2-state.json": {
      "controller": {},
      "error": "AssertionError(('sat-slot-tag', 1, '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-bucket-tag-r2-20261111/proof/sat-slot-tag-attempt-1.log'))",
      "hardware_commit": "2bfa6047b10de351db1934e9cd58da1d3e921096",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "E pass (reducing word size of cells).\n\n2.10. Executing OPT_CLEAN pass (remove unused cells and wires).\nFinding unused cells or wires in module \\BucketTagProof..\n\n2.11. Executing MEMORY_COLLECT pass (generating $mem cells).\n\n2.12. Executing OPT pass (performing simple optimizations).\n\n2.12.1. Executing OPT_EXPR pass (perform const folding).\nOptimizing module BucketTagProof.\n\n2.12.2. Executing OPT_MERGE pass (detect identical cells).\nFinding identical cells in module `\\BucketTagProof'.\nRemoved a total of 0 cells.\n\n2.12.3. Executing OPT_CLEAN pass (remove unused cells and wires).\nFinding unused cells or wires in module \\BucketTagProof..\n\n2.12.4. Finished fast OPT passes.\n\n2.13. Printing statistics.\n\n=== BucketTagProof ===\n\n        +----------Local Count, excluding submodules.\n        | \n       11 wires\n       73 wire bits\n        7 public wires\n       69 public wire bits\n        4 ports\n       66 port bits\n        8 cells\n        4   $eq\n        2   $logic_not\n        2   $logic_or\n\n2.14. Executing CHECK pass (checking for obvious problems).\nChecking module BucketTagProof...\nFound and reported 0 problems.\n\n3. Executing SAT pass (solving SAT problems in the circuit).\n\nSetting up SAT problem:\nFinal constraint equation: { } = { }\nImported 8 cells to SAT database.\nImport proof-constraint: \\io_equivalent = 1'1\nFinal proof equation: \\io_equivalent = 1'1\n\nSolving problem with 205 variables and 460 clauses..\nSAT proof finished - model found: FAIL!\n\n   ______                   ___       ___       _ _            _ _ \n  (_____ \\                 / __)     / __)     (_) |          | | |\n   _____) )___ ___   ___ _| |__    _| |__ _____ _| | _____  __| | |\n  |  ____/ ___) _ \\ / _ (_   __)  (_   __|____ | | || ___ |/ _  |_|\n  | |   | |  | |_| | |_| || |       | |  / ___ | | || ____( (_| |_ \n  |_|   |_|   \\___/ \\___/ |_|       |_|  \\_____|_|\\_)_____)\\____|_|\n\n\n  Signal Name                 Dec       Hex                                 Bin\n  ------------------- ----------- --------- -----------------------------------\n  \\io_equivalent                0         0                                   0\n  \\seq                        128        80    00000000000000000000000010000000\n  \\stored                       0         0    00000000000000000000000000000000\n  \\valid                        0         0                                   0\n\nERROR: Called with -verify and proof did fail!\n",
      "pid": 1529364,
      "source_id": "3791dd0e8f7d9c380500cd37f11ece4c92e275bc399894780228fa61449df561",
      "stage_log": {
        "bytes": 6228,
        "mtime_ns": 1794346900643159185,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-bucket-tag-r2-20261111/proof/sat-slot-tag-attempt-1.log"
      },
      "stage_process": {},
      "start_ticks": "15861945",
      "status": "FAILED_WITH_EVIDENCE",
      "updated_utc": "2026-11-10T21:41:40.652874+00:00",
      "worker_processes": []
    },
    "Opt4-fit-address-bucket-tag-r3-state.json": {
      "controller": {},
      "full_module_map": {
        "checkpoint": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-bucket-tag-r3-20261111/map-full-module/module.dcp",
        "checkpoint_sha256": "61df118f25d7be250a6bf197d8e268bea6e9f5cb04442debb73720905fe8cc6a",
        "hierarchy": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-bucket-tag-r3-20261111/map-full-module/hierarchical.rpt",
        "hierarchy_sha256": "906876cae6019c476604a516b395c1420695c546efc4d66f073414697bcb5eef",
        "log": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-bucket-tag-r3-20261111/map-full-module/map-full-module-attempt-1.log",
        "report": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-bucket-tag-r3-20261111/map-full-module/utilization.rpt",
        "report_sha256": "c748787ebf31c7cabdf789be2c7287ad11cbd9c82fa9f7d36af366513bd0b5b0",
        "resources": {
          "Block RAM Tile": 216.0,
          "CARRY8": 55418.0,
          "CLB LUTs": 990905.0,
          "CLB Registers": 386202.0,
          "DSPs": 0.0
        },
        "scope": "Complete PackageAddressStats OOC only; not whole-DUT capacity or FIT",
        "tcl_sha256": "9221e1a04ff3c11fd8531cb86e339c9c46c5e2ace1ba3ba5ff7039c8ad5e2d0f"
      },
      "hardware_commit": "9ae9a7fcf231a75259e23973b12a93896a443cbb",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "seconds\nWARNING: [Netlist 29-101] Netlist 'PackageAddressStats' is not ideal for floorplanning, since the cellview 'PackageAddressStats' contains a large number of primitives.  Please consider enabling hierarchy in synthesis if you want to do floorplanning.\nINFO: [Project 1-570] Preparing netlist for logic optimization\nINFO: [Opt 31-138] Pushed 0 inverter(s) to 0 load pin(s).\nNetlist sorting complete. Time (s): cpu = 00:00:00.37 ; elapsed = 00:00:00.36 . Memory (MB): peak = 11581.230 ; gain = 0.000 ; free physical = 92312 ; free virtual = 357138\nINFO: [Project 1-111] Unisim Transformation Summary:\nNo Unisim elements were transformed.\n\nSynth Design complete, checksum: 22ce2fc2\nINFO: [Common 17-83] Releasing license: Synthesis\n481 Infos, 1 Warnings, 0 Critical Warnings and 0 Errors encountered.\nsynth_design completed successfully\nsynth_design: Time (s): cpu = 01:44:59 ; elapsed = 01:49:06 . Memory (MB): peak = 11581.230 ; gain = 9081.793 ; free physical = 94262 ; free virtual = 359080\nINFO: [Common 17-600] The following parameters have non-default value.\ngeneral.maxThreads\n# report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-bucket-tag-r3-20261111/map-full-module/utilization.rpt}\nreport_utilization: Time (s): cpu = 00:00:09 ; elapsed = 00:00:09 . Memory (MB): peak = 11581.230 ; gain = 0.000 ; free physical = 92896 ; free virtual = 357801\n# report_utilization -hierarchical -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-bucket-tag-r3-20261111/map-full-module/hierarchical.rpt}\nreport_utilization: Time (s): cpu = 00:00:13 ; elapsed = 00:00:14 . Memory (MB): peak = 11581.230 ; gain = 0.000 ; free physical = 89782 ; free virtual = 354827\n# write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-bucket-tag-r3-20261111/map-full-module/module.dcp}\nINFO: [Timing 38-35] Done setting XDC timing constraints.\nINFO: [Common 17-1381] The checkpoint '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-bucket-tag-r3-20261111/map-full-module/module.dcp' has been generated.\nwrite_checkpoint: Time (s): cpu = 00:04:47 ; elapsed = 00:03:27 . Memory (MB): peak = 11653.266 ; gain = 72.035 ; free physical = 98766 ; free virtual = 364474\n# exit 0\nINFO: [Common 17-206] Exiting Vivado at Wed Nov 11 07:49:14 2026...\n",
      "pid": 1549363,
      "source_id": "3791dd0e8f7d9c380500cd37f11ece4c92e275bc399894780228fa61449df561",
      "stage_log": {
        "bytes": 231730,
        "mtime_ns": 1794354554450364190,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-bucket-tag-r3-20261111/map-full-module/map-full-module-attempt-1.log"
      },
      "stage_process": {},
      "start_ticks": "15911708",
      "status": "VERIFIED_AND_MAPPED_CANDIDATE_NOT_PROMOTED",
      "updated_utc": "2026-11-10T23:49:21.195562+00:00",
      "worker_processes": []
    },
    "Opt4-fit-address-decode-r1-state.json": {
      "controller": {},
      "full_module_map": {
        "checkpoint": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-decode-r1-aeabe5ab-20261111/map-full-module/module.dcp",
        "report": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-decode-r1-aeabe5ab-20261111/map-full-module/utilization.rpt",
        "report_sha256": "152fbf1896580b114a418e3df516c1ccf36c089f114d0eecaa5b786da7c47bbf",
        "resources": {
          "Block RAM Tile": 0.0,
          "CARRY8": 0.0,
          "CLB LUTs": 0.0,
          "CLB Registers": 0.0,
          "DSPs": 0.0
        },
        "rtl_sha256": "2ef55433f3c429218f249d894acadc8d09a94f6da916b08354afc15530eeab77",
        "scope": "OOC only; not whole-DUT FIT",
        "tcl_sha256": "f28a3e0a8ab0b4fd7113a8c870e82d994d605b9f71d6d713aec4115d19b714a0"
      },
      "hardware_commit": "aeabe5abe9f0ece2e024b5c8aa91a2c24fdfa4cb",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "list 29-101] Netlist 'PackageAddressStats' is not ideal for floorplanning, since the cellview 'PackageAddressStats' contains a large number of primitives.  Please consider enabling hierarchy in synthesis if you want to do floorplanning.\nINFO: [Project 1-570] Preparing netlist for logic optimization\nINFO: [Opt 31-138] Pushed 0 inverter(s) to 0 load pin(s).\nNetlist sorting complete. Time (s): cpu = 00:00:00.43 ; elapsed = 00:00:00.43 . Memory (MB): peak = 16232.363 ; gain = 0.000 ; free physical = 48325 ; free virtual = 333165\nINFO: [Project 1-111] Unisim Transformation Summary:\nNo Unisim elements were transformed.\n\nSynth Design complete, checksum: e99f9739\nINFO: [Common 17-83] Releasing license: Synthesis\n481 Infos, 1 Warnings, 0 Critical Warnings and 0 Errors encountered.\nsynth_design completed successfully\nsynth_design: Time (s): cpu = 03:31:51 ; elapsed = 03:37:57 . Memory (MB): peak = 16232.363 ; gain = 13722.926 ; free physical = 50072 ; free virtual = 335206\nINFO: [Common 17-600] The following parameters have non-default value.\ngeneral.maxThreads\n# report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-decode-r1-aeabe5ab-20261111/map-full-module/utilization.rpt}\nreport_utilization: Time (s): cpu = 00:00:09 ; elapsed = 00:00:10 . Memory (MB): peak = 16232.363 ; gain = 0.000 ; free physical = 49885 ; free virtual = 335289\n# report_utilization -hierarchical -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-decode-r1-aeabe5ab-20261111/map-full-module/hierarchical.rpt}\nreport_utilization: Time (s): cpu = 00:00:13 ; elapsed = 00:00:14 . Memory (MB): peak = 16232.363 ; gain = 0.000 ; free physical = 46386 ; free virtual = 331802\n# write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-decode-r1-aeabe5ab-20261111/map-full-module/module.dcp}\nINFO: [Timing 38-35] Done setting XDC timing constraints.\nINFO: [Common 17-1381] The checkpoint '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-decode-r1-aeabe5ab-20261111/map-full-module/module.dcp' has been generated.\nwrite_checkpoint: Time (s): cpu = 00:05:44 ; elapsed = 00:04:02 . Memory (MB): peak = 16304.398 ; gain = 72.035 ; free physical = 41956 ; free virtual = 328095\n# exit 0\nINFO: [Common 17-206] Exiting Vivado at Wed Nov 11 04:16:25 2026...\n",
      "pid": 833677,
      "source_id": "c1d8e0c2da48e82aba099638e2a910d8c358341c44aba59229098cf83cc29404",
      "stage_log": {
        "bytes": 232158,
        "mtime_ns": 1794341785767857068,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-decode-r1-aeabe5ab-20261111/map-full-module/map-full-module-attempt-1.log"
      },
      "stage_process": {},
      "start_ticks": "13960271",
      "status": "VERIFIED_AND_MAPPED_MODULE_ONLY",
      "updated_utc": "2026-11-10T20:16:32.329450+00:00",
      "worker_processes": []
    },
    "Opt4-fit-address-decode-r2-state.json": {
      "controller": {},
      "full_module_map": {
        "checkpoint": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-decode-r2-20261111/map-full-module/module.dcp",
        "report": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-decode-r2-20261111/map-full-module/utilization.rpt",
        "report_sha256": "9376d91c7ca4d310cd3cbc4f1745ba017179b48043a0f4dd053e154fd89fe190",
        "resources": {
          "Block RAM Tile": 0.0,
          "CARRY8": 0.0,
          "CLB LUTs": 0.0,
          "CLB Registers": 0.0,
          "DSPs": 0.0
        },
        "rtl_sha256": "436fb8056edba112c589e9de0aaa1c7a76b3687243ae1c980c7817d933e87cbe",
        "scope": "OOC only; not whole-DUT FIT",
        "tcl_sha256": "5c9e55ba86187c461f1bc2988b42edcfa353a6df7df17e4e70cae1285241a1a0"
      },
      "hardware_commit": "579904b258213630cf00c13e65fde5ea9512bb03",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "pleted in 5 CPU seconds\nWARNING: [Netlist 29-101] Netlist 'PackageAddressStats' is not ideal for floorplanning, since the cellview 'PackageAddressStats' contains a large number of primitives.  Please consider enabling hierarchy in synthesis if you want to do floorplanning.\nINFO: [Project 1-570] Preparing netlist for logic optimization\nINFO: [Opt 31-138] Pushed 0 inverter(s) to 0 load pin(s).\nNetlist sorting complete. Time (s): cpu = 00:00:00.41 ; elapsed = 00:00:00.41 . Memory (MB): peak = 15890.641 ; gain = 0.000 ; free physical = 57676 ; free virtual = 340404\nINFO: [Project 1-111] Unisim Transformation Summary:\nNo Unisim elements were transformed.\n\nSynth Design complete, checksum: d05b78b\nINFO: [Common 17-83] Releasing license: Synthesis\n481 Infos, 1 Warnings, 0 Critical Warnings and 0 Errors encountered.\nsynth_design completed successfully\nsynth_design: Time (s): cpu = 01:48:27 ; elapsed = 01:53:04 . Memory (MB): peak = 15890.641 ; gain = 13391.207 ; free physical = 59016 ; free virtual = 341747\nINFO: [Common 17-600] The following parameters have non-default value.\ngeneral.maxThreads\n# report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-decode-r2-20261111/map-full-module/utilization.rpt}\nreport_utilization: Time (s): cpu = 00:00:09 ; elapsed = 00:00:10 . Memory (MB): peak = 15890.641 ; gain = 0.000 ; free physical = 58656 ; free virtual = 341390\n# report_utilization -hierarchical -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-decode-r2-20261111/map-full-module/hierarchical.rpt}\nreport_utilization: Time (s): cpu = 00:00:14 ; elapsed = 00:00:15 . Memory (MB): peak = 15890.641 ; gain = 0.000 ; free physical = 58295 ; free virtual = 341029\n# write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-decode-r2-20261111/map-full-module/module.dcp}\nINFO: [Timing 38-35] Done setting XDC timing constraints.\nINFO: [Common 17-1381] The checkpoint '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-decode-r2-20261111/map-full-module/module.dcp' has been generated.\nwrite_checkpoint: Time (s): cpu = 00:05:27 ; elapsed = 00:03:54 . Memory (MB): peak = 15962.676 ; gain = 72.035 ; free physical = 59271 ; free virtual = 342699\n# exit 0\nINFO: [Common 17-206] Exiting Vivado at Wed Nov 11 03:17:01 2026...\n",
      "pid": 1057994,
      "source_id": "9bbb8feb5244affd7d7288a1a3024a6c53b9cf5248cf4077aad3959e00cf088c",
      "stage_log": {
        "bytes": 232020,
        "mtime_ns": 1794338221053418581,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-decode-r2-20261111/map-full-module/map-full-module-attempt-1.log"
      },
      "stage_process": {},
      "start_ticks": "14234872",
      "status": "VERIFIED_AND_MAPPED_MODULE_ONLY",
      "updated_utc": "2026-11-10T19:17:08.299860+00:00",
      "worker_processes": []
    },
    "Opt4-fit-address-delta-r3-state.json": {
      "controller": {},
      "error": "AssertionError(('map-full-module', 7, '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-delta-r3-56711a00-20261111/map-full-module/map-full-module-attempt-1.log'))",
      "hardware_commit": "56711a0057bb2822f5bf00754a2b3e13cde11e8f",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "     \n\t                8 Bit    Registers := 1     \n\t                2 Bit    Registers := 257   \n\t                1 Bit    Registers := 579   \n+---RAMs : \n\t              89K Bit\t(1024 X 89 bit)          RAMs := 48    \n\t              64K Bit\t(1024 X 64 bit)          RAMs := 24    \n\t              34K Bit\t(1024 X 34 bit)          RAMs := 24    \n\t              32K Bit\t(1024 X 32 bit)          RAMs := 24    \n+---Muxes : \n\t   2 Input   89 Bit        Muxes := 320   \n\t   2 Input   64 Bit        Muxes := 7232  \n\t  65 Input   64 Bit        Muxes := 1     \n\t   2 Input   40 Bit        Muxes := 1024  \n\t   2 Input   34 Bit        Muxes := 24    \n\t   2 Input   33 Bit        Muxes := 512   \n\t   2 Input   32 Bit        Muxes := 1049  \n\t  18 Input   16 Bit        Muxes := 1     \n\t  17 Input   16 Bit        Muxes := 1     \n\t   2 Input   10 Bit        Muxes := 12336 \n\t   2 Input    9 Bit        Muxes := 4176  \n\t   2 Input    8 Bit        Muxes := 28954 \n\t   9 Input    8 Bit        Muxes := 2     \n\t  10 Input    8 Bit        Muxes := 1     \n\t   2 Input    7 Bit        Muxes := 23844 \n\t   2 Input    6 Bit        Muxes := 10042 \n\t   2 Input    5 Bit        Muxes := 9293  \n\t   2 Input    4 Bit        Muxes := 9385  \n\t   2 Input    3 Bit        Muxes := 3348  \n\t   2 Input    2 Bit        Muxes := 7838  \n\t   2 Input    1 Bit        Muxes := 10156 \n---------------------------------------------------------------------------------\nFinished RTL Component Statistics \n---------------------------------------------------------------------------------\n---------------------------------------------------------------------------------\nStart Part Resource Summary\n---------------------------------------------------------------------------------\nPart Resources:\nDSPs: 9024 (col length:94)\nBRAMs: 4032 (col length: RAMB18 288 RAMB36 144)\n---------------------------------------------------------------------------------\nFinished Part Resource Summary\n---------------------------------------------------------------------------------\nNo constraint files found.\n---------------------------------------------------------------------------------\nStart Cross Boundary and Area Optimization\n---------------------------------------------------------------------------------\ntcmalloc: large alloc 18446744073607741440 bytes == (nil) @  0x7f4f58438e7f 0x7f4f57c07fa2\n\nout of memory allocating 18446744073607735856 bytes\n",
      "pid": 1142797,
      "source_id": "e5f327505b504fa55c75b29500a915d2f32db6e28766f9444c62e3989a384ada",
      "stage_log": {
        "bytes": 40504,
        "mtime_ns": 1794336102227946867,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-delta-r3-56711a00-20261111/map-full-module/map-full-module-attempt-1.log"
      },
      "stage_process": {},
      "start_ticks": "14386952",
      "status": "FAILED_WITH_EVIDENCE",
      "updated_utc": "2026-11-10T18:41:46.756653+00:00",
      "worker_processes": []
    },
    "Opt4-fit-address-epoch-clear-r2-state.json": {
      "controller": {},
      "full_module_map": {
        "checkpoint": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-epoch-clear-r2-20261111/map-full-module/module.dcp",
        "report": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-epoch-clear-r2-20261111/map-full-module/utilization.rpt",
        "report_sha256": "695eb8dbf427ab2489b33974d55c4e7160ff4bda810b68b42c193f553acbe32d",
        "resources": {
          "Block RAM Tile": 216.0,
          "CARRY8": 32861.0,
          "CLB LUTs": 1262145.0,
          "CLB Registers": 388409.0,
          "DSPs": 0.0
        },
        "rtl_sha256": "2deacf1e61c306d1762ea819d19c1837bde08419249ad7386d0fe9ed8c1c218f",
        "scope": "Complete module OOC; not whole-DUT FIT",
        "tcl_sha256": "57ddcb5133d87bfa12eb97fdd03251e0fb9d25d925848044ac7189bdf26b6d20"
      },
      "hardware_commit": "64421513f29420498e128b78d82121ab11f52286",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "nds\nWARNING: [Netlist 29-101] Netlist 'PackageAddressStats' is not ideal for floorplanning, since the cellview 'PackageAddressStats' contains a large number of primitives.  Please consider enabling hierarchy in synthesis if you want to do floorplanning.\nINFO: [Project 1-570] Preparing netlist for logic optimization\nINFO: [Opt 31-138] Pushed 0 inverter(s) to 0 load pin(s).\nNetlist sorting complete. Time (s): cpu = 00:00:00.40 ; elapsed = 00:00:00.41 . Memory (MB): peak = 12070.012 ; gain = 0.000 ; free physical = 78612 ; free virtual = 346220\nINFO: [Project 1-111] Unisim Transformation Summary:\nNo Unisim elements were transformed.\n\nSynth Design complete, checksum: c5f67827\nINFO: [Common 17-83] Releasing license: Synthesis\n482 Infos, 1 Warnings, 0 Critical Warnings and 0 Errors encountered.\nsynth_design completed successfully\nsynth_design: Time (s): cpu = 01:59:02 ; elapsed = 02:03:18 . Memory (MB): peak = 12070.012 ; gain = 9577.574 ; free physical = 77985 ; free virtual = 345593\nINFO: [Common 17-600] The following parameters have non-default value.\ngeneral.maxThreads\n# report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-epoch-clear-r2-20261111/map-full-module/utilization.rpt}\nreport_utilization: Time (s): cpu = 00:00:10 ; elapsed = 00:00:11 . Memory (MB): peak = 12070.012 ; gain = 0.000 ; free physical = 76343 ; free virtual = 343036\n# report_utilization -hierarchical -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-epoch-clear-r2-20261111/map-full-module/hierarchical.rpt}\nreport_utilization: Time (s): cpu = 00:00:16 ; elapsed = 00:00:17 . Memory (MB): peak = 12070.012 ; gain = 0.000 ; free physical = 68677 ; free virtual = 336337\n# write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-epoch-clear-r2-20261111/map-full-module/module.dcp}\nINFO: [Timing 38-35] Done setting XDC timing constraints.\nINFO: [Common 17-1381] The checkpoint '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-epoch-clear-r2-20261111/map-full-module/module.dcp' has been generated.\nwrite_checkpoint: Time (s): cpu = 00:05:32 ; elapsed = 00:04:04 . Memory (MB): peak = 12142.047 ; gain = 72.035 ; free physical = 72460 ; free virtual = 339501\n# exit 0\nINFO: [Common 17-206] Exiting Vivado at Wed Nov 11 06:29:57 2026...\n",
      "pid": 1438186,
      "source_id": "ed5aed4e7968b932e844f3bc0c4be78f08e46c83837aea2903c887ba80b3527c",
      "stage_log": {
        "bytes": 231858,
        "mtime_ns": 1794349797002603822,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-epoch-clear-r2-20261111/map-full-module/map-full-module-attempt-1.log"
      },
      "stage_process": {},
      "start_ticks": "15351861",
      "status": "VERIFIED_AND_MAPPED_MODULE_ONLY",
      "updated_utc": "2026-11-10T22:30:03.729438+00:00",
      "worker_processes": []
    },
    "Opt4-fit-address-group4-r1-state.json": {
      "controller": {},
      "full_module_map": {
        "checkpoint": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-group4-r1-20261111/map-full-module/module.dcp",
        "report": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-group4-r1-20261111/map-full-module/utilization.rpt",
        "report_sha256": "3f5ae2e6a9a5b168493ff4e4a530cdfbd15f3c52b2cdafb290604b7bdeb3cb7a",
        "resources": {
          "Block RAM Tile": 216.0,
          "CARRY8": 55499.0,
          "CLB LUTs": 1030558.0,
          "CLB Registers": 389477.0,
          "DSPs": 0.0
        },
        "rtl_sha256": "bd846e3a6e0ba7bd967d2d3e3c332a3b815fe0ec0cc63cc65938e4c840e1c4b0",
        "scope": "Complete module OOC; not whole-DUT FIT",
        "tcl_sha256": "5804504d630d72a586c8ff5e8cf1cc8b25416724bf299b087f64c0207f09d7e9"
      },
      "hardware_commit": "981b890d870130f99ec24a0c5e37acb39362318a",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "pleted in 4 CPU seconds\nWARNING: [Netlist 29-101] Netlist 'PackageAddressStats' is not ideal for floorplanning, since the cellview 'PackageAddressStats' contains a large number of primitives.  Please consider enabling hierarchy in synthesis if you want to do floorplanning.\nINFO: [Project 1-570] Preparing netlist for logic optimization\nINFO: [Opt 31-138] Pushed 0 inverter(s) to 0 load pin(s).\nNetlist sorting complete. Time (s): cpu = 00:00:00.35 ; elapsed = 00:00:00.36 . Memory (MB): peak = 11448.562 ; gain = 0.000 ; free physical = 62743 ; free virtual = 347622\nINFO: [Project 1-111] Unisim Transformation Summary:\nNo Unisim elements were transformed.\n\nSynth Design complete, checksum: ec91b48e\nINFO: [Common 17-83] Releasing license: Synthesis\n481 Infos, 1 Warnings, 0 Critical Warnings and 0 Errors encountered.\nsynth_design completed successfully\nsynth_design: Time (s): cpu = 01:34:31 ; elapsed = 01:38:21 . Memory (MB): peak = 11448.562 ; gain = 8942.129 ; free physical = 70581 ; free virtual = 355459\nINFO: [Common 17-600] The following parameters have non-default value.\ngeneral.maxThreads\n# report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-group4-r1-20261111/map-full-module/utilization.rpt}\nreport_utilization: Time (s): cpu = 00:00:09 ; elapsed = 00:00:10 . Memory (MB): peak = 11448.562 ; gain = 0.000 ; free physical = 70162 ; free virtual = 355038\n# report_utilization -hierarchical -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-group4-r1-20261111/map-full-module/hierarchical.rpt}\nreport_utilization: Time (s): cpu = 00:00:13 ; elapsed = 00:00:14 . Memory (MB): peak = 11448.562 ; gain = 0.000 ; free physical = 69896 ; free virtual = 354774\n# write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-group4-r1-20261111/map-full-module/module.dcp}\nINFO: [Timing 38-35] Done setting XDC timing constraints.\nINFO: [Common 17-1381] The checkpoint '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-group4-r1-20261111/map-full-module/module.dcp' has been generated.\nwrite_checkpoint: Time (s): cpu = 00:05:01 ; elapsed = 00:03:33 . Memory (MB): peak = 11520.598 ; gain = 72.035 ; free physical = 65331 ; free virtual = 350728\n# exit 0\nINFO: [Common 17-206] Exiting Vivado at Wed Nov 11 05:06:06 2026...\n",
      "pid": 1373338,
      "source_id": "632c20a179a83d030793d1d0f24add9c3f2acd99f84e8ddfe4a4a61da4a66e0d",
      "stage_log": {
        "bytes": 231327,
        "mtime_ns": 1794344766936188379,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-group4-r1-20261111/map-full-module/map-full-module-attempt-1.log"
      },
      "stage_process": {},
      "start_ticks": "14995851",
      "status": "VERIFIED_AND_MAPPED_MODULE_ONLY",
      "updated_utc": "2026-11-10T21:06:12.445365+00:00",
      "worker_processes": []
    },
    "Opt4-fit-address-group8-cec-r1-state.json": {
      "controller": {
        "cpu_ticks": 380,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 1635055,
        "process_state": "S",
        "rss_bytes": 19615744,
        "start_ticks": "16366140"
      },
      "hardware_commit": "32837b0b1987091eb86e4157ec0c6360f5bde58b",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": true,
      "log_tail": "",
      "pid": 1635055,
      "source_id": "ac8e2b03492d7de78ab5ad94d2383827498f530ee3daf40ef4d2184cc3081706",
      "stage_log": {
        "bytes": 0,
        "mtime_ns": 1794351954251781976,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-group8-cec-r1-20261111/cec/cec-g0-attempt-1.log"
      },
      "stage_process": {
        "cpu_ticks": 718974,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 1635289,
        "process_state": "R",
        "rss_bytes": 142012416,
        "start_ticks": "16367468"
      },
      "start_ticks": "16366140",
      "status": "RUNNING_CEC-G0",
      "updated_utc": "2026-11-11T01:05:35.226134+00:00",
      "worker_processes": [
        {
          "comm": "yosys-abc",
          "cpu_ticks": 718974,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 0,
            "rchar": 243822,
            "read_bytes": 122880,
            "syscr": 31,
            "syscw": 0,
            "wchar": 0,
            "write_bytes": 0
          },
          "pid": 1635289,
          "process_state": "R",
          "rss_bytes": 142012416,
          "start_ticks": "16367468"
        }
      ]
    },
    "Opt4-fit-address-group8-proofsplit-r1-state.json": {
      "controller": {},
      "error": "AssertionError(('sat-equivalent-g0', 1, PosixPath('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-group8-proofsplit-r1-20261111/proof/sat-equivalent-g0-attempt-1.log')))",
      "hardware_commit": "32837b0b1987091eb86e4157ec0c6360f5bde58b",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "._ref_T_2.\nRemoved top 60 bits (of 64) from wire Group8EqProof0._ref_T_20.\nRemoved top 60 bits (of 64) from wire Group8EqProof0._ref_T_23.\nRemoved top 59 bits (of 64) from wire Group8EqProof0._ref_T_25.\nRemoved top 58 bits (of 64) from wire Group8EqProof0._ref_T_27.\nRemoved top 57 bits (of 64) from wire Group8EqProof0._ref_T_29.\nRemoved top 63 bits (of 64) from wire Group8EqProof0._ref_T_31.\nRemoved top 60 bits (of 64) from wire Group8EqProof0._ref_T_5.\nRemoved top 63 bits (of 64) from wire Group8EqProof0._ref_T_8.\n\n2.10. Executing OPT_CLEAN pass (remove unused cells and wires).\nFinding unused cells or wires in module \\Group8EqProof0..\nRemoved 0 unused cells and 23 unused wires.\n<suppressed ~1 debug messages>\n\n2.11. Executing MEMORY_COLLECT pass (generating $mem cells).\n\n2.12. Executing OPT pass (performing simple optimizations).\n\n2.12.1. Executing OPT_EXPR pass (perform const folding).\nOptimizing module Group8EqProof0.\n\n2.12.2. Executing OPT_MERGE pass (detect identical cells).\nFinding identical cells in module `\\Group8EqProof0'.\nRemoved a total of 0 cells.\n\n2.12.3. Executing OPT_CLEAN pass (remove unused cells and wires).\nFinding unused cells or wires in module \\Group8EqProof0..\n\n2.12.4. Finished fast OPT passes.\n\n2.13. Printing statistics.\n\n=== Group8EqProof0 ===\n\n        +----------Local Count, excluding submodules.\n        | \n      263 wires\n     1972 wire bits\n      239 public wires\n     1822 public wire bits\n       18 ports\n      105 port bits\n      219 cells\n       14   $add\n       14   $and\n       24   $eq\n        6   $ge\n       26   $le\n      119   $mux\n        7   $ne\n        1   $not\n        8   $or\n\n2.14. Executing CHECK pass (checking for obvious problems).\nChecking module Group8EqProof0...\nFound and reported 0 problems.\n\n3. Executing SAT pass (solving SAT problems in the circuit).\n\nSetting up SAT problem:\nFinal constraint equation: { } = { }\nImported 219 cells to SAT database.\nImport proof-constraint: \\io_equivalent = 1'1\nFinal proof equation: \\io_equivalent = 1'1\n\nSolving problem with 8879 variables and 24648 clauses..\nInterrupted SAT solver: TIMEOUT!\n\n        _____  _  _      _____ ____  _     _____\n       /__ __\\/ \\/ \\__/|/  __//  _ \\/ \\ /\\/__ __\\\n         / \\  | || |\\/|||  \\  | / \\|| | ||  / \\\n         | |  | || |  |||  /_ | \\_/|| \\_/|  | |\n         \\_/  \\_/\\_/  \\|\\____\\\\____/\\____/  \\_/\n\nERROR: Called with -verify and proof did time out!\n",
      "pid": 1617649,
      "source_id": "ac8e2b03492d7de78ab5ad94d2383827498f530ee3daf40ef4d2184cc3081706",
      "stage_log": {
        "bytes": 21879,
        "mtime_ns": 1794351318813517689,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-group8-proofsplit-r1-20261111/proof/sat-equivalent-g0-attempt-1.log"
      },
      "stage_process": {},
      "start_ticks": "16272789",
      "status": "FAILED_WITH_EVIDENCE",
      "updated_utc": "2026-11-10T22:55:18.828523+00:00",
      "worker_processes": []
    },
    "Opt4-fit-address-group8-r1-state.json": {
      "controller": {},
      "error": "AssertionError(('sat-equivalent', 1, PosixPath('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-group8-r1-20261111/proof/sat-equivalent-attempt-1.log')))",
      "hardware_commit": "32837b0b1987091eb86e4157ec0c6360f5bde58b",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "Proof._equivalent_ref_T_99.\nRemoved top 2 bits (of 7) from wire Group8Proof._io_mutantEquivalent_T_33.\nRemoved top 1 bits (of 7) from wire Group8Proof._io_mutantEquivalent_T_34.\nRemoved top 1 bits (of 7) from wire Group8Proof._io_mutantEquivalent_T_35.\nRemoved top 1 bits (of 7) from wire Group8Proof._io_mutantEquivalent_T_36.\nRemoved top 1 bits (of 7) from wire Group8Proof._io_mutantEquivalent_T_37.\nRemoved top 53 bits (of 64) from wire Group8Proof.equivalent_ref.\nRemoved top 53 bits (of 64) from wire Group8Proof.equivalent_ref_1.\n\n2.10. Executing OPT_CLEAN pass (remove unused cells and wires).\nFinding unused cells or wires in module \\Group8Proof..\nRemoved 0 unused cells and 107 unused wires.\n<suppressed ~1 debug messages>\n\n2.11. Executing MEMORY_COLLECT pass (generating $mem cells).\n\n2.12. Executing OPT pass (performing simple optimizations).\n\n2.12.1. Executing OPT_EXPR pass (perform const folding).\nOptimizing module Group8Proof.\n\n2.12.2. Executing OPT_MERGE pass (detect identical cells).\nFinding identical cells in module `\\Group8Proof'.\nRemoved a total of 0 cells.\n\n2.12.3. Executing OPT_CLEAN pass (remove unused cells and wires).\nFinding unused cells or wires in module \\Group8Proof..\n\n2.12.4. Finished fast OPT passes.\n\n2.13. Printing statistics.\n\n=== Group8Proof ===\n\n        +----------Local Count, excluding submodules.\n        | \n      732 wires\n     5007 wire bits\n      632 public wires\n     4844 public wire bits\n       45 ports\n      204 port bits\n      591 cells\n       63   $add\n       53   $and\n       28   $eq\n        6   $ge\n       64   $le\n      332   $mux\n        7   $ne\n        1   $not\n       37   $or\n\n2.14. Executing CHECK pass (checking for obvious problems).\nChecking module Group8Proof...\nFound and reported 0 problems.\n\n3. Executing SAT pass (solving SAT problems in the circuit).\n\nSetting up SAT problem:\nFinal constraint equation: { } = { }\nImported 591 cells to SAT database.\nImport proof-constraint: \\io_equivalent = 1'1\nFinal proof equation: \\io_equivalent = 1'1\n\nSolving problem with 17045 variables and 46986 clauses..\nInterrupted SAT solver: TIMEOUT!\n\n        _____  _  _      _____ ____  _     _____\n       /__ __\\/ \\/ \\__/|/  __//  _ \\/ \\ /\\/__ __\\\n         / \\  | || |\\/|||  \\  | / \\|| | ||  / \\\n         | |  | || |  |||  /_ | \\_/|| \\_/|  | |\n         \\_/  \\_/\\_/  \\|\\____\\\\____/\\____/  \\_/\n\nERROR: Called with -verify and proof did time out!\n",
      "pid": 1599756,
      "source_id": "ac8e2b03492d7de78ab5ad94d2383827498f530ee3daf40ef4d2184cc3081706",
      "stage_log": {
        "bytes": 74718,
        "mtime_ns": 1794350250136776426,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-group8-r1-20261111/proof/sat-equivalent-attempt-1.log"
      },
      "stage_process": {},
      "start_ticks": "16165917",
      "status": "FAILED_WITH_EVIDENCE",
      "updated_utc": "2026-11-10T22:37:30.176449+00:00",
      "worker_processes": []
    },
    "Opt4-fit-address-heap-candidate-state.json": {
      "controller": {},
      "hardware_commit": "c41d42f61aa79d8249125c9e911438b797d007ce",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-heap-candidate-c41d42f-20261110/map/full-module-map-attempt-1.log",
      "log_tail": "[Project 1-571] Translating synthesized netlist\nNetlist sorting complete. Time (s): cpu = 00:00:26 ; elapsed = 00:00:26 . Memory (MB): peak = 15603.688 ; gain = 0.000 ; free physical = 81016 ; free virtual = 339356\nINFO: [Netlist 29-17] Analyzing 302843 Unisim elements for replacement\nINFO: [Netlist 29-28] Unisim Transformation completed in 5 CPU seconds\nWARNING: [Netlist 29-101] Netlist 'PackageAddressStats' is not ideal for floorplanning, since the cellview 'PackageAddressStats' contains a large number of primitives.  Please consider enabling hierarchy in synthesis if you want to do floorplanning.\nINFO: [Project 1-570] Preparing netlist for logic optimization\nINFO: [Opt 31-138] Pushed 0 inverter(s) to 0 load pin(s).\nNetlist sorting complete. Time (s): cpu = 00:00:00.38 ; elapsed = 00:00:00.39 . Memory (MB): peak = 15615.785 ; gain = 0.000 ; free physical = 81361 ; free virtual = 339768\nINFO: [Project 1-111] Unisim Transformation Summary:\nNo Unisim elements were transformed.\n\nSynth Design complete, checksum: 85725cf4\nINFO: [Common 17-83] Releasing license: Synthesis\n481 Infos, 1 Warnings, 0 Critical Warnings and 0 Errors encountered.\nsynth_design completed successfully\nsynth_design: Time (s): cpu = 03:32:50 ; elapsed = 03:39:36 . Memory (MB): peak = 15615.785 ; gain = 13128.348 ; free physical = 82449 ; free virtual = 340896\nINFO: [Common 17-600] The following parameters have non-default value.\ngeneral.maxThreads\n# report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-heap-candidate-c41d42f-20261110/map/utilization.rpt}\nreport_utilization: Time (s): cpu = 00:00:09 ; elapsed = 00:00:10 . Memory (MB): peak = 15615.785 ; gain = 0.000 ; free physical = 81694 ; free virtual = 340193\n# write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-heap-candidate-c41d42f-20261110/map/module.dcp}\nINFO: [Timing 38-35] Done setting XDC timing constraints.\nINFO: [Common 17-1381] The checkpoint '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-heap-candidate-c41d42f-20261110/map/module.dcp' has been generated.\nwrite_checkpoint: Time (s): cpu = 00:05:23 ; elapsed = 00:03:54 . Memory (MB): peak = 15687.820 ; gain = 72.035 ; free physical = 79581 ; free virtual = 342418\n# exit 0\nINFO: [Common 17-206] Exiting Vivado at Wed Nov 11 00:28:15 2026...\n",
      "pid": 3393575,
      "resources": {
        "Block RAM Tile": 216.0,
        "CARRY8": 54885.0,
        "CLB LUTs": 1183979.0,
        "CLB Registers": 390109.0,
        "DSPs": 0.0
      },
      "source_id": "6fcb790b0d19e832582166c1940f485a00940f95437b38d297d9533f446721d2",
      "stage_log": {
        "bytes": 230711,
        "mtime_ns": 1794328095684291743,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-heap-candidate-c41d42f-20261110/map/full-module-map-attempt-1.log"
      },
      "start_ticks": "12566129",
      "status": "VERIFIED_AND_MAPPED_CANDIDATE_NOT_PROMOTED",
      "updated_utc": "2026-11-10T16:28:20.740980+00:00",
      "worker_processes": []
    },
    "Opt4-fit-address-index-share-r1-bind2-state.json": {
      "controller": {},
      "full_module_map": {
        "checkpoint": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-index-share-r1-bind2-20261111/map-full-module/module.dcp",
        "checkpoint_sha256": "5c4b1503e7dd055df89eb3759337037ec00f2273dfcf8bb13b230b9948401760",
        "report": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-index-share-r1-bind2-20261111/map-full-module/utilization.rpt",
        "report_sha256": "fc8ab53383ac6a0f3b527bb3a90efdde4659fe5f3bd667694f999a36c473f53a",
        "resources": {
          "Block RAM Tile": 216.0,
          "CARRY8": 57429.0,
          "CLB LUTs": 1559184.0,
          "CLB Registers": 391106.0,
          "DSPs": 0.0
        },
        "rtl_sha256": "95c592f84723d724a5134f194c38087c224eb5bc5d2b36b8ab585cfb6e1a0e47",
        "scope": "OOC module only; not whole-DUT FIT",
        "tcl_sha256": "efd73b09bc2e6f0e8ddede929dd7eced8b1697b5b8cfb628ae1954f413a5d330"
      },
      "hardware_commit": "470f1291d01608e80be6cd8d42b29fc5fc28d395",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "-101] Netlist 'PackageAddressStats' is not ideal for floorplanning, since the cellview 'PackageAddressStats' contains a large number of primitives.  Please consider enabling hierarchy in synthesis if you want to do floorplanning.\nINFO: [Project 1-570] Preparing netlist for logic optimization\nINFO: [Opt 31-138] Pushed 0 inverter(s) to 0 load pin(s).\nNetlist sorting complete. Time (s): cpu = 00:00:00.47 ; elapsed = 00:00:00.47 . Memory (MB): peak = 12264.180 ; gain = 0.000 ; free physical = 80710 ; free virtual = 342775\nINFO: [Project 1-111] Unisim Transformation Summary:\nNo Unisim elements were transformed.\n\nSynth Design complete, checksum: 7c322c5f\nINFO: [Common 17-83] Releasing license: Synthesis\n481 Infos, 1 Warnings, 0 Critical Warnings and 0 Errors encountered.\nsynth_design completed successfully\nsynth_design: Time (s): cpu = 02:11:38 ; elapsed = 02:16:10 . Memory (MB): peak = 12264.180 ; gain = 9764.746 ; free physical = 84811 ; free virtual = 346877\nINFO: [Common 17-600] The following parameters have non-default value.\ngeneral.maxThreads\n# report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-index-share-r1-bind2-20261111/map-full-module/utilization.rpt}\nreport_utilization: Time (s): cpu = 00:00:11 ; elapsed = 00:00:11 . Memory (MB): peak = 12264.180 ; gain = 0.000 ; free physical = 88877 ; free virtual = 350945\n# report_utilization -hierarchical -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-index-share-r1-bind2-20261111/map-full-module/hierarchical.rpt}\nreport_utilization: Time (s): cpu = 00:00:16 ; elapsed = 00:00:17 . Memory (MB): peak = 12264.180 ; gain = 0.000 ; free physical = 88402 ; free virtual = 350468\n# write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-index-share-r1-bind2-20261111/map-full-module/module.dcp}\nINFO: [Timing 38-35] Done setting XDC timing constraints.\nINFO: [Common 17-1381] The checkpoint '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-index-share-r1-bind2-20261111/map-full-module/module.dcp' has been generated.\nwrite_checkpoint: Time (s): cpu = 00:06:23 ; elapsed = 00:04:37 . Memory (MB): peak = 12336.215 ; gain = 72.035 ; free physical = 87916 ; free virtual = 351025\n# exit 0\nINFO: [Common 17-206] Exiting Vivado at Wed Nov 11 07:08:02 2026...\n",
      "pid": 1467003,
      "source_id": "4eb296ef53358af362644177a450a3bdfd6488f0d98f0e5d8d5c1b49cb2e010e",
      "stage_log": {
        "bytes": 231462,
        "mtime_ns": 1794352082300906578,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-index-share-r1-bind2-20261111/map-full-module/map-full-module-attempt-1.log"
      },
      "stage_process": {},
      "start_ticks": "15499432",
      "status": "VERIFIED_AND_MAPPED_MODULE_ONLY",
      "updated_utc": "2026-11-10T23:08:09.764648+00:00",
      "worker_processes": []
    },
    "Opt4-fit-address-round3-state.json": {
      "controller": {},
      "full_address_map": {
        "report": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-round3-20261110/full-address-map/utilization.rpt",
        "report_sha256": "ebed46013236e9910f5202e9149795496389d9835397521da50e851c21307b66",
        "resources": {
          "Block RAM Tile": 216.0,
          "CARRY8": 55392.0,
          "CLB LUTs": 1153226.0,
          "CLB Registers": 390181.0,
          "DSPs": 0.0
        },
        "rtl_sha256": "a9f6976ade4bd02282b755cc25b203caf153728775d35ff8238aa0c956460a52",
        "scope": "OOC probe only; not full-system capacity",
        "tcl_sha256": "0e0e37e92486315a62af5342494b1a41c44c4e13d111eb66a54535684eabcdfa"
      },
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "pid": 2872322,
      "source_id": "d5ca949536b50c2d6bf2f9ef1c2748282f88bac0fa5f2d4cc7ffa5b6c94feb28",
      "start_ticks": "12071140",
      "status": "VERIFIED_AND_MAPPED_MODULE_ONLY",
      "updated_utc": "2026-11-10T15:12:09.106271+00:00",
      "worker_processes": []
    },
    "Opt4-fit-address-sort-state.json": {
      "controller": {},
      "full_module_map": {
        "report": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-sort-11edd719-20261110/full-address/map/utilization.rpt",
        "report_sha256": "7dc8790896f26c628ae47453d4fbc60a06bd8ad6d23834fe54664cf3e873642d",
        "resources": {
          "Block RAM Tile": 216.0,
          "CARRY8": 56065.0,
          "CLB LUTs": 1197215.0,
          "CLB Registers": 389479.0,
          "DSPs": 0.0
        }
      },
      "hardware_commit": "11edd71981aa30ff3a26aab1f2f7327ac0266ee1",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "pid": 199432,
      "source_id": "f8a4239fe5a4818e15d98791f76d9d877172f342cdc0bc036ac6811e68de3cec",
      "start_ticks": "13241527",
      "status": "VERIFIED_AND_MAPPED_CANDIDATE_NOT_PROMOTED",
      "updated_utc": "2026-11-10T16:43:12.080511+00:00",
      "worker_processes": []
    },
    "Opt4-fit-address-tag-read-r1-state.json": {
      "controller": {},
      "full_module_map": {
        "checkpoint": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-tag-read-r1-20261111/map-full-module/module.dcp",
        "report": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-tag-read-r1-20261111/map-full-module/utilization.rpt",
        "report_sha256": "088781fecabebd84fd3c825417fafa403cf43ce246fb202fcc5a43318ab098cc",
        "resources": {
          "Block RAM Tile": 0.0,
          "CARRY8": 0.0,
          "CLB LUTs": 0.0,
          "CLB Registers": 0.0,
          "DSPs": 0.0
        },
        "rtl_sha256": "d8ff9b45d44abce15d28ceb8ea66e805359bb7ec49f3d11d44e1c7c4648a4785",
        "scope": "OOC only; not whole-DUT FIT",
        "tcl_sha256": "f054e3440499d3f278ab2ec31ccb4c5eb4063441cfaf32483e5eeceec778ad57"
      },
      "hardware_commit": "67e6fa3c3fd700ab749e5e5ee71d653b53c0a429",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "n 5 CPU seconds\nWARNING: [Netlist 29-101] Netlist 'PackageAddressStats' is not ideal for floorplanning, since the cellview 'PackageAddressStats' contains a large number of primitives.  Please consider enabling hierarchy in synthesis if you want to do floorplanning.\nINFO: [Project 1-570] Preparing netlist for logic optimization\nINFO: [Opt 31-138] Pushed 0 inverter(s) to 0 load pin(s).\nNetlist sorting complete. Time (s): cpu = 00:00:00.41 ; elapsed = 00:00:00.41 . Memory (MB): peak = 11652.301 ; gain = 0.000 ; free physical = 56795 ; free virtual = 341582\nINFO: [Project 1-111] Unisim Transformation Summary:\nNo Unisim elements were transformed.\n\nSynth Design complete, checksum: a1606b6e\nINFO: [Common 17-83] Releasing license: Synthesis\n481 Infos, 1 Warnings, 0 Critical Warnings and 0 Errors encountered.\nsynth_design completed successfully\nsynth_design: Time (s): cpu = 01:40:04 ; elapsed = 01:45:08 . Memory (MB): peak = 11652.301 ; gain = 9149.863 ; free physical = 57315 ; free virtual = 342100\nINFO: [Common 17-600] The following parameters have non-default value.\ngeneral.maxThreads\n# report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-tag-read-r1-20261111/map-full-module/utilization.rpt}\nreport_utilization: Time (s): cpu = 00:00:10 ; elapsed = 00:00:10 . Memory (MB): peak = 11652.301 ; gain = 0.000 ; free physical = 56532 ; free virtual = 341320\n# report_utilization -hierarchical -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-tag-read-r1-20261111/map-full-module/hierarchical.rpt}\nreport_utilization: Time (s): cpu = 00:00:15 ; elapsed = 00:00:15 . Memory (MB): peak = 11652.301 ; gain = 0.000 ; free physical = 62129 ; free virtual = 346917\n# write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-tag-read-r1-20261111/map-full-module/module.dcp}\nINFO: [Timing 38-35] Done setting XDC timing constraints.\nINFO: [Common 17-1381] The checkpoint '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-tag-read-r1-20261111/map-full-module/module.dcp' has been generated.\nwrite_checkpoint: Time (s): cpu = 00:05:32 ; elapsed = 00:04:02 . Memory (MB): peak = 11724.336 ; gain = 72.035 ; free physical = 49601 ; free virtual = 335827\n# exit 0\nINFO: [Common 17-206] Exiting Vivado at Wed Nov 11 04:45:25 2026...\n",
      "pid": 1286520,
      "source_id": "61f96a2321c1339c37a416a762f47bd9a8e25ee8562b7ec2fea14819614820a9",
      "stage_log": {
        "bytes": 231415,
        "mtime_ns": 1794343525954602552,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-tag-read-r1-20261111/map-full-module/map-full-module-attempt-1.log"
      },
      "stage_process": {},
      "start_ticks": "14802177",
      "status": "VERIFIED_AND_MAPPED_MODULE_ONLY",
      "updated_utc": "2026-11-10T20:45:33.572165+00:00",
      "worker_processes": []
    },
    "Opt4-fit-address-tagcompress-cachefix-r3-state.json": {
      "controller": {
        "cpu_ticks": 236,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 1715176,
        "process_state": "S",
        "rss_bytes": 15921152,
        "start_ticks": "16712610"
      },
      "hardware_commit": "3fb8a7f7d7e65b5076aaebbc8aa93101f00041ce",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": true,
      "log_tail": "   \n\t               64 Bit    Registers := 5251  \n\t               40 Bit    Registers := 257   \n\t               34 Bit    Registers := 64    \n\t               32 Bit    Registers := 577   \n\t               24 Bit    Registers := 256   \n\t               10 Bit    Registers := 120   \n\t                9 Bit    Registers := 1     \n\t                8 Bit    Registers := 1     \n\t                2 Bit    Registers := 257   \n\t                1 Bit    Registers := 579   \n+---RAMs : \n\t              89K Bit\t(1024 X 89 bit)          RAMs := 48    \n\t              64K Bit\t(1024 X 64 bit)          RAMs := 24    \n\t              34K Bit\t(1024 X 34 bit)          RAMs := 24    \n\t              32K Bit\t(1024 X 32 bit)          RAMs := 24    \n+---Muxes : \n\t   2 Input   89 Bit        Muxes := 320   \n\t   2 Input   64 Bit        Muxes := 6216  \n\t  65 Input   64 Bit        Muxes := 1     \n\t   2 Input   40 Bit        Muxes := 1024  \n\t   2 Input   34 Bit        Muxes := 24    \n\t   2 Input   32 Bit        Muxes := 1049  \n\t  18 Input   16 Bit        Muxes := 1     \n\t  17 Input   16 Bit        Muxes := 1     \n\t   2 Input    8 Bit        Muxes := 222   \n\t   9 Input    8 Bit        Muxes := 2     \n\t  10 Input    8 Bit        Muxes := 1     \n\t   2 Input    6 Bit        Muxes := 6152  \n\t   2 Input    5 Bit        Muxes := 12328 \n\t   2 Input    4 Bit        Muxes := 24865 \n\t   2 Input    3 Bit        Muxes := 24648 \n\t   2 Input    2 Bit        Muxes := 26177 \n\t   2 Input    1 Bit        Muxes := 14356 \n---------------------------------------------------------------------------------\nFinished RTL Component Statistics \n---------------------------------------------------------------------------------\n---------------------------------------------------------------------------------\nStart Part Resource Summary\n---------------------------------------------------------------------------------\nPart Resources:\nDSPs: 9024 (col length:94)\nBRAMs: 4032 (col length: RAMB18 288 RAMB36 144)\n---------------------------------------------------------------------------------\nFinished Part Resource Summary\n---------------------------------------------------------------------------------\nNo constraint files found.\n---------------------------------------------------------------------------------\nStart Cross Boundary and Area Optimization\n---------------------------------------------------------------------------------\n",
      "pid": 1715176,
      "source_id": "9a2882d23afaeada238076322cceb267d0c7ed5d74e00b0d6e532e04c13c03e3",
      "stage_log": {
        "bytes": 40292,
        "mtime_ns": 1794358527155780729,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-tagcompress-cachefix-r3-20261111/map-full-module/map-full-module-attempt-1.log"
      },
      "stage_process": {
        "cpu_ticks": 0,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 1727358,
        "process_state": "S",
        "rss_bytes": 3821568,
        "start_ticks": "16748173"
      },
      "start_ticks": "16712610",
      "status": "RUNNING_MAP-FULL-MODULE",
      "updated_utc": "2026-11-11T01:05:21.585607+00:00",
      "worker_processes": [
        {
          "comm": "vivado",
          "cpu_ticks": 0,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 0,
            "rchar": 66522,
            "read_bytes": 0,
            "syscr": 169,
            "syscw": 16,
            "wchar": 352,
            "write_bytes": 0
          },
          "pid": 1727358,
          "process_state": "S",
          "rss_bytes": 3821568,
          "start_ticks": "16748173"
        },
        {
          "comm": "loader",
          "cpu_ticks": 0,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 0,
            "rchar": 1499877,
            "read_bytes": 0,
            "syscr": 450,
            "syscw": 16,
            "wchar": 232,
            "write_bytes": 0
          },
          "pid": 1727380,
          "process_state": "S",
          "rss_bytes": 3923968,
          "start_ticks": "16748176"
        },
        {
          "comm": "vivado",
          "cpu_ticks": 334253,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 2556678144,
            "rchar": 6495350973,
            "read_bytes": 45056,
            "syscr": 794162,
            "syscw": 1660728,
            "wchar": 6536907106,
            "write_bytes": 6537355264
          },
          "pid": 1727399,
          "process_state": "S",
          "rss_bytes": 6703095808,
          "start_ticks": "16748185"
        }
      ]
    },
    "Opt4-fit-address-tagcompress-r1-state.json": {
      "controller": {},
      "error": "AssertionError(('boundary-compile', 2, '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-tagcompress-r1-20261111/histogram/boundary-compile-attempt-1.log'))",
      "hardware_commit": "3fb8a7f7d7e65b5076aaebbc8aa93101f00041ce",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "n -Wno-c++11-narrowing -Wno-constant-logical-operand -Wno-non-pod-varargs -Wno-parentheses-equality -Wno-shadow -Wno-sign-compare -Wno-tautological-bitwise-compare -Wno-tautological-compare -Wno-uninitialized -Wno-unused-parameter -Wno-unused-variable    -O0   -x c++-header VHistogramProbe__pch.h -o VHistogramProbe__pch.h.slow.gch\necho \"\" > VHistogramProbe__ALL.verilator_deplist.tmp\nccache: error: Failed to write to /home/guozh/.ccache/0/stats.tmp.devjz-ubt20-s01.1695581.SwRXtv\nmake: *** [/usr/local/share/verilator/include/verilated.mk:275: verilated_threads.o] Error 1\nmake: *** Waiting for unfinished jobs....\nccache: error: Failed to write to /home/guozh/.ccache/8/stats.tmp.devjz-ubt20-s01.1695580.VCivDd\nmake: *** [/usr/local/share/verilator/include/verilated.mk:275: verilated.o] Error 1\nccache: error: Failed to write to /home/guozh/.ccache/4/stats.tmp.devjz-ubt20-s01.1695582.EApW48\nmake: *** [/usr/local/share/verilator/include/verilated.mk:281: VHistogramProbe__pch.h.fast.gch] Error 1\nccache: error: Failed to write to /home/guozh/.ccache/f/stats.tmp.devjz-ubt20-s01.1695579.KQvixa\nmake: *** [VHistogramProbe.mk:64: boundary.o] Error 1\nccache: error: Failed to write to /home/guozh/.ccache/4/stats.tmp.devjz-ubt20-s01.1695584.hllBHJ\nmake: *** [/usr/local/share/verilator/include/verilated.mk:283: VHistogramProbe__pch.h.slow.gch] Error 1\nrm VHistogramProbe__ALL.verilator_deplist.tmp\nmake: Leaving directory '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-tagcompress-r1-20261111/histogram/obj'\n%Error: make -C /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-tagcompress-r1-20261111/histogram/obj -f VHistogramProbe.mk -j 8 OPT_FAST=-O0 OPT_SLOW=-O0 exited with 2\n%Error: Command Failed ulimit -s unlimited 2>/dev/null; exec /usr/local/share/verilator/bin/verilator_bin --cc --exe --build --top-module HistogramProbe --Mdir /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-tagcompress-r1-20261111/histogram/obj -j 8 --output-split 10000 --output-split-cfuncs 200 -Wno-fatal -CFLAGS -O0 -MAKEFLAGS OPT_FAST=-O0\\ OPT_SLOW=-O0 /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-tagcompress-r1-20261111/histogram/HistogramProbe.v /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-tagcompress-r1-20261111/histogram/boundary.cpp\n",
      "pid": 1693582,
      "source_id": "9a2882d23afaeada238076322cceb267d0c7ed5d74e00b0d6e532e04c13c03e3",
      "stage_log": {
        "bytes": 5413,
        "mtime_ns": 1794354571885461617,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-tagcompress-r1-20261111/histogram/boundary-compile-attempt-1.log"
      },
      "stage_process": {},
      "start_ticks": "16621863",
      "status": "FAILED_WITH_EVIDENCE",
      "updated_utc": "2026-11-10T23:49:31.904361+00:00",
      "worker_processes": []
    },
    "Opt4-fit-address-update-share-r1-state.json": {
      "controller": {
        "cpu_ticks": 225,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 1712770,
        "process_state": "S",
        "rss_bytes": 15417344,
        "start_ticks": "16704932"
      },
      "hardware_commit": "eada7948b15146fd33bbc91aad7bac4ab9ec44b7",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": true,
      "log_tail": "= 5251  \n\t               40 Bit    Registers := 257   \n\t               34 Bit    Registers := 64    \n\t               32 Bit    Registers := 833   \n\t               10 Bit    Registers := 120   \n\t                9 Bit    Registers := 1     \n\t                8 Bit    Registers := 1     \n\t                2 Bit    Registers := 257   \n\t                1 Bit    Registers := 579   \n+---RAMs : \n\t              89K Bit\t(1024 X 89 bit)          RAMs := 48    \n\t              64K Bit\t(1024 X 64 bit)          RAMs := 24    \n\t              34K Bit\t(1024 X 34 bit)          RAMs := 24    \n\t              32K Bit\t(1024 X 32 bit)          RAMs := 24    \n+---Muxes : \n\t   2 Input   89 Bit        Muxes := 320   \n\t   2 Input   64 Bit        Muxes := 64    \n\t  65 Input   64 Bit        Muxes := 1     \n\t   2 Input   40 Bit        Muxes := 1024  \n\t   2 Input   34 Bit        Muxes := 24    \n\t   2 Input   32 Bit        Muxes := 1049  \n\t  17 Input   16 Bit        Muxes := 1     \n\t  18 Input   16 Bit        Muxes := 1     \n\t   9 Input    8 Bit        Muxes := 2     \n\t  10 Input    8 Bit        Muxes := 1     \n\t   2 Input    8 Bit        Muxes := 222   \n\t   2 Input    6 Bit        Muxes := 6152  \n\t   2 Input    5 Bit        Muxes := 12328 \n\t   2 Input    4 Bit        Muxes := 24865 \n\t   2 Input    3 Bit        Muxes := 24648 \n\t   2 Input    2 Bit        Muxes := 26177 \n\t   2 Input    1 Bit        Muxes := 11284 \n---------------------------------------------------------------------------------\nFinished RTL Component Statistics \n---------------------------------------------------------------------------------\n---------------------------------------------------------------------------------\nStart Part Resource Summary\n---------------------------------------------------------------------------------\nPart Resources:\nDSPs: 9024 (col length:94)\nBRAMs: 4032 (col length: RAMB18 288 RAMB36 144)\n---------------------------------------------------------------------------------\nFinished Part Resource Summary\n---------------------------------------------------------------------------------\nNo constraint files found.\n---------------------------------------------------------------------------------\nStart Cross Boundary and Area Optimization\n---------------------------------------------------------------------------------\ntcmalloc: large alloc 1128800256 bytes == 0x10f25c000 @  0x7fb210038e7f 0x7fb1b860ea71\n",
      "pid": 1712770,
      "source_id": "89a95f25bc2b2413464e4cd94c5ed5b3a69673f16f0ebf18521baf1cc1cb8a29",
      "stage_log": {
        "bytes": 40302,
        "mtime_ns": 1794358237286249444,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-update-share-r1-20261111/map-full-module/map-full-module-attempt-1.log"
      },
      "stage_process": {
        "cpu_ticks": 0,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 1722271,
        "process_state": "S",
        "rss_bytes": 3829760,
        "start_ticks": "16734457"
      },
      "start_ticks": "16704932",
      "status": "RUNNING_MAP-FULL-MODULE",
      "updated_utc": "2026-11-11T01:05:34.452012+00:00",
      "worker_processes": [
        {
          "comm": "vivado",
          "cpu_ticks": 0,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 0,
            "rchar": 66522,
            "read_bytes": 0,
            "syscr": 169,
            "syscw": 16,
            "wchar": 344,
            "write_bytes": 0
          },
          "pid": 1722271,
          "process_state": "S",
          "rss_bytes": 3829760,
          "start_ticks": "16734457"
        },
        {
          "comm": "loader",
          "cpu_ticks": 0,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 0,
            "rchar": 1499877,
            "read_bytes": 0,
            "syscr": 450,
            "syscw": 16,
            "wchar": 232,
            "write_bytes": 0
          },
          "pid": 1722287,
          "process_state": "S",
          "rss_bytes": 3895296,
          "start_ticks": "16734460"
        },
        {
          "comm": "vivado",
          "cpu_ticks": 339562,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 1573023744,
            "rchar": 6261663859,
            "read_bytes": 352256,
            "syscr": 727707,
            "syscw": 1546882,
            "wchar": 6181572468,
            "write_bytes": 6182014976
          },
          "pid": 1722315,
          "process_state": "S",
          "rss_bytes": 5932453888,
          "start_ticks": "16734469"
        }
      ]
    },
    "Opt4-fit-address-update-share-r2-state.json": {
      "controller": {
        "cpu_ticks": 202,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 1737896,
        "process_state": "S",
        "rss_bytes": 15470592,
        "start_ticks": "16778236"
      },
      "hardware_commit": "00847dc2b8f6be3f1e1ff0639c1104d33334ddc9",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": true,
      "log_tail": "or RAM strictMem_15_lineTag_reg. We will not be able to pipeline it. This may degrade performance. \nRAM Pipeline Warning: Read Address Register Found For RAM strictMem_15_sessionTag_reg. We will not be able to pipeline it. This may degrade performance. \nRAM Pipeline Warning: Read Address Register Found For RAM strictMem_15_packetSeq_reg. We will not be able to pipeline it. This may degrade performance. \nRAM Pipeline Warning: Read Address Register Found For RAM strictMem_0_strictStoreFirst_reg. We will not be able to pipeline it. This may degrade performance. \nRAM Pipeline Warning: Read Address Register Found For RAM strictMem_0_lineTag_reg. We will not be able to pipeline it. This may degrade performance. \nRAM Pipeline Warning: Read Address Register Found For RAM strictMem_1_strictStoreFirst_reg. We will not be able to pipeline it. This may degrade performance. \nRAM Pipeline Warning: Read Address Register Found For RAM strictMem_1_lineTag_reg. We will not be able to pipeline it. This may degrade performance. \nRAM Pipeline Warning: Read Address Register Found For RAM packageMem_7_storeSeen_reg. We will not be able to pipeline it. This may degrade performance. \nRAM Pipeline Warning: Read Address Register Found For RAM packageMem_6_storeSeen_reg. We will not be able to pipeline it. This may degrade performance. \nRAM Pipeline Warning: Read Address Register Found For RAM packageMem_5_storeSeen_reg. We will not be able to pipeline it. This may degrade performance. \nRAM Pipeline Warning: Read Address Register Found For RAM packageMem_4_storeSeen_reg. We will not be able to pipeline it. This may degrade performance. \nRAM Pipeline Warning: Read Address Register Found For RAM packageMem_3_storeSeen_reg. We will not be able to pipeline it. This may degrade performance. \nRAM Pipeline Warning: Read Address Register Found For RAM packageMem_2_storeSeen_reg. We will not be able to pipeline it. This may degrade performance. \nRAM Pipeline Warning: Read Address Register Found For RAM packageMem_1_storeSeen_reg. We will not be able to pipeline it. This may degrade performance. \nRAM Pipeline Warning: Read Address Register Found For RAM packageMem_0_storeSeen_reg. We will not be able to pipeline it. This may degrade performance. \nRAM Pipeline Warning: Read Address Register Found For RAM packageMem_0_lineTag_reg. We will not be able to pipeline it. This may degrade performance. \n",
      "pid": 1737896,
      "source_id": "6b0de8636ec9d88f7d9702769c03325df78ab43c3c1fe527fff9dc1a3aafbbdb",
      "stage_log": {
        "bytes": 36026,
        "mtime_ns": 1794359021918682691,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-update-share-r2-20261111/map-full-module/map-full-module-attempt-1.log"
      },
      "stage_process": {
        "cpu_ticks": 0,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 1875944,
        "process_state": "S",
        "rss_bytes": 3895296,
        "start_ticks": "16806758"
      },
      "start_ticks": "16778236",
      "status": "RUNNING_MAP-FULL-MODULE",
      "updated_utc": "2026-11-11T01:05:37.398894+00:00",
      "worker_processes": [
        {
          "comm": "vivado",
          "cpu_ticks": 0,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 0,
            "rchar": 66522,
            "read_bytes": 0,
            "syscr": 169,
            "syscw": 16,
            "wchar": 344,
            "write_bytes": 0
          },
          "pid": 1875944,
          "process_state": "S",
          "rss_bytes": 3895296,
          "start_ticks": "16806758"
        },
        {
          "comm": "loader",
          "cpu_ticks": 0,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 0,
            "rchar": 1499877,
            "read_bytes": 0,
            "syscr": 450,
            "syscw": 16,
            "wchar": 232,
            "write_bytes": 0
          },
          "pid": 1875960,
          "process_state": "S",
          "rss_bytes": 3997696,
          "start_ticks": "16806760"
        },
        {
          "comm": "vivado",
          "cpu_ticks": 280207,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 36749312,
            "rchar": 5385734439,
            "read_bytes": 233472,
            "syscr": 497629,
            "syscw": 757804,
            "wchar": 4411291338,
            "write_bytes": 4411400192
          },
          "pid": 1875985,
          "process_state": "S",
          "rss_bytes": 6616563712,
          "start_ticks": "16806769"
        }
      ]
    },
    "Opt4-fit-bucket-tag-cad-state.json": {
      "certified_bitstream": false,
      "child": {
        "cpu_ticks": 3,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 1886240,
        "process_state": "S",
        "rss_bytes": 3932160,
        "start_ticks": "16844824"
      },
      "child_pid": 1886240,
      "child_start_ticks": "16844824",
      "controller": {
        "cpu_ticks": 497,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 1737960,
        "process_state": "S",
        "rss_bytes": 328224768,
        "start_ticks": "16778336"
      },
      "current_stage": "dut_synth",
      "hardware_commit": "9ae9a7fcf231a75259e23973b12a93896a443cbb",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": true,
      "log_dir": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-bucket-tag-cad-9ae9a7fc",
      "log_tail": "stant address. \n\t2: No valid read/write found for RAM. \n\t2: Only 1 word in RAM \nRAM \"ram_flattened_reg\" dissolved into registers\nReason is one or more of the following :\n\t1: Write port has constant address. \n\t2: No valid read/write found for RAM. \n\t2: Only 1 word in RAM \nRAM \"ram_flattened_reg\" dissolved into registers\nReason is one or more of the following :\n\t1: Write port has constant address. \n\t2: No valid read/write found for RAM. \n\t2: Only 1 word in RAM \nRAM \"ram_flattened_reg\" dissolved into registers\nReason is one or more of the following :\n\t1: RAM has multiple writes via different ports in same process. If RAM inferencing intended, write to one port per process. \n\t2: Unable to determine number of words or word size in RAM. \n\t3: No valid read/write found for RAM. \nRAM \"head_reg\" dissolved into registers\nReason is one or more of the following :\n\t1: Write port has constant address. \n\t2: No valid read/write found for RAM. \n\t2: Only 1 word in RAM \nRAM \"ram_flattened_reg\" dissolved into registers\nReason is one or more of the following :\n\t1: RAM has multiple writes via different ports in same process. If RAM inferencing intended, write to one port per process. \n\t2: Unable to determine number of words or word size in RAM. \n\t3: No valid read/write found for RAM. \nRAM \"head_reg\" dissolved into registers\nReason is one or more of the following :\n\t1: Write port has constant address. \n\t2: No valid read/write found for RAM. \n\t2: Only 1 word in RAM \nRAM \"ram_flattened_reg\" dissolved into registers\nReason is one or more of the following :\n\t1: Write port has constant address. \n\t2: No valid read/write found for RAM. \n\t2: Only 1 word in RAM \nRAM \"ram_flattened_reg\" dissolved into registers\nReason is one or more of the following :\n\t1: RAM has multiple writes via different ports in same process. If RAM inferencing intended, write to one port per process. \n\t2: Unable to determine number of words or word size in RAM. \n\t3: No valid read/write found for RAM. \nRAM \"head_reg\" dissolved into registers\nReason is one or more of the following :\n\t1: Write port has constant address. \n\t2: No valid read/write found for RAM. \n\t2: Only 1 word in RAM \nRAM \"ram_flattened_reg\" dissolved into registers\nReason is one or more of the following :\n\t1: Write port has constant address. \n\t2: No valid read/write found for RAM. \n\t2: Only 1 word in RAM \nRAM \"ram_flattened_reg\" dissolved into registers\n",
      "pid": 1737960,
      "profile": "Opt4-fit-C4-SVB32-bucket-tag-20261111",
      "source_id": "3791dd0e8f7d9c380500cd37f11ece4c92e275bc399894780228fa61449df561",
      "stage_log": {
        "bytes": 69789,
        "mtime_ns": 1794356829547853848,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-bucket-tag-cad-9ae9a7fc/dut_synth-attempt-1.log"
      },
      "start_ticks": "16778336",
      "status": "RUNNING_DUT_SYNTH",
      "updated_utc": "2026-11-11T01:05:28.010228+00:00",
      "worker_processes": [
        {
          "comm": "vivado",
          "cpu_ticks": 3,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 0,
            "rchar": 66522,
            "read_bytes": 0,
            "syscr": 169,
            "syscw": 16,
            "wchar": 386,
            "write_bytes": 0
          },
          "pid": 1886240,
          "process_state": "S",
          "rss_bytes": 3932160,
          "start_ticks": "16844824"
        },
        {
          "comm": "loader",
          "cpu_ticks": 0,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 0,
            "rchar": 1499877,
            "read_bytes": 0,
            "syscr": 450,
            "syscw": 16,
            "wchar": 232,
            "write_bytes": 0
          },
          "pid": 1886256,
          "process_state": "S",
          "rss_bytes": 3842048,
          "start_ticks": "16844829"
        },
        {
          "comm": "vivado",
          "cpu_ticks": 242177,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 36741120,
            "rchar": 1175809327,
            "read_bytes": 0,
            "syscr": 153563,
            "syscw": 3258,
            "wchar": 36883396,
            "write_bytes": 36966400
          },
          "pid": 1886276,
          "process_state": "S",
          "rss_bytes": 13162213376,
          "start_ticks": "16844839"
        }
      ]
    },
    "Opt4-fit-bucket-tag-rtl-state.json": {
      "controller": {},
      "hardware_commit": "9ae9a7fcf231a75259e23973b12a93896a443cbb",
      "identity_live": false,
      "source_id": "3791dd0e8f7d9c380500cd37f11ece4c92e275bc399894780228fa61449df561",
      "status": "GOLDENGATE_COMPLETE_NOT_SYNTHESIZED"
    },
    "Opt4-fit-bucket-tag-software-prep-r1-state.json": {
      "controller": {},
      "hardware_commit": "9ae9a7fcf231a75259e23973b12a93896a443cbb",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "pid": 1945119,
      "source_id": "3791dd0e8f7d9c380500cd37f11ece4c92e275bc399894780228fa61449df561",
      "start_ticks": "17042704",
      "status": "13_ORDINARY_PROGRAMS_EXACT_PAIRED_SOFTWARE_READY_NOT_FPGA_ADMITTED",
      "updated_utc": "2026-11-11T00:58:28.048195+00:00",
      "worker_processes": []
    },
    "Opt4-fit-bucket-tag-system-r1-state.json": {
      "controller": {},
      "hardware_commit": "9ae9a7fcf231a75259e23973b12a93896a443cbb",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": " full_compare=%d cancelled=%d\\n), PrintPort(synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire,List((enable,UInt<1>), (args_0,UInt<3>), (args_1,UInt<32>), (args_2,UInt<2>), (args_3,UInt<1>), (args_4,UInt<1>)),EC_OPT4_PACKAGE_RESULT hart=%d seq=%x status=%d full_compare=%d cancelled=%d\\n)))\nGenerating a Midas Memory Model\n  Max Read Requests: 6\n  Max Write Requests: 6\n  Max Read Length: 8\n  Max Write Length: 8\n  Max Read ID Reuse: 1\n  Max Write ID Reuse: 1\n\nTiming Model Parameters\n  Timing Model Class: Latency Bandwidth Pipe\n  No LLC Model Instantiated\n\n\nDefault Settings\n  +mm_relaxFunctionalModel_0=0\n  +mm_writeMaxReqs_0=6\n  +mm_readMaxReqs_0=6\n  +mm_writeLatency_0=30\n  +mm_readLatency_0=30\n\nBridge Streams To CPU:\n  Name: TRACERVBRIDGEMODULE_0_to_cpu_stream, Idx: 0, FPGA Buffer Depth: 6144, FPGA Buffer Width: 64\n  Name: TRACERVBRIDGEMODULE_1_to_cpu_stream, Idx: 1, FPGA Buffer Depth: 6144, FPGA Buffer Width: 64\n  Name: TRACERVBRIDGEMODULE_2_to_cpu_stream, Idx: 2, FPGA Buffer Depth: 6144, FPGA Buffer Width: 64\n  Name: TRACERVBRIDGEMODULE_3_to_cpu_stream, Idx: 3, FPGA Buffer Depth: 6144, FPGA Buffer Width: 64\n  Name: TRACERVBRIDGEMODULE_4_to_cpu_stream, Idx: 4, FPGA Buffer Depth: 6144, FPGA Buffer Width: 64\n  Name: PRINTBRIDGEMODULE_0_to_cpu_stream, Idx: 5, FPGA Buffer Depth: 6144, FPGA Buffer Width: 64\n  Name: PRINTBRIDGEMODULE_1_to_cpu_stream, Idx: 6, FPGA Buffer Depth: 6144, FPGA Buffer Width: 64\nBridge Streams From CPU:\n  None\nSimulator Memory Map:\n  [   0,   7f]: FASEDMemoryTimingModel_0\n  [  80,   ff]: BlockDevBridgeModule_0\n  [ 100,  13f]: TSIBridgeModule_0\n  [ 140,  17f]: TracerVBridgeModule_0\n  [ 180,  1bf]: TracerVBridgeModule_1\n  [ 1c0,  1ff]: TracerVBridgeModule_2\n  [ 200,  23f]: TracerVBridgeModule_3\n  [ 240,  27f]: TracerVBridgeModule_4\n  [ 280,  2bf]: LoadMemWidget_0\n  [ 2c0,  2df]: PeekPokeBridgeModule_0\n  [ 2e0,  2ff]: UARTBridgeModule_0\n  [ 300,  31f]: ClockBridgeModule_0\n  [ 320,  33f]: PrintBridgeModule_0\n  [ 340,  35f]: PrintBridgeModule_1\n  [ 360,  37f]: CPUManagedStreamEngine_0\n  [ 380,  38f]: SimulationMaster_0\n  [ 390,  397]: ResetPulseBridgeModule_0\nTotal Host-FPGA DRAM Allocated: 16.000 GiB of 16.000 GiB available.\nHost-FPGA DRAM Allocation Map:\n  MainMemory_0 -> [0x0, 0x3FFFFFFFF]\n    Associated bridges: FASEDMemoryTimingModel_0\nAuto ILA: p(EnableAutoILA) unset. Skipping AutoILATransform\n",
      "pid": 1721924,
      "source_id": "3791dd0e8f7d9c380500cd37f11ece4c92e275bc399894780228fa61449df561",
      "stage_log": {
        "bytes": 7576,
        "mtime_ns": 1794356513665890268,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-bucket-tag-system-r1-20261111/goldengate-attempt-1.log"
      },
      "stage_process": {},
      "start_ticks": "16732278",
      "status": "RTL_READY_REAL_ABI_CHECKED",
      "updated_utc": "2026-11-11T00:24:35.512361+00:00",
      "worker_processes": []
    },
    "Opt4-fit-cad-state.json": {
      "certified_bitstream": false,
      "controller": {},
      "current_stage": "implementation",
      "dut_resources": {
        "Block RAM Tile": {
          "available": 2016.0,
          "percent": 44.39484126984127,
          "used": 895.0
        },
        "CARRY8": {
          "available": 162960.0,
          "percent": 56.284364261168385,
          "used": 91721.0
        },
        "CLB LUTs": {
          "available": 1303680.0,
          "percent": 240.23303264604812,
          "used": 3131870.0
        },
        "CLB Registers": {
          "available": 2607360.0,
          "percent": 65.41371348797252,
          "used": 1705571.0
        },
        "DSPs": {
          "available": 9024.0,
          "percent": 2.127659574468085,
          "used": 192.0
        },
        "URAM": {
          "available": 960.0,
          "percent": 0.0,
          "used": 0.0
        }
      },
      "error": "('implementation', 1, '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-cad-8da24a26/implementation-attempt-1.log')",
      "hardware_commit": "8da24a269b98a0d6a8f57b030353a310812c4344",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_dir": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-cad-8da24a26",
      "log_tail": "al -hierarchical_depth 30 -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-cad-8da24a26/top-postopt-hierarchical.rpt}\n##   report_drc -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-cad-8da24a26/top-postopt-drc.rpt}\n##   set f [open {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-cad-8da24a26/top-postopt-utilization.rpt} r]\n##   set text [read $f]; close $f\n##   set exceeded {}; set seen {}\n##   foreach line [split $text \\n] {\n##     set a [split $line |]\n##     if {[llength $a] < 7} {continue}\n##     set kind [string trimright [string trim [lindex $a 1]] *]\n##     if {$kind ni {\"CLB LUTs\" \"CLB Registers\" \"CARRY8\" \"DSPs\" \"Block RAM Tile\" \"URAM\"} || [dict exists $seen $kind]} {continue}\n##     set used [string map {, {}} [string trim [lindex $a 2]]]\n##     set avail [string map {, {}} [string trim [lindex $a 5]]]\n##     if {![string is double -strict $used] || ![string is double -strict $avail] || $avail <= 0} {continue}\n##     dict set seen $kind 1\n##     puts \"EC_FIT_CAPACITY kind=$kind used=$used available=$avail\"\n##     if {$used > $avail} {lappend exceeded $kind}\n##   }\n##   if {[dict size $seen] < 5} {error \"capacity report parse incomplete\"}\n##   set f [open {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-cad-8da24a26/capacity.complete} w]\n##   if {[llength $exceeded]} {puts $f \"NOT_FIT_POSTOPT $exceeded\";close $f;error \"NOT FIT; saved optimized checkpoint, no place/route: $exceeded\"}\n##   puts $f \"CAPACITY_FITS_POSTOPT_TIMING_PENDING\";close $f\n## \n##   create_report \"impl_1_opt_report_drc_0\" \"report_drc -file design_1_wrapper_drc_opted.rpt -pb design_1_wrapper_drc_opted.pb -rpx design_1_wrapper_drc_opted.rpx\"\n## OPTRACE \"opt_design reports\" END { }\n##   close_msg_db -file opt_design.pb\n## } RESULT]\n## if {$rc} {\n##   step_failed opt_design\n##   return -code error $RESULT\n## } else {\n##   end_step opt_design\n##   unset ACTIVE_STEP \n## }\nNOT FIT; saved optimized checkpoint, no place/route: {CLB LUTs}\n\n    while executing\n\"source {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-cad-8da24a26/implementation-bound.tcl}\"\n    (file \"/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-cad-8da24a26/implementation-attempt-1.tcl\" line 1)\nINFO: [Common 17-206] Exiting Vivado at Wed Nov 11 08:46:44 2026...\n",
      "pid": 2790677,
      "profile": "Opt4-fit-C4-SVB32-20261110",
      "source_id": "7e77ddda28298ac88be13c28dbe98771982bc6ca9587f810adf875bffd580cc1",
      "stage_log": {
        "bytes": 80893,
        "mtime_ns": 1794358004660371076,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-cad-8da24a26/implementation-attempt-1.log"
      },
      "start_ticks": "11895255",
      "status": "NOT_FIT_POSTOPT",
      "top_postopt_resources": {
        "Block RAM Tile": {
          "available": 2016.0,
          "percent": 51.01686507936508,
          "used": 1028.5
        },
        "CARRY8": {
          "available": 162960.0,
          "percent": 56.939739813451155,
          "used": 92789.0
        },
        "CLB LUTs": {
          "available": 1303680.0,
          "percent": 246.66198760432007,
          "used": 3215683.0
        },
        "CLB Registers": {
          "available": 2607360.0,
          "percent": 68.91173447471772,
          "used": 1796777.0
        },
        "DSPs": {
          "available": 9024.0,
          "percent": 2.160904255319149,
          "used": 195.0
        },
        "URAM": {
          "available": 960.0,
          "percent": 0.0,
          "used": 0.0
        }
      },
      "updated_utc": "2026-11-11T00:46:57.255440+00:00",
      "worker_processes": []
    },
    "Opt4-fit-retire-read-r1-state.json": {
      "controller": {
        "cpu_ticks": 147,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 1896443,
        "process_state": "S",
        "rss_bytes": 15450112,
        "start_ticks": "16895677"
      },
      "hardware_commit": "7e68d3df224fd37fd3f462b9deff376566ed9a79",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": true,
      "log_tail": "\n****** Vivado v2021.1 (64-bit)\n  **** SW Build 3247384 on Thu Jun 10 19:36:07 MDT 2021\n  **** IP Build 3246043 on Fri Jun 11 00:30:35 MDT 2021\n    ** Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.\n\nsource /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-retire-read-r1-20261111/map-full-module/map.tcl\n# set_param general.maxThreads 4\n# read_verilog {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-retire-read-r1-20261111/address/PackageAddressStats.v}\n# synth_design -top PackageAddressStats -part xcu280-fsvh2892-2L-e -mode out_of_context -directive RuntimeOptimized\nCommand: synth_design -top PackageAddressStats -part xcu280-fsvh2892-2L-e -mode out_of_context -directive RuntimeOptimized\nStarting synth_design\nAttempting to get a license for feature 'Synthesis' and/or device 'xcu280'\nINFO: [Common 17-349] Got license for feature 'Synthesis' and/or device 'xcu280'\nINFO: [Synth 8-7079] Multithreading enabled for synth_design using a maximum of 4 processes.\nINFO: [Synth 8-7078] Launching helper process for spawning children vivado processes\nINFO: [Synth 8-7075] Helper process launched with PID 1906281\n---------------------------------------------------------------------------------\nStarting Synthesize : Time (s): cpu = 00:00:05 ; elapsed = 00:00:05 . Memory (MB): peak = 2499.602 ; gain = 0.000 ; free physical = 68821 ; free virtual = 333768\n---------------------------------------------------------------------------------\nINFO: [Synth 8-6157] synthesizing module 'PackageAddressStats' [/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-retire-read-r1-20261111/address/PackageAddressStats.v:1]\n",
      "pid": 1896443,
      "source_id": "4c8636670eb9f78b3df716d02c5690dd50b163582fa370c323b5b4fe4dd3cea5",
      "stage_log": {
        "bytes": 1688,
        "mtime_ns": 1794357587140741272,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-retire-read-r1-20261111/map-full-module/map-full-module-attempt-1.log"
      },
      "stage_process": {
        "cpu_ticks": 0,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 1906014,
        "process_state": "S",
        "rss_bytes": 3964928,
        "start_ticks": "16928137"
      },
      "start_ticks": "16895677",
      "status": "RUNNING_MAP-FULL-MODULE",
      "updated_utc": "2026-11-11T01:05:21.070743+00:00",
      "worker_processes": [
        {
          "comm": "vivado",
          "cpu_ticks": 0,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 0,
            "rchar": 66522,
            "read_bytes": 0,
            "syscr": 169,
            "syscw": 16,
            "wchar": 335,
            "write_bytes": 0
          },
          "pid": 1906014,
          "process_state": "S",
          "rss_bytes": 3964928,
          "start_ticks": "16928137"
        },
        {
          "comm": "loader",
          "cpu_ticks": 0,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 0,
            "rchar": 1499877,
            "read_bytes": 0,
            "syscr": 450,
            "syscw": 16,
            "wchar": 232,
            "write_bytes": 0
          },
          "pid": 1906030,
          "process_state": "S",
          "rss_bytes": 3956736,
          "start_ticks": "16928139"
        },
        {
          "comm": "vivado",
          "cpu_ticks": 158126,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 4096,
            "rchar": 968095151,
            "read_bytes": 0,
            "syscr": 57665,
            "syscw": 146,
            "wchar": 8580,
            "write_bytes": 32768
          },
          "pid": 1906049,
          "process_state": "S",
          "rss_bytes": 7176474624,
          "start_ticks": "16928147"
        }
      ]
    },
    "Opt4-fit-runtime-state.json": {
      "certified_bitstream": false,
      "controller": {
        "cpu_ticks": 22,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 3135212,
        "process_state": "S",
        "rss_bytes": 16441344,
        "start_ticks": "12439082"
      },
      "hardware_commit": "8da24a269b98a0d6a8f57b030353a310812c4344",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": true,
      "pid": 3135212,
      "source_id": "7e77ddda28298ac88be13c28dbe98771982bc6ca9587f810adf875bffd580cc1",
      "start_ticks": "12439082",
      "status": "WAITING_FOR_DERIVED_BITSTREAM",
      "updated_utc": "2026-11-11T01:01:24.146295+00:00",
      "worker_processes": [
        {
          "comm": "python3",
          "cpu_ticks": 22,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 0,
            "rchar": 2290008,
            "read_bytes": 0,
            "syscr": 480,
            "syscw": 158,
            "wchar": 169644,
            "write_bytes": 659456
          },
          "pid": 3135212,
          "process_state": "S",
          "rss_bytes": 16441344,
          "start_ticks": "12439082"
        }
      ]
    },
    "Opt4-fit-sort-system-continuation-state.json": {
      "controller": {},
      "hardware_commit": "11edd71981aa30ff3a26aab1f2f7327ac0266ee1",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "measured_module_resources": {
        "Block RAM Tile": 216.0,
        "CARRY8": 56065.0,
        "CLB LUTs": 1197215.0,
        "CLB Registers": 389479.0,
        "DSPs": 0.0
      },
      "pid": 258082,
      "source_id": "f8a4239fe5a4818e15d98791f76d9d877172f342cdc0bc036ac6811e68de3cec",
      "start_ticks": "13300541",
      "status": "REJECTED_INSUFFICIENT_MEASURED_AREA_GAIN",
      "updated_utc": "2026-11-10T16:39:47.300143+00:00",
      "worker_processes": []
    },
    "Opt4-fit-svb-tree-r1-state.json": {
      "controller": {},
      "error": "AssertionError(('compile', 1, PosixPath('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-tree-r1-20261111/compile-attempt-1.log')))",
      "hardware_commit": "f2d2ca3ea0b12c918f2ccd2d1131be2709960470",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "Picked up JAVA_TOOL_OPTIONS: \n/data1/gzh/EC/firesim/final-opt4-20261106/candidates/svb-tree-r1-20261111/Emit.scala:59: error: object UnlocatableSourceInfo is not a member of package chisel3.experimental\n      implicit val edge: TLEdgeOut = new TLEdgeOut(client, manager, p, chisel3.experimental.UnlocatableSourceInfo)\n                                                                                            ^\n1 error\n",
      "pid": 1883243,
      "source_id": "f678ac806ea4b0f801596b26ec8bf9ef914a3161b39f92564ac25452abd8eafc",
      "stage_log": {
        "bytes": 420,
        "mtime_ns": 1794356627612305011,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-tree-r1-20261111/compile-attempt-1.log"
      },
      "start_ticks": "16834411",
      "status": "FAILED_WITH_EVIDENCE",
      "updated_utc": "2026-11-11T00:23:47.692668+00:00",
      "worker_processes": []
    },
    "Opt4-fit-svb-tree-r2-state.json": {
      "controller": {},
      "error": "AssertionError(('emit-svb', 1, PosixPath('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-tree-r2-20261111/emit-svb-attempt-1.log')))",
      "hardware_commit": "f2d2ca3ea0b12c918f2ccd2d1131be2709960470",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "Picked up JAVA_TOOL_OPTIONS: \nException in thread \"main\" java.lang.IllegalArgumentException: requirement failed: Key TileVisibilityNodeKey is not defined in Parameters\n\tat ... ()\n\tat chipsalliance.rocketchip.config$View.apply(Config.scala:28)\n\tat chipsalliance.rocketchip.config$View.apply(Config.scala:25)\n\tat freechips.rocketchip.tile.HasTileParameters.tlBundleParams(BaseTile.scala:179)\n\tat freechips.rocketchip.tile.HasTileParameters.tlBundleParams$(BaseTile.scala:179)\n\tat freechips.rocketchip.rocket.L1HellaCacheModule.tlBundleParams(HellaCache.scala:97)\n\tat freechips.rocketchip.tile.HasL1CacheParameters.cacheDataBits(L1Cache.scala:36)\n\tat freechips.rocketchip.tile.HasL1CacheParameters.cacheDataBits$(L1Cache.scala:36)\n\tat freechips.rocketchip.rocket.L1HellaCacheModule.cacheDataBits(HellaCache.scala:97)\n\tat freechips.rocketchip.rocket.HasL1HellaCacheParameters.$init$(HellaCache.scala:92)\n\tat freechips.rocketchip.rocket.L1HellaCacheModule.<init>(HellaCache.scala:97)\n\tat boom.lsu.SpeculativeVersionBuffer.<init>(speculative-version-buffer.scala:48)\n\tat opt4svbtree.Emit$.$anonfun$new$23(Emit.scala:60)\n\tat ... ()\n\tat ... (Stack trace trimmed to user code only. Rerun with --full-stacktrace to see the full stack trace)\n",
      "pid": 1885091,
      "source_id": "f678ac806ea4b0f801596b26ec8bf9ef914a3161b39f92564ac25452abd8eafc",
      "stage_log": {
        "bytes": 1231,
        "mtime_ns": 1794356706333785983,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-tree-r2-20261111/emit-svb-attempt-1.log"
      },
      "start_ticks": "16840668",
      "status": "FAILED_WITH_EVIDENCE",
      "updated_utc": "2026-11-11T00:25:06.395233+00:00",
      "worker_processes": []
    },
    "Opt4-fit-svb-tree-r3-state.json": {
      "controller": {},
      "error": "AssertionError(('emit-svb', 1, PosixPath('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-tree-r3-20261111/emit-svb-attempt-1.log')))",
      "hardware_commit": "f2d2ca3ea0b12c918f2ccd2d1131be2709960470",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "Picked up JAVA_TOOL_OPTIONS: \nException in thread \"main\" java.lang.IllegalArgumentException: requirement failed: rowBits(128) != cacheDataBits(64)\n\tat ... ()\n\tat freechips.rocketchip.rocket.HasL1HellaCacheParameters.$init$(HellaCache.scala:92)\n\tat freechips.rocketchip.rocket.L1HellaCacheModule.<init>(HellaCache.scala:97)\n\tat boom.lsu.SpeculativeVersionBuffer.<init>(speculative-version-buffer.scala:48)\n\tat opt4svbtree.Emit$$anon$2$$anon$3.$anonfun$dut$2(Emit.scala:67)\n\tat chisel3.Module$.do_apply(Module.scala:53)\n\tat opt4svbtree.Emit$$anon$2$$anon$3.$anonfun$dut$1(Emit.scala:67)\n\tat chisel3.internal.plugin.package$.autoNameRecursively(package.scala:33)\n\tat opt4svbtree.Emit$$anon$2$$anon$3.<init>(Emit.scala:67)\n\tat opt4svbtree.Emit$$anon$2.$anonfun$module$1(Emit.scala:64)\n\tat chisel3.internal.plugin.package$.autoNameRecursively(package.scala:33)\n\tat opt4svbtree.Emit$$anon$2.module$lzycompute(Emit.scala:64)\n\tat opt4svbtree.Emit$$anon$2.module(Emit.scala:64)\n\tat opt4svbtree.Emit$$anon$2.module(Emit.scala:59)\n\tat opt4svbtree.Emit$.$anonfun$new$24(Emit.scala:72)\n\tat ... ()\n\tat ... (Stack trace trimmed to user code only. Rerun with --full-stacktrace to see the full stack trace)\n",
      "pid": 1888600,
      "source_id": "f678ac806ea4b0f801596b26ec8bf9ef914a3161b39f92564ac25452abd8eafc",
      "stage_log": {
        "bytes": 1190,
        "mtime_ns": 1794356858108295713,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-tree-r3-20261111/emit-svb-attempt-1.log"
      },
      "start_ticks": "16855853",
      "status": "FAILED_WITH_EVIDENCE",
      "updated_utc": "2026-11-11T00:27:38.147582+00:00",
      "worker_processes": []
    },
    "Opt4-fit-svb-tree-r4-state.json": {
      "controller": {},
      "error": "AssertionError(('emit-svb', 1, PosixPath('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-tree-r4-20261111/emit-svb-attempt-1.log')))",
      "hardware_commit": "f2d2ca3ea0b12c918f2ccd2d1131be2709960470",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "le.vpnBits(types.scala:21)\n\tat freechips.rocketchip.tile.HasTileParameters.vpnBitsExtended(BaseTile.scala:197)\n\tat freechips.rocketchip.tile.HasTileParameters.vpnBitsExtended$(BaseTile.scala:197)\n\tat boom.common.BoomBundle.vpnBitsExtended(types.scala:21)\n\tat freechips.rocketchip.tile.HasTileParameters.vaddrBitsExtended(BaseTile.scala:198)\n\tat freechips.rocketchip.tile.HasTileParameters.vaddrBitsExtended$(BaseTile.scala:198)\n\tat boom.common.BoomBundle.vaddrBitsExtended(types.scala:21)\n\tat freechips.rocketchip.tile.HasCoreParameters.coreMaxAddrBits(Core.scala:107)\n\tat freechips.rocketchip.tile.HasCoreParameters.coreMaxAddrBits$(Core.scala:107)\n\tat boom.common.BoomBundle.coreMaxAddrBits(types.scala:21)\n\tat boom.lsu.SpeculativeVersionSnapshot.$anonfun$line$1(speculative-version-buffer.scala:20)\n\tat chisel3.internal.plugin.package$.autoNameRecursively(package.scala:33)\n\tat boom.lsu.SpeculativeVersionSnapshot.<init>(speculative-version-buffer.scala:20)\n\tat boom.lsu.SpeculativeVersionBuffer$$anon$1.$anonfun$capture$1(speculative-version-buffer.scala:53)\n\tat chisel3.internal.plugin.package$.autoNameRecursively(package.scala:33)\n\tat boom.lsu.SpeculativeVersionBuffer$$anon$1.<init>(speculative-version-buffer.scala:53)\n\tat boom.lsu.SpeculativeVersionBuffer.$anonfun$io$2(speculative-version-buffer.scala:52)\n\tat chisel3.internal.prefix$.apply(prefix.scala:48)\n\tat boom.lsu.SpeculativeVersionBuffer.$anonfun$io$1(speculative-version-buffer.scala:52)\n\tat chisel3.internal.plugin.package$.autoNameRecursively(package.scala:33)\n\tat boom.lsu.SpeculativeVersionBuffer.<init>(speculative-version-buffer.scala:52)\n\tat opt4svbtree.Emit$$anon$2$$anon$3.$anonfun$dut$2(Emit.scala:67)\n\tat chisel3.Module$.do_apply(Module.scala:53)\n\tat opt4svbtree.Emit$$anon$2$$anon$3.$anonfun$dut$1(Emit.scala:67)\n\tat chisel3.internal.plugin.package$.autoNameRecursively(package.scala:33)\n\tat opt4svbtree.Emit$$anon$2$$anon$3.<init>(Emit.scala:67)\n\tat opt4svbtree.Emit$$anon$2.$anonfun$module$1(Emit.scala:64)\n\tat chisel3.internal.plugin.package$.autoNameRecursively(package.scala:33)\n\tat opt4svbtree.Emit$$anon$2.module$lzycompute(Emit.scala:64)\n\tat opt4svbtree.Emit$$anon$2.module(Emit.scala:64)\n\tat opt4svbtree.Emit$$anon$2.module(Emit.scala:59)\n\tat opt4svbtree.Emit$.$anonfun$new$24(Emit.scala:72)\n\tat ... ()\n\tat ... (Stack trace trimmed to user code only. Rerun with --full-stacktrace to see the full stack trace)\n",
      "pid": 1890546,
      "source_id": "f678ac806ea4b0f801596b26ec8bf9ef914a3161b39f92564ac25452abd8eafc",
      "stage_log": {
        "bytes": 2910,
        "mtime_ns": 1794356934473417564,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-tree-r4-20261111/emit-svb-attempt-1.log"
      },
      "start_ticks": "16863514",
      "status": "FAILED_WITH_EVIDENCE",
      "updated_utc": "2026-11-11T00:28:54.520817+00:00",
      "worker_processes": []
    },
    "Opt4-fit-svb-tree-r5-state.json": {
      "controller": {},
      "error": "AssertionError(('sat32', 1, PosixPath('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-tree-r5-20261111/sat32-attempt-1.log')))",
      "hardware_commit": "f2d2ca3ea0b12c918f2ccd2d1131be2709960470",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "_15\nImport show expression: \\io_seq_16\nImport show expression: \\io_seq_17\nImport show expression: \\io_seq_18\nImport show expression: \\io_seq_19\nImport show expression: \\io_seq_2\nImport show expression: \\io_seq_20\nImport show expression: \\io_seq_21\nImport show expression: \\io_seq_22\nImport show expression: \\io_seq_23\nImport show expression: \\io_seq_24\nImport show expression: \\io_seq_25\nImport show expression: \\io_seq_26\nImport show expression: \\io_seq_27\nImport show expression: \\io_seq_28\nImport show expression: \\io_seq_29\nImport show expression: \\io_seq_3\nImport show expression: \\io_seq_30\nImport show expression: \\io_seq_31\nImport show expression: \\io_seq_4\nImport show expression: \\io_seq_5\nImport show expression: \\io_seq_6\nImport show expression: \\io_seq_7\nImport show expression: \\io_seq_8\nImport show expression: \\io_seq_9\nImport show expression: \\io_valid_0\nImport show expression: \\io_valid_1\nImport show expression: \\io_valid_10\nImport show expression: \\io_valid_11\nImport show expression: \\io_valid_12\nImport show expression: \\io_valid_13\nImport show expression: \\io_valid_14\nImport show expression: \\io_valid_15\nImport show expression: \\io_valid_16\nImport show expression: \\io_valid_17\nImport show expression: \\io_valid_18\nImport show expression: \\io_valid_19\nImport show expression: \\io_valid_2\nImport show expression: \\io_valid_20\nImport show expression: \\io_valid_21\nImport show expression: \\io_valid_22\nImport show expression: \\io_valid_23\nImport show expression: \\io_valid_24\nImport show expression: \\io_valid_25\nImport show expression: \\io_valid_26\nImport show expression: \\io_valid_27\nImport show expression: \\io_valid_28\nImport show expression: \\io_valid_29\nImport show expression: \\io_valid_3\nImport show expression: \\io_valid_30\nImport show expression: \\io_valid_31\nImport show expression: \\io_valid_4\nImport show expression: \\io_valid_5\nImport show expression: \\io_valid_6\nImport show expression: \\io_valid_7\nImport show expression: \\io_valid_8\nImport show expression: \\io_valid_9\n\nSolving problem with 732241 variables and 2197485 clauses..\nInterrupted SAT solver: TIMEOUT!\n\n        _____  _  _      _____ ____  _     _____\n       /__ __\\/ \\/ \\__/|/  __//  _ \\/ \\ /\\/__ __\\\n         / \\  | || |\\/|||  \\  | / \\|| | ||  / \\\n         | |  | || |  |||  /_ | \\_/|| \\_/|  | |\n         \\_/  \\_/\\_/  \\|\\____\\\\____/\\____/  \\_/\n\nERROR: Called with -verify and proof did time out!\n",
      "pid": 1892804,
      "source_id": "f678ac806ea4b0f801596b26ec8bf9ef914a3161b39f92564ac25452abd8eafc",
      "stage_log": {
        "bytes": 23609,
        "mtime_ns": 1794357971108093720,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-tree-r5-20261111/sat32-attempt-1.log"
      },
      "start_ticks": "16875697",
      "status": "FAILED_WITH_EVIDENCE",
      "updated_utc": "2026-11-11T00:46:11.198425+00:00",
      "worker_processes": []
    },
    "Opt4-fit-svb-tree-r6-state.json": {
      "controller": {},
      "error": "AssertionError(('compile-vectors', 2, PosixPath('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-tree-r6-20261111/compile-vectors-attempt-1.log')))",
      "hardware_commit": "f2d2ca3ea0b12c918f2ccd2d1131be2709960470",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "rguments -Wno-bool-operation -Wno-c++11-narrowing -Wno-constant-logical-operand -Wno-non-pod-varargs -Wno-parentheses-equality -Wno-shadow -Wno-sign-compare -Wno-tautological-bitwise-compare -Wno-tautological-compare -Wno-uninitialized -Wno-unused-parameter -Wno-unused-variable      -x c++-header VSelectionProbe__pch.h -o VSelectionProbe__pch.h.slow.gch\necho \"\" > VSelectionProbe__ALL.verilator_deplist.tmp\n/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-tree-r6-20261111/vectors.cpp:10:111: error: expected ')'\nif(valid[i]&&(!found||seq[i]>seq[best]||(seq[i]==seq[best]&&(gen[i]>gen[best]||(gen[i]==gen[best]&&i>best)))) {best=i;found=true;}}\n                                                                                                              ^\n/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-tree-r6-20261111/vectors.cpp:10:3: note: to match this '('\nif(valid[i]&&(!found||seq[i]>seq[best]||(seq[i]==seq[best]&&(gen[i]>gen[best]||(gen[i]==gen[best]&&i>best)))) {best=i;found=true;}}\n  ^\n/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-tree-r6-20261111/vectors.cpp:10:131: error: expected statement\nif(valid[i]&&(!found||seq[i]>seq[best]||(seq[i]==seq[best]&&(gen[i]>gen[best]||(gen[i]==gen[best]&&i>best)))) {best=i;found=true;}}\n                                                                                                                                  ^\n2 errors generated.\nmake: *** [VSelectionProbe.mk:63: vectors.o] Error 1\nmake: *** Waiting for unfinished jobs....\nrm VSelectionProbe__ALL.verilator_deplist.tmp\nmake: Leaving directory '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-tree-r6-20261111/obj'\n%Error: make -C /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-tree-r6-20261111/obj -f VSelectionProbe.mk -j 8 exited with 2\n%Error: Command Failed ulimit -s unlimited 2>/dev/null; exec /usr/local/share/verilator/bin/verilator_bin --cc --exe --build -j 8 -Wno-fatal --top-module SelectionProbe --Mdir /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-tree-r6-20261111/obj /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-tree-r6-20261111/proof/SelectionProbe.v /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-tree-r6-20261111/vectors.cpp\n",
      "pid": 1914143,
      "source_id": "f678ac806ea4b0f801596b26ec8bf9ef914a3161b39f92564ac25452abd8eafc",
      "stage_log": {
        "bytes": 5323,
        "mtime_ns": 1794358036120629470,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-tree-r6-20261111/compile-vectors-attempt-1.log"
      },
      "start_ticks": "16972523",
      "status": "FAILED_WITH_EVIDENCE",
      "updated_utc": "2026-11-11T00:47:16.130809+00:00",
      "worker_processes": []
    },
    "Opt4-fit-svb-tree-r7-state.json": {
      "controller": {},
      "hardware_commit": "f2d2ca3ea0b12c918f2ccd2d1131be2709960470",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "elapsed = 00:02:53 . Memory (MB): peak = 3792.387 ; gain = 1285.820 ; free physical = 70006 ; free virtual = 331435\nSynthesis Optimization Complete : Time (s): cpu = 00:02:51 ; elapsed = 00:02:53 . Memory (MB): peak = 3792.387 ; gain = 1285.820 ; free physical = 70013 ; free virtual = 331431\nINFO: [Project 1-571] Translating synthesized netlist\nNetlist sorting complete. Time (s): cpu = 00:00:02 ; elapsed = 00:00:02 . Memory (MB): peak = 3792.387 ; gain = 0.000 ; free physical = 67945 ; free virtual = 329343\nINFO: [Netlist 29-17] Analyzing 29356 Unisim elements for replacement\nINFO: [Netlist 29-28] Unisim Transformation completed in 0 CPU seconds\nWARNING: [Netlist 29-101] Netlist 'SVBModuleHarness' is not ideal for floorplanning, since the cellview 'SpeculativeVersionBuffer' contains a large number of primitives.  Please consider enabling hierarchy in synthesis if you want to do floorplanning.\nINFO: [Project 1-570] Preparing netlist for logic optimization\nINFO: [Opt 31-138] Pushed 0 inverter(s) to 0 load pin(s).\nNetlist sorting complete. Time (s): cpu = 00:00:00.02 ; elapsed = 00:00:00.02 . Memory (MB): peak = 3971.508 ; gain = 0.000 ; free physical = 66210 ; free virtual = 327549\nINFO: [Project 1-111] Unisim Transformation Summary:\nNo Unisim elements were transformed.\n\nSynth Design complete, checksum: 653a41d5\nINFO: [Common 17-83] Releasing license: Synthesis\n94 Infos, 68 Warnings, 0 Critical Warnings and 0 Errors encountered.\nsynth_design completed successfully\nsynth_design: Time (s): cpu = 00:03:21 ; elapsed = 00:03:24 . Memory (MB): peak = 3971.508 ; gain = 1465.074 ; free physical = 67336 ; free virtual = 328675\n# report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-tree-r7-20261111/map-svb/utilization.rpt}\n# write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-tree-r7-20261111/map-svb/module.dcp}\nINFO: [Timing 38-35] Done setting XDC timing constraints.\nINFO: [Common 17-1381] The checkpoint '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-tree-r7-20261111/map-svb/module.dcp' has been generated.\nwrite_checkpoint: Time (s): cpu = 00:00:49 ; elapsed = 00:00:31 . Memory (MB): peak = 4312.863 ; gain = 341.355 ; free physical = 63753 ; free virtual = 326660\n# exit 0\nINFO: [Common 17-206] Exiting Vivado at Wed Nov 11 08:58:09 2026...\n",
      "pid": 1922848,
      "source_id": "f678ac806ea4b0f801596b26ec8bf9ef914a3161b39f92564ac25452abd8eafc",
      "stage_log": {
        "bytes": 43863,
        "mtime_ns": 1794358689761686661,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-tree-r7-20261111/map-svb-attempt-1.log"
      },
      "start_ticks": "16998349",
      "status": "VERIFIED_SELECTION_SUBSTITUTION_AND_MAPPED_NOT_WHOLE_DUT_ADMITTED",
      "updated_utc": "2026-11-11T00:58:14.412682+00:00",
      "worker_processes": []
    },
    "Opt4-svb-invalidation-validation-r1-state.json": {
      "controller": {},
      "error": "AssertionError('compile failed')",
      "hardware_commit": "f2d2ca3ea0b12c918f2ccd2d1131be2709960470",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "pid": 1913610,
      "source_id": "f678ac806ea4b0f801596b26ec8bf9ef914a3161b39f92564ac25452abd8eafc",
      "start_ticks": "16970839",
      "status": "FAILED_WITH_EVIDENCE",
      "worker_processes": []
    },
    "active-0000_21_00.0.json": {
      "controller": {},
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "pid": 2853651,
      "start_ticks": "12041108",
      "status": "COMPLETE",
      "updated_utc": "2026-11-10T12:47:55.884321+00:00",
      "worker_processes": []
    }
  },
  "utc": "2026-11-11T01:05:48.627207+00:00"
}

Previous round directories: /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/unattended-opt4/rounds
