#!/usr/bin/python3
"""Durable read-only result consumer; never launches models or touches a board."""
from pathlib import Path
import csv,datetime,fcntl,gzip,hashlib,json,os,re,resource,sys,time,traceback
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import read,save,sha,identity,live
C=Path(__file__).resolve().parent;O=D/'paper-matched-source-cpu-comparison-r2-20261112';N=D/'cycleprecise-matched-single-boom-gg-r3-20261112';A=D/'overnight-ec-evidence-audit-r4-20261112';P=W/'candidates/matched-single-boom-gg-r3-20261112';PACK=D/'paper-real-ec-data-r2-20261112';BASE='8491167d84b6d9521b151a743673c1516926a1f8'
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def csvout(p,rows):
 tmp=p.with_suffix('.tmp')
 with tmp.open('w',newline='') as f:
  w=csv.DictWriter(f,fieldnames=list(dict.fromkeys(k for r in rows for k in r)));w.writeheader();w.writerows(rows);f.flush();os.fsync(f.fileno())
 os.replace(tmp,p)
def extract_core(path,name):
 text=path.read_text();body=text.split('class '+name+'(',1)[1].split('new WithTAGELBPD',1)[1].split('\n/**',1)[0]
 body=body.split('\nclass ',1)[0];body=re.sub(r'//[^\n]*','',body);return re.sub(r'\s+','',body)
def verify_static():
 os.environ['MPLCONFIGDIR']=str(D/'matplotlib-cache');import matplotlib;matplotlib.use('Agg');import matplotlib.pyplot as plt
 plan=read(P/'plan.json');p1=read(W/'candidates/matched-single-boom-gg-r1-20261112/plan.json');audit=read(A/'summary.json');ac=read(A/'complete.json');assert sha(A/'summary.json')==ac['summary_sha256'];assert audit['functional_baseline']==BASE
 pc=read(PACK/'complete.json');assert sha(PACK/'summary.json')==pc['summary_sha256'];assert sha(PACK/'delivery-manifest.json')==pc['delivery_manifest_sha256']
 assert plan['functional_baseline']==BASE and plan['native_source_id']==p1['native_source_id'] and plan['target_frequency_hz']==200000000
 bp=Path('generators/boom/src/main/scala/common/config-mixins.scala');np=W/'Native/chipyard'/bp;ep=W/'C4/chipyard'/bp
 assert extract_core(np,'WithDacMatchedBoom')==extract_core(ep,'WithNParaMedicBooms'),'CORE_PARAMETER_MISMATCH'
 nc=W/'Native/chipyard/generators/chipyard/src/main/scala/config/DacBaselineConfig.scala';ec=W/'C4/chipyard/generators/chipyard/src/main/scala/config/RocketConfigs.scala'
 nt=re.sub(r'\s+','',nc.read_text());et=re.sub(r'\s+','',ec.read_text().split('//===== EC Config: End')[0])
 shared='WithInclusiveCache(nWays=16,capacityKB=1024,outerLatencyCycles=12)';assert shared in nt and shared in et
 for token in ['WithTileFrequency(200,Some(0))','WithSystemBusFrequency(200)','WithMemoryBusFrequency(200)','WithPeripheryBusFrequency(200)']:assert token in nt and token in et
 assert 'Rocket' not in nt and 'Checker' not in nt and 'WithDacMatchedBoom(1,' in nt
 evidence={str(q):sha(q) for q in [P/'plan.json',W/'candidates/matched-single-boom-gg-r1-20261112/plan.json',np,ep,nc,ec,A/'summary.json',A/'complete.json',PACK/'complete.json',C/'matched_consumer.py']}
 swbuild=read(D/'cycleprecise-matched-single-boom-gg-r1-20261112/software-build.json')
 for sw in plan['software']:
  oldroot=Path('/data1/gzh/EC-opt4-perf/slowdown/parsec_evaluation_20261103/build')/sw['workload']/'source';newroot=Path(sw['cwd'])/'source'
  for rel,h in sw['kernel_and_input_source_sha256'].items():assert sha(oldroot/rel)==h==sha(newroot/rel),('KERNEL_OR_INPUT_CHANGED',rel)
  assert sha(newroot/'test.c')==sw['native_main_sha256'];assert sw['source_unchanged_except']==['test.c'];assert sw['threads']==1
  assert sha(sw['reference_manifest'])==sw['reference_manifest_sha256'];rm=read(sw['reference_manifest']);assert rm['elf_sha256']==sw['protected_reference_elf_sha256']
  assert sha(sw['elf'])==next(r['elf_sha256'] for r in swbuild['software'] if r['workload']==sw['workload'])
  original=(oldroot/'test.c').read_text();new=(newroot/'test.c').read_text()
  for t in [original,new]:assert 'rdcycle %0\\nrdinstret %1' in t and 'rdinstret %1\\nrdcycle %0' in t and 'workload_run();' in t
  assert 'test_setup' not in new and 'r_ini' not in new
  # Compiler modes are preserved. Include/output absolute paths intentionally
  # differ because the Native boot adapter resides in a separate capsule.
  for cmd in sw['commands']:assert '-march=rv64imafd' in cmd and '-O2' in cmd and '-static' in cmd
  source=next(r for r in audit['workloads'] if sw['workload'].startswith(r['benchmark']+'_'))
  assert sw['protected_reference_elf_sha256']==source['elf_sha256']
 return plan,audit,evidence

