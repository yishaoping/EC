#!/usr/bin/python3
"""Full 256-entry barrier banks: finite target, real host tokens, serial OOC.

This is a deterministic experiment, never an intelligent supervisor or a
whole-EC capacity/build owner. Existing pinned owners are left untouched.
"""
import fcntl
import importlib.util
import json
import os
from pathlib import Path
import re
import resource
import shutil
import subprocess
import sys
import time

from prepare import prepare, TREE, REL

C=Path(__file__).resolve().parent
W=C.parent.parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O=D/'build-logs/Opt4-barrier-banked-host-r3-20261113'
R=D/'build-logs/Opt4-barrier-banked-host-r2-20261113'
FS=W/'C4/chipyard/sims/firesim/sim'
CPUS={206,207}
P=D/'build-logs/Opt4-barrier-banked-host-r1-20261113'
PC=W/'candidates/barrier-banked-host-r1-20261113'
spec=importlib.util.spec_from_file_location('immutable_banked_barrier_tools',W/'candidates/address-histogram-fame5-r6-20261112/controller.py')
m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
m.C,m.O,m.CPUS=C,O,CPUS
from opt4_unattended_common import identity,now,read,save,sha

parser_spec=importlib.util.spec_from_file_location('strict_banked_barrier_resources',W/'candidates/mcrams-full-host-capacity-r1-20261112/resource_parser.py')
parser=importlib.util.module_from_spec(parser_spec);parser_spec.loader.exec_module(parser)

def ports(p,top):
    head=re.search(r'\bmodule '+top+r'\s*\((.*?)\);',p.read_text(),re.S).group(1)
    return re.findall(r'\b(input|output)\s*(\[\d+:\d+\])?\s+(\w+)',head)

