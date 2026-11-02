# L1 geometry 硬件成本与配置点

当前配置由`chipyard/generators/chipyard/src/main/scala/config/RocketConfigs.scala:v1Config`
选中`boom.common.WithNParaMedicBooms`，真实DCache参数在
`chipyard/generators/boom/src/main/scala/common/config-mixins.scala`：
`DCacheParams(rowBits=128,nSets=256,nWays=2,nMSHRs=6,nTLBWays=16)`。
本轮未修改任何geometry；后续若获GO，应通过这个配置链，不能在DCache RTL硬编码sets/ways。

以下P是实际物理地址宽度；只算raw tag位，不含ECC、权限、valid/dirty、EC resident/epoch/image-key等元数据。

|几何|Data SRAM|Lines|Index bits|Tag bits/line|总raw tag bits|并行tag比较器|hit mux|
|---|---:|---:|---:|---:|---:|---:|---|
|S0 32K/2way|32KiB|512|8|P−14|512(P−14)|2|2:1|
|S1 32K/4way|32KiB|512|7|P−13|512(P−13)|4|4:1|
|S2 64K/2way|64KiB|1,024|9|P−15|1,024(P−15)|2|2:1|
|S3 64K/4way|64KiB|1,024|8|P−14|1,024(P−14)|4|4:1|

## Ways 2→4

tag比较器数量×2；hit one-hot reduction、数据选择、way写掩码、广播负载增大。
way/victim索引1→2bits；同容量下data SRAM总位数不变，但阵列组织和mux不同。
S1 raw tag比S0多512bits。真实policy为`RandomReplacement`，
`rocket-chip/src/main/scala/util/Replacement.scala`定义16-bit全局LFSR；它不随ways变成LRU的per-set元数据。
不要虚构“replacement state翻倍”。相应way相关所有者/回放标识宽度仍需重新检查。
BOOM L1 hit敏感，4way的比较与mux可能拉长关键路径；没有综合、PPA或时序证据可给面积百分比/频率保证。

## Capacity 32→64KiB

data SRAM×2；line数与逐line EC元数据条目×2；S2 tag条目×2但每tag少1bit。
S2 index8→9bits、tag边界移动；每way阵列深度翻倍，decode/wordline/layout可能变化。
2way比较器数保持2，并不意味着hit时序不变或真实1-cycle access已获保证。
S3同时承担容量和ways两类成本，只比S2再避免123个shadow miss，缺少额外成本合理性。

## 验证边界

本轮只做7个观察修改文件的Scala typer检查，不是geometry合法性elaboration。
没有生成任何候选geometry、SRAM宏、coherence参数或地址索引RTL，也没有timing/layout检查。
若后续选择geometry，仍须在被授权的功能实验阶段核对SRAM形状、tag/index、MSHR/Probe/Release一致性、
preservation resident元数据尺寸、组合环与访问级数。当前不能声称已保持1-cycle物理访问。
