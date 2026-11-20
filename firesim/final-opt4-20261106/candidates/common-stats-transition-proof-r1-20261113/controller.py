#!/usr/bin/python3
"""Exact state-boundary cone comparison for the committed mixed-role bank.

Reuses authenticated generated bank miter RTL. No elaboration, CAD, FPGA IO,
or claim about caller/GoldenGate/whole EC equivalence.
"""
from pathlib import Path
import fcntl
import hashlib
import json
import os
import resource
import subprocess
import sys
import time

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D / 'build-logs/Opt4-common-stats-transition-proof-r1-20261113'
P = D / 'build-logs/Opt4-common-stats-bank-r3-20261113'
T = W / 'Opt4-area-common-stats-transition-proof-r1-20261113'
sys.path.insert(0, str(W / 'scripts'))
from opt4_unattended_common import identity, now, read, save, sha

ST = {}


def members(unit):
    found = []
    for p in Path('/proc').iterdir():
        if not p.name.isdigit():
            continue
        try:
            if any(l.split(':', 2)[-1].endswith('/' + unit)
                   for l in (p / 'cgroup').read_text().splitlines()):
                found.append(identity(int(p.name)))
        except OSError:
            pass
    return found


def update(status, **kw):
    ST.update(status=status, updated_utc=now(), **kw)
    save(O / 'state.json', ST)


def run_yosys():
    rtl = P / 'target/Pair.v'
    script = O / 'state-boundary.ys'
    script.write_text(f'read_verilog -sv {rtl}\nhierarchy -top Pair\nproc\nopt_clean\nwrite_json {O}/state-boundary.json\n')
    start = time.monotonic()
    with (O / 'state-boundary.log').open('xb') as out:
        child = subprocess.Popen(['/usr/local/bin/yosys', '-Q', '-T', '-s', str(script)],
                                 cwd=O, stdin=subprocess.DEVNULL, stdout=out,
                                 stderr=subprocess.STDOUT)
        while child.poll() is None:
            update('RUNNING_AUTHENTICATED_STATE_BOUNDARY_EXTRACTION',
                   active_stage='state-boundary', child=identity(child.pid),
                   stage_seconds=time.monotonic() - start)
            try:
                child.wait(timeout=30)
            except subprocess.TimeoutExpired:
                pass
    save(O / 'state-boundary-receipt.json', dict(returncode=child.returncode,
         seconds=time.monotonic() - start, script_sha256=sha(script),
         log_sha256=sha(O / 'state-boundary.log')))
    assert child.returncode == 0, ('yosys', child.returncode)
    return read(O / 'state-boundary.json')['modules']


def digest(x):
    return hashlib.sha256(json.dumps(x, sort_keys=True, separators=(',', ':')).encode()).hexdigest()


class Cones:
    def __init__(self, module, role):
        self.module, self.role = module, role
        self.leaves, self.drivers, self.state, self.cache = {}, {}, {}, {}
        for n, p in module['ports'].items():
            if p['direction'] != 'input':
                continue
            semantic = n
            if role == 'common' and n.startswith('io_barrier'):
                tail = n[len('io_barrier'):]
                semantic = 'io_' + tail[0].lower() + tail[1:]
                owner = 'barrier'
            else:
                owner = 'address' if role == 'common' else role
            # Both original banks use exactly the same clock and Module reset.
            if n in ['clock', 'reset']:
                owner = 'shared'
            for i, b in enumerate(p['bits']):
                self.leaves[b] = digest(['input', owner, semantic, i])
        for n, net in module['netnames'].items():
            if n.startswith(('bucketValid_', 'bucketSeq_', 'bucketStore_',
                             'bucketFirstStore_', 'bucketLoadFirst_',
                             'bucketStoreFirst_', 'bucketStrictWriteRead_', 'buckets_')):
                owner = 'barrier' if n.startswith('buckets_') else 'address'
                for i, b in enumerate(net['bits']):
                    assert isinstance(b, int), ('constant state', n, i)
                    label = (owner, n, i)
                    assert b not in self.state, ('aliased state', label)
                    self.state[b] = label
                    self.leaves[b] = digest(['state', *label])
        self.dffs = {}
        for n, c in module['cells'].items():
            if c['type'] == '$dff':
                for i, b in enumerate(c['connections']['Q']):
                    assert b in self.state, ('unaccounted register', n, b)
                    assert b not in self.dffs
                    self.dffs[b] = (c, i)
            else:
                assert not any(t in c['type'].lower() for t in ['dff', 'latch', 'mem']), c['type']
                for p, direction in c['port_directions'].items():
                    if direction == 'output':
                        for i, b in enumerate(c['connections'][p]):
                            if isinstance(b, int):
                                assert b not in self.drivers
                                self.drivers[b] = (c, p, i)
        assert set(self.dffs) == set(self.state), 'Every state bit must have exactly one flop'

    def h(self, b):
        if isinstance(b, str):
            return digest(['constant', b])
        if b in self.leaves:
            return self.leaves[b]
        if b in self.cache:
            return self.cache[b]
        c, p, i = self.drivers[b]
        inputs = {port: [self.h(v) for v in c['connections'][port]]
                  for port, direction in c['port_directions'].items() if direction == 'input'}
        result = digest([c['type'], c['parameters'], p, i, inputs])
        self.cache[b] = result
        return result

    def transitions(self):
        result = {}
        for b, (c, i) in self.dffs.items():
            params = {k: v for k, v in c['parameters'].items() if k != 'WIDTH'}
            result[self.state[b]] = digest([c['type'], params,
                self.h(c['connections']['D'][i]),
                {p: [self.h(x) for x in xs] for p, xs in c['connections'].items()
                 if p not in ['D', 'Q']}])
        return result

    def initial(self):
        result = {}
        for n, net in self.module['netnames'].items():
            if 'init' in net.get('attributes', {}):
                bits = net['bits']
                value = net['attributes']['init']
                assert len(value) == len(bits)
                for b, v in zip(bits, reversed(value)):
                    assert b in self.state
                    result[self.state[b]] = v
        return result

    def outputs(self):
        result = {}
        for n, p in self.module['ports'].items():
            if p['direction'] != 'output':
                continue
            owner = self.role
            semantic = n
            if self.role == 'common':
                owner = 'address'
                if n.startswith('io_barrier'):
                    tail = n[len('io_barrier'):]
                    semantic = 'io_' + tail[0].lower() + tail[1:]
                    owner = 'barrier'
                elif n == 'io_observeBarrier':
                    owner = 'barrier'
            # Vec proof outputs have a suffix and name identifies their half.
            if n.startswith('io_observeBarrier'):
                owner = 'barrier'
            elif n.startswith('io_observeAddress'):
                owner = 'address'
            result[(owner, semantic)] = digest([self.h(b) for b in p['bits']])
        return result


