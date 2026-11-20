# 最新实际推进（2026-11-11 16:27 CST）

9ae综合内部优化完成，真实单元统计3182510个LUT1–6/89672个CARRY8；工具网表翻译中，正式物理CLB LUT、DSP和顶层post-opt报告尚未产生，不能计算新版本准确FIT缺口。e0及d9完整DCache面积仍运行，未进入物理实现，无认证bitstream/Opt4样本。

d9完整冻结DCache8192周期回归PASS；3656独立字段读优化真实GG/7ABI、完整生成DCache符号结构比较及实际写数据负例PASS（只映射60处相同源码行的诊断行号元数据）。准确异步读端口各561→35/518/4/4，保留512generation观察；无面积收益结论。新完整模块面积请求已排队。只保留一个8d后继等待器，未触碰任何活综合；无人值守第30轮继续，Native暂停，21-only。

真实报告与恢复入口：[REPORT.md](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/opt4-field-cycle-and-successor-20261111T074000Z/REPORT.md)。以下旧状态保留为历史。

# 最新执行（2026-11-11T07:13:24.854581+00:00）

9ae9a7fc已完成Timing Optimization并进入Technology Mapping；e0正常DUT综合。二者仍无新整机资源报告/FIT结论。d9真实GG/7ABI、生成存储512正向+4真实写数据负例通过；完整DCache实际综合已启动。完整cycle-r3 C++接口失败保留，r4已修复Verilator端口编码/宽向量API并复用原模型实际编译，未改RTL。新8d50489a精确组合预检通过，prep-r2实际托管等待真实面积+完整周期门，随后自动GG/ABI/CAD/21only认证。未开第三整机，Native暂停。

最近完成整机仍旧8da：3215683LUT/92789CARRY8/195DSP，旧版超U2801912003LUT，不能当9ae/e0结果。完整DCache面积和当前FIT缺口尚未知，无认证bitstream/Opt4FPGA样本。详见[真实执行报告](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/opt4-field-map-and-next-20261111T070420Z/REPORT.md)。以下保留历史记录。

# 最新实际推进（2026-11-11T06:08:08.840480+00:00）

9ae/e0两条整机综合保持，均暂无新资源/FIT报告。真实生成存储512/512分区形式证明及真实写数据位翻转负例全部通过（存储transition cut，不是完整DCache/整机形式证明）。完整DCache旧评估发现74752bit打包memory的Vivado推断/默认回退上限错误，已保留证据并实际启动独立full-pair-r2恢复，后继prep-r3/CAD-r5已重新绑定且不启动第三整机。

新等价结构候选d9d73262拆为81/32/32/1bit四块物理存储，源关系SAT/改动源码编译/冻结参数通过，实际GoldenGate正在运行，尚无面积或整机准入。最近完成整机仍旧8da：3215683LUT/92789CARRY8/195DSP，超U280 1912003LUT；不能将其当9ae/e0新结果。无认证bitstream、无Opt4 FPGA样本。Native暂停、严格21-only。[最新真实证据与恢复入口](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/opt4-generated-proof-and-progress-20261111T053104Z/RECOVERY_REPORT.md)。以下旧状态为历史。

# 最新实际推进（2026-11-11T05:48:20.759777+00:00）

9ae9a7fc实际完成跨层面积优化并进入Timing Optimization；e0c3737f实际DUT综合继续，均尚无新整机面积/FIT报告。DCache真实GG与7项ABI通过，完整模块匹配面积评估运行；265176→89636LUT仅为保留全部generation观察的存储边界收益。实际生成存储联合SAT超时后，分区证明服务已启动，当前120/512，未完成不记全通过。99c25302组合源码/全部改动编译/冻结参数/地址RTL一致性预检通过；下一整机仍受完整模块面积门和无第三整机限制。

