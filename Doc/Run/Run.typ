
= EC
== BOOM
boom对于L1 Cache的所有写入都应该进行处理。
先统计

= Version
v0基础版本，感觉已经废了没有用了。

chipyard 1.9.0
= Command
source ./env.sh

make -j48 CONFIG=v1Config run-binary-debug-hex BINARY=../../../Software/Test/test.riscv
= Code
你是计算机架构领域的专家，我正在进行基于chipyard的开发，设计小核rocket校验大核boom的协同工作框架。不要做仿真和硬件生成。
/home/gzh/EC/chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.log中大核store和load次数相较于小核store和load次数和还有差距，说明硬件设置的计数方案有问题，分析原因，看看存在哪些多计漏计。
