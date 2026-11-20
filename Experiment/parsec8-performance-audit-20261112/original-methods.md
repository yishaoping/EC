# PARSEC CPU Golden Gate measurement method

This CPU-only campaign uses frozen EC functional baseline `8491167d84b6d9521b151a743673c1516926a1f8`. Source/configuration receipts are in `audit/`. It does not require an FPGA bitstream. No FPGA, Vivado or CAD command is part of this campaign.

The clean Native and frozen EC models use the matched single-BOOM target and FASED memory: BOOM 200 MHz, EC checker 100 MHz, read/write latency 30, maximum four requests and relax=0. Both run one application thread. At most four single-threaded simulators use CPUs 200, 201, 202 and 204 at nice 19. CPU 201 prioritizes EC; when all eight first EC runs have been dispatched and no EC task is ready, it prefetches comparable repeats. CPUs 202/204 may serve guarded first Native samples and prefetch a missing earlier Native repeat before a later EC repeat, while sharing locks with their EC slots. CPU 200 serves Native, then an auxiliary EC slot after the selected eight first Native runs pass; a shared CPU lock prevents Native and auxiliary EC from running together. Extra EC slots on CPUs 202 and 204 sample pressure every 10 seconds and pause only their own simulator process groups while global CPU utilization exceeds 65%, the sibling hardware thread exceeds 20%, or available memory is below 64 GiB; per-run pressure events record pauses and resumes, and paused time is excluded from the active host budget. Address-space reservation is capped at 64 GiB because the simulated memory backing needs a large mmap; resident memory is bounded at 16 GiB for new runs. Build/reference tasks use CPU 200 at nice 19. Later runners record an execution policy with a 14,400-second active host-time floor to let target-cycle caps be reached at the observed EC simulation throughput; this host budget does not change the target or ROI. The initial CPU 208 extra slot was retired after sustained sibling-thread pressure; its interrupted attempt is preserved, and subsequent attempts use CPU 204. Earlier runs retain their original bound scheduling policy.

Linux PARSEC ELF files cannot be loaded as valid applications by this bare-metal HTIF environment. Independent HTIF adapters use original PARSEC computational source, embedded byte-identical inputs or explicitly reduced inputs. Native and EC share all compiled application objects and compiler flags (O2, rv64imafd, static HTIF/newlib, lp64d ABI). Their EC initialization and startup ELF images differ; address layout and cache state can differ. This is a paired comparison for the declared profile, with a remaining layout confound. It is not a same-ELF or Linux simmedium comparison. Each manifest records compiler invocations, ELF/source/object/input hashes, independent host reference, ROI and limitations. See `abi-audit.json` for decoded ELF metadata. `software-source-input-audit.json` independently rechecks retained sources, inputs, traces and host references against those hashes. The root htif.ld linker scripts were not separately hashed in the initial manifests; their current retained hashes and snapshot copies are supplemental, while the actual linked ELF hashes remain originally bound.

Both modes clear main-hart MTIE before workload preparation. The frozen checker firmware is unchanged. Timer counter values and MIE are printed across ROI and checked. RD cycle and retired-instruction CSRs surround exactly the shared workload_run call; setup, verification and output are outside ROI. The common timer-counter read contributes the same instrumentation inside each ROI. An output-valid pair is accepted only when the Native and EC instruction counts match, both manifests match their run bindings, and the EC strict join proves every allocated package began, completed full comparison and was accepted by BOOM with zero pending/failure/cancellation/duplicate entries.

The following profiles are independent measurement contracts. Every listed cycle is a measured target cycle if a result has passed; pending cells are empty. Exact simulation of a short profile does not establish its representativeness for simmedium. Counter resolution is one target cycle; the common CSR/instrumentation sequence is included on both sides. Exactness refers to the retained target model with fixed FASED settings. No empirical error bound to physical DRAM/FPGA timing is available. `measurement-uncertainty.csv` records this boundary separately from repeatability, workload representativeness, software layout and missing event endpoints. No extrapolated full-workload cycle estimates are produced.

