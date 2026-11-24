# 恢复 SFENCE 与迟到的 PTW 响应

BOOM 恢复 SCP 的特权状态时，Core 发出全量 SFENCE，经 Frontend 送到 I-TLB，经 LSU 送到 DTLB，并通过 Core 的 PTW 端口送到页表遍历器。旧的遍历可能已被接受，必须等它的响应释放请求槽。恢复后的访问必须重新遍历页表。

| 定向运行 | 证据 |
|---|---|
| 旧生产 DTLB | [run.log](../../TMP/singlecore_checker_20261122_082540/dtlb_before_direct_retry/run.log) 在第 7 拍首次读到旧物理地址 `0x80000000`。DTLB 已回到 idle，下一访问却命中。 |
| DTLB 已修复、旧生产 I-TLB | [run.log](../../TMP/singlecore_checker_20261122_082540/translation_before_itlb_v5/run.log) 在第 64 拍出现 I-TLB 同类命中。普通页和超页测试已经通过，非同质条目的迟到响应再填入旧映射。 |
| 两个生产 TLB 都修复 | [run.log](../../TMP/singlecore_checker_20261122_082540/translation_after_itlb_v5/run.log) exit 0。两个实例覆盖普通页、超页、非同质条目、SFENCE 与 walk 接受同拍、SFENCE 与响应同拍。旧 owner 在响应到来才清除，下一访问 miss 并从新遍历得到 `0x80200000`。 |

DTLB 原来在 `do_refill` 下写入全部三类条目。共享 Rocket TLB 原来仅在常规与超页条目写入后清有效位，非同质条目绕过该条件。两个模块现在直接以 `do_refill && !invalidate_refill` 控制写入，原有 `s_wait_invalidate` 记录正在等待的旧 walk。PTW 响应仍把状态送回 `s_ready`，且响应拍仍对查询报告 miss。Rocket TLB 的 GPA 副数据也使用相同的填充条件。该修改复用现有状态与 SFENCE，不增加寄存器、队列或 FSM。

夹具使用生产 BoomTile 参数和生产 TLB 实例，由 C++ 控制 PTW 接受与响应。日志中的 cycle 是夹具上升沿计数。两次 A/B 使用同一夹具与激励。各目录保存 `commands.json` 和 `inputs.sha256`。真实页表存储访存、PTW 的多级缓存、CSR 恢复和精确异常并发仍需独立验收。

```bash
PALIMPSEST_OUT="$out" PALIMPSEST_TESTS=TranslationRecovery PALIMPSEST_RUN=1 bash AI/Debug/scripts/rollback/user_build.sh
```

生产 PTW 还用其原有 `invalidated` 屏蔽全量 SFENCE 之后的 non-leaf 和 L2 TLB
填充，SFENCE 同拍对 valid 的清除在赋值顺序上优先。长期 `PtwRecovery` 在
`rtl_translation_v5_ptw/` 通过：迟到旧 walk 仍完成，之后真实根/中间/叶页表
读取新的映射；正常新 walk 的叶缓存命中和邻页 non-leaf 命中仍有效。还覆盖
leaf 返回与 L2 缓存填充拍的全量 fence。测试遵守 HellaCache s1_kill，取消的
投机请求不计入有效物理读取；初版 agent 因未区分它而 exit1，原记录保留。
该用例未修改生产 PTW，且不替代实际 CSR/LSU/异常整核联合验收。
