#!/usr/bin/python3
"""Paired one-bucket area screen of the actual helpers; never a whole-host FIT."""
import fcntl
import importlib.util
import os
from pathlib import Path
import resource
import re
import shutil
import subprocess
import sys
import time

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'build-logs/Opt4-address-packed-bucket-area-r3-20261112'
LOCAL = W/'candidates/address-packed-group-reduction-r2-20261112'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, live, now, read, save, sha

ST = {}


def update(status=None, **values):
    ST.update(values, updated_utc=now())
    if status:
        ST['status'] = status
    save(O/'state.json', ST)


def exact(path, value):
    if path.exists():
        assert path.read_text() == value, ('immutable preparation changed', str(path))
    else:
        path.write_text(value)


def prepare():
    O.mkdir(exist_ok=True)
    plan = read(LOCAL/'plan.json')
    source = Path(plan['source'])
    assert sha(source) == plan['source_sha256']
    assert sha(LOCAL/'AddressBucketGrouped.scala') == plan['candidate_sha256']
    exact(C/'Reference.scala', source.read_text().replace('object AddressBucketGrouped {', 'object AddressBucketGroupedReference {'))
    exact(C/'Candidate.scala', (LOCAL/'AddressBucketGrouped.scala').read_text())
    exact(C/'Emit.scala', '''package opt4packedarea
import chisel3._
import chisel3.util._
class Bucket(reference: Boolean) extends RawModule {
  override def desiredName = "FPGATop"
  val io = IO(new Bundle {
    val keys = Input(Vec(80, UInt(8.W)))
    val counts = Input(Vec(80, Vec(4, UInt(4.W))))
    val result = Output(Vec(4, UInt(64.W)))
  })
  val bounds = Seq(8,3,2,1)
  val all = if (reference) boom.lsu.AddressBucketGroupedReference.histogram(
    io.keys.toSeq, io.counts.map(_.toSeq), bounds, 256)
  else boom.lsu.AddressBucketGrouped.histogram(
    io.keys.toSeq, io.counts.map(_.toSeq), bounds, 256)
  io.result := all(0)
}
object Emit extends App {
  (new chisel3.stage.ChiselStage).emitVerilog(new Bucket(args(0) == "reference"),
    Array("--target-dir", args(1)))
}
''')
    cfgfile = W/'candidates/dcache-field-read-system-r1-20261111/config.json'
    parser = W/'candidates/mcrams-full-host-capacity-r1-20261112/resource_parser.py'
    cfg = read(cfgfile)
    paths = [C/'screen.py', C/'Reference.scala', C/'Candidate.scala', C/'Emit.scala',
        LOCAL/'validation-inputs.json', cfgfile, parser]
    paths += [Path(p) for p in cfg['classpath'] + cfg['compiler'] + [cfg['plugin']]]
    pins = dict(schema='ec-actual-address-helper-paired-bucket-area/1',
        functional_baseline=plan['functional_baseline'], files={str(p):sha(p) for p in paths},
        scope='One fixed bucket of the actual 80-input/four-granule helpers, including group4 compaction and scatter. Not whole histogram/module/host area.',
        full_host_synthesis=False, fpga_access=False, production_admission=False,
        no_multiplier_extrapolation=True, no_functional_or_target_cycle_change=True)
    if (C/'inputs.json').exists():
        assert read(C/'inputs.json') == pins
    else:
        save(C/'inputs.json', pins)
    return cfg, pins, parser


def stage(name, argv, outputs=()):
    receipt = O/(name+'-receipt.json')
    if receipt.exists():
        r = read(receipt)
        assert r['returncode'] == 0 and all(sha(p) == h for p,h in r['outputs'].items())
        return
    log = O/(name+'.log')
    assert not log.exists(), 'Retain partial attempt; versioned recovery required'
    start = time.monotonic()
    with log.open('xb', buffering=0) as stream:
        child = subprocess.Popen(list(map(str, argv)), cwd=O, stdin=subprocess.DEVNULL,
            stdout=stream, stderr=subprocess.STDOUT,
            env={**os.environ, 'LD_LIBRARY_PATH':'', 'OMP_NUM_THREADS':'2'})
        update('RUNNING_'+name.upper(), child=identity(child.pid))
        while child.poll() is None:
            try:
                child.wait(timeout=30)
            except subprocess.TimeoutExpired:
                pass
            os.fsync(stream.fileno())
            update(child=identity(child.pid), host_wall_seconds=time.monotonic()-start)
    r = dict(argv=list(map(str,argv)),returncode=child.returncode,log=str(log),
        log_sha256=sha(log),outputs={str(p):sha(p) for p in outputs if Path(p).is_file()})
    save(receipt,r)
    update(child={})
    assert child.returncode == 0 and len(r['outputs']) == len(outputs), (name,r)