| Benchmark | Method | ROI profile | Native cycles | EC cycles | Status |
| --- | --- | --- | ---: | ---: | --- |
| blackscholes | CPU_GG_TEST_DERIVED_REPRESENTATIVE_ROI | project64-one-iteration-no-main-timer | 60832 | 63547 | VALID_CPU_GG_PAIR |
| fluidanimate | CPU_GG_REAL_TRACE_COMPONENT_REPLAY | real-test64-preintegration-AdvanceParticles-4725-cells-norelax | 16949 | 28077 | VALID_CPU_GG_PAIR |
| bodytrack | CPU_GG_REAL_TRACE_COMPONENT_REPLAY | real-frame0-likelihood-measurement-replay | 125929 | 146905 | VALID_CPU_GG_PAIR |
| freqmine | CPU_GG_TEST_DERIVED_REPRESENTATIVE_ROI | test-input-hot4-lp64-quiet-roi | 166379 | 467929 | VALID_CPU_GG_PAIR |
| swaptions | CPU_GG_REPRESENTATIVE_TEST_PROFILE | representative-16-trial-no-main-timer | 167237 | 337633 | VALID_CPU_GG_PAIR |
| ferret | CPU_GG_REAL_TRACE_COMPONENT_REPLAY | real-test-emd-distance-matrix-126-pairs | 24720 | 34184 | VALID_CPU_GG_PAIR |
| dedup | CPU_GG_TEST_DERIVED_REPRESENTATIVE_ROI | official-test-gzip-serial-buffer16m-preloaded-table-heap512 | 211667 | 407603 | VALID_CPU_GG_PAIR |
| streamcluster | CPU_GG_TEST_DERIVED_REPRESENTATIVE_ROI | representative-16-points-fp-contract-off | 303982 | 609828 | VALID_CPU_GG_PAIR |

**blackscholes**: One original bs_thread iteration over the same 64 option records in both modes; the records contain distinct call/put and price/volatility cases. Setup/output are outside ROI.

- One iteration, not project64 100-iteration full workload; extrapolation error uncalibrated
- Distinct startup/link/cache state; shared application objects

**fluidanimate**: Verbatim original AdvanceParticles over original4725-cell grid and64 particles; p/hv/v/a captured after original RebuildGrid, ComputeForces, ProcessCollisions on first64 official-test input particles; excludes other frame phases

- Original AdvanceParticles subphase replay only, not complete AdvanceFrame or Fluidanimate
- Input population is reduced to first64 official-test records; full-frame/application time coverage and sampling error uncalibrated; no extrapolation
- Full AdvanceFrame profile produced actual checker CANCELLED result; this component does not repair or validate the failed full computation
- Cell storage is explicitly preloaded zero ELF data; Cell lifetimes and real captured state established outsideROI; warm/cache layout differs from complete frame
- Disable compiler/linker relaxation in both modes because prior profile linked one fewer AUIPC instruction for EC cells load; both original kernels/data unchanged
- Preserve all4725 original grid cells, indices, counts and sizeof(Cell) stride; maximum occupancy proven <=16 so no overflow cell is needed
- Captured all12 floating-point state components per particle before original integration; original host AdvanceParticles produces all9 output values per particle
- Both modes share exact application objects, trace, preparation, ROI and correctness check
- Supplemental independent Python binary32 integration oracle matches all576 original host-reference output floats bit-for-bit; see audit/fluid-advance-binary32-oracle.json and scripts/check_fluid_oracle.py. The measured target separately checks every output with the declared tolerance. An earlier component pair differed by one retired instruction because Native linked cells via AUIPC+LD and EC relaxed to gp-relative LD. That pair is excluded. The selected new profile disables target compiler/linker relaxation in both modes and requires a fresh pair; diagnostics/fluid-link-relaxation-mismatch.json binds both disassemblies and proves matching phase mnemonic sequences.

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
- Verification clarification: the exact per-cardinality itemset-count histogram and transaction count are checked against an independent oracle; individual itemset identities/supports are not emitted or compared.

**swaptions**: serial worker call only; workload setup/pricing-structure initialization and output verification outside ROI


