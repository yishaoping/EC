#!/usr/bin/python3
"""Matched longer ROI on existing frozen full-EC / clean Native GG models.

Own outputs only. Shares original CPU locks; never modifies original campaign.
"""
from pathlib import Path
import argparse,csv,fcntl,hashlib,importlib.util,json,os,re,shutil,subprocess,sys,time

ROOT=Path(__file__).resolve().parent
ORIGINAL=ROOT.parent/'parsec8-cpu-8491167d-20261112'
OLD=ORIGINAL/'software/blackscholes_no_main_timer'
SW=ROOT/'software/blackscholes_project64_100_iterations'
BASE='8491167d84b6d9521b151a743673c1516926a1f8'
sys.path.insert(0,str(ORIGINAL/'scripts'))
from common import read,save,sha,ident,now,NATIVE,PROTECTED,MEM,module

def prepare():
 assert not SW.exists() and not (ROOT/'inputs.json').exists()
 mf=read(OLD/'manifest.json')
 assert mf['functional_baseline']==BASE and mf['threads']==1
 for n,h in mf['source_sha256'].items():assert sha(OLD/'source'/n)==h
 SW.mkdir(parents=True);shutil.copytree(OLD/'source',SW/'source')
 upstream=SW/'source/blackscholes.upstream.c';text=upstream.read_text()
 assert text.count('#define NUM_RUNS 1\n')==1
 upstream.write_text(text.replace('#define NUM_RUNS 1\n','#define NUM_RUNS 100\n'))
 shutil.copy2(OLD/'htif.ld',SW/'htif.ld') if (OLD/'htif.ld').exists() else None
 commands=[]
 with (SW/'build.log').open('xb') as log:
  for cmd in mf['commands']:
   argv=[a.replace(str(OLD),str(SW)) for a in cmd]
   subprocess.run(argv,cwd=SW,stdout=log,stderr=subprocess.STDOUT,check=True);commands.append(argv)
 host=SW/'host-reference';proc=subprocess.run([str(host)],cwd=SW,stdout=subprocess.PIPE,stderr=subprocess.PIPE,text=True,timeout=60,check=True)
 (SW/'host-reference.log').write_text(proc.stdout+proc.stderr)
 outputs=[x.split('[OUTPUT] ',1)[1] for x in proc.stdout.splitlines() if x.startswith('[OUTPUT] ')]
 assert len(outputs)==1 and 'verified=1' in outputs[0] and 'runs=100' in outputs[0]
 assert outputs==[s.replace('runs=1','runs=100') for s in mf['expected_output']]
 sources={str(p.relative_to(SW/'source')):sha(p) for p in (SW/'source').rglob('*') if p.is_file()}
 differences=[n for n,h in sources.items() if mf['source_sha256'].get(n)!=h]
 assert differences==['blackscholes.upstream.c']
 assert upstream.read_text().replace('#define NUM_RUNS 100\n','#define NUM_RUNS 1\n')==(OLD/'source/blackscholes.upstream.c').read_text()
 mf.update(profile='project64-100-iterations-no-main-timer',method='CPU_GG_PROJECT64_COMPLETE_KERNEL_ROI',
           input={**mf['input'],'iterations':100},commands=commands,expected_output=outputs,
           roi_scope='Full original bs_thread 100 iterations on64 declared option records; workload_prepare/output and checker tail outsideROI',
           limitations=['Full declared64-option kernel ROI, not official Linux simmedium or whole application including I/O',
                        'Separate startup ELF/link/cache state; same application objects/ISA/input/threadcount/timer policy',
                        'Only100iterations restored; no hardware feature or cycle semantics changed'],
           source_sha256=sources,original_source_profile_sha256=sha(OLD/'manifest.json'),
           shared_kernel_objects={str(SW/Path(p).name):sha(SW/Path(p).name) for p in mf['shared_kernel_objects']},
           elf={m:dict(path=str(SW/(m+'.riscv')),sha256=sha(SW/(m+'.riscv'))) for m in ['native','ec']},
           host_reference=dict(path=str(host),sha256=sha(host),log=str(SW/'host-reference.log'),log_sha256=sha(SW/'host-reference.log')),
           max_target_cycles=16000000,timeout_seconds=28800)
 save(SW/'manifest.json',mf)
 policy=read(ORIGINAL/'execution-policy.json')
 policy.update(host_timeout_floor_seconds=28800,raw_log_limit_bytes=16*2**30,simulators_total=2,
               reason='New100iteration exact matched project64 ROI; measured original ECU GG around400targetcycles/s. Preserve all target/ROI semantics, use host budget8h, compressed raw logs; Native200 and EC201 original locks.')
 save(ROOT/'execution-policy.json',policy)
 pins={str(p):sha(p) for p in [Path(__file__),SW/'manifest.json',ROOT/'execution-policy.json',OLD/'manifest.json',
                              ORIGINAL/'scripts/run_one.py',ORIGINAL/'scripts/common.py',NATIVE,PROTECTED]}
 for m in mf['elf'].values():pins[m['path']]=m['sha256']
 for p,h in mf['shared_kernel_objects'].items():pins[p]=h
 save(ROOT/'inputs.json',dict(functional_baseline=BASE,files=pins,fpga_access=False,
                            one_source_change='NUM_RUNS1->100 restored to original project64',native_cpu=200,ec_cpu=201,
                            original_campaign_shared_locks=True,original_campaign_not_modified=True,
                            existing_profile_pairs_reused='/data1/gzh/EC/Experiment/parsec8-performance-audit-r2-20261112'))
 print('Built matched100iteration ELFs and host correctness oracle PASS',flush=True)

