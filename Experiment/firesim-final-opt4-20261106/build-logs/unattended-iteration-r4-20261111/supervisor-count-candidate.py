#!/usr/bin/env python3
"""Persistent single-agent optimization loop and narrowly scoped job broker.

Never signals CAD/sample jobs. Failed candidates remain visible and the next
round receives evidence. Existing services retain ownership of their tasks.
"""
from pathlib import Path
import argparse
import re
import shutil
import subprocess
import time
from opt4_unattended_common import *

STATES=['Opt4-fit-cad-state.json','Opt4-fit-address-sort-state.json',
 'Opt4-fit-address-round3-state.json','Opt4-fit-address-heap-candidate-state.json',
 'Opt4-fit-sort-system-continuation-state.json','Opt4-fit-sort-cad-state.json',
 'Opt4-fit-runtime-state.json','Opt4-fit-sort-runtime-state.json','active-0000_21_00.0.json']
IMPORTANT={'status','updated_utc','current_stage','hardware_commit','source_id','profile',
 'certified_bitstream','bitstream','error','top_postopt_resources','dut_resources',
 'full_module_map','full_address_map','measured_module_resources','resources','matrix',
 'valid_formal_samples','stage','pid','start_ticks','host_boot_id','child_pid','child_start_ticks','log_dir','log'}

def known_tree(pid,depth=0):
    if depth>6:return []
    row=identity(pid)
    if not row:return []
    p=Path('/proc')/str(pid)
    try:
        row['comm']=(p/'comm').read_text().strip()
        row['io']={k:int(v) for line in (p/'io').read_text().splitlines() for k,v in [line.split(':')]}
    except (OSError,ValueError):row['io_unavailable']=True
    rows=[row]
    try:children=(p/'task'/str(pid)/'children').read_text().split()
    except OSError:children=[]
    for child in children[:16]:rows.extend(known_tree(int(child),depth+1))
    return rows[:32]

def snapshot():
    rows={}
    names=set(STATES)
    for spec in (U/'jobs').glob('*/spec.json'):
        for checkpoint in read(spec).get('checkpoints',[]):
            path=Path(checkpoint).resolve()
            if path.parent==D and path.name.endswith('-state.json'):names.add(path.name)
    for n in sorted(names):
        p=D/n;x=read(p)
        if not x:continue
        s={k:v for k,v in x.items() if k in IMPORTANT}
        s['controller']=identity(x['pid']) if x.get('pid') else {}
        s['identity_live']=live(x)
        if x.get('child_pid'):s['child']=identity(x['child_pid'])
        stage=x.get('stages',{}).get(x.get('current_stage') or x.get('active_stage'),{})
        if not stage:
            active=[v for v in x.get('stages',{}).values() if v.get('returncode') is None and v.get('pid')]
            if active:stage=active[-1]
        if stage.get('pid'):s['stage_process']=identity(stage['pid'])
        root=x.get('child_pid') or x.get('child',{}).get('pid') or stage.get('pid') or x.get('pid')
        if root:s['worker_processes']=known_tree(root)
        log=Path(stage.get('log') or x.get('log') or '/nonexistent')
        if log.is_file():
            t=log.stat();s['stage_log']=dict(path=str(log),bytes=t.st_size,mtime_ns=t.st_mtime_ns)
            with log.open('rb') as f:f.seek(max(0,t.st_size-2400));s['log_tail']=f.read().decode(errors='replace')
        rows[n]=s
    mem={l.split(':')[0]:int(l.split()[1]) for l in Path('/proc/meminfo').read_text().splitlines()}
    return dict(schema='ec-opt4-unattended-snapshot/1',utc=now(),host_boot_id=boot(),states=rows,
        available_memory_gib=round(mem['MemAvailable']/2**20,2),free_disk_gib=round(shutil.disk_usage(W).free/2**30,2),
        loadavg=Path('/proc/loadavg').read_text().strip(),board_allowlist=['0000:21:00.0'])

