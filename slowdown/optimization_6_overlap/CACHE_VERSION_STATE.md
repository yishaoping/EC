# Cache image and transaction boundaries

Source audit for validated A/B/C in the isolated performance worktree.
This describes implemented predicates and ownership; it is not proof of every
rollback/exception path. The benchmark and focused RTL witnesses are described
separately in [PERFORMANCE_REPORT.md](PERFORMANCE_REPORT.md).

## Identity and normal selection

Normal L1 loads select tags/data, never the SVB. `CacheImageKey` identifies bytes
by valid/writer/generation/content sequence. Slot epoch, MSHR transaction token,
request token and effect token are separate identities; a reused set/way or STQ
index cannot substitute for one of them. Safe watermark classifies an image; it
does not change its bytes, key, L1 tag or permission.

The shared [L1 preservation predicate](../../chipyard/generators/boom/src/main/scala/lsu/phase1.scala)
allows a semantic overwrite when no old image exists, when the same writer/package
already owns it, or when the predecessor is safe and the required lower receipt
exists. Trusted incoming sequence zero has an explicit exception to the receipt
test. The unsafe-predecessor fast lease is an additional exact resident/package
authorization backed by a completed full SVB capture. These checks protect S2
admission and S3 physical effect; accepting a lookup is not permission to mutate.

## L1 and SVB transitions

| Condition or state | Data/recovery owner | Permitted progress and exit |
| --- | --- | --- |
| Refill installed | L1 current bytes; imported exact image already exists below | Install uses reserved slot epoch and MSHR transaction. The last matching refill beat sets a lower receipt and clears duplicate-effect history. |
| Same-package semantic write | New L1 image of the same writer/package; earlier safe predecessor obligation persists below or in SVB | Physical array acceptance creates a new generation and revokes the current image's lower receipt. |
| Unsafe predecessor before younger write | Old current L1 bytes | For the supported normal cached store, freeze and drain the exact resident, capture all bytes in SVB, then grant one identity-qualified fast lease. Without capture resources, use the legacy wait path. |
| SVB SPEC | Immutable predecessor snapshot, independent of the younger L1 current image | Does not serve demand loads. Safe/current-epoch entries can be selected; only a newer safe same-line/same-writer SPEC image can coalesce an older safe SPEC image. |
| SVB WB_WAIT | Selected immutable entry owns promotion and receipt | Hold through arbitration, all C beats and exact entry/key ACK. The last C beat does not free it. ACK frees it once; same-line younger releases/probes remain blocked until then. |
| Legacy WaitSafe | Frozen resident, with pre-freeze grants drained before snapshot | Watermark permits publication, not destructive overwrite by itself. Unrelated demand hits retain their ordinary path. |
| Legacy WB issued | Frozen resident plus WB's exact image/epoch/source owner | No semantic write or refill can change snapshot bytes. Only matching completion can create its lower receipt. |
| B legacy receipt | Exact image exists below | Matching live resident is invalidated through guarded metadata clear; epoch advances and duplicate/image metadata is retired. A later demand refill creates new residency. |
| C retaining receipt | Exact safe image exists below; matching L1 copy remains | T-to-T publication keeps permission. Matching receipt releases freeze and sets the lower receipt, preserving bytes/key/epoch/effect identity. Branch permission uses the invalidating fallback. |

The legacy freeze has one descriptor. The SVB capture shares that descriptor, but
SVB entries own their data independently after capture. An unrelated line does not
need every older retained entry to become safe. Same-line publication does need
its retained predecessors ordered before it.

A resident invalidating probe clears its image/receipt and advances its slot
epoch. An issued WB remains owned until ACK even if the resident disappears.
C's receipt requires the live tag, slot epoch and image key and excludes a
simultaneous invalidating probe. It neither recreates a vanished line nor restores
write permission after a downgrade. The ordinary coherence upgrade remains required.

Source: [DCache](../../chipyard/generators/boom/src/main/scala/lsu/dcache.scala),
[SVB](../../chipyard/generators/boom/src/main/scala/lsu/speculative-version-buffer.scala).

## PASS, FAIL, CANCELLED and epoch boundaries

Allocation and checker result tracking use a sequence-tagged bitmap. An accepted
result marks completion; only PASS marks the passed bit. The watermark advances
through the contiguous allocated/completed/passed prefix, including accepted
same-cycle results. An out-of-order PASS cannot skip a hole, FAIL or CANCELLED.
Result-channel ownership and BOOM release remain independent from local checker
cleanup and from physical cache completion.

FAIL/CANCELLED trigger invalidation of SPEC images newer than the existing safe
watermark. Safe SPEC predecessors survive that invalidation; WB_WAIT survives
until ACK. Separately, session reset or LSU exception flushes all SPEC entries and
changes the selection epoch on exception. This distinction is why the proposed
safe-predecessor-to-SPEC optimization was withheld: extending reliance on SPEC
requires a recovery proof across those flush/epoch boundaries. C instead copies
the old safe image below before permitting the next local write.

None of these source rules establishes complete architectural restoration after
an injected failure. The retained-image and lifecycle checks cover their stated
transactions, not a full recovery/drain signoff.

## L2 overwrite, eviction and checkpoint

L2 may retain a newer speculative resident without exposing it to ordinary
non-image-aware clients or outer memory. A different image replacing a resident
uses the existing same-package exception or preservation gate. An unsafe old
image waits for verification; a safe dirty image without an outer receipt is
checkpointed before overwrite. Identical immutable copies do not create a new
preservation obligation.

The checkpoint engine follows `idle -> read -> delay1 -> delay2 -> send` for each
beat, then `waitAck -> idle` only on matching successful source/size/transaction
AccessAck. Capture first drains admitted bank operations and captures an immutable
candidate. The target set stays locked through ACK. A only releases the shared
SourceC read-port reservation during pure waitAck, when no checkpoint read or A
beat remains; it retains the lock and terminal owner. Outer failure does not grant
a successful receipt.

Eviction uses the normal MSHR Release/ReleaseAck owner rather than the checkpoint
Put engine. Unsafe victims remain gated. Incoming younger ReleaseData or ProbeAck
cannot bypass the protection of the old L2 image. For C's T-to-T ReleaseData, L2's
existing MSHR transition retains TRUNK and the client's bit. A later different
image still encounters the same L2 preservation gate before replacing its bytes.

Source: [scheduler](../../chipyard/generators/sifive-cache/design/craft/inclusivecache/src/Scheduler.scala),
[checkpoint](../../chipyard/generators/sifive-cache/design/craft/inclusivecache/src/L2Preservation.scala),
[MSHR](../../chipyard/generators/sifive-cache/design/craft/inclusivecache/src/MSHR.scala).

## Store terminal overlap

S2 grant captures the return value and intended effect. S3 array acceptance creates
the physical effect. A terminal then transfers exact request/effect ownership to
the LSU consumer; STQ reuse waits for its normal functional completion/release.
B can enqueue and deliver that terminal on the effect edge and admit a younger
S0 request on the same accepted terminal. It does not remove the older-inflight
barrier for an uncompleted owner. Nack priority and per-slot completion guards
remain. S3 turnover, replay, MSHR installation, probes and image-generation checks
remain separate serialization boundaries.

Source: [LSU](../../chipyard/generators/boom/src/main/scala/lsu/lsu.scala),
[completion audit](CANDIDATE_AUDIT.md).
