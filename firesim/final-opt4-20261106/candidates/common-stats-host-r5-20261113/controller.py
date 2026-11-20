#!/usr/bin/python3
"""Deterministic mixed-role actual-caller host/token/OOC experiment; no board IO."""
import fcntl
import importlib.util
import json
import os
from pathlib import Path
import re
import resource
import subprocess
import sys

from prepare import prepare,T
C=Path(__file__).resolve().parent
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O=D/'build-logs/Opt4-common-stats-host-r5-20261113'
P1=D/'build-logs/Opt4-common-stats-host-r1-20261113'
FS=W/'C4/chipyard/sims/firesim/sim'
CPUS={206,207}
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import identity,now,read,save,sha
spec=importlib.util.spec_from_file_location('mixed_stats_stage_tools',W/'candidates/address-histogram-fame5-r6-20261112/controller.py')
m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
m.C,m.O,m.CPUS=C,O,CPUS
spec=importlib.util.spec_from_file_location('mixed_stats_resource_parser',W/'candidates/mcrams-full-host-capacity-r1-20261112/resource_parser.py')
parser=importlib.util.module_from_spec(spec);spec.loader.exec_module(parser)


def cgroup_members(unit):
    suffix='/'+unit;found=[]
    for p in Path('/proc').iterdir():
        if not p.name.isdigit():continue
        try:
            if any(l.split(':',2)[-1].endswith(suffix) for l in (p/'cgroup').read_text().splitlines()):
                found.append(identity(int(p.name)))
        except OSError:pass
    return found


def ports(path,top):
    head=re.search(r'\bmodule '+top+r'\s*\((.*?)\);',path.read_text(),re.S).group(1)
    return re.findall(r'\b(input|output)\s*(\[\d+:\d+\])?\s+(\w+)',head)


def oracle(rtl):
    ps=ports(rtl,'MixedTarget')
    ins=[n for d,w,n in ps if d=='input' and n!='clock']
    outs=[n for d,w,n in ps if d=='output']
    assert len(outs)==73
    assert not any('debug' in n.lower() for n in outs)
    lines=['module tb;','integer i,phase,seq,trace_fd,valid_edges=0,idle_edges=0;',
        "reg [63:0] rng=64'h4d595df4d0f33173;"]
    lines += [('reg ' if d=='input' else 'wire ')+w+' '+n+';' for d,w,n in ps]
    lines += ['MixedTarget dut('+','.join('.'+n+'('+n+')' for d,w,n in ps)+');',
        'initial begin']
    lines += [n+"='0;" for d,w,n in ps if d=='input']
    trace=O/'target-public-tokens.txt'
    lines += [f'trace_fd=$fopen("{trace}","w");','for(i=0;i<3003;i=i+1)begin']
    prior=D/'build-logs/Opt4-address-packed-full-module-r1-20261112/tb.v'
    s=prior.read_text();stim=s[s.index('reset=(i<3);'):s.index('// A normal reset without resetStats')]
    stim=re.sub(r'\bio_', 'io_address_',stim)
    lines += [stim,'if(i>=3000)begin reset=1;io_address_resetStats=0;end']
    for j in range(3):
        p=f'io_barrier_{j}_'
        lines += ['rng=rng^(rng<<13); rng=rng^(rng>>7); rng=rng^(rng<<17);',
            p+'resetStats=(i<3 || i==2048);',p+'event_valid=(rng[3:0]!=0);',
            p+f'event_bits=(i<512)?(1+(i+{j})%255):rng[11:0];',
            p+'safeWatermark=(i<512)?0:((i<768)?i-511:rng[23:12]);',
            p+f'currentCycle=(i<2500)?(100000+i+{j}):rng;',
            p+f'fatalProtocolError=(i=={2600+j});']
    fmt=' '.join('%h' for _ in ins+outs)+'\\n'
    lines += ['#1;clock=1;#1;',
        f'$fwrite(trace_fd,"{fmt}",'+','.join(ins+outs)+');',
        'if(io_address_statsValid)valid_edges=valid_edges+1;',
        'if(io_address_idle)idle_edges=idle_edges+1;',
        'clock=0;#1;end',
        'if(valid_edges<100 || idle_edges<10)begin $display("MIXED_TARGET_INSUFFICIENT_LIVE_COVERAGE");$finish_and_return(1);end',
        '$display("MIXED_TARGET_TOKEN_ORACLE_PASS tokens=3003 outputs=73 valid_edges=%0d idle_edges=%0d",valid_edges,idle_edges);$finish;',
        'end endmodule']
    m.exact(O/'tb.v','\n'.join(lines)+'\n')
    m.exact(O/'trace-ports.h','static const char *input_ports[] = {'+', '.join(json.dumps(n) for n in ins)+'};\n'+
        'static const char *output_ports[] = {'+', '.join(json.dumps(n) for n in outs)+'};\n')
    save(O/'target-token-binding.json',dict(target_RTL_sha256=sha(rtl),testbench_sha256=sha(O/'tb.v'),
        original_stimulus_sha256=sha(prior),tokens=3003,public_outputs=73,
        sample='post_target_rising_edge',invalid_internal_seed=False,
        functional_equivalence_claim=False,scope='Independent target oracle for mixed host transform/token validation.'))
    exe=O/'target.vvp'
    m.stage('compile-token-target',['/usr/bin/iverilog','-g2012','-s','tb','-o',exe,rtl,O/'tb.v'],[exe])
    m.stage('target-token-oracle',['/usr/bin/vvp',exe],marker='MIXED_TARGET_TOKEN_ORACLE_PASS tokens=3003 outputs=73')
    rows=trace.read_text().splitlines()
    assert len(rows)==3003 and all(len(l.split())==len(ins)+73 for l in rows)
    assert all(re.fullmatch('[0-9a-fA-F]+',v) for l in rows[3:] for v in l.split())
    save(O/'target-oracle.json',dict(tokens=3003,public_outputs=73,trace=str(trace),trace_sha256=sha(trace),
        oracle_is_independent_unthreaded_target=True,not_complete_functional_equivalence=True))
    return trace


