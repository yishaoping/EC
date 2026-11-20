#!/usr/bin/env python3
"""Publish receipt-backed campaign status; never query devices or processes."""
import datetime as dt
import fcntl
import hashlib
import json
import os
import shutil
import subprocess
from pathlib import Path

W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
DOC=Path('/data1/gzh/EC/slowdown/final_opt4_freeze_20261106/FIRESIM_START_HERE.md')
def read(p,default=None):return json.loads(p.read_text()) if p.exists() else default
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def save(p,value):
    tmp=p.with_name(p.name+'.publish.tmp')
    with tmp.open('w') as f:
        f.write(value if isinstance(value,str) else json.dumps(value,indent=2)+'\n')
        f.flush();os.fsync(f.fileno())
    tmp.replace(p)
def link(p,label=None):return f'[{label or p.name}]({p})'

def main():
    lock=(D/'locks/campaign-publish.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX)
    now=dt.datetime.now(dt.timezone.utc).isoformat()
    subprocess.run(['python3',str(W/'scripts/coverage_status.py')],check=True)
    subprocess.run(['python3',str(W/'scripts/suite_matrix.py')],check=True)
    suite=read(D/'parsec-suite-progress.json',{})
    coverage=suite['coverage'];total=coverage['total_programs']
    cad=read(D/'C4-runtime-cad-state.json',{})
    readiness=read(D/'opt4-readiness-latest.json',{})
    cad_guard=read(D/'cad-wall-limit-guard-state.json',{})
    deployment=read(D/'latest-deployment.json',{})
    continuation=read(D/'fpga-continuation-state.json',{})
    second=read(D/'second-pcie-recovery-state.json',{})
    boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip()
    current_deployment=(deployment.get('host_boot_id')==boot_id and deployment.get('status')=='DEPLOYED_NOT_RUN')
    rows=[];running=[];incomplete=[];valid=[];failures=[]
    for manifest_path in sorted((D/'runs').glob('*/manifest.json')):
        out=manifest_path.parent
        result=read(out/'result.json')
        state=read(out/'state.json',{})
        if result is None:
            record=dict(run_dir=str(out),state=state)
            (running if state.get('status') in ['RUNNING','STARTING'] and state.get('host_boot_id')==boot_id else incomplete).append(record)
            continue
        complete=read(out/'complete.json',{})
        committed=(result.get('valid') and complete.get('result_sha256')==sha(out/'result.json')
                   and complete.get('identity_sha256')==result.get('identity_sha256'))
        ident=result['identity']
        row=dict(path=str(out/'result.json'),configuration=ident['configuration'],program=ident['program'],
                 input=ident['input'],repetition=ident['repetition'],valid=bool(committed),
                 software_profile=ident.get('software_profile','original-parsec-serial'),
                 formal=result.get('formal',False),roi_cycles=result.get('roi_cycles'),issues=result.get('issues',[]))
        rows.append(row)
        (valid if committed else failures).append(row)
    parsec=[r for r in valid if r['program']!='smoke']
    formal=[r for r in parsec if r['formal']]
    campaign=read(D/'campaign-state.json',{})
    campaign.update(updated_utc=now,status='ACTIVE',phase='FINAL_C4_CAD_AND_NATIVE_RUNTIME',
        suite_coverage=coverage,suite_progress=str(D/'parsec-suite-progress.json'),
        fpga_deployed=current_deployment,fpga_samples_valid=len(parsec),formal_samples_valid=len(formal),
        smoke_samples_valid=len(valid)-len(parsec),running_samples=running,incomplete_samples=incomplete,result_index=rows,
        active_builds=[str(D/'C4-runtime-cad-state.json')] if cad.get('status') in ['RUNNING','STARTING'] else [],
        disk_free_gib=shutil.disk_usage(D).free/2**30,continuation=continuation,
        current_host_boot_id=boot_id,current_board_inventory=str(D/'latest-deployment.json'),
        waiting_for=dict(final_C4_bitstream=cad.get('status'),runtime=continuation.get('stage')))
    campaign.setdefault('configurations',{}).setdefault('Native',{})['status']='VALID_PARSEC' if any(r['configuration']=='Native' for r in parsec) else 'NOT_VALIDATED'
    campaign['configurations'].setdefault('Correction',{})['status']='VALID_FPGA_SAMPLE' if any(r['configuration']=='C4' for r in valid) else 'CAD_'+str(cad.get('status'))
    save(D/'campaign-state.json',campaign)
    bindings=read(D/'artifact-bindings.json',{})
    bindings.update(observed_utc=now,fpga_deployed=current_deployment,valid_fpga_samples=len(parsec),formal_samples=len(formal),
        cad_state=str(D/'C4-runtime-cad-state.json'),deployment=str(D/'latest-deployment.json'),result_index=rows)
    current_software={
        'C4_kernel':W/'software/C4/formal-earlyconsole-kernel-build.json',
        'C4_firmware':W/'software/C4/formal-firmware-build.json',
        'C4_driver':W/'runtime/C4-efficiency-driver.json',
        'Native_post_reboot_kernel':W/'software/Native/reboot-earlyconsole-kernel-build.json',
        'Native_post_reboot_firmware':W/'software/Native/reboot-firmware-build.json',
        'Native_driver':W/'runtime/Native-efficiency-driver.json',
        'apps':W/'software/formal-apps-build.json','rootfs':W/'software/formal-rootfs-build.json',
        'canneal_apps':W/'software/canneal-formal-apps-build.json',
        'canneal_rootfs':W/'software/canneal-formal-rootfs-build.json',
        'Native_canneal_kernel':W/'software/Native/canneal-formal-kernel-build.json',
        'Native_canneal_firmware':W/'software/Native/canneal-formal-firmware-build.json',
        'C4_canneal_kernel':W/'software/C4/canneal-formal-kernel-build.json',
        'C4_canneal_firmware':W/'software/C4/canneal-formal-firmware-build.json'}
    bindings['active_software_receipts']={k:dict(receipt=str(p),sha256=sha(p),value=read(p))
                                           for k,p in current_software.items() if p.exists()}
    bindings['historical_receipt_note']='The original receipts map is retained as history; active_software_receipts and each run manifest bind current software. Existing Native formal samples retain their original software identities.'
    save(D/'artifact-bindings.json',bindings)
    archive=D/'documentation-history/FIRESIM_START_HERE-before-20261107-reuse.md'
    if DOC.exists() and not archive.exists():
        archive.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(DOC,archive)
    table='\n'.join(f"| {r['configuration']} | {r['program']} {r['input']} r{r['repetition']} ({r['software_profile']}) | {'有效' if r['valid'] else '失败/不完整'} | {r['roi_cycles']} | {link(Path(r['path']))} |" for r in rows)
    recovery_receipts=sorted((D/'interruptions').glob('host-reboot-*/receipt.json'))
    recovery_note='；'.join(link(p,p.parent.name) for p in recovery_receipts) or '无本轮新增中断'
    fluid_adoption=read(D/'software/fluidanimate-stable-formal-adoption.json',{})
    fluid_note=('用户已于2026-11-07明确授权稳定编号配对修复；正式profile为fluidanimate-stable-formal，两组同ELF/输入/原ROI。Native由定向服务ec-parsec-fluidanimate-stable-native在原队列和idle-repairs结束后补跑，C4由现有全套队列执行；旧失败和原profile保留。实际FPGA通过与正式轮数以全套矩阵为准。'
        if fluid_adoption.get('status')=='BOUND_FOR_BOTH_CONFIGURATIONS' else
        '授权修复尚未完成正式profile绑定，当前状态：'+str(fluid_adoption.get('status','NOT_ADOPTED'))+'。原失败与原profile保留。')
    text=f'''# 最终 Opt4 FireSim 实验统一入口

更新时间：{now}。用户已授权必要构建、目标卡无具体冲突时的安全部署及实验；无需额外独占凭据。未更新系统驱动、板卡固件或冻结 Tag，未主动重启服务器。

**全套共 {total} 个程序；Native 正式通过 {coverage['native_formal_passed']}/{total}；Opt4 正式通过 {coverage['opt4_formal_passed']}/{total}；有效配对 {coverage['paired_formal_passed']}/{total}。** 正式通过要求相同版本3轮；小输入功能验证另计。逐项 ELF、输入、命令、线程、ROI、正确性、缺项和队列见 {link(D/'PARSEC_SUITE_PROGRESS.md')} 与 {link(D/'parsec-suite-progress.json')}。本地正式列表包含13项 apps/kernels及3项netapps，freqmine亦在范围内；未把部分集合称为全套结果。

有效 FPGA PARSEC 样本 {len(parsec)}，正式样本 {len(formal)}，有效 smoke {len(valid)-len(parsec)}。当前 C4 CAD `{cad.get('status')}`；未获得有效 C4 样本前不计算 Correction/Native。{link(D/'results-summary.json')} 只计原子完成的有效样本并保留失败/缺项。

## Opt4 首验与优先衔接（2026-11-10）

13 项普通 PARSEC 的 Opt4 软件离线哈希审计为 {readiness.get('ready',0)}/13 就绪，收据 {link(D/'opt4-readiness-latest.json')} 绑定真实 ELF、输入/参考、rootfs、内核、固件、driver 以及 Native 三轮版本；这不是 C4 FPGA 通过。Fluidanimate 保持已授权的 stable-formal 修复 profile。
最终 bitstream 仍须通过原 CAD 输入/源码/时序与产物哈希认证。认证后在21卡安全边界部署，首验仅执行 smoke → Blackscholes test/reset 探测 → simsmall；全部正式样本由现有 coverage-first 唯一调度。优先级为所有可运行 C4 在先，配置内先覆盖所有 r1，再补 r2/r3；失败按版本保留并跳过，Native 网络任务只能在 C4 尚无可运行任务时执行。不得触碰 e2 或执行全局驱动/PCIe 操作。
原 CAD Python 恢复包装器存在24小时硬超时，会杀掉仍有进展的 Vivado。独立服务 `ec-parsec-cad-wall-limit-guard.service` 当前为 `{cad_guard.get('status','NOT_STARTED')}`，每300秒保存 {link(D/'cad-wall-limit-guard-state.json')}。它在23小时后只暂停原 Python 包装器的计时循环，Vivado 及其进程组不接收信号；CAD 子进程退出后唤醒同一个包装器，继续原始认证与落盘。60 GiB 余量/120 GiB 增长守卫保留。此期间包装器 T 状态及原 CAD 状态时间戳不更新属于已记录状态，须同时看 guard、实际 Vivado worker 和阶段日志，不能误判综合已停止。说明见 {link(W/'RUN_RECOVERY.md')}。

## 覆盖优先调度与逐轮状态

2026-11-07 新增 `ec-parsec-coverage-first.service`，已启用系统启动恢复。逐项 test、simsmall、r1/r2/r3 及已核实进程身份见 {link(D/'COVERAGE_STATUS_LIVE.md')} 和 {link(D/'coverage-status-live.json')}；每300秒随发布器更新。
旧队列保留当前 Freqmine 批次、定向修复服务及 C4 首次部署验证器，未来任务在安全边界交给该唯一服务；它按正式首轮覆盖、第二轮、第三轮推进，只复用精确版本的原子完成样本。失败阶段记录后继续其他程序，缺失软件仍列在32个配置/程序槽中，软件绑定补齐后自动进入队列。
状态 {link(D/'coverage-first-state.json')}；日志 `{D}/coverage-first-logs/`、`{D}/jobs/coverage-first/console.log`。旧 C4 全套等待门标为 `DELEGATED_TO_COVERAGE_FIRST_SERVICE`，避免其部署恢复与新所有者竞争；未停止原有FPGA/CAD任务。详细交接证据见执行计划的 `handoff_receipt`。
Native Blackscholes 既有3轮保留各自原始 observed/restart 驱动哈希；已审阅 host-only patch，仅 journal序号原点/宿主效率记录变化，ROI tick与RTL不变，允许复用目标周期；宿主效率数据按原驱动区分。

## 作业托管与断线恢复

恢复规则、只读核验命令、系统级 unit、状态和日志入口见 {link(W/'RUN_RECOVERY.md')}。新长任务由 `ec-parsec-*.service` 托管，启动先核对 PID/启动 tick/boot_id；存活进程只监控，不停止、迁移、重复启动或修改输入。确认退出后按完成 DCP 或精确版本样本原子标记恢复。`{D}/jobs/<name>/state.json`、`console.log`、`startup-audit.json` 为持久入口。统计快照不是指令级检查点。

## 版本与可复用产物

- 冻结 commit `8491167d84b6d9521b151a743673c1516926a1f8`，Tag `opt4-final-performance-fpga-20261106`，v1Config、4 checkers、SVB32、L2 report-permission repair；未修改。
- 冻结备份 `/data1/gzh/EC-backups/opt4-final-performance-20261106/source/chipyard`。实际 C4 输入 `{W}/C4/chipyard` 是独立源快照，不以父目录 Git HEAD 冒充版本。source_id `c9f51d3a94aac7783c750682162cd25e9d1460b04974bde9b7541f1d9f4120e7`。
- {link(W/'integration.json')} 和 `{W}/frozen-to-firesim.patch` 绑定集成差异；{link(D/'hardware-revalidation-20261106.json')}、{link(D/'generated-svb-audit.json')} 及 GoldenGate receipt 绑定源码到生成产物。实际使用 FireSim 1.17.0 `07efa6a6da18bd64d1159ae84a4701b37abb1228` / Chipyard 1.9 / Vivado 2021.1，未升级工具链。
- Native 真实 0 checker、单 BOOM，无保护；{link(W/'native-reuse.json')} 绑定既有可复用 bitstream，SHA256 `bbe70b655538fa8d17deb72c4307ac66167ee0510aa12d0270ce2c9e37a34aea`。最终 C4 bitstream 尚由当前 CAD receipt 决定，不能用旧 Opt4 代替。
- 不因程序、输入、重复编号或只改软件而重做 bitstream。复用同一硬件时只重启 guest；C4 同部署第二个样本必须通过目标 reset 探测，之后每个样本仍独立核对启动、输出、ROI、真实校验匹配及排空。无效/中断样本保留并补跑；reset/驱动兼容性失败时复用原 bitstream 重新部署。

## 当前构建、空间与中断

- 主机于 2026-11-06 22:07 本地时间重启；旧 `/tmp` CAD/内核/payload 消失，旧两项 C4 CAD 与 Native r4 中断，未计有效。原状态和唯一失败证据保留。
- 2026-11-07 11:35:19 本地时间再次发生主机重启，boot ID 变化；本任务没有执行重启。中断状态及恢复收据：{recovery_note}。本轮 `/var/tmp` CAD/内核/payload 全部保留；当前 CAD 复用已完成 IP 检查点 {cad.get('reused_checkpoint_count',0)} 个，仅补建未完成阶段。Native/Opt4 的有效完成样本继续复用，未完成样本明确保留为 INTERRUPTED。
- 只保留一个正在运行的最终 C4 CAD：PID `{cad.get('child_pid')}`，{link(D/'C4-runtime-cad-state.json')}，日志 `{cad.get('log_dir')}`，输出 `{cad.get('output_dir')}`。状态由构建程序持续保存；不启动第二个候选。
- 已获用户例外授权处理失败 CAD，完整证据见 {link(D/'interruptions/authorized-failed-cad-20261107T064048Z/receipt.json')}。仅停止该失败服务，Native 身份不变。恢复脚本现在以原项目用户执行，先生成综合脚本再同步执行，保留11个完成IP检查点；根本启动异常原因仍未证实。当前进度见 {link(D/'cad-runtime-progress-latest.json')}，不以外层进程存活代替实际综合 worker。
- CAD 工作区现为持久根分区 `/var/tmp/guozh-firesim-final-opt4-20261107-cad`，启动空闲 {cad.get('disk_budget',{}).get('initial_free_gib',0):.1f} GiB，最近快照 {cad.get('disk_free_gib',0):.1f} GiB；80 GiB 启动、60 GiB 停止余量、120 GiB 增长预算。与 `/data1` 是不同文件系统，未降低阈值。
- 已授权旧废弃 `.Xil/**/*.rtd` 清理证据：{link(D/'batches/Native-20261106T113308Z/cleanup.json')}。此次额外空间来自另一文件系统；没有为腾空间删除有效源码/bitstream/软件/结果。
- formal rootfs、PARSEC 应用、输入与 DTB 持久产物复用；C4 缺失 Linux/OpenSBI 已在 `/var/tmp` 重建，{link(W/'software/C4/formal-earlyconsole-kernel-build.json')}、{link(W/'software/C4/formal-firmware-build.json')}。恢复后 C4 `.config` SHA256 `cd367595b60ffe7e2c33d1e3a0049a2461a102f71f6681b7e818598693e1377d` 与旧 formal kernel 一致；编译完成仍不是 FPGA 通过。

## 板卡、安全维护与批次

- 单卡恢复入口：21 维护锁 `{D}/locks/maintenance-0000_21_00.0.lock`；状态 {link(D/'active-0000_21_00.0.json')}；服务日志 `{D}/jobs/coverage-first/console.log`。重连先核对 PID、start_ticks、boot_id 与 cgroup，活进程接管监控，确认退出才按原子 complete 补跑。安全切换完成证据：{link(D/'safety/21-only-20261109/final-state.json')}。
- 安全修复与离线检查：[21-only safety report]({D/'safety/21-only-20261109/REPORT.md'})。通用 FireSim Manager 的实体卡 infrasetup/enumeration 已禁用；部署入口为 `{W}/scripts/infrasetup.py Native|C4`，只复用认证 bitstream。
- 当前部署目标固定为 Xilinx U280 `0000:21:00.0` / `21770433G02LA`；`0000:e2:00.0` / `21770433G001A` 保留为不触碰设备。系统映射与两端点型号记录在 {link(D/'fpga-target-map-20261109.json')}。旧 `restore_second_pcie.py` 已禁用。
- 每次部署前检查目标 BDF/序列号、所有可见进程和 XDMA FD/MMIO；权限拒绝单独记录；具体目标设备冲突才阻止部署。FireSim `fpga-util.py` 只接受精确 `0000:21:00.0`（序列号仅由核验映射取得，拒绝 serial-only 编程），拒绝 `--all-bdfs` / `--all-serials`。部署按目标设备 unbind/remove/JTAG/上游桥 rescan/rebind，不卸载全局 XDMA 模块，也不写 `/sys/bus/pci/rescan`。21 的运行实例持有单卡共享维护锁；21 部署需单卡独占锁。既有 e2 活样本保持不动，不加载或卸载主机级模块。
- 本任务自有 `hw_server:3122` 的 PID、boot ID、日志位于 {link(D/'owned-hw-server-3122.json')}。未停止其他服务或任务，未运行有副作用的 enumeratefpgas。
- 最新部署 {link(D/'latest-deployment.json')}，当前 boot ID 匹配：`{current_deployment}`。实际编程证明在该 batch 的 `program-Xilinx_*.log`，部署状态不代替运行验证。
- 续跑进程 {link(D/'fpga-continuation-state.json')}：最终 bitstream 成功及软件绑定通过后，仅在 `0000:21:00.0` 部署，执行 C4 smoke → Blackscholes test/reset 探测 → simsmall，再将所有正式首轮与重复交给 coverage-first。功能门槛不通过时不进入正式测量；重复结果持续保存。
- 后续全套队列 {link(D/'suite-execution-plan.json')}；Native 扩展 {link(D/'suite-native-queue-state.json')} 在综合期间仅使用21；C4扩展 {link(D/'suite-c4-queue-state.json')} 等首个控制器结束后依次运行就绪程序。原 Canneal/Streamcluster 等待控制器已在确认无子任务后并入全套队列，历史状态保留，未中断样本。各程序先小输入门槛再正式3轮，故障逐项保留；C4仅在具体失败guest后由统一维护流程重载同一认证bitstream以恢复，其余软件/输入变化不触发bitstream重建。

## 软件、公平性与观测

- `{W}/software/formal-apps-build.json`、`formal-rootfs-build.json` 为首组 Native/C4 共用软件，rootfs SHA256 `427d0b923bc2be77b67ba0ff11efd47bb83c7bbf28fd990e10c658dcf7178711`；Blackscholes Linux 静态 ELF SHA256 `75b4e2923b0a7b1d096023daa6610f5c622bf04771b4e2966bbdee006e5270ea`。所有输入/argv/参考输出由 manifest 绑定；未把裸机 ELF 当 Linux 程序。
- Blackscholes 官方 simmedium：16384 options、NUM_RUNS=100、串行单线程、无预热；与已完成 Native r1/r2/r3 一致。已有 QEMU 参考与 FPGA Native 输出校验，C4 必须另行通过真实 checker 证明。
- 两组 BOOM/uncore 200 MHz、C4 checker 100 MHz；host FPGA 50 MHz 单列。FASED 为 LatencyBandwidthPipe，读/写延迟30、max requests4、relaxFunctionalModel0，每个样本要求全部寄存器读回相等。
- 实际硬件 RAM `[0x80000000,0x480000000)` 共16 GiB，Linux 两组统一物理位宽36、SECTION27、`mem=2G`、相同 bootargs；与无cap/诊断配置结果分开。{link(D/'matched-guest-mem2g.json')} 记录布局。不得用宿主墙钟计算体系结构 slowdown。
- C4 固件每次 guest 一个 ROI，hart0 Linux、hart1..4 真实 checker 服务。要求 generated=completed=passed>0，fault/failed/cancelled/dropped/outstanding=0、每个任务序号匹配、full_compare=1、真实 drain 及 firmware park mask15；缺项不提交有效标记。
- 严格 latency 尚缺同一任务 BOOM 执行完成与 Rocket 真比较完成的统一时基事件，保留 null，不把 PACKAGE_BEGIN、入队或采样时刻充数。已有128项 traffic 寄存器在排空后读回；利用率/队列指标仅报告已验证接口。

## Streamcluster 与后续

- 原 Streamcluster ROI 包含进度 stderr write、结果 open/fstat/write/close；这是实际功能缺口。串行候选未发现线程同步或计时 syscall。DacRoiController 在 ROI 内 trap/非U态/satp变化置 fault8，不能跳过。
- 当前正式队列已选 `streamcluster-staged-formal`，绑定官方 simmedium/full original ROI，Native 正式三轮已原子提交；C4 真实比较、输出和排空仍待验证。旧 `streamcluster-staged` 仅保留为功能阶段历史证据，不用于正式汇总。
- 历史软件候选 {link(D/'software/streamcluster-staged-diagnostic-20261106T115645Z/result.json')} 保留原 ROI hook位置、输入生成、聚类和结果格式化，把外部文件/日志 I/O 延后，并预置内存。当前正式 profile 的真实ROI接入为 {link(W/'software/streamcluster-staged-formal-apps-build.json')} 和 {link(W/'software/streamcluster-staged-formal-rootfs-build.json')}；两组同用官方 simmedium、原完整计算及格式化 ROI，不能与旧功能 profile 或原版输入结果混合。Native 已正式通过，C4 真实校验仍待 FPGA 验证。文件输入及异步中断仍未证明。
- x264 新 profile `x264-no-progress` 复用原 encoder、原 staged ELF 和全部编码/延迟帧排空 ROI，在两组及参考一致启用原 CLI 的 `--no-progress`；test/simsmall/simmedium 输出逐字节一致且软件诊断 ROI syscall 为0，仍需 FPGA 验证。Facesim 使用 `facesim-staged-resident` 预载原控制文件，保持读解析/插值/完整求解在原 ROI；Raytrace `raytrace-headless` 仅移除不可达GL显示，保留官方多帧渲染，记录原本未渲染的边缘像素与 test 1x1 无计算限制。它们的实际 profile、输出校验与未解决问题以全套矩阵为准。
- Fluidanimate Native simsmall 两次输出校验失败，保留为无效样本；新诊断镜像复用同一 ELF/输入/ROI，失败前回收完整 out.fluid，禁止正式使用或放宽校验。独立服务 `ec-parsec-idle-repairs` 等现有 Native 全套队列空闲后定向补跑 Dedup 与该诊断；`ec-parsec-fluidanimate-output-analysis` 严格核对 UART 文件信封、字节数与版本，再量化字段差异。入口为 {link(D/'idle-repairs-state.json')} 与 {link(D/'software/fluidanimate-fpga-output-analysis.json')}，不抢占活样本，不自动重新部署 Native。
- Fluidanimate Linux reference 已从完整 UART 证据恢复，无须重跑 QEMU，收据 {link(D/'software/fluidanimate-linux-reference-recovery.json')}。随后两个独立 systemd 软件诊断定位了原程序跨分配指针比较的漏算：第一帧 QEMU user/Linux 分别漏掉3,662/6,798个半径内跨cell对；仅加计数的二进制逐字节复现各自原输出。{link(D/'software/fluidanimate-pair-selection-diagnostic.json')} 与 {link(D/'software/fluidanimate-stable-order-candidate.json')} 保存全部计数、来源、补丁和日志。两处稳定编号谓词的候选在两环境输出逐字节一致、跨cell漏算0，但它改变原版错误数值轨迹。{fluid_note} 采用收据见 {link(D/'software/fluidanimate-stable-formal-adoption.json')}。不能由QEMU结果推断FPGA通过。
- Dedup 首次在应用启动前因 initramfs `broken padding` 失败：OpenSBI 默认 DTB 拷贝地址 `0x82200000` 落入从 `0x80200000` 开始的 57,467,904 字节内核 Image。完整归档本身与内嵌压缩数据逐字节一致，GDB/QEMU 保存了错误和地址证据。软件修复将 Native/C4 固件的 `FW_PAYLOAD_FDT_ADDR` 与 `FW_JUMP_FDT_ADDR` 一致设为 `0xbfe00000`，构建前检查其位于统一 mem=2G 内且不与内核重叠；应用、ROI、输入、rootfs、内核和 bitstream 不改。Dedup/Facesim/Ferret/Raytrace 的 `*-safe-fdt` profile 均已 QEMU 启动并校验全部文件 SHA256 通过，**尚不等于 FPGA 通过**。证据见 {link(D/'software/large-payloads-preparation.json')}。未来任务计划已绑定新固件，旧失败样本不改写，当前 Freqmine 输入不变。
- 三个网络程序未移出范围。{link(D/'software/network-original-roi-audit.json')} 记录完整原 ROI 和实际依赖：默认 user TCP/shared-memory 路径不能仅因 CONFIG_NET=n 判不可行，但其 RISC-V 移植、线程/阻塞/上下文支持尚未完成；当前 C4 ROI trap/context 合约不支持直接照搬。Netdedup 正式 runconf 含服务器 getopt 不接受的 -p/-i，且 wrapper 输入不同；Netstreamcluster 的 simmedium 实际选择 simlarge。没有用单机版替代或移出网络计算来计通过，未擅自修改冻结 DUT。
- 共用 uptcpip 已在隔离副本实际尝试 RISC-V 构建：原 Makefile 在缺少 `include/riscv64` 时退出2；独立编译 `uptcp_statis.c` 又因 x86 `%rax/%rbx/%rcx/%rdx` 汇编寄存器失败。{link(D/'software/network-riscv-build-probe.json')} 绑定命令、日志哈希和返回码；这不是已完成的网络程序移植，也没有产生ELF。
- 上述网络构建失败是历史证据；后续独立移植及三输入Linux结果见 {link(D/'software/NETWORK_PREPARATION.md')}。2026-11-09 Native网络双进程guest/真实hooks/完整输出接入已完成，原coverage-first已实际启动网络程序；当前版本与恢复入口见 {link(D/'software/NETWORK_NATIVE_RUNNING.md')}，实时通过状态以完整result/complete哈希为准，不能把离线成功计入FPGA。完整原ROI离线探针见 {link(D/'software/network-complete-roi-probe.json')}。Native允许原线程/syscall；C4驱动、固件和monitor仍没有支持完整线程/trap ROI的pause/resume路径，不能通过分段省略、删除guard或mask fault通过，也不把Native通过当C4通过。
- 2026-11-09实际恢复 {link(D/'software/ferret-vips-recovery-20261109.md')}：Vips固件DTB地址重叠已按safe-FDT修复；Ferret独立stable-order profile只在预载阶段固定目录顺序，逐查询结果、计算object和完整ROI保留。两组同ELF/输入/ROI，原队列已接入新profile；Native test/simsmall均有有效FPGA结果，正式轮次见实时矩阵。状态 {link(D/'software/vips-safe-fdt-recovery.json')}、{link(D/'software/ferret-order-recovery.json')}；旧失败保留，未改冻结硬件、bitstream或正常调度服务。
- Canneal、Blackscholes 原 ROI 的软件诊断无同步 syscall；实际 checker/排空仍由板级验证决定。真实 Check 实现审计 {link(D/'real-check-source-audit.json')}，尚未 FireSim 构建，不阻塞 Native/C4。2/8 checker、面积及消融后续处理。
- Canneal 独立正式输入 profile：{link(W/'software/canneal-formal-apps-build.json')}、{link(W/'software/canneal-formal-rootfs-build.json')}，官方 simmedium 为200000.nets、15000 swaps、初温2000、64 steps、1线程；复用原 ELF，不缩计算。两组内核以现有已构建目录增量构建，仅更换相同 initramfs；{link(D/'software/canneal-formal-software-reuse.json')} 核对配置（除 initramfs 路径）和 ROI driver object 不变。须先通过该 profile 的 FPGA simsmall 再采正式三轮；不与 Blackscholes 原 profile 混用。

## 实际入口与持续证据

```sh
cd {W}
# 已有构建正在运行；不要重复执行 bitstream 构建。
python3 scripts/continue_fpga.py --check-software-only
sudo python3 scripts/continue_fpga.py --single-board-bdf 0000:21:00.0
```

启动续跑前检查已有状态/PID/boot ID，避免重复控制同一卡。每个 run 目录持续保存 UART、host、ROI/RTL事件；30秒快照刷盘。`result.json` 与 `complete.json` 原子提交并绑定源码/bitstream/driver/软件/输入；统计快照不是指令级恢复检查点。失败、超时、中断和不完整尾部保留；只有匹配版本的有效完成样本可复用。正常主动查询至少间隔5分钟，长构建可10分钟。

| 配置 | 程序输入重复 | 状态 | ROI周期 | 结果 |
| --- | --- | --- | --- | --- |
{table}

历史 Verilator Streamcluster project64 的1.1995×不作为 FPGA 结果或调参目标。当前阶段不对缺少C4配对的数据发布 slowdown；共同有效集合与重复波动由 results-summary.json 明确记录。
'''
    save(DOC,text)
    print(json.dumps(dict(document=str(DOC),valid_parsec=len(parsec),valid_formal=len(formal),
                          c4_cad=cad.get('status'),deployment_current_boot=current_deployment)))

if __name__=='__main__':main()
