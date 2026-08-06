
结合/home/gzh/EC/chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.vcd，/home/gzh/EC/Software/Test和硬件代码，不做仿真，分析问题。发现过程要可信的硬件信号和指令行为做支撑，便于我自己看波形图分析。

hart0从80000164:	f8ba                	sd	a4,112(sp)进入80000404:	001026f3          	frflags	a3后不断在附近重复。

hart1，3，4在
    80000fa8:	0100006f          	j	80000fb8 \<checker+0xcc>
    80000fac:	c200452b          	.word	0xc200452b
    80000fb0:	01857513          	andi	a0,a0,24
    80000fb4:	06e50863          	beq	a0,a4,80001024 \<checker+0x138>
    80000fb8:	0e00452b          	.word	0x0e00452b
循环中重复。

hart2在80000fb4:	06e50863          	beq	a0,a4,80001024 \<checker+0x138>后跳转到80001024:	c000002b          	.word	0xc000002b，随后又跳转到800003ac:	d0377753          	fcvt.s.lu	fa4,a4，之后一直在循环里。

似乎是大小核心之间没有正确同步？分析发生该现象原因。

= BOOM

arch_valid
commit_uops_0_debug_pc


checker_mode

= Rocket
wb


= AI
你是计算机架构领域的专家，我正在进行基于chipyard的开发，设计小核rocket校验大核boom的协同工作框架。


不允许自行启动仿真，不允许删减硬件功能，不允许删减软件代码对于硬件的测试。

请你结合/home/gzh/EC/chipyard下的硬件代码和相关配置，/home/gzh/EC/Software/test中的软件代码，/home/gzh/EC/chipyard/sims/verilator/output/chipyard.TestHarness.v0Config/test.vcd中的波形图，以及其他可能需要的文件帮我进行design和debug。不允许自行启动仿真，不允许删减硬件功能，不允许删减软件代码对于硬件的测试。

目前我从波形图的结果中观察到：
大核反复进入trap_entry，
小核1一直在0000000080000a8c <checker>:，
小核2一直在00000000800002a0 <loop267>:，
小核3一直在0000000080000a8c <checker>:，
小核4一直在0000000080000a8c <checker>:，

我怀疑系统应该在某处卡死了，帮我进行分析，若确有问题则指出原因。


按照上述方案修改，重新生成test.dump和test.riscv文件。


你是计算机架构领域的专家，我正在进行基于chipyard的开发，设计小核rocket校验大核boom的协同工作框架。希望通过小核重新执行大核的指令来避免大核出错。

