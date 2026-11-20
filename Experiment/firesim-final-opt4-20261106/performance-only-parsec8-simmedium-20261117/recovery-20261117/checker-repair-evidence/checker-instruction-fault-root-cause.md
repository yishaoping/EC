# Performance-Only checker instruction fault, 2026-11-17

The failed blackscholes simmedium sample is invalid (0/8, no Slowdown).
Its evidence was copied before its controller and exact FPGA21 driver were
stopped. No reset, device reprogramming, image modification or hot deployment
was performed. SIGTERM did not terminate the driver within 15 seconds; the
verified owned process required SIGKILL. The card host locks were released.

## Evidence and revision boundary

Suite and evidence root:

`/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/performance-only-parsec8-simmedium-20261117/recovery-20261117`

`failure-evidence/run/` contains complete UART, simulator/host, checker event,
heartbeat and deployment logs. `failure-evidence/suite/` retains the original
runner and state. `artifact-manifest.json` binds copies of bitstream, generated
RTL, firmware ELF, DTB and build receipts. `process-context.json` retains the
nonintrusive host process/maps/fd snapshot. No live guest command was injected.
No register debug bridge or enabled instruction trace was available to recover
the actual last retired PC or the original pre-fault internal CSR state.

Certified original bitstream:

`/data1/gzh/EC/firesim/final-opt4-20261106/runtime/Opt4-performance-only-4915b82-physical-r3/firesim.bit`

SHA256 `1617d53ae39b5c4d700dc24de04a055391d163678d6ac7f989d3ba52b1cd1154`.
This is Performance-Only hardware (semantic 4915b82, emission 80da038), not a
full PALIMPSEST measurement. Physical certification does not establish checker
functional correctness.

Repair A branch `repair/checker-instruction-fault-20261117` starts at
`80da038d800f77baa53dd97ac0436eb352410953` in the independent worktree
`/data1/gzh/EC/firesim/final-opt4-20261106/Opt4-checker-fault-repair-20261117`.
Repair B branch `repair/runner-fatal-checker-trap` is a separate repository
at `recovery-20261117/runner-repair`, repair commit `dc83848`.

## Direct observations

| Field | hart1 | hart3 |
|---|---|---|
| mcause | 1, Instruction Access Fault | 1, Instruction Access Fault |
| mepc | `ffffffff80002e00` | `0000003f9c8aa020` |
| mtval | `ffffffff80002e00` | `0000003f9c8aa020` |
| mstatus printed by OpenSBI | `8000000a0001f800` | `8000000a0001f800` |
| ra | `0000000000010f78` | `00000000800005cc` |
| sp | `000000008001ef00` | `000000008001af00` |
| address mapping | kernel `handle_exception`, first `csrrw tp,sscratch,tp` | checker management `service_va + 0x20`, CPS-ready instruction |

They faulted at different functions/PCs. Both addresses name legitimate code in
their intended virtual address spaces; symbol mapping alone does not prove
the runtime PTE/PMP permissions were correct. `ra=0x10f78` maps into blackscholes
`bs_thread` after the call to `__expf` at 0x10f74. A saved return address is not
the last proven retired PC. hart3 RA is inside the generic firmware trap handler.

Firmware logged all four checker harts installed with actual
`satp=80000000000829f9`; version6, four checkers, service VA `3f9c8aa000`,
`scope=user_no_trap_one_mm`, hardware initialized. This is installation-time
evidence, not a later fault-time satp observation. No complete ROI or successful
checker completion was observed. The generic bound OpenSBI `sbi_trap_error`
ends in noreturn `sbi_hart_hang`; further target cycle growth cannot recover
these checker harts. The test was therefore stopped after evidence collection.

The printed CSR values can select EC shadow CSRs in privileged checker mode.
In particular, printed MPP=3 alone is not proof of the actual pre-trap privilege.

## Proven RTL defect and matching mechanism

1. BOOM `exu/core.scala` connects `rsu_master.io.priv := csr.io.status.prv` and
   connects exception nesting separately to `rsu_master.io.excp_mode`.
2. `r/R_RSU.scala` captures both `crt_priv` and `crt_mode`. Its transmitted
   header uses `Cat(0, crt_mode)`. The frozen netlist does not transport the
   captured real `crt_priv` to the checker.
3. Rocket `RocketCore.scala:1032` names the header `check_priv`, but it is the
   exception-mode bit. Existing CSR comments explicitly document this encoding.
4. `rocket/CSR.scala` synthetic `check_exception && check_priv === 1` entry
   unconditionally sets `new_prv := PRV.M`. An S-mode snapshot PC can therefore
   be fetched in M mode. M mode bypasses Sv39 even with satp.mode=8.
5. The **actual production Golden Gate emitted CSRFile_1 and TLB_2 modules**
   were extracted and simulated, rather than substituting an abstract model.

