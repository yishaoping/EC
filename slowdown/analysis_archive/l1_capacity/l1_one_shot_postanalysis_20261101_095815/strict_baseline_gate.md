# Strict baseline gate

`STRICT_BASELINE_REFRESH_JUSTIFIED`.

| Gate | Evidence | Verdict |
|---|---|---|
|0 correctness/measurement|complete320 package closures; checker/observer/integrity PASS after auditable lossless recovery; full ROI|PASS|
|1 trivial benefit|saving58,940 >5,000; head wait falls85,849|not a weak/trivial signal|
|2 weak5k–15k|saving exceeds15k with consistent counters|not this case|
|3 strict refresh worthwhile|3.4511% >1%; actual misses−19.8%; head wait−61.46%; nack retries−57.72%|PASS|
|4 strong signal|tens of k ROI savings and85.8k head-wait reduction near earlier85k opportunity scale|STRONG_OPT5_SIGNAL (reference only)|

Do not reuse old A as a final strict baseline. A_NON_INTERFERENCE_PROVEN remains NO because701 old SC6 records are missing. Do not rerun B: corrected B is complete and all mandatory evidence has been recovered from saved bytes. No extra geometry/policy run is justified ahead of this one A-prime.

A-prime = Opt4/SVB16/baseline32KiB L1D2way/6MSHR + **exact completed-B hardware source** (checker fix, SC46/47, STOP, observer and native counters), software/checker mask/seed/arguments unchanged. Only the two host bookkeeping caps change128→256, under a separate explicit seal. This adds sufficient bounded identity metadata storage and has no RTL or counter-definition effect. Original B tools remain untouched. Raw B mandatory evidence is validated with the same unchanged performance gates; final pairing audits actual argv, generated geometry/clocks/L2/native resource copies and complete A correctness.

```bash
bash AI/Debug/scripts/run_checker_seq67_baseline_refresh.sh --report AI/TMP/l1_one_shot_postanalysis_20261101_095815/baseline_refresh --jobs 4
```

User execution only. Exclusive persistent A-prime claim forbids duplicate launch; no retry, B command, second arm or cleanup. A wrapper rejects arm B and all source/software/patch guards remain called. If this A-prime fails, preserve artifacts and diagnose offline; do not automatically consume another run. No hardware phases were executed by the agent.
