# 未来手动构建和成对运行说明

**本文件是未来操作说明，本轮未执行以下任何构建或运行命令。** 当前状态 `COMMON_BENCHMARK_READY_TO_BUILD`，尚无共同ELF/loadmem；它们的SHA256和最终PC不能预填。

## 先只构建共同软件一次

用户下一阶段手动执行，例如选一个尚不存在的输出名：

```bash
bash /data1/gzh/EC/baseline/build_common_benchmark.sh \
  --output /data1/gzh/EC/baseline/software_common_builds/paired_bfs512_01
```

[DIRECT_EVIDENCE] builder直接调用RISC-V GCC，不调用原始 `Software/Test/compile.sh`、make、SBT或硬件脚本；输出只能在 `baseline/software_common_builds/` 的新目录。GCC/汇编器/链接器使用主机只读、仅该输出目录可写的bwrap，TMP/HOME也位于其中；不下载、不运行目标ELF。

静态/后处理门禁：

1. 共用源码snapshot逐文件SHA256；既有libgloss archive、specs、encoding均为独立副本。
2. 固定18个layout契约项，包括timer stride64、AMO两word、BFS mutable arrays、HTIF和stack边界；原地址值来自旧ELF，不是猜测。
3. 最终 `common_roi_start/stop` 唯一且为rdcycle，记录实际PC；拒绝0x55/77/78/79/7b遗留读回和hart0 ROI地址范围内的0x76。
4. ELF64/RISC-V/静态entry、PT_LOAD范围与不重叠映射；从同一个ELF生成8192行、64byte/行、反序hex loadmem，base=0x80000000，总512KiB，与旧loader格式一致。
5. builder只在前述门禁通过后写 `workload.json`，其中绑定真实ELF/loadmem SHA256、build manifest SHA256、ROI PC、harts/workload/timer、PASS/failure patterns。任何失败均不得手写“通过”的descriptor替代。

[UNRESOLVED] 构建未执行，toolchain/isolator/链接脚本实际可用性未验证。首次构建还应人工复核 `test.dump/test.map/test.symbols`：共同函数内的AMO/BFS调用与原顺序、trap返回a0=mepc、checker control/release、timer读写、旧统计指令已删、无硬件版本分支。单靠layout gate不能证明所有动态路径正确。

## Baseline启动参数

成功构建并审阅后，唯一软件输入描述为：

`/data1/gzh/EC/baseline/software_common_builds/paired_bfs512_01/workload.json`

未来可先静态检查（本轮没运行）：

```bash
bash /data1/gzh/EC/baseline/start_baseline_experiment.sh --check \
  --workload /data1/gzh/EC/baseline/software_common_builds/paired_bfs512_01/workload.json
```

然后在另外授权的阶段使用已经独立验证成功的b3硬件build目录；不要把以下模板中的变量当成已存在产物：

```bash
: "${VERIFIED_BASELINE_BUILD:?set the successful isolated b3 build directory}"
: "${REVIEWED_MAX_CYCLES:?set a reviewed smoke timeout, not a performance correction}"
bash /data1/gzh/EC/baseline/start_baseline_experiment.sh \
  --run "$VERIFIED_BASELINE_BUILD" \
  --workload /data1/gzh/EC/baseline/software_common_builds/paired_bfs512_01/workload.json \
  --max-cycles "$REVIEWED_MAX_CYCLES" --seed 1
```

[DIRECT_EVIDENCE] 没有另造START/STOP/interval/drain CLI。它们由共同软件和descriptor明确声明，不能通过环境变量猜测或硬编码旧PC。schema2 launcher校验软件/build manifest/contract身份，snapshot相同文件，明确输出 `ROI_CYCLES` 与辅助 `HARNESS_CYCLES_AUXILIARY_ONLY`。

[UNRESOLVED] 合理smoke超时尚无新共用软件运行依据，所以不把原默认500M包装为审定的smoke预算。这里也不提供自动硬件构建/仿真串联命令。

## Current使用同一软件

[STATIC_INFERENCE] 不需要修改Current源码。必须选择身份已闭合、参数已核对的Current simulator；本轮未确认一个可用的具体Current simulator路径，**不能从目录命名默认它就是匹配模型**。

其未来手动命令结构如下，ELF/loadmem必须与上面的descriptor同哈希。`CURRENT_SIMULATOR`、DRAM ini、配置、工具链/库环境和超时由该simulator的真实manifest提供，不是从b3推定：

