#!/usr/bin/python3
"""Bind the ABC CEC recovery while preserving both prior SAT timeouts."""
from pathlib import Path
import ast
import hashlib
import importlib.util
import json
import os
import shutil
import subprocess

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D/'unattended-opt4'
C = W/'candidates/address-group8-cec-r1-20261111'
OLD = W/'candidates/address-group8-r1-20261111'
SPLIT = W/'candidates/address-group8-proofsplit-r1-20261111'
TAG = W/'candidates/address-group4-r1-20261111'
F = W/'Opt4-fit-address-group8-r1-20261111'
O = D/'build-logs/Opt4-fit-address-group8-cec-r1-20261111'
REL = 'chipyard/generators/boom/src/main/scala/lsu/'
COMMIT = '32837b0b1987091eb86e4157ec0c6360f5bde58b'
PARENT = '981b890d870130f99ec24a0c5e37acb39362318a'
FROZEN = '8491167d84b6d9521b151a743673c1516926a1f8'

def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as f:
        for block in iter(lambda: f.read(1 << 20), b''):
            h.update(block)
    return h.hexdigest()

def write(path, data):
    path = Path(path); path.parent.mkdir(parents=True, exist_ok=True)
    if path.exists():
        assert path.read_bytes() == data, 'immutable conflict: ' + str(path)
        return
    tmp = path.with_name(path.name + '.tmp-' + str(os.getpid()))
    with tmp.open('xb') as stream:
        stream.write(data); stream.flush(); os.fsync(stream.fileno())
    os.replace(tmp, path)

def save(path, value):
    write(path, (json.dumps(value, indent=2, sort_keys=True) + '\n').encode())

