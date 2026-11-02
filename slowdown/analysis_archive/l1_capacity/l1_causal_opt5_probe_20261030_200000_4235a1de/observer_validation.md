# Observer / correctness 独立状态

|验证项|A|B|
|---|---|---|
|软件完成/benchmark|PASS，verified1/checksum43439728|FAIL，未完成，exit1|
|运行时断言|无|checker3 ownership assert24|
|ROI marker|712114/2419977，均lookup_valid1|只有start698301，lookup_valid1；stop缺失|
|Native causal/ROI/occupancy/hist/overlap守恒|PASS|UNAVAILABLE，无final JSON|
|Integrity ledger|全程PASS：406=391completed+12coalesced+3discarded|已记录prefix PASS：149=53completed+94discarded+2invalidated；非完整run认证|
|Protocol/mandatory capture/end accounting|PASS|INCOMPLETE，abort后无producer footer；非证明每个所报footer缺失都是独立RTL bug|
|L1 S0|PASS|UNVALIDATED，无final summary|
|L2 read-consistent snapshot/key/S0|PASS，snapshot_errors0/key_errors0|UNVALIDATED，无final summary；没有观察到L2 mismatch报警|
|STOP40–45|PASS|UNAVAILABLE，未到STOP|

A L2 read snapshots42,225；latest accepted镜像的temporal disagreements40,220是已区分的诊断，
read-consistent snapshot独立比较PASS，不能把它当RTL损坏。
本次B失败来自已有ownership watchdog，不能以放宽observer或关闭断言消除。
完整的B功能数据正确性和observer都没有闭合，禁止性能解读。

实际执行参数/二进制hash、source/tool/software seal、生成配置和native source copy检查PASS。
validation中`same_l2_geometry=false`是B缺少动态最终geometry，**不是**生成的L2配置变了；
generated_configuration_audit证明两组L2 JSON和clock摘要byte-identical。

详见[runtime失败](r2_B_correctness_failure.md)与[结构化gate](validation_result.json)。
