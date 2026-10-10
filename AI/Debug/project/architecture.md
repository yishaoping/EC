# 项目架构

## 作用

这是一个 Chipyard 配置 `v1Config` 下的 BOOM 大核与四个 Rocket checker 协同校验系统。BOOM 负责真实架构执行；Rocket checker 通过 GuardianCouncil 重放 BOOM 的指令、数据、ARF/CSR 和控制流，并把带 package sequence 的结果返回 BOOM。

## 主要路径

- BOOM：`chipyard/generators/boom/src/main/scala/`
- Rocket/GuardianCouncil：`chipyard/generators/rocket-chip/src/main/scala/`
- v1Config：`chipyard/generators/chipyard/src/main/scala/config/RocketConfigs.scala`
- 仿真输出：`chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/`
- 生成 RTL：`chipyard/sims/verilator/generated-src/` 或本地隔离 build 目录
- 软件输入：`Software/Test/test.riscv` 与 `test.dump`

当前参数事实来自源码：`GH_NUM_CORES=5`、`GH_NUM_BIG_CORES=1`、`GH_TOTAL_PACKETS=2`、`GH_REAL_BARRIER_ENABLED=true`。不要把旧生成物的参数当成当前源码参数，必须记录生成目录、软件 hash 和 Git diff 身份。

## 数据流

```text
BOOM ROB commit
  -> GH_BUF/GHM（按 sequence 路由 DATA/ARF/CPS/END）
  -> CDC AsyncQueue
  -> Rocket R_IC/R_ICSL、RSU/RSUSL、LSL/ELU
  -> data/ARF/CSR/instruction-tail completion
  -> package result CDC / safe watermark
  -> BOOM ownership clear
```

`ready` 只是接收许可，只有 `valid && ready` 是 fire。FIFO 非空、barrier ACK、session FINISH、checker PASS、result dequeue 和 BOOM clear 是不同事件。

## 机制摘要

- **Barrier/cache/TileLink**：真实 barrier 由 L2 dirty tracked writeback 的 packet sequence 与 safe watermark 约束；`barrier_allow`、TL C-channel completion、metadata clear、`TtoN`、safe watermark 和 PASS 不能互相替代。
- **Snapshot/next PC**：snapshot 需要空 ROB、有效 committed next PC、注册 quiet/armed；空 ROB 的旧 head storage 不是架构 PC。
- **LSL**：SyncReadMem 先 `deq_read`，再寄存 payload/valid；请求必须匹配 head 的类型和地址，只有匹配请求 fire 才出队；payload 必须保持到响应。
- **Drain/count/END**：BOOM 仍可在 barrier close 后 drain 旧 package。最终 count 必须覆盖该 sequence 的全部架构退休，END/producer seal 必须在最后一条旧包记录之后产生。
- **Strict store/token**：架构提交产生 token，token 经 DCache/MSHR/replay 传递，在匹配物理完成处只消费一次；STQ index 或无身份写脉冲不能单独去重。
- **异常/前端/BJL**：redirect、handler、checker descriptor、BJL reservation 和 commit/rollback 各有生命周期；redirect 当拍不能用旧 mode 给新请求打身份，也不能用 ready 单独释放 pending。

## 核心 invariant

1. 一个非零 sequence 只有一个 owner；allocation、snapshot、LSQ、CDC、checker、result 和 release 使用同一 identity。
2. 每个 producer final count 与同一 sequence 的真实 BOOM 架构退休区间相等；done 之后不得再出现未覆盖的旧包退休。
3. DATA/ARF/CPS/END 的顺序、类型和背压必须可观察且不丢失；valid 拉高后 payload 保持到 fire。
4. LSL head 在类型/地址不匹配时不消费；匹配时 exactly-once。
5. strict-store token 一次分配、一次匹配完成、一次消费；reset/kill/reuse 会使旧 token 失效。
6. PASS、result release、safe watermark 和 barrier release 只在各自条件成立后发生。
7. Completion、stall、kill 和 pipeline valid 不能形成同周期组合反馈；每次接口新增必须经过 elaboration/FIRRTL 环检查。
8. 程序退出、watchdog 没触发或 package 数相等都不足以证明 `verified=1`。
