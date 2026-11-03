# PARSEC characterization

Native denotes the unprotected execution mode defined in CONFIG.md. Host seconds are simulation cost. Only validated, work-equivalent selected triplets enter normalized means.

|benchmark|input|native_ROI|check_ROI|correction_ROI|check_native|correction_native|correction_check|native_baseline_scope|
|---|---|---|---|---|---|---|---|---|

## Statistics

{}

## Validated raw measurements

|benchmark|input|design|roi_cycles|roi_instructions|roi_IPC|host_seconds|correct|
|---|---|---|---|---|---|---|---|
|blackscholes|simdev|check|1551970|904747|0.5829668099254496|908.2512398082763|PASS|
|blackscholes|simdev|correction|1615350|904747|0.5600934781935804|2316.4009550679475|PASS|
|blackscholes|simdev|native|1534367|904747|0.5896548869990035|2235.0147724188864|PASS|
|canneal|simdev|check|119034|110507|0.928365004956567|555.2564487978816|PASS|
|streamcluster|simdev|check|920602|1094668|1.1890784508397765|572.5827882774174|PASS|
|streamcluster|simdev|native|854140|1094668|1.2816025475917296|1374.92516323179|PASS|

Missing counters are N/A in counters/RUNS.csv. See CONFIG.md for counter-window and partial-package scope. Invalid, aborted and pending runs are listed in logs/exclusions.json. Recovery results are separate in recovery/.
