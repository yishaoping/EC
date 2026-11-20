#!/usr/bin/python3
"""Persistent deterministic continuation and evidence ledger, without FPGA IO.

The existing optimizer remains the only intelligent supervisor. This service
executes only prewritten bounded recovery and already authorized tasks.
"""
from pathlib import Path
import fcntl
import json
import os
import subprocess
import sys
import time

C=Path(__file__).resolve().parent
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U=D/'unattended-opt4'
O=D/'area-sprint-20261112'
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import identity,live,now,read,save,sha
BASE='8491167d84b6d9521b151a743673c1516926a1f8'
ST={}
NAMES=[
 'address-dsp-fullmodule-pair-r1','address-packed-full-module-r1',
 'address-histogram-fame5-r6','address-banked-complete-module-r1',
 'address-banked-production-host-r1','address-banked-production-area-pair-r1',
 'dcache-storage-compose-r3','address-banked-production-contract-sat-r2',
 'sprint-composed-validate-r1','sprint-production-stack-recovery-r1',
 'sprint-production-recovered-area-r1','sprint-composed-recovered-validate-r1']
EXTRA_OWNERS={
 'mshr-split-complete-host-pair-r4': 'Opt4-mshr-split-complete-host-pair-r4-20261112',
 'barrier-banked-host-r4': 'Opt4-barrier-banked-host-r4-20261113',
 'common-stats-bank-r3': 'Opt4-common-stats-bank-r3-20261113',
 'common-stats-host-r1': 'Opt4-common-stats-host-r1-20261113',
}


def safe_read(path):
    try:return read(path)
    except (OSError,ValueError) as exc:return dict(read_error=type(exc).__name__)


def no_owner_members(unit):
    expected='/user.slice/user-1008.slice/user@1008.service/'+unit
    for p in Path('/proc').iterdir():
        if not p.name.isdigit():continue
        try:
            if expected in [l.split(':',2)[-1] for l in (p/'cgroup').read_text().splitlines()]:
                if live(identity(int(p.name))):return False
        except (OSError,ProcessLookupError):pass
    return True


def actions():
    production=D/'build-logs/Opt4-address-banked-production-host-r1-20261112'
    s=safe_read(production/'state.json')
    if s.get('status','').startswith('FAILED') and not live(s) and s.get('active_stage','').startswith('goldengate-'):
        log=production/(s['active_stage']+'.log')
        destination=D/'build-logs/Opt4-sprint-production-stack-recovery-r1-20261112'
        if log.exists() and 'java.lang.StackOverflowError' in log.read_text(errors='replace') and not (destination/'state.json').exists():
            if no_owner_members('ec-opt4-address-banked-production-host-r1-20261112.service'):
                result=subprocess.run(['systemctl','--user','start','ec-opt4-sprint-production-stack-recovery-r1-20261112.service',
                    'ec-opt4-sprint-production-recovered-area-r1-20261112.service',
                    'ec-opt4-sprint-composed-recovered-validate-r1-20261112.service'],capture_output=True,text=True)
                save(O/('stack-recovery-launch-'+str(time.time_ns())+'.json'),dict(utc=now(),returncode=result.returncode,
                    reason='Exact prior production GoldenGate StackOverflow; target verification reused; JVM stack only',
                    source_failure_sha256=sha(production/'failure.json')))
    # If a module result exits, the original service-owned continuation is
    # already running or terminal. This runner never restarts healthy CAD.


