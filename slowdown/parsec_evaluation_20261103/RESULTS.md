# PARSEC characterization

Native denotes the unprotected execution mode defined in CONFIG.md. Host seconds are simulation cost. Only validated, work-equivalent selected triplets on the accepted hardware revision enter normalized means. Historical pilot rows are not primary comparisons.

|benchmark|input|native_ROI|check_ROI|correction_ROI|check_native|correction_native|correction_check|native_baseline_scope|
|---|---|---|---|---|---|---|---|---|

## Statistics

```json
{}
```

## Correctness and work equivalence

|benchmark|input|ROI_instructions|check_PASS|correction_PASS|correction_FAIL|correction_CANCELLED|correct|
|---|---|---|---|---|---|---|---|

Detection package counts and checker-work coverage are N/A because this sealed detection model has no equivalent accepted-result/work ledger. Identical protected ELF, application retired instructions, input/loops and output are independently required.

## Mechanism counters

|benchmark|input|checker_active_capacity_lower_bound|checker_backpressure_BOOM_cycles|version_management_block_cycles|SourceC_ACK_wait_cycles|result_queue_stalls|drain_tail_cycles|
|---|---|---|---|---|---|---|---|

Checker activity is a lower bound from fully captured packages inside the ROI. Stall counters cover the recorded hardware traffic window, not necessarily the application ROI; categories can overlap. They do not constitute an additive explanation of slowdown.

## Application versus verified completion

|benchmark|input|correction_app_ROI|correction_outstanding_at_app_end|correction_drain_tail|correction_start_to_verified|check_start_to_verified|verified_correction_check|
|---|---|---|---|---|---|---|---|

The correction drain includes all packages allocated before application end. Detection software session completion is not the same observable and is not substituted for verified completion.

## Validated raw measurements

|benchmark|input|design|roi_cycles|roi_instructions|roi_IPC|host_seconds|correct|
|---|---|---|---|---|---|---|---|
|blackscholes|simdev|check|1551970|904747|0.5829668099254496|908.2512398082763|PASS|
|blackscholes|simdev|correction|1615350|904747|0.5600934781935804|2316.4009550679475|PASS|
|blackscholes|simdev|native|1534367|904747|0.5896548869990035|2235.0147724188864|PASS|
|canneal|simdev|check|119034|110507|0.928365004956567|555.2564487978816|PASS|
|canneal|simdev|correction|182954|110507|0.6040152169397772|1846.998416500166|PASS|
|streamcluster|simdev|check|920602|1094668|1.1890784508397765|572.5827882774174|PASS|
|streamcluster|simdev|native|854140|1094668|1.2816025475917296|1374.92516323179|PASS|

Missing counters are N/A in counters/RUNS.csv. See CONFIG.md for counter-window and partial-package scope. Invalid, aborted and pending runs are listed in logs/exclusions.json. Recovery results are separate in recovery/.
