# FPGA critical path continuation — 2026-11-12 13:45 CST

The original SVB r5 E router and complete owner MCRams synthesis remain alive
under their original controllers. No new certified bitstream or FPGA sample
exists. Only `0000:21:00.0` is authorized; functional baseline remains
`8491167d84b6d9521b151a743673c1516926a1f8`.

| Requested result | Actual evidence |
|---|---|
| SVB r5 WNS | Latest **intermediate**, not final: WNS +0.198 ns, TNS 0, WHS −0.471 ns. Global routing overlaps 349206 → 144668 → 73331 → 37605 → 17760. Final routed timing remains pending. |
| Complete MCRams LUT / CARRY8 / DSP / FIT | No complete synth/postopt utilization report or DCP yet. Values and FIT remain unknown. Full generated FPGATop OOC excludes U280 shell. |
| Bitstream | No r5 or complete MCRams certified bitstream. No programming performed. |
| Fastest board path | r5 final setup/hold, route, DRC, clock, pulse/skew gates → independent certificate → existing 21-only directed SVB test → same-bit real application trace replay. Component result only. |

Complete MCRams passed Cross Boundary and Area Optimization at approximately
13:14 CST, then entered Timing Optimization at 13:16 CST. A bounded 12-second
sampling of the exact live Vivado identity found ConstProp/BDD computation:
`NDesC::objHasDirective`, `ConstProp::getBDDsOfInputs`, equivalent-net lookup,
combinational evaluation and allocation. CPU ticks increased; no evidence of
deadlock or I/O waiting was found. This does not predict completion time or FIT.
The raw profile and process identity receipt are retained here.

One definite future physical blocker was repaired. The exact generated XDC
defines both target clocks with `-divide_by 1`; checker timing uses its original
setup/hold multicycle 2/1. The old final physical gate incorrectly required the
checker clock period to be twice the host period. The independently versioned
controller fixes that period check to 1/1 while retaining the generated XDC,
target RTL, timing/route/DRC gates, output paths and existing independent runtime
certification. A pre-place clock contract check prevents spending place/route
time on invalid clock bindings. Actual physical tool validation is still pending.

Service `ec-opt4-mcrams-host-continuation-r3-clock-3656aec4.service` is active,
PID 2759828, start_ticks 27368804. Only the exact old consumer cgroup containing
two idle Python tasks was retired; the original synthesis, owner parity and
SVB CAD processes were rechecked alive with unchanged start_ticks. The old
bound source files are unchanged. Canonical consumer state remains
`Opt4-mcrams-full-host-continuation-r2-state.json`, with revision
`r3-generated-clock-contract`. Do not restart the old r2 consumer.

The new consumer also parses the first complete synth/hierarchical report before
post-opt completion, using the strict section-aware parser and hierarchy/
CARRY8/blackbox crosschecks. Results will be written to
`build-logs/Opt4-mcrams-full-host-continuation-r2-20261112/early-synth-capacity.json`
and `early-postopt-capacity.json`. These do not substitute for final full-shell
capacity or certification. FIT plus actual parity submits the unique corrected
physical job and reuses the complete host checkpoint.

A second future integration concern was localized by a bounded shell-only
Vivado inventory that has already exited: loading the shell top and clock-wizard
DCP alone supplies no clocks, and Vivado warns that a raw IP DCP omits related IP
constraints. This partial-shell diagnostic does not establish the final linked
shell state. The persistent FPGA worker has the precise evidence and a concrete
next task to audit unchanged BD/IP constraint loading before physical admission;
the new pre-place contract will fail safely if clocks are incomplete. Do not
invent clock periods or relax constraints to work around missing collateral.

Owner parity continues from reset, most recently observed at target cycle
1,530,039; the Plain reference ends around 1,759,002. No final parity result is
claimed. The previous address RAM prototype regressed 60,726 LUT and remains
excluded. Historical 2,847,382 LUT NOT FIT is not this MCRams result.

Validation completed: r5 driver/application offline bindings; all 19 original
physical input hashes; Python compilation; exact generated XDC contract checks;
Tcl positive same-period and negative doubled-period cases; unchanged final
timing/route/DRC gate comparison; actual new service/cgroup/process handoff;
priority runtime scheduling behavior for first-round coverage of Blackscholes,
Fluidanimate, Bodytrack, Freqmine, Swaptions, Ferret, Dedup, Streamcluster before
rounds 2/3. All original ROI, checker, drain, software and correctness gates stay.

No CPU comparison task, e2 device, global XDMA operation or dual-card workflow
was controlled. No credentials are stored in these artifacts. `snapshot.json`
contains contemporaneous raw state, process identities, services and hashes.
