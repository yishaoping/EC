#!/usr/bin/python3
"""Source-bound 80-source/256-slot FAME5 histogram experiment. No board IO."""
import fcntl
import importlib.util
import json
import os
from pathlib import Path
import resource
import shutil
import subprocess
import sys
import time

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'build-logs/Opt4-address-histogram-fame5-r1-20261112'
FS = W/'C4/chipyard/sims/firesim/sim'
SOURCE = W/'candidates/address-packed-full-module-r1-20261112/ReferenceHelper.scala'
PARENT = W/'candidates/address-packed-full-module-r1-20261112/ReferenceModule.scala'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, now, read, save, sha

ST = {}
CPUS = {220, 221}


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
    original = SOURCE.read_text()
    # The existing method remains byte-equal. Only add its single-destination
    # projection, using exactly the same compact/scatter/reduce expressions.
    projection = '''
  def lookup(keys: Seq[UInt], counts: Seq[Seq[UInt]], bounds: Seq[Int], key: UInt): Vec[UInt] = {
    require(keys.size == 80 && counts.size == 80 && key.getWidth == 8)
    val groups = keys.indices.grouped(4).map { ids =>
      compact4(ids.map(keys(_)), ids.map(counts(_)), bounds)
    }.toSeq
    VecInit(bounds.indices.map { g =>
      sum(groups.map(group => (scatter(group, key, g, bounds(g)),
        4 * bounds(g)))).pad(64)
    })
  }
'''
    text = original.replace('package opt4packedref', 'package sourceprojected', 1)
    pos = text.rfind('\n}')
    text = text[:pos]+projection+text[pos:]
    assert text.replace(projection, '').replace('package sourceprojected', 'package opt4packedref', 1) == original
    exact(C/'SourceProjected.scala', text)
    cfgpath = W/'candidates/dcache-field-read-system-r1-20261111/config.json'
    cfg = read(cfgpath)
    fame = FS/'midas/src/main/scala/midas/passes/fame'
    paths = [C/'Histogram.scala', C/'SourceProjected.scala', C/'TestHistogram.cc', C/'README.md',
             C/'controller.py', C/'install.py', SOURCE, PARENT, cfgpath,
             fame/'MultiThreader.scala', fame/'MuxingMultithreader.scala',
             fame/'MultiThreadFAME5Models.scala', fame/'ImplementThreadedMems.scala']
    paths += [Path(p) for p in cfg['compiler']+cfg['classpath']+[cfg['plugin']]]
    pins = dict(schema='ec-address-histogram-fame5-prototype/1',
        functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8',
        files={str(p):sha(p) for p in paths}, cpus=sorted(CPUS), memory_limit_gib=64,
        full_size=dict(sources=80, slots=256, granularities=4, bounds=[8,3,2,1],
                       output_width_per_bucket=256),
        unchanged_target_register_count=0, target_cycle_changes=0,
        source_projection_reversal_pass=True,
        smoke_slots=[2,4], same_harness_area=['PlainConfig','ThreadedConfig'],
        fpga_access=False, full_host_synthesis=False, production_admission=False,
        scope='Actual strict address histogram only; not complete PackageAddressStats or whole EC',
        next='2/4-thread actual generated-host token smoke; full256 plain/threaded oracle and paired host maps. Reject nonpositive LUT gain; integration requires full-module/ABI/cycle proofs and fresh whole capacity.')
    exact(C/'inputs.json', json.dumps(pins, indent=2, sort_keys=True)+'\n')
    return cfg, pins


