# Original SVB conditional physical recovery

Functional baseline `8491167d84b6d9521b151a743673c1516926a1f8`; component source ID `b1d917ca49290fe8732de71bfad9e99edc421fba574f6aff0d1142c1fb248a3f`.

At preparation time this mechanism has not been installed and has not run placement, physical optimization or routing. Both existing route producers remain unchanged. The only Vivado processes started during preparation read command help without opening a design.

`run.py` defaults to a read-only eligibility report. `--run` refuses a live or successful producer and requires a matching source ID, recorded failure, inactive/failed service, dead PID/start/boot identities, a saved checkpoint, original generated input hashes, and resource headroom. It preserves a sealed checkpoint and original failure evidence. It admits at most a replacement for one exited component route slot; it never creates a third component route. The parent must wrap it in a persistent bounded service before allowing actual execution.

Two independent recovery modes:

- `--mode postroute`: restore the failed producer's saved routed DCP; try `ExploreWithAggressiveHoldFix`, preserved ECO routing, then at most one `AggressiveExplore`/hold-fix and routing pass. Save each physical/routed checkpoint. No resynthesis.
- `--mode replicate`: restore the failed producer's saved physopt DCP; verify the exact two original activeIdx driver nets, each with at least 1,000 loads; force physical replication even with positive setup slack, record before/after fanout, congestion and resource reports, route, then use the same bounded timing repair. This addresses a different failure mechanism from the already running `AggressiveFanoutOpt` branch, which is timing driven.

Actual Vivado 2021.1 help was checked for `-force_replication_on_nets`, `ExploreWithAggressiveHoldFix`, `-aggressive_hold_fix`, `route_design -preserve -directive Explore -tns_cleanup` and pulse-width reporting. No retiming, negative-edge FF insertion, clock/frequency changes, source RTL changes, FPGA, JTAG, PCIe or driver operations are used.

Bitstream writing requires original 19.998 ns target clock, clock coverage, no unresolved IP, full routing, setup/hold/pulse timing and DRC gates. A resulting bitstream is only marked pending independent certification. `runtime.py` independently restores the final routed checkpoint, rechecks source/driver/trace/clock/timing/DRC bindings, and only then can deploy and run the original directed sample on card21. It shares both existing card21 locks and gives a completed original/spread sample priority. It can only stop verified pure-waiting old deployment controllers after certification; it never stops CAD or an active board task.

`install.py` (root) prepares four separate bounded CPU worker units, a five-minute dispatcher timer, and the waiting certification/runtime follower. Workers are not enabled or started by installation. The dispatcher only starts an independently versioned replacement after a real recorded producer failure, dead identities and an empty exact cgroup. Original replacement CPUs252–253 and spread replacement CPUs254–255 use 200%/64GiB limits. Only one recovery runs at a time, and each source/mode/checkpoint is attempted at most once. It retains failures and tries the next eligible mode. Two healthy producers produce a waiting status, not another CAD process.

Read-only checks:

```sh
python3 run.py --producer spread --mode postroute
python3 run.py --producer original --mode replicate
```

Evidence: `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/`. Current read-only checks reject both live producers; no recovery was launched.
