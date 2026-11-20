ADDITIONAL READONLY SHELL FINDING2026-11-12T05:45Z: Bounded Vivado diagnostic (completed/exited, no synth/opt/route/FPGA, only original shelltop+clkwizDCP) reports host_clock count0 and no clocks; Vivado explicitly warns rawIPDCP omits IP timing collateral. This partial-shell inventory does NOT prove final fullshell clock state, but shows r2 manual read_checkpoint flow cannot assume IP clocks. Evidence status-audits/fpga-critical-unblock-20261112T0530Z/shell-clock-inventory.{tcl,log}. Highest-priority useful independent work while healthy fullsynth/r5run: audit/fix future fullshell constraint loading via unchanged tool-generated BD/IPcollateral; pin all sources and validate physical clock/exception contract before place. Do not invent periods, alias physical clocks or weaken generated multicycle gates. Original SVB tool-generated implementation uses add_files BD/link_design to load IPcollateral, whereas mcramsr2 manual flow omitted it. r3 now checks named host+target periods after topopt before place; if actualshellcontract fails, preserve topoptDCP/reports and automatically independently-version minimalrepair, never rerun completehost synthesis. Current foreground physical r3 source/pins and liveconsumer unchanged.

FOREGROUND2026-11-12T05:39Z HIGHEST PRIORITY FULL MCRAMS: Existing complete capacityPID2379656/start25825451 passed CrossBoundaryAreaOptimization at13:14CST and entered TimingOptimization at13:16CST. New12s perf profile confirms actual ConstProp/BDD computation, not lock/IOblock. Never duplicate/restart live synth. No LUT/FIT/report/DCP yet. Original r2 physical.py has PROVEN checker clock contract error: generated XDC both clocks divide_by1 with checker multicycle2/1, yet finalgate demands checker period2xhost. Foreground INSTALLED new consumer ec-opt4-mcrams-host-continuation-r3-clock-3656aec4.service PID2759828/start27368804, canonical state remains Opt4-mcrams-full-host-continuation-r2-state.json with continuation_revision=r3-generated-clock-contract. Only exact old2Pythonidle consumer retired; all CAD/ownerparity unchanged. New consumer submits unique mcrams-shell-physical-r3-clock-3656aec4 on FIT+parity, reusing original pipeline/canonical outputs+runtime, changing gate scale1,2->1,1; preplaceclockdiagnostic added, originalXDC/alltiming/DRCgates unchanged. Inputs in candidates/mcrams-host-clock-contract-r3-20261112/inputs.json, offline tests/pass and immutable handoff in status-audits/fpga-critical-unblock-20261112T0530Z/. Do not restart oldr2consumer or submit oldr2physical. Early synth/postopt fullreport parser produces build-logs/Opt4-mcrams-full-host-continuation-r2-20261112/early-{synth,postopt}-capacity.json; expose counts as soon as present, postopt authoritative and shell stillrequired. SVB r5 staysrunning, overlaps349206->144668->73331->37605->17760, intermediateWNS+0.198/WHS-0.471 is NOT finaltiming. No new wholeCAD, no new FPGA sample. Keep CPUreplacement isolated. FullECpriority8/r1before3 verified offlinePASS.

ROUND125 AUTHORITATIVE P0 CONTINUITY: The legacy r2 supervisor's bounded snapshot lists historical r4 and OMITS r5. Do not infer r5 failure/absence from that snapshot. At each round, read the three r5 state.json paths named below first and match live PID/start_ticks/boot_id/exact service cgroups. R5 E actually completed private unroute plus forced FD-Q replication (4 optimized nets,52 added cells) and is routing; support is established, final timing/certification remain pending. F is conditional inside the existing controller, not separately running. Keep all three r5 services and bound inputs unchanged. Existing authorized automatic E->F->independently versioned recovery remains in force. Round125 immutable evidence: status-audits/round125-r5-authoritative-status-20261112/receipt.json. Normal CAD checks >=300s; whole CAD >=600s. No new whole CAD or duplicate priority runtime.