**ferret**: Original emdinit distance-matrix loop over all126 region pairs from actual official-test first EMD query/candidate capture; original inline14-dimensional ground distance; excludes EMD flow solution

- Real captured EMD subphase only, not complete EMD or Ferret
- Original warmed full-EMD profile produced actual checker cancellations; this narrower scope does not repair or validate that full computation
- Full-application and full-EMD time coverage/sampling error uncalibrated; no extrapolation
- Explicit preloaded matrix and global state change cache/stack setup relative to full EMD; original full257-double row stride and original float-row interpretation retained
- Matrix rows are explicitly loaded zero ELF data before target execution; pointer setup outsideROI; same software objects/input in both modes
- Exact original emdinit distance-matrix loop copied verbatim from retained source; independent oracle checks all126 results

**dedup**: Complete original SerialIntegratedPipeline (Rabin, SHA1, dedup, gzip and archive encoding), preloaded input and RAM archive sink; cache setup and correctness outside ROI

- Changed buffer/initialization profile, not the original default128MiB buffer configuration
- Table is initialized by ELF loading and used exactly once; original dynamic table destruction is not called by this adapter
- Original128MiB-buffer EC run produced actual cancellations and is retained as a failure; this software variant does not establish a hardware root cause or fix
- Full-test pipeline computation on the official6-byte input only; full simmedium representativeness error uncalibrated
- ROI-external table creation uses a single-use 98317-entry zero table loaded as explicit ELF PROGBITS; table size/hash/pipeline unchanged; Native and EC share the same object; cache setup differs from runtime table clearing
- Heap reservation512MiB retained; MAXBUF changed128MiB to16MiB in both modes; 16MiB is the original8*ANCHOR_JUMP warning threshold and greatly exceeds the6-byte input
- Input provided through original preloading path
- Archive xwrite replaced by byte-preserving in-memory output; file open/header/close omitted
- Original chunking/hash/dedup/compression computation retained

**streamcluster**: Complete original streamCluster on a 16-point SimStream, matched no-main-timer policy, setup and correctness outside ROI

- Reduced point count and kmax, not project64 or full simmedium; extrapolation error uncalibrated
- Floating multiply/add contraction disabled in both modes and host reference; target pair still requires identical output checksum

`correctness-contracts.csv` specifies each verifier, comparison fingerprint and its limits. Output-match columns mean agreement of the reported output rows, including compact FNV fingerprints; several floating-point profiles use quantized fingerprints alongside individual tolerance checks. Swaptions has finite/nonnegative checks and agreement with a host fingerprint quantized to 1e-3, without emitting raw mean/error values. Dedup independently decompresses the host archive; target agreement is checked by its hash over every archive byte, not independent target archive decompression. These scopes must be preserved when describing correctness.

The official Freqmine test has three transactions and Dedup test has six input bytes; results at these tiny sizes cannot substantiate full benchmark performance. Swaptions uses 16 trials because the original 16-wide block kernel gives a NaN standard error for the official five-trial input. Bodytrack, Fluidanimate and Ferret use real application-generated component inputs, but their full-application time coverage and sampling error remain uncalibrated. Fluidanimate captures all12 state components per particle after original grid rebuild, force computation and collision handling, then replays the verbatim original AdvanceParticles on the original4725-cell grid. Its64-particle input is reduced, and the measured integration phase excludes the other frame phases. The original full-frame Fluidanimate and full-EMD Ferret attempts produced actual cancelled checker results; the narrower successful scopes, if accepted, do not repair or validate those failed computations. Dedup's selected profile changes MAXBUF from128MiB to16MiB and preloads its original-size zero hash table; its original128MiB attempt remains a failed observation. These choices create selection and scope limits, so no all-application claim follows from a complete profile table. Failure chains and original raw evidence are preserved in diagnostics/ and runs/.