def compare(modules):
    a = Cones(modules['AddressReference'], 'address')
    b = Cones(modules['BarrierReference'], 'barrier')
    c = Cones(modules['StatsBankProof'], 'common')
    expected = {**a.transitions(), **b.transitions()}
    actual = c.transitions()
    assert set(expected) == set(actual)
    unequal = [k for k in expected if expected[k] != actual[k]]
    save(O / 'transition-comparison.json', dict(state_bits=len(expected),
         exact_cone_equal=len(expected) - len(unequal), unequal=unequal,
         expected_digest=digest(sorted((list(k), v) for k, v in expected.items())),
         actual_digest=digest(sorted((list(k), v) for k, v in actual.items()))))
    assert not unequal, ('nonidentical next-state cones require diagnosis', len(unequal), unequal[:10])
    initial = {**a.initial(), **b.initial()}
    assert initial == c.initial(), 'Initial values differ'
    expected_outputs = {**a.outputs(), **b.outputs()}
    actual_outputs = c.outputs()
    assert set(expected_outputs) == set(actual_outputs)
    unequal_outputs = [k for k in expected_outputs if expected_outputs[k] != actual_outputs[k]]
    save(O / 'output-comparison.json', dict(outputs=len(expected_outputs),
         exact_cone_equal=len(expected_outputs) - len(unequal_outputs),
         unequal=unequal_outputs, initialized_state_bits=len(initial)))
    assert not unequal_outputs, ('nonidentical output cones', unequal_outputs[:10])
    # Mutate one actual next-state cone hash: the exact same complete comparison
    # must reject it, without omitting or constraining any state/input bit.
    mutated = dict(actual)
    first = next(iter(mutated))
    mutated[first] = digest(['inverted-next-state-bit', mutated[first]])
    assert mutated != expected and sum(expected[k] != mutated[k] for k in expected) == 1
    save(O / 'negative-comparison.json', dict(rejected=True,
         mutation='one next-state cone signature changed', bit=first,
         limit='Comparator mutation only; not a separately synthesized RTL mutation.'))
    return dict(state_bits=len(expected), initialized_state_bits=len(initial),
                public_and_proof_output_ports=len(expected_outputs),
                arbitrary_state_and_inputs=True, exact_next_state_cone_isomorphism=True,
                reset_clock_and_init_compared=True, outputs_exact_cone_isomorphism=True)


def main():
    O.mkdir(exist_ok=True)
    lock = (O / 'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    assert not (O / 'state.json').exists(), 'Adopt existing owner'
    prior = 'ec-opt4-mshr-split-complete-host-pair-r4-20261112.service'
    assert not members(prior), 'Predecessor resource cgroup must be released'
    save(O / 'predecessor-release.json', dict(unit=prior, utc=now(), members=[]))
    os.sched_setaffinity(0, {204, 205})
    resource.setrlimit(resource.RLIMIT_AS, (32 * 2**30,) * 2)
    binding = read(C / 'source-binding.json')
    assert all(sha(p) == h for p, h in binding['files'].items())
    assert subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=T, text=True).strip() == binding['hardware_commit']
    for rel, h in binding['committed_files'].items():
        assert hashlib.sha256(subprocess.check_output(['git', 'show', binding['hardware_commit'] + ':' + rel], cwd=T)).hexdigest() == h
    ST.update(schema='ec-common-stats-state-transition-cone-proof/1', **identity(),
              started_utc=now(), functional_baseline=binding['functional_baseline'],
              hardware_commit=binding['hardware_commit'],
              hardware_source_commit=binding['hardware_source_commit'],
              source_binding_sha256=sha(C / 'source-binding.json'),
              cpus=[204, 205], memory_limit_gib=32, fpga_access=False,
              full_system_fit=False, production_admission=False,
              scope='Exact generated16-lane common bank vs separate address/barrier bank next-state and output cones. No caller, host-transform or whole EC equivalence.')
    update('VERIFYING_AUTHENTICATED_GENERATED_BANK_STATE_BOUNDARY')
    result = compare(run_yosys())
    assert all(sha(p) == h for p, h in binding['files'].items())
    update('PASS_EXACT_COMMON_BANK_STATE_TRANSITION_AND_OUTPUT_CONES',
           child={}, ended_utc=now(), proof=result, target_transition_equivalence_local=True,
           host_equivalence=False, whole_EC_equivalence=False,
           netlist_sha256=sha(O / 'state-boundary.json'))
    save(O / 'result.json', ST)


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        if ST:
            update('FAILED_WITH_EVIDENCE_VERSIONED_CORRECTION_REQUIRED',
                   error=repr(exc), ended_utc=now())
            save(O / 'failure.json', ST)
        raise
