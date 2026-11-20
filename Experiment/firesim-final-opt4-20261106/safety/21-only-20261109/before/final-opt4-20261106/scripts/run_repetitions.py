#!/usr/bin/env python3
"""Run/resume paired-software repetitions, using actual sample completion receipts."""
import argparse,datetime as dt,fcntl,json,os,subprocess
from pathlib import Path
from board_batch import W,D,BDFS,save,sha


def main():
    p=argparse.ArgumentParser();p.add_argument('configuration',choices=['Native','C4']);p.add_argument('--bdf',choices=BDFS,required=True)
    p.add_argument('--program',default='blackscholes')
    p.add_argument('--input',default='simmedium');p.add_argument('--repetitions',type=int,default=3);p.add_argument('--timeout',type=int,default=3600)
    p.add_argument('--driver-receipt',type=Path)
    p.add_argument('--firmware-receipt',type=Path)
    p.add_argument('--apps-receipt',type=Path)
    p.add_argument('--rootfs-receipt',type=Path)
    a=p.parse_args();assert os.geteuid()==0
    cfg=a.configuration;fw=a.firmware_receipt or W/'software'/cfg/'formal-firmware-build.json';apps=a.apps_receipt or W/'software/formal-apps-build.json';rootfs=a.rootfs_receipt or W/'software/formal-rootfs-build.json'
    driver_path=a.driver_receipt or W/'runtime'/(cfg+'-observed-driver.json')
    driver=json.loads(driver_path.read_text());exe=Path(driver['output_dir'])/'FireSim-xilinx_alveo_u280'
    bound=dict(configuration=cfg,board_bdf=a.bdf,program=a.program,input=a.input,firmware_receipt_sha256=sha(fw),apps_manifest_sha256=sha(apps),rootfs_sha256=json.loads(rootfs.read_text())['sha256'],driver_receipt_sha256=sha(driver_path),driver_sha256=sha(exe),hardware_source_id=driver['hardware_source_id'])
    firmware=json.loads(fw.read_text());dt_receipt=next(Path(f) for f in firmware['input_files'] if f.endswith('.json') and 'fdt' in Path(f).name)
    fdt=json.loads(dt_receipt.read_text());bound['linux_bootargs']=fdt['bootargs'];bound['linux_memory_cap_bytes']=fdt['linux_mem_cap']
    maintenance=(D/'locks/dual-maintenance.lock').open('a');fcntl.flock(maintenance,fcntl.LOCK_SH|fcntl.LOCK_NB)
    lock=(D/'locks'/('repetitions-'+a.bdf.replace(':','_')+'.lock')).open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)

    def results():
        for f in sorted((D/'runs').glob('*/result.json')):
            r=json.loads(f.read_text());c=f.parent/'complete.json'
            if not r.get('valid') or not c.exists():continue
            done=json.loads(c.read_text())
            assert done['result_sha256']==sha(f) and done['identity_sha256']==r['identity_sha256'],str(f)
            yield f,r

    functional=[r for f,r in results() if r['identity']['configuration']==cfg and r['identity']['hardware_source_id']==bound['hardware_source_id'] and r['identity'].get('linux_bootargs')==bound['linux_bootargs'] and r['identity'].get('linux_memory_cap_bytes')==bound['linux_memory_cap_bytes'] and not r.get('formal')]
    assert any(r['identity']['program']=='smoke' for r in functional), 'requires a valid hardware smoke'
    assert any(r['identity']['program']==a.program and r['identity']['input']=='simsmall' and all(r['identity'].get(k)==bound[k] for k in ['firmware_receipt_sha256','apps_manifest_sha256','rootfs_sha256','driver_receipt_sha256','driver_sha256']) for r in functional), 'requires matching software/driver simsmall validation before formal sampling'
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ');out=D/'sampling-batches'/(cfg+'-'+a.program+'-'+stamp);out.mkdir(parents=True)
    tasks=[dict(repetition=n,status='PENDING') for n in range(1,a.repetitions+1)]
    state=dict(schema='ec-fpga-repetitions/1',bound=bound,pid=os.getpid(),host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),started_utc=dt.datetime.now(dt.timezone.utc).isoformat(),tasks=tasks,status='RUNNING',no_deployment_or_global_operations=True)
    save(out/'state.json',state);print(out,flush=True)
    for task in tasks:
        matches=[(f,r) for f,r in results() if r.get('formal') and all(r['identity'].get(k)==v for k,v in bound.items()) and r['identity']['repetition']==task['repetition']]
        if matches:
            task.update(status='COMPLETE',result=str(matches[-1][0]),resumed=True);save(out/'state.json',state);continue
        task.update(status='RUNNING');save(out/'state.json',state)
        before=set((D/'runs').glob('*/manifest.json'))
        argv=['python3',str(W/'scripts/run_isolated_sample.py'),cfg,a.program,a.input,'--bdf',a.bdf,'--repetition',str(task['repetition']),'--timeout',str(a.timeout),'--formal','--firmware-receipt',str(fw),'--apps-receipt',str(apps),'--rootfs-receipt',str(rootfs)]
        if a.driver_receipt:argv+=['--driver-receipt',str(a.driver_receipt)]
        with (out/('r'+str(task['repetition'])+'-launch.log')).open('wb',buffering=0) as log:
            rc=subprocess.run(argv,stdout=log,stderr=subprocess.STDOUT).returncode
        created=set((D/'runs').glob('*/manifest.json'))-before
        own=[f.parent for f in created if all(json.loads(f.read_text())['identity'].get(k)==v for k,v in bound.items())]
        task.update(status='COMPLETE' if rc==0 else 'FAILED',returncode=rc,run_directories=[str(f) for f in sorted(own)])
        save(out/'state.json',state);print(json.dumps(task),flush=True)
        # A failed repeat remains evidence and does not discard earlier results.
    state.update(status='COMPLETE' if all(t['status']=='COMPLETE' for t in tasks) else 'COMPLETE_WITH_FAILURES',ended_utc=dt.datetime.now(dt.timezone.utc).isoformat());save(out/'state.json',state)
    return 0 if state['status']=='COMPLETE' else 2


if __name__=='__main__':raise SystemExit(main())
