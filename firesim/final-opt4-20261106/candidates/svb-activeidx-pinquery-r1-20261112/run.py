import os,subprocess,json,time
from pathlib import Path
os.sched_setaffinity(0,{246,247})
C=Path(__file__).resolve().parent
O=Path("/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-activeidx-pinquery-r1-20261112")
start=time.monotonic()
with (O/"probe.log").open("xb",buffering=0) as f:
 p=subprocess.run(["/tools/Xilinx/Vivado/2021.1/bin/vivado","-mode","batch","-nojournal","-log",str(O/"vivado.log"),"-source",str(C/"probe.tcl")],cwd=O,stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,timeout=1800,env={**os.environ,"LD_LIBRARY_PATH":""})
s=(O/"probe.log").read_text(errors="replace")
good=p.returncode==0 and "EC_ACTIVEIDX_EXACT_PINQUERY_PASS nets=2" in s
(O/"result.json.tmp").write_text(json.dumps(dict(status="PASS_EXACT_ACTIVEIDX_PIN_QUERY" if good else "FAILED_WITH_EVIDENCE",returncode=p.returncode,fpga_access=False,target_changed=False,host_wall_seconds=time.monotonic()-start),indent=2)+"\n")
os.replace(O/"result.json.tmp",O/"result.json")
raise SystemExit(0 if good else 1)
