# PARSEC CPU Golden Gate measurement method

This CPU-only campaign uses frozen EC functional baseline `8491167d84b6d9521b151a743673c1516926a1f8`. Source/configuration receipts are in `audit/`. It does not require an FPGA bitstream. No FPGA, Vivado or CAD command is part of this campaign.

The clean Native and frozen EC models use the matched single-BOOM target and FASED memory: BOOM 200 MHz, EC checker 100 MHz, read/write latency 30, maximum four requests and relax=0. Both run one application thread. At most two single-threaded simulators use CPUs 200 and 201 at nice 19. CPU 201 serves EC. CPU 200 serves Native, then an auxiliary EC slot after the selected eight first Native runs pass; a shared CPU lock prevents Native and auxiliary EC from running together. Address-space reservation is capped at 64 GiB because the simulated memory backing needs a large mmap; resident memory is bounded at 16 GiB for new runs. Build/reference tasks use CPU 200 at nice 19. Later runners record an execution policy with a 14,400-second host-time floor to let target-cycle caps be reached at the observed EC simulation throughput; this host budget does not change the target or ROI.

Linux PARSEC ELF files cannot be loaded as valid applications by this bare-metal HTIF environment. Independent HTIF adapters use original PARSEC computational source, embedded byte-identical inputs or explicitly reduced inputs. Native and EC share all compiled application objects and compiler flags (O2, rv64imafd, static HTIF/newlib, lp64d ABI). Their EC initialization and startup ELF images differ; address layout and cache state can differ. This is a paired comparison for the declared profile, with a remaining layout confound. It is not a same-ELF or Linux simmedium comparison. Each manifest records compiler invocations, ELF/source/object/input hashes, independent host reference, ROI and limitations. See `abi-audit.json` when available for decoded ELF metadata.

Both modes clear main-hart MTIE before workload preparation. The frozen checker firmware is unchanged. Timer counter values and MIE are printed across ROI and checked. RD cycle and retired-instruction CSRs surround exactly the shared workload_run call; setup, verification and output are outside ROI. The common timer-counter read contributes the same instrumentation inside each ROI. An output-valid pair is accepted only when the Native and EC instruction counts match, both manifests match their run bindings, and the EC strict join proves every allocated package began, completed full comparison and was accepted by BOOM with zero pending/failure/cancellation/duplicate entries.

The following profiles are independent measurement contracts. Every listed cycle is a measured target cycle if a result has passed; pending cells are empty. Exact simulation of a short profile does not establish its representativeness for simmedium.

| Benchmark | Method | ROI profile | Native cycles | EC cycles | Status |
| --- | --- | --- | ---: | ---: | --- |
| blackscholes | CPU_GG_TEST_DERIVED_REPRESENTATIVE_ROI | project64-one-iteration-no-main-timer | 60832 | 63547 | VALID_CPU_GG_PAIR |
| fluidanimate | CPU_GG_TEST_DERIVED_REPRESENTATIVE_ROI | test-derived-64-particles-no-main-timer-heap64 | 455066 |  | PAIR_PENDING |
| bodytrack | CPU_GG_REAL_TRACE_COMPONENT_REPLAY | real-frame0-likelihood-measurement-replay | 125929 | 146905 | VALID_CPU_GG_PAIR |
| freqmine | CPU_GG_TEST_DERIVED_REPRESENTATIVE_ROI | test-input-hot4-lp64-quiet-roi | 166379 |  | PAIR_RUNNING |
| swaptions | CPU_GG_REPRESENTATIVE_TEST_PROFILE | representative-16-trial-no-main-timer | 167237 | 337633 | VALID_CPU_GG_PAIR |
| ferret | CPU_GG_REAL_TRACE_COMPONENT_REPLAY | real-test-first-emd-warm-replay-qword-setup | 212516 |  | PAIR_PENDING |
| dedup | CPU_GG_FULL_OFFICIAL_TEST | official-test-gzip-serial-qword-setup-heap512 | 215277 |  | PAIR_PENDING |
| streamcluster | CPU_GG_TEST_DERIVED_REPRESENTATIVE_ROI | representative-16-points-fp-contract-off | 303982 |  | PAIR_RUNNING |

**blackscholes**: One original bs_thread iteration over the same 64 option records in both modes; the records contain distinct call/put and price/volatility cases. Setup/output are outside ROI.

- One iteration, not project64 100-iteration full workload; extrapolation error uncalibrated
- Distinct startup/link/cache state; shared application objects

**fluidanimate**: One complete original serial AdvanceFrame on test-derived 64-particle input; initialization and verification outside ROI

- Test-derived reduced particle population; sampling error versus official test/simmedium is uncalibrated; no extrapolation to full workload slowdown
- Heap reservation raised from 4 MiB to 64 MiB for original grid and cell pools
- Whole original grid/domain/physics and frame phases retained; embedded input replaces filesystem only

**bodytrack**: Unmodified original ImageErrorEdge and ImageErrorInside on real LogLikelihood initial-pose projection/maps captured from official frame0

- Actual likelihood measurement component replay only; excludes pose generation, geometry/projection, image processing and particle filter control
- Coverage weight and extrapolation error against full Bodytrack uncalibrated; not full-application slowdown
- Only serialization accessors added; original ImageMeasurements.cpp is unchanged

**freqmine**: Hot4 original scan1_DB + scan2_DB + FP_growth_first; memory-pool setup and output verification outside ROI; input bytes read through embedded memory stream

