#!/usr/bin/env python3
"""Read existing private validation inputs; write only this round's evidence."""
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
from datetime import datetime, timezone

EC = Path('/data1/gzh/EC')
D = EC / 'Experiment/firesim-final-opt4-20261106'
C = EC / 'firesim/final-opt4-20261106/candidates/address-packed-full-module-r1-20261112'
O = D / 'build-logs/Opt4-address-packed-full-module-r1-20261112'
F = D / 'build-logs/Opt4-address-packed-module-parity-r4b-20261112'
A = Path(__file__).resolve().parent
BOOT = Path('/proc/sys/kernel/random/boot_id').read_text().strip()
NOW = datetime.now(timezone.utc).isoformat()


def read(p):
    return json.loads(Path(p).read_text())


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def save(name, obj):
    with (A / name).open('x') as f:
        json.dump(obj, f, indent=2, sort_keys=True)
        f.write('\n')


def identity(pid):
    p = Path('/proc') / str(pid)
    if not p.exists():
        return {'pid': pid, 'present': False}
    s = (p / 'stat').read_text().rsplit(')', 1)[1].split()
    groups = (p / 'cgroup').read_text().splitlines()
    return dict(pid=pid, present=True, start_ticks=s[19], process_state=s[0],
                cpu_ticks=int(s[11]) + int(s[12]), host_boot_id=BOOT,
                exact_cgroups=[x.split(':', 2)[2] for x in groups],
                affinity=sorted(os.sched_getaffinity(pid)),
                argv=(p / 'cmdline').read_bytes().replace(b'\0', b' ').decode()[:700])


def properties(unit, user=False):
    env = {**os.environ, 'XDG_RUNTIME_DIR': '/run/user/1008',
           'DBUS_SESSION_BUS_ADDRESS': 'unix:path=/run/user/1008/bus'}
    args = ['systemctl'] + (['--user'] if user else [])
    args += ['show', unit, '--property=Id,ActiveState,SubState,MainPID,ControlGroup,Result']
    r = subprocess.run(args, env=env, capture_output=True, text=True, check=True)
    return dict(line.split('=', 1) for line in r.stdout.splitlines() if '=' in line)


pins = read(C / 'inputs.json')
state = read(O / 'state.json')
unit = 'ec-opt4-address-packed-full-module-r1-20261112.service'
props = properties(unit, user=True)
owner = identity(state['pid'])
assert state['inputs_sha256'] == sha(C / 'inputs.json')
assert state['host_boot_id'] == BOOT == owner['host_boot_id']
assert owner['start_ticks'] == state['start_ticks'] == '29246727'
assert props['MainPID'] == str(owner['pid']) and props['ActiveState'] == 'active'
expected = '/user.slice/user-1008.slice/user@1008.service/' + unit
assert props['ControlGroup'] == expected and expected in owner['exact_cgroups']
assert owner['affinity'] == [214, 215]
members = []
for p in Path('/proc').iterdir():
    if not p.name.isdigit():
        continue
    try:
        if any(x.split(':', 2)[2] == expected for x in (p / 'cgroup').read_text().splitlines()):
            members.append(identity(int(p.name)))
    except (FileNotFoundError, ProcessLookupError, PermissionError):
        pass
assert all(m['affinity'] == [214, 215] for m in members)
limits = (Path('/proc') / str(owner['pid']) / 'limits').read_text()
limit = next(x for x in limits.splitlines() if x.startswith('Max address space'))
assert str(64 * 2**30) in limit
save('r1-live-adoption.json', dict(utc=NOW, state=state, service=props,
     identity=owner, cgroup_members=members, address_space_limit=limit,
     sole_existing_paired_area_owner=True, new_jobs=0, live_inputs_changed=False))