def admission():
    while True:
        memory = int(next(x.split()[1] for x in Path('/proc/meminfo').read_text().splitlines() if x.startswith('MemAvailable:')))
        load = float(Path('/proc/loadavg').read_text().split()[0])
        disk = shutil.disk_usage(W).free
        workers = []
        for proc in Path('/proc').iterdir():
            if not proc.name.isdigit():
                continue
            try:
                argv = (proc/'cmdline').read_bytes().split(b'\0')
                if argv and argv[0].endswith(b'/unwrapped/lnx64.o/vivado') and any(b'/data1/gzh/EC/' in a for a in argv):
                    workers.append(identity(int(proc.name)))
            except (FileNotFoundError, ProcessLookupError, PermissionError):
                pass
        if memory >= 256*2**20 and disk >= 40*2**30 and load < 64 and len(workers) < 8:
            return dict(memory_kib=memory,disk_bytes=disk,load1=load,existing_project_vivado=workers)
        update('WAITING_LOCAL_AREA_RESOURCES_NO_SIGNALS',memory_kib=memory,disk_bytes=disk,load1=load,workers=workers)
        time.sleep(30)


def main():
    cfg,pins,parser = prepare()
    if '--prepare-only' in sys.argv:
        return
    lock = (O/'instance.lock').open('a')
    fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    old = read(O/'state.json')
    assert not live(old) and not live(old.get('child',{})), 'Adopt existing screen'
    local = D/'build-logs/Opt4-address-packed-group-reduction-r2-20261112/result.json'
    r = read(local)
    assert r['status'] == 'PASS_LOCAL_ACTUAL_HISTOGRAM_NOT_COMPLETE_MODULE_OR_AREA'
    assert r['actual_output_checks'] == 8388608 and r['inputs_sha256'] == sha(LOCAL/'validation-inputs.json')
    assert all(sha(p) == h for p,h in pins['files'].items())
    os.sched_setaffinity(0,{214,215})
    resource.setrlimit(resource.RLIMIT_AS,(24*2**30,)*2)
    ST.update(**identity(),schema=pins['schema'],functional_baseline=pins['functional_baseline'],
        started_utc=now(),fpga_access=False,full_host_synthesis=False,production_admission=False,
        inputs_sha256=sha(C/'inputs.json'),actual_histogram_receipt_sha256=sha(local),
        cpus=[214,215],memory_limit_gib=24,scope=pins['scope'])
    update('STARTING_PAIRED_ACTUAL_BUCKET_SCREEN')
    cl=O/'classes';cl.mkdir(exist_ok=True)
    cp=':'.join(cfg['classpath']);java=[cfg['java'],'-Xmx12G','-Xss8M','-XX:ActiveProcessorCount=2']
    stage('compile',java+['-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main','-classpath',cp,
        '-Xplugin:'+cfg['plugin'],'-d',cl,C/'Reference.scala',C/'Candidate.scala',C/'Emit.scala'],[cl/'opt4packedarea/Emit$.class'])
    spec=importlib.util.spec_from_file_location('strict_bucket_resource_parser',parser)
    p=importlib.util.module_from_spec(spec);spec.loader.exec_module(p)
    maps={}
    for label in ['reference','candidate']:
        out=O/label;out.mkdir(exist_ok=True);rtl=out/'FPGATop.v'
        stage('elaborate-'+label,java+['-cp',str(cl)+':'+cp,'opt4packedarea.Emit',label,out],[rtl])
        a=admission();save(out/'admission.json',a)
        tcl=out/'map.tcl';util=out/'utilization.rpt';hier=out/'hierarchical.rpt';dcp=out/'module.dcp';netlist=out/'mapped.v'
        exact(tcl,'set_param general.maxThreads 2\n'+f'read_verilog {{{rtl}}}\n'+
            'synth_design -mode out_of_context -top FPGATop -part xcu280-fsvh2892-2L-e\n'+
            'if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "blackbox"}\n'+
            f'report_utilization -file {{{util}}}\nreport_utilization -hierarchical -file {{{hier}}}\n'+
            f'write_checkpoint -force {{{dcp}}}\nwrite_verilog -force -mode funcsim {{{netlist}}}\nexit 0\n')
        stage('map-'+label,['/tools/Xilinx/Vivado/2021.1/bin/vivado','-mode','batch','-nojournal','-log',out/'vivado.log','-source',tcl],[util,hier,dcp,netlist])
        total=p.parse_total(util.read_text());p.parse_hier(hier.read_text(),total);p.crosschecks(util.read_text(),total)
        assert total['CLB Registers']['used']==0, 'A combinational histogram must not gain a register'
        mapped=netlist.read_text()
        assert not re.search(r'\b(FDRE|FDSE|FDCE|FDPE|LDCE|LDPE)\b',mapped)
        for reg in ['AREG','BREG','CREG','PREG','MREG','ALUMODEREG','OPMODEREG','CARRYINREG']:
            assert all(int(v)==0 for v in re.findall(r'\.'+reg+r'\((\d+)\)',mapped)), ('DSP register introduced',reg)
        maps[label]=dict(resources=total,report=str(util),report_sha256=sha(util),rtl_sha256=sha(rtl))
    saving=maps['reference']['resources']['CLB LUTs']['used']-maps['candidate']['resources']['CLB LUTs']['used']
    update('PAIRED_ACTUAL_BUCKET_SCREEN_COMPLETE_NOT_WHOLE_MODULE',child={},maps=maps,
        lut_saved_one_bucket=saving,complete_module_area_unknown=True,whole_host_fit_unknown=True,
        no_multiplier_extrapolation=True,completed_utc=now())
    save(O/'result.json',ST)


if __name__=='__main__':
    try:
        main()
    except Exception as exc:
        if ST:
            update('FAILED_WITH_EVIDENCE',error=repr(exc))
        raise
