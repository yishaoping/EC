

chipyard 1.9.0


= Verilator
cd /data1/gzh/EC/chipyard/sims/verilator

== 日常高性能
make CONFIG=v1Config EXTRA_SIM_FLAGS=+cycle-count \
  run-binary-fast-hex BINARY=../../../Software/Test/test.riscv

== FST 波形调试
```
make CONFIG=v1Config VERBOSE_FLAGS= \
  'WAVEFORM_FLAG=-v$(sim_out_name).fst' \
  EXTRA_SIM_FLAGS=+cycle-count \
  run-binary-debug-hex BINARY=../../../Software/Test/test.riscv
```
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
