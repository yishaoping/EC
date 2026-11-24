# Sv39物理读取与恢复后架构结果联合计分

```bash
python3 -B AI/Debug/scripts/sv39/scoreboard.py \
  --normal "$normal_log" --fault "$fault8_log" --report "$fresh_report"
```

这是固定compact-sv39工作负载：alias LOAD PC为0x8000045c，round保存在x5，
返回值写x12，两物理页0x8000a000/0x8000b000。原ELF与长期等价profile的
loaded bytes必须记录；换程序/寄存器分配必须重新审查该契约，不能静默接受。

原简化脚本错误地要求故障运行也恰好16次物理读取。V6、V10和本批实际均为
18次：SCP8在round3已读之后、PC0x800004bc建立；错误报告前又完成round4/5；
恢复截断这两次逻辑操作，随后round4/5重新执行。最终仍恰好16次存活操作。
原计分失败保留，不能当作硬件退化，也不能简单改成18或至少16。

当前计分把每个请求/响应/终态与Main实际提交trace一一配对，核对x5 round、
x12写回、真实物理地址和数据。SCP记录提交前缀及x5，Restore严格按其PC和
前缀截断已废弃逻辑操作。故障前被废弃的物理读取也必须正确，不豁免数据。
两个生产模块同一拍printf可有不同先后，因此两个完整事件流以FIFO配对，
不凭日志行顺序把同拍打印误判成缺终态。最终必须无未配对物理/提交事件，
存活round恰好0..15，物理尝试数等于存活加废弃数，并通过完整架构/唯一FAIL8/
SCP/EVT/Restore/Restart严格配对。缺日志或不兼容输入均失败。

实际本批正常16物理/16存活、Fault8为18物理/16存活/2废弃。四个负例均被拒绝：
废弃round数据损坏、重执行数据损坏、缺SCP、恢复PC错误。此前首次双流实现
假定终态总在提交打印之前，正常运行暴露同拍相反打印顺序，已修成双队列；
最终正向两控制与四负例联合验收。证据在本批current_sv39_strict_pair_retry及
sv39_oracle_negative_paired/，不能用最初parser失败日志冒充当前通过。
