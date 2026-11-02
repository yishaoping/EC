# Optimization history — classifications and evidence boundaries

Current stable version **Opt4**, slowdown **1.7050×**. Optimization PAUSED on2026-11-02
so DAC experiments can use a fixed reproducible version; not a claim all bottlenecks
are closed. Figures below are same pinned GAPBS512 software ROI, not additive causal gains.

|Stage|ROI cycles / classification|Mechanism / evidence|
|---|---|---|
|Native/reference baseline|1,001,675; PROVEN recorded measurement, historical provenance/drain limits retained|baseline/runs/b3_20261023_162309_15ywsnjz/run_manifest.json|
|Original EC Current|4,734,881; PROVEN recorded measurement|slowdown/runs/current_20261023_222009_3cebcab2/ and Opt1 reference metrics|
|Opt1|4,706,513; PROVEN recorded result|Same-set different-tag safe hit-only admission; old locally ignored optimization_1/ retained.|
|Opt2|4,707,273; PROVEN measured, no net improvement overOpt1|optimization_2 run20261027_144838_fdf571b7; laterOpt2b3,760,243 improved checker/result chain.|
|Opt3|2,928,347; PROVEN measurement, validated checker frontend optimization|source commit092301df4; optimization_3_checker/manifests/measured_result.json and versioned references.|
|Opt4|1,707,863; PROVEN benchmark/integrity/protocol/ordering/ROI after host recertification|SVB16 and correctness/fast-line fixes; source476a76091; ../OPT4_BASELINE.md. L2 S0 fidelity remains failed.|
|PausedOpt5/L1|B64KiB ROI1,648,923; REFERENCE_ONLY for A/new-B comparison|Strict matched A/new-B pairing pending; capacity alone insufficient for sub1.5; l1_capacity/ and checker_seq67/.|
|seq67 trap/return race|PROVEN on experimental B path|Privileged CPS/real trap dispatch/return collision, corrected B closes320 packages; not backported into stable Opt4.|
|Direct load path|DEPRIORITIZED as sole sub1.5 mechanism|Head wait53,845 and nested80,832 are scoped fixed-trace envelopes, not all feedback effects; load_critical_path/.|
|Cache transfer|Static serialization PROVEN; critical recoverable saving NOT_PROVEN|6,735 releases/53,880 bank writes; ROI2,231; phase union100,915 is exposure, not gain; cache_transfer/.|
|Preservation / outerA|Packet-through-ACK theory REJECTED; whole mechanism NOT_PROVEN|Packet lock ends on finalA, not ACK. Intrinsic-gap-only UB34,104 is too small as mainOpt5; preservation_outerA/.|
|SourceC HOL|PROVEN static global reservation→Release/Acquire dependency; runtime gain NOT_PROVEN|Minimal waitAck bypass prepared, Scala+14CPU only, no hardware run. sourcec_hol/ and experimental_patches/.|

SVB32 is DEPRIORITIZED (SVB16 full-episode local bound5,254); promotion-only mainline
DEPRIORITIZED (24,569 safe→terminal union is exposure); pure MSHR capacity and direct
load-only sub1.5 are not justified. Independent cache-transfer/BOOM-checker feedback
may remain. Checker frontend remains LAST_RESORT for future optimization.

[Archive inventory](archive_inventory.json) records original and copied report identity.
Original AI/TMP reports, raw data, source seals, capture FAIL/recovery, run/build paths
and launch claims are retained. No historical failure was overwritten by a PASS.
[Resume guide](RESUME_OPTIMIZATION.md) describes recovery; archived next-run commands
are historical and superseded by PAUSED.
