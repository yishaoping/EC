"""Serialize evidence verification and paper exports, using per-run audit caches."""
from common import *
import fcntl,subprocess,sys
os.nice(19-os.getpriority(os.PRIO_PROCESS,0));os.sched_setaffinity(0,{200})
lock=(ROOT/'export.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX)
for script in ['progress.py','run_ledger.py','failure_summary.py','abi_audit.py','check_fluid_oracle.py','software_audit.py','audit_complete.py','svb_metrics.py','checker_metrics.py','summarize.py','reproduction_plan.py','verify_release.py','report_zh.py']:
 subprocess.run([sys.executable,str(ROOT/'scripts'/script)],cwd=ROOT,check=True)
save(ROOT/'paper/export-receipt.json',dict(created_utc=now(),queue_sha256=sha(ROOT/'queue.json'),summary_sha256=sha(ROOT/'paper/summary.json'),raw_audit_sha256=sha(ROOT/'audit/completed-raw-audit.json'),abi_audit_sha256=sha(ROOT/'audit/abi-audit.json')))
subprocess.run([sys.executable,str(ROOT/'scripts/snapshot.py')],cwd=ROOT,check=True)
