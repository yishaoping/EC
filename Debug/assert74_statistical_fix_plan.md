# Assert 74 统计修复方案

## 推荐方案：架构提交 token + 一次性消费

当前统计用一个 Bool `traffic_arch_check` 标识严格 store，再用
`dataWriteArb.io.in(0).fire` 作为完成事件。这个组合无法区分：

* 同一个 store 的延迟 replay；
* STQ 项已经回收后产生的旧 replay；
* traffic reset 前发出、reset 后才到达的完成事件；
* 没有架构提交资格却继承了旧 metadata 的请求。

修复应把“是否属于统计窗口”改成一个由架构提交产生的稳定 token，并在
DCache 完成点消费该 token 一次。

### 1. 只在架构提交点分配 token

在 LSU 的 `arch_store_in_scope` 分支中分配 token。地址生成阶段
`lsu.scala:1093-1112` 不再给普通 store 设置
`traffic_arch_check`；该阶段最多只记录 cacheability。

token 至少包含：

```text
window_epoch + monotonically_increasing_store_id
```

不能只使用 `stq_idx`，因为 STQ 项会循环复用；也不建议只使用
`packet_seq + stq_idx`，因为同一 packet 可能包含多个 store，且 reset 后旧
replay 仍可能返回。一个 64 bit 的单调 ID 加窗口 epoch 已足够，实际宽度
按配置决定。

架构提交时同时完成三件事：

```text
archStoreEvents(w) := true
strictStorePending := strictStorePending + 1
outstandingTokens.insert(token)
stq(idx).strictStoreToken := token
```

`outstandingTokens` 应是有限 CAM/FIFO，容量至少覆盖 STQ/MSHR/RPQ 可同时
存在的严格 store 数量。它独立于 STQ，避免 store 已经收到 DCache ack 并
被 STQ 回收后，物理 replay 才到达导致 token 丢失。

### 2. token 随请求穿过所有缓存队列

在以下请求结构中增加 `strict_store_token` 和 `strict_store_token_valid`：

* `BoomDCacheReq`；
* `BoomDCacheReqInternal`；
* MSHR 的 `req`、`rpq`、`replay`；
* DCache 的 `replay_req`、`s2_req`、`s3_req`。

普通 store 由 `stq_commit_e` 形成 DCache 请求时，复制 STQ 中由架构提交
分配的 token。MSHR primary、secondary、RPQ enqueue/dequeue、refill 后
replay 都只复制 token，不能重新采样全局 traffic 状态。

这样即使一个 cache line 合并多个 store，每个 RPQ 项仍带有自己的 token，
不会因为 line-level metadata 被错误复用而合并计数。

### 3. DCache 输出带 token 的完成事件

把当前 Bool 完成接口扩展为 `Valid(token)` 接口：

```text
traffic_store_cache_complete.valid
traffic_store_cache_complete.bits
traffic_store_uncache_complete.valid
traffic_store_uncache_complete.bits
```

缓存 store 在真实物理写入点产生事件：

```scala
dataWriteArb.io.in(0).fire &&
s3_req.strict_store_token_valid &&
s3_req.uop.uses_stq &&
s3_req.uop.mem_cmd === M_XWR
```

不可缓存 store 在原来的 TileLink 接受点产生同样的 token 事件。

注意：不能继续只导出 Bool。Bool 无法判断这是哪个 store，也无法判断事件
是否已经消费。

### 4. LSU 只接受匹配且未消费的 token

LSU 收到完成 token 后执行 CAM 查找：

```text
token 在 outstandingTokens 中，且未 consumed
    -> 标记 consumed
    -> strictStorePending -= 1
    -> strictStoreTotal/Cache/Uncache += 1

token 不存在、已 consumed 或 epoch 已失效
    -> 不增加完成统计
    -> 记录 duplicate/stale completion 诊断
```

原来的算术断言应改成协议断言：

```text
valid completion 必须命中 outstanding token
同一 token 只能消费一次
```

对 traffic reset 前遗留、reset 后到达的 replay，使用 epoch 使其 token 自动
失效。若旧请求仍会修改 cache 数据，这是缓存一致性路径的问题；统计路径
只应丢弃该旧 token，不能把它计入新窗口。

### 5. 严格资格和完成统计分离

`traffic_arch_check` 可以暂时保留用于兼容旧波形和其他 LR/SC/AMO 逻辑，
但普通 store 的严格完成统计必须以 `strict_store_token_valid` 为准。

推荐同时删除或限制以下提前赋值：

```scala
stq(stq_idx).bits.traffic_arch_check :=
  io.dmem.traffic_counting && io.dmem.traffic_check_state
```

普通 store 只能在 `arch_store_in_scope` 为真时获得 token；非架构提交、被
回滚或异常清除的 STQ 项必须保持 token invalid。

## 为什么不建议只改一个条件

### 不建议方案 A：在 underflow 时饱和到零

当前代码已经在寄存器更新处对 underflow 饱和到零。它只能避免无符号减法
回绕，不能修复统计总数，反而会隐藏重复/错误完成。

### 不建议方案 B：用 `stq_idx` 去重

STQ index 会循环复用。旧 replay 使用同一 index 返回时，可能误消费新 store
的 token，造成更隐蔽的少计或错配。

### 不建议方案 C：只按地址或 packet sequence 去重

同一 cache line 可以合法包含多个 store，同一 packet 也可能包含多个 store。
按地址去重会漏计，按 packet 去重会把多个合法事件合并。

### 可接受但语义改变的快速方案 D

如果暂时只想统计“DCache 接受已提交 store 请求”的次数，可以把完成点改到
首次 `s2_send_resp`/MSHR request fire，并完全取消物理 array write 作为完成事件。
这能避免 replay 重复计数，但指标从“物理完成”变成“缓存接受”，不应作为
最终修复，除非同步修改指标定义和文档。

## 推荐落地顺序

1. 先新增 token bundle 和 `Valid(token)` 接口，保持现有 Bool 接口旁路一版；
2. 让 token 完整穿过 LSU -> DCache -> MSHR/RPQ -> replay -> s3；
3. 在 LSU 增加 outstanding token CAM，并用 token 事件更新计数；
4. 将旧 Bool 统计改为由 token 事件驱动；
5. 删除普通 store 的地址阶段提前资格置位；
6. 增加静态断言/波形检查：每个架构提交 token 最多一个完成，每个有效
   completion 必须命中 token；
7. 只在完成静态检查后再生成 RTL 或仿真验证。当前用户要求的本轮分析不
   执行这些生成和仿真步骤。

## 修复后应满足的不变量

```text
completed_strict_store <= committed_strict_store
每个 token 的 consumed 位最多从 0 变 1 一次
同一 token 的 replay 次数不影响完成计数
STQ 回收/复用不影响尚未到达的 token
traffic reset 后旧 epoch token 不进入新窗口统计
```

## 本次落地说明

本次实现使用 STQ 中的 token 作为未消费记录，并增加了严格 store 的 STQ 回收栅栏：即使普通 cache/MSHR 接受响应已经把 `succeeded` 置位，只要 token 仍有效，STQ 项不会回收。这样 cache miss 的 refill replay 仍能通过 STQ index + token 匹配完成事件；完成事件消费 token 后，STQ 才恢复原有回收流程。该实现避免新增独立 CAM，同时保留了 STQ 对在途严格 store 的占用约束。

该方案保留 BOOM 原有 store 的提交、nack、MSHR、refill 和 replay 行为，
只改变统计资格的生成、传递和消费协议。
