# Sole objective: frozen-equivalent Opt4 area implementation and real FPGA experiments

The latest explicit user instruction supersedes ALL earlier architectural recovery
approvals, contracts and prompts. Read U/campaign-policy.json before every action.
The ONLY functional baseline is final Opt4 commit
8491167d84b6d9521b151a743673c1516926a1f8, v1Config, C4, SVB32,
L2 report-permission repair. Preserve every existing EC, checker, fault handling,
rollback, drain, instrumentation and cycle-semantic behavior of that exact version.
All RTL changes must be functionally AND cycle-equivalent area optimizations.
No new architecture, new recovery, changed experiment parameters or reduced checks.

W=/data1/gzh/EC/firesim/final-opt4-20261106
D=/data1/gzh/EC/Experiment/firesim-final-opt4-20261106
U=D/unattended-opt4
Artifacts, logs, candidate commits, failures and raw results are immutable evidence.
Do not modify frozen tag/source, other sessions, or live task inputs.

## Stop the revoked functional branch

Independent architectural-recovery a4477d72, e4a9d517, 24633f1a and descendants
are preserved ONLY. Do not develop, validate, merge, synthesize, deploy or make
them an admission/success prerequisite. No PackageRecoveryController/State/Memory
or other new feature may enter the area branch. All old recovery decision files
are historical and revoked; lack of a new full architectural rollback interface
must not block original-scheme bitstream or experiments. Validate only behavior
already present in frozen Opt4; document limits honestly without extending it.

## Actual current implementation and capacity evidence

KEEP 9ae9a7fcf231a75259e23973b12a93896a443cbb whole DUT synthesis alive.
W/Opt4-fit-address-bucket-tag-r3-20261111; source ID
3791dd0e8f7d9c380500cd37f11ece4c92e275bc399894780228fa61449df561.
State D/Opt4-fit-bucket-tag-cad-state.json, service
ec-opt4-auto-bucket-tag-cad-r1-9ae9a7fc.service. Do not duplicate or restart.
It is still DUT synthesis: latest complete whole resource report is predecessor
8da24a26 post-opt: 3,215,683 LUT / 92,789 CARRY8 / 195 DSP,
U280 limits 1,303,680 / 162,960 / 9,024. NOT FIT, LUT excess 1,912,003.
This predecessor completed and naturally stopped before placement; preserve it.
Do not call 9ae FIT until its actual report exists. Even eliminating predecessor
address stats completely still leaves about646,512 LUT excess: optimize MSHRFile,
BOOM/L2 memories/dynamic indexing and repeated wide mux/reduction logic as well.

The live build already reuses11 shell IP DCPs, skips irrelevant functional
netlist export, does real top link/zero blackbox/opt capacity gate and then
place/route/timing/DRC/bitstream. FIT -> advance immediately, no extra area work.
NOT FIT -> preserve actual reports, rank inclusive hierarchy without double
counting and integrate largest VERIFIED gains on an independent next commit.
Module/composed equivalence, real-size reset/overflow and frozen full-module
cycle comparisons are required before expensive whole admission. A proof timeout
or one failed candidate never stops the iteration. Do not repeat no-gain whole
syntheses or stack candidates without composed verification. One whole DUT
synthesis at a time; do not interrupt effective CAD for log silence alone.

## Current useful area-only candidates and evidence

9ae complete address module measured990,905 LUT. Newly completed00847dc2
(address-update-share-r2) is VERIFIED_AND_MAPPED_MODULE_ONLY:872,880 LUT,
30,842 CARRY8,384,373 FF,216 BRAM,0 DSP. That is118,025 LUT (11.91%)
less than9ae address, not a measured whole-system saving. Prior990,230 candidate
is now superseded in ranking. Inspect exact source-bound proof and full-module
comparison receipts; prepare a composition with proven f2 SVB on a separate
commit, perform combined verification and early RTL/runtime preparation while
current9ae synthesis continues. After9ae actual NOT FIT, use real reports and
verified composed candidates for the next whole build; continue substantial
MSHRFile/BOOM/L2 storage optimization to close the remaining million-LUT gap.
Read latest actual module rankings and states, never estimated local savings.
The f2d2ca3e SVB selector composition is an AREA-ONLY child of9ae, not the revoked
recovery extension: source-bound combined proof, full127-output/4096-cycle actual
SVB comparison, frozen parameter/class-origin checks and GoldenGate passed.
D/Opt4-fit-svb-system-r2-state.json; W/candidates/svb-tree-cad-r1-20261111/build.py.
Do not launch another whole solely for its small selector gain against a large
gap; combine only with materially larger verified equivalent candidates.
51a2bd25 result-memory storage proof uses actual256 sets x2 ways,512 entries,
2R1W async storage: proof-r4 passed local SAT/mutation/8192-cycle and DCache
typecheck. Full frozen DCache comparison is still required; no whole admission.
Adopt latest mapping continuation receipts, do not resurrect superseded jobs.
27f7e7d6 replicated sequence and c4b5820d barrier event-read candidates need
actual complete-module/map evidence. Existing controller/child identity wins;
never launch a duplicate because a summary says a job is not running.

## Persistent CPU broker and recovery

This round is one worker of the existing SSH-independent systemd supervisor.
Do not spawn other AI agents or nested Codex sessions. Do useful RTL/proof/map/
composed-build preparation each round, not just a status plan.
Normal queries >=300 seconds, whole builds >=600 where practical. Use existing
snapshot/state/exit receipts and incremental log tails; do not rescan /proc or
recompute large hashes repeatedly. Continuous logging is done by controllers.
Adopt live PID+start_ticks+boot_id (including child). Resume exact successful
stage outputs after confirmed exit only. Preserve failure evidence and use a
versioned recovery controller; never blind-retry or overwrite a partial stage.
Bound input hashes and retain source/config/generated RTL/software/result IDs.

Write versioned controllers under W and submit atomic U/requests/<unique>.json:
{"action":"cpu_job","spec":{"name":"unique-lowercase-version",
"kind":"proof|module|rtl|cad|analysis","cwd":"absolute path under W",
"argv":["/usr/bin/python3","/absolute/versioned/controller.py"],
"inputs":{"/absolute/controller.py":"sha256","actual source/config":"sha256"},
"outputs":["absolute final receipt"],"checkpoints":["absolute state"]}}
Use ONE kind. CPU jobs are independent enabled systemd services. Check request
receipt STARTED/ADOPTED and actual PID; DEFERRED is only queued. Eight ordinary
jobs; up to two light proof/analysis/RTL auxiliaries only with >=256GiB available
and load<96. Whole >=96GiB memory/150GiB disk; module >=48GiB/40GiB. Retain single
whole synthesis rule. Do not lower guards or oversubscribe. Preserve live scripts,
supervisor, launcher, driver safety and other sessions. Safe tool fixes use new
versioned scripts and verified checkpoints. A new scope policy must be obeyed.

## Certification and real experiments

Native and unrelated software remain PAUSED. 13 ordinary PARSEC exact-paired
software already prepared in runtime/Opt4-fit-9ae9a7fc/software-suite.json.
Use the same Native ELF/input/thread/ROI, including fluidanimate-stable-formal.
Do not rebuild or replace valid software unnecessarily or lower output/checker
requirements. Formal r1 coverage first, then r2/r3; skip app-specific failure.

Only 0000:21:00.0 / 21770433G02LA. Never touch e2, global driver/reload/reset/
rescan, enumeratefpgas, reboot or firmware. No FPGA I/O from the AI worker.
Only existing certified runtime services started through the broker may deploy,
at a safe boundary without another task on21. Source/ABI/timing/DRC/capacity and
bitstream binding must actually pass. Existing native service must stay paused.

W/runtime-candidates/<commit-prefix>.json pins commit, source_id, profile,
worktree, cad_state, rtl_state, state_prefix, BDF and serial. Submit existing
prepare_runtime then start_runtime requests; latter remains DEFERRED until true
certification. Reuse driver ONLY if all7 real generated ABI files match exactly;
otherwise rebuild driver and make a separate source-bound receipt. Never alter
receipts to fake compatibility. Equivalent original-scheme smoke/checker/drain/
correct output first, then13 ordinary PARSEC r1. Atomic results with complete
version/hash binding. No new functional recovery implementation gate.

Runtime unavailability, NOT FIT, failed proof, physical implementation failure,
software limit or transport outage NEVER stop the area iteration. Save evidence,
try another equivalent approach, continue. On certified FIT stop unnecessary
optimization and prioritize implementation/deployment. Only a real valid formal
Opt4 FPGA sample satisfies success; services/submitted jobs are not results.

Preserve original stdout/stderr, checkpoint manifests and candidate versions.
Do not inspect or print credentials. The configured provider transport is owned
by the existing launcher; report external outages and keep independent CAD jobs
running. Finish each round with schema-compliant JSON and actual changed files,
proof/map evidence, launched jobs and a concrete next safe action.


