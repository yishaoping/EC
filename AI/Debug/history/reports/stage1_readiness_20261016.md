# Stage 1 simulation readiness / closure preflight — 2026-10-16

> 后续用户于 19:22 尝试构建，`AI/TMP/stage1_closure_build_d1DLDfai/build.log` 记录 TestHarness 的三条 Scala 类型错误。根因为先提取 path-dependent tileParams 再 collect；现已直接匹配 `BoomTileAttachParams` 并收集 `Seq[Int]` hart IDs，修复同一根因及其 `Nothing.hartId` 连锁错误。此修复仅做静态检查，未由 agent 重新编译/生成/仿真；下文 preflight PASS 不能视作编译已通过。

```text
PRE_FLIGHT=PASS
NEXT_ACTION=RUN_STAGE1_BUILD_AND_RUN
```

当前 working tree 已具备下一轮一次隔离 hardware build、一次 Stage 1 simulation 的取证路径。此结论是运行准入，**不是修改后的动态 correctness PASS**。本轮没有运行硬件/Scala 编译、Chisel elaboration、FIRRTL、Verilator 或 simulator，也没有修改 generated artifacts。完成了独立软件构建、反汇编、loadmem 转换和 Python 离线测试。

## 1. 实际运行入口与 provenance

完整审计并修正了 `AI/Debug/scripts/stage1_build_and_run.sh`、`stage1_run_trace.sh`、`stage1_provenance.py`：

| 问题 | 当前行为 |
|---|---|
| 当前 working tree？ | YES。硬件输入来自 `/data1/gzh/EC/chipyard` 当前文件，包括 dirty/untracked 源码；构建前后比对 source hash。软件使用当前源码对应、已独立构建并验证 hash 的 workload manifest。 |
| 隔离 build？ | YES。默认新建 `AI/TMP/stage1_closure_build_XXXXXXXX/`；`STAGE1_SIM_ROOT` 指定的目录必须不存在。隔离 generated/model/binary；Scala 编译缓存和工具库仍由 Chipyard 管理，不是独立源码 checkout。 |
| 重新生成 simulator？ | YES。空 build 目录中只调用一次 `make ... CONFIG=v1Config VERILATOR_FST_MODE=1 EXTRA_SIM_CXXFLAGS=-DSTAGE1_EXIT_PORTS debug`。没有 `run-binary`、测试集或 retry 目标。 |
| provenance 自动产生？ | YES。构建前保存 `source.before.json`，构建成功后对 source/generated/binary 生成新的 `provenance.json`；源文件漂移、文件缺失、已有 manifest 均拒绝。运行入口只验证，不能给旧 binary 补写新身份。 |
| 一次 simulation？ | YES。run launcher 只有一次直接 simulator 调用；没有重试、benchmark loop 或第二次运行。软件的一次执行包含 directed AMO 和原 BFS。 |
| 默认 FST？ | YES。`STAGE1_WAVEFORM` 默认 `1`；显式设置 `0` 才关闭运行时 dump。debug binary 始终按 FST 模式构建。 |
| FST 路径？ | `AI/TMP/stage1_closure_run_XXXXXXXX/trace.fst`。 |
| trace/log？ | 同一 run 目录中的 `trace.log`（stdout/stderr）、`simulator.status`、`run.json`、`scoreboard.out`、`scoreboard.json`；build 日志在新 build 目录 `build.log`。 |
| 最新 analyzer？ | YES。启动时复制当前 `stage1_trace_scoreboard.py` 到 run 目录，记录 SHA256，结束后执行该固定副本。失败/不完整运行也分析并保存输出。 |
| stale model/binary？ | 默认入口不能复用旧 build 目录；随后 source/generated/binary hash 必须与新 provenance 全部一致。单独使用 run launcher 也必须提供已有 attestation，不能默默生成。 |
| provenance 边界？ | source inventory 当前为 11,480 个路径，覆盖 generators/tools/project/sims 等源码、资源及构建配置；generated 清单覆盖全部相关 RTL/C++/header/filelist，不只顶层模型。binary 要求 `STAGE1_TX`、`STAGE1_SIM_EXIT`、`EXIT_DRAIN`、`CLEAR_CHECK` marker。`run.json` 保存实际 argv、输入 manifest/analyzer hashes 和相关环境。 |

