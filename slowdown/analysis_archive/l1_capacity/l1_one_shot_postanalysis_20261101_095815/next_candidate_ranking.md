# Next candidates (maximum3)

L1 capacity is not rejected: this reference signal qualifies for one strict baseline refresh. Do not spend the next experiment on a competing policy before resolving A-prime vs existing B.

|Rank / candidate|Measured evidence|Causal confidence|Opportunity ceiling / limits|Code complexity|New simulation needed?|
|---|---|---|---|---|---|
|1 L1D64KiB/2way|reference ROI−58,940; head miss wait−85,849; actual misses−648; nack−64,386|strong reference support; strict geometry effect pending|old head exposure139,694 is a conditional fixed-trace deletion envelope; no strict timing-feedback bound;58,940 is measured net difference, not guaranteed gain|existing one-parameter geometry; hardware area/timing cost not synthesized|one A-prime only; current B already valid|
|2 checker scheduler / admission critical gating|exact ROI scheduler-unavailable318,150→347,409; almost no intersection with MSHR busy; traffic ROB-no-commit∩IC318,493→340,519|large exposure; recoverability unproven|347,409 exposure is not a recoverable bound; requires package/commit identity and alternate-safe-admission proof|high: ordering, ownership and architectural snapshot constraints|offline existing-log joins first; a future justified functional run only after A-prime|
|3 load retry / victim-conflict path|nack retry47,162 remains; victim nack8,087; RPQ replay229; critical miss wait53,845|moderate exposure evidence, no independent optimization causality|53,845 fixed-trace critical miss exposure only; do not add retries to it or multiply by a penalty; no strict candidate-specific upper bound|medium/high: cache ordering/victim/replay invariants|existing-source/counter correlation first; no policy simulation prepared|

`NEXT_OPTIMIZATION = L1_CAPACITY_64K_2WAY_PENDING_STRICT_A_PRIME`.

MSHR expansion has full0, occupancy at most2/6 in B, scheduler∩full0, so it is not selected. SVB stays16; no SVB32, L2 geometry, promotion, replay, scheduler or MSHR modification is authorized or implemented here. Other STOP categories remain overlapping activities in the traffic window; none is promoted into an additive recoverable slowdown estimate.
