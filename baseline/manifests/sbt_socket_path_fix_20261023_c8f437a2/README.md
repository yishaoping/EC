# SBT 启动 socket 路径修复

## 原因

`DIRECT_EVIDENCE`：用户运行的一键入口在 `build/b3_20261023_123539_ukekyclx/rtl_generation.log` 中止。SBT 尚未加载工程，底层原因为：

```text
Cannot fit name [/data1/gzh/EC/baseline/build/b3_20261023_123539_ukekyclx/tmp/.sbt/sbt-socket-1815875447306759302/sbt-load.sock] in maximum unix domain socket length
```

该路径为110字节。`sbt thinks that server is already booting` / `ServerAlreadyBootingException` 是该异常的上层包装；该日志不证明另有SBT进程占用。`-Dsbt.server.autostart=false` 没有阻止此次boot socket创建。

`DIRECT_EVIDENCE`：历史Makefile中的`libriscv not found`是可选共享库探测警告，`common-sim-flags.mk:8-14`在缺失时取消`-lriscv`。此次退出点是SBT boot socket异常，不是该警告或Chisel硬件代码错误。

`STATIC_INFERENCE`：原launcher把`java.io.tmpdir`放在较长的构建目录下，SBT再附加`.sbt/sbt-socket-<id>/sbt-load.sock`后超限。此前的Java版本检查不创建该socket，故没有覆盖这个问题。

## 修复

仅修改 `baseline/launch_baseline.py` 的实验基础设施：

- `short_temporary_directory()`在`baseline/tmp/j_<8位随机>/`创建独立临时目录，保留结果；不使用工程外临时目录或共享固定socket名。
- 对完整SBT socket路径预留20位数字ID，检查路径小于100字节；过长即在生成前失败。
- 硬件build使用该目录设置`TMPDIR/TMP/TEMP`、`-Djava.io.tmpdir`和Make的`JAVA_TMP_DIR`，并在build manifest记录其路径及策略。
- 非硬件preflight也采用短目录，并在相同bwrap隔离内实际创建、关闭、移除一个最大ID长度的AF_UNIX socket，提前验证路径和权限。

保留Current与规范历史source只读挂载。没有修改Baseline硬件、软件ELF/loadmem、Config、Git index或原失败构建目录；一键入口保持相同命令，下次自动创建新的build，不清理旧现场。

## 验证

`DIRECT_EVIDENCE`：`baseline/manifests/preflight_1d8armbx/manifest.json`记录`PASS_NO_HARDWARE_OR_SIMULATION`；`isolation.txt`记录`SBT_SOCKET_BIND=PASS`、Current/source只读及Baseline可写。工具版本检查通过。Bash和Python语法检查通过。

`DIRECT_EVIDENCE`：ELF、loadmem与descriptor哈希仍分别为`da8897e790f0c5e91eff3e9560d2b0e7b4e1de6dff208788fb4d9e2ae462c81c`、`f1c0335e8a7ffc6f57232e9bcb8c80a49f45eacaa1e4f533f4cb3af91ad308ad`、`71373bcfeb4609c9c5b4a6a8e5212c3d1ddafcb340488736785dbd873e2dc743`。根index及历史source index保持此前SHA；历史source仍clean；Current和原软件没有diff。

`UNRESOLVED`：本轮没有再次执行SBT项目、Chisel elaboration、RTL generation、Verilator硬件构建、仿真或workload。验证覆盖具体socket故障和启动环境，不宣称完整硬件构建或仿真已通过。`RUN_PROVENANCE=UNRESOLVED`及近似比较标记不变。

用户重试：

```bash
/data1/gzh/EC/baseline/run_baseline_gapbs512.sh
```
