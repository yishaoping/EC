#!/usr/bin/env python3
"""Fresh immutable run directories, sealed models, existing compact capture."""
import argparse,datetime,hashlib,json,os,platform,re,shlex,shutil,subprocess,sys,time,uuid
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];OUT=ROOT/'slowdown/parsec_evaluation_20261103'
sys.path.insert(0,str(ROOT/'slowdown/optimization_4_svb/scripts'))
import compact_capture
FINAL='1532923803d7451b0c7843e9abad1c90ef9eb9ed'
FIXBUILD='overlap_blackscholes_capture_flush_fix_20261103_064936_fd6cd4a6'
class Router(compact_capture.Router):
    def line(self,line,stream):
        if line.startswith(b'SVB_CAPTURE_DISCARD '):
            self.counts['cancelled_snapshots_drained']+=1;self.write('stderr.log',line);return
        super().line(line,stream)
compact_capture.Router=Router
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def dump(p,x):p.write_text(json.dumps(x,indent=2)+'\n')
def main():
    p=argparse.ArgumentParser();p.add_argument('workload');p.add_argument('design',choices=['native','check','correction']);p.add_argument('--max-cycles',type=int,default=20000000);a=p.parse_args()
    status=subprocess.check_output(['git','status','--porcelain=v1'],cwd=ROOT,text=True)
    assert not status,'Evaluation must start from a clean worktree: '+status
    soft=OUT/'build'/a.workload;sm=json.loads((soft/'build.manifest.json').read_text());mode='native'if a.design=='native'else'protected'
    for ext,key in [('riscv','elf_sha256'),('loadmem_hex','loadmem_sha256')]:assert sha(soft/(mode+'.'+ext))==sm['artifacts'][mode][key]
    if a.design=='check':
        d=ROOT/'slowdown/blackscholes_validation/build/matched_check_v5048';bm=json.loads((d/'build.manifest.json').read_text());assert bm['state']=='BUILT'
        for path,h in bm['input_sha256'].items():assert sha(Path(path))==h,path
        sim=Path(bm['simulator']);assert sha(sim)==bm['simulator_sha256'];evidence={'manifest':str(d/'build.manifest.json'),'sha256':sha(d/'build.manifest.json'),'base_commit':bm['base_commit'],'config_patch_sha256':bm['configuration_patch_sha256']}
    else:
        d=ROOT/'slowdown/optimization_6_overlap';bm=json.loads((d/'runs'/FIXBUILD/'run_manifest.json').read_text())
        seal=json.loads((ROOT/'slowdown/blackscholes_validation/evidence/capture_fix_build.manifest.json').read_text())
        for group in ['hardware_sha256','restored_resource_sha256']:
            for rel,h in seal['source'][group].items():assert sha(ROOT/rel)==h,rel
        sim=d/'build'/FIXBUILD/'verilator/simulator-chipyard-v1Config';assert sha(sim)=='acf962dc248d7060c5e2418949006e887c0fddb30a042dbfd0b190303e03dbc8'
        evidence={'manifest':str(ROOT/'slowdown/blackscholes_validation/evidence/capture_fix_build.manifest.json'),'sha256':sha(ROOT/'slowdown/blackscholes_validation/evidence/capture_fix_build.manifest.json'),'source':seal['source']}
    rid=a.workload+'_'+a.design+'_'+datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%d_%H%M%S_')+uuid.uuid4().hex[:8]
    run=OUT/'runs'/rid;run.mkdir(parents=True,exist_ok=False)
    for ext in ['riscv','loadmem_hex']:shutil.copy2(soft/(mode+'.'+ext),run/('test.'+ext))
    argv=[str(sim),'-s','1','+cycle-count','+permissive']
    if a.design!='check':argv+=['+safe-chain-events','+safe-chain-budgeted','+cache-opportunity']
    argv+=['+dramsim','+dramsim_ini_dir='+str(ROOT/'chipyard/generators/testchipip/src/main/resources/dramsim2_ini'),'+max-cycles='+str(a.max_cycles),'+loadmem='+str(run/'test.loadmem_hex'),'+loadmem_addr=80000000','+permissive-off',str(run/'test.riscv')]
    m={'run_id':rid,'design':a.design,'software':sm,'elf_sha256':sha(run/'test.riscv'),'simulator_sha256':sha(sim),'canonical_hardware_commit':FINAL if a.design!='check' else None,'build_evidence':evidence,'command':argv,'host':platform.uname()._asdict(),'seed':1,'start_utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),'state':'STARTED','evaluation_git_head':subprocess.check_output(['git','rev-parse','HEAD'],cwd=ROOT,text=True).strip(),'evaluation_git_status':status}
    dump(run/'run_manifest.json',m);(run/'command.sh').write_text('cd '+shlex.quote(str(run))+'\n'+shlex.join(argv)+'\n');print('RUN_DIRECTORY='+str(run),flush=True)
    os.chdir(run);t=time.monotonic();rc,stats=compact_capture.capture(argv,run)
    m.update(state='COMPLETED',exit_status=rc,host_wall_seconds=time.monotonic()-t,end_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),capture=stats)
    logs='\n'.join((run/n).read_text(errors='replace')for n in ['stdout.log','stderr.log'])
    app=re.findall(r'\[APP\] protected=(\d+) start=(\d+) end=(\d+) cycles=(\d+) instret=(\d+) session_stop=(\d+)',logs)
    if len(app)==1:
        modeflag,start,end,cycles,inst,stop=map(int,app[0]);assert end-start==cycles
        m.update(roi_cycles=cycles,roi_instret=inst,roi_start=start,roi_end=end,software_session_stop=stop,ipc=inst/cycles)
        dump(run/'roi.json',dict(start_cycle=start,stop_cycle=end,safe_chain_roi_cycles=cycles,scope=sm['roi_scope']))
    m['output']=re.findall(r'\[OUTPUT\] (.*)',logs)
    total=re.findall(r'\*\*\* PASSED \*\*\* Completed after (\d+) cycles',logs)
    if len(total)==1:m['total_harness_cycles']=int(total[0])
    m['software_correct']=rc==0 and len(app)==1 and len(total)==1 and len(m['output'])==1 and 'verified=1' in m['output'][0] and '[COMPUTATION] status=PASS' in logs and '[END] hart=0 status=PASS' in logs and not re.search(r'\bAssertion\b|%Error|\*\*\* FAILED|status=FAIL',logs,re.I)
    m['validation']='SOFTWARE_PASS_PROTOCOL_PENDING'if m['software_correct']else'FAILED'
    dump(run/'run_manifest.json',m);print(json.dumps({k:m.get(k)for k in ['run_id','exit_status','roi_cycles','roi_instret','output','total_harness_cycles','host_wall_seconds','validation']},indent=2),flush=True)
    return int(not m['software_correct'])
if __name__=='__main__':raise SystemExit(main())
