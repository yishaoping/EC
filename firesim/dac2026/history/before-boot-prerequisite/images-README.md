# Linux 镜像准备（当前未构建）

使用独立安装的 FireMarshal：
`/data1/gzh/EC/firesim/upstream/target-design/chipyard/software/firemarshal`。
上游 Linux/OpenSBI/Buildroot/Busybox 子模块尚未全部初始化；没有本论文可启动镜像。
原 Chipyard 镜像只可作为待审查的输入，不自动复用其 checker/DT/FireSim bridge。

镜像必须满足：

1. 固定内核/OpenSBI/Buildroot revision 与 RISC-V ISA/ABI，记录所有修改和 rootfs hash。
2. Linux 只把应用调度到单 BOOM；Rocket checker 由 firmware/DT/驱动实际预留、启动和
   跨进程服务。不能仅用 `taskset` 声称已把 checker 从 Linux scheduler 隔离。
3. 实现 `measurement/dac_roi.h` 的真实驱动与 `measurement/INTEGRATION.md` 的 control
   backend，打通 bridge→宿主快照。当前没有实现这些集成，不能装假驱动。
4. guest 安装 Python3、pthread/C/C++ 运行库（如二进制不是静态链接）、输入和输出校验器。
   文件统一放 `/opt/ec-dac`；jobs 在每次启动前由 adapter 注入，而非写死一个 campaign。
5. 内核/app/checker 对中断、syscall、地址空间、page cache、频率、内存 FASED 配置有一致
   政策；为每份镜像记录 BOOM hart→Linux CPU 映射与 checker reservation 的证据。

`br-dac.candidate.json` 是 FireMarshal overlay 候选，不是已验证镜像。`overlay/etc/ec-dac`
中的状态标记让未集成镜像明确可识别。没有开机自动跑 benchmark 的 init 脚本。
先把 **已构建并准入** 的同一 PARSEC ELF、inputs、guest 脚本、control backend、驱动及
固件放入新的工作 overlay；不要把原参考树的全部 checker 二进制直接打包为 B/D/C。

手动命令（本次均未执行）：

```bash
cd /data1/gzh/EC
source firesim/dac2026/env.sh
# 以下仅下载固定子模块源码，不运行 target、驱动或 FPGA；限制网络并行度2：
git -C "$FIREMARSHAL_ROOT" submodule update --init --depth 1 --jobs 2 \
  boards/default/linux boards/default/firmware/opensbi \
  boards/default/distros/br/buildroot wlutil/busybox

# 完成 checker/ROI 内核配置和 overlay 后才可构建。
# WARNING: marshal build/host-init/post-bin 可能运行 QEMU 或镜像初始化程序，
# 因而此命令明确留给用户启动，不能视为纯编译：
cd "$FIREMARSHAL_ROOT"
./marshal -v build /data1/gzh/EC/firesim/dac2026/images/br-dac.candidate.json
```

不要默认执行 `marshal launch`、`marshal test`、`firesim infrasetup` 或 `enumeratefpgas`。
构建镜像不涉及卡烧写，但可能涉及软件仿真。candidate 中也没有自动调用驱动操作。
完成后把实际 kernel/rootfs 路径及 SHA256 填 `config/site.json` 的各配置 artifact；
未生成文件时保留空配置并阻断。run adapter 还必须在线验证对应输出及控制响应。
