#!/usr/bin/python3
"""Freeze a private complete-module pair; submit only through the normal broker."""
from pathlib import Path
import ast
import hashlib
import json
import re
import sys

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'build-logs/Opt4-address-packed-module-parity-r4b-20261112'
NAME = 'address-packed-module-parity-r4b-8491167d'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import sha


def exact(path, data):
    data = data.encode() if isinstance(data, str) else data
    if path.exists():
        assert path.read_bytes() == data, ('immutable conflict', str(path))
    else:
        with path.open('xb') as stream:
            stream.write(data)


def freeze_json(path, value):
    exact(path, json.dumps(value, indent=2, sort_keys=True)+'\n')


def prepare():
    old = W/'candidates/mcrams-full-address-storage-r2-20261112'
    packed = W/'candidates/address-packed-group-reduction-r2-20261112'
    manifest = json.loads((old/'manifest.json').read_text())
    source = Path(manifest['source'])
    assert sha(source) == manifest['source_sha256']
    plain = old/'PlainPackageAddressStats.scala'
    assert sha(plain) == manifest['plain_proof_target_sha256']
    local = json.loads((packed/'validation-inputs.json').read_text())
    assert all(sha(p) == h for p, h in local['files'].items())
    update_helper = old/'AddressBucketUpdate.scala'
    exact(C/'AddressBucketUpdate.scala', update_helper.read_bytes())
    original_helper = old/'AddressBucketGrouped.scala'
    candidate_helper = packed/'AddressBucketGrouped.scala'
    assert sha(original_helper) == json.loads((packed/'plan.json').read_text())['source_sha256']
    assert sha(candidate_helper) == local['files'][str(candidate_helper)]
    names = ['bucketStore', 'bucketLoadFirst', 'bucketStoreFirst', 'bucketStrictWriteRead', 'bucketFirstStore']
    text = plain.read_text()
    # Reconstruct the current production source exactly after removing only
    # the old private namespace and the proof-only 5120-word debug ports.
    projected = text.replace('package opt4addressplain\nimport boom.lsu.{AddressBucketGrouped, AddressBucketUpdate}', 'package boom.lsu', 1)
    projected = projected.replace('\n    val debugBuckets = Output(Vec(5, Vec(packetWindow, Vec(4, UInt(64.W)))))', '', 1)
    for k, name in enumerate(names):
        projected = projected.replace(f'  io.debugBuckets({k}) := {name}\n', '', 1)
    assert projected == source.read_text(), 'private proof source differs beyond debug ports'
    for label in ['Reference', 'Candidate']:
        package = 'opt4packed'+label.lower()
        changed = text.replace('package opt4addressplain\nimport boom.lsu.{AddressBucketGrouped, AddressBucketUpdate}',
            'package '+package+'\nimport boom.lsu.AddressBucketUpdate', 1)
        exact(C/(label+'PackageAddressStats.scala'), changed)
        helper = original_helper if label == 'Reference' else candidate_helper
        exact(C/(label+'AddressBucketGrouped.scala'), helper.read_text().replace('package boom.lsu', 'package '+package, 1))
    # One elaboration assigns consistent unique names to all shared Queue
    # modules. The wrapper exports every ordinary output and debug word.
    exact(C/'EmitPair.scala', '''package opt4packedpair
import chisel3._
class PackedAddressPair extends Module {
  val a = Module(new opt4packedreference.PackageAddressStats(3,40,64,256))
  val b = Module(new opt4packedcandidate.PackageAddressStats(3,40,64,256))
  val io = IO(new Bundle {
    val reference = chiselTypeOf(a.io)
    val candidate = chiselTypeOf(b.io)
  })
  io.reference <> a.io
  io.candidate <> b.io
}
object EmitPair extends App {
  (new chisel3.stage.ChiselStage).emitVerilog(new PackedAddressPair,
    Array("--target-dir", args(0)))
}
''')
    tb_source = W/'candidates/address-group4-r1-20261111/frozen-tb.v'
    tb = tb_source.read_text()
    instances = []
    for label, suffix, pattern in [('reference', 'a', r'^PackageAddressStats_original a\((.*)\);$'),
                                    ('candidate', 'b', r'^PackageAddressStats b\((.*)\);$')]:
        match = re.search(pattern, tb, re.M)
        assert match
        ports = re.findall(r'\.([A-Za-z0-9_]+)\(([^()]*)\)', match[1])
        assert len(ports) == 75, ('unexpected inherited IO port count', len(ports))
        instances += [f'.io_{label}_{p[3:]}({v})' for p, v in ports if p not in ['clock','reset']]
        instances += [f'.io_{label}_debugBuckets_{k}_{i}_{g}({suffix}_debug_{k}_{i}_{g})'
            for k in range(5) for i in range(256) for g in range(4)]
        tb = tb[:match.start()] + tb[match.end():]
    declarations = []
    checks = []
    for k in range(5):
        for i in range(256):
            for g in range(4):
                name = f'debug_{k}_{i}_{g}'
                declarations.append(f'wire [63:0] a_{name},b_{name};')
                other = f'b_{name}'
                if (k,i,g) == (0,0,0):
                    other = f'({other} ^ ((mutate_debug && i==1900 && !a_io_statsValid) ? 64\'d1 : 64\'d0))'
                checks.append(f'if(a_{name} !== {other})begin $display("PACKED_DEBUG_MISMATCH word={k*1024+i*4+g} cycle=%0d valid=%0d",i,a_io_statsValid);$fatal;end')
                checks.append(f'if(!a_io_statsValid && a_{name}!=0) invalid_nonzero_seen=1;')
    declarations += ['integer invalid_edges=0; integer invalid_nonzero_seen=0; integer mutate_debug=0;',
        'PackedAddressPair pair(.clock(clock),.reset(reset),'+','.join(instances)+');']
    tb = tb.replace('initial begin', '\n'.join(declarations)+'\ninitial begin\nmutate_debug=$test$plusargs("mutate-debug");', 1)
    tb = tb.replace('io_fatalProtocolError=(phase==1850);', 'io_fatalProtocolError=(phase==1100 || phase==1850);', 1)
    tb = tb.replace('if(a_io_statsValid)valid_edges=valid_edges+1;', '\n'.join(checks)+
        '\nif(!a_io_statsValid)invalid_edges=invalid_edges+1;\nif(a_io_statsValid)valid_edges=valid_edges+1;', 1)
    marker='$display("ADDRESS_SEQUENTIAL_COMPARISON_PASS'
    index=tb.index(marker)
    tb=tb[:index]+'''if(invalid_edges<100 || !invalid_nonzero_seen)begin $display("INSUFFICIENT_INVALID_DEBUG_COVERAGE");$fatal;end
$display("PACKED_FULL_MODULE_DEBUG_PASS cycles=6144 outputs=5172 debug_checks=31457280 invalid_edges=%0d nonzero_invalid=%0d",invalid_edges,invalid_nonzero_seen);
'''+tb[index:]
    assert tb.count('PACKED_DEBUG_MISMATCH') == 5120
    assert 'PackageAddressStats_original a(' not in tb and 'PackageAddressStats b(' not in tb
    exact(C/'pair-tb.v', tb)
    ast.parse((C/'controller.py').read_text())
    cfgfile=W/'candidates/dcache-field-read-system-r1-20261111/config.json'
    cfg=json.loads(cfgfile.read_text())
    paths=[C/'prepare.py',C/'controller.py',C/'EmitPair.scala',C/'pair-tb.v',plain,source,
        old/'manifest.json',update_helper,C/'AddressBucketUpdate.scala',original_helper,candidate_helper,packed/'validation-inputs.json',
        packed/'plan.json',tb_source,cfgfile,W/'scripts/opt4_unattended_common.py',
        W/'scripts/opt4_frozen_scope.py']
    paths += [C/(label+kind+'.scala') for label in ['Reference','Candidate']
        for kind in ['PackageAddressStats','AddressBucketGrouped']]
    paths += [Path(p) for p in cfg['classpath']+cfg['compiler']+[cfg['plugin'],cfg['java']]]
    paths += [Path('/usr/local/bin/verilator'),Path('/usr/bin/g++')]
    inputs=dict(schema='ec-private-packed-complete-module-parity/1',
        functional_baseline=manifest['functional_baseline'],files={str(p):sha(p) for p in sorted(set(paths))},
        current_source_sha256=sha(source),current_source_projection_exact=True,
        change='Only the private histogram helper final reduction; complete target source and state identical.',
        cpus=[214,215],memory_limit_gib=24,full_host_synthesis=False,fpga_access=False,
        production_admission=False,formal_equivalence=False,area_result_available=False,
        checks=dict(cycles=6144,ordinary_outputs=52,debug_words=5120,debug_checks=31457280,
            invalid_state_unmasked=True,invalid_nonzero_required=True,
            observer_mutation_required=True,common_initial_payload='zero; arbitrary state not proved'),
        next='On finite parity PASS, independently version paired complete-module/generated-host area; no integration or whole CAD admission.')
    freeze_json(C/'inputs.json',inputs)
    direct={p:h for p,h in inputs['files'].items() if Path(p).resolve().is_relative_to(W)}
    # Tool executables remain transitively bound in inputs.json and are
    # rehashed by the controller, matching the broker executable-root contract.
    request=dict(action='cpu_job',spec=dict(name=NAME,kind='rtl',cwd=str(C),
        argv=['/usr/bin/python3',str(C/'controller.py')],
        inputs={**direct,str(C/'inputs.json'):sha(C/'inputs.json')},
        outputs=[str(O/'result.json')],checkpoints=[str(O/'state.json')]))
    return inputs,request


if __name__=='__main__':
    inputs,request=prepare()
    if '--submit' in sys.argv:
        freeze_json(D/'unattended-opt4/requests'/(NAME+'.json'),request)
    print(json.dumps(dict(status='PRIVATE_PAIR_PREPARED_NOT_RUN',name=NAME,
        inputs_sha256=sha(C/'inputs.json'),request_queued='--submit' in sys.argv,
        no_live_source_edits=True,no_cad_or_device_operations=True)))
