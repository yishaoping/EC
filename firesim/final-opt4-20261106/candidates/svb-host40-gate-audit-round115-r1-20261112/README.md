# Host40r2 gate control-flow audit

Run `/usr/bin/python3 audit.py` once. Results are retained under
`Experiment/firesim-final-opt4-20261106/build-logs/Opt4-svb-host40-gate-audit-round115-r1-20261112`.
The runner refuses to overwrite completed or partial evidence.

This audit executes copies of both installed r2 Tcl templates with explicit
mock implementations of every Vivado API. It tests two positive paths and
44 rejection paths: wrong device, unresolved cells, MMCM changes, clock set
and host/shell period changes, missing target clock/register/path coverage,
negative setup/hold, incomplete routing, DRC errors, pulse violations and
bus-skew violations. It also executes the exact clock-coverage expressions
from the independent Python certificate. The live templates and installation
manifests remain hash-bound and unchanged.

No Vivado, DCP read, synthesis, physical implementation, bitstream generation,
certificate creation or FPGA access occurs. Passing this test validates gate
control flow under the stated mocks; measured physical timing and independent
certification remain mandatory. Full Python artifact/hash transport and actual
Vivado API availability are outside this test's scope.