def snapshot():
    jobs={};failed=[];resources={}
    owners={name: 'Opt4-'+name+'-20261112' for name in NAMES}
    owners.update(EXTRA_OWNERS)
    extensions=safe_read(O/'additional-owners.json').get('owners',{})
    for name,directory in extensions.items():
        assert isinstance(name,str) and isinstance(directory,str)
        assert directory.startswith('Opt4-') and '/' not in directory and '..' not in directory
        owners[name]=directory
    for name,directory in owners.items():
        out=D/'build-logs'/directory
        state=safe_read(out/'state.json');result=safe_read(out/'result.json')
        if not state:continue
        row={k:state[k] for k in ['status','updated_utc','active_stage','error','hardware_commit','source_variant',
            'functional_baseline','complete_dcache_cycles_verified','candidate_resources','module_lut_saved','lut_saved',
            'resources','host_lut_gap','shell_excluded','full_system_fit',
            'complete_module_lut_saving','same_scope_LUT_saved','source_binding_sha256',
            'target_validation','host_validation','area_gain_unknown'] if k in state}
        row.update(identity_live=live(state),state_path=str(out/'state.json'),
            completed_result=bool(result),result_path=str(out/'result.json') if result else None)
        jobs[name]=row
        if state.get('status','').startswith(('FAILED','REJECTED','INSUFFICIENT','NOT_FIT')):
            failed.append(dict(candidate=name,status=state['status'],error=state.get('error'),
                path=str(out/'failure.json' if (out/'failure.json').exists() else out/'state.json')))
        if result:
            resources[name]={k:result[k] for k in ['area','savings','resources','candidate_resources','reference_resources',
                'module_lut_saved','lut_saved','host_lut_gap','shell_excluded','scope','hardware_commit','source_variant',
                'maps','complete_module_lut_saving','same_scope_LUT_saved','screens',
                'target_validation','host_validation','area_gain_unknown'] if k in result}
            resources[name].update(result=str(out/'result.json'),result_sha256=sha(out/'result.json'))
    host_lut=2420482
    for key in ['sprint-composed-validate-r1','sprint-composed-recovered-validate-r1']:
        r=resources.get(key,{})
        if r.get('shell_excluded') and 'CLB LUTs' in r.get('resources',{}):
            host_lut=r['resources']['CLB LUTs']
    fullshell_lut,fullshell_evidence=2789012,None
    adoptions=safe_read(O/'fullshell-adoptions.json').get('results',[])
    for entry in adoptions:
        try:
            assert entry['scope']=='complete_u280_shell_postopt'
            assert all(sha(entry[k])==entry[k+'_sha256'] for k in ['result','utilization','source_binding'])
            r=read(entry['result'])
            assert r['functional_baseline']==BASE and r['shell_included'] and r['blackboxes']==0
            assert r['hardware_commit']==entry['hardware_commit']
            fullshell_lut=r['resources']['CLB LUTs'];fullshell_evidence=entry
        except (AssertionError,KeyError,OSError,ValueError):
            continue
    report=dict(schema='ec-area-sprint-morning-evidence/1',updated_utc=now(),
        functional_baseline=BASE,experimental_branch='ec-area-sprint-20261112',
        experimental_commit=subprocess.check_output(['git','rev-parse','HEAD'],cwd=W/'Opt4-area-sprint-20261112',text=True).strip(),
        jobs=jobs,completed_resources=resources,failures=failed,
        collector_revision='sprint-continuation-r3-20261113',collector_sha256=sha(C/'controller.py'),
        latest_round_evidence=safe_read(O/'latest-round.json'),
        authoritative_fullshell_lut=fullshell_lut,authoritative_fullshell_capacity=1303680,
        authoritative_fullshell_gap=fullshell_lut-1303680,fullshell_evidence=fullshell_evidence,
        fullshell_source='e0 completed postopt' if fullshell_evidence is None else fullshell_evidence['result'],
        authoritative_latest_host_lut=host_lut,host_shell_excluded=True,host_gap=host_lut-1303680,
        completed_fullshell_LUT_within_capacity=bool(fullshell_evidence and fullshell_lut<=1303680),
        completed_EC_bitstream_evidence=safe_read(O/'physical-adoption.json'),
        optimizer=safe_read(U/'state.json'),board_allowlist=['0000:21:00.0'],board_serial='21770433G02LA',
        no_FPGA_IO=True,no_CPU_session_control=True,no_SVB_control=True,
        limitation='Pending/local/module/host results are never a fullshellFIT or certified fullEC image. No deadline promise.')
    blacklist=safe_read(O/'blacklist.json')
    rejected=blacklist.setdefault('rejected_exact_candidates',{})
    for name,row in resources.items():
        gain=row.get('lut_saved',row.get('module_lut_saved',row.get('complete_module_lut_saving',row.get('same_scope_LUT_saved'))))
        if gain is None and isinstance(row.get('savings'),dict):
            gain=row.get('savings',{}).get('CLB LUTs')
        if isinstance(gain,(int,float)) and gain<=0:
            path=Path(row['result'])
            rejected[name]=dict(module_lut_saved=gain,scope=row.get('scope'),
                result=str(path),result_sha256=sha(path),
                reason='Measured same-scope candidate has no positive LUT saving; no identical retry or integration.')
    small=blacklist.setdefault('insufficient_gain_for_standalone_whole_build',{})
    for name,key in [('address-packed-full-module-r1','complete_module_lut_saving'),('mshr-split-complete-host-pair-r4','same_scope_LUT_saved')]:
        row=resources.get(name,{})
        if 0 < row.get(key,0) < 300000:
            small[name]=dict(lut_saved=row[key],result=row['result'],result_sha256=row['result_sha256'],
                scope=row.get('scope'),hardware_rejected=False,
                reason='Measured small gain does not justify its own expensive whole build; no unchanged screen retry.')
    blacklist.update(updated_utc=now(),build_failures_are_not_functional_or_area_rejections=True)
    save(O/'blacklist.json',blacklist)
    save(O/'latest.json',report)
    lines=[f"EC 面积冲刺实测记录（{report['updated_utc']}）",'',
        f'功能基线：8491167d。完整 shell 最后完成的资源报告：{fullshell_lut:,.0f} LUT，差额 {fullshell_lut-1303680:,.0f}。',
        f'另有完整 generated host：{host_lut:,.0f} LUT，差额 {host_lut-1303680:,.0f}，不含 shell。',
        '模块收益不直接相加为整机收益。FIT、bitstream、上板状态必须由新完整 shell/物理认证证据更新。','',
        '|任务|实际状态|完成结果|','|---|---|---|']
    for name,row in jobs.items():lines.append('|'+name+'|'+row['status']+'|'+('已完成' if row['completed_result'] else '未完成')+'|')
    lines += ['', '实测同范围模块结果：']
    for name,row in resources.items():
        gain=row.get('complete_module_lut_saving',row.get('same_scope_LUT_saved'))
        if gain is not None:lines.append(f'- {name}: {gain:,.0f} LUT saving; isolated module/host scope, not whole EC.')
        for lanes,screen in row.get('screens',{}).items():
            saving=screen.get('savings',{}).get('CLB LUTs')
            if saving is not None:lines.append(f'- {name}, lanes={lanes}, production256: {saving:,.0f} LUT saving; isolated barrier host, not whole EC.')
    round_evidence=report.get('latest_round_evidence',{})
    if round_evidence:
        lines += ['', '本轮记录：'+str(round_evidence.get('receipt','')),str(round_evidence.get('summary','')),
            '下一步：'+str(round_evidence.get('next_action',''))]
    lines+=['','已完成资源数据与失败证据见同目录 latest.json；原始报告和 checkpoint 保留。',
        '既有智能 supervisor 持续重试网络/模型调用；确定性 CAD、验证及已准备好的门槛续跑独立于 SSH。']
    tmp=O/'LATEST.md.tmp';tmp.write_text('\n'.join(lines)+'\n');os.replace(tmp,O/'LATEST.md')
    return report


