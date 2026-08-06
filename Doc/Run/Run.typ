
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
你是计算机架构领域的专家，我正在进行基于chipyard的开发，设计小核rocket校验大核boom的协同工作框架。不要做仿真。现在/home/gzh/EC/chipyard/generators/boom/src/main/scala/lsu/dcache.scala和/home/gzh/EC/chipyard/generators/rocket-chip/src/main/scala/rocket/DCache.scala中关于store和load的六个计数器统计口径宽泛，应该只统计检查状态下的，这样才能确保大核和4个小核最后的统计结果相等，修改硬件代码实现这一点，做好中文注释。

