# Frozen Opt4 baseline for DAC experiments

CURRENT_STABLE_OPT = Opt4

STATUS = FROZEN

SLOWDOWN ~= 1.7x

OPTIMIZATION_STATUS = PAUSED

OPT4_COMMIT = 962c4b87db2a810bc025a87f5f7289dd7aedc5cf

This freeze commit records the stable host recertification and reproducibility files.
MEASURED_FUNCTIONAL_SOURCE_COMMIT = 476a760910f3bfbd3c111000ebe40343870ab439

There is no new hardware optimization.
The cleanup restores later experiments to that exact hardware tree; it does not change
Opt4 functional RTL. Freeze/archive commits only add host recertification/reproducibility
and organization. The archive commit identity is available with `git log --oneline -- slowdown/OPT4_BASELINE.md`
and in the final cleanup report; no self-referential commit hash is embedded.

|Item|Verified value|
|---|---|
|Opt4 run|optimization_4_svb_20261030_072604_18475a92|
|Opt4 ROI|1,707,863 main cycles; start712114, stop2419977|
|Native/reference ROI|1,001,675; baseline/runs/b3_20261023_162309_15ywsnjz|
|Ratio|1.7050071130855817×|
|SVB|16 entries|
|Configuration|v1Config, BOOM hart0 at200MHz, Rocket checker harts1–4 at100MHz|
|BOOM L1D|32KiB,256sets×2ways,64B,6MSHRs|
|L2|1MiB,1024sets×16ways,64B,one bank|
|Software|Same pinned GAPBS BFS512/8192edges/source0 ELF+loadmem; no recompilation|
|Correctness|PASS in separate offline-recertified summary; verified1/checksum43439728|
|Integrity/protocol/order/capture|PASS;406 allocations=391 completed+12 coalesced+3 flush-discarded; no duplicate beats|
|Observers|L1 S0 PASS; original L2 S0 FAIL, blocked for L2 geometry recommendations|
|Frozen source fingerprint|bc1843a9bae6448cb252c50d1c29362535bce8682951b254905c7284c27b23ff|
|Generated config SHA256|fadf76a18905fde7c415917e3f1adab9f7d6dbe1e3e75c85c98941d74283789f|
|Measured cumulative patch SHA256|1426121f50bfbf5fc205bc80f4dc9a44c0c00d11fc5b37bac367ce9e0bb95281|
|ELF SHA256|da8897e790f0c5e91eff3e9560d2b0e7b4e1de6dff208788fb4d9e2ae462c81c|
|Loadmem SHA256|f1c0335e8a7ffc6f57232e9bcb8c80a49f45eacaa1e4f533f4cb3af91ad308ad|

The original raw summary/manifest remains unchanged with historical shadow-related
FAIL/partial status. Corrected host analysis separates counterfactual S0 fidelity from
functional, benchmark, allocation-scoped integrity, protocol and ordering. It does not
turn failed L2 S0 estimates into validated data. Both original and corrected views are
versioned in [opt4/reference](opt4/reference/); full raw evidence remains at original
[run directory](optimization_4_svb/runs/optimization_4_svb_20261030_072604_18475a92/).
The original12 hardware/resource SHA256s all match the measured source commit; an
expanded20-file scope additionally protects experimental config/checker/SourceC targets.
See [machine identity](opt4/frozen_manifest.json).

The64KiB B ROI1,648,923 and recovered320-package result are **REFERENCE_ONLY** in
[analysis archive](analysis_archive/l1_capacity/). They are not this stable result.
SourceC candidate has no runtime result.

## Reproducible entry

Repository root `/data1/gzh/EC`; stable sources remain under chipyard/generators/;
implementation/launcher remains `slowdown/optimization_4_svb/` (no path rearrangement).
Read-only checks: `python3 -I -B slowdown/scripts/verify_opt4_frozen.py` and
`bash slowdown/run_optimization_4_svb.sh --static-check`.
The existing user-run launcher is the future Opt4 benchmark/config entry; no simulation
is authorized or started by this cleanup. Subsequent DAC experiments should branch
from the frozen archive state and keep v1Config/Opt4 unless explicitly stated otherwise.

Limits remain: historical baseline RUN_PROVENANCE and complete durable cache/package/
DRAM drain/recovery are not newly proven. No new elaboration/build/simulation occurred.
