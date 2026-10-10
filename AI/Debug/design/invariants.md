# Design Invariants

1. `valid && ready == fire`，所有 payload 在 valid 且未 ready 时保持。
2. 任何 sequence 的 allocation、producer records、consumer records、final count、END 和 result 使用同一 owner。
3. `done/final` 后不可再产生同一 sequence 的未计数 producer retirement。
4. LSL mismatch 不 dequeue；prefetch response 必须进入寄存 payload；quiescent 要覆盖 read/response/replay。
5. strict token 与 STQ slot reuse、kill、reset、replay 绑定；完成 exactly-once。
6. trap/context、redirect、clear、handler、BJL reservation 的生命周期不能跨包泄漏。
7. counter 不得在同拍发生 underflow；统计窗口 reset 清除旧 pending metadata。
8. 每个新 Chisel IO 都要检查宿主、所有实例连接、FIRRTL initialization 和 generated RTL。
