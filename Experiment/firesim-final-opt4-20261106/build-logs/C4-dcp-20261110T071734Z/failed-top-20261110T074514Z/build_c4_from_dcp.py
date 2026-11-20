#!/usr/bin/env python3
"""Independent DCP reuse experiment. Never writes the live CAD tree or FPGA.

Use original generated top/implementation scripts and all sibling checkpoints.
Only simulation exports are omitted. The original Vivado process is untouched.
"""
import datetime as dt
import fcntl
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import signal
import subprocess
import sys
import time
import zipfile

from board_batch import W, D, save, sha
from job_service import proc
sys.path.insert(0, '/data1/gzh/EC/firesim/dac2026/scripts')
from build_minimal import inventory

STATE = D/'C4-dcp-cad-state.json'
PART = 'xcu280-fsvh2892-2L-e'
SID = 'c9f51d3a94aac7783c750682162cd25e9d1460b04974bde9b7541f1d9f4120e7'
COMMIT = '8491167d84b6d9521b151a743673c1516926a1f8'
DUT = 'design_1_firesim_wrapper_0_0'
VIVADO = '/tools/Xilinx/Vivado/2021.1/bin/vivado'


def read(p):
    return json.loads(Path(p).read_text())


def now():
    return dt.datetime.now(dt.timezone.utc).isoformat()


