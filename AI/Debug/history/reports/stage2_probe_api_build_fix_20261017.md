# Stage 2 fixture Probe API 编译错误修复（2026-10-17）

用户构建 `AI/TMP/stage2_validation_llhv_oen/` 在 `module.emit.log` 的 Scala compile 阶段失败，exit 1；唯一编译错误为 fixture `Stage2Generate.scala:142` 的 `TLMessages.ProbeBlock` 不存在。directed/system 未运行，失败证据继续保留。

当前仓库 `rocket-chip/.../tilelink/Bundles.scala` 定义 `TLMessages.Probe = 6.U`，`TLEdgeIn.Probe` 也使用该成员。fixture 将 ProbeBlock 误写成其他 API 版本的名称；离线 C++ stub/Python/shell 检查不执行 Scala 类型检查，因此此前未捕获该错误。

最小修复：仅将正式 fixture 的 `TLMessages.ProbeBlock` 改为 `TLMessages.Probe`，不改失败 root 内副本或日志，不改生产 RTL、消息参数、provenance、退出和覆盖条件。

最新离线证据 `AI/TMP/stage2_validation_8h7j2vpe/`：offline exit 0，75 项离线测试、Python/shell/C++ declaration-stub syntax 与 diff 检查通过；额外 `probe_api_check.json` 将 fixture 引用的 TLMessages/TLPermissions/TLAtomics 名称与当前 Bundles.scala 定义核对，missing_after 全部为空；`fixture.fix.patch` 确认与失败副本相比恰好一行修改，并记录原日志/原副本/当前 fixture/API 的 SHA256。

本轮没有执行 sbt/Scala compile、硬件生成、elaboration、Verilator 或仿真。该具体符号错误已在源码修正，后续编译/生成和动态正确性仍待验证。用户重新执行原绝对路径 `stage2_build_and_run.sh all`，脚本会自动新建 root；不能改写旧失败状态或复用旧 fixture 副本。