def parallel_slot_admission(count,kind,memory_kib,load1,ordinary_count=None):
    # Preserve eight ordinary synthesis slots. Two extra slots are only for
    # proof/analysis/RTL preparation, with 256GiB free and a low host load.
    # Existing jobs are never stopped when resource conditions change.
    assert count < 10,'DEFER_RESOURCE_LIMIT: ten campaign CPU jobs already running'
    ordinary_count=count if ordinary_count is None else ordinary_count
    assert 0 <= ordinary_count <= count,'invalid synthesis job count'
    if kind in ['module','cad']:
        assert ordinary_count < 8,'DEFER_RESOURCE_LIMIT: ordinary synthesis slots full'
    elif count >= 8:
        assert memory_kib >= 256*2**20,'DEFER_MEMORY_AUXILIARY_MARGIN'
        assert load1 < 96,'DEFER_CPU_AUXILIARY_MARGIN'

def broker_cpu(req):
    name=req['name'];assert re.fullmatch(r'[a-z0-9][a-z0-9-]{0,60}',name)
    assert req['kind'] in ['proof','module','rtl','cad','analysis']
    assert req['argv'][0] in ['/usr/bin/python3','/usr/bin/bash','/bin/bash','/usr/local/bin/yosys','/tools/Xilinx/Vivado/2021.1/bin/vivado']
    assert len(req['argv'])>=2 and all(isinstance(v,str) and '\x00' not in v and '\n' not in v for v in req['argv'])
    assert not any(v in ['-c','--command'] for v in req['argv']),'use bound script file, not arbitrary inline shell'
    cwd=Path(req['cwd']).resolve();assert cwd.is_relative_to(W)
    bound_inputs(req)
    script=Path(req['argv'][1]).resolve()
    if req['argv'][0] in ['/usr/bin/python3','/usr/bin/bash','/bin/bash']:
        assert str(script) in req['inputs'],'entry script must be hash bound'
    out=U/'jobs'/name;out.mkdir(parents=True,exist_ok=True);os.chown(out,UID,GID)
    specpath=out/'spec.json';unit='ec-opt4-auto-'+name+'.service'
    if specpath.exists():assert read(specpath)==req,'immutable job name; create new version'
    state=read(out/'state.json')
    if live(state) or live(state.get('child',{})):return dict(status='ADOPTED_ALREADY_LIVE',unit=unit)
    if state.get('status')=='COMPLETE':
        assert state.get('input_sha256')==bound_inputs(req),'completed input binding changed; new recovery version required'
        assert all(Path(p).is_file() and sha(p)==h for p,h in state.get('outputs',{}).items()),'completed output changed; preserve evidence and create recovery version'
        return dict(status='REUSED_COMPLETED_JOB',unit=unit)
    peers=[read(p) for p in (U/'jobs').glob('*/state.json')]
    livepeers=[r for r in peers if live(r) or live(r.get('child',{}))]
    admission_memory=int(next(l.split()[1] for l in Path('/proc/meminfo').read_text().splitlines() if l.startswith('MemAvailable:')))
    admission_load=float(Path('/proc/loadavg').read_text().split()[0])
    ordinary_count=sum(r.get('kind') in ['module','cad'] for r in livepeers)
    parallel_slot_admission(len(livepeers),req['kind'],admission_memory,admission_load,ordinary_count)
    if req['kind']=='cad':
        for p in [D/'Opt4-fit-cad-state.json',D/'Opt4-fit-sort-cad-state.json']:
            x=read(p)
            # A new DUT may synthesize while the previous, completed DUT is
            # only being linked/optimized. Never overlap two DUT syntheses.
            completed_dut_overlap=(req.get('overlap_completed_dut')==x.get('hardware_commit')
                and x.get('current_stage')=='implementation'
                and x.get('stages',{}).get('dut_synth',{}).get('returncode')==0
                and x.get('stages',{}).get('top_synth',{}).get('returncode')==0)
            assert not live(x) or x.get('status') in ['NOT_FIT_POSTOPT','FAILED_WITH_EVIDENCE'] or completed_dut_overlap,'DEFER_EXISTING_WHOLE_CAD'
        assert not any(r.get('kind')=='cad' for r in livepeers),'DEFER_EXISTING_WHOLE_CAD'
    mem=int(next(l.split()[1] for l in Path('/proc/meminfo').read_text().splitlines() if l.startswith('MemAvailable:')))
    if len(livepeers)>=6:assert mem>=192*2**20,'DEFER_MEMORY_PARALLEL_MARGIN'
    assert mem>=((192 if req.get('overlap_completed_dut') else 96) if req['kind']=='cad' else 48)*2**20,'DEFER_MEMORY'
    assert shutil.disk_usage(W).free >= (150 if req['kind']=='cad' else 40)*2**30,'DEFER_DISK'
    save(specpath,req)
    text=f'''[Unit]
Description=Opt4 autonomous CPU job {name}
After=local-fs.target
RequiresMountsFor={W} {D}
[Service]
Type=simple
User=guozh
Group=guozh
WorkingDirectory={cwd}
ExecStart=/usr/bin/python3 {W}/scripts/opt4_unattended_cpu_job.py {specpath}
Nice=10
TasksMax=1024
CPUQuota=3200%
Restart=no
KillMode=process
StandardOutput=append:{out}/service.log
StandardError=append:{out}/service.log
[Install]
WantedBy=multi-user.target
'''
    up=Path('/etc/systemd/system')/unit
    if up.exists():assert up.read_text()==text,'service definition immutable'
    else:up.write_text(text)
    subprocess.run(['systemctl','daemon-reload'],check=True)
    subprocess.run(['systemctl','enable','--now',unit],check=True,capture_output=True)
    return dict(status='STARTED',unit=unit,spec_sha256=sha(specpath))

