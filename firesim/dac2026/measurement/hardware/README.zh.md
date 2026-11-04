# B 的 ROI 源时间控制器（v4 候选）

本目录的 Scala 安装到独立 `work/opt4-roi-v4/B/chipyard`。v3 的 B/C4 源码、GoldenGate、
driver 和构建证据保持原样。当前 v4 只有 B，不包含 Rocket、GC 或纠错数据通路。
这两个模块不是 C4 延迟测量器，也不是 FireSim 宿主统计 bridge。

`DacRoiController` 运行在 BOOM 源时钟域，在退休处识别标准 NOP marker。
BOOM 的 ROB debug instruction 存储器同步读晚一周期，因此 valid/priv/satp/原 tick 同样延迟一周期，
与读出指令对齐；用原 tick 记录 ROI 起止，禁止用投递、MMIO 或宿主到达时刻替代。
只接受 hart0、U-mode、完整 satp 匹配的 marker。计数回绕、次序错误、多 marker 冲突使样本失败。
该接线依据静态源码时序；尚无用户运行证明，不能标记 timebase_verified=true。

`DacRoiPeripheral` 在 pbus 暴露64位 MMIO，DT 节点自动生成，候选地址0x10040000/4KiB。
请求和响应分别使用 RocketChip AsyncQueue；控制器反压仅连接控制队列，不连接 BOOM
dispatch/commit/LSU 等功能 ready/stall。原时钟时间戳随响应跨域，CDC 到达时间不参与 ROI。
响应在一个 pbus 边沿整体锁存，在下一个响应之前不变。该设备不发 DMA、中断或功能内存请求。

B 没有 checker、producer 或校验任务，因此任务数均为0，排空边界等于 ROI end，延迟 N/A；
这些常数只适用于真实 B。模块只公布 common+B capabilities，不公布纠错/执行完成/Linux-checker能力。
不能接到 C4 后保留这些常数，也不能把 retired marker 的时间冒充 BOOM 指令执行完成时间。

工作树由 `scripts/prepare_roi_hardware.py` 创建；构建要显式指定 `--integration opt4-roi-v4`。
脚本记录五个改动文件：controller、peripheral、BOOM tap、DigitalTop trait、Firechip config。
后续修订须保留失败日志，并以新源码 hash 重新生成；不能复用 v3 或不同 hash 的 GoldenGate/driver。

仍需验证：源 metadata 对齐、复位/首次边界、错误 marker、satp/任务切换、重复会话、异步队列复位与
反压、正常/异常 close、用户短程序/输出及共同 C4 策略。当前不自行运行这些仿真。
