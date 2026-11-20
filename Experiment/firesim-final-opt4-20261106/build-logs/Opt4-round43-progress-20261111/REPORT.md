# Round43 evidence and continuation

Baseline8491167d; target v1Config/C4/SVB32 unchanged. Native paused,21-only certification services adopted; worker performed no FPGA I/O.

9ae whole postopt remains NOT FIT:2,847,382LUT/90,740CARRY8/195DSP; LUT excess1,543,702. e0 and d9/3656/fullpair maps remain source/PID-bound and untouched.

Recovered the owner-only full-system GG audit in independent r3. The prior r2 hash failure remains preserved: its stage receipt binds raw SV before the producer's recorded892-byte black-box suffix. r3 independently authenticates original raw prefix SHA, exact ordered suffix, assembled SHA and header/pre-host FIR hashes. Complete pre-host target FIR is byte identical; original DCache statements and35image/518generation read observations/reset/writer gates match after expected memory wrapping. Three assembly mutations rejected; prior wrapper mutations bound. This is structural evidence, not full host runtime equivalence or FIT. Result:/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-dcache-owner-audit-round43-r3-20261111/result.json

Prepared MC and Plain full-host models from the same3656 target. Copied each model's own generated SV/header/XDC collateral, authenticated280 inputs and22 staged files, and retained fresh driver compilation per model. Sequential2CPU/64GiB compile,96GiB available memory/100GiB disk guards; no new GG, whole CAD, workload or hardware action. Broker receipt:DEFERRED; currently queued at the campaign CPU limit, not running. Plan:/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-owner-pair-compile-round43-v1-20261111/build-plan.json

Independently paired all131 BOOM allocations and131 BOOM accepted results with local checker results, all full_compare/PASS, harts33/33/33/32, unmatched0. Checked unique sequences1..131, raw payload sequence/status and ordering. Five checker/status/payload/duplicate/missing mutations rejected. Used only common BOOM clocks for allocation-to-acceptance:mean11257.480916,median10092,P9517823,P9919684,max20084 cycles. This is not checkerDone-minus-BOOMDone, SVB/memory global drain or FPGA evidence. Immutable CSV/histogram:/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-boom-accepted-evidence-round43-v1-20261111

Existing r5 complete-payload observer, original fullMCRams parity, two original SVB physical routes and21-only followers/timers are adopted. No duplicated workload, CAD, deployment or Native job. Router intermediate reports remain timing risks; setup/hold/DRC/certification must actually pass.

Sprint deadline:2026-11-12T08:52:10.022583+00:00. Snapshot2026-11-11T14:06:56.359790+00:00:available memory368.63GiB,free disk311.21GiB,load26.93 31.72 34.22 29/25872 1442271. No measured fullOpt4 FIT or FPGA sample.

Next:existing r5 completion -> automatic standalone frozenSVB full payload replay/mutation -> separately certified matching component replay. Let the queued owner pair compile enter an ordinary slot; after both compile receipts prepare same-ELF/memory timing/target-cycle parity. Preserve live e0, maps and both routing jobs; normal checks>=300s, whole>=600s.
