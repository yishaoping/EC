# 1769000 deadlock 独立核实与实施记录

日期：2026-10-09。以当前工作树为底座，未撤销任何既有修改。

## 1. 核实结论与证据边界

完整阅读 `1769000_fix_spec.md` 及 `debug_handoff_528000.md`，逐项核对实际 Scala、现有 diff、软件及保存的 FST。HEAD 为 `fbca5d0c5ee2a65575ad2b283c7219103684169a`；修改前 `git diff --binary -- chipyard | sha256sum` 为 `f42742f0adc5342435fc434144af288762895411824fe88f7e59c401b136bdaf`，与交接一致。Frontend/IBuf/R_BJLR 原先没有 diff。

核心根因可实施，但 spec 不是已验证实现。以下证据来自原运行，不能用将来的生成文件解释旧波形。

- 直接症状：BOOM idle watchdog；不是 checker assert22。原 FST 范围 `0..3538972`，本文时间均为原始 FST 单位。
- 上游触发：独立重读 `3009300..3009700`，`3009393..3009397` 的 FQ valid 与 redirect replay 同时有效；原包含 `0x80004898` 分支和 `0x8000489a` ret，后者在 `3009413..3009417` 再交付。WB `3009669..3009677` 连续两个退休边沿的 ret 伴随 sl_counter 98→99→100。重复执行机制为 Confirmed。
- 直接阻塞：独立重读 `3025800..3025940`，此前 load 正常出队，sl_counter 于 `3025925..3025929` 从 4074 到 4075，WB valid 降低且 instruction_tail_waiting 拉高，LSL bank0 留有一条。源 final=4074 与正常 checker startup +1 的计数表示相符。局部环是 instruction tail 等 LSL quiescent，而剩余 LSL 等已被 count 禁止的最后 load 执行。不是最后 LSL 等 writeback 产生。
- 下游放大：未 PASS 的 e4 无法填补 safe=e3 的缺口，跨包 shadow writeback 等 safe，再阻挡 BOOM；CANCEL 不是 PASS。这条源码链与 spec 相符。整包 PC/机器码独立 scoreboard 尚需新运行，现有总数不作为 exactly-once 自证。

接口盘点基本真实：实例为 R_BJLR；FrontendResp 缺少独立前缀长度，IBuf 的 nIC 只读 taken/bridx；GH_FIFO_SC 内层 rollback 已用 cptr_after_commit，外层仍用旧 commit_bank_ptr；RocketCore 当前按 opcode commit。GHM 已有同 DATA 队列 ordered END、15 位 finalCount 和 53 位 sequenced checker count，无需另一套 bridge。保留既有 drain、snapshot、LSL、barrier/TL/token 修复。

## 2. 必须修正的实施细节

1. **清理不能先 reset BJL 再等待旧路径 kill。** CANCEL 本地 capture 后，旧 EX/MEM/WB 可能尚未被返回 redirect 杀掉；立即 reset 会吞掉有效 commit 或使旧归属使用新 cursor。clear 先禁止新 reserve/emit、取消未交付 descriptor；BJL reset 和 ack 等真实 redirect 已杀旧 checker 路径、旧请求阶段已失效后执行。ack 为寄存状态，加入 cleanup/handoff/admission，不加入 exec/tail/ARF gate。正常 result 后亦用同一规则。
2. **redirect 当拍的 live checker_mode 不能决定新目标的请求属性。** 异常/返回 FSM 在该边沿后才换 mode。实施时在 redirect 周期不接受 ICache 请求，先锁存 redirect PC，下一周期按新模式接受；正常模式增加一个 redirect bubble。这比用旧 mode 给 handler 请求打上 reservation 身份可证明。S1/S2 checker owner 来自真实 req.fire；miss 在固定响应阶段后重试，不无限等待 resp.valid。
3. **descriptor 可复用现有 S1/S2，不再建立第二套 cache/TLB流水。** checker 每次只允许一个未完成 fetch；响应捕获后暂停后续请求，CLASSIFY/WAIT/READY 保存完整 payload、seq、GPA。READY valid 来自寄存 state。无需无限 token 或多 descriptor；已发到 FQ 的 CFI 不等 WB 才继续取指。
4. **跨块归属不能用 packet-wide reserved bit。** 显式 prefixLength 与最后半字 endMask 同 data 拼接和移位；低半字 partial 只随 FQ fire 更新，保存首 PC/seq，redirect/clear 清除。最早 CFI 的精确 PC/长度匹配；无 head 时先发它前面的完整指令，避免扣住前方 load 形成 DATA/BJL 新环。
5. **ordinary 管理响应和 checker 响应有固定身份。** 已捕获 descriptor 不随 live mode 被改释；管理 bit12=1 JALR 不 reserve/commit，MEM 既有 rsu_pc redirect 保留。源码 JALR BitPat 允许该编码；软件二进制/管理编码核验及运行边界将单独记入验证结果。
6. **串行 miss 重试不能沿用 S2 空拍杀 PTW 的条件。** 实施后静态追踪发现：checker miss 释放请求阶段后重试，旧 `s2_replay` 可使中间 `s2_valid=0`；TLB 在 `s_request` 等 PTW ready 时，`io.kill` 会无条件回到 `s_ready`（TLB.scala:686–693）。因此旧 `!s2_valid` 会取消同一 PC 的待发翻译，反复错过 ready 时不能保证进展。checker flow 的 kill 改为真实 core redirect 或包 clear；普通 flow 保留原 speculative/S2 kill。重试阶段不推进 fetch PC，PTW 请求因空拍不再被取消，真正 redirect/clear 仍取消旧路径。
7. **fault response 不采纳无效 ICache response 的 replay 位。** `ICache.scala` 的 replay sideband 不随 resp.valid 自动归零；checker 可以因 S2 fetch fault 捕获一个没有 cache response 的 descriptor。新 capture 将 cache replay 限定为 cache-valid，避免旧 ECC/replay 状态抢先触发 IBuf replay 而掩盖本次异常。异常/GPA 仍来自当前请求对齐的 S2 TLB response。
8. **背压稳定断言须跨拍识别取消。** checker READY valid 不直接组合门控 redirect；redirect 当拍 FQ 尚满时，原 held 寄存器会把已取消的事务记为仍须保持，下一拍 EMPTY 触发假断言。held capture 增加 `!req.valid`，仅监测没有被真实 redirect 取消的背压事务；这不改变 enq.valid 或引入 ready/valid 环。
9. **模式边界清理旧 BTB 响应。** checker 请求进入 S1 或 core redirect 时清除 `s2_btb_resp_valid`；checker 模式沿用既有规则，不向 BTB 发新请求。这样管理返回切回普通前端时不会把旧模式的 taken/bridx 重新解释成当前 response 的 legacy prefix；下一普通请求重新走 BTB lookup。
10. **clear 的 owner 撤销与 response 有效性同步。** clear 在 checker S1 到来时，下一拍 owner 已清，但 S2 TLB fault 仍可能满足 legacy_emit；故该事件也清除这笔请求的 `s2_valid`。只处理 `checker_s1_owner`，普通 handler 的 S1/S2 不被包 clear 无条件杀掉。

