#!/usr/bin/python3
"""Actual complete barrier parity and paired GoldenGate host area, no board IO."""
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

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'build-logs/Opt4-barrier-fullmodule-host-pair-r1-20261112'
SOURCE = W/'Opt4-fit-dcache-field-read-prune-r1-20261111/chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/BarrierLatencyStats.scala'
PRIVATE = W/'candidates/barrier-valid-masked-storage-r1-20261112'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, live, now, read, save, sha

ST = {}


def exact(p, value):
    if p.exists():
        assert p.read_text() == value, ('Immutable input changed', str(p))
    else:
        p.write_text(value)


def update(status, **values):
    ST.update(status=status, updated_utc=now(), **values)
    save(O/'state.json', ST)


def prepare():
    O.mkdir(exist_ok=True)
    plan = read(PRIVATE/'plan.json')
    assert sha(SOURCE) == plan['source_sha256']
    assert sha(PRIVATE/'BarrierLatencyStats.scala') == plan['candidate_sha256']
    debug = '\n    val debugView = Output(Vec(window, UInt(161.W)))'
    observe = '\n  for (i <- 0 until window) {\n    io.debugView(i) := Cat(buckets.valid(i), buckets.seq(i), buckets.count(i), buckets.requestCycleSum(i))\n  }\n'
    paths = [C/'controller.py', C/'Emit.scala', C/'install.py', SOURCE,
             PRIVATE/'BarrierLatencyStats.scala', PRIVATE/'plan.json',
             W/'candidates/mcrams-full-host-capacity-r1-20261112/resource_parser.py']
    for label, original in [('Reference', SOURCE), ('Candidate', PRIVATE/'BarrierLatencyStats.scala')]:
        package = 'barrierpair'+label.lower()
        text = original.read_text().replace('package freechips.rocketchip.guardiancouncil',
            'package '+package+'\nimport freechips.rocketchip.guardiancouncil.GH_GlobalParams', 1)
        exact(C/(label+'Module.scala'), text)
        assert text.count('    val seen = Output(UInt(64.W))') == 1
        proof = text.replace('    val seen = Output(UInt(64.W))',
            '    val seen = Output(UInt(64.W))'+debug, 1)
        pos = proof.rfind('\n}')
        proof = proof[:pos]+observe+proof[pos:]
        assert proof.replace(debug, '').replace(observe, '') == text
        exact(C/(label+'Proof.scala'), proof)
        paths += [C/(label+'Module.scala'), C/(label+'Proof.scala')]
    cfgfile = W/'candidates/dcache-field-read-system-r1-20261111/config.json'
    cfg = read(cfgfile)
    paths += [cfgfile]+[Path(p) for p in cfg['compiler']+cfg['classpath']+[cfg['plugin']]]
    pins = dict(schema='ec-private-complete-barrier-host-pair/1',
        functional_baseline=plan['functional_baseline'], derived_parent=plan['derived_parent'],
        files={str(p):sha(p) for p in paths}, cpus=[218,219], memory_limit_gib=64,
        target_slots=256, proof_outputs=263, target_cycle_changes=0,
        no_counter_narrowing=True, full_host_synthesis=False, fpga_access=False,
        production_admission=False, paired_area_scope='Complete GoldenGate FPGATop for isolated actual barrier module, same MC config on both sides; proof-only state views excluded')
    exact(C/'inputs.json', json.dumps(pins, indent=2, sort_keys=True)+'\n')
    return cfg, pins


