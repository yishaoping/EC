# Original SVB actual-host40 shell postroute recovery r2

Explicitly admitted extra **small component** postroute slot: CPUs224-225,64GiB address-space and memory cap; before each strategy require256GiB MemAvailable,150GiB disk,load<48 and fewer than3 actual component Vivado workers. Existing50MHz/r51/r3/r4/host40r1 inputs and services are untouched. No full RTL synthesis or third large Opt4 CAD. Independent single-instance lock controls only this extra slot.

Actual host40 sealed DCP derives from physical MMCM divider30, targetRTL/bridge ratios unchanged, all66 clocks pinned. Worst shell path is asyncFIFO pointer FDCE→RAMD32→FDRE in250MHz XDMA domain, WNS-0.424ns,95.5% route; second worst is XDMA reset FDCE→FDRE reset,98.1% route. Route-only TNS cleanup does not fix WNS according to real2021.1 help.

A: postroute `phys_opt_design -routing_opt -placement_opt` only (no retime/register insertion) → saved physical DCP → legal route Explore/tns_cleanup → full gates. B only after A fails: reuse A's saved final routed DCP when available; obtain safe FD-Q driver nets directly from actual negative shell setup paths, exclude target/ASYNC_REG/DONT_TOUCH and low fanout, bounded at32nets; force physical driver replication → route → full gates. Every attempt immutable with result, checksums, logs and checkpoints; no repeated A or source synthesis. No automatic kill merely from silent tool logs.

Each bit candidate requires unchanged MMCM and66-clock contract, setup/hold, full route, DRC, coverage, pulse and bus-skew. New r2 independent certificate restores actual final DCP and repeats the gates. It never reuses50MHz certificate. Physical host frequency is separate from target cycle counts.

New rootruntime and application follower use shared21 locks, guarded driver and source/trace/ABI hashes. Existing valid original component wins. If old host40r1 rootfollower remains a proved idle one-Python-process waiter, r2 may hand off that controller only while both21 locks held and r2 certificate exists; audit/running/deploying/child states are never stopped. r1CAD remains untouched. Application follower never redeploys; it requires latest bitstream SHA matches r2. No e2/global PCIe/driver operation.

CAD outputs/state: cycleprecise-svb-host40-shell-recovery-r2-20261112. Directed board run: cycleprecise-original-svb-host40-shell-onboard-r2-20261112. Real application replay: cycleprecise-original-svb-host40-shell-application-onboard-r2-20261112. All under Experiment/firesim-final-opt4-20261106. No certification or board data is claimed at installation.
