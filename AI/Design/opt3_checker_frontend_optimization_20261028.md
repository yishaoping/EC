# Opt3：Checker 前端指令供给优化设计与验证

- 日期：2026-10-28。
- 项目：`/data1/gzh/EC`；硬件源码：`chipyard/`。
- 主实现：`chipyard/generators/rocket-chip/src/main/scala/rocket/Frontend.scala`。
- 成功运行：`optimization_3_checker_20261028_090640_a56794e2`。
- 状态：GAPBS512 已测有显著收益；本次文档/提交整理不改变已仿真的硬件字节。

## 1. 优化范围与结论

Opt3 将已接收的 checker ICache S2 response 捕获与控制流指令（CFI）分类合并，
移除固定的 `checker_classify` 状态。它不是预测、预取或多 owner 流水化：
同一时刻仍只有一个尚未交付的 checker response。

同时保留此前 Opt2b：当前 response 被 Fetch Queue（FQ）接受时，同拍请求
已经解析的 successor，避免先回到 EMPTY 再发请求的固定空拍。两项优化分别
作用于 response 到达端和 response 交付端，实验上分开实现和测量。

Opt3 ROI 为 **2,928,347 主核周期**，相对 Opt2b 的 3,760,243 减少
**831,896（22.123464%）**。相对最初 Current 累计减少 38.153736%。
这些是固定 GAPBS512、固定软件、固定配置和 seed 的实测比较；不宣称其他负载
均有相同比例收益，也不将各 checker local cycle 直接相加为可消除的主核周期。

## 2. 为什么选择前端

Opt2 调整了 checker 分配，包数更均衡，但 ROI 几乎不变。Opt2b 的 handoff
优化则将 ROI 从 4,707,273 降到 3,760,243，说明频繁的前端空拍值得继续追踪。

Opt2b 在完全观测的 324 个 ROI package 中，owned execution 共 3,739,176
checker local cycles；互斥优先分类 `WAIT_INSTRUCTION` 为 1,980,533（52.9671%）。
producer seal 后为 1,285,131 / 1,708,940（75.2005%）。Frontend 的独立
CLASSIFY 状态累计出现 630,955 次，ICache acquire 仅 92 次，fault emission 为 0。
因此不能把这类等待简单归因于 ICache miss。

分类 counter 由实际状态和 `RocketCore` 的优先级谓词定义，不是所有 raw
wait predicate 的无重叠并集。`WAIT_CONTROL` 包含管理/流式等待等多项条件，
不能解释成纯 branch stall。BJL empty 等 Frontend 诊断也不能与 core stall 相加。

SVB 未被选中：串行 WaitSafe trace 看不到从未发出的 younger stores，无法可靠
估计反事实版本深度/全局占用；`L2=P0 safe / SVB=P1 / L1=P2` 后出现
`P1 PASS, P2 FAIL` 时，latest-safe 恢复数据源和一致性所有权也尚未闭合。
本次没有实现 SVB、修改 watermark 或放宽 cache 安全条件。

## 3. 数据、控制与时钟域

本优化全部位于 `FrontendModule` 的 `withClock(gated_clock)` 区域。
没有新增 CDC、修改 checker/main 时钟比，或改变 result-return 协议。
已保存运行中观测到一个 checker local cycle 对应两个 main cycles；这只是
本配置的观测关系，不应推广为任意配置常数。

```text
checker_seq + 已解析 PC
          │ request valid/ready/fire
          ▼
       ICache / TLB
          │ owned S2 response
          ▼
 checker_incoming ── CFI scan + exception/replay classification
          │ 同一拍写寄存器
          ├─ checker_resp / checker_gpa
          ├─ checker_next_pc 或 checker_cfi_* → WAIT_BJL
          └─ checker_tail_*（跨块 RVC 尾部）
          │
          ▼
        READY ── FQ enq.fire ──► IBuf / checker execution
          │
          └─ Opt2b：满足 guard 时同拍请求 successor
```

ICache 数据不是主核校验结果；FQ handoff 也不是指令退休、BJL commit 或 package PASS。
前端提前供给可缩短后续 exec_done，但 package/result/safe 判定仍由原逻辑负责。

## 4. Opt2b：response 交付端消除 EMPTY 空拍

入口信号是 `checker_handoff`，实际接受事件是 `checker_handoff_fire`。
只有以下条件同时满足才允许 READY 期间发出下一请求：

