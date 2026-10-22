# Stage 3 source implementation / static handoff — 2026-10-18

后续入口更新：原人工分阶段 wrapper 已删除，由
`AI/Debug/scripts/stage3/stage3_run.sh` 自动执行和安全续跑。
以下文件清单记录协议实现时的历史改动；当前入口及状态见
[单入口交接](stage3_runner_20261018.md)。此更新没有修改 preservation protocol。

`STAGE3_STATUS=PATCHED_PENDING_USER_BUILD`. No compilation, generation,
elaboration, simulation or regression was run. HEAD at inspection:
`1ed07c28067fad6d8aed697323b465b925895914`; existing dirty Stage1/Stage2 work retained.

Complete pre-patch dependency graph, root causes, protocol, ten invariant
answers, 18 directed cases and exact commands:
[Stage3 design](../../../Design/stage3_l2_preservation_20261018.md).

Production changes:

* CacheImage.scala: Stage2 safety semantics + 64-bit completion echo.
* CacheCork.scala: echo on local Grant, ReleaseData-to-Put and ReleaseAck.
* PhysicalFilter.scala: echo on a synthesized denial response.
* L2Preservation.scala: same-line snapshot/drain/Put/completion FSM.
* Directory.scala: exact-image receipt.
* MSHR.scala: victim snapshot/generation/sent/ACK checks, receipt lifecycle,
  no premature tag invalidation/acquire, complete probe metadata and matching
  completion-bit conditions. Every trusted write schedules a directory write,
  including already-dirty hits, to revoke obsolete exact-image receipts.
* Scheduler.scala: SourceD/probe admission, arbitration, drain/reservation,
  outer A arbitration/D demux, safety assertions and bank provenance.
* InclusiveCache.scala: source/echo negotiation, watermark/pressure-close wiring.
* Parameters.scala: DCache attribution tolerates coherent fixture clients with
  an empty nodePath, without changing the attribution of negotiated real clients.
* SourceC.scala: queued image/echo/last and safe output checks.
* SinkC.scala: first ProbeAckData gate before metadata/bank queue.
* SinkD.scala: completion echo; SourceA.scala: initialize optional fields.
* SourceD.scala: expose drain; existing Stage2 write/receipt logic retained.

New verification: stage3/{Stage3Generate.scala,stage3_test.cpp},
stage3_validation.py, stage3_build_and_run.sh. Stage2Generate.scala only ties
off added inputs. README/current state/timeline updated without relabeling
old Stage2 PASS as verification of the modified hardware.

Static diff/check, AST, shell syntax, lexical delimiter and 18-case source
inventory checks passed. All outer writes, ACK consumers, install/allocation
and validation paths reviewed. These are not type/elaboration/runtime checks.
The directed driver checks actual bank effects/ReleaseAck rather than SinkC
input occupancy, and adds a trusted dirty-hit -> BASE -> speculative Q chain
within case 2. The current v1Config outer domain contains no built-in error/zero
or backing SRAM manager; unrelated manager implementations were not broadened.

```
STATIC_REVIEW=PASS
OUTER_WRITE_PATHS_AUDITED=YES
ACK_PROVENANCE_AUDITED=YES
VALIDATION_RACES_AUDITED=YES
STAGE1_STAGE2_REGRESSION_RISK=L1 identity/effect logic retained; L2 serialization/echo requires fresh system closure
```

Current-turn changed/new file manifest (paths relative to repository):

```text
chipyard/generators/rocket-chip/src/main/scala/tilelink/CacheImage.scala
chipyard/generators/rocket-chip/src/main/scala/tilelink/CacheCork.scala
chipyard/generators/rocket-chip/src/main/scala/devices/tilelink/PhysicalFilter.scala
chipyard/generators/sifive-cache/design/craft/inclusivecache/src/L2Preservation.scala
chipyard/generators/sifive-cache/design/craft/inclusivecache/src/Directory.scala
chipyard/generators/sifive-cache/design/craft/inclusivecache/src/MSHR.scala
chipyard/generators/sifive-cache/design/craft/inclusivecache/src/Scheduler.scala
chipyard/generators/sifive-cache/design/craft/inclusivecache/src/InclusiveCache.scala
chipyard/generators/sifive-cache/design/craft/inclusivecache/src/Parameters.scala
chipyard/generators/sifive-cache/design/craft/inclusivecache/src/SinkC.scala
chipyard/generators/sifive-cache/design/craft/inclusivecache/src/SourceC.scala
chipyard/generators/sifive-cache/design/craft/inclusivecache/src/SinkD.scala
chipyard/generators/sifive-cache/design/craft/inclusivecache/src/SourceA.scala
chipyard/generators/sifive-cache/design/craft/inclusivecache/src/SourceD.scala
AI/Debug/scripts/stage2/Stage2Generate.scala
AI/Debug/scripts/stage3/Stage3Generate.scala
AI/Debug/scripts/stage3/stage3_test.cpp
AI/Debug/scripts/stage3_validation.py
AI/Debug/scripts/stage3_build_and_run.sh
AI/Design/stage3_l2_preservation_20261018.md
AI/Debug/history/reports/stage3_static_20261018.md
AI/Debug/state/current_debug_state.md
AI/Debug/scripts/README.md
AI/Debug/history/timeline.md
```

Existing BOOM changes, stage1_build_and_run.sh, QueuedRequest.scala, SinkA.scala,
SinkX.scala and Stage2 collateral in git status were present before this turn;
they remain intact and are not represented as new Stage3 changes. Shared source
files above also contain pre-existing Stage2 edits; the full git diff is not a
Stage3-only patch.
