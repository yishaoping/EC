#!/usr/bin/python3
"""Independent read-only recovery of existing comparable PARSEC ROI pairs.

No CPU simulator, device, Vivado, or original campaign file is modified.
"""
from pathlib import Path
import csv,gzip,hashlib,json,math,os,re,shutil,statistics,time

OUT=Path(__file__).resolve().parent
ROOT=Path('/data1/gzh/EC/Experiment/parsec8-cpu-8491167d-20261112')
SNAP=ROOT/'batches/three-paired-repeats-accepted-20261112T102452Z'
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
BASE='8491167d84b6d9521b151a743673c1516926a1f8'
NAMES=['blackscholes','fluidanimate','bodytrack','freqmine','swaptions','ferret','dedup','streamcluster']
SCOPES={
 'blackscholes':'64 options, one bs_thread iteration',
 'fluidanimate':'AdvanceParticles phase, 64 particles, real captured state',
 'bodytrack':'ImageErrorEdge/Inside likelihood phase, real frame0 maps',
 'freqmine':'Official 3-transaction test, hot4 cache and quiet ROI',
 'swaptions':'Original worker, 16 trials',
 'ferret':'EMD distance matrix, 126 real region pairs; excludes flow solution',
 'dedup':'Official 6-byte test pipeline, 16MiB buffer, preloaded hash table',
 'streamcluster':'Original streamCluster, 16 points, FP contraction disabled'}

def read(p):return json.loads(Path(p).read_text())
def save(p,j):
 p=Path(p);tmp=p.with_name(p.name+'.tmp');tmp.write_text(json.dumps(j,indent=2,sort_keys=True)+'\n');tmp.replace(p)
def rows(p):return list(csv.DictReader(Path(p).open()))
def csvout(name,rr):
 with (OUT/name).open('x') as f:
  w=csv.DictWriter(f,fieldnames=list(dict.fromkeys(k for r in rr for k in r)));w.writeheader();w.writerows(rr)
cache={}
def sha(p):
 p=Path(p);st=p.stat();key=(str(p.resolve()),st.st_size,st.st_mtime_ns)
 if key not in cache:
  h=hashlib.sha256()
  with p.open('rb') as f:
   while b:=f.read(8*2**20):h.update(b)
  cache[key]=h.hexdigest()
 return cache[key]

def audit_run(path):
 p=Path(path).parent;r=read(path);binding=read(p/'binding.json');receipt=read(p/'stdout-integrity.json');done=read(p/'complete.json')
 assert r['functional_baseline']==binding['functional_baseline']==BASE
 assert r['valid'] and r['returncode']==0 and r['interrupt_policy_verified']
 assert r['roi_end_csr']-r['roi_start_csr']==r['roi_cycles']>0
 assert done['result_sha256']==sha(path) and done['binding_sha256']==sha(p/'binding.json')
 assert done['stdout_integrity_sha256']==sha(p/'stdout-integrity.json')
 assert sha(binding['args'][0])==binding['binary_sha256']
 assert sha(binding['elf']['path'])==binding['elf']['sha256']
 assert sha(binding['manifest'])==r['manifest_sha256']==binding['manifest_sha256']
 assert not binding['fpga_access']
 assert receipt['complete_stream_eof'] and sha(p/'host-complete.log.gz')==receipt['gzip_sha256']
 # Parse the complete compressed byte stream again, retaining exact markers.
 h=hashlib.sha256();size=0;pending=b'';markers=[]
 with gzip.open(p/'host-complete.log.gz','rb') as f:
  while chunk:=f.read(8*2**20):
   h.update(chunk);size+=len(chunk);data=pending+chunk;end=data.rfind(b'\n')
   if end>=0:
    markers.extend(x.decode().strip() for x in re.findall(rb'^\[(?:ROI|APP|IRQ|OUTPUT|END)\][^\r\n]*',data[:end+1],re.M))
    pending=data[end+1:]
   else:pending=data
 if pending and re.match(rb'^\[(?:ROI|APP|IRQ|OUTPUT|END)\]',pending):markers.append(pending.decode().strip())
 assert h.hexdigest()==receipt['raw_sha256']==r['raw_log_sha256'] and size==receipt['raw_bytes']
 tags={tag:[x for x in markers if x.startswith(tag)] for tag in ['[ROI]','[APP]','[IRQ]','[OUTPUT]','[END]']}
 assert all(len(tags[k])==1 for k in ['[ROI]','[APP]','[IRQ]','[END]'])
 roi=re.search(r'start=(\d+) stop=(\d+) cycles=(\d+)',tags['[ROI]'][0]);assert roi
 assert list(map(int,roi.groups()))==[r['roi_start_csr'],r['roi_end_csr'],r['roi_cycles']]
 app=re.search(r'cycles=(\d+) instret=(\d+)',tags['[APP]'][0]);assert app and list(map(int,app.groups()))==[r['roi_cycles'],r['roi_instructions']]
 irq=re.search(r'before=(\d+) after=(\d+) mie=(\d+)',tags['[IRQ]'][0]);assert irq and irq[1]==irq[2] and not(int(irq[3])&128)
 assert [s[len('[OUTPUT] '):] for s in tags['[OUTPUT]']]==r['output']
 assert tags['[END]']==['[END] hart=0 status=PASS']
 if r['mode']=='ec':
  strict=read(p/'strict-acceptance.json');assert strict['passed']
  assert strict['allocations']==strict['local_begins']==strict['full_compare_local_results']==strict['boom_pass_accepted']>0
  assert all(strict[k]==0 for k in ['pending','fail','cancel','duplicate','sample_errors'])
  for q,digest in strict['evidence'].items():assert sha(q)==digest,('strict evidence',q)
  events=[json.loads(s) for s in (p/'external-events.jsonl').read_text().splitlines()]
  accepted=[e for e in events if e['kind']=='BOOM_RESULT_ACCEPTED'];assert all(e['status']==0 for e in accepted)
  assert max(0,max(e['boom_csr_cycle'] for e in accepted)-r['roi_end_csr'])==r['drain_cycles']
 return dict(benchmark=r['benchmark'],mode=r['mode'],repeat=r['repeat'],profile=r['profile'],
             roi_cycles=r['roi_cycles'],roi_instructions=r['roi_instructions'],passed=True,
             result=str(path),result_sha256=sha(path),binding_sha256=sha(p/'binding.json'),
             compressed_raw_log=str(p/'host-complete.log.gz'),gzip_sha256=receipt['gzip_sha256'],
             raw_sha256=h.hexdigest(),raw_bytes=size,manifest_sha256=r['manifest_sha256'],markers=markers)

