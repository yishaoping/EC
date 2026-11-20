#!/usr/bin/python3
"""Full source integration/parity prerequisite, without CAD or FPGA access."""
import fcntl
import importlib.util
import json
import os
from pathlib import Path
import re
import resource
import sys

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'build-logs/Opt4-address-banked-complete-module-r1-20261112'
REUSE = W/'candidates/address-histogram-fame5-r6-20261112/controller.py'
spec = importlib.util.spec_from_file_location('immutable_host_tools', REUSE)
m = importlib.util.module_from_spec(spec)
spec.loader.exec_module(m)
m.C, m.O, m.CPUS = C, O, {226,227}
from opt4_unattended_common import identity, now, read, save, sha
from prepare import prepare as source_prepare


def prepare():
    O.mkdir(exist_ok=True)
    source = source_prepare()
    cfgpath = W/'candidates/dcache-field-read-system-r1-20261111/config.json'
    cfg = read(cfgpath)
    prior = D/'build-logs/Opt4-address-packed-full-module-r1-20261112'
    tb_binding = read(prior/'generated-testbench-binding.json')
    assert sha(prior/'tb.v') == tb_binding['sha256']
    assert tb_binding['monitor_outputs'] == 5684
    paths = [C/n for n in ['prepare.py','controller.py','install.py','Emit.scala','README.md','source-binding.json']]
    paths += [Path(p) for p in source['generated']]
    paths += [cfgpath, REUSE, prior/'tb.v', prior/'generated-testbench-binding.json']
    paths += [Path(p) for p in cfg['compiler']+cfg['classpath']+[cfg['plugin']]]
    pins = dict(schema='ec-banked-complete-module-validation/1',
        files={str(p):sha(p) for p in paths},
        cpus=sorted(m.CPUS), memory_limit_gib=64,
        functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8',
        derived_parent='3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c',
        geometry=source['geometry'], source_inverse_byte_equal=True,
        target_registers_added=0, target_pipeline_cycles_added=0,
        scope='Complete actual AddressStats source with sixteen r4 banks. Target parity only; not a FAME host area result or full EC equivalence.',
        complete_module_outputs=52, observed_bucket_words=5120,
        observed_valid_words=256, observed_seq_words=256,
        borrowed_stimulus_sha256=sha(prior/'tb.v'),
        finite_target_cycles=6144, full_host_synthesis=False,
        fpga_access=False, production_admission=False,
        no_cad_in_this_controller=True,
        next='Require finite complete-module parity and actual r4 fullsize paired gain; then complete-module GoldenGate, all target observations/tokens and same-harness generated-host pair. Fresh full-host capacity remains mandatory.')
    m.exact(C/'inputs.json', json.dumps(pins, indent=2, sort_keys=True)+'\n')
    return cfg, pins


def ports(path, top):
    text = path.read_text()
    header = re.search(r'\bmodule '+re.escape(top)+r'\s*\((.*?)\);', text, re.S).group(1)
    return re.findall(r'\b(input|output)\s*(\[\d+:\d+\])?\s+(\w+)', header)


def testbench(reference, candidate):
    p = ports(reference, 'BankedProofReference')
    assert p == ports(candidate, 'BankedProofCandidate')
    assert len([n for d,w,n in p if d == 'output']) == 5684
    rtl = candidate.read_text()
    instances = re.findall(r'\bBucketBank(?:_\d+)?\s+(bucketBanks_\d+)\s*\(', rtl)
    assert set(instances) == {f'bucketBanks_{b}' for b in range(16)}, instances
    original = (D/'build-logs/Opt4-address-packed-full-module-r1-20261112/tb.v').read_text()
    text = original.replace('PackedProofReference', 'BankedProofReference')
    text = text.replace('PackedProofCandidate', 'BankedProofCandidate')
    seed_re = r'\bb\.(bucket(?:Store|FirstStore|LoadFirst|StoreFirst|StrictWriteRead))_(\d+)_(\d+)'
    def target(match):
        metric, slot, g = match.groups()
        slot = int(slot)
        return f'b.bucketBanks_{slot//16}.{metric}_{slot%16}_{g}'
    text, count = re.subn(seed_re, target, text)
    assert count == 5122, count  # 5120 seeds plus both sides of one mutation.
    text = text.replace('PACKED_MODULE_MISMATCH', 'BANKED_MODULE_MISMATCH')
    text = text.replace('PACKED_COMPLETE_MODULE_PARITY_PASS', 'BANKED_COMPLETE_MODULE_PARITY_PASS')
    # Only top names, candidate register paths and log labels differ; the
    # existing finite stimuli and full comparison monitor remain identical.
    m.exact(O/'tb.v', text)
    save(O/'testbench-binding.json',dict(source_sha256=sha(D/'build-logs/Opt4-address-packed-full-module-r1-20261112/tb.v'),
        testbench_sha256=sha(O/'tb.v'), candidate_register_rebindings=count,
        actual_bank_instances=sorted(instances), output_pins=5684,
        public_outputs=52, finite_cycles=6144, checks_before_and_after_edge=True,
        actual_invalid_register_mutation='bank15/lane15/strictWriteRead/granule3',
        reference_rtl_sha256=sha(reference),candidate_rtl_sha256=sha(candidate)))
    return O/'tb.v'