def verify_pins():
 pins=read(ROOT/'inputs.json');assert pins['functional_baseline']==BASE
 for p,h in pins['files'].items():assert sha(p)==h,('input changed',p)

def run(mode):
 verify_pins();cpu=200 if mode=='native' else 201
 # Hold BOTH original shared resource locks for the complete new run.
 held=[]
 for n in [f'cpu{cpu}-simulator.lock',mode+'-simulator.lock']:
  f=(ORIGINAL/n).open('a');fcntl.flock(f,fcntl.LOCK_EX|fcntl.LOCK_NB);held.append(f)
 m=module(ORIGINAL/'scripts/run_one.py','original_parsec_runner_'+mode)
 m.ROOT=ROOT
 result=m.run(SW/'manifest.json',mode,repeat=1,attempt=1,slot_name=mode)
 print(json.dumps(result,indent=2),flush=True)

def export_pair():
 mf=read(SW/'manifest.json');paths={m:ROOT/'runs'/f"blackscholes-{mf['profile']}-{m}-r1" for m in ['native','ec']}
 results={m:read(p/'result.json') for m,p in paths.items() if (p/'result.json').exists()}
 comparable=len(results)==2 and all(r['valid'] for r in results.values())
 if comparable:
  n,e=results['native'],results['ec']
  comparable=n['roi_instructions']==e['roi_instructions'] and n['output']==e['output'] and n['manifest_sha256']==e['manifest_sha256']==sha(SW/'manifest.json')
 if not comparable:
  save(ROOT/'comparison.json',dict(status='FAILED_OR_NONCOMPARABLE_KEEP_EIGHT_EXISTING_PAIRS',results={m:str(paths[m]/'result.json') for m in results},valid_ratio=False));return
 auditor=module(ROOT.parent/'parsec8-performance-audit-20261112/audit_and_publish.py','raw_audit_helpers')
 audits=[auditor.audit_run(paths[m]/'result.json') for m in ['native','ec']]
 ratio=e['roi_cycles']/n['roi_cycles']
 row=dict(benchmark='blackscholes',profile=mf['profile'],native_roi_cycles=n['roi_cycles'],ec_roi_cycles=e['roi_cycles'],
          slowdown=ratio,roi_instructions_each=n['roi_instructions'],threads=1,method='CPU_GG_CYCLE_EXACT',
          scope=mf['roi_scope'],full_simmedium=False,native_result=str(paths['native']/'result.json'),ec_result=str(paths['ec']/'result.json'))
 with (ROOT/'comparison.csv').open('x') as f:w=csv.DictWriter(f,fieldnames=list(row));w.writeheader();w.writerow(row)
 save(ROOT/'raw-audits.json',audits)
 save(ROOT/'comparison.json',dict(status='VALID_LONGER_MATCHED_PROJECT64_PAIR',valid_ratio=True,**row,
                                native_result_sha256=sha(paths['native']/'result.json'),ec_result_sha256=sha(paths['ec']/'result.json'),
                                raw_audits_sha256=sha(ROOT/'raw-audits.json'),functional_baseline=BASE))
 import matplotlib
 matplotlib.use('Agg')
 import matplotlib.pyplot as plt
 previous=list(csv.DictReader((ROOT.parent/'parsec8-performance-audit-r2-20261112/first-round.csv').open()))
 fig,ax=plt.subplots(figsize=(11,4.5));fig.subplots_adjust(bottom=.25)
 labels=[r['benchmark']+'\nscoped ROI' for r in previous]+['blackscholes\n64options ×100']
 bars=ax.bar(range(9),[float(r['slowdown']) for r in previous]+[ratio],color=['#367da2']*8+['#59834d'])
 ax.bar_label(bars,fmt='%.3f',padding=4);ax.set_xticks(range(9),labels,rotation=20,ha='right')
 ax.set(ylabel='EC/Native target ROI cycles',title='Cycle-exact CPU Golden Gate — explicit declared profiles',ylim=(0,3.3));ax.axhline(1,color='gray',ls='--')
 for ext in ['pdf','svg','png']:fig.savefig(ROOT/('Performance-updated.'+ext),dpi=160)
 plt.close(fig)
 save(ROOT/'complete.json',dict(comparison_sha256=sha(ROOT/'comparison.json'),completed_utc=now()))

