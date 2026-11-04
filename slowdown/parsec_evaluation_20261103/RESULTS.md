# PARSEC characterization

Native denotes the unprotected execution mode defined in CONFIG.md. Host seconds are simulation cost. Only validated, work-equivalent selected triplets on the accepted hardware revision enter normalized means. Historical pilot rows are not primary comparisons.

|benchmark|input|native_ROI|check_ROI|correction_ROI|check_native|correction_native|correction_check|native_baseline_scope|
|---|---|---|---|---|---|---|---|---|
|blackscholes|project64|5920394|5952831|6165734|1.0054788583327394|1.0414398095802408|1.035764999879889|matched detection hardware without recovery datapath, protected session disabled|
|streamcluster|project64|2281930|2499121|3706513|1.0951786426402212|1.6242886503968132|1.4831266673362353|matched detection hardware without recovery datapath, protected session disabled|
|canneal|project400|310942|419398|668878|1.3487981681471142|2.1511342951418593|1.5948526220916648|matched detection hardware without recovery datapath, protected session disabled|

## Statistics

```json
{
  "check_native": {
    "n": 3,
    "geometric_mean": 1.1409544124080222,
    "arithmetic_mean": 1.1498185563733583,
    "median": 1.0951786426402212,
    "min": 1.0054788583327394,
    "max": 1.3487981681471142,
    "minimum_benchmark": "blackscholes",
    "maximum_benchmark": "canneal"
  },
  "correction_native": {
    "n": 3,
    "geometric_mean": 1.53811321288143,
    "arithmetic_mean": 1.605620918372971,
    "median": 1.6242886503968132,
    "min": 1.0414398095802408,
    "max": 2.1511342951418593,
    "minimum_benchmark": "blackscholes",
    "maximum_benchmark": "canneal"
  },
  "correction_check": {
    "n": 3,
    "geometric_mean": 1.3480934874822832,
    "arithmetic_mean": 1.3712480964359297,
    "median": 1.4831266673362353,
    "min": 1.035764999879889,
    "max": 1.5948526220916648,
    "minimum_benchmark": "blackscholes",
    "maximum_benchmark": "canneal"
  }
}
```

## Correctness and work equivalence

|benchmark|input|ROI_instructions|check_PASS|correction_PASS|correction_FAIL|correction_CANCELLED|correct|
|---|---|---|---|---|---|---|---|
|blackscholes|project64|3562647|N/A|1174|0|0|PASS|
|streamcluster|project64|3017385|N/A|1213|0|0|PASS|
|canneal|project400|392248|N/A|139|0|0|PASS|

Detection package counts and checker-work coverage are N/A because this sealed detection model has no equivalent accepted-result/work ledger. Identical protected ELF, application retired instructions, input/loops and output are independently required.

## Mechanism counters

|benchmark|input|checker_active_capacity_lower_bound|checker_backpressure_BOOM_cycles|version_management_block_cycles|SourceC_ACK_wait_cycles|result_queue_stalls|drain_tail_cycles|
|---|---|---|---|---|---|---|---|
|blackscholes|project64|0.1973623091751931|N/A|5171|4647|0|13050|
|streamcluster|project64|0.12843688933507044|N/A|12413|36934|0|5314|
|canneal|project400|0.6740377168930657|N/A|8148|19894|0|7193|

Checker activity is a lower bound from fully captured packages inside the ROI. Stall counters cover the recorded hardware traffic window, not necessarily the application ROI; categories can overlap. They do not constitute an additive explanation of slowdown.

## Application versus verified completion

|benchmark|input|correction_app_ROI|correction_outstanding_at_app_end|correction_drain_tail|correction_start_to_verified|check_start_to_verified|verified_correction_check|
|---|---|---|---|---|---|---|---|
|blackscholes|project64|6165734|3|13050|6178784|N/A|N/A|
|streamcluster|project64|3706513|1|5314|3711827|N/A|N/A|
|canneal|project400|668878|3|7193|676071|N/A|N/A|

The correction drain includes all packages allocated before application end. Detection software session completion is not the same observable and is not substituted for verified completion.

## Validated raw measurements

|benchmark|input|design|roi_cycles|roi_instructions|roi_IPC|host_seconds|correct|
|---|---|---|---|---|---|---|---|
|blackscholes|project64|check|5952831|3562647|0.5984794461660343|3407.466882545501|PASS|
|blackscholes|project64|correction|6165734|3562647|0.5778139309934551|8927.448627719656|PASS|
|blackscholes|project64|correction|6165734|3562647|0.5778139309934551|9021.736087268218|PASS|
|blackscholes|project64|native|5920394|3562647|0.6017584302666343|3422.970922164619|PASS|
|blackscholes|simdev|check|1551970|904747|0.5829668099254496|908.2512398082763|PASS|
|blackscholes|simdev|correction|1615350|904747|0.5600934781935804|2316.4009550679475|PASS|
|blackscholes|simdev|correction|1615350|904747|0.5600934781935804|2427.5652909409255|PASS|
|blackscholes|simdev|native|1534367|904747|0.5896548869990035|2235.0147724188864|PASS|
|blackscholes|simdev|native|1522825|904747|0.5941240786039105|883.7430800311267|PASS|
|canneal|project400|check|419398|392248|0.935264355099452|722.3095146156847|PASS|
|canneal|project400|correction|668878|392248|0.5864268222306609|2461.785780698061|PASS|
|canneal|project400|correction|668878|392248|0.5864268222306609|2456.1166412718594|PASS|
|canneal|project400|native|310942|392248|1.2614828488914331|674.7096065189689|PASS|
|canneal|simdev|check|119034|110507|0.928365004956567|555.2564487978816|PASS|
|canneal|simdev|correction|182954|110507|0.6040152169397772|1846.998416500166|PASS|
|canneal|simdev|correction|182954|110507|0.6040152169397772|1996.5726660862565|PASS|
|canneal|simdev|native|92212|110507|1.1984015095649156|533.9054273888469|PASS|
|streamcluster|project64|check|2499121|3017385|1.2073785142856228|1453.6897538471967|PASS|
|streamcluster|project64|correction|3706513|3017385|0.8140764648606386|5555.684157593176|PASS|
|streamcluster|project64|correction|3706513|3017385|0.8140764648606386|5404.514061300084|PASS|
|streamcluster|project64|native|2281930|3017385|1.3222951624282953|1326.948180327192|PASS|
|streamcluster|simdev|check|920602|1094668|1.1890784508397765|572.5827882774174|PASS|
|streamcluster|simdev|correction|1452774|1094668|0.7535019211522233|2222.1411819513887|PASS|
|streamcluster|simdev|native|854140|1094668|1.2816025475917296|1374.92516323179|PASS|
|streamcluster|simdev|native|751653|1094668|1.4563475433477948|468.55510263703763|PASS|

Missing counters are N/A in counters/RUNS.csv. See CONFIG.md for counter-window and partial-package scope. Invalid, aborted and pending runs are listed in logs/exclusions.json. Recovery results are separate in recovery/.
