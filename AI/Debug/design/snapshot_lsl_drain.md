# Snapshot、LSL、drain 的交互

Snapshot 只在空 ROB、valid committed next PC、quiet/armed 条件满足后接受；next PC 来自架构 committed state。LSL 的 SyncReadMem head 必须先读后寄存，payload 与 valid 同步保持，type/address match 后才 dequeue/fire。Barrier close 允许旧 package drain；final count/END/seal 必须覆盖 drain 中的真实提交。Completion gate 仍需 data/ARF/CSR/tail/LSL/CDC 全部满足。

首 bad 定位顺序：snapshot acceptance → BOOM commit count/seq → GH_BUF DATA/END → checker admission/instruction tail → LSL prefetch/head/fire → result/release/safe。每一级都用 fire 和 sequence 证据，不使用 level 单独推断。