Frozen RTL reproduction (`bound-probe-run.log`):

```text
FIRMWARE_ENTRY prv=0 satp_mode=8 satp_ppn=000000829f9 real_mtvec=080006ab0
S_CPS_ENTRY prv=3 satp_mode=8 evec=ff80002e00 vm_enabled=0
```

Frozen TLB reproduction (`bound-tlb-run.log`):

```text
BAD_M_FETCH va=ff80002e00 prv=3 vm=0 ae=1 pf=0 pa=780002e00
BAD_M_FETCH va=3f9c8aa020 prv=3 vm=0 ae=1 pf=0 pa=79c8aa020
TRANSLATED_REFILL va=ff80002e00 prv=1 miss=0 ae=0 pf=0 pa=080200e00
TRANSLATED_REFILL va=3f9c8aa020 prv=0 miss=0 ae=0 pf=0 pa=080200020
```

The translated cases use deliberately supplied executable PTEs; they are not
recovered runtime page tables. These tests prove a concrete RTL defect and an
access-fault mechanism at both observed addresses. They do not capture the
original FPGA upstream event sequence or prove this is its only fault.

The forced-M source also exists in frozen history commit `0390a80`; baseline
CSR source SHA256 is
`f92f52d15868605f0fe8bdaf9ea4c84188eb75c339ecb07df4685645f2ca8620`.
The relevant production source matches. This defect predates the recent
BJL/result-CDC mapping optimizations. No evidence justifies blaming DDR,
DCache or SVB from mcause=1 alone. It reproduces in the emitted target module
without host token transformation, so a Golden Gate transformation is not
required to produce this defect.

## Firmware and remaining alternatives

The bound firmware disassembly shows real mtvec installation at 0x80006a32,
pointing to `ec_opt4_trap` 0x80006ab0. `ec_opt4_enter` at 0x80006a6c installs
satp, executes sfence.vma/fence.i, writes mepc, clears MPP/MPIE/MIE/MPRV and
executes mret. Missing firmware initialization is therefore contradicted by
the binary and the four installation receipts.

`CSR.scala` selects shadow mtvec while `checker_priv_mode` is asserted, and
updates shadow mstatus/mepc on machine traps. This explains a possible route
into the generic OpenSBI handler despite the real mtvec installation, but
the original runtime shadow vector and timing of the checker-mode transition
were not recorded. This amplifier remains unproven for the FPGA event.

No runtime page-table dump, fault-time satp, PMP register snapshot, instruction
trace, or pre-fault target/checker comparison is available. Wrong return/jump,
runtime permission changes and other mismatches are not fully excluded.
Binary/build receipts and source bindings provide compatibility evidence;
there is no successful identical C4 PARSEC run to use as a runtime reference.
Synthetic collector fixtures and SVB component replays are not such a reference.

The software's `scope=user_no_trap_one_mm` string is not a hardware-enforced
U-only filter in this build. `guardiancouncil/GHE.scala:238` enables monitoring
on matching satp PPN and `has_monitor_target`; the adjacent `hit_privi` is
excluded. Thus the log string cannot rule out S-mode snapshots in the same
address space. This configuration/reporting mismatch is separate from the
proven forced-M entry defect. The candidate deliberately preserves monitoring
coverage: enabling a U-only filter would evade the problem by reducing checks.

An isolated CSR audit also shows a captured sepc differing from local sepc is
not selected by an explicitly injected sret (`captured-sret-run.log`). This
bypasses the package boundary: BOOM excludes mret/sret/ecall from `ic_incr`,
closes on mode_ret/mode_switch, and projects boundary trap/return state during
comparison. Runtime reachability has not been proved. Consequently no broad
xRET rewrite is included in the minimal candidate.

## Minimal implemented candidate

Only `r/R_RSU.scala` and `rocket/CSR.scala` change production behavior:

- The last privileged CSR beat has 13 CSR words, so its upper 64-bit word was
  padding. Carry captured actual privilege in bits65:64 of that beat.
- Capture those two bits with the CPS tail, then select them at synthetic
  context entry. Keep the exception-mode header semantics unchanged.

Producer and consumer must be rebuilt together. The number and width of beats,
packet ordering, target-cycle timing, valid/destination/busy, snapshot timing,
normal data, and backpressure are unchanged. Software ABI and firmware/image
are unchanged. This requires a new strictly implemented bitstream; it cannot
be repaired by deploying only the runner or by reusing the failed sample.

Validated locally:

- Real Chisel compilation and isolated CSR/RSU elaboration: PASS.
- Paired frozen-reference CSR test: 4,136 normal cycles; S/M/U entry, nested
  actual trap + matching mret, real trap and architectural return priority: PASS.
