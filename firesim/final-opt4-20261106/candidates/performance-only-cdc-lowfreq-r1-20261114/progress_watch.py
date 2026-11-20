#!/usr/bin/env python3
"""Five-minute evidence-based CAD watch; no model, device or healthy-task restart."""
import datetime as dt
import fcntl
import json
import os
from pathlib import Path
import signal
import shlex
import subprocess
import time

C = Path(__file__).resolve().parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'performance-only-cdc-lowfreq-r1-20261114'
FULL = D/'performance-only-memory-cdc-r2-20261114/complete-shell-r3'
OWNER = 'ec-performance-only-cdc-lowfreq-r1-20261114.service'
RECOVERY = 'ec-performance-only-cdc-lowfreq-watch-recovery-r1-20261114.service'
FOLLOW = 'ec-performance-only-cdc-lowfreq-followthrough-r1-20261114.service'
LEGACY = 'ec-performance-only-routability-r3-20261114.service'
FULL_UNIT = 'ec-performance-only-memory-cdc-full-r3-20261114.service'
BOOT = Path('/proc/sys/kernel/random/boot_id').read_text().strip()


def read(p):
    try:
        return json.loads(Path(p).read_text())
    except FileNotFoundError:
        return {}


def save(p, row):
    p = Path(p); tmp = p.with_suffix('.tmp')
    tmp.write_text(json.dumps(row, indent=2)+'\n'); os.replace(tmp, p)


def unit(name):
    result = subprocess.check_output(['systemctl', '--user', 'show', name,
        '-p', 'ActiveState', '-p', 'SubState', '-p', 'MainPID', '-p', 'Result'], text=True)
    return dict(line.split('=', 1) for line in result.splitlines() if '=' in line)


def active(row):
    return row.get('ActiveState') in ['active', 'activating', 'reloading']


def tail(path, size=16384):
    with Path(path).open('rb') as f:
        f.seek(max(0, Path(path).stat().st_size-size))
        return f.read().decode(errors='replace')


def inventory():
    rows = {}
    roots = [str(FULL), str(O), str(D/'performance-only-routability-r1-20261114')]
    for p in Path('/proc').glob('[0-9]*'):
        try:
            if p.stat().st_uid != os.getuid():
                continue
            cmd = (p/'cmdline').read_bytes().replace(b'\0', b' ').decode(errors='replace')
            if not any(root in cmd for root in roots) or '/unwrapped/lnx64.o/vivado' not in cmd:
                continue
            fields = (p/'stat').read_text().rsplit(') ', 1)[1].split()
            io = dict(line.split(': ', 1) for line in (p/'io').read_text().splitlines())
            key = f'{BOOT}:{p.name}:{fields[19]}'
            rows[key] = dict(pid=int(p.name), start_ticks=fields[19], state=fields[0],
                cpu_ticks=int(fields[11])+int(fields[12]), rss_bytes=int(fields[21])*os.sysconf('SC_PAGE_SIZE'),
                io_bytes=sum(int(io.get(k, 0)) for k in ['read_bytes', 'write_bytes']),
                command=cmd, wchan=(p/'wchan').read_text().strip())
        except (FileNotFoundError, ProcessLookupError, PermissionError):
            continue
    return rows


def assess(previous, processes, logs, now):
    """No log update alone is ever sufficient to label an active tool stalled."""
    prior = previous.get('processes', {}) if previous.get('boot_id') == BOOT else {}
    oldlogs = previous.get('logs', {})
    result = {}
    for key, row in processes.items():
        args = shlex.split(row['command'])
        own_log = args[args.index('-log')+1] if '-log' in args else None
        own_logs = {p: v for p, v in logs.items() if p == own_log}
        progressed_logs = any(oldlogs.get(p, {}).get('bytes') != v['bytes'] or
                              oldlogs.get(p, {}).get('mtime_ns') != v['mtime_ns']
                              for p, v in own_logs.items())
        old = prior.get(key, {})
        delta = row['cpu_ticks']-old.get('cpu_ticks', row['cpu_ticks'])
        io_delta = row['io_bytes']-old.get('io_bytes', row['io_bytes'])
        still_since = old.get('no_progress_since', now)
        progressed = not old or delta > 0 or io_delta > 0 or progressed_logs
        if progressed:
            still_since = now
        row.update(cpu_tick_delta=delta, io_byte_delta=io_delta, no_progress_since=still_since)
        result[key] = ('RUNNING_CPU_IO_OR_LOG_PROGRESS' if progressed else
                       'STALLED_CPU_IO_LOG_UNCHANGED_15MIN_DIAGNOSE' if now-still_since >= 900 else
                       'QUIET_INTERVAL_RECHECK_NO_RESTART')
    return result


