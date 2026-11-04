# B ROI 实现进展与剩余链路（2026-11-02）

本次实际推进了 ROI 驱动和目标/宿主接线。**没有运行仿真、benchmark 或任何 driver，真实运行通过样本数0。**
没有访问/烧写/复位 FPGA、改变 XDMA、解绑、重扫或执行 infrasetup/enumeratefpgas。
主矩阵仍为 B/C2/C4/C8，B/C4 优先，check 不接入；C2/C8 没有批量构建。

## 源码和版本

准确 Opt4 身份 `/data1/gzh/EC/slowdown/opt4` 是冻结身份目录；真实冻结功能硬件在
`/data1/gzh/EC/chipyard/generators`，入口 `/data1/gzh/EC/slowdown/run_optimization_4_svb.sh`，配置 `chipyard.v1Config`。
功能提交 `476a760910f3bfbd3c111000ebe40343870ab439`，冻结提交 `962c4b87db2a810bc025a87f5f7289dd7aedc5cf`。
原 tracked 源保持原样；Opt4 不是编译优化等级。

B 是上游 Chipyard1.9.0 `7475bfb1a05802ac4dfc3990a889f93164b8d798` 的真单 BOOM，
BOOM `deae9f70469336a3787fa7fcc10135ffb93d21d9`，没有 Rocket/GuardianCouncil。
FireSim 实际为1.17.0 `07efa6a6da18bd64d1159ae84a4701b37abb1228`，各自工作树正常 Chipyard library 集成；
manager 工具环境目录 `firesim/envs/manager-1.17.1` 仅为保留的目录名。

| 工作树（均在 `/data1/gzh/EC/firesim/dac2026/work` 下） | 用途和证据 |
|---|---|
| `opt4-alveo-v3/{B,C4}/chipyard` | 原 B/C4 各4阶段已编译通过；8份源码/产物哈希重新核验；无 ROI 外设/真实被动统计 |
| `opt4-roi-v4/B/chipyard` | B ROI 源域控制器、MMIO和driver编译通过；软件候选内容核验通过；已保留 |
| `opt4-roi-v5/B/chipyard` | B 被动 raw ROI bridge 的参数/生成/GoldenGate/native driver四阶段通过，hash/软件复用核验通过；未执行 |
| `software-roi-v4-20261102T082148.459199Z/linux` | 独立 Linux6.2，B-only ROI driver 编译入 UP 内核 |

没有 v4/v5 的 C4。新 B 与 C4 v3 的 BOOM/cache/clock 配置参数再次比较通过，但尚不能作为正式共同测量配置。
v4与修订后v5生成 DT 的精确字节相同，复用已核验软件有单独 `opt4-roi-v5/software-reuse-v4-v5-corrected.json` 证据，
这不等于新 bridge 运行准入。manager/源树/commit/产物对应关系见 `opt4-roi-v5/source-mapping.json`。

## 已实际通过的构建和检查

- B v4 参数实例化、目标生成、GoldenGate转换、native U280 driver 编译/链接，源码ID相同：
  `67d3bdbf740837e46d54e57808afc7311143715b5b6cf13e7ba6b27cf99fade4`。
- B v5 上述四阶段同样通过，真实 raw bridge 已包含于 FPGA RTL 且由生成header注册到native driver：
  source_id=`be443a3dc2992eb52be4d3da55d687e13e9a21a0dccc1d136a2f23c2c3f436e4`。
  核验报告 `opt4-roi-v5/B-raw-bridge-compile-content-verified.json`；没有执行driver。
- ROI驱动真实执行 MMIO 请求/ACK，不提供成功stub；只接B，C4 probe明确拒绝。
- RV64用户/内核40字节 ABI、三个 ioctl 号码和字段偏移静态断言通过。
- 内核 `CONFIG_EC_DAC_ROI=y`，!SMP；`ec_dac_roi.o` 已链接入 vmlinux，原Linux副本不改。
- 候选 initramfs 已打包相同静态 roi-smoke/blackscholes、test/simsmall输入和手动脚本，newc中23个文件/链接逐项核验。
- OpenSBI payload 包含精确 Image/DTB 字节。之前错误参数 `FW_FDT_PATH` 被make忽略，旧产物保留且标为集成无效；
  改为 `FW_PAYLOAD_FDT_PATH`，新增内容失败判据。审查：`opt4-alveo-v3/firmware-dtb-content-audit.json`。
- 35项宿主离线测试通过，包括新增原始日志/输出校验。首次缺PYTHONPATH的测试调用失败日志保留，按正确环境重跑通过。
  这些测试不执行任何目标应用，也不构成真实实验通过。

v4整链只读证据：`opt4-roi-v4/B-candidate-compile-content-verified.json`。
完整硬件和软件构建路径、hash及返回码都在该文件引用的receipt中，旧失败记录不改写。
v5首次GoldenGate在Host BridgeModule实例化时因Bool扩展写法失败，已改为显式64位Mux；
修订后重新elaborate，后续各阶段必须绑定修订后的source_id。`opt4-roi-v5/bridge-width-fix.json`保留改动和失败receipt。