def main():
    assert subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=F, text=True).strip() == COMMIT
    assert subprocess.check_output(['git', 'rev-parse', 'HEAD^'], cwd=F, text=True).strip() == PARENT
    assert subprocess.check_output(['git', 'rev-parse', FROZEN], cwd=F, text=True).strip() == FROZEN
    ast.parse((C/'controller.py').read_text())
    ast.parse(Path(__file__).read_text())
    for name in ['PackageAddressStats.scala', 'AddressBucketGrouped.scala']:
        assert (F/REL/name).read_bytes() == subprocess.check_output(
            ['git', 'show', COMMIT+':'+REL+name], cwd=F)

    build_spec = importlib.util.spec_from_file_location('group8_build_hw', W/'scripts/build_hw.py')
    build_hw = importlib.util.module_from_spec(build_spec); build_spec.loader.exec_module(build_hw)
    inventory = build_hw.inventory(F/'chipyard')
    source_id = hashlib.sha256(json.dumps(inventory, sort_keys=True).encode()).hexdigest()
    old_binding = json.loads((OLD/'binding.json').read_text())
    assert source_id == old_binding['source_id']
    binding = dict(old_binding, schema='ec-opt4-address-group8-cec-binding/1',
        profile='Opt4-fit-address-group8-cec-r1-candidate',
        candidate_change='Hardware RTL remains exactly group8 commit 32837b0b. Recovery changes only the local proof engine and decomposes equivalence by granule: synthesize separate candidate/reference combinational networks and prove them with ABC CEC, with out-of-bound inputs mapped to zero in both wrappers. No result is inferred from either prior SAT timeout.')
    save(C/'binding.json', binding)

    cfg = json.loads((OLD/'config.json').read_text())
    cfg.update(binding=binding, worktree=str(F), minimum_memory_gib=48,
        minimum_disk_gib=40, max_threads=8,
        parent_local_receipt=str(D/'build-logs/Opt4-fit-address-round3-20261110/local-validation-receipt.json'))
    save(C/'config.json', cfg)
    for name in ['frozen-original.v', 'frozen-tb.v']:
        write(C/name, (OLD/name).read_bytes())

    parent_receipt = json.loads(Path(cfg['parent_local_receipt']).read_text())
    proof1 = D/'build-logs/Opt4-fit-address-group8-r1-20261111/proof/sat-equivalent-attempt-1.log'
    proof2 = D/'build-logs/Opt4-fit-address-group8-proofsplit-r1-20261111/proof/sat-equivalent-g0-attempt-1.log'
    job1 = U/'jobs/address-group8-r1-bind2-32837b0b'
    job2 = U/'jobs/address-group8-proofsplit-r1-32837b0b'
    paths = [F/REL/name for name in ['PackageAddressStats.scala', 'AddressBucketGrouped.scala']]
    paths += [C/name for name in ['controller.py', 'prepare_cec.py', 'EmitGroup8.scala',
        'binding.json', 'config.json', 'frozen-original.v', 'frozen-tb.v']]
    paths += [TAG/'controller.py', OLD/'controller.py', OLD/'prepare_group8.py', OLD/'EmitGroup8.scala',
        OLD/'config.json', OLD/'binding.json', OLD/'input-hashes.json',
        SPLIT/'controller.py', SPLIT/'prepare_proofsplit.py', SPLIT/'EmitGroup8.scala',
        SPLIT/'config.json', SPLIT/'binding.json', SPLIT/'input-hashes.json',
        F/'source-inventory.json', F/'candidate.patch', F/'candidate-binding.json', F/'lineage.json',
        F/'bindings'/(COMMIT+'.json'), W/'scripts/build_hw.py', Path(cfg['parent_local_receipt']),
        Path(parent_receipt['tests']['touch_bounds']['log']), proof1,
        D/'build-logs/Opt4-fit-address-group8-r1-20261111/proof/sat-equivalent-result.json',
        proof2, D/'build-logs/Opt4-fit-address-group8-proofsplit-r1-20261111/proof/sat-equivalent-g0-result.json',
        job1/'service.log', job1/'state.json', job2/'service.log', job2/'state.json']
    paths += [Path(path) for path in cfg['classpath'] + cfg['compiler'] + [cfg['plugin']]]
    hashes = {str(path): sha(path) for path in sorted(set(paths), key=str)}
    save(C/'input-hashes.json', hashes)

    report = dict(schema='ec-opt4-group8-cec-preflight/1', status='BOUND_NO_CEC_VERIFICATION_YET',
        hardware_commit=COMMIT, source_id=source_id, input_manifest_sha256=sha(C/'input-hashes.json'),
        prior_failures=[dict(log=str(proof1), sha256=sha(proof1),
            outcome='300-second Yosys SAT timeout; 17,045 variables, 46,986 clauses; no counterexample'),
            dict(log=str(proof2), sha256=sha(proof2),
            outcome='300-second per-granule Yosys SAT timeout; 8,879 variables, 24,648 clauses; no counterexample')],
        recovery='Synthesize one candidate and reference network per granule and use ABC combinational equivalence checking. Wrappers gate invalid source counts to zero on both sides; the theorem covers every legal count, key and query.',
        available_memory_gib=int(next(line.split()[1] for line in Path('/proc/meminfo').read_text().splitlines()
            if line.startswith('MemAvailable:')))/2**20,
        free_disk_gib=shutil.disk_usage(W).free/2**30, max_threads=8,
        minimum_memory_gib=48, minimum_disk_gib=40, fpga_access=False,
        formal_admission=False, full_dut_synthesis=False, production_selected=False,
        proof_limits=['ABC CEC, topology SAT, 8192-vector actual-size boundary test, and 6144-cycle complete-module comparison are still pending.',
            'No full-DUT formal equivalence or whole-system FIT claim.'],
        broker_receipt_issue='Both earlier worker states preserve failure evidence, but their systemd units failed appending CPU_JOB_EXITED because the shared ledger is root-owned mode 0644. This candidate does not modify the broker or ledger.')
    save(O/'candidate-preflight.json', report)
    print(json.dumps(report, sort_keys=True))

if __name__ == '__main__':
    main()
