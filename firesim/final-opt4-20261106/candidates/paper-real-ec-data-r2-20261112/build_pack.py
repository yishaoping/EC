#!/usr/bin/python3
"""Small-file verified exports. No RTL/model execution or FPGA operations."""
from pathlib import Path
import collections,csv,datetime,hashlib,importlib.util,json,math,os,re,shutil,statistics
os.environ['MPLCONFIGDIR']='/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/matplotlib-cache'
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
A=D/'overnight-ec-evidence-audit-r4-20261112';O=D/'paper-real-ec-data-r2-20261112';BASE='8491167d84b6d9521b151a743673c1516926a1f8'
INPUTS={}
def read(p):return json.loads(Path(p).read_text())
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def bind(p,expected=None):
 p=Path(p);h=sha(p)
 if expected is not None:assert h==expected,('HASH',str(p))
 INPUTS[str(p)]=h;return h
def save(p,x):
 with Path(p).open('x') as f:json.dump(x,f,sort_keys=True,indent=2);f.write('\n')
def csvout(name,rows):
 with (O/name).open('x',newline='') as f:
  out=csv.DictWriter(f,fieldnames=list(dict.fromkeys(k for r in rows for k in r)));out.writeheader();out.writerows(rows)
def stats(v):
 v=sorted(v);return dict(n=len(v),sum=sum(v),mean=statistics.mean(v),sample_sd=statistics.stdev(v) if len(v)>1 else None,
  cv=statistics.stdev(v)/statistics.mean(v) if len(v)>1 else None,min=v[0],median=statistics.median(v),p95=v[math.ceil(.95*len(v))-1],p99=v[math.ceil(.99*len(v))-1],max=v[-1])
def figsave(fig,name):
 for ext in ['pdf','svg']:fig.savefig(O/(name+'.'+ext),bbox_inches='tight')
 plt.close(fig)