build wrapper 只接受环境配置，无位置参数。支持 `STAGE1_WORKLOAD`、新的 `STAGE1_SIM_ROOT`、新的 `STAGE1_RUN_ROOT`、`STAGE1_WAVEFORM`；旧 `STAGE1_BUILD_ROOT` 和直接 simulator/generated/provenance override 显式拒绝，避免参数被静默忽略。run launcher 的三个 attested model 参数由 wrapper 自动传入。

## 2. AMO.W 双 lane 的确定性软件覆盖

```text
LOW_LANE_DYNAMIC_COVERAGE=YES
HIGH_LANE_DYNAMIC_COVERAGE=YES
```

原 BFS 编译输入不包含 C++ GAPBS atomic helpers 或已注释的 `bench/work.c`，旧运行的 AMO.W 锁地址也都在 low lane。因此新增最小 `Software/Test/bench/stage1_amo.h`，由 `test.c` 在 checking/measurement START 后、BFS 前无条件调用。四条 volatile asm 均不依赖随机数、BFS 分支或测试结果；返回值合并进入原 `result->verified`。

独立软件构建产物在 `AI/TMP/stage1_workload_aqkkuUF2/`，manifest 为 `AI/TMP/stage1_workload.json`。反汇编直接证明 `0x8000036c` 调用 `stage1_amo_w_test`（`0x80000738`）；四条 AMO 都位于结果判断分支之前：

| 指令 PC | 指令 | 实际地址 | lane |
|---|---|---|---|
| `0x80000760` | `amoswap.w.aqrl` | `stage1_amo_words+0 = 0x80007e00` | low，addr[2]=0 |
| `0x8000076c` | `amoadd.w.aqrl` | `stage1_amo_words+4 = 0x80007e04` | high，addr[2]=1 |
| `0x80000770` | `amoadd.w.aqrl` | `0x80007e00` | low |
| `0x80000774` | `amoswap.w.aqrl` | `0x80007e04` | high |

数组按 64-byte 对齐，两项共享同一 64-bit word，位于普通 cacheable DRAM；普通 RISC-V AMO 经 BOOM LSU/DCache AMO path，无 MMIO 或软件替代路径。初值 low=`0x80000001`、high=`0xfffffffc`，swap=`0x76543210`、add=`7`；检查负/正旧值的 RV64 sign extension、两次操作的返回值和最终两项数据。初始化后有 `fence rw,rw`，四条 AMO 使用 aqrl。

| 产物 | SHA256 |
|---|---|
| `test.riscv` | `bcae2a9f4b67a8ce98c56f31085cc37c0cb67e466c51e61d6db645e1146008be` |
| `test.dump` | `60555e3f507874d17ed42b40871d320d36f2a53e7b17fbd11f61785c97df7ce0` |
| `test.loadmem_hex` | `cd3f7864f6e2eb8eadfadee3db32d3ee0c226b42beeea46917c6d17537e9d413` |

原 `Software/Test/test.riscv` 未覆盖。后续若修改软件，先运行独立的 `stage1_prepare_workload.sh`；build wrapper 会在昂贵构建前拒绝 stale 软件 manifest。上述 YES 表示正常执行必经这四条指令；真实 trace 仍必须证明两 lane EFFECT 和语义都通过。

## 3. 真正的退出 RTL snapshot

```text
EXIT_DRAIN_RTL_PRESENT=YES
EXIT_DRAIN_ANALYZER_SUPPORTED=YES
EXIT_DRAIN_SUFFICIENT_FOR_CLOSURE=YES
```