def controller():
 verify_pins();lock=(ROOT/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 assert not (ROOT/'started.json').exists(),'preserve run; no blind retry'
 save(ROOT/'started.json',dict(controller=ident(os.getpid()),started_utc=now(),inputs_sha256=sha(ROOT/'inputs.json'),fpga_access=False))
 children={};logs=[]
 for mode in ['native','ec']:
  f=(ROOT/(mode+'-controller.log')).open('xb');logs.append(f)
  children[mode]=subprocess.Popen([sys.executable,str(Path(__file__)),'--run',mode],cwd=ROOT,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
 while any(p.poll() is None for p in children.values()):
  save(ROOT/'state.json',dict(status='RUNNING_LONGER_BLACKSCHOLES_MATCHED_PAIR',updated_utc=now(),
                            controller=ident(os.getpid()),children={m:dict(**ident(p.pid),returncode=p.poll()) for m,p in children.items()},
                            first_eight_existing_profiles='PASS_3PAIREDREPEATS_EACH',fpga_access=False))
  for p in children.values():
   if p.poll() is None:
    try:p.wait(timeout=10)
    except subprocess.TimeoutExpired:pass
 for f in logs:f.close()
 export_pair()
 result=read(ROOT/'comparison.json')
 save(ROOT/'state.json',dict(status=result['status'],updated_utc=now(),controller=ident(os.getpid()),fpga_access=False))

if __name__=='__main__':
 ap=argparse.ArgumentParser();ap.add_argument('--prepare',action='store_true');ap.add_argument('--run',choices=['native','ec']);ap.add_argument('--controller',action='store_true');a=ap.parse_args()
 if a.prepare:prepare()
 elif a.run:run(a.run)
 elif a.controller:controller()
 else:raise ValueError('action required')