- Paired frozen-reference RSU test: seven privileged contexts and one normal
  transfer, 313 beats, 471 stalled cycles, forced 17-cycle tail stalls: PASS.
  All output timings/data match except the intended two formerly padded bits.
- Actual Golden Gate RSU-to-CSR atomic-token test: three contexts,120 beats,
  195 stalls,506 harness cycles/567 target cycles including reset: PASS.
- Deliberately corrupting the transported privilege causes the same generated
  host test to fail: PASS negative control (context1 becomes0).

Full C4 elaboration and Golden Gate generation also passed. A recursive graph
audit of 4,891 reachable target modules matches the production graph outside
the intended CSR/RSU boundaries, with identical boundary interfaces, parameters
and the original boot ROM. The generated artifact is bound by SHA256 in
`/var/tmp/guozh-ec-checker-fault-20261117/full-r2/rtl-state.json`.

The actual full-system Golden Gate emitted CSR module was then extracted and
tested at both observed PCs plus an M-mode reference context. It selects S/U/M
as transported, preserving satp and the virtual entry PC. The same testbench
against the frozen production module fails immediately (expected S, actual M).
The test verifies explicit PASS/FATAL content because this installed vvp returns
zero even for `$fatal`; a return code alone is not accepted as test success.

These tests preserve the normal path and exercise the intentional correction.
They are bounded tests, not a proof of whole Linux/multihart execution or a
claim that the original fault is fully fixed. Strict physical implementation
and FPGA21 health checks remain mandatory before resuming PARSEC.

Reproduce from this candidate directory:

```sh
/usr/bin/python3 -I build-probe.py
/usr/bin/python3 -I test-probes.py
EC_PRIVILEGE_HOST_DIR=/var/tmp/guozh-ec-checker-fault-20261117/host-new /usr/bin/python3 -I host.py
/usr/bin/python3 -I test-full-generated.py /var/tmp/guozh-ec-checker-fault-20261117/full-r2
```

## Independent runner repair

Commit `dc83848` recognizes anchored fatal OpenSBI headers/register rows and
hart-qualified hangs. It persists FAILED_CHECKER_TRAP before terminating the
owned child, preserves interleaved register dumps, rejects stale attempt logs,
and stops the suite for repair. The verifier independently invalidates even a
completed measurement if a fatal trap appears. Checker fatal, firmware fatal,
application failure and timeout remain distinct; ROI gates and Slowdown math
are unchanged. Ten historical/synthetic positive and negative tests passed.
No patch was hot-installed into the old attempt.

## Required next validation and acceptance

1. PASS: complete bound full-system generation; prove changes outside the intended
   CSR/RSU cones absent and preserve all BJL/CDC/DTB fixes and constraints.
2. Run necessary integration tests, then strictly rebuild under exclusive CAD
   ownership. Preserve host99.960ns, DDR3.332ns and validated clock groups.
3. Only a legal route with setup/hold, DRC/methodology and clock validation
   passing can be written as a new bitstream and bound into a fresh runner plan.
4. On BDF0000:21:00.0 / serial21770433G02LA exclusively, perform minimal boot,
   four-hart installation and directed U/S context health checks, retaining
   diagnostic records. No unchanged long retry of the old binary is useful.
5. Run blackscholes simmedium once with the repaired runner. Require checker
   health, EC_SAMPLE_START, BENCH_BEGIN, ROI start/end, sample completion and
   original full validity gates. Only then resume the other seven benchmarks.

The exclusive new build has started in
`/var/tmp/guozh-ec-checker-fault-20261117/physical-r1`, using full-r2's bound RTL.
`physical.py` rebuilds the changed DUT and shell post-opt, then runs one fresh
10MHz SSI_SpreadSLLs implementation with the previously successful physical
flow. Original DDR, host and exception gates remain mandatory. It never imports
a failed placed/routed DCP or retries another strategy without new evidence.

`complete.py` provides a single pidfd completion event (no periodic patrol).
After strict admission it independently verifies reports, exception membership,
source/output hashes and exact existing driver ABI, and creates a new physical
certificate. Only then may it use FPGA21. Its health run uses the unchanged
rootfs/firmware's existing smoke app, requires all four harts installed and
actually participating, preserves ordinary sample/checker/drain gates, and
never counts as PARSEC. The independent runner integration branch requires
that health result bound to its new plan/certificate; any invalid blackscholes
attempt blocks the other seven. Ten fatal-detector and five integration tests
passed offline. Neither these gates nor the driver ABI audit establish FPGA
runtime success.

Current root-cause confidence: direct fatal symptom proven; wrong-M entry
mechanism proven; original FPGA trigger strongly consistent but unobserved;
shadow-vector downstream amplification possible and unproven. No successful
checker certification or Slowdown is claimed.
