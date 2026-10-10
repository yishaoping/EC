# Bug 导航与状态

当前未解决 failure 唯一入口为 ../state/current_debug_state.md。以下是历史机制；禁止把旧root cause直接套入最新run。

- bug-528000-count-boundary：600/558/42 drain计数链，directed验证通过，整机未证明。
- bug-1769000-frontend-regression：重复ret与redirect启动regression，最终静态生成通过，动态未证实。
- bug-461000-lsl-syncfifo：wrong type、ready/read等待环，528000 run中的旧first-bad已消失。
- bug-snapshot-next-pc：invalid empty-head PC与ARF边界；528000中23次snapshot审计通过。
- bug-shadow-writeback-coherence：TtoB/本地Nothing与metadata clear重发。
- bug-strict-store-token、bug-killed-store-stq-replay：exact identity/once-only及迟到nack。
- bug-barrier-traffic-window、bug-20260930-package-address：窗口、ownership和safe等值。
- bug-anchor-admission-result、bug-assert24-trap-backpressure、bug-boot-scoreboard：早期CDC/result/trap/backpressure/boot机制。

每次修复验证完成补写对应bug的实际证据、独立回归和最终状态，更新history，不继续扩充current的旧问题叙述。
