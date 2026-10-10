# 屏障开启后 BOOM/checker 统计不一致：61299 vs 60587

## 结论

`test.log` 的差异是统计窗口停止时序不一致造成的，当前证据不支持
LSU 在同一窗口内重复累计同一个架构 Store：

```text
boom_arch   store=61299 load=84940
boom_strict store=61299 load=84940
checker_sum store=60587 load=82691
差值        store=+712  load=+2249
```

`boom_arch == boom_strict` 说明 BOOM 内部提交计数和严格完成计数是一致的；
不一致发生在 BOOM 与 checker 的跨 hart 统计窗口之间。

## 证据

日志路径：

```text
chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.log
```

本次波形实际文件虽然扩展名为 `.vcd`，内容是 Verilator FST：

```text
chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd
```

定向追踪结果：

| 事件 | VCD 时间 |
| --- | ---: |
| checker hart 3 发出 STOP | 3270205 |
| checker hart 4 发出 STOP | 3272497 |
| checker hart 1 发出 STOP | 3273949 |
| checker hart 2 发出 STOP | 3277109 |
| BOOM 发出 STOP | 3284491 |

因此最后一个 checker STOP 到 BOOM STOP 之间仍有约 7382 个 FST 时间单位，
约 3691 个 BOOM 时钟周期。该区间内 BOOM LSU 的
`arch_store_in_scope` 和 `arch_load_in_scope` 仍然有大量提交脉冲，计数器继续
增长；checker 已经在各自的 `checker.c` 中执行 `ghe_fpga_perf_stop()`，所以
不会记录这部分尾部提交。

相关软件路径：

```text
Software/Test/core/checker.c:44-46
Software/Test/stat/report.c:1003-1023
```

checker 在 `ghe_checkght_status() == 0x02` 后先停止自己的本地计数器并保存
快照；BOOM 则等所有 checker 快照就绪后，才在 `report_end()` 中停止计数器。

相关硬件路径：

```text
chipyard/generators/boom/src/main/scala/common/tile.scala:651-653
chipyard/generators/boom/src/main/scala/lsu/dcache.scala:446-456
chipyard/generators/boom/src/main/scala/lsu/lsu.scala:1819-1822
```

BOOM 的 `trafficCounting` 由本地 `traffic_start/traffic_stop` 控制；它没有
自动跟随 checker hart 的 STOP。屏障开启后 checker 完成与 BOOM 最终停止的
间隔被放大，所以原先未开屏障时看不出的窗口误差暴露出来。

## 另一个必须单独处理的问题

本次 `test.log` 的程序结果本身与参考运行不等价：

```text
verified=0
parent_checksum=6535936116
packages allocated=257
```

而 `Experiment/流量分析.typ` 中的参考运行是 `verified=1`、
`parent_checksum=43439728`，包数分别为 32（开屏障旧记录）和 279（未开屏障）。
因此不能用 61299 与旧记录 60570 直接判断屏障改变了同一条指令流的 Store 数量；
当前运行还存在 barrier/package 逻辑导致的功能结果偏离。

## 修复方向

统计修复应先统一窗口边界，再比较 BOOM 与 checker：

1. 在 benchmark 的共同逻辑结束点发出一次统一 STOP，让 BOOM 和所有 checker
   使用同一边界；或者让 BOOM 的计数窗口由同一个全局停止握手关闭。
2. STOP 后继续等待严格 Store、地址统计和 barrier pending 清零，只影响读取时机，
   不重新打开计数窗口。
3. 修复并验证 `verified=1`、checksum 和包生命周期后，再比较 60570、60587 等
   数值。不能通过给 checker 或 BOOM 加减常数来掩盖窗口错位。

本次只做了波形和源码静态分析，没有运行仿真，也没有生成 RTL。
