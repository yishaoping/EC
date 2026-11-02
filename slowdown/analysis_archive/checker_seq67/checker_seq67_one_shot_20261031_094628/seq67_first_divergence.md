# seq67 first divergence

Evidence is immutable r2 (fingerprint b6f9a8739a0be1a64cd349625e37dc8b5b8cd246b418041bc3ee68dd1af414b1).
B: `/data1/gzh/EC/AI/TMP/l1_causal_opt5_probe_20261030_200000_4235a1de/revisions/r2/arms/B/runs/optimization_4_svb_20261030_135736_b3958002`. A: `/data1/gzh/EC/AI/TMP/l1_causal_opt5_probe_20261030_200000_4235a1de/revisions/r2/arms/A/runs/optimization_4_svb_20261030_135448_0c744900`.
SC column2 is the global BOOM-cycle label; column3 is checker-local cycle. Verilator `[1202000]` is not a software ROI stop.

| Global cycle | B checker3 fact | Meaning |
|---:|---|---|
| 939331 | seq63; new_package_seq67; context_idle1 | Previous ownership locally clean |
| 939333 | seq67; start_pending1; context_idle1 | Admitted but not executing |
| 939335 | start_pending1; context_idle1; Frontend clear pending | CPS/data ingress begins |
| **939415** | line63039, local469481; start_accepted1, context_idle0, excpt_mode1, local depth0, ICSL status1 | **First recorded invalid privileged entry into an architectural trap context** |
| 939417 | active1; excpt_mode1; local depth0 | Privileged checking owns package but not the real trap |
| 939817 | producer sealed, CSR/ECP required; exec_done0 | Producer completion does not imply checker instruction completion |
| 1070889 | no-progress timeout; CANCEL67 enqueue | Failure result, not ownership release |
| 1070891 | result queue valid, return_pending1, local trap_depth1 | Cancellation creates local trap wait from architectural excpt_mode |
| 1070897 | LSL/RSU/compare/ECP/Frontend clean, context_idle0 | Only context conjunct blocks result handoff |

The 939415 row rules out normal_start (requires context_idle), and rules out running fallback
(ICSL status1 means nonchecking; cleanup_done=true). Therefore registered `if_check_privrun`
was necessarily asserted. Its source is `RegNext(check_exception)`. Architectural excpt_mode
is also registered and became1 at the same edge; complete B SC6 prefix has no earlier
context change. This strongly supports a synthetic dispatch / real trap collision at the
preceding checker edge (global label939413). This is an inverse reconstruction, not a
sampled CSR exception/vector. Old generated Rocket.sv and R_ICSL.sv confirm both equations.

The old A retained 283 start rows, none with excpt_mode1, including checker3 seq67 at961545.
However 701 SC6 records were host-dropped later in A. Do not generalize those retained
rows into full-run noninterference. B host omitted0 SC6 rows; B has no final producer
footers because it aborted. See offline_evidence.json and old_generated_rtl_excerpt.txt.

Kind13 checker accepted/handoff counters remain14763/14730 across the failed seq67;
that is no recorded checker-Frontend delivery, not proof that every legacy handler
instruction was absent. No new waveform or hardware execution was performed.
