# Seq32 与 CDC

当前验收（2026-11-24）：69项功能VERIFIED；当前5模型/12完整程序/31负例与严格联合评分全部PASS。来源、范围和独立物理状态见[系统验收](System_Acceptance.md)。

Seq0 表示无包或可信基线。普通 rollback 留下旧 tail，分配下一个 Seq。v1 在首次分配进入保留区 (2^{32}-257) 时启用 Seq32 重基。小上界配置 PalimpsestSeqRebaseTestConfig 将门槛设为 16。无重基配置耗尽时由原 identityUnavailable 停止。

| 顺序 | 持有者和实际条件 |
|---|---|
| 1 | Core 以刚分配的空 Starting CP 为目标，停 dispatch、retire、异常选择及新 I/O 授权。R_IC 进入新包的 fsm_check 后证明旧 producer 尾巴已封口。有未结 I/O 效果时跳过该检查点，保留重执行和效果验证所需的前进路径，在下一次保留区分配时重试。真实 FAIL 优先，且可抢占更晚目标。 |
| 2 | Controller pin SCP，经普通 EVT 邮箱安装废弃区间并排空 LSU、cache、RSU 和失败后缀 Checker owner。DCache 等 SW=tail、全部 Checker slot 释放、SVB/archive 及本地 owner 空闲，再发物理维护请求。 |
| 3 | 每个 L2 bank 阻止新 A，复用 flush/Probe/Release 和真实外部 ACK 扫描驻留行。终态还要求 history sidecar、park 槽、SourceC/SourceD 和收到的 C 全空。 |
| 4 | Main 请求 GHM transport 收据。GHM 确认 data、ARF、count 源端读指针追上写指针，无未发的 anchor/END/count，无选中的旧包，无 held result release。每个 Checker 还要确认其 result FIFO 的源端为空。 |
| 5 | Rocket 等本地 LSL、RSUSL、R_ICSL 包上下文、前端及结果 owner 清理，清 RocketCore 的 package_seq_reg 和 RocketTile 高水位后保持 ACK。R_ICSL 的 package_idle 要求包 FSM、包内 trap/depth 和待返回 owner 为空；无包 owner 的管理异常保留 CSR/PC/深度，不阻止清包标签。新包 admission、COPY 与结果交付仍要求完整 context_idle，必须等管理异常真正 xRET。GHM 在相同 Checker 域清 dataConsumedSeq、receivedCount，下一状态才允许跨回 Main。全部确认后 GHM 清 Main 域的 anchor_seq_sent 和 end_seq_sent。 |
| 6 | DCache 同拍清 EVT、tail、SW 和有效结果 bitmap，R_IC 清分配计数与旧 barrier ACK。L2 持续冻结，确认源端注册 Gray SW 在本域解码稳定为零，旧 barrier level 已退出。 |
| 7 | Main 用原 mailbox 的 `installOnly` 请求发送空 EVT，等所有 bank 和 Checker ACK 的高低阶段结束，再降低 maintenance、transport 及 SW 请求。所有终端 ACK 返回低后允许 Restart。SCP 仍由 Controller pin，重启从 Seq1 重新分配。 |

 AsyncQueue 保留其 Gray 指针与队列 reset 协议。空证书来自源端已同步的读指针；接收侧一拍 deq.valid 低可能只是传播延迟。Seq 重基跨过多个 Gray 位时 bank 已停用所有旧发布 owner。软件会话 CDC 与包 Seq 独立。地址统计清理自己的 Seq RAM tag，累计值保存，丢失排队样本时标记 measurement 无效。

普通 EVT 容量维护只回收 tombstone 和 Epoch/G 等标签。它保留 Seq32 与 SW 的原编号。短事务 owner 标签保持原恰好一次响应后循环的规则。

SeqTransport 使用生产 GHM、hart1 的生产 R_ICSL 和独立 Checker 时钟，驱动延迟结果、待发送旧 anchor/END、停钟及 ACK 高低阶段。它同时检查管理异常保持时可清空包标签，以及包内 trap、取消后的 xRET 和 special-PC 返回仍阻止清理。RSUSL/LSL/结果 join 及其他 Checker cleanup 由夹具提供，不能代替完整 RocketCore。I/O journal 恢复和 Seq 重基的重叠需要整核用例。整核小上界和 Figure 4 的执行状态见 [验证矩阵](Verification_Matrix.md)。