## 3. 不变量与审查门槛

- reserve 仅 WAIT 的 resident、PC/长度匹配 head，且不与 redirect/clear 并发；READY 背压不再次 reserve，payload 不变；FQ fire 才移交并更新 PC/partial。
- owned CFI 仅 WB 真正退休一次 commit；kill/replay 不 commit。commit+rollback 两层均落到 post-commit cursor。
- 前缀槽合法、非零；taken 不冒充截断。异常/replay 不等待不存在的正常 BJL。
- DATA/END/count 的 producer/CDC/checker表示保持，正常 N+1 不调大；PASS/safe 条件保持。
- forward progress 依赖合法源记录、时钟运行和最终响应/解除背压；缺失 head 仍可由既有 timeout CANCEL，不能称为修复成功。新 clear 不阻挡管理 return/xRET。
- 必须检查真实 Scala 编译、目标 elaboration/FIRRTL 初始化与组合环；生成/仿真证据与旧运行隔离。不得以静态检查或 watchdog 延后替代运行正确性。

## 4. 实际实施与验证

第一轮 rocketchip Scala compile 已通过。第一轮目标 v1Config 的真实 FIRRTL `-X low` 发现 4 个 RocketTile 的同构组合环：`req.valid -> checker_emit/enq.valid -> flow-through FQ/IBuf -> mem_wrong_npc -> take_pc_mem -> req.valid`。这也修正了 spec 的“redirect 优先于 emit”解释：不能组合门控 READY valid；redirect 通过 FQ 的现有 reset、IBuf kill 和 descriptor 清状态优先级撤销本拍事务，valid 保持来自寄存 READY。reserve 禁止与 redirect 并发，commit+rollback 仍保留已退休项。已移除新 enq.valid 对 req.valid 的组合依赖；随后重新生成通过，不能引用第一轮编译为 FIRRTL 通过。

### 4.1 本次实际源码修改

| 文件（rocket-chip/src/main/scala 下） | 本次实施 |
|---|---|
| `rocket/Frontend.scala` | `prefixLength/bjlEndMask`、seq/clear/ack 接口；单 checker descriptor，真实 ICache fire 的 S1/S2 owner；完整 response/GPA 保持；最早 CFI 精确 PC/长度匹配；普通前缀优先发出；跨块 partial 按 FQ fire 更新；WAIT 只 reserve 一次，READY 保持至 FQ fire；redirect bubble、rollback 与包清理；删除旧 checker S1 reserve/S2 退项路径和提前 already_done reset；补齐第 2 节的 PTW、fault replay、BTB、held 断言及 clear/S2 边界 |
| `rocket/IBuf.scala` | nIC 采用显式 prefixLength；endMask 与 data 同步 offset/拼接/缓存/移位；完整指令最后半字产生 `Instruction.bjlOwned`，replay 不产生归属；保留既有 kill、异常和指令展开规则 |
| `rocket/RocketCore.scala` | 三个 pipeline ownership 寄存器采用对应级 ctrl_kill 条件；只在 `wb_valid && wb_reg_bjl_owned` commit；寄存 clear pending 保持至 ack；ack 只加入本地 cleanup，由现有 handoff/admission 条件使用 |
| `r/R_BJL.scala` | resident-only ready；rollback 当拍禁止 reserve；外层 rollback 使用 post-commit bank cursor，与已有 GH_FIFO_SC 一致；无 reservation 的 commit 触发断言 |

RocketCore diff 中原有的 LSL mismatch、quiescent、producer seal、count seq、progress watchdog 等行属于接手前的修改。本次在这些已有条件上增加前端 cleanup，不重新改写它们。其余已修改的 BOOM、GHM、LSL、RSU、cache/TL/token 文件继续保留，未回滚，也不把其全部 Git diff 计为本次工作。新 IO 沿 RocketTile 的既有 bulk connect 连接，不增加裸跨时钟接口。

### 4.2 最终源码静态核对

| 审查项 | 结论与边界 |
|---|---|
| spec 与真实结构 | 新增字段有真实宿主；FrontendResp 只有 Frontend producer，IBuf 消费；三个 ownership stage 赋值与 pipeline valid 同条件；所有新增 FrontendIO 接线由原 bulk connect 完成 |
| 状态生命周期 | req.fire capture PC/seq；固定响应阶段 miss 释放并重试同 PC；response capture 后分类；reserve 后保存 endMask/npc；FQ fire 后释放；redirect/clear 最后赋值优先作废 descriptor/partial/owners。新 seq 撤销旧 ack，初始空闲 ack 为 true |
| reserve/emit/commit | WAIT→READY 仅 resident head 精确匹配时 reserve；READY 不再读 live head；valid 不读 FQ ready；FQ fire 才推进交付 PC/partial；IBuf 归属仅跟最后半字；WB replay/exception/check_exception 不 commit。允许多个已移交 FQ 的 reservation，不逐条等待 WB |
| redirect 同拍 | enq.valid 可以在 redirect 当拍仍为 1；现有 FQ reset 与 IBuf.kill/ctrl_killd 杀掉该路径，descriptor 最终清空，BJL rollback；若老 WB 真退休，内外游标都保留 post-commit 点。不能把取消当拍的 FQ fire 当有效架构交付 |
| DATA/END/count | 本次未修改该链。GHM 同一 AsyncQueue 的 ordered END、15 位 final 和 53 位 sequenced count 与 spec 相符；END 不写 LSL/BJL，也不等 LSL quiescent。normal N+1、privileged N 保留，源端 final 上限断言为 5000，当前 4074+1 不溢出；未调高 final 掩盖多退休 |
| clear/handler | result capture 后寄存请求；先停旧 reserve/未交付片段，等真实 redirect 杀旧 FQ/流水线后 reset BJL 并寄存 ack；clear 不无目标清空 handler FQ/IBuf，不要求管理循环永久为空。S1 clear 同步杀该 checker 的 S2 valid |
| completion 无环 | clear ack 未进入 package_tail_drained、ARF/CSR compare 或 exec completion；现有 completion/cancel 仍独立驱动管理返回，ack 只允许结果交接/复用。active/start-pending 包的 DATA admission 不依赖 cleanup ack |
| progress | CFI 前普通指令先交付，释放更早 DATA；I$ miss 不占 BJL reservation；TLB pending 不因重试空拍取消；reserve 后只等 FQ；返回不等清理 ack。依赖合法有序源记录及最终外部响应/解除背压，不声称无条件进展或把 CANCEL 当成功 |
| Chisel/Scala/FIRRTL | prefix/end index 至少 1 位，边界加法用 +&；复用项目 extract 支持 fetchWidth=1 的空 slice；新 Bundle producer 全赋值、寄存有效位有 reset、无新动态 dontTouch。目标 v1Config 的真实编译/初始化/环检查见下节；未实际生成所有其他参数配置 |
| 旧修复回归范围 | 没有改变 snapshot/drain producer owner/count、LSL head/匹配消费、strict store token、TtoN/meta-clear、PASS/safe/barrier 条件；但前端延时改变会暴露其他时序边界，运行回归仍必要 |