`lsu.scala`/`dcache.scala` 连续导出只读 BoringUtils probes 到 `TestHarness.scala` 顶层输出；`emulator.cc` 在最后一次正常 `tile->eval()` 之后、销毁模型之前读取这些 live RTL outputs，打印 `snapshot=sim_exit` 的 `EXIT_DRAIN` 和逐项 `EXIT_STQ`。没有额外 clock、假定的 drain delay 或改变 simulator success。wrapper 的 `-DSTAGE1_EXIT_PORTS` 启用此读取路径；v1Config 的一个 BOOM hart 对应 schema=1，非适用配置 schema=0，analyzer 不能给其 PASS。

快照包括：S1/S2 valid mask、活动 cacheable+MMIO MSHR 数、fence-ready、replay valid/busy/result queue、completion queue、S3/store_done、writeback/probe、refill/install、slot reservations、completion responsibility、killed replay、cross-package pending、response 和 TL A/D/E valid。另有 S3/completion/replay request token，以及 STQ valid/committed/inflight/done、LDQ valid/pending、Hella adapter、LSU request/force-order。64 个 STQ probe 槽逐项携带 functional token、PC、地址和 flags；真实配置超过容量会在生成时明确拒绝。

特别区分两个 MSHR 计数：`mshr_outstanding` 统计 `!req_pri_rdy` 的 cacheable MSHR 和 `!req.ready` 的 IOMSHR；`mshr_owners` 是原始 `owner_line_valid` 数。`s_prefetch` 已停驻项仍持有 owner，但 `req_pri_rdy=true`，不能仅凭 owner 非零误报活动事务。该修改只增加 observation port/组合计数，没有改变 FSM。

analyzer 校验 schema、必要字段和 STQ 数量一致性；缺快照/字段为 UNRESOLVED。S1/S2、活动 MSHR、队列、inflight/done、pending、非 fence-ready 等真实未完成状态均 FAIL。LDQ speculative entries、尚未握手的 request.valid 和软件 ROB commit 不直接等价于已接受 L1 transaction；它们原样保留为诊断字段，accepted load 的活动由 pipeline/MSHR/response 状态覆盖。

## 4. `_exit` 的 15 个历史 commits

```text
EXIT_LOOP_CLASSIFICATION_READY=YES
```

不硬编码历史 PC，也不忽略 `_exit`：`stage1_workload.py` 从本次 ELF 符号表提取 `_exit` 函数范围和 `tohost/fromhost` 地址。新 ELF 的范围是 `[0x8000692a,0x8000694c)`，地址是 `0x80007d00/0x80007d08`。下轮提交数量可以变化，不能假定仍为 15。

新增不受 `traffic_check` 统计口径影响的 `ARCH_STORE`，覆盖所有 architectural uses_stq commits（含 AMO/fence）。对每个无 terminal 的普通 store，必须在退出 STQ 中匹配 token、slot、PC、地址。只有 `_exit` 范围内、目标为上述 HTIF 地址、valid+committed+physical address/data ready、且无 L1 grant/inflight 的项，分类为 `committed_unissued` 软件退出尾部。它仍出现在 `EXIT_LOOP_PENDING` 和详细 JSON。

已经被 L1 接受的 `_exit` 请求保持真实 outstanding；owner 消失/身份错配报 `LOST_ARCH_STORE`；快照中已提交却没有 ARCH_STORE 记录的 owner 报 `EXIT_STQ_WITHOUT_ARCH`。任何 PC 都不能豁免 EFFECT 缺 TERMINAL、TERMINAL 缺 STORE_DONE/RELEASE、重复 effect/release、未闭合 replay 或实际 cache busy。这样软件 commit、cache acceptance 和物理 effect 分别计量。

## 5. main/checker 的自动判据

```text
MAIN_CHECKER_CLOSURE_READY=YES
```