def testbench(lanes,reference,candidate):
    ps=ports(reference,'BarrierReference')
    assert ps==ports(candidate,'BarrierCandidate')
    inputs=[p for p in ps if p[0]=='input']
    outputs=[p for p in ps if p[0]=='output']
    assert len(outputs)==263
    public=[n for d,w,n in outputs if not n.startswith('io_debug')]
    ins=[n for d,w,n in inputs if n!='clock']
    assert len(public)==7
    trace=O/f'reference-{lanes}-tokens.txt'
    lines=['module tb;','integer cycle, trace_fd;',"reg [63:0] rng=64'h4d595df4d0f33173;"]
    for d,w,n in inputs:lines.append(f'reg {w} {n};')
    for d,w,n in outputs:lines += [f'wire {w} r_{n};',f'wire {w} c_{n};']
    for label,prefix in [('Reference','r'),('Candidate','c')]:
        args=[f'.{n}({n})' for d,w,n in inputs]+[f'.{n}({prefix}_{n})' for d,w,n in outputs]
        lines.append('Barrier'+label+' dut'+label+'('+','.join(args)+');')
    lines += ['task check; begin']
    for d,w,n in outputs:
        lines.append(f'if(r_{n} !== c_{n}) begin $display("BARRIER_BANK_MISMATCH port={n} cycle=%0d",cycle); $fatal(1); end')
    lines += ['end endtask','initial begin','cycle=-1;']
    lines += [n+"='0;" for d,w,n in inputs]
    lines += [f'trace_fd=$fopen("{trace}","w");','reset=1; #1; clock=1; #1; clock=0; #1;',
        'for(cycle=0;cycle<8704;cycle=cycle+1) begin',
        'rng=rng^(rng<<13); rng=rng^(rng>>7); rng=rng^(rng<<17);',
        'reset=(cycle<3 || cycle==3072 || cycle==6144);',
        'io_resetStats=(cycle==2048 || cycle==4096 || cycle==7168 || cycle==8192);',
        'io_event_valid=(rng[3:0]!=0);',"io_event_bits={20'd0,rng[11:0]};",
        "io_safeWatermark={20'd0,rng[23:12]};",
        "io_currentCycle=(cycle<4096)?(64'd100000+cycle):rng;",
        'io_fatalProtocolError=(cycle==6000);',
        'if(cycle<512) begin io_safeWatermark=0; io_event_bits=1+(cycle%255); io_currentCycle=cycle; end',
        'if(cycle>=512 && cycle<768) begin io_safeWatermark=cycle-511; io_event_bits=cycle-255; end',
        '// Directed exact-width overflow, invalid payload, underflow, and reset priority after public trace.',
        'if(cycle>8192) begin io_event_bits=7; io_safeWatermark=0; io_event_valid=1; io_currentCycle=1; end',
        'if(cycle==8193) begin']
    # Equal arbitrary internal seed on both sides; host token claim ends before
    # this seed, so unreproducible internal state is never claimed by host replay.
    for prefix in ['dutReference',f'dutCandidate.bucketBanks_{7//lanes}']:
        idx=7 if prefix=='dutReference' else 7%lanes
        for field,value in [('valid',"1'b1"),('seq',"32'd7"),('count',"64'hffffffffffffffff"),('requestCycleSum',"64'hffffffffffffffff")]:
            lines.append(f'{prefix}.buckets_{field}_{idx}={value};')
    for prefix in ['dutReference','dutCandidate']:
        for field in ['seen','resolved','pending','dropped','requestCycleSum','safeCycleSum']:
            lines.append(f'{prefix}.{field}=64\'hffffffffffffffff;')
    lines += ['end',
        'if(cycle==8195) begin io_safeWatermark=7; io_event_bits=263; end',
        'if(cycle==8196) begin io_safeWatermark=263; io_event_bits=263; end',
        'if(cycle==8197) begin io_resetStats=1; io_fatalProtocolError=1; end',
        '#1; check;']
    fmt=' '.join('%h' for _ in ins+public)+'\\n'
    lines += ['clock=1; #1;',
        f'if(cycle<8192)$fwrite(trace_fd,"{fmt}",'+','.join(ins+['r_'+n for n in public])+');',
        'clock=0; #1;',
        'if($test$plusargs("EC_MUTATE") && cycle==1000) begin force dutCandidate.seen=64\'hdeadbeef12345678; #1; end',
        'check; end',
        '$display("BARRIER_BANK_TARGET_PASS cycles=8704 observations=263 public_trace_tokens=8192"); $finish;',
        'end endmodule']
    tb=O/f'tb-{lanes}.v';m.exact(tb,'\n'.join(lines)+'\n')
    m.exact(O/'trace-ports.h','static const char *input_ports[] = {'+', '.join(json.dumps(n) for n in ins)+'};\n'+
        'static const char *output_ports[] = {'+', '.join(json.dumps(n) for n in public)+'};\n')
    save(O/f'target-binding-{lanes}.json',dict(reference=sha(reference),candidate=sha(candidate),testbench=sha(tb),
        target_cycles=8704,observations=263,public_host_tokens=8192,internal_seed_after_host_trace=True,public_output_sampling="post_target_rising_edge"))
    return tb,trace

def compile_host(host,name,trace):
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
    if name == 'Threaded16':
        reused=read(R/'compile-host-Threaded16-receipt.json')
        assert reused['accepted'] and sha(reused['log'])==reused['log_sha256']
        assert all(sha(p)==h for p,h in reused['outputs'].items())
        binary=R/'Threaded16/VBarrierBank'
        save(O/'reused-host-Threaded16.json',dict(predecessor=str(R),binary=str(binary),binary_sha256=sha(binary),compile_receipt_sha256=sha(R/'compile-host-Threaded16-receipt.json'),driver_unchanged=True,host_RTL_sha256=sha(host/'FireSim-generated.sv')))
    else:
        binary=host/'VBarrierBank'
        m.stage('compile-host-'+name,['/usr/bin/make','-C',FS/'midas/src/main/cc','-j2','verilator',
        'PLATFORM=xilinx_alveo','DRIVER_NAME=BarrierBank','GEN_DIR='+str(host),
        'GEN_FILE_BASENAME=FireSim-generated','DESIGN_V='+str(sim),
        'DRIVER='+str(FS/'src/main/cc/midasexamples/TestHarness.cc')+' '+str(C/'TestBarrier.cc'),
        'VERILATOR_FLAGS=-Wno-fatal -Wno-MULTIDRIVEN','CXX='+clang],[host/'VBarrierBank'],env=env)
    args=[binary,'+trace='+str(trace),'+seed=8491167','+max-cycles=10000000']
    m.stage('token-oracle-'+name,args,marker='BARRIER_BANK_HOST_TOKEN_PASS',env=env,timeout=3600)
    m.stage('token-negative-'+name,args+['+negative'],negative=True,
        marker='BARRIER_BANK_HOST_MISMATCH cycle=100 port=io_statsValid',env=env,timeout=600)
    line=next(l for l in (O/('token-oracle-'+name+'.log')).read_text().splitlines() if l.startswith('BARRIER_BANK_HOST_TOKEN_PASS '))
    r=json.loads(line.split(' ',1)[1]);assert r['checked_outputs']==(8192-3)*7
    return r

