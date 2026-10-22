# Stage 3 timer/trap validation cycle: concrete witness and control-domain fix

The remaining unsafe-client timer cycle is **reachable with the old software
layout**. It is not excluded by package-close or by freeing L2 MSHRs. In the
saved execution the responsible checker has already computed PASS, but cannot
publish it until a local timer trap returns. Its handler accesses another word
of the BOOM package's unsafe cacheline. The minimal fix isolates the per-hart
timer counters into distinct coherence blocks. No hardware functionality,
Rocket provenance, CacheImage format, validation handoff or Stage2 semantics
is changed in this task.

Evidence/preimages/static outputs: `AI/TMP/stage3_timer_wait_ecs_zsrg/`.
Pointer: `AI/TMP/stage3_timer_wait.latest`. HEAD is
`1ed07c28067fad6d8aed697323b465b925895914`; prior uncommitted work is retained.
All 1463 Scala source hashes match this task's implementation preimages.

## Evidence boundary

The FST and generated RTL are from
`AI/TMP/stage3_runs/run_zr8umvan/`, before the new lineage-unaware gate. They
prove the handler, address, image, package ownership and blocked result handoff
coexist. They do **not** show a dynamically observed new-gate stall. Applying
the current gate to that concrete protocol state yields the static reachable
cycle; the old model instead grants the unsafe data and later stalls on its
BASE ProbeAckData. The new control-domain layout has not been built or run.

The exact old workload is `AI/TMP/stage1_workload_M1vSNwQC/`, as authenticated
by the saved run's `system/system.run/workload.json`:

- ELF SHA256 `64d450b7288198d7ba0b317221914ffe7930d9223ef4868e66bda691386a3ce3`.
- Dump SHA256 `ab5bd2f9b8cd7a2cf8a62ce028cbe75cc788483065b2460d987b039b0db4abb8`.
- Old interrupt.c/h hashes match the task's saved preimages, not today's padded
  layout. The working `Software/Test/test.dump` is a different artifact and was
  not used to interpret these PCs.
- Actual generated files are under
  `build/system.build/generated-src/chipyard.TestHarness.v1Config/gen-collateral/`.
  `Rocket.sv:1226` implements the same result-handoff predicate as source;
  `R_ICSL.sv:573` excludes a live architectural trap from context_idle.

Times below are FST units. For this run only,
`t_fst = 2 * BOOM csr_cycle + 205`; checker clocks have a different period.
No Rocket performance counter is silently treated as a BOOM cycle.

## Real wait-for graph

| Edge | Concrete evidence |
| --- | --- |
| HANDLER_REQUEST -> UNSAFE_LINE | Hart2 local timer cause `0x8000000000000007`; handler PC `0x800006bc` is `lw a5,-1912(gp)` from `timer_flags[2]=0x80007e48`. At FST1460361 DCache issues AcquireBlock/NtoB, address `0x80007e40`, local source0, valid=ready=1. FST1460365 cached_grant_wait becomes1. L2 remaps this peer to source24. |
| UNSAFE_LINE -> PACKAGE | BOOM store ce81, PC `0x80000564`, csr_cycle `0xb20c2`, writes timer_flags[0] at `0x80007e40`. The image returned by BOOM's probe is writer0/gen`0xb920`/seq2. L2 meta acquires that identity at FST1460547; source24 processes the same hit at FST1460589, watermark=1. |
| PACKAGE -> VALIDATION_DEPENDENCY | Hart2 owns seq2 (`package_seq_reg=2`, `compare_done_seq=2`). At FST1459853 its comparison completes and result enqueues. FST1459857 queue head is `{PASS=0,seq=2}`, valid1/ready0. BOOM's contiguous PASS bitmap cannot advance past1 until that authenticated result crosses GHM. |
| VALIDATION_DEPENDENCY -> CHECKER/TRAP | `RocketCore.scala:1350,1554`: handoff requires checker_local_cleanup_done, including `icsl.context_idle`. FST1459885 takes the timer trap; FST1459889 excpt_mode1, trap_depth1, ICSL=self_xcpt_priv, result handoff0. PASS is retained, not lost. |
| CHECKER/TRAP -> HANDLER | `R_ICSL.scala:271`: self_xcpt_priv resumes only on matching self_ret/xRET. `RocketCore.scala:1171` connects this to CSR eret. Trap restore/mret follows the handler, so the blocked load must finish first. |
| Current gate closes the loop | `MSHR.scala:263` classifies the ordinary peer, unsafe hit and data/ownership exposure. A probe may initially find a BASE directory image but obtain unsafe seq2 from BOOM; this is the late-park case. It never grants the peer that unsafe image. Parking frees cache resources but cannot make this checker's retained PASS eligible for handoff. |

Thus the old-layout cycle is:

