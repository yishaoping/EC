#!/usr/bin/python3
"""Isolated 16-bank x 16-lane complete bucket-state FAME5 screen."""
import importlib.util
import json
import os
from pathlib import Path
import resource
import sys
import fcntl

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'build-logs/Opt4-address-banked-state-fame5-r2-20261112'
FS = W/'C4/chipyard/sims/firesim/sim'
REUSE = W/'candidates/address-histogram-fame5-r6-20261112/controller.py'
spec = importlib.util.spec_from_file_location('immutable_r6_host_tools', REUSE)
m = importlib.util.module_from_spec(spec)
spec.loader.exec_module(m)
# Private Python module state only. No r6 file, process, controller or input is
# modified. Reuse the exact existing resource guard, stage runner and mapper.
m.C, m.O, m.CPUS = C, O, {218, 219}
from opt4_unattended_common import identity, now, read, save, sha


def prepare():
    O.mkdir(exist_ok=True)
    original = m.SOURCE.read_text()
    projection = '''
  def lookup(keys: Seq[UInt], counts: Seq[Seq[UInt]], bounds: Seq[Int], key: UInt): Vec[UInt] = {
    require(keys.nonEmpty && keys.size % 4 == 0 && keys.size == counts.size && key.getWidth == 8)
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
    text = text[:pos] + projection + text[pos:]
    assert text.replace(projection, '').replace('package sourceprojected', 'package opt4packedref', 1) == original
    m.exact(C/'SourceProjected.scala', text)
    cfgpath = W/'candidates/dcache-field-read-system-r1-20261111/config.json'
    cfg = read(cfgpath)
    fame = FS/'midas/src/main/scala/midas/passes/fame'
    paths = [C/n for n in ['BankedState.scala', 'SourceProjected.scala',
        'TestBankedState.cc', 'AddressBucketUpdate.scala', 'controller.py', 'install.py', 'README.md']]
    paths += [REUSE, m.SOURCE, m.PARENT, cfgpath]
    paths += [fame/n for n in ['MultiThreadFAME5Models.scala',
        'LabelMultiThreadedInstances.scala', 'MuxingMultithreader.scala',
        'MultiThreader.scala', 'ImplementThreadedMems.scala']]
    paths += [Path(p) for p in cfg['compiler'] + cfg['classpath'] + [cfg['plugin']]]
    pins = dict(schema='ec-banked-bucket-state-fame5-screen/1',
        functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8',
        files={str(p): sha(p) for p in paths}, cpus=sorted(m.CPUS),
        memory_limit_gib=64, geometry=dict(target_slots=256, banks=16,
        parallel_lanes=16, selected_module_types=['BucketBank']),
        package_sources=8, strict_sources=80, granules=4, counters_per_slot=20,
        seq_bits=32, source_projection_reversal_pass=True,
        target_extra_registers=0, target_extra_pipeline_cycles=0,
        smoke_bank_counts=[2,4], finite_tokens_per_configuration=48,
        fpga_access=False, production_admission=False, full_host_synthesis=False,
        scope='Five complete bucket-state vectors, valid/seq and exact carry outputs. External processCommit/safeError qualification; not complete address module or EC.',
        overflow_reachability_not_proved=True,
        area_scope='Same complete256slot harness on both sides including exact observation bridge. No extrapolation from small prototypes; fullmodule gain remains unknown.',
        throughput_scope='16 selected instances is a structural choice, not measured FMR/host MHz/EC cycles/runtime.',
        next='2/4-bank tokens+negative; full16x16 plain/threaded tokens; serial paired host maps. Then fullmodule integration and equivalence prerequisites only if useful gain.')
    m.exact(C/'inputs.json', json.dumps(pins, indent=2, sort_keys=True)+'\n')
    return cfg, pins


def build_host(cp, java, name, banks, config):
    assert banks in [2,4,16] and 256 == 16*16
    target = O/(name+'-target'); target.mkdir()
    host = O/name; host.mkdir()
    harness = {2:'Smoke2',4:'Smoke4',16:'Full16'}[banks]
    m.stage('elaborate-'+name, java+['-cp',cp,'freechips.rocketchip.system.Generator',
        '--target-dir',target,'--name','BankedState','--top-module','bankedstate.'+harness,
        '--configs','firesim.midasexamples.NoConfig'],
        [target/'BankedState.fir',target/'BankedState.anno.json'])
    # Assert exactly one actual selected target module type, and actual count.
    annotations = read(target/'BankedState.anno.json')
    selected = [a for a in annotations if a.get('class','').endswith('FirrtlEnableModelMultiThreadingAnnotation')]
    assert len(selected) == banks, (banks, selected)
    assert all(a['target'].endswith(':BucketBank') for a in selected), selected
    m.stage('goldengate-'+name, java+['-cp',cp,'midas.stage.GoldenGateMain',
        '-i',target/'BankedState.fir','-td',host,'-faf',target/'BankedState.anno.json',
        '-ggcp','bankedstate','-ggcs',config,'--output-filename-base','FireSim-generated'],
        [host/'FireSim-generated.sv',host/'FireSim-generated.synthesis.xdc'])
    fir = (host/'post-gen-sram-models.fir').read_text()
    threaded = config == 'ThreadedConfig'
    assert ('module BucketBank_threaded :' in fir) == threaded
    if threaded:
        assert f'UInt<{(banks-1).bit_length()}>' in fir
    save(O/(name+'-threading-audit.json'), dict(banks=banks, lanes=16,
        target_slots=banks*16, selected_type='BucketBank', selected_annotations=selected,
        enabled=threaded, target_sha256=sha(target/'BankedState.fir'),
        post_fame_sha256=sha(host/'post-gen-sram-models.fir'),
        host_rtl_sha256=sha(host/'FireSim-generated.sv'), compiler_patch=False))
    return host


def simulate(host, name, banks):
    simsv = host/'simulation.sv'
    bb = host/'firrtl_black_box_resource_files.f'
    simsv.write_text((host/'FireSim-generated.sv').read_text()+
        ''.join(Path(p).read_text() for p in bb.read_text().splitlines() if p.strip()))
    clang = '/nix/store/zxw41nfy4gjlzd31ly7q6mkv4vkybx15-clang-wrapper-16.0.6/bin/clang++'
    verilator = '/nix/store/bj3wbpawbk71c082cvrnqkfyix7ipx0g-verilator-5.048/bin/verilator'
    deps = D/'build-logs/Opt4-mcrams-address-bucket-r2-20261112'
    env = {**os.environ, 'CCACHE_DISABLE':'1', 'LD_LIBRARY_PATH':'',
        'PATH':str(Path(clang).parent)+':'+str(Path(verilator).parent)+':/usr/local/bin:/usr/bin:/bin',
        'CXX':clang, 'CXXFLAGS':'-O1 -I'+str(deps/'headers')+' -I'+str(FS/'src/main/cc/midasexamples'),
        'LDFLAGS':'-L'+str(deps/'libs')+' -Wl,-rpath,'+str(deps/'libs'), 'OMP_NUM_THREADS':'2'}
    m.stage('compile-host-'+name, ['/usr/bin/make','-C',FS/'midas/src/main/cc','-j2',
        'verilator','PLATFORM=xilinx_alveo','DRIVER_NAME=BankedState','GEN_DIR='+str(host),
        'GEN_FILE_BASENAME=FireSim-generated','DESIGN_V='+str(simsv),
        'DRIVER='+str(FS/'src/main/cc/midasexamples/TestHarness.cc')+' '+str(C/'TestBankedState.cc'),
        'VERILATOR_FLAGS=-Wno-fatal -Wno-MULTIDRIVEN','CXX='+clang],
        [host/'VBankedState'], env=env)
    args = [host/'VBankedState','+banks='+str(banks),'+seed=8491167','+max-cycles=10000000']
    m.stage('token-oracle-'+name, args, marker='BANKED_STATE_TOKEN_PASS', env=env, timeout=3600)
    m.stage('token-negative-'+name, args+['+negative'], negative=True,
        marker='BANKED_STATE_TOKEN_MISMATCH cycle=7 slot=0', env=env, timeout=600)
    line = next(l for l in (O/('token-oracle-'+name+'.log')).read_text().splitlines()
                if l.startswith('BANKED_STATE_TOKEN_PASS '))
    result = json.loads(line.split(' ',1)[1])
    assert result['target_tokens'] == 48 and result['checked_outputs'] == banks*16*48
    save(O/(name+'-token-result.json'), result)
    return result


def main():
    cfg,pins = prepare()
    if '--prepare-only' in sys.argv:
        print(json.dumps(dict(status='PREPARED_BANKED_STATE_16x16', inputs_sha256=sha(C/'inputs.json')))); return
    lock = (O/'instance.lock').open('a'); fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(), 'Adopt live attempt; never restart'
    assert all(sha(p)==h for p,h in pins['files'].items())
    os.sched_setaffinity(0, m.CPUS)
    resource.setrlimit(resource.RLIMIT_AS, (64*2**30,64*2**30))
    m.ST.update(schema=pins['schema'], **identity(), started_utc=now(),
        inputs_sha256=sha(C/'inputs.json'), functional_baseline=pins['functional_baseline'],
        fpga_access=False, production_admission=False, full_system_fit=False,
        cpus=sorted(m.CPUS), scope=pins['scope'], geometry=pins['geometry'])
    m.update('ADMITTING_INDEPENDENT_BANKED_WHOLE_BUCKET_STATE_SCREEN')
    save(O/'admission.json', m.admission())
    java = [cfg['java'],'-Xmx24G','-Xss8M','-XX:ActiveProcessorCount=2']
    classes = O/'classes'; classes.mkdir()
    m.stage('scala-compile',java+['-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main',
        '-classpath',':'.join(cfg['classpath']),'-Xplugin:'+cfg['plugin'],'-d',classes,
        C/'AddressBucketUpdate.scala',C/'SourceProjected.scala',C/'BankedState.scala'], [classes/'bankedstate/BucketBank.class'])
    cp = str(classes)+':'+':'.join(cfg['classpath'])
    tokens = {}
    for banks in [2,4]:
        name = 'Smoke'+str(banks)
        host = build_host(cp, java, name, banks, 'ThreadedConfig')
        tokens[name] = simulate(host, name, banks)
        save(O/'token-progress.json', tokens)
    save(O/'banked-fullsize-admission.json', dict(utc=now(),
        geometry=pins['geometry'], smoke_receipts={n:sha(O/(n+'-token-result.json')) for n in tokens},
        foreground_throughput_constraint_read=True, no_claim_of_measured_FMR=True,
        pinned_r6_preserved=True, production_admission=False))
    hosts = {}
    for name,config in [('Plain16','PlainConfig'),('Threaded16','ThreadedConfig')]:
        hosts[name] = build_host(cp, java, name, 16, config)
        tokens[name] = simulate(hosts[name], name, 16)
        save(O/'token-progress.json', tokens)
    assert tokens['Plain16']['digest'] == tokens['Threaded16']['digest']
    results = {}
    for name in ['Plain16','Threaded16']:
        results[name] = m.map_host(hosts[name], name)
        save(O/'paired-progress.json', dict(area=results, tokens=tokens))
    delta = results['Plain16']['resources']['CLB LUTs'] - results['Threaded16']['resources']['CLB LUTs']
    m.update('PASS_FINITE_TOKENS_AND_PAIRED_BANKED_HOST_AREA_NOT_INTEGRATED' if delta>0 else
        'REJECTED_NO_POSITIVE_SAME_HARNESS_LUT_GAIN', area=results, tokens=tokens,
        lut_saved=delta, ended_utc=now(), whole_host_gain_unknown=True,
        complete_module_equivalence=False, full_system_fit=False)
    save(O/'result.json', m.ST)


if __name__ == '__main__':
    try:
        main()
    except Exception as error:
        if m.ST:
            m.update('FAILED_WITH_EVIDENCE_VERSIONED_CORRECTION_REQUIRED',error=repr(error),ended_utc=now())
            save(O/'failure.json',m.ST)
        raise