## 手动命令与含义

只读核验已有v4四阶段产物，不执行driver、不访问FPGA：

```bash
cd /data1/gzh/EC
python3 firesim/dac2026/scripts/verify_compile_evidence.py \
  --evidence Experiment/dac2026/preparation/opt4-roi-v4/hardware-compile-evidence.json \
  --out /data1/gzh/EC/Experiment/dac2026/preparation/opt4-roi-v4/review-new.json
```

输出文件采用exclusive create，已存在时请给新文件名。v5实际构建状态可只读汇总：

```bash
python3 firesim/dac2026/scripts/report_builds.py --integration opt4-roi-v5 \
  --out /data1/gzh/EC/Experiment/dac2026/preparation/opt4-roi-v5/build-status.json
python3 firesim/dac2026/scripts/verify_roi_bridge.py \
  --hardware-evidence Experiment/dac2026/preparation/opt4-roi-v5/hardware-compile-evidence.json \
  --software-reuse Experiment/dac2026/preparation/opt4-roi-v5/software-reuse-v4-v5-corrected.json \
  --out /data1/gzh/EC/Experiment/dac2026/preparation/opt4-roi-v5/review-new.json
```

`guest/manual-link.sh` 已生成/打包；以下仅供用户在**匹配 B 候选已经手动启动的guest shell**执行：

```bash
/opt/ec-dac/manual-link.sh smoke
/opt/ec-dac/manual-link.sh test
/opt/ec-dac/manual-link.sh simsmall
```

init不自动启动它们。预期smoke输出 `DAC_SMOKE checksum=500500 expected=500500`；
blackscholes必须输入/输出计数相符、有限数值且相对输入第9列参考的绝对误差严格小于1e-4。
脚本先核SHA256，缺真实设备返回125。成功后打印的 `formal_sample=false` 仍不是正式完成标记。

当前**没有可成功启动完整 B/C4 实验链路的宿主命令**：缺少C4上下文/完成事件、正式adapter和bitstream。
现有 `dac.py plan/stage/run` 继续保持证据门槛，不通过改 ready=true 绕过。
具体持续保存/恢复/补跑入口保留在 `firesim/dac2026/README.zh.md`，待真实backend接通后由用户执行。

## 持续保存新增实现与边界

v5真正 passive bridge 的 C++ driver写宿主raw JSONL，epoch/state/reset变化立刻排队，默认每20秒请求累计快照。
exclusive create、目录fsync、逐记录fsync后才pop；队列满暂停宿主token推进，不向目标协议注入stall；
丢序、溢出、控制器fault或写盘失败要求退出126。详见 `measurement/hardware/BRIDGE.zh.md`。
源码/编译不证明运行时行为；当前raw日志没有sample/job身份或输出确认，不生成正式完成标记。

将来用户运行生成raw文件后，宿主可只读检查完整前缀或中断尾行：

```bash
python3 firesim/dac2026/scripts/inspect_roi_raw.py \
  /data1/gzh/EC/Experiment/本次attempt/roi-raw.jsonl \
  --allow-partial --out /data1/gzh/EC/Experiment/本次attempt/roi-prefix-review.json
```

这是将来文件的模板命令，不是已有运行证据。部分尾行显式列出；缺DRAIN/错误/ABORT不标完整边界；
即便ROI边界齐全，报告仍保持正式样本不适用，等待完整identity/输出/正式collector。

## 尚需实现与验证

1. 将B raw bridge接到正式guest/backend、sample身份、输出校验和现有durable collector；证据及版本绑定后才能提交完成标记。
2. C4 Linux/checker必须传递并保护 satp/privilege/页表生命期，增加mmu-notifier或等效失效握手、TLB/ICache处理，
   预留hart1..4并支持重复会话；旧checker不能只加while循环。B驱动不能直接用于C4。
3. C4 BOOM每个最终存活成员的原执行完成事件与sealed package关联，覆盖store/fence/flush/replay等路径；
   Rocket取第一次完整PASS，统一源时钟原点。提交、enqueue/dequeue、owner释放都不替代定义。
4. B/C4使用同样显式FASED设置（LatencyBandwidthPipe，latency30、maxReqs4、relax0）；v5 B和v3 C4的生成寄存器重新静态审查通过，
   候选manifest在 `firesim/dac2026/config/firesim/memory-opt4-roi-v5/manifest.json`，尚未替换正式site准入；运行时实际读回仍未验证。
5. 核验真实运行时连续保存、正确输出、中断恢复、缺项补跑；bitstream、实现时序和隔离安全adapter尚缺。
   FPGA已可能有任务，不能因指定单卡而忽略全局XDMA风险。
6. B/C4链路后才推进C2/C8；具体编号/掩码/包位宽问题见 `opt4-alveo-v3/C2-C8-review.md`。
   消融和面积保留，不把check作为前置条件，不将FPGA资源冒充ASIC面积。
