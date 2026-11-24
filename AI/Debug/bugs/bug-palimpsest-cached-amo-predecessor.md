# 缓存 AMO 覆盖待验证的前驱

短整核诊断的 BOOM 在 PC `0x80000380` 发出 Seq2 的 `amoadd.d`，地址 `0x80007f90`。该行的两条 Seq1 写已经结清，驻留完整行的身份为 Seq1、serial 2。此时 SW 为 0，缓存 AMO 所需的前驱没有下层收据。AMO 被原先只接受 `M_XWR` 的 SVB 准入条件排除，进入 S2 的保存等待，无法到达 S3。见 [整核日志](../../TMP/singlecore_rtl_20261121_171154/compact_probe_previous_v1Config/run.log#L203393) 和 [输入哈希](../../TMP/singlecore_rtl_20261121_171154/compact_probe_previous_v1Config/run.inputs.sha256)。

| BOOM 周期（十六进制） | 实际事件 |
|---|---|
| `c1d1` | 同址 Seq1 字节写报告终态。 |
| `c1d9` | Seq2 AMO 遇到待验证前驱，保存请求得到本地描述符，SVB 没有获得快照。 |
| `c1da` | 旧行不安全，保守写回不能发出。 |
| `125e2` | PASS1 已到，保存发出安全写回。 |
| `1270c` | 精确收据和清理完成后重试原 AMO。 |

这次整核运行中，等待持续约 2.6 万拍，随后恢复执行。定向反例保持 Seq7 Pending，在同一行发 Seq8 的缓存 AMO。修复前等待期内既没有 SVB 快照也没有终态，测试在周期 36068 失败。定向生成物从修复前 Hierarchy 取得，激励单独记录哈希。见 [定向反例](../../TMP/singlecore_rtl_20261121_171154/hierarchy_amo_before/run.log#L541)、[生成时源码](../../TMP/singlecore_rtl_20261121_171154/evt_install01/sources.after.json) 和 [激励哈希](../../TMP/singlecore_rtl_20261121_171154/hierarchy_amo_before/fixtures.sha256)。

DCache 将缓存 AMO 纳入原 SVB 捕获资格。仍需同址较老的完整驻留行、空闲捕获描述符和可用 SVB 项。快照完成后，S2 和 S3 都按地址、way、epoch 和版本确认原 owner。ALU、原子写效应、终态和旧值响应复用现有路径。用例在 SW=6 时要求 Seq8 AMO 返回 `0xa1`，读回 `0xa3`，FAIL8 后再从真实 L1 读出 Seq7 整行和原邻字。运行状态见 [验证矩阵](../../Design/SingleCore_RTL_Baseline/Verification_Matrix.md)。
