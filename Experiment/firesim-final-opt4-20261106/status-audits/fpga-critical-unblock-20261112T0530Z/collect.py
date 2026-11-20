#!/usr/bin/python3
"""Bounded evidence snapshot; never writes producer state or controls devices."""
from pathlib import Path
import datetime
import hashlib
import json
import os
import re
import subprocess

OUT=Path(__file__).resolve().parent
D=OUT.parent.parent
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')


def read(p):
    return json.loads(p.read_text()) if p.is_file() else {}


def sha(p):
    h=hashlib.sha256()
    with p.open('rb') as f:
        for b in iter(lambda:f.read(2**20),b''):h.update(b)
    return h.hexdigest()


def identity(pid):
    p=Path('/proc')/str(pid)
    if not p.is_dir():return {}
    a=(p/'stat').read_text().rsplit(')',1)[1].split()
    return dict(pid=pid,start_ticks=a[19],state=a[0],cpu_ticks=int(a[11])+int(a[12]),
                rss_bytes=int(a[21])*os.sysconf('SC_PAGE_SIZE'),cgroup=(p/'cgroup').read_text())


def main():
    now=datetime.datetime.now(datetime.timezone.utc).isoformat()
    states={n:read(D/n) for n in [
        'Opt4-mcrams-full-host-capacity-r1-state.json',
        'Opt4-mcrams-full-host-continuation-r2-state.json',
        'Opt4-mcrams-owner-mc-runtime-r2-state.json',
        'cycleprecise-svb-host40-shell-recovery-r5-20261112/state.json',
        'cycleprecise-original-svb-host40-shell-onboard-r5-20261112/state.json',
        'cycleprecise-original-svb-host40-shell-application-onboard-r5-20261112/state.json',
        'fpga-priority-handoff-r1-20261112/state.json']}
    sroot=D/'cycleprecise-svb-host40-shell-recovery-r5-20261112'
    log=sroot/'E-preroute-shell-replication/vivado.log'
    text=log.read_text()
    svb=dict(log=str(log),log_sha256=sha(log),log_mtime_utc=datetime.datetime.fromtimestamp(log.stat().st_mtime,datetime.timezone.utc).isoformat(),
        intermediate_timing=re.findall(r'Intermediate Timing Summary[^\n]+',text),
        overlaps=[int(x) for x in re.findall(r'Number of Nodes with overlaps = (\d+)',text)],
        snapshots=re.findall(r'^EC_HOST40_SHELL_SNAPSHOT.*$',text,re.M),
        result=read(sroot/'E-preroute-shell-replication/result.json'),
        chosen=read(sroot/'chosen-result.json'),bitstreams=list(map(str,sroot.glob('*/*.bit'))))
    area=D/'build-logs/Opt4-mcrams-full-host-capacity-r1-20261112'
    text=(area/'vivado.log').read_text()
    mcrams=dict(log=str(area/'vivado.log'),log_sha256=sha(area/'vivado.log'),phase=(area/'phase.txt').read_text().strip(),
        last_log_lines=text.splitlines()[-10:],result=read(area/'result.json'),
        actual_reports={name:dict(path=str(area/name),bytes=(area/name).stat().st_size,sha256=sha(area/name)) for name in ['synth-utilization.rpt','synth-hierarchical.rpt','postopt-utilization.rpt','postopt-hierarchical.rpt'] if (area/name).is_file()},
        checkpoints=list(map(str,area.glob('*.dcp'))),
        early_reports={tag:read(D/f'build-logs/Opt4-mcrams-full-host-continuation-r2-20261112/early-{tag}-capacity.json') for tag in ['synth','postopt']})
    par=D/'cycleprecise-owner-mc-runtime-r2-20261112/run-MCRams.log'
    with par.open('rb') as f:
        f.seek(max(0,par.stat().st_size-262144));tail=f.read().decode(errors='replace')
    cycles=re.findall(r'cycle=([0-9a-f]{16})',tail)
    parity=dict(last_observed_target_cycle=int(cycles[-1],16) if cycles else None,log_bytes=par.stat().st_size,
        result=read(par.parent/'result.json'),finite_target_parity_complete=(par.parent/'result.json').exists())
    units=['ec-opt4-svb-host40-shell-physical-r5.service','ec-opt4-svb-host40-shell-follow-r5.service',
        'ec-opt4-svb-host40-shell-application-follow-r5.service','ec-opt4-auto-mcrams-full-host-capacity-r1-3656aec4.service',
        'ec-opt4-mcrams-host-continuation-r3-clock-3656aec4.service','ec-opt4-fpga-priority-handoff-r1.service']
    services={u:subprocess.check_output(['systemctl','show',u,'-p','MainPID','-p','ActiveState','-p','ControlGroup'],text=True) for u in units}
    snap=dict(schema='ec-fpga-critical-unblock-evidence/1',captured_utc=now,
        functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8',board_allowlist=['0000:21:00.0'],
        states=states,services=services,processes={str(pid):identity(pid) for pid in [2379594,2379596,2379656,2378806,2378807,2692645,2692703,2759828]},
        svb=svb,mcrams=mcrams,parity=parity,fpga_operations_this_turn=[],cpu_comparison_control_operations=[])
    p=OUT/'snapshot.json';q=p.with_suffix('.tmp');q.write_text(json.dumps(snap,indent=2)+'\n');q.replace(p)
    print(json.dumps(dict(captured_utc=now,SVB_last_overlap=svb['overlaps'][-1],SVB_final=svb['result'].get('status'),
        MCRams_reports=list(mcrams['actual_reports']),MCRams_result=mcrams['result'].get('status'),MC_cycle=parity['last_observed_target_cycle'])))


if __name__=='__main__':main()
