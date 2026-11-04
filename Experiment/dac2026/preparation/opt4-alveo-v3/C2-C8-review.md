# C2/C8 扩展审查（2026-11-02，只读审查，未构建）

本阶段只构建 B/C4。C2/C8 与 C4 使用同一 frozen Opt4 功能源，绝不能切换其他目录同名 opt4。
以下相对路径均以 `/data1/gzh/EC/firesim/dac2026/work/opt4-alveo-v3/C4/chipyard/generators` 为基准。
源 hash 由各 build 日志的 sources.json 绑定；行号可因后续插桩变化。

| 位置 | 当前证据 | C2/C8 所需工作 |
|---|---|---|
| rocket-chip/src/main/scala/guardiancouncil/GH_GlobalParams.scala:10 | GH_NUM_CORES=5，GH_NUM_BIG_CORES=1 | 私有配置副本改为 3/9；所有 Vec/CDC/结果/会话位图同步核对。不能只改 WithNGCCheckers。 |
| chipyard/src/main/scala/config/RocketConfigs.scala:9 | v1Config，WithNGCCheckers 以 GH_NUM_CORES−1 实例化；Rocket hart offset=1 | 分别生成明确命名 DacOpt4C2/DacOpt4C8，审计设备树 hart0+1..N；BOOM 参数和软件不变。 |
| rocket-chip/src/main/scala/r/R_IC.scala:94,97,136 | crnt_target/nxt_target/producer_target 均 3 bit；编号使用 1..N，0 为无目标 | C8 的 hart/checker 编号 8 需至少 4 bit，当前会截断为 0。依据 log2Ceil(N+1) 定义公共位宽。 |
| 同文件 :96,221,406 | crnt_mask 6 bit，Cat(capture_ctrl(3 bit), target(3 bit)) | 新协议要区分 control 和 target 位段，逐项修改编码/解码；C2 也不能无审查缩窄。 |
| rocket-chip/src/main/scala/r/R_RSU.scala:43,45,232,255,264 | ic_crnt_target 6 bit，arfs_pidx 8 bit，以 Cat(ic_crnt_target(4,0), 3-bit op) 打包 | 第 8 个 checker 将侵占原 control 位；不能仅将 R_IC 寄存器拓宽。需稳定统一 ARF 包格式。 |
| rocket-chip/src/main/scala/guardiancouncil/GHM.scala:123,124 | ARF/ECP 目的字段提取 (5,3)，只有 3 bit | 与 R_IC、R_RSU 同时调整和审核，否则 C8 目标号丢失。 |
| rocket-chip/src/main/scala/r/R_IC.scala:658 | one_fourbits/core_bitmap 4 bit；shared_CP_CFG 13 bit | C8 checker bitmap 至少 8 bit；重新定义 shared_CP_CFG，并审核所有消费者的位段提取。 |
| rocket-chip/src/main/scala/guardiancouncil/ght_sch.scala:136 | GHT_SCH_ANYAVILIABLE 的 current_dest/候选值是 4 bit，core_s/core_e 为 4 bit | 目的寄存器本身能表达 8，但 scheduler 输出到 R_IC 的窄连接会截断。核对 totalnumber_of_checkers、core_na、动态索引、范围、RR 回绕和全忙行为。 |
| boom/src/main/scala/exu/core.scala:2163–2178 | release_wait1..4 和对应 slot1..4 更新硬编码 | 区分诊断计数与功能阻塞，改为 N 项循环，并核对所有类似硬编码 slot。 |
| rocket-chip/src/main/scala/guardiancouncil/ght_filter_prfs.scala:243 | 指令索引含 4-bit checker 目标 | 能表达 8，但须核对 index/mapper 全链路不与其他类别编码冲突。 |
| GH_CHECKER_MASK_WIDTH 及 GHE checker_enable_reg | 16-bit mask 可表达 8 | 容量足够不代表协议正确；所有 mask 初始化/读回仍须审计。 |

软件参考源码 `/data1/gzh/EC/Software/Test` 不修改，只在新的 FireSim 工作副本实现：

- `cfg/init.c` 中 `ght_cfg_se` 与 `ghe_set_checker_mask(0xF)` 写死四路，须由 N 生成 `[1,N]` 和 `(1ULL<<N)-1`，读取回验。
- `hw/ght.h:r_set_corex_p_s` 的类型字段 `core_id<<3` 和 mapper mask 要与硬件新协议一起审计；不能只扩大 mask。
- `core/secondary.c` switch 只处理 hart1..4，且完成后永久 idle，不是多次 Linux ROI 服务。C2/C8 都需要可重复 epoch/session 的 firmware/checker 运行时。
- Linux 只向应用开放 BOOM hart0，checker harts 由 firmware 服务，核对中断、页表、privilege 和多个应用进程切换。B 必须是真单核硬件。
- C2/C4/C8 共用相同 payload 二进制、输入 hash、1 应用线程、B 数据和内存模型；不能用停用最大配置来冒充移除小核。

在公共编号/ARF 包/软件会话接口稳定后再编译 C2/C8；本次未生成这两组 RTL 或 bitstream。
