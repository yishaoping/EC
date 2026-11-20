#!/usr/bin/python3
"""Finite control tests in a temporary directory. Never invoke Vivado/devices."""
import importlib.util
import json
from pathlib import Path
import tempfile

C = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('resource_recovery51', C/'controller.py')
m = importlib.util.module_from_spec(spec)
spec.loader.exec_module(m)


def main():
    m.policy()
    checks = []

    def check(name, predicate):
        assert predicate, name
        checks.append(name)

    base = dict(memory_kib=128*2**20, disk_bytes=96*2**30, load1=47.999)
    check('unchanged exact memory/disk lower bounds accepted', m.resources(**base)['eligible'])
    for name, change in [
            ('low memory rejected', dict(memory_kib=128*2**20-1)),
            ('low disk rejected', dict(disk_bytes=96*2**30-1)),
            ('load exactly48 rejected', dict(load1=48)),
            ('high load rejected', dict(load1=60)),
            ('unknown load rejected', dict(load1=float('nan'))),
            ('negative load rejected', dict(load1=-1))]:
        check(name, not m.resources(**{**base, **change})['eligible'])
    unit = m.OLD_WORKERS[0]
    empty = dict(MainPID='0', ActiveState='failed', ControlGroup='')
    with tempfile.TemporaryDirectory(prefix='svb-resource-preflight-') as td:
        t = Path(td)
        h = t/'cgroup'
        h.mkdir()
        check('missing hierarchy fails closed', not m.exact_empty(unit, empty, t/'missing'))
        check('missing group accepted after failed PID0', m.exact_empty(unit, empty, h))
        check('active PID0 rejected', not m.exact_empty(unit, {**empty, 'ActiveState':'active'}, h))
        check('inactive nonzero PID rejected', not m.exact_empty(unit, {**empty, 'MainPID':'123'}, h))
        check('foreign group rejected', not m.exact_empty(unit, {**empty, 'ControlGroup':'/foreign'}, h))
        group = h/'system.slice'/unit
        group.mkdir(parents=True)
        check('missing procs fails closed', not m.exact_empty(unit, empty, h))
        (group/'cgroup.procs').write_text('')
        child = group/'child'
        child.mkdir()
        (child/'cgroup.procs').write_text('123\n')
        check('empty reported group cannot hide child task', not m.exact_empty(unit, empty, h))
        (child/'cgroup.procs').write_text('')
        check('all exact cgroups empty accepted', m.exact_empty(unit, empty, h))

        # Exercise the actual worker boundary. Temporary outputs cannot be
        # mistaken for campaign proof, DCP, bitstream or measurement artifacts.
        m.OUT = t/'attempts'
        m.OUT.mkdir()
        m.STATE = t/'monitor.json'
        class Fake:
            calls = 0
            def eligibility(self, producer, mode):
                return dict(eligible=True)
            def run(self, producer, mode):
                self.calls += 1
        fake = Fake()
        rejected = lambda: m.resources(**{**base, 'load1':60})
        check('resource failure defers', m.run_attempt(fake, 'spread', 'postroute', rejected) == 'deferred')
        check('resource deferral never calls CAD', fake.calls == 0)
        check('deferral consumes no attempt path', not list(m.OUT.iterdir()))
        check('monitor explicitly labels no attempt', m.read(m.STATE)['status'].endswith('NO_CAD_ATTEMPT'))

        original_empty = m.exact_empty
        m.exact_empty = lambda unit: False
        admitted = lambda: m.resources(**base)
        check('old live recovery defers', m.run_attempt(fake, 'spread', 'postroute', admitted) == 'deferred')
        check('old live recovery never invokes CAD', fake.calls == 0)
        m.exact_empty = lambda unit: True
        check('all gates must pass before invocation', m.run_attempt(fake, 'spread', 'postroute', admitted) == 'finished')
        check('one admitted invocation only', fake.calls == 1)

        for line in [141, 142, 143]:
            try:
                exec(compile('\n'*(line-1)+'assert False\n', str(m.R1/'run.py'), 'exec'))
            except AssertionError as error:
                check('resource traceback classifier line'+str(line), m.guard_race(error) == (line in [141,142]))
        class Race(Fake):
            def run(self, producer, mode):
                exec(compile('\n'*141+'assert False\n', str(m.R1/'run.py'), 'exec'))
        check('resource admission race defers', m.run_attempt(Race(), 'spread', 'postroute', admitted) == 'deferred')
        check('resource race consumes no attempt path', not list(m.OUT.iterdir()))
        class Fault(Fake):
            def run(self, producer, mode):
                raise RuntimeError('injected unrelated failure')
        check('unrelated failure remains failure', m.run_attempt(Fault(), 'spread', 'postroute', admitted) == 'failed')
        check('unrelated failure preserved outside attempt', (m.OUT/'spread-postroute-failure.json').is_file())
        m.exact_empty = original_empty

    code = (m.R1/'run.py').read_text().splitlines()
    check('original memory/disk assertion site unchanged', 'mem >= 128*2**20' in code[140] and '96*2**30' in code[140])
    check('original strict load assertion site unchanged', "< 48" in code[141])
    follower = (m.R1/'runtime.py').read_text()
    check('existing follower permits nested immutable result', 'assert result.is_relative_to(ROOT)' in follower)
    check('original capsule hash retained for live follower', "capsule_inputs_sha256=m.sha(C/'inputs.json')" in (m.R1/'run.py').read_text())
    result = dict(schema='ec-svb-resource-recovery-preflight/1',
                  status='PASS_RESOURCE_DEFERRAL_AND_STRICT_CGROUP_NEGATIVES',
                  checks=checks, count=len(checks), completed_utc=m.now(),
                  cad_invocations=0, device_operations=0, fpga_access=False,
                  target_changed=False, source_sha256=m.sha(C/'controller.py'))
    path = C/'preflight.json'
    assert not path.exists(), 'immutable preflight; use new version'
    m.save(path, result)
    print(json.dumps(result, indent=2))


if __name__ == '__main__':
    main()
