# Stage 2 单命令入口与 denied A 回归补充（2026-10-17）

后续更新：按用户要求，当前 all 已移除重复 offline，改为 build→directed→system，仍保留所有 provenance/覆盖门禁；同时修复用户生成 OOM，见 [OOM 修复与当前流程](stage2_emit_oom_fix_20261017.md)。本文四阶段描述保留为原交付历史。

结论继续为 `PREFLIGHT_READY_PENDING_BUILD`。没有已知需要在构建前继续修复的阻塞；新增 RTL/fixture 与动态回归均待首次构建、运行，不把离线检查算作硬件正确。

## 一条命令

在原 Stage 1 环境终端中，从任意工作目录执行：

```bash
/data1/gzh/EC/AI/Debug/scripts/stage2_build_and_run.sh all
```

复用原 shell/Python 框架，没有另建验证框架。脚本按自身路径定位项目根，`all` 每次用 mkdtemp 创建唯一 `AI/TMP/stage2_validation_*/`，不复用继承的 `STAGE2_ROOT`，也不要求 cd/export 或手建目录。原分步入口继续保留。

严格串行 offline → build → directed → system；任一步失败或缺覆盖，后阶段未运行。源码（含未提交/未跟踪硬件文件）、参数、环境、工具、workload、fixture 副本、generated model 和 binary 的原有匹配与 provenance 条件全部保留。build 仍生成两个模型；directed/system 各一次仿真进程。

终端中文打印每阶段结果、总结果、失败阶段、具体原因/首个有意义错误、原始日志绝对路径和 summary.out 绝对路径。`runner.log` 保存完整入口输出，原工具/仿真完整日志分别保留；`commands.jsonl` 与阶段 status 保存原始和对外退出码。工具失败直接传播退出码；负的 signal return code 转为 128+信号，原值仍保留。覆盖不足返回 3/UNCOVERED；工具自身返回 3 记录 FAIL，不能误当覆盖不足。判据失败返回 1，使用/缺工具错误返回 2。旧阶段结果不覆盖、不自动重试；下次 all 自动建新 root。

全部通过的中文结论是“当前测试通过；不等于已证明所有硬件行为正确”。未运行、RUNNING/中断、FAIL、UNCOVERED 均不能算 PASS。

失败后先看终端指明的原始日志；`summary.out` 和 `runner.log` 同时保存失败阶段、原因、首个错误与路径。Scala/FIRRTL 是 module.emit.log，Verilator 是 module.lint.log/module.build.log，系统构建是 system.build.wrapper.log 及 system.build/build.log，定向是 module.trace.log/directed.coverage.json，整机是 system.run.wrapper.log 及 system.run/trace.log、各 scoreboard。

## denied A 的真实 RTL 回归

新增两个必须出现的 CASE：`denied_a_put_preserves_image`、`denied_a_amo_preserves_image`，将 directed 从 8 项扩为 10 项。仍在现有 Stage2Harness / VStage2Harness 中完成，没有新增构建入口或仿真进程。

fixture 实例化生产 **L2 MSHR → SourceD**；C++ 经 allocate、directory result、sinkd response 驱动，观察真实 schedule.fire、directory write request、bank write fire 与 D fire。先种入 BRANCH hit、非零完整 old ImageKey 与 provenance，等待实际 BtoT acquire，延迟 Grant，背压 schedule，再分别提供 denied 与成功响应。

独立判据由 C++ 保存的常量 old key/数据和请求操作数给出，不复制生产 `!bad_grant` predicate：

- denied Put/ADD：directory 与 D 上的完整 key 保持 old；packetSeq/tracked 保留；BRANCH/clean 保留；只有一次响应和一次 directory publication；**bank 零写**。
- 成功 Put：key 为全零 BASE，packet provenance 清除；恰好一次 bank 写、数据为 operand。
- 成功 ADD：同样创建 BASE，恰好一次 bank 写，数据为独立计算的 old+operand，返回 old。
- 两种操作在未收到外层响应或 schedule 背压期间，不得产生提前 directory/bank/D 事件。

四种操作/denial 组合各记录一次 `STAGE2_MSHR`；analyzer 要求完整事件集合和 10 个准确 CASE，无重复。CASE 名出现而实际回归事件缺失仍是 UNCOVERED。

真实模块的 directory 存储、SinkA/SinkD TL wire 解码、BankedStore 与跨模块互连未包括在新增子模块场景中，仍依赖整机验证。当前整机 workload/内存未承诺主动产生 denied；不能据整机 PASS 宣称出现了该路径。新增 fault injection 明确位于真实 MSHR 的 SinkDResponse 接口，验证的是该接口之后的生产状态机、metadata 和 SourceD 数据行为；动态结果尚未执行。

## 补覆盖时实际发现的两项相关问题

1. 旧 fixture 的 InclusiveCacheParameters.outer 复用 L1 的 CACHED manager，违反现有 `require(lastLevel)`。改用描述 UNCACHED terminal 的参数 edge，明确 mayDenyGet/mayDenyPut，不改生产 TL 参数。这是为真实 SourceD/MSHR fixture 必须修复的参数问题，实际类型/生成仍待 build。
2. 生产 SourceD 对 denied full Put 原先仅在 s3 将 opcode 改 Get，但 full Put 在 s1 已跳过 old-data read，因而不能靠 Get 保证写回旧字节。`s1_retires` 新增 `!s1_req.bad`，使 denied 操作不进入 bank retirement，也不成为 s2/s3/s4 的数据 bypass 来源。原 preflight 的 MSHR `!bad_grant` 身份修复保留；本补充让“保留旧身份”也对应不写新字节。新增 denied 零写和成功数据对照将直接检查该行为。

修改局限于现有 stage2 runner/wrapper/tests、fixture/driver、SourceD 的 denied retirement 条件及文档；所有本地 Stage 1/Stage 2 与用户改动保留。没有 reset、清理、提交、远端同步或修改 sources/。

## 本轮实际检查

最新证据：`AI/TMP/stage2_validation_53whknp_/`，从 `/tmp` 通过脚本绝对路径执行 **offline**，退出 0。

- 75 项纯离线单元测试（硬件 phase actions 全部替换；日志中的 synthetic BUILD/DIRECTED PASS 仅是 dispatch 测试数据）。
- Python AST、3 个 shell syntax、git diff --check。
- declaration-only C++ stub 的 `-fsyntax-only -Wall -Wextra -Werror`；没有模型生成、链接或执行，不能证明 generated port 类型正确。
- `all` 唯一 root、继承旧 root 不覆写、四个失败点串行停止、成功调度顺序、原始退出码、中文摘要、缺动态事件与重复事件门禁均有离线工具测试。

没有执行最终 all 命令，没有运行 build/elaboration/FIRRTL/Verilator 或任何仿真。构建后的 10 CASE、denied 回归和整机结果全部 `NOT_RUN`，建议用户现在手动启动上述单命令验证。
