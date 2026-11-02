# 计时、退出与启动配置契约

## 1. 先区分四类边界

[DIRECT_EVIDENCE] 以下时间点来自固定候选 ELF（f5f84a17...）和与 manifest 匹配的源码。PC 是软件身份锚点，**不是实测周期**。本轮没有运行，所有实际时长均 UNRESOLVED。

| 顺序 | 候选指令/状态 | 边界含义与证据 |
|---|---|---|
| 配置 | r_ini(4)、等待 ght_get_initialisation()!=0 | test.c:30-60；hart0，先完成软件/硬件协同初始化。 |
| perf RESET/START | 0x76 写1/0，写0x20/0；PC 0x80000330..0x80000348 | test.c:58-59；统计控制窗口，早于软件 ROI；b3 不保存高控制位。 |
| monitor START | funct31，PC 0x8000035c | GHE 监测状态=1；不是仿真器启动时间。 |
| checking/replay START | funct70，rs1=1，PC 0x80000364 | R_IC 的开始控制。 |
| ROI START | rdcycle s3，PC 0x80000368 | 软件 baseline_cycles/current_cycles 首选共同起点。 |
| 有效工作 | stage1_amo_w_test，随后 gapbs_bfs_run_512 | PC 0x8000036c/0x80000378 调用，包含初始化内置图与验证，不是只有 BFS 核心循环。 |
| checking/replay STOP | funct70，rs1=2，PC 0x80000394 | workload 返回后的停止请求，不是 checker/缓存已经全部完成。 |
| 软件间隔 | 26 次 NOP+减计数/分支，PC 0x8000039c..0x800003a4 | 不是固定26个 cycles，不是经过证明的 drain。 |
| monitor STOP | funct32，PC 0x800003a8 | 监测状态=2。 |
| 指令统计端点 | funct55 index0，PC 0x800003b0 | CSR-performance 统计的 end；其 start 在0x80000304，和 rdcycle ROI 不完全相同。 |
| checker/session wait | funct06 rs1=rs2=0，PC 0x800003cc；直到 status>=0x1ffff | GHE 返回 Cat(bigComp_reg,0)，bigComp_reg 在 bigcore_comp[1:0]==3 时锁存；不是全系统 drain 信号。 |
| ROI STOP | rdcycle s4，PC 0x800003d4 | 包含 STOP路径、poll和尾部checker等待；之后才 printf/统计和退出。 |
| checker统计收集 | report_end PC 0x80001620..0x8000163c 轮询 ready[1..4] | 所有 checker release 后保存流量快照；等待无源码 timeout。 |
| package统计 drain | 0x7B向量，PC 0x80001658..0x8000173c | Current专用有效位与pending合约；b3默认零导致 hard_error。 |
| perf STOP | 0x76 写0x40/0，PC 0x800017a8/0x800017b0 | 报表前冻结Current统计；不等于 workload STOP 或 ROI STOP。 |
| 软件/host退出 | main仍返回0；_exit 0x800007b0..0x800007d4 | 清 MIE、fromhost=0、tohost=1、fence 后自旋。软件 FAIL 并不自动使 exit 非零。 |
| harness结束 | 历史 host success 后退出；Current在编译了STAGE1_EXIT_PORTS时还等L1/LSU quiet | 必须单独记录 host success 和最后仿真结束，不比较不同边界的 Completed after。 |

[STATIC_INFERENCE] 基本 monitor/checker ABI 的静态指令形式在 b3 有匹配路径；实际能否完成一次会话仍需未来 smoke。不能把 source-level 路径视为本轮已观察到握手。

## 2. interval 不是一个参数

