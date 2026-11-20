#!/usr/bin/python3
"""Sample the exact live complete MCRams synthesis without stopping CAD."""
import json
import os
from pathlib import Path
import subprocess
import time

OUT = Path(__file__).resolve().parent
PID = 2379656
START = '25825451'
UNIT = 'ec-opt4-auto-mcrams-full-host-capacity-r1-3656aec4.service'


def identity():
    p = Path('/proc') / str(PID)
    s = (p / 'stat').read_text().rsplit(')', 1)[1].split()
    argv = (p / 'cmdline').read_bytes().split(b'\0')
    cg = (p / 'cgroup').read_text()
    assert s[19] == START and s[0] not in ['Z', 'X']
    assert '/' + UNIT in cg
    assert argv[0].decode().endswith('/unwrapped/lnx64.o/vivado')
    assert b'Opt4-mcrams-full-host-capacity-r1-20261112' in b' '.join(argv)
    return dict(pid=PID, start_ticks=s[19], cpu_ticks=int(s[11])+int(s[12]),
                rss_bytes=int(s[21])*os.sysconf('SC_PAGE_SIZE'), cgroup=cg,
                boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())


assert os.geteuid() == 0
before = identity()
data = OUT / 'timing-synth.perf.data'
assert not data.exists()
argv = ['/usr/bin/perf', 'record', '-e', 'cpu-clock', '-F', '49',
        '--call-graph', 'fp', '-p', str(PID), '-o', str(data), '--',
        '/usr/bin/sleep', '12']
r = subprocess.run(argv, capture_output=True, text=True, timeout=30)
(OUT / 'perf-record.log').write_text(r.stdout + r.stderr)
assert r.returncode == 0, r.stderr
with (OUT / 'timing-synth-profile.txt').open('x') as f:
    subprocess.run(['/usr/bin/perf', 'report', '--stdio', '--no-children',
                    '--sort', 'comm,dso,symbol', '--percent-limit', '0.5',
                    '-i', str(data)], stdout=f, stderr=subprocess.STDOUT,
                   check=True, timeout=30)
after = identity()
assert after['boot_id'] == before['boot_id']
receipt = dict(captured_unix=time.time(), before=before, after=after, argv=argv,
               returncode=r.returncode, cad_signals=[], cad_inputs_changed=False,
               fpga_access=False)
(OUT / 'profile-receipt.json').write_text(json.dumps(receipt, indent=2)+'\n')
print('EXACT_LIVE_MCRAMS_TIMING_PROFILE_COMPLETE')
