"""Read saved Native FPGA results only; exclude them from CPU comparison."""
from common import *
import csv,statistics
os.nice(19-os.getpriority(os.PRIO_PROCESS,0));os.sched_setaffinity(0,{200})
source=D/'paper-real-ec-data-r2-20261112/native-fpga-samples.json'
names={x['benchmark'] for x in read(ROOT/'queue.json')['items']};rows=[]
for r in read(source):
 if r['program'] not in names or r['input']!='simmedium' or r['group']!='ordinary_main':continue
 p=Path(r['result']);j=read(p)
 checks=dict(result_sha256=sha(p)==r['result_sha256'],roi_cycles=j['roi_cycles']==r['roi_cycles'],valid=j['valid']==r['valid']==True,actual_fpga=j['fpga_execution']==True,guest_power_down=j['guest_power_down_observed']==True,application_output=r['output_valid']==True,one_thread=r['threads']==1)
 rows.append(dict(benchmark=r['program'],repeat=r['repetition'],native_linux_fpga_cycles=r['roi_cycles'],all_saved_result_checks_passed=all(checks.values()),checks=checks,result=str(p),result_sha256=sha(p),source_record=r,excluded_from_current_cpu_pairs=True,exclusion='Historical Linux FPGA simmedium OS/input/ROI/ELF differs from current HTIF profile; ROI instructions were not collected; no EC counterpart in same contract'))
stats=[]
for name in sorted(names):
 rs=[r for r in rows if r['benchmark']==name];v=[r['native_linux_fpga_cycles'] for r in rs]
 stats.append(dict(benchmark=name,n=len(v),mean_cycles=statistics.mean(v),sample_stddev=statistics.stdev(v) if len(v)>1 else None,coefficient_of_variation=statistics.stdev(v)/statistics.mean(v) if len(v)>1 else None,result_checks_passed=all(r['all_saved_result_checks_passed'] for r in rs),included_in_current_pairs=False,source=str(source),source_sha256=sha(source)))
save(ROOT/'audit/historical-native-fpga-audit.json',dict(created_utc=now(),read_only=True,fpga_access=False,cad_access=False,source=str(source),source_sha256=sha(source),saved_runs_checked=len(rows),all_saved_result_checks_passed=all(r['all_saved_result_checks_passed'] for r in rows) and len(rows)==24,records=rows,statistics=stats,limitation='Checks saved result receipts and source-record output validity; no hardware access or new hardware/runtime validation; no historical/current pairing or extrapolation'))
with (ROOT/'paper/historical-native-fpga-excluded.csv').open('w',newline='') as f:
 w=csv.DictWriter(f,fieldnames=list(stats[0]));w.writeheader();w.writerows(stats)
print([(r['benchmark'],r['n'],r['result_checks_passed']) for r in stats])
assert len(rows)==24 and all(r['all_saved_result_checks_passed'] for r in rows)
