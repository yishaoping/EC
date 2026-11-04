# FireSim 构建与部署边界

当前 manager 和硬件树来自独立工作副本
`/data1/gzh/EC/firesim/dac2026/work/opt4-alveo-v3/{B,C4}/chipyard/sims/firesim`，
FireSim 1.17.0 `07efa6a6da18bd64d1159ae84a4701b37abb1228`，与各自 Chipyard 1.9.0
正常 library 集成，FIRESIM_STANDALONE unset。不可使用原 chipyard 的 bundled manager，
也不可用早期 `firesim/upstream` 1.17.1 取代本集成的 manager/GoldenGate/driver。

candidate YAML 仅给出 B/C4 实际配置类和 native U280 字段，不是已准入的 bitstream recipe。
须先完成 build_minimal.py 的 elaboration、GoldenGate 和 driver，绑定 result.json 及产物 hash；
再解决 Linux/checker、被动测量桥、FASED 运行时参数和安全部署 adapter。
FPGA host clock 与目标系统200/100MHz 是不同参数，未得到实现报告前不声称满足时序。

只允许纯构建；不调用 infrasetup/enumeratefpgas，不卸载/重载 XDMA，不烧写/复位/解绑/
重扫。两块卡可能已有任务，选中一张卡不能规避全局驱动影响。实际用户部署入口必须
说明目标 BDF 和影响范围并重新检查占用；无法证明安全隔离时退出。

完整工作流及状态见 `../../README.zh.md` 和
`/data1/gzh/EC/Experiment/dac2026/preparation/opt4-alveo-v3/`。