软件 `Software/Test/core/checker.c:40` 在 COPY 指令（0x60）后使用 `R_INSTRUCTION_JLR`；`Software/Test/test.dump:4099` 的 `0x80003ab0` 编码为 `00001067`。对应 bit12=1 管理 JALR 豁免 BJL，保留 MEM 既有 rsu_pc redirect；其 endMask 为 0，不会 commit 下一项。`Software/Test/test.riscv` SHA256 为 `7d440cced710e16958d0121fcac377d57266c9c54a82845e2d5dc9a3a0a9c686`。这验证当前软件用途，不授权普通源程序随意复用该管理编码。

### 4.3 验证记录与仿真边界

- 初始 Scala compile 通过：`Debug/1769000_compile.log`。
- 首次 lowering 发现组合环：`Debug/1769000_generate.log`；已修正，见本节开头。
- 修正组合环后的 compile、目标 elaboration、Scala FIRRTL `-X low` 和 firtool RTL 生成通过：`Debug/1769000_generate_final.log`。该轮在后续静态补充之前，不作为最终源码验证。
- 最终静态补充后的 Scala compile、Chisel elaboration、Scala FIRRTL `-X low`、firtool RTL 导出及 all.f 生成全部通过，make exit 0：`Debug/1769000_generate_review_final.log`，完成于 2026-10-09 19:28:40 +08。中间因补齐审查发现而中断的生成不算通过。工具仍有原有 unused/feature 及未消费 annotation 警告（InfoMode、RegFieldDescMapping、DontTouch、RetimeModule、Params、AddressMap）；未出现新的初始化、target parser 或组合环错误。
- 用户说“别做仿真，我自己来”之前，已运行两个生成模块的小测试：`Debug/1769000_build/ibuf_test.cpp` 和 `bjl_test.cpp`，两者 PASS，覆盖不重叠 RVC 前缀、IBuf 缓存/跨块 ownership、背压/kill、resident reserve 和 commit+rollback。它们不是 Frontend/整机验证；这些模块之后未再修改。
- Frontend 测试仅准备了源码，未执行；整机 simulator build 被 Ctrl-C 中断（exit 130）。没有运行新 RTL 的完整程序仿真；用户明确接管仿真后不再运行任何模块或整机仿真。已确认被中断构建的进程组无残留。
- `git diff --check -- chipyard` 通过；全仓检查仅报告接手前 `Experiment/流量分析.typ` 的 4 处行尾空格与 EOF 空行，未替用户清理无关文档。

本次生成目录隔离为 `Debug/1769000_build/generated`，原失败运行的 `chipyard/sims/verilator/generated-src`、`output/test.log/test.vcd` 保持为旧证据。可复现的最终生成命令（不是运行仿真）：

```sh
cd /data1/gzh/EC/chipyard
source ./env.sh
JAVA_TOOL_OPTIONS='-Xmx16G -Xss8M -XX:ActiveProcessorCount=8 -Dsbt.supershell=false' \
make -C sims/verilator CONFIG=v1Config \
  build_dir=/data1/gzh/EC/Debug/1769000_build/generated \
  /data1/gzh/EC/Debug/1769000_build/generated/chipyard.TestHarness.v1Config.all.f
```

### 4.4 剩余风险与用户运行验收

没有新整机波形，不能断言 1769000 已动态修复，也不能宣称端到端 exactly-once/forward progress 已证明。静态机制消除了已定位的重复后缀交付路径，独立运行证据仍是验收条件。

1. 用 BOOM ROB 架构 PC/机器码逐项对齐 checker 退休流，扣除合法 startup，确认同一动态 ret 只退休一次；合法循环同 PC 重复不是错误。不要用 final/count 相等自证 exactly-once。
2. 确认最后 load 真正 LSL match/dequeue、一次 WB，再进入 instruction tail、quiescent、ARF/CSR、PASS、result handoff、BOOM release、连续 safe 和合法 writeback；越过原 watchdog 或 CANCEL 清理均不够。
3. 验证 I$/TLB miss 与 PTW 背压、FQ full、两条 RVC CFI 的 BJL 迟到、跨 word/page CFI 的高半字 fault/replay、WB commit+redirect/rollback、最后一条 CFI，以及 clear 落在 WAIT/READY/S1/S2/FQ/handler 的交叉时序。
4. 验证 normal/privileged、interrupt/nested trap/matching xRET、管理 special JALR、快速 slot 复用，检查 seq 不变、旧 END/DATA 不进入新 owner、BJL reserve/commit/rollback 守恒。CFI head 永久不匹配只能按既有超时诊断取消，不能强制消费。
5. 前端单 descriptor 增加每次 checker fetch 的分类/等待延时；本轮不新增性能优化、不放宽 watchdog。确认完整 benchmark 输出和既有 snapshot/LSL/drain/barrier/TL/token 回归。v1Config 以外的 latency=1、fetchWidth=1、VM/hypervisor/ITIM/clock-gate 参数尚未实际生成或运行。

### 4.5 最终 diff 与生成 RTL 复查

生成 RTL 抽查对象为隔离目录 `gen-collateral/{Frontend,IBuf,Rocket,R_BJLR}.sv`：checker_emit 只读 READY/clear；checker_resp 在 capture/classify/reserve 时写入，READY 背压不改变；fault replay 有 cache-valid 限定；clear+checker S1 清 S2 valid；held capture 排除 redirect；BTB valid 在 redirect/checker S1 撤销；IBuf nIC/endMask shift/完整指令归属与源码一致；Rocket ownership 逐级按 ctrl_kill 清除、commit 为 wb_valid&owned；ack 只进入 local cleanup/handoff；R_BJLR resident ready 与 commit+rollback post-commit 分支一致。FIRRTL 检查通过不替代这些接口的运行语义验证。

