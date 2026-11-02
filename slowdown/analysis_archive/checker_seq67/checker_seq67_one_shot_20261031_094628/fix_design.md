# Fix design

FIX_READY = YES means source/type/offline validated and command-ready, not dynamically proven.

Two functional changes, one combined hardware version:

1. RocketCore treats privileged CPS as a held request (`priv_status`, reset to0).
   Dispatch only with `!excpt_mode && !csr.trace.exception && !csr.eret`.
   The pending bit is consumed by the actual synthetic dispatch, not a guessed return
   pulse. CPS during a real trap waits for real architectural depth to unwind. The
   common trap-free delayed-CPS edge is unchanged. ECALL, EBREAK, inner xRET and a
   current real trap cannot authorize or share a synthetic redirect.
2. R_ICSL captures a real trap coincident with the registered privileged entry pulse
   in nonchecking: set local depth1, resume_state=checking_priv, enter self_xcpt_priv.
   The real handler executes outside checker mode; its matching xRET resumes the
   package. This closes the remaining one-cycle gap after a trap-free dispatch.

This fixes the upstream loss; simply forcing CANCEL handoff would leave the benchmark
with a rejected cancelled result. Cleanup/result ready-valid, CANCEL return logic,
AsyncQueue/GHM release, compare authorization, architectural trap accounting, and
ownership watchdog bounds remain unchanged. No artificial trap clear or result PASS
is introduced. All 17 previous seal hardware inputs remain byte-identical; two formerly
unmodified Rocket sources are added. No L1 geometry beyond existing B512sets/2way,
MSHR6, SVB16, scheduler/replay/promotion/L2 policy changes.

Static dependency audit: csr.trace.exception at slot0 depends on CSR's decoded
system instruction and wb_xcpt, not io.retire (retire>=0 is unconditional).
csr.eret depends on the registered WB CSR command, not check_exception-gated wb_valid.
The new priority excludes a direct combinational feedback through wb_valid. It does
not replace downstream FIRRTL/CheckCombLoops validation, which the user's build must do.

Risks: pending CSR context must remain owned while the real handler unwinds; this was
already the purpose of priv_status and admission gates. A can be timing-affected by
safe deferrals even without a CANCEL, so old A timing reuse is not assumed. Exact
privileged trap/vector route and later benchmark correctness remain for the single B.
