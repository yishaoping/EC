#set page(margin: 1.5cm)
#set text(font: "Noto Serif CJK SC", size: 10pt)
#set heading(numbering: "1.")
#show link: underline

= EC / Chipyard DebugFlow

这是 BOOM 主核、Rocket checker、GuardianCouncil、LSL、snapshot/drain、cache/TileLink 协同校验的快速工作流。当前状态唯一入口：`AI/Debug/state/current_debug_state.md`。

== 总流程

```text
新问题
  ↓
保存现场与 provenance
  ↓
更新 current_debug_state.md
  ↓
Root Cause Analysis
  ↓
first bad / first divergence / causal chain / broken invariant
  ↓
Fix Design
  ↓
Risk Review
  ↓
Implementation
  ↓
Static Check
  ↓
Compile / Elaborate / FIRRTL
  ↓
Simulation
  ↓
Independent Validation
  ↓
更新 Debug：state → bugs/history → skills/checks/scripts
```

中间波形、信号提取、generated RTL、编译对象和一次性日志放 `/data1/gzh/EC/AI/TMP`；长期结论和可复用工具写回 `/data1/gzh/EC/AI/Debug`。

== 阶段与 Agent prompt

=== 1. 新问题与保存现场

保存 `test.log`、仿真输出、波形、生成 RTL、软件 hash、Git HEAD/diff、配置、时间戳和时间单位；不要覆盖旧运行。

_ Prompt:_

```text
先只读保存现场。建立 run manifest，记录 FST/VCD 类型、时间换算、源码/生成物/软件身份。不要修改功能代码。
```

=== 2. Root Cause Analysis

先读 current state 和相关历史；用窄信号集建立 last good → first bad → failure 表。优先 first bad / first divergence，不能围绕最终 watchdog 猜测；区分 symptom、immediate blocker、upstream trigger、downstream amplifier。root cause 未确认前不要 patch。

_ Prompt:_

```text
以 rising edge 前状态检查 valid/ready/fire、commit、sequence 和 owner。找最早可证明的不变量破坏，列出已排除和未证明假设；不要先提出 patch。
```

=== 3. Fix Design 与 Risk Review

先写 broken invariant 的恢复条件，再写最小状态/握手设计。检查 reset、kill、redirect、slot reuse、CDC、backpressure、count/DATA/END、barrier/cache/TL，以及新增等待边和组合环。

_ Prompt:_

```text
只针对已确认 root cause 设计修复。说明生命周期、fire 条件、payload hold、清除优先级和不会新增的 wait-for edge；把方案标为 hypothesis，列出静态与动态验收门槛。
```

=== 4. Implementation 与 Static Check

检查真实 Scala/Chisel 类型、API、宽度、Bundle 宿主和所有实例连接。单独检查动态 `dontTouch`、SyncReadMem、ready 反向依赖和组合环。Scala compile 通过不代表 elaboration 或 FIRRTL 通过。

_ Prompt:_

```text
对照设计逐文件审查实现。执行 parser/API/type compile、Chisel elaboration、FIRRTL initialization/CheckCombLoops 和 generated RTL 对照；报告每一个 warning/error 的证据边界。
```

=== 5. Compile / Elaborate / Simulation

按顺序通过 Scala/Chisel 编译、目标 elaboration、FIRRTL/RTL 生成、模块定向测试和整机仿真。模块测试 PASS 不能替代整机验证；静态检查不能替代动态验证。

_ Prompt:_

```text
先模块后整机，所有产物写 TMP 并生成 manifest。不要把编译通过、程序跑完、watchdog 变晚或 package 数平衡称为功能正确。
```

=== 6. Validation 与资料回写

修复后确认 broken invariant 恢复：独立 BOOM commit/PC/机器码 scoreboard、DATA/ARF/CPS/END、LSL fire、result/release/safe、cache/TL/token 和最终软件输出都要对齐。新 bug 出现时先判断旧 first-bad 是否消失。

_ Prompt:_

```text
按独立参考事件验证修复。逐项确认 first bad 消失、invariant 恢复、旧路径无 regression；把 confirmed fact、historical conclusion、hypothesis、unresolved 分开写回 Debug。
```

== 固定提醒

- root cause 没确认前不要 patch。
- 优先 first bad / first divergence，不围绕最终 failure 猜测。
- symptom 不等于 root cause；fix 前明确 broken invariant，fix 后确认 invariant 恢复。
- `valid && ready` 才是 fire；FIFO 非空、ACK、PASS、safe 和程序结束不是同一事件。
- Chisel/Scala/FIRRTL/组合环必须单独检查；静态检查不能代替动态验证。
- count、DATA、END、slot lifecycle、replay exactly-once、drain 覆盖和 deadlock wait-for cycle 必须逐项核对。
- 程序跑完不默认正确；`verified=0`、计数差值或 checksum 错误仍是 failure。
- 中间文件进 TMP；长期结论、脚本、skill、checklist 和关键 provenance 必须写回 Debug。

== 收尾规则

每完成一次 _Root Cause → Fix Design → Implementation → Validation_：

+ 更新 `state/current_debug_state.md`。
+ 把结束问题写入 `bugs/` 和 `history/`。
+ 把通用经验加入 `skills/`、`checks/`。
+ 把可复用脚本加入 `scripts/`。
+ 保留 TMP 中间产物，是否清理由用户决定。