最近完成整机仍8da：3215683LUT/92789CARRY8/195DSP，超U280 1912003LUT。尚无认证bitstream或Opt4 FPGA样本。仅8491167d等价面积优化，Native暂停、严格21-only。真实证据与持续状态：[REPORT.md](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/opt4-generated-proof-and-progress-20261111T053104Z/REPORT.md)。以下历史状态以本条和状态文件为准。

# 最新实际推进（2026-11-11T04:57:48.249009+00:00）

9ae整机保持，e0已在独立8核/128GiB服务中实际进入DUT综合；二者均尚无新资源报告。DCache源绑定组合证明通过、GoldenGate进行中；真实完整DCache匹配面积作业等待该RTL。保留全部generation观察的存储边界265176→89636LUT，节省175540，不能当完整模块或整机收益。e211完整地址正在map。99c25302独立组合及既有21-only认证/runtime模板已准备，但受真实面积/证明门和无第三整机守卫约束，未获准整机。

本轮实际操作、进程身份、资源与完整证据：[REPORT.md](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/opt4-dcache-full-and-dual-dut-20261111T045748Z/REPORT.md)。最近完成整机仍8da：3215683LUT/92789CARRY8/195DSP，NOTFIT。无认证bitstream、无Opt4FPGA样本。Native暂停，仅8491167d功能/周期等价优化，禁止功能扩展与e2/全局设备操作。

# 当前执行范围补充（2026-11-11）：仅8491167d功能/周期等价面积优化

新功能开发已撤销，旧恢复扩展仅保留证据，禁止合入。e0c3737f组合/GG/ABI/13软件准备完成，下一CAD等待活9ae安全退出；1a571775结构候选独立验证。当前真实执行与恢复入口：[REPORT.md](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/opt4-structural-acceleration-20261111T034259Z/REPORT.md)。以下旧状态保留为历史，不能作为当前放行条件。

# Opt4 无人值守实现与实验入口

## 2026-11-11 09:45 CST：SVB组合验证/GG/ABI及13项软件准备完成；持续迭代继续

当前整机 **9ae9a7fc仍在DUT综合**，尚无其真实整机FIT结果。最近完成的8da24a26完整post-opt为 **3,215,683 LUT /1,303,680、92,789 CARRY8、195 DSP**，缺口 **1,912,003 LUT**，已自然停在容量门。

独立 **f2d2ca3e** 已通过源绑定组合证明、完整SVB127输出/4096周期对照、真实类/参数核对、GoldenGate及7项ABI核对，13项软件与Native配对绑定也已实际完成。DCache **51a2bd25** 的生成SAT、8192周期及实际256组×2路类型检查通过；匹配面积排队，完整DCache等价尚未成立。后台第16轮已产生 **27f7e7d6** 复制序列表并通过局部SAT/拓扑/8192向量，待完整对照和面积。

仍无认证bitstream、无Opt4 FPGA样本。综合/验证失败不停止持续优化；保留当前活整机，只接入已证明且有实测显著收益的独立组合。Native继续暂停，严格21-only。完整架构restore/restart仍有真实设计接口缺口，已另列契约，不能把SVB invalidation当作架构恢复通过。

本轮实际操作、版本/资源/失败恢复及自动接续条件：[REPORT.md](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/opt4-continuous-20261111T014515Z/REPORT.md)。当前任务入口：[state.json](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/unattended-opt4/state.json)。以下旧日期状态作为历史保留。

2026-11-11 CST。当前用户指令覆盖旧 Native 自动续跑策略：Native 和网络
软件工作暂停，全部资源优先用于可实现 Opt4。任何部署/运行只允许
`0000:21:00.0` / `21770433G02LA`；禁止 e2、全局 XDMA/PCIe 操作、重启和固件升级。

## 已实际启动的服务