def recover_owner(services, processes, actions):
    if active(services[OWNER]) or active(services[RECOVERY]) or (O/'result.json').exists():
        return
    if any(str(O) in p['command'] for p in processes.values()):
        actions.append('Orphan low-frequency Vivado is alive: preserve and adopt; no duplicate owner.')
        return
    # An in-flight followthrough recovery already owns the same lock.
    with (O/'owner.lock').open('a') as lock:
        try:
            fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
        except BlockingIOError:
            actions.append('Existing low-frequency orchestration lease held; no duplicate recovery.')
            return
    state = read(O/'state.json')
    if state.get('status') == 'FAILED_WITH_EVIDENCE' and 'Clock/scope probe must pass' not in state.get('error', ''):
        actions.append('Specific owner failure preserved; recovery requires a diagnosed change, never unchanged retry.')
        return
    # Only orchestration vanished; completed synthesis receipts/checkpoints are
    # recovered by the existing controller. No target elaboration is restarted.
    if (O/'physical').exists() and not all(
            (p/'result.json').exists() for p in (O/'physical/candidates').iterdir() if p.is_dir()):
        actions.append('Incomplete physical candidate preserved: no blind placement restart.')
        return
    if not (FULL/'dut_synth-result.json').exists() or not (O/'clock-probe/complete').exists():
        actions.append('Waiting for existing synthesis/clock receipt; no speculative recovery.')
        return
    marker = O/'watch-owner-recovery-request.json'
    if marker.exists():
        actions.append('One bounded owner recovery already requested; inspect its evidence.')
        return
    args = ['systemd-run', '--user', '--unit='+RECOVERY.removesuffix('.service'),
            '--property=CPUQuota=800%', '--property=MemoryMax=144G', '--property=TasksMax=2048',
            '--property=Nice=5', '--property=WorkingDirectory='+str(O),
            '--property=StandardOutput=append:'+str(O/'watch-owner-recovery.log'),
            '--property=StandardError=inherit', '/usr/bin/python3', str(C/'controller.py')]
    save(marker, dict(status='DIAGNOSED_MISSING_OWNER_RESUME_VERIFIED_RECEIPTS',
         previous_owner_state=state, command=args, fpga_access=False, model_requests=False))
    completed = subprocess.run(args, text=True, capture_output=True)
    actions.append(dict(action='resume_missing_owner_from_verified_receipts', returncode=completed.returncode,
                        output=completed.stdout+completed.stderr))


def main():
    with (O/'progress-watch.lock').open('a') as lock:
        fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
        now = time.time(); previous = read(O/'progress-watch-state.json')
        processes = inventory(); logs = {}
        for root in [FULL, O/'physical/candidates', D/'performance-only-routability-r1-20261114/candidates']:
            patterns = ['*-attempt-*.log'] if root == FULL else ['*/vivado.log']
            for pattern in patterns:
                for p in root.glob(pattern):
                    st = p.stat(); text = tail(p)
                    phase = next((line for line in reversed(text.splitlines())
                                  if line.startswith(('Phase ', 'EC_PHYSICAL_STAGE', 'Command:'))), None)
                    logs[str(p)] = dict(bytes=st.st_size, mtime_ns=st.st_mtime_ns,
                        age_seconds=now-st.st_mtime, phase=phase,
                        recent_errors=[l for l in text.splitlines() if l.startswith('ERROR:')][-8:])
        assessment = assess(previous, processes, logs, now)
        services = {u: unit(u) for u in [OWNER, RECOVERY, FOLLOW, LEGACY, FULL_UNIT]}
        actions = []
        for key, status in assessment.items():
            p = processes[key]
            if p['state'] in ['T', 't']:
                # Identity includes boot ID and start ticks; signals only an
                # owned stopped Vivado whose exact command was just checked.
                current = inventory().get(key)
                if current and current['state'] in ['T', 't']:
                    os.kill(p['pid'], signal.SIGCONT)
                    actions.append(dict(action='resume_owned_stopped_vivado', identity=key))
            if status.startswith('STALLED_'):
                proc = Path('/proc')/str(p['pid'])
                task_waits = {}
                for task in (proc/'task').glob('[0-9]*'):
                    try: task_waits[task.name] = (task/'wchan').read_text().strip()
                    except FileNotFoundError: pass
                diag = O/'watch-diagnostics'; diag.mkdir(exist_ok=True)
                save(diag/(str(int(now))+'-'+str(p['pid'])+'.json'),
                     dict(identity=key, process=p, thread_waits=task_waits, services=services,
                          logs=logs, action='Diagnosed without killing or repeating a healthy CAD.'))
        recover_owner(services, processes, actions)
        cad = read(FULL/'cad-state.json'); physical = read(O/'physical/state.json')
        row = dict(utc=dt.datetime.now(dt.timezone.utc).isoformat(), epoch=now, boot_id=BOOT,
            check_interval_seconds=300, model_requests=False, fpga_access=False,
            processes=processes, assessment=assessment, logs=logs, services=services, actions=actions,
            cad_status=cad.get('status'), dut_resources=cad.get('dut_resources'),
            whole_shell_resources=cad.get('top_postopt_resources'),
            owner_status=read(O/'state.json').get('status'), physical_status=physical.get('status'),
            bitstream_result=read(O/'result.json'))
        save(O/'progress-watch-state.json', row)
        with (O/'progress-watch-history.jsonl').open('a') as f:
            f.write(json.dumps(row, separators=(',', ':'))+'\n')
        print(json.dumps(dict(cad=row['cad_status'], owner=row['owner_status'],
                              assessment=assessment, actions=actions)))


if __name__ == '__main__':
    main()