failed = read(F / 'state.json')
vr = read(F / 'verilate-receipt.json')
assert failed['status'] == 'FAILED_WITH_EVIDENCE'
assert vr['returncode'] == 1 and not vr['accepted']
assert sha(vr['log']) == vr['log_sha256']
old = identity(failed['pid'])
assert not old['present'] or old['start_ticks'] != failed['start_ticks']
oldprops = properties('ec-opt4-auto-address-packed-module-parity-r4b-8491167d.service')
assert oldprops['ActiveState'] == 'inactive' and oldprops['MainPID'] == '0'
oldgroup = Path('/sys/fs/cgroup/systemd/system.slice/ec-opt4-auto-address-packed-module-parity-r4b-8491167d.service')
oldmembers = (oldgroup / 'cgroup.procs').read_text().split() if oldgroup.exists() else []
assert not oldmembers
bad_tb = Path(vr['argv'][-1])
line = bad_tb.read_text().splitlines()[5184]
save('r4b-failure-closure.json', dict(utc=NOW, state=failed, receipt=vr,
     current_old_pid=old, service=oldprops, exact_old_cgroup=str(oldgroup),
     old_cgroup_exists=oldgroup.exists(), old_cgroup_members=oldmembers,
     source_testbench=str(bad_tb), testbench_sha256=sha(bad_tb),
     offending_line=5185, offending_line_characters=len(line),
     direct_symptom={'status': 'PROVEN', 'value': 'Verilator >40000 preprocessor tokens on a line'},
     immediate_block={'status': 'PROVEN', 'value': 'Generated testbench cannot be parsed'},
     upstream_trigger={'status': 'PROVEN', 'value': 'Single 530716-character pair connection line'},
     downstream_effect={'status': 'PROVEN', 'value': 'No simulation/parity or area result from r4b'},
     disposition='Preserve failure. Healthy foreground r1 already owns parity and paired area; no r4c or duplicate.',
     process_signals=[], new_requests=[]))
with (A / 'r4b-verilate.log').open('x') as f:
    f.write(Path(vr['log']).read_text())

# Targeted source/proof boundary audit, without executing a validation again.
checked = {}
for p in sorted(C.glob('*.scala')) + [C / 'controller.py', C / 'README.md']:
    checked[str(p)] = sha(p)
    assert checked[str(p)] == pins['files'][str(p)]
source = EC / 'firesim/final-opt4-20261106/Opt4-fit-dcache-field-read-prune-r1-20261111/chipyard/generators/boom/src/main/scala/lsu/PackageAddressStats.scala'
original = source.read_text()
assert sha(source) == pins['files'][str(source)]
debug = '''
    val debugBuckets = Output(Vec(5, Vec(packetWindow, Vec(4, UInt(64.W)))))
    val debugBucketValid = Output(Vec(packetWindow, Bool()))
    val debugBucketSeq = Output(Vec(packetWindow, UInt(32.W)))'''
names = ['bucketStore', 'bucketLoadFirst', 'bucketStoreFirst', 'bucketStrictWriteRead', 'bucketFirstStore']
observe = '\n'.join(f'  io.debugBuckets({k}) := {n}' for k, n in enumerate(names))
observe += '\n  io.debugBucketValid := bucketValid\n  io.debugBucketSeq := bucketSeq\n'
for label, namespace in [('Reference', 'opt4packedref'), ('Candidate', 'opt4packedcandidate')]:
    module = (C / (label + 'Module.scala')).read_text()
    assert module.replace(f'package {namespace}\nimport boom.lsu.AddressBucketUpdate', 'package boom.lsu', 1) == original
    proof = (C / (label + 'Proof.scala')).read_text()
    assert proof.replace(debug, '').replace('\n' + observe, '') == module
refhelper = (C / 'ReferenceHelper.scala').read_text().replace('package opt4packedref', 'package common')
helper = (C / 'CandidateHelper.scala').read_text().replace('package opt4packedcandidate', 'package common')
common = refhelper[:refhelper.index('    VecInit((0 until slots).map { i =>', refhelper.index('  def histogram'))]
assert helper[:helper.index('    // Each scatter lane is unchanged.')] == common


def ports(p):
    with p.open() as f:
        header = ''
        while ');' not in header:
            chunk = f.read(65536)
            assert chunk, str(p)
            header += chunk
    return re.findall(r'\b(input|output)\s*(\[\d+:\d+\])?\s+(\w+)', header.split(');', 1)[0])


