#!/usr/bin/env bash

source_file="Null"
clean_files="Null"
object_file="Null"
malloc_flag="Null"
null="Null"
perf_mode="${MEEK_PERF_MODE:-checker}"

# Input flags
while getopts c:r:o:m:p: flag
do
	case "${flag}" in
		o) object_file=${OPTARG};;
		c) source_file=${OPTARG};;
		m) malloc_flag=${OPTARG};;
		p) perf_mode=${OPTARG};;
		r) clean_files=${OPTARG};;
	esac
done

case "$perf_mode" in
	checker)
		perf_flags=(-DMEEK_ENABLE_BIG_CORE_PERF=0 -DMEEK_ENABLE_CHECKER_SEGMENT_PERF=1)
		;;
	big)
		perf_flags=(-DMEEK_ENABLE_BIG_CORE_PERF=1 -DMEEK_ENABLE_CHECKER_SEGMENT_PERF=0)
		;;
	both)
		perf_flags=(-DMEEK_ENABLE_BIG_CORE_PERF=1 -DMEEK_ENABLE_CHECKER_SEGMENT_PERF=1)
		;;
	off)
		perf_flags=(-DMEEK_ENABLE_BIG_CORE_PERF=0 -DMEEK_ENABLE_CHECKER_SEGMENT_PERF=0)
		;;
	*)
		echo "error: invalid perf mode '$perf_mode' (expected checker, big, both, or off)" >&2
		exit 1
		;;
esac

echo ">> MEEK perf mode: $perf_mode"

if [[ $clean_files == "all" ]]; then
	rm -f *.o
	rm -f *.riscv
	rm -f *.dump
	echo ">>Jessica:  Removing generated files ";
fi


if [[ $source_file != $null ]]; then
	echo ">>Jessica:  Source FIle: $source_file.c";
	echo ">>Jessica:  ============================================ ";

	if [ -f "$source_file.o" ]; then
		rm $source_file.o
		echo ">>Jessica:  Removing $source_file.o ";
	fi

	if [ -f "$source_file.riscv" ]; then
		rm $source_file.riscv
		echo ">>Jessica:  Removing $source_file.riscv ";
	fi

	riscv64-unknown-elf-gcc -fno-common -fno-builtin-printf -specs=htif_nano.specs -march=rv64imafd -O2 "${perf_flags[@]}" -c $source_file.c tasks.c timer.c

	if [[ $malloc_flag != $null ]]; then
		riscv64-unknown-elf-gcc -fno-common -fno-builtin-printf -specs=htif_nano.specs -march=rv64imafd -static -Wl,--allow-multiple-definition -DUSE_PUBLIC_MALLOC_WRAPPERS ./malloc.o $source_file.o ./tasks.o -O2 -o $source_file.riscv
		# 生成二进制后立即反汇编
	    riscv64-unknown-elf-objdump -d -S $source_file.riscv > $source_file.dump
	    echo ">>Jessica:  Generating $source_file.riscv and $source_file.dump"
	fi

	if [[ $malloc_flag == $null ]]; then
		riscv64-unknown-elf-gcc -fno-common -fno-builtin-printf -specs=htif_nano.specs -march=rv64imafd -static -Wl,--allow-multiple-definition  $source_file.o ./tasks.o -O2 -o $source_file.riscv
		# 生成二进制后立即反汇编
	    riscv64-unknown-elf-objdump -d -S $source_file.riscv > $source_file.dump
	    echo ">>Jessica:  Generating $source_file.riscv and $source_file.dump"
	fi
	
	echo ">>Jessica:  Generating $source_file.riscv ";
fi

if [ $object_file != $null ]; then
	echo ">>Jessica:  Source FIle: $object_file.c";
	echo ">>Jessica:  ============================================ ";

	if [ -f "$object_file.o" ]; then
		rm $object_file.o
		echo ">>Jessica:  Removing $object_file.o ";
	fi

	riscv64-unknown-elf-gcc -fno-common -fno-builtin-printf -specs=htif_nano.specs -march=rv64imafd -DUSE_PUBLIC_MALLOC_WRAPPERS -O2 "${perf_flags[@]}" -c $object_file.c 
	echo ">>Jessica:  Generating $object_file.o ";
fi