`hart2 handler Acquire(timer_flags[2]) waits safe seq2 -> seq2 validation waits
hart2 result CDC -> result handoff waits trap cleanup -> cleanup waits handler
mRET -> handler Acquire waits safe seq2`.

The late source28/hart1 probe mismatch amplifies the old run's failure, but is
not needed to prove this new gate cycle. Hart2 is itself the owner of the
needed result. Raising a timeout, accepting package-close ACK as PASS, early
releasing the checker, or trusting all Rocket requests would not repair it.

Narrow evidence files:
`wait_graph.snapshots.json`, `wait_graph.events.txt`, `hart2.a.events.json`,
`handler.request.txt`, `handler.events.txt`, `old.elf.symbols.txt`, and
`evidence.identity.json`. The saved snapshots include queue valid/ready/head,
package seq, trap cause/depth, context state, resident key and watermark.

## Handler address/domain audit

`Software/Test/core/secondary.c` enables timers on Rocket harts1,2,3; hart4
does not enable one. Hart0/BOOM runs the same handler for its own interrupts.
All hart selection uses physical mhartid, including checker-local traps.
The handler's DCache accesses are its trap/function stack and timer counter;
get_mtime and timer/MSIP programming use CLINT MMIO. There are no library,
allocator, printf, application-data or arbitrary-pointer calls in this handler.
The ecall branch changes CSRs only; software-interrupt branch writes MSIP only.

Old workload symbols: __stack_start=`0x80080000`, shift15, size`0x8000`.
`crt0.S` sets SP to `base+(hart+1)*0x8000` and allocates a 256-byte trap frame.
Hart0 stack is `[0x80080000,0x80088000)`; Rocket stacks occupy successive private
32KiB regions through `0x800a8000`. Observed hart1 frame writes are
`0x8008fec8..0x8008ffb8`; hart2 writes are `0x80097ec8..0x80097fb8`.

This separation is supported by source, not just one observed frame:
`R_RSUSL.scala:152,346` records management ARFs and returns GMode SP/GP on a
local exception; `RocketCore.scala:1678` restores those registers on exception
and the replay SP/GP on xRET. Replayed application memory instructions use LSL
and suppress physical dmem.req in checker modes (`RocketCore.scala:1975`).
The handler is outside checker mode and therefore really uses DCache, with its
management stack. Timer traps during replay do not turn that stack into BOOM's
application stack. Normal well-formed software/stack bounds are assumed.

The old flat timer array is the concrete overlap: offsets0/4/8/12 are all in
the 64-byte coherence block `0x80007e40`. Main's timer store tags the **whole
line**, not just word0. No safe-address allowlist can make peer word2 safe
while transferring that speculative whole-line ownership.

## Minimal control-domain fix

Functional production files: **2 C/header files, 0 hardware files**.

- `Software/Test/hw/interrupt.h`: timer_flag_t occupies/aligned-to64 bytes,
  including explicit tail padding. Compile-time assertions enforce both size
  and alignment. timer_flags[4] therefore reserves256 bytes with no adjacent
  object sharing its first/last block.
- `Software/Test/hw/interrupt.c`: each existing hart branch reads/increments
  only `timer_flags[hart].value`. Count, interrupt limit, timer programming,
  CSR handling and trap behavior are unchanged. No counter is removed.

For linked base T, with `T % 64 == 0`, hart h uses block
`[T+64*h,T+64*(h+1))`. BOOM's runtime writes only slot0; Rocket handlers use
slots1..3. All uses of timer_flags are in interrupt.c, no pointer escapes or
other slot writers exist. Startup global BSS zeroing is before functional
packages: old Stage2 closure trace explicitly reports seq0/check0 for stores
to both `0x80007e40` and `0x80007e48`. Subsequent replay stores do not reach
physical DCache. Rocket runtime writes remain BASE/trusted. Hence its timer
block has no BOOM unsafe lineage to expose, even if it must be fetched again.
This cuts the handler-request -> unsafe-image edge without bypassing any L2
safety check. New absolute addresses require the next software link and are
not invented from the old ELF.

Support/provenance files: **2 Python scripts**.

- `stage1_workload.py`: preparation checks actual ELF timer_flags alignment64
  and symbol size256, recording block/stride/harts/size/base. Verification
  requires that domain evidence plus original source and ELF/dump/loadmem
  hashes. The old16-byte linked layout is rejected. Actual source size/stride
  is enforced by the C type and syntax-checked static assertions.
- `stage3_validation.py`: under the existing invocation lock, changed/missing
  software sources/manifest trigger the existing software preparation script
  **when the user next runs the runner**. It preserves the prior manifest in
  the new run; immutable old workload directories remain intact. Unchanged
  sources with corrupt artifacts fail closed instead of silently rebuilding.
  Input capture and all phase attestation occur after preparation. The same
  public no-argument command handles the software change; the user does not
  need a separate workload/build/stage command.