1. `checker_emit` 且 `fq.io.enq.ready`，当前 response 正在交付；
2. `checker_request` 有效：checker mode、未完成、非零 sequence、没有 clear；
3. 当前 response 无 replay、无异常；
4. 没有 `redirect_pending`、`redirect_settle`、`io.cpu.req.valid`。

`s0_valid` 在 EMPTY 或合格 handoff 窗口允许请求。当前 FQ 交付后，若 successor
`icache.io.req.fire`，FSM 直接保持/进入 FETCHING，否则回 EMPTY 按原路径重试。
`checker_fetch_pc` 和 `checker_fetch_seq` 只在实际接收请求时更新。

因此不会跨越 held response 猜测 next PC，也不会在 ICache 不 ready 时假定
请求已经发出。每次成功 handoff 最多移除一个固定 local issue cycle。

## 5. Opt3：response 接收端融合分类

### 5.1 状态迁移变化

旧状态集合：

```text
EMPTY → FETCHING → CLASSIFY → READY → EMPTY/下一请求
                            └→ WAIT_BJL → READY
```

新状态集合：

```text
EMPTY → FETCHING ── owned response + classify ──► READY
               └─ owned response + CFI ────────► WAIT_BJL → READY
```

`Enum(5)` 变为 `Enum(4)`，删除的只是额外寄存一拍的分类状态。
仍保留 READY 寄存边界；没有从组合 ICache bus 直接把数据送进 FQ。

### 5.2 接收条件与数据对齐

`checker_classify_fire` 要求：

- `checker_s2_owner`；
- `checker_state === checker_fetching`；
- `!s2_tlb_resp.miss`；
- `checker_cache_valid || icache.io.s2_kill`；
- `!io.cpu.req.valid && !io.cpu.checker_clear`。

`checker_incoming` 从已有 `legacy_resp` 取得 PC/TLB/异常等字段，并使用
`checker_cache_bits` 的数据；replay/access-error 按既有 checker capture 语义处理。
ICache latency=1 的配置继续使用原有 `RegNext`/`RegEnable` 对齐方案；其他配置
继续使用原 response 接口，未重新解释 cache 延迟。

实际接收边写入 `checker_resp`、GPA、默认 prefix、清零的 `bjlEndMask`，并进行
CFI scan。TLB miss 或没有可接收 response 时回 EMPTY 重试，不承诺迟到 response。
redirect/clear 的末级赋值仍优先清除旧 owner/partial 状态。

### 5.3 四种分类结果

按源码优先顺序：

| 条件 | 动作 | 下一状态 |
|---|---|---|
| 无 CFI，或 replay/exception | 默认 prefix/顺序 successor；fault 仍限制 handoff | READY |
| 首个 CFI 前存在有效 prefix | 先交付 prefix；next PC 指向 CFI | READY |
| CFI 为已有特殊 JALR 编码 | 保留原处理，next PC=CFI PC+4 | READY |
| 其余 CFI | 保存 `checker_cfi_pc/end/rvc`，等待真实 BJL head | WAIT_BJL |

这些模式是 accepted-response 的分区，不是 retired-instruction 分区。

## 6. BJL 所有权与顺序保持

`BJL.io.bj_req_valid` 仍只在 WAIT_BJL，且 head 的 PC、RVC 标志与当前 CFI
匹配、没有 redirect/clear 时有效。分类本身不 reserve/pop BJL。

BJL request fire 后才写入已记录的 taken/target 和 CFI end mask，然后进入 READY。
`bj_commit_valid` 仍来自 CPU 的 `bjl_commit`；`bj_rollback` 仍来自 redirect。
因此 reserve、交付到 FQ、指令 commit 和 rollback 是不同事件，不能互相替代。
本次未改 `R_BJL.scala`、`IBuf.scala` 的功能。

## 7. 跨取指块压缩指令与 FQ 反压

RVC 下，32-bit instruction 可能跨 fetch block。scan 使用
`checker_partial_valid/bits/pc/seq`，并要求 sequence 相等、PC 相邻，才把
前一块的低半字与本块高半字合并。

旧 scan 读取已注册 `checker_resp`；融合后读取 `checker_incoming`。为使 READY
等待任意 FQ 反压期间不依赖不断变化的 live ICache data bus，新增加：

