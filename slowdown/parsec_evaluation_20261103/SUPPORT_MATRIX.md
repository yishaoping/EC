# PARSEC support matrix (discovery, before pilot)

Installed Linux binaries are build artifacts, not proof of execution under the frozen Verilator configuration. Existing FireSim scripts contain absolute paths and destructive image operations; none are executed.

| Benchmark | Builds/artifact | Runs | ROI identifiable | Native | Check | Correction |
|---|---|---|---|---|---|---|
|blackscholes|RISC-V Linux ELF exists|verified_test4|shared baremetal harness available|PENDING_UNPROTECTED_MODE|PASS_test4|PASS_test4|
|bodytrack|RISC-V Linux ELF exists|UNPROVEN|Linux PARSEC hooks only; adaptation required|PENDING_UNPROTECTED_MODE|NOT_RUN|NOT_RUN|
|canneal|source only|UNPROVEN|Linux PARSEC hooks only; adaptation required|PENDING_UNPROTECTED_MODE|NOT_RUN|NOT_RUN|
|dedup|RISC-V Linux ELF exists|UNPROVEN|Linux PARSEC hooks only; adaptation required|PENDING_UNPROTECTED_MODE|NOT_RUN|NOT_RUN|
|facesim|source only|UNPROVEN|Linux PARSEC hooks only; adaptation required|PENDING_UNPROTECTED_MODE|NOT_RUN|NOT_RUN|
|ferret|RISC-V Linux ELF exists|UNPROVEN|Linux PARSEC hooks only; adaptation required|PENDING_UNPROTECTED_MODE|NOT_RUN|NOT_RUN|
|fluidanimate|RISC-V Linux ELF exists|UNPROVEN|Linux PARSEC hooks only; adaptation required|PENDING_UNPROTECTED_MODE|NOT_RUN|NOT_RUN|
|freqmine|RISC-V Linux ELF exists|UNPROVEN|Linux PARSEC hooks only; adaptation required|PENDING_UNPROTECTED_MODE|NOT_RUN|NOT_RUN|
|raytrace|source only|UNPROVEN|Linux PARSEC hooks only; adaptation required|PENDING_UNPROTECTED_MODE|NOT_RUN|NOT_RUN|
|streamcluster|RISC-V Linux ELF exists|UNPROVEN|Linux PARSEC hooks only; adaptation required|PENDING_UNPROTECTED_MODE|NOT_RUN|NOT_RUN|
|swaptions|RISC-V Linux ELF exists|UNPROVEN|Linux PARSEC hooks only; adaptation required|PENDING_UNPROTECTED_MODE|NOT_RUN|NOT_RUN|
|vips|source only|UNPROVEN|Linux PARSEC hooks only; adaptation required|PENDING_UNPROTECTED_MODE|NOT_RUN|NOT_RUN|
|x264|RISC-V Linux ELF exists|UNPROVEN|Linux PARSEC hooks only; adaptation required|PENDING_UNPROTECTED_MODE|NOT_RUN|NOT_RUN|

Pilot candidates: blackscholes (floating-point compute), streamcluster (distance calculations/cache/load-store), canneal (irregular graph/control). Start from official sources with narrow baremetal I/O adaptations. simsmall feasibility is measured before selecting a smaller explicit project-equivalent input. No synthetic replacement kernels.