def stage(name, argv, outputs=(), marker=None, negative=False, env=None, timeout=None):
    log = O/(name+'.log')
    assert not log.exists(), 'Preserve evidence; version a diagnosed correction'
    start = time.monotonic()
    with log.open('xb', buffering=0) as f:
        child = subprocess.Popen(list(map(str, argv)), cwd=O,
            stdin=subprocess.DEVNULL, stdout=f, stderr=subprocess.STDOUT,
            env=env or {**os.environ, 'LD_LIBRARY_PATH':'', 'OMP_NUM_THREADS':'2'})
        update('RUNNING_'+name.upper(), child=identity(child.pid), active_stage=name)
        while child.poll() is None:
            try:
                child.wait(timeout=30)
            except subprocess.TimeoutExpired:
                pass
            if timeout and time.monotonic()-start > timeout and child.poll() is None:
                child.terminate(); child.wait(timeout=30)
                raise TimeoutError((name, timeout))
            update('RUNNING_'+name.upper(), child=identity(child.pid), stage_seconds=time.monotonic()-start)
    accepted = child.returncode != 0 if negative else child.returncode == 0
    accepted = accepted and (marker is None or marker in log.read_text(errors='replace'))
    receipt = dict(argv=list(map(str, argv)), returncode=child.returncode,
        accepted=accepted, negative=negative, log=str(log), log_sha256=sha(log),
        seconds=time.monotonic()-start,
        outputs={str(p):sha(p) for p in outputs if p.is_file()},
        missing_outputs=[str(p) for p in outputs if not p.is_file()])
    save(O/(name+'-receipt.json'), receipt)
    update('COMPLETED_'+name.upper(), child={})
    assert accepted and not receipt['missing_outputs'], (name, child.returncode, receipt['missing_outputs'])


def admission():
    while True:
        mem = int(next(l.split()[1] for l in Path('/proc/meminfo').read_text().splitlines() if l.startswith('MemAvailable:')))
        load = float(Path('/proc/loadavg').read_text().split()[0])
        disk = shutil.disk_usage(W).free
        workers, overlap = [], []
        for p in Path('/proc').iterdir():
            if not p.name.isdigit(): continue
            try:
                args = (p/'cmdline').read_bytes().split(b'\0')
                affinity = os.sched_getaffinity(int(p.name))
                if args and args[0].endswith(b'/unwrapped/lnx64.o/vivado') and any(b'/data1/gzh/EC/' in a for a in args):
                    workers.append(int(p.name))
                if p.stat().st_uid == os.getuid() and int(p.name) != os.getpid() and len(affinity)<=8 and affinity&CPUS:
                    overlap.append(int(p.name))
            except (OSError, ProcessLookupError): pass
        if mem>=256*2**20 and load<64 and disk>=60*2**30 and len(workers)<8 and not overlap:
            return dict(utc=now(), available_memory_kib=mem, load1=load,
                        free_disk_bytes=disk, existing_project_vivado=workers, cpu_overlap=overlap)
        update('WAITING_PRIVATE_MODULE_RESOURCES_NO_SIGNALS', memory_kib=mem,
               load1=load, free_disk_bytes=disk, existing_vivado=workers, cpu_overlap=overlap)
        time.sleep(30)


def build_host(cfg, cp, java, name, slots, config):
    target = O/(name+'-target'); target.mkdir()
    host = O/name; host.mkdir()
    harness = {2:'Smoke2',4:'Smoke4',256:'Full256'}[slots]
    stage('elaborate-'+name, java+['-cp',cp,'freechips.rocketchip.system.Generator',
        '--target-dir',target,'--name','Histogram','--top-module','histogramfame.'+harness,
        '--configs','firesim.midasexamples.NoConfig'], [target/'Histogram.fir',target/'Histogram.anno.json'])
    stage('goldengate-'+name, java+['-cp',cp,'midas.stage.GoldenGateMain',
        '-i',target/'Histogram.fir','-td',host,'-faf',target/'Histogram.anno.json',
        '-ggcp','histogramfame','-ggcs',config,'--output-filename-base','FireSim-generated'],
        [host/'FireSim-generated.sv',host/'FireSim-generated.synthesis.xdc'])
    fir = (host/'post-fame-transform.fir').read_text()
    threaded = config == 'ThreadedConfig'
    assert ('module HistogramBucket_threaded :' in fir) == threaded, 'actual threading must be visible'
    if threaded:
        assert f'UInt<{(slots-1).bit_length()}>' in fir
    save(O/(name+'-threading-audit.json'),dict(slots=slots, enabled=threaded,
         source_sha256=sha(target/'Histogram.fir'), host_rtl_sha256=sha(host/'FireSim-generated.sv'),
         post_fame_sha256=sha(host/'post-fame-transform.fir'), selected_type='HistogramBucket'))
    return host


