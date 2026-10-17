# Phase 1 Implementation Notes (2026-10-11)

This note records the deliberate scope mapping used by the Phase 1 RTL changes.
It does not change the revision-2 preservation specification.

## Local ownership mapping

The L1 implementation currently has two separate local identities:

- `slotEpoch(set, way)` changes when a resident slot is invalidated or
  reallocated. It rejects S1/S2/S3 requests, old MSHR replays, and refills that
  refer to a previous slot owner.
- `lineGeneration(set, way)` is the generation of the current resident
  allocation. It changes on replacement allocation and is installed with the
  matching refill. It stays constant across same-owner stores and replays.

Revision 2 defines the full ImageKey `generation` as a new image serial for
each semantic store/AMO/SC/replay write. Implementing that meaning requires
same-line generation forwarding through all in-flight S2/S3 grants and the
MSHR replay queue. That forwarding is not present in the Phase 1 pipeline, so
incrementing `lineGeneration` at every data write would reject a legal second
store in the same resident line. Phase 1 therefore uses the allocation
generation for stale-owner rejection and a separate `effect_token` for
exactly-once effect identity.

## Effect and cancellation rules

- A store receives an `effect_token` at the first L1 request boundary when it
  does not already have the architectural strict-store token.
- `appliedEffectToken` suppresses a duplicate replay of the most recently
  applied token for that resident slot. The slot epoch/reallocation clears this
  record.
- RPQ entries remain owned from issue through `replay_effect_done`. A replay
  whose slot owner is invalidated is sent through LSU's nack path with
  `replay_retry`, then retired with `replay_cancel`; this is an explicit
  cancel/retry, not a successful effect.
- Completion and cancel pulses are carried per MSHR. This handles an S3 store
  completion and a different MSHR's S2 load response in the same cycle without
  dropping either RPQ head; SDQ release is a bitmask over all terminal replay
  stores.
- Clear/probe/replacement ownership transitions drain or reject an S3 effect
  before changing the slot epoch. A refill is accepted only while its captured
  slot epoch still matches.
- Cross-package clear also waits for any MSHR holding the exact set/way, even
  when that MSHR currently targets a different tag; this prevents an old clear
  from erasing a newly reallocated resident slot.

## Deferred Phase 2 work

This mapping does not claim safe-old push-before-overwrite, L2 predecessor
preservation, or rollback. Phase 2 must add a true per-image generation and
certificate update at the atomic resident commit point, together with
same-line forwarding or serialization so every in-flight request carries the
correct ImageKey dependency.

## 2026-10-12: S0 effect-token combinational-loop fix

The user's hardware-generation report identified a FIRRTL `CheckCombLoops`
failure in `BoomNonBlockingDCache`, through `s0_req_0_effect_token_valid`
and the token-allocation condition (pre-fix `dcache.scala:713-715`). The
condition read the same output flag that its conditional assignment drove:
`when (!s0_req(0).effect_token_valid) { ... := true.B }`. Chisel last-connect
semantics therefore created combinational feedback; this is not a Java
heap/options failure.

The source now separates the selected incoming payload (`s0_selected_req`)
from the augmented pipeline payload (`s0_req`). Token allocation tests only
the input payload, then sets the output flag/token and advances the existing
counter. Existing incoming tokens pass through. No register stage or new
cache-preservation mechanism is added by this fix.

Validation: `make -C chipyard/sims/verilator launch-sbt
SBT_COMMAND='project boom; compile'` passed at 2026-10-12 08:43:23 +08;
`git diff --check` passed for the changed source. No elaboration, FIRRTL
lowering, hardware generation, or simulation was run for this fix, as the
user owns those steps. The reported direct feedback is removed at source
level; passing the full FIRRTL loop check and Phase 1 runtime invariants
remain unverified until the user regenerates/runs the design.


## 2026-10-12: Phase-1 closure implementation (supersedes the temporary mapping)

The earlier allocation-generation mapping above is historical and no longer
applies to the current working tree. `lineGeneration` now changes only at the
actual local semantic array write. Every store, successful SC, and AMO write
gets a new serial even if the bytes are unchanged. Allocation/refill do not
invent imported ImageKey provenance; `image_valid=false` explicitly represents
an imported image whose cross-level identity is deferred to Phase 2.

DCache splits registered raw S2 requests from the current combinational effective
transaction. MSHR admission provides the destination way, epoch, transaction
serial, MSHR ID and SDQ ID. Primary new-line acceptance reserves the incoming
epoch without relabeling the resident. A primary upgrade reserves the resident
epoch. Secondary requests inherit the existing MSHR owner; MMIO carries no
cache owner. The descriptor, RPQ, and SDQ companion metadata capture the same
complete effective payload on acceptance.

Replacement/clear freeze old references, drain grants and terminal responsibility,
and recheck resident tag/epoch before snapshot/transition. Complete GrantData is
captured into LineBuffer, and its E acknowledgement is held independently of
local replay. Install validates the reserved transaction before any shared
LineBuffer read; final data fire commits the new resident epoch. RPQ and issued
descriptors remain live until identity-matched terminal results. RETRY ends only
an attempt. Pre-issue branch cancellation exposes the original queue payload so
its SDQ companion can retire. Protocol owner mismatch asserts and parks that
MSHR without array write, request release, or repeated LineBuffer acquisition.

LSU allocates functional request/effect tokens independently of strict statistics.
STQ release waits for identity-checked `store_done`, and younger stores wait for
older functional effects. MMIO terminal completion follows its matching D response,
not A acceptance. Held S3 records include the image dependency, token, transformed
write data and architectural AMO/SC result. Failed SC holds a no-write terminal
result. Measurement RESET does not clear functional owner/image/token/result
bitmap/safe watermark or cross-package pending responsibility. The core keeps
package identity during snapshot tail execution.

Source audit and compile evidence are in
`AI/TMP/phase1_closure_20261012/identity-audit.md` and `compile-final-nodata.log`.
No target elaboration, FIRRTL lowering, hardware generation or simulation was
run; all dynamic invariants remain pending user validation. No preservation
certificate, L2 predecessor/victim preservation FSM, TtoB handoff or late ACK
protocol was added.
