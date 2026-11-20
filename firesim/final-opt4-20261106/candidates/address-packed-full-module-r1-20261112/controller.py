#!/usr/bin/python3
"""Private complete-module validation and paired map; no whole-host or FPGA work."""
import fcntl
import importlib.util
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
O = D/'build-logs/Opt4-address-packed-full-module-r1-20261112'
LOCAL = W/'candidates/address-packed-group-reduction-r2-20261112'
SOURCE = W/'Opt4-fit-dcache-field-read-prune-r1-20261111/chipyard/generators/boom/src/main/scala/lsu'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, live, now, read, save, sha

ST = {}
BUCKETS = ['bucketStore', 'bucketLoadFirst', 'bucketStoreFirst',
           'bucketStrictWriteRead', 'bucketFirstStore']


def exact(path, value):
    if path.exists():
        assert path.read_text() == value, ('immutable input changed', str(path))
    else:
        path.write_text(value)


def update(status=None, **values):
    ST.update(values, updated_utc=now())
    if status:
        ST['status'] = status
    save(O/'state.json', ST)


def prepare():
    O.mkdir(exist_ok=True)
    plan = read(LOCAL/'plan.json')
    assert sha(SOURCE/'PackageAddressStats.scala') == '58e9f8ec8b2ae65f28915825f21cf8dd2d07732b2243c473321d461ad4e57fe4'
    assert sha(SOURCE/'AddressBucketGrouped.scala') == plan['source_sha256']
    assert sha(LOCAL/'AddressBucketGrouped.scala') == plan['candidate_sha256']
    original = (SOURCE/'PackageAddressStats.scala').read_text()
    helper = (SOURCE/'AddressBucketGrouped.scala').read_text()
    candidate = (LOCAL/'AddressBucketGrouped.scala').read_text()
    # Bind the complete unchanged compaction/scatter code on both sides.
    marker = '    // Each scatter lane is unchanged.'
    common = helper[:helper.index('    VecInit((0 until slots).map { i =>', helper.index('  def histogram'))]
    assert candidate[:candidate.index(marker)] == common
    debug = '''
    val debugBuckets = Output(Vec(5, Vec(packetWindow, Vec(4, UInt(64.W)))))
    val debugBucketValid = Output(Vec(packetWindow, Bool()))
    val debugBucketSeq = Output(Vec(packetWindow, UInt(32.W)))'''
    observe = '\n'.join(f'  io.debugBuckets({k}) := {n}' for k,n in enumerate(BUCKETS))
    observe += '\n  io.debugBucketValid := bucketValid\n  io.debugBucketSeq := bucketSeq\n'
    for label, package, h in [('Reference', 'opt4packedref', helper), ('Candidate', 'opt4packedcandidate', candidate)]:
        module = original.replace('package boom.lsu', f'package {package}\nimport boom.lsu.AddressBucketUpdate', 1)
        exact(C/(label+'Module.scala'), module)
        exact(C/(label+'Helper.scala'), h.replace('package boom.lsu', f'package {package}', 1))
        proof = module.replace('    val idle = Output(Bool())', '    val idle = Output(Bool())'+debug, 1)
        pos = proof.rfind('\n}')
        proof = proof[:pos]+'\n'+observe+proof[pos:]
        # Source projection makes the proof-only instrumentation explicit.
        assert proof.replace(debug, '').replace('\n'+observe, '') == module
        exact(C/(label+'Proof.scala'), proof)
    exact(C/'AddressBucketUpdate.scala', (SOURCE/'AddressBucketUpdate.scala').read_text())
    cfgfile = W/'candidates/dcache-field-read-system-r1-20261111/config.json'
    cfg = read(cfgfile)
    paths = [C/'controller.py', C/'Emit.scala', C/'install.py', C/'README.md', cfgfile,
             LOCAL/'validation-inputs.json', LOCAL/'arithmetic-proof-receipt.json',
             SOURCE/'PackageAddressStats.scala', SOURCE/'AddressBucketGrouped.scala', SOURCE/'AddressBucketUpdate.scala',
             W/'candidates/address-group4-r1-20261111/frozen-tb.v',
             W/'candidates/mcrams-full-host-capacity-r1-20261112/resource_parser.py']
    paths += list(C.glob('*Module.scala'))+list(C.glob('*Proof.scala'))+list(C.glob('*Helper.scala'))+[C/'AddressBucketUpdate.scala']
    paths += [Path(p) for p in cfg['classpath']+cfg['compiler']+[cfg['plugin']]]
    pins = dict(schema='ec-private-packed-complete-module/1',
        functional_baseline=plan['functional_baseline'], derived_parent='3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c',
        files={str(p): sha(p) for p in paths},
        scope='Complete actual PackageAddressStats target: unchanged state/update priorities and public interface. Private proof observes all5120 bucketwords plus valid/sequence, including invalid payload. Paired area excludes proof-only ports.',
        public_outputs=52, debug_bucket_words=5120, debug_valid_words=256, debug_sequence_words=256,
        finite_regression_not_formal=True, complete_generated_host_area=False,
        target_registers_added=0, full_host_synthesis=False, fpga_access=False, production_admission=False,
        cpus=[214,215], memory_limit_gib=64,
        next_gates=['Complete-module finite parity including invalid payload', 'Actual paired full-module default map',
                    'Composition and source-bound GoldenGate/ABI/target-cycle validation', 'Fresh whole-host post-opt capacity'])
    exact(C/'inputs.json', __import__('json').dumps(pins, indent=2, sort_keys=True)+'\n')
    return cfg, pins