最终 `git diff --check -- chipyard` 通过，staged diff 为空，HEAD 不变。`git diff --binary -- chipyard | sha256sum` 为 `6535a959189cfbfe5a9b085b11d4857191ef5db4c90e8b990775b6948c3510a7`。该 hash 包含接手前的所有 chipyard 修改，不是四文件 task-only hash；RocketCore 相对 HEAD 的 diff 同样包含既有修复。没有改动原失败证据或撤销无关变更，没有提交。最终生成进程与之前中断 simulator build 的进程组均已退出。

结论：经独立核实并纠正后的方案已实施，目标配置通过编译及真实 FIRRTL/RTL 生成；目前是**可供用户运行验收的补丁**，不是“1769000 整机死锁已通过仿真修复”的结论。

## 5. 2026-10-10：459000 回归后的方案收敛（未实施）

**结论：当前 first-bad 是本次 Frontend redirect patch 的 regression，同时违反原 spec 和本 review 第 2 节第 2 项的 redirect 生命周期约定。** 旧 e4 重复 ret 的证据和局部 deadlock 判断仍成立；当前补丁不能作为已正确实现该修复的实现。第 4 节的编译/生成记录仍有效，但其中“状态生命周期闭合”“legacy 语义保留”的静态判断不完整，本节更正这些判断。当前运行在首次包 admission 前已经损坏普通启动指令流，不能用它验证 e4 修复成功或失败。

本轮只完善方案、追加本文；没有修改 Scala/C++/软件、生成 RTL、编译或运行仿真。用户继续负责动态验证。

### 5.1 当前证据身份与 first-bad

- HEAD 仍为 `fbca5d0c5ee2a65575ad2b283c7219103684169a`；chipyard diff SHA256 仍为 `6535a959189cfbfe5a9b085b11d4857191ef5db4c90e8b990775b6948c3510a7`。
- 当前 `chipyard/sims/verilator/output/chipyard.TestHarness.v1Config/test.log` 为 548 bytes，2026-10-09 20:44:37 +08；断言是 `[459000] BoomCore.sv:6894/assert__assert_21`，BOOM idle watchdog。历史同名 459000/assert22 报告不是本次运行。
- 同目录 `test.vcd` 实为 FST，172408906 bytes，2026-10-09 20:44:38 +08，范围 `0..918330`。下表为原始 FST 时间，不是架构 cycle；checker 上升沿间隔为 4，BOOM 为 2。
- 当前 generated `Frontend.sv` 与隔离目录 `Debug/1769000_build/generated/gen-collateral/Frontend.sv` 逐字一致，SHA256 均为 `9aae476c13ae6ae2605c0b6d7d65f4890371c2eed7f2f7705cebd15d2dd7485d`。保存波形、当前源码与生成逻辑可对应；本轮没有覆盖证据。

checker 1 层级：`TOP.TestHarness.chiptop.system.tile_prci_domain_1.tile_reset_domain_tile`。

| FST 时间 | 直接观测及解释 |
|---|---|
| `360509` | `wb_valid=1`，PC=`0x800034ec`、inst=`30471073`（`csrw mie,a4`），`wb_reg_flush_pipe=1`；redirect target=`0x800034f0`。此时 checker_mode=0、seq=0、checker_request=0，是普通启动流。新 bubble 令 ICache req.valid=0，而旧 `s2_pc=0x80003508`、replay 成立。单独出现 bubble 是合法设计选择，错误在后续身份未保存。 |
| **`360513`** | req.valid 已撤销；`s1_pc=0x800034f0` 但 `s1_valid=0`，没有目标请求被接受。`s2_valid=0`、旧 `s2_pc=0x80003508`、`s2_replay_REG=1`；ICache req.valid/ready 均为 1，地址却是 `0x80003508`。这是最早已定位的确定坏请求状态。 |
| `360677` | FQ fire 交付 `0x80003508`、data=`00271713`、replay=0。 |
| **`360689`** | WB 执行 `0x80003508: slli a4,a4,2`，结果=`0x20`。退休流由 `0x800034ec` 跳至 `0x80003508`，这是明确的架构 first divergence。 |
| `360693` | `0x8000350c: sw a5,0(a4)` 触发 store access fault，cause=7、mtval=`0x20`。 |
| `365661` | 后续出现 instruction access fault，地址=`0x7fffd4a8`，进入嵌套异常链。 |
| `394049` | BOOM 分配 seq=1，active seq=1、owned1 对齐；不是旧 allocation/active seq 错位起点。 |
| `394069..394089` | DATA anchor 到达但不接受；checker seq=0、excpt_mode=1、admission=0。ARF CDC 随后满，RSU merge_counter 停在 8、big_hang=1。 |
| `918329` | checker active/start_pending=0、seq=0、excpt_mode=1；无包级 timeout、无结果/release；BOOM idle watchdog 达阈值。clear_pending=0、clear_ack=1，clear ack 不是这里的 admission 阻塞原因。 |

被跳过的六条指令位于 `0x800034f0..0x80003504`：读/写 mstatus、读 mhartid、`lui a3,0x800`、`add a4,a4,a3`。缺少这些初始化后，`slli` 使用旧 a4 而得到 `0x20`，下一 store 访问错误地址。`Software/Test/hw/interrupt.c:117` 的同步异常处理只为 cause=11 推进 mepc，cause=7 原地返回，因此该 store 的重试循环可由软件直接解释。

完整 causal chain：

```text
普通 CSR flush redirect 指向 0x800034f0
  -> bubble 阻止当拍接受；旧 S2 replay 因 !s0_valid 被延续
  -> 目标只写进一个无 valid 的 s1_pc，没有 pending 身份/保持协议
  -> req.valid 撤销后，旧 s2_pc 重新赢得 npc/ICache 地址选择
  -> 六条初始化被跳过，slli 计算出 0x20
  -> store access fault；handler 不推进该 cause 的 mepc，重试并出现后续嵌套异常
  -> checker 不具备 clean context，首个 DATA anchor 无法 admission
  -> ARF CDC 背压，RSU merge 无法完成，BOOM 停止正常 dispatch/commit
  -> 无 checker result/release，BOOM idle watchdog 在日志约 459000 触发
```

请求丢失、错误退休、首个 fault、admission/CDC/RSU/末态为直接证据；cause=7 原地重试有波形和软件支持。后续每一次异常导致的全部寄存器破坏未逐条重建，不把 `0x7fffd4a8` 当成另一处已独立定位的首因。

分类为 **patch regression + spec/实现不一致**。旧 snapshot invalid-head PC、LSL payload 消失、drain final 漏计均不是本次已定位起点：当前错误早于首包 allocation，checker 尚未接受 LSL 包；没有证据认定那些旧 first-bad 重新出现，也不声称当前短运行覆盖了它们的全部回归。原 e4 root cause 不因此推翻，暴露的是本次实施/静态 review 对普通 redirect 生命周期的分析遗漏。