def main():
 assert not (OUT/'complete.json').exists(),'completed outputs immutable'
 os.nice(19-os.getpriority(os.PRIO_PROCESS,0));os.sched_setaffinity(0,{200})
 start=time.monotonic();snapshot=read(SNAP/'snapshot-receipt.json')
 for name,digest in snapshot['files_sha256'].items():assert sha(SNAP/name)==digest,('snapshot',name)
 platform=read(SNAP/'platform-audit.json');assert platform['passed'] and all(platform['checks'].values())
 assert platform['functional_baseline']==BASE
 for p,digest in platform['evidence'].items():assert sha(p)==digest,('platform',p)
 for mode,v in platform['models'].items():assert sha(v['path'])==v['sha256']
 assert read(SNAP/'abi-audit.json')['all_abi_matched']
 software=read(SNAP/'software-source-input-audit.json');assert software['passed']
 for f in software['files']:assert f['passed'] and sha(f['path'])==f['expected_sha256'],f['path']
 print('Snapshot436 artifacts, model/platform/ABI/software bindings PASS',flush=True)
 primary=rows(SNAP/'paper/parsec8-native-ec.csv');samples=rows(SNAP/'paper/samples.csv')
 assert len(primary)==8 and len(samples)==24
 audit=[];failures=[];first=[];allpairs=[]
 for name in NAMES:
  source=next(r for r in primary if r['benchmark']==name)
  for sample in [r for r in samples if r['benchmark']==name]:
   try:
    n=audit_run(sample['native_evidence']);e=audit_run(sample['ec_evidence'])
    assert n['roi_instructions']==e['roi_instructions'] and n['manifest_sha256']==e['manifest_sha256']
    nr=read(n['result']);er=read(e['result']);assert nr['output']==er['output'] and nr['profile']==er['profile']
    assert nr['mode']=='native' and er['mode']=='ec' and nr['repeat']==er['repeat']==int(sample['repeat'])
    assert sample['status']=='VALID_CPU_GG_PAIR' and math.isclose(float(sample['slowdown']),e['roi_cycles']/n['roi_cycles'],rel_tol=1e-14)
    pair=dict(benchmark=name,repeat=int(sample['repeat']),native_roi_cycles=n['roi_cycles'],ec_roi_cycles=e['roi_cycles'],
              slowdown=e['roi_cycles']/n['roi_cycles'],roi_instructions_each=n['roi_instructions'],
              method='CPU_GG_CYCLE_EXACT',functional_baseline=BASE,threads=1,scope=SCOPES[name],
              full_simmedium=False,full_application_claim=False,native_result=n['result'],ec_result=e['result'],
              native_result_sha256=n['result_sha256'],ec_result_sha256=e['result_sha256'])
    audit.extend([n,e]);allpairs.append(pair)
    if pair['repeat']==1:first.append(pair)
    save(OUT/'state.json',dict(status='VERIFYING_REUSED_RAW_LOGS',completed_pairs=len(allpairs),current_benchmark=name,elapsed_seconds=time.monotonic()-start))
    print(f'{name} r{pair["repeat"]}: actual logs/hash/ROI/ISA-platform/strict-checker PASS, slowdown={pair["slowdown"]:.9f}',flush=True)
   except Exception as ex:
    failures.append(dict(benchmark=name,repeat=sample['repeat'],error=repr(ex)));print('FAIL_SKIP',failures[-1],flush=True)
  print('NEXT_BENCHMARK',name,flush=True)
 historical=read(SNAP/'historical-native-fpga-audit.json');native=[]
 for rec in historical['records']:
  p=Path(rec['result']);r=read(p);done=read(p.parent/'complete.json')
  ok=sha(p)==rec['result_sha256']==done['result_sha256'] and r['valid'] and r['formal'] and r['fpga_execution'] and r['guest_power_down_observed']
  assert r['roi_cycles']==rec['native_linux_fpga_cycles'] and r['identity_sha256']==done['identity_sha256']
  issues=[]
  for q,digest in r['evidence'].items():
   if sha(q)!=digest:issues.append(q)
  ok=ok and not issues
  native.append(dict(benchmark=rec['benchmark'],repeat=rec['repeat'],roi_cycles=r['roi_cycles'],method='NATIVE_FPGA_LINUX_SIMMEDIUM',
                     saved_result_and_evidence_valid=bool(ok),reused_no_rerun=True,usable_as_current_cpu_denominator=False,
                     mismatch='Linux simmedium input/ELF/ROI/OS differs from selected HTIF ROI; instructions not collected',
                     source_bdf=r['identity']['board_bdf'],result=str(p),result_sha256=sha(p),evidence_issues=';'.join(issues)))
 assert len(native)==24
 csvout('first-round.csv',first);csvout('paired-repeats.csv',allpairs);csvout('historical-native-fpga.csv',native)
 csvout('cpu-raw-log-audit.csv',[{k:v for k,v in x.items() if k!='markers'} for x in audit])
 save(OUT/'cpu-raw-log-audit.json',audit)
 coverage=[]
 for name in NAMES:
  pp=[x for x in allpairs if x['benchmark']==name];nn=[x for x in native if x['benchmark']==name]
  coverage.append(dict(benchmark=name,native_fpga_valid_repeats=sum(x['saved_result_and_evidence_valid'] for x in nn),
                       native_fpga_comparable_to_current_cpu=False,cpu_pair_repeats=len(pp),
                       ec_cpu_current_status='PASS_REUSED_EXISTING_THREE_REPEATS' if len(pp)==3 else 'PARTIAL_REUSED_RESULTS',
                       full_ec_fpga_ready=False,scope=SCOPES[name],new_simulations_started=0))
 csvout('coverage-status.csv',coverage)
 # One thread; real ROI cycle ratios only. No modeled full-application estimates.
 import matplotlib
 matplotlib.use('Agg')
 import matplotlib.pyplot as plt
 labels={'blackscholes':'Blackscholes\n64 options ×1','fluidanimate':'Fluidanimate\nAdvanceParticles','bodytrack':'Bodytrack\nlikelihood phase','freqmine':'Freqmine\n3 transactions, hot4','swaptions':'Swaptions\n16 trials','ferret':'Ferret\nEMD matrix only','dedup':'Dedup\n6-byte input, 16MiB','streamcluster':'Streamcluster\n16 points'}
 colors=['#cb7748' if r['benchmark'] in ['fluidanimate','bodytrack','ferret'] else '#367da2' for r in first]
 with plt.rc_context({'font.family':'DejaVu Sans','font.size':9,'pdf.fonttype':42,'svg.fonttype':'none'}):
  fig,ax=plt.subplots(figsize=(11,4.5),layout='constrained');bars=ax.bar(range(len(first)),[r['slowdown'] for r in first],color=colors,width=.66)
  ax.axhline(1,color='#777777',ls='--',lw=.9);ax.bar_label(bars,labels=[f'{r["slowdown"]:.3f}×' for r in first],padding=4)
  ax.set_xticks(range(len(first)),[labels[r['benchmark']] for r in first]);ax.set(ylabel='EC / Native ROI target cycles',ylim=(0,3.25),title='PARSEC declared ROIs — cycle-exact CPU Golden Gate')
  ax.spines[['top','right']].set_visible(False);ax.grid(axis='y',alpha=.18);ax.set_axisbelow(True)
  from matplotlib.patches import Patch
  ax.legend(handles=[Patch(color='#367da2',label='Declared test / reduced workload'),Patch(color='#cb7748',label='Captured application phase')],loc='upper left',frameon=False,ncol=2)
  fig.text(.5,.005,'Each row has three matched repeats. Different declared scopes; full-application and FPGA slowdown are not established.',ha='center',fontsize=8)
  for ext in ['pdf','svg','png']:fig.savefig(OUT/('Performance.'+ext),dpi=180)
  plt.close(fig)
 summary=dict(status='PASS_REUSED_EXISTING_8_PROFILE_24_PAIRS' if len(first)==8 and len(allpairs)==24 and not failures and all(r['saved_result_and_evidence_valid'] for r in native) else 'PARTIAL_WITH_EVIDENCE',
              functional_baseline=BASE,first_round_pairs=len(first),matched_repeat_pairs=len(allpairs),raw_cpu_logs_verified=len(audit),
              native_fpga_runs_checked=len(native),new_simulations_started=0,fpga_access=False,source_campaign_preserved=True,
              raw_cpu_bytes_verified=sum(r['raw_bytes'] for r in audit),full_application_slowdown=None,full_ec_fpga_slowdown=None,
              failures=failures,elapsed_seconds=time.monotonic()-start,
              native_model=str(platform['models']['native']),ec_model=str(platform['models']['ec']),
              snapshot_receipt=str(SNAP/'snapshot-receipt.json'),snapshot_receipt_sha256=sha(SNAP/'snapshot-receipt.json'))
 save(OUT/'summary.json',summary)
 shutil.copy2(SNAP/'paper/methods.md',OUT/'original-methods.md')
 shutil.copy2(SNAP/'paper/platform-parameters.csv',OUT/'platform-parameters.csv')
 shutil.copy2(SNAP/'paper/repeatability.csv',OUT/'repeatability.csv')
 text='''# 八项 PARSEC 性能数据复核与复用

已实际复核此前独立 CPU 会话完成的八项首轮及三轮重复，共24对/48份真实周期精确 Golden Gate 日志。历史 Native FPGA 八项各三轮也已复核，保留其数据；当前CPU测量与历史Linux simmedium workload/ROI/OS不同，分母全部采用同环境Native CPU，不跨平台拼接。

本目录只读核查原会话，没有重启、修改原任务或重复已完成实验。首轮原始CSV为first-round.csv，所有重复为paired-repeats.csv，论文图为Performance.pdf/svg/png。历史FPGA为historical-native-fpga.csv，资格状态为coverage-status.csv。完整原始日志的路径、compressed/raw SHA256、原始字节数及完成收据见cpu-raw-log-audit.json/csv，原数据保持原目录。436项快照文件、源码/模型/ABI/平台参数/输入、48份完整原始日志重新解压校验，EC包完整通过并排空才接受配对。

| 项目 | Native ROI cycles | EC ROI cycles | Slowdown | 测量范围 |
|---|---:|---:|---:|---|
'''
 for r in first:text+=f'| {r["benchmark"]} | {r["native_roi_cycles"]} | {r["ec_roi_cycles"]} | {r["slowdown"]:.6f}× | {r["scope"]} |\n'
 text+='''
这些是声明输入/阶段的真实target-cycle比值；不是模型估算，也不是整应用、完整simmedium或FPGA Slowdown。Fluidanimate、Bodytrack和Ferret只测所列阶段，其他输入也有缩小/改配置，不能外推完整应用。三轮确定性模拟的重复一致性不等于不同输入/布局的统计不确定度。Native/EC共享应用对象、ISA、处理器/内存配置、单线程和ROI口径；boot ELF/链接地址及初始cache布局不同这一既有限制保留。所有旧失败/超时/取消的profile保持排除，未被成功小profile“修复”。

完整EC FPGA仍无认证可运行映像；SVB-only数据完全不进入此图。当前八项选定profile三轮均完成，没有为重复同一测量启动新模拟器。独立CPU会话原调度器已以COMPLETE_THREE_ACCEPTED_PAIRED_REPEATS自然结束。原测量方法完整保留在original-methods.md。更大/完整输入仍须另立匹配的Native/EC测量，不能用本表推算。
'''
 (OUT/'README.md').write_text(text)
 manifest={str(p.relative_to(OUT)):sha(p) for p in OUT.rglob('*') if p.is_file() and p.name not in ['complete.json','state.json','audit.log']}
 save(OUT/'complete.json',dict(status=summary['status'],files_sha256=manifest,summary_sha256=sha(OUT/'summary.json')))
 save(OUT/'state.json',dict(status=summary['status'],verified_cpu_logs=len(audit),elapsed_seconds=time.monotonic()-start))
 print(json.dumps(summary,indent=2),flush=True)

if __name__=='__main__':main()
