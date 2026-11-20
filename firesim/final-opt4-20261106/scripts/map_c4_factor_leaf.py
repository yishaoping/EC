#!/usr/bin/env python3
from pathlib import Path
import json,os,subprocess,datetime
from board_batch import D,W,save,sha
from job_service import proc
out=D/'build-logs/C4-capacity-factor-leaf-20261110'
tcl=out/'map-factor-leaf.tcl'
state=D/'C4-capacity-factor-leaf-state.json'
st=dict(status='STARTING_CANDIDATE_ONLY',pid=os.getpid(),start_ticks=proc(os.getpid())['start_ticks'],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),started_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),fpga_access=False,formal_admission=False,dut_synthesis=False,candidate_sha256=sha(W/'candidates/capacity-exact-factor-20261110/GHBarrierLatencyStats-factor.v'),tcl_sha256=sha(tcl))
save(state,st)
with (out/'mapping.log').open('ab',buffering=0) as f:
 p=subprocess.Popen(['nice','-n','10','/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',str(out/'mapping.vivado.log'),'-source',str(tcl)],cwd=out,env={**os.environ,'LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'8'},stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
 st.update(status='RUNNING_CANDIDATE_ONLY',child_pid=p.pid,child_start_ticks=proc(p.pid)['start_ticks']);save(state,st)
 while p.poll() is None:
  try:p.wait(timeout=30)
  except subprocess.TimeoutExpired:pass
  st.update(updated_utc=datetime.datetime.now(datetime.timezone.utc).isoformat());save(state,st);os.fsync(f.fileno())
 st.update(status='MAPPED_CANDIDATE_ONLY' if p.returncode==0 else 'FAILED_WITH_EVIDENCE',returncode=p.returncode,ended_utc=datetime.datetime.now(datetime.timezone.utc).isoformat());save(state,st)
raise SystemExit(p.returncode)