### 5.2 实现偏离 spec 的具体位置

以下为本轮核对时的源码行号，路径均为 `chipyard/generators/rocket-chip/src/main/scala/rocket/Frontend.scala`。

| 约定 | 当前实现 | 判断 |
|---|---|---|
| spec §6.4/228：redirect 取消旧 request，下一请求使用 req.bits.pc；review:21：先锁存 redirect PC，下一周期按新模式接受 | :174 禁止当拍请求，:204 仍每拍覆盖 s1_pc；:262 只在 live req.valid 时选目标，没有 pending valid 或保持到 fire | **直接致因偏离**：PC 的数值保存不是一个有效的待接受请求。 |
| spec §6.4：旧 request ownership 在 redirect 后不可影响新路径 | :201 的 replay sticky 在 bubble 下存活；:202 下一拍仍以旧 s2_pc 为重试地址。redirect 只清 checker descriptor/owner/partial（:593），没有取消 ordinary replay | **直接致因偏离**：新增 bubble 与未修改的旧 replay 优先级组合，复活了已被 core 撤销的路径。 |
| spec §6.4/231：按真实接受事件对齐身份；review:21 的 S1/S2 身份要求 | :178 ordinary s1_valid 是尝试 valid，checker 才用 fire；:216 无视 s1_valid 而置 s2_valid；:256 另用 RegNext(s1_valid) 筛交付 | 普通路径本来有尝试/重试语义；增加 redirect bubble 后，未定义新目标何时正式进入该流水。pending 等待期不能生成 ghost S2、翻译 fault 或使旧 replay 杀新 S1。当前波形先证明目标丢失，尚未证明另一次 ghost fault 消费。 |
| review:21：新目标按接受时的新模式处理；FrontendReq 还含 speculative | :210 的 redirect speculative 只在当拍采样，并可被 checker_request 覆盖；下一拍未持有一个 redirect 请求的完整属性 | 需保存 PC 与 speculative，checker 属性在 bubble 后真正接受时 capture。当前 first-bad mode=0，无需 mode 切换也能触发。 |
| spec §6.4/233：response 不因 live mode 改释 | checker S1/S2 owner 与 descriptor 已 capture，但 :257 legacy_emit 还依赖当前 checker_state；:287 BTB lookup 使用 live checkerMode | 这是模式交叉时必须核验的限制。当前 first-bad 属普通启动 redirect，不能把此限制冒充已观测致因。修正时必须证明模式交叉有真实 redirect kill 或旧响应能按原 owner 完成；仅加 PC mux 不提供这个证明。 |

review:21 自身还有一个需要修正的设计假设：**新模式不一定在 redirect 后一个边沿就就绪。** 普通 self exception/xRET 直接驱动 ICSL 转移；但 `RocketCore.scala:1169` 的 privileged 启动为 `icsl.io.if_check_privrun := RegNext(check_exception)`。当周期 R 的 check_exception 发出 redirect 时，R+1 才出现该启动输入，R+2 才进入 `R_ICSL.scala:205` 的 checking_priv。因此接受时读 live mode 是必要条件，却不能把 R+1 无条件当成已稳定新模式。这个时序风险来自源码推导，当前普通启动 first-bad 不需要它即可解释，不能冒充当前 FST 证实的第二首因。

spec 的 FETCHING miss 自循环，实施编码为 FETCHING→EMPTY→重试，**不必视为功能错误**：单 descriptor、同 PC/seq、固定请求阶段结束、不 reserve、PTW 不因空拍被 kill 时，两种编码等价。共用一个 checker_fetch_seq 也可替代逐级 seq 寄存器，前提是 busy 生命周期内 owner 不换；现有 seq 断言只能检查该前提，不能替代 redirect 目标的有效性。prefixLength/endMask、owned WB commit、post-commit rollback、DATA/END/count 未发现本次首因所需的语义偏离。

### 5.3 收敛后的 Recommended Fix

**只在 Frontend 内补齐 redirect 请求从 capture 到 ICache acceptance 的生命周期，以及该边界的 replay/S1/S2 接续。保留现有 checker descriptor、前缀、BJL reservation/commit、包 clear 协议。** 不恢复旧 checker S1 reserve/S2 退项，不改 LSL、snapshot/drain、count、safe 或 watchdog。

最小新增状态：`redirect_pending: Bool`（reset=false）、`redirect_pc: UInt(vaddrBitsExtended.W)`、`redirect_speculative: Bool`，以及 `redirect_settle: Bool`（`RegNext(io.cpu.req.valid, false.B)`）。PC/属性只在 pending 有效时使用，不需要新跨模块 IO、CDC token、FQ flush 信号或第二套 fetch descriptor。settle 使 R+1 不发目标请求，最早 R+2 接受，以覆盖当前 privileged 启动的注册延迟；相比原 review 多一个 ordinary redirect 等待周期，是本次明确修正的规格，不隐含声称原一拍假设正确。若后续更改 core 模式转移延迟，需要重新核对此条件，不能把固定拍数当通用模式握手。

1. **真实 redirect 为最高顺序优先级。** 在 `io.cpu.req.valid` 的采样边沿 capture `alignPC(req.bits.pc)` 和 `req.bits.speculative`，置 pending；保留当拍不发 ICache 请求的 bubble。新 redirect 覆盖尚未接受的旧 pending。沿现有 FQ reset/IBuf kill/ctrl_kill 撤销旧路径，BJL rollback 仍保留同拍真正退休项的 post-commit 点。
2. **目标保持到接受，模式先 settle。** 地址选择优先级为 live core redirect → registered pending target → 原 checker/legacy NPC。pending 期间 PC/属性不依赖 ready、旧 prediction、live req.bits 或 s1_pc 的空拍更新；`redirect_settle` 有效时不发 ICache 请求，消除 delayed privileged start 尚未进入新状态的窗口。pending 仅在目标 `icache.io.req.fire` 后释放，不能在 req.valid、ready 单独为 1 或 resp.valid 时释放。接受时以当前 `checker_request` capture checker/legacy 身份和 seq；checker speculative=false，普通目标使用保存的 speculative。不锁存 redirect 当拍旧 live mode。请求 valid 不通过 ICache ready 生成。
3. **旧 ordinary replay 在边沿取消。** 将匿名 RegNext replay sticky 改为可明确更新的寄存器，保留原 reset-vector 启动语义；真实 redirect 清该 sticky。在 pending 启动等待期保持它为 0，旧 S2 valid 同时撤销。不要用组合 `!req.valid` 去门控 legacy_emit/checker_emit 或把取消反馈到 FQ valid；那会重建已发现的 flow-FQ/IBuf/req.valid 组合环。
4. **pending 启动期不制造流水身份。** redirect 之后到首次目标 fire 的等待期，S1 valid 来自真实 fire；未 fire 时 S1/S2 valid 均为 0，不发旧 S1 的 TLB/BTB lookup，不以空拍把 S2 重新置 valid。实现上可局部覆盖 pending 期间的 `s1_valid` 更新和 `s2_valid` 下一状态；pending 在 fire 边沿释放，下一拍已有有效目标 S1，沿现有 S1→S2 路径捕获目标 PC/speculative/TLB response。无需全局重写 ordinary 流水。
5. **移交后沿原 miss/retry 机制。** pending 只拥有“尚未被接受的目标”；fire 后由现有 S1/S2/descriptor 接管，不能继续拿 pending PC 压住后继。目标 I$/TLB miss 可以再次请求同 PC，但不生成额外 FQ 正常交付、不重复 BJL reserve。checker 的空拍不 kill PTW 修复、fault replay 的 cache-valid 限定、latency=1 response 保持继续保留。
6. **清理和 handler 不新增等待环。** checker_clear 仅取消旧 checker owner/descriptor，不能无条件删除一个 pending redirect target 或无目标杀 handler FQ/IBuf；清理时的新请求按接受时属性进入 ordinary 路径。pending 不进入 exec/tail/ARF completion gate，也不要求 clear ack 才能发 handler 请求。clock_en_reg 增加 pending，保证等待/接受期间时钟运行。

