# 最小信号集导航

实际生成hierarchy/宽度必须按run核对。源码symbol不是对所有配置固定的FST名字。reader要求显式波形，默认POSIX ERE。

| 问题 | 先观察 |
|---|---|
| watchdog vs上游首坏 | BOOM commit.arch_valids、idle/slot counter、ic_status/clear、gh_stall及合法复位条件 |
| snapshot/empty PC | rob_empty、r_next_pc/valid、snapshot_quiet/armed/accepted、doSnapshot、active seq、checker CPS PC |
| drain/count/END | R_IC producer_open/target、old seq/count、snapshot_capture/closing、GH_BUF DATA seq/fire、per-slot seal、GHM send_end/end_pending/receivedCount |
| LSL同步读 | bank empty、deq_read/read_valid、prefetch_pending、head_payload/head_valid、selected_head、type/address match、response/deq_fire/quiescent |
| package release | start_pending/active/owned/seq、context_idle、exec/data/ARF/CSR completion、result valid/ready/fire/status、GHM release、BOOM clear、safe |
| frontend/replay | req.valid/target pending/settle、ICache fire/owner S1/S2、descriptor/READY、FQ fire/prefix/endMask、IBuf完整指令、WB bjlOwned/commit/rollback |
| cache/TL | addr/set/way、STQ idx/token、S0–S3、MSHR replay、dataWrite fire、TL A/C/D fire/param、meta clear、safe/barrier request/ACK |

波形后缀.vcd实际可能FST；unknown/raw RAM值不能强制转换为0。完整时间戳归并后按边沿前状态判断fire，避免把文本打印次序当逻辑传播次序。