def main():
    cfg,pins = prepare()
    if '--prepare-only' in sys.argv:
        print('PREPARED_COMPLETE_ADDRESS_SOURCE_WITH_R4_BANKS_NO_CAD')
        return
    lock = (O/'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(), 'Adopt existing attempt; do not restart'
    assert all(sha(p)==h for p,h in pins['files'].items())
    os.sched_setaffinity(0, m.CPUS)
    resource.setrlimit(resource.RLIMIT_AS,(64*2**30,)*2)
    m.ST.update(**identity(),schema=pins['schema'],started_utc=now(),
        inputs_sha256=sha(C/'inputs.json'),scope=pins['scope'],
        functional_baseline=pins['functional_baseline'],derived_parent=pins['derived_parent'],
        cpus=pins['cpus'],geometry=pins['geometry'],memory_limit_gib=64,
        fpga_access=False,production_admission=False,full_system_fit=False,
        full_host_synthesis=False,no_cad_in_this_controller=True)
    m.update('ADMITTING_COMPLETE_BANKED_SOURCE_VALIDATION')
    save(O/'admission.json',m.admission())
    cp = ':'.join(cfg['classpath'])
    java = [cfg['java'],'-Xmx24G','-Xss8M','-XX:ActiveProcessorCount=2']
    emitted = {}
    for mode in ['Proof','Module']:
        classes = O/('classes-'+mode); classes.mkdir()
        sources = [C/n for n in ['AddressBucketUpdate.scala','SourceProjected.scala','BucketBank.scala',
            'ReferenceHelper.scala','Reference'+mode+'.scala','Candidate'+mode+'.scala','Emit.scala']]
        m.stage('scala-compile-'+mode,java+['-cp',':'.join(cfg['compiler']),'scala.tools.nsc.Main',
            '-classpath',cp,'-Xplugin:'+cfg['plugin'],'-d',classes,*sources],
            [classes/'opt4bankedfull/Emit$.class'])
        for label in ['Reference','Candidate']:
            out = O/(label+'-'+mode); out.mkdir()
            top = 'Banked'+mode+label
            m.stage('elaborate-'+label+'-'+mode,java+['-cp',str(classes)+':'+cp,
                'opt4bankedfull.Emit',label,mode,out],[out/(top+'.v')])
            emitted[(label,mode)] = out/(top+'.v')
    a = ports(emitted[('Reference','Module')], 'BankedModuleReference')
    b = ports(emitted[('Candidate','Module')], 'BankedModuleCandidate')
    assert a == b
    assert len([n for d,w,n in a if d=='output']) == 52
    save(O/'public-abi.json',dict(reference_ports=a,candidate_ports=b,exact=True,
        proof_only_outputs_absent=True,reference_rtl_sha256=sha(emitted[('Reference','Module')]),
        candidate_rtl_sha256=sha(emitted[('Candidate','Module')])))
    tb = testbench(emitted[('Reference','Proof')],emitted[('Candidate','Proof')])
    exe = O/'obj/Vtb'
    m.stage('parity-compile',['/usr/local/bin/verilator','--binary','--timing','--top-module','tb',
        '--Mdir',O/'obj','-j','2','--output-split','10000','--output-split-cfuncs','200',
        '--x-initial','0','--x-assign','0','-Wno-fatal',
        '-DRANDOMIZE_REG_INIT','-DRANDOMIZE_MEM_INIT',"-DRANDOM=32'h0",'-CFLAGS','-O0',
        '-MAKEFLAGS','OPT_FAST=-O0 OPT_SLOW=-O0',emitted[('Reference','Proof')],
        emitted[('Candidate','Proof')],tb],[exe])
    m.stage('parity-positive',[exe],marker='BANKED_COMPLETE_MODULE_PARITY_PASS cycles=6144')
    m.stage('parity-negative',[exe,'+EC_MUTATE'],negative=True,
        marker='BANKED_MODULE_MISMATCH port=io_debugBuckets_3_255_3 cycle=1000')
    m.update('PASS_COMPLETE_BANKED_MODULE_FINITE_PARITY_HOST_VALIDATION_PENDING',
        finite_parity=True,finite_target_cycles=6144,monitor_outputs=5684,
        invalid_register_mutation_detected=True,public_abi_equal=True,
        complete_formal_equivalence=False,host_area_gain_unknown=True,
        golden_gate_and_token_validation_pending=True,ended_utc=now())
    save(O/'result.json',m.ST)


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        if m.ST:
            m.update('FAILED_WITH_EVIDENCE_VERSIONED_CORRECTION_REQUIRED',error=repr(exc),ended_utc=now())
            save(O/'failure.json',m.ST)
        raise