def simulate(host, name, slots):
    # Keep GoldenGate synthesis RTL intact; append simulation-only blackboxes
    # to a separately hashed private file.
    sv = host/'FireSim-generated.sv'
    simsv = host/'simulation.sv'
    bb = host/'firrtl_black_box_resource_files.f'
    simsv.write_text(sv.read_text()+''.join(Path(p).read_text() for p in bb.read_text().splitlines() if p.strip()))
    clang = '/nix/store/zxw41nfy4gjlzd31ly7q6mkv4vkybx15-clang-wrapper-16.0.6/bin/clang++'
    verilator = '/nix/store/bj3wbpawbk71c082cvrnqkfyix7ipx0g-verilator-5.048/bin/verilator'
    # Use the exact installed tools used by prior successful host tests.
    assert Path(clang).is_file() and Path(verilator).is_file()
    deps = D/'build-logs/Opt4-mcrams-address-bucket-r2-20261112'
    env = {**os.environ, 'CCACHE_DISABLE':'1', 'LD_LIBRARY_PATH':'',
        'PATH':str(Path(clang).parent)+':'+str(Path(verilator).parent)+':/usr/local/bin:/usr/bin:/bin',
        'CXX':clang, 'CXXFLAGS':'-O1 -I'+str(deps/'headers')+' -I'+str(FS/'src/main/cc/midasexamples'),
        'LDFLAGS':'-L'+str(deps/'libs')+' -Wl,-rpath,'+str(deps/'libs'), 'OMP_NUM_THREADS':'2'}
    stage('compile-host-'+name, ['/usr/bin/make','-C',FS/'midas/src/main/cc','-j2',
        'verilator','PLATFORM=xilinx_alveo','DRIVER_NAME=Histogram','GEN_DIR='+str(host),
        'GEN_FILE_BASENAME=FireSim-generated','DESIGN_V='+str(simsv),
        'DRIVER='+str(FS/'src/main/cc/midasexamples/TestHarness.cc')+' '+str(C/'TestHistogram.cc'),
        'VERILATOR_FLAGS=-Wno-fatal -Wno-MULTIDRIVEN','CXX='+clang],
        [host/'VHistogram'], env=env)
    stage('token-oracle-'+name, [host/'VHistogram','+slots='+str(slots),'+seed=8491167',
        '+max-cycles=1000000'], marker='HISTOGRAM_TOKEN_PASS', env=env, timeout=1800)
    stage('token-negative-'+name, [host/'VHistogram','+slots='+str(slots),'+seed=8491167',
        '+max-cycles=1000000','+negative'], negative=True,
        marker='HISTOGRAM_TOKEN_MISMATCH cycle=7 slot=0', env=env, timeout=300)
    line = next(l for l in (O/('token-oracle-'+name+'.log')).read_text().splitlines() if l.startswith('HISTOGRAM_TOKEN_PASS '))
    result = json.loads(line.split(' ',1)[1])
    assert result['target_tokens']==32 and result['checked_outputs']==slots*32
    save(O/(name+'-token-result.json'),result)
    return result


