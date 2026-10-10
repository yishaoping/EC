# 协议检查清单

- [ ] sequence 非零、owner 唯一且 allocation/snapshot/LSQ/CDC/result 一致
- [ ] valid 未被 ready 反向组合门控；valid&&!ready 时 payload 保持
- [ ] AsyncQueue/FIFO full、empty、deq fire 和 reset/kill 都有证据
- [ ] DATA/ARF/CPS/END 顺序、count、epoch 和 stale message 检查
- [ ] LSL head 先读后寄存，type/address match，mismatch 不 dequeue
- [ ] result valid 保持到 fire；PASS、clear、safe、barrier ACK 分开
