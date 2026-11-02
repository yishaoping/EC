# Latency decomposition 与长尾证据

两类cohort严格分开：native latency是completion-in-ROI，允许start在ROI前、unfinished censored；mandatory release表仅全程位于ROI内的事务。不能跨cohort相减，也不能把所有load都当head-critical。

## Native miss/load latency：只有三个总阶段

| Observed phase | N | Sum | Average | Median interval | p90 interval | p99 interval | Max interval |
|---|---:|---:|---:|---|---|---|---|
| detect_to_alloc | 960 | 157622 | 164.190 | [0,0] | [32,63] | [4096,8191] | [8192,16383] |
| alloc_to_physical_final_refill | 1883 | 157331 | 83.553 | [32,63] | [64,127] | [128,255] | [8192,16383] |
| detect_to_data | 1052 | 211045 | 200.613 | [16,31] | [64,127] | [8192,16383] | [8192,16383] |

native bin0=0，binN=[2^(N−1),2^N−1]，最后bin饱和。区间是quantile所在bin，**不是精确分位数**。长尾最高非空bin14=[8192,16383]。detect→data并不保证晚于physical install；alloc→final refill包括request/下游/RPQ/victim/install，不能标成DRAM latency。detect→alloc长尾可能由本地ownership/same-set/admission引起，没有资源归因。

用hist各bin真实范围和**精确cohort sum**可以收紧>=1024cycle长尾的累计duration范围：令tail/non-tail各自bin下/上界为L/U，则tail sum属于 `[max(L_tail,total−U_other), min(U_tail,total−L_other)]`，无需任意per-miss penalty。

| Phase | >=1024cycle samples | Tail elapsed-duration sum bounds | Fraction of phase sum |
|---|---:|---|---|
| detect_to_alloc | 18 / 960 | [145,010, 151,224] | [92.00%, 95.94%] |
| alloc_to_physical_final_refill | 8 / 1883 | [38,912, 77,816] | [24.73%, 49.46%] |
| detect_to_data | 22 / 1052 | [169,083, 189,549] | [80.12%, 89.81%] |

因此detect→data只有22/1052个长尾样本，却至少占该cohort累计延迟约80%。这证明少量请求可主导**累计请求延迟**；没有这些请求的地址/phase/head身份，不能声称169k是ROI critical cycles、refill损失或可恢复收益。duration可重叠且可从ROI之前开始；top critical episodes仍unknown。

## 请求要求的七段及critical subset

| 分解项 | Avg / median / p90 / p99 / max | ROB-head critical | Non-critical | 缺失证据 |
|---|---|---|---|---|
| L1 detect→L2 issue | null | null | null | req token→MSHR source→A fire |
| L2 queue | null | null | null | inner A first→directory/schedule时间 |
| L2 lookup/service | null | null | null | lookup result→SourceD准入 |
| response wait | null | null | null | D valid/ready、credit、port |
| transfer | null | null | null | 同一miss各D beat accepted timestamp |
| L1 refill | null | null | null | lastD/LB→owner/install rows/meta |
| wakeup | null | null | null | dependent token response/ROB matching |

`T_total`七项不能数值闭合；unknown保持null，没有用均值相减补造。native仅说明尾部可很长，不能列出不存在的top miss/ROB episode。已知251个completed misses ever-head、head-cycle aggregate53,845，不含每episode边界或阶段。

## 新恢复的release子链（不是load miss分解的替代）

| Phase | N | Sum (cycles) | Average | Median | p90 | p99 | Max |
|---|---:|---:|---:|---:|---:|---:|---:|
| first_C_to_last_C | 2231 | 13386 | 6.000 | 6 | 6 | 6 | 6 |
| first_C_to_first_bank | 2231 | 80752 | 36.195 | 49 | 49 | 62 | 82 |
| last_C_to_first_bank | 2231 | 67366 | 30.195 | 43 | 43 | 56 | 76 |
| first_bank_to_last_bank | 2231 | 15617 | 7.000 | 7 | 7 | 7 | 7 |
| last_C_to_last_bank | 2231 | 82983 | 37.195 | 50 | 50 | 63 | 83 |
| last_bank_to_ACK | 2231 | 4546 | 2.038 | 2 | 2 | 2 | 9 |
| last_C_to_ACK | 2231 | 87529 | 39.233 | 52 | 52 | 65 | 85 |
| first_C_to_ACK | 2231 | 100915 | 45.233 | 58 | 58 | 71 | 91 |

normal/SVB各自分布见numeric_audit.json；每个原始事件行、8个bank fingerprints/word offset与完整时间戳见release_transactions.json。下面是 **lastC→ACK最慢的release**；没有证据称它们为ROB-critical episodes。

| Rank | Owner / pkg / line / generation | firstC / lastC | first…last bank | ACK | lastC→ACK | TSV row firstC / firstbank / ACK |
|---|---|---|---|---:|---:|---|
| 1 | SVB / 315 / 0x80087fc0 / 106942 | 2344642 / 2344648 | 2344724…2344731 | 2344733 | 85 | 107436 / 107442 / 107450 |
| 2 | normal / 270 / 0x80009040 / 97642 | 2183963 / 2183969 | 2184044…2184051 | 2184053 | 84 | 104882 / 104885 / 104893 |
| 3 | normal / 294 / 0x80009f40 / 101866 | 2279125 / 2279131 | 2279204…2279211 | 2279213 | 82 | 106342 / 106344 / 106352 |
| 4 | normal / 112 / 0x80019000 / 61874 | 1280726 / 1280732 | 1280804…1280811 | 1280813 | 81 | 73711 / 73713 / 73721 |
| 5 | normal / 29 / 0x80016580 / 49872 | 1535008 / 1535014 | 1535084…1535091 | 1535093 | 79 | 81163 / 81169 / 81179 |
| 6 | normal / 93 / 0x80087e40 / 55790 | 1038929 / 1038935 | 1039004…1039011 | 1039013 | 78 | 68111 / 68113 / 68121 |
| 7 | normal / 244 / 0x80009100 / 94426 | 2043569 / 2043575 | 2043644…2043651 | 2043653 | 78 | 100758 / 100760 / 100768 |
| 8 | normal / 15 / 0x80016180 / 48562 | 750330 / 750336 | 750404…750411 | 750413 | 77 | 53239 / 53241 / 53249 |
| 9 | normal / 271 / 0x80007f80 / 98026 | 2187090 / 2187096 | 2187164…2187171 | 2187173 | 77 | 105034 / 105037 / 105045 |
| 10 | normal / 55 / 0x80087e40 / 52213 | 895411 / 895417 | 895484…895491 | 895493 | 76 | 60948 / 60954 / 60962 |

optional prefix `[698301, 2192911]`中，release phase并集92,448cycles，与scheduler unavailable的280,215cycles仅交151cycles。说明**已经开始发C之后的这段release阶段**在该prefix大多不与scheduler unavailable同时出现；不排除pre-C、checkpoint、checker请求等待或较早阶段对package completion的影响。

SC7 flags的scheduler bit6及FSM可以恢复上述interval；flag10只在snap/cooling含ROB empty，flag13pipeline stall未参与change signature。故SC7不能恢复逐cycle noCommit/ROB-head，也不能伪造release×ROB overlap。unknown后缀154,313cycles不补齐。
