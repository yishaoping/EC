# Causal attribution

`MISS_TO_CRITICAL_PATH_REDUCTION = NOT_PROVEN` as a strict geometry-only claim, because old A/new B differ in checker repair and A noninterference is not proved. The reference signal is strong enough to justify exactly one corrected A-prime.

Chain A: actual lookup misses3,272→2,624 (−648,−19.8044%); exact-ROI load tag misses1,533→1,060 (−473). ROB-head miss waiting139,694→53,845 (−85,849,−61.4550%); ROI1,707,863→1,648,923 (−58,940,−3.4511%). All directions agree. Head-wait saving is1.4565× the net ROI saving and is large enough to accompany the full net gain, but it cannot be assigned as85,849 recoverable geometry cycles.

Exact observed ROI partition:

| Partition | Old A | New B | B−A |
|---|---:|---:|---:|
| head miss only |139677|53845|−85832|
| scheduler only |318133|347409|+29276|
| both |17|0|−17|
| neither |1250036|1247669|−2367|

The partition sums explain the arithmetic ROI difference:85,832+17−29,276+2,367=58,940. They are labels on different dynamic executions, not independent interventions or an additive counterfactual proof. Scheduler-unavailable exposure increases29,259 total cycles; it offsets some observed head-wait reduction in this partition.

Chain B: nack retry111,548→47,162 (−64,386,−57.7204%, substantial). RPQ replay321→229 (−92,−28.6604%). MSHR-not-ready nack exposure111,074→39,072, while victim nack474→8,087 increases and writeback nack3,885→2,354 decreases. These reason predicates may overlap; do not sum them or treat every MSHR-not-ready nack as full-capacity pressure. Full remains0; address/state/victim conflicts can reject requests with free MSHRs.

The large decline in retry and replay pressure accompanies lower head waiting and shorter ROI, supporting a second plausible chain. Existing aggregates do not join each nack to a particular critical miss or prove the entire64,386 retry reduction is responsible for the ROI saving. Never multiply retries or misses by a fixed penalty. Miss→data mean347.84→200.61 and allocation→refill mean126.95→83.55 support lower observed wait, but cohorts and checker timing changed.

MSHR busy313,150→194,905 is a resource exposure. scheduler∩busy154→269, scheduler∩full0→0, full0→0. There is no evidence to reopen an MSHR-count optimization. Partial overlaps, STOP windows and exact-ROI counters are not added together.
