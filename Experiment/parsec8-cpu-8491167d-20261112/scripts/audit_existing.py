#!/usr/bin/env python3
from common import *
import subprocess
out=ROOT/'audit';out.mkdir(exist_ok=True)
audit={
 'schema':'parsec8-existing-evidence-audit/1','functional_baseline':BASE,
 'frozen_source_id':'c9f51d3a94aac7783c750682162cd25e9d1460b04974bde9b7541f1d9f4120e7',
 'start_here_source':str(EC/'slowdown/final_opt4_freeze_20261106/FIRESIM_START_HERE.md'),
 'start_here_copy_sha256':sha(out/'FIRESIM_START_HERE.md'),
 'created_utc':now(),'fpga_access':False,'cad_access':False,
 'evidence':{},'benchmarks':{},
 'separation_rules':['Do not combine old Linux FPGA simmedium, baremetal project64/project400, and CPU GG target cycles.',
 'Canneal project400 is workflow validation only and excluded from the requested eight.',
 'Native FPGA results are not CPU target-cycle samples.',
 'Only valid CPU GoldenGate source-matched per-profile pairs may enter the CPU GG geomean.'],
}
for path in [D/'paper-matched-source-cpu-comparison-r2-20261112/README.md',D/'paper-matched-source-cpu-comparison-r2-20261112/canneal_project400/result.json',D/'cycleprecise-frozen-full-gg-blackscholes-observed-r1-20261111/result.json',D/'cycleprecise-frozen-full-gg-blackscholes-observed-r1-20261111/strict-acceptance.json',D/'cycleprecise-frozen-canneal-20261111/result.json',D/'cycleprecise-frozen-canneal-20261111/fresh-event-intervals.json',W/'candidates/matched-single-boom-gg-r1-20261112/plan.json',W/'candidates/full-gg-blackscholes-observed-r1-20261111/plan.json']:
 if path.is_file():audit['evidence'][str(path)]={'sha256':sha(path),'size':path.stat().st_size}
requested=['blackscholes','fluidanimate','bodytrack','freqmine','swaptions','ferret','dedup','streamcluster']
for name in requested:
 row={'benchmark':name,'functional_baseline':BASE,'native_cycles':None,'ec_cycles':None,'slowdown':None,'instructions_native':None,'instructions_ec':None,'correctness':None,'evidence':[]}
 if name=='blackscholes':
  r=read(D/'cycleprecise-frozen-full-gg-blackscholes-observed-r1-20261111/result.json')
  row.update(profile='project64',threads=1,method='CPU_GOLDENGATE_FULL_APPLICATION',ec_cycles=r.get('roi_cycles'),instructions_ec=r.get('roi_instructions'),correctness='EC PASS; output and 1122/1122 checker results accepted',status='WAITING_FOR_MATCHED_CLEAN_NATIVE_FULL_ROI',native_cycles=None)
  row['evidence'] += [str(D/'cycleprecise-frozen-full-gg-blackscholes-observed-r1-20261111/result.json'),str(D/'cycleprecise-frozen-full-gg-blackscholes-observed-r1-20261112')]
 elif name=='streamcluster':
  row.update(profile='project64',threads=1,method='CPU_GOLDENGATE_FULL_APPLICATION',status='RUNNING_PAIRED_CPU_GG',correctness='not yet validated')
  row['evidence'] += [str(ROOT/'software/streamcluster_project64/manifest.json'),str(ROOT/'runs/streamcluster-project64-native-r1-attempt2'),str(ROOT/'runs/streamcluster-project64-ec-r1-attempt2')]
 elif name in ['fluidanimate','bodytrack','freqmine','swaptions','ferret','dedup']:
  row.update(profile='PARSEC simsmall Linux workload not executable by current baremetal CPU GG harness',threads=1,status='SKIPPED_UNSUPPORTED_LINUX_ABI',correctness='not measured')
  for p in sorted((W/'software').glob(name+'*apps-build.json')):
   try:
    j=read(p);b=j.get('binaries',{}).get(name,{})
    row['existing_linux_artifact']={'receipt':str(p),'status':j.get('status'),'binary':b.get('path'),'sha256':b.get('sha256'),'application_threads':b.get('application_threads'),'reference_sha256':b.get('reference_sha256')}
    break
   except Exception:pass
  row['diagnostic']='Existing ELF built for guest Linux; CPU GG +prog0 path is baremetal HTIF. No Linux userland/syscall/filesystem workload image or tested ROI adapter is bound to this matched model.'
  row['evidence'] += [str(p) for p in sorted((W/'software').glob(name+'*apps-build.json'))[:3]]
 audit['benchmarks'][name]=row
for p in [W/'candidates/matched-single-boom-gg-r1-20261112/software/blackscholes_project64/protected.riscv',D/'cycleprecise-frozen-full-gg-blackscholes-observed-r1-20261111/software/blackscholes-project64.riscv',W/'software/apps-formal-20261106/blackscholes']:
 if p.exists():
  x=subprocess.run(['/usr/bin/file',str(p)],text=True,capture_output=True,check=True)
  audit['evidence'][str(p)]={'sha256':sha(p),'file_abi':x.stdout.strip()}
save(out/'existing-data-audit.json',audit)
print(json.dumps({'audit':str(out/'existing-data-audit.json'),'benchmarks':{k:v['status'] for k,v in audit['benchmarks'].items()},'evidence_files':len(audit['evidence'])},indent=2))
