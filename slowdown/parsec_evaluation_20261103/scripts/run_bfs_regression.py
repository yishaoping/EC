#!/usr/bin/env python3
"""Run the pinned BFS acceptance regression on an explicitly sealed revision."""
import argparse,datetime,hashlib,json,os,re,shlex,shutil,subprocess,time,uuid
from pathlib import Path
from run_pilot import ROOT,OUT,hardware,sha,dump,compact_capture
from analyze_pilot import stable

def main():
    p=argparse.ArgumentParser();p.add_argument('--hardware-revision',type=Path,default=OUT/'hardware_revision.json');a=p.parse_args()
    status=subprocess.check_output(['git','status','--porcelain=v1'],cwd=ROOT,text=True)
    assert not status,'Regression must launch from a clean worktree'
    sim,evidence,commit=hardware(a.hardware_revision,True)
    pinned=json.loads((ROOT/'slowdown/opt4/frozen_manifest.json').read_text())['software']
    soft=Path('/data1/gzh/EC/check/software_common_builds/gapbs512_20261023_03')
    for name,key in [('test.riscv','elf_sha256'),('test.loadmem_hex','loadmem_sha256')]:assert sha(soft/name)==pinned[key]
    run=OUT/'build'/('bfs_regression_'+datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%d_%H%M%S_')+uuid.uuid4().hex[:8]);run.mkdir()
    for name in ['test.riscv','test.loadmem_hex']:shutil.copy2(soft/name,run/name)
    argv=[str(sim),'-s','1','+cycle-count','+permissive','+safe-chain-events','+safe-chain-budgeted','+cache-opportunity','+dramsim','+dramsim_ini_dir='+str(ROOT/'chipyard/generators/testchipip/src/main/resources/dramsim2_ini'),'+max-cycles=3000000','+loadmem='+str(run/'test.loadmem_hex'),'+loadmem_addr=80000000','+permissive-off',str(run/'test.riscv')]
    m={'run_id':run.name,'simulation':'STARTED','source':evidence['source'],'build_evidence':evidence,'canonical_hardware_commit':commit,'elf_sha256':sha(run/'test.riscv'),'command':argv,'start_utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),'evaluation_git_head':subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),'evaluation_git_status':status,'scope':'BFS correctness acceptance regression; outside PARSEC means'}
    dump(run/'run_manifest.json',m);(run/'command.sh').write_text('cd '+shlex.quote(str(run))+'\n'+shlex.join(argv)+'\n');print('RUN_DIRECTORY='+str(run),flush=True)
    os.chdir(run);t=time.monotonic();rc,stats=compact_capture.capture(argv,run)
    m.update(simulation='COMPLETED',exit_status=rc,capture=stats,host_wall_seconds=time.monotonic()-t,end_utc=datetime.datetime.now(datetime.timezone.utc).isoformat());dump(run/'run_manifest.json',m)
    logs=(run/'stdout.log').read_text();roi=re.findall(r'\[ROI\] hart=0 start=(\d+) stop=(\d+) cycles=(\d+)',logs)
    if len(roi)==1:
        start,stop,cycles=map(int,roi[0]);assert stop-start==cycles
        dump(run/'roi.json',dict(start_cycle=start,stop_cycle=stop,safe_chain_roi_cycles=cycles))
    s=stable.run_summary(run);dump(run/'summary.json',s)
    result={'status':'PASS' if s['performance_valid'] and rc==0 else 'FAIL','ROI_cycles':s['opt4_roi_cycles'],'previous_revision_ROI':1128052,'delta_cycles':s['opt4_roi_cycles']-1128052 if s['opt4_roi_cycles'] else None,'correctness':s['correctness'],'protocol':s['protocol']['status'],'integrity':s['integrity']['status'],'capture':s['capture_evidence']['status'],'data_ordering':s['data_ordering']['status'],'benchmark_result':s['benchmark_result'],'run_id':run.name,'canonical_hardware_commit':commit}
    dump(run/'result.json',result);print(json.dumps(result,indent=2));return result['status']!='PASS'
if __name__=='__main__':raise SystemExit(main())
