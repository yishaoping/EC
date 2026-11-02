# L1-Causal-1 64KiB probe：checker3 seq67 ownership timeout

## 2026-11-01 runtime closure — ROOT_CAUSE_CONFIRMED

Corrected B `_103130`, run `optimization_4_svb_20261031_024551_8fbf8937`,
now completes exit0, all320 package PASSes and full ROI1,648,923. Raw SC46 directly
observes seq67 CPS request overlapping machine timer trap at939413; dispatch is
held until exception/depth clear939859, start accepts939861, cleanup/handoff940907,
BOOM PASS940911 and ownership clear940912. Old mismatched context never starts.
The successful path needs no CANCEL. Alternative registered-entry trap handling
has zero runtime exercises; do not claim universal trap/cancellation validation.

Original overall validation FAIL was a separate128-vs133 host identity accounting
limit, losslessly recovered from saved mandatory event/footer/producer counts in a
new derived view; all24 unchanged arm gates PASS. Original files remain untouched.
Reference gain58,940 cycles/3.45% with head wait−85,849 and nack retries−64,386
justifies exactly one user-run A-prime; old A noninterference remains unproved.

[Postanalysis](../../TMP/l1_one_shot_postanalysis_20261101_095815/README.md)
· [Runtime chain](../../TMP/l1_one_shot_postanalysis_20261101_095815/seq67_runtime_confirmation.md)
· [Host accounting recovery](seq67_capture_identity_cap_20261101.md).
No hardware execution by the agent. Older pending/unresolved entries below are historical.

## 2026-10-31 continuation — source fix ready; dynamic validation pending

Report: `AI/TMP/checker_seq67_one_shot_20261031_094628/`. Saved B's complete SC6 prefix
establishes privileged entry while architectural excpt_mode1 and local ICSL depth0;
normal start and running fallback are false. Source/old generated RTL expose an
unguarded synthetic CPS redirect versus current architectural trap/return, including
CSR.eret's ECALL/EBREAK alias. Exact cause/vector is not sampled, so root classification
is MOST_LIKELY_WITH_BOUNDED_RUNTIME_CONFIRMATION. Final cleanup blockage remains proven.

RocketCore now holds CPS until no old/current trap or current return; R_ICSL captures
a coincident real trap on its registered privileged-entry edge. Bounded SC46/47 are
included in this same hardware version, with no cleanup bypass, forced PASS, watchdog
extension or policy change. Scala type check and42 offline CPU tests PASS. Agent did
not elaborate, generate RTL, build Verilator or run a benchmark. One user-run B is ready.

Old A correctness is preserved, but its701 optional SC6 host drops prevent strict
dynamic noninterference proof. Do not schedule A now. If B passes, close correctness
and retain explicit unpaired performance-reference status pending evidence/benefit review.

The following text is the preserved 2026-10-30 failure record.

**状态：运行时失败和直接阻塞链已证明；上游root trigger未闭合。**

本次严格成对试验r2仅改变BOOM L1D sets256→512，SVB16、MSHR6、checker、时钟、
软件和instrumentation保持一致。A完整PASS/ROI1,707,863；B真实仿真exit1，
`BoomCore.sv:6977 assert24`，没有ROI stop或最终性能计数。不能评价capacity收益。

断言映射到`boom/exu/core.scala:2211 little_status3(18)`，阈值262,144 BOOM cycles；
generated WideCounter的`large_3[13]`不是8192cycles。复位条件为checker3 ownership
清零或BOOM收到release clear，不是普通指令commit。因此这是checker3 ownership
watchdog，不是缺少CORE_WATCHDOG_SNAPSHOT就能排除的失败。

保存SC事件使用fields[2]的global BOOM cycle：seq67在939333待启动，939415记录
start accepted且excpt_mode1/context_idle0；1,070,889 no-progress timeout生成并入队
CANCEL67。1,070,897本地result queue valid/outstanding1，context_idle0、return_pending1、
excpt_mode1、R_ICSL trap_depth1，handoff_allowed0；Frontend clear ack已到。
kind13 accepted/handoff累计数在seq67窗口保持14763/14730，没有新的Frontend交付进展。
所录prefix没有seq67的BOOM result release；其它checker1的CANCEL93不能替代它。

已证明的链：seq67缺少所录执行进展→local no-progress cancellation→CANCEL queue
由context cleanup gate保留→ownership不释放→checker3 watchdog。
具体trap/start/return/privileged boundary触发条件及geometry如何使其暴露仍未证明；
不把历史assert24根因直接套用。不以该失败推断L2 observer损坏、缓存数据损坏、
MSHR数量不足、SVB容量不足或promotion优化必要性。

B observed-prefix integrity ledger PASS只覆盖已录149alloc；不是整run认证。
没有最终L2 snapshot/key/S0，因此B observer状态UNVALIDATED；A该验证完整PASS。

下一步为seq67 trap/start/return→context cleanup→CANCEL handoff→BOOM release的
独立correctness审查与最小验证。本轮未更改这些策略、未放宽watchdog，未另跑波形或4way。
**NEXT_OPTIMIZATION=NONE_JUSTIFIED；NOT YET PROVEN。**

证据revision/source fingerprint：
`b6f9a8739a0be1a64cd349625e37dc8b5b8cd246b418041bc3ee68dd1af414b1`。

[主报告](../../TMP/l1_causal_opt5_probe_20261030_200000_4235a1de/README.md) ·
[完整失败分析](../../TMP/l1_causal_opt5_probe_20261030_200000_4235a1de/r2_B_correctness_failure.md) ·
[flags/行号/hash](../../TMP/l1_causal_opt5_probe_20261030_200000_4235a1de/r2_B_failure_evidence.json)。
