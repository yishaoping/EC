# retry amplification：循环已证明，关键路径倍率未测得

RTL闭环：LDQ保留immutable functional_token → DCache lookup → S2被结构条件nack → LSU核对live token并清executed → registered AgePriorityEncoder从LDQ head挑可执行load → 同一token再次lookup，直至资源/owner状态改变。一次实际miss或同set owner窗口可以容纳很多次这种尝试；tag-miss attempts会对同token每次增加，首次miss-request计数只增加一次。

这支持“容量改变减少冲突窗口 → 重复lookup/nack随之大幅减少 → 某些load更早解除head阻塞”的结构解释。它没有证明所有64,386 retry减少来自648个actual miss减少：actual misses在更大的traffic窗口，retry在精确ROI，而且旧A/新B非严格pair。两run之间也没有同token对应关系。不能用64,386/648推导每miss固定代价。

用户定义 retry events / unique affected retry requests：B分子47,162，分母未导出；精确倍率null，安全但很宽的bounds **[1,47,162]**。A为[1,111,548]。不是用1,062个first miss当分母，因为hit-victim/probe/uncached等nack cohort不等于首次cacheable miss cohort。
critical retry events / unique critical requests：二者关联均未导出，critical事件可能为0，倍率可能未定义；若条件性假设至少1个critical事件，则倍率在[1,47,162]。head∩retry-cycle最多47,162、最少0，不证明任一token的critical amplification。

可以独立给出较有信息量的**miss lookup attempt**倍率边界：

| arm | attempts | ROI首次tag+permission detections | 含carry-in的affected miss token bounds | attempts/token bounds | 至少一个token尝试≥ |
|---|---:|---:|---:|---:|---:|
| A | 112,461 | 1,542 | [1542, 1558] | 72.1829..72.9319 | 73 |
| B | 40,033 | 1,062 | [1062, 1078] | 37.1364..37.6959 | 38 |

推导：本次生成RTL有16个LDQ槽；ROI开始前已detected、但在ROI里再次lookup的token最多16；ROI中新detected的每个token至少有一次kind14。stable token/slot lifetime保证分母在[first,first+16]，由鸽巢原理B至少一个token有38次miss lookup（至少37次重复）。这是cohort-bound，不能冒称实测逐token nack histogram或critical factor。native忽略address，无法建立每line retry分布。

七个机制判断：

1. 一个miss导致大量重复lookup：结构证明且上述aggregate bound支持；具体request nack次数未记录。
2. refill window内重新发起：当窗口仍使ready/owner条件不满足时结构上成立；缺少refill-state/token时间join，未测该子集大小。
3. miss占共享资源：同set MSHR排他、RPQ admission/drain、meta/data端口/WB/owner保留均有源码证据；各自占关键周期未测。
4. critical load受普通请求挤压：端口固定优先级可能造成等待，但未测关键请求被挤压多久；不能称已确认饥饿。
5. hit/miss特定状态重复nack：victim8,087、miss-not-ready39,072支持，S2具体first blocker未分解。
6. retry缺少age/保留：已排除。LDQ已保留请求且有age priority；重复增加age仲裁/queue不是新优化。
7. refill/replay/lookup serialization：结构存在；普通load已可从line-buffer直接返回，RPQ replay held-until-terminal是正确性协议。尚未分开外部服务时间与本地可消除serialization。

四层证据：症状=47,162 retries（PROVEN）；直接阻塞=S2谓词及MSHR admission（PROVEN，数量细分有限）；上游trigger=每次具体owner/refill/SDQ条件（UNPROVEN逐事件）；下游amplifier=保留token的重复lookup循环（PROVEN），其ROI可恢复周期（UNPROVEN）。