This is round 21. Latest durable snapshot:
{
  "available_memory_gib": 375.6,
  "board_allowlist": [
    "0000:21:00.0"
  ],
  "free_disk_gib": 372.79,
  "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
  "loadavg": "35.46 39.43 42.23 41/27990 2315833",
  "schema": "ec-opt4-unattended-snapshot/1",
  "states": {
    "Opt4-architectural-recovery-control-r3-state.json": {
      "controller": {},
      "hardware_commit": "24633f1a0333e9515a5b38dcfb38d4b23ca09082",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "RECOVERY_CONTROL_COMPONENT_PASS positive_transactions=64 negative_cases=10 accepted_command_is_not_completion=1 frozen_checkpoint_tokens=1 real_response_event_order=1 not_architectural_recovery=1\n",
      "pid": 2089395,
      "source_id": "c2cb9e37c8252c87e3f3d0252f093ddf88171fd7be4c205af25cd837d7ae7904",
      "stage_log": {
        "bytes": 196,
        "mtime_ns": 1794363663693763189,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-architectural-recovery-control-r3-20261111/test.log"
      },
      "start_ticks": "17537522",
      "status": "PASS_INITIAL_CONTROL_COMPONENT_NOT_FULL_ARCHITECTURAL_RECOVERY",
      "updated_utc": "2026-11-11T02:21:03.730547+00:00",
      "worker_processes": []
    },
    "Opt4-architectural-recovery-r1-state.json": {
      "controller": {},
      "hardware_commit": "a4477d7241d80826f5d47a679fa05a2571d413c7",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "RECOVERY_CONTROL_COMPONENT_PASS positive_transactions=64 negative_cases=10 accepted_command_is_not_completion=1 frozen_checkpoint_tokens=1 real_response_event_order=1 not_architectural_recovery=1\n",
      "pid": 2034045,
      "source_id": "0078dfc1a5e18f456ebb820c68ca1cbbc7bd7b36a4a3fe850b91b9118b978c4e",
      "stage_log": {
        "bytes": 196,
        "mtime_ns": 1794362066035642085,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-architectural-recovery-r1-20261111/test.log"
      },
      "start_ticks": "17377725",
      "status": "PASS_INITIAL_CONTROL_COMPONENT_NOT_FULL_ARCHITECTURAL_RECOVERY",
      "updated_utc": "2026-11-11T01:54:26.068949+00:00",
      "worker_processes": []
    },
    "Opt4-architectural-recovery-state-r2-state.json": {
      "controller": {},
      "hardware_commit": "e4a9d5177673f097ed07adf7579c59b6d75fda88",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "RECOVERY_MEMORY_PASS reverse_transactions=16 records_per_transaction=64 masked_overlap=1 cursor_ring_wrap=1 ownership_until_ack=1 negative_cases=24 real_cache_integration=0\n",
      "pid": 2073290,
      "source_id": "e19f50ac36ce1dad6b88f7379e710422cb530492e50ed8b28dbdeac71a918679",
      "stage_log": {
        "bytes": 173,
        "mtime_ns": 1794363262642690256,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-architectural-recovery-state-r2-20261111/test-memory.log"
      },
      "start_ticks": "17496572",
      "status": "PASS_RECOVERY_BACKEND_COMPONENTS_NOT_DUT_INTEGRATED",
      "updated_utc": "2026-11-11T02:14:22.674162+00:00",
      "worker_processes": []
    },
    "Opt4-architectural-recovery-state-r3-state.json": {
      "controller": {},
      "hardware_commit": "24633f1a0333e9515a5b38dcfb38d4b23ca09082",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "RECOVERY_MEMORY_PASS reverse_transactions=16 records_per_transaction=64 masked_overlap=1 cursor_ring_wrap=1 ownership_until_ack=1 negative_cases=27 real_cache_integration=0\n",
      "pid": 2080618,
      "source_id": "c2cb9e37c8252c87e3f3d0252f093ddf88171fd7be4c205af25cd837d7ae7904",
      "stage_log": {
        "bytes": 173,
        "mtime_ns": 1794363459694487545,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-architectural-recovery-state-r3-20261111/test-memory.log"
      },
      "start_ticks": "17516293",
      "status": "PASS_RECOVERY_BACKEND_COMPONENTS_NOT_DUT_INTEGRATED",
      "updated_utc": "2026-11-11T02:17:39.727945+00:00",
      "worker_processes": []
    },
    "Opt4-fit-address-async-current-r1-state.json": {
      "controller": {},
      "full_module_map": {
        "checkpoint": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-async-current-r1-20261111/map-full-module/module.dcp",
        "report": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-async-current-r1-20261111/map-full-module/utilization.rpt",
        "report_sha256": "b1e425a0f7b43489e225d82f5e19c99c2b0fffef515a5f29560438fae6d77c25",
        "resources": {
          "Block RAM Tile": 216.0,
          "CARRY8": 55418.0,
          "CLB LUTs": 935433.0,
          "CLB Registers": 256273.0,
          "DSPs": 0.0
        },
        "rtl_sha256": "1497cc2d726b2583a4da95d43d3309cdecb2ef8999b182ba31a8b07e1bfe8735",
        "scope": "OOC only; not whole-DUT FIT",
        "tcl_sha256": "0526b411f413391eb19b0a3300fc320edf7ec3cd2406d06102668932d132e615"
      },
      "hardware_commit": "c61d0b2a431451ca70093dcf6eeaed5945fc2ec1",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "ee virtual = 349333\nINFO: [Netlist 29-17] Analyzing 215305 Unisim elements for replacement\nINFO: [Netlist 29-28] Unisim Transformation completed in 4 CPU seconds\nINFO: [Project 1-570] Preparing netlist for logic optimization\nINFO: [Opt 31-138] Pushed 0 inverter(s) to 0 load pin(s).\nNetlist sorting complete. Time (s): cpu = 00:00:00.27 ; elapsed = 00:00:00.28 . Memory (MB): peak = 10876.367 ; gain = 0.000 ; free physical = 81332 ; free virtual = 342372\nINFO: [Project 1-111] Unisim Transformation Summary:\n  A total of 512 instances were transformed.\n  RAM256X1D => RAM256X1D (MUXF7(x4), MUXF8(x2), RAMD64E(x8)): 512 instances\n\nSynth Design complete, checksum: e55b59f0\nINFO: [Common 17-83] Releasing license: Synthesis\n483 Infos, 0 Warnings, 0 Critical Warnings and 0 Errors encountered.\nsynth_design completed successfully\nsynth_design: Time (s): cpu = 01:52:09 ; elapsed = 01:55:47 . Memory (MB): peak = 10876.367 ; gain = 8378.926 ; free physical = 80376 ; free virtual = 341485\nINFO: [Common 17-600] The following parameters have non-default value.\ngeneral.maxThreads\n# report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-async-current-r1-20261111/map-full-module/utilization.rpt}\nreport_utilization: Time (s): cpu = 00:00:07 ; elapsed = 00:00:07 . Memory (MB): peak = 10876.367 ; gain = 0.000 ; free physical = 83832 ; free virtual = 343774\n# report_utilization -hierarchical -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-async-current-r1-20261111/map-full-module/hierarchical.rpt}\nreport_utilization: Time (s): cpu = 00:00:10 ; elapsed = 00:00:10 . Memory (MB): peak = 10876.367 ; gain = 0.000 ; free physical = 86217 ; free virtual = 346162\n# write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-async-current-r1-20261111/map-full-module/module.dcp}\nINFO: [Timing 38-35] Done setting XDC timing constraints.\nINFO: [Common 17-1381] The checkpoint '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-async-current-r1-20261111/map-full-module/module.dcp' has been generated.\nwrite_checkpoint: Time (s): cpu = 00:04:20 ; elapsed = 00:03:07 . Memory (MB): peak = 10948.402 ; gain = 72.035 ; free physical = 79690 ; free virtual = 340118\n# exit 0\nINFO: [Common 17-206] Exiting Vivado at Wed Nov 11 10:35:39 2026...\n",
      "pid": 1893386,
      "source_id": "10e7dc799c504012de1f3f5adf1e34dd494ae1de6e40751cf37dac56991a860c",
      "stage_log": {
        "bytes": 235409,
        "mtime_ns": 1794364539636243244,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-async-current-r1-20261111/map-full-module/map-full-module-attempt-1.log"
      },
      "stage_process": {},
      "start_ticks": "16878859",
      "status": "VERIFIED_AND_MAPPED_MODULE_ONLY",
      "updated_utc": "2026-11-11T02:35:44.890989+00:00",
      "worker_processes": []
    },
    "Opt4-fit-address-async-sequence-r1-state.json": {
      "controller": {},
      "full_module_map": {
        "checkpoint": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-async-sequence-r1-20261111/map-full-module/module.dcp",
        "report": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-async-sequence-r1-20261111/map-full-module/utilization.rpt",
        "report_sha256": "fc8a1a7f6fdc8f3906900c8b8bcefdb2be72275a9bbd6fb1d89efcfc7cb14400",
        "resources": {
          "Block RAM Tile": 216.0,
          "CARRY8": 55418.0,
          "CLB LUTs": 977167.0,
          "CLB Registers": 386244.0,
          "DSPs": 0.0
        },
        "rtl_sha256": "edfedd8fdaf366047c91cdef37e5ec9e4aa594a3ddb4dba37765605213d433b8",
        "scope": "OOC only; not whole-DUT FIT",
        "tcl_sha256": "15c012c2b0d4fa33183df8c2b7540e5f59135c97867166320adcfc1b5b83503b"
      },
      "hardware_commit": "94b749cf20b50487d82c7378071250fa9bd5eb3b",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "0:22 . Memory (MB): peak = 10677.219 ; gain = 0.000 ; free physical = 69091 ; free virtual = 323780\nINFO: [Netlist 29-17] Analyzing 267009 Unisim elements for replacement\nINFO: [Netlist 29-28] Unisim Transformation completed in 4 CPU seconds\nINFO: [Project 1-570] Preparing netlist for logic optimization\nINFO: [Opt 31-138] Pushed 0 inverter(s) to 0 load pin(s).\nNetlist sorting complete. Time (s): cpu = 00:00:00.34 ; elapsed = 00:00:00.34 . Memory (MB): peak = 10689.316 ; gain = 0.000 ; free physical = 39158 ; free virtual = 297241\nINFO: [Project 1-111] Unisim Transformation Summary:\nNo Unisim elements were transformed.\n\nSynth Design complete, checksum: 902cf02e\nINFO: [Common 17-83] Releasing license: Synthesis\n485 Infos, 0 Warnings, 0 Critical Warnings and 0 Errors encountered.\nsynth_design completed successfully\nsynth_design: Time (s): cpu = 02:01:33 ; elapsed = 02:05:34 . Memory (MB): peak = 10689.316 ; gain = 8187.879 ; free physical = 39384 ; free virtual = 297468\nINFO: [Common 17-600] The following parameters have non-default value.\ngeneral.maxThreads\n# report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-async-sequence-r1-20261111/map-full-module/utilization.rpt}\nreport_utilization: Time (s): cpu = 00:00:09 ; elapsed = 00:00:09 . Memory (MB): peak = 10689.316 ; gain = 0.000 ; free physical = 37754 ; free virtual = 295838\n# report_utilization -hierarchical -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-async-sequence-r1-20261111/map-full-module/hierarchical.rpt}\nreport_utilization: Time (s): cpu = 00:00:13 ; elapsed = 00:00:14 . Memory (MB): peak = 10689.316 ; gain = 0.000 ; free physical = 35593 ; free virtual = 293679\n# write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-async-sequence-r1-20261111/map-full-module/module.dcp}\nINFO: [Timing 38-35] Done setting XDC timing constraints.\nINFO: [Common 17-1381] The checkpoint '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-async-sequence-r1-20261111/map-full-module/module.dcp' has been generated.\nwrite_checkpoint: Time (s): cpu = 00:05:04 ; elapsed = 00:03:38 . Memory (MB): peak = 10761.352 ; gain = 72.035 ; free physical = 51722 ; free virtual = 310000\n# exit 0\nINFO: [Common 17-206] Exiting Vivado at Wed Nov 11 11:17:17 2026...\n",
      "pid": 1945040,
      "source_id": "a22e245c0631d0aabb52cbddf1d254a735541dc51279ca9638e841695851da94",
      "stage_log": {
        "bytes": 233226,
        "mtime_ns": 1794367037012391974,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-async-sequence-r1-20261111/map-full-module/map-full-module-attempt-1.log"
      },
      "stage_process": {},
      "start_ticks": "17042597",
      "status": "VERIFIED_AND_MAPPED_MODULE_ONLY",
      "updated_utc": "2026-11-11T03:17:22.600803+00:00",
      "worker_processes": []
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
    "Opt4-fit-address-dsp-counter-bank-r1-state.json": {
      "controller": {},
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "3159.801 ; gain = 660.230 ; free physical = 56166 ; free virtual = 311271\nSynthesis Optimization Complete : Time (s): cpu = 00:00:13 ; elapsed = 00:00:16 . Memory (MB): peak = 3159.809 ; gain = 660.230 ; free physical = 56165 ; free virtual = 311270\nINFO: [Project 1-571] Translating synthesized netlist\nNetlist sorting complete. Time (s): cpu = 00:00:00.05 ; elapsed = 00:00:00.06 . Memory (MB): peak = 3159.809 ; gain = 0.000 ; free physical = 56119 ; free virtual = 311224\nINFO: [Netlist 29-17] Analyzing 256 Unisim elements for replacement\nINFO: [Netlist 29-28] Unisim Transformation completed in 0 CPU seconds\nINFO: [Project 1-570] Preparing netlist for logic optimization\nINFO: [Opt 31-138] Pushed 0 inverter(s) to 0 load pin(s).\nNetlist sorting complete. Time (s): cpu = 00:00:00 ; elapsed = 00:00:00 . Memory (MB): peak = 3274.395 ; gain = 0.000 ; free physical = 55769 ; free virtual = 310874\nINFO: [Project 1-111] Unisim Transformation Summary:\n  A total of 64 instances were transformed.\n  DSP48E2 => DSP48E2 (DSP_ALU, DSP_A_B_DATA, DSP_C_DATA, DSP_MULTIPLIER, DSP_M_DATA, DSP_OUTPUT, DSP_PREADD, DSP_PREADD_DATA): 64 instances\n\nSynth Design complete, checksum: 8ff6b78e\nINFO: [Common 17-83] Releasing license: Synthesis\n17 Infos, 0 Warnings, 0 Critical Warnings and 0 Errors encountered.\nsynth_design completed successfully\nsynth_design: Time (s): cpu = 00:00:20 ; elapsed = 00:00:20 . Memory (MB): peak = 3274.395 ; gain = 774.957 ; free physical = 55900 ; free virtual = 311005\nINFO: [Common 17-600] The following parameters have non-default value.\ngeneral.maxThreads\n# report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-dsp-counter-bank-r1-20261111/candidate/utilization.rpt}\n# write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-dsp-counter-bank-r1-20261111/candidate/module.dcp}\nINFO: [Timing 38-35] Done setting XDC timing constraints.\nINFO: [Common 17-1381] The checkpoint '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-dsp-counter-bank-r1-20261111/candidate/module.dcp' has been generated.\n# write_verilog -force -mode funcsim {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-dsp-counter-bank-r1-20261111/candidate/mapped.v}\n# exit 0\nINFO: [Common 17-206] Exiting Vivado at Wed Nov 11 11:19:39 2026...\n",
      "pid": 2243917,
      "stage_log": {
        "bytes": 37716,
        "mtime_ns": 1794367179094621346,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-dsp-counter-bank-r1-20261111/map-candidate.log"
      },
      "start_ticks": "17883254",
      "status": "PROVEN_AND_PAIRED_MAPPED_LOCAL_ARITHMETIC_NOT_INTEGRATED",
      "updated_utc": "2026-11-11T03:19:43.593955+00:00",
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
        "cpu_ticks": 856,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 1635055,
        "process_state": "S",
        "rss_bytes": 19628032,
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
        "mtime_ns": 1794360529419204208,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-group8-cec-r1-20261111/cec/cec-g1-attempt-1.log"
      },
      "stage_process": {
        "cpu_ticks": 797192,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 1989196,
        "process_state": "R",
        "rss_bytes": 123977728,
        "start_ticks": "17224985"
      },
      "start_ticks": "16366140",
      "status": "RUNNING_CEC-G1",
      "updated_utc": "2026-11-11T03:41:30.407248+00:00",
      "worker_processes": [
        {
          "comm": "yosys-abc",
          "cpu_ticks": 797192,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 0,
            "rchar": 211494,
            "read_bytes": 0,
            "syscr": 31,
            "syscw": 0,
            "wchar": 0,
            "write_bytes": 0
          },
          "pid": 1989196,
          "process_state": "R",
          "rss_bytes": 123977728,
          "start_ticks": "17224985"
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
    "Opt4-fit-address-packed-reduction-r1-state.json": {
      "controller": {},
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": ": peak = 3160.801 ; gain = 676.230 ; free physical = 17406 ; free virtual = 277986\nSynthesis Optimization Complete : Time (s): cpu = 00:00:12 ; elapsed = 00:00:15 . Memory (MB): peak = 3160.809 ; gain = 676.230 ; free physical = 17400 ; free virtual = 277980\nINFO: [Project 1-571] Translating synthesized netlist\nNetlist sorting complete. Time (s): cpu = 00:00:00 ; elapsed = 00:00:00 . Memory (MB): peak = 3160.809 ; gain = 0.000 ; free physical = 17472 ; free virtual = 278052\nINFO: [Netlist 29-17] Analyzing 46 Unisim elements for replacement\nINFO: [Netlist 29-28] Unisim Transformation completed in 0 CPU seconds\nINFO: [Project 1-570] Preparing netlist for logic optimization\nINFO: [Opt 31-138] Pushed 0 inverter(s) to 0 load pin(s).\nNetlist sorting complete. Time (s): cpu = 00:00:00 ; elapsed = 00:00:00 . Memory (MB): peak = 3250.523 ; gain = 0.000 ; free physical = 17444 ; free virtual = 278024\nINFO: [Project 1-111] Unisim Transformation Summary:\n  A total of 1 instances were transformed.\n  DSP48E2 => DSP48E2 (DSP_ALU, DSP_A_B_DATA, DSP_C_DATA, DSP_MULTIPLIER, DSP_M_DATA, DSP_OUTPUT, DSP_PREADD, DSP_PREADD_DATA): 1 instance \n\nSynth Design complete, checksum: 4dd2abad\nINFO: [Common 17-83] Releasing license: Synthesis\n15 Infos, 0 Warnings, 0 Critical Warnings and 0 Errors encountered.\nsynth_design completed successfully\nsynth_design: Time (s): cpu = 00:00:19 ; elapsed = 00:00:18 . Memory (MB): peak = 3250.523 ; gain = 766.086 ; free physical = 17580 ; free virtual = 278159\nINFO: [Common 17-600] The following parameters have non-default value.\ngeneral.maxThreads\n# report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-packed-reduction-r1-20261111/candidate/utilization.rpt}\n# write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-packed-reduction-r1-20261111/candidate/module.dcp}\nINFO: [Timing 38-35] Done setting XDC timing constraints.\nINFO: [Common 17-1381] The checkpoint '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-packed-reduction-r1-20261111/candidate/module.dcp' has been generated.\n# write_verilog -force -mode funcsim {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-packed-reduction-r1-20261111/candidate/mapped.v}\n# exit 0\nINFO: [Common 17-206] Exiting Vivado at Wed Nov 11 11:28:48 2026...\n",
      "pid": 2274392,
      "stage_log": {
        "bytes": 15321,
        "mtime_ns": 1794367728931856879,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-packed-reduction-r1-20261111/map-candidate.log"
      },
      "start_ticks": "17937651",
      "status": "PROVEN_AND_PAIRED_MAPPED_LOCAL_ARITHMETIC_NOT_INTEGRATED",
      "updated_utc": "2026-11-11T03:28:53.235477+00:00",
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
    "Opt4-fit-address-sequence-replicated-map-r1-state.json": {
      "controller": {
        "cpu_ticks": 418,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 2040627,
        "process_state": "S",
        "rss_bytes": 17133568,
        "start_ticks": "17407846"
      },
      "hardware_commit": "27f7e7d6d043d2c5e3dff7551fdb0487e5775580",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": true,
      "log_tail": "|\n|28    |    replica_31         |AddressBucketSequenceReplica_24 |      99|\n|29    |    replica_32         |AddressBucketSequenceReplica_25 |      99|\n|30    |    replica_33         |AddressBucketSequenceReplica_26 |   10042|\n|31    |    replica_34         |AddressBucketSequenceReplica_27 |      99|\n|32    |    replica_35         |AddressBucketSequenceReplica_28 |     101|\n|33    |    replica_36         |AddressBucketSequenceReplica_29 |      99|\n|34    |    replica_37         |AddressBucketSequenceReplica_30 |      99|\n|35    |    replica_38         |AddressBucketSequenceReplica_31 |      99|\n|36    |    replica_39         |AddressBucketSequenceReplica_32 |     101|\n|37    |    replica_4          |AddressBucketSequenceReplica_33 |      99|\n|38    |    replica_40         |AddressBucketSequenceReplica_34 |      99|\n|39    |    replica_41         |AddressBucketSequenceReplica_35 |      99|\n|40    |    replica_42         |AddressBucketSequenceReplica_36 |      99|\n|41    |    replica_43         |AddressBucketSequenceReplica_37 |      99|\n|42    |    replica_44         |AddressBucketSequenceReplica_38 |   21946|\n|43    |    replica_5          |AddressBucketSequenceReplica_39 |      99|\n|44    |    replica_6          |AddressBucketSequenceReplica_40 |      99|\n|45    |    replica_7          |AddressBucketSequenceReplica_41 |      99|\n|46    |    replica_8          |AddressBucketSequenceReplica_42 |      99|\n|47    |    replica_9          |AddressBucketSequenceReplica_43 |      99|\n+------+-----------------------+--------------------------------+--------+\n---------------------------------------------------------------------------------\nFinished Writing Synthesis Report : Time (s): cpu = 01:27:32 ; elapsed = 01:31:10 . Memory (MB): peak = 10463.758 ; gain = 7967.215 ; free physical = 51577 ; free virtual = 313443\n---------------------------------------------------------------------------------\nSynthesis finished with 0 errors, 0 critical warnings and 0 warnings.\nSynthesis Optimization Runtime : Time (s): cpu = 01:27:36 ; elapsed = 01:31:16 . Memory (MB): peak = 10467.668 ; gain = 7971.125 ; free physical = 93936 ; free virtual = 355941\nSynthesis Optimization Complete : Time (s): cpu = 01:27:36 ; elapsed = 01:31:16 . Memory (MB): peak = 10467.668 ; gain = 7971.125 ; free physical = 94089 ; free virtual = 355973\nINFO: [Project 1-571] Translating synthesized netlist\n",
      "pid": 2040627,
      "source_id": "96369486ff5e2c163787b4ce71f5e3d0344346f2b7fb1077d37176ff230bbcdf",
      "stage_log": {
        "bytes": 247309,
        "mtime_ns": 1794368152043946605,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-sequence-replicated-r1-20261111/map-full-module/map-full-module-attempt-1.log"
      },
      "stage_process": {
        "cpu_ticks": 0,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 2049883,
        "process_state": "S",
        "rss_bytes": 4030464,
        "start_ticks": "17438107"
      },
      "start_ticks": "17407846",
      "status": "RUNNING_MAP-FULL-MODULE",
      "updated_utc": "2026-11-11T03:41:21.184778+00:00",
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
            "wchar": 351,
            "write_bytes": 0
          },
          "pid": 2049883,
          "process_state": "S",
          "rss_bytes": 4030464,
          "start_ticks": "17438107"
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
          "pid": 2049899,
          "process_state": "S",
          "rss_bytes": 3923968,
          "start_ticks": "17438110"
        },
        {
          "comm": "vivado",
          "cpu_ticks": 579686,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 2767089664,
            "rchar": 7364203727,
            "read_bytes": 0,
            "syscr": 884876,
            "syscw": 2342132,
            "wchar": 9280562067,
            "write_bytes": 9281822720
          },
          "pid": 2049919,
          "process_state": "S",
          "rss_bytes": 6796152832,
          "start_ticks": "17438119"
        }
      ]
    },
    "Opt4-fit-address-sequence-replicated-proof-r2-state.json": {
      "controller": {},
      "hardware_commit": "27f7e7d6d043d2c5e3dff7551fdb0487e5775580",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "SEQUENCE_ACTUAL_SIZE_PASS vectors=8192 slots=256 bits=32 readers=90 same=107857 reset_write=55 disabled=1984 clockless=8192\n",
      "pid": 2001848,
      "source_id": "96369486ff5e2c163787b4ce71f5e3d0344346f2b7fb1077d37176ff230bbcdf",
      "stage_log": {
        "bytes": 124,
        "mtime_ns": 1794361000279782180,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-sequence-replicated-r1-20261111/boundary/boundary-run-attempt-1.log"
      },
      "stage_process": {},
      "start_ticks": "17271836",
      "status": "VERIFIED_LOCAL_REPLICATED_TOPOLOGY_AND_BOUNDARY_FULL_MODULE_COMPARISON_PENDING",
      "updated_utc": "2026-11-11T01:36:40.295123+00:00",
      "worker_processes": []
    },
    "Opt4-fit-address-sequence-replicated-r1-state.json": {
      "controller": {},
      "error": "KeyError('reset')",
      "hardware_commit": "27f7e7d6d043d2c5e3dff7551fdb0487e5775580",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "gister for signal `\\AddressBucketSequenceReplica.$memwr$\\payload$/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-sequence-replicated-r1-20261111/memory/AddressBucketSequenceMemory.v:39$1_ADDR' using process `\\AddressBucketSequenceReplica.$proc$/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-sequence-replicated-r1-20261111/memory/AddressBucketSequenceMemory.v:37$4'.\n  created $dff cell `$procdff$21' with positive edge clock.\nCreating register for signal `\\AddressBucketSequenceReplica.$memwr$\\payload$/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-sequence-replicated-r1-20261111/memory/AddressBucketSequenceMemory.v:39$1_DATA' using process `\\AddressBucketSequenceReplica.$proc$/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-sequence-replicated-r1-20261111/memory/AddressBucketSequenceMemory.v:37$4'.\n  created $dff cell `$procdff$22' with positive edge clock.\nCreating register for signal `\\AddressBucketSequenceReplica.$memwr$\\payload$/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-sequence-replicated-r1-20261111/memory/AddressBucketSequenceMemory.v:39$1_EN' using process `\\AddressBucketSequenceReplica.$proc$/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-sequence-replicated-r1-20261111/memory/AddressBucketSequenceMemory.v:37$4'.\n  created $dff cell `$procdff$23' with positive edge clock.\n\n3.10. Executing PROC_MEMWR pass (convert process memory writes to cells).\n\n3.11. Executing PROC_CLEAN pass (remove empty switches from decision trees).\nFound and cleaned up 1 empty switch in `\\AddressBucketSequenceReplica.$proc$/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-sequence-replicated-r1-20261111/memory/AddressBucketSequenceMemory.v:37$4'.\nRemoving empty process `AddressBucketSequenceReplica.$proc$/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-sequence-replicated-r1-20261111/memory/AddressBucketSequenceMemory.v:37$4'.\nCleaned up 1 empty switch.\n\n3.12. Executing OPT_EXPR pass (perform const folding).\nOptimizing module AddressBucketSequenceMemory.\nOptimizing module AddressBucketSequenceReplica.\n<suppressed ~1 debug messages>\n\n4. Executing MEMORY_COLLECT pass (generating $mem cells).\n\n5. Executing JSON backend.\n",
      "pid": 1991646,
      "source_id": "96369486ff5e2c163787b4ce71f5e3d0344346f2b7fb1077d37176ff230bbcdf",
      "stage_log": {
        "bytes": 5818,
        "mtime_ns": 1794360695525781294,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-sequence-replicated-r1-20261111/memory/memory-topology-attempt-1.log"
      },
      "stage_process": {},
      "start_ticks": "17240394",
      "status": "FAILED_WITH_EVIDENCE",
      "updated_utc": "2026-11-11T01:31:35.570145+00:00",
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
    "Opt4-fit-address-static-retire-r1-state.json": {
      "controller": {},
      "error": "AssertionError(('sat-clear', 1, '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-static-retire-r1-20261111/sat-clear.log'))",
      "hardware_commit": "1a5717752b2efd28d99b7b0b5cccb97e9ff6215c",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "-20261111/proof/RetireClearProof.v:4219$7622 ($eq).\nRemoved top 1 bits (of 8) from port B of cell RetireClearProof.$eq$/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-static-retire-r1-20261111/proof/RetireClearProof.v:4224$7642 ($eq).\nRemoved top 1 bits (of 8) from port B of cell RetireClearProof.$eq$/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-static-retire-r1-20261111/proof/RetireClearProof.v:4229$7662 ($eq).\nRemoved top 255 bits (of 256) from wire RetireClearProof._T.\n\n2.10. Executing OPT_CLEAN pass (remove unused cells and wires).\nFinding unused cells or wires in module \\RetireClearProof..\nRemoved 0 unused cells and 1 unused wires.\n<suppressed ~1 debug messages>\n\n2.11. Executing MEMORY_COLLECT pass (generating $mem cells).\n\n2.12. Executing OPT pass (performing simple optimizations).\n\n2.12.1. Executing OPT_EXPR pass (perform const folding).\nOptimizing module RetireClearProof.\n\n2.12.2. Executing OPT_MERGE pass (detect identical cells).\nFinding identical cells in module `\\RetireClearProof'.\nRemoved a total of 0 cells.\n\n2.12.3. Executing OPT_CLEAN pass (remove unused cells and wires).\nFinding unused cells or wires in module \\RetireClearProof..\n\n2.12.4. Finished fast OPT passes.\n\n2.13. Printing statistics.\n\n=== RetireClearProof ===\n\n        +----------Local Count, excluding submodules.\n        | \n     8276 wires\n   986639 wire bits\n     7250 public wires\n   985613 public wire bits\n     1030 ports\n    65804 port bits\n     6918 cells\n      514   $and\n      513   $eq\n        1   $logic_not\n     5888   $mux\n        1   $not\n        1   $shr\n\n2.14. Executing CHECK pass (checking for obvious problems).\nChecking module RetireClearProof...\nFound and reported 0 problems.\n\n3. Executing SAT pass (solving SAT problems in the circuit).\n\nSetting up SAT problem:\nFinal constraint equation: { } = { }\nImported 6918 cells to SAT database.\nImport proof-constraint: \\io_equivalent = 1'1\nFinal proof equation: \\io_equivalent = 1'1\n\nSolving problem with 2312012 variables and 6212020 clauses..\nInterrupted SAT solver: TIMEOUT!\n\n        _____  _  _      _____ ____  _     _____\n       /__ __\\/ \\/ \\__/|/  __//  _ \\/ \\ /\\/__ __\\\n         / \\  | || |\\/|||  \\  | / \\|| | ||  / \\\n         | |  | || |  |||  /_ | \\_/|| \\_/|  | |\n         \\_/  \\_/\\_/  \\|\\____\\\\____/\\____/  \\_/\n\nERROR: Called with -verify and proof did time out!\n",
      "pid": 2295670,
      "source_id": "6b2b0cd36757eb600c4470c1489ba61469a1b81f92a7a766ce0c5ed51006f0e5",
      "stage_log": {
        "bytes": 61876,
        "mtime_ns": 1794368344620273329,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-static-retire-r1-20261111/sat-clear.log"
      },
      "start_ticks": "17983094",
      "status": "FAILED_WITH_EVIDENCE",
      "updated_utc": "2026-11-11T03:39:04.807977+00:00",
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
      "controller": {},
      "full_module_map": {
        "checkpoint": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-tagcompress-cachefix-r3-20261111/map-full-module/module.dcp",
        "report": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-tagcompress-cachefix-r3-20261111/map-full-module/utilization.rpt",
        "report_sha256": "0c6d62536302524b517ad279c49eec61241650a0b0450b617b6a7417d00e25fe",
        "resources": {
          "Block RAM Tile": 216.0,
          "CARRY8": 55413.0,
          "CLB LUTs": 990230.0,
          "CLB Registers": 386142.0,
          "DSPs": 0.0
        },
        "rtl_sha256": "5e061d818bff7be4878d6eab82b2343f760e7ce1a54db3ae2641a21b4f4db039",
        "scope": "Complete module OOC; not whole-DUT FIT",
        "tcl_sha256": "62ba0718366eb45c35850100b805f35c216675c44b1352966133434f3f9f71fa"
      },
      "hardware_commit": "3fb8a7f7d7e65b5076aaebbc8aa93101f00041ce",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "t 'PackageAddressStats' is not ideal for floorplanning, since the cellview 'PackageAddressStats' contains a large number of primitives.  Please consider enabling hierarchy in synthesis if you want to do floorplanning.\nINFO: [Project 1-570] Preparing netlist for logic optimization\nINFO: [Opt 31-138] Pushed 0 inverter(s) to 0 load pin(s).\nNetlist sorting complete. Time (s): cpu = 00:00:00.35 ; elapsed = 00:00:00.34 . Memory (MB): peak = 11073.617 ; gain = 0.000 ; free physical = 59060 ; free virtual = 319042\nINFO: [Project 1-111] Unisim Transformation Summary:\nNo Unisim elements were transformed.\n\nSynth Design complete, checksum: 33df6aaf\nINFO: [Common 17-83] Releasing license: Synthesis\n482 Infos, 1 Warnings, 0 Critical Warnings and 0 Errors encountered.\nsynth_design completed successfully\nsynth_design: Time (s): cpu = 01:41:47 ; elapsed = 01:45:42 . Memory (MB): peak = 11073.617 ; gain = 8567.207 ; free physical = 60363 ; free virtual = 320354\nINFO: [Common 17-600] The following parameters have non-default value.\ngeneral.maxThreads\n# report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-tagcompress-cachefix-r3-20261111/map-full-module/utilization.rpt}\nreport_utilization: Time (s): cpu = 00:00:08 ; elapsed = 00:00:09 . Memory (MB): peak = 11073.617 ; gain = 0.000 ; free physical = 61762 ; free virtual = 321764\n# report_utilization -hierarchical -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-tagcompress-cachefix-r3-20261111/map-full-module/hierarchical.rpt}\nreport_utilization: Time (s): cpu = 00:00:12 ; elapsed = 00:00:13 . Memory (MB): peak = 11073.617 ; gain = 0.000 ; free physical = 60745 ; free virtual = 321386\n# write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-tagcompress-cachefix-r3-20261111/map-full-module/module.dcp}\nINFO: [Timing 38-35] Done setting XDC timing constraints.\nINFO: [Common 17-1381] The checkpoint '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-tagcompress-cachefix-r3-20261111/map-full-module/module.dcp' has been generated.\nwrite_checkpoint: Time (s): cpu = 00:04:49 ; elapsed = 00:03:27 . Memory (MB): peak = 11145.652 ; gain = 72.035 ; free physical = 58089 ; free virtual = 317547\n# exit 0\nINFO: [Common 17-206] Exiting Vivado at Wed Nov 11 09:59:03 2026...\n",
      "pid": 1715176,
      "source_id": "9a2882d23afaeada238076322cceb267d0c7ed5d74e00b0d6e532e04c13c03e3",
      "stage_log": {
        "bytes": 232076,
        "mtime_ns": 1794362343100064161,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-tagcompress-cachefix-r3-20261111/map-full-module/map-full-module-attempt-1.log"
      },
      "stage_process": {},
      "start_ticks": "16712610",
      "status": "VERIFIED_AND_MAPPED_MODULE_ONLY",
      "updated_utc": "2026-11-11T01:59:08.543628+00:00",
      "worker_processes": []
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
      "controller": {},
      "full_module_map": {
        "checkpoint": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-update-share-r1-20261111/map-full-module/module.dcp",
        "report": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-update-share-r1-20261111/map-full-module/utilization.rpt",
        "report_sha256": "887c8c94789959539513a8e94c87480a0510c4f1fee25b306492c3c5545008df",
        "resources": {
          "Block RAM Tile": 216.0,
          "CARRY8": 30840.0,
          "CLB LUTs": 749673.0,
          "CLB Registers": 384311.0,
          "DSPs": 0.0
        },
        "rtl_sha256": "4edf1038beee95bd74e2d05bff2d0fc0d0cff2cd3841e6a82d4dd7a9816cb659",
        "scope": "Complete module OOC; not whole-DUT FIT",
        "tcl_sha256": "f1376b18f91490478e58dfad0553d44640dcb50c1f66f8fe16d82497a71fafd2"
      },
      "hardware_commit": "eada7948b15146fd33bbc91aad7bac4ab9ec44b7",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "\nWARNING: [Netlist 29-101] Netlist 'PackageAddressStats' is not ideal for floorplanning, since the cellview 'PackageAddressStats' contains a large number of primitives.  Please consider enabling hierarchy in synthesis if you want to do floorplanning.\nINFO: [Project 1-570] Preparing netlist for logic optimization\nINFO: [Opt 31-138] Pushed 0 inverter(s) to 0 load pin(s).\nNetlist sorting complete. Time (s): cpu = 00:00:00.28 ; elapsed = 00:00:00.27 . Memory (MB): peak = 11073.141 ; gain = 0.000 ; free physical = 59826 ; free virtual = 319817\nINFO: [Project 1-111] Unisim Transformation Summary:\nNo Unisim elements were transformed.\n\nSynth Design complete, checksum: a9fbe37\nINFO: [Common 17-83] Releasing license: Synthesis\n481 Infos, 1 Warnings, 0 Critical Warnings and 0 Errors encountered.\nsynth_design completed successfully\nsynth_design: Time (s): cpu = 01:43:18 ; elapsed = 01:48:06 . Memory (MB): peak = 11073.141 ; gain = 8570.699 ; free physical = 61714 ; free virtual = 321715\nINFO: [Common 17-600] The following parameters have non-default value.\ngeneral.maxThreads\n# report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-update-share-r1-20261111/map-full-module/utilization.rpt}\nreport_utilization: Time (s): cpu = 00:00:07 ; elapsed = 00:00:08 . Memory (MB): peak = 11073.141 ; gain = 0.000 ; free physical = 61854 ; free virtual = 321945\n# report_utilization -hierarchical -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-update-share-r1-20261111/map-full-module/hierarchical.rpt}\nreport_utilization: Time (s): cpu = 00:00:11 ; elapsed = 00:00:12 . Memory (MB): peak = 11073.141 ; gain = 0.000 ; free physical = 60350 ; free virtual = 321189\n# write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-update-share-r1-20261111/map-full-module/module.dcp}\nINFO: [Timing 38-35] Done setting XDC timing constraints.\nINFO: [Common 17-1381] The checkpoint '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-update-share-r1-20261111/map-full-module/module.dcp' has been generated.\nwrite_checkpoint: Time (s): cpu = 00:03:53 ; elapsed = 00:02:48 . Memory (MB): peak = 11145.176 ; gain = 72.035 ; free physical = 52153 ; free virtual = 314992\n# exit 0\nINFO: [Common 17-206] Exiting Vivado at Wed Nov 11 09:58:26 2026...\n",
      "pid": 1712770,
      "source_id": "89a95f25bc2b2413464e4cd94c5ed5b3a69673f16f0ebf18521baf1cc1cb8a29",
      "stage_log": {
        "bytes": 231381,
        "mtime_ns": 1794362306963996404,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-update-share-r1-20261111/map-full-module/map-full-module-attempt-1.log"
      },
      "stage_process": {},
      "start_ticks": "16704932",
      "status": "VERIFIED_AND_MAPPED_MODULE_ONLY",
      "updated_utc": "2026-11-11T01:58:32.202829+00:00",
      "worker_processes": []
    },
    "Opt4-fit-address-update-share-r2-state.json": {
      "controller": {},
      "full_module_map": {
        "checkpoint": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-update-share-r2-20261111/map-full-module/module.dcp",
        "report": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-update-share-r2-20261111/map-full-module/utilization.rpt",
        "report_sha256": "fe5e4eb32e4c8e9a8438c9ec15fabe0b95acc3d2eca300de8919455765f009dd",
        "resources": {
          "Block RAM Tile": 216.0,
          "CARRY8": 30842.0,
          "CLB LUTs": 872880.0,
          "CLB Registers": 384373.0,
          "DSPs": 0.0
        },
        "rtl_sha256": "88f390bb71c01d3b8ddd90b4660cc20a81f44faa14b64e7578aab273d0c599d6",
        "scope": "Complete module OOC; not whole-DUT FIT",
        "tcl_sha256": "363d4d2ecad05c4ca315e528574bda7c1637d8537cb20146320ba8b48b12925d"
      },
      "hardware_commit": "00847dc2b8f6be3f1e1ff0639c1104d33334ddc9",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "WARNING: [Netlist 29-101] Netlist 'PackageAddressStats' is not ideal for floorplanning, since the cellview 'PackageAddressStats' contains a large number of primitives.  Please consider enabling hierarchy in synthesis if you want to do floorplanning.\nINFO: [Project 1-570] Preparing netlist for logic optimization\nINFO: [Opt 31-138] Pushed 0 inverter(s) to 0 load pin(s).\nNetlist sorting complete. Time (s): cpu = 00:00:00.33 ; elapsed = 00:00:00.34 . Memory (MB): peak = 11124.805 ; gain = 0.000 ; free physical = 76310 ; free virtual = 335797\nINFO: [Project 1-111] Unisim Transformation Summary:\nNo Unisim elements were transformed.\n\nSynth Design complete, checksum: 3dec0e6d\nINFO: [Common 17-83] Releasing license: Synthesis\n481 Infos, 1 Warnings, 0 Critical Warnings and 0 Errors encountered.\nsynth_design completed successfully\nsynth_design: Time (s): cpu = 01:55:39 ; elapsed = 01:58:49 . Memory (MB): peak = 11124.805 ; gain = 8625.363 ; free physical = 77443 ; free virtual = 336929\nINFO: [Common 17-600] The following parameters have non-default value.\ngeneral.maxThreads\n# report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-update-share-r2-20261111/map-full-module/utilization.rpt}\nreport_utilization: Time (s): cpu = 00:00:08 ; elapsed = 00:00:09 . Memory (MB): peak = 11124.805 ; gain = 0.000 ; free physical = 77387 ; free virtual = 336874\n# report_utilization -hierarchical -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-update-share-r2-20261111/map-full-module/hierarchical.rpt}\nreport_utilization: Time (s): cpu = 00:00:12 ; elapsed = 00:00:13 . Memory (MB): peak = 11124.805 ; gain = 0.000 ; free physical = 76754 ; free virtual = 336241\n# write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-update-share-r2-20261111/map-full-module/module.dcp}\nINFO: [Timing 38-35] Done setting XDC timing constraints.\nINFO: [Common 17-1381] The checkpoint '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-update-share-r2-20261111/map-full-module/module.dcp' has been generated.\nwrite_checkpoint: Time (s): cpu = 00:04:19 ; elapsed = 00:03:08 . Memory (MB): peak = 11196.840 ; gain = 72.035 ; free physical = 68728 ; free virtual = 330300\n# exit 0\nINFO: [Common 17-206] Exiting Vivado at Wed Nov 11 10:21:38 2026...\n",
      "pid": 1737896,
      "source_id": "6b0de8636ec9d88f7d9702769c03325df78ab43c3c1fe527fff9dc1a3aafbbdb",
      "stage_log": {
        "bytes": 231875,
        "mtime_ns": 1794363698626274141,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-update-share-r2-20261111/map-full-module/map-full-module-attempt-1.log"
      },
      "stage_process": {},
      "start_ticks": "16778236",
      "status": "VERIFIED_AND_MAPPED_MODULE_ONLY",
      "updated_utc": "2026-11-11T02:21:43.982754+00:00",
      "worker_processes": []
    },
    "Opt4-fit-barrier-event-read-map-r1-state.json": {
      "controller": {},
      "hardware_commit": "c4b5820da837b2296a3362d3f60dae50580de2fb",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "pid": 2049250,
      "source_id": "4eab5d120a9dbe5a93141fa3af6ecba6e886016c200ff931426b2f571905f345",
      "stage_process": {},
      "start_ticks": "17436077",
      "status": "VERIFIED_AND_PAIRED_MAPPED_MODULE_ONLY_NOT_SELECTED",
      "updated_utc": "2026-11-11T02:11:26.495002+00:00",
      "worker_processes": []
    },
    "Opt4-fit-barrier-event-read-proof-r1-state.json": {
      "controller": {},
      "hardware_commit": "c4b5820da837b2296a3362d3f60dae50580de2fb",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "BARRIER_COMPLETE_FROZEN_PARENT_CANDIDATE_PASS cycles=8192 observations=16384 outputs=7 bucket_fields=1024 collisions=256 immediate=86 reset_events=10 overflow_seeds=2\n",
      "pid": 2033434,
      "source_id": "4eab5d120a9dbe5a93141fa3af6ecba6e886016c200ff931426b2f571905f345",
      "stage_log": {
        "bytes": 167,
        "mtime_ns": 1794362131263718857,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-barrier-event-read-r1-20261111/comparison/complete-comparison-attempt-1.log"
      },
      "stage_process": {},
      "start_ticks": "17374458",
      "status": "PASS_LOCAL_SAT_AND_COMPLETE_FROZEN_8192_CYCLES_MAPPING_PENDING",
      "updated_utc": "2026-11-11T01:55:31.310342+00:00",
      "worker_processes": []
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
        "cpu_ticks": 905,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 1737960,
        "process_state": "S",
        "rss_bytes": 328228864,
        "start_ticks": "16778336"
      },
      "current_stage": "dut_synth",
      "hardware_commit": "9ae9a7fcf231a75259e23973b12a93896a443cbb",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": true,
      "log_dir": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-bucket-tag-cad-9ae9a7fc",
      "log_tail": "imul/imul/prod.\nDSP Report: Generating DSP st_uncache_packet_cycle_contribution, operation Mode is: A*B.\nDSP Report: operator st_uncache_packet_cycle_contribution is absorbed into DSP st_uncache_packet_cycle_contribution.\nDSP Report: operator st_uncache_packet_cycle_contribution is absorbed into DSP st_uncache_packet_cycle_contribution.\nDSP Report: Generating DSP st_uncache_packet_cycle_contribution, operation Mode is: (PCIN>>17)+A*B.\nDSP Report: operator st_uncache_packet_cycle_contribution is absorbed into DSP st_uncache_packet_cycle_contribution.\nDSP Report: operator st_uncache_packet_cycle_contribution is absorbed into DSP st_uncache_packet_cycle_contribution.\nDSP Report: Generating DSP st_uncache_packet_cycle_contribution, operation Mode is: A*B.\nDSP Report: operator st_uncache_packet_cycle_contribution is absorbed into DSP st_uncache_packet_cycle_contribution.\nDSP Report: operator st_uncache_packet_cycle_contribution is absorbed into DSP st_uncache_packet_cycle_contribution.\nDSP Report: Generating DSP st_uncache_packet_cycle_contribution, operation Mode is: (PCIN>>17)+A*B.\nDSP Report: operator st_uncache_packet_cycle_contribution is absorbed into DSP st_uncache_packet_cycle_contribution.\nDSP Report: operator st_uncache_packet_cycle_contribution is absorbed into DSP st_uncache_packet_cycle_contribution.\nRAM (\"FireSim_i_497/ram/srams/mem_0_reg\") is too shallow (depth = 512) to use URAM. Choosing BRAM instead of URAM \nRAM (\"FireSim_i_497/ram/srams/mem_1_reg\") is too shallow (depth = 512) to use URAM. Choosing BRAM instead of URAM \nRAM (\"FireSim_i_497/ram/srams/mem_2_reg\") is too shallow (depth = 512) to use URAM. Choosing BRAM instead of URAM \nRAM (\"FireSim_i_497/ram/srams/mem_3_reg\") is too shallow (depth = 512) to use URAM. Choosing BRAM instead of URAM \nRAM (\"FireSim_i_497/ram/srams/mem_4_reg\") is too shallow (depth = 512) to use URAM. Choosing BRAM instead of URAM \nRAM (\"FireSim_i_497/ram/srams/mem_5_reg\") is too shallow (depth = 512) to use URAM. Choosing BRAM instead of URAM \nRAM (\"FireSim_i_497/ram/srams/mem_6_reg\") is too shallow (depth = 512) to use URAM. Choosing BRAM instead of URAM \nRAM (\"FireSim_i_497/ram/srams/mem_7_reg\") is too shallow (depth = 512) to use URAM. Choosing BRAM instead of URAM \nRAM (\"topi_502/FASEDMemoryTimingModel_0/readEgress/multiQueue/ram_data_reg\") is too shallow (depth = 128) to use URAM. Choosing BRAM instead of URAM \n",
      "pid": 1737960,
      "profile": "Opt4-fit-C4-SVB32-bucket-tag-20261111",
      "source_id": "3791dd0e8f7d9c380500cd37f11ece4c92e275bc399894780228fa61449df561",
      "stage_log": {
        "bytes": 179270,
        "mtime_ns": 1794366734970845974,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-bucket-tag-cad-9ae9a7fc/dut_synth-attempt-1.log"
      },
      "start_ticks": "16778336",
      "status": "RUNNING_DUT_SYNTH",
      "updated_utc": "2026-11-11T03:41:28.640799+00:00",
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
          "cpu_ticks": 1200909,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 234397696,
            "rchar": 17713583910,
            "read_bytes": 0,
            "syscr": 2278206,
            "syscw": 4660896,
            "wchar": 22309909535,
            "write_bytes": 22316167168
          },
          "pid": 1886276,
          "process_state": "S",
          "rss_bytes": 9739558912,
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
    "Opt4-fit-dcache-result-memory-mapping-r3-state.json": {
      "controller": {},
      "hardware_commit": "51a2bd2588fe09ded84c3d9911d9b8481da929ca",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "-----------\nSynthesis finished with 0 errors, 0 critical warnings and 0 warnings.\nSynthesis Optimization Runtime : Time (s): cpu = 00:00:12 ; elapsed = 00:00:15 . Memory (MB): peak = 3174.781 ; gain = 683.238 ; free physical = 54628 ; free virtual = 310587\nSynthesis Optimization Complete : Time (s): cpu = 00:00:12 ; elapsed = 00:00:15 . Memory (MB): peak = 3174.789 ; gain = 683.238 ; free physical = 54641 ; free virtual = 310600\nINFO: [Project 1-571] Translating synthesized netlist\nNetlist sorting complete. Time (s): cpu = 00:00:00.01 ; elapsed = 00:00:00.01 . Memory (MB): peak = 3174.789 ; gain = 0.000 ; free physical = 54893 ; free virtual = 310852\nINFO: [Netlist 29-17] Analyzing 288 Unisim elements for replacement\nINFO: [Netlist 29-28] Unisim Transformation completed in 0 CPU seconds\nINFO: [Project 1-570] Preparing netlist for logic optimization\nINFO: [Opt 31-138] Pushed 0 inverter(s) to 0 load pin(s).\nNetlist sorting complete. Time (s): cpu = 00:00:00 ; elapsed = 00:00:00 . Memory (MB): peak = 3247.375 ; gain = 0.000 ; free physical = 54550 ; free virtual = 310514\nINFO: [Project 1-111] Unisim Transformation Summary:\n  A total of 160 instances were transformed.\n  RAM64M8 => RAM64M8 (RAMD64E(x8)): 144 instances\n  RAM64X1D => RAM64X1D (RAMD64E(x2)): 16 instances\n\nSynth Design complete, checksum: 179c31e\nINFO: [Common 17-83] Releasing license: Synthesis\n15 Infos, 0 Warnings, 0 Critical Warnings and 0 Errors encountered.\nsynth_design completed successfully\nsynth_design: Time (s): cpu = 00:00:19 ; elapsed = 00:00:18 . Memory (MB): peak = 3247.375 ; gain = 755.965 ; free physical = 54635 ; free virtual = 310599\nINFO: [Common 17-600] The following parameters have non-default value.\ngeneral.maxThreads\n# report_utilization -file {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-dcache-result-memory-mapping-r3-20261111/map-candidate/utilization.rpt}\n# write_checkpoint -force {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-dcache-result-memory-mapping-r3-20261111/map-candidate/module.dcp}\nINFO: [Timing 38-35] Done setting XDC timing constraints.\nINFO: [Common 17-1381] The checkpoint '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-dcache-result-memory-mapping-r3-20261111/map-candidate/module.dcp' has been generated.\n# exit 0\nINFO: [Common 17-206] Exiting Vivado at Wed Nov 11 10:01:38 2026...\n",
      "pid": 2039705,
      "source_id": "fadfd22293afed9177e282eaf0a82e7750b0e20d51284bc6d89f592b24ca0e47",
      "stage_log": {
        "bytes": 15535,
        "mtime_ns": 1794362498464388100,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-dcache-result-memory-mapping-r3-20261111/map-candidate/map-candidate-attempt-1.log"
      },
      "stage_process": {},
      "start_ticks": "17404595",
      "status": "LOCAL_STORAGE_VERIFIED_AND_MAPPED_COMPLETE_DCACHE_PENDING_NOT_ADMITTED",
      "updated_utc": "2026-11-11T02:01:40.528956+00:00",
      "worker_processes": []
    },
    "Opt4-fit-dcache-result-memory-proofonly-r1-state.json": {
      "controller": {},
      "error": "AssertionError(('compile', 1, '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-dcache-result-memory-proofonly-r1-20261111/compile-attempt-1.log'))",
      "hardware_commit": "51a2bd2588fe09ded84c3d9911d9b8481da929ca",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "Picked up JAVA_TOOL_OPTIONS: \n/data1/gzh/EC/firesim/final-opt4-20261106/candidates/dcache-result-memory-r1-20261111/Emit.scala:66: error: object firesim is not a member of package firesim\n  val base=new firesim.firesim.DacOpt4C4().toInstance\n                       ^\n1 error\n",
      "pid": 1991009,
      "source_id": "fadfd22293afed9177e282eaf0a82e7750b0e20d51284bc6d89f592b24ca0e47",
      "stage_log": {
        "bytes": 275,
        "mtime_ns": 1794360637855449414,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-dcache-result-memory-proofonly-r1-20261111/compile-attempt-1.log"
      },
      "stage_process": {},
      "start_ticks": "17235579",
      "status": "FAILED_WITH_EVIDENCE",
      "updated_utc": "2026-11-11T01:30:37.901896+00:00",
      "worker_processes": []
    },
    "Opt4-fit-dcache-result-memory-proofonly-r2-state.json": {
      "controller": {},
      "error": "AssertionError(('emit-proof', 1, '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-dcache-result-memory-proofonly-r2-20261111/proof/emit-proof-attempt-1.log'))",
      "hardware_commit": "51a2bd2588fe09ded84c3d9911d9b8481da929ca",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "Picked up JAVA_TOOL_OPTIONS: \nException in thread \"main\" java.lang.IllegalArgumentException: requirement failed\n\tat scala.Predef$.require(Predef.scala:324)\n\tat opt4dcacheresult.Emit$.delayedEndpoint$opt4dcacheresult$Emit$1(Emit.scala:70)\n\tat opt4dcacheresult.Emit$delayedInit$body.apply(Emit.scala:64)\n\tat scala.Function0.apply$mcV$sp(Function0.scala:42)\n\tat scala.Function0.apply$mcV$sp$(Function0.scala:42)\n\tat scala.runtime.AbstractFunction0.apply$mcV$sp(AbstractFunction0.scala:17)\n\tat scala.App.$anonfun$main$1(App.scala:98)\n\tat scala.App.$anonfun$main$1$adapted(App.scala:98)\n\tat scala.collection.IterableOnceOps.foreach(IterableOnce.scala:575)\n\tat scala.collection.IterableOnceOps.foreach$(IterableOnce.scala:573)\n\tat scala.collection.AbstractIterable.foreach(Iterable.scala:933)\n\tat scala.App.main(App.scala:98)\n\tat scala.App.main$(App.scala:96)\n\tat opt4dcacheresult.Emit$.main(Emit.scala:64)\n\tat opt4dcacheresult.Emit.main(Emit.scala)\n",
      "pid": 1992909,
      "source_id": "fadfd22293afed9177e282eaf0a82e7750b0e20d51284bc6d89f592b24ca0e47",
      "stage_log": {
        "bytes": 944,
        "mtime_ns": 1794360720313126164,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-dcache-result-memory-proofonly-r2-20261111/proof/emit-proof-attempt-1.log"
      },
      "stage_process": {},
      "start_ticks": "17243605",
      "status": "FAILED_WITH_EVIDENCE",
      "updated_utc": "2026-11-11T01:32:00.367161+00:00",
      "worker_processes": []
    },
    "Opt4-fit-dcache-result-memory-proofonly-r3-state.json": {
      "controller": {},
      "error": "AssertionError(('typecheck-dcache', 1, '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-dcache-result-memory-proofonly-r3-20261111/typecheck-dcache-attempt-1.log'))",
      "hardware_commit": "51a2bd2588fe09ded84c3d9911d9b8481da929ca",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "Picked up JAVA_TOOL_OPTIONS: \n/data1/gzh/EC/firesim/final-opt4-20261106/Opt4-fit-dcache-result-memory-r1-20261111/chipyard/generators/boom/src/main/scala/lsu/dcache.scala:2704: error: not found: type SafePrefixScanner\n  val safePrefix = Module(new SafePrefixScanner(statsWindow,\n                              ^\n1 error\n",
      "pid": 1999006,
      "source_id": "fadfd22293afed9177e282eaf0a82e7750b0e20d51284bc6d89f592b24ca0e47",
      "stage_log": {
        "bytes": 319,
        "mtime_ns": 1794360881509641703,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-dcache-result-memory-proofonly-r3-20261111/typecheck-dcache-attempt-1.log"
      },
      "stage_process": {},
      "start_ticks": "17257675",
      "status": "FAILED_WITH_EVIDENCE",
      "updated_utc": "2026-11-11T01:34:41.574475+00:00",
      "worker_processes": []
    },
    "Opt4-fit-dcache-result-memory-proofonly-r4-state.json": {
      "controller": {},
      "hardware_commit": "51a2bd2588fe09ded84c3d9911d9b8481da929ca",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "Picked up JAVA_TOOL_OPTIONS: \nwarning: 1 deprecation (since 2.13.2)\nwarning: 3 deprecations (since 2.13.3)\nwarning: 4 deprecations in total; re-run with -deprecation for details\nwarning: 968 feature warnings; re-run with -feature for details\n4 warnings\n",
      "pid": 2002556,
      "source_id": "fadfd22293afed9177e282eaf0a82e7750b0e20d51284bc6d89f592b24ca0e47",
      "stage_log": {
        "bytes": 253,
        "mtime_ns": 1794361028275415111,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-dcache-result-memory-proofonly-r4-20261111/typecheck-dcache-attempt-1.log"
      },
      "stage_process": {},
      "start_ticks": "17273488",
      "status": "PASS_GENERATED_STORAGE_PROOF_TOPOLOGY_8192_CYCLES_AND_DCACHE_TYPECHECK_NOT_ADMITTED",
      "updated_utc": "2026-11-11T01:37:08.420577+00:00",
      "worker_processes": []
    },
    "Opt4-fit-retire-read-r1-state.json": {
      "controller": {
        "cpu_ticks": 564,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 1896443,
        "process_state": "S",
        "rss_bytes": 15450112,
        "start_ticks": "16895677"
      },
      "hardware_commit": "7e68d3df224fd37fd3f462b9deff376566ed9a79",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": true,
      "log_tail": "---------------\nStart Writing Synthesis Report\n---------------------------------------------------------------------------------\n\nReport BlackBoxes: \n+-+--------------+----------+\n| |BlackBox name |Instances |\n+-+--------------+----------+\n+-+--------------+----------+\n\nReport Cell Usage: \n+------+---------+-------+\n|      |Cell     |Count  |\n+------+---------+-------+\n|1     |CARRY8   |  55414|\n|2     |LUT1     |      4|\n|3     |LUT2     | 241597|\n|4     |LUT3     |  84750|\n|5     |LUT4     | 336604|\n|6     |LUT5     | 185033|\n|7     |LUT6     | 396032|\n|8     |MUXF7    |  97310|\n|9     |MUXF8    |  48516|\n|10    |RAMB18E2 |     48|\n|11    |RAMB36E2 |    192|\n|12    |FDRE     | 386073|\n|13    |FDSE     |     38|\n+------+---------+-------+\n\nReport Instance Areas: \n+------+---------+-------+--------+\n|      |Instance |Module |Cells   |\n+------+---------+-------+--------+\n|1     |top      |       | 1831611|\n+------+---------+-------+--------+\n---------------------------------------------------------------------------------\nFinished Writing Synthesis Report : Time (s): cpu = 02:54:40 ; elapsed = 02:59:07 . Memory (MB): peak = 11658.934 ; gain = 9159.332 ; free physical = 59271 ; free virtual = 321267\n---------------------------------------------------------------------------------\nSynthesis finished with 0 errors, 0 critical warnings and 0 warnings.\nSynthesis Optimization Runtime : Time (s): cpu = 02:54:45 ; elapsed = 02:59:10 . Memory (MB): peak = 11662.844 ; gain = 9163.242 ; free physical = 68772 ; free virtual = 330767\nSynthesis Optimization Complete : Time (s): cpu = 02:54:45 ; elapsed = 02:59:10 . Memory (MB): peak = 11662.844 ; gain = 9163.242 ; free physical = 68897 ; free virtual = 330766\nINFO: [Project 1-571] Translating synthesized netlist\nNetlist sorting complete. Time (s): cpu = 00:00:20 ; elapsed = 00:00:21 . Memory (MB): peak = 11662.844 ; gain = 0.000 ; free physical = 66215 ; free virtual = 328099\nINFO: [Netlist 29-17] Analyzing 201240 Unisim elements for replacement\nINFO: [Netlist 29-28] Unisim Transformation completed in 4 CPU seconds\nWARNING: [Netlist 29-101] Netlist 'PackageAddressStats' is not ideal for floorplanning, since the cellview 'PackageAddressStats' contains a large number of primitives.  Please consider enabling hierarchy in synthesis if you want to do floorplanning.\nINFO: [Project 1-570] Preparing netlist for logic optimization\n",
      "pid": 1896443,
      "source_id": "4c8636670eb9f78b3df716d02c5690dd50b163582fa370c323b5b4fe4dd3cea5",
      "stage_log": {
        "bytes": 229704,
        "mtime_ns": 1794368438772473019,
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
      "updated_utc": "2026-11-11T03:41:21.903671+00:00",
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
          "cpu_ticks": 1089073,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 2186326016,
            "rchar": 8900887779,
            "read_bytes": 454656,
            "syscr": 1184090,
            "syscw": 2941983,
            "wchar": 11842433218,
            "write_bytes": 11843538944
          },
          "pid": 1906049,
          "process_state": "S",
          "rss_bytes": 7629643776,
          "start_ticks": "16928147"
        }
      ]
    },
    "Opt4-fit-runtime-state.json": {
      "certified_bitstream": false,
      "controller": {
        "cpu_ticks": 25,
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
      "updated_utc": "2026-11-11T03:41:27.103191+00:00",
      "worker_processes": [
        {
          "comm": "python3",
          "cpu_ticks": 25,
          "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
          "io": {
            "cancelled_write_bytes": 0,
            "rchar": 2664024,
            "read_bytes": 0,
            "syscr": 544,
            "syscw": 190,
            "wchar": 201676,
            "write_bytes": 790528
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
    "Opt4-fit-svb-reference-map-r1-state.json": {
      "controller": {},
      "hardware_commit": "9ae9a7fcf231a75259e23973b12a93896a443cbb",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "pid": 2040739,
      "start_ticks": "17407983",
      "status": "COMPLETE_IDENTICAL_HARNESS_FULL_SVB_AREA_COMPARISON_NOT_WHOLE_DUT",
      "updated_utc": "2026-11-11T02:03:53.997380+00:00",
      "worker_processes": []
    },
    "Opt4-fit-svb-software-prep-r1-state.json": {
      "controller": {},
      "hardware_commit": "f2d2ca3ea0b12c918f2ccd2d1131be2709960470",
      "identity_live": false,
      "source_id": "f678ac806ea4b0f801596b26ec8bf9ef914a3161b39f92564ac25452abd8eafc",
      "status": "PREPARED_REAL_ABI_AND_PAIRED_SOFTWARE_NOT_FPGA_VALIDATED"
    },
    "Opt4-fit-svb-system-r1-state.json": {
      "controller": {},
      "error": "AssertionError(('compile-svb-emitter', 1, '/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-system-r1-20261111/compile-svb-emitter-attempt-1.log', ['/data1/gzh/EC/firesim/final-opt4-20261106/Opt4-fit-svb-tree-r1-20261111/builds/system-f2d2ca3e-r1/svb-comparison/emit-classes/opt4svbtree/Emit.class']))",
      "hardware_commit": "f2d2ca3ea0b12c918f2ccd2d1131be2709960470",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": "Picked up JAVA_TOOL_OPTIONS: \n/data1/gzh/EC/firesim/final-opt4-20261106/candidates/svb-system-r1-20261111/Emit.scala:54: error: object firesim is not a member of package firesim\n      val base = new firesim.firesim.DacOpt4C4().toInstance\n                             ^\n1 error\n",
      "pid": 1976889,
      "source_id": "f678ac806ea4b0f801596b26ec8bf9ef914a3161b39f92564ac25452abd8eafc",
      "stage_log": {
        "bytes": 277,
        "mtime_ns": 1794359894453466078,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-system-r1-20261111/compile-svb-emitter-attempt-1.log"
      },
      "stage_process": {},
      "start_ticks": "17159456",
      "status": "FAILED_WITH_EVIDENCE",
      "updated_utc": "2026-11-11T01:18:14.515799+00:00",
      "worker_processes": []
    },
    "Opt4-fit-svb-system-r2-state.json": {
      "controller": {},
      "hardware_commit": "f2d2ca3ea0b12c918f2ccd2d1131be2709960470",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": " full_compare=%d cancelled=%d\\n), PrintPort(synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire,List((enable,UInt<1>), (args_0,UInt<3>), (args_1,UInt<32>), (args_2,UInt<2>), (args_3,UInt<1>), (args_4,UInt<1>)),EC_OPT4_PACKAGE_RESULT hart=%d seq=%x status=%d full_compare=%d cancelled=%d\\n)))\nGenerating a Midas Memory Model\n  Max Read Requests: 6\n  Max Write Requests: 6\n  Max Read Length: 8\n  Max Write Length: 8\n  Max Read ID Reuse: 1\n  Max Write ID Reuse: 1\n\nTiming Model Parameters\n  Timing Model Class: Latency Bandwidth Pipe\n  No LLC Model Instantiated\n\n\nDefault Settings\n  +mm_relaxFunctionalModel_0=0\n  +mm_writeMaxReqs_0=6\n  +mm_readMaxReqs_0=6\n  +mm_writeLatency_0=30\n  +mm_readLatency_0=30\n\nBridge Streams To CPU:\n  Name: TRACERVBRIDGEMODULE_0_to_cpu_stream, Idx: 0, FPGA Buffer Depth: 6144, FPGA Buffer Width: 64\n  Name: TRACERVBRIDGEMODULE_1_to_cpu_stream, Idx: 1, FPGA Buffer Depth: 6144, FPGA Buffer Width: 64\n  Name: TRACERVBRIDGEMODULE_2_to_cpu_stream, Idx: 2, FPGA Buffer Depth: 6144, FPGA Buffer Width: 64\n  Name: TRACERVBRIDGEMODULE_3_to_cpu_stream, Idx: 3, FPGA Buffer Depth: 6144, FPGA Buffer Width: 64\n  Name: TRACERVBRIDGEMODULE_4_to_cpu_stream, Idx: 4, FPGA Buffer Depth: 6144, FPGA Buffer Width: 64\n  Name: PRINTBRIDGEMODULE_0_to_cpu_stream, Idx: 5, FPGA Buffer Depth: 6144, FPGA Buffer Width: 64\n  Name: PRINTBRIDGEMODULE_1_to_cpu_stream, Idx: 6, FPGA Buffer Depth: 6144, FPGA Buffer Width: 64\nBridge Streams From CPU:\n  None\nSimulator Memory Map:\n  [   0,   7f]: FASEDMemoryTimingModel_0\n  [  80,   ff]: BlockDevBridgeModule_0\n  [ 100,  13f]: TSIBridgeModule_0\n  [ 140,  17f]: TracerVBridgeModule_0\n  [ 180,  1bf]: TracerVBridgeModule_1\n  [ 1c0,  1ff]: TracerVBridgeModule_2\n  [ 200,  23f]: TracerVBridgeModule_3\n  [ 240,  27f]: TracerVBridgeModule_4\n  [ 280,  2bf]: LoadMemWidget_0\n  [ 2c0,  2df]: PeekPokeBridgeModule_0\n  [ 2e0,  2ff]: UARTBridgeModule_0\n  [ 300,  31f]: ClockBridgeModule_0\n  [ 320,  33f]: PrintBridgeModule_0\n  [ 340,  35f]: PrintBridgeModule_1\n  [ 360,  37f]: CPUManagedStreamEngine_0\n  [ 380,  38f]: SimulationMaster_0\n  [ 390,  397]: ResetPulseBridgeModule_0\nTotal Host-FPGA DRAM Allocated: 16.000 GiB of 16.000 GiB available.\nHost-FPGA DRAM Allocation Map:\n  MainMemory_0 -> [0x0, 0x3FFFFFFFF]\n    Associated bridges: FASEDMemoryTimingModel_0\nAuto ILA: p(EnableAutoILA) unset. Skipping AutoILATransform\n",
      "pid": 1978586,
      "source_id": "f678ac806ea4b0f801596b26ec8bf9ef914a3161b39f92564ac25452abd8eafc",
      "stage_log": {
        "bytes": 7576,
        "mtime_ns": 1794360896133383977,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-system-r2-20261111/goldengate-attempt-1.log"
      },
      "stage_process": {},
      "start_ticks": "17168869",
      "status": "RTL_READY_REAL_ABI_CHECKED",
      "updated_utc": "2026-11-11T01:37:40.297207+00:00",
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
    "Opt4-fit-update-share-svb-r2-state.json": {
      "controller": {},
      "hardware_commit": "e0c3737f989c563f99a00f3fd26c1cbd27421775",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "pid": 2218872,
      "source_id": "b058237185f3c6f1c730e4a128e4c3670299eb45a250627fa61aeb3eb631d235",
      "start_ticks": "17843829",
      "status": "PASS_COMPOSED_SOURCE_BOUND_MODULE_EQUIVALENCE_TYPECHECKED_NOT_FULL_DUT_FORMAL_OR_CAD",
      "updated_utc": "2026-11-11T03:14:14.932051+00:00",
      "worker_processes": []
    },
    "Opt4-fit-update-share-svb-rtl-state.json": {
      "controller": {},
      "hardware_commit": "e0c3737f989c563f99a00f3fd26c1cbd27421775",
      "identity_live": false,
      "source_id": "b058237185f3c6f1c730e4a128e4c3670299eb45a250627fa61aeb3eb631d235",
      "status": "GOLDENGATE_COMPLETE_NOT_SYNTHESIZED"
    },
    "Opt4-fit-update-share-svb-software-prep-r3-state.json": {
      "controller": {},
      "error": "PermissionError(13, 'Permission denied')",
      "hardware_commit": "e0c3737f989c563f99a00f3fd26c1cbd27421775",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "pid": 2299140,
      "source_id": "b058237185f3c6f1c730e4a128e4c3670299eb45a250627fa61aeb3eb631d235",
      "start_ticks": "17989233",
      "status": "FAILED_WITH_EVIDENCE",
      "worker_processes": []
    },
    "Opt4-fit-update-share-svb-software-prep-r4-state.json": {
      "controller": {},
      "hardware_commit": "e0c3737f989c563f99a00f3fd26c1cbd27421775",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "pid": 2308129,
      "source_id": "b058237185f3c6f1c730e4a128e4c3670299eb45a250627fa61aeb3eb631d235",
      "start_ticks": "18007475",
      "status": "13_ORDINARY_PROGRAMS_EXACT_PAIRED_SOFTWARE_READY_NOT_FPGA_ADMITTED",
      "updated_utc": "2026-11-11T03:39:15.964896+00:00",
      "worker_processes": []
    },
    "Opt4-fit-update-share-svb-system-r3-state.json": {
      "controller": {},
      "hardware_commit": "e0c3737f989c563f99a00f3fd26c1cbd27421775",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "log_tail": " full_compare=%d cancelled=%d\\n), PrintPort(synthesizedPrintf_lazyModule_system_tile_prci_domain_3_tile_reset_domain_tile_core_printf_1_wire,List((enable,UInt<1>), (args_0,UInt<3>), (args_1,UInt<32>), (args_2,UInt<2>), (args_3,UInt<1>), (args_4,UInt<1>)),EC_OPT4_PACKAGE_RESULT hart=%d seq=%x status=%d full_compare=%d cancelled=%d\\n)))\nGenerating a Midas Memory Model\n  Max Read Requests: 6\n  Max Write Requests: 6\n  Max Read Length: 8\n  Max Write Length: 8\n  Max Read ID Reuse: 1\n  Max Write ID Reuse: 1\n\nTiming Model Parameters\n  Timing Model Class: Latency Bandwidth Pipe\n  No LLC Model Instantiated\n\n\nDefault Settings\n  +mm_relaxFunctionalModel_0=0\n  +mm_writeMaxReqs_0=6\n  +mm_readMaxReqs_0=6\n  +mm_writeLatency_0=30\n  +mm_readLatency_0=30\n\nBridge Streams To CPU:\n  Name: TRACERVBRIDGEMODULE_0_to_cpu_stream, Idx: 0, FPGA Buffer Depth: 6144, FPGA Buffer Width: 64\n  Name: TRACERVBRIDGEMODULE_1_to_cpu_stream, Idx: 1, FPGA Buffer Depth: 6144, FPGA Buffer Width: 64\n  Name: TRACERVBRIDGEMODULE_2_to_cpu_stream, Idx: 2, FPGA Buffer Depth: 6144, FPGA Buffer Width: 64\n  Name: TRACERVBRIDGEMODULE_3_to_cpu_stream, Idx: 3, FPGA Buffer Depth: 6144, FPGA Buffer Width: 64\n  Name: TRACERVBRIDGEMODULE_4_to_cpu_stream, Idx: 4, FPGA Buffer Depth: 6144, FPGA Buffer Width: 64\n  Name: PRINTBRIDGEMODULE_0_to_cpu_stream, Idx: 5, FPGA Buffer Depth: 6144, FPGA Buffer Width: 64\n  Name: PRINTBRIDGEMODULE_1_to_cpu_stream, Idx: 6, FPGA Buffer Depth: 6144, FPGA Buffer Width: 64\nBridge Streams From CPU:\n  None\nSimulator Memory Map:\n  [   0,   7f]: FASEDMemoryTimingModel_0\n  [  80,   ff]: BlockDevBridgeModule_0\n  [ 100,  13f]: TSIBridgeModule_0\n  [ 140,  17f]: TracerVBridgeModule_0\n  [ 180,  1bf]: TracerVBridgeModule_1\n  [ 1c0,  1ff]: TracerVBridgeModule_2\n  [ 200,  23f]: TracerVBridgeModule_3\n  [ 240,  27f]: TracerVBridgeModule_4\n  [ 280,  2bf]: LoadMemWidget_0\n  [ 2c0,  2df]: PeekPokeBridgeModule_0\n  [ 2e0,  2ff]: UARTBridgeModule_0\n  [ 300,  31f]: ClockBridgeModule_0\n  [ 320,  33f]: PrintBridgeModule_0\n  [ 340,  35f]: PrintBridgeModule_1\n  [ 360,  37f]: CPUManagedStreamEngine_0\n  [ 380,  38f]: SimulationMaster_0\n  [ 390,  397]: ResetPulseBridgeModule_0\nTotal Host-FPGA DRAM Allocated: 16.000 GiB of 16.000 GiB available.\nHost-FPGA DRAM Allocation Map:\n  MainMemory_0 -> [0x0, 0x3FFFFFFFF]\n    Associated bridges: FASEDMemoryTimingModel_0\nAuto ILA: p(EnableAutoILA) unset. Skipping AutoILATransform\n",
      "pid": 2237267,
      "source_id": "b058237185f3c6f1c730e4a128e4c3670299eb45a250627fa61aeb3eb631d235",
      "stage_log": {
        "bytes": 7576,
        "mtime_ns": 1794367967399774114,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-update-share-svb-system-r3-20261111/goldengate-attempt-1.log"
      },
      "stage_process": {},
      "start_ticks": "17874132",
      "status": "RTL_READY_REAL_ABI_CHECKED",
      "updated_utc": "2026-11-11T03:35:52.412846+00:00",
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
    "Opt4-svb-invalidation-validation-r2-state.json": {
      "controller": {},
      "hardware_commit": "f2d2ca3ea0b12c918f2ccd2d1131be2709960470",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "pid": 1966395,
      "source_id": "f678ac806ea4b0f801596b26ec8bf9ef914a3161b39f92564ac25452abd8eafc",
      "start_ticks": "17127125",
      "status": "PASS_REAL_RTL_SVB_INVALIDATION_OWNER_DATA_AND_NEGATIVE_ACK_NOT_ARCHITECTURAL_ROLLBACK",
      "updated_utc": "2026-11-11T01:12:35.948202+00:00",
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
  "utc": "2026-11-11T03:41:46.780299+00:00"
}

Previous round directories: /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/unattended-opt4/rounds
