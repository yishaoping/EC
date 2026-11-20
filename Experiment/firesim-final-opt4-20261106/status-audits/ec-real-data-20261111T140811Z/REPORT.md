# EC 三路线实际结果与持续接续（2026-11-11 22:08 CST）

唯一功能基线 `8491167d84b6d9521b151a743673c1516926a1f8`；不增加功能。Native 暂停。只允许 `0000:21:00.0` / `21770433G02LA`。本轮未操作任何 FPGA、驱动或 PCIe。

| 路线 | 已完成的实测 | 当前状态与边界 |
|---|---|---|
| 原冻结 SVB 组件 FPGA | host+shell post-opt 200,342 LUT /12,790 CARRY8 /3 DSP；容量 FIT，placed/physopt DCP 已保存 | 两条物理实现继续路由，spread overlaps 已从355,934降至75,138；尚无 routed 时序/DRC 通过或认证 bitstream，尚无 FPGA 样本 |
| Canneal 完整 GG metasim | ROI536,456 cycles /392,248 instructions；总1,759,002targetcycles；131package精确 joined PASS、pending0；尾部接受排空332cycles | 真正完成且输出正确；不冒充 FPGA 或严格checkerDone−BOOMDone；完整SVB payload r5已运行至1,019,711targetcycles（22:08快照） |
| MCRams 真实 DCache 存储入口 | 405,706→24,192 LUT，节省381,514 /94.037%；FF65,886→32,721；CARRY8均250、DSP均0；BRAM0→1.5 | 2,569targetcycles /178,857定义检查和负例通过；仅局部入口，不是全DCache/整机收益 |
| MCRams owner-only 整机应用 | GoldenGate真实生成完成；独立r3结构审计通过，35读/单写/518debug/reset保持 | 完整paired编译及实际生成wrapper面积请求在既有broker队列，当前DEFERRED；未假称已运行或整机等价 |
| 完整 Opt4 | 最近完成9ae9a7fc post-opt2,847,382LUT /90,740CARRY8 /195DSP，NOT FIT；缺1,543,702LUT | e0c3737f仍在DUT TimingOptimization，无该版新容量报告；无完整Opt4 bitstream/FPGA样本 |

## Canneal 证据

- `cycleprecise-frozen-full-gg-external-observer-r3-20261111/result.json`：同ELF、原模型对象和FASED内存参数；原printf两流哈希、输出、ROI和总targetcycles精确一致。checksum=`40b2b50000000000`、routing_cost=4789、verified=1、exit0。
- `strict-acceptance-analysis-r1.json`：alloc/BEGIN/full-compare RESULT/BOOM accepted按seq/hart/status实际逐项join，131 unique；各checker33/33/33/32，FAIL/CANCEL/sample_errors=0，pending=0。
- `acceptance-analysis.json`：ROI stop CSR1610857，最后accepted CSR1611189，差332targetcycles；stop时2任务未完成，之后全部接收。缺同package BOOM execution-done事件，所以不报告严格checker latency。
- Observer host3421.5449秒，约514.096 targetcycles/host秒，是CPU metasim效率。原未插observer run host3136.1126秒，结果相同；宿主速度不能作为架构slowdown。
- 独立原targetRTL+DRAMsim2 ROI485329cycles/392248inst、136PASS；GG为FASED LatencyPipe30/max4。周期差51127(+10.5345%)不是受控周期等价结果。
- Blackscholes完整原project64（64 options×100 rounds）已真实开始，service `ec-opt4-auto-full-gg-blackscholes-observed-r1-8491167d.service`，model PID1439618/start21765217；全stdout持续gzip并保留raw SHA，checker打印/外部事件另存。未结束不判PASS。CPU0–1与r5共享，因此host效率不标为隔离测量；没有迁移活进程。

## 原 SVB 自动实验链

现有实际系统服务和timer独立于SSH/VS Code：

1. 两条route保存checkpoint，真实setup/hold/target-clock/DRC/route与bitstream门通过后，原或spread认证服务才允许21-only部署；完整Opt4和现有活21任务优先。没有认证通过前不部署。
2. `ec-opt4-external-svb-r5-dispatch.timer`已启动真实完整Canneal r5。保存reset起点及每一个BOOMtargetedge，62emittedports/101uint32/404bytes，完整512bitpayload；包括idle/backpressure，不压缩目标时间。
3. `ec-opt4-original-svb-replay-r1-dispatch.timer`等待完整有效r5和真实capture/promote，再运行原冻结standaloneSVB全流正例和payload负例。
4. `ec-opt4-svb-gg-stream-replay-r3-dispatch.timer`再接GG完整stream正例/负例。必须`+svb-force-all-inputs`。旧cache省poke缺少每cycle输入token，已真实失败，禁止使用；旧header和cache失败证据均保留。
5. `ec-opt4-original-svb-application-onboard-r1.service`已安装且存活，当前等待CPU全trace与组件认证/定向板测通过。它不部署，只复用完全匹配的已上板bitstream；核对source/bit/driver/header/trace/CPUproof哈希，持maintenance/card两锁，独立输出目录，真正板测全record/事件与CPU对照后才原子complete。

当前实际预备通过：真实10kstartup replay109989定义word、0差异（应用事件0）；372cycle定向GG replay6821word、0差异，62capture/16promote/16ACK；真实512bitpayload翻位负例被拒。这些均为CPU验证，不是FPGA样本。链路root/hash/frozen-scope guard与准入schema已实查通过，见 `svb-replay-chain-preflight-r1-20261111/result.json`；应用follower `--offline`亦通过。

