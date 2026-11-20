#!/usr/bin/python3
"""One-shot low-resource evidence export. Does not run Native or change results."""
import csv, hashlib, json, math, pathlib, statistics
P=pathlib.Path;D=P('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');DOC=P('/data1/gzh/EC/slowdown/final_opt4_freeze_20261106')
L=D/'paper-evidence-20261111';L.mkdir(exist_ok=True)
def sha(p):return hashlib.sha256(P(p).read_bytes()).hexdigest()
summary=json.loads((D/'results-summary.json').read_text());rows=[];problems=[]
for group in summary['formal_groups']:
 for config,values in group['configurations'].items():
  for sample in values['samples']:
   p=P(sample['result']);r=json.loads(p.read_text());c=json.loads((p.parent/'complete.json').read_text());i=r['identity']
   ok=(r['valid'] and r['formal'] and r['fpga_execution'] and not r['timedout'] and not r['issues'] and c['result_sha256']==sha(p) and c['identity_sha256']==r['identity_sha256'] and hashlib.sha256(json.dumps(i,sort_keys=True).encode()).hexdigest()==r['identity_sha256'])
   if not ok:problems.append(str(p));continue
   rows.append(dict(program=i['program'],configuration=i['configuration'],input=i['input'],repetition=i['repetition'],roi_cycles=r['roi_cycles'],host_wall_seconds=r['host_wall_seconds'],drain_cycles=r['drain_cycles'],board_bdf=i['board_bdf'],hardware_commit=i['hardware_commit'],elf_sha256=i['elf_sha256'],rootfs_sha256=i['rootfs_sha256'],input_profile_sha256=group['matched_identity_sha256'],result=str(p),result_sha256=sha(p),identity_sha256=r['identity_sha256']))
assert rows and not problems,problems
with (L/'native-fpga-valid-samples.csv').open('x') as f:
 w=csv.DictWriter(f,fieldnames=list(rows[0]));w.writeheader();w.writerows(rows)
(L/'native-fpga-valid-samples.json').write_text(json.dumps(dict(samples=rows,formal_result_complete_binding_rechecked=True,raw_log_hashes_reused_not_rehashed=True,failures_preserved=summary['failures'],duplicates_excluded=summary['duplicate_samples_excluded']),indent=2)+'\n')
historical=[]
for x in json.loads((DOC/'data/FINAL_RUNS.json').read_text()):
 historical.append({k:x.get(k) for k in ['workload','mode','hardware_commit','native_baseline_scope','roi_cycles','roi_instret','host_wall_seconds','manifest','simulator_sha256','elf_sha256']})
(L/'historical-rtl-evidence.json').write_text(json.dumps(dict(runs=historical,scope='Historical small bare-metal project inputs, not full Linux PARSEC and not FPGA measurements',native_limitation='Historical Native uses protection-disabled detection hardware with idle checker harts, not the requested single-BOOM no-checker Native; no mixed normalization with FPGA Native.',strict_latency='Only actual same-unit completion events permit latency; none inferred from allocation/package begin.',rollback_limitation='No full architectural rollback/restart completion established by ordinary PASS/lifetime data.'),indent=2)+'\n')
report=['# Reproducible evidence boundaries','','Validated FPGA Native samples: '+str(len(rows))+'; programs: '+str(len(set(r['program'] for r in rows)))+'/16. Opt4 FPGA samples: 0; paired FPGA comparisons: 0.','',
'Original result and atomic complete hashes were checked; raw logs remain at their original paths and are not overwritten. Hardware/software/input identity and historical BDF are retained.','',
'CPU RTL replay: cycleprecise-frozen-canneal-20261111 (new execution, await complete.json). It uses the sealed 8491167d simulator and identical project400 ELF/input; it is not Linux simmedium or FPGA performance.','',
'Space/time prototype: cycleprecise-route-a-r2-20261111 and cycleprecise-metasim-r4-20261111. Boundary read/reset/overlap tests do not constitute whole EC equivalence. FMR measures host cost, never target slowdown.','',
'Never report the historical protection-disabled detection-model Native as the strict single-BOOM baseline. A new true Native cycle-precise comparison needs the same target memory model/software/ROI; existing FPGA rows can only cross-check a matching metasim.','',
'The original architectural rollback behavior must be measured as implemented. No new recovery controller is part of this route; normal PASS, SVB invalidation and process exit do not establish architectural restore/restart.','']
(L/'README.md').write_text('\n'.join(report))
print(json.dumps(dict(valid_samples=len(rows),programs=len(set(r['program'] for r in rows)),opt4_fpga=0,paired_fpga=0,output=str(L))))
