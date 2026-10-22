# Stage3 单入口与 provenance 管理 — 2026-10-18

STAGE3_STATUS=READY_FOR_BUILD_AND_DIRECTED_VALIDATION；STAGE3_CLOSURE=NO。
本轮只修改 runner、状态/provenance 管理与交接文档，未改 preservation protocol、
Scala fixture 或 C++ directed driver。未执行 build、elaboration、RTL generation、
Verilator、simulation、regression 或 runner 单元测试。

唯一公开入口：`AI/Debug/scripts/stage3/stage3_run.sh`。不接受参数，不要求
STAGE3_ROOT；遗留的 STAGE3_ROOT 不选目录，也不参与 cache identity。
`stage3_validation.py` 是内部状态机，旧 `stage3_build_and_run.sh` 已删除，
旧 build/directed/system/all CLI 分支已移除。脚本运行时不修改/删除自身。

## 生命周期与 immutable evidence

每次调用新建 `AI/TMP/stage3_runs/run_*`，立即打印 STAGE3_ROOT。全局非阻塞
flock 防止两个 Stage3 runner 同时使用共享构建环境；冲突也输出失败 summary。
每阶段新执行时写 plan.json/started.json，成功后写 result.json/seal.json；
文件使用 exclusive create。失败与中断保留原目录，不覆盖或补写旧阶段。
复用只写新 run 下的 reference.json、review 日志和 reuse.audit.jsonl，
原阶段目录保持只读；不复制或硬链接巨大模型。没有清理命令或自动重试循环。

cache discovery 仅考虑新 schema 的 run_*/phase/result.json。旧人工分阶段 run
不自动导入。每个候选必须同时满足：

1. 阶段、schema、exit0/PASS、输入清单哈希与 phase seal 一致。
2. HEAD、逐文件 source identity、工具/环境和该阶段实际依赖的脚本/fixture 一致。
3. 当前 phase contract 与原 plan 一致；完整上游 token/seal 一致。
4. 实际 generated model、binary、来源清单和结果 artifact 全部重新计算哈希。
5. BUILD 使用既有 Stage1 provenance 工具重新校验整机 source/generated/binary，
   只向本轮 review 目录写日志。
6. DIRECTED/SYSTEM 使用当前 checker 重新解析原 trace，核对原 JSON 结果。
   同时核对 simulator 命令、exit code、workload、copied checker 与模型 provenance。

PASS 文件、目录名排序、时间戳均不构成复用依据。损坏/缺失候选记录 INVALID，
然后尝试其他完全匹配候选；没有可用候选就在新目录执行该阶段。旧文件不改。
本轮执行前后反复校验 inputs，source/script/tool/environment 中途改变则失败；
simulator 结束后还检查上游模型与 directed 证据未被修改。

## Invalidation / resume

| 变化或先前结果 | 自动动作 |
|---|---|
| fresh source、HEAD/source/Scala/C++ fixture 改变 | BUILD、DIRECTED、SYSTEM 新执行 |
| 工具/环境、共享运行器/构建依赖改变 | 保守失效 BUILD 与全部下游 |
| 仅 directed checker/CASE 判据函数改变 | 可复用 BUILD；DIRECTED、SYSTEM 重跑 |
| 仅 system checker/progress 函数或其脚本改变 | 可复用 BUILD/DIRECTED；SYSTEM 重跑 |
| BUILD PASS，DIRECTED FAIL/中断 | 核验并复用 BUILD，重新 DIRECTED；通过才 SYSTEM |
| DIRECTED PASS，SYSTEM FAIL/中断 | 核验并复用 BUILD/DIRECTED，重新 SYSTEM |
| 全部已通过、身份及证据全部一致 | 三阶段 REUSED |
| 模型损坏 | BUILD 重跑；模型 token 改变则全部下游失效 |
| trace/结果/依赖损坏或缺失 | 相应阶段重跑；新证据 token 使下游失效 |
| 进程在 seal 写完前中断 | 不可复用；新调用自动恢复到最早缺失阶段 |

阶段 key 分离 checker 函数的 AST identity；未分类代码变化一律保守失效 BUILD。
source、工具与环境使用实际哈希；上游 token 同时包含阶段 key 和 artifact manifest。
非功能注释变化不改变函数 AST，文件的完整 hash 仍记录在每次 inputs 中。

## 通过条件与 fail-fast

BUILD 保留现有两个 target 的一次构建模式：Stage3Harness + fresh v1Config；
没有 simulator 调用。保持生成完成标记、lint 的 UNOPTFLAT/PINMISSING、模型来源门禁。

DIRECTED 必须严格 18/18、每个 CASE 恰好一次、无 CASE FAIL、唯一
STAGE3_DIRECTED=PASS 和 `[END] status=PASS`、simulator exit0、assertions/errors=0、
完整 transaction provenance 平衡、request/ACK counter 一致、两个精确 race 被观察。
Speculative outer write、duplicate preserve、premature overwrite 任一诊断即失败。
Stale ACK 只允许 directed 故意注入且明确 ignored=1 的事件；host 仍必须检查它未
解除 barrier。raw stale/duplicate 观测数允许非零，correctness error 必须为零。
未分类或产生状态效果的 stale ACK、重复/不匹配完成、缺 provenance 都失败。
SYSTEM 不豁免 stale ACK 诊断。

SYSTEM 只在当前有效 DIRECTED PASS 后执行。检查 Stage1 原有所有 gates（含 AMO、
main/checker、clear、duplicate/lost effect 与真实 exit drain）、Stage2 regression、
Stage3 事务闭合和非空覆盖。重新流式计算 Stage1 checker，与 launcher JSON 对照。
progress.json 要求 verified=1、软件 END PASS、serial_success、正周期且小于既有
500000000-cycle 上限、DCACHE/LSU live exit drain 齐全且无 blocker；deadlock/
watchdog timeout 诊断失败。外部命令还受 wall timeout 限制（build 每命令12h、
directed15min、system24h）；超时/中断终止进程组，不标 PASS，不执行后续阶段。

每次正常结束、失败、SIGINT/SIGTERM 都生成固定 summary.out/json，包括：
STAGE3_ROOT、SOURCE_PROVENANCE、BUILD、DIRECTED、SYSTEM、STAGE3_STATUS、
STAGE3_CLOSURE、NEXT_ACTION、FAILURE_LOG/REASON 与五个自动化目标字段。
硬退出/SIGKILL 无法保证 finally 输出，残留 started 且无 seal 的阶段仍不可复用。
VALIDATION_PASS 只表示本次既定验证门禁通过；STAGE3_CLOSURE 保持 NO，待证据审计。
本轮未执行，不能宣称动态 closure。

## 本轮静态检查与文件

STATIC_REVIEW=PASS。仅执行 Python AST syntax、bash -n、git diff --check
和静态控制流/依赖审查。
没有导入/运行 Stage3 runner，没有跑 offline tests 或任何硬件工具。
静态 review 不证明新 resume 分支或实际 build/simulation 已通过。

修改：stage3_validation.py、scripts/README.md、state/current_debug_state.md、
history/timeline.md、history/reports/stage3_static_20261018.md、
Design/stage3_l2_preservation_20261018.md。
新增：stage3/stage3_run.sh、本报告。
删除：stage3_build_and_run.sh。

```ini
ONE_USER_COMMAND=YES
FAIL_FAST=YES
SAFE_RESUME=YES
STALE_RESULT_REUSE=NO
MANUAL_STAGE_SELECTION=NO
```
