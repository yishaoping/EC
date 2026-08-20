# EC
纠错代码纪要

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
