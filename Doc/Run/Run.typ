

make -j64 CONFIG=v1Config VERILATOR_FST_MODE=1 VERILATOR_THREADS=8 NUMACTL=1 VERBOSE_FLAGS= EXTRA_SIM_FLAGS=+uart_tx=0 run-binary-debug-hex BINARY=../../../Software/Test/test.riscv

= 

= EC
== BOOM
boom对于L1 Cache的所有写入都应该进行处理。
先统计

= Version

chipyard 1.9.0
= Command
source ./env.sh

make -j64 CONFIG=v1Config run-binary-debug-hex BINARY=../../../Software/Test/test.riscv
make -j64 CONFIG=v1Config BREAK_SIM_PREREQ=1 run-binary-debug-hex BINARY=../../../Software/Test/test.riscv


= Code
你是计算机架构领域的专家，我正在进行基于chipyard的开发，设计小核rocket校验大核boom的协同工作框架。不要做仿真和硬件生成。

= Debug
你是计算机架构领域的专家，我正在进行基于chipyard的开发，设计小核rocket校验大核boom的协同工作框架，目前遇到了一些bug需要你帮我解决，要保障原有功能，不要做仿真和硬件生成。

参考/data1/gzh/EC/Debug内容，结合软硬件代码和/data1/gzh/EC/chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd波形进行分析。报错原因为：
`[1187000] %Error: BoomCore.sv:6764: Assertion failed in TOP.TestHarness.chiptop.system.tile_prci_domain.tile_reset_domain_boom_tile.core.assert__assert_24: 'assert' failed.
%Error: /data1/gzh/EC/chipyard/sims/verilator/generated-src/chipyard.TestHarness.v1Config/gen-collateral/BoomCore.sv:6764: Verilog $stop`

我知道是硬件断言错误，肯定是某些信号不对导致了计数超时之类的。请你注意原来的报错时间是1359000，时间发生倒退，说明上次修改造成了某些问题提前暴露。先分析出完整的信号逻辑链，同时尽量避免头痛医头，脚痛医脚，进行综合性地诊断。

在这个过程中可以供后续debug复用的文件放到/data1/gzh/EC/Debug下，方便重复利用。

= AI
== Codex
```
# 切到本地转发通道
bash /data1/gzh/EC/codex_switch.sh relay

# 切到直连通道
bash /data1/gzh/EC/codex_switch.sh direct

# 查看当前通道
bash /data1/gzh/EC/codex_switch.sh status
```
