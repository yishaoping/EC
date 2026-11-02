# EC
纠错代码纪要

## 历史检错实现

[`check/`](check/README.md) 保存固定在 `b3d7adddd1e2d2cf428dd933529de878226420cd`
的历史检错版源码、配套软件及实验记录。其 `v1Config` 启用 GHE、1 个 BOOM 主核和
4 个 Rocket checker 核。该目录原名 `baseline/`，于 2026-11-02 改名；旧名保留为
指向 `check/` 的兼容符号链接，供未改写的历史 manifest、构建路径和 Opt4 封存校验使用。
当前稳定 Opt4 的入口与状态见 [`slowdown/`](slowdown/README.md)。

## Nix 仿真编译环境

根目录的 `flake.nix` 提供了由 Clang 16 编译的 Verilator 5.048，并复用
`chipyard/.conda-env` 中现有的 RISC-V/Scala 工具链。

```bash
nix develop path:.
cd chipyard/sims/verilator
make -j64 CONFIG=v1Config run-binary-debug-hex \
  BINARY=../../../Software/Test/test.riscv
```

环境中的 `verilator` 会优先于 Conda 里的旧版本，且生成模型、DRAMSim2 等
C/C++ 编译步骤会使用 Clang。

当前用户的 bash/zsh 启动脚本已配置为自动激活并显示 `(EC)`。首次使用时如未生成缓存，启动脚本会自动调用 `ec-refresh-env.sh`。环境更新后可执行 `./ec-refresh-env.sh` 重新生成缓存，手动进入环境则执行 `source ./ec-env.sh`。