proof_ports = ports(O / 'Reference-Proof/PackedProofReference.v')
assert proof_ports == ports(O / 'Candidate-Proof/PackedProofCandidate.v')
outputs = [n for d, w, n in proof_ports if d == 'output']
production_ports = ports(O / 'Reference-Module/FPGATop.v')
assert production_ports == ports(O / 'Candidate-Module/FPGATop.v')
public = [n for d, w, n in production_ports if d == 'output']
assert len(public) == 52 and not any(n.startswith('io_debug') for n in public)
assert len(outputs) == 5684
assert sum(n.startswith('io_debugBuckets_') for n in outputs) == 5120
assert sum(n.startswith('io_debugBucketValid_') for n in outputs) == 256
assert sum(n.startswith('io_debugBucketSeq_') for n in outputs) == 256
tb = (O / 'tb.v').read_text()
binding = read(O / 'generated-testbench-binding.json')
assert sha(O / 'tb.v') == binding['sha256']
monitored = re.findall(r'if\(a_(\w+) !== b_\1\)', tb)
assert set(monitored) == set(outputs) and len(monitored) == len(outputs)
assert '#1; compare; @(posedge clock);#1;compare;' in tb
assert 'if(i>=3000 && i<=3002)begin reset=1;io_resetStats=0;end' in tb
assert 'if(i==3003)seed_invalid;' in tb
assert 'if(i==1000 && $test$plusargs("EC_MUTATE"))b.bucketStrictWriteRead_255_3=' in tb
controller = (C / 'controller.py').read_text()
assert controller.index("stage('parity-positive'") < controller.index("stage('parity-invalid-register-mutation'") < controller.rindex("for label in ['Reference','Candidate']:")
assert "require='PACKED_MODULE_MISMATCH port=io_debugBuckets_3_255_3 cycle=1000'" in controller
assert "rtl=production[label]" in controller and 'proof_only_ports_excluded_from_area=True' in controller
save('source-and-continuation-contract.json', dict(utc=NOW,
     status='PASS_STATIC_BOUNDARY_AND_SINGLETON_CONTINUATION_AUDIT',
     source_pins=checked, input_manifest_sha256=sha(C / 'inputs.json'),
     exact_complete_target_source_projection=True, proof_only_instrumentation_projection=True,
     unchanged_compaction_and_scatter_prefix=True, identical_production_ports=True,
     public_outputs=52, debug_bucket_words=5120, debug_valid_words=256,
     debug_sequence_words=256, monitor_outputs=5684, monitor_checks_before_and_after_edge=True,
     equal_payload_seeding_and_normal_reset_present=True,
     actual_register_mutation_required_before_area=True, production_area_excludes_debug_ports=True,
     area_owner=unit, maps_sequential=True,
     finite_runtime_parity_complete_at_snapshot=bool(state.get('finite_parity_pass')),
     area_result_available_at_snapshot=(O / 'result.json').exists(),
     formal_equivalence=False, production_admission=False,
     pending=['Model compilation', '6144-cycle positive finite parity',
              'Actual register mutation rejection', 'Reference then candidate full-module area',
              'Source-bound composition/GoldenGate/ABI/target cycles', 'Fresh whole-host capacity'],
     tests_or_CAD_started=0, device_operations=[]))

prior = D / 'status-audits/round141-packed-complete-module-parity-20261112/completed-svb-verification.json'
assert sha(prior) == '1c0cb0c379cb1409764218571298aeab3b9bd51bde7e983fd41495f3977d74d9'
capacity = D / 'build-logs/Opt4-mcrams-full-host-capacity-r1-20261112/result.json'
assert sha(capacity) == '131a8219a2404634db44959f8373771bda319930ff327da3e6d4f1df07e02544'
cap = read(capacity)
assert cap['status'] == 'NOT_FIT_FULL_GENERATED_HOST_NO_PLACE_RUN'
original_metrics = D / 'unattended-opt4/requests/svb-application-fpga-metrics-r1-8491167d.json'
assert sha(original_metrics) == '57b767d86a915fcaaa845b4bbe13c3f68c148ac17a26e975deabb2e8e8104833'
save('completed-results-reused.json', dict(utc=NOW,
     previous_svb_verification=str(prior), previous_svb_verification_sha256=sha(prior),
     bitstream_sha256='678a5b7fa0fcf56719fd011231748daf61f437b37136f304179c515c1c0e763e',
     svb_target_edges=1759001, svb_complete_lifetimes=659, mismatches=0, full_ec=False,
     mcrams_result=str(capacity), mcrams_result_sha256=sha(capacity),
     mcrams_luts=2420482, mcrams_lut_excess=1116802, shell_excluded=True,
     original_metrics_request=str(original_metrics), original_metrics_request_sha256=sha(original_metrics),
     original_metrics_request_modified=False, broker_guard_bypassed=False,
     existing_result_validation_repeated=False, new_fpga_samples=0))
print(json.dumps({'status': 'AUDIT_PASS_R1_ADOPTED_R4B_FAILURE_PRESERVED',
                  'utc': NOW, 'r1_pid': owner['pid'], 'r1_stage': state['active_stage'],
                  'r4b': 'FAILED_PARSER_NO_PARITY', 'monitor_outputs': len(outputs),
                  'new_jobs': 0, 'evidence_directory': str(A)}))
