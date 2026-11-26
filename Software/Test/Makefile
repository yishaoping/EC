BENCHMARK ?= GAPBS

.PHONY: all
all:
	$(MAKE) -C ../$(BENCHMARK) OUTPUT_DIR=.build .build/test.riscv
	cmp -s ../$(BENCHMARK)/.build/test.riscv test.riscv || cp ../$(BENCHMARK)/.build/test.riscv test.riscv