为何不把所有 ordinary `s1_valid` 改为 req.fire：基线 ordinary 前端用“尝试请求”的 S1/S2 和 replay 保持未接受的取指尝试。若同时改为 fire、仍保留每拍 s1_pc/predicted_npc 更新，普通顺序请求遇 ready=0 时可能跳过该 PC。此轮只把 **redirect pending 的启动阶段**绑定到 fire；移交后的 ordinary 尝试/重试结构保持。任何全局接受流水改写都需要另外证明未接受请求的 PC 重试，不能作为本轮顺带修改。

逐拍约束（R 为真实 redirect 周期，L 为其目标实际被接受的周期；L 最早为 R+2，可因背压更晚）：

| 周期 | 必须成立 |
|---|---|
| R | 不接受新 ICache 请求；边沿 capture 目标、作废旧 fetch valid/replay/partial/BTB 身份；WB commit+rollback 保留 post-commit。 |
| R+1 | pending 稳定、settle=1，不发目标请求；delayed privileged start 可在本拍输入 ICSL，边沿更新新状态；无有效旧 S1/S2。 |
| R+2..L 前 | settle 结束；可请求目标但 ready=0 不推进身份；S1/S2 无有效旧事务、无 ghost fault/emit；新 redirect 可替换目标并重新 settle。 |
| L | ICache fire 的地址恰为最新 pending PC；PC/speculative 与 request owner 一起 capture；一次 fire 释放 pending。 |
| L+1 | S1 PC 为目标，TLB vaddr/I$ S1 地址身份对齐；旧 replay 不能 kill 它；checker/legacy 身份使用已 capture 的请求属性。 |
| L+2（latency=2） | S2 PC/TLB/I$ response 同属目标；hit/fault 可按原规则交付，miss 只启动该目标的合法 retry。 |

连续 redirect、ready 低/FQ full、ordinary↔checker、CSR flush、interrupt/xRET、special JALR、checker_clear 与 handler 并发，都遵守这一优先级。不要通过一次普通请求的数值 PC 与 pending PC 相等猜测“已经接受”，必须使用具体 pending request 的 fire。对 BTB/partial/GPA 的更新使用有效请求/有效交付事件；取消拍 FQ 组合 fire 不算架构交付。

### 5.4 原 deadlock 机制与旧修复如何保留

- **Exactly-once 机制保留。** redirect pending 不读/消耗 BJL；完整 response 后仍 CLASSIFY→WAIT→resident exact-match reserve 一次→READY held→FQ fire 一次。endMask 经 IBuf 拼接后只让 owning CFI 在 WB 真退休时 commit。rollback 仍撤销年轻 reservation、保留已退休前缀；合法重新取指与同一未回滚路径的重复交付区别不变。
- **LSL 旧问题不重新打开。** 不改 SyncReadMem 预取/稳定 head、type/address/size 匹配或 req kill，不强制 dequeue，不放宽 quiescent。修正使取指执行到相应 memory 指令后按现有合法请求消费；没有新增 LSL 等 pending、pending 等 LSL 的边。
- **snapshot 旧问题不重新打开。** 不改原子 allocation、active seq、空 ROB/注册 quiet 或有效架构 next-PC。Frontend 新 PC 来自真实 core redirect 的 req.bits.pc，不从 BOOM invalid ROB head 取值；不放宽 clean-context admission。
- **drain/count 旧问题不重新打开。** 不改稳定 producer owner、drain 退休计数、真实 seal/final、同 DATA 队列 ordered END。normal N+1/privileged N、tail/PASS/safe 均保持，不能靠调大 count 补偿前端错误。
- **清理关系保留。** clear ack 只控制 result handoff/slot reuse，管理 return 不等 ack；不恢复 already_done 提前 reset BJL，不新增“先清完 pending 才能 exec_done”的条件。

这是对修改边界和依赖边的机制论证，不能把“未改那些文件”单独作为动态无回归证明。前端延时改变仍须在用户的新运行里观察 snapshot/LSL/drain 边界。

**原 e4 forward-progress invariant 在修正后可继续作为条件性设计不变量；当前实现已破坏其 redirect 前提，不能宣称当前满足。** 前提是合法有序源记录、clean admission、各时钟运行、TL/CDC/PTW 最终响应及背压最终解除：pending 只等 fetch 接受；miss 不 reserve/不重复消费；CFI 前普通前缀先执行，释放更早 DATA；BJL reserve 后只等 FQ，不等下一个 BJL head 或 WB commit；后一请求只从实际未交付后缀/target 开始。e4 的额外 ret 因而不再用掉最后 load 的执行预算，4074 源指令加正常 startup 对齐 4075，最后 load 能先匹配消费，再进入 tail/quiescent/PASS。该结论需要新动态 PC/机器码对齐验证，CANCEL 或越过 watchdog 均不是成功证据。

### 5.5 独立问题：allocation → checker admission timeout 缺口

该缺口与 redirect regression **不合并实现**。当前链中 regression 先破坏启动 context，再暴露此缺口；两者不构成同一根因。