整核 Seq16 原始反例确认：取消可以先于管理软件 COPY 到达。RocketCore 已增加 COPY/JLR 存活 owner 门控；本地空收据同时等待 RSUSL 复制尾拍。修复后的V10异常/MMIO整核23次重基已通过，新GHM修复后的最终组合整核也已完整通过23次，不由SeqTransport单独替代。详见 `AI/Debug/bugs/bug-palimpsest-checker-cancel-before-copy.md`。

V2 又在 transport 阶段触发 Main watchdog。V1 只读探针确认维护开始后的管理异常与冻结的新 A 请求形成循环等待；V3 GHM＋R_ICSL 组合反例 cycle4455 失败。V4 分离上述 package_idle/context_idle，不修改异常计数、CSR 或 watchdog。该修复已通过V10完整异常/MMIO的23次重基；物理同步器映射另有当前未结项，详见 `AI/Debug/bugs/bug-palimpsest-seq-management-trap.md`。

V6原优化整核compact已完整通过两次重基；严格事件计分重新核对EVT安装、
同目标restore、物理compact、Seq reset、同PC restart及新Seq1 PASS。
V6异常MMIO的正常/Fault8严格配对通过。Seq16 原 200 万周期运行超时保留；同一
模型和 ELF 增加至 300 万仿真预算后，在 2061735 周期完整退出，23 次重基后
均有新 Seq1 PASS，128 次 ecall 与内存、FP、CSR、MMIO oracle 全部通过。
硬件 watchdog 未调整。

V6 Fault40+Seq41 的有界整核诊断已通过第一次交叠链计分：设备效果 journal
建立后，tick123963 分配 Seq41，effectPending=1、rebasePending=0；FAIL40
普通恢复后，Seq43 在同 PC 重放原值 0x26b，并且通过校验。tick125148 journal
释放，tick125156 才预留 Seq45；tick227899 完成物理 Seq reset，随后从原 SCP
PC 重启，新 Seq1 PASS。设备 A 在原效果及重放期间仅握手一次。
证据为 `AI/TMP/singlecore_checker_20261122_082540/fault40_seq41_candidate_v6/extended/`
的 `result.json`、`effects.log`、`overlap.log` 与 `run.log`。scoreboard.exit=0，
run.exit=2 是 350000 周期诊断上限；这项 PASS 仅适用于首次交叠链，不能替代
该配置的完整程序验收。原 180000 周期未覆盖 reset 的失败记录继续保留。

会话FINISH与Seq32复用共同使用forwardDrained收据。它包含无selected_segment_valid、无end/countPending、无DATA/ARF新offer、DATA/ARF/count源端队列空、无held checker_result_release。FINISH不得因Checker输入队列已空而越过尚未执行的包。SeqTransport新增START→Seq42 DATA/ARF/END→FINISH，分别扣住ingress、结果生成和Main槽释放；三个阶段均不得sessionDone，真实释放后才完成。夹具保留segment直到Main释放，遵守生产R_IC owner规则。

当前生产已合入Main源端registeredRequest（每Checker1bit，共4bit），forwardDrained与seqTransportRequest在源域注册后送原8级同步链。通用SynchronizerReg不改，物理flop属性由综合前`AI/Debug/scripts/synthesis/synchronizers.xdc`维护。firtool会忽略普通FIRRTL属性，故仅Scala注解不能作为物理保护证据。

生产重新生成SeqTransport/Hierarchy来源前后相同且均PASS；真实有限L1 slot 0xffff→1完整分配/安装/终态、32位Epoch/CurGen保留区真实外写和ACK后维护清零均通过。最终组合Seq16完整Main+4Checker+真实cache程序raw0、严格oracle0，23次物理重基均有新Seq1 PASS，128ecall与内存/FP/CSR正确。证据`recovery_integration_closure.json`及长期矩阵。

同top生产GHM U250综合实际exit0，原4条组合前置CDC-10和4条ACK提取SRL的CDC-13全部消失，226项CDC-3；1742项AsyncQueue数据CE warning仍需数据保持/Gray总线偏斜约束验证。98,895 LUT/336,652 FF、5ns内部综合WNS+1.448ns只属于未布局布线、接口无外延时的GHM，不能作为完整Core物理签核。原失败报告保留。

长期`PalimpsestFault40Seq41TestConfig`的连续设备owner来源完整程序已通过8次真实重基、8个新Seq1 PASS、48设备读和9个负例；新Scheduler仅含E抢占修复来源正在独立重验。`concurrency_regression.py`保留完整入口。它要求首次未结效果在Seq41时不预留、真实FAIL后journal重放和释放，再做全部计划reset/新Seq1 PASS。旧350000周期首段PASS的范围不改变，不冒充新完整通过。
