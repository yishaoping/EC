# cache / TileLink / strict store

- [ ] strict-store token 在架构提交分配；一路穿过 DCache/MSHR/RPQ/replay
- [ ] completion 匹配 live STQ、token 和窗口，消费后立即失效
- [ ] slot reuse/kill/reset 的旧 replay 不影响新 slot 或新统计窗口
- [ ] nack rollback 只指向仍 live、未完成且 identity 匹配的 STQ
- [ ] killed S1 request 被保存/重试一次；不能 fire 后被静默丢弃
- [ ] 跨包 shadow WB 使用 TtoN，metadata clear 期间不重发
- [ ] TL channel 完成、safe、barrier ACK/result/release 各有独立证据