`ec-opt4-unattended.service` 已安装、enable 并启动。systemd 直接启动监督器，
不以 VS Code/SSH/当前 Codex 会话为父进程。独立 CLI 优化进程实际完成过
headless 文件读写预检，证据 `unattended-opt4/preflight/{worker-proof.json,result.json}`。
首轮已实际建立 `Opt4-fit-address-decode-r1-20261111` 独立工作副本并提交共享 one-hot bucket 读取/静态 retirement clear 候选；候选未验证，不能当作已节省资源。首个 broker 托管的资源审计 CPU 作业已真实完成（退出 0、输出存在）；其首次目录权限失败证据已保留并修复。新服务恢复测试保持原 worker PID/启动身份不变。
下一版实际提交为 `aeabe5abe9f0ece2e024b5c8aa91a2c24fdfa4cb`，source ID `c1d8e0c2da48e82aba099638e2a910d8c358341c44aba59229098cf83cc29404`。独立服务 `ec-opt4-auto-address-decode-r1-aeabe5ab.service` 已实际启动验证，领域状态 `Opt4-fit-address-decode-r1-state.json` 为 `RUNNING_SAT-ARITHMETICOK`；尚未通过完整模块等价和资源门，不进入正式整机。
首轮真实优化任务、工具事件和退出结果以 `unattended-opt4/state.json` 指向的
`round_dir` 为准；service active 不代表候选验证、综合或 FPGA 运行通过。

实验数据根目录：`/data1/gzh/EC/Experiment/firesim-final-opt4-20261106`。

| 入口 | 含义 |
|---|---|
| `unattended-opt4/state.json` | 监督器 PID/start_ticks/boot_id、当前优化轮次 |
| `unattended-opt4/snapshot.json` | 每 300 秒合并的已知作业身份、CPU/RSS、阶段日志变化 |
| `unattended-opt4/ledger.jsonl` | append + fsync 的服务、轮次、请求与进度事件 |
| `unattended-opt4/rounds/round-*/` | prompt、worker.json、events.jsonl、stderr.log、final.json |
| `unattended-opt4/requests/` | 有版本、绑定输入的 CPU 作业或派生 runtime 请求 |
| `unattended-opt4/request-results/` | STARTED / DEFERRED / 拒绝证据；排队不等于执行 |
| `unattended-opt4/jobs/<name>/` | 独立 systemd CPU 作业的 spec、日志与原子状态 |
| `unattended-opt4/supervisor.log` | 监督器本身故障证据 |
| `unattended-opt4/offline-validation.json`、`11edd719-runtime-offline-validation.json` | 无 FPGA 的恢复/隔离/拒绝路径验证 |

CPU 作业以 guozh 用户运行，固定脚本与输入哈希、有单实例锁和持久日志；
成功的同版本作业复用，失败保留证据交给下一优化轮次分析。新的整机作业
必须等待现有整机明确 NOT FIT/失败，另有内存、磁盘和并发守卫。

## 当前构建与接续

保留正常运行的 `ec-parsec-opt4-fit-cad.service`（整机 `8da24a26`）、
`ec-parsec-opt4-fit-address-sort.service`（完整地址 `11edd719`）、其他活模块综合，
没有迁移、终止或修改其输入。`11edd719` 完整资源报告尚未产生时不得用
388,563 LUT 的组合核报告冒充完整地址面积；round3 完整地址实测
1,153,226 LUT / 55,392 CARRY8，与整机 FIT 分开记录。

已有 `ec-parsec-opt4-fit-sort-system.service` 在精确模块证明和实测面积门后
准备独立整机 RTL，并等待当前整机真实 NOT FIT；当前设计若 FIT 优先实现。
顶层容量门在 place 前拒绝 NOT FIT，FIT 后接 place、route、时序、DRC 和 bitstream。
新优化必须独立提交、完整功能和周期语义不变，未经验证不得合入正式构建。

