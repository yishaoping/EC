#!/usr/bin/env python3
"""Preserve this exact failed run, then stop only its controller and driver."""
import datetime as dt
import hashlib
import json
import os
from pathlib import Path
import select
import shutil
import signal
import subprocess

ROOT = Path(__file__).resolve().parent
SUITE = ROOT.parent
RUN = SUITE / 'runs/blackscholes'
CONTROLLER, DRIVER = 1529793, 1531902

def save(path, value):
    path.write_text(json.dumps(value, indent=2, sort_keys=True) + '\n')
    os.chown(path, 1008, 1008)

def sha(path):
    h = hashlib.sha256()
    with path.open('rb') as f:
        for b in iter(lambda: f.read(8 * 1024 * 1024), b''):
            h.update(b)
    return h.hexdigest()

def wait_exit(fd, milliseconds):
    poll = select.poll(); poll.register(fd, select.POLLIN)
    return bool(poll.poll(milliseconds))

assert os.geteuid() == 0
assert not (ROOT/'stop-result.json').exists(), 'Already stopped; do not repeat'
state = json.loads((RUN/'state.json').read_text())
assert state['pid'] == DRIVER and state['board_bdf'] == '0000:21:00.0'
assert state['start_ticks'] == Path(f'/proc/{DRIVER}/stat').read_text().rsplit(') ', 1)[1].split()[19]
driver_cmd = Path(f'/proc/{DRIVER}/cmdline').read_bytes()
controller_cmd = Path(f'/proc/{CONTROLLER}/cmdline').read_bytes()
assert b'+bus=21\0' in driver_cmd and b'+bus=e2' not in driver_cmd
assert str(SUITE/'run.py').encode() in controller_cmd
assert Path(f'/proc/{DRIVER}/stat').read_text().rsplit(') ', 1)[1].split()[1] == str(CONTROLLER)
assert b'sbi_trap_error: hart1: trap handler failed' in (RUN/'uart.log').read_bytes()
cf, df = os.pidfd_open(CONTROLLER), os.pidfd_open(DRIVER)
os.kill(CONTROLLER, signal.SIGSTOP)  # Prevent the old queue from advancing.
evidence = ROOT/'failure-evidence'; evidence.mkdir(exist_ok=False)
for directory in [RUN, SUITE]:
    target = evidence/('run' if directory == RUN else 'suite'); target.mkdir()
    for source in directory.iterdir():
        if source.is_file() and source.suffix in ['.json', '.log', '.csv', '.md', '.py', '.in'] or (source.is_file() and source.name.startswith('rtl-events-')):
            shutil.copy2(source, target/source.name)
proc = {}
for pid in [CONTROLLER, DRIVER]:
    row = {}
    for name in ['cmdline','stat','status','io','syscall','wchan','maps','schedstat']:
        try: row[name] = Path(f'/proc/{pid}/{name}').read_bytes().decode(errors='replace').replace('\0', ' ')
        except OSError as e: row[name] = str(e)
    row['fd'] = {}
    for f in Path(f'/proc/{pid}/fd').iterdir():
        try: row['fd'][f.name] = str(f.readlink())
        except OSError: pass
    proc[str(pid)] = row
save(evidence/'process-context.json', proc)
plan = json.loads((SUITE/'plan.json').read_text())
cert = json.loads(Path(plan['certificate']).read_text())
artifacts = [Path(plan[k]) for k in ['bitstream','certificate','driver']]
artifacts += [Path('/var/tmp/guozh-ec-rtl-timing-r2-20261115/full-combined-qualified')/f for f in ['host/FireSim-generated.sv','host/FireSim-generated.const.h','source-binding.json','target-graph-audit.json','rtl-state.json']]
row = next(r for r in plan['programs'] if r['program'] == 'blackscholes')
artifacts += [Path(row['firmware']), Path(row['fdt'])]
artifacts += [Path(f) for f in row['receipts'].values()]
manifest = {}
preserved = evidence/'artifacts'; preserved.mkdir()
for index, source in enumerate(artifacts):
    assert source.is_file(), source
    target = preserved/f'{index:02d}-{source.name}'
    subprocess.run(['/bin/cp', '--reflink=auto', '--preserve=timestamps', str(source), str(target)], check=True)
    manifest[str(source)] = {'sha256': sha(target), 'bytes': target.stat().st_size, 'copy': str(target)}
save(evidence/'artifact-manifest.json', manifest)
print(json.dumps({'status':'EVIDENCE_SAVED_QUEUE_FROZEN','evidence':str(evidence)}), flush=True)
assert os.getpgid(DRIVER) == DRIVER
os.killpg(DRIVER, signal.SIGTERM)
forced = not wait_exit(df, 15000)
if forced:
    os.killpg(DRIVER, signal.SIGKILL)
    assert wait_exit(df, 5000), 'Driver did not exit'
os.kill(CONTROLLER, signal.SIGTERM)
os.kill(CONTROLLER, signal.SIGCONT)
assert wait_exit(cf, 5000), 'Controller did not exit'
os.close(cf); os.close(df)
for source in RUN.iterdir():
    if source.is_file() and source.suffix in ['.log','.csv'] or (source.is_file() and source.name.startswith('rtl-events-')):
        shutil.copy2(source, evidence/'run'/source.name)
ended = dt.datetime.now(dt.timezone.utc).isoformat()
failure = {'status':'FAILED_CHECKER_TRAP','program':'blackscholes','input':'simmedium','configuration':'ECPerformanceOnly','full_PALIMPSEST':False,'valid':False,'roi_cycles':None,'slowdown':None,'checkers_with_fatal_trap':[1,3],'ended_utc':ended,'evidence':str(evidence),'retry_required_after_root_cause_fix':True,'automatically_advance_queue':False}
save(RUN/'failure.json', failure)
state.update(status='FAILED_CHECKER_TRAP', ended_utc=ended, issues=['fatal checker instruction access fault; sample invalid'])
save(RUN/'state.json', state)
save(SUITE/'state.json', {**failure,'pid':CONTROLLER,'phase':'ROOT_CAUSE_REPAIR','current_program':'blackscholes','results':[],'valid_completed_samples':0})
active = SUITE.parent/'active-0000_21_00.0.json'
if active.exists() and json.loads(active.read_text()).get('pid') == DRIVER:
    save(active, state)
save(ROOT/'stop-result.json', {**failure,'controller_stopped':True,'driver_stopped':True,'forced_sigkill':forced,'fpga_reset':False,'bitstream_changed':False,'card_host_ownership_released':True})
subprocess.run(['/bin/chown','-R','1008:1008',str(evidence)],check=True)
print(json.dumps({'status':'FAILED_CHECKER_TRAP_STOPPED','driver':DRIVER,'controller':CONTROLLER,'forced_sigkill':forced}),flush=True)