def stage(name, argv, outputs=(), marker=None, negative=False, timeout=None):
    log = O/(name+'.log')
    assert not log.exists(), 'Preserve attempt; independently version a diagnosed recovery'
    t = time.monotonic()
    with log.open('xb', buffering=0) as f:
        child = subprocess.Popen(list(map(str, argv)), cwd=O, stdin=subprocess.DEVNULL,
            stdout=f, stderr=subprocess.STDOUT,
            env={**os.environ, 'LD_LIBRARY_PATH':'', 'OMP_NUM_THREADS':'2', 'MAKEFLAGS':'-j2'})
        update('RUNNING_'+name.upper(), child=identity(child.pid), active_stage=name)
        while child.poll() is None:
            try:
                child.wait(timeout=20)
            except subprocess.TimeoutExpired:
                pass
            if timeout and time.monotonic()-t > timeout and child.poll() is None:
                child.terminate()
                child.wait(timeout=30)
                raise TimeoutError((name, timeout))
            update('RUNNING_'+name.upper(), child=identity(child.pid), stage_seconds=time.monotonic()-t)
    accepted = child.returncode != 0 if negative else child.returncode == 0
    accepted = accepted and (marker is None or marker in log.read_text(errors='replace'))
    r = dict(argv=list(map(str, argv)), returncode=child.returncode, accepted=accepted,
        negative=negative, log=str(log), log_sha256=sha(log), seconds=time.monotonic()-t,
        outputs={str(p):sha(p) for p in outputs if p.is_file()},
        missing_outputs=[str(p) for p in outputs if not p.is_file()])
    save(O/(name+'-receipt.json'), r)
    update('COMPLETED_'+name.upper(), child={})
    assert accepted and not r['missing_outputs'], (name, r)


def admission():
    while True:
        mem = int(next(l.split()[1] for l in Path('/proc/meminfo').read_text().splitlines() if l.startswith('MemAvailable:')))
        load = float(Path('/proc/loadavg').read_text().split()[0])
        disk = shutil.disk_usage(W).free
        workers, overlap = [], []
        for p in Path('/proc').iterdir():
            if not p.name.isdigit():
                continue
            try:
                args = (p/'cmdline').read_bytes().split(b'\0')
                affinity = os.sched_getaffinity(int(p.name))
                if args and args[0].endswith(b'/unwrapped/lnx64.o/vivado') and any(b'/data1/gzh/EC/' in a for a in args):
                    workers.append(int(p.name))
                if p.stat().st_uid == os.getuid() and int(p.name) != os.getpid() and len(affinity)<=8 and affinity&{218,219}:
                    overlap.append(int(p.name))
            except (OSError, ProcessLookupError):
                pass
        if mem>=256*2**20 and load<64 and disk>=60*2**30 and len(workers)<8 and not overlap:
            return dict(utc=now(), available_memory_kib=mem, load1=load, free_disk_bytes=disk,
                existing_project_vivado=workers, cpu_overlap=overlap)
        update('WAITING_PRIVATE_MODULE_RESOURCES_NO_SIGNALS', memory_kib=mem,
            load1=load, free_disk_bytes=disk, existing_vivado=workers, cpu_overlap=overlap)
        time.sleep(30)


