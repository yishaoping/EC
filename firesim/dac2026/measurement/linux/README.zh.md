# ROI 控制驱动的当前边界

`ec_dac_roi.c` 是真实 MMIO 平台驱动，已在独立 Linux 6.2 工作副本中以
`CONFIG_EC_DAC_ROI=y` 编译并链接入 vmlinux；没有执行内核或 ioctl。
它不会创建虚拟设备、读取宿主时间或为缺失硬件返回成功。

本次仅实现 B。C4/C2/C8 在 probe 返回 `-EOPNOTSUPP`，即使硬件自报 capability 也拒绝。
下一步必须实现 mmu-notifier 与 Opt4 Linux/checker 上下文、权限、TLB 和重复会话协议，
保证页表失效前停止 checker。`mmget()` 只保留 mm/页表生命期，不会固定用户映射；
不能以它替代映射失效协议。

驱动只绑定 DT `compatible="ec,dac-roi-v1"` 的真实设备，要求 RV64、MMU、OF、!SMP，
Linux 唯一在线 CPU 必须对应物理 hart0。设备节点权限 0600，单 open；BEGIN 绑定调用任务、
mm 和完整 satp，END/DRAIN 核对任务、mm、satp 与 epoch。BEGIN 只确认 arm，返回 tick=0；
它不声称知道随后用户态 marker 的时间。

三个 ioctl 的40字节布局和号码与现有应用 ABI 一致。`abi_check.c` 用 RV64 Linux 编译器
做静态断言，验证号码、大小和各字段偏移；该检查不执行目标代码。

```bash
cd /data1/gzh/EC
firesim/envs/manager-1.17.1/riscv-tools/bin/riscv64-unknown-linux-gnu-gcc \
  -Wall -Wextra -Werror -std=c11 -fsyntax-only firesim/dac2026/measurement/linux/abi_check.c
```

请求写完 epoch/satp/hart 后以 token 写 COMMAND 提交；ACK 相等后读取不可变响应，
响应寄存器必须作为整体锁存，不允许逐项读取滚动计数。控制器必须保留源时间，
禁止用 MMIO 响应到达时间给 marker 计时。正常 DRAIN 必须零 outstanding、生成=完整PASS完成，
且无 fault；B 还要求生成/完成均为0。ABORT 使整项样本作废，可以取消任务，但必须真正释放
全部 owner/传输且清空 outstanding 才确认。超时或无法确认排空时保留 mm 引用并阻断新样本。

每条命令最多等待30秒目标 Linux 时间。任何不确定 ARM/END/DRAIN、异常用户地址或提前 close
都进入失败路径；禁止把 timeout 后迟到的响应当作新命令确认。模块未提供32位兼容 ioctl。

硬件候选位于 `measurement/hardware`，B 的 v4 工作树与 v3 分开。v3 已编译硬件没有该设备，
不能把 v4 内核配到 v3 FPGA 上声称 ROI 已接通。v4 也仍需 FireSim 转换、被动宿主 bridge、
产物绑定、bitstream 与用户手动运行证据。ABI/capability/编译通过都不会解除实验准入门槛。
