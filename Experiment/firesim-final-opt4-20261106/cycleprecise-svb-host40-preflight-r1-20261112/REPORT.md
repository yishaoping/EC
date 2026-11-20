# Original SVB host40 successor actually installed

All three independent systemd services have started under root installer ownership. Physical controller waits for the existing r51 exact cgroup release; directed FPGA follower waits for independently produced and certified host40 bitstream; real application follower waits for its own valid directed component replay. No CAD or device access occurred on installation. Existing50MHz jobs, source/manifests/certificates remain untouched.

The complete real-MMCM probe is consumed by output SHA. Actual divider30 produces host period24.997ns (derived24.9975), with WNS-0.424/WHS+0.001 before physical repair. The target RTL, bridge ratios,56,584 target-clock registers and unrelated clock periods remained unchanged in the real probe. This is diagnostic evidence, not timing or bitstream certification.

Two reused AXI clock converters are explicitly asynchronous, with3stage synchronizers; target STEP/DONE and clock counts contain no physical-frequency conversion. Driver/trace/ABI are hashbound. New certification independently checks actual MMCM and all66 physical-clock periods, setup/hold, route coverage, DRC, pulse and bus-skew before deploying. This distinct profile never claims full Opt4 or formal PARSEC data.

Both shared21 locks, full Opt4 priority, concrete-conflict checks and existing-valid-component-winner checks remain active. Application follower never deploys and requires latest deployment's bitstream SHA to match its own host40 certificate. No e2/global FPGA operations.

Installation receipt: `/data1/gzh/EC/firesim/final-opt4-20261106/candidates/svb-host40-physical-r1-20261112/installation.json` SHA256 `34dc78a9c2a2fe56a35422010ef33444733b103cf58b6b70ce562003670f1aa5`.

- `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-svb-host40-physical-r1-state.json`: WAITING_R51_EXACT_CGROUP_RELEASE_NO_CAD PID 2402382.
- `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-original-svb-host40-onboard-r1-20261112/state.json`: WAITING_INDEPENDENT_HOST40_PHYSICAL_RESULT_NO_FPGA_IO PID 2402383.
- `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-original-svb-host40-application-onboard-r1-20261112/state.json`: WAITING_CERTIFIED_COMPONENT_AND_REAL_APPLICATION_CPU_REPLAY PID 2402384.
