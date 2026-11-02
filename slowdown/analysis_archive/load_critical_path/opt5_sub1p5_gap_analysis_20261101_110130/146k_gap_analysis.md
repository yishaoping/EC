# 146k gap分析

native/reference=1,001,675；旧Opt4/A=1,707,863；B=1,648,923，slowdown=1.646165672。
用户目标 `ROI < 1,502,513`，近似缺口146,410。严格1.5阈值为1,502,512.5；整数ROI最大1,502,512，需至少节省 **146,411**；相对Opt4至少205,351（用户近似205,350）。

| exact-ROI观测 | A | B | B−A |
|---|---:|---:|---:|
| ROB_HEAD_WAITING_ON_LOAD_MISS_CYCLES | 139,694 | 53,845 | -85,849 |
| rob_head_load_pending_cycles | 151,352 | 80,832 | -70,520 |
| load_nack_retry_cycles | 111,548 | 47,162 | -64,386 |
| load_rpq_replay_cycles | 321 | 229 | -92 |
| mshr_busy_cycles | 313,150 | 194,905 | -118,245 |
| mshr_full_cycles | 0 | 0 | +0 |
| scheduler_unavailable_cycles | 318,150 | 347,409 | +29,259 |

以下是固定轨迹的互斥状态分区，不是干预收益分解：

| 分区 | A | B | B−A |
|---|---:|---:|---:|
| head miss only | 139,677 | 53,845 | −85,832 |
| scheduler only | 318,133 | 347,409 | +29,276 |
| both | 17 | 0 | −17 |
| neither | 1,250,036 | 1,247,669 | −2,367 |

分区各列之和等于各自ROI；分区变化之和−58,940。head total减少85,849同时scheduler total增加29,259，不能把85,849再加进58,940，更不能把每个miss平均分配固定代价。时序变化/窗口内事件变化和未闭合pairing都可能改变分区。

head miss53,845 ⊆ all head-load pending80,832，后者包含额外26,987非已标记miss的head load等待。nack47,163 cycles / retry47,162 cycles / replay229 issue cycles可能互相重叠并落在head等待内；没有逐cycle join，不相加。
仅head miss理想删除后ROI1,595,078/1.592410712x；全部head-load pending理想删除后1,568,091/1.565468840x，仍分别缺92,566/65,579才能严格低于1.5。

不能忽略的更宽证据：STOP traffic窗口 `ROB no-commit AND any load pending`159,519；扣除窗口外11,160后，ROI交集在 **148,359..159,519**。它名义上够大，但any-load与head blocker没有因果身份关联，可能与IC/GC/其他条件同时成立。该项不是已证明load stall，也不是可删除预算；它保留了非head依赖传播待归因空间。

独立control方向：native scheduler exposure347,409，head-miss交集0、MSHRbusy交集269/full0。它不是memory问题的已证放大器，不能捆入Opt5。作为以后独立方向可先离线归因，但目前也没有347k可恢复收益证明。