def main():
    O.mkdir(exist_ok=True)
    lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    prior=safe_read(O/'state.json');assert not live(prior),'Adopt existing support runner'
    ST.update(schema='ec-deterministic-sprint-continuation/1',**identity(),started_utc=now(),
        functional_baseline=BASE,status='RUNNING_WITH_EXISTING_OPTIMIZER_AND_INDEPENDENT_CAD',
        FPGA_IO=False,new_intelligent_supervisor=False,board_allowlist=['0000:21:00.0'],
        implementation_revision='sprint-continuation-r3-20261113',controller_sha256=sha(C/'controller.py'))
    save(O/'inputs.json',dict(files={str(p):sha(p) for p in C.iterdir() if p.is_file()}))
    while True:
        try:
            actions();r=snapshot()
            ST.update(status='RUNNING_WITH_EXISTING_OPTIMIZER_AND_INDEPENDENT_CAD',updated_utc=now(),
                jobs=len(r['jobs']),failed_jobs=len(r['failures']),latest=str(O/'latest.json'))
        except Exception as exc:
            ST.update(status='RECOVERABLE_SUPPORT_ERROR_RETRYING',error=repr(exc),updated_utc=now())
            save(O/('support-error-'+str(time.time_ns())+'.json'),dict(utc=now(),error=repr(exc)))
        save(O/'state.json',ST)
        time.sleep(60)


if __name__=='__main__':main()
