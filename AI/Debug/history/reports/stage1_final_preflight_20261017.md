# Stage 1 最终仿真前 preflight（2026-10-17）

本轮只检查已打补丁的 accounting、exit/drain 及最终一次运行的覆盖链。没有重新展开全局 debug，没有修改功能源码、analyzer、workload 或运行脚本，没有执行硬件/Scala 编译、elaboration、FIRRTL、Verilator 或仿真。结论是运行准入，补丁动态验证仍 pending。

```ini
PRE_FLIGHT=PASS
ACCOUNTING_PATCH_STATIC_READY=YES
POST_SUCCESS_NEW_REQUESTS_POSSIBLE=NO
DRAIN_PREDICATE_CAN_REACH_ZERO=YES
EXIT_DRAIN_DEADLOCK_PATH_FOUND=NO
EXIT_PREDICATE_AND_ANALYZER_ALIGNED=YES
STAGE1_STATUS=PATCHED_PENDING_FINAL_VALIDATION
NEXT_SIM_REQUIRED=YES
NEXT_ACTION=RUN_STAGE1_BUILD_AND_RUN
EXPECTED_SIM_COUNT=1
```

## Accounting

R_IC 的 `traffic_package_open = producer_open && if_correct_process` 同时供 `count_owned` 及 Core → Tile → LSU 统计资格使用，覆盖 cooling/snapshot/postcheck 的旧包 drain；非零残留 seq 本身不能授权计数。LSQ 在首次有效翻译时捕获 scope/check/seq，retry 保留这些身份；普通 M_XRD/M_XWR 仅在 `arch_valids` 退休时计数，kill/回收清除身份，refill/replay 不新建退休事件。Checker 的事件输出与实际计数 enable 相同，使用 checker-owned package seq 和 hart/ordinal，analyzer 按 occurrence 对齐并检查重复及 counter/event 一致性。

复用上一轮已完成的旧 trace 反事实证据：87 store + 242 load 恰好补回 329，extra=0、missing=0；这不是本轮新 RTL 动态验证。完整来源在 [closure 报告](stage1_closure_20261017.md) 与 `AI/TMP/stage1_audit_20261017_atpbr625/validation.json`。

## Exit/drain

已验证默认 manifest 对应的 ELF：`_exit=[0x800007b0,0x800007d8)`，关闭中断后仅两条 `sd`（fromhost/tohost），然后 fence、自跳；没有 attempt 计数或后续软件访存循环。LSU 未接受时保留同一功能 token/有效 STQ，只有 `dmem_req_fire` 推进 execute head 并标 inflight；terminal completion 后才能 release。有限的是架构 store 数量，不会把未握手 attempt 当成成功。host success 后仅继续服务已有请求及其重试/响应。

emulator 锁存 host success，继续原有 clock/eval 与 TSI tick，TSI host run 返回后继续 yield；drain 没有阻断 response/release。Fence 在 `ordered` 后清除，force_order 随之可回零。park loop 不再产生新的架构数据请求；真实事务、回放、completion、slot reservation、WB/probe、TL A/D/E 及 LSU 队列均可随有限工作完成而消退。停驻的 prefetch owner 与无效 payload ID 不作为活动事务。

`stage1_exit.h` 与 `EXIT_DRAIN` 使用同组连续 probes：cache[1..3,5..23] 必须为零，cache[4] fence_ready 必须为一；LSU[0..8] 全零。Analyzer 检查相同 cache blockers、fence、inflight/done/hella/force_order、pending load/request，并核对逐项 STQ 与 aggregate counts。Simulator 额外强制全部 STQ/LDQ valid 为零，较 analyzer 为旧 trace 保留的精确 committed/unissued `_exit` 分类更严格；本次成功退出不能借该兼容分类留下尾部。对本次有限 workload，正常 simulator exit 必满足 analyzer 的 drain 条件；旧 trace 分类不改变最终运行准入。

未找到退出等待新增的死锁依赖。若不能归零，原 max-cycles 仍生效，正常最终 eval 后无条件输出 DCACHE/LSU `EXIT_DRAIN`、每个 live `EXIT_STQ` 的 token/PC/address/flags 及退出原因；run wrapper 即使 sim 失败也执行 analyzer，保存 blockers、outstanding、日志与默认 FST。

## 一次运行与静态验证

`stage1_build_and_run.sh` 先验证已准备的软件身份，再做一次独立新 build，带 `-DSTAGE1_EXIT_PORTS`，验证 provenance 后仅调用一次 simulator。Analyzer/workload/provenance 均复制到独立 run 目录，自动输出 `scoreboard.out` 和 `scoreboard.json`；返回值同时保留 sim 失败和 closure gate 失败。

同一次运行检查 main/checker diff、真实 exit drain、AMO.W low/high、architectural error/verified、clear/S1/S2/refill 的实际 invariant（mode B）、effect → terminal、terminal → STQ release、duplicate/lost effect，并附 replay/software-report gate。AMO low/high 各 swap/add 位于 checking window 内且无条件执行；缺覆盖/必要证据时 analyzer 输出 UNRESOLVED。未观察到的 clear overlap 仍按实际覆盖记录，不预先声称全部交叉情形必出现。

本轮结果：

- 现有 `test_stage1*.py`：32 tests PASS（包含独立 host C++ helper 单测，无硬件 model）。
- 六个 Stage 1 Python 文件 AST parse：PASS。
- 三个 Stage 1 shell wrapper 与 `Software/Test/compile.sh` 的 `bash -n`：PASS。
- `stage1_workload.py --manifest AI/TMP/stage1_workload.json`：WORKLOAD_IDENTITY=PASS。
- `git diff --check`：PASS。

默认 ELF 为 `AI/TMP/stage1_workload_M1vSNwQC/test.riscv`，SHA256 `64d450b7288198d7ba0b317221914ffe7930d9223ef4868e66bda691386a3ce3`。AMO 地址 `0x80007e00/0x80007e04`。本轮准入后冻结代码，用户执行：

```bash
cd /data1/gzh/EC
/data1/gzh/EC/AI/Debug/scripts/stage1_build_and_run.sh
```