def stage(name, argv, outputs=(), require=None, negative=False):
    receipt = O/(name+'-receipt.json')
    if receipt.exists():
        r = read(receipt)
        assert r['accepted'] and all(sha(p)==h for p,h in r['outputs'].items())
        assert sha(r['log']) == r['log_sha256']
        return Path(r['log'])
    log = O/(name+'.log')
    assert not log.exists(), 'Keep partial attempt; versioned recovery required'
    start = time.monotonic()
    with log.open('xb', buffering=0) as f:
        child = subprocess.Popen(list(map(str, ['nice', '-n', '10', *argv])), cwd=O,
            stdin=subprocess.DEVNULL, stdout=f, stderr=subprocess.STDOUT,
            env={**os.environ, 'LD_LIBRARY_PATH':'', 'OMP_NUM_THREADS':'2', 'MAKEFLAGS':'-j2'})
        update('RUNNING_'+name.upper(), active_stage=name, child=identity(child.pid))
        while child.poll() is None:
            try:
                child.wait(timeout=30)
            except subprocess.TimeoutExpired:
                pass
            os.fsync(f.fileno())
            update(child=identity(child.pid), stage_wall_seconds=time.monotonic()-start, log_bytes=log.stat().st_size)
    accepted = child.returncode != 0 if negative else child.returncode == 0
    text = log.read_text(errors='replace')
    accepted = accepted and (require is None or require in text)
    r = dict(argv=list(map(str, argv)), returncode=child.returncode, accepted=accepted, negative=negative,
        log=str(log), log_sha256=sha(log), host_wall_seconds=time.monotonic()-start,
        outputs={str(p):sha(p) for p in outputs if Path(p).is_file()},
        missing_outputs=[str(p) for p in outputs if not Path(p).is_file()])
    save(receipt, r)
    update(child={})
    assert accepted and not r['missing_outputs'], (name, r)
    return log


