Round154: complete AddressStats bank integration implemented and validation started

The new private complete-module candidate retains256target slots as16identical
BucketBank instances with16parallel lanes each. Its exact bank class body is
copied from the foreground r4 input, with only a package rename. Parent bucket
register declarations become combinational views of those bank registers;
bank-local histogram, exact65bit arithmetic, carry, allocation, retirement and
stats reset replace the corresponding parent expressions and writes. All
queue/table processing, source qualification, sequence membership checks,
global error logic and online/global metrics remain in the complete module.
The12recorded source edits reverse byte-for-byte to the immutable reference.
The public IO source declaration is identical. Bucket geometry is still5120
64bitcounter words plus256valid/sequence slots; no target pipeline is added.
These are source checks, not a completed runtime/equivalence claim.

Actual new service:ec-opt4-address-banked-complete-module-r1-20261112.service,
CPUs226/227,64GiB hard cap. Admission recorded362.4GiB available memory,
194.8GiB free disk,load13.46,no pinnedCPU overlap and five projectVivados.
It compiles/elaborates the complete reference and banked module, checks the
52output public ABI, and runs the existing immutable6144cycle full-module
stimulus/monitor with only candidate register paths rebound into the16banks.
The5684observations cover52public outputs,5120bucket words,256valids and256
sequences, before and after target edges. Equal arbitrary invalid payload,
ordinary reset without stats reset, and an actual candidate bank15/lane15
register-bit mutation remain in the test. Completion is reported only by the
stage receipts. This service submits no CAD and performs no board operation.

Completed integration evidence at14:50UTC: both proof/module Scala compiles
passed, and complete reference/banked proof RTL elaborations passed. The
emitted RTL hierarchy has exactly16bank instances and the same327680counter
bits,8192sequence bits and256valid bits as the reference. Full-module finite
parity has not completed. The r4 PLAIN2bank and threaded2bank tests each passed
48target tokens/1504complete1314bit observations with digest4904395e436accb4;
the deliberate negative tests passed their expected mismatch gates. These are
two-bank screen results, not full256slot bank/complete-module/EC equivalence.

At the final14:55UTC observation, both complete production-module RTL outputs
also elaborated successfully and the52output public ABI check passed exactly,
with proof-only ports absent. The6144cycle parity executable was compiling;
positive/negative runtime parity had not completed. R4's4bank smoke passed
48tokens/3008complete observations with digest7adf818470ca4433 and its negative
test passed. R4 then began Plain16GoldenGate generation; no full16bank token
or paired-area result existed. Packed/DSP Candidate and histogram Plain256
maps remained live, with all immutable input pins verified. No saving is booked.

Foreground storage-compose r2 stopped naturally at14:49UTC after its generated
2534signal/71589bit cycle pair preparation, before cycle parity or area. The
controller required its auto-generated clear-inputs.h to equal the selected
corrected driver header. Its PID is absent and exact systemd cgroup is gone.
The generated header transforms byte-for-byte to the selected corrected one
by Verilator doubleunderscore identifier spelling and explicit32bitword loops.
Both original headers remain unchanged. The immutable failure handoff records
their hashes and a versioned foreground recovery that can reuse r2 generated
RTL/pair, without duplicate elaboration/map. No competing recovery was launched.

Foreground r4 on218/219, storage-compose r2 on216/217, packed r1 on214/215,
DSP r1 on220/221 and original histogram r6 on222/223 are adopted. No duplicate
of their target/parity/map jobs was launched, no live input was edited and no
healthy process was signaled. Original8d50489aDUTCAD and the certificate/runtime
handoff remain untouched. Separate CPU and successfulSVB work receive no new
monitoring or optimization effort in this round. Exact observed owner states,
PID/start_ticks/boot/cgroup identities, pinned-input verification and immutable
completed stage receipts are in round154-structural-progress.json and its
per-owner referenced receipts.

Scope remains explicit: complete target-source finite parity does not prove
whole formal equivalence, FAME5 channel/token correctness, host area saving,
or completeEC equivalence. The complete-module host must still validate the
same-target-cycle carry->processCommit and state->safeError feedback. Installed
FAMETransform derives output firing rules from combinational input dependencies;
that source fact alone cannot establish freedom from a bank scheduling deadlock.
Actual useful r4 fullsize paired area is required before a new area admission.
Then complete-module GoldenGate/ABI/tokens and a real same-harness generated-host
pair are required; accepted complete-source composition still needs a fresh
complete-host postopt result. No one-bank multiplication or module-only number
is subtracted from the completeEC baseline.

Completed negative barrier evidence stays rejected:83888->158516hostLUT,
+74628LUT/+86620FF, despite finite target parity. No same256readport retry or
integration is admitted. Packed/DSP/histogram/r4 live jobs do not establish an
unmeasured paired saving. The owner-memory reduction is already included in
the authoritative2420482LUT complete generated host, shell excluded, with
1116802LUT remaining gap to1303680capacity. Actual fullshell2789012LUT/gap1485332
is a distinct receipt. Even ideal zero address+barriers leaves47519LUT excess
before shell. No validatedFIT route can currently meet theNovember18deadline;
structural replacement, full physical certification and all eight actual FPGA
workloads remain necessary. No EC FMR/MHz/cycles/slowdown is inferred from16banks.