def map_host(host, name):
    save(O/(name+'-area-admission.json'), admission())
    tcl=host/'map.tcl'; util=host/'utilization.rpt'; hier=host/'hierarchical.rpt'; dcp=host/'host.dcp'
    collateral=list(host.glob('*.v'))+[host/'FireSim-generated.sv']
    exact(tcl,'set_param general.maxThreads 2\n'+
        ''.join(f'read_verilog -sv {{{p}}}\n' for p in collateral)+
        f'read_xdc {{{host/"FireSim-generated.synthesis.xdc"}}}\n'+
        'synth_design -mode out_of_context -top FPGATop -part xcu280-fsvh2892-2L-e\n'+
        'if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "blackbox"}\n'+
        f'report_utilization -file {{{util}}}\nreport_utilization -hierarchical -file {{{hier}}}\nwrite_checkpoint -force {{{dcp}}}\nexit 0\n')
    stage('map-'+name,['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal',
        '-log',host/'vivado.log','-source',tcl],[util,hier,dcp])
    path=W/'candidates/mcrams-full-host-capacity-r1-20261112/resource_parser.py'
    spec=importlib.util.spec_from_file_location('histogram_area_parser',path)
    parser=importlib.util.module_from_spec(spec);spec.loader.exec_module(parser)
    total=parser.parse_total(util.read_text())
    parser.parse_hier(hier.read_text(),total);parser.crosschecks(util.read_text(),total)
    return dict(resources={k:v['used'] for k,v in total.items()},
        outputs={str(p):sha(p) for p in [util,hier,dcp,tcl,host/'FireSim-generated.sv']})


def main():
    cfg,pins=prepare()
    if '--prepare-only' in sys.argv:
        print(json.dumps(dict(status='PREPARED_SOURCE_BOUND_80SOURCE_256SLOT_FAME5',inputs_sha256=sha(C/'inputs.json')))); return
    lock=(O/'instance.lock').open('a'); fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(), 'Adopt existing attempt; never restart'
    assert all(sha(p)==h for p,h in pins['files'].items())
    os.sched_setaffinity(0,CPUS)
    resource.setrlimit(resource.RLIMIT_AS,(64*2**30,64*2**30))
    ST.update(schema=pins['schema'], **identity(), started_utc=now(), inputs_sha256=sha(C/'inputs.json'),
        functional_baseline=pins['functional_baseline'], fpga_access=False,
        production_admission=False, full_system_fit=False, cpus=sorted(CPUS), scope=pins['scope'])
    update('ADMITTING_PRIVATE_SOURCE_BOUND_FAME5_PROTOTYPE')
    save(O/'admission.json',admission())
    java=[cfg['java'],'-Xmx24G','-Xss8M','-XX:ActiveProcessorCount=2']
    classes=O/'classes'; classes.mkdir()
    stage('scala-compile',java+['-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main',
        '-classpath',':'.join(cfg['classpath']),'-Xplugin:'+cfg['plugin'],'-d',classes,
        C/'SourceProjected.scala',C/'Histogram.scala'],[classes/'histogramfame/Histogram.class'])
    cp=str(classes)+':'+':'.join(cfg['classpath'])
    for slots in [2,4]:
        name='Smoke'+str(slots)
        host=build_host(cfg,cp,java,name,slots,'ThreadedConfig')
        simulate(host,name,slots)
    update('PASS_2_AND_4_THREAD_HOST_TOKEN_SMOKES_FULL_SIZE_NEXT')
    results={}; tokens={}
    for name,config in [('Plain256','PlainConfig'),('Threaded256','ThreadedConfig')]:
        host=build_host(cfg,cp,java,name,256,config)
        tokens[name]=simulate(host,name,256)
        results[name]=map_host(host,name)
        save(O/'paired-progress.json',dict(area=results,tokens=tokens))
    assert tokens['Plain256']['digest']==tokens['Threaded256']['digest']
    delta=results['Plain256']['resources']['CLB LUTs']-results['Threaded256']['resources']['CLB LUTs']
    update('PASS_FINITE_TOKENS_AND_PAIRED_HOST_AREA_GAIN_NOT_INTEGRATED' if delta>0 else
           'REJECTED_NO_POSITIVE_SAME_HARNESS_LUT_GAIN', area=results, tokens=tokens,
           lut_saved=delta, ended_utc=now(), whole_host_gain_unknown=True)
    save(O/'result.json',ST)


if __name__=='__main__':
    try:
        main()
    except Exception as error:
        if ST:
            update('FAILED_WITH_EVIDENCE_VERSIONED_CORRECTION_REQUIRED',error=repr(error),ended_utc=now())
            save(O/'failure.json',ST)
        raise