def admission():
    while True:
        mem = int(next(x.split()[1] for x in Path('/proc/meminfo').read_text().splitlines() if x.startswith('MemAvailable:')))
        disk = shutil.disk_usage(W).free
        load = float(Path('/proc/loadavg').read_text().split()[0])
        workers = []
        dedicated = []
        for proc in Path('/proc').iterdir():
            if not proc.name.isdigit():
                continue
            try:
                argv=(proc/'cmdline').read_bytes().split(b'\0')
                affinity=os.sched_getaffinity(int(proc.name))
                if proc.stat().st_uid==os.getuid() and len(affinity)<=8 and affinity&{214,215} and int(proc.name)!=os.getpid():
                    dedicated.append(identity(int(proc.name)))
                if argv and argv[0].endswith(b'/unwrapped/lnx64.o/vivado') and any(b'/data1/gzh/EC/' in a for a in argv):
                    workers.append(identity(int(proc.name)))
            except (FileNotFoundError, ProcessLookupError, PermissionError):
                pass
        if mem >= 256*2**20 and disk >= 60*2**30 and load < 64 and len(workers)<8 and not dedicated:
            return dict(memory_kib=mem, disk_bytes=disk, load1=load, project_vivado=workers)
        update('WAITING_PRIVATE_MODULE_RESOURCES_NO_SIGNALS', memory_kib=mem, disk_bytes=disk,
               load1=load, existing_vivado=workers, dedicated_overlap=dedicated)
        time.sleep(30)


def testbench(reference, candidate):
    rtl_texts = [reference.read_text(), candidate.read_text()]
    register_names = [set(re.findall(r'\breg \[63:0\]\s+(\w+);', text)) for text in rtl_texts]
    def ports(path):
        header=path.read_text().split(');',1)[0]
        return re.findall(r'\b(input|output)\s*(\[\d+:\d+\])?\s+(\w+)',header)
    p=ports(reference)
    assert p==ports(candidate)
    inputs=[(w,n) for direction,w,n in p if direction=='input']
    outputs=[(w,n) for direction,w,n in p if direction=='output']
    assert len([n for w,n in outputs if n.startswith('io_debugBuckets_')])==5120
    assert len([n for w,n in outputs if not n.startswith('io_debug')])==52
    text=['`timescale 1ns/1ps','module tb;']
    text += [f"reg {w} {n}=0;" for w,n in inputs]
    text += ['always #5 clock=~clock;', 'integer i,phase,seq; integer valid_edges=0; integer idle_edges=0;']
    text += [f'wire {w} a_{n},b_{n};' for w,n in outputs]
    for label,top in [('a','PackedProofReference'),('b','PackedProofCandidate')]:
        con=[f'.{n}({n})' for w,n in inputs]+[f'.{n}({label}_{n})' for w,n in outputs]
        text.append(f'{top} {label}('+','.join(con)+');')
    text.append('task compare; begin')
    text += [f'if(a_{n} !== b_{n})begin $display("PACKED_MODULE_MISMATCH port={n} cycle=%0d a=%h b=%h",i,a_{n},b_{n});$fatal;end' for w,n in outputs]
    text += ['end endtask','task seed_invalid; begin']
    # Equal arbitrary payload seeds are applied only in the private testbench.
    # Both global reset and valid-bit observations remain active.
    seed=0x8491167D3656AEC4
    for n in BUCKETS:
        for i in range(256):
            for g in range(4):
                seed=(seed*6364136223846793005+1442695040888963407)&((1<<64)-1)
                value=[seed,(1<<64)-1,(1<<64)-2,0][(i+g)%4]
                reg=f'{n}_{i}_{g}'
                # These are the actual source register names in emitted RTL.
                assert all(reg in names for names in register_names), reg
                text += [f"a.{reg}=64'h{value:016x}; b.{reg}=64'h{value:016x};"]
    text += ['end endtask','initial begin','i=-1; reset=1; io_resetStats=0; #1; seed_invalid; #1; compare;',
             'for(i=0;i<6144;i=i+1)begin','@(negedge clock);']
    old=(W/'candidates/address-group4-r1-20261111/frozen-tb.v').read_text()
    stimulus=old.split('@(negedge clock);',1)[1].split('@(posedge clock);#1;',1)[0]
    text.append(stimulus)
    text += ['// A normal reset without resetStats retains arbitrary invalid bucket payload.',
             'if(i>=3000 && i<=3002)begin reset=1;io_resetStats=0;end',
             'if(i==3003)seed_invalid;',
             '// Deliberate actual invalid-register mutation must be detected by the same monitor.',
             "if(i==1000 && $test$plusargs(\"EC_MUTATE\"))b.bucketStrictWriteRead_255_3=b.bucketStrictWriteRead_255_3 ^ 64'h1;",
             '#1; compare; @(posedge clock);#1;compare;',
             'if(a_io_statsValid)valid_edges=valid_edges+1;',
             'if(a_io_idle)idle_edges=idle_edges+1;', 'end',
             'if(valid_edges<100 || idle_edges<10)$fatal;',
             f'$display("PACKED_COMPLETE_MODULE_PARITY_PASS cycles=6144 public_outputs=52 bucket_words=5120 valid_words=256 sequence_words=256 checks_per_edge={len(outputs)} invalid_seed=1 normal_reset=1 valid_edges=%0d idle_edges=%0d",valid_edges,idle_edges);$finish;',
             'end','endmodule']
    tb=O/'tb.v';exact(tb,'\n'.join(text)+'\n')
    save(O/'generated-testbench-binding.json', dict(testbench=str(tb), sha256=sha(tb),
        reference_rtl_sha256=sha(reference),candidate_rtl_sha256=sha(candidate),
        monitor_outputs=len(outputs),bucket_words=5120,seeded_equal_invalid_payload=True,
        negative_mutation='Actual candidate invalid bucket register bit flip; same comparison monitor must reject',
        finite_only=True, production_inputs_changed=False))
    return tb