def requests():
    for p in sorted((U/'requests').glob('*.json')):
        receipt=U/'request-results'/p.name
        prior=read(receipt)
        if prior and prior.get('status')!='DEFERRED':continue
        r=read(p)
        try:
            assert r['action'] in ['cpu_job','prepare_runtime','start_runtime']
            if r['action']=='cpu_job':result=broker_cpu(r['spec'])
            else:
                # Fixed generator checks exact source binding/template hashes,
                # generated ABI, real CAD receipts, card locks and 21-only tools.
                from prepare_opt4_candidate_runtime import request
                result=request(r)
            save(receipt,dict(result,request_sha256=sha(p),utc=now()))
            event('REQUEST_HANDLED',request=str(p),result=result)
        except Exception as e:
            msg=str(e)
            deferred=any(v in msg for v in ['DEFER_','WAITING_'])
            record=dict(status='DEFERRED' if deferred else 'REJECTED_WITH_EVIDENCE',error=repr(e),utc=now(),request_sha256=sha(p))
            if prior.get('error')!=record['error']:event('REQUEST_REJECTED',request=str(p),**record)
            save(receipt,record)

def actual_experiment():
    # A language-model summary cannot satisfy this success gate. Require exact
    # atomic result/complete binding produced by the real sample collector.
    for p in (D/'runs').glob('opt4-fit-*/result.json'):
        r=read(p);c=read(p.parent/'complete.json');i=r.get('identity',{})
        if (r.get('valid') and r.get('formal') and r.get('fpga_execution') and
            c.get('result_sha256')==sha(p) and c.get('identity_sha256')==r.get('identity_sha256') and
            hashlib.sha256(json.dumps(i,sort_keys=True).encode()).hexdigest()==r.get('identity_sha256') and
            i.get('configuration')=='C4' and i.get('board_bdf')=='0000:21:00.0' and
            i.get('board_serial')=='21770433G02LA' and i.get('hardware_profile','').startswith('Opt4-fit-') and
            i.get('hardware_commit') and i.get('derived_build_receipt_sha256') and
            Path(i.get('derived_build_receipt','/nonexistent')).is_file() and
            sha(i['derived_build_receipt'])==i['derived_build_receipt_sha256']):
            return dict(result=str(p),result_sha256=sha(p),identity=i)
    return None

