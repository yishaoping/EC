---
name: ec-protocol-review
description: Audit EC sequence ownership, FIFO/CDC handshakes, cache/TileLink identity and packet completion after a concrete failure or proposed fix.
---

# ec-protocol-review

Read ../../project/architecture.md for the EC protocol boundaries. Apply ../handshake_protocol.md and ../cache_tl_trace.md to the affected path only.

Use ../../checks/protocol_checklist.md, ../../checks/retirement_count.md, ../../checks/lifecycle_replay.md and ../../checks/cache_tokens.md as relevant. For every state/transaction, identify producer, consumer, owner/seq, capture fire, payload hold, cancellation and release. Distinguish DATA END, instruction final count, PASS, result handoff, cleanup, BOOM release, safe watermark and TL completion.

Output an event table or per-identity ledger plus any concrete violated invariant; source-marker presence is only triage. Do not infer forward progress from xRET, FIFO level or ACK alone.