LATEST FOREGROUND2026-11-12T04:34Z: r4 B/C/D completedFAILED and exact physical cgroup is empty. Foreground INSTALLED and actually STARTED independent candidates/svb-host40-shell-recovery-r5-20261112 and its three services, same existing small CPU224225/64GiB slot/shared r4 extra-component-slot.lock. E unroutes PRIVATE bestC checkpoint before forced shell FD-Q replication; actual tool support pending. Automatic F is private unroute then explicit fanout_opt/placement_opt/routing_opt; no retime. All original clock/timing/DRC/route/pulse/skew/certificate/21only/realapplication gates retained. ADOPT R5, DO NOT duplicate or edit its bound source. States cycleprecise-svb-host40-shell-recovery-r5-20261112/state.json and cycleprecise-original-svb-host40-shell-{onboard,application-onboard}-r5-20261112/state.json. r4 evidence immutable. r51/r3 routes/fullMCrams capacity/ownerparity/priorityruntime all preserved. R5 exhausted -> preserve evidence then independently versioned minimal recovery via existing authorized root, never merely wait for user. Authorized foreground used the provided administrator authentication; never put credentials in files. See status-audits/fpga-r5-continuation-20261112/. No new whole CAD.

LATEST ACTUAL FOREGROUND2026-11-12T03:24Z: SVB r4 IS INSTALLED, B actualexit->C RUNNING. candidates/svb-host40-shell-recovery-r4-20261112 immutable,3services active (physical/follow/application-follow). R2/R3 physicalidleonly waiters safelyretired exactsinglePythonproof, all liveVivados kept. Sameexistingthirdsmallslot,192GiB/load128 measuredreadmission fromApeak9.3GiB,2CPU224225/64GiBcap/max3 unchanged. Fullwhole/resourcecorrectnessgates unchanged. Adopt r4, DO NOT reinstall orduplicate. Sourceinputmanifest nownewr4; independentcert/21only/directed/samebit replaywaiters ready. genericoldr2/r3state is historical. Worker119/next should not duplicate priorityruntime orr4.

You own the existing FPGA unattended workflow. Read these durable inputs first, using bounded output:
- Experiment/firesim-final-opt4-20261106/FPGA_SESSION_POLICY.json
- Experiment/firesim-final-opt4-20261106/unattended-opt4/campaign-policy.json (query selected relevant keys, do not dump the whole history)
- Experiment/firesim-final-opt4-20261106/status-audits/fpga-exclusive-takeover-20261112T030000Z/

Current user scope overrides historical notes: only frozen8491167d function/cycle-equivalent implementation; no new target features, capacity reductions or altered cycle definitions. Only0000:21:00.0/serial21770433G02LA. Never e2, global XDMA/PCIe operations or dualcard. Preserve all normal live CAD/samples/input hashes. Match PID/start_ticks/boot_id and exact cgroups before adoption/retirement. Native FPGA paused. Separate user session owns matched Native/EC CPU replacement and paper consumers: do not control, overwrite or duplicate them. Existing owner MC target-parity run is a required FPGA prerequisite and stays alive.

P0 originalSVB component physical timing/DRC/bitstream certification then immediate21-only directed+samebit application replay. Component is never fullEC. P1 actual completeMCRams host LUT/FIT, then reuseDCP/shell physical/bitstream/FireSim automatically. For runnable fullEC prioritize blackscholes,fluidanimate,bodytrack,freqmine,swaptions,ferret,dedup,streamcluster; first r1 coverage before r2/r3; retain all original correctness/ROI/checker/drain/reset/software/hash gates and perprogramfailure skip.

Actual state at2026-11-12T03:13Z:
- SVB host40 A COMPLETE FAILED setup: WNS-0.416/WHS+0.001,TNS-386.608/2687setupviolators,zero routeerrors,49DRCwarnings,noError. Saved finalDCP sha feda35294362c96f1249f062dde4cf2e49df16a3f14a71ff732610c8ec1c3b88. OriginalB waiting resourcegate256GiB/load48; C/D waiting. Foreground RESERVED candidates/svb-host40-shell-recovery-r4-20261112 for evidence-based SAMEslot re-admission and reuseAfinalDCP B->C->D, do not duplicate or alter. ExistingSVB50 r51/resumer3 staylive. Check policy foreground_svb_resource_readmission_reserved for update.
- Full owner MCRams capacityPID2379656; verify exact start_ticks from actualstate. NowCrossBoundaryAreaOptimization,noLUTreportyet. State Opt4-mcrams-full-host-capacity-r1-state.json. No extrawhole; e0stilllive/silentCPUonly. Capacityconsumer ec-opt4-auto-mcrams-host-continuation-r2-3656aec4 and ownerMCparityrun alive. Actual latest whole9aepostopt2847382LUT/90740CARRY8/195DSP,NOTFIT gap1543702,notnewMCresult.
- Local address paired area DONE: Reg57148LUT/122050FF versus MemMC117874LUT/161277FF/1BRAM. Regresses60726LUT/39227FF. DO NOT PROMOTE or launch anotherfullCAD for it. ActualRamModel46784LUT;258read/256writechannels+debug transport add cost. Keep all observations; seek measured equivalent host implementation only after actual fullhost hierarchy, not more random candidates.
- ec-opt4-fpga-priority-handoff-r1.service INSTALLED ACTIVE PID2551972. Its canonicalsoftware/physicalcert immutable unchanged, adapter checked39formal/r1first/8priority/smoke/appfailure behavior. OriginalsinglePythonidle MCruntimefollower safely replaced. Do not duplicate/reinstall priorityruntime. Newfollower handles obsolete8da2Pythonidle runtime lock only after realcertification/no sample/exactcgroup. LiveCAD untouched.