| 寄存器 | 保存内容 |
|---|---|
| `checker_tail_valid` | scan 后的尾部是否为未完成 instruction |
| `checker_tail_bits` | 尾部半字 |
| `checker_tail_pc` | 对应 PC |

以上与 response 在同一接收边捕获。只有 FQ 接收、交付完整 fetch suffix、没有
fault、没有 BJL end mask 时，才把 held tail 提交给 `checker_partial_*`。
`checker_partial_seq` 使用仍拥有当前响应的旧 sequence；同拍 successor capture
不会把它错标成新 owner。redirect/clear 清除 `checker_partial_valid`。

## 8. 正确性不变量与断言

Frontend 中保留/增加的检查包括：

- 分类不能同时交付另一个 FQ response；
- incoming PC 必须等于实际接收请求的 `checker_fetch_pc`；
- 分类边不能提前 reserve BJL；
- 分类后的响应 PC/data 和 READY/WAIT_BJL 状态必须与 captured decision 一致；
- 合格 handoff 必须伴随 FQ fire，且不能仍持有上一 S1/S2 request owner；
- 下一拍 handoff owner/PC 不丢失；
- READY prefix 非零、不超出本 fetch 的有效范围，BJL mask 至多一位；
- FQ 反压期间 response 保持；
- 活跃 owner 的 sequence 与 CPU checker sequence 一致。

成功 GAPBS512 没有触发这些断言。但它不能证明所有异常、replay、FAIL/recovery、
probe 或任意 ICache 配置均正确，也不替代模块级形式验证或时序收敛验证。

## 9. Compact observation 与分析器

保留 kind1..15 共 67 个 observer，新增 kind16 四个 checker 实例，总计 71。
`SafeChainObservation`/`SafeChainEventLogger` 是 input-only 观测 sink。
`emulator.cc` 仅在 `SAFE_CHAIN_EVENTS` 构建下调用 `tile->final()` 产生完整 footer，
不增加 eval 或 clock edge。

kind13 原字段位置保持；已删除的 CLASSIFY 状态位置固定为 0，避免旧字段移位。
kind16 每行 payload 的含义：

| 字段 | 内容 |
|---|---|
| d0 | `checker_seq` |
| d1 | accepted fused classifications |
| d2 | no-CFI 或 fault 模式 |
| d3 | prefix-before-CFI 模式 |
| d4 | special-JALR 模式 |
| d5 | WAIT_BJL 模式 |
| d6 | BJL reserve fire |
| d7 | WAIT_BJL 且 BJL not ready 的 local cycles |
| d8 | WAIT_BJL、BJL ready 但 head mismatch 的 local cycles |
| d9 | READY held by FQ 的 local cycles |
| d10 | 既有 Frontend flags |
| d11..15 | padding |

必须满足 `d1=d2+d3+d4+d5`。d6..d9 是有重叠的诊断，不能加入该分区。
累计 counter 只在 sequence/flags 或 emitted 高位改变时稀疏快照，尾部可能被
censor；不是每 fetch 一行。事件上限 48 MiB，stdout/stderr 各 2 MiB；不输出全 ROI FST/VCD。

分析器 `analysis/opt3_summary.py` 本次整理修正了继承的旧字段：
`opt2b_roi=3760243`、`opt3_roi=本次 ROI`，`incremental_gain_*` 明确相对 Opt2b。
相对 Opt2/最初 Current 的收益另列；原成功 run 下的旧 summary/manifest 一律保留。
分析器还逐快照检查分类分区和 counter 单调性，保留失败结果为证据不完整。
历史 safe-chain 比较只读取随 Git 保存的小型 `reference_safe_chain_summary.json`，
其中保留原摘要路径和 SHA256；不再依赖未提交的旧 run 目录。原日志保持不变。

## 10. 实测结果

配置：`chipyard.v1Config`；seed=1；max-cycles=500000000；jobs=1。
固定软件 ELF SHA256：
`da8897e790f0c5e91eff3e9560d2b0e7b4e1de6dff208788fb4d9e2ae462c81c`。

| 版本 | ROI（main cycles） |
|---|---:|
| Baseline | 1,001,675 |
| Original Current | 4,734,881 |
| Opt1 | 4,706,513 |
| Opt2 | 4,707,273 |
| Opt2b | 3,760,243 |
| Opt3 | 2,928,347 |

