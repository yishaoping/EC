# 历史上确实遗漏过的风险

这些项目来自保存的 Debug 记录：

- EC 实际 compile 日志出现未定义 `producerSealTrigger`；probe 删除后遗留 dontTouch 引用被静态审查遗漏。`asBools` 错误来自外部项目，仅作为类型/API 检查参考，不计入 EC 历史问题。
- dynamic Vec/Memory selection 上 `dontTouch` 触发 FIRRTL `NumberFormatException`。
- 跨模块 completion/snapshot/Frontend ready 路径形成 FIRRTL 组合环。
- `ready` 与 `SyncReadMem.read` 互相等待；原始 RAM output 不等于寄存 head payload。
- stale ROB head PC、redirect/handler 生命周期和 xRET 清 timeout，静态局部逻辑看不出跨周期后果。
- package final count 早于 drain、DATA/END/count 不同 owner；package 数平衡仍可 `verified=0`。
- strict store underflow、STQ reuse、killed replay/nack 需要 token/identity；不能用 Bool、地址或 slot index 单独去重。
- barrier ACK、PASS、safe watermark、TL completion 和 metadata clear 的顺序必须分开。
- 生成/模块测试 PASS 与整机动态功能正确不是同一个结论。

具体依据（区分真实发生与检查要求）：

- EC undefined symbol：`history/evidence/528000/implementation/compile.log` 中 `core.scala:2260 not found: value producerSealTrigger`，probe移除后的残留引用。
- Verilator bench/API：同目录 `ghm-sim/build.log`，`VlWide<9/5/6/3>` 不支持range-for begin；新工具生成header也需要实际C++编译。
- FST/位值：原FST提取用binary字符串；528000 audit按完整timestamp与edge前状态归并，不能按打印先后推断fire。
- FIRRTL组合环：`history/evidence/1769000/1769000_generate.log` 报4个RocketTile同构req.valid→FQ/IBuf→take_pc环；之后生成通过、但更早redirect regression证明静态生命周期审查仍漏项。
- no-progress timer：528000中38次无包进展xRET反复清零timeout；marker脚本当时PASS却未发现done早于drain。
- 新IO完整连接属于这次接口扩展确认必须核对的风险；没有保存某个missing-IO报错就不声称此错误实际发生。
