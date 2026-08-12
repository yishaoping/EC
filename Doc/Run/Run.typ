
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

我想对store_uncache做检测延迟的统计；对L1到L2的写回，L2到DRAM的写回做更详细的分类统计和延迟统计。利用大小核心中csr中的时钟为建立严格的时间戳。将大核和小核各自store_uncache统计时的时钟数总和利用rocc指令读出之后分别利用各自频率转为时间并打印，利用四个小核心的时间和减去大核心时间，再除以平均，给出每个store_uncache大致的延迟。对于两种写回中的脏写回也做类似的工作，分类中额外再分出脏写回并且未校验的，采用类似的方法统计脏写回并且未校验的大致平均延迟。先不修改代码，分析我所给方法的合理性，列出潜在问题。

先修改store_uncache延迟统计部分相关软硬件。大核求时钟和所用时钟数从大核csr中引出，注意与store_uncache的统计信号时间点做匹配。小核求时钟和所用时钟数从小核csr中引出，时间点应为store_uncache所在包全部校验结束。五个总和最后由GHE读出，由软件转为时间后打印，再计算延迟打印。