BOOM 普通 load/store 在 architectural retirement 统计，资格为 LSQ 锁存的 `traffic_scope_valid && traffic_check && packet_seq!=0`；重试保留资格和 package identity，不能以仅非零 tag 或 live window 给窗口外访问重新授权。Checker 用实际 dequeue/WB 事件，并限制在 checking/postchecking ownership 和 performance window；LR/SC/AMO 单独统计，不与普通 load/store 混合。此次 directed AMO 不改变普通统计定义。

`RocketCore.scala` 将 checker debug token 绑定到 checker-owned `package_seq_reg`；已将连接移至该 `val` 声明之后，消除前向引用隐患。BOOM_STAT 带 LSQ `seq`；CHECKER_STAT 带本地 package token。

analyzer 输出 MAIN_COUNT/CHECKER_COUNT/MAIN_CHECKER_DIFF、独立 STORE/LOAD 差值，检查全部六个 total/cacheable/uncacheable counters，避免 store/load 差额抵消；另比较 `(seq, kind, cacheability)` 的事件多重集，定位包级口径差异。PC/address trace 差异仍保存为诊断。旧格式缺 stable seq 时不能据总计相等宣布完整闭合。重试、kill、clear 的物理事件不参与 architectural retirement counter；是否动态完全相等由下轮判定。

## 6. clear/S1/S2/refill 证据路径

```text
CLEAR_S1_S2_REFILL_CLOSURE_MODE=B
```

采用对本次实际发生事件的 invariant 检查。历史同一 BFS 已有 CLEAR=187、REFILL=30,596、S1=1,755,252、S2=1,705,836，为常规运行提供有依据的事件覆盖预期；不声称软件可以确定制造某个极低概率同周期 interleaving，也不把这些历史计数当作新源码的动态 PASS。

新增 `CLEAR_CHECK` 在每次真实 clear fire 及首次 pending 决策时，记录同 set 的 S1/S2 any 与 before-freeze old 请求、同 slot 的 held S3/completion，以及 MSHR/slot conflict。EFFECT 增加 set/way/owner_match；INSTALL/REFILL/CLEAR 已有 slot epoch、line、MSHR、transaction identity。

analyzer 以整个 DCache cycle 为单位匹配，避免依赖 printf 顺序，自动检查：

- 每次 CLEAR 必须有当周期 fired CLEAR_CHECK；fire 时 old S1/S2、held S3、completion、slot conflict 必须为零。
- 同 slot 不允许 CLEAR/EFFECT 或 CLEAR/INSTALL/REFILL 同周期；clear 后 effect/install/refill 必须使用更新 epoch。
- 每个 refill 必须匹配最近 INSTALL 的 line/epoch/MSHR/transaction，beat 必须唯一且按序；EFFECT 必须 owner_match。
- 输出 checks/clear/install/refill 和 S1/S2 overlap coverage；缺事件/必要字段不会空集 PASS。

本项闭合范围是**实际运行中所有 clear 决策和 install/refill/effect 的这些 invariant**，结合现有 RTL owner/drain assertions。并非穷尽所有可能的调度；Mode B 不依赖必须随机撞到某一种特定 race。若实际无 CLEAR/INSTALL/REFILL，结果仍为 UNRESOLVED，不能以运行成功替代证据。

## 7. 统一 analyzer summary

`stage1_trace_scoreboard.py` 输出如下指标，并提供各 gate 的 PASS/FAIL/UNRESOLVED 和详细 JSON：

```text
ARCH_ERROR
AMO_LOW_LANE_SEEN / AMO_HIGH_LANE_SEEN / AMO_ERROR
MAIN_COUNT / CHECKER_COUNT / MAIN_CHECKER_DIFF
MAIN_CHECKER_STORE_DIFF / MAIN_CHECKER_LOAD_DIFF
DUP_EFFECT / LOST_EFFECT
EFFECT_WITHOUT_TERMINAL / DUP_TERMINAL
TERMINAL_WITHOUT_STQ_RELEASE / DUP_STQ_RELEASE
REPLAY_UNCLOSED / CLEAR_RACE_VIOLATION
EXIT_REAL_OUTSTANDING / EXIT_LOOP_PENDING
STAGE1_TRACE=PASS|FAIL|UNRESOLVED
```

