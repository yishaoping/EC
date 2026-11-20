"""Measure genuine local new-package to result-enqueue intervals."""
from common import *
import csv
os.nice(19-os.getpriority(os.PRIO_PROCESS,0));os.sched_setaffinity(0,{200})
parser_path=W/'candidates/full-gg-package-analysis-round37-v1-20261111/controller.py'
parser=module(parser_path,'retained_checker_event_parser')
source=W/'C4/chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala'
code=source.read_text();assert 'when (new_package)' in code and 'val package_result_fire = package_result_queue.io.enq.fire' in code
rows=[];tested=False
targets=[]
for item in read(ROOT/'queue.json')['items']:
 mf=read(ROOT/item['manifest'])
 for repeat in range(1,4):
  result,rp=selected_result(mf,'ec',repeat)
  targets.append((mf,result,rp))
for mf,result,rp in targets:
 if not result or not result.get('valid') or not (rp.parent/'complete.json').exists():continue
 out=rp.parent;prints=out/'rtl-prints-1';text=prints.read_text()
 fingerprint=dict(prints=sha(prints),result=sha(rp),parser=sha(parser_path),source=sha(source),script=sha(__file__))
 dest=out/'checker-local-metrics.json';cached=read(dest) if dest.exists() else {}
 if cached.get('fingerprint')==fingerprint:
  rows.append(cached['paper_row']);continue
 events,begins,ends=parser.parse_prints(text)
 if not tested:
  tests=parser.parser_negatives(text);save(ROOT/'audit/checker-parser-negative-validation.json',dict(created_utc=now(),actual_print_evidence=str(prints),actual_print_sha256=sha(prints),parser_sha256=sha(parser_path),cases=tests));tested=True
 intervals=[dict(benchmark=mf['benchmark'],hart=hart,seq=seq,begin_checker_cycle=begin,result_enqueue_checker_cycle=ends[(hart,seq)],local_checker_cycles=ends[(hart,seq)]-begin,boom_equivalent_duration_cycles=2*(ends[(hart,seq)]-begin)) for (hart,seq),begin in sorted(begins.items(),key=lambda x:x[1])]
 assert len(intervals)==result['strict_acceptance']['boom_pass_accepted']
 stats=parser.summarize([r['local_checker_cycles'] for r in intervals])
 csvpath=out/'checker-local-intervals.csv'
 with csvpath.open('w',newline='') as f:
  writer=csv.DictWriter(f,fieldnames=list(intervals[0]));writer.writeheader();writer.writerows(intervals)
 row=dict(benchmark=mf['benchmark'],profile=mf['profile'],repeat=result['repeat'],packages=len(intervals),local_mean_checker_cycles=stats['mean'],local_median_checker_cycles=stats['median'],local_p95_checker_cycles=stats['p95'],local_min_checker_cycles=stats['minimum'],local_max_checker_cycles=stats['maximum'],boom_equivalent_mean_duration_cycles=stats['mean']*2,checker_hz=100000000,boom_hz=200000000,evidence=str(dest))
 save(dest,dict(fingerprint=fingerprint,paper_row=row,interval_csv=str(csvpath),interval_csv_sha256=sha(csvpath),stats=stats,per_checker={str(h):parser.summarize([r['local_checker_cycles'] for r in intervals if r['hart']==h]) for h in sorted({r['hart'] for r in intervals})},endpoints=['new_package actual transition','package_result_queue.io.enq.fire with full_compare=1, status=PASS, cancelled=0'],limitations=['Local package interval includes service/stalls until result queue enqueue, not strict detection latency','Two BOOM cycles per checker cycle converts durations only; no absolute epoch alignment inferred','No same-package BOOM execution-done, architectural rollback begin/end or result transport latency inferred'],source=str(source),parser=str(parser_path)))
 rows.append(row);print(mf['benchmark'],len(intervals),'mean local checker cycles',stats['mean'],flush=True)
for filename,population in [('checker-local-metrics.csv',[r for r in rows if r['repeat']==1]),('checker-local-metrics-repeats.csv',rows)]:
 with (ROOT/'paper'/filename).open('w',newline='') as f:
  writer=csv.DictWriter(f,fieldnames=list(rows[0]) if rows else ['benchmark']);writer.writeheader();writer.writerows(population)
