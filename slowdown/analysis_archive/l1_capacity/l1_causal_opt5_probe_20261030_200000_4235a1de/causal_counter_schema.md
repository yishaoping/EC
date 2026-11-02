# L1-Causal-1 measurement contract

## Windows and identities

- `causal` uses exact software half-open `[rdcycle_start, rdcycle_stop)`, recovered from the BOOM writeback values at pinned ELF PCs `0x80000340` and `0x8000039c`. A 64-cycle prefix-snapshot ring backs up the actual read timestamp. Missing/duplicate/out-of-ring markers invalidate the native report.
- The existing top-level cache `actual`, S0, and SC40–45 use hardware traffic START-inclusive/STOP-exclusive. This window is slightly wider. They are displayed separately and are not substituted for exact-software-ROI counts.
- Request identity is the existing 64-bit LSU functional token, not a recycled LDQ/ROB index. The ROB bore carries head ROB/LDQ identity; LSU requires the same live ROB allocation and an unsucceeded LDQ entry before exporting its functional token.
- Counter storage: 64 load slots, 64 store slots, 6 MSHR slots, 192 monotone counters, 3x32 histogram bins, 64 prefix snapshots. No native per-cycle record is printed or saved.

## Event meaning

|Native event|Observed edge/predicate|Meaning and limit|
|---|---|---|
|14|Live cacheable S2 LSU lookup without hit|Unique first miss per functional request; tag and permission misses separate; raw attempts also counted|
|15|Actual cacheable MSHR request fire|Primary / upgrade / secondary merge; request token joins load latency, MSHR ID + transaction token join refill|
|16|Final refill data-write handshake with owner match|Data array install complete; not architectural retirement|
|17|DCache valid load response, matching request token|Data available; the real LSU separately checks live identity and writes succeeded; not retirement|
|18|Every BOOM DCache cycle|ROB busy first valid head load + live unsucceeded LDQ + matching outstanding native miss; same-cycle scheduler/MSHR intersections|
|20|Load RPQ replay fire|Replay event; distinct-cycle count is a replay-active-cycle count, not an ROI penalty|
|21|Load nack valid|Nack event, with existing overlapping reason bits: MSHR unavailable/victim/data/writeback/hit|
|22|Real load request fire following that token's nack|Observed retry event; distinct-cycle retry count is not recoverable stall|
|23|Pinned software rdcycle writeback marker|Lookup exact prefix boundary in bounded ring|
|24|Cacheable MSHR request valid and not ready|Rejected request attempt; not a unique lost transaction|

Native load/store request classes follow existing `uop.uses_ldq` / `uop.uses_stq`; non-LDQ/STQ helper requests are excluded from native unique miss requests, and AMO classification follows its existing queue ownership. These queue-based request counts are not silently equated with legacy `isRead/isWrite` traffic totals.

There is a second important distinction: legacy `actual.miss` classifies only the **first lookup per request token** (`Cache::event(1)`, global `tokens.insert`). Native `load/store_tag_miss_requests` classify the **first failed lookup per live queue-token incarnation** (`Causal::event(14)`, `!x.detected`); preceding hits do not mark a native miss slot as detected. A token whose first lookup hits but a later attempt loses its line can therefore enter the native miss population without entering legacy first-lookup misses. Native tag-versus-permission class is fixed at that first failed lookup. The two populations also use different ROI windows and queue classification, so their totals need not match. In particular, A has native tag-miss requests1533+2478=4011 versus legacy first-lookup misses3272; the saved aggregate does not isolate how many of the difference come from each distinction. No one-to-one reconciliation or exact subtype count is claimed.

MSHR busy/full sample the existing owner-line occupancy predicate (6 owners), including stores and all live allocation states, not only ROB-critical loads. An owner can stay live after refill for drain/publication. `full` means all six owners active; it does not prove every request was blocked.

## Critical-cycle accounting

The six requested head/scheduler/MSHR overlap counters are intersections evaluated in one BOOM cycle. Head-miss association includes both tag misses and permission misses (`S2 !hit`); the two request classes remain separately counted. The head predicate excludes rollback, flush, exception, and any successful commit in that cycle. Head sampling occurs before native response removal because a busy load returning in that cycle cannot already retire at the same pre-edge state.

Four mutually exclusive predicates (head-miss only, scheduler only, both, neither) conserve software ROI exactly. Their A-minus-B deltas sum to the ROI delta, but this is accounting, not four independent removable causal costs. Scheduler refers exactly to `fsm_state == fsm_sch && !scheduler_available`, not every EC pause. `rob_head_load_pending_cycles` is broader than miss-caused waiting and is reported separately.

## Latency cohorts

Histograms use completion-in-ROI cohorts for load detect→accepted-MSHR, accepted-primary/upgrade transaction→last-refill (load or store initiators), and load detect→DCache-load-response. The first/third cohorts are loads; the middle cohort is MSHR transactions. Store request misses/admissions are counted separately, but no store detect→architectural-completion latency histogram is claimed. A request may begin before ROI. Squashed, recycled or unfinished requests are censored, not assigned zero latency. Merges contribute request detect→accept but do not create another refill allocation. Permission upgrades that do not write refill data have no alloc→refill completion sample; they are not assigned a zero-latency data refill. Histogram bins: bin0=0; binN=[2^(N−1),2^N−1]; bin31 saturates. Different-arm cohorts and different-stage cohorts are not assumed identical. No mean-latency-times-miss estimate is used.

## Claim hierarchy

- Direct observation: measured A/B ROI, real misses/admission/replay/refill, matched head-load intersections, histogram conservation.
- Immediate blocking condition: a live miss-associated load is busy at ROB head without commit; scheduler and MSHR predicates may coincide.
- Upstream intervention: only BOOM L1D nSets changes 256→512; all other sealed source, software, seed and instrumentation are identical.
- Downstream amplification: changes in replay, publication, checker scheduling or overlap can amplify/cancel the head-load change. A single global pair cannot assign every saved cycle to a particular miss or prove a physically achievable frequency/area/energy benefit.

Dynamic correctness and measurement validation remain prerequisites for any performance conclusion. Source review and offline fixtures alone do not establish the experiment result.