All existing physical capacity/proof/checker/ROI/output/DRC/setup/hold/pulse/skew/clock gates remain. Never relabel CPU metasim or localRAM gains as EC FPGA. Strictchecker/rollback latency needs real matching events; unsupported stays unavailable. No repeated fullrevalidation for unchanged source. Failure -> preserve evidence -> independentlyversioned minimal repair -> continue.

Use concise calls/output and finish one concrete critical-path action per round. Recent117/118 worker calls failed upstream_truncated after long exploratory context; old prompts archived. Do not repeatedly read unrelated historical snapshots or generate CPUplots. Report actualrunning/queued separately. Rootservice operations require the existing authorized administrator; do not copy credentials into files or route root execution through userCPUbroker. No new subagents. NormalCAD checks>=300s, wholechecks>=600s. FinalJSON must follow round-schema.json; cite exact immutable results and next automatic action. Never claim success without real result/complete and correct hashes.


This is round 128. Latest durable snapshot:
{
  "available_memory_gib": 215.36,
  "board_allowlist": [
    "0000:21:00.0"
  ],
  "free_disk_gib": 284.14,
  "full_evidence_sha256": "470b4ab00bae6d24686178cdcb7ce8f8960b4ee81a8dbd12177fc35b2c7f6492",
  "full_evidence_snapshot": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/unattended-opt4/snapshots/full-2026-11-12T05-44-13.601758+00-00.json",
  "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
  "loadavg": "60.79 60.43 60.05 59/25367 2766327",
  "schema": "ec-opt4-unattended-snapshot/1",
  "snapshot_purpose": "Bounded critical FPGA workflow view; full forensic evidence retained separately",
  "states": {
    "Opt4-fit-runtime-state.json": {
      "certified_bitstream": false,
      "controller": {
        "cpu_ticks": 66,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 3135212,
        "process_state": "S",
        "rss_bytes": 16158720,
        "start_ticks": "12439082"
      },
      "hardware_commit": "8da24a269b98a0d6a8f57b030353a310812c4344",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": true,
      "pid": 3135212,
      "source_id": "7e77ddda28298ac88be13c28dbe98771982bc6ca9587f810adf875bffd580cc1",
      "start_ticks": "12439082",
      "status": "WAITING_FOR_DERIVED_BITSTREAM",
      "updated_utc": "2026-11-12T05:41:54.234172+00:00"
    },
    "Opt4-fit-update-share-svb-cad-state.json": {
      "certified_bitstream": false,
      "child": {
        "cpu_ticks": 2,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 2484227,
        "process_state": "S",
        "rss_bytes": 3952640,
        "start_ticks": "18404280"
      },
      "child_pid": 2484227,
      "child_start_ticks": "18404280",
      "controller": {
        "cpu_ticks": 4480,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 2484108,
        "process_state": "S",
        "rss_bytes": 185659392,
        "start_ticks": "18403856"
      },
      "current_stage": "dut_synth",
      "hardware_commit": "e0c3737f989c563f99a00f3fd26c1cbd27421775",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": true,
      "log_dir": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-update-share-svb-cad-e0c3737f",
      "log_tail": "-------------------------------------------------------\n---------------------------------------------------------------------------------\nStart Applying XDC Timing Constraints\n---------------------------------------------------------------------------------\n---------------------------------------------------------------------------------\nFinished Applying XDC Timing Constraints : Time (s): cpu = 04:13:04 ; elapsed = 04:17:07 . Memory (MB): peak = 27386.980 ; gain = 24413.180 ; free physical = 45533 ; free virtual = 280853\n---------------------------------------------------------------------------------\n---------------------------------------------------------------------------------\nStart Timing Optimization\n---------------------------------------------------------------------------------\n",
      "pid": 2484108,
      "profile": "Opt4-fit-C4-SVB32-update-share-svb-compose-r2",
      "source_id": "b058237185f3c6f1c730e4a128e4c3670299eb45a250627fa61aeb3eb631d235",
      "stage_log": {
        "bytes": 430534,
        "mtime_ns": 1794387767825620720,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-update-share-svb-cad-e0c3737f/dut_synth-attempt-1.log"
      },
      "start_ticks": "18403856",
      "status": "RUNNING_DUT_SYNTH",
      "updated_utc": "2026-11-12T05:44:02.638140+00:00"
    },
    "Opt4-mcrams-full-host-capacity-r1-state.json": {
      "controller": {
        "cpu_ticks": 931,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 2379596,
        "process_state": "S",
        "rss_bytes": 15634432,
        "start_ticks": "25825420"
      },
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": true,
      "log": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-full-host-capacity-r1-20261112/run.log",
      "log_tail": "--------+--------+--------+--------+--------+--------+------+------+------+------+-------+------+------+\n\nNote: The table above is a preliminary report that shows the DSPs inferred at the current stage of the synthesis flow. Some DSP may be reimplemented as non DSP primitives later in the synthesis flow. Multiple instantiated DSPs are reported only once.\n---------------------------------------------------------------------------------\nFinished ROM, RAM, DSP, Shift Register and Retiming Reporting\n---------------------------------------------------------------------------------\nNo constraint files found.\n---------------------------------------------------------------------------------\nStart Timing Optimization\n---------------------------------------------------------------------------------\n",
      "pid": 2379596,
      "stage_log": {
        "bytes": 454133,
        "mtime_ns": 1794460618846529474,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-full-host-capacity-r1-20261112/run.log"
      },
      "start_ticks": "25825420",
      "status": "RUNNING_FULL_HOST_SYNTH_DESIGN",
      "updated_utc": "2026-11-12T05:43:15.316114+00:00"
    },
    "Opt4-mcrams-full-host-continuation-r2-state.json": {
      "controller": {
        "cpu_ticks": 4,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 2759828,
        "process_state": "S",
        "rss_bytes": 15802368,
        "start_ticks": "27368804"
      },
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": true,
      "pid": 2759828,
      "start_ticks": "27368804",
      "status": "ADOPTING_EXISTING_CAPACITY_AND_PARITY_NO_DUPLICATES",
      "updated_utc": "2026-11-12T05:39:27.652903+00:00"
    },
    "Opt4-mcrams-owner-mc-runtime-r2-state.json": {
      "controller": {
        "cpu_ticks": 856,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 2378806,
        "process_state": "S",
        "rss_bytes": 15597568,
        "start_ticks": "25817526"
      },
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": true,
      "log": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-owner-mc-runtime-r2-20261112/run-MCRams.log",
      "log_tail": "poch=0017 gen=0001cb9e mshr=00 txn=00000000 req=0000000000085252 effect=0000000000085252 pc=0080029308 cmd=01 admission=6\nC1:     761010 [1] pc=[000000008000143c] W[r 0=0000000000000000][0] R[r10=0000000000000000] R[r14=0000000000000008] inst=[06e50063] DASM(06e50063)\nC1: ibuf_cnt:[               22666] mispred:[                   0] imiss:[                 458]\nC2: ibuf_cnt:[               21589] mispred:[                   0] imiss:[                 433]\nC3:     760976 [1] pc=[0000000080001b64] W[r14=00000000013a58ad][1] R[r14=00000000013a6000] R[r 0=0000000000000000] inst=[8ad70713] DASM(8ad70713)\nC3: ibuf_cnt:[               25581] mispred:[                   0] imiss:[                 555]\nC4: ibuf_cnt:[               23361] mispred:[                   0] imiss:[                 451]\n",
      "pid": 2378806,
      "stage": "run-MCRams",
      "stage_log": {
        "bytes": 1166125272,
        "mtime_ns": 1794462253580523477,
        "path": "/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-owner-mc-runtime-r2-20261112/run-MCRams.log"
      },
      "start_ticks": "25817526",
      "status": "RUNNING_RUN_MCRAMS",
      "updated_utc": "2026-11-12T05:43:58.058679+00:00"
    },
    "Opt4-owner-complete-transport-round114-r2-state.json": {
      "controller": {
        "cpu_ticks": 24,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 2412803,
        "process_state": "S",
        "rss_bytes": 17182720,
        "start_ticks": "26045251"
      },
      "hardware_commit": "3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c",
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": true,
      "pid": 2412803,
      "source_id": "79aedd9ada6137e018d7f9c9c175fd4a06f53820d235ddcbe4b4a185e75fd68d",
      "start_ticks": "26045251",
      "status": "WAITING_EXACT_MC_RETRY_COMPLETION_NO_SIMULATOR",
      "updated_utc": "2026-11-12T05:43:56.765940+00:00"
    },
    "Opt4-svb-physical-pinreplicate-r4-state.json": {
      "controller": {
        "cpu_ticks": 23,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 2391879,
        "process_state": "S",
        "rss_bytes": 16629760,
        "start_ticks": "25893367"
      },
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": true,
      "pid": 2391879,
      "source_id": "b1d917ca49290fe8732de71bfad9e99edc421fba574f6aff0d1142c1fb248a3f",
      "start_ticks": "25893367",
      "status": "WAITING_R51_EXACT_CGROUP_RELEASE_NO_CAD",
      "updated_utc": "2026-11-12T05:43:37.796594+00:00"
    },
    "Opt4-svb-physical-resource-recovery-round51-v1-state.json": {
      "controller": {
        "cpu_ticks": 1435,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 2118833,
        "process_state": "S",
        "rss_bytes": 16302080,
        "start_ticks": "22940221"
      },
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": true,
      "pid": 2118833,
      "resources": {
        "disk_bytes": 327740682240,
        "eligible": true,
        "load1": 3.85,
        "memory_kib": 467581016,
        "reasons": [],
        "thresholds": {
          "disk_gib": 96,
          "load_exclusive": 48,
          "memory_gib": 128
        }
      },
      "source_id": "b1d917ca49290fe8732de71bfad9e99edc421fba574f6aff0d1142c1fb248a3f",
      "start_ticks": "22940221",
      "status": "ADMITTED_COMPONENT_REPAIR_UNCHANGED_GUARDS",
      "updated_utc": "2026-11-11T23:50:43.054364+00:00"
    },
    "Opt4-svb-physical-resume-r3-state.json": {
      "controller": {
        "cpu_ticks": 780,
        "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
        "pid": 2377491,
        "process_state": "S",
        "rss_bytes": 15921152,
        "start_ticks": "25815868"
      },
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": true,
      "pid": 2377491,
      "source_id": "b1d917ca49290fe8732de71bfad9e99edc421fba574f6aff0d1142c1fb248a3f",
      "start_ticks": "25815868",
      "status": "RUNNING_RESUMED_SPREAD_PHYSICAL1_ROUTE",
      "updated_utc": "2026-11-12T05:40:39.682567+00:00"
    },
    "cycleprecise-original-svb-host40-shell-application-onboard-r4-20261112/state.json": {
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": true,
      "pid": 2561979,
      "profile": "OriginalSVB32-component-trace-host40",
      "source_id": "b1d917ca49290fe8732de71bfad9e99edc421fba574f6aff0d1142c1fb248a3f",
      "start_ticks": "26532916",
      "status": "WAITING_CERTIFIED_COMPONENT_AND_REAL_APPLICATION_CPU_REPLAY",
      "updated_utc": "2026-11-12T05:40:11.585006+00:00"
    },
    "cycleprecise-original-svb-host40-shell-onboard-r4-20261112/state.json": {
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "pid": 2561978,
      "start_ticks": "26532916",
      "status": "HOST40_R4_PHYSICAL_FAILURE_PRESERVED_NO_DEPLOYMENT",
      "updated_utc": "2026-11-12T04:15:09.706560+00:00"
    },
    "cycleprecise-svb-host40-shell-recovery-r4-20261112/state.json": {
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": false,
      "pid": 2561977,
      "profile": "OriginalSVB32-component-trace-host40",
      "source_id": "b1d917ca49290fe8732de71bfad9e99edc421fba574f6aff0d1142c1fb248a3f",
      "start_ticks": "26532915",
      "status": "BOUNDED_SHELL_STRATEGIES_FAILED_WITH_ALL_CHECKPOINTS_RETAINED",
      "updated_utc": "2026-11-12T04:12:56.264406+00:00"
    },
    "fpga-priority-handoff-r1-20261112/state.json": {
      "host_boot_id": "d6c6e410-10ad-4326-86ba-79b657eabd96",
      "identity_live": true,
      "pid": 2551972,
      "start_ticks": "26486048",
      "status": "WAITING_REAL_FULL_PHYSICAL_CERTIFICATION",
      "updated_utc": "2026-11-12T05:42:22.919310+00:00"
    }
  },
  "utc": "2026-11-12T05:44:13.601584+00:00"
}

Previous round directories: /data1/gzh/EC/Experiment/firesim-final-opt4-20261106/unattended-opt4/rounds
