#!/usr/bin/env python3
"""Read real process, CAD and controller evidence for this continuation."""
from pathlib import Path
import hashlib
import json
import os
import re
import subprocess
import sys

W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C=W/'candidates/svb-host40-shell-recovery-r5-20261112'
OUT=Path(__file__).resolve().parent
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import identity,live,now,read,save,sha

def unit(name):
    props=dict(x.split('=',1) for x in subprocess.check_output(
      ['systemctl','show',name,'-p','MainPID','-p','ActiveState','-p','ControlGroup'],text=True).splitlines() if '=' in x)
    cg=Path('/sys/fs/cgroup/systemd/system.slice')/name
    tasks=sorted({int(x) for p in cg.rglob('cgroup.procs') for x in p.read_text().split()}) if cg.exists() else []
    return dict(unit=name,properties=props,processes=[identity(p) for p in tasks])

def main():
    for n in ['inputs.json','runtime-inputs.json','application-inputs.json']:
        assert all(sha(p)==h for p,h in read(C/n)['files'].items())
    stages={}
    for name in ['C-postroute-clock-skew','D-shell-critical-shortest-route']:
        root=D/'cycleprecise-svb-host40-shell-recovery-r4-20261112'/name
        result=read(root/'result.json')
        for p in [root/'final.dcp',root/'final-timing.rpt',root/'route-final.rpt',root/'drc-final.rpt']:
            assert sha(p)==result['outputs'][str(p)]
        txt=(root/'final-timing.rpt').read_text()
        match=re.search(r'\n\s*(-?\d+\.\d+)\s+(-?\d+\.\d+)\s+(\d+)\s+\d+\s+(-?\d+\.\d+)\s+(-?\d+\.\d+)\s+(\d+)\s+\d+\s+(-?\d+\.\d+)',txt)
        assert match
        stages[name]=dict(result=str(root/'result.json'),sha256=sha(root/'result.json'),status=result['status'],
            wns_ns=float(match[1]),tns_ns=float(match[2]),setup_failing_endpoints=int(match[3]),
            whs_ns=float(match[4]),hold_failing_endpoints=int(match[6]))
    states={p:read(D/p) for p in [
        'cycleprecise-svb-host40-shell-recovery-r5-20261112/state.json',
        'cycleprecise-original-svb-host40-shell-onboard-r5-20261112/state.json',
        'cycleprecise-original-svb-host40-shell-application-onboard-r5-20261112/state.json',
        'Opt4-mcrams-full-host-capacity-r1-state.json',
        'Opt4-mcrams-full-host-continuation-r2-state.json',
        'Opt4-mcrams-owner-mc-runtime-r2-state.json',
        'fpga-priority-handoff-r1-20261112/state.json',
        'unattended-opt4/state.json']}
    units=[unit(n) for n in [
        'ec-opt4-svb-host40-shell-physical-r4.service',
        'ec-opt4-svb-host40-shell-physical-r5.service',
        'ec-opt4-svb-host40-shell-follow-r5.service',
        'ec-opt4-svb-host40-shell-application-follow-r5.service',
        'ec-opt4-auto-svb-physical-resource-recovery-r51-v1.service',
        'ec-opt4-auto-svb-physical-resume-r3-v1-8491167d.service',
        'ec-opt4-auto-mcrams-full-host-capacity-r1-3656aec4.service',
        'ec-opt4-auto-owner-mc-runtime-r2-3656aec4.service',
        'ec-opt4-unattended-r2.service']]
    root=D/'cycleprecise-svb-host40-shell-recovery-r5-20261112'
    log_rows=[]
    replication={}
    for log in root.glob('*/vivado.log'):
        st=log.stat();txt=log.read_text(errors='replace')
        lines=txt.splitlines()
        if log.parent.name=='E-preroute-shell-replication':
            count=re.search(r'Optimized (\d+) nets\. Created (\d+) new instances\.',txt)
            replication=dict(private_unroute_succeeded='All nets in the design were unrouted.' in txt,
                physopt_completed='phys_opt_design completed successfully' in txt,
                optimized_nets=int(count[1]) if count else None,
                added_cells=int(count[2]) if count else None,
                routed_timing_required=True)
        log_rows.append(dict(path=str(log),bytes=st.st_size,mtime_ns=st.st_mtime_ns,
            tail='\n'.join(lines[-12:]),
            support_markers=[x for x in lines if any(s in x for s in [
                'force_replication_on_nets','Physical Optimization','Post Routing Timing Summary',
                'ERROR:','EC_HOST40_SHELL_SNAPSHOT tag=','EC_SVB_HOST40_BITSTREAM_COMPLETE'])][-20:]))
    audit=dict(schema='ec-fpga-r5-continuation-audit/1',updated_utc=now(),
        functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8',board_allowlist=['0000:21:00.0'],
        complete_ec_fpga_samples=0,component_fpga_samples=0,r4=stages,states=states,units=units,
        selected_checkpoint=read(root/'selected-checkpoint.json'),r5_logs=log_rows,actual_replication=replication,
        installation=read(C/'installation.json'),source_bindings_verified=True,
        original_r4_tcl_gate_sha256=sha(C/'recover.tcl.in'),
        original_r4_certificate_sha256=sha(C/'certificate.py'),
        no_existing_cad_signalled=True,no_cpu_experiment_jobs_controlled=True)
    save(OUT/'snapshot.json',audit)
    status=states['cycleprecise-svb-host40-shell-recovery-r5-20261112/state.json']
    text=f'''# FPGA continuation, {audit['updated_utc']}

SVB r4 completed without a certified bitstream. C remains the best final
checkpoint: WNS −0.411 ns, TNS −292.970 ns, 2,130 setup failing endpoints,
WHS +0.001 ns. D completed with WNS −0.503 ns, TNS −343.017 ns,
2,299 setup failing endpoints, WHS +0.001 ns. Their routed checkpoints and
failure receipts are preserved; neither is deployable. Both have zero route
errors and 49 warning DRC violations.

Independent r5 is installed and started: {status.get('status')},
mode {status.get('mode')}, controller PID {status.get('pid')}.
It holds r4's released extra-component-slot lock and uses a private copy of
the best completed checkpoint. E removes routing before bounded shell FD-Q
replication. If E fails, F automatically removes routing on a private copy
of the best final checkpoint and applies explicit fanout/placement/routing
optimization. Actual support and timing improvement must come from Vivado;
offline binding checks do not establish either. No retiming or RTL changes.

The original complete Tcl timing/route/DRC/pulse/skew/clock gate and independent
certificate are byte-identical. Three new services run physical recovery,
independent certification plus card21 directed testing, and same-bit real
application trace replay. All bitstream, source, software, locks, board serial
and correctness bindings remain required. SVB is a component, not complete EC.
The measured same-slot guard remains CPUs 224–225, 64 GiB, max3 component Vivados,
192 GiB available memory, load1 below128, disk at least150 GiB.

MCRams complete generated host synthesis and owner-MC parity remain under
their original controllers and exact cgroups. New LUT/FIT is still unknown;
the capacity/parity continuation and complete EC priority runtime remain alive.
The old completed 9ae full post-opt result is 2,847,382 LUT, NOT FIT; it is not
a new MCRams measurement. No new whole-system CAD was started.

Original r51 and resumed-r3 routing are preserved. Global unattended r2 remains
active and its next-worker instructions now identify r5, its evidence, and the
automatic failure-recovery requirement. No CPU replacement experiment was
controlled. Only0000:21:00.0/serial21770433G02LA can be admitted after certification.

Complete EC PARSEC order remains Blackscholes, Fluidanimate, Bodytrack,
Freqmine, Swaptions, Ferret, Dedup, Streamcluster; first cover r1, then r2/r3.
ROI target cycles, checker correctness/events, drain and output gates remain.
No new FPGA sample or strict detection/rollback latency is claimed.

Validation: Python compilation; unchanged gate/certificate byte comparison;
immutable source/software input verification; original runtime/application
offline binding checks; actual systemd start and process/cgroup verification.
The contemporaneous detailed evidence is in snapshot.json. No credentials
were written into artifacts.
'''
    (OUT/'REPORT.md').write_text(text)
    if replication.get('physopt_completed'):
        with (OUT/'REPORT.md').open('a') as f:
            f.write('\nActual tool milestone: forced replication completed successfully after private unroute. '
                f'Vivado reports {replication["optimized_nets"]} optimized nets and {replication["added_cells"]} added cells. '
                'New routed timing is still required; unrouted timing estimates do not certify closure.\n')
    print(json.dumps(dict(updated_utc=audit['updated_utc'],r5_status=status.get('status'),r5_mode=status.get('mode'),
        r5_controller=status.get('pid'),mcrams=states['Opt4-mcrams-full-host-capacity-r1-state.json'].get('status'),report=str(OUT/'REPORT.md'))))

if __name__=='__main__':main()
