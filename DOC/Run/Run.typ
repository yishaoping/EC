

source ./env.sh

make -j32 CONFIG=v0Config run-binary-debug-hex BINARY=../../../Software/test/test.riscv
