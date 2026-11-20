Versioned CPU-only recovery of the completed owner-only Canneal MCRams run
that reached HOST_TIMEOUT at 10822 seconds. Original logs, failed result,
models, software, target parameters, observations and successful Plain sample
are preserved.

First require the predecessor's exact PID identities and systemd cgroup to
have exited. Compare every complete byte in the timed-out log against Plain's
prefix, and validate both full log hashes. A mismatch stops recovery with its
first byte offset; this is not a semantic repair. If the prefix is identical,
reuse Plain and run only the identical authenticated MC binary. Increase only
the host wall-time budget to 1.6 times the measured completion projection,
rounded up to a minute and capped at nine hours. No target cycle limit,
FASED setting, ELF, ROI, output/checker requirement or executable is changed.

The final result requires complete exact target rows, both print streams,
correctness and absence of faults. Prefix agreement alone is incomplete
evidence. No full formal equivalence, full-system area/FIT, or FPGA result is
claimed. Execution is owned by the existing CPU broker; no device operations.
