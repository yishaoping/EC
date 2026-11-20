# Opt4 持续优化与实现：真实执行记录

2026-11-11 09:45:15 CST。本记录只描述实际产物；历史资源与新候选分别绑定。

| 项目 | 真实状态 | 证据 |
|---|---|---|
| 当前整机 `9ae9a7fc` | DUT synthesis 仍存活，PID/start/boot匹配；未产生新整机资源/FIT结果 | `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-fit-bucket-tag-cad-state.json` |
| 最近完整顶层 post-opt `8da24a26` | NOT FIT：3,215,683 LUT /1,303,680；92,789 CARRY8；195 DSP；LUT缺口1,912,003 | `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-cad-8da24a26/top-postopt-utilization.rpt` |
| 独立 SVB 组合 `f2d2ca3e` | 源绑定组合证明、完整SVB127输出/4096周期对照、冻结参数与真实类来源、GoldenGate、7文件ABI核对已完成 | `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-svb-system-r2-20261111/` |
| SVB 组合软件 | 13项真实ELF/rootfs/firmware/Native配对绑定准备完成；非上板通过 | `/data1/gzh/EC/firesim/final-opt4-20261106/runtime/Opt4-fit-f2d2ca3e/software-suite.json` |
| DCache存储 `51a2bd25` | 生成RTL SAT/反例、512x64双异步读8192周期、实际256组x2路参数、DCache类型检查通过；完整DCache对照与实测面积待完成 | `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-dcache-result-memory-proofonly-r4-20261111/result.json` |
| 复制序列表 `27f7e7d6` | 45副本/90读口的SAT、拓扑、四类负变异、8192实际尺寸向量通过；完整模块对照/面积排队 | `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-address-sequence-replicated-proof-r2-20261111/result.json` |
| bitstream / Opt4 FPGA样本 | 尚无认证bitstream，尚未上板，无正式Opt4样本 | 当前CAD未进入place/route |

## 面积边界与下一版

当前9ae地址完整OOC实测990,905 LUT /55,418 CARRY8 /0 DSP；相对同设置1,500,571 LUT降低509,666。SVB选择器43,898→3,230 LUT、5,952→124 CARRY8；candidate完整SVB OOC为130,912 LUT，需要匹配reference map才能报告完整SVB净收益。以上均不能从旧完整顶层直接相减来判FIT。

旧完整post-opt不重叠子树：地址1,265,491 LUT、BOOM core244,938、MSHRFile222,552、L2 168,544；DCache祖先不能重复相加。即使旧地址面积归零仍差646,512 LUT，故需要继续MSHR/BOOM/L2/统计存储等结构优化。新整机只接入经过实际验证的显著收益组合，不能为一个40k选择器收益重复昂贵整机。

f2独立源ID：`f678ac806ea4b0f801596b26ec8bf9ef914a3161b39f92564ac25452abd8eafc`；9ae源ID：`3791dd0e8f7d9c380500cd37f11ece4c92e275bc399894780228fa61449df561`；冻结parent8491167及Tag未修改。

## 本轮实际修复与恢复

保持当前整机与所有正常模块任务。DCache测试先暴露缺firechip classpath、错误64x8几何假定、缺私有SafePrefixScanner类三项接入问题；r1/r2/r3失败原证据保留。r4只修复测试/编译接入，复用全部成功生成证明、拓扑与8192周期收据，没有修改候选RTL。匹配面积恢复请求`001-dcache-result-mapping-r3-51a2bd25.json`已提交，当前因8个综合控制器预留而DEFERRED；不是已开始综合。两个从未启动的已知错误请求明确标记superseded，原始请求和旧收据保留。证据`/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/unattended-iteration-r3-20261111/dcache-queue-recovery.json`。

控制服务此前已启用最多两个受内存/负载守卫的轻量额外名额，普通综合仍8个、整机DUT仍唯一。进一步的计数方案测试后确认现有8个控制器都包含实际/后续map，未部署，未再次重载控制服务。f2 runtime仅修复输出目录属主，未改脚本或启动FPGA。

## 持续执行与部署条件

`ec-opt4-unattended.service`继续运行，已完成16轮；每轮真实动作/退出证据在`/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/unattended-opt4/rounds/`，每300秒快照、追加fsync总账、原子状态。普通失败、超时、无收益只淘汰对应候选，下一轮继续。请求`queued/DEFERRED`与`STARTED`、验证完成严格分开。

9ae若FIT，当前实现控制器直接继续必要的顶层、opt、place、route、timing/DRC、bitstream。NOT FIT保留DCP/实报，不进入无效布局；后台选真实已证明/已映射的大收益候选，在独立提交组合验证后接唯一下一整机。实现失败保留阶段收据并诊断恢复；不重新综合已成功DUT。

f2认证/启动请求已经存在，当前因没有真实bitstream而等待。7文件ABI实核及13项软件准备已完成；真实容量/时序/DRC/版本认证之前不会访问FPGA。部署只允许21/BDF0000:21:00.0/serial21770433G02LA，沿用单卡/维护锁、严格checker/输出/排空校验、先13项首轮再重复。Native保持暂停。

**恢复范围必须真实：** 已通过实际SVB invalidation、512位payload与WB_WAIT owner稳定、匹配ACK释放/错误ACK断言；这不等于architectural restore/restart。源审计确认冻结路径未连接完整架构恢复，契约在`/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-architectural-recovery-contract-r1-20261111/CONTRACT.md`。面积主线持续，完整架构恢复需要独立功能分支决策，不伪造通过。

**网络限制：** CAD、CPU作业和监督器进程脱离SSH，新的AI RTL迭代仍依赖现有SSH代理网络；代理失联时自动退避重试，已启动CAD不受影响。不能宣称已解决模型网络的完全断线独立性。

状态捕获与进程身份见同目录`audit.json`及原状态副本；原始成功/失败结果均未覆盖。本轮未访问FPGA、e2、驱动或PCIe。