def testbench():
    reference = O/'Reference-Proof/Barrier.v'
    candidate = O/'Candidate-Proof/Barrier.v'
    def ports(path):
        header = path.read_text().split(');',1)[0]
        result = []
        for direction, width, name in re.findall(r'\b(input|output)\s*(\[[^\]]+\])?\s*(\w+)\s*[,\n]', header+'\n'):
            result.append((direction, width, name))
        return result
    ps = ports(reference)
    assert ps == ports(candidate), 'Target interfaces differ'
    inputs = [p for p in ps if p[0]=='input']
    outputs = [p for p in ps if p[0]=='output']
    assert len(outputs)==263, len(outputs)
    lines = ['module tb;', 'integer cycle;', "reg [63:0] rng = 64'h4d595df4d0f33173;"]
    for _, width, name in inputs:
        lines.append(f'reg {width} {name};')
    for _, width, name in outputs:
        lines += [f'wire {width} r_{name};', f'wire {width} c_{name};']
    for label, prefix in [('Reference','r'),('Candidate','c')]:
        args = [f'.{name}({name})' for _,_,name in inputs]+[f'.{name}({prefix}_{name})' for _,_,name in outputs]
        lines.append('Barrier'+label+' dut'+label+'('+','.join(args)+');')
    lines += ['task check;', 'begin']
    for _,_,name in outputs:
        lines.append(f'if (r_{name} !== c_{name}) begin $display("BARRIER_MISMATCH port={name} cycle=%0d",cycle); $fatal(1); end')
    lines += ['end','endtask','initial begin']
    lines += [name+" = '0;" for _,_,name in inputs]
    lines += ['reset=1;', '#1; clock=1; #1; clock=0; #1;',
        'for(cycle=0;cycle<8192;cycle=cycle+1) begin',
        'rng=rng^(rng<<13); rng=rng^(rng>>7); rng=rng^(rng<<17);',
        'reset=(cycle==3072 || cycle==6144);',
        'io_resetStats=(cycle==2048 || cycle==4096 || cycle==7168);',
        'io_event_valid=(rng[3:0]!=0);',
        'io_event_bits={20\'d0,rng[11:0]};',
        'io_safeWatermark={20\'d0,rng[23:12]};',
        "io_currentCycle=(cycle<4096)?(64'd100000+cycle):rng;",
        'io_fatalProtocolError=(cycle==6000);',
        # Directed accumulation, resolution/reallocation, slot collision,
        # immediate events, and reset priority.
        'if(cycle<512) begin io_safeWatermark=0; io_event_bits=1+(cycle%255); io_currentCycle=cycle; end',
        'if(cycle>=512 && cycle<768) begin io_safeWatermark=cycle-511; io_event_bits=cycle-255; end',
        '#1; check; clock=1; #1; clock=0; #1;',
        'if ($test$plusargs("EC_MUTATE") && cycle==1000) begin',
        "force dutCandidate.seen = 64'hdeadbeef12345678; #1; end",
        'check;', 'end',
        '$display("BARRIER_COMPLETE_MODULE_PARITY_PASS cycles=8192 outputs=263"); $finish;',
        'end','endmodule']
    tb=O/'tb.v';exact(tb,'\n'.join(lines)+'\n')
    return tb


