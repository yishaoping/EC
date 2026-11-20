#!/usr/bin/env python3
"""Read-only evidence audit, followed by atomic publication of the 16x2 matrix."""
import datetime as dt
import json
import os
from pathlib import Path
import shutil

import coverage_first as c
from board_batch import W,D,save
from job_service import inspect,proc


def same(row, ident):
    drivers=row.get('accepted_driver_bindings',[])+[{k:row['bound'][k] for k in ['driver_sha256','driver_receipt_sha256']}]
    return (all(ident.get(k)==v for k,v in row['bound'].items() if k not in ['driver_sha256','driver_receipt_sha256'])
            and any(all(ident.get(k)==v for k,v in d.items()) for d in drivers))


def build():
    rows,valid=c.catalog(),c.results()
    active=c.read(D/'active-0000_e2_00.0.json',{})
    active_live=c.live(active)
    active_ident=c.read(Path(active['run_dir'])/'manifest.json',{}).get('identity',{}) if active.get('run_dir') else {}
    coordinator=c.read(D/'coverage-first-state.json',{})
    inventory=c.read(D/'parsec-suite-inventory.json')
    plan=c.read(D/'suite-execution-plan.json')
    byname={t['program']:t for t in plan['programs']}
    programs=[]
    for base in inventory['programs']:
        name=base['program'];entry=dict(program=name,profile=byname[name]['software_profile_prefix'],
            formal_input='simmedium',threads=1,warmups=0,configurations={})
        for cfg in ['Native','C4']:
            row=next(r for r in rows if r['program']==name and r['configuration']==cfg)
            detail=dict(software_status=row['status'],receipts=row['receipts'],slots={},formal_completed=[],
                future_owner=byname[name].get('future_owner'),missing=row.get('missing',[]))
            if row['status']=='READY':
                detail['bound']=row['bound'];detail['accepted_driver_bindings']=row.get('accepted_driver_bindings',[])
                apps=c.read(Path(row['receipts']['apps']))
                detail['formal_case']=next((x for x in apps['cases'] if x['program']==name and x['input']=='simmedium'),None)
                for size,rep,label in [('test',1,'test'),('simsmall',1,'simsmall')]+[('simmedium',n,'r'+str(n)) for n in [1,2,3]]:
                    passes=c.matches(row,valid,size,rep)
                    key=row['signature']+':'+size+':'+str(rep)
                    if passes:
                        slot=dict(status='PASSED',results=[str(p) for p,_ in passes])
                        if size=='simmedium':detail['formal_completed'].append(rep)
                    elif size not in row['inputs']:
                        slot=dict(status='NOT_DEFINED',reason='No compute test case in the bound profile; simsmall is the functional gate')
                    elif active_live and same(row,active_ident) and active_ident.get('input')==size and active_ident.get('repetition')==rep:
                        slot=dict(status='RUNNING',run_dir=active['run_dir'],pid=active.get('pid'),start_ticks=active.get('start_ticks'))
                    elif key in coordinator.get('failures',{}):
                        slot=dict(status='FAILED_WITH_EVIDENCE',failure=coordinator['failures'][key])
                    else:slot=dict(status='PENDING')
                    detail['slots'][label]=slot
                legacy=c.read(D/f'suite-{cfg.lower()}-queue-state.json',{}).get('tasks',{}).get(name,{})
                if legacy.get('status')=='FAILED':detail['historical_failed_profile']=legacy
                if len(detail['formal_completed'])==3:detail['status']='COMPLETE'
                elif any(s['status']=='RUNNING' for s in detail['slots'].values()):detail['status']='RUNNING'
                elif any(s['status']=='FAILED_WITH_EVIDENCE' for s in detail['slots'].values()):detail['status']='FAILED_STAGE_OTHER_PROGRAMS_CONTINUE'
                else:detail['status']='PENDING'
                detail['boundary']=coordinator.get('boundaries',{}).get(cfg,{})
            else:
                detail['status']=row['status']
                detail['slots']={s:dict(status=row['status']) for s in ['test','simsmall','r1','r2','r3']}
            entry['configurations'][cfg]=detail
        programs.append(entry)
    coverage=dict(total=len(programs),Native=sum(len(r['configurations']['Native']['formal_completed'])==3 for r in programs),
        C4=sum(len(r['configurations']['C4']['formal_completed'])==3 for r in programs),
        paired=sum(all(len(r['configurations'][cfg]['formal_completed'])==3 for cfg in ['Native','C4']) for r in programs),
        Native_first=sum(bool(r['configurations']['Native']['formal_completed']) for r in programs),
        C4_first=sum(bool(r['configurations']['C4']['formal_completed']) for r in programs))
    state_names=['active-0000_e2_00.0.json','suite-native-queue-state.json','suite-c4-queue-state.json',
        'C4-runtime-cad-state.json','fpga-continuation-state.json','idle-repairs-state.json',
        'fluidanimate-stable-native-state.json','coverage-first-state.json']
    mem=dict(x.split(':',1) for x in Path('/proc/meminfo').read_text().splitlines())
    devices=[]
    for p in Path('/sys/bus/pci/devices').iterdir():
        if (p/'vendor').read_text().strip()=='0x10ee':devices.append(dict(bdf=p.name,device=(p/'device').read_text().strip()))
    resources=dict(cpu_logical=os.cpu_count(),affinity_count=len(os.sched_getaffinity(0)),load_average=os.getloadavg(),
        mem_total=mem['MemTotal'].strip(),mem_available=mem['MemAvailable'].strip(),xilinx_pcie=devices,
        data1_free_gib=shutil.disk_usage(D).free/2**30,cad_fs_free_gib=shutil.disk_usage('/var/tmp').free/2**30)
    report=dict(schema='ec-coverage-slot-status/1',updated_utc=dt.datetime.now(dt.timezone.utc).isoformat(),
        boot_id=c.BOOT,coverage=coverage,programs=programs,actual_fpga_benchmarks_running=int(active_live and active_ident.get('program') not in [None,'smoke']),
        active_identity=active_ident if active_live else None,known_process_audits={n:inspect(D/n) for n in state_names},
        cad_progress=c.read(D/'cad-runtime-progress-latest.json',{}),resources=resources,
        plan=str(D/'suite-execution-plan.json'),all_programs_automatically_enrolled=len(byname)==16,
        runnable_software_programs=sum(r['configuration']=='Native' and r['status']=='READY' for r in rows),
        scheduling='Future owner runs first pass before topups; preexisting active batches/repair controllers preserved. Three network entries remain blocked, never silently omitted.')
    save(D/'coverage-status-live.json',report)
    lines=['# PARSEC 逐轮真实状态','',report['updated_utc'], '',
        f"全套 {coverage['total']}；Native 三轮完成 {coverage['Native']}；C4 三轮完成 {coverage['C4']}；配对 {coverage['paired']}。Native 至少一轮 {coverage['Native_first']}；C4 至少一轮 {coverage['C4_first']}。",'',
        'P=有效原子提交；R=真实活进程；Q=待执行；B=依赖阻塞；F=失败；—=该profile无此test。test与simsmall不计正式轮次。','',
        '| 程序 | Native test/small/r1/r2/r3 | Native状态 | C4 test/small/r1/r2/r3 | C4状态 |',
        '| --- | --- | --- | --- | --- |']
    symbols={'PASSED':'P','RUNNING':'R','PENDING':'Q','NOT_DEFINED':'—','FAILED_WITH_EVIDENCE':'F'}
    for entry in programs:
        cells=[]
        for cfg in ['Native','C4']:
            detail=entry['configurations'][cfg]
            cells+=[' / '.join(symbols.get(detail['slots'][s]['status'],'B') for s in ['test','simsmall','r1','r2','r3']),detail['status']]
        lines.append('| '+entry['program']+' | '+' | '.join(cells)+' |')
    lines+=['',f"完整ELF、输入、命令、ROI、正确性、版本及完成证据：[coverage-status-live.json]({D/'coverage-status-live.json'})。",
            f"当前单实例调度器：[coverage-first-state.json]({D/'coverage-first-state.json'})。"]
    p=D/'COVERAGE_STATUS_LIVE.md';tmp=p.with_suffix('.tmp');tmp.write_text('\n'.join(lines)+'\n');tmp.replace(p)
    return report


if __name__=='__main__':
    report=build();print(json.dumps(dict(coverage=report['coverage'],actual_running=report['actual_fpga_benchmarks_running'],resources=report['resources'])))
