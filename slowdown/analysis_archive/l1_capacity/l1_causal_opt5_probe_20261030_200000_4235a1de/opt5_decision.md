# Opt5 判决

**INCONCLUSIVE_DUE_TO_CORRECTNESS_OR_MEASUREMENT**

`NEXT_OPTIMIZATION = NONE_JUSTIFIED`

B runtime correctness失败且测量不完整，不能套用5k/17k/几十k/85k性能档位。
本判决既不是REJECT，也不是WEAK/CANDIDATE/DIRECTION_JUSTIFIED。
保持有效Opt4、SVB16和此前不扩大SVB/不以promotion为主方向的结论。

下一步：先针对checker3 seq67的trap/start/return、cleanup和CANCEL handoff→BOOM release
关闭correctness问题；本轮没有实施超出geometry的功能修复，也未启动其它优化实验。
正确性闭合后，才评估重新封存并执行完整同instrumentation A/B。
面积、能耗、物理时序仍未测量，64KiB并未命名为正式Opt5。

因果问题：**NOT YET PROVEN**。A alone的head-miss关联不等于干预收益证据。
