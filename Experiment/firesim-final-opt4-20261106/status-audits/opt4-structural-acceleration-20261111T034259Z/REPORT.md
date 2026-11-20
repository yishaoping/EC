# Opt4 area acceleration: actual execution

Functional/cycle baseline8491167d only. Existing9ae9a7fc whole CAD and its input hashes preserved. Native stays paused; no FPGA operation this turn.

## Actual results and queued continuation

- Latest completed whole8da24a26 postopt3215683 LUT /92789CARRY8 /195DSP. U2801303680 LUT; excess1912003. Current9ae remains in DUT synth and has new DSP/RAM mapping phase messages; no9ae area report or bitstream yet.
- Broken compositionedd3d921 was missing requiredAddressBucketUpdate.scala and its controller doubledchipyard/ paths. Failed submissions/logs retained. New exact compositione0c3737f includes both00847dc2 files and bothf2d2ca3e SVB files. Combined typecheck, source binding, actual re-emitted address/SVB RTL equality to verified component RTL PASSED. Scope is compositional delta proof/regression; not full-DUT formal.
- e0c3737f full GoldenGate and exact frozen-parameter/class-origin checks COMPLETED. All7 generated driver ABI/target files byte-equal.13 ordinary exact paired software profiles prepared, not FPGA validated. Driver reuse records no recompilation and no FPGA admission.
- e0c3737f whole CAD request isDEFERRED_EXISTING_WHOLE_CAD, not running. Only after9ae naturally exits with real postoptNOTFIT will the capsule select using that report, then DUT synthesis/top link/postopt capacity/place/route/timing/DRC/bitstream. On current9aeFIT its implementation/runtime has priority. A newer proven, materially better candidate may supersede the queued one before launch.
- Source-bound runtime prepare/start requests are installed for e0c3737f, strictly21-only. Start remainsWAITING_CERTIFIABLE_BITSTREAM. No certification/deployment/sample is claimed.

## Structural optimization and exclusions

00847dc2 complete address OOC872880 LUT /30842CARRY8 /0DSP vs same-parent990905 LUT:118025 LUT saving. SVB identical-harness complete module135987->130912 LUT:5075 saving. The two gains are not an integrated full-DUT measurement.

Read-only attribution shows hugeMSHR0/prober LUT name groups containDCache metadata arrays andbarrier buckets from other source cones. Avoid double-counting or attributing those to theMSHR FSM. Physical predecessor addressStats1265491 LUT; BOOM core244938; MSHRFile222552(includes cross-boundary relocated logic); DCache total2124812 is inclusive. Detailed structural inventory:build-logs/Opt4-fit-structural-roots-r1-20261111/result.json.

Independent candidate1a571775 changes only indexed retirement clears into constant-slot decoded clears, with identical reads, update/reset ordering, invalid payload semantics and64-bit state. Original full65536-bit payload SAT exceeded180sec; evidence retained, never marked PASS. Recovery proves exact256x4bit mux/clear template and source-bound lifting independently to all64 bits, then complete frozen6144-cycle/52-output comparison and full actual module map. StateOpt4-fit-address-static-retire-r2-state.json. No area saving claimed before map and no production selection.

Two quick screens were completed and excluded: DSP low47 arithmetic9LUT/cell; packed four-granule reduction156LUT/bucket (isolated256-bucket screen estimate39936 LUT, with CARRY growth). Neither enters costly full-module/whole CAD. An oldaeabe5ab complete-module all-zero area receipt is excluded as invalid area evidence; original proof/log preserved.

## Failure recovery actually performed

Root-created candidate runtime templates blocked user-mode software preparation. The failed job had exited; no candidateCAD or runtime had started. Copied6 unchanged files to a user-owned peer directory and atomically exchanged names withrenameat2. Original root-owned directory retained asruntime/Opt4-fit-e0c3737f-root-template-before-r4; byte hashes unchanged. Recoveryr4 then completed all13 software bindings. Detailed evidencebuild-logs/Opt4-fit-update-share-svb-software-permission-repair-r4-20261111/repair.json.

## Reconnect and next action

Adoptlive PID/start_ticks/boot_id; never restart or modify live inputs. Existingec-opt4-unattended.service round20 continues independent source analysis and read/equivalence/map candidates. CPU jobs are independently enabledsystemd services with locks, durable logs and atomic state. Requests, receipts and input hashes are underunattended-opt4/. One whole synthesis at a time. All successful receipts/checkpoints remain reusable. For future runtime candidates precreate runtime/scripts directories asguozh before root prepare_runtime to avoid repeating the ownership fault.

Primary next actions: current9ae real resource report; completed structural candidates/maps selection; static-retirement candidate proof/map; automatically admit the largest validated next candidate only after safeCAD boundary. FIT directly enters implementation and certified21-only experiments.