BOOM 已 owned seq=1，但 `RocketTile.scala:220..247` 只有 DATA 真正 accepted 才给 core seq pulse；`RocketCore.scala:1356` 因异常 context 不允许 admission，于是 active/start_pending=0、seq=0、pending_package_seq_valid=0。包级 timeout（:1492）只在 package_owned 时有效，且 :1656 在无 owner 时清 counter，因此 pre-admission allocation 无法用它 CANCEL。末态 timeout=0 与源码相符。

后续应独立定义从 BOOM allocation 到 admission/result/release 的序号归属及 bounded failure 路径，考虑晚到 DATA/ARF、handler 永久不能返回、CANCEL 的 seq 身份与一次 release。这里不提出放宽 admission 或把未消费 anchor 当成已完成包，也不宣称现有 timeout 已覆盖全 allocation 生命周期。

### 5.6 实施前后的验收约束

下一次实施的预期功能范围为 `Frontend.scala` 的上述局部状态/时序，含明确的 settle 位；IBuf、RocketCore owned commit、R_BJLR 与其余旧修复保持。当前 delayed privileged start 是增加 settle 的具体源码依据。模式交叉若不能证明“redirect 杀旧事务或按 captured owner 完成”，应先补充具体证据和设计，不能静默扩大 ordinary producer 重写。

静态审查必须核对新状态初始化/位宽、last-connect 优先级、pending only-fire 消费、同拍新 redirect 优先、S1/S2/TLB/cache/BTB 对齐、无新增 req.valid→FQ valid 组合边、clock gate 和 clear/handler 生命周期。编译/FIRRTL 通过后仍需用户动态验证：首先 `0x800034ec` 后正确执行 `0x800034f0..0x80003504`，再检查 e4 非重复 ret、最后 LSL load、严格 count/tail/PASS/release/safe 链；同时覆盖 ready 低、miss、连续 redirect、模式/clear 交叉与已有 LSL/snapshot/drain 回归。latency=1 等未验证配置继续是显式风险，不能借当前 latency=2 证明其成立。

本轮对当前 FST 做只读定点复采样（`/tmp/fst_point_sample`，360509/360513/394073/918329），并复核现有窄 trace、当前 diff、Scala 和 generated Frontend；没有运行仿真、反事实 A/B、编译或重新生成。**Recommended Fix 是待实施方案，尚无修正后的动态通过证据。**

## 6. 2026-10-10：Recommended Fix 实施与复核

本轮按用户授权实施第 5.3 节方案。功能修改仅在 `chipyard/generators/rocket-chip/src/main/scala/rocket/Frontend.scala`；本节为实施记录，不将第 4 节旧构建或保存的 459000 波形当作本轮通过证据。没有运行模块或整机仿真。

### 6.1 实际修改与范围

- 增加 reset=false 的 `redirect_pending`、`redirect_settle=RegNext(req.valid,false.B)`，以及由 pending 有效性保护的 `redirect_pc` 和 `redirect_speculative`。地址选择为 live redirect → pending target → 原 checker/legacy NPC。
- `req.valid` 优先 capture/覆盖目标，只有 `redirect_pending && !redirect_settle && icache.io.req.fire` 消费 pending；ready 单独有效、发请求尝试或 response 均不释放目标。R 和 R+1 不发请求，目标最早 R+2 被接受，背压时 PC/属性继续保持。
- pending 启动期 S1 valid 只取真实 fire，PC/speculative 只在接受时进入 S1；S2 下一状态强制 invalid，停止空拍重新制造有效 S2。接受时 checker 身份/seq 使用现有 fire capture，普通 speculative 使用保存值；移交后恢复原 ordinary attempt/replay 和 checker descriptor 流水。
- 匿名 replay `RegNext` 改为 reset=true 的显式 `s2_replay_reg`，在真实 redirect/pending/settle 边沿清零，其余周期保持原递推。保留 reset-vector 启动及 fire 后 miss/retry，不把 pending 保持到 response。
- pending/settle 期间禁止旧 S1 BTB lookup、taken prediction 和 BTB response valid 的复活；真实 redirect 沿原清理规则杀 partial/wrong-path/GPA/checker descriptor/owners。TLB lookup 无新增门控，等待期由已清除的 S1/checker owner valid 关闭。clock-enable 保持条件增加 pending/settle。

未改变 FQ enq valid 表达式、ICache/TLB 接口、checker 分类/前缀/endMask/reserve/commit/rollback、clear ack、completion gate、LSL、snapshot、drain、DATA/END/count 或 watchdog。allocation→admission timeout 缺口仍作为第 5.5 节的独立问题保留。

### 6.2 生命周期、时序和组合环复核

| 事件/周期 | 源码复核结果 |
|---|---|
| R 真实 redirect | `s0_valid=0`，没有 ICache fire；capture PC/speculative、置 pending、下一 settle=1；S1/S2 下一 valid=0，replay sticky 清零，旧 checker owner/descriptor 最后连接清除。FQ reset/IBuf kill 和 BJL post-commit rollback 沿原机制执行。 |
| R+1 | pending=1、settle=1，继续不发请求；S1/S2 无有效旧身份，TLB req 无有效 S1，BTB request/capture/prediction 被 pending/settle 隔离；delayed privileged start 在本拍更新 ICSL。 |
| R+2 到 L 前 | settle=0，目标地址恒为已保存 PC；ICache ready=0 时不 capture S1、不释放 pending、不产生 ghost S2/正常 FQ 交付；不等待 BJL、LSL、tail、result 或 clear ack。 |
| L 目标 fire | 同一次 ICache fire capture S1 PC/speculative 和 checker owner/seq，消费 pending；仍将 S2 下一 valid 保持 0，不能把此前无效 S1 装成目标 response。新 redirect 优先覆盖目标并重新 settle；因 req.valid 禁止发请求，该事件不会与旧目标 fire 并发。 |
| L+1 | pending=0、目标 S1 valid=1，TLB vaddr 与 ICache 内部 fire capture 的 S1 地址对齐；replay sticky=0、S2 valid=0，旧 replay 不能 kill 首次目标 S1；边沿捕获目标 S2 PC/speculative/TLB response。 |
| L+2，latency=2 | 目标 S2 与 ICache response/translation 身份对齐；hit/fault 沿原交付，miss 沿原同 PC retry。pending 已释放，不压住后继 PC、不另行 reserve 或等待 response。 |
| checker clear/handler | clear 不写 pending PC/valid，不取消 ordinary handler 的 S1/S2；checker_request 在 clear 时为 false，既有 owner/descriptor 清理保持。pending 未加入 exec/tail/ARF/clear-ack gate。 |
| reset/连续 redirect/clock gate | pending/settle reset=false，PC/speculative 只在已 capture 的 pending 下使用；replay reset=true 保留原启动。每次 redirect 可替换未接受目标并重启 settle；等待与接受期间保持 gated clock。 |