- Original hot-item cache setting reduced 16 to 4 (recursive cache 6 to 4) equally in Native/EC and host; complete official-test itemset output verified but runtime is not original default cache configuration
- Full-default test and simmedium extrapolation error uncalibrated
- Packed scratch arrays aligned to 8 bytes and each pool allocation reserves 256 bytes of padding; fixes original x86-only unaligned pointer packing with unchanged mining/count semantics
- Heap reservation increased from 4 MiB to 128 MiB to fit unchanged original memory pools
- Data filesystem reads replaced with byte-identical embedded stream; full original FP-growth computation retained
- Unused iostream headers, host thread affinity and original CLI removed; wall-clock function returns zero in both builds; source hashes retained
- Successful input parser progress printf removed from ROI in both modes; count is still independently checked and printed after ROI. This eliminates HTIF fromhost spin loops dependent on host service timing.

**swaptions**: serial worker call only; workload setup/pricing-structure initialization and output verification outside ROI


**ferret**: One original EMD distance computation using first real query/candidate signature pair captured during the complete original serial Ferret official-test query; cost matrix allocation warmed outside ROI

- Actual first EMD invocation operands from official full test, not a synthetic vector microbenchmark
- One component invocation only; excludes decode, segmentation, extraction, LSH lookup, candidate control and result IO
- Component frequency/time coverage and extrapolation error against full Ferret are uncalibrated; do not publish as full Ferret slowdown
- Original cost-matrix allocation is warmed before ROI equally in both modes; original EMD and cass_dist source unchanged
- Main stack reservation raised to 512 KiB for original automatic EMD arrays
- ROI-external allocation retains the full 257x257 double matrix, using malloc and volatile uint64_t zero stores instead of bytewise calloc; warm original EMD call remains before ROI

**dedup**: Complete original SerialIntegratedPipeline (Rabin, SHA1, dedup, gzip and archive encoding), preloaded input and RAM archive sink; cache setup and correctness outside ROI

- ROI-external hashtable_create clears the identical 98317-entry pointer table with volatile uintptr_t stores instead of bytewise libc memset; table size/hash/pipeline unchanged; Native and EC share the same object
- Heap reservation raised to 512 MiB for unchanged original 128 MiB streaming buffer
- Input provided through original preloading path
- Archive xwrite replaced by byte-preserving in-memory output; file open/header/close omitted
- Original chunking/hash/dedup/compression computation retained

**streamcluster**: Complete original streamCluster on a 16-point SimStream, matched no-main-timer policy, setup and correctness outside ROI

- Reduced point count and kmax, not project64 or full simmedium; extrapolation error uncalibrated
- Floating multiply/add contraction disabled in both modes and host reference; target pair still requires identical output checksum

The official Freqmine test has three transactions and Dedup test has six input bytes; results at these tiny sizes cannot substantiate full benchmark performance. Swaptions uses 16 trials because the original 16-wide block kernel gives a NaN standard error for the official five-trial input. Bodytrack and Ferret use real application-generated component inputs, but their full-application time coverage and sampling error remain uncalibrated.

The primary CSV/plot contains only accepted first-round ratios, after independent raw-stream and binary/ELF/binding hash validation. Interrupted runs retain all evidence and can be retried in a new attempt directory. Selection uses the earliest successful completed attempt, never the fastest result. `run-attempts.csv` lists the attempts. Method-specific subset Geomeans list every included benchmark and are not the requested-eight Geomean. The requested-eight Geomean stays null until eight accepted pairs use the same method. Repeat statistics use complete paired repeats, record n, and leave standard deviation empty at n=1. Repeated deterministic runs do not sample workload diversity or software/hardware configuration uncertainty.

Checker acceptance tail is max(0, last accepted-result BOOM CSR cycle minus ROI-end CSR cycle). It is reported separately from ROI cycles. Strict checker detection needs same-package actual execution-done and checker-done endpoints; full rollback needs actual rollback begin/end events. These have not been captured, so those latency fields are null. No fault injection means this campaign cannot establish detection or recovery time. Where available, SVB capture/promotion/C-first/C-last/matching-ACK events are joined by full entry/line/sequence/generation key using their BOOM CSR timestamps. `svb-lifetimes.csv` marks captures inside ROI. Whole-run and ROI-capture populations are separate; matching-ACK tail describes completed observed ROI keys only. Missing/coalesced entries and absent payload validation prevent calling this architectural or complete SVB drain. Accepted package counts are not SVB lifetimes.

Historical Linux Native FPGA simmedium, bare-metal Canneal project400, old project64 runs and new short profiles are never paired across contracts. `diagnostic-pairs-excluded.csv` preserves old output-valid Blackscholes/Swaptions ratios with mismatched timer policies and instruction counts; none enters this plot or a Geomean. Canneal is workflow validation only. The independent historical audit is `audit/existing-data-audit.json`, including the existing Native FPGA repeats, CPU metasim and RTL evidence.

Each result points to its original run directory: `binding.json` contains the exact command and binary/ELF/manifest hashes; `host-complete.log.gz` is complete stdout/stderr; `stdout-integrity.json` records raw and compressed stream SHA-256; EC `external-events.jsonl` and `strict-acceptance.json` contain event and package evidence. `host-summary.log` is a filtered convenience log, not the complete source. A failed run retains its evidence and cannot yield a ratio. Rebuilds use new profile/directory bindings if an earlier target run exists. Run `python3 scripts/summarize.py` to refresh all paper exports.
