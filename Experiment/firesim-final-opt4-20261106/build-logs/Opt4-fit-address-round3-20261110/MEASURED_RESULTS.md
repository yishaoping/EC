# Address round3: measured candidate evidence

Independent commit `aca893e0aa3f7e23e16067ab40713afea41558e8`, source ID `d5ca949536b50c2d6bf2f9ef1c2748282f88bac0fa5f2d4cc7ffa5b6c94feb28`. Current whole-system synthesis remains pinned to `8da24a2` and is unchanged.

| Matched OOC probe | LUT | CARRY8 | DSP |
|---|---:|---:|---:|
| 80-term reduction before | 1843 | 6 | 0 |
| Bounded/growing-width reduction | 957 | 2 | 0 |
|16 parallel64-bit state+10-bit delta updates, normal carry |160|144|0|
| Split carry candidate |368|144|0|
| Explicit prefix high-carry candidate |2016|32|0|

The reduction probe saves886 LUT (48.0738%) and4 CARRY8 (66.6667%). The update probes are rejected for production adoption because LUT is the primary bottleneck; no update variant is installed in the committed candidate. All three update+overflow variants passed universal74-input-bit equivalence.

The bounded touch proof covers all96 input bits including arbitrary history masks, offsets and allsize encodings, so it also covers clipped cross-line accesses. The8-term and80-term reduction identities passed universal SAT over136/1360 input bits under the proved per-term bounds. The full-size original frozen/candidate RTL comparison passed6144 cycles, all52 exported outputs eachcycle,5550 valid edges and12 idle edges. This is local validation, not full-design equivalence, timing or FPGA validation.

The new full-size address module is now actually in Vivado OOC synthesis; status `Opt4-fit-address-round3-state.json`, service `ec-parsec-opt4-fit-address-round3.service`. Report will be `full-address-map/utilization.rpt` under this directory. Never multiply isolated savings or subtract them from frozen whole-system utilization to claim FIT. The actual current whole-DUT resources remain pending.

Original/candidate input/command/outputhashes, proofs, comparelog, microreports/checkpoints are retained. Stage receipts permit resuming only missing work after exact PID/start_ticks/boot_id exitaudit. NoFPGAaccess, noactiveCADinputedits, noactiveNativeedits.