派生 runtime 描述为 `runtime-candidates/11edd719.json`，模板在
`runtime/Opt4-fit-11edd719/`。`prepare_runtime` 已实际生成独立代码模板；
`start_runtime` 请求必须等待真实 CAD 成功，再比较七个 ABI/目标描述文件、
绑定正确 host driver、验证真实阶段/时序/DRC/bitstream 哈希后才启动。
ABI 不匹配会拒绝复用并留下具体文件，必须实际重建驱动。
部署和采样复用已固定的 21-only 工具及共享维护/单卡锁；保留活样本。
只有旧整机真实 NOT FIT、旧 runtime 仅等待且无活子任务/样本时，才允许安全
移交旧等待器的锁。不会因候选出现而抢占仍可用的现有硬件。

**未验证项必须保留：** 原 runtime 的 full_compare/checker/drain 证据不等于
故障触发的完整 architectural rollback/restart。后台优化任务已明确要求
寻找真实注入/完成接口并补独立诊断验证；不得把无故障 smoke 写成 rollback
通过，也不得通过伪造 marker/receipt 放行。当前无 bitstream、无 Opt4 FPGA 样本。

## 断线与失败恢复规则

重连先只读 `state.json`、round 的 `worker.json` 和 CAD/模块领域状态。
逐一匹配 boot_id、PID 和 `/proc/PID/stat` 的 start_ticks，并检查已记录子任务。
仍存活就接管监控，不能停止、修改输入或重复启动。监督器异常退出后
systemd 自动重启；活优化进程保持独立并被接管。已完成结果不覆盖。

作业退出后，从实际存在且哈希有效的证明、模块 map、DCP/阶段 receipt
续跑。无效或失败的候选保留日志与提交，新版本解决后再请求；不因一次
NOT FIT/工具报错终止整个优化循环。统计快照不是指令级执行检查点。
日志沉默只触发诊断，不授权杀掉活 Vivado。进程 CPU 增长与阶段进展分别记录。
未提交原子 result/complete 的样本不得计入有效性能结果。

## 已知外部连接限制

预检模型调用成功使用现有 `127.0.0.1:2731` 代理；已核实监听者是 SSH
进程，而非独立本机代理服务。当前网络还存在 beeapi.ai 的直连 DNS 异常；
使用独立 DNS 得到的地址进行严格 TLS 直连也被 reset。未更改系统 DNS、
未关闭 TLS 校验、未把 API key 写入 unit/命令行/实验数据。

监督器和 CAD 的进程生命周期已经独立于 SSH，**新的 AI RTL 迭代仍依赖
该外部代理可达，不能宣称模型网络已彻底脱离 SSH**。代理消失时保留轮次和
已有综合结果，自动退避重试；已运行的 CAD/模块服务继续。真正完全断线后
仍可无限迭代，需要可持续的外部模型网络连接。这项限制不等于已有综合停止。

凭据仅由 worker 在内存读取现有账户 CLI 凭据，连接配置存放在账户私有
0600 文件；不得将其内容复制到报告。无需在重连后重复提供密码/API key。


2026-11-11恢复/容量/候选更新：/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/opt4-acceleration-20261111T0046Z/REPORT.md。动态快照纳入broker全部候选state；保持8da NOT FIT容量门和9ae独立DUT综合。ccache/manifest/ledger修复验证：/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/unattended-recovery-r2-20261111。只认PID+start_ticks+boot_id；不重启活任务。

最新加速/恢复实做报告：/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/opt4-acceleration-20261111T010108Z/REPORT.md。8da门禁已NOT_FIT并自然退出；9ae活综合保持。r7SVB选择器/完整候选map完成，实际13-app软件绑定完成；r2SVB断言测试和同harness参考map依broker资源门排队。不得把queued写running或把局部收益写整机FIT。


2026-11-11结构性存储优化实做：[20261111T042537Z REPORT](/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/status-audits/opt4-structural-storage-20261111T042537Z/REPORT.md)。原9ae整机保持运行；e0组合已准备且CAD排队，未开始第二整机。新2210930f完整所有权存储、e21194b2地址共享+序列表组合实际启动独立验证。通用存储探针305778→15888LUT不能当整机收益；保留全部generation观察的实测图与组合验证通过后才可选择。Native暂停、21-only、功能扩展禁止。
