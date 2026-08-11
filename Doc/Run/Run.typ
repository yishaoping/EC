
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

仿照store和load的统计口径，传输方式等，修改软硬件代码，实现对于SC/LR的统计，注意区别成功和失败。

利用csr寄存器里面的事件值，统计