def main():
    cfg,pins=prepare()
    if '--prepare-only' in sys.argv:
        print(json.dumps(dict(status='PREPARED_IMMUTABLE_SOURCE_BOUND_FULL_MODULE_PAIR', inputs_sha256=sha(C/'inputs.json'))))
        return
    lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(), 'Adopt existing attempt, never restart'
    assert all(sha(p)==h for p,h in pins['files'].items())
    os.sched_setaffinity(0,{218,219})
    resource.setrlimit(resource.RLIMIT_AS,(64*2**30,64*2**30))
    ST.update(schema='ec-private-complete-barrier-host-pair/1', **identity(),
        started_utc=now(), functional_baseline=pins['functional_baseline'],
        inputs_sha256=sha(C/'inputs.json'), fpga_access=False, production_admission=False,
        complete_formal_equivalence=False, full_system_fit=False, cpus=[218,219])
    update('ADMITTING_PRIVATE_MODULE_TASK')
    save(O/'admission.json',admission())
    java=[cfg['java'],'-Xmx24G','-Xss8M','-XX:ActiveProcessorCount=2']
    models={}
    for kind in ['Proof','Module']:
        classes=O/('classes-'+kind);classes.mkdir()
        compiler=java+['-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main',
            '-classpath',':'.join(cfg['classpath']),'-Xplugin:'+cfg['plugin'],'-d',classes]
        stage('compile-'+kind, compiler+[C/('Reference'+kind+'.scala'), C/('Candidate'+kind+'.scala'), C/'Emit.scala'],
            [classes/'barrierpair/Emit.class'])
        cp=str(classes)+':'+':'.join(cfg['classpath'])
        for label in ['Reference','Candidate']:
            out=O/(label+'-'+kind);out.mkdir()
            stage('elaborate-'+label+'-'+kind,java+['-cp',cp,'barrierpair.Emit',label,kind,out],
                [out/'Barrier.v',out/'Barrier.fir',out/'Barrier.anno.json'])
        models[kind]=cp
    tb=testbench();exe=O/'obj/Vtb'
    stage('parity-compile',['/usr/local/bin/verilator','--binary','--timing','--top-module','tb',
        '--Mdir',O/'obj','-j','2','--output-split','10000','--output-split-cfuncs','200',
        '--x-initial','0','--x-assign','0','-Wno-fatal','-CFLAGS','-O0',
        '-MAKEFLAGS','OPT_FAST=-O0 OPT_SLOW=-O0',
        O/'Reference-Proof/Barrier.v',O/'Candidate-Proof/Barrier.v',tb],[exe])
    stage('parity-positive',[exe],marker='BARRIER_COMPLETE_MODULE_PARITY_PASS cycles=8192 outputs=263',timeout=1800)
    stage('parity-actual-register-mutation',[exe,'+EC_MUTATE'],negative=True,
        marker='BARRIER_MISMATCH port=io_seen cycle=1000',timeout=300)
    update('PASS_COMPLETE_MODULE_FINITE_PARITY_HOST_GENERATION_NEXT',finite_parity_pass=True)
    save(O/'verified-parity.json',ST)
    parserpath=W/'candidates/mcrams-full-host-capacity-r1-20261112/resource_parser.py'
    spec=importlib.util.spec_from_file_location('barrier_pair_parser',parserpath)
    parser=importlib.util.module_from_spec(spec);spec.loader.exec_module(parser)
    results={}
    for label in ['Reference','Candidate']:
        host=O/(label+'-host');host.mkdir()
        target=O/(label+'-Module')
        stage('goldengate-'+label,java+['-cp',models['Module'],'midas.stage.GoldenGateMain',
            '-i',target/'Barrier.fir','-td',host,'-faf',target/'Barrier.anno.json',
            '-ggcp','barrierpair','-ggcs','MCConfig','--output-filename-base','FireSim-generated'],
            [host/'FireSim-generated.sv',host/'FireSim-generated.synthesis.xdc'])
        save(O/(label+'-area-admission.json'),admission())
        tcl=host/'map.tcl';util=host/'utilization.rpt';hier=host/'hierarchical.rpt';dcp=host/'host.dcp'
        collateral=list(host.glob('*.v'))+[host/'FireSim-generated.sv']
        assert collateral
        exact(tcl,'set_param general.maxThreads 2\n'+
            ''.join(f'read_verilog -sv {{{p}}}\n' for p in collateral)+
            f'read_xdc {{{host/"FireSim-generated.synthesis.xdc"}}}\n'+
            'synth_design -mode out_of_context -top FPGATop -part xcu280-fsvh2892-2L-e\n'+
            'if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "blackbox"}\n'+
            f'report_utilization -file {{{util}}}\nreport_utilization -hierarchical -file {{{hier}}}\nwrite_checkpoint -force {{{dcp}}}\nexit 0\n')
        stage('map-'+label,['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal',
            '-log',host/'vivado.log','-source',tcl],[util,hier,dcp])
        total=parser.parse_total(util.read_text())
        parser.parse_hier(hier.read_text(),total);parser.crosschecks(util.read_text(),total)
        results[label]=dict(resources={k:v['used'] for k,v in total.items()},
            outputs={str(p):sha(p) for p in [util,hier,dcp,host/'FireSim-generated.sv',tcl]})
        save(O/'paired-host-progress.json',results)
    savings={k:results['Reference']['resources'][k]-results['Candidate']['resources'][k]
        for k in results['Reference']['resources']}
    update('COMPLETE_PARITY_AND_PAIRED_GENERATED_HOST_AREA_NOT_FULL_EC',child={},
        completed_utc=now(), results=results, savings=savings,
        next='Assess actual host area and memory resources; useful gain still needs source-bound composition, full target-cycle/ABI gates, then fresh complete-host postopt and shell physical certification.')
    save(O/'result.json',ST)


if __name__=='__main__':
    try:
        main()
    except Exception as exc:
        if ST:
            update('FAILED_WITH_EVIDENCE_VERSIONED_CORRECTION_REQUIRED',error=repr(exc),ended_utc=now())
            save(O/'failure.json',ST)
        raise
