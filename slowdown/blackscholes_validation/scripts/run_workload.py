#!/usr/bin/env python3
"""Run the existing sealed simulators using the project's compact capture.
Only private fresh run directories are written; no build or hardware mutation.
"""
import argparse, datetime, hashlib, importlib.util, json, os, platform, re, shlex, shutil, sys, time, uuid
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];OUT=ROOT/'slowdown/blackscholes_validation'
CHECK=Path('/data1/gzh/EC/check');RID='overlap_retained_copy_20261103_040650_0a6ef6bc'
FINAL=ROOT/'slowdown/optimization_6_overlap';SOFT=OUT/'build/parsec_test4'
sys.path.insert(0,str(ROOT/'slowdown/optimization_4_svb/scripts'))
import compact_capture
from compact_capture import capture
class WorkloadRouter(compact_capture.Router):
    def line(self,line,stream):
        if line.startswith(b"SVB_CAPTURE_DISCARD "):
            self.counts["cancelled_snapshots_drained"] += 1
            self.write("stderr.log",line)
            return
        super().line(line,stream)
compact_capture.Router=WorkloadRouter

def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def dump(p,x):p.write_text(json.dumps(x,indent=2)+'\n')
def main():
    p=argparse.ArgumentParser();p.add_argument('design',choices=['check','check_matched','check_matched_v5048','correction']);p.add_argument('--smoke',action='store_true');p.add_argument('--smoke-cycles',type=int,default=10000);p.add_argument('--max-cycles',type=int,default=10000000);p.add_argument('--correction-build',default=RID);args=p.parse_args()
    sm=json.loads((SOFT/'build.manifest.json').read_text())
    assert sha(SOFT/'test.riscv')==sm['elf_sha256'] and sha(SOFT/'test.loadmem_hex')==sm['loadmem_sha256']
    if args.design=='check':
        spec=importlib.util.spec_from_file_location('existing_check',CHECK/'launch_baseline.py');old=importlib.util.module_from_spec(spec);spec.loader.exec_module(old)
        directory,bm,sim=old.verified_build(CHECK/'build/b3_20261023_141155_3qge7ayp')
        source={'git_head':bm['source']['commit'],'config':bm['config'],'checker_harts':[1,2,3,4]}
        binary_hash=bm['simulator_sha256'];evidence={'build_manifest':str(directory/'manifest.json'),'sha256':sha(directory/'manifest.json')}
    elif args.design=='check_matched':
        directory=OUT/'build/matched_check';bm=json.loads((directory/'build.manifest.json').read_text());assert bm['state']=='BUILT'
        for rel,h in bm['source_configuration_sha256'].items():assert sha(directory/'source/chipyard'/rel)==h
        assert json.loads((directory/'configuration_check.json').read_text())['status']=='PASS'
        source={'git_head':bm['base_commit'],'configuration_only_patch_sha256':bm['configuration_patch_sha256'],'config':'v1Config','checker_harts':[1,2,3,4]}
        sim=Path(bm['simulator']);binary_hash=bm['simulator_sha256'];assert sha(sim)==binary_hash
        evidence={'build_manifest':str(directory/'build.manifest.json'),'sha256':sha(directory/'build.manifest.json')}
    elif args.design=='check_matched_v5048':
        directory=OUT/'build/matched_check_v5048';bm=json.loads((directory/'build.manifest.json').read_text());assert bm['state']=='BUILT'
        parent=Path(bm['parent_build']);assert sha(parent/'build.manifest.json')==bm['parent_manifest_sha256']
        assert json.loads((parent/'configuration_check.json').read_text())['status']=='PASS'
        for path,h in bm['input_sha256'].items():assert sha(Path(path))==h,path
        source={'git_head':bm['base_commit'],'configuration_only_patch_sha256':bm['configuration_patch_sha256'],'config':'v1Config','checker_harts':[1,2,3,4]}
        sim=Path(bm['simulator']);binary_hash=bm['simulator_sha256'];assert sha(sim)==binary_hash
        evidence={'build_manifest':str(directory/'build.manifest.json'),'sha256':sha(directory/'build.manifest.json'),'verilator_version':bm['verilator_version'],'compiler_version':bm['compiler_version']}
    else:
        build_id=args.correction_build
        if build_id==RID:
            seal=json.loads((FINAL/'runs'/build_id/'binary_seal.json').read_text())
        else:
            bm=json.loads((FINAL/'runs'/build_id/'run_manifest.json').read_text());assert bm['hardware_generation']=='PASS' and bm['verilator_build']=='PASS'
            seal={'source':bm['source'],'binary_sha256':sha(FINAL/'build'/build_id/'verilator/simulator-chipyard-v1Config')}
        source=dict(seal['source'],frozen_hardware_commit='5343ea33f7ccc1b4d140eef09e2d07ab775ae72c')
        for rel,h in source['hardware_sha256'].items():assert sha(ROOT/rel)==h,rel
        for rel,h in source['restored_resource_sha256'].items():assert sha(ROOT/rel)==h,rel
        sim=FINAL/'build'/build_id/'verilator/simulator-chipyard-v1Config';binary_hash=seal['binary_sha256']
        assert sha(sim)==binary_hash;evidence={'build_id':build_id,'sealed_source':seal['source'],'binary_sha256':binary_hash}
    name=args.design+('_smoke_' if args.smoke else '_test4_')+datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%d_%H%M%S_')+uuid.uuid4().hex[:8]
    run=OUT/'runs'/name;run.mkdir(parents=True,exist_ok=False)
    for f in ['test.riscv','test.loadmem_hex','build.manifest.json']:shutil.copy2(SOFT/f,run/f)
    maximum=args.smoke_cycles if args.smoke else args.max_cycles
    argv=[str(sim),'-s','1','+cycle-count','+permissive']
    if args.design=='correction':argv+=['+safe-chain-events','+safe-chain-budgeted','+cache-opportunity']
    argv+=['+dramsim','+dramsim_ini_dir='+str(ROOT/'chipyard/generators/testchipip/src/main/resources/dramsim2_ini'),'+max-cycles='+str(maximum),'+loadmem='+str(run/'test.loadmem_hex'),'+loadmem_addr=80000000','+permissive-off',str(run/'test.riscv')]
    record={'schema':1,'design':args.design,'run_id':name,'simulation':'STARTED','source':source,'build_evidence':evidence,'simulator':str(sim),'simulator_sha256':binary_hash,'software':sm,'command':argv,'host':platform.uname()._asdict(),'trace_enabled':False,'seed':1,'smoke':args.smoke,'start_utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),'metric':'target rdcycle ROI; host time is simulation cost','environment':{'PATH':'/usr/bin:/bin'},'validation':'PENDING'}
    dump(run/'run_manifest.json',record);dump(run/'SIMULATION_STARTED.json',{'source':source,'argv':argv,'binary_sha256':binary_hash});dump(run/'binary_seal.json',{'source':source,'binary_sha256':binary_hash,'binary_bytes':sim.stat().st_size});(run/'command.sh').write_text('cd '+shlex.quote(str(run))+'\n'+shlex.join(argv)+'\n')
    print('RUN_DIRECTORY='+str(run),flush=True);os.chdir(run)
    started=time.monotonic();rc,stats=capture(argv,run);wall=time.monotonic()-started
    record.update(simulation='COMPLETED',exit_status=rc,host_wall_seconds=wall,capture=stats,end_utc=datetime.datetime.now(datetime.timezone.utc).isoformat())
    logs='\n'.join((run/n).read_text(errors='replace')for n in ['stdout.log','stderr.log'])
    roi=re.findall(r'\[ROI\] hart=0 start=(\d+) stop=(\d+) cycles=(\d+)',logs)
    if len(roi)==1:
        start,stop,cycles=map(int,roi[0]);assert stop-start==cycles
        record['roi_cycles']=cycles;dump(run/'roi.json',dict(start_cycle=start,stop_cycle=stop,safe_chain_roi_cycles=cycles,scope=sm['roi_scope']))
    total=re.findall(r'\*\*\* PASSED \*\*\* Completed after (\d+) cycles',logs)
    if len(total)==1:record['total_harness_cycles']=int(total[0])
    record['price_bits']=re.findall(r'\[PRICE\] index=(\d+) bits=([0-9a-f]+)',logs)
    record['checksum']=re.findall(r'checksum=([0-9a-f]+) verified=(\d+)',logs)
    record['roi_instret']=re.findall(r'roi_instret=(\d+)',logs)
    record['software_correct']=rc==0 and len(roi)==1 and len(total)==1 and len(record['price_bits'])==4 and len(record['checksum'])==1 and record['checksum'][0][1]=='1' and '[COMPUTATION] status=PASS' in logs and '[END] hart=0 status=PASS' in logs and not re.search(r'\bAssertion\b|%Error|\*\*\* FAILED|status=FAIL',logs,re.I)
    smoke_ok=args.smoke and rc!=0 and ('(timeout, seed 1) after '+str(maximum)+' cycles') in logs and not re.search(r'\bAssertion\b|%Error',logs,re.I) and '[UART] UART0 is here' in logs
    record['validation']='SMOKE_EXPECTED_TIMEOUT' if smoke_ok else 'SOFTWARE_PASS_PROTOCOL_PENDING' if record['software_correct'] else 'FAILED'
    dump(run/'run_manifest.json',record);print(json.dumps({k:record.get(k)for k in ['run_id','exit_status','host_wall_seconds','roi_cycles','total_harness_cycles','price_bits','checksum','roi_instret','validation']},indent=2),flush=True)
    return 0 if smoke_ok or record['software_correct'] else 1
if __name__=='__main__':raise SystemExit(main())
