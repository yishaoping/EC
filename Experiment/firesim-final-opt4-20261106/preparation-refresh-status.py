#!/usr/bin/env python3
"""Publish actual receipts and unresolved gates; never turn build success into runtime PASS."""
import datetime as dt
import hashlib
import json
import os
from pathlib import Path
import shutil

ROOT=Path('/data1/gzh/EC')
W=ROOT/'firesim/final-opt4-20261106'
D=ROOT/'Experiment/firesim-final-opt4-20261106'
DOC=ROOT/'slowdown/final_opt4_freeze_20261106/FIRESIM_START_HERE.md'
def read(p):return json.loads(Path(p).read_text())
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def atomic(p,obj):
    tmp=p.with_suffix('.tmp')
    with tmp.open('w') as f:
        if isinstance(obj,str):f.write(obj)
        else:json.dump(obj,f,indent=2,sort_keys=True);f.write('\n')
        f.flush();os.fsync(f.fileno())
    tmp.replace(p)
def link(p):return f'[{Path(p).name}]({p})'
def main():
    now=dt.datetime.now(dt.timezone.utc).isoformat()
    hw=read(D/'C4-build-state.json')
    system=read(D/'system-supervisor-state.json') if (D/'system-supervisor-state.json').exists() else {}
    integration=read(W/'integration.json')
    native=read(W/'native-reuse.json')
    rootfs=read(W/'software/rootfs-build.json')
    existing_campaign=read(D/'campaign-state.json')
    assert not existing_campaign.get('fpga_deployed') and existing_campaign.get('fpga_samples_valid',0)==0, 'This preparation-only publisher must not overwrite a live/deployed campaign.'
    rows=[];bindings={}
    for label,p in [('integration',W/'integration.json'),('native_hardware',W/'native-reuse.json'),('apps',W/'software/apps-build.json'),('rootfs',W/'software/rootfs-build.json'),('linux_profile',W/'software/linux-profile.json'),('parameters',D/'matched-parameters.json'),('runtime_scope',D/'runtime-scope-audit.json')]:
        bindings[label]=dict(receipt=str(p),sha256=sha(p),value=read(p))
    for label,p in [('matched_software',D/'matched-system-software.json'),('real_check',D/'real-check-source-audit.json'),('generated_svb',D/'generated-svb-audit.json'),('cad_disk_guard',D/'cad-resource-precheck.json'),('fased',W/'runtime/fased-common/manifest.json')]:
        if p.exists():bindings[label]=dict(receipt=str(p),sha256=sha(p),value=read(p))
    for stage in hw['phases']:
        rp=stage.get('result_path');phase=stage['phase']
        rows.append(f"| C4 {phase} | {stage['status']} | {link(rp) if rp else link(stage['log'])} |")
        if rp:bindings['C4_'+phase]=dict(receipt=rp,sha256=sha(rp),value=read(rp))
    for variant in ['Native','C4']:
        for phase in ['fdt','kernel','firmware']:
            p=W/'software'/variant/(phase+'-build.json')
            if p.exists():
                bindings[variant+'_'+phase]=dict(receipt=str(p),sha256=sha(p),value=read(p))
                rows.append(f'| {variant} {phase} | BUILT_NOT_RUN | {link(p)} |')
            else:rows.append(f'| {variant} {phase} | 尚未完成 | — |')
    binding=dict(schema='ec-final-opt4-artifact-bindings/1',observed_utc=now,hardware_commit=integration['hardware_commit'],receipts=bindings,fpga_deployed=False,valid_fpga_samples=0,formal_samples=0,strict_latency=None)
    atomic(D/'artifact-bindings.json',binding)
    c=read(D/'campaign-state.json')
    c['updated_utc']=now;c['configurations']['Native']['status']='EXACT_SOURCE_GG_DRIVER_BITSTREAM_REUSE_VERIFIED_NOT_DEPLOYED'
    c['configurations']['Correction']['status']='C4_'+hw['status']
    c['software_state']=system.get('status','NOT_STARTED')
    c['disk_free_gib']=shutil.disk_usage(W).free/2**30
    c['runtime_scope_audit']=str(D/'runtime-scope-audit.json')
    c['artifact_bindings']=str(D/'artifact-bindings.json')
    c['software_scope_blocker']='Existing C4 user_no_trap_one_mm path does not admit Streamcluster original ROI syscalls; timer-interrupt handling remains unvalidated for all workloads.'
    c['fpga_samples_valid']=0;c['formal_samples_valid']=0;c['fpga_deployed']=False
    atomic(D/'campaign-state.json',c)
    integration['generated_rtl']='GOLDENGATE_'+next((s['status'] for s in hw['phases'] if s['phase']=='goldengate'),'NOT_STARTED')
    integration['functional_runtime']='NOT_RUN'
    # Do not rewrite integration lineage during an active receipt-linked hardware build.
    text=f'''# 最终 Opt4 FireSim 双卡实验统一入口

更新时间：{now}。本次用户授权已覆盖旧文档中“仅交接、不构建、不运行”的限制。

**当前有效 FPGA PARSEC 样本：0；正式样本：0；双卡尚未部署。** 编译、elaboration、QEMU 软件执行均不作为 FPGA 实测值。

## 本次独立工作与证据

- 硬件冻结 Commit：`8491167d84b6d9521b151a743673c1516926a1f8`。
- Tag：`opt4-final-performance-fpga-20261106`；Branch：`frozen/opt4-final-performance-20261106`。
- 冻结备份：`/data1/gzh/EC-backups/opt4-final-performance-20261106/source/chipyard`，未修改。
- 新工作目录：`{W}`；实验/日志/状态：`{D}`。
- C4 独立源码：`{W}/C4/chipyard`；Native：`{W}/Native/chipyard`。
- {link(W/'integration.json')} 记录恢复 checkpoint、冻结移植和六个保留的平台适配差异；{link(W/'frozen-to-firesim.patch')} 记录补丁。
- {link(D/'frozen-source-closure.json')}：核心核对 1,914 个文件，1,908 个与冻结源逐字节相同；SVB32、L2 report-permission repair 已移入独立源码。必要 RTL 产物与构建 receipt 单独绑定。
- FireSim 上游兼容版本 1.17.0，Commit `07efa6a6da18bd64d1159ae84a4701b37abb1228`；C4 集成 checkpoint `7345ef3cf162c311153d7d0db983da22361b181b`。环境目录名 `manager-1.17.1` 不代表上游版本。
- 环境：`{ROOT}/firesim/envs/manager-1.17.1`；Vivado：`/tools/Xilinx/Vivado/2021.1/bin/vivado`。
- 总绑定清单：{link(D/'artifact-bindings.json')}；状态：{link(D/'campaign-state.json')}。完成标记尚未产生。

## 实际构建状态

| 阶段 | 状态 | 证据 |
| --- | --- | --- |
| C4 Scala compile | 已完成，returncode 0 | {link(D/'build-logs/C4-compile-20261106T095608.324820Z/result.json')} |
{chr(10).join(rows)}
| Native 旧 GG/driver/bitstream | 87 项产物与恢复源码已核验，可复用；未部署 | {link(W/'native-reuse.json')} |
| C4 最终 bitstream | 尚未构建 | 旧 C4 CAD 目录不能作为最终 bitstream |
| Linux/rootfs 的 QEMU virt 启动 | 只见下列软件验证 receipt，非 DUT | `{D}/software/*-qemu-kernel-*/result.json` |

- C4 硬件 source_id：`c9f51d3a94aac7783c750682162cd25e9d1460b04974bde9b7541f1d9f4120e7`。
- Native source_id：`{native['source_id']}`。其旧 bitstream SHA256 为 `bbe70b655538fa8d17deb72c4307ac66167ee0510aa12d0270ce2c9e37a34aea`；**不是 Opt4 bitstream**。
- Native 实现为 clean upstream BOOM + `WithDacMatchedBoom`，一个 BOOM、零 Rocket checker。共同 BOOM/L2/RAM/model 参数审计：{link(D/'matched-parameters.json')}。BOOM 预测器匿名类序号是唯一序列化命名差异。

## 已执行命令与长任务恢复

以下命令已实际执行；各阶段退出状态以 receipt 为准。

```sh
cd /data1/gzh/EC
python3 firesim/final-opt4-20261106/scripts/build_hw.py C4 compile
python3 firesim/final-opt4-20261106/scripts/continue_hw.py
python3 firesim/final-opt4-20261106/scripts/build_apps.py
python3 firesim/final-opt4-20261106/scripts/prepare_rootfs.py
python3 firesim/final-opt4-20261106/scripts/repair_linux_closure.py
python3 firesim/final-opt4-20261106/scripts/continue_system.py
python3 firesim/final-opt4-20261106/scripts/audit_roi_syscalls.py
python3 firesim/final-opt4-20261106/scripts/qemu_kernel_smoke.py C4
```

- 硬件 supervisor PID `{hw['pid']}`，阶段 PGID/start_ticks：{link(D/'C4-build-state.json')}，日志 {link(D/'C4-supervisor.log')}。
- 系统软件 supervisor PID `{system.get('pid','未启动')}`：{link(D/'system-supervisor-state.json')}。每个子构建单独记录 PID/PGID/start_ticks、超时、stdout、命令和源清单。
- 这些 PID 是状态文件中的身份记录，不是重新查询后的存活断言。先读增量日志及状态，正常主动检查不早于 5 分钟，不重复启动。
- 硬件链按 parameters → elaborate → GoldenGate → driver 自动前进；未启动任何 CAD/部署后台任务。
- Linux 初次配置失败因 checkpoint 排除名为 `target/build/output` 的真实源码目录；同版 Linux 6.2 archive 补全 250 个输入并验证，两组同样修复：{link(D/'linux-source-closure-repair.json')}。失败/中断日志保留，未覆盖旧源码或结果。
- `refresh_status.py` 只更新本入口及状态/绑定清单，不查询设备、不重算大型产物哈希。

## 软件、输入、地址布局与测量

- PARSEC：`{ROOT}/Software/PARSEC`，Commit `a06d35960951c9bfad61eb4826bca8d167f98c19`。
- 真实 Linux ELF：{link(W/'software/apps-build.json')}。Streamcluster/Canneal/Blackscholes 均为静态 RISC-V Linux 程序，原算法源码保持不变，统一 serial 分支、单线程、`-O3 -march=rv64gc -mabi=lp64d -static`。
- 已实际执行无真实 ROI hook 的 QEMU 软件参考：三个程序的 test/simsmall 共六例。Blackscholes 另对官方价格列验证：{link(D/'software/blackscholes-reference-validation.json')}。这些程序不计入 FPGA 样本。
- 共用 rootfs：`{rootfs['path']}`，SHA256 `{rootfs['sha256']}`，{rootfs['bytes']} bytes；{link(W/'software/rootfs-build.json')}。
- 每个程序的 argv、输入 archive/解包文件哈希、输出验证参考均在 apps manifest 内。正式输入和三次重复尚未开始，simsmall 当前只作为功能验证输入。
- 两组 Linux 统一 `{W}/software/linux-profile.json`：`MAX_PHYSMEM_BITS=36`、`SECTION_SIZE_BITS=27`，覆盖实际 RAM `[0x80000000,0x480000000)`；没有 Linux `mem=` cap。保留 16 GiB 生成 RAM，未混用旧 32 MiB diagnostic36-small。
- 两组 DT 由真实对应 elaboration DTS 修改：只给 Linux hart0，C4 hart1..4 留给固件；保留原内存/MMIO布局。OpenSBI 使用真实 checker 服务、实验 SBI ID `0x08004f50`；不复用冲突 PMU ID。
- 目标 BOOM/uncore 200 MHz、checker 100 MHz；50 MHz 是 FPGA 宿主时钟。正式 slowdown 必须使用 BOOM ROI 目标周期。
- 两组须显式设置并读回：`+mm_readLatency_0=30 +mm_readMaxReqs_0=4 +mm_relaxFunctionalModel_0=0 +mm_writeLatency_0=30 +mm_writeMaxReqs_0=4`。旧 B 默认 maxreq4、C4 默认6，未进行最终 runtime readback。

## 尚未解决的运行适配

{link(D/'runtime-scope-audit.json')} 记录已确认范围及证据。现有 C4 Linux 接口是 `user_no_trap_one_mm`，一 boot 一 context/ROI；活跃 ROI 内 trap、非用户态或 satp 变化会置 fault。

- 原 Streamcluster ROI 内确有输出和文件系统调用，不能移动 ROI、删输出或改算法来掩盖。软件诊断的 QEMU strace 已观察 `write/openat/newfstatat/close`；诊断二进制名称含 `DIAGNOSTIC-NOT-FOR-FPGA`，不装入正式镜像。
- Canneal、Blackscholes test 的软件诊断未观察 ROI 内同步系统调用；定时中断、异常、checker 与实际 drain 仍未经 DUT 验证。
- 初期仅可在同一硬件部署下逐样本重启 guest，不能宣称已支持单 guest 多 ROI 批量运行。固件安全重入仍未实现。
- 严格校验 latency 目前缺少同一校验单元的 BOOM 执行完成与 Rocket 真正比较完成时间配对，保留 `null`。PACKAGE_BEGIN 不是完成；周期快照不是执行检查点。
- PACKAGE_RESULT 的等待路径日志字段还不足以独立证明队列中 saved seq/status 的对应；首跑须核验真实比较路径、任务匹配和正计数，不能仅凭日志名称认定通过。
- 真实 Check detection 源码已定位：`/data1/gzh/EC-opt4-perf/slowdown/blackscholes_validation/build/matched_check/source/chipyard`，基线 Commit `b3d7adddd1e2d2cf428dd933529de878226420cd`，仅三项配置修改；实际 patch 和旧 simulator 哈希已核验：{link(D/'real-check-source-audit.json')}。未移植 FireSim、未构建 bitstream，不使用 Opt4 关闭恢复替代；不阻塞首组 Native/Opt4。历史 Check checker I$ 为 2 KiB，最终 Correction 为 4 KiB，后续比较必须保留并说明。2/8 checker、消融、面积未铺开。

## 双卡占用、部署路径与阻碍

只读已有映射 `/opt/firesim-db.json`：

| BDF | 既有 UID/序列号 | sysfs XDMA 映射 |
| --- | --- | --- |
| `0000:e2:00.0` | `Xilinx/21770433G001A` | `xdma0` |
| `0000:21:00.0` | `Xilinx/21770433G02LA` | `xdma1` |

设备 PCI ID 为 `10ee:903f`，数据库 device 字段 `xcu280_u55c_0`，历史构建平台 U280。该映射不是新的部署前空闲证明；未运行有副作用的 enumeratefpgas。

1. **安全占用阻碍**：普通用户检查有 4,306～4,399 项 `/proc` 访问拒绝，不能证明两卡空闲；`sudo -n python3` 实际要求密码。用户当前无法提供双卡独占和管理员完整占用检查，部署等待。证据 {link(D/'hardware-precheck-unprivileged.json')}。
2. **空间阻碍**：当前 `/data1` 可用约 {c['disk_free_gib']:.1f} GiB。通用 `ec_dac/build.py` 和站点 safety 要求 80 GiB；当前在跑的兼容 Scala/system builder 保留自身 40 GiB guard。用户当前无额外专属空间。最终 CAD 未启动，不修改 guard，不删除他人/历史产物。
3. **系统级副作用**：兼容 manager 的真实实现位于 `{ROOT}/firesim/dac2026/work/opt4-linux-v6/C4/chipyard/sims/firesim/deploy/runtools/run_farm_deploy_managers.py`。`XilinxAlveoInstanceDeployManager.infrasetup_instance` 依次 `unload_xdma` → `flash_fpgas` → `load_xdma`；内部有 `sudo rmmod xdma` 和既有模块 `insmod`。它影响整台主机的两卡，不能单卡交错部署。

本次未打开 FPGA 设备，未部署、复位、PCIe rescan、全局驱动操作、升级驱动/固件、重启或终止他人任务。以后需在两卡任务都安全结束后，统一维护部署，再分别绑定独立 run 目录/日志/锁/PID 运行；一张卡先结束时不自动重新部署。

## 恢复到真实执行的顺序

先结束/核验当前构建，补齐最终 C4 bitstream 和与当前镜像绑定的采集链；解决原 ROI trap/中断范围。外部占用与空间条件具备后，在部署前重新做管理员完整检查，统一双卡维护部署，然后最短 smoke → test/simsmall 功能验证 → 相同正式输入各一轮 → 初始三次重复。

宿主必须持续落盘 UART/ROI/必要任务事件，定期刷盘，按源码/硬件/软件/输入版本原子提交完整样本；guest DONE 只写 `hardware_validation=HOST_REQUIRED`。当前没有 FPGA 采集流、完整样本或完成标记。失败/缺失不能丢弃，严格 latency 缺项不能伪造，也不能用宿主耗时计算 slowdown。
'''
    atomic(DOC,text)
    print(DOC)
if __name__=='__main__':main()
