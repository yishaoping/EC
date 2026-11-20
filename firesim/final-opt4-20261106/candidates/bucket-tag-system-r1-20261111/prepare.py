#!/usr/bin/python3
from pathlib import Path
import ast,hashlib,importlib.util,json,os,shutil,subprocess,sys
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');U=D/'unattended-opt4';C=Path(__file__).resolve().parent
F=W/'Opt4-fit-address-bucket-tag-r3-20261111';COMMIT='9ae9a7fcf231a75259e23973b12a93896a443cbb';L=D/'build-logs/Opt4-fit-bucket-tag-system-r1-20261111'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def write(p,x):
 p=Path(p);p.parent.mkdir(parents=True,exist_ok=True);data=(json.dumps(x,indent=2,sort_keys=True)+'\n').encode()
 if p.exists():assert p.read_bytes()==data,str(p);return
 q=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with q.open('xb') as f:f.write(data);f.flush();os.fsync(f.fileno())
 os.replace(q,p)
def main():
 for n in ['controller.py','prepare.py']:ast.parse((C/n).read_text())
 assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()==COMMIT
 sys.path.insert(0,str(W/'scripts'));s=importlib.util.spec_from_file_location('bucket_system_inventory',W/'scripts/build_hw.py');mod=importlib.util.module_from_spec(s);s.loader.exec_module(mod)
 inv=mod.inventory(F/'chipyard');sid=hashlib.sha256(json.dumps(inv,sort_keys=True).encode()).hexdigest()
 state=D/'Opt4-fit-address-bucket-tag-r3-state.json';mapped=json.loads(state.read_text());assert sid==mapped['source_id'] and mapped['status']=='VERIFIED_AND_MAPPED_CANDIDATE_NOT_PROMOTED'
 original=W/'Opt4-fit-20261110/bindings/8da24a269b98a0d6a8f57b030353a310812c4344.json';base=json.loads(original.read_text());changed=base['changed_files']+['chipyard/generators/boom/src/main/scala/lsu/AddressBucketGrouped.scala']
 for rel in base['changed_files'][1:]:assert (F/rel).read_bytes()==subprocess.check_output(['git','show','8da24a269b98a0d6a8f57b030353a310812c4344:'+rel],cwd=F)
 b=dict(schema='ec-opt4-best-module-system-binding/1',hardware_commit=COMMIT,source_id=sid,frozen_commit=base['frozen_commit'],changed_files=changed,formal_admission=False,production_selected=False,full_dut_formal=False)
 write(C/'binding.json',b);write(C/'source-inventory.json',inv);write(F/'bindings'/(COMMIT+'.json'),b)
 cfg=json.loads((W/'candidates/address-group4-r1-20261111/config.json').read_text());cfg.update(binding=b,worktree=str(F),verified_local=str(D/'build-logs/Opt4-fit-address-bucket-tag-r3-20261111/verified-local.json'),mapped_result=str(state),firechip=str(W/'C4/chipyard/generators/firechip/target/scala-2.13/firechip_2.13-1.6.jar'),frozen_parameters=str(W/'builds/C4-parameters-20261106T100204.040607Z/parameters.json'),baseline_driver_compatibility=str(W/'runtime/Opt4-fit-C4-driver-compatibility.json'));write(C/'config.json',cfg)
 baseline=json.loads(Path(cfg['baseline_driver_compatibility']).read_text());assert len(baseline['generated_abi_and_target_description'])==7
 paths=[C/n for n in ['controller.py','prepare.py','config.json','binding.json','source-inventory.json']]
 paths += [F/rel for rel in changed]
 paths += [W/'scripts/build_hw.py',original,F/'bindings'/(COMMIT+'.json'),W/'integration.json',Path(cfg['firechip']),Path(cfg['frozen_parameters']),Path(cfg['baseline_driver_compatibility']),state,Path(cfg['verified_local']),Path(mapped['full_module_map']['report'])]
 paths += [Path(row['original']) for row in baseline['generated_abi_and_target_description']]
 paths += [Path(p) for p in cfg['classpath']+cfg['compiler']+[cfg['plugin']]]
 hashes={str(p):sha(p) for p in sorted(set(paths),key=str)};write(C/'input-hashes.json',hashes)
 direct={p:h for p,h in hashes.items() if Path(p).resolve().is_relative_to(W)};direct[str(C/'input-hashes.json')]=sha(C/'input-hashes.json')
 desc=dict(schema='ec-opt4-runtime-candidate/1',commit=COMMIT,source_id=sid,profile='Opt4-fit-C4-SVB32-bucket-tag-20261111',worktree=str(F),cad_state=str(D/'Opt4-fit-bucket-tag-cad-state.json'),rtl_state=str(D/'Opt4-fit-bucket-tag-rtl-state.json'),state_prefix='Opt4-fit-bucket-tag',board_bdf='0000:21:00.0',board_serial='21770433G02LA');dp=W/'runtime-candidates'/(COMMIT[:8]+'.json');write(dp,desc)
 memory=int(next(l.split()[1] for l in Path('/proc/meminfo').read_text().splitlines() if l.startswith('MemAvailable:')))/2**20;disk=shutil.disk_usage(W).free/2**30;assert memory>=96 and disk>=100
 name='bucket-tag-system-r1-'+COMMIT[:8];req=dict(action='cpu_job',spec=dict(name=name,kind='rtl',cwd=str(F/'chipyard'),argv=['/usr/bin/python3',str(C/'controller.py')],inputs=direct,outputs=[str(L/'result.json'),str(D/'Opt4-fit-bucket-tag-rtl-state.json'),str(L/'driver-reuse-seven-file-audit.json')],checkpoints=[str(D/'Opt4-fit-bucket-tag-system-r1-state.json'),str(D/'Opt4-fit-bucket-tag-rtl-state.json')]))
 report=dict(schema='ec-opt4-best-module-system-preflight/1',hardware_commit=COMMIT,source_id=sid,status='VERIFIED_MODULE_BOUND_FOR_RTL_AND_REAL_ABI_AUDIT',module_lut=990905,module_carry8=55418,manifest_sha256=sha(C/'input-hashes.json'),available_memory_gib=memory,free_disk_gib=disk,max_threads=8,minimum_memory_gib=96,minimum_disk_gib=100,fpga_access=False,full_dut_synthesis=False,formal_admission=False,proof_limits='Local proof and finite complete-module regression only; no full-DUT formal or whole-system FIT. Existing 8da CAD is untouched; this job has no CAD stage.')
 write(L/'preflight.json',report)
 if '--submit' in sys.argv:
  write(U/'requests'/(name+'.json'),req);write(U/'requests'/(COMMIT[:8]+'-prepare-runtime.json'),dict(action='prepare_runtime',descriptor=str(dp)))
 print(json.dumps(report))
if __name__=='__main__':main()