def main():
 assert not O.exists(),'VERSION_IMMUTABLE_CREATE_ANOTHER';O.mkdir()
 os.sched_setaffinity(0,{208});os.nice(10)
 comp=read(A/'complete.json');bind(A/'complete.json');bind(A/'summary.json',comp['summary_sha256']);bind(A/'evidence-verification.json',comp['evidence_verification_sha256'])
 audited=read(A/'evidence-verification.json');summary=read(A/'summary.json');assert summary['functional_baseline']==BASE
 delivery=read(A/'delivery-manifest.json');bind(A/'delivery-manifest.json')
 for p,h in delivery['files'].items():bind(p,h)
 nativefile=D/'paper-evidence-20261111/native-fpga-valid-samples.json';bind(nativefile);native=read(nativefile);rows=[];checks=[];seen=set();versions={}
 for sample in native['samples']:
  p=Path(sample['result']);r=read(p);c=read(p.parent/'complete.json');i=r['identity'];bind(p,sample['result_sha256']);bind(p.parent/'complete.json')
  assert r['valid'] and r['formal'] and r['fpga_execution'] and not r['timedout'] and r['driver_returncode']==0 and not r['issues']
  assert c['result_sha256']==sha(p) and c['identity_sha256']==r['identity_sha256']==sample['identity_sha256']==hashlib.sha256(json.dumps(i,sort_keys=True).encode()).hexdigest()
  assert i['configuration']=='Native' and i['input']=='simmedium' and i['threads']==1 and i['warmups']==0 and i['target_boom_hz']==200000000
  assert r['fased_readback']==dict(readLatency=30,readMaxReqs=4,relaxFunctionalModel=0,writeLatency=30,writeMaxReqs=4)==i['memory_model']['settings']
  uart=p.parent/'uart.log';bind(uart,r['evidence'][str(uart)]);text=uart.read_text(errors='replace')
  markers=[x for x in text.splitlines() if x.startswith('EC_SAMPLE_GUEST_DONE ')]
  assert len(markers)==1 and ('run_id='+i['run_id']+' ') in markers[0] and 'output_valid=1 application_exit=0' in markers[0]
  assert re.search(r'^EC_COMMAND_EXIT=0$',text,re.M)
  assert not r['raw']['protocol_issues'] and r['raw']['partial_tail_bytes']==0
  raw=p.parent/'roi-raw.jsonl';bind(raw,r['evidence'][str(raw)])
  key=(i['program'],i['repetition']);assert key not in seen;seen.add(key)
  version=(i['elf_sha256'],i['rootfs_sha256'],i['hardware_source_id'],i['bitstream_sha256'],sample['input_profile_sha256'])
  if i['program'] in versions:assert versions[i['program']]==version,'MIXED_VERSION_REPETITIONS'
  versions[i['program']]=version
  group='network_appendix' if i['program'].startswith('net') else 'ordinary_main'
  rows.append(dict(program=i['program'],group=group,input='simmedium',repetition=i['repetition'],roi_cycles=r['roi_cycles'],
   roi_target_seconds=r['roi_cycles']/200000000,host_wall_seconds=r['host_wall_seconds'],host_time_scope='whole guest including boot; not ROI host time',
   roi_instructions='not collected',drain_cycles=r['drain_cycles'],output_valid=True,application_exit=0,valid=True,
   data_kind='NATIVE_FPGA_LINUX',threads=1,warmups=0,target_boom_hz=200000000,board_bdf=i['board_bdf'],
   hardware_source_id=i['hardware_source_id'],hardware_commit=i['hardware_commit'],bitstream_sha256=i['bitstream_sha256'],
   elf_sha256=i['elf_sha256'],rootfs_sha256=i['rootfs_sha256'],input_profile_sha256=sample['input_profile_sha256'],result=str(p),result_sha256=sha(p)))
  checks.append(dict(result=str(p),result_complete_identity_binding=True,uart_and_roi_hash_recomputed=True,output_and_exit_independently_checked=True,raw_host_log_hash_reused=True))
 assert len(rows)==45 and sum(r['group']=='ordinary_main' for r in rows)==39
 csvout('native-fpga-samples.csv',rows);save(O/'native-fpga-samples.json',rows);save(O/'native-small-file-verification.json',checks)
 ag=[]
 for program in sorted(versions):
  sr=[r for r in rows if r['program']==program];assert sorted(r['repetition'] for r in sr)==[1,2,3]
  a=dict(program=program,group=sr[0]['group'],input='simmedium',**{'roi_'+k:v for k,v in stats([r['roi_cycles'] for r in sr]).items()},**{'host_'+k:v for k,v in stats([r['host_wall_seconds'] for r in sr]).items()});ag.append(a)
 csvout('native-fpga-statistics.csv',ag)
 ordinary=[a for a in ag if a['group']=='ordinary_main'];fig,ax=plt.subplots(figsize=(9,4.3));ax.bar([x['program'] for x in ordinary],[x['roi_mean']/1e9 for x in ordinary],color='#346D8C',yerr=[x['roi_sample_sd']/1e9 for x in ordinary],capsize=2)
 ax.set(ylabel='ROI target cycles (billions)',title='Native Linux PARSEC on FPGA: 13 programs, n=3 each');ax.tick_params(axis='x',rotation=45);figsave(fig,'native-fpga-roi-cycles')
 ec=[]
 for row in summary['workloads']:
  r=dict(row);r['input_profile']='canneal_project400: 1 thread, 400 swaps, starttemp 300, 100.nets, 2 temperature steps' if r['benchmark']=='canneal' else 'blackscholes_project64: 64 options, 100 rounds, 1 thread'
  r['provenance_note']='Corrected human label only; original audit mislabels Canneal project64. ELF hashes and all numeric values unchanged.' if r['benchmark']=='canneal' else ''
  assert r['faults']==0 and r['pending_at_observation_end']==0;ec.append(r)
 save(O/'ec-full-gg-metasim.json',ec);csvout('ec-full-gg-metasim.csv',ec)
 # Existing fully audited finite trace, not a new hardware replay.
 shutil.copy2(A/'svb-lifetimes.csv',O/'svb-lifetimes.csv');lifetimes=list(csv.DictReader((O/'svb-lifetimes.csv').open()));assert len(lifetimes)==659
 svb=[];fig,axes=plt.subplots(1,3,figsize=(11,3.4))
 labels={'capture_to_promotion':'Capture to promotion','promotion_to_ack':'Promotion to ACK','capture_to_ack':'Capture to ACK'}
 for axis,(key,label) in zip(axes,labels.items()):
  vals=sorted(int(x[key]) for x in lifetimes);a=dict(metric=key,**stats(vals),units='fastest BOOM target cycles',bucket_precision_cycles=1,quantiles='nearest rank',data_kind='CPU_FULL_GG_TRACE',ack='ownership/writeback completion; not checker completion');svb.append(a)
  axis.step(vals,[(i+1)/len(vals) for i in range(len(vals))],where='post');axis.set(title=label,xlabel='Target cycles',ylabel='CDF',ylim=(0,1.01));axis.grid(alpha=.2)
 fig.suptitle('659 complete SVB lifetimes from Canneal CPU GoldenGate trace');fig.tight_layout();figsave(fig,'svb-lifetime-cdfs');csvout('svb-latency-statistics.csv',svb)
 save(O/'svb-observed-rates.json',summary['svb_observed_rates']);save(O/'svb-replay-results.json',summary['replays'])
 parser=W/'candidates/full-gg-package-analysis-round37-v1-20261111/controller.py';bind(parser)
 spec=importlib.util.spec_from_file_location('local_print_parser',parser);m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
 local=[];ls=[];hist=[];fig,ax=plt.subplots(figsize=(6,3.6))
 for r in ec:
  src=Path(r['raw_prints']).with_name('rtl-prints-1');bind(src,read(A/(r['benchmark']+'-strict-join.json'))['evidence'][str(src)]);events,begins,results=m.parse_prints(src.read_text());v=[]
  for (hart,seq),begin in sorted(begins.items()):
   latency=results[(hart,seq)]-begin;v.append(latency);local.append(dict(benchmark=r['benchmark'],hart=hart,package_sequence=seq,checker_begin_cycle=begin,checker_result_enqueue_cycle=results[(hart,seq)],local_interval_cycles=latency,timebase='checker local target cycles (100 MHz)',event_definition='CHECKER_NEW_PACKAGE to full PASS LOCAL_RESULT_QUEUE_ENQUEUE',strict_boom_done_to_checker_done=False))
  assert len(v)==r['boom_accepted_pass'];st=dict(benchmark=r['benchmark'],**stats(v),units='checker local target cycles',bucket_precision_cycles=1,quantiles='nearest rank',strict_requested_latency=False);ls.append(st)
  hist.extend(dict(benchmark=r['benchmark'],checker_cycles=k,count=n) for k,n in sorted(collections.Counter(v).items()))
  v=sorted(v);ax.step(v,[(i+1)/len(v) for i in range(len(v))],where='post',label=r['benchmark'])
 ax.set(title='CPU GoldenGate: checker local package interval',xlabel='Checker target cycles (100 MHz)',ylabel='CDF',ylim=(0,1.01));ax.legend();ax.grid(alpha=.2);figsave(fig,'checker-local-package-interval-cdf')
 csvout('checker-local-package-intervals.csv',local);csvout('checker-local-package-statistics.csv',ls);csvout('checker-local-package-histogram.csv',hist)
 allprograms=['blackscholes','bodytrack','canneal','dedup','facesim','ferret','fluidanimate','freqmine','raytrace','streamcluster','swaptions','vips','x264','netdedup','netferret','netstreamcluster']
 csvout('coverage-and-comparability.csv',[dict(program=x,native_linux_fpga_valid_rounds=3 if x in versions else 0,opt4_linux_fpga_valid_rounds=0,paired_linux_fpga_rounds=0,cpu_ec_baremetal_profile=next((e['input_profile'] for e in ec if e['benchmark']==x),'not measured'),pairable_with_native_linux=False,reason='software/input/OS/ROI differ; do not divide these cycles') for x in allprograms])
 missing=[dict(metric='same package BOOM execution done to Rocket compare complete',status='NOT_MEASURED',reason='Captured events lack true same-package last retirement completion; producer seal is a later quiescence boundary'),dict(metric='Rocket RESULT enqueue to BOOM acceptance',status='NOT_COMPUTED',reason='No explicitly observed cross-domain reset/epoch/phase anchor in current trace; cannot subtract unrelated counters'),dict(metric='architectural rollback/restart',status='NOT_VERIFIED',reason='No new function added; no architectural recovery evidence in these fault-free runs'),dict(metric='full Opt4 Linux FPGA slowdown',status='NOT_AVAILABLE',reason='No complete Opt4 FPGA sample; Native Linux and CPU baremetal not pairable')]
 save(O/'missing-metrics.json',missing);save(O/'preserved-failures.json',dict(failures=native['failures_preserved'],duplicates=native['duplicates_excluded']))
 results=dict(status='PASS_PAPER_EXPORT_AUTHENTICATED_SMALL_FILES_AND_PREVIOUS_LARGE_LOG_AUDIT',functional_baseline=BASE,
  native_fpga_valid_samples=45,native_ordinary_samples=39,native_network_samples=6,native_programs_with_3_rounds=15,native_missing=['netferret'],
  ec_cpu_metasim_workloads=2,svb_complete_lifetimes=659,checker_local_interval_statistics=ls,fpga_access=False,
  new_fpga_results_created=False,strict_latency_measured=False,architectural_recovery_verified=False,matched_source_native_cpu_status='separate running r3 build; independent consumer will extend this immutable package',completed_utc=datetime.datetime.now(datetime.timezone.utc).isoformat())
 save(O/'summary.json',results)
 (O/'README.md').write_text('''# Audited EC experiment exports\n\nNative FPGA: 45 valid formal samples, 15/16 programs with three rounds. The ordinary 13-program set contributes 39 samples; Netdedup/Netstreamcluster contribute six appendix samples. Netferret is missing. Historical e2 BDFs remain historical evidence; this export touches no board. Native hardware commit was not recorded; source ID and bitstream hash are retained rather than inventing a commit.\n\nEC full-system CPU GoldenGate metasim: Canneal project400 and Blackscholes project64, frozen 8491167d. The original audit mislabeled Canneal project64 in prose; the corrected label here preserves the exact ELF, input, cycles and evidence. Both programs passed output checks, strict allocation/begin/full-compare/result/BOOM-accept joins, and drained pending packages to zero. These are CPU metasim data, not full Opt4 FPGA data.\n\nSVB: 659 complete finite-trace lifetimes from Canneal. ACK denotes ownership/writeback completion, not checker completion. CDFs use original one-cycle samples, nearest-rank percentiles. Observed rates include offered-workload idle/backpressure and are not saturated capacity. CPU replay wall time is a host execution rate.\n\nChecker local package intervals are BEGIN to validated full PASS local RESULT enqueue at 100 MHz. They include waiting within that interval; they are not the requested BOOM-execution-complete to checker-complete latency. No strict cross-domain latency is invented.\n\nNative Linux simmedium and EC baremetal project400/project64 are deliberately not paired. There is no full Opt4 FPGA slowdown in this package. The separate matching clean-Native CPU experiment preserves algorithm/input sources and ROI scope but uses a different startup ELF/link layout; its consumer must validate complete/hash/FASED/BOOM/cache/software and instruction counts before producing a source-matched CPU ratio.\n\nFigures: PDF/SVG from matplotlib. Native error bars are sample standard deviation over n=3. Host wall time includes guest boot and is not architectural slowdown. Raw large host-log hashes are inherited from the completed independent audit; small result/complete/identity, UART and raw ROI hashes were independently rechecked here. Original failures remain linked in preserved-failures.json.\n''')
 save(O/'input-manifest.json',INPUTS);save(O/'delivery-manifest.json',{str(p):sha(p) for p in sorted(O.iterdir()) if p.is_file()})
 save(O/'complete.json',dict(summary_sha256=sha(O/'summary.json'),input_manifest_sha256=sha(O/'input-manifest.json'),delivery_manifest_sha256=sha(O/'delivery-manifest.json'),builder_sha256=sha(__file__),fpga_access=False));print(json.dumps(results,indent=2))
if __name__=='__main__':main()
