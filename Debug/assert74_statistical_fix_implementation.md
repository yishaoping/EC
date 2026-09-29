# Assert 74 统计修复实现记录

本次按 `assert74_statistical_fix_plan.md` 修改了 BOOM LSU/DCache 统计路径，未修改生成的 Verilog、未运行仿真。

## 修改位置

- `chipyard/generators/boom/src/main/scala/lsu/lsu.scala`
  - `STQEntry` 和 `BoomDCacheReq` 增加 64 位单调 `strict_store_token`。
  - token 只在 `arch_store_in_scope` 的 ROB 提交点分配；普通 store 地址阶段不再设置 `traffic_arch_check`。
  - STQ 入队、分支清除、异常清除、traffic reset 和正常回收路径清理 token。
  - DCache 完成事件必须匹配 STQ index、提交状态、token valid 和 token 值；接受后清除 token，重复事件不会再次计数。
  - 严格 store 即使先收到 miss/MSHR 的早期响应，也要等物理写入消费 token 后才能回收 STQ，保证延迟 replay 仍能匹配。
  - `strictStorePending`、严格 store 总数及 cache/uncache 分项只使用匹配完成事件。
- `chipyard/generators/boom/src/main/scala/lsu/dcache.scala`
  - MSHR replay 和 MSHR request 显式传播 token。
  - cache store 在 `dataWriteArb.io.in(0).fire` 产生带 STQ index/token 的完成事件。
  - uncache store 转发 MSHR 文件产生的 STQ index/token。
- `chipyard/generators/boom/src/main/scala/lsu/mshrs.scala`
  - 不可缓存 store 完成端口增加 STQ index/token，并从多个 IOMSHR 选择实际完成者。
- `chipyard/generators/boom/src/main/scala/lsu/prefetcher.scala`
  - prefetch 明确携带 invalid token。

## 统计不变量

1. 未在 ROB 架构提交点获得 token 的请求不能产生严格 store 统计事件。
2. STQ index 被复用时，旧 replay 的 token 不匹配新 token。
3. token 在一次匹配完成后立即失效，同一 token 的重复完成不会重复消费。
4. traffic reset 清除 STQ 中的 token，reset 前遗留完成不会进入新窗口。
5. `completedStrictStores` 使用 LSU 接受事件，因此不会被无身份的原始 DCache Bool 直接驱动。

## 静态检查

已执行：

```text
scalac -Ystop-after:parser chipyard/generators/boom/src/main/scala/lsu/{lsu,dcache,mshrs,prefetcher}.scala
git diff --check
./chipyard/.conda-env/bin/sbt -batch 'project boom' Compile/compile
```

Scala parser、BOOM 子项目编译和 diff 检查均通过。按照本轮约束，没有执行 RTL 生成或仿真；运行时波形仍需后续验证。
