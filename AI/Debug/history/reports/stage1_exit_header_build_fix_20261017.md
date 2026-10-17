# Stage 1 simulator 头文件依赖修复（2026-10-17）

用户新 build `AI/TMP/stage1_closure_build_e0hlkAyW/build.log:1024` 在 simulator C++ 编译阶段失败：生成目录的 `emulator.cc:24` 报 `stage1_exit.h file not found`。随后的 `emulator.o Error 1` 与顶层 `Error 2` 是同一错误的传播；未进入本次 simulation。

根因已确认：头文件存在于正式资源目录，但 `chipyard/sims/verilator/Makefile` 的 `SIM_FILE_REQS` 只列出 emulator.cc 和其他 support 文件，漏列 stage1_exit.h；真实日志的复制清单及 sim_files.f 均没有该头文件，编译器仅搜索 gen-collateral 等既定目录。上一轮 preflight 验证了 helper 本体，遗漏了其构建复制链路，原运行准入记录不能覆盖这次实际 build 失败。

修复仅在 `SIM_FILE_REQS` 增加 `$(CHIPYARD_RSRCS_DIR)/csrc/stage1_exit.h` 一行。它复用原有逐文件复制及 prerequisite 规则，进入 gen-collateral 和 filelist；emulator 的相对 include 可正常解析。没有修改 accounting、exit predicate、硬件逻辑、analyzer、workload 或 wrapper。

验证证据保留于 `AI/TMP/stage1_exit_header_fix_dgopfbpr/`，包括修复前源码/hash、失败日志 hash、隔离 Makefile fixture、before/after staging 日志及 `staging_validation.json`。fixture 直接提取正式 Makefile 的支持文件列表和复制/filelist 规则，只执行文件 staging，不 include 工程构建规则：

- 修复前：header_copied=false、header_in_filelist=false，独立 host C++ 预处理退出 1，复现找不到头文件。
- 修复后：两项均 true，复制内容与源文件逐字一致，预处理退出 0。
- 现有 32 项 Stage 1 离线测试及 `git diff --check` PASS。

本轮没有运行硬件编译、Scala、elaboration、FIRRTL、Verilator 或 simulation，没有修改旧 build/generated 证据。完整 simulator build 与动态验证仍待执行，`STAGE1_STATUS=PATCHED_PENDING_FINAL_VALIDATION`。按原入口重新运行即可；默认会建立新目录并重新采集来源身份，旧失败 build 保留：

```bash
cd /data1/gzh/EC
/data1/gzh/EC/AI/Debug/scripts/stage1_build_and_run.sh
```
