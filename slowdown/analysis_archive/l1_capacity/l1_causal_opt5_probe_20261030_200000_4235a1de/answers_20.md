# 20项结果回答

本表精确说明已测A与不可用B；不填零，不比较不等长prefix。

1. **Run A ROI cycles**：1,707,863，精确软件区间[712114,2419977)

2. **Run B ROI cycles**：UNAVAILABLE；start698301有效，但无stop，不能把assertion tick当终点

3. **净改善cycles**：UNAVAILABLE；B未完成，不能计算paired delta

4. **占A ROI百分比**：UNAVAILABLE；B未完成，不能计算paired delta

5. **L1 miss变化**：A legacy首次lookup tag misses3272；native load1533 / store2478；B unavailable。两总体定义不同。

6. **miss reduction百分比**：UNAVAILABLE；B未完成，不能计算paired delta

7. **MSHR allocation**：A primary2162 / upgrade115 / merge952；B unavailable

8. **MSHR full cycles**：A 0；B unavailable

9. **MSHR busy cycles**：A 313150；B unavailable

10. **MSHR occupancy distribution**：A bins0–6 [1394713, 312184, 953, 13, 0, 0, 0]；B unavailable

11. **load replay count / cycles**：A RPQ 321 events/321 active cycles，nack retry 111548 events/111548 cycles；B unavailable

12. **load miss latency**：load detect→accept: A samples=1380, mean=324.3130 cycles；B unavailable；MSHR alloc→refill: A samples=2162, mean=126.9519 cycles；B unavailable；load detect→data: A samples=1530, mean=347.8379 cycles；B unavailable

13. **ROB-head miss wait**：A 139694；B unavailable

14. **ROB-head与MSHR交集**：A head∩busy 139500 / full 0；B unavailable

15. **scheduler unavailable**：A 318150；B unavailable。完整计数不是旧稀疏prefix的267087。

16. **scheduler与MSHR交集**：A scheduler∩busy 154 / full 0，head∩scheduler 17；B unavailable

17. **ROI改善的定量解释**：不能定量解释：没有B完整ROI/counters，不能进行exposure加法或miss×penalty推算

18. **miss下降但critical counters不变？**：无法判断：B实际miss和critical counters都缺失，不使用shadow1301替代

19. **是否可能有其他performance来源？**：无法判断：没有有效paired performance。Geometry的warmup/时序反馈存在可能性，但未测出净效应

20. **observer / correctness**：A全部PASS；B runtime assertion FAIL，完整observer/ROI/counters未验证；已记录prefix完整性不是整次run认证