No software compilation or ELF-to-hex generation was executed in this task.
Default workload manifest and all old sealed run artifacts remain untouched.

## Gate precision and neighboring paths

CURRENT_GATE_TOO_BROAD=NO for the requested unsafe-image boundary. No functional
gate change is needed:

- Unrelated lines and misses: MSHR unsafe exposure requires meta.hit, not just
  an unsafe selected victim. Miss refill's new key is BASE. Existing unsafe
  victim preservation/validation requirements remain independent and intact.
- CLINT MMIO is routed to its own manager, outside this inclusive-cache gate.
  An uncached Get to the *same cacheable unsafe physical line* still consumes
  those bytes and correctly waits; uncached is not an unsafe bypass.
- AcquirePerm carries no data beats but transfers permission to the resident
  image, so must wait just like AcquireBlock. Get and AMO old-value response
  also expose bytes. HintAck and Put AccessAck do not expose the old image.
- Existing destructive-write preservation and cross-package gates still
  apply to Put/AMO updates. Denied completion gets no new unsafe exception.
- Source-specific parking/relookup, no MSHR/set ownership retention, separate
  package-close and unchanged SourceC/probe/ACK progress remain as reviewed in
  the boundary report. No result-before-cleanup shortcut was added: GHM still
  couples validated result delivery to checker release, preserving Stage1.

Historical Stage1 CLOSED baseline
`AI/TMP/stage1_closure_run_g3Y7Oi9x/` accepted the old shared timer C traffic
(28 narrow events, ready1), and Stage2 CLOSED
`AI/TMP/stage2_validation_agciqdp_/` used the same ELF. Those models lack the
new unsafe-client gate; their PASS does not exclude this cycle. No saved
Stage1/2/3 run can contain the new L2_CLIENT_WAIT gate event; the gate was
implemented after those artifacts. Existing event evidence, rather than
absence of an as-yet-unbuilt diagnostic, establishes the concrete chain.

The post-fix exclusion is for this timer/trap **unsafe-image transfer** loop
in current v1Config/Test control software. It is not a proof of arbitrary
applications, malicious pointers, universal replacement fairness or all
possible cache resource schedules. The unrelated victim preservation FSM and
existing global liveness assumptions are unchanged; no newly evidenced
independent cycle was found in this bounded task. Dynamic Stage1/2/3 checking
is still required; static readiness is not Stage3 closure.

## Static checks and status

- RISC-V GCC **-fsyntax-only**, including C size/alignment assertions: PASS;
  no object/assembly/ELF generated. A host-target syntax attempt did not define
  the RISC-V CSR macros; the actual RISC-V syntax parser was used successfully.
- Python AST for the two modified scripts: PASS.
- bash -n for public runner, software-preparation and software-compile scripts:
  PASS; scripts were parsed, not executed.
- Mock-only runner cases: unchanged/no-build, changed source/preparation,
  missing manifest/preparation, corrupt artifacts/fail-without-build: PASS.
  All preparation commands were mocked; zero builds occurred.
- Real manifest verifier with static mock artifacts: correct domain accepted;
  old shared size, unaligned base and shared stride rejected. Source inventory,
  address-interval check and old ELF symbol audit: PASS.
- git diff --check, assignment/use review, unchanged1463 hardware source hashes,
  unchanged directed fixture/CASEs and invariant paths: PASS.

```ini
PRE_FIX_CONDITIONAL_TIMER_TRAP_VALIDATION_CYCLE=REACHABLE
POST_FIX_TIMER_UNSAFE_TRANSFER_CYCLE=IMPOSSIBLE
KNOWN_DEADLOCK_CYCLES=NONE
STATIC_REVIEW=PASS
ROCKET_LINEAGE_AWARE=NO
ROCKET_GENERATION_OWNER=NO
UNSAFE_TO_ROCKET_BLOCKED=YES
STAGE2_INVARIANT_PRESERVED=YES
STAGE3_INVARIANT_PRESERVED=YES
SPECULATIVE_OUTER_BYPASS_ADDED=NO
ASSERTIONS_DISABLED=NO
READY_FOR_DYNAMIC_VALIDATION=YES
STAGE3_STATUS=PATCHED_PENDING_REBUILD
STAGE3_CLOSURE=NO
```

READY means no known blocker remains in this static review; it does not claim
a new BUILD/DIRECTED/SYSTEM PASS. The next user invocation must bind the padded
software's new ELF/dump/loadmem identity and fresh compatible production model.
The agent did not execute the runner, hardware/software build, typecheck,
elaboration, RTL generation, Verilator, directed or system simulation.
