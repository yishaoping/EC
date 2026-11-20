Resource-aware original SVB component physical recovery, round 51

The four strict-r2 attempts stopped at the original `load<48` assertion before
sealing any input or invoking Vivado. Their states, logs and service definitions
are preserved. This module job runs through the existing CPU broker and waits
300 seconds between resource checks. It never installs or stops a service.

The unchanged admission gates are 128 GiB available memory, 96 GiB free disk,
load strictly below 48, exact inactive/failed producer cgroups with MainPID0,
no live recovery task, original source identity and unchanged frozen policy.
CPUs 254-255 and the original 64 GiB process limit are retained. No whole DUT
synthesis, RTL change, clock relaxation, board I/O or Native run occurs here.

After admission, the existing hash-bound r1 physical implementation runs in
independent `cycleprecise-svb-postroute-recovery-r1-20261111/round51-v1/` variant
directories. Resource races before the original controller creates state defer
without consuming an attempt. Any other failure remains immutable and that
variant is not retried. At most four original deterministic physical variants
are considered, sequentially under the original global physical lock.

A real successful result is published through the existing chosen-result
manifest. The live original recovered certificate and application followers
retain all source/ABI/clock/timing/DRC/21-lock requirements. A handed-off artifact
is not certification or an FPGA measurement.