def main():
    lock = (D/'.c4-dcp-independent.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    old = read(D/'C4-runtime-cad-state.json')
    assert old['hardware_commit']==COMMIT and old['source_id']==SID
    original = Path(old['output_dir'])
    original_worker = proc(11088)
    assert original_worker and original_worker['start_ticks']=='10629'
    boot = Path('/proc/sys/kernel/random/boot_id').read_text().strip()
    st = read(STATE) if STATE.exists() else {}
    if st.get('certified_bitstream'):
        return
    stamp = dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out = Path(st.setdefault('output_dir', str(W/'dcp-work'/('C4-dcp-'+stamp))))
    logs = Path(st.setdefault('log_dir', str(D/'build-logs'/out.name)))
    out.mkdir(parents=True, exist_ok=True); logs.mkdir(parents=True, exist_ok=True)
    free = shutil.disk_usage(out).free
    assert free >= 80*2**30
    mem = {l.split(':')[0]:int(l.split()[1]) for l in Path('/proc/meminfo').read_text().splitlines()}
    assert mem['MemAvailable'] >= 96*2**20
    assert os.getloadavg()[0] < os.cpu_count()*.75
    st.update(schema='ec-c4-independent-dcp-cad/1',status='VALIDATING_INPUTS',pid=os.getpid(),
        start_ticks=proc(os.getpid())['start_ticks'],host_boot_id=boot,updated_utc=now(),
        hardware_commit=COMMIT,source_id=SID,source_tree=old['source_tree'],configuration='C4',
        original_cad_state=str(D/'C4-runtime-cad-state.json'),original_cad_worker=original_worker,
        original_output_dir=str(original),original_process_modified=False,fpga_access=False,
        certified_bitstream=False,checkpoints=st.get('checkpoints',{}),stages=st.get('stages',{}),
        host_fpga_clock_mhz=50,target_boom_clock_mhz=200,target_checker_clock_mhz=100,
        disk_budget=dict(initial_free_gib=free/2**30,stop_free_below_gib=60,max_growth_gib=120),
        script_sha256=sha(__file__))
    save(STATE,st)
    for p,h in {**old['inputs'],**old['effective_cad_inputs']}.items():
        assert sha(p)==h, p
    inv = inventory(Path(old['source_tree']))
    assert hashlib.sha256(json.dumps(inv,sort_keys=True).encode()).hexdigest()==SID
    st['input_hashes']={**old['inputs'],**old['effective_cad_inputs']}
    save(logs/'original-cad-receipt.json',old)

    if not (out/'snapshot.complete.json').exists():
        st.update(status='COPYING_PRIVATE_PROJECT'); save(STATE,st)
        for n in ['design','scripts','strategies','reportstrategies','2021.1']:
            src=original/n
            if src.exists():shutil.copytree(src,out/n,dirs_exist_ok=True)
        project=out/'vivado_proj'; project.mkdir(exist_ok=True)
        for n in ['firesim.gen','firesim.srcs','firesim.cache','firesim.ip_user_files']:
            src=original/'vivado_proj'/n
            if src.exists():shutil.copytree(src,project/n,dirs_exist_ok=True)
        shutil.copy2(original/'vivado_proj/firesim.xpr',project/'firesim.xpr')
        runs=project/'firesim.runs';runs.mkdir(exist_ok=True)
        for run in (original/'vivado_proj/firesim.runs').iterdir():
            if not run.is_dir() or run.name.startswith('.'):continue
            if run.name==DUT+'_synth_1':continue
            if run.name=='synth_1' or (run/'.vivado.end.rst').exists():
                shutil.copytree(run,runs/run.name,dirs_exist_ok=True)
        dcps=[]
        for run in (original/'vivado_proj/firesim.runs').iterdir():
            if not run.is_dir():continue
            if run.name!=DUT+'_synth_1' and not (run/'.vivado.end.rst').exists():continue
            for src in run.glob('*.dcp'):
                before=src.stat();h=sha(src)
                dst=project/'firesim.gen/sources_1/bd/design_1/ip'/src.stem/src.name
                dst.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(src,dst)
                assert sha(dst)==h
                after=src.stat();assert (before.st_size,before.st_mtime_ns)==(after.st_size,after.st_mtime_ns)
                dcps.append(dict(original=str(src),snapshot=str(dst),sha256=h,bytes=before.st_size,
                                 original_run_complete=(run/'.vivado.end.rst').exists()))
                if src.stem==DUT:
                    with zipfile.ZipFile(dst) as z:
                        metadata=z.read('dcp.xml').decode()
                        assert 'Vivado v2021.1' in metadata and f'<Part Name="{PART}"' in metadata
                        assert f'<Top Name="{DUT}"' in metadata
                        assert f'<RenamePrefix Name="{DUT}_"' in metadata
                        for member in [DUT+'_stub.v',DUT+'_stub.vhdl']:
                            (dst.parent/member).write_bytes(z.read(member))
                    st['dut_dcp']=str(dst);st['dut_dcp_sha256']=h
        assert len(dcps)==12 and 'dut_dcp' in st
        # Relocate text references into the private copy. Do not copy or touch
        # the live .Xil databases / .jobs / active DUT run directory.
        changes=[]
        for p in out.rglob('*'):
            if not p.is_file() or p.suffix not in ['.tcl','.sh','.xdc','.xpr','.xci','.xml','.bd','.v','.sv','.vh','.json']:continue
            if p.stat().st_size>200*2**20:continue
            raw=p.read_bytes()
            if str(original).encode() in raw:
                p.write_bytes(raw.replace(str(original).encode(),str(out).encode()));changes.append(str(p))
        # Original board path was serialized relative to its previous root.
        xpr=project/'firesim.xpr';x=xpr.read_text()
        x=re.sub(r'(<Option Name="BoardPartRepoPaths" Val=")[^"]*("/>)',r'\g<1>/data1/gzh/EC/firesim/dac2026/deps/boards\2',x)
        xpr.write_text(x)
        (out/'tmp').mkdir(exist_ok=True)
        st['reused_checkpoints']=dcps;st['relocated_text_files']=changes
        save(out/'snapshot.complete.json',dict(dcps=dcps,relocated=changes,source_id=SID,utc=now()))
        save(STATE,st)
    else:
        snap=read(out/'snapshot.complete.json');st['reused_checkpoints']=snap['dcps']
        dut=next(d for d in snap['dcps'] if Path(d['snapshot']).stem==DUT)
        st['dut_dcp']=dut['snapshot'];st['dut_dcp_sha256']=dut['sha256']
    for d in st['reused_checkpoints']:assert sha(d['snapshot'])==d['sha256']

    def stage(name,text,cwd):
        if st['stages'].get(name,{}).get('returncode')==0:return
        tcl=logs/(name+'.tcl');tcl.write_text(text)
        env={**os.environ,'OMP_NUM_THREADS':'2','TMPDIR':str(out/'tmp'),'LD_LIBRARY_PATH':''}
        argv=['nice','-n','15',VIVADO,'-mode','batch','-nojournal','-log',str(logs/(name+'.vivado.log')),'-source',str(tcl)]
        started=time.monotonic()
        with (logs/(name+'.log')).open('ab',buffering=0) as stream:
            child=subprocess.Popen(argv,cwd=cwd,env=env,stdin=subprocess.DEVNULL,
                                   stdout=stream,stderr=subprocess.STDOUT,start_new_session=True)
            st.update(status='RUNNING_'+name.upper(),child_pid=child.pid,
                      child_start_ticks=proc(child.pid)['start_ticks'],current_stage=name,updated_utc=now())
            st['stages'][name]=dict(argv=argv,tcl_sha256=sha(tcl),pid=child.pid,started_utc=now(),returncode=None)
            save(STATE,st)
            while child.poll() is None:
                try:child.wait(timeout=30)
                except subprocess.TimeoutExpired:pass
                remain=shutil.disk_usage(out).free
                st.update(updated_utc=now(),stage_wall_seconds=time.monotonic()-started,disk_free_gib=remain/2**30)
                save(STATE,st)
                if child.poll() is None and (remain<60*2**30 or free-remain>120*2**30):
                    # This branch's process group only; original CAD untouched.
                    os.killpg(child.pid,signal.SIGTERM);child.wait(timeout=60)
                    raise RuntimeError('independent branch disk guard')
            os.fsync(stream.fileno())
        st['stages'][name].update(returncode=child.returncode,ended_utc=now(),wall_seconds=time.monotonic()-started)
        st.pop('child_pid',None);st.pop('child_start_ticks',None);save(STATE,st)
        assert child.returncode==0,(name,child.returncode,str(logs/(name+'.log')))

    # Tool-readability test, without any write_checkpoint or RTL synthesis.
    stage('dcp_read',f'''set_param general.maxThreads 2
open_checkpoint {{{st['dut_dcp']}}}
if {{[get_property PART [current_design]] ne "{PART}"}} {{ error "DCP part mismatch" }}
set bb [get_cells -hier -quiet -filter {{IS_BLACKBOX == 1}}]
puts "EC_DCP_READ_OK part=[get_property PART [current_design]] ports=[llength [get_ports]] unresolved=[llength $bb]"
if {{[llength $bb] != 0}} {{ error "DUT DCP contains unresolved cells" }}
report_utilization -file {{{logs/'dut-utilization.rpt'}}}
close_design
exit 0
''',out)
    # Generate, but never launch, original implementation scripts. All paths
    # refer to the independent project; no original run markers are forged.
    stage('prepare_impl',f'''set_param general.maxThreads 2
set_param board.repoPaths {{/data1/gzh/EC/firesim/dac2026/deps/boards}}
open_project {{{out/'vivado_proj/firesim.xpr'}}}
set impl [get_runs impl_1]
foreach step {{OPT_DESIGN PLACE_DESIGN ROUTE_DESIGN PHYS_OPT_DESIGN POST_ROUTE_PHYS_OPT_DESIGN}} {{
  set_property STEPS.$step.ARGS.DIRECTIVE Explore $impl
}}
set_property STEPS.PHYS_OPT_DESIGN.IS_ENABLED true $impl
launch_runs $impl -to_step route_design -scripts_only
close_project
exit 0
''',out)
    top=out/'vivado_proj/firesim.runs/synth_1/design_1_wrapper.tcl'
    stage('top_synth',f'source {{{top}}}\nputs "EC_TOP_SYNTH_OK"\nexit 0\n',top.parent)
    assert (top.parent/'design_1_wrapper.dcp').is_file()
    impl=out/'vivado_proj/firesim.runs/impl_1/design_1_wrapper.tcl'
    code=impl.read_text();assert 'write_vhdl' not in code
    assert str(original) not in code,'implementation still references original CAD'
    assert str(out) in code
    save(logs/'implementation-script-binding.json',dict(path=str(impl),sha256=sha(impl),
        original_dut_run_reexecuted=False,no_original_paths=True,top_dcp=str(top.parent/'design_1_wrapper.dcp')))
    # Generated init_design must contain the reused DUT checkpoint. Otherwise
    # stop for review rather than accidentally implementing a black box.
    assert DUT+'.dcp' in code,'generated impl does not bind DUT DCP'
    stage('implementation',f'source {{{impl}}}\nputs "EC_IMPLEMENTATION_ROUTE_OK"\nexit 0\n',impl.parent)
    routed=impl.parent/'design_1_wrapper_routed.dcp'
    assert routed.is_file()
    stage('timing_bitstream',f'''set_param general.maxThreads 2
open_checkpoint {{{routed}}}
set bb [get_cells -hier -quiet -filter {{IS_BLACKBOX == 1}}]
if {{[llength $bb]}} {{ error "unresolved cells after linking" }}
set setup [get_timing_paths -delay_type max -max_paths 1]
set hold [get_timing_paths -delay_type min -max_paths 1]
if {{![llength $setup] || ![llength $hold]}} {{ error "missing timing paths" }}
set wns [get_property SLACK $setup]
set whs [get_property SLACK $hold]
puts "EC_DCP_ROUTE_TIMING WNS=$wns WHS=$whs"
report_timing_summary -report_unconstrained -file {{{logs/'timing-summary.rpt'}}}
report_drc -file {{{logs/'drc.rpt'}}}
if {{$wns < 0 || $whs < 0}} {{ error "route failed setup/hold timing gates" }}
write_bitstream -force {{{out/'vivado_proj/firesim.bit'}}}
puts "EC_DCP_BITSTREAM_OK"
close_design
exit 0
''',out)
    assert inventory(Path(old['source_tree']))==inv
    for p,h in st['input_hashes'].items():assert sha(p)==h,p
    for d in st['reused_checkpoints']:assert sha(d['snapshot'])==d['sha256']
    bit=out/'vivado_proj/firesim.bit';assert bit.is_file() and bit.stat().st_size>0
    st.update(status='BUILT_NOT_RUN',certified_bitstream=True,ended_utc=now(),
        outputs={str(bit):sha(bit)},runtime_validation='NOT_RUN',
        certification_scope='Independent DCP branch: same frozen RTL, DUT/sibling checkpoints, original generated top/implementation scripts, setup/hold and normal bitstream DRC gates; original Vivado preserved',
        deployment_admission='NOT_PUBLISHED_TO_LIVE_RUNTIME; original runtime state preserved')
    save(logs/'result.json',st);save(STATE,st)


if __name__=='__main__':
    try:main()
    except Exception as exc:
        if STATE.exists():
            s=read(STATE);s.update(status='FAILED_WITH_EVIDENCE',error=repr(exc),ended_utc=now());save(STATE,s)
        raise