| 聚合指标 | Opt2b | Opt3 |
|---|---:|---:|
| 完整 ROI package counter windows | 324 | 312 |
| 指令等待 local cycles | 1,980,533 | 1,346,930 |
| 独立 CLASSIFY local cycles | 630,955 | 0 |
| 融合分类次数（kind16） | 未定义 | 630,932 |
| Opt2b handoff 次数 | 630,212 | 630,260 |
| admission→done 平均 main cycles | 23,083.33 | 17,792.74 |
| admission→done p95 main cycles | 48,126 | 35,708 |
| 严格 unsafe WaitSafe main cycles | 2,296,540 | 1,547,483 |
| 全部 pending main cycles | 2,374,335 | 1,625,485 |
| sealed→exec_done pending main cycles | 2,098,732 | 1,407,280 |

不同运行的 package 边界与数量会变化；上述是同软件 ROI 下的聚合观测，不是
相同 package 的逐项因果配对。630,932 次移除状态拍也不是 630,932 个主核 ROI
cycles：多 checker 并发、供给重叠和主核是否真正被阻塞均影响实际收益。

GAPBS512 reached=512、edges=8192、verified=1、checksum=43439728。
315 accepted PASS，FAIL/CANCEL/stale/held-duplicate/collision 均为 0；
无 unsafe cross-package semantic overwrite 观测。71 footer、127,466 event，
39,029,794 bytes，无 overflow/truncation；精确 Stage1 L1/LSU exit drain PASS。
剩余指令等待占 48.53%，post-seal 占 67.64%，仍是最大的观测分类。

## 11. 本次提交边界与依赖

当前 Git 基准为 `ab4f1f48811f9a4037b1f980fa94ddf611d9cb07`。
该基准尚未提交 Opt1/Opt2/Opt2b 依赖，因此本次 Opt3 是可运行的累计提交，
不能只摘取 Frontend 一个文件并认为包含完整实验环境。

| 路径/模块 | 提交原因 |
|---|---|
| `rocket/Frontend.scala` | Opt2b handoff、Opt3 fused classification、tail capture、assertions、kind13/16 |
| `boom/.../lsu/dcache.scala` | 已验证 Opt1 hit-only bypass 与 safe-chain/cache identity 观测 |
| `guardiancouncil/ght_sch.scala`、`r/R_IC.scala` | 保留已测 Opt2 availability-aware round-robin 和观测 |
| `rocket/RocketCore.scala` | package execution 分类、时间戳和 compact counters |
| `guardiancouncil/GHM.scala`、`InclusiveCache.scala` | result CDC / L2 侧观测闭环 |
| `util/SafeChainObservation.scala`、`resources/vsrc/SafeChainEventLogger.v` | 共享 input-only observer 类与 BlackBox 资源 |
| `emulator.cc`、rocket-chip `.gitignore` | footer 产生及资源可归档性 |
| `slowdown/run_optimization_3_checker.sh` 与对应 scripts/analysis/manifests | 可复现入口、隔离构建、capture、分析、资源与源码身份 |
| 本文件、精简实测记录、Debug state/history | 机制、验证范围和维护交接 |

以上硬件字节与成功运行 identity 相同。本次不改 RTL 控制、不改 ELF、不改
配置、cycle limit、seed、CDC、安全判定或 recovery。无关 `DOC/Figure/` 与
`docs/paper_design_reference.typ` 的本地修改/删除不进入此提交。
构建目录、缓存、仿真日志、waveform、临时目录、锁文件不进入 Git，也不删除。

## 12. 提交后源码身份与 SBT 路径

launcher 相对固定 `BASE_SOURCE_HEAD` 比较源码内容，并显式纳入两个 observer
资源；不依赖工作区是否 dirty。因此将相同字节从 untracked/modified 变成 tracked/
committed 不应改变 `source_digest`。提交前后都必须验证：

`dece4a35a99eb0c2ed30fb917a9f8946e9d8d53a48d7f99c36e51f15a15e1fae`。

仿真软件直接引用既有 Baseline ELF/loadmem，不重新编译、不复制到 run。
独立 build 只修改 `optimization_3_checker/build`，不覆盖主源码和旧 build。