def main():
    cfg,pins=prepare()
    if '--prepare-only' in sys.argv:
        print('PREPARED_PRIVATE_COMPLETE_MODULE_NO_LIVE_INPUT_EDITS')
        return
    lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    old=read(O/'state.json')
    assert not live(old) and not live(old.get('child',{})), 'Adopt live private module job'
    assert all(sha(p)==h for p,h in pins['files'].items())
    r=read(D/'build-logs/Opt4-address-packed-group-reduction-r2-20261112/result.json')
    assert r['status']=='PASS_LOCAL_ACTUAL_HISTOGRAM_NOT_COMPLETE_MODULE_OR_AREA'
    assert r['actual_output_checks']==8388608 and r['inputs_sha256']==sha(LOCAL/'validation-inputs.json')
    ST.update(**identity(),schema=pins['schema'],functional_baseline=pins['functional_baseline'],
        derived_parent=pins['derived_parent'],started_utc=now(),inputs_sha256=sha(C/'inputs.json'),
        cpus=pins['cpus'],memory_limit_gib=64,full_host_synthesis=False,fpga_access=False,
        production_admission=False,scope=pins['scope'])
    update('ADMITTING_PRIVATE_COMPLETE_MODULE_VALIDATION')
    save(O/'admission.json',admission())
    os.sched_setaffinity(0,{214,215});resource.setrlimit(resource.RLIMIT_AS,(64*2**30,)*2)
    cp=':'.join(cfg['classpath'])
    java=[cfg['java'],'-Xmx20G','-Xss8M','-XX:ActiveProcessorCount=2']
    proofs={}
    production={}
    for mode in ['Proof','Module']:
        cl=O/('classes-'+mode);cl.mkdir(exist_ok=True)
        stage('compile-'+mode,java+['-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main',
                '-classpath',cp,'-Xplugin:'+cfg['plugin'],'-d',cl,C/'AddressBucketUpdate.scala',
                C/'ReferenceHelper.scala',C/('Reference'+mode+'.scala'),
                C/'CandidateHelper.scala',C/('Candidate'+mode+'.scala'),C/'Emit.scala'],[cl/'opt4packedfull/Emit$.class'])
        for label in ['Reference','Candidate']:
            out=O/(label+'-'+mode);out.mkdir(exist_ok=True)
            top='FPGATop' if mode=='Module' else 'Packed'+mode+label
            rtl=out/(top+'.v')
            stage('elaborate-'+label+'-'+mode,java+['-cp',str(cl)+':'+cp,'opt4packedfull.Emit',label,mode,out],[rtl])
            (proofs if mode=='Proof' else production)[label]=rtl
    tb=testbench(proofs['Reference'],proofs['Candidate'])
    exe=O/'obj/Vtb'
    stage('parity-compile',['/usr/local/bin/verilator','--binary','--timing','--top-module','tb',
        '--Mdir',O/'obj','-j','2','--output-split','10000','--output-split-cfuncs','200',
        '--x-initial','0','--x-assign','0','-Wno-fatal',
        '-DRANDOMIZE_REG_INIT','-DRANDOMIZE_MEM_INIT',"-DRANDOM=32'h0",'-CFLAGS','-O0',
        '-MAKEFLAGS','OPT_FAST=-O0 OPT_SLOW=-O0',proofs['Reference'],proofs['Candidate'],tb],[exe])
    stage('parity-positive',[exe],require='PACKED_COMPLETE_MODULE_PARITY_PASS cycles=6144')
    stage('parity-invalid-register-mutation',[exe,'+EC_MUTATE'],negative=True,
          require='PACKED_MODULE_MISMATCH port=io_debugBuckets_3_255_3 cycle=1000')
    update('PASS_COMPLETE_MODULE_FINITE_PARITY_PAIRED_AREA_NEXT',finite_parity_pass=True,
        monitor_outputs=5684,complete_formal_equivalence=False,proof_only_ports_excluded_from_area=True)
    save(O/'verified-parity.json',ST)
    parser=W/'candidates/mcrams-full-host-capacity-r1-20261112/resource_parser.py'
    spec=importlib.util.spec_from_file_location('strict_packed_complete_module_parser',parser)
    p=importlib.util.module_from_spec(spec);spec.loader.exec_module(p)
    maps={}
    for label in ['Reference','Candidate']:
        # Sequential complete-module maps; no additional whole-host process.
        update('ADMITTING_PAIRED_FULL_MODULE_'+label.upper())
        save(O/(label+'-map-admission.json'),admission())
        out=O/(label+'-area');out.mkdir(exist_ok=True)
        util=out/'utilization.rpt';hier=out/'hierarchical.rpt';dcp=out/'module.dcp'
        tcl=out/'map.tcl';rtl=production[label];top='FPGATop'
        exact(tcl,'set_param general.maxThreads 2\n'+f'read_verilog {{{rtl}}}\n'+
            f'synth_design -mode out_of_context -top {top} -part xcu280-fsvh2892-2L-e\n'+
            'if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "blackbox"}\n'+
            f'report_utilization -file {{{util}}}\nreport_utilization -hierarchical -file {{{hier}}}\n'+
            f'write_checkpoint -force {{{dcp}}}\nexit 0\n')
        stage('map-'+label,['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal',
            '-log',out/'vivado.log','-source',tcl],[util,hier,dcp])
        total=p.parse_total(util.read_text());p.parse_hier(hier.read_text(),total);p.crosschecks(util.read_text(),total)
        maps[label]=dict(resources=total,rtl_sha256=sha(rtl),utilization_sha256=sha(util),
                         hierarchical_sha256=sha(hier),checkpoint_sha256=sha(dcp),scope='Complete target module OOC, not GoldenGate host')
        save(O/'paired-map-progress.json',maps)
    saving=maps['Reference']['resources']['CLB LUTs']['used']-maps['Candidate']['resources']['CLB LUTs']['used']
    update('COMPLETE_PRIVATE_MODULE_PARITY_AND_PAIRED_AREA_NOT_WHOLE_FIT',child={},completed_utc=now(),
        maps=maps,complete_module_lut_saving=saving,production_admission=False,
        full_host_fit_unknown=True,debug_latency_unchanged_by_source=True,
        next='If actual module gain is useful, verify source-bound composition/GoldenGate/ABI and full target cycles, then fresh whole-host capacity. No automatic admission from this OOC map.')
    save(O/'result.json',ST)


if __name__=='__main__':
    try:
        main()
    except Exception as exc:
        if ST:
            update('FAILED_WITH_EVIDENCE_NO_BLIND_RESTART',error=repr(exc))
        raise
