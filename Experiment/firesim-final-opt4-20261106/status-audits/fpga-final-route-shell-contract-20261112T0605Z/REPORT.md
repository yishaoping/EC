At 2026-11-12 14:18:56 CST, the exact original r5 E router remains alive
(PID 2692703, start_ticks 26961377). Its routing overlaps decreased from 4,738
through 2,735 and 1,773 to 1,218 during this continuation. Final timing, route,
DRC, bitstream and FPGA measurement remain pending.

| Requested output | Actual evidence |
|---|---|
| SVB Setup/Hold | Router intermediate WNS +0.198 ns, TNS 0, WHS −0.471 ns, THS −1528.898 ns. These are initialization estimates, not final STA. |
| Final route/DRC | No final reports or final checkpoint yet. Router overlaps are not the final count of unrouted networks. |
| Bitstream/board | No r5 or complete-MCRams bitstream. No programming or measurement was performed. Existing independent certification, card21 directed test and same-bitstream application replay services remain active. |
| Complete MCRams LUT/CARRY8/DSP/FIT | No complete synth/postopt utilization report or checkpoint yet. The original Vivado PID 2379656 remains active in Timing Optimization. Counts and FIT are unknown. |

The old physical snapshot WNS −0.029/WHS −0.554 predates the +0.198/−0.471
router estimate. The pre-route worst hold path is a PCIe read-data pipeline
register to the PCIe hard block input: data delay 0.133 ns and skew 0.076 ns.
The next path is a PCIe EQ coefficient register to the hard block. These
paths are evidence for preserving the current router's hold repair, not a
reason to change constraints. The existing controller automatically runs
hold_fix and reroutes if routed setup passes and hold fails, then checks all
timing, route, DRC, clock, pulse and skew gates. E failure conditionally
continues to a different fanout/placement/routing strategy F; no duplicate
recovery was launched.

The persistent worker independently completed the shell constraint diagnosis
and started its r4b conditional recovery observer. Its evidence is in
`status-audits/round128-shell-collateral-20261112/`. The shell-only link loaded
27 original IP implementation constraints. It observes the native physical
clock instead of assuming a nonexistent host_clock name. The separate repair
can reuse the exact full-host wrapper checkpoint after an actual r3 failure;
all divide-by-one and multicycle rules, complete-shell capacity and physical
certification gates stay. No host synthesis is repeated. This foreground
session's project-only inventory also completed and exited without link,
synthesis, optimization, route or device work; it is retained only as an
independent constraint inventory. Existing r4b work was adopted.

A new read-only application metrics consumer was implemented and submitted as
`svb-application-fpga-metrics-r1-8491167d`. Offline validation checks 659 bound
application lifetimes and exact binary/driver/proof bindings. Five negative
cases reject CPU attribution, cached inputs, output-count loss, ACK-count loss
and mismatches. Successful actual replay is required before publishing FPGA
component metrics. Outputs separate target-cycle event intervals, observed
workload ACK rates and host MMIO replay rates. Strict checker completion,
rollback and autonomous peak throughput are not inferred.

The broker currently defers this optional metrics consumer with
DEFER_MEMORY_AUXILIARY_MARGIN and will automatically retry its single request.
The generic resource guard was retained. The r5 CAD, full capacity producer,
owner parity, clock consumer and runtime follower identities remain unchanged.
The owner parity trace had reached target cycle 1,727,727; its final result
was still pending. The separate CPU PARSEC experiment was not controlled.

`snapshot.json` contains exact states, process identities, cgroups, timing
observations and services. `metrics-negative-validation.json` and
`metrics-submission.json` contain the new verification and dispatch receipt.
`preroute-hold-paths.json` preserves the explicitly historical path analysis.
Functional baseline is 8491167d84b6d9521b151a743673c1516926a1f8; the sole device
allowlist is 0000:21:00.0 / 21770433G02LA. No target RTL, functional behavior,
target-cycle semantics, running CAD input, or CPU comparison state was changed.