| 项目 | 已确定设置 | 解释与限制 |
|---|---|---|
| timer interval | [DIRECT_EVIDENCE] TIMER_COMPARE_DELTA=0x20=32 个 CLINT mtime ticks | next=get_mtime()+32，不是绝对固定周期相位，也不是32个BOOM cycles。timer harts0..3；limit50。 |
| CLINT timebase | [STATIC_INFERENCE] b3 v1Config继承BaseConfig WithTimebase(1000000)，pbus200MHz时内部tick divider=200 | RTC.scala:12-26；CLINT.scala:69-79。配置推导为1MHz，名义32us间隔；handler延迟/重装开销不包含在32tick中。实际生成模型和两侧运行时钟一致性 UNRESOLVED，报告cycles优先。 |
| 软件 requested perf interval | [DIRECT_EVIDENCE] FPGA_PERF_INTERVAL_CYCLES=5000；checker用0x79发出 | GHE和所查Current/b3活动router/core路径无该interval实现；不得以打印interval_cycles=5000推导硬件采样。 |
| checkpoint阈值 | [DIRECT_EVIDENCE] 历史GHE t_Value默认200，funct71可改，R_IC用ic_counter>=threshold | 不是timer tick，也不是5000-cycle采样。候选custom1清单没有0x71写入。不得将三者合并。 |
| 软件drain timeout | [DIRECT_EVIDENCE] PACKAGE_DRAIN_TIMEOUT_CYCLES=100000，按hart0 rdcycle计 | 只约束相应report轮询；checker ready等待、GHT poll并未由这个值统一约束。不是仿真max-cycles。 |
| simulator超时 | [UNRESOLVED] 尚未定可称为“短smoke”的有效上限 | launcher默认500000000只是默认，不是历史性能证据；未来需显式传 --max-cycles，timeout判失败，不人为截断成PASS。 |

[STATIC_INFERENCE] 这些软件常量已编入 ELF。现有启动脚本没有 --start、--stop、--interval、--timer-flags 或 --drain 参数；添加环境变量也不会改变该二进制。不得在配置说明里制造不存在的 CLI。

## 3. 退出与 drain 的可用证据

[DIRECT_EVIDENCE] 历史 libgloss _exit 循环写 fromhost/tohost；候选覆盖为一次写。HTIF payload低位1表示exit，其余为code，故code0 -> tohost1，与历史 FESVR syscall.cc:199-211、htif.cc:153-159,306-308 兼容。候选 fromhost=0x80007d08、tohost=0x80007d00。

[STATIC_INFERENCE] 有限次退出写入可用于历史硬件，不依赖 Current 新增缓存协议；可以减少退出之后继续产生的store，但并不证明 tohost 被主机观察到时所有缓存资源均已释放。

[DIRECT_EVIDENCE] 软件 drain 要求：allocated==completed，L1/L2未校验writeback pending=0，三个barrier pending=0，三个valid=1，且dropped/overflow=0；随后还检查 strict pending、address stats、STOP后的barrier尾部。源码 report.c:47-108,186-268,1003-1071。**b3没有0x7B，所以该契约不能套到 b3。零是“不支持”，不能当“有效空”。**

[DIRECT_EVIDENCE] 历史 emulator.cc:331-354 只等待dtm/tsi/jtag未done、io_success为假且没超时；没有post-exit drain分支，也没有对应脚本参数。Current emulator.cc:334-350 在 STAGE1_EXIT_PORTS 定义时等待 host_success_seen && stage1_l1_drained。stage1_exit.h:7-25 检查 schema、DCache fence_ready和若干busy/queue状态及LSU状态。这仍不能自动证明外层L2/DRAM全部空闲。

[UNRESOLVED] 未来Current的实际编译产物是否启用STAGE1_EXIT_PORTS、Baseline host-success后的真正L1/L2/LSU资源状态、所有dirty写回最终完成点，均无本轮运行证据。没有可填写为“已确认全系统drain”的配置。不得关闭Current barrier或删去安全检查来伪造相同退出。

## 4. 公平成对测量定义

[STATIC_INFERENCE] 保留同一修复布局并优先两侧使用**完全相同最终审定ELF与loadmem**，同一加载方式、相同图/输入、五harts与映射、相同CLINT/handler、软件START/STOP指令和timeout语义。不要用历史混合刺激ELF对BFS ELF。不做cycle平移或扣常数补偿。

建议未来分别保存以下指标，不互相替代：

