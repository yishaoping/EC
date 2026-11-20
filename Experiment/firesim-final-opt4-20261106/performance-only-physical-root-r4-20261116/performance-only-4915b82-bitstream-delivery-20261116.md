# Performance-Only 4915b82 bitstream delivery

SSI_SpreadSLLs 完成合法布线及严格物理时序签核，2026-11-16 22:19（北京时间）write_bitstream 成功。此镜像为 EC Performance-Only BJL＋四路 result CDC Mem，不代表完整 PALIMPSEST。

| 指标 | 最终 routed 结果 |
|---|---:|
| WNS / TNS | +0.013 / 0 ns |
| WHS / THS | +0.010 / 0 ns |
| Setup / hold 失败端点 | 0 / 0 |
| 可布线 / 已完整布线网络 | 1,131,319 / 1,131,319 |
| Routing errors / 未布线 / 部分布线 / 重叠 | 0 / 0 / 0 / 0 |
| DDR 3.332 ns WNS / WHS | +0.013 / +0.010 ns |
| Host/Target、FTQ→trace、跨 SLR 负 hold 路径 | 0 |
| LUT / FF | 814,600 / 448,531 |
| BRAM / URAM / DSP | 698.5 / 0 / 115 |
| SLR0 / SLR1 / SLR2 CLB 占用 | 85.65% / 93.59% / 96.46% |
| Bus-skew 最差 slack | +2.797 ns |

合法性依据：全部 routable nets 均为 fully routed，routing errors=0，router verification 成功，路由日志明确列出 failed/unrouted/partially routed/node overlaps 均为 0。Vivado 在正式 route status 中省略部分零值分类行；原 JSON 的 null 字段原样保留。

初次与最终全量负 hold 提取均为 0。路由器 Phase 6 内置 hold fixing 已完成收敛，无需额外 RTL、流水级或约束调整。Host 周期 99.960 ns、DDR 周期 3.332 ns、实际时钟拓扑、精确 clock-group 例外、时钟覆盖和 bus-skew 均通过既定检查。DRC 和 methodology 的 Error/Critical Warning 均为 0；原报告保留 281 和 4,814 条普通 Warning。

Bitstream：[firesim.bit](/data1/gzh/EC/firesim/final-opt4-20261106/runtime/Opt4-performance-only-4915b82-physical-r3/firesim.bit)，70,974,619 字节。

SHA-256：`1617d53ae39b5c4d700dc24de04a055391d163678d6ac7f989d3ba52b1cd1154`。

物理证书：[certified-build.json](/data1/gzh/EC/firesim/final-opt4-20261106/runtime/Opt4-performance-only-4915b82-physical-r3/certified-build.json)。完整 checkpoint、报告和日志：`/var/tmp/guozh-ec-rtl-timing-r2-20261115/physical-r3-20261116/implementation/candidates/bjl-result-cdc-10mhz-ssi_spreadslls`。

## 21-only 上板阻断与恢复

自动交接已完成物理证书及镜像哈希核验；管理员执行入口返回 `sudo: a password is required`，因此未执行 FPGA 操作，上板和运行功能验证尚未完成。错误原文：`/var/tmp/guozh-ec-rtl-timing-r2-20261115/physical-r3-20261116/deployment21-command.log`。handoff 状态已准确记录为 CARD21_DEPLOYMENT_FAILED_WITH_EVIDENCE。

在可认证终端完成 sudo 认证后，用原有交接程序恢复；它会再次核对镜像/证据、获取两把 CAD 锁、确认无 Vivado、获取卡维护锁并执行既定 21-only 检查。仅针对 0000:21:00.0 / 21770433G02LA，不执行全局 XDMA 操作。

```sh
sudo -v
env -u PYTHONHOME -u PYTHONPATH -u LD_LIBRARY_PATH -u LD_PRELOAD /usr/bin/python3 -I /data1/gzh/EC/firesim/final-opt4-20261106/Opt4-performance-only-rtl-timing-r2-20261115/candidates/rtl-timing-physical-r3-20261116/after-physical.py
```

当前 Vivado 已正常退出，两把 CAD 锁已释放。诊断、模块综合和后续组合实现队列均因当前镜像成功而跳过。未恢复周期巡检，已验证的其他成果保留。
