

chipyard 1.9.0
= Software
Software/Test 统一提供公共初始化、Checker、中断处理及 HTIF 构建规则。
Software/EC-Test 只存放综合功能测试；Software/GAPBS 只存放 benchmark 实现。

默认构建 EC-Test：
make -C /data1/gzh/EC/Software/Test

切换至 GAPBS：
make -C /data1/gzh/EC/Software/Test BENCHMARK=GAPBS

切回 EC-Test：
make -C /data1/gzh/EC/Software/Test

统一产物为 Software/Test/test.riscv 和 test.dump。公共规则位于
Software/Test/htif.mk；具体 benchmark 包含该规则，不递归调用 Test 接口。

= Verilator
cd /data1/gzh/EC/chipyard/sims/verilator

== 日常高性能
make CONFIG=v1Config timeout_cycles=750000 EXTRA_SIM_FLAGS=+cycle-count \
  run-binary-fast-hex BINARY=../../../Software/Test/test.riscv

== FST 波形调试
make CONFIG=v1Config VERBOSE_FLAGS= timeout_cycles=750000 EXTRA_SIM_FLAGS=+cycle-count \
  run-binary-debug-hex BINARY=../../../Software/Test/test.riscv

== S8 故障注入
make CONFIG=PalimpsestFault8Config timeout_cycles=750000 \
  'EXTRA_SIM_FLAGS=+cycle-count +verbose' \
  run-binary-fast-hex BINARY=../../../Software/Test/test.riscv

== History 满容量压力，包含只读观测器
make CONFIG=Palimpsest12p5MHzHistoryPressureConfig timeout_cycles=2000000 \
  EXTRA_SIM_FLAGS=+cycle-count \
  run-binary-pressure-hex BINARY=../../../Software/Test/test.riscv

== Seq 强制重基
make CONFIG=PalimpsestSeqRebaseTestConfig timeout_cycles=1000000 \
  'EXTRA_SIM_FLAGS=+cycle-count +verbose' \
  run-binary-fast-hex BINARY=../../../Software/Test/test.riscv
