r4 B/C/D exhausted; certification remains unavailable.

C: WNS -0.411ns, TNS -292.970ns, 2130 setup failures; WHS +0.001ns.
D: WNS -0.503ns, TNS -343.017ns, 2299 setup failures; WHS +0.001ns.
Both retain final checkpoints, zero routing errors and 49 warning DRC violations.
B failed because Vivado 2021.1 rejects forced replication in post-route mode.

Proven immediate blocker: negative setup slack. Proven worst-path observations:
C XDMA reset-to-reset pin, 96.792% routing delay; D width-converter-to-DDR
enable, 92.066% routing delay. These observations do not prove that the prepared
replication repair will fix timing. C remains the best completed checkpoint.

Prepared a separate Tcl repair: unroute a private checkpoint before the original
B forced-replication command. The entire reporting/strict certification gate tail
is identical to r4. Tcl mock validates command ordering only; actual Vivado support
and timing improvement remain unproven. Preparation is neither queued nor launched.
Root service installation belongs to the existing authorized administrator.

r4 physical and directed follower exited with exact empty cgroups. Its application
waiter remains one matched idle Python. No process was stopped or signalled.
Existing r51/resumed-r3 routes, MCRams full-host capacity, owner-MC parity, and
priority handoff were matched live during this round and remain under their owners.
No LUT/FIT result is inferred for MCRams. Existing continuations automatically
consume their actual completed outputs. Recheck components >=300s, whole CAD >=600s.
