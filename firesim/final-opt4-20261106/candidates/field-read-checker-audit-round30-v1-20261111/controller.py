#!/usr/bin/python3
"""Source-bound checker review only; no full candidate job or area admission."""
from pathlib import Path
import datetime
import fcntl
import hashlib
import importlib.util
import json
import os
import subprocess

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path(__file__).resolve().parent
L = D / 'build-logs/Opt4-fit-field-read-checker-audit-round30-v1-20261111'
S = D / 'Opt4-fit-field-read-checker-audit-round30-v1-state.json'


def read(p):
    return json.loads(Path(p).read_text())


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def policy():
    p = read(D / 'unattended-opt4/campaign-policy.json')
    assert p['functional_baseline_commit'] == '8491167d84b6d9521b151a743673c1516926a1f8'
    assert p['area_equivalence_only'] and not p['functional_extensions_allowed']
    assert p['native_paused'] and not p['fpga_access']


def save(p, j):
    q = p.with_name(p.name + '.tmp-' + str(os.getpid()))
    with q.open('w') as f:
        json.dump(j, f, indent=2, sort_keys=True)
        f.write('\n'); f.flush(); os.fsync(f.fileno())
    os.replace(q, p)


def load_module(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def main():
    policy()
    L.mkdir(exist_ok=True)
    lock = (L / 'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    assert not S.exists(), 'version partial-stage recovery'
    manifest = read(C / 'input-hashes.json')
    assert all(sha(p) == h for p, h in manifest.items())
    binding = read(W / 'candidates/dcache-field-read-prune-r1-20261111/binding.json')
    fields = Path('/proc/self/stat').read_text().rsplit(')', 1)[1].split()
    st = dict(schema='ec-opt4-checker-context-audit/1', pid=os.getpid(), start_ticks=fields[19],
              host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip(),
              hardware_commit=binding['hardware_commit'], source_id=binding['source_id'],
              status='CHECKING_WIDTH_CONTEXT_AND_EXACT_PREDICATE_FACTORING',
              started_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
              fpga_access=False, production_admission=False, resources=None,
              scope='Verification-tool snapshot review only. Does not run or duplicate complete generated candidate proof, module mapping, whole CAD, runtime, or FPGA I/O.')
    save(S, st)
    exact = load_module('exact_predicate_checker', C / 'canonical.py')
    prototype = load_module('prototype_snapshot', C / 'evidence/canonical.py')
    parent = "module Check(input a, output y);\nwire t = ~a;\nassign y = (t == 2'h2);\nendmodule"
    candidate = "module Check(input a, output y);\nassign y = (~a == 2'h2);\nendmodule"
    proposed = prototype.compare(parent, candidate, set())
    restricted = exact.compare(parent, candidate, set())
    assert proposed['identical'], 'snapshot changed: preserve mismatch for review'
    assert not restricted['identical'], 'restricted rule must not normalize complement width context'
    policy()
    semantic = """module WidthContext(input a, output parent, candidate, equivalent);
 wire t = ~a;
 assign parent = (t == 2'h2);
 assign candidate = (~a == 2'h2);
 assign equivalent = parent == candidate;
 endmodule
"""
    rtl = L / 'width-context.v'
    with rtl.open('x') as f: f.write(semantic)
    script = L / 'width-context.ys'
    with script.open('x') as f:
        f.write(f'read_verilog {rtl}\nprep -top WidthContext\nsat -verify -prove equivalent 1 -show-inputs -show parent -show candidate -timeout 60\n')
    log = L / 'width-context-counterexample.log'
    with log.open('xb') as f:
        child = subprocess.Popen(['/usr/local/bin/yosys', '-s', str(script)], stdout=f,
                                 stderr=subprocess.STDOUT, stdin=subprocess.DEVNULL)
        st['child'] = dict(pid=child.pid,
                          start_ticks=Path(f'/proc/{child.pid}/stat').read_text().rsplit(')', 1)[1].split()[19],
                          host_boot_id=st['host_boot_id'])
        save(S, st)
        rc = child.wait(timeout=120)
    assert rc != 0 and 'model found: FAIL' in log.read_text(), 'actual semantic counterexample required'
    policy()
    validation = load_module('predicate_selfcheck', C / 'initial-selfcheck.py')
    validation.run(L)
    original = W / 'candidates/dcache-field-read-generated-r2-20261111/canonical.py'
    st.update(status='PASS_CHECKER_REVIEW_WITH_SAT_WIDTH_COUNTEREXAMPLE_AND_RESTRICTED_PREDICATE_VALIDATION_NOT_CANDIDATE_ADMISSION',
              child={}, prototype_snapshot=str(C / 'evidence/canonical.py'),
              prototype_snapshot_sha256=sha(C / 'evidence/canonical.py'),
              current_foreground_checker_matches_snapshot=sha(original) == sha(C / 'evidence/canonical.py'),
              prototype_false_positive=proposed, restricted_rejects_context_mutation=restricted,
              semantic_counterexample=dict(log=str(log), sha256=sha(log), returncode=rc),
              restricted_checker_validation=read(L / 'checker-validation.json'),
              input_hashes=manifest, ended_utc=datetime.datetime.now(datetime.timezone.utc).isoformat())
    assert all(sha(p) == h for p, h in manifest.items())
    save(S, st); save(L / 'result.json', st)


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        if S.exists():
            st = read(S)
            if st.get('pid') == os.getpid():
                st.update(status='FAILED_WITH_EVIDENCE', error=repr(exc))
                save(S, st)
        raise
