Round 113 completed an independent, immutable audit of the original incomplete
owner-memory Plain/MCRams stdout streams. Result: PASS for all 6,033,629
non-UART complete MC lines (848,232,260 bytes), exact timestamps/payload/order,
and all six startup UART messages (189 bytes). Full MC raw log 848,232,449 bytes
and Plain raw log 1,370,938,735 bytes match their original receipt SHA256s. No
complete line was discarded or normalized. All ten synthetic data/cycle/order/
missing/duplicate/unknown-message mutations were rejected. Result SHA256:
e59d399ec61966b3ab98e637d5fb176ec5c79a76cd49db5ec0da69d7824ef7dc.

The direct symptom was a failed mixed stdout prefix comparison. The immediate
blocking condition was differing UART versus RTL host drain order (proven by
exact equality after lossless stream partition). The upstream trigger is host
transport scheduling; this is not target cycle divergence. Incomplete UART
inventories amplified the comparison failures: round58 v2 omitted RUN;
round113 v1 omitted CONFIG; round113 v2 omitted the two netlist constructor
messages. All failed versions and raw evidence remain unchanged. Six exact
messages and their ELF format-string origins are bound in the passing audit.

This remains a pre-ROI, incomplete finite CPU observation: the original MC run
reached target cycle 1,040,734 before the 10,800-second host budget expired.
It does not establish completed application parity, universal target/FAME/
DCache cycle equivalence, full Opt4 FIT, strict checkerDone-minus-BOOMDone
latency, FPGA data, or formal PARSEC success.

A newer existing owner-MC runtime r2 service was discovered live during v3
preparation. The CPU-conflict guard blocked another runtime; v3 was never
submitted. Adopt controller PID2378806/start25817526 and model
PID2378807/start25817536 on boot d6c6e410-10ad-4326-86ba-79b657eabd96,
CPUs250-251. It reruns the existing MC binary from reset with the completed
Plain reference reused. Do not duplicate it. The completed offline audit used
CPU248, a 2GiB process limit, memory/load gates, and current broker/checkpoint
reconciliation. It launches no simulation, CAD, or FPGA process.

All existing effective jobs were preserved: e0 whole synthesis, group8 address
module mapping, original-postroute SVB recovery, resumed spread physical route,
owner-MC runtime r2, full-host MCRams capacity r1, and certified-board/application
followers. Original SVB binary replay and GG stream replay remain PASS. No new
board sample or certified full Opt4 bitstream was observed. No target RTL,
software, frozen parameters, existing scripts, Native state, or FPGA was changed.

The authoritative full Opt4 capacity remains 9ae postopt 2,847,382 LUT against
1,303,680: NOT FIT, excess1,543,702. e0 is still DUT synthesis with no new whole
capacity result. Module/entry savings are not subtracted from that whole gap.
Latest adopted snapshot: 2026-11-12T01:29:24.154648+00:00, memory415.27GiB,
disk305.31GiB, load11.38. Sprint deadline2026-11-12T08:52:10.022583+00:00,
about7h21m remaining at audit: full Opt4 FIT remains high risk. Simulator
observations remain separately labelled; no bitstream-dependent result claim.

Next safe action: after >=600 seconds, adopt exact current jobs and read new
exit/checkpoint receipts. Let existing owner-MC r2 complete; validate its
same-ELF expected output, exact full print streams and checker observations
against completed Plain. Continue source-bound area work from real full-host
capacity evidence; if either component physical route certifies, the existing
21-only followers handle directed then application replay. Never launch another
Canneal, competing physical route, whole build, or board follower from this
round's superseded recovery candidates.
