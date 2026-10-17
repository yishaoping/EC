# Phase-1 Row Provenance Fix Design

Status: design only. No RTL or Chisel source is changed by this document.

## 1. `rowValid` contract

The three possible meanings are distinct:

| Meaning | Correct signal in the current design |
|---|---|
| Complete LineBuffer contents exist | `grant_had_data` after the final GrantData beat |
| One row is held and may be offered to the data-array refill path | `rowValid` + `rowData` |
| A row is held together with arbitrary read provenance | Current generated behavior, and the bug |

The intended contract for `rowValid` is therefore **B**. It means:

```text
rowData is the row selected by the current install refill counter,
captured for this MSHR transaction after install ownership was accepted,
and may remain held until the refill handshake fires.
```

It does not mean that the LineBuffer contains any data (`grant_had_data`),
and it does not mean that a load response or forwarding response is pending.

The current implementation is effectively **C** in generated RTL. The source
has one textual `when (io.lb_read.fire)` in the `s_commit_line` branch, but the
generated register update is driven by the shared LineBuffer fire. That shared
fire also represents `s_drain_rpq_loads` reads. The result is a provenance mix.

## 2. All `rowValid` writes

Current source locations in `chipyard/generators/boom/src/main/scala/lsu/mshrs.scala`:

| Update | Location | Current condition | Classification |
|---|---|---|---|
| reset value 0 | declaration near line 463 | `RegInit(false.B)` | transaction/register reset |
| set to 1 | line 468 | `io.lb_read.fire` as generated | intended install capture, but also RPQ load capture |
| clear to 0 | line 482 | `io.refill.fire` | valid install row consumed |

There is no intended RPQ-load, replay, or forwarding assignment to `rowValid`.
Those paths use the LineBuffer response directly for `io.resp`; they must not
write `rowData` or change `rowValid`.

`installStarted` is set only by `io.install.fire` (line 450). In the DCache,
`io.install.fire` already means that the MSHR's install request was accepted
through `installOwnerMatch && installDrain`; the DCache then sets
`installActive(set)(way)`. This registered fire is the correct local witness
of owner acceptance. A raw DCache `installOwnerMatch` wire is not currently an
MSHR input and should not be added merely to create a combinational feedback
path.

The missing condition is an explicit install-read-purpose guard on the set
operation:

```text
install_row_read_fire =
    io.lb_read.fire &&
    state == s_commit_line &&
    grant_had_data &&
    installStarted &&
    !protocolFault

when (install_row_read_fire) {
  rowData  := io.lb_resp
  rowValid := true.B
}
```

The state/purpose qualification must be visible in generated RTL; relying on
the lexical location of a `Reg` declaration is insufficient.

## 3. Candidate fixes

### Scheme A: restrict `rowValid` writes

Use one held row register, but make its write enable the explicit
`install_row_read_fire` condition above. Treat `io.install.fire` as the
owner-match acceptance event, so `installStarted` is a registered proof that
the DCache install handshake succeeded. Keep DCache's existing
`installActive` validation on every refill beat.

**RTL impact:** one qualified write enable; optionally one explicit clear at
primary transaction admission. No Bundle or inter-module port change.

**FSM impact:** no state transition change. The existing order remains:
`s_commit_line` install fire, then row read, then held refill row.

**Cache behavior:** ordinary RPQ loads continue to read the LineBuffer and
return `io.resp` exactly as before, but cannot modify install state. Refill
protocol and owner checks are unchanged.

**Performance:** no added cycle. The install row read was already blocked by
`installStarted`; it becomes legal on the same post-install cycle as intended.

**Risk:** low, provided the generated RTL includes the explicit state/purpose
guard and the held row is cleared at transaction admission. A separate raw
`installOwnerMatch` input is unnecessary and would add a combinational path.

### Scheme B: split `lineBufferDataValid` and `installRowValid`

Represent complete Grant capture and held install row with separate registers.
`grant_had_data` already performs most of the first role, so a new
`lineBufferDataValid` would largely duplicate existing state. `installRowValid`
would still need the same explicit install-read guard.

**RTL impact:** extra state, reset/clear cases, and more waveform/assertion
surface; no Bundle change.

**FSM impact:** can preserve the FSM, but requires auditing every transition
that clears or consumes each valid bit.

**Cache behavior:** can be correct, but does not by itself fix the shared-fire
write enable. If the wrong fire still writes `installRowValid`, the bug remains.

**Performance:** no required throughput change, but extra muxing/register state
may lengthen the MSHR control path.

**Assessment:** architecturally clearer if the LineBuffer later becomes a
multi-entry protocol buffer, but unnecessary for this Phase-1 defect.

