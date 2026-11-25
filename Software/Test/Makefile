BENCHMARK ?= EC-Test

.PHONY: all
all:
	$(MAKE) -C ../$(BENCHMARK) OUTPUT_DIR=.build
	cmp -s ../$(BENCHMARK)/.build/test.riscv test.riscv || cp ../$(BENCHMARK)/.build/test.riscv test.riscv
	cmp -s ../$(BENCHMARK)/.build/test.dump test.dump || cp ../$(BENCHMARK)/.build/test.dump test.dump
