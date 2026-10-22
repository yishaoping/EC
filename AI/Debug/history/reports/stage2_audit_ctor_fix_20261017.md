# Stage 2 审计 transform 无参构造修复（2026-10-17）

`PATCHED_PENDING_REBUILD`。这是上一轮增加 `Stage2WiringAudit` 时引入的构造契约错误，已在正式 fixture 修正，未修改生产 RTL。没有已知需要先修复的构建前阻塞；本轮没有运行 Scala compile、硬件生成、elaboration、FIRRTL transform、Verilator 或仿真。

## 证据与根因

用户运行 `AI/TMP/stage2_validation_mzljfuss/` 的 module.emit.log 第 57 行显示 Scala compile 完成；第 60 行为 `DependencyManagerException: Failed to construct 'class stage2.Stage2WiringAudit'`；第 197 行 InstantiationException，第 335 行明确 `NoSuchMethodException: stage2.Stage2WiringAudit.<init>()`。工具返回 1，generated 为空，directed/system 未运行，尚未执行 wiring 审计，不能据此认为此前接收端修复已动态通过。

本地 FIRRTL 1.5.5 jar 的静态字节码核对确认完整链路：Compiler 将注册实例交给 `Dependency.fromTransform`；该方法只为 singleton 保留实例，普通 class 被转为类依赖；Dependency.getObject 经 safeConstruct 调用 Class.newInstance，要求公开无参构造器。用户本次已编译 class 的 javap 也显示仅有 `Stage2WiringAudit(java.lang.String)`。上一轮对“传入实例即可保存带参对象”的判断错误，造成当前阻塞；不是生产 L1/L2 连接再次出错。

## 实际修改

仅修改 `scripts/stage2/Stage2Generate.scala` 的 transform 构造、报告路径及注册处：

- 将审计类改为公开顶层无参类，移除构造器里的每次运行路径。
- execute 从 `state.annotations.toSeq` 提取当前 `TargetDirAnnotation`，以 File(targetDir, stage2.wiring.out) 写原路径。缺少该 annotation 明确失败，不回落到 cwd，不使用跨 run 的全局变量。
- EmitModule 在建立配置及 elaboration 前调用真实 `Dependency[Stage2WiringAudit].getObject`，提前执行相同的反射构造检查，再把所得对象注册给 RunFirrtlTransformAnnotation。即使之后框架重新构造，也满足相同无参契约。这项运行时检查并入原进程，没有增加硬件构建或仿真次数；本轮未执行。

保留全部 97 个只读 sink、MidForm/prerequisite 顺序、所有坏 pin 的批量报告、原 circuit/annotations 不修改、成功 wiring 报告/产物门禁，以及原 all 的 build→directed→system 严格串行、失败停止和跳过自动 offline。没有删掉审计来绕过异常。

## 本轮检查与边界

证据在 `AI/TMP/stage2_audit_ctor_fix_qxwo_iry/`。保存原日志副本、关键失败文件 hashes、精确 fixture 差异，以及 FIRRTL 工厂/构造/Compiler/TargetDirAnnotation 和用户旧审计 class 的 javap 输出。FIRRTL 自带 MustDeduplicateTransform 也从 CircuitState 的 TargetDirAnnotation 获取目录；Compiler 对普通 annotations 的传递已做静态核对。

轻量检查确认本轮差异仅改变上述构造与路径链路，全部硬件输入/输出、97 个 sink、审计 pin 判据及成功/失败标记与失败副本一致；公开顶层无参声明和提前调用顺序已检查。Python AST、shell syntax、diff 检查见 checks.json；没有重复运行完整 offline suite 或把源码/字节码检查称作运行时 PASS。原失败现场关键文件 hashes 再核对未变，生产 dcache 与用户 run 的输入 hashes 一致。

尚待用户新构建验证：当前 Scala 编译、反射构造、TargetDirAnnotation 的实际到达、审计调度与报告、完整 RTL/结构检查，以及定向/整机动态验证。当前准确入口仍为 `/data1/gzh/EC/AI/Debug/scripts/stage2_build_and_run.sh all`；失败查看新 root 的 module.emit.log.errors.out、module.emit.log 和 summary.out。原失败 root 不复用、不改写。
