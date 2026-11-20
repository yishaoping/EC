#!/usr/bin/env python3
"""Resolve shell IP separately to locate the failed top-link black box."""
from pathlib import Path
import datetime,json,os,subprocess
from board_batch import W,D,save,sha
from job_service import proc

O=D/'build-logs/C4-capacity-20261110/shell-link-diagnostic'
O.mkdir(exist_ok=True)
s=json.loads((D/'C4-dcp-cad-state.json').read_text())
assert s['status']=='FAILED_WITH_EVIDENCE'
assert proc(s['pid']) is None
top=Path(s['output_dir'])/'vivado_proj/firesim.runs/synth_1/design_1_wrapper.dcp'
lines=['set_param general.maxThreads 8', f'open_checkpoint {{{top}}}']
bindings=[]
for d in s['reused_checkpoints']:
    p=Path(d['stable_snapshot'])
    if p.stem=='design_1_firesim_wrapper_0_0':continue
    assert sha(p)==d['sha256']
    lines += [f'set target [get_cells -hier -quiet -filter {{REF_NAME == {p.stem}}}]',
              f'if {{[llength $target] != 1}} {{error "shell cell match {p.stem}: $target"}}',
              f'read_checkpoint -cell $target {{{p}}}']
    bindings.append(dict(path=str(p),sha256=d['sha256']))
lines += [f'set f [open {{{O/"black-boxes.txt"}}} w]',
          'foreach c [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}] {',
          'puts $f "CELL=$c REF_NAME=[get_property REF_NAME $c] IS_PRIMITIVE=[get_property IS_PRIMITIVE $c]"',
          'report_property -file {'+str(O/'black-box-properties.rpt')+'} -append $c',
          '}', 'close $f',
          f'write_checkpoint -force {{{O/"shell-linked.dcp"}}}',
          'puts "EC_SHELL_LINK_DIAGNOSTIC_COMPLETE_NOT_FORMAL_BUILD"','exit 0']
tcl=O/'diagnose.tcl';tcl.write_text('\n'.join(lines)+'\n')
state=D/'C4-shell-link-diagnostic-state.json'
st=dict(status='RUNNING',pid=os.getpid(),start_ticks=proc(os.getpid())['start_ticks'],host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),started_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),bindings=bindings,top_dcp=str(top),top_dcp_sha256=sha(top),tcl_sha256=sha(tcl),dut_resynthesis=False,fpga_access=False,formal_admission=False)
save(state,st)
with (O/'diagnose.log').open('ab',buffering=0) as f:
    p=subprocess.Popen(['nice','-n','10','/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',str(O/'vivado.log'),'-source',str(tcl)],cwd=O,env={**os.environ,'LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'8'},stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
    st.update(child_pid=p.pid,child_start_ticks=proc(p.pid)['start_ticks']);save(state,st)
    while p.poll() is None:
        try:p.wait(timeout=30)
        except subprocess.TimeoutExpired:pass
        st.update(updated_utc=datetime.datetime.now(datetime.timezone.utc).isoformat());save(state,st);os.fsync(f.fileno())
    st.update(status='COMPLETE_DIAGNOSTIC_ONLY' if p.returncode==0 else 'FAILED_WITH_EVIDENCE',returncode=p.returncode,ended_utc=datetime.datetime.now(datetime.timezone.utc).isoformat());save(state,st)
raise SystemExit(p.returncode)
