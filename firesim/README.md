# 独立 FireSim 实验目录

本目录中的安装和运行入口独立于 `/data1/gzh/EC/chipyard/sims/firesim`。

- `upstream/`：FireSim 1.17.1，固定 commit `b473147af03edc854a5bc2a95d1bc404c8711b2a`。
- `envs/manager-1.17.1/`：独立 Python/Java/RISC-V 工具环境；为复用工具而克隆现有兼容环境，
  不把旧 FireSim 作为运行入口。已有工具环境没有被修改。
- `dac2026/`：配置、测量统计核心、批处理/保存/恢复/分析、综合脚本和中文手册。
- `conda-env/`：第一次离线克隆失败的残留，保留，不作为有效环境使用。

```bash
cd /data1/gzh/EC
source firesim/dac2026/env.sh
command -v firesim python3 riscv64-unknown-linux-gnu-gcc
firesim --help
python3 firesim/dac2026/dac.py --help
```

以上命令只加载环境和显示 CLI，不启动仿真或操作 FPGA。
主手册：[`dac2026/README.zh.md`](dac2026/README.zh.md)。
检查结论：`/data1/gzh/EC/Experiment/dac2026/preparation/STATUS-20261102.md`。
当前 EC 设计移植、测量接线和镜像仍有真实阻碍，不能直接开始正式实验。
