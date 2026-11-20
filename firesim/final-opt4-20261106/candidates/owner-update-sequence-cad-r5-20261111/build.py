#!/usr/bin/env python3
"""Derived C4 CAD: new DUT, immutable reused shell, capacity gate before place.

No FPGA access. Never publish into the frozen C4 admission records.
"""
import datetime as dt
import fcntl
import json
import os
from pathlib import Path
import re
import shutil
import signal
import subprocess
import time

from board_batch import W, D, save, sha
from job_service import proc, boot
from summarize_c4_capacity import utilization

COMMIT = '99c25302ab9139907416e4673bfa39e07e2dc38e'
F = W/'Opt4-fit-owner-update-sequence-r1-20261111'
N = W/'dcp-work/C4-dcp-20261110T071734Z'
O = F/'builds'/('cad-'+COMMIT[:8])
L = D/'build-logs'/('Opt4-fit-owner-update-sequence-cad-'+COMMIT[:8])
S = D/'Opt4-fit-owner-update-sequence-cad-state.json'
R = D/'Opt4-fit-owner-update-sequence-rtl-state.json'
PART = 'xcu280-fsvh2892-2L-e'
DUT = 'design_1_firesim_wrapper_0_0'
VIVADO = '/tools/Xilinx/Vivado/2021.1/bin/vivado'

def now(): return dt.datetime.now(dt.timezone.utc).isoformat()
def read(p): return json.loads(Path(p).read_text())

def generated_owner_admission():
    """Require authenticated completed cut-proof, never a partial SAT snapshot."""
    state = D/'Opt4-fit-dcache-generated-owner-proof-r3-state.json'
    result = D/'build-logs/Opt4-fit-dcache-generated-owner-proof-r3-20261111/result.json'
    proof = read(state) if state.exists() else {}
    expected = 'PASS_ACTUAL_GENERATED_512WORD_TRANSITION_AND_TAPS_WITH_REAL_WRITE_MUTATION_NOT_FULL_DCACHE_FORMAL'
    assert proof.get('status') == expected, 'WAITING_GENERATED_OWNER_PROOF_COMPLETE: ' + str(proof.get('status'))
    assert proof['hardware_commit'] == '2210930f510eccf5518c444dadca4a51bcf6f851'
    assert proof['source_id'] == '548c7b8e1066ba82388ab759127e6d3b5c2a794f2f32ebcdc27b7f653b71d66c'
    assert proof['covered_count'] == 512 and proof['covered_slots'] == list(range(512))
    assert proof['actual_write_data_mutation_rejected'] is True
    assert proof['whole_dut_formal'] is False and proof['complete_dcache_formal'] is False
    assert read(result) == proof, 'partial/mismatched proof result'
    job = read(D/'unattended-opt4/jobs/dcache-generated-owner-proof-r3b-2210930f/state.json')
    assert job['status'] == 'COMPLETE' and job['returncode'] == 0
    assert job['outputs'][str(result)] == sha(result), 'proof result hash mismatch'
    root = result.parent
    covered = set()
    for p in sorted(root.glob('slots-*/result.json')):
        row = read(p)
        assert row['miter_sha256'] == sha(p.parent/'miter.v')
        assert row['log_sha256'] == sha(p.parent/'proof.log')
        if row['accepted']:
            assert row['returncode'] == 0 and not row['timeout']
            covered.update(row['slots'])
        else:
            assert row['timeout'], 'actual semantic proof failure'
    assert covered == set(range(512)), 'missing authenticated partitions'
    negdir = root/'negative-write-data-bitflip'
    neg = read(negdir/'result.json')
    assert neg['accepted'] and neg['negative_write_data_mutation'] and not neg['timeout']
    assert neg['miter_sha256'] == sha(negdir/'miter.v') and neg['log_sha256'] == sha(negdir/'proof.log')
    original = D/'build-logs/Opt4-fit-dcache-generated-owner-proof-r2-20261111'
    contract = read(original/'extraction-contract.json')
    assert proof['contract_sha256'] == sha(original/'extraction-contract.json')
    assert proof['miter_sha256'] == sha(original/'GeneratedOwnerTransition.v') == contract['miter_sha256']
    for row in contract['inputs'].values():
        assert sha(row['path']) == row['sha256']
    return dict(path=str(result), sha256=sha(result), covered_words=512,
                source_id=proof['source_id'], proof_scope=proof['proof_scope'],
                real_write_data_mutation_rejected=True, whole_dut_formal=False)