def simulate(host,name,trace):
    listing=host/'firrtl_black_box_resource_files.f'
    sim=host/'simulation.sv'
    m.exact(sim,(host/'FireSim-generated.sv').read_text()+''.join(Path(p).read_text() for p in listing.read_text().splitlines() if p.strip()))
    clang='/nix/store/zxw41nfy4gjlzd31ly7q6mkv4vkybx15-clang-wrapper-16.0.6/bin/clang++'
    verilator='/nix/store/bj3wbpawbk71c082cvrnqkfyix7ipx0g-verilator-5.048/bin/verilator'
    deps=D/'build-logs/Opt4-mcrams-address-bucket-r2-20261112'
    env={**os.environ,'CCACHE_DISABLE':'1','LD_LIBRARY_PATH':'',
        'PATH':str(Path(clang).parent)+':'+str(Path(verilator).parent)+':/usr/local/bin:/usr/bin:/bin',
        'CXX':clang,'CXXFLAGS':'-O1 -I'+str(O)+' -I'+str(deps/'headers')+' -I'+str(FS/'src/main/cc/midasexamples'),
        'LDFLAGS':'-L'+str(deps/'libs')+' -Wl,-rpath,'+str(deps/'libs'),'OMP_NUM_THREADS':'2'}
    exe=host/'VMixedStats'
    m.stage('compile-host-'+name,['/usr/bin/make','-C',FS/'midas/src/main/cc','-j2','verilator',
        'PLATFORM=xilinx_alveo','DRIVER_NAME=MixedStats','GEN_DIR='+str(host),
        'GEN_FILE_BASENAME=FireSim-generated','DESIGN_V='+str(sim),
        'DRIVER='+str(FS/'src/main/cc/midasexamples/TestHarness.cc')+' '+str(C/'TestMixed.cc'),
        'VERILATOR_FLAGS=-Wno-fatal -Wno-MULTIDRIVEN','CXX='+clang],[exe],env=env)
    args=[exe,'+trace='+str(trace),'+seed=8491167','+max-cycles=10000000']
    m.stage('token-oracle-'+name,args,marker='MIXED_STATS_HOST_TOKEN_PASS',env=env,timeout=3600)
    m.stage('token-negative-'+name,args+['+negative'],negative=True,
        marker='MIXED_STATS_HOST_MISMATCH cycle=100 port=io_address_statsValid',env=env,timeout=600)
    s=next(l for l in (O/('token-oracle-'+name+'.log')).read_text().splitlines() if l.startswith('MIXED_STATS_HOST_TOKEN_PASS '))
    r=json.loads(s.split(' ',1)[1]);assert r['target_tokens']==3003 and r['checked_outputs']==3000*73
    return r


