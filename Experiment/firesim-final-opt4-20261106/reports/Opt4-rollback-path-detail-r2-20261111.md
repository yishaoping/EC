# Opt4 rollback path detail

## Revision and scope

This is a read-only source trace of hardware commit `8da24a269b98a0d6a8f57b030353a310812c4344`, source ID `7e77ddda28298ac88be13c28dbe98771982bc6ca9587f810adf875bffd580cc1`. The source tree is `firesim/final-opt4-20261106/Opt4-fit-20261110`. No RTL was changed or generated, no simulation was run, and no device was accessed. Generated-RTL evidence is reused from `build-logs/Opt4-rollback-interface-audit-r1-20261111/audit.json`; its 137,210,873-byte `FireSim-generated.sv` scan reported no `use_fi_mode` occurrences and no `GHT` or `GHT_FILTER_PRFS` module declarations.

## Legacy injection path

The legacy source contains an internal packet-corruption path, but the available source does not expose it as a supported software control:

- `chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GHT.scala:68,125` declares `use_fi_mode` and forwards it to `GHT_FILTERS_PRFS`.
- `chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/ght_filters_prfs.scala:55,98` declares the matching input and forwards it to each filter.
- `chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/ght_filter_prfs.scala:45,205-238` declares the leaf input, gates the counter with it, and uses the resulting `fi` signal to select corrupted packet fields.
- `chipyard/generators/rocket-chip/src/main/scala/tile/RocketTile.scala:293-315` instantiates GHT for hart 0 and wires its core, mask, and configuration inputs. It does not assign `ght.io.use_fi_mode`. A search of the candidate's Rocket Chip, BOOM, and Chipyard Scala sources found no driver or software-facing register for this signal.
- `chipyard/generators/boom/src/main/scala/trans/GH_BUF.scala:49` has the corresponding `use_fi_mode` input commented out. The active generated RTL scan found no surviving signal or GHT/GHT_FILTER_PRFS module.

Source hashes from the candidate tree:

| Source | SHA-256 |
| --- | --- |
| `chipyard/generators/rocket-chip/src/main/scala/tile/RocketTile.scala` | `d7ca08cd4604f44e83f0d9d3c3425bb303ad8ca1626aa0cc49c46bfb7fc872f4` |
| `chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GHT.scala` | `c3d778b7044d67a406c4b5b8ed302f552552fd2ae036deff33ec07229e219e19` |
| `chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/ght_filters_prfs.scala` | `61d36d100034482845e784e7ce1db25c7a1ac2b9416c844968926766a9827f66` |
| `chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/ght_filter_prfs.scala` | `130f7f6908cc5b89de6b125b974dfee70e703a5c02712147e07e42680cad1d6d` |
| `chipyard/generators/boom/src/main/scala/trans/GH_BUF.scala` | `e437ac0b2dd1a16639c287c41e76b35ab16e2cc81dbd3dac77c3155b9d27b10d` |

## Failure and rollback paths

In the checking RocketCore, a completed comparison error becomes a sequenced `FAIL` result (`RocketCore.scala:1523-1541,1577-1582`). The tile hands that result to the checker-result path (`RocketTile.scala:340-342`); GHM transports and releases it across the result CDC (`GHM.scala:559-576`). In the BOOM DCache, an accepted `FAIL` or `CANCELLED` result latches its sequence, invalidates speculative versions newer than the safe watermark, and marks address-statistics evidence fatal (`dcache.scala:2651-2684,2853-2857`). This is package-result and memory-version handling.

The ROB rollback FSM has a separate trigger. `exception_thrown` is derived from a committing ROB exception (`rob.scala:705-727`); in the non-commit-map-table configuration it enters `s_rollback` and returns to normal when the ROB is empty (`rob.scala:971-1000`). BOOM uses `commit.rollback` for rename-state unwind (`exu/core.scala:1036`). The audited checker-result path does not feed this ROB exception input, and the audited runtime exposes no rollback-completion witness or application-restart request. A normal checker `FAIL`, result dequeue, SVB invalidation, or promotion ACK is therefore not evidence of architectural checkpoint restoration or application replay.

## Safest next verification

Keep the current RTL and hardware unchanged. A separate simulation-only test can inject a sequenced `FAIL` at the existing checker-result boundary, then observe the DCache/LSU/ROB signals in the same candidate revision. It should confirm the documented failure invalidation and explicitly fail any assertion that equates that event with ROB rollback or application restart. This can validate the current failure behavior, but it cannot establish rollback/restart because the audited design has no supported restore-and-replay interface. A true rollback experiment requires a separately versioned diagnostic design with an explicit architectural recovery contract and independently observable restore, restart-PC retirement, correct output, and complete drain; no such design or hardware diagnostic profile is claimed here.

## Limits

This is a static source and generated-RTL interface audit, not full-DUT formal proof or a fault-injection experiment. It does not claim that every unrelated test-only mechanism in the repository was excluded. No bitstream-bound rollback diagnostic can be honestly prepared from the available interface and bitstream evidence.