SBT socket 的旧路径为 110 bytes，超过 Unix socket 路径限制；现在在实验锁内
选择 `tmp/t`、`tmp/u` … `tmp/z` 的未占用私有目录，完整路径 102 bytes。
不复用旧目录，不放宽保护，不改 sandbox 的只读源码/私有临时目录语义。
短目录全部占满时明确报错，由用户决定如何处理，不能自行清理证据。

## 13. 后续复现命令

只读/纯文件静态检查，不运行 SBT 或编译：

```bash
bash /data1/gzh/EC/slowdown/run_optimization_3_checker.sh --static-check
python3 -I -B /data1/gzh/EC/slowdown/optimization_3_checker/scripts/offline_contract_tests.py
python3 -I -B /data1/gzh/EC/slowdown/optimization_3_checker/scripts/offline_release_tests.py
```

在同一机器显式重跑本次成功实验，先只验证复现授权与身份：

```bash
bash /data1/gzh/EC/slowdown/run_optimization_3_checker.sh \
  --static-check --repeat-from optimization_3_checker_20261028_090640_a56794e2
```

真正生成/编译/仿真，只由用户执行：

```bash
bash /data1/gzh/EC/slowdown/run_optimization_3_checker.sh \
  --repeat-from optimization_3_checker_20261028_090640_a56794e2
```

`--repeat-from` 必须是最近一次已完成、exit0、SUCCEEDED、coverage COMPLETE 的
run；要求硬件 digest 和软件 hash 一致。创建新的唯一 run/build/tmp，保留旧
`SIMULATION_STARTED.json`。不指定参数仍禁止第二次默认仿真；失败或未完成的
最近尝试不能用该参数绕过，也不自动 retry。此参数并不允许任意新 RTL 复用旧
identity；新功能版本须单独审阅/准备 manifest。

离线重新分析旧日志只读输入，并写全新目录；无需重跑仿真：

```bash
python3 -I -B /data1/gzh/EC/slowdown/optimization_3_checker/analysis/opt3_summary.py \
  /data1/gzh/EC/slowdown/optimization_3_checker/runs/optimization_3_checker_20261028_090640_a56794e2/safe_chain_events.tsv \
  /data1/gzh/EC/slowdown/optimization_3_checker/runs/optimization_3_checker_20261028_090640_a56794e2/roi.json \
  /data1/gzh/EC/AI/TMP/opt3_reanalysis_USER_UNIQUE
```

项目依赖已安装的本机工具链、Baseline 软件和离线依赖缓存；Git 提交不包含这些
GB 级外部输入。提交后在本机可验证依赖闭包，不宣称仅 clone 一个仓库即可在
任意机器无需准备地仿真。

## 14. 验证分层与未闭合项

- 已有运行完成 Scala/SBT、elaboration/RTL generation、Verilator build、整机 GAPBS512；
  generated/compiled observer audit 均 PASS。
- 本次提交整理仅执行 Python/文件合同、历史日志离线重放、Git/index/归档身份检查。
  不运行硬件生成、编译或新仿真。
- FPGA/ASIC 综合、布局布线、最高频率和时序收敛没有测量。CFI scan 移到 S2
  data→response metadata 路径，增加组合深度；不能把仿真 cycle 收益直接当频率收益。
- Stage1 L1/LSU drain 不等价于完整 package/cache/DRAM durable drain。
- `RUN_PROVENANCE` 保持原有 UNRESOLVED，不因源码 hash 一致而擅自升级为全局 PASS。
- PASS workload 未覆盖 FAIL/recovery、probe、复杂 redirect/replay 的所有组合。
- SVB 未实现，其版本深度、容量需求与 latest-safe restore invariant 仍开放。

## 15. 证据入口

- 原始 Opt3：`slowdown/optimization_3_checker/runs/optimization_3_checker_20261028_090640_a56794e2/`。
- 原始 Opt2b：`slowdown/optimization_2b/runs/optimization_2b_20261027_200348_2b41a21b/`。
- 原始分析与决策：`AI/TMP/opt2b_result_and_next_opt_20261028_081042_cb4f1916/`。
- 已纠正比较的离线结果：`AI/TMP/opt3_results_20261028_122909_092f25bb/`。
- 可随 Git 保存的小型测量记录：`slowdown/optimization_3_checker/manifests/measured_result.json`。
- 提交归档核验：本次 `AI/TMP/opt3_commit_*` 工作目录；大运行证据原地保存。
