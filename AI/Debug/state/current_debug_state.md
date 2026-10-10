# Current Debug State

更新时间：2026-10-10（Asia/Shanghai）。本文件只描述当前有效状态；历史运行进入 `history/` 与 `bugs/`。

## 工作树身份

- 运行采集时的代码基线：`ba883dac9e9c50eca94a8a09ac8dd542457798cc`（同步时已从该未发布提交移除旧 Debug 生成物，映射见 `../references/git_sync.md`）。
- 本次整理及同步没有修改 Chipyard 正式功能代码；当前 HEAD/分支同步状态以 `git status --short --branch` 为准。
- 配置：`v1Config`，源码默认 `GH_REAL_BARRIER_ENABLED=true`，1 个 BOOM + 4 个 Rocket checker。
- 软件：`Software/Test/test.riscv` SHA256 `7d440cced710e16958d0121fcac377d57266c9c54a82845e2d5dc9a3a0a9c686`。

## 最新完整运行

权威输入：`chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/{test.log,test.out,test.vcd}`。`.vcd` 实际是 FST 容器；日志时间 2026-10-10 18:07:23 +08，FST 时间 18:07:25 +08；该运行的波形为 2,275,433,245 bytes（约 2.12 GiB），时间换算必须重新从生成 RTL 确认。

- 程序到达 `[END]`，但 `verified=0`，`parent_checksum=947892178`。
- `packages allocated/completed/passed = 291/291/291`，这只说明 package result 数量平衡。
- `boom_arch`：store 60491、load 84480。
- `boom_strict`：store 60491、load 84480。
- `checker_sum`：store 60655、load 84738；差值分别为 164、258。
- address stats、L1-L2、L2-DRAM 的本次打印结果不能替代 `verified=1`。

最新证据 manifest：[manifest.json](evidence/latest/manifest.json)；日志副本：[test.log](evidence/latest/test.log)；模拟器结尾：[completion_excerpt.txt](evidence/latest/completion_excerpt.txt)。独立 FST reader 验证范围 `0..9304241`。原 `test.out` 的 `*** PASSED *** Completed after 4652121 cycles` 与 `test.log` 功能 FAIL 同时存在：模拟器返回/退出条件与 benchmark correctness 必须分别判断。完整 output/FST 的独立备份已按用户要求删除；长期区保留日志、manifest 和窄证据，原仿真 output 路径可能被后续运行覆盖。

## 当前结论

**已证实的事实**：程序完成但功能校验失败；package 数量平衡；BOOM 与 checker 流量计数不一致。该日志没有提供最新运行的 first bad state、root cause 或修复通过证据。

**历史上已证实、需要先复核的机制**：528000 的旧 run 曾证明 R_IC 在 barrier close 后过早发布 `count=558/done`，而 BOOM 同一 seq 实际退休 600 条，造成 42 条尾部（5 条 store）留在 LSL；459000/461000 曾分别证明同步 FIFO head 生命周期、LSL 类型/地址匹配和 frontend redirect 生命周期存在独立问题。详见 `bugs/`。

**尚未验证**：最新 291-package 运行的 first bad / root cause；计数差值是否是同一首因；当前源码→生成 RTL→simulator→波形的完整对应关系（Frontend 源码和生成物 hash 与 10-10 review 第 6 节吻合，但仅此不能证明整机同版）；最新 barrier、LSL、snapshot、drain、strict-token 回归。

## 下一步

1. 保存当前运行的 manifest，不覆盖现有 output；确认生成 RTL、软件和 diff 身份。
2. 从最后一个 PASS package 开始，先找 BOOM commit、checker DATA/ARF/CPS/END、LSL fire 和 result/release 的 first divergence。
3. 分别检查旧 first-bad：empty-ROB next PC、LSL registered payload/type/address、barrier close drain count；旧问题若消失，再命名新首因。
4. 只在 root cause 与 broken invariant 已确认后写 Fix Design；随后依次做 Scala/Chisel 静态、elaboration/FIRRTL、RTL、定向仿真和整机 validation。
5. 更新本文件，并把已结束问题写入 `history/`/`bugs/`；中间 trace 放 `AI/TMP`。

## 状态维护规则

每次 `Root Cause → Fix Design → Implementation → Validation` 完成后，更新本文件；结论进入 bug/history；通用经验进入 skills/checks；脚本进入 scripts；大型输出只进 TMP。
