CHIPYARD := $(abspath ../../chipyard)
RISCV ?= $(CHIPYARD)/.conda-env/riscv-tools
RISCV_TOOLS := $(RISCV)/bin/riscv64-unknown-elf-
GLOSS := $(CHIPYARD)/toolchains/libgloss
ENCODING := $(CHIPYARD)/toolchains/riscv-tools/riscv-pk/machine/encoding.h
RUNTIME := ../Test
OUTPUT_DIR ?= .build

RUNTIME_SOURCES := $(addprefix $(RUNTIME)/,hw/interrupt.c hw/spin_lock.c cfg/init.c \
	core/secondary.c core/checker.c stat/report.c)
HEADERS := $(wildcard $(RUNTIME)/*/*.h)

.PHONY: all
all: $(OUTPUT_DIR)/test.riscv $(OUTPUT_DIR)/test.dump

$(OUTPUT_DIR)/riscv-pk/encoding.h: $(ENCODING)
	mkdir -p $(@D)
	ln -sf $< $@

$(OUTPUT_DIR)/test.riscv: $(SOURCES) $(RUNTIME_SOURCES) $(HEADERS) $(BENCH_HEADERS) \
		Makefile $(RUNTIME)/htif.mk $(GLOSS)/util/htif_nano.specs \
		$(GLOSS)/util/htif.ld $(GLOSS)/build/libgloss_htif.a $(OUTPUT_DIR)/riscv-pk/encoding.h
	$(RISCV_TOOLS)gcc -march=rv64imafd -mabi=lp64d -O2 -fno-common -fno-builtin-printf \
		-specs=$(GLOSS)/util/htif_nano.specs -B$(GLOSS)/util/ -L$(GLOSS)/build \
		-I$(OUTPUT_DIR) -I$(RUNTIME) $(BENCH_FLAGS) $(SOURCES) $(RUNTIME_SOURCES) -o $@

$(OUTPUT_DIR)/test.dump: $(OUTPUT_DIR)/test.riscv
	cd $(OUTPUT_DIR) && $(RISCV_TOOLS)objdump -d -S test.riscv > test.dump
