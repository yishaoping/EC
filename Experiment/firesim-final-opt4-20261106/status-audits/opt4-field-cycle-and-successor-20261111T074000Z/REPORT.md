# Opt4 实际推进记录：2026-11-11 16:27 CST

当前尚无可证明 FIT 的新整机、认证 bitstream 或 Opt4 FPGA 样本。两条正常整机9ae/e0的进程和输入未改动，未启动第三条整机。Native暂停，21-only。

## 真实资源与容量边界

9ae9a7fc已完成 synth_design 内部综合优化，0 error/0 critical warning/453 warning，当前日志进入工具网表翻译。真实 Report Cell Usage：LUT1–LUT6合计 **3,182,510**，其中LUT6 **1,502,097**；CARRY8 **89,672**。DSP内部DSP_ALU/DSP_MULTIPLIER等各192是同一类DSP的内部组件，不相加，也暂不当作正式物理DSP块数。

这是DUT综合单元统计，**不是最终打包CLB LUT或顶层post-opt报告**。正式dut-utilization.rpt、top-postopt-utilization.rpt尚未产生，因此新整机准确物理容量缺口未知，不能用3182510直接计算物理LUT缺口。单LUT6数量已高于U280的1303680个LUT位置，当前综合映射超容，仍需真实post-opt判断优化后的最终NOT FIT/FIT。最近已经完成的旧8da post-opt仍为3215683LUT/92789CARRY8/195DSP，旧版本的确定缺口1912003LUT，不能冒作9ae/e0结果。

真实单元表及绑定：[9ae9a7fc-synth-cell-usage.json](./9ae9a7fc-synth-cell-usage.json)、[原始表](./9ae9a7fc-synth-cell-usage.txt)。活日志：`/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-bucket-tag-cad-9ae9a7fc/dut_synth-attempt-1.log`。

e0c3737f仍在DUT综合，无新的真实面积报告。d9d73262完整DCache、2210930f完整参考对及e211完整地址模块仍在综合/跨层面积优化，**完整DCache的真实LUT/CARRY8/DSP尚未产生**，未把存储边界265176→89636LUT当完整模块收益。

## 本轮完成的验证与实际优化推进

- d9对原冻结硬件的完整DCache周期对照PASS：8192周期，2534信号/71589bit，全部185输出、原DontTouch、512generation观察、所有原断言保留。368request、294load、74store、149acquire/596grant、600reset edges、末尾pending=0/replies=0。C通道beat=0，此回归不代表完整协议或整机形式证明。非法load write_domain_valid=1的r4失败证据保留，r5只把测试输入修复为isWrite，复用原编译模型。
- 3656aec4为独立d9派生面积候选，只消除未使用字段读端口；真实GoldenGate与7项ABI完成。四字段**真实异步读**为35/518/4/4，对照父版各561。旧data-wire计数36/519/5/5额外包含每字段一个写data wire，原证据保留，并以[准确读访问审计](./actual-field-read-accesses.json)更正。全部512generation观察保留。
- 3656相对d9的完整生成DCache符号结构比较PASS：28142个寄存器/存储对象、全部原输出/观察、全部顺序赋值/断言条件/打印字段/子模块连接；实际memory writer数据位翻转负例被拒绝。验证器对1bit条件别名/内联执行宽度受限规范化并以SAT及负例验证。只对60处断言源码行号元数据通过相同git源码行映射；每对行号及源内容留存，不忽略其他字符串、断言或时序赋值。不是全DUT形式证明，也不表示面积准入。
- r1 UNPROVEN验证证据完整保留；独立r2作业已真实执行并由broker原子认证COMPLETE/0。新完整面积请求`dcache-field-read-full-map-r2-3656aec4`已提交，受普通综合并发门排队，**尚未开始面积综合**。复用唯一已在进行的精确e0参考映射，不重复参考。

## 自动接续、去重与恢复

后台已独立提交8d50489a的等价组合等待器。因此撤回并仅终止本轮自己新建、无子任务/无阶段的重复等待器，保留后台既有`field-address-cycle-consumer-r3-8d50489a`。证据[deduplication.json](./deduplication.json)。未终止任何Vivado、模块综合、FPGA或CAD服务。

8d组合源码/冻结参数/重emit一致性预检已PASS；自动等待真实d9完整面积、唯一e0参考及e211面积，再GG/7ABI、条件CAD。CAD保留两条既有整机身份检查/禁止第三整机，真实post-opt NOT FIT停在place前，FIT立即继续实现/时序/DRC/bitstream。runtime描述及5个脚本哈希/语法再次核验PASS，仅21卡，认证前不部署。

持久服务`ec-opt4-unattended.service`保持运行，已进入第30轮；以PID/start_ticks/boot_id接管现存任务，失败采用新版本和原子结果继续。当前策略和下一工作动作保存在`/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/unattended-opt4/campaign-policy.json`、`foreground-area-owner.json`。不把服务存活当作验证/综合通过。

关键实时入口：

- `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-fit-bucket-tag-cad-state.json`
- `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-fit-update-share-svb-cad-state.json`
- `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-fit-dcache-fieldbank-full-map-r4-state.json`
- `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-fit-field-address-cycle-consumer-r3-state.json`
- `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/Opt4-fit-dcache-field-read-generated-r2-state.json`
- `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/build-logs/Opt4-fit-dcache-field-read-generated-r2-20261111/`（比较、60处元数据映射、真实write负例）
- `/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/unattended-opt4/requests/dcache-field-read-full-map-r2-3656aec4.json`（排队，不是已运行）

下一关键路径是实际面积/容量报告；当前没有进入物理实现。所有新硬件版本独立绑定，8491167d冻结Tag未修改，不开发架构新功能。