```bash
# Future template only; run directory must be new, under baseline/runs/.
: "${CURRENT_SIMULATOR:?set verified absolute Current simulator path}"
: "${CURRENT_DRAMSIM_INI:?set the matching DRAM configuration directory}"
: "${CURRENT_RUN_DIRECTORY:?set a NEW directory under /data1/gzh/EC/baseline/runs/}"
: "${REVIEWED_MAX_CYCLES:?set reviewed timeout}"
# Create this new run directory and its tmp/inputs/ in that later phase.
# Snapshot the ELF/loadmem/build manifest and verify hashes before invocation.
/usr/bin/bwrap --die-with-parent --new-session --unshare-all \
  --ro-bind / / --bind "$CURRENT_RUN_DIRECTORY" "$CURRENT_RUN_DIRECTORY" \
  --proc /proc --dev /dev --chdir "$CURRENT_RUN_DIRECTORY" \
  --setenv TMPDIR "$CURRENT_RUN_DIRECTORY/tmp" \
  --setenv TMP "$CURRENT_RUN_DIRECTORY/tmp" \
  --setenv TEMP "$CURRENT_RUN_DIRECTORY/tmp" \
  -- "$CURRENT_SIMULATOR" \
  -v "$CURRENT_RUN_DIRECTORY/trace.fst" -s 1 \
  +cycle-count +verbose +permissive +dramsim \
  "+dramsim_ini_dir=$CURRENT_DRAMSIM_INI" \
  "+max-cycles=$REVIEWED_MAX_CYCLES" \
  "+loadmem=$CURRENT_RUN_DIRECTORY/inputs/test.loadmem_hex" \
  +loadmem_addr=80000000 +permissive-off \
  "$CURRENT_RUN_DIRECTORY/inputs/test.riscv"
```

这只是尚待匹配Current manifest的命令说明，不是本轮执行或对某个既有simulator可用性的认证。其stdout/stderr应保存至同一新目录；不得使用Current工程目录作为cwd或临时文件目录。正式执行前还需给该模板补上与已验证模型匹配的环境，并完整记录命令、软件/模型/simulator哈希。

两版原始日志都使用 `baseline/common_benchmark_contract.py` 的相同pattern和parser；Current外围采集必须要求同样的process exit、四个PASS markers、唯一ROI/唯一result及无ERROR/FAIL，不能只grep到一行cycles就接受。两版parent_checksum和全部result字段必须一致。Current的harness drain开关及生成宏身份另记；不加入ROI差值。

## 确定配置与未确定项

| 字段 | 共用定义/值 | 当前状态 |
|---|---|---|
| ELF/loadmem | 一次build目录内 `test.riscv/test.loadmem_hex` | UNRESOLVED_NOT_BUILT；不使用旧f5f84a17...哈希替代 |
| 软件来源 | N独立副本，逐文件来源/哈希见source_manifest.json | DIRECT_EVIDENCE |
| START/STOP | hart0两个命名rdcycle，实际PC构建后生成 | STATIC_INFERENCE / PC未生成 |
| ROI scope | AMO.W+BFS512+checking STOP/26NOP loop/GHT completion | DIRECT_EVIDENCE源码定义 |
| interval | NOT_USED；没有0x79请求 | DIRECT_EVIDENCE |
| timer | harts0..3、stride64、limit50、delta32 CLINT ticks | DIRECT_EVIDENCE |
| workload/input | BFS512固定内置图，source0，degree16，alpha15/beta18，无外部文件；保留AMO自测 | DIRECT_EVIDENCE |
| exit | 四checker软件ready、真实计算self-check/ROI检查，main返回0或1，finite HTIF exit | DIRECT_EVIDENCE / runtime未验证 |
| cache/package/L2/DRAM drain | 不作为软件共同PASS的伪造前提；两边原harness行为各自记录 | UNRESOLVED完整drain；ROI之外 |
| R-Kernel | 不需要，已有libgloss+HTIF静态runtime | STATIC_INFERENCE |
| max cycles | 必须显式审定，不决定ROI数值 | UNRESOLVED |
| 硬件及运行identity | baseline revision固定；两版最终build/simulator/命令/运行正确性分别闭合 | RUN_PROVENANCE=UNRESOLVED |
