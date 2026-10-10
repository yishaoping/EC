# 259 包地址统计错误修复记录

## 修改内容

本次只修改源 Scala，不修改生成的 Verilog，也不运行仿真。

### 1. 地址统计水位边界

文件：`chipyard/generators/boom/src/main/scala/lsu/PackageAddressStats.scala`

`processMalformed` 从：

```scala
packetSeq <= safeWatermark
```

改为：

```scala
packetSeq < safeWatermark
```

原因是 checker 安全水位表示包结果已经安全，但 BOOM 仍可能提交同一包的尾部 LSQ 访问。事件序号等于安全水位时是合法的同包尾部事件；严格早于安全水位的事件仍然报 malformed。

### 2. 架构统计使用 LSQ 锁存归属

文件：`chipyard/generators/boom/src/main/scala/lsu/lsu.scala`

- LDQ/STQ 增加并初始化 `packet_seq`。
- 地址翻译阶段锁存 `io.core.active_packet_seq`。
- 地址统计事件使用对应 LDQ/STQ 项的 `packet_seq`，不再使用提交时的实时全局序列。
- 架构 load/store 统计资格使用 `traffic_scope_valid && packet_seq =/= 0`，不再要求提交当拍 `traffic_counting=1`。

这样 STOP 后才提交、但在窗口内已经获得有效包归属的 LSQ 项仍会计入，避免尾部统计丢失；窗口外且没有有效包序列的访问不会被计入。

## 保持不变

- checker 包分配、结果接受和 PASS 水位推进逻辑；
- `259/259/259` 包计数路径；
- 跨包屏障使用的 `safePacketWatermark`；
- strict store token、replay 和 STQ late-nack 防护；
- 零序列事件和真正早于安全水位的事件仍然触发错误。

## 验证

源码编译通过：

```sh
cd /data1/gzh/EC/chipyard
./.conda-env/bin/sbt -batch 'project boom' Compile/compile
```

静态检查通过：

```sh
/home/guozh/.codex/skills/ec-debug-analysis/scripts/check_debug_invariants.py /data1/gzh/EC
```

未生成 RTL，未运行仿真。下一次仿真重点检查：

```text
ADDRESS_STATS status=PASS valid=1 error=0
boom_arch == boom_strict == checker_sum
packages allocated == completed == passed == 259
```
