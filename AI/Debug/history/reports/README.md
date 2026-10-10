# 原始报告导航（60份，含528000 implementation验证总结）

原文字节内容保留；每个报告的 current/path/line/window 都属于原调查。不要直接用旧命令对最新同名波形复现。逐文件来源见 ../../references/original_inventory.tsv，关联历史证据目录与 external archive。

- frontend/：1769000 spec、独立 review 与更早459000 redirect回归。
- snapshot-lsl/：ARF/PC边界、wrong-type dequeue、SyncReadMem head/read/deadlock。
- drain-count/：528000首坏、600/558/42计数和修复规格。
- cache-replay/：TtoN/meta-clear、strict token、killed S1 store/nack/STQ生命周期。
- ownership-address/：seq0/LSQ归属、safe水位相等、地址统计error0x10。
- barrier-statistics/：统计窗口、barrier close/session exit、性能比较口径。
- handoff-probes/：历史交接、FIRRTL/探针风险。
- legacy_ai/：早期BootROM/scoreboard、CDC anchor/result、trap、backpressure和统计口径；按标题/机制查找。

528000 verification-summary 原件在 ../evidence/528000/verification-summary.md；exact baseline/patch 在 ../evidence/528000/implementation/。