The primary CSV/plot contains only accepted first-round ratios, after independent raw-stream and binary/ELF/binding hash validation. Interrupted runs retain all evidence and can be retried in a new attempt directory. Selection uses the earliest successful completed attempt, never the fastest result. `run-attempts.csv` lists selected-profile attempts and `all-run-evidence-ledger.csv` retains superseded profiles. Workload-scope subset Geomeans list every included benchmark separately. After all eight accepted pairs use the same exact CPU GG engine, their all-eight declared-profile Geomean is exp(mean(log(EC cycles / Native cycles))). It is explicitly a descriptive index of the eight listed profiles, including reduced/changed workloads and captured component replays. It does not estimate full applications; `full_application_geomean_slowdown` stays null. Different measurement engines or estimates are never mixed in that aggregate. Idle-slot Native repeats may be prepared while a first EC remains pending, after all first EC dispatches; completed noncomparable first contracts remain ineligible. EC repeats and published paired statistics still require actual first-pair comparability. Repeat statistics use complete paired repeats, record n, and leave standard deviation empty at n=1. Repeated deterministic runs do not sample workload diversity or software/hardware configuration uncertainty.

Checker acceptance tail is max(0, last accepted-result BOOM CSR cycle minus ROI-end CSR cycle). It is reported separately from ROI cycles, explicitly as `checker_acceptance_tail_boom_cycles`; the legacy `drain_cycles` column carries the same observed package acceptance tail and does not claim complete architectural drain. Strict checker detection needs same-package actual execution-done and checker-done endpoints; full rollback needs actual rollback begin/end events. These have not been captured, so those latency fields are null. No fault injection means this campaign cannot establish detection or recovery time. Where available, SVB capture/promotion/C-first/C-last/matching-ACK events are joined by full entry/line/sequence/generation key using their BOOM CSR timestamps. `svb-lifetimes.csv` marks captures inside ROI. Whole-run and ROI-capture populations are separate; matching-ACK tail describes completed observed ROI keys only. Missing/coalesced entries and absent payload validation prevent calling this architectural or complete SVB drain. Accepted package counts are not SVB lifetimes. `checker-local-metrics-repeats.csv` and `svb-metrics-repeats.csv` retain the same event metrics for every accepted EC repeat.

Historical Linux Native FPGA simmedium, bare-metal Canneal project400, old project64 runs and new short profiles are never paired across contracts. `diagnostic-pairs-excluded.csv` preserves old output-valid Blackscholes/Swaptions ratios with mismatched timer policies and instruction counts; none enters this plot or a Geomean. Canneal is workflow validation only. The independent historical audit is `audit/existing-data-audit.json`, including the existing Native FPGA repeats, CPU metasim and RTL evidence.

The supplemental `audit/historical-native-fpga-audit.json` rechecks all 24 archived Native FPGA simmedium result hashes, cycles and saved validity/exit evidence for the requested eight. `historical-native-fpga-excluded.csv` records their statistics independently. This read-only audit does not operate hardware or produce a cross-platform performance pair.

`checker-local-metrics.csv` reports real same-package new_package to package_result_queue.io.enq.fire intervals from the synthesized checker print bridge. PASS/full_compare/cancellation flags and package ownership are checked. Intervals use the 100 MHz checker domain; two BOOM-equivalent duration cycles correspond to one checker cycle. Absolute epochs are not aligned from this frequency ratio. These overlapping local intervals include service/stalls and result enqueue waiting. Summing them across four parallel checkers does not yield application overhead, strict detection latency or result transport delay.

Each result points to its original run directory: `binding.json` contains the exact command and binary/ELF/manifest hashes; `host-complete.log.gz` is complete stdout/stderr; `stdout-integrity.json` records raw and compressed stream SHA-256; EC `external-events.jsonl` and `strict-acceptance.json` contain event and package evidence. Independent raw auditing decompresses the full stream and re-parses ROI CSR boundaries, cycle/instruction counts, timer policy, output and end markers against the result. `host-summary.log` is a filtered convenience log, not the complete source. A failed run retains its evidence and cannot yield a ratio. Rebuilds use new profile/directory bindings if an earlier target run exists. Run `python3 scripts/export.py` to refresh all audits and paper exports. First-eight and completed-three-repeat releases are automatically retained under `batches/` with file hashes and original raw-log references.