**TLB kill 保持实施前语义，没有增加 redirect 的第二个 in-flight owner。** 核对 `TLB.scala:666..693`：L+1 的 miss fire 在 `s_ready` 中置 `s_request`，`io.kill` 只取消已经处于 `s_request` 的 walk，或使 PTW request 的 bits.valid=0。L+1 虽然 ordinary `!s2_valid` 为 1，但此时没有由该目标产生的旧 `s_request`；L+2 已有目标 S2 valid，因此其 walk 可沿原规则继续。checker 空拍不 kill PTW 的既有修复保持。不能把 `!s2_valid` 无条件等同于“取消同拍首次 translation”，也不能为此给 ordinary handler 增加 checker_clear kill。本论证不扩展为所有 ordinary PTW 背压都已验证。

组合依赖方面，fire 只更新寄存状态，未用于生成同拍 request valid；pending/settle 对 S1/S2/replay 的取消均在寄存边沿生效。没有增加 `req.valid→legacy_emit/checker_emit/FQ enq.valid` 的组合门控；READY valid、FQ flow 和 IBuf 路径保持原样。BTB response 本身不以 req.valid 归零，因此等待期还显式隔离 prediction 和 response valid capture，不能仅关闭 `btb.io.req.valid`。

### 6.3 本轮静态构建与证据隔离

实际使用新目录 `Debug/1769000_redirect_build/generated`，日志为 `Debug/1769000_redirect_generate.log`；构建目标仅为 RTL file list，不构建或运行 simulator。2026-10-10 14:25:33 +08 完成，make exit=0：本轮 Frontend Scala 编译、v1Config Chisel elaboration、Scala FIRRTL `-X low`、firtool `--verify-each=true`/`CheckCombLoops`、RTL 导出和 all.f 生成全部通过。保留原有 unused/feature 和未消费 annotation 警告，没有初始化、位宽或组合环错误。日志中 sbt 将子 JVM stderr 的 `Picked up JAVA_TOOL_OPTIONS` 标为 error，该行不是编译失败，最终 lowering 和 make 均成功。

```sh
cd /data1/gzh/EC/chipyard
source ./env.sh
JAVA_TOOL_OPTIONS='-Xmx16G -Xss8M -XX:ActiveProcessorCount=8 -Dsbt.supershell=false' \
make -C sims/verilator CONFIG=v1Config \
  build_dir=/data1/gzh/EC/Debug/1769000_redirect_build/generated \
  /data1/gzh/EC/Debug/1769000_redirect_build/generated/chipyard.TestHarness.v1Config.all.f
```

实施前 Frontend 可由 `/tmp/frontend.diff` 与 HEAD 精确重建，Git blob 为 `0ae842a332e9176d07467d37441d0b418cea1078`。已对照该底座审查本轮增量，未将最初 1769000 实施的整个 Frontend diff 误记为本轮修改。移除空白后逐段比较确认 TLB/ICache miss-kill、checker descriptor/BJL/clear/response connect、GPA/performance 块保持相同。

生成 `Frontend.sv` 复核：`redirect_accept=pending & !settle & ready & s0_valid`；pending 下一状态为 `req.valid | (!redirect_accept & pending)`，PC/speculative 仅在 req.valid capture；NPC 为 live redirect/pending/checker/legacy 四级选择；S1 pending 分支带 ready/fire，S2 更新先受 redirect/pending/settle 与既有 checker-clear owner 条件取消，S2 PC/TLB/speculative 同 enable 捕获；replay reg reset=1，取消优先于原递推；BTB valid/prediction 等待期隔离；FQ enq valid 仍为 `checker_emit | legacy_emit`，TLB kill 仍为 checker-flow/ordinary 原选择。对应 generated IBuf 和 R_BJLR 与上一轮隔离生成物 SHA256 分别完全一致：`a144d43b09e6ccfc2a006e14fa3536f2702524ffcf70141f9c2e8d932fe344f2`、`cfd059e6c9b17291398424db6ad1eff318cc888acdc97cf48d7c8c5e25ada168`。

最终身份和 diff 核对：

- HEAD 保持 `fbca5d0c5ee2a65575ad2b283c7219103684169a`，staged diff 为空，没有提交或撤销已有修改；`git diff --check -- chipyard` 通过。
- Frontend 最终 Git blob：`7561cd5989df6a583c57ccf66553cc5e7fc0dd72`；源码 SHA256：`0c63607174ea86d50a7ec909e9017958f100638975a9f9a29fc644a949ab0957`。
- 最终 `git diff --binary -- chipyard | sha256sum`：`0a546f121f8650008cd79ac60cc942bac9039058ec0e43c4a1d78022084079c0`。排除 Frontend 后的 chipyard diff hash 在本轮静态构建前后保持 `d0a048c2e96d26a06e1ff0452bb5b56a6ff6e6f5230af44e741f1ab817f06e3c`。
- 本轮新生成 `Frontend.sv` SHA256：`76d63a9ab10e99c6242b1c8b1b3e2b2d8d919dc84a63914a60a85f524010590f`；旧 `sims/verilator/generated-src/.../Frontend.sv` 保持 `9aae476c13ae6ae2605c0b6d7d65f4890371c2eed7f2f7705cebd15d2dd7485d`。旧 test.log/test.vcd 的大小与 2026-10-09 20:44 时间戳保持不变。
- 本轮 make、sbt、lowering JVM 和 firtool 进程均已退出。没有启动 simulator build、模块仿真或整机仿真。

### 6.4 剩余风险与运行验收

本轮静态论证保持原 e4 forward-progress 条件：pending 只等目标接受，不新建 BJL/LSL/完成等待边；fire 后 miss 不 reserve、普通前缀先交付、reserve 后只等 FQ、返回不等 clear ack。LSL、snapshot、drain/count 的有效事件和严格完成条件保持。此为机制和修改范围审查，不能代替动态无回归或 exactly-once 证明。

用户新运行首先验证 CSR flush 后 `0x800034f0..0x80003504` 正确执行，再验证原 e4 类似序列没有重复 ret、最后 load 合法消费、count/tail/PASS/result/release/safe 全链完成。定向边界继续覆盖 ICache ready 低、I$/TLB miss/PTW 背压、FQ full、连续 redirect、ordinary↔checker、delayed privileged start、interrupt/xRET、special JALR 和 clear/handler 交叉，并复查既有 LSL/snapshot/drain 边界。

`redirect_settle` 依赖当前 core/ICSL 的模式转换延迟；若未来增加转换级数，必须重新检查最早接受拍。当前配置的编译/生成不能外推为 latency=1、VM/hypervisor/ITIM 或 clock-gate 配置的动态通过。allocation→admission timeout 覆盖缺口未修复，不能宣称所有分配失败路径均有 bounded CANCEL。