def validate_sample(sw,ec,plan,static):
 folder=N/(sw['workload']+'-full');r=read(folder/'result.json');c=read(folder/'complete.json');binding=read(folder/'binding.json')
 assert c['result_sha256']==sha(folder/'result.json') and c['binding_sha256']==sha(folder/'binding.json')
 assert r['valid'] and r['status']=='PASS_TRUE_SINGLE_BOOM_COMPLETE_MATCHED_KERNEL_ROI' and r['returncode']==0 and not r['timeout'] and not r['faults']
 assert binding['plan_sha256']==sha(P/'plan.json') and binding['elf_sha256']==r['elf_sha256']==sha(sw['elf'])
 assert r['binary_sha256']==binding['binary_sha256']==read(N/'compile-result.json')['binary_sha256']==sha(plan['binary'])
 assert r['functional_baseline']==BASE and r['target_boom_hz']==200000000 and r['threads']==1 and not r['fpga_access']
 assert r['source_kernel_and_input_identical'] and r['roi_scope']==sw['roi_scope'] and not r['same_ec_elf']
 assert r['memory_plusargs']==plan['memory_plusargs'];memory={x.split('=')[0]:x.split('=')[1] for x in plan['memory_plusargs']}
 assert memory=={'+mm_readLatency_0':'30','+mm_readMaxReqs_0':'4','+mm_relaxFunctionalModel_0':'0','+mm_writeLatency_0':'30','+mm_writeMaxReqs_0':'4'}
 eroot=Path(ec['source_result']).parent
 eb=eroot/'canneal-observer-on/binding.json' if ec['benchmark']=='canneal' else eroot/'binding.json'
 ebinding=read(eb);assert ebinding['elf_sha256']==ec['elf_sha256']==r['protected_reference_elf_sha256'];assert all(x in ebinding['args'] for x in plan['memory_plusargs'])
 assert r['roi_end_csr']-r['roi_start_csr']==r['roi_cycles']>0
 assert ec['faults']==0 and ec['pending_at_observation_end']==0 and ec['boom_accepted_pass']==ec['full_compare_results']
 assert r['output']==sw['expected_output'] and '[OUTPUT] '+r['output'][0]==ec['output']
 log=folder/'host-complete.log.gz';assert sha(log)==r['compressed_log_sha256'];h=hashlib.sha256();count=0;rows=[];tail=b''
 with gzip.open(log,'rb') as f:
  for block in iter(lambda:f.read(2**20),b''):
   h.update(block);count+=len(block);parts=(tail+block).split(b'\n');tail=parts.pop()
   for line in parts:
    if any(x in line for x in [b'[APP]',b'[OUTPUT]',b'[END]',b'[ROI]',b'%Error',b'Assertion failed',b'status=FAIL']):rows.append(line.decode(errors='replace'))
 assert count==r['raw_stdout_bytes'] and h.hexdigest()==r['raw_stdout_sha256'];assert '[END] hart=0 status=PASS' in rows;assert not any('status=FAIL' in x or '%Error' in x or 'Assertion failed' in x for x in rows)
 assert [x.split('[OUTPUT] ',1)[1] for x in rows if '[OUTPUT] ' in x]==sw['expected_output']
 instructions_equal=r['roi_instructions']==ec['roi_instructions']
 out=O/sw['workload'];out.mkdir(exist_ok=True);assert not (out/'complete.json').exists()
 evidence={**static,**{str(p):sha(p) for p in [folder/'result.json',folder/'complete.json',folder/'binding.json',eb,N/'compile-result.json',log]}}
 result=dict(status='PASS_SOURCE_MATCHED_CPU_COMPARISON' if instructions_equal else 'VALID_RUNS_INSTRUCTION_COUNT_MISMATCH_COMPARISON_WITHHELD',
  data_kind='CPU_GOLDENGATE_SOURCE_MATCHED_BAREMETAL_NOT_FPGA',benchmark=ec['benchmark'],input_profile=sw['workload'],functional_baseline=BASE,
  native_roi_cycles=r['roi_cycles'],ec_roi_cycles=ec['roi_cycles'],ec_drain_cycles=ec['checker_acceptance_tail_csr_cycles'],
  native_roi_instructions=r['roi_instructions'],ec_roi_instructions=ec['roi_instructions'],instructions_equal=instructions_equal,
  ratio_ec_native_roi=ec['roi_cycles']/r['roi_cycles'] if instructions_equal else None,
  ratio_ec_including_drain_native_roi=(ec['roi_cycles']+ec['checker_acceptance_tail_csr_cycles'])/r['roi_cycles'] if instructions_equal else None,
  native_host_seconds=r['host_wall_seconds'],ec_host_seconds=ec['host_wall_seconds'],host_time_is_architecture_slowdown=False,
  target_boom_hz=200000000,ec_checker_hz=100000000,common_memory='FASED LatencyBandwidthPipe read/write30 max4 relax0',
  kernel_input_sources_identical=True,source_file_count=len(sw['kernel_and_input_source_sha256']),same_elf=False,
  native_elf_sha256=r['elf_sha256'],ec_elf_sha256=ec['elf_sha256'],native_source_id=r['native_source_id'],ec_source_id=ec['source_id'],
  ordinary_linux_fpga_pair=False,limitations=['Independent Native startup adapter excludes EC custom initialization; original test_setup cannot run on no-checker hardware','Different ELF/link layout and initial cache state; no perfect sameELF claim','Whole shared BOOM/cache parameters audited; EC mechanisms retained','Single deterministic CPU sample each, not three formal FPGA rounds'],
  instruction_mismatch_next_action=None if instructions_equal else 'Disassemble ROI/kernel and attribute native adapter register allocation, source paths, EC trap/interrupt overhead before any ratio publication',
  output_correct=True,ec_fullcompare_pass=ec['boom_accepted_pass'],ec_end_pending=0,fpga_access=False,completed_utc=now())
 save(out/'result.json',result);save(out/'evidence.json',evidence);csvout(out/'comparison.csv',[{k:v for k,v in result.items() if not isinstance(v,(dict,list))}]);
 if instructions_equal:
  os.environ['MPLCONFIGDIR']=str(D/'matplotlib-cache');import matplotlib;matplotlib.use('Agg');import matplotlib.pyplot as plt
  fig,ax=plt.subplots(figsize=(5,3.8));ax.bar(['Native CPU GG','EC CPU GG'],[r['roi_cycles'],ec['roi_cycles']],color=['#467c94','#b16543']);ax.set(ylabel='ROI target cycles',title=sw['workload']+'; source-matched, different boot ELF');fig.tight_layout()
  for ext in ['pdf','svg']:fig.savefig(out/('roi-cycles.'+ext),bbox_inches='tight')
  plt.close(fig)
 save(out/'complete.json',dict(result_sha256=sha(out/'result.json'),evidence_sha256=sha(out/'evidence.json')));return result

