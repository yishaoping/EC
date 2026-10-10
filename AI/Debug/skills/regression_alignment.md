# BOOM/Rocket alignment 与统计差值

先确定比较口径：架构退休、物理完成、请求入口、checker WB 和软件窗口不是同一种事件。按 sequence、动态退休序号、PC+机器码对齐，startup jump/trap/管理指令单独处理。同 PC 在合法循环中重复不是 duplicate；独立参考应来自 BOOM 架构退休而非修复自身 count。分别核对物理 replay/forwarding 与架构事件，再检查 START/STOP/reset/safe 水位边界。

新运行先复查旧 first-bad。旧运行中排除的“软件重复/CDC丢包/容量溢出”不能自动视作新运行已排除；保留运行边界。输出净差值同时列正负贡献，避免只看总数抵消。