严格预算来自实际每recordhost时间×全记录数×3+600，字段`per_run_timeout_seconds`；不把MMIO replay效率称为SVB自主峰值吞吐。SVB ACK也不是checker完成或架构restart。

## MCRams 后继与故障修复

- 权威面积结果 `build-logs/Opt4-mcrams-dcache-entry-area-analysis-r2-20261111/result.json`，稳定SHA34fc766d60d2aa577050e88f9fa125ab04096ac3df91494ad8e308f047598e4c。旧parser误读0LUT和旧timer重写UTC证据保留，现timer仅重验证原报告。
- owner-only真实整机GG只增加ownerImageMemory annotation，目标FIR字节/7450原annotations保留；已完成HOST_RTL_GENERATED。r2后审计因GG之后追加blackbox导致整文件hash变化失败；独立r3精确校验原SV前缀、blackbox后缀、追加receipt与最终hash后通过，没有重生成或改RTL。
- r3证明post-bridge整个DCache精确相等、post-wrap仅memory wrapper及clock替换、35口逐口相等，其余target语句/518debug/reset写门保持；这是结构审计，不是完整系统形式等价。
- 自动round43已提交唯一`mcrams-owner-pair-compile-r43-v1-3656aec4`。前景新建的同目标编译请求确认DEFERRED且无state后撤回到withdrawn-requests，保留证据，避免重复。后续纯runtime沿用这两份真实binary/receipt，等待旧MCRams Canneal自然退出。
- `owner-generated-area-r1-3656aec4`只综合实际整机输出的ownerImageMemory_flattened+RamModel闭包（174462bytes/294ports），独立2CPU/64GiB，不是第三整机CAD。当前仍排队，不能提前写面积收益。

## 活任务与恢复

`snapshot.json`保存本次原始state副本、boot_id、PID/start_ticks、资源/日志mtime和尾部。相对21:25快照，e0实际Vivado CPU增加2649.89秒、原SVBroute增加4834.89秒；这证明仍在计算，阶段进展另以实际checkpoint/route overlaps为准，不能由CPU增长声称完成。

系统监督器实际round43活跃，未重启；所有确定性timer和板测等待器均由systemd托管。本次更新campaign-policy/WORKER_PROMPT只对后续接管生效，没有改活任务脚本/输入。正常检查≥300秒，整机≥600秒；重连先核对boot_id、PID/start_ticks和complete/inputhash，活任务只接管、不重复启动；失败保留证据，独立版本恢复。AI新RTL候选仍依赖外部模型服务网络，确定性CAD/metasim后继不依赖当前聊天。

`metasim-samples.csv`与`resources.csv`按数据类型分开；`evidence-index.json`绑定原始证据。没有把组件FPGA、CPU RTL/GG仿真、整机容量或正式PARSEC样本混合统计。


## 22:22 CST 新完成与实际安装

冻结 Plain 与现有10个RF MCRams 的 Canneal 完整CPU运行对照已自然完成：ROI均536456cycles /392248instructions；两路target print流SHA完全相同，262条checker本地事件值和周期相同；输出正确、exit0、无fault。对变值/错clockheader/少一行/cycle平移四类负例均拒绝。host8416.889s、FMR26.18只属宿主仿真效率。结果 `cycleprecise-frozen-full-mcrams-parity-round38-v1-20261111/result.json`。未观察此模型BOOM释放，所以不是完整排空证明或全系统形式等价；不能替代新owner-only3656成对对照。

owner-only唯一成对编译已改为准确分类rtl的v2请求，controller/inputs/outputpaths不变，旧v1确认无启动后留证撤回。当前MemAvailable201.69GiB，未满足辅助槽256GiB守卫，所以v2仍DEFERRED；不改并发守卫。真正安装启用的`ec-opt4-owner-runtime-r1-dispatch.timer`每5分钟检查，首次service退出0，当前等待这唯一编译。

已安装条件SVB物理恢复worker/dispatcher与独立认证follower。两条producer仍活，所以四类检查全部拒绝启动，未开第三route；后续只取明确失败且退出的封存DCP进行物理hold/setup恢复或显式activeIdx复制，不改RTL/时钟。新增`ec-opt4-original-svb-recovered-follow-r1.service`等待认证；`ec-opt4-original-svb-application-onboard-recovered-r1.service`PID1616391实际存活，等待recovered组件和CPU全trace，识别集合与活applicationr1不相交，仅复用相同bit，不重刷。


22:25 CST：条件物理恢复timer已切换到独立严格r2并实际active/waiting；仅停用旧纯timer，4旧worker全部inactive且原dispatcher已退出。r2显式检查精确systemd cgroup及所有子cgroup.procs，不将未知TasksCurrent当空闲。原r1源码、活route、证书与应用等待器完全保留。`installed-continuations.json`保存实际安装receipt/hash。当前无恢复CAD启动或板操作。


22:27 CST 最终快照：SVB spread overlaps再降至18,243，仍非route/timing通过。Canneal完整r5实际推进至1,450,048targetcycles，Blackscholes至435,015；两model活。e0与原SVB的CAD子进程使用child_pid/child_start_ticks字段核对，均存活，不能用通用child字段缺失误判退出。监督器已进入round44，owner-only编译v2仍因辅助槽内存门DEFERRED、生成wrapper面积因ordinaryslots门DEFERRED，均保留自动续接。原应用/恢复应用两个follower离线版本检查再次PASS，无设备访问。最终原始状态见final-state-summary.json。
