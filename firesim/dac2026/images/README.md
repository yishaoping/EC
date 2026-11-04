# Linux 基础构建与未完成的实验镜像

当前使用 `/data1/gzh/EC/firesim/dac2026/work/software-v3/{linux,opensbi,busybox}` 的独立副本，
来源是 EC 当前 vendored FireMarshal 软件；不使用早期 `firesim/upstream` 1.17.1 的镜像目录。
Linux 6.2、BusyBox 1.36.0。各上游仓库的独立提交在 vendored 树中不可恢复，不能把 EC HEAD 冒充它们的提交。
来源、同版本缺失文件补齐及哈希见 `work/software-v3/source-origin.json` 和
`Experiment/dac2026/preparation/opt4-alveo-v3/linux-missing-source-repair.json`。

实际纯编译结果在 `Experiment/dac2026/build-logs/opt4-alveo-v3/{busybox,kernel,firmware}-*/result.json`。
BusyBox 静态 RV64GC、基础 Linux Image/vmlinux、generic OpenSBI fw_payload 编译已通过；**全部未执行**。
没有已准入的 B/C4 实验镜像。generic OpenSBI 不包含持续 checker 服务。

新增 B ROI 候选内核的驱动以 `CONFIG_EC_DAC_ROI=y` 实际编译、链接，源位于
`work/software-roi-v4-20261102T082148.459199Z/linux`。仅支持 B，C4 仍拒绝绑定。
匹配的目标外设在 `work/opt4-roi-v4/B/chipyard`，生成/GoldenGate 已通过；不是 v3 RTL。
含原静态程序/输入的候选打包 receipt 为
`Experiment/dac2026/build-logs/opt4-alveo-v3/B-boot-pack-20261102T083720.765499Z/result.json`。
最终内核/payload 构建与逐项内容核验见 v4 报告，不把打包成功当作启动成功。

`prepare_boot_prerequisite.py` 仅为真实单 BOOM B 打包交互 initramfs 和软件 DTB：

- 输入是已通过的 B elaboration 与 BusyBox build result，逐项核验产物 SHA256。
- DT 从同次生成产物复制，补 console/rdinit、现有 ISA 扩展名小写和已审查的 CPU0 200MHz；不改硬件生成 DT。
- init 只挂载 proc/sys/dev 并提供交互 shell；不会自动执行程序或 benchmark。
- newc 归档由宿主 Python 打包，无 root mount、目标执行、QEMU/Spike 或 FireMarshal host-init。
- 没有 ROI 控制驱动、checker 服务、被动测量 bridge、PARSEC jobs/backend/Python3。

手动可复现的纯构建命令（不会启动仿真或访问 FPGA）：

```bash
cd /data1/gzh/EC
firesim/envs/manager-1.17.1/bin/python3 firesim/dac2026/scripts/build_base_linux.py busybox --wait-lock
# 每次返回独立日志目录，将对应成功 result 和打包产物路径填入以下参数：
python3 firesim/dac2026/scripts/prepare_boot_prerequisite.py --busybox-result /绝对路径/busybox-时间/result.json --baseline-elaboration-result /绝对路径/B-elaborate-时间/result.json
firesim/envs/manager-1.17.1/bin/python3 firesim/dac2026/scripts/build_base_linux.py kernel --initramfs /绝对路径/B-boot-时间/initramfs.cpio --wait-lock
firesim/envs/manager-1.17.1/bin/python3 firesim/dac2026/scripts/build_base_linux.py firmware --kernel-result /绝对路径/kernel-时间/result.json --fdt /绝对路径/B-boot-时间/B-boot.dtb --wait-lock
```

这些是基础构建命令，不能用 `fw_payload.elf` 存在或 shell 预期输出来证明论文链路完成。
firmware 构建使用 vendored OpenSBI 的 `FW_PAYLOAD_FDT_PATH`，并校验最终 bin 包含精确 Image/DTB 字节。
旧 `firmware-20261102T080649.318315Z` 的 make 返回0但忽略了错误 DT 参数，已标为集成无效并保留；
审查和纠正证据为 `opt4-alveo-v3/firmware-dtb-content-audit.json`，不能继续选用该旧 payload。
`br-dac.candidate.json` 只保留未验证 overlay 候选；当前构建不调用 FireMarshal。
旧镜像说明保留在 `../history/before-boot-prerequisite/images-README.md`，不作为当前执行流程。

正式 B/C4 镜像仍须：Linux 只调度 BOOM；DT/firmware 实际预留 Rocket；可重复的 checker 服务处理每个
进程的 satp/特权/中断/上下文；真实 `/dev/ec_dac_roi` 实现 BEGIN/END/DRAIN；观测事件有精确执行完成和
完整比较时间；guest 批处理、输出验证与 bridge epoch 绑定；软件/输入/缓存/FASED 政策一致。
原 `Software/Test` 一次 hart1..4 检查后永久 idle 的程序不能直接充当此运行时。
不得装返回假成功的 ioctl，不得把原 checker 二进制直接打包成 B 或已完成的 C4。

所有启动、benchmark 和 FPGA 部署由用户手动执行。当前没有获准的启动 adapter/bitstream；
不调用 infrasetup/enumeratefpgas、XDMA 卸载/重载、烧写、复位、解绑或重扫。
