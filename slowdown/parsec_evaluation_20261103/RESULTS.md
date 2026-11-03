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
|blackscholes|simdev|native|1534367|904747|0.5896548869990035|2235.0147724188864|PASS|

Missing counters are N/A in counters/RUNS.csv. See CONFIG.md for counter-window and partial-package scope. Invalid, aborted and pending runs are listed in logs/exclusions.json. Recovery results are separate in recovery/.
