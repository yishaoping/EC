#!/usr/bin/python3
"""Bounded immutable round receipt; never signals or launches an existing job."""
from datetime import datetime, timezone
import fcntl
import hashlib
import json
import os
from pathlib import Path

A = Path(__file__).resolve().parent
D = A.parent.parent
W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
P = D/'unattended-opt4/campaign-policy.json'
C = W/'candidates/address-banked-complete-module-r1-20261112'
BOOT = Path('/proc/sys/kernel/random/boot_id').read_text().strip()


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def read(path):
    return json.loads(Path(path).read_text())


def write(path, value):
    text = json.dumps(value, indent=2, sort_keys=True)+'\n'
    with path.open('x') as f:
        f.write(text)


def identity(state):
    if not state.get('pid'):
        return dict(live=False)
    proc = Path('/proc')/str(state['pid'])
    try:
        fields = (proc/'stat').read_text().rsplit(')',1)[1].split()
        return dict(pid=state['pid'], start_ticks=fields[19], boot_id=BOOT,
            live=fields[19]==str(state.get('start_ticks')) and
                BOOT==state.get('host_boot_id') and fields[0] not in ['Z','X'],
            process_state=fields[0],cgroup=(proc/'cgroup').read_text().strip())
    except FileNotFoundError:
        return dict(pid=state['pid'],live=False,reason='PID absent')


utc = datetime.now(timezone.utc).isoformat()
owners = {}
for name in ['Opt4-address-packed-full-module-r1-20261112',
             'Opt4-address-dsp-fullmodule-pair-r1-20261112',
             'Opt4-address-histogram-fame5-r6-20261112',
             'Opt4-address-banked-state-fame5-r4-20261112',
             'Opt4-dcache-storage-compose-r2-20261112',
             'Opt4-address-banked-complete-module-r1-20261112']:
    out = D/'build-logs'/name
    file = out/'state.json'
    raw = file.read_bytes()
    state = json.loads(raw)
    result = dict(state_path=str(file),state_sha256=hashlib.sha256(raw).hexdigest(),
        state=state,identity=identity(state),child_identity=identity(state.get('child',{})))
    receipts = {}
    for pattern in ['*-token-result.json','*receipt.json','*result.json','public-abi.json',
                    'paired-map-progress.json','paired-progress.json','token-progress.json']:
        for receipt in out.glob(pattern):
            if receipt.is_file():
                receipts[str(receipt)] = dict(sha256=sha(receipt),content=read(receipt))
    result['completed_receipts'] = receipts
    source = W/'candidates'/name.removeprefix('Opt4-')
    pinfile = source/'inputs.json'
    if pinfile.exists():
        pins = read(pinfile)
        result['inputs_sha256'] = sha(pinfile)
        mismatches = [p for p,h in pins['files'].items() if sha(p)!=h]
        result['pin_mismatches'] = mismatches
        assert not mismatches, (name,mismatches)
    write(A/('round154-observed-'+name+'.json'),result)
    owners[name] = dict(state_path=str(file),state_sha256=result['state_sha256'],
        status=state['status'],active_stage=state.get('active_stage'),
        identity=result['identity'],child_identity=result['child_identity'],
        inputs_sha256=result.get('inputs_sha256'),
        immutable_receipt=str(A/('round154-observed-'+name+'.json')))

source_binding = read(C/'source-binding.json')
assert source_binding['source_inverse_byte_equal']
assert source_binding['exact_bank_class_copy_except_namespace']
new = owners['Opt4-address-banked-complete-module-r1-20261112']
reservation = dict(utc=utc,candidate=str(C),
    state=new['state_path'],unit='ec-opt4-address-banked-complete-module-r1-20261112.service',
    owner='existing unattended optimizer round154',cpus=[226,227],memory_limit_gib=64,
    inputs_sha256=sha(C/'inputs.json'),
    source_binding=str(C/'source-binding.json'),source_binding_sha256=sha(C/'source-binding.json'),
    status=new['status'],identity=new['identity'],geometry=source_binding['geometry'],
    no_cad=True,fpga_access=False,production_admission=False,
    complete_source_inverse_byte_equal=True,exact_r4_bank_class_except_namespace=True,
    complete_formal_equivalence=False,whole_host_saving_unknown=True,
    next='Complete-module finite parity/ABI and r4 fullsize material paired gain; then complete-module GoldenGate/channel/token checks and actual same-harness host pair before fresh complete-host postopt.')
write(A/'round154-complete-source-integration.json',reservation)
with (A/'round154-policy.lock').open('a') as lock:
    fcntl.flock(lock,fcntl.LOCK_EX)
    before = P.read_bytes()
    policy = json.loads(before)
    key = 'foreground_complete_address_banked_integration_round154'
    assert key not in policy
    policy[key] = reservation
    bank = owners['Opt4-address-banked-state-fame5-r4-20261112']
    previous = policy.get('foreground_structural_threading_next',{}).get('banked_state_owner',{})
    # Never overwrite a newer foreground recovery unknown to this round.
    if any(version in previous.get('candidate','') for version in ['fame5-r3-','fame5-r4-']):
        bank_owner = dict(candidate=str(W/'candidates/address-banked-state-fame5-r4-20261112'),
            state=bank['state_path'],unit='ec-opt4-address-banked-state-fame5-r4-20261112.service',
            inputs_sha256=bank['inputs_sha256'],no_duplicate=True,preserve=True,
            scope='Five complete bucket-state vectors; external qualification; not complete AddressStats or EC.')
        policy['foreground_structural_threading_next']['banked_state_owner'] = bank_owner
        policy['foreground_banked_bucket_state_sharing_round153'].update(bank_owner,
            status='ADOPT_EXISTING_R4_NO_DUPLICATE',latest_round154_observed_status=bank['status'])
    assert P.read_bytes() == before, 'Concurrent policy update: preserve and merge again'
    temp = P.with_name('campaign-policy.round154.tmp')
    temp.write_text(json.dumps(policy,indent=2,sort_keys=True)+'\n')
    os.replace(temp,P)
    write(A/'round154-policy-update.json',dict(utc=utc,
        before_sha256=hashlib.sha256(before).hexdigest(),after_sha256=sha(P),
        added_key=key,banked_r4_adopted=True,no_live_input_edits=True))

receipt = dict(utc=utc,round=154,owners=owners,
    source_binding_sha256=sha(C/'source-binding.json'),
    actual_new_service=reservation['unit'],actual_new_stage=new['status'],
    new_service_scope='Complete AddressStats target source integration and finite parity only; no CAD',
    no_duplicate_maps=True,no_existing_input_edits=True,no_board_access=True,
    full_generated_host_lut=2420482,host_shell_excluded=True,host_gap=1116802,
    fullshell_lut=2789012,fullshell_gap=1485332,
    fit=False,deadline='2026-11-18 Asia/Shanghai; time unspecified',
    current_validated_route_can_meet_deadline=False,
    no_measured_EC_FMR_MHz_or_slowdown=True,
    scope_limit='Source inverse and finite parity are not formal equivalence, FAME5 token equivalence, host gain or whole EC FIT. Original r4/histogram/packed/DSP owners remain sole screen/map owners.')
write(A/'round154-structural-progress.json',receipt)
print(json.dumps(dict(receipt=str(A/'round154-structural-progress.json'),
    actual_new_service=receipt['actual_new_service'],actual_new_stage=new['status'],
    owners={k:v['status'] for k,v in owners.items()})))
