# Real DCache memory entry to Golden Gate MCRams

Functional baseline: `8491167d84b6d9521b151a743673c1516926a1f8`.
Derived equivalent implementation under analysis: `3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c`.

This independent CPU-only prototype binds the actual generated DCache FIRRTL and source. `entry-inventory.json` preserves the four unchanged memory definition blocks, real port names, depths, widths, latency, read-under-write declaration, write enable and reset-mask semantics. The original raw FIRRTL and worktree are never edited.

The isolated `EntryDUT` reproduces the 512 x 81 owner-image memory with its real 35 read / 1 write shape, existing written-bit reset mask and reset-gated write. Observation-only target-edge capture permits explicit comparison of pre-write reads and post-write asynchronous outputs. The same emitted target FIRRTL and annotations are fed to both Golden Gate PlainConfig and MCConfig. This is an interface-level experiment, not extraction of the full DCache control logic and not whole-system equivalence.

The persistent job runs 1,536 target cycles per host configuration, exercises all addresses before randomized traffic, forces read/write address conflicts and periodically resets the written mask. It compares all 35 captured values and all 35 post-edge outputs with the same deterministic scoreboard. Both host configurations must produce an identical data-event digest. A deliberately corrupted expected capture at target cycle 513 must fail in each configuration. Shape mutations (latency, read count and read/write port) must also be rejected.

The observed generation-memory 518-read shape includes 512 preserved debug reads; it is recorded explicitly and is not silently reduced to a low-port memory.

Service: `ec-opt4-auto-mcrams-dcache-entry-r1-8491167d.service`.
State: `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-mcrams-dcache-entry-r1-state.json`.
Evidence: `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-mcrams-dcache-entry-r1-20261111/`.
Broker receipt: `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/unattended-opt4/request-results/mcrams-dcache-entry-r1-8491167d.json`.

The controller holds a single-instance lock, atomically updates state, stores per-stage command/hash/exit receipts and runs with two pinned CPUs and a 24 GiB address-space limit. Reconnects must adopt live PID/start_ticks/boot_id. Successful stage outputs may be reused only with matching hashes. A failed or partial stage is preserved and requires a new isolated recovery version; do not overwrite live inputs or rerun a second instance.

No FPGA access, full-DUT CAD, production admission or FIT claim is performed by this job.
