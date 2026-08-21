

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

我想对store_uncache做检测延迟的统计；对L1到L2的写回，L2到DRAM的写回做更详细的分类统计和延迟统计。利用大小核心中csr中的时钟为建立严格的时间戳。将大核和小核各自store_uncache统计时的时钟数总和利用rocc指令读出之后分别利用各自频率转为时间并打印，利用四个小核心的时间和减去大核心时间，再除以平均，给出每个store_uncache大致的延迟。对于两种写回中的脏写回也做类似的工作，分类中额外再分出脏写回并且未校验的，采用类似的方法统计脏写回并且未校验的大致平均延迟。先不修改代码，分析我所给方法的合理性，列出潜在问题。

先修改store_uncache延迟统计部分相关软硬件。大核求时钟和所用时钟数从大核csr中引出，注意与store_uncache的统计信号时间点做匹配。小核求时钟和所用时钟数从小核csr中引出，时间点应为store_uncache所在包全部校验结束。五个总和最后由GHE读出，由软件转为时间后打印，再计算延迟打印。

利用csr的时钟为缓存行和包提供时间戳，缓存行的时间戳以最后一次操作的时间为准，包的开头和结尾都需要时间戳。小核在检验完后将包尾时间戳返回到大核的dcache，表示当前校验位置。L1到L2的脏写回比较时间戳判断是否校验过，打印未校验脏行写回次数的新统计结果。并且采用与前文类似的方法，利用比较时返回的时间戳总和减去脏行时间戳总和计算延迟。
先不修改代码，分析我所给方法的合理性，列出潜在问题。

问题1，校验完成时间改为小核csr时钟提供，注意匹配。
问题2，偏差等暂不考虑。
问题3，采用位图方式维护完成表。
问题5，采用序号判断是否被校验，采用时间戳用于统计延迟。
问题6，应该限定为最后一次脏化操作。
问题7，确实需要提前所存。
问题8，未校验写回利用队列保存所需信息，确保统计正确性。
问题9，引入包序号。
问题10，需要进行配套操作。
问题11，技术范围应该明确为同一地址多次被换入换出计多次。
延迟只统计未校验脏写回的，新方法利用包序号判断是否被校验，并且通过位图进行维护，时间戳仅用于统计延迟，分析还有哪些问题。

问题3用包序号建立桶。
问题6，目前单大核，暂不考虑。
问题7，需要区分。
问题8，确实应该分开判断。
问题10，确实需要计数。
问题11，位图可以暂时先开大些，保证未完成包跨度小于位图宽度。
问题12，目前只做观测，不做阻塞。写回缓存行信息只是额外暂存。
问题13，统计数据确实应该改为小核测所给校验安全时间减去大核测写回时刻的时间。
目前序号用于是否被校验，校验完成时间由小核提供，校验安全时间由位图整理得到，写回时刻时间由csr提供，时间戳似乎不被需要了。分析看看还有哪些大问题，关于正确性的。

问题1，将完成校验时间调整为到达位图的时间，这样应该差距不大了，先暂时忽略吧，问题2应该也能顺带解决。
问题3，按照回答所给方案解决。
问题4，在软件上解决，跟非缓存store延迟差不多处理方法。
问题5，将序号伴随传递。
问题6，选择最大序号。
问题9，用新水位。
其他也按所给方案解决。先修改硬件软件代码，进行实现吧。

= Debug
你是计算机架构领域的专家，我正在进行基于chipyard的开发，设计小核rocket校验大核boom的协同工作框架，目前遇到了一些bug需要你帮我解决，要保障原有功能，不要做仿真和硬件生成。

结合软硬件代码和/data1/gzh/EC/chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd波形进行分析，目前在执行过程中不能正确推进。报错原因为：
`[1068000] %Error: BoomCore.sv:6736: Assertion failed in TOP.TestHarness.chiptop.system.tile_prci_domain.tile_reset_domain_boom_tile.core.assert__assert_22: 'assert' failed.
%Error: /data1/gzh/EC/chipyard/sims/verilator/generated-src/chipyard.TestHarness.v1Config/gen-collateral/BoomCore.sv:6736: Verilog $stop
Aborting...`

请你先分析出完整的信号逻辑链，在此基础上解决问题。在这个过程中可以供后续debug复用的文件放到/data1/gzh/EC/Debug下，方便重复利用。