def area(host,name):
    save(O/(name+'-area-admission.json'),m.admission())
    collateral=sorted(host.glob('*.v'))+[host/'FireSim-generated.sv']
    tcl=host/'map.tcl'
    m.exact(tcl,'set_param general.maxThreads 2\n'+''.join(f'read_verilog -sv {{{p}}}\n' for p in collateral)+
        f'read_xdc {{{host/"FireSim-generated.synthesis.xdc"}}}\n'+
        'synth_design -mode out_of_context -top FPGATop -part xcu280-fsvh2892-2L-e\n'+
        'if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "blackbox"}\n'+
        f'report_utilization -file {{{host/"utilization.rpt"}}}\n'+
        f'report_utilization -hierarchical -file {{{host/"hierarchical.rpt"}}}\n'+
        f'write_checkpoint -force {{{host/"host.dcp"}}}\nexit 0\n')
    files=collateral+[host/'FireSim-generated.synthesis.xdc',tcl]
    pins={str(p):sha(p) for p in files};save(O/(name+'-map-inputs.json'),dict(files=pins))
    m.stage('map-'+name,['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal',
        '-log',host/'vivado.log','-source',tcl],[host/n for n in ['utilization.rpt','hierarchical.rpt','host.dcp']])
    assert all(sha(p)==h for p,h in pins.items())
    total=parser.parse_total((host/'utilization.rpt').read_text())
    parser.parse_hier((host/'hierarchical.rpt').read_text(),total)
    parser.crosschecks((host/'utilization.rpt').read_text(),total)
    return dict(resources={k:v['used'] for k,v in total.items()},
        outputs={str(host/n):sha(host/n) for n in ['utilization.rpt','hierarchical.rpt','host.dcp']})

