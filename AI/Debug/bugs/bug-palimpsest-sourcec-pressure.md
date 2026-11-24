# PALIMPSEST History 压力与 Checker 脏 victim 写回

旧正常配置在 BOOM 的 `little core 1 has hung` 断言退出。该断言表明 Checker 长时间持有包。旧模拟器的窄信号探针进一步捕获到 L2 的另一个真实停顿。History 抵达保留容量后，bank 为 Seq1 开启封口，并请求所有脏 victim 停在 SourceC 前。已有 BASE 脏 victim 也无法发射。旧模型的 `InclusiveCache.barrierAllow` 使用 `barrierBlocksOuter`，该位来自 bank 级 `validationBlock`，其中包含任意地址的 History 压力。输入、原生模型和探针哈希保存在同一运行目录。探针按 Verilator context 的时间计数记录，以下没有将它换算成各域的本地 cycle。

| Context 时间 | 旧模型实测 |
|---|---|
| 68152–68192 | L2 普通 MSHR 1 处理 AcquireBlock。victim 为脏，版本 Seq0，Probe 终态到齐后 C schedule valid 拉高。 |
| 68352 | History 空闲数从 5 降到 4。Seq1 的 `barrierActive/barrierBlocksOuter` 拉高。 |
| 68752–125000 | Checker 1 的 `cached_grant_wait` 保持。MSHR 1 的 Release 没有发射，也没有 ReleaseAck。两边的等待持续到诊断运行的上限。 |

直接阻塞和上游压力触发已在旧模型中观察。该轨迹支持 Checker 的网络前进受限，最终完整 workload 的收敛由修订版整核回归判定。

现行 `InclusiveCache` 屏障向 Main 发送存活、未验证的 Seq。 `Scheduler.stage3Allowed` 按实际 victim 的安全、原有发布顺序与 set owner 准入 SourceC。在已有同址收据可用时，旧行仍按原规则结束权限事务。此次修改移除全 bank 的门控和状态位。

定向对照使用同一份 `pressure_test.cpp`。以 `cold_gap06` 的生成 Stage3Harness 为基础，另制一个在压力时禁止 dirty C 的对照模型。两组均通过满 64 项、四拍 Probe、停车和 Checker 逃生用例。对照组在下一用例中收到 Checker Acquire，却未发出安全 BASE victim 的 C，在 3000 拍窗口后失败。开放组在 SW=0、压力仍高时发出 C、收到匹配 ReleaseAck，外存仅提交一次 `0x80041000` 的内容，随后收到 Checker Grant。进程分别以 1 和 0 退出。

- [旧整核断言](../../TMP/singlecore_rtl_20261121_171154/amo_rtl_v1Config_fastlink_compact/run.log#L796990) 与 [窄信号探针](../../TMP/singlecore_rtl_20261121_171154/amo_normal_state02/stderr.log)
- [压力用例 PASS](../../TMP/singlecore_rtl_20261121_171154/pressure_sourcec_diff05/eligible/run.log#L965) 与 [故意恢复门控的对照组](../../TMP/singlecore_rtl_20261121_171154/pressure_sourcec_diff05/blocked/run.log)
- [压力激励](../scripts/rollback/pressure_test.cpp) 与 [源码对应的验证状态](../../Design/SingleCore_RTL_Baseline/Verification_Matrix.md)
