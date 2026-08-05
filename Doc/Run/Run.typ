
chipyard 1.9.0

source ./env.sh

make -j32 CONFIG=v0Config run-binary-debug-hex BINARY=../../../Software/test/test.riscv

make -j32 CONFIG=v1Config run-binary-debug-hex BINARY=../../../Software/Test/test.riscv

= EC
== BOOM
boom对于L1 Cache的所有写入都应该进行处理。
先统计

= Version
v0基础版本