AMO 使用独立 Python reference 检查 lane、完整 64-bit 写回值、mask、sign-extended return 和 matching terminal。architectural gate 必须同时有 `verified=1`、serial_success 且无 assertion/mismatch；仅 `ARCH_ERROR=0` 不替代 coverage 或完成判据。缺必需证据时总体返回 2，真实失败返回 1，所有 gate PASS 才返回 0。

## 8. 稳定 identity 链

| 链路 | join 键与边界 |
|---|---|
| LSU request → S1/S2 | LSQ allocation 的 `functional_token` → `request_token/req`；同一 entry 的重试保持 token。 |
| S2 → replay | `req/effect`，以及 owner `mshr/transaction_token/slot_epoch/way`；REPLAY_GRANT/RESULT 用 `(mshr,txn,req)`。 |
| install/refill | INSTALL 将 initiating req 关联到 line/slot/epoch/MSHR/txn；REFILL 用该 owner tuple 关联，不能把其 transaction token 当 request token。 |
| effect → terminal → STQ | `req/effect` 与 STQ slot；terminal/STORE_DONE/RELEASE 分别检查唯一性、身份、状态和返回数据。 |
| main → checker | BOOM_STAT 的 functional token 桥接本地访存，锁存 seq 与 checker-owned package_seq_reg 对应；按包、kind、cacheability 计数，PC/address 多重集用于进一步定位。checker package token 不等于每条 BOOM request token。 |
| exit drain | EXIT_STQ 逐项 token/slot/PC/address/flags 与 ARCH_STORE/ISSUE 精确对应；S3/completion/replay head token 和全局 busy 位保留未退休责任。 |

未发现需要 architectural redesign 的 identity 断裂。本轮补的是 functional ARCH_STORE、稳定统计 seq 和真实退出状态；没有把 traffic stats token 当作物理 effect identity。

## 9. 已执行验证与下一步

- Python offline unittest：23 项通过（scoreboard 21 项、provenance 2 项），包含双 lane reference、完整 synthetic closure、丢失/重复/未 release、clear 同周期顺序/旧 epoch/refill owner、退出精确 owner、已接受请求、未知提交项、停驻预取计数、缺 snapshot/fence-ready、总计抵消和 package identity 等负例。
- 四个 shell 脚本 `bash -n`、Python AST parse、`git diff --check` 通过。
- 独立软件编译/objdump/elf2hex 完成，`WORKLOAD_IDENTITY=PASS`；当前已准备好默认 manifest。
- Scala/C++ 观察端口、Vec 维度/字段顺序和 v1Config hart 静态复核；**尚未编译或 elaboration 验证这些新增端口**，这是本轮禁止硬件工具下的验证边界。

离线检查原始输出与本轮代码 hash 保存在 `AI/TMP/stage1_readiness_dtdeoatb/`（`static-checks.json`、unittest/shell-syntax/workload-identity/diff-check logs）。这份清单只证明静态 preflight，不冒充 build provenance。

历史运行 `AI/TMP/stage1_trace_20261016_120118/trace.log` 及其 707/1715 计数差、15 个退出 commits 的事实保留在 [历史 closure checkpoint](stage1_closure_20261016.md)。它不验证本次新源码；不重写其 provenance，不复用其旧 simulator。

用户下一步准确命令（本轮未执行）：

```bash
/data1/gzh/EC/AI/Debug/scripts/stage1_build_and_run.sh
```

此命令将默认启用 FST 并打印新 build/run 路径。查看该 run 的 `scoreboard.out`/`scoreboard.json`；真实退出 busy 必须明确 FAIL，不能为了得到 closure PASS 而丢弃 `_exit` 事务或修改退出语义。