def area(host,name):
    save(O/(name+'-area-admission.json'),m.admission())
    collateral=sorted(host.glob('*.v'))+[host/'FireSim-generated.sv']
    tcl=host/'map.tcl'
    m.exact(tcl,'set_param general.maxThreads 2\n'+
        '\n'.join('read_verilog -sv {'+str(p)+'}' for p in collateral)+'\n'+
        'read_xdc {'+str(host/'FireSim-generated.synthesis.xdc')+'}\n'+
        'synth_design -mode out_of_context -top FPGATop -part xcu280-fsvh2892-2L-e\n'+
        'if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "blackbox"}\n'+
        'report_utilization -file {'+str(host/'utilization.rpt')+'}\n'+
        'report_utilization -hierarchical -file {'+str(host/'hierarchical.rpt')+'}\n'+
        'write_checkpoint -force {'+str(host/'host.dcp')+'}\nexit 0\n')
    save(O/(name+'-map-inputs.json'),dict(files={str(p):sha(p) for p in collateral+[tcl,host/'FireSim-generated.synthesis.xdc']}))
    pins={str(p):sha(p) for p in collateral+[tcl,host/'FireSim-generated.synthesis.xdc']}
    m.stage('map-'+name,['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal',
        '-log',host/'vivado.log','-source',tcl],[host/'utilization.rpt',host/'hierarchical.rpt',host/'host.dcp'])
    assert all(sha(p)==h for p,h in pins.items())
    total=parser.parse_total((host/'utilization.rpt').read_text())
    parser.parse_hier((host/'hierarchical.rpt').read_text(),total)
    parser.crosschecks((host/'utilization.rpt').read_text(),total)
    return dict(resources={k:v['used'] for k,v in total.items()},outputs={str(host/n):sha(host/n) for n in ['utilization.rpt','hierarchical.rpt','host.dcp']})