def main():
    O.mkdir(exist_ok=True)
    lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(),'Adopt existing experiment; never restart'
    os.sched_setaffinity(0,CPUS);resource.setrlimit(resource.RLIMIT_AS,(64*2**30,)*2)
    # Successor launch requires complete predecessor cgroup release.
    cgroups=['/user.slice/user-1008.slice/user@1008.service/ec-opt4-barrier-banked-host-'+v+'-20261113.service' for v in ['r1','r2']]
    for proc in Path('/proc').iterdir():
        if not proc.name.isdigit(): continue
        try: assert not set(cgroups).intersection(l.split(':',2)[-1] for l in (proc/'cgroup').read_text().splitlines())
        except (OSError,ProcessLookupError): pass
    binding=read(C/'source-binding.json')
    predecessor_inputs=read(R/'inputs.json')['files']
    assert all(sha(p)==h for p,h in predecessor_inputs.items()), 'r2 immutable inputs changed'
    save(O/'predecessor-release.json',dict(utc=now(),cgroups=cgroups,all_released=True,predecessor_state_sha256=sha(R/'state.json'),predecessor_inputs_sha256=sha(R/'inputs.json')))
    assert all(sha(p)==h for p,h in binding['source_files'].items())
    assert all(sha(p)==h for p,h in binding['proof_files'].items())
    assert subprocess.check_output(['git','rev-parse','HEAD'],cwd=TREE,text=True).strip()==binding['hardware_commit']
    cfg=read(W/'candidates/dcache-field-read-system-r1-20261111/config.json')
    m.ST.update(schema='ec-complete-banked-barrier-experiment/1',**identity(),started_utc=now(),
        hardware_commit=binding['hardware_commit'],functional_baseline=binding['functional_baseline'],
        source_binding_sha256=sha(C/'source-binding.json'),cpus=sorted(CPUS),memory_limit_gib=64,
        fpga_access=False,whole_synthesis=False,full_system_fit=False,production_admission=False,
        slots=256,scope='Complete single barrier target/host and serial full-size 16x16 / 32x8 OOC screens. Not whole EC or shell FIT.')
    pins={str(p):sha(p) for p in [C/'controller.py',C/'prepare.py',C/'Emit.scala',C/'Host.scala',C/'TestBarrier.cc',C/'source-binding.json',Path(m.__file__),Path(parser.__file__)]}
    for p in cfg['compiler']+cfg['classpath']+[cfg['plugin']]:pins[p]=sha(p)
    for root in [P/'classes-Proof',R/'classes-Module']:
        pins.update({str(p):sha(p) for p in root.rglob('*.class')})
    for p in [P/'Reference-Proof-16/Barrier.v',P/'Candidate-Proof-16/Barrier.v',R/'Threaded16/VBarrierBank',R/'Threaded16/FireSim-generated.sv']:
        pins[str(p)]=sha(p)
    save(O/'inputs.json',dict(files=pins))
    m.update('ADMITTING_FULL_SIZE_BANKED_BARRIER_VALIDATION')
    save(O/'admission.json',m.admission())
    java=[cfg['java'],'-Xmx24G','-Xss16M','-XX:ActiveProcessorCount=2']
    basecp=':'.join(cfg['classpath'])
    cps={}
    # Adopt immutable proof classes; rerun full target checks to bind corrected sampling.
    inputs=read(P/'inputs.json')['files']
    assert all(sha(p)==h for p,h in inputs.items()), 'Predecessor pinned inputs changed'
    for name in ['target-oracle-16','target-negative-16']:
        r=read(P/(name+'-receipt.json'))
        assert r['accepted'] and sha(r['log'])==r['log_sha256']
    cps['Proof']=str(P/'classes-Proof')+':'+basecp
    receipt=read(R/'compile-Module-receipt.json')
    assert receipt['accepted'] and sha(receipt['log'])==receipt['log_sha256']
    assert all(sha(p)==h for p,h in receipt['outputs'].items())
    cps['Module']=str(R/'classes-Module')+':'+basecp
    save(O/'reused-classes.json',dict(predecessor=str(R),receipt_sha256=sha(R/'compile-Module-receipt.json'),class_hashes={p:h for p,h in pins.items() if p.endswith('.class')}))
    result={}
    for lanes in [16,8]:
        target={}
        for label in ['Reference','Candidate']:
            if lanes==16:
                target[label]=P/f'{label}-Proof-{lanes}/Barrier.v'
            else:
                out=O/f'{label}-Proof-{lanes}';out.mkdir();target[label]=out/'Barrier.v'
                m.stage(f'elaborate-{label}-{lanes}',java+['-cp',cps['Proof'],'barrierbankexperiment.Emit',label,str(lanes),out],[out/'Barrier.v'])
        tb,trace=testbench(lanes,target['Reference'],target['Candidate'])
        exe=O/f'obj-{lanes}/Vtb'
        m.stage(f'compile-target-{lanes}',['/usr/local/bin/verilator','--binary','--timing','--top-module','tb',
            '--Mdir',exe.parent,'-j','2','--output-split','10000','--output-split-cfuncs','200',
            '--x-initial','0','--x-assign','0','-Wno-fatal','-CFLAGS','-O0','-MAKEFLAGS','OPT_FAST=-O0 OPT_SLOW=-O0',
            target['Reference'],target['Candidate'],tb],[exe])
        m.stage(f'target-oracle-{lanes}',[exe],marker='BARRIER_BANK_TARGET_PASS cycles=8704',timeout=1800)
        positive=O/f'positive-reference-{lanes}-tokens.txt';os.link(trace,positive)
        trace.rename(O/f'reference-{lanes}-before-negative.txt')
        m.stage(f'target-negative-{lanes}',[exe,'+EC_MUTATE'],negative=True,
            marker='BARRIER_BANK_MISMATCH port=io_seen cycle=1000',timeout=300)
        if lanes==16:
            before=P/'positive-reference-16-tokens.txt'
            oldrows=[line.split() for line in before.read_text().splitlines()]
            newrows=[line.split() for line in positive.read_text().splitlines()]
            assert len(oldrows)==len(newrows)==8192
            # All seven input tokens are byte-equal. Original registered-output
            # row n+1 is exactly new post-edge row n, including every reset.
            assert all(a[:7]==b[:7] for a,b in zip(oldrows,newrows))
            assert all(newrows[i][7:]==oldrows[i+1][7:] for i in range(8191))
            save(O/'sampling-diagnosis.json',dict(input_tokens_byte_equal=True,registered_output_adjacent_edge_identity_checks=8191*7,predecessor_trace_sha256=sha(before),post_edge_trace_sha256=sha(positive),checks_weakened=False,original_target_comparisons_preserved=True))
        targethost=O/f'Host-target-{lanes}';targethost.mkdir()
        m.stage(f'elaborate-host-{lanes}',java+['-cp',cps['Module'],'freechips.rocketchip.system.Generator',
            '--target-dir',targethost,'--name','BarrierBank','--top-module',f'barrierbankexperiment.Host{lanes}',
            '--configs','firesim.midasexamples.NoConfig'],[targethost/'BarrierBank.fir',targethost/'BarrierBank.anno.json'])
        annotations=read(targethost/'BarrierBank.anno.json')
        assert sum(a.get('class','').endswith('FirrtlEnableModelMultiThreadingAnnotation') for a in annotations)==256//lanes
        hosts={};tokens={}
        for name in ['Threaded','Plain']:
            key=f'{name}{lanes}';host=O/key;host.mkdir();hosts[name]=host
            if key=='Threaded16':
                rec=read(R/'goldengate-Threaded16-receipt.json')
                assert rec['accepted'] and sha(rec['log'])==rec['log_sha256']
                assert all(sha(p)==h for p,h in rec['outputs'].items())
                for source in (R/key).iterdir():
                    if source.is_file() and source.name not in ['VBarrierBank','simulation.sv']:
                        shutil.copy2(source,host/source.name)
            else:
                m.stage('goldengate-'+key,java+['-cp',cps['Module'],'midas.stage.GoldenGateMain',
                '-i',targethost/'BarrierBank.fir','-td',host,'-faf',targethost/'BarrierBank.anno.json',
                '-ggcp','barrierbankexperiment','-ggcs',name+'Config','--output-filename-base','FireSim-generated'],
                [host/'FireSim-generated.sv',host/'FireSim-generated.synthesis.xdc'])
            fir=(host/'post-gen-sram-models.fir').read_text()
            assert ('module GHBarrierBucketBank_threaded :' in fir)==(name=='Threaded')
            assert 'debugView' not in fir and 'io_observe' not in fir
            save(O/(key+'-threading-audit.json'),dict(selected_type='GHBarrierBucketBank',selected_count=256//lanes,
                slots=256,lanes=lanes,proof_ports_absent=True,host_RTL_sha256=sha(host/'FireSim-generated.sv')))
            tokens[name]=compile_host(host,key,positive)
        assert tokens['Plain']['digest']==tokens['Threaded']['digest']
        save(O/f'validated-{lanes}.json',dict(target_cycles=8704,observations=263,tokens=tokens,
            source_binding_sha256=sha(C/'source-binding.json'),hardware_commit=binding['hardware_commit']))
        areas={name:area(hosts[name],name+str(lanes)) for name in ['Plain','Threaded']}
        savings={k:areas['Plain']['resources'][k]-areas['Threaded']['resources'][k] for k in areas['Plain']['resources']}
        result[str(lanes)]=dict(geometry=dict(slots=256,banks=256//lanes,lanes=lanes),tokens=tokens,area=areas,savings=savings)
        save(O/'paired-progress.json',result)
    assert all(sha(p)==h for p,h in pins.items())
    m.update('COMPLETED_FULL_SIZE_BANKED_BARRIER_SCREENS_NOT_FULL_EC',screens=result,
        ended_utc=now(),full_formal=False,full_system_fit=False,
        next='Consume exact measured full256 results; useful bank scheme still needs one-type/power2 whole-EC composition and complete DCache/host validation before any whole CAD.')
    save(O/'result.json',m.ST)

if __name__=='__main__':
    try:main()
    except Exception as exc:
        if m.ST:
            m.update('FAILED_WITH_EVIDENCE_VERSIONED_RECOVERY_REQUIRED',error=repr(exc),ended_utc=now())
            save(O/'failure.json',m.ST)
        raise
