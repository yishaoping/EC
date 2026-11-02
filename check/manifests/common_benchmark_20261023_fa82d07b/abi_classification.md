# 特殊接口分类与最小 ABI

标记：DIRECT_EVIDENCE=源码/对象/ELF 字节直接读取；STATIC_INFERENCE=静态控制或数据流推断；UNRESOLVED=缺少匹配运行或完整实现证据。H= `/data1/gzh/EC/baseline/source`；C=`/data1/gzh/EC`；N=`C/baseline/software_common`。

本表 PC 全属于旧 fixed_candidate ELF f5f84a17...，不是新 ELF 的地址。`abi_sites.json` 保存全部静态 custom/CSR 指令位置，重新与 ELF 字节核对8056个位置，无动态次数含义。相同源码里的不同调用/内联位置不简化成一次运行事件。

## 当前候选实际接口

| 接口、软件位置与旧 PC | 分类 | 硬件实现和 Baseline / Current 行为 | 相对 hart0 ROI | 删除影响及本轮处理 | 等级 |
|---|---|---|---|---|---|
| cycle CSR0xc00；`hw/cycle.h:7-11`、`test.c:70,92`；0x80000368/0x800003d4；旧 report 还有额外 rdcycle | PERFORMANCE_MEASUREMENT_REQUIRED | H/C `rocket/CSR.scala` 映射 cycle到reg_cycle，normal模式计数条件一致，见计时契约 | 前后端点；旧报告读在后 | 保留两个主计时，删旧统计timeout/latency计时；不同hart cycle不互减 | DIRECT_EVIDENCE |
| mhartid0xf14；`test.c`、`secondary.c`、`interrupt.{c,h}`；0x800000dc、0x8000025c/278/2b8、0x800004ac/504、0x8000350c等，完整表见json | WORKLOAD_REQUIRED | H/C CSRFile hart ID；libgloss通过该值分配stack/分流main、__main | 前/内/后，取决于hart和中断 | 保留，删除将破坏hart拓扑、timer寻址 | DIRECT_EVIDENCE |
| mie0x304、mstatus0x300、mip0x344、mcause0x342、mepc0x341；`hw/interrupt.c:41-128`、h:37-65；0x80000508/510/52c/534/5b8/5c0/648/650/654/65c等 | WORKLOAD_REQUIRED | H/C CSRFile/CLINT标准中断与xRET接口；同一修复handler | 前/内/后，中断可能在ROI发生 | 保留，不为旧hardware回退handler或flag64布局 | DIRECT_EVIDENCE / STATIC_INFERENCE |
| mtvec0x305、mscratch0x340、mtval0x343、mret；libgloss crt0.S:94-124,138-222；0x8000004c/104/144/14c/194/1ea | WORKLOAD_REQUIRED | H/C核心trap通道；复制既有libgloss_htif.a用于同一静态链接。trap stub调用C handler并将a0写mepc | 启动及ROI内中断 | 保留；源码和既有ELF证明接口形状，不能代替未来新ELF确认 | DIRECT_EVIDENCE / UNRESOLVED(runtime) |
| CLINT MSIP=`0x02000000+4*hart`；mtimecmp=`0x02004000+8*hart`；mtime=`0x0200bff8`；`interrupt.c:7-38,51-113`/h:37-47；函数mtimecmp_cfg旧0x800004ac，handle_trap旧0x80000504起 | WORKLOAD_REQUIRED | H/C `devices/tilelink/CLINT.scala`；32bit mtime hi/lo读、初始cmp low/high写、重装64bit写；不是专有statistics MMIO | 初始化及ROI内 | 全保留，delta32是CLINT tick，**不是interval5000** | DIRECT_EVIDENCE |
| ordinary DRAM timer_flags[4]；`interrupt.h:15-23`、c:5；旧base0x80007e40，stride64 | WORKLOAD_REQUIRED（共享软件数据ABI） | 普通可缓存数据，H/C64-byte块；无Current专有MMIO | 中断前/内/后 | 源码逐字节保留，linker/postlink固定256bytes。禁止恢复紧密布局 | DIRECT_EVIDENCE / STATIC_INFERENCE |
| custom1 funct1c（checker数量）、1b（初始化完成）；`cfg/init.c:13`、`test.c:40`；0x8000365c、0x800002b0 | WORKLOAD_REQUIRED | H GHE.scala:78-79,134-151,205-208，C对应decode；四checker状态 | 前 | 保留，main等待硬件初始化；checker低位observer初始化移到initialized=1之前 | DIRECT_EVIDENCE |
| funct06 xs2=1,rs2=2/3/4，GHT filter/RVC/map/SE/debug filter width；`hw/ght.h:25-68`、`cfg/init.c:16-81`；旧0x8000366c起66个位置，完整json | WORKLOAD_REQUIRED（配置） | H/C GHE doGHT_Cfg 输出到GHM/GHT。不能从函数名debug推断可删 | 前 | 配置源码不变；删改会改变过滤/路由、包工作量 | DIRECT_EVIDENCE |
| funct7d/7e，mask=0xf/readback；`cfg/init.c:82-86`；0x800039f8/39fc | WORKLOAD_REQUIRED（mask配置）；读回为诊断 | **b3本来已有**；GHE decode/outputs H:96-98,260-264，C同类实现 | 前 | 保留，不能误当Current-only。新验收要求mask打印0xf | DIRECT_EVIDENCE |
| funct16 rs1=1/2；`ght.h:15-23`；0x80000314/450、0x80003a54/3b44 | WORKLOAD_REQUIRED（monitor上下文）；结束clear为COMPLETION_ONLY | H GHE.scala:213-236、C对应：捕获satp_ppn/sysmode并设置has_monitor_target；**不是软件写satp或R-Kernel syscall** | 前/后；checker与main时序不同 | 保留；不改变监测目标/恢复边界 | DIRECT_EVIDENCE |
| funct31/32/30，monitor START/STOP/clear；`test.c:66,85,111`；0x8000035c/3a8/454 | WORKLOAD_REQUIRED（检查工作范围）；funct30为COMPLETION_ONLY | H/C GHE doMask更新ght_status；改变上游监测/调度状态 | 前/内/后 | 全保留；0x32不是“统计STOP”，不能一起删 | DIRECT_EVIDENCE |
| funct70 rs1=1/2，checking START/STOP；`test.c:67,80`；0x80000364/394 | WORKLOAD_REQUIRED | H/C GHE io.ic_ctrl、R_IC checking FSM | 前/内 | 保留，STOP后仍等GHT。不能关闭barrier/检查来取代停止协议 | DIRECT_EVIDENCE |
| funct06 xd=1,rs1=rs2=0；`ght.h:8-12`；0x800003cc | WORKLOAD_REQUIRED（本ROI包含session完成） | H GHE:73-78,139：bigComp[1:0]==3锁存并返回Cat(bigComp_reg,rs1[15:0])；C同类 | 内 | 保留status>=0x1ffff；不等价于cache drain/逐包PASS/资源释放 | DIRECT_EVIDENCE |
| funct01/40/51，checker角色、go、初始化；`checker.c:13-16`；0x80003a50/58/5c | WORKLOAD_REQUIRED | H/C GHE角色、event、initialized输出 | checker启动，通常ROI前；没有运行窗口证明时不把PC当时间 | 保留，与init/release语义相连 | DIRECT_EVIDENCE / STATIC_INFERENCE |
| funct75/73/72/64，record、上下文来源、record_pc；`checker.c:24-26,48`；0x80003a8c/90/94、0x80003b14 | WORKLOAD_REQUIRED | H GHE:256-277及RocketCore:526-528,1063-1084；C对应上下文/复制机制 | checker执行可与ROI重叠 | 保留；这些“记录”不是流量report，删除会破坏回放/上下文 | DIRECT_EVIDENCE |
| funct07/61/60，状态/RSU ready/copy；`checker.c:37-48`；0x80003afc/3b34、3af0、3b18/3b68 | WORKLOAD_REQUIRED | H/C GHE状态/RSU/copy连接RocketCore/ICSL | 可与ROI重叠 | 保留所有循环、5个NOP和copy顺序；等待不简化为report-only | DIRECT_EVIDENCE |
| special JLR `.word 0x00001067`；`checker.c:40`；0x80003b6c | WORKLOAD_REQUIRED | H RocketCore:689,725等对jalr inst(12)=1的checker跳转/rsu_pc；C保留扩展后的恢复路径 | checker执行可与ROI重叠 | 不按普通非法指令删除；保留原宏/字节生成方式 | DIRECT_EVIDENCE |
| funct43 release；`checker.c:62`；0x80003b3c | COMPLETION_ONLY（checker/session），必要协议 | H/C GHE doEvent -> GHM控制；旧checker之后才进入secondary snapshot | 相对checker完成；可能在main stop之前 | 保留，不从名字推断package-result release | DIRECT_EVIDENCE |
| funct65选择ELU、66读status、63 deq/ERROR printf；`checker.c:27-35`、`ghe.h:56-60`；0x80003aac、3ab0/3ad0、3acc；ERROR分支printf旧3ac4 | UNRESOLVED（有效ELU诊断）；接口形状为LEGACY_TEST_METRIC | 所查H/C GHE均无65/66 decode；66 xd读取默认0，elu_sel锁存0未见该命令更新；63 deq有实现 | checker初始化可能与ROI有相对偏移 | 保守保留整段错误/上下文路径；不能据此宣称全部checker验证PASS | DIRECT_EVIDENCE / UNRESOLVED |
| funct55 index0，旧csr_read_s/e、boom_inst；`test.c:54,87`、report.c；0x80000304/3b0 | LEGACY_TEST_METRIC | H/C doGetCsrPerf -> io.csr_counter_in，非architectural cycleCSR；读回窗口与rdcycle不同 | 前/内 | 删除统计读和数组写，不是删除BFS工作；不再输出boom_inst | DIRECT_EVIDENCE |
| funct76 reset/selector、START/STOP；`ghe.h:63-98`；main0x80000330/338/340/348；checker0x80003a70/78/80/88、3b08/10；report0x800017a8/7b0 | LEGACY_TEST_METRIC；保留部分共享初始化 | H GHE279-283为5bits；C281-285为7bits；H截掉bit5/6，C驱动traffic_start/stop。低位reset两版都有 | main前/后；旧checker尾部可与ROI重叠 | 保留main ROI外控制和checker pre-initialized reset/clear；删除checker高位observer START/STOP；完全不作为主计时/软件PASS | DIRECT_EVIDENCE / STATIC_INFERENCE |
| funct79 rs1=5000，旧set_interval；`checker.c:19`、ghe.h:101-104；0x80003a68 | LEGACY_TEST_METRIC | H/C活动GHE均无interval decode，xd=0时无读回；5000是请求/标签，不是测到的采样间隔。更早b87的同funct是store counters读取，b3已删 | checker初始化可与mainROI重叠 | 删除；统一interval=NOT_USED；不恢复旧storecounter硬件来伪装interval | DIRECT_EVIDENCE |
| funct7b hart0 stats valid、package drain和报告；`report.c:47-108,1003-1071`；0x80001658..0x800019c0，全部30处见json | LEGACY_TEST_METRIC（部分旧逻辑用作completion验收） | H无decode、默认0且ready/xd响应；C读traffic vector[0..127]；只读输出，不是协议ACK | **hart0 stop之后** | 移除统计valid要求及统计报告。替换为实际计算self-check，不把删除统计验收升级为包保护正确性 | DIRECT_EVIDENCE / STATIC_INFERENCE |
| funct7b checker snapshot + hart_traffic stores；`secondary.c:24-25`；0x800034c4为循环单个读指令 | LEGACY_TEST_METRIC | 同上；读128项后只供report消费；不决定AMO/BFS结果或checker FSM状态 | **可能与mainROI重叠，UNRESOLVED实际区间** | 在共同profile删除；明确减少的是观察者读和写，非保证旧ROI性能不变。保留ready/fence/idle | DIRECT_EVIDENCE / STATIC_INFERENCE |
| hart_traffic_ready[5]、fence；`secondary.c:27-28`、`report.c:1007-1012`；旧save_checker_traffic0x800034a8..34fc、report_end0x800015d8起 | COMPLETION_ONLY（软件） | 普通共享DRAM，H/C一致；不是专有CSR | checker侧可重叠ROI，main读取在后 | 保留发布和等待，地址固定0x8005df50；不把ready当全部硬件quiet | DIRECT_EVIDENCE |
| printf/HTIF syscall write；libgloss misc/htif.c:14-40、sys/write.c:6-9；旧htif_syscall 0x80006622，_write 0x80006706（函数入口，非ROI端点） | LEGACY_TEST_METRIC/COMPLETION_ONLY；初始化输出及ERROR诊断 | 普通DRAM tohost/fromhost和FESVR；不是直接UART MMIO，也不是R-Kernel调用 | main报告后；ERROR中断/诊断路径可能另有流量 | 保留init/result/ROI/error及必要输出，删详细legacy metrics；stdout不作为计时端点 | DIRECT_EVIDENCE / STATIC_INFERENCE |
| `_exit` finite tohost；`test.c:16-26`；旧0x800007b0..7d4；tohost0x80007d00/fromhost0x80007d08 | COMPLETION_ONLY | H/C FESVR读取HTIF符号并识别code；harness后续drain行为不同 | 后 | 保留清MIE、有限两store、fence+spin。新main失败返回1；不通过harness伪造成功 | DIRECT_EVIDENCE |
| report_start | LEGACY_TEST_METRIC（本候选无实际调用） | 当前build source集合无该函数/入口；test_setup做旧perf setup | 无实际PC | 不杜撰一个必需硬件ABI；本轮替换report_end并清理setup观察路径 | DIRECT_EVIDENCE |
| 0x77/78/7f及其他定义但候选无可达指令 | LEGACY_TEST_METRIC/UNRESOLVED用途 | H/C有相关perf/state入口，但8056位置枚举中无实际候选调用 | 不适用 | 不把“头文件存在”当动态接口。共用最小头文件不再声明这些未使用统计读回 | DIRECT_EVIDENCE |

