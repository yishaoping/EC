#!/usr/bin/python3
"""Trace feedback Clock provenance before channel excision; never alter a clock."""
from pathlib import Path
import datetime
import fcntl
import hashlib
import importlib.util
import json
import os
import resource
import traceback

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path(__file__).resolve().parent
O = D / 'build-logs/Opt4-mt-clock-residual-round39-v1-20261111'
S = D / 'Opt4-mt-clock-residual-round39-v1-state.json'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'

def read(p):
    return json.loads(Path(p).read_text())

def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for b in iter(lambda: f.read(2**20), b''): h.update(b)
    return h.hexdigest()

def save(p, j):
    t = Path(str(p) + '.tmp-' + str(os.getpid()))
    with t.open('x') as f:
        json.dump(j, f, indent=2, sort_keys=True); f.write('\n'); f.flush(); os.fsync(f.fileno())
    os.replace(t, p)

def main():
    policy = read(D / 'unattended-opt4/campaign-policy.json')
    assert policy['functional_baseline_commit'] == BASE and policy['area_equivalence_only']
    assert policy['native_paused'] and not policy['fpga_access']
    assert not O.exists() and not S.exists()
    plan = read(C / 'plan.json')
    for p, digest in plan['inputs'].items(): assert sha(p) == digest
    O.mkdir()
    lock = (O / 'instance.lock').open('a'); fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    st = dict(pid=os.getpid(), start_ticks=Path('/proc/self/stat').read_text().rsplit(')',1)[1].split()[19],
              host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),
              status='TRACING_PRE_EXCISION_CLOCK_ROOTS', functional_baseline=BASE, fpga_access=False)
    save(S, st)
    resource.setrlimit(resource.RLIMIT_AS, (32 * 2**30,) * 2)
    sp = importlib.util.spec_from_file_location('audit', plan['audit_script'])
    a = importlib.util.module_from_spec(sp); sp.loader.exec_module(a)
    circuit, modules = a.parse_fir(Path(plan['checkpoint']))
    names = plan['references']; top = modules[circuit]
    instances = [i for i,m in top['instances'].items() if m == 'FireSim']
    assert len(instances) == 1
    results = {}
    for ref in names:
        assert modules['FireSim']['ports'][ref] == dict(direction='input', type='Clock')
        try:
            root, chain = a.resolve(modules, 'FireSim', ref, ((circuit, instances[0]),))
            for step in chain:
                mod = modules[step['module']]; r = step['reference']
                if '.' in r:
                    i,p = r.split('.'); assert modules[mod['instances'][i]]['ports'][p]['type'] == 'Clock'
                else:
                    assert mod['ports'][r]['type'] == 'Clock'
            results[ref] = dict(status='EXACT_UNCONDITIONAL_WIRE_ROOT', root=root, chain=chain)
        except Exception as e:
            results[ref] = dict(status='UNPROVEN_DO_NOT_RECONNECT', error=repr(e))
    result = dict(schema='ec-opt4-pre-excision-feedback-clock-provenance/1',
         status='DIAGNOSED_SIX_PRE_EXCISION_CLOCKS_NO_REPAIR_OR_ADMISSION',
         functional_baseline=BASE, checkpoint=plan['checkpoint'], inputs=plan['inputs'],
         clock_roots=results, negative_checks=a.negative_checks(),
         target_or_compiler_changed=False, full_fame_passed=False, whole_fit=False, fpga_access=False,
         completed_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
         scope='An earlier compiler checkpoint diagnoses exact feedback wiring; no automatic tie-off or state change is allowed')
    save(O / 'result.json', result)
    st.update(status=result['status'], result=str(O / 'result.json'), updated_utc=result['completed_utc'])
    save(S, st)
    print(json.dumps({r:j['status'] for r,j in results.items()}),flush=True)

if __name__ == '__main__':
    try: main()
    except BaseException as e:
        if O.exists(): save(O / 'failure.json', dict(error=repr(e),traceback=traceback.format_exc()))
        raise