def main():
    assert os.geteuid()==0
    for n in ['rounds','requests','request-results','jobs','snapshots']:
        p=U/n;p.mkdir(parents=True,exist_ok=True);os.chown(p,UID,GID)
    lock=(U/'supervisor.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    state=U/'state.json';old=read(state)
    if live(old):raise RuntimeError('adopt existing supervisor')
    st=dict(schema='ec-opt4-unattended/1',**identity(),started_utc=now(),status='RUNNING',
      service_unit='ec-opt4-unattended.service',board_bdf='0000:21:00.0',native_paused=True,
      round_dir=old.get('round_dir'),rounds_completed=old.get('rounds_completed',0),
      model_from_existing_configuration=True,no_instruction_checkpoint=True)
    save(state,st);event('SUPERVISOR_STARTED',identity=identity())
    last_snapshot=0;next_round_at=0
    success=None
    while True:
        requests()
        if time.monotonic()-last_snapshot>=300:
            s=snapshot();save(U/'snapshot.json',s)
            event('PROGRESS_SNAPSHOT',states={n:{k:v for k,v in r.items() if k in ['status','stage_log','stage_process','controller','worker_processes']} for n,r in s['states'].items()})
            last_snapshot=time.monotonic()
            success=actual_experiment()
            if success:
                save(U/'first-valid-opt4-sample.json',success)
                st.update(status='SUCCESS_REAL_OPT4_FORMAL_SAMPLE_OPTIMIZATION_QUIESCED',evidence=success,updated_utc=now());save(state,st)
                # Runtime scheduler stays independent and continues the batch.
                if not st.get('round_dir') or not live(read(Path(st['round_dir'])/'worker.json')):return
        r=Path(st['round_dir']) if st.get('round_dir') else None
        worker=read(r/'worker.json') if r else {}
        if r and (live(worker) or live(worker.get('child',{}))):
            st.update(active_worker=worker,status='SUCCESS_WAITING_OPTIMIZATION_ROUND_EXIT' if success else 'OPTIMIZATION_WORKER_ACTIVE',updated_utc=now());save(state,st)
            time.sleep(15);continue
        if success:
            st.update(status='SUCCESS_REAL_OPT4_FORMAL_SAMPLE_OPTIMIZATION_QUIESCED',evidence=success,ended_utc=now());save(state,st);return
        if r and not (r/'accounted.json').exists():
            try:result=read(r/'final.json')
            except (ValueError,TypeError):result={'outcome':'INVALID_WORKER_SUMMARY_EVIDENCE_RETAINED'}
            save(r/'accounted.json',dict(utc=now(),worker=worker,result=result,verified_hardware_success=False))
            st['rounds_completed']+=1
            event('ROUND_ACCOUNTED',round_dir=str(r),returncode=worker.get('returncode'),outcome=result.get('outcome'))
            # Tool/network failures use bounded backoff, never mark FIT/pass.
            next_round_at=time.monotonic()+(300 if worker.get('returncode')!=0 else int(result.get('retry_after_seconds',30)))
            next_round_at=min(next_round_at,time.monotonic()+600)
            st['round_dir']=None;save(state,st)
        if time.monotonic()<next_round_at:time.sleep(15);continue
        count=len(list((U/'rounds').glob('round-*')))+1
        r=U/'rounds'/('round-%05d'%count);r.mkdir();os.chown(r,UID,GID)
        prompt=(U/'WORKER_PROMPT.md').read_text()+'\n\nThis is round '+str(count)+'. Latest durable snapshot:\n'+json.dumps(read(U/'snapshot.json'),indent=2)+'\n\nPrevious round directories: '+str(U/'rounds')+'\n'
        (r/'prompt.md').write_text(prompt);os.chown(r/'prompt.md',UID,GID)
        with (r/'launcher.log').open('ab',buffering=0) as log:
            p=subprocess.Popen(['/usr/sbin/runuser','-u','guozh','--','/usr/bin/python3',str(W/'scripts/opt4_unattended_worker.py'),str(r)],
                stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,start_new_session=True)
        # Startup barrier prevents duplicate launch during the wrapper's setup.
        st.update(round_dir=str(r),launcher=identity(p.pid),status='STARTING_OPTIMIZATION_WORKER',updated_utc=now());save(state,st)
        for _ in range(15):
            if (r/'worker.json').exists() or p.poll() is not None:break
            time.sleep(1)
        event('ROUND_STARTED',round_dir=str(r),launcher=identity(p.pid))
        time.sleep(15)

if __name__=='__main__':main()
