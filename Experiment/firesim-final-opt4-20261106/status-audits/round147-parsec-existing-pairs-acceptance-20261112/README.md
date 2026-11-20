Eight existing matched CPU profiles are accepted independently of the historical
FPGA archive. The original publication remains unchanged at
`Experiment/parsec8-performance-audit-20261112`, including its partial status and
its original verifier failure. Its 24 pairs and complete 48-log decompression
audit are reused. This receipt rechecks the compressed log hashes and current
result, completion, binding, software/model, and strict checker evidence without
repeating raw decompression or any simulation.

Three historical Blackscholes FPGA `state.json` files differ from the hashes in
their saved results. They remain excluded; 21 of 24 historical evidence sets pass.
The precise expected and actual hashes are recorded in `result.json`. The cause
of the historical state changes is unproven. Those Linux simmedium runs differ
from the current CPU workloads and none is used as a slowdown denominator.
Historical board identities are read from saved files only.

| Benchmark | Native ROI cycles | EC ROI cycles | EC / Native | Scope |
|---|---:|---:|---:|---|
| blackscholes | 60832 | 63547 | 1.044631× | 64 options, one bs_thread iteration |
| fluidanimate | 16949 | 28077 | 1.656558× | Captured AdvanceParticles phase, 64 particles |
| bodytrack | 125929 | 146905 | 1.166570× | Captured likelihood phase, frame0 maps |
| freqmine | 166379 | 467929 | 2.812428× | Three-transaction test, hot4 cache |
| swaptions | 167237 | 337633 | 2.018889× | Original worker, 16 trials |
| ferret | 24720 | 34184 | 1.382848× | EMD matrix, 126 region pairs; excludes flow solution |
| dedup | 211667 | 407603 | 1.925680× | Six-byte test, 16 MiB buffer, preloaded hash table |
| streamcluster | 303982 | 609828 | 2.006132× | Original worker, 16 points, FP contraction disabled |

Each declared profile has three identical deterministic repeats. These are
cycle-exact CPU Golden Gate measurements on frozen
`8491167d84b6d9521b151a743673c1516926a1f8`. They establish neither full-application
nor full-simmedium nor FPGA slowdown. Boot ELF/link addresses and initial cache
layouts differ; repeat agreement does not establish uncertainty across inputs.
No CPU campaign, FPGA operation, CAD job, source edit, or controller change is
performed by this reconciliation. Existing CAD remains with its original owners.
