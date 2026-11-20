# Opt4 真实执行与恢复报告

记录时间：2026-11-11T07:13:24.854581+00:00。功能基线仅 `8491167d84b6d9521b151a743673c1516926a1f8`；无架构扩展、Native 暂停、21-only。

| 对象 | 真实容量结果 | 本轮已执行动作与现状 |
|---|---|---|
| 9ae9a7fc 整机 | 尚无新 LUT/CARRY8/DSP 报告，FIT 未知 | 原PID1886276/start16844839保持；日志已从 Timing Optimization 推进到 Technology Mapping。尚未完成DUT，不能称已进入顶层。 |
| e0c3737f 整机 | 尚无新整机报告，FIT 未知 | 原PID2484262/start18404293保持；实际DUT综合继续，无输入或约束变更。 |
| 2210930f 完整DCache | 尚无完整面积 | 原RAM74752bit默认回退限制失败保留；独立r2同RTL按工具建议提高dissolveMemorySizeLimit，已越过旧错误，并完成RTL Optimization Phase2；继续综合。原唯一参考映射仍由同控制器后续执行，不重复启动。 |
| d9d73262 完整DCache | 尚无完整面积，不能报告完整节省 | 真实GG及7ABI已经通过；四字段81/32/32/1真实拓扑已核验；full-map-r4独立Vivado已启动，完整ports/原DontTouch/512generation观察保留。 |
| d9生成存储证明 | 512/512正向及4/4真实写数据负例通过 | r4负例正则跨行错误保留；r5复用64个哈希认证正向分区，只补4个负例，未重跑512项；此为storage transition cut，不是单体完整DCache/整机形式证明。 |
| d9完整周期回归 | 尚未通过 | 对原冻结完整模块的2,534信号/71,589bit对照已准备，包含全部185原输出、原调试观察与512generation；r3因当前Verilator端口mangling与VlWide C++API编译失败，保留全部证据。r4已修复接口，独立clang语法检查通过，复用约806MB原生成C++模型，systemd实际编译运行中；没有改RTL、屏蔽assert或降低覆盖门。 |
| 新组合8d50489a | 未整机综合、未宣称FIT | 精确d9存储+e211地址组合，全部10改动源码编译/冻结参数/实际重emit地址RTL一致性预检通过。独立prep-r2实际服务等待真实模块面积和cycle-r4；既有r1因依赖失败自然退出，未停止或改输入。 |

最近**完成**的整机仍是旧 `8da24a26` post-opt：**3,215,683 LUT /92,789 CARRY8 /195 DSP**；U280 LUT容量 **1,303,680**，旧版超 **1,912,003 LUT**。这不是9ae/e0新数据，当前两版剩余FIT缺口尚无法量化。不能相加局部面积收益代替整机实测。

无认证新bitstream，无Opt4上板记录或有效FPGA正式样本。本轮没有任何FPGA/驱动/PCIe操作，也未启动第三条大型整机。

## 实际自动接续

- 新组合commit：`8d50489af3af9e4c766509284ba3d9d7c99cfec9`。
- source ID：`9bfb0710adc7650940c3edd5005f578cc1295038b34282ece46b87f2ec55ac6a`。
- 工作树：`/data1/gzh/EC/firesim/final-opt4-20261106/Opt4-fit-field-address-compose-r1-20261111`。
- 已通过预检：`/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-fit-field-address-precheck-r1-state.json`。
- 活独立准备：`ec-opt4-auto-field-address-system-r2-8d50489a.service`；状态`/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-fit-field-address-system-r2-state.json`。
- 当前面积任务：`ec-opt4-auto-dcache-fieldbank-full-map-r4-d9d73262.service`；状态`/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-fit-dcache-fieldbank-full-map-r4-state.json`。
- 当前完整周期恢复：`ec-opt4-auto-dcache-frozen-cycle-r4-d9d73262.service`；状态`/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-fit-dcache-frozen-cycle-r4-state.json`。
- 新runtime descriptor：`/data1/gzh/EC/firesim/final-opt4-20261106/runtime-candidates/8d50489a.json`；模板已由broker实际准备，但未经真GG/ABI/CAD认证不可部署。

prep-r2只在以下真实门全部通过后执行：精确组合预检、512word/4mutation证明、完整冻结DCache8192cycle回归、实际全DCache配对显著收益、实际e211全地址收益。随后复用已认证compile类、重新elaborate+GoldenGate+7ABI，自动发布新CAD/runtime请求。CAD仍等待两条旧整机安全退出，无第三条整机；若已有版本FIT则它优先实现。新CAD在post-opt容量门判断NOTFIT即止于place前，FIT才place/route/setup-hold/DRC/bitstream，再由既有严格21-only认证首验链放行。任何环节失败保留状态及日志交给持续优化循环，不伪造PASS。

同时在未来候选的独立CAD脚本修正了原模板`implement_debug_core`后插入检查缺换行的问题；只做离线Python/Tcl语法与输入哈希核对，未修改活9ae/e0控制器。

## 重连与无人值守

`ec-opt4-unattended.service`持续运行，已完成第27轮。所有本轮长任务由systemd/broker托管，有单实例锁、PID/start_ticks/boot_id、持续日志和原子状态。重连读取状态匹配活身份后接管，不能重启/重复启动。完成样本/证明均保留原文件与哈希；旧失败作业以独立新版本恢复，不改旧结果。

当前资源约355.95GiB可用内存、359.79GiB磁盘。07:04:20至07:11:09UTC四个已知Vivado CPU各增长约409秒；这只能证明计算活跃，阶段进展另以日志为准。9ae完成Timing进入TechnologyMapping和221完成Phase2为本次可验证阶段变化。没有资源冲突、OOM或空间不足的证据要求停止活CAD。

## 证据入口

- 本目录`snapshot.json`：07:04:20UTC原子状态、PID/start/boot、CPU/RSS/I/O、服务状态、文件存在性。
- `followup.json`：07:11:09UTC比较及新增阶段日志，CPU进展与资源报告不存在分开记录。
- `new-artifacts-manifest.json`：新独立控制器/准入逻辑/修复驱动SHA256。
- `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-fit-dcache-fieldbank-mutation-r5-state.json`：512结果复用和四真实负例完整通过。
- `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-dcache-fieldbank-full-map-r4-20261111/map-attempt-1.log`：真实完整DCache综合。
- `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-dcache-frozen-cycle-r4-20261111/compile-attempt-1.log`：修复后实际模型编译。
- `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-cad-8da24a26/top-postopt-utilization.rpt`：唯一最近已完成整机资源，历史NOTFIT。