- [STATIC_INFERENCE] baseline_cycles_roi / current_cycles_roi = hart0 end_cpu-start_cpu，锚点为同一二进制的0x80000368与0x800003d4；若未来软件重建，重新记录PC与SHA，不能沿用旧PC。
- [STATIC_INFERENCE] workload_body_cycles：本候选没有紧接BFS/AMO返回处的第二个rdcycle，不能从现有打印精确拆出BFS-only耗时；保持UNRESOLVED或未来单独观测。
- [STATIC_INFERENCE] harness_total_cycles_to_host_success：两侧同一harness计数域下的host成功时间，包括启动/打印等，不等于ROI。
- [STATIC_INFERENCE] post_host_drain_cycles：从host成功到实际定义的资源静止；Baseline当前无等价采集，不能用0替代。
- [STATIC_INFERENCE] full_simulator_cycles：按各自harness停止规则记录，只做运行身份/超时信息，不直接形成性能比率。
- [STATIC_INFERENCE] ROB gate、cross-package waits、机制活动与重叠：按已有独立审查定义采集，不能以0x7B缺失读回补零。

[UNRESOLVED] 候选 [PERF] boom_inst 的funct55 index0统计窗口不是rdcycle窗口，Baseline/Current事件定义也未闭合；不能直接将二者相除宣称一致CPI。后续还须独立控制/披露硬件Config差异：b3使用WithNLargeBooms和默认L2，Current使用WithNParaMedicBooms及显式16-way/1024KB/outerLatency12；本轮不改这些配置，也不宣称已完成全系统公平比较。

[UNRESOLVED] 当前没有共同可验收的软件/drain契约与两侧匹配运行，因此当前已准备产物的状态是 FAIR_SOFTWARE_COMPARISON_BLOCKED。软件ROI定义本身并未被否定；障碍不是“所有统计ABI不同就一定不能比较”，而是本候选把不支持统计作为了必需成功条件，同时harness退出口径不同。

## 5. 启动脚本所需字段的审定状态

| 字段 | 可填入说明的确定值/阻塞 |
|---|---|
| 推荐共同软件候选 | /data1/gzh/EC/baseline/software/fixed_candidate/test.riscv；完整SHA在proposal JSON。当前不批准为可成功验收的smoke软件。 |
| loadmem | 同目录test.loadmem_hex，base字符串80000000，SHA已核对；若未来两侧都使用preload，需要同时给ELF让HTIF找符号。 |
| 软件版本 | C HEAD 9b0f34648d5ef483fcebaef6bdfb2c18f1b5014f下40项输入哈希匹配manifest，关键ELF指令已验证；编译过程完整身份UNRESOLVED。 |
| START/STOP | 使用第1节软件指令与rdcycle PC；不能以仿真起止代替。 |
| workload/input | stage1_amo_w_test + gapbs_bfs_run_512，source0，degree16内置模环图，alpha15/beta18；inputs=[]。无额外文件/argv。 |
| exit | main返回0 -> 有限HTIF code0；还须独立要求verified=1与report PASS，不能仅看进程exit0。 |
| drain | 当前软件所需valid/pending在b3不支持；真正Baseline全系统drain为UNRESOLVED，不能给固定post-exit延迟冒充依据。 |
| R-Kernel | 不需要；不设置R-Kernel路径变量。 |
| 环境 | launcher使用baseline/manifests/environment.json中明确保存的RISCV/PATH/JAVA_HOME等；运行现有ELF不另外需要软件编译环境。工具/隔离运行可用性未在本轮测试。 |
| --run | 必须指向未来已有且验证BUILD_COMPLETE的baseline/build目录；当前build为空。不能填虚构simulator路径。 |
| --workload | 未来指向经共同ABI/drain审查通过的独立描述；本次proposal故意不通过兼容门禁。 |
| --seed | 未来两侧显式指定同一个值，例如计划值1；这是实验约定，不是工作负载图随机输入。 |
| --max-cycles | UNRESOLVED；未来明确有限smoke上限，不接受默认数值作为性能或正确性证据。 |
| 其他参数 | 没有经验证的额外启动、interval或drain选项；不得猜测。 |

**[STATIC_INFERENCE] 本轮不给可执行 --run/--all 命令，也不将任何描述改为 REVIEWED_FOR_BASELINE。** 对当前b3硬件，单独提供CLI参数无法修复report对不存在统计有效位的强依赖。最小后续工作是形成保留同一workload与timer布局的共同完成/报告契约，并定位或在另获授权后准备对应的同一软件产物；本轮不进行该适配、软件编译、硬件生成或仿真。