def main():
    lock = (D/'.opt4-fit-owner-update-sequence-cad.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    L.mkdir(exist_ok=True)
    # Third full synthesis is forbidden; broker admission and these identities
    # must both establish that prior whole jobs have reached a safe boundary.
    for path in [D/'Opt4-fit-bucket-tag-cad-state.json',D/'Opt4-fit-update-share-svb-cad-state.json']:
        previous=read(path);ident=proc(previous.get('pid',0))
        alive=bool(ident and previous.get('host_boot_id')==boot() and ident['start_ticks']==str(previous.get('start_ticks')) and ident['process_state'] not in ['X','Z'])
        assert not alive,'live whole predecessor preserved; defer this next CAD'
        cap=Path(previous['log_dir'])/'capacity.complete'
        assert not cap.exists() or not cap.read_text().startswith('CAPACITY_FITS'),'existing FIT design has implementation/runtime priority'
    predecessor=read(D/'Opt4-fit-update-share-svb-cad-state.json')
    O.mkdir(parents=True, exist_ok=True); L.mkdir(exist_ok=True)
    b = read(F/'bindings'/f'{COMMIT}.json')
    st = dict(schema='ec-opt4-fit-whole-cad/1', status='WAITING_FOR_BOUND_GOLDENGATE',
        hardware_commit=COMMIT, source_id=b['source_id'], frozen_parent_commit=b['frozen_commit'],
        profile='Opt4-fit-C4-SVB32-owner-update-sequence-r1', configuration='DacOpt4C4', part=PART,
        pid=os.getpid(), start_ticks=proc(os.getpid())['start_ticks'], host_boot_id=boot(),
        started_utc=now(), output_dir=str(O), log_dir=str(L), stages={}, fpga_access=False,
        certified_bitstream=False, formal_admission=False, frozen_dut_reused=False,
        reuse_scope='11 unchanged U280 shell IPs, block design, wrappers and tool-generated control scripts only')
    save(S, st)
    while True:
        r = read(R) if R.exists() else {}
        control=read(D/'Opt4-fit-owner-update-sequence-system-r3-state.json')
        assert control.get('status') not in ['FAILED_WITH_EVIDENCE','DEPENDENCY_FAILED_WITH_EVIDENCE','NOT_SELECTED_NO_SIGNIFICANT_COMBINED_MODULE_GAIN'],'candidate preparation/area failed; preserve evidence'
        assert r.get('hardware_commit') in [None, COMMIT]
        if r.get('status') == 'GOLDENGATE_COMPLETE_NOT_SYNTHESIZED': break
        if r.get('status') == 'FAILED_WITH_EVIDENCE':
            raise RuntimeError('Bound RTL stage failed; preserve its evidence, no stale RTL fallback')
        st.update(updated_utc=now(), rtl_status=r.get('status')); save(S, st)
        time.sleep(60)
    # Admit only actual matched full module gain and exact component proofs.
    generated_proof = generated_owner_admission()
    prep=read(D/'Opt4-fit-owner-update-sequence-system-r3-state.json')
    assert prep['status']=='RTL_READY_REAL_ABI_CHECKED' and prep['hardware_commit']==COMMIT and prep['source_id']==b['source_id']
    combo_path=D/'build-logs/Opt4-fit-owner-update-sequence-system-r3-20261111/combined-equivalence.json'
    combo=read(combo_path);assert combo['hardware_commit']==COMMIT and combo['source_id']==b['source_id'] and combo['source_files_exact_components'] and not combo['architectural_recovery_added']
    full=read(D/'Opt4-fit-dcache-full-pair-r2-state.json');address=read(D/'Opt4-fit-address-update-sequence-r1-state.json')
    assert full['status']=='COMPLETE_REAL_FULL_DCACHE_OBSERVED_PAIR_NOT_WHOLE_DUT_FIT' and full['lut_saved']>=75000
    assert address['status']=='VERIFIED_AND_MAPPED_COMPLETE_ADDRESS_MODULE_NOT_WHOLE_DUT' and address['full_module_map']['resources']['CLB LUTs']<872880
    for row in list(full['maps'].values())+[address['full_module_map']]:assert sha(row['report'])==row['report_sha256']
    policy=read(D/'unattended-opt4/campaign-policy.json');assert policy['functional_baseline_commit']==b['frozen_commit'] and policy['area_equivalence_only'] and not policy['functional_extensions_allowed']
    save(L/'selection.json',dict(hardware_commit=COMMIT,source_id=b['source_id'],decision='VERIFIED_EXACT_COMPONENT_COMPOSITION_AND_ACTUAL_FULL_MODULE_GAIN',composition_sha256=sha(combo_path),full_dcache_pair=full['maps'],address_full_module=address['full_module_map'],whole_dut_fit_not_inferred=True,generated_owner_proof=generated_proof,utc=now()))
    assert r['source_id'] == b['source_id']
    assert r['configuration_matches_frozen_parameters'] and r['modified_class_origins_verified']
    gg = Path(r['goldengate_dir'])
    for p, h in r['outputs'].items(): assert sha(p) == h, p
    assert shutil.disk_usage(O).free >= 100*2**30
    mem = {l.split(':')[0]:int(l.split()[1]) for l in Path('/proc/meminfo').read_text().splitlines()}
    assert mem['MemAvailable'] >= 96*2**20

    # The immutable snapshot predates its active implementation. Only copy
    # stable shell source collateral, never a live run, log, or original DUT.
    snap = read(N/'snapshot.complete.json')
    shell = [d for d in snap['dcps'] if Path(d['snapshot']).stem != DUT]
    assert len(shell) == 11
    old = read(D/'C4-runtime-cad-state.json')
    original = Path(old['output_dir'])
    def relocate(text):
        return text.replace(str(N), str(O)).replace(str(original), str(O))
    def ignore(directory, names):
        return [n for n in names if n.endswith(('.dcp', '.pb', '.rpx', '.jou', '.log'))
                or '_sim_netlist.' in n or n in ['.Xil', '.jobs']
                or n in [DUT+'_stub.v', DUT+'_stub.vhdl']]
    marker = O/'project-inputs.complete.json'
    if not marker.exists():
        st.update(status='PREPARING_PRIVATE_PROJECT'); save(S, st)
        for n in ['design', 'scripts', '2021.1', 'strategies', 'reportstrategies',
                  'vivado_proj/firesim.gen', 'vivado_proj/firesim.srcs']:
            if (N/n).exists(): shutil.copytree(N/n, O/n, ignore=ignore, dirs_exist_ok=True)
        shutil.copy2(N/'vivado_proj/firesim.xpr', O/'vivado_proj/firesim.xpr')
        for run in ['synth_1', 'impl_1']:
            target = O/'vivado_proj/firesim.runs'/run; target.mkdir(parents=True, exist_ok=True)
            for p in (N/'vivado_proj/firesim.runs'/run).iterdir():
                if p.suffix in ['.tcl', '.xdc']: shutil.copy2(p, target/p.name)
        for p in O.rglob('*'):
            if p.is_file() and p.suffix in ['.tcl','.sh','.xdc','.xpr','.xci','.xml','.bd','.v','.sv','.vh']:
                # Vendor comments may contain legacy non-UTF8 bytes. Relocate
                # ASCII paths without decoding or changing those bytes.
                raw=p.read_bytes()
                changed=raw.replace(str(N).encode(),str(O).encode()).replace(str(original).encode(),str(O).encode())
                if raw != changed: p.write_bytes(changed)
        # Same physical wrapper interface is mandatory for shell checkpoint reuse.
        oldsv=(N/'design/FireSim-generated.sv').read_text()
        newsv=(gg/'FireSim-generated.sv').read_text()
        def ports(s):
            found=re.search(r'^module FPGATop\s*\((.*?)\);',s,re.M|re.S)
            assert found, 'GoldenGate FPGATop interface missing'
            return re.sub(r'\s+',' ',found.group(1)).strip()
        assert ports(oldsv)==ports(newsv), 'Shell-facing FPGATop interface changed'
        assert (N/'design/FireSim-generated.defines.vh').read_bytes()==(gg/'FireSim-generated.defines.vh').read_bytes()
        generated={}
        for name in ['FireSim-generated.sv','FireSim-generated.defines.vh',
                     'FireSim-generated.synthesis.xdc','FireSim-generated.implementation.xdc']:
            assert (gg/name).is_file(); shutil.copy2(gg/name, O/'design'/name)
            generated[str(O/'design'/name)]=sha(gg/name)
        reused=[]
        for d in shell:
            src=N/'reused-checkpoints'/Path(d['snapshot']).name
            assert sha(src)==d['sha256']
            dst=O/Path(d['snapshot']).relative_to(N)
            dst.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(src,dst)
            assert sha(dst)==d['sha256']
            reused.append(dict(path=str(dst),sha256=d['sha256']))
        # Empty private caches: never accidentally import the frozen DUT cache.
        for n in ['tmp','vivado_proj/firesim.cache/ip','vivado_proj/firesim.cache/wt']:
            (O/n).mkdir(parents=True,exist_ok=True)
        save(marker,dict(source_id=b['source_id'],hardware_commit=COMMIT,
            rtl_receipt=str(R),
            generated=generated,shell_checkpoints=reused,shell_interface_equal=True,
            frozen_dut_imported=False,utc=now()))
    inputs=read(marker);assert inputs['source_id']==b['source_id']
    for p,h in inputs['generated'].items():assert sha(p)==h
    for d in inputs['shell_checkpoints']:assert sha(d['path'])==d['sha256']
    st['inputs']=inputs;save(S,st)

    def stage(name, code, cwd, outputs):
        receipt=L/(name+'-result.json')
        if receipt.exists():
            prev=read(receipt)
            if prev['source_id']==b['source_id'] and prev['returncode']==0:
                assert all(sha(p)==h for p,h in prev['outputs'].items())
                st['stages'][name]=prev;save(S,st);return
        attempt=len(list(L.glob(name+'-attempt-*.tcl')))+1
        tcl=L/(name+f'-attempt-{attempt}.tcl');tcl.write_text(code)
        log=L/(name+f'-attempt-{attempt}.log')
        argv=['nice','-n','5',VIVADO,'-mode','batch','-nojournal','-log',
              str(L/(name+f'-attempt-{attempt}.vivado.log')),'-source',str(tcl)]
        env={**os.environ,'LD_LIBRARY_PATH':'','OMP_NUM_THREADS':'8','TMPDIR':str(O/'tmp')}
        started=time.monotonic()
        with log.open('ab',buffering=0) as stream:
            child=subprocess.Popen(argv,cwd=cwd,env=env,stdin=subprocess.DEVNULL,
                stdout=stream,stderr=subprocess.STDOUT,start_new_session=True)
            item=dict(source_id=b['source_id'],hardware_commit=COMMIT,argv=argv,
                tcl_sha256=sha(tcl),log=str(log),started_utc=now(),returncode=None)
            st.update(status='RUNNING_'+name.upper(),current_stage=name,child_pid=child.pid,
                child_start_ticks=proc(child.pid)['start_ticks']);st['stages'][name]=item;save(S,st)
            while child.poll() is None:
                try:child.wait(timeout=30)
                except subprocess.TimeoutExpired:pass
                st.update(updated_utc=now(),stage_wall_seconds=time.monotonic()-started,
                    disk_free_gib=shutil.disk_usage(O).free/2**30);save(S,st);os.fsync(stream.fileno())
                if child.poll() is None and shutil.disk_usage(O).free < 60*2**30:
                    os.killpg(child.pid,signal.SIGTERM)
                    try:child.wait(timeout=60)
                    except subprocess.TimeoutExpired:os.killpg(child.pid,signal.SIGKILL);child.wait()
                    raise RuntimeError('Private CAD disk guard; preserve stage/checkpoints')
        item.update(returncode=child.returncode,ended_utc=now(),wall_seconds=time.monotonic()-started)
        st.pop('child_pid',None);st.pop('child_start_ticks',None);save(S,st)
        assert child.returncode==0,(name,child.returncode,str(log))
        assert all(p.is_file() and p.stat().st_size for p in outputs)
        item['outputs']={str(p):sha(p) for p in outputs}
        save(receipt,item);st['stages'][name]=item;save(S,st)

    # Reuse the pinned tool-generated OOC input setup, not its cache/export tail.
    template=original/'vivado_proj/firesim.runs'/ (DUT+'_synth_1')/(DUT+'.tcl')
    prefix=relocate(template.read_text().split('OPTRACE "Configure IP Cache" START')[0])
    assert 'write_vhdl' not in prefix and 'write_verilog' not in prefix
    prefix=prefix.replace('set_param general.maxThreads 2','set_param general.maxThreads 8')
    dutrun=O/'vivado_proj/firesim.runs'/(DUT+'_synth_1');dutrun.mkdir(exist_ok=True)
    dutdest=O/'vivado_proj/firesim.gen/sources_1/bd/design_1/ip'/DUT
    dutdcp=dutdest/(DUT+'.dcp')
    code=prefix+f'''
set_param synth.elaboration.rodinMoreOptions {{rt::set_parameter dissolveMemorySizeLimit 74752}}
synth_design -top {DUT} -part {PART} -mode out_of_context
set bb [get_cells -hier -quiet -filter {{IS_BLACKBOX == 1}}]
if {{[llength $bb]}} {{error "unresolved DUT cells: $bb"}}
rename_ref -prefix_all {DUT}_
# Publish actual resource reports before costly DCP export. This changes noRTL,
# constraints or synthesized design; subsequent stages still require exactDCP.
report_utilization -file {{{L/'dut-utilization.rpt'}}}
report_utilization -hierarchical -hierarchical_depth 30 -file {{{L/'dut-hierarchical.rpt'}}}
puts "EC_FIT_DUT_RESOURCE_REPORTS_DURABLE_CHECKPOINT_PENDING"
write_checkpoint -force -noxdef {{{dutdcp}}}
write_verilog -force -mode synth_stub {{{dutdest/(DUT+'_stub.v')}}}
puts "EC_FIT_DUT_SYNTH_COMPLETE"
exit 0
'''
    stage('dut_synth',code,dutrun,[dutdcp,dutdest/(DUT+'_stub.v'),L/'dut-utilization.rpt',L/'dut-hierarchical.rpt'])
    st['dut_resources']=utilization(L/'dut-utilization.rpt');save(S,st)
    # Prior whole identities were checked before admission; no peer CAD is launched by the broker while this service owns its slot.
    topdir=O/'vivado_proj/firesim.runs/synth_1'
    top=topdir/'design_1_wrapper.tcl'
    stage('top_synth',f'source {{{top}}}\nputs "EC_FIT_TOP_SYNTH_COMPLETE"\nexit 0\n',topdir,[topdir/'design_1_wrapper.dcp'])
    impldir=O/'vivado_proj/firesim.runs/impl_1'
    code=(impldir/'design_1_wrapper.tcl').read_text()
    assert str(N) not in code and str(original) not in code
    link='  link_design -top design_1_wrapper -part '+PART
    assert code.count(link)==1
    gate='''
  set unresolved {}
  foreach c [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}] {
    if {$c eq "dbg_hub" && [get_property REF_NAME $c] eq "dbg_hub_CV" && [get_property IS_DEBUG_CORE $c]} {continue}
    lappend unresolved $c
  }
  if {[llength $unresolved]} {error "unresolved functional IP: $unresolved"}
  puts "EC_FIT_LINK_ZERO_FUNCTIONAL_BLACKBOX"
'''
    report='OPTRACE "opt_design reports" START { REPORT }'
    place='    implement_debug_core '
    assert code.count(report)==1 and code.count(place)==1
    cap=f'''
  report_utilization -file {{{L/'top-postopt-utilization.rpt'}}}
  report_utilization -hierarchical -hierarchical_depth 30 -file {{{L/'top-postopt-hierarchical.rpt'}}}
  report_drc -file {{{L/'top-postopt-drc.rpt'}}}
  set f [open {{{L/'top-postopt-utilization.rpt'}}} r]
  set text [read $f]; close $f
  set exceeded {{}}; set seen {{}}
  foreach line [split $text \\n] {{
    set a [split $line |]
    if {{[llength $a] < 7}} {{continue}}
    set kind [string trimright [string trim [lindex $a 1]] *]
    if {{$kind ni {{"CLB LUTs" "CLB Registers" "CARRY8" "DSPs" "Block RAM Tile" "URAM"}} || [dict exists $seen $kind]}} {{continue}}
    set used [string map {{, {{}}}} [string trim [lindex $a 2]]]
    set avail [string map {{, {{}}}} [string trim [lindex $a 5]]]
    if {{![string is double -strict $used] || ![string is double -strict $avail] || $avail <= 0}} {{continue}}
    dict set seen $kind 1
    puts "EC_FIT_CAPACITY kind=$kind used=$used available=$avail"
    if {{$used > $avail}} {{lappend exceeded $kind}}
  }}
  if {{[dict size $seen] < 5}} {{error "capacity report parse incomplete"}}
  set f [open {{{L/'capacity.complete'}}} w]
  if {{[llength $exceeded]}} {{puts $f "NOT_FIT_POSTOPT $exceeded";close $f;error "NOT FIT; saved optimized checkpoint, no place/route: $exceeded"}}
  puts $f "CAPACITY_FITS_POSTOPT_TIMING_PENDING";close $f
'''
    postdebug='''
    set bb [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]
    if {[llength $bb]} {error "unresolved after debug core implementation: $bb"}
'''
    code=code.replace(link,link+gate).replace(report,report+'\n'+cap).replace(place,place+postdebug)
    code=code.replace('set_param general.maxThreads 2','set_param general.maxThreads 8')
    bound=L/'implementation-bound.tcl';bound.write_text(code)
    routed=impldir/'design_1_wrapper_routed.dcp'
    stage('implementation',f'source {{{bound}}}\nputs "EC_FIT_ROUTED"\nexit 0\n',impldir,[routed,L/'top-postopt-utilization.rpt'])
    bit=O/'vivado_proj/firesim.bit'
    stage('timing_bitstream',f'''
set_param general.maxThreads 8
open_checkpoint {{{routed}}}
if {{[llength [get_cells -hier -quiet -filter {{IS_BLACKBOX == 1}}]]}} {{error "unresolved cells"}}
set setup [get_timing_paths -delay_type max -max_paths 1]
set hold [get_timing_paths -delay_type min -max_paths 1]
if {{![llength $setup] || ![llength $hold]}} {{error "missing timing paths"}}
set wns [get_property SLACK $setup];set whs [get_property SLACK $hold]
report_timing_summary -report_unconstrained -file {{{L/'timing-summary.rpt'}}}
report_drc -file {{{L/'final-drc.rpt'}}}
puts "EC_FIT_TIMING WNS=$wns WHS=$whs"
if {{$wns < 0 || $whs < 0}} {{error "setup/hold timing gate failed"}}
write_bitstream -force {{{bit}}}
puts "EC_FIT_BITSTREAM_COMPLETE"
exit 0
''',O,[bit,L/'timing-summary.rpt',L/'final-drc.rpt'])
    st.update(status='BUILT_TIMING_DRC_PASSED_NOT_RUNTIME_VALIDATED',ended_utc=now(),
        certified_bitstream=True,bitstream=str(bit),bitstream_sha256=sha(bit),
        top_postopt_resources=utilization(L/'top-postopt-utilization.rpt'),
        admission='Separate derived profile; requires matching new host driver, 21-only safe boundary, smoke/checker/drain/correctness before formal sampling')
    save(L/'result.json',st);save(S,st)

if __name__=='__main__':
    try: main()
    except Exception as exc:
        if S.exists() and read(S).get("pid")==os.getpid():
            st=read(S); cap=L/'capacity.complete'
            st.update(status='NOT_FIT_POSTOPT' if cap.exists() and cap.read_text().startswith('NOT_FIT') else 'FAILED_WITH_EVIDENCE',
                error=str(exc),error_type=type(exc).__name__,ended_utc=now(),top_postopt_resources=utilization(L/'top-postopt-utilization.rpt'))
            save(S,st)
        raise
