#!/usr/bin/python3
"""Pin the new best-parent structural candidate and its local proof/map job."""
from pathlib import Path
import ast,hashlib,importlib.util,json,os,shutil,subprocess,sys
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');U=D/'unattended-opt4';C=Path(__file__).resolve().parent
F=W/'Opt4-fit-address-update-share-r2-20261111';P=W/'Opt4-fit-address-bucket-tag-r3-20261111';R='chipyard/generators/boom/src/main/scala/lsu/'
O=D/'build-logs/Opt4-fit-address-update-share-r2-20261111';PARENT='9ae9a7fcf231a75259e23973b12a93896a443cbb';FROZEN='8491167d84b6d9521b151a743673c1516926a1f8'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def write(p,data):
 p=Path(p);p.parent.mkdir(parents=True,exist_ok=True)
 if p.exists():assert p.read_bytes()==data,str(p);return
 q=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with q.open('xb') as f:f.write(data);f.flush();os.fsync(f.fileno())
 os.replace(q,p)
def save(p,x):write(p,(json.dumps(x,indent=2,sort_keys=True)+'\n').encode())
def main():
 for n in ['controller.py','prepare.py']:ast.parse((C/n).read_text())
 commit=subprocess.check_output(['git','rev-parse','HEAD'],cwd=F,text=True).strip()
 assert subprocess.check_output(['git','rev-parse','HEAD^'],cwd=F,text=True).strip()=='eada7948b15146fd33bbc91aad7bac4ab9ec44b7'
 assert subprocess.check_output(['git','rev-parse',FROZEN],cwd=F,text=True).strip()==FROZEN
 assert subprocess.check_output(['git','diff','--check',PARENT,commit],cwd=F)==b''
 sys.path.insert(0,str(W/'scripts'));spec=importlib.util.spec_from_file_location('update_inventory',W/'scripts/build_hw.py');mod=importlib.util.module_from_spec(spec);spec.loader.exec_module(mod)
 inventory=mod.inventory(F/'chipyard');sid=hashlib.sha256(json.dumps(inventory,sort_keys=True).encode()).hexdigest()
 patch=subprocess.check_output(['git','show','--format=','--binary',commit],cwd=F)
 b=dict(schema='ec-opt4-update-share-binding/1',hardware_commit=commit,source_id=sid,parent_commit=PARENT,frozen_commit=FROZEN,profile='Opt4-fit-address-update-share-r2-candidate',candidate_change='Consolidate allocation and delta-hit writes while retaining exact zero-based allocation for arbitrary invalid payload. Current addend mux and all reset/error logic are retained. No invariant precondition, widths, bucket count or cycles change.',derivation_parent='eada7948b15146fd33bbc91aad7bac4ab9ec44b7',patch_sha256=hashlib.sha256(patch).hexdigest(),formal_admission=False,production_selected=False)
 save(F/'source-inventory.json',inventory);write(F/'candidate.patch',patch);save(F/'candidate-binding.json',b);save(F/'bindings'/(commit+'.json'),b);save(C/'binding.json',b)
 for n in ['frozen-original.v','frozen-tb.v']:
  data=(W/'candidates/address-group4-r1-20261111'/n).read_bytes()
  if n=='frozen-tb.v':
   data=data.replace(b'reset=(i<3); io_resetStats=',b'reset=(i<3 || i%2048==512 || i%2048==513); io_resetStats=')
   data=data.replace(b'io_start=(phase==4);',b'io_start=(phase==4 || phase==516);')
  write(C/n,data)
 cfg=json.loads((W/'candidates/address-group4-r1-20261111/config.json').read_text());cfg.update(binding=b,worktree=str(F),parent_local_receipt=str(D/'build-logs/Opt4-fit-address-bucket-tag-r3-20261111/verified-local.json'));save(C/'config.json',cfg)
 inherited=json.loads(Path(cfg['parent_local_receipt']).read_text()); assert inherited['hardware_commit']==PARENT
 assert inherited['inherited_group4']['actual_size_boundary']=='PASS_8192_VECTORS_80_INPUTS_1024_OUTPUTS_256_BUCKETS_64BIT_OVERFLOW_RESET'
 assert (F/R/'AddressBucketGrouped.scala').read_bytes()==(P/R/'AddressBucketGrouped.scala').read_bytes()
 paths=[p for p in C.iterdir() if p.is_file() and p.name!='input-hashes.json']
 paths += [F/R/n for n in ['PackageAddressStats.scala','AddressBucketGrouped.scala','AddressBucketUpdate.scala']]
 paths += [F/'source-inventory.json',F/'candidate.patch',F/'candidate-binding.json',F/'lineage.json',F/'bindings'/(commit+'.json'),W/'scripts/build_hw.py',W/'candidates/make_update_share_r1.py',Path(cfg['parent_local_receipt']),D/'build-logs/Opt4-fit-address-group4-r1-20261111/result.json',D/'build-logs/Opt4-fit-address-group4-r1-20261111/verified-local.json',D/'build-logs/Opt4-fit-address-group4-r1-20261111/histogram/boundary-run-result.json',D/'build-logs/Opt4-fit-address-group4-r1-20261111/histogram/boundary-run-attempt-1.log']
 paths += [Path(p) for p in cfg['classpath']+cfg['compiler']+[cfg['plugin']]]
 inputs={str(p):sha(p) for p in sorted(set(paths),key=str)};save(C/'input-hashes.json',inputs)
 direct={p:h for p,h in inputs.items() if Path(p).resolve().is_relative_to(W)};direct[str(C/'input-hashes.json')]=sha(C/'input-hashes.json')
 desc=dict(schema='ec-opt4-runtime-candidate/1',commit=commit,source_id=sid,profile='Opt4-fit-C4-SVB32-update-share-r2-20261111',state_prefix='Opt4-fit-update-share-r2',worktree=str(F),cad_state=str(D/'Opt4-fit-update-share-r2-cad-state.json'),rtl_state=str(D/'Opt4-fit-update-share-r2-rtl-state.json'),board_bdf='0000:21:00.0',board_serial='21770433G02LA');dp=W/'runtime-candidates'/(commit[:8]+'.json');save(dp,desc)
 memory=int(next(x.split()[1] for x in Path('/proc/meminfo').read_text().splitlines() if x.startswith('MemAvailable:')))/2**20;disk=shutil.disk_usage(W).free/2**30;assert memory>=48 and disk>=40
 name='address-update-share-r2-'+commit[:8];req=dict(action='cpu_job',spec=dict(name=name,kind='module',cwd=str(F/'chipyard'),argv=['/usr/bin/python3',str(C/'controller.py')],inputs=direct,outputs=[str(O/'result.json'),str(O/'verified-local.json')],checkpoints=[str(D/'Opt4-fit-address-update-share-r2-state.json'),str(O/'verified-local.json')]))
 report=dict(schema='ec-opt4-update-share-preflight/1',hardware_commit=commit,source_id=sid,parent_commit=PARENT,manifest_sha256=sha(C/'input-hashes.json'),available_memory_gib=memory,free_disk_gib=disk,max_threads=8,minimum_memory_gib=48,minimum_disk_gib=40,status='BOUND_PROOF_BOUNDARY_COMPARE_MAP_PENDING',prior_delta_evidence='56711a00 used a different decode/reduction parent and hit Vivado internal negative-allocation failure. This candidate retains the better group4/fixed-slot topology and additionally merges the write branches; no resource gain is assumed.',full_dut_synthesis=False,formal_admission=False,fpga_access=False)
 save(O/'candidate-preflight.json',report)
 if '--submit' in sys.argv:
  save(U/'requests'/(name+'.json'),req);save(U/'requests'/(commit[:8]+'-prepare-runtime.json'),dict(action='prepare_runtime',descriptor=str(dp)))
 print(json.dumps(report))
if __name__=='__main__':main()
