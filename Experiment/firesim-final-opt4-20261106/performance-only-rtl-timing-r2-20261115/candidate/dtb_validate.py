#!/usr/bin/env python3
"""Check actual generator classes against a complete independently compiled DTB."""
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys

C = Path(__file__).resolve().parent
T = C.parent.parent
W = T.parent
R = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = Path(sys.argv[1]).resolve()
SOURCE = T/'chipyard/generators/rocket-chip/src/main/scala/diplomacy/DeviceTree.scala'
DTS = Path('/var/tmp/guozh-ec-rtl-structure-r1-20261114/full-r3/elaborate/firesim.firesim.FireSim.dts')


def main():
    os.sched_setaffinity(0, {248, 249})
    os.nice(19)
    O.mkdir(parents=True, exist_ok=False)
    env = {k:v for k,v in os.environ.items() if k not in
           ['PYTHONHOME', 'PYTHONPATH', 'LD_LIBRARY_PATH', 'LD_PRELOAD', 'JAVA_TOOL_OPTIONS']}
    cfg = json.loads((W/'candidates/common-composed-source-r2-20261113/config.json').read_text())
    cp = ':'.join([str(R/'build-logs/Opt4-performance-only-fpga-r1-20261113/classes'),
                   cfg['firechip'], *cfg['classpath']])
    java = [cfg['java'], '-Xmx1G', '-XX:ActiveProcessorCount=2']
    classes = O/'classes'
    classes.mkdir()
    commands = []

    def run(name, argv, require_success=True):
        with (O/(name+'.log')).open('xb') as log:
            p = subprocess.run(list(map(str, argv)), cwd=O, env=env, stdin=subprocess.DEVNULL,
                               stdout=log, stderr=subprocess.STDOUT, timeout=300)
        commands.append(dict(name=name, argv=list(map(str, argv)), returncode=p.returncode))
        if require_success:
            assert p.returncode == 0, (name, p.returncode)
        return (O/(name+'.log')).read_text()

    run('dtc', ['dtc', '-I', 'dts', '-O', 'dtb', '-o', O/'expected.dtb', DTS])
    run('compile-probe', java+['-cp', ':'.join(cfg['compiler']), 'scala.tools.nsc.Main',
        '-classpath', cp, '-d', classes, C/'DtbProbe.scala'])
    old = run('original-probe', java+['-cp', str(classes)+':'+cp, 'ectimingdtb.DtbProbe',
        DTS, O/'expected.dtb', '64'], require_success=False)
    # Replace the exact production generator class, then rerun the same probe.
    run('compile-generator', java+['-cp', ':'.join(cfg['compiler']), 'scala.tools.nsc.Main',
        '-classpath', cp, '-d', classes, SOURCE])
    new = run('candidate-probe', java+['-cp', str(classes)+':'+cp, 'ectimingdtb.DtbProbe',
        DTS, O/'expected.dtb', '64'])
    assert 'iterations=64 failures=0' in new
    expected = (O/'expected.dtb').read_bytes()
    assert len(expected) == int.from_bytes(expected[4:8], 'big')
    (O/'result.json').write_text(json.dumps(dict(
        status='PASS_DTB_FILE_OUTPUT_EXACT_BYTES', iterations=64,
        original_probe=[line for line in old.splitlines() if line.startswith('DTB_')],
        candidate_probe=[line for line in new.splitlines() if line.startswith('DTB_')],
        log_sha256={n:hashlib.sha256((O/n).read_bytes()).hexdigest()
                    for n in ['original-probe.log', 'candidate-probe.log']},
        source_sha256=hashlib.sha256(SOURCE.read_bytes()).hexdigest(),
        dts_sha256=hashlib.sha256(DTS.read_bytes()).hexdigest(),
        expected_dtb_sha256=hashlib.sha256(expected).hexdigest(), expected_bytes=len(expected),
        commands=commands, new_RTL_function=False), indent=2)+'\n')


if __name__ == '__main__':
    main()
