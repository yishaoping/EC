# Safe-chain 启动控制电平耗尽观测预算

- 状态：根因 DIRECT_EVIDENCE；修复静态通过，动态验证 UNRESOLVED。
- Run：`slowdown/safe_chain/runs/safe_chain_20261026_114110_076b64d2`；原 manifest、事件、guard 和 simulator 保留。
- Failure：`SAFE_CHAIN_OBSERVER_OVERFLOW`。旧生成和 Verilator build 均返回 0，仿真未到软件 ROI。
- First bad：首条事件已为 KIND=10/hart=0/RESET=1；cycle 0..49,999 连续产生相同 payload。无 START、ROI、footer；不能证明 workload 完成或性能根因。
- 因果链：启动软件控制 RESET 持续高 → KIND10 sample 持续真且 force_event 真 → 每周期重复记录 → 50,000 条上限触发 → capture 终止且因果证据不完整。原 capture 在保存 SC_OVERFLOW 身份前抛错，进一步丢失 kind/hart 诊断。
- 破坏的不变量：稳定控制不应重复消耗事件预算；首次失败身份应保存；机制观测失败不得当成功 workload 或安全完成。
- 修复：仅在 DCache `SAFE_CHAIN_OBSERVATION` 内将 RESET/START 转为上升沿；STOP 复用原 pulse。capture 保存溢出身份/统计/返回码，次级 close 错误不覆盖首次失败。原预算不变，无 Opt2 功能或保护逻辑改动。
- 重试：默认 guard 不变；显式 `--retry-observer-overflow safe_chain_20261026_114110_076b64d2` 校验原完整失败前缀、不同源码 digest 和唯一旧 guard。替代运行启动后拒绝进一步替代；不删除旧证据，不自动执行。
- Validation：35 项离线测试通过，含实际源码布尔边沿检查、控制高持续 60,000 cycles、重触发/同时触发、capture mock、guard 正反例。21 项来源与资源闭包 identity、Python AST/JSON/bash/diff 检查通过；从 Git 对象内存重建的 17 个 Opt1 文件哈希一致，观测块外不变。
- 未验证：修复版无 Scala 编译、elaboration、RTL generation、Verilator build 或仿真；其他 observer 的实际事件规模、ROI 完整性、Opt2 决策、ROB 关键路径、RUN_PROVENANCE 和全系统 drain 仍 UNRESOLVED。
- 下一步：由用户执行显式修复重试命令，完成后只分析新运行；旧 generated RTL 不代表边沿修复已验证。

详细证据：`AI/TMP/safe_chain_boundary_overflow_fix_20261026_abd48b5a/`。
