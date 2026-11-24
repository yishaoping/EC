# 单主核 Rollback RTL 基准

| 需要查找的内容 | 入口 |
|---|---|
| 69 项任务的源码、信号、不变量、进度与剩余条件 | [功能实现矩阵](Feature_Implementation_Matrix.md) · [机器可读清单](implementation_manifest.json) · [原任务板](../05_SingleCore_Taskboard.md) |
| RTL 模块、状态转换与跨域握手 | [架构](RTL_Architecture.md) · [接口与握手](Interface_and_Handshake.md) · [恢复状态机](Recovery_State_Machine.md) |
| 安全基线的所有发布入口及 Seq 重基 | [基线发布](Baseline_Publication_Rules.md) · [Seq32 与 CDC](Seq32_CDC_Rules.md) |
| 断言、试验判定与可复现命令 | [硬件不变量](Hardware_Invariants.md) · [验证矩阵](Verification_Matrix.md) · [测试计划](../08_SingleCore_Manual_Test_Plan.md) |
| 实现边界和硬件开销 | [架构决策](Architecture_Decisions.md) · [成本审查](../15_SingleCore_RTL_Cost_Review.md) |

`05_SingleCore_Taskboard.json` 保存任务状态，`verification_catalog.json` 保存证据及其源码标识。修改这两份输入后运行现有渲染和静态检查入口。

```bash
python3 -B AI/Debug/scripts/rollback/render_taskboard.py
python3 -B AI/Debug/scripts/rollback/render_baseline.py
python3 -B AI/Debug/scripts/rollback/static_check.py
```

验证矩阵的每条运行记录带对应源码哈希。整核通过条件包括 workload 的退出状态、结果计分器和规定事件顺序。单项夹具通过按所列不变量计入，任务最终状态由实施矩阵给出。
