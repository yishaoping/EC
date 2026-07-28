#!/bin/bash
# =============================================================================
# @file    compile.sh
# @brief   GuardianCouncil 裸机测试的编译、链接和反汇编脚本
#
# @details 使用 Chipyard 配套 riscv64-unknown-elf 工具链，将入口文件与
#          checker、GHT 配置、CLINT、统计和混合负载模块静态链接，生成
#          HTIF 可加载的 .riscv ELF 以及带源码交叉引用的 .dump。
#
# @usage   ./compile.sh -c <源文件名(不含.c)> [-o <目标文件名>] [-r all]
#
# @options
#   -c <name>   指定入口源文件（不含 .c 后缀），并链接固定支持模块
#   -o <name>   额外把指定源文件单独编译为 .o
#   -r all      先清理生成物；因 source_file 默认是 test，随后仍会重建 test
#
# @example
#   ./compile.sh -c test             # 编译 test.c → test.riscv + test.dump
#   ./compile.sh -r all              # 清理后重新生成默认 test 产物
#
# @note   编译参数说明：
#   -fno-common         禁止将未初始化全局变量放入 common 段
#   -fno-builtin-printf 禁用内建 printf 优化
#   -specs=htif_nano.specs  使用 HTIF 链接脚本和精简 newlib
#   -march=rv64imafd    RISC-V 64位架构：整数+乘法+原子+单精度+双精度浮点
#   -O2                 优化级别 2
#   -static             静态链接
# =============================================================================

source_file="test"
clean_files=""
object_file=""
support_sources=(tasks.c timer.c clint.c gth_init.c test_runtime.c test_workload.c)
support_objects=(tasks.o timer.o clint.o gth_init.o test_runtime.o test_workload.o)

# 解析入口、清理和额外单文件编译选项。
while getopts c:r:o: flag
do
    case "${flag}" in
        o) object_file=${OPTARG};;     # 额外单文件目标
        c) source_file=${OPTARG};;     # 主入口文件名（无 .c）
        r) clean_files=${OPTARG};;     # 生成物清理模式
    esac
done

# 清理当前目录生成物；此分支不会清空默认 source_file。
if [[ $clean_files == "all" ]]; then
    rm -f *.o *.riscv *.dump
    echo ">> Removing generated files"
fi

# 完整构建：分别编译入口和支持模块，静态链接后生成反汇编。
if [[ -n $source_file ]]; then
    echo ">> Source FIle: $source_file.c"
    echo ">> ============================================"

    rm -f "$source_file.o" "$source_file.riscv"

    # htif_nano.specs 同时选择 medany 代码模型和 HTIF 裸机运行时。
    riscv64-unknown-elf-gcc -fno-common -fno-builtin-printf \
        -specs=htif_nano.specs -march=rv64imafd -O2 \
        -c "$source_file.c" "${support_sources[@]}"

    # ght.h/timer.h 含历史外部定义，现有工程用 allow-multiple-definition 兼容。
    riscv64-unknown-elf-gcc -fno-common -fno-builtin-printf \
        -specs=htif_nano.specs -march=rv64imafd -static \
        -Wl,--allow-multiple-definition \
        "$source_file.o" "${support_objects[@]}" -O2 \
        -o "$source_file.riscv"

    # -d -S 生成机器指令与 C 源码交叉显示，便于核对自定义指令编码。
    riscv64-unknown-elf-objdump -d -S "$source_file.riscv" > "$source_file.dump"

    # 最终目录只保留可执行文件和 dump，不保留完整构建的中间对象。
    rm -f "$source_file.o" "${support_objects[@]}"
    echo ">> Generating $source_file.riscv and $source_file.dump"
fi

# 可选的额外单文件编译；它与上面的默认完整构建可在一次调用中同时发生。
if [[ -n $object_file ]]; then
    echo ">> Source FIle: $object_file.c"
    echo ">> ============================================"

    rm -f $object_file.o

    riscv64-unknown-elf-gcc -fno-common -fno-builtin-printf \
        -specs=htif_nano.specs -march=rv64imafd -O2 \
        -c $object_file.c
    echo ">> Generating $object_file.o"
fi