def main():
 O.mkdir(exist_ok=True);lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB);os.nice(10);os.sched_setaffinity(0,{208});resource.setrlimit(resource.RLIMIT_AS,(4*2**30,4*2**30));plan,audit,static=verify_static();save(O/'static-verification.json',dict(status='PASS_COMMON_BOOM_CACHE_FREQUENCY_KERNEL_INPUT_COMPILER_ROI_ADAPTER_AUDIT',files=static,fpga_access=False))
 completed={};failed={}
 for p in O.glob('*/complete.json'):
  q=read(p.parent/'result.json');assert sha(p.parent/'result.json')==read(p)['result_sha256'];completed[p.parent.name]=q
 for p in O.glob('*/validation-failure.json'):failed[p.parent.name]=read(p)
 while True:
  for sw in plan['software']:
   name=sw['workload']
   if name in completed or name in failed:continue
   if (N/(name+'-full')/'complete.json').exists():
    try:completed[name]=validate_sample(sw,next(r for r in audit['workloads'] if r['benchmark']==name.split('_')[0]),plan,static)
    except Exception as error:
     out=O/name;out.mkdir(exist_ok=True);failed[name]=dict(status='VALIDATION_FAILED_WITH_EVIDENCE_COMPARISON_WITHHELD',error=repr(error),traceback=traceback.format_exc(),fpga_access=False,utc=now());save(out/'validation-failure.json',failed[name])
  broker=read(D/'unattended-opt4/jobs/matched-single-boom-gg-r3-8491167d/state.json');end=read(N/'result.json')
  terminal=len(completed)+len(failed)==len(plan['software']) or bool(end) or (broker.get('status')=='FAILED_WITH_EVIDENCE' and not live(broker) and not live(broker.get('child',{})))
  status=dict(status='COMPLETE_VALIDATED_CPU_COMPARISONS' if len(completed)==2 else ('TERMINAL_PARTIAL_OR_WITHHELD_COMPARISONS' if terminal else 'WAITING_OWNED_NATIVE_CPU_COMPLETION_NO_DEVICE_ACCESS'),**identity(),completed={k:v['status'] for k,v in completed.items()},failed=failed,source_state=str(N/'result.json'),updated_utc=now(),fpga_access=False)
  save(O/'state.json',status)
  if completed:csvout(O/'comparisons.csv',[{k:v for k,v in row.items() if not isinstance(v,(list,dict))} for row in completed.values()])
  if terminal:save(O/'complete.json',dict(state_sha256=sha(O/'state.json'),static_verification_sha256=sha(O/'static-verification.json'),completed_count=len(completed),failed_count=len(failed),missing=[sw['workload'] for sw in plan['software'] if sw['workload'] not in completed and sw['workload'] not in failed],fpga_access=False));return
  time.sleep(300)
if __name__=='__main__':
 if '--offline' in sys.argv:
  plan,audit,evidence=verify_static();O.mkdir(exist_ok=True)
  sw=plan['software'][0];print(json.dumps(validate_sample(sw,next(x for x in audit['workloads'] if x['benchmark']=='canneal'),plan,evidence),indent=2))
 else:main()
