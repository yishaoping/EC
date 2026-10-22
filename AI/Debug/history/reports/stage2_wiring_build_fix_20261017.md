# Stage 2 wiring 失败修复与批量错误报告（2026-10-17）

`PATCHED_PENDING_REBUILD`。当前已知的构建阻塞已在源码修正，可以由用户启动下一次新构建；没有运行本轮 Scala compile、硬件生成、elaboration、FIRRTL、Verilator 或仿真。

## 原失败与根因

原现场 `AI/TMP/stage2_validation_5iv7ungc/` 保留。module.emit.log 第 57 行 Scala compile 完成，第 60 行 `firrtl.FirrtlInternalException: Wrong number of sources or sinks!`，第 62 行进入 WiringTransform.execute；raw exit 1，生成目录为空，directed/system 未运行。上一处 Probe API 编译错误和 1G OOM 在这次运行中已消失；这不表示生成已经完成。

对本地 FIRRTL 1.5.5 jar 使用 javap 做静态检查，确认该错误来自有 source、零 sink 的分支，重复 source 则有另一条专用异常。fixture 只实例化 L1/SourceD/MSHR，没有实例化真实 TestHarness 和 InclusiveCache 的统计消费者。L1 的全部 97 个 bore 因而只有 source：统计 reset/enable 2 个、16 个 sideband slot × 4 字段、failure 与 failureSeq 2 个、safe watermark 1 个、Stage 1 cache observation 28 个。本轮按实际生产 source 和 fixture 逐名/宽度展开核对，修改前缺 97，修改后缺 0，多余 0，宽度不匹配 0；生产 dcache.scala hash 与失败 run 的输入清单一致。

## 修复与错误收集

- `scripts/stage2/Stage2Generate.scala` 一次补齐 97 个初始化的只读 sink，保留 dontTouch。没有补虚假的协议反馈，没有改真实 L1/L2 的保护逻辑，也没有为 fixture 伪造未实例化 LSU/STQ 的 source。
- 同文件新增观察用 `Stage2WiringAudit`，与真实 WiringTransform 使用相同的 MidForm 前置条件并显式先于它运行。检查全部 pin，列出所有缺失/重复 source/sink 及其模块目标，一次报告全部错误；不改 circuit/annotations、不删除错误。正常和失败清单均写入 `generated/stage2.wiring.out`。本地 jar API 已核对，使用显式 AnnotationSeq 和 toSeq，避免依赖 wildcard implicit 或引入同名类型冲突；新增 Scala 仍待真实编译。
- `scripts/stage2_validation.py`：生成成功除原 RTL/完成标记外，还必须有成功 wiring 报告，报告 hash 进入模型复用门禁。定向 Verilator lint/build 使用 `--error-limit 0`，参数与审计设置进入 inputs 指纹，不放宽 UNOPTFLAT、PINMISSING 或动态覆盖检查。
- 同次命令失败时收集原日志全部不同的错误/失败诊断，过滤堆栈和重复消息，保留原行号、上下文、出现次数、原返回码及原日志 hash。终端打印全部，持久化 `<log>.errors.out/json`；阶段 status 与 summary 记录数量和汇总路径。对于 sbt exit 0 + 后台异常同样生效，原日志不改写。

仍保留原 `all` 的唯一 root、build→directed→system 严格串行、输入/环境/产物/覆盖匹配、失败即停；不自动重跑 offline。批量报告覆盖本次工具能够发现的错误；前面一个必要变换失败时，无法声称后续变换或整机检查已经执行。

## 已检查与未验证

证据 `AI/TMP/stage2_wiring_fix_3nol05y4/`：`source_inventory.json` 是初次源码展开及修改前后缺失集合，`source_inventory.final.json` 绑定最终源码 hashes 并再次核对全部 97 个名称/宽度；`fixture.fix.final.patch` 是最终 fixture 相对失败副本的精确差异。原日志副本和重新提取的完整诊断均在新证据目录，且原现场四项关键文件 hashes 已再次核对未变。最终 48 项运行器单元测试通过，硬件动作全部替换，覆盖多错误收集、长堆栈不掩盖首部错误、wiring 多 pin 报告、上下文与 raw code 保存、摘要路径及 NOT_RUN、原串行与覆盖门禁。Python AST、wrapper shell syntax、diff 检查通过；最终记录见 `checks.json`。这些不等于硬件生成或动态验证通过。

当前修复和新增审计的真实 Scala 编译、transform 调度/annotation 更新、完整 RTL 初始化/组合环、Verilator 结构检查、C++ 生成端口匹配及全部定向/整机场景仍待运行。没有已知需要先继续修复的构建前阻塞。未修改 sources/ 或生产 RTL，未同步/reset/清理/提交，原 Stage 1/Stage 2 与用户改动保留。

下一步仍由用户执行 `/data1/gzh/EC/AI/Debug/scripts/stage2_build_and_run.sh all`。如再次失败，先看终端的错误汇总路径、同一 root 的 module.emit.log 与 generated/stage2.wiring.out，再看 summary.out；不要复用本次失败 root。
