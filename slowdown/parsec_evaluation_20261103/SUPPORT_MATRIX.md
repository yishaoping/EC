# PARSEC support matrix

Status after the initial three-workload pilot. The current candidate correctness repair is not yet accepted; see STREAMCLUSTER_CORRECTNESS.md. PASS below denotes validated pilot evidence on the previous hardware revision, not a primary publication comparison. Installed Linux executables require a different execution environment and were not launched.

| Benchmark | Builds | Runs | ROI identifiable | Native | Check | Correction |
|---|---|---|---|---|---|---|
|blackscholes|yes: official serial kernel + HTIF|yes|application kernel only|PASS (engineering pilot)|PASS|PASS (previous revision); r2 pending|
|bodytrack|Linux artifact/source only|unsupported by current HTIF harness|requires baremetal adaptation|N/A|N/A|N/A|
|canneal|yes: official serial kernel + HTIF|check yes|application kernel only|cycle bound reached; retry pending|PASS|running (previous revision); r2 pending|
|dedup|Linux artifact/source only|unsupported by current HTIF harness|requires baremetal adaptation|N/A|N/A|N/A|
|facesim|Linux artifact/source only|unsupported by current HTIF harness|requires baremetal adaptation|N/A|N/A|N/A|
|ferret|Linux artifact/source only|unsupported by current HTIF harness|requires baremetal adaptation|N/A|N/A|N/A|
|fluidanimate|Linux artifact/source only|unsupported by current HTIF harness|requires baremetal adaptation|N/A|N/A|N/A|
|freqmine|Linux artifact/source only|unsupported by current HTIF harness|requires baremetal adaptation|N/A|N/A|N/A|
|raytrace|Linux artifact/source only|unsupported by current HTIF harness|requires baremetal adaptation|N/A|N/A|N/A|
|streamcluster|yes: official serial kernel + HTIF|native/check yes|application kernel only|PASS|PASS|EXCLUDED: epoch flush / store lease assertion; r2 pending|
|swaptions|Linux artifact/source only|unsupported by current HTIF harness|requires baremetal adaptation|N/A|N/A|N/A|
|vips|Linux artifact/source only|unsupported by current HTIF harness|requires baremetal adaptation|N/A|N/A|N/A|
|x264|Linux artifact/source only|unsupported by current HTIF harness|requires baremetal adaptation|N/A|N/A|N/A|

The three supported ports preserve the official serial computation: Blackscholes represents floating-point compute, Streamcluster represents distance calculations and load/store traffic, and Canneal represents irregular graph/control behavior. These are single-thread runs; they do not characterize parallel synchronization or full native-scale PARSEC working sets. No functioning Linux boot/syscall/filesystem baseline has been established here. Historical FireSim scripts are not executed.

Official simdev inputs are the pipeline pilots. Larger project inputs preserve the official kernels and iteration semantics and are recorded separately, including explicit deviations from official input classes. Blackscholes project32 derives the first 32 options from simsmall/in_4K; Canneal project1k retains 100.nets and changes swaps/temperature steps, not graph size. Streamcluster larger candidates use the official SimStream generator. Input selection awaits measured feasibility after hardware acceptance.