### Scheme C: add `rowValid` plus `rowOwner` provenance

Store owner identifiers such as MSHR, transaction, epoch, or line address with
the held row and compare them at refill time.

**RTL impact:** extra held metadata and comparators; likely Bundle/debug wiring
if the owner is propagated.

**FSM impact:** no mandatory state transition change, but more stale-row and
clear cases.

**Cache behavior:** a same-MSHR ordinary RPQ load has the same transaction and
owner as the install, so owner metadata alone does not distinguish the wrong
purpose. A purpose bit/state is still required, making C a larger version of
Scheme A.

**Performance:** no protocol throughput change, but additional compare logic
on the refill offer path.

**Assessment:** useful as a defensive assertion/provenance field in a later
debug build, insufficient as the minimal fix.

## 4. Recommended minimal design

Recommend **Scheme A**, with two precise safeguards:

1. Define `rowValid`/`rowData` at MSHR scope and clear `rowValid` when a new
   primary request is admitted (`handle_pri_req`), in addition to the existing
   clear on `io.refill.fire`. This makes the transaction boundary explicit and
   prevents a killed/aborted transaction from carrying a held row forward.
2. Set `rowValid` only on an explicit `install_row_read_fire` as defined above.
   The owner admission condition is represented by `installStarted`, which is
   set only after `io.install.fire`; DCache `installActive` remains the
   independent per-beat owner guard.

Keep unchanged:

- `s_drain_rpq_loads` response and RPQ retirement behavior;
- `s_commit_line` state transitions;
- `BoomCacheRefill.addr` array-row semantics;
- `BoomCacheRefill.line_addr` physical identity;
- MSHR ID, transaction, epoch, owner, tag, alignment checks;
- `refill_fault` and both owner assertions.

This removes the provenance mix without changing the refill protocol or
ordinary load timing. It also avoids a new DCache-to-MSHR combinational
owner-match path. If the owner becomes invalid after installation, the
existing DCache `installActive`/reservation checks still reject the refill;
the proposed fix does not weaken that detection.

## 5. Proposed source change locations

| File | Location | Design change |
|---|---|---|
| `mshrs.scala` | register declarations near lines 121-139/463 | place `rowValid` and `rowData` at stable MSHR scope; clear `rowValid` on new primary admission |
| `mshrs.scala` | `s_drain_rpq_loads`, lines 360-405 | no row-register writes; preserve direct load response |
| `mshrs.scala` | `s_commit_line`, lines 448-484 | explicit `install_row_read_fire`; only this event sets `rowData/rowValid` |
| `dcache.scala` | existing refill validation lines 1162-1184 | no functional change; retain `installActive` and all owner checks |

No change is needed to `phase1.scala`, Bundle fields, arbiter wiring, TileLink
transactions, preservation metadata, version/generation, or watermark logic.

## 6. Verification plan

### Static/generated checks

- Confirm generated `rowValid` set enable contains `state == s_commit_line`,
  `installStarted`, `grant_had_data`, and `!protocolFault`.
- Confirm no generated `rowValid` write is reachable from state 3, replay, or
  forwarding logic.
- Confirm `rowValid` clears on every refill fire and new primary admission.
- Confirm `refill.valid` still reaches the unchanged DCache owner predicate and
  `refill_fault`/asserts remain present.
- Confirm no new Bundle, TileLink, line address, epoch, transaction, or owner
  field is introduced.

### Focused waveform/assertion cases

1. **Normal load drain:** `io.lb_read.fire` in `s_drain_rpq_loads` produces
   `io.resp.fire` but never changes `rowValid` or `rowData`.
2. **Normal refill:** after `io.install.fire`, each install row read sets
   `rowValid`; each accepted refill clears it; all four rows retain the same
   MSHR/transaction/epoch/line identity.
3. **Commit invariant:** `rowValid=1` implies `installStarted=1`; any
   `refill.valid` implies the same, while DCache still requires `installActive`.
4. **Multiple MSHRs:** a LineBuffer read for another MSHR cannot set this MSHR's
   row state; arbitration ID and transaction remain unchanged.
5. **Backpressure:** held `rowValid/rowData` remains stable while refill
   `ready=0`, then clears only on `refill.fire`.
6. **625000 testcase:** transaction 937 must either perform a valid install
   handshake before its first refill row or remain waiting; no refill is
   offered with `installActive=0`, and the owner assertion remains enabled.

The key safety assertions are:

```text
rowValid -> installStarted && grant_had_data
refill.valid -> rowValid && installStarted
row_capture_fire -> state == s_commit_line && installStarted
refill.fire -> DCache owner predicate
```

