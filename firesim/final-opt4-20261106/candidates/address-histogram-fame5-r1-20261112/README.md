Private FAME5 address histogram prototype, round 152

This owns a distinct host-sharing experiment, not the foreground packed
complete-module or barrier paired maps. It has no board access and never
edits a production source, existing controller, generated checkpoint, or input.

The selected strict histogram has 80 sources (16 strict ways plus 64 overflow
entries), 8-bit keys, 256 destinations, four touched-mask count bounds
[8,3,2,1], and four 64-bit outputs per destination. SourceProjected.scala
retains the pinned helper byte-for-byte after reversing the added lookup
method and package rename. The added lookup selects one arbitrary key from
the original compact4/scatter/width-bounded reduction. All target logic is
combinational; no target registers or target-cycle delay are introduced.

The installed FAME5 implementation allows at most one selected module type.
The prototype uses only HistogramBucket and power-of-two 2/4/256 instances.
The actual running path uses MuxingMultiThreader; the older MultiThreader
requires power-of-two memory threading. No compiler sources are changed.

First run actual generated-host 2- and 4-instance handshakes with 32 complete
target tokens, checking all four results per bucket against an independent
integer scatter oracle. Directed cases cover duplicate keys, maximum legal
counts, absent destinations, and mixed keys. An intentionally wrong oracle
value must be detected; this negative test is not a hardware mutation proof.
Only after both smoke cases pass, generate the full 256-instance plain and
threaded hosts from the same target harness and check all 256 results for
each token. Map both FPGATop hosts with identical Vivado OOC directives,
report every resource total and hierarchy, and reject nonpositive LUT gain.

Host cycles include test bridge I/O and are not FPGA performance. This test
does not prove full PackageAddressStats equivalence, ABI composition, complete
EC equivalence, or full-system FIT. A positive screen still needs those gates
and a fresh complete generated-host post-opt result before physical work.

Resource admission matches the existing private module guard: at least
256 GiB available, load below 64, 60 GiB free disk, fewer than eight existing
project Vivados, and no user process pinned to CPUs 220/221. The controller
uses two cores, a 64 GiB address-space limit, and serial stages. It cannot
submit whole-host CAD, program a device, or access another campaign.