def main():
    O.mkdir(exist_ok=True)
    lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(),'Adopt existing owner, never duplicate'
    predecessors=['ec-opt4-common-stats-host-r4-20261113.service','ec-opt4-common-stats-host-r3-20261113.service','ec-opt4-common-stats-host-r2-20261113.service','ec-opt4-common-stats-host-r1-20261113.service','ec-opt4-common-stats-bank-r3-launch2-20261113.service','ec-opt4-barrier-banked-host-r4-20261113.service']
    release={u:cgroup_members(u) for u in predecessors};assert not any(release.values())
    save(O/'predecessor-release.json',dict(utc=now(),members=release))
    os.sched_setaffinity(0,CPUS);resource.setrlimit(resource.RLIMIT_AS,(64*2**30,)*2)
    failed=D/'build-logs/Opt4-common-stats-host-r4-20261113'
    assert read(failed/'failure.json')['active_stage']=='goldengate-Threaded'
    assert 'java.lang.OutOfMemoryError: Java heap space' in (failed/'goldengate-Threaded.log').read_text()
    assert 'firrtl.annotations.ModuleTarget.ref' in (failed/'goldengate-Threaded.log').read_text()
    save(O/'diagnosed-recovery.json',dict(predecessor_failure_sha256=sha(failed/'failure.json'),
        predecessor_log_sha256=sha(failed/'goldengate-Threaded.log'),
        cause='48GiB heap exhausted constructing repeated immutable port ReferenceTargets in ordinary CombinationalPath annotations; intern exact targets and equal source rows, retaining every path and all checks',
        hardware_change=False,check_comb_loops_enabled=True,target_register_or_cycle_changes=False,
        Java_heap_GiB=48,memory_hard_limit_GiB=64,
        no_savings_or_feasibility_claim=True,one_diagnosed_attempt=True,
        checker_is_analysis_only=True,compiler_semantics_regression_required=True,no_loop_check_disabled=True))
    binding=read(C/'source-binding.json')
    assert all(sha(p)==h for p,h in binding['files'].items())
    assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=T,text=True).strip()==binding['hardware_commit']
    assert prepare()==binding['derivation']
    import hashlib
    for path,h in binding['committed_files'].items():
        raw=subprocess.check_output(['git','show',binding['hardware_commit']+':'+path],cwd=T)
        assert hashlib.sha256(raw).hexdigest()==h
    m.ST.update(schema='ec-common-stats-mixed-host-pair/1',**identity(),started_utc=now(),
        hardware_commit=binding['hardware_commit'],functional_baseline=binding['functional_baseline'],
        cpus=sorted(CPUS),memory_limit_gib=64,fpga_access=False,whole_EC_CAD=False,
        full_system_fit=False,production_admission=False,source_binding_sha256=sha(C/'source-binding.json'),
        hardware_source_parent=binding['hardware_source_parent'],compiler_recovery=True,
        scope=binding['derivation']['scope'])
    m.update('ADMITTING_MIXED_ROLE_EXPERIMENT')
    save(O/'admission.json',m.admission())
    proof=D/'build-logs/Opt4-common-stats-bank-r3-20261113'
    prior=read(proof/'result.json')
    assert prior['status']=='PASS_COMMON_BANK_COMPILE_AND_FULL_STATE_FINITE_MITER_NO_HOST_AREA'
    assert sha(proof/'target-validation.json')==prior['target_validation_sha256']
    prod=D/'build-logs/Opt4-common-stats-bank-r1-20261113/classes'
    composed=D/'build-logs/Opt4-address-banked-storage-compose-r1-20261112/source-classes'
    rec=read(proof/'reused-production-classes.json')
    assert all(sha(p)==h for p,h in rec['files'].items())
    save(O/'adopted-bank-validation.json',dict(result=str(proof/'result.json'),result_sha256=sha(proof/'result.json'),
        class_hashes=rec['files'],hardware_source_commit=prior['hardware_commit'],
        complete_caller_and_DCache_equivalence=False))
    cfg=read(W/'candidates/address-banked-storage-compose-r1-20261112/config.json')
    java=[cfg['java'],'-Xmx48G','-Xss32M','-XX:ActiveProcessorCount=2']
    checker=O/'checker-classes'; checker.mkdir()
    compiler_sources=[C/n for n in ['CheckCombLoops.scala','ECReferenceCheckCombLoops.scala','CheckCompact.scala']]
    m.stage('compile-compact-checker',java+['-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main',
        '-classpath',':'.join(cfg['classpath']),'-d',checker]+compiler_sources,
        [checker/'firrtl/transforms/CheckCombLoops.class',checker/'firrtl/transforms/CheckCompact.class'])
    checkercp=str(checker)+':'+':'.join(cfg['classpath'])
    m.stage('checker-semantic-regression',java+['-cp',checkercp,'firrtl.transforms.CheckCompact'],
        marker='EC_COMPACT_CHECKER_REGRESSION_PASS passed=261 rejected=5 stock_paths_fullgraphs_and_circuit_identity=true')
    save(O/'compiler-recovery-gate.json',dict(regression_receipt_sha256=sha(O/'checker-semantic-regression-receipt.json'),
        checker_source_sha256=sha(C/'CheckCombLoops.scala'),unchanged_circuit_and_exact_port_paths_tested=True,
        bypassed_comb_loop_checks=False,hardware_or_target_cycles_changed=False,
        classes={str(p):sha(p) for p in checker.rglob('*.class')}))
    classes=P1/'classes' 
    oldbinding=read(W/'candidates/common-stats-host-r1-20261113/source-binding.json')
    assert all(sha(p)==h for p,h in oldbinding['files'].items())
    assert sha(C/'Mixed.scala')==sha(W/'candidates/common-stats-host-r1-20261113/Mixed.scala')
    rec=read(P1/'compile-harness-receipt.json')
    assert rec['accepted'] and all(sha(p)==h for p,h in rec['outputs'].items())
    save(O/'reused-harness-classes.json',dict(receipt_sha256=sha(P1/'compile-harness-receipt.json'),
        files={str(p):sha(p) for p in classes.rglob('*.class')},hardware_source_unchanged=True))
    basecp=':'.join(map(str,[prod,composed]))+':'+':'.join(cfg['classpath'])
    cp=str(checker)+':'+str(classes)+':'+basecp
    # Host topology is the new prerequisite; validate it before spending on
    # independent target-token compilation. No proof-only output channels.
    target=P1/'Host-target'
    rec=read(P1/'elaborate-mixed-host-receipt.json')
    assert rec['accepted'] and all(sha(p)==h for p,h in rec['outputs'].items())
    save(O/'reused-elaboration.json',dict(receipt_sha256=sha(P1/'elaborate-mixed-host-receipt.json'),
        files=rec['outputs'],source_Mixed_sha256=sha(C/'Mixed.scala'),no_reelaboration=True))
    assert 'DontCheckCombLoopsAnnotation' not in (target/'MixedStats.anno.json').read_text()
    selected=[a for a in read(target/'MixedStats.anno.json') if a.get('class','').endswith('FirrtlEnableModelMultiThreadingAnnotation')]
    assert len(selected)==64
    assert all(re.fullmatch(r'StatsBank(?:_\d+)?',a['target'].split(':')[-1]) for a in selected)
    save(O/'pre-dedup-selection.json',dict(count=len(selected),targets=selected,
        one_type_check_stage='post-fame-transform after FIRRTL dedup, before multithreading'))
    hosts={}
    for name in ['Threaded','Plain']:
        host=O/name;host.mkdir();hosts[name]=host
        m.stage('goldengate-'+name,java+['-cp',cp,'midas.stage.GoldenGateMain',
            '-i',target/'MixedStats.fir','-td',host,'-faf',target/'MixedStats.anno.json',
            '-ggcp','commonstatshost','-ggcs',name+'Config','--output-filename-base','FireSim-generated'],
            [host/'FireSim-generated.sv',host/'FireSim-generated.synthesis.xdc'])
        assert 'EC_COMPACT_PORT_SUMMARY module=' in (O/('goldengate-'+name+'.log')).read_text()
        assert 'Skipping Combinational Loop Detection' not in (O/('goldengate-'+name+'.log')).read_text()
        fame=(host/'post-fame-transform.fir').read_text()
        actual_selected=re.findall(r'(?m)^\s*inst \w+ of (StatsBank(?:_\d+)?)\b',fame)
        assert len(actual_selected)==64 and len(set(actual_selected))==1, ('post_dedup_selected',len(actual_selected),set(actual_selected))
        fir=(host/'post-gen-sram-models.fir').read_text()
        assert ('module StatsBank_threaded :' in fir)==(name=='Threaded')
        assert not any(x in fir for x in ['io_observe','io_debugBuckets','io_debugValid','io_debugSeq'])
        save(O/(name+'-threading-audit.json'),dict(selected_instances=64,selected_types=['StatsBank'],
            address_banks=16,barrier_banks=48,slots=256,lanes=16,proof_outputs=False,
            source_firrtl_sha256=sha(target/'MixedStats.fir'),host_RTL_sha256=sha(host/'FireSim-generated.sv')))
    targetoracle=O/'Target-oracle';targetoracle.mkdir()
    m.stage('elaborate-token-target',java+['-cp',cp,'commonstatshost.Emit',targetoracle],[targetoracle/'MixedTarget.v'])
    trace=oracle(targetoracle/'MixedTarget.v')
    tokens={name:simulate(host,name,trace) for name,host in hosts.items()}
    assert tokens['Plain']['digest']==tokens['Threaded']['digest']
    save(O/'host-validation.json',dict(tokens=tokens,target_tokens=3003,outputs=73,full_formal=False,
        whole_EC_equivalence=False,source_binding_sha256=sha(C/'source-binding.json')))
    measured={}
    for name in ['Plain','Threaded']:
        measured[name]=area(hosts[name],name);save(O/'paired-progress.json',measured)
    savings={k:measured['Plain']['resources'][k]-measured['Threaded']['resources'][k] for k in measured['Plain']['resources']}
    assert all(sha(p)==h for p,h in binding['files'].items())
    m.update('COMPLETE_MIXED_ROLE_HOST_TOKENS_AND_AREA_PAIR_NOT_WHOLE_EC',tokens=tokens,
        area=measured,savings=savings,ended_utc=now(),full_formal=False,full_system_fit=False,
        next='Use exact mixed-role same-scope area and caller/token receipts to choose composition; full frozen DCache/whole-host validation and complete shell capacity still required. Reject insufficient gains without a whole build.')
    save(O/'result.json',m.ST)

if __name__=='__main__':
    try:main()
    except Exception as exc:
        if m.ST:
            m.update('FAILED_WITH_EVIDENCE_VERSIONED_CORRECTION_REQUIRED',error=repr(exc),ended_utc=now())
            save(O/'failure.json',m.ST)
        raise