HTIF具体符号PC另外保存在本目录 `library_symbol_sites.json`；表中不能从不完整的函数地址示例推断调用窗口。所有新共用PC都必须来自未来ELF，不从旧函数偏移猜测。

## 0x7B 的历史与策略比较

[DIRECT_EVIDENCE] 定向 `git log -S 'val doGetTrafficCounter'` 和 `git show` 表明，b3祖先的本路径没有该实现；`d5585b36f5e99ae6abb57bbe849ce3733a464dc3` 在2026-08-05加入funct7B读回，且b3是其祖先。b3日期为2026-07-29。后续28331622...、65cb4ee3...扩展统计类型，不构成“b3原本支持128项valid”的证据。

[DIRECT_EVIDENCE] `b87f893fd4e16a8d47c0a0f3b0599aa4a3f34b27` GHE存在funct79 store counter读回；b3的本文件diff移除了它并加入checker mask/state。恢复它也不能实现Current软件所谓interval5000。

| 不兼容/差异 | A 共用软件删除或替换 | B harness外围兼容 | C 恢复硬件接口 | 本轮决定 |
|---|---|---|---|---|
| 7B statistics valid/report | 实际result+共同软件completion替代统计验收，删除全部7B读回与观察者snapshot | 伪造valid=1会掩盖缺失的包证据；拦截RoCC还可能进入被测路径 | b3没有该接口；移植后来硬件不是恢复b3原貌 | A；保留保护机制，不谎称完整包正确性 |
| 55 inst统计 | 删除；主指标用architectural rdcycle | 没有必要另造返回值 | 两版已有，但窗口不一致且非必需 | A |
| 79 interval | 删除未实现请求和5000标签 | 没有真实采样语义可模拟 | 历史79为不同storecounter ABI；无必要恢复 | A |
| 76宽度 | 最小共享初始化；main高位控制限制ROI外，返回值从不参与结果 | 不需要外部兼容 | b3低位原有；不扩展b3为7bit | 保留共同命令子集/ROI外observer控制 |
| exit/drain差异 | 共同finite HTIF退出；主指标在退出之前采样 | 保留各自harness原退出语义，独立记录 | 不为统计硬改cache/core | A+原生harness，非修改B |
| ELU65/66有效性 | 保留既有指令，不改变checker控制流；报告有限证据 | 外围返回零不构成验证通过 | 未证明这是workload必需且必须补回的ABI | 不修改；有效检错证据另列UNRESOLVED |

[STATIC_INFERENCE] 去除legacy报告不是消除它的正确性含义，而是缩小软件共同PASS的声明范围。packet sequence/ownership、snapshot、preservation、validation barrier、recovery、TL握手及资源释放仍由原硬件执行；不得为了让smoke通过去掉真正workload操作或保护条件。

## 最小运行依赖

[DIRECT_EVIDENCE] 这份共同软件通过已存在的 `libgloss_htif.a`、htif specs/linker、toolchain/newlib构建静态ELF，runtime使用HTIF。既有历史ELF也没有动态interpreter。`Software/R-Kernel` 缺失对象不构成这个静态程序的运行依赖；本轮不恢复、不编译内核。

[UNRESOLVED] 新ELF实际加载/执行、AMO/BFS/timer/checker两版行为和生成模型身份需要未来smoke。静态ABI可接受不等于历史硬件对所有AMO/回放语义均已验证正确。
