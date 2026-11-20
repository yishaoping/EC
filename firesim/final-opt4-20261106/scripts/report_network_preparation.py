#!/usr/bin/env python3
"""Publish candidate evidence; never emit formal apps/rootfs/firmware receipts."""
import datetime as dt
import json
from pathlib import Path
from board_batch import W,D,save,sha

def read(p,default=None):return json.loads(p.read_text()) if p.exists() else default

def main():
    root=D/'software';base=read(W/'software/network-candidate-build.json')
    first=read(root/'network-offline-validation.json');follow=read(root/'network-followup-state.json')
    ferret=read(root/'netferret-sameisa-state.json');linux=read(root/'network-linux-validation.json',{})
    sc_linux=read(root/'netstreamcluster-linux-validation.json',{})
    now=dt.datetime.now(dt.timezone.utc).isoformat();rows={}
    old=Path(first['output_dir']);new=Path(follow['output_dir'])
    driver=W/'software/C4/linux/drivers/misc/ec_dac_roi.c'
    monitor=W/'C4/chipyard/generators/rocket-chip/src/main/scala/util/DacRoi.scala'
    gate=dict(status='BLOCKED_ORIGINAL_ROI_PROTOCOL',driver=dict(path=str(driver),sha256=sha(driver),
        predicate='dac_begin: context_started || get_nr_threads(current) != 1 || !service_va -> -EOPNOTSUPP'),
        monitor=dict(path=str(monitor),sha256=sha(monitor),predicate='running (or ended and busy) plus trap/prv!=U/satp mismatch -> faults bit 8'),
        evidence='Saved QEMU test syscall traces contain actual clone/futex/nanosleep in original ROI. User TCP is shared-memory transport; CONFIG_NET=n alone is not its blocker.',
        required='A proved checker-compatible execution/context path preserving entire original ROI and real comparisons. Do not remove guards, mask faults, disable checking or narrow ROI.',
        hardware_modified=False,driver_modified=False)
    for name in ['netdedup','netferret','netstreamcluster']:
        evidence=[]
        for size in ['test','simsmall','simmedium']:
            path=new/(name+'-'+size+'-riscv64')/'result.json'
            if not path.exists():path=old/(name+'-'+size+'-riscv64')/'result.json'
            result=read(path);assert result['status']!='FAILED_WITH_EVIDENCE'
            item=dict(input=size,qemu_user_result=str(path),result_sha256=sha(path),
                both_peers_exit_zero=all(v==0 for v in result['exit_codes'].values()),
                server_argv=result['server_argv'],client_argv=result['client_argv'],input_archive=result['input_archive'],
                output=result['output'],diagnostic_roi=result['roi_diagnostic'],fpga_valid=False)
            if name=='netdedup':
                item['correctness']=result['correctness'];item['passed']=result['correctness']['passed']
                host=read(old/(name+'-'+size+'-x86_64')/'result.json')
                item['cross_isa_compressed_output_exact']=host['output']['sha256']==result['output']['sha256']
            else:
                ref=Path(ferret['log_dir'])/size/'result.json' if name=='netferret' else new/(name+'-'+size+'-riscv64-kernel')/'result.json'
                other=read(ref);assert other['status']!='FAILED_WITH_EVIDENCE'
                item['same_isa_socket_reference']=dict(result=str(ref),result_sha256=sha(ref),output=other['output'])
                item['passed']=other['output']['sha256']==result['output']['sha256']
                assert item['passed'],'unresolved same-ISA output mismatch'
            evidence.append(item)
        conf=Path('/data1/gzh/EC/Software/PARSEC/pkgs/netapps')/name/'parsec/simmedium.runconf'
        row=dict(schema='ec-network-program-preparation/1',program=name,status='QEMU_USER_AND_REFERENCE_PASSED_TARGET_LINUX_PENDING',
            observed_utc=now,profile='network-riscv-port-v2-diagnostic',parsec_commit=base['source_parsec_commit'],
            candidate_receipt=str(W/'software/network-candidate-build.json'),candidate_receipt_sha256=sha(W/'software/network-candidate-build.json'),
            binaries=base['programs'][name]['binaries'],patch=dict(path=base['patch'],sha256=base['patch_sha256']),
            formal_runconf=dict(path=str(conf),sha256=sha(conf)),application_threads_argument=1,
            roi='Original server __parsec_roi_begin/end sites unchanged; diagnostic hooks, not real checker hooks',
            offline_cases=evidence,formal_eligible=False,fpga_validation='NOT_RUN',
            linux_validation_state=str(root/'network-linux-validation.json'),
            linux_cases=[r for r in linux.get('cases',[]) if r['program']==name],
            c4_admission=gate,
            queue_admission='Existing coverage-first already enrolls all 16. Formal apps/rootfs/config firmware receipts must be bound only after valid target software/checker path exists; no candidate receipt enables scheduling.',
            still_missing=['Target Linux protocol/correctness validation','Real ROI hook integration and validated original-ROI C4 context support','Immutable runnable rootfs and Native/C4 firmware receipts','FPGA smoke, small input, real checker/drain/correctness validation'])
        if row['linux_cases'] and any(r['status']=='FAILED_WITH_EVIDENCE' for r in row['linux_cases']):row['status']='QEMU_USER_AND_REFERENCE_PASSED_LINUX_FAILURE_RETAINED'
        if name=='netstreamcluster' and sc_linux:
            assert sc_linux['candidate_receipt_sha256']==row['candidate_receipt_sha256']
            row['linux_cases']=[r for r in row['linux_cases'] if r['input']=='test']+sc_linux['cases']
            row['linux_validation_state']=str(root/'netstreamcluster-linux-validation.json')
            if {r['input'] for r in row['linux_cases'] if r['status']=='LINUX_PROTOCOL_AND_EXACT_OUTPUT_PASSED'}=={'test','simsmall','simmedium'}:
                row['status']='TARGET_LINUX_EXACT_OUTPUT_PASSED_C4_ORIGINAL_ROI_BLOCKED'
                row['still_missing'].remove('Target Linux protocol/correctness validation')
        if name=='netdedup':
            row['mapping']='Repair CLI wiring: server -c -v -t 1 -o out.ddp; client -i test.dat for test, unchanged media.dat archives for small/formal. Original invalid -p/-i server args and wrapper test.dat mismatch retained as evidence.'
            row['additional_candidate']=dict(preparation_state=str(root/'netdedup-linger-preparation.json'),linux_state=str(root/'netdedup-linger-linux-validation.json'),
                reason='Single-core Linux v2 timed out after client exited; independent graceful-close candidate preserves computation/server ROI. No v2/v3 evidence mixing.')
        if name=='netstreamcluster':
            row['mapping']='Local simmedium.runconf actually invokes run.sh 1 simlarge; preserve server 10 20 128 16384 16384 1000 none output.txt 1 and client 128 16384 16384 1.'
            row['cross_isa_note']='simsmall x86/RISC-V 340 fields: 4 coordinates differ by exactly 0.000001; no tolerance pass asserted. All test/small/formal outputs are byte-exact against same-ISA original socket reference.'
        if name=='netferret':
            row['mapping']='Original pthread server pipeline retained; 1/16/64 queries for test/simsmall/simmedium, all complete. No substitution with standalone serial Ferret.'
            row['cross_isa_note']='x86 differs in large-input ranks; not accepted by numerical tolerance. Same RISC-V original socket implementation returns exactly the same full output as user TCP for all three sizes.'
            row['retained_failure']=str(old/'netferret-test-riscv64/result.json')
            row['protocol_review']='Original client has duplicate receive-byte accounting and does not frame partial headers robustly; saved untraced tests pass but this remains a transport robustness risk, not a proven fix.'
        variant='netdedup-linger' if name=='netdedup' else ('netferret-protocol' if name=='netferret' else None)
        if variant:
            prep=read(root/(variant+'-preparation.json'),{})
            target=read(root/(variant+'-linux-validation.json'),{})
            row['independent_repair_candidate']=dict(preparation=str(root/(variant+'-preparation.json')),status=prep.get('status'),
                receipt=prep.get('receipt'),patch=prep.get('patch'),patch_sha256=prep.get('patch_sha256'),
                target_linux_state=str(root/(variant+'-linux-validation.json')),linux_cases=target.get('cases',[]),
                formal_eligible=False,output_comparisons=[])
            row['independent_repair_candidate']['linux_failure_evidence']=[]
            for c in target.get('cases',[]):
                result_path=Path(c['result']);r=read(result_path,{})
                if r.get('status')!='FAILED_WITH_EVIDENCE':continue
                log=result_path.parent/'console.log'
                text=log.read_text(errors='replace') if log.exists() else ''
                row['independent_repair_candidate']['linux_failure_evidence'].append(dict(input=c['input'],result=c['result'],
                    returncode=r.get('returncode'),both_peers_exit_zero=r.get('both_peers_exit_zero'),
                    exact_qemu_user_output=r.get('exact_qemu_user_output'),
                    assertion_lines=[line for line in text.splitlines() if 'Assertion' in line],
                    root_cause='UNPROVEN; retain complete failed sample and do not change correctness gate'))
            for c in prep.get('user_cases',[]):
                r=read(Path(c['result']),{})
                expected=next(e['output']['sha256'] for e in evidence if e['input']==c['input'])
                row['independent_repair_candidate']['output_comparisons'].append(dict(input=c['input'],result=c['result'],
                    passed_protocol=r.get('status')!='FAILED_WITH_EVIDENCE' and bool(r.get('output')),
                    exact_v2_output=r.get('output',{}).get('sha256')==expected))
            if target.get('active_case'):
                log=Path(target['output_dir'])/target['active_case']/'console.log'
                if log.exists():
                    text=log.read_text(errors='replace')
                    if 'Assertion `obj != NULL\' failed.' in text:
                        row['independent_repair_candidate']['observed_linux_failure']=dict(log=str(log),
                            symptom='t_out: Assertion obj != NULL failed; server aborted',root_cause='UNPROVEN; do not skip invalid results',
                            case=target['active_case'])
            if name=='netdedup':
                row['independent_repair_candidate']['boundedness_note']='Original _sleep in uptcpip/freebsd.kern/kern_synch.c ignores timo and calls an untimed condition wait. SO_LINGER alone is not a proved bounded closure fix; the outer QEMU timeout remains mandatory.'
                row['next_transport_candidate']=dict(preparation=str(root/'netdedup-framed-preparation.json'),
                    linux_state=str(root/'netdedup-framed-linux-validation.json'),
                    scope='Explicitly consume the original length header and every declared payload byte, avoiding reliance on a final EOF from an exiting in-process TCP stack. Original compression and ROI sites retained; requires new independent validation.',
                    state=read(root/'netdedup-framed-preparation.json',{}),formal_eligible=False)
        save(W/'software'/(name+'-candidate-build.json'),row);save(root/(name+'-preparation-state.json'),row);rows[name]=row
    suite=read(D/'coverage-status-live.json')
    summary=dict(schema='ec-network-preparation-summary/1',observed_utc=now,hardware_commit='8491167d84b6d9521b151a743673c1516926a1f8',
        formal_eligible=False,fpga_execution=False,programs=rows,existing_queue_evidence=dict(path=str(D/'coverage-status-live.json'),
            observed_utc=suite['updated_utc'],total_programs=16,runnable_software_programs=suite['runnable_software_programs'],
            all_programs_automatically_enrolled=suite['all_programs_automatically_enrolled']),
        linux_in_progress=linux.get('status')!='COMPLETE_REVIEW_EVIDENCE')
    save(root/'network-preparation-summary.json',summary)
    lines=['# 网络 PARSEC 软件准备证据','',f'快照时间（UTC）：{now}。这些结果均不是 FPGA 正式样本。冻结硬件未改变。','',
        '| 程序 | 已实际完成 | Linux guest | C4/FPGA 入队状态 |','|---|---|---|---|']
    for name,row in rows.items():
        evidence='完整解码与输入一致，x86 压缩输出相同' if name=='netdedup' else '完整输出与同 RISC-V 原 socket 参考逐字节相同'
        ls='；'.join(r['input']+': '+r['status'] for r in row['linux_cases']) or '独立作业验证中，未判通过'
        lines.append(f'| {name} | RISC-V 静态 server/client ELF；test/simsmall/正式映射均完成；{evidence} | {ls} | 未进入正式执行；原 ROI 的多线程/trap 协议未解决 |')
    lines+=['','完整 ELF/输入/补丁哈希、命令和各级原始证据：'+str(root/'network-preparation-summary.json'),'','## 版本与测量边界','',
        'v2 共享内存 SPSC ring 使用 acquire/release 发布消费顺序，原始 PARSEC 应用计算源码和 ROI 保留。ELF 使用诊断 hooks，不能用来提交真实 checker 样本。旧 v1 与 v2 的 trace 失败证据保留。',
        'Netdedup 的原始 server CLI 与 client 文件名有接入缺陷，候选显式拆分，仍使用原 test/media.dat 文件。Netstreamcluster 必须保留本地 simmedium 实际调用 simlarge 的正式工作量。Netferret 使用原网络 pthread pipeline。',
        '跨 x86 的差异不以放宽容差判通过；Netferret/Netstreamcluster 采用同 ISA、未改计算源码的原 socket 参考完成精确比较。单核 Linux 的实跑结果另存，不能用 user-mode 成功覆盖 Linux 失败。','',
        'Netdedup 独立 graceful-close 候选及 Netferret 独立 framed-I/O/end-tag 候选都已完成 QEMU user test/simsmall/simmedium，输出与 v2 一致；这些是新软件版本的证据，未正式采用。Netdedup 单靠 linger 仍未证明 Linux 可完成，且上游 _sleep 忽略 timo，不能声称其内部超时有效；外层 guest 超时仍生效。Netferret 新候选 Linux test 已观察到 t_out 的 obj != NULL 断言，根因未证实，不屏蔽断言/丢弃结果。各候选补丁、ELF 哈希和独立 Linux case 状态在 JSON 的 independent_repair_candidate 字段。','',
        '## 确认的 C4 接入限制','',
        f'驱动 {driver} 的 dac_begin 明确要求 get_nr_threads(current)==1；网络栈/应用会创建线程。ROI 监测 {monitor} 对区间内 trap、非 U 特权或 satp 变化记 fault 8。保存的诊断已观察到实际 clone/futex/nanosleep，不能去掉守卫或屏蔽 fault 当作兼容。',
        '仅将 I/O/网络搬出原 ROI 或把 pthread 换成别的算法不能提交原实验。需要完整原 ROI 的可证明 checker context 路径，之后绑定真实 hooks、rootfs、两组 firmware，再做 FPGA smoke、小输入、真实比较/排空和正式采样。当前不生成会误触发队列的正式 apps/rootfs/firmware 收据。','',
        '## 持续作业与重连','',
        f'软件作业复用现有 job_service：{D}/jobs/network-*/{{state.json,console.log,startup-audit.json}}。正常 FPGA、CAD 和调度服务未改造、未重启。',
        f'Linux 持续状态：{root}/network-linux-validation.json 与 netstreamcluster-linux-validation.json；单核 Netdedup 收尾诊断：{root}/network-linux-probe.json；独立排空候选：{root}/netdedup-linger-preparation.json 与 netdedup-linger-linux-validation.json；Netferret：netferret-protocol-preparation.json 与 netferret-protocol-linux-validation.json。',
        '重连先核对 PID、start_ticks、boot_id；存活作业只接管监控。每个完整 case 的 result.json 为软件验证检查点，确认退出后才补缺项；失败证据留存。统计/诊断快照不是指令级检查点。',
        f'全套 16 项逐轮进度继续由现有服务维护：{D}/COVERAGE_STATUS_LIVE.md 和 coverage-status-live.json；C4 综合状态为 {D}/C4-runtime-cad-state.json。',
        '全套 16 项已登记，13 项有正式软件绑定。网络三项在真正软件/ROI 条件满足后由原 coverage-first 动态读取正式收据，不另起第二套队列。C4 bitstream 通过版本/哈希认证后仍走既有 first 验证链，成功才放行后续正式队列。','']
    dest=root/'NETWORK_PREPARATION.md';tmp=dest.with_suffix('.md.tmp');tmp.write_text('\n'.join(lines));tmp.replace(dest)

if __name__=='__main__':main()
