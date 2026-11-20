#!/usr/bin/python3
"""Reuse freshly reparsed CPU logs; resolve exact immutable Native snapshots."""
from pathlib import Path
import csv,hashlib,json,math,shutil,statistics,time

OUT=Path(__file__).resolve().parent
OLD=OUT.parent/'parsec8-performance-audit-20261112'
ROOT=OUT.parent/'parsec8-cpu-8491167d-20261112'
SNAP=ROOT/'batches/three-paired-repeats-accepted-20261112T102452Z'
def read(p):return json.loads(Path(p).read_text())
def sha(p):
 h=hashlib.sha256()
 with Path(p).open('rb') as f:
  while b:=f.read(8*2**20):h.update(b)
 return h.hexdigest()
def save(p,j):Path(p).write_text(json.dumps(j,indent=2,sort_keys=True)+'\n')
def rows(p):return list(csv.DictReader(Path(p).open()))
def csvout(name,rr):
 with (OUT/name).open('x') as f:
  w=csv.DictWriter(f,fieldnames=list(dict.fromkeys(k for r in rr for k in r)));w.writeheader();w.writerows(rr)

def main():
 assert not (OUT/'complete.json').exists()
 prior=read(OLD/'complete.json')
 for name,h in prior['files_sha256'].items():assert sha(OLD/name)==h,name
 audited=read(OLD/'cpu-raw-log-audit.json');assert len(audited)==48 and all(x['passed'] for x in audited)
 for r in audited:
  p=Path(r['result']);binding=read(p.with_name('binding.json'));done=read(p.with_name('complete.json'))
  assert sha(p)==r['result_sha256']==done['result_sha256']
  assert sha(p.with_name('binding.json'))==r['binding_sha256']==done['binding_sha256']
  assert sha(r['compressed_raw_log'])==r['gzip_sha256']
  assert sha(binding['elf']['path'])==binding['elf']['sha256']
  assert sha(binding['manifest'])==binding['manifest_sha256']==r['manifest_sha256']
 print('48 full raw-stream reparse receipts/current gzip/result/ELF/binding hashes PASS',flush=True)
 platform=read(SNAP/'platform-audit.json');assert platform['passed'] and all(platform['checks'].values())
 for m in platform['models'].values():assert sha(m['path'])==m['sha256']
 native=rows(OLD/'historical-native-fpga.csv');metadata=[]
 for rec in native:
  p=Path(rec['result']);r=read(p);done=read(p.with_name('complete.json'))
  assert sha(p)==rec['result_sha256']==done['result_sha256']
  assert r['valid'] and r['formal'] and r['fpga_execution'] and r['guest_power_down_observed']
  assert r['identity_sha256']==done['identity_sha256']
  changes=[]
  for q,h in r['evidence'].items():
   if sha(q)==h:continue
   assert Path(q)==p.with_name('state.json'),'unexpected immutable evidence change'
   original=p.with_name('snapshot.json');assert sha(original)==h==r['evidence'][str(original)]
   a=read(original);b=read(q)
   assert b['status']=='COMPLETE' and a['status']=='RUNNING'
   assert b['identity_sha256']==a['identity_sha256']==r['identity_sha256']
   assert {k:v for k,v in a.items() if k!='status'}=={k:v for k,v in b.items() if k not in ['status','ended_utc','issues']}
   assert b.get('issues',[])==[]
   evidence=dict(state_path=q,current_state_sha256=sha(q),bound_snapshot=str(original),bound_snapshot_sha256=sha(original),
                 changed_fields=['status','ended_utc','issues'],assessment='Mutable runner progress changed RUNNING->COMPLETE after result capture. Exact originally bound snapshot and all original data/log/ROI hashes match.')
   metadata.append(evidence);changes.append(q)
  rec['saved_result_and_evidence_valid']=True
  rec['evidence_issues']=''
  rec['mutable_completion_metadata_changes']=';'.join(changes)
 assert len(metadata)==3 and all(x['benchmark']=='blackscholes' for x in native if x['mutable_completion_metadata_changes'])
 save(OUT/'native-mutable-metadata-resolution.json',dict(records=metadata,raw_data_changes=False,result_changes=False))
 csvout('historical-native-fpga.csv',native)
 for n in ['first-round.csv','paired-repeats.csv','cpu-raw-log-audit.csv','cpu-raw-log-audit.json','original-methods.md','platform-parameters.csv','repeatability.csv']:
  shutil.copy2(OLD/n,OUT/n)
 coverage=rows(OLD/'coverage-status.csv')
 for r in coverage:r['native_fpga_valid_repeats']=sum(x['benchmark']==r['benchmark'] and x['saved_result_and_evidence_valid'] for x in native)
 csvout('coverage-status.csv',coverage)
 first=rows(OUT/'first-round.csv');pairs=rows(OUT/'paired-repeats.csv')
 assert len(first)==8 and len(pairs)==24
 for r in pairs:assert math.isclose(float(r['slowdown']),int(r['ec_roi_cycles'])/int(r['native_roi_cycles']),rel_tol=1e-14)
 import matplotlib
 matplotlib.use('Agg')
 import matplotlib.pyplot as plt
 from matplotlib.patches import Patch
 labels={'blackscholes':'Blackscholes\n64 options ×1','fluidanimate':'Fluidanimate\nAdvanceParticles','bodytrack':'Bodytrack\nlikelihood phase','freqmine':'Freqmine\n3 transactions, hot4','swaptions':'Swaptions\n16 trials','ferret':'Ferret\nEMD matrix only','dedup':'Dedup\n6-byte input, 16MiB','streamcluster':'Streamcluster\n16 points'}
 colors=['#cb7748' if r['benchmark'] in ['fluidanimate','bodytrack','ferret'] else '#367da2' for r in first]
 with plt.rc_context({'font.family':'DejaVu Sans','font.size':9,'pdf.fonttype':42,'svg.fonttype':'none'}):
  fig,ax=plt.subplots(figsize=(11,4.8));fig.subplots_adjust(bottom=.23,top=.88,left=.065,right=.99)
  bars=ax.bar(range(8),[float(r['slowdown']) for r in first],color=colors,width=.66)
  ax.axhline(1,color='#777777',ls='--',lw=.9);ax.bar_label(bars,labels=[f'{float(r["slowdown"]):.3f}×' for r in first],padding=4)
  ax.set_xticks(range(8),[labels[r['benchmark']] for r in first]);ax.set(ylabel='EC / Native ROI target cycles',ylim=(0,3.25),title='PARSEC declared ROIs — cycle-exact CPU Golden Gate')
  ax.spines[['top','right']].set_visible(False);ax.grid(axis='y',alpha=.18);ax.set_axisbelow(True)
  ax.legend(handles=[Patch(color='#367da2',label='Declared test / reduced workload'),Patch(color='#cb7748',label='Captured application phase')],loc='upper left',frameon=False,ncol=2)
  fig.text(.5,.035,'Three matched repeats per declared ROI. Full-application and FPGA slowdown are not established.',ha='center',fontsize=8)
  for ext in ['pdf','svg','png']:fig.savefig(OUT/('Performance.'+ext),dpi=180)
  plt.close(fig)
 summary=read(OLD/'summary.json');summary.update(status='PASS_REUSED_EXISTING_8_PROFILE_24_PAIRS',native_fpga_valid_runs=24,
          previous_raw_reparse_receipt=str(OLD/'complete.json'),previous_raw_reparse_receipt_sha256=sha(OLD/'complete.json'),
          original_audit_status_explained='All CPU pairs passed. Earlier all-evidence status was partial solely because 3 mutable Blackscholes state.json files advanced to COMPLETE. Their exactly bound snapshot and every immutable data hash pass; resolution explicitly recorded.',
          native_model=platform['models']['native'],ec_model=platform['models']['ec'])
 save(OUT/'summary.json',summary)
 text=(OLD/'README.md').read_text()
 text+='\n历史Blackscholes三轮的state.json在收据保存后正常从RUNNING更新为COMPLETE；与收据绑定的snapshot.json仍精确一致，原始UART/ROI/manifest/result均未变化，详见native-mutable-metadata-resolution.json。原r1严格审计的partial状态与原输出保留，本r2复用同轮48份完整原始日志解压校验收据，不再重复12.7GB解压。Performance图已调整说明位置，避免遮挡横轴标签。\n\n复核：`python3 verify.py`，不启动仿真或访问FPGA。\n'
 (OUT/'README.md').write_text(text)
 shutil.copy2(OLD/'verify.py',OUT/'verify.py')
 save(OUT/'complete.json',dict(status=summary['status'],files_sha256={str(p.relative_to(OUT)):sha(p) for p in OUT.rglob('*') if p.is_file() and p.name!='complete.json'},summary_sha256=sha(OUT/'summary.json')))
 print(summary['status'],flush=True)

if __name__=='__main__':main()
