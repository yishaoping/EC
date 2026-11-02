# 修复后的L2观察契约

实现状态：**源码修复与CPU fixtures、Scala类型检查PASS；动态S0 sanity尚未运行**。

1. Directory新增只读`observationRows/Set/Tag`。每way快照取自真实lookup的延迟RAM输出，
   用与functional lookup相同的`setQuash && bypass.way==i`覆盖pending-write数据。
2. Scheduler在每个demand event1之前，向input-only native DPI sink发送全部way的kind13快照。
   request address用Directory本身的delayed key；独立保留scheduler-delayed key作为audit。
   metadata/demand/snapshot都使用`restoreAddress(expandAddress(...))`。
3. host S0从snapshot的valid/tag独立求hit；actual.hit只用于另行统计比较。旧latest-write mirror保留，
   只统计`temporal_mirror_disagreements`，不再作L2 S0判定。
4. 每lookup要求全way齐全，拒绝重复frame/重复way/错误set/missing snapshot；
   key不一致计`lookup_key_errors`，结束残留open frame也使replay fail。
5. 输出schema2 replay完整性、snapshot数、错误数、A/C first-opcode和directory demand opcode分类。
   完整性要求snapshot_count==actual.access、snapshot_errors==0、lookup_key_errors==0。
6. analyzer在S0或read-consistency审计失败时，将所有L2 geometry delta/proxy置null；
   `shadow_validation_status`与SVB functional correctness独立。L1可单独sanity PASS。

修复没有更改functional directory hit、victim、ready/valid或TileLink路径。
7个硬件文件观察区逆变换与preimage逐字节一致；见`source_scope_audit.json`。
CPU fixture验证accepted-write/read-image时序反例、独立tag比较、缺失/重复/orphan snapshot、
key不一致、opcode分离、warm-state保留。没有执行硬件仿真。

下一次有功能优化的run须同时满足：S0 miss误差门槛、snapshot覆盖、key audit与流量守恒，
才允许讨论L2替代geometry；S0总数吻合仍不自动证明S1–S3的全部coherence counterfactual。
该数据不追溯覆盖旧run，旧run保持原样。
