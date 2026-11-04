# B 原始 ROI 被动 bridge（v5 候选）

`DacRoiBridge.scala` 为真正 FireSim Bridge/BridgeModule，接收 BOOM 域的 epoch/state/tick/
begin/end/faults 和 reset；没有向目标输出协议 ready、stall、DMA 或中断。
控制器时间仍来自 BOOM 源时钟，桥不使用通知到达时间替代。B 的这个 bridge 不观察或计算 C4 延迟。

状态或 epoch/reset 变化时保留一条记录；宿主默认每20秒请求一次当前累计快照。
host FPGA 中16项队列保留完整记录，满时只暂停仿真 token 的宿主推进；不丢弃目标时钟周期。
记录在 MMIO 出队前保持稳定，低/高32位读取不跨不同记录。队列序号64位严格连续；回绕报错。

`ec_dac_roi_t` 是被生成 header 注册到 native driver 的真实 bridge driver。
只允许用户显式提供 `+ec-dac-roi-log=FILE`，路径必须在 `/data1/gzh/EC/Experiment` 内，
以 exclusive create 打开，拒绝覆盖旧日志。创建时 fsync 目录；每条追加完整 JSONL 后 fsync 文件，
成功后才向 FPGA 写 pop。磁盘错误、重复/缺失序号、目标 fault 或溢出使它请求退出，返回126。
快照间隔由 `+ec-dac-snapshot-seconds=N` 指定，范围1..60秒；这是宿主保存周期，性能仍使用源 tick。

原始 schema=`ec-dac-b-raw-roi/1`，保留uint64十进制，所有记录写 `formal_sample=false`。
当前 raw bridge 还没有 job/sample identity、guest输出确认、完成标记或 collector adapter。
因此即使后续用户看到记录，也不能当成正式样本或 slowdown 结果。未完成尾行需要由后续接收层
恢复/保留；本 driver 不提供断点续写，恢复运行必须创建新 attempt 文件。

源码安装到独立 `work/opt4-roi-v5/B/chipyard`，v4编译/内容证据不被修改。
除源寄存器被动导出和 FireSim blackbox/harness/bridge 外，B功能参数沿用v4。
v5独立 elaboration/GoldenGate/driver receipts 才能证明该版本编译；不能用C++语法检查代替它。
运行时持续保存、阻塞不改变目标时序、复位和marker对齐均待用户实际运行验证。
