# 两个 MSHR drain phase 关闭 secondary admission（2026-10-14）

结论：最小修复、静态证明、完整 v1Config compile/elaboration/FIRRTL/SV/CheckCombLoops/Verilator build 和五个短 RTL 场景通过，**可以进入最终大仿真**。本轮没有运行长仿真、修改 build flags 或提交 git。

## 根因与方案

s_drain_rpq_loads 普通 load 虽直接经 LineBuffer 响应，仍先进入 RPQ。旧状态允许新 secondary、出口依赖 empty/non-load head，故持续 polling 可以维持正 occupancy，read MSHR 不退出且 writer 无法重竞争。

统一 drainAdmissionClosed=state.isOneOf(s_drain_rpq,s_drain_rpq_loads)，复用已有 sec_rdy gate。
本轮唯一硬件文件 mshrs.scala:157–177，增量5行替换：一个 Bool、两行注释、两条 assertion 文案。
已有 no-secondary-accept/no-enqueue.fire assertions 自动覆盖两个状态；没有新增历史寄存器/counter。

## 范围与 provenance

HEAD a68183c83e08ed837c677aec7836c97895e3a95e + 原有 dirty Phase-1。
修改前 mshrs.scala SHA256 53a3b2795cccc92268f41b9542fdc248079f6785496a27af875f1c650727ef3b。
修改后 SHA256 594b0a9bc4d990d8a0b9c16a010fa41268adf6fa99c66c98b632eedb4e02123f。
1461 Scala 来源逐文件hash检查仅 mshrs.scala变化；撤销五行替换后精确恢复本轮基线。
完整 git diff 相对HEAD为 +334/-48，含原已有 Phase-1；本轮增量是 +5/-5，不能混淆。
本轮另新增本报告/bug记录，更新current state与timeline；其他原有dirty文件保留。
生成物和最终binary在独立 AI/TMP 目录；未覆盖旧默认 simulator/生成物。

## 静态进展与正确性

进入任一drain后 primary ready=false、secondary ready=false，RPQ唯一producer无valid，外部工作集不增长。
state3普通load继续deq→LineBuffer response→retired；branch kill按原queue discard；遇非普通load头进入s_meta_read留后续replay。
empty/commit_line=false时原no-enqueue条件自然成立，commit_line=true时原empty出口也成立。Q=1→dequeue1/enqueue0→Q=0，下一拍可退出。
state12仍保持issued head与immutable inflight直至matching terminal；RETRY不新增entry，仅清attempt后重发。
publish仍是empty && !enq.valid && !replay_inflight，未放宽metadata/DCache functional drain guard。
收敛前提：下游服务有界、replay有限RETRY后terminal；永久背压/无限RETRY不由此修复排除。

BranchKillableQueue hold/discard、branch kill/exception条件没有改；生成BranchKillableQueue.sv与修复前逐字一致。
enq.ready仅依赖寄存full，没有deq.ready组合反馈；完整CheckCombLoops通过。
existing RPQ、replay/terminal ownership、rowValid/rowData/install_row_read_fire、transaction/epoch/generation、LineBuffer均逐字保留。

被拒secondary在MSHRFile req.ready=false、block_hit仍保持，经DCache s2_nack_miss/send_nack回到LSU。
LDQ匹配token后清executed再wakeup；STQ匹配live functional token后清functional_inflight/succeeded、必要时回退execute head。
无fire则无新增SDQ/MSHR ownership；不silent drop、不新增响应。retry保留原order/coherence/token检查，可能等待多次并合法读取更新的数据。

## 验证

| 项目 | 结果 |
|---|---|
| git diff --check | PASS |
| Scala project boom compile | PASS，1源码增量编译；已有feature/deprecation warnings |
| 完整 v1Config Chisel elaboration/FIRRTL | PASS |
| Scala FIRRTL low lowering | PASS，644秒 |
| firtool verify-each/CheckCombLoops/SV/内存宏 | PASS，已有annotation warnings |
| 完整 Verilator debug/FST/--assert simulator | PASS，退出0，flags未改 |
| 生成RTL | state12或state3→drainAdmissionClosed→sec_rdy；两个assert与publish guard保留，6个MSHR共用 |
| 旧 RTL 对照 | 1000模块周期仍state3，新enqueue1000，accepted1004/retired1000 |
| 新 RTL 5短场景 | 全PASS，两drain enqueue0，所有accepted逐token退休 |

短场景：持续polling、响应/refill/meta/E背压+RETRY、未issue分支取消、issued CANCEL、入口全部load被kill/commit_line=false。
正常state3 drain5模块周期；带响应背压16周期。每场景总88–262模块周期，最终accepted/retired22/22或23/23，无重复退休。
检查普通load数据、rowValid未被普通load污染、refill stall payload稳定、无提前publish；后续store权限upgrade/Trunk直接dirty-drain完成。
fixture使用真实MSHR/RPQ/RAM，环境提供Grant/LineBuffer/metadata/tagged terminal，无真实CPU/LSU/DCache/TL fabric；不将stub APPLIED等同真实STQ/内存可见。
完整Verilator告警只有trace-threads弃用、EICG_wrapper显式clockgate latch；EICG_wrapper.v与修复前逐字相同。模块构建无Verilator告警。

## 剩余风险与下一步

固定同line、无invalidate/eviction时，publish后line resident，polling转hit，不会在每次retire后重建read MSHR；writer保留STQ并获得重新竞争机会。
LSU incoming load优先、15-cycle保护仅抑制load wakeup，MSHRFile lane固定优先：不能证明所有无限外部流量下writer公平上界。此为独立仲裁边界，不阻止当前fix排除drain自续命；未据此扩大patch。
窄扫描未发现第三个同类drain-admission livelock状态；metadata/victim/install等仍开放阶段的退出不依赖RPQ排空，不具有相同producer/exit循环。
尚未动态验证真实LSU/STQ store完成、完整Phase-1或BFS；这些应在下一步最终大仿真观察，不能将缺少大仿真本身列为当前准入blocker。

## 证据与复现

证据目录：`AI/TMP/mshr_both_drain_closure_20261014_165012/`。
- `incremental.diff`：本轮 +5/-5；`mshrs.final.git.diff`：用户要求的完整 git diff（含原有dirty修改）。
- `static-audit.md` / `static-results.json`：各源码路径、状态/queue/retry/fairness论证。
- `build.py` / `build-commands.json` / `build-results.json`：完整顺序构建命令、阶段时间和退出码。
- `rtl-evidence.txt` / `rtl-checks.json`：生成SV中的真实gate/assert/publish证据。
- `module-before-*.log` / `module-fixed-*.log` / `module-fixed-results.json`：旧/新分别记录。
- `scala.before.json` / `final-manifest.json`：来源和最终binary SHA256。

最终binary：`AI/TMP/mshr_both_drain_closure_20261014_165012/simulator-chipyard-v1Config-debug`（63883352字节）。
