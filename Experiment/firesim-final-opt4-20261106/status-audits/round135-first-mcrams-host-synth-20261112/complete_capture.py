#!/usr/bin/env python3
"""Finish the immutable report capture across a natural r6 G-to-H transition."""
import datetime
import importlib.util
import json
from pathlib import Path
import subprocess
import sys

sys.dont_write_bytecode = True
O = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('capture_helpers', O / 'capture.py')
m = importlib.util.module_from_spec(spec)
spec.loader.exec_module(m)


def main():
    now = datetime.datetime.now(datetime.timezone.utc).isoformat()
    analysis = json.loads((O / 'hierarchy.json').read_text())
    # All saved report copies must still match the completed consumer receipt.
    for item in analysis['source_reports'] + [analysis['parser']]:
        assert m.sha(Path(item['copy']).read_bytes()) == item['sha256']
    early = json.loads((O / 'early-synth-capacity.json').read_text())
    boot = Path('/proc/sys/kernel/random/boot_id').read_text().strip()
    assert boot == 'd6c6e410-10ad-4326-86ba-79b657eabd96'
    expected = [
        (3109899, '28470862', 'ec-opt4-svb-host40-shell-physical-r6.service'),
        (3109930, '28470947', 'ec-opt4-svb-host40-shell-follow-r6.service'),
        (3110004, '28471027', 'ec-opt4-svb-host40-shell-application-follow-r6.service'),
        (2379596, '25825420', 'ec-opt4-auto-mcrams-full-host-capacity-r1-3656aec4.service'),
        (2379656, '25825451', 'ec-opt4-auto-mcrams-full-host-capacity-r1-3656aec4.service'),
        (2759828, '27368804', 'ec-opt4-mcrams-host-continuation-r3-clock-3656aec4.service'),
        (2797798, '27514959', 'ec-opt4-auto-mcrams-ipcollateral-recovery-observer-r4b-3656aec4.service'),
        (2813002, '27638842', 'ec-opt4-auto-svb-application-fpga-metrics-r1-8491167d.service'),
    ]
    identities = [m.identity(pid, start, unit, boot) for pid, start, unit in expected]
    services = []
    for unit in sorted({item[2] for item in expected}):
        result = subprocess.run(['systemctl', 'show', unit, '-p', 'MainPID', '-p', 'ControlGroup', '-p', 'ActiveState'], check=True, capture_output=True, text=True)
        props = dict(line.split('=', 1) for line in result.stdout.splitlines())
        assert props['ActiveState'] == 'active'
        assert props['ControlGroup'] == '/system.slice/' + unit
        services.append(dict(unit=unit, properties=props))
    physical_unit = expected[0][2]
    cg = Path('/sys/fs/cgroup/systemd/system.slice') / physical_unit / 'cgroup.procs'
    physical_processes = []
    for pid_text in cg.read_text().split():
        try:
            p = Path('/proc') / pid_text
            start = (p / 'stat').read_text().rsplit(')', 1)[1].split()[19]
            physical_processes.append(m.identity(int(pid_text), start, physical_unit, boot))
        except FileNotFoundError:
            continue  # A short-lived child can naturally leave during capture.
    tool = [p for p in physical_processes if '/unwrapped/' in p['argv'][0] and p['argv'][0].endswith('/vivado')]
    assert len(tool) == 1
    assert 'H-postroute-placement-critical-cell' in ' '.join(tool[0]['argv'])
    m.save('identities.json', dict(observed_utc=now, identities=identities,
           services=services, r6_physical_processes=physical_processes,
           completed_G_pid=3109996, completed_G_start_ticks='28471000',
           completed_G_present=Path('/proc/3109996/stat').exists(),
           processes_signalled=[]))
    gpath = m.D / 'cycleprecise-svb-host40-shell-recovery-r6-20261112/G-postroute-critical-routing/result.json'
    gbytes, gevidence = m.capture(gpath, 'r6-G-result.json')
    g = json.loads(gbytes)
    assert g['status'] == 'FAILED_WITH_EVIDENCE' and g['bitstream'] is None
    checked_outputs = {}
    for suffix in ['final-timing.rpt', 'drc-final.rpt', 'route-final.rpt', 'check-timing.rpt']:
        path = gpath.parent / suffix
        data, ev = m.capture(path, 'r6-G-' + suffix)
        assert m.sha(data) == g['outputs'][str(path)]
        checked_outputs[str(path)] = ev
    qbytes, qevidence = m.capture(m.D / 'unattended-opt4/requests/svb-application-fpga-metrics-r1-8491167d.json', 'metrics-request.json')
    rbytes, revidence = m.capture(m.D / 'unattended-opt4/request-results/svb-application-fpga-metrics-r1-8491167d.json', 'metrics-request-result.json')
    broker = json.loads(rbytes)
    assert broker['status'] == 'STARTED' and broker['request_sha256'] == m.sha(qbytes)
    observation = dict(schema='ec-opt4-round135-measured-host-observation/1', observed_utc=now,
        complete_host_synth_resources=early['resources'],
        synth_LUT_excess=early['resource_excess']['CLB LUTs'],
        functional_baseline=early['functional_baseline'],
        derived_target_commit=early['derived_target_commit'],
        postopt_pending_in_captured_early_receipt=True, physical_FIT=False,
        scope='complete FPGATop OOC synthesis; U280 shell excluded',
        r6_G_result=gevidence, r6_G_final_timing=g['timing'],
        r6_G_small_reports_verified=checked_outputs,
        r6_H_live=tool[0], r6_certified=False,
        metrics_request=qevidence, metrics_broker_receipt=revidence,
        metrics_status='EXISTING_SINGLETON_RUNNING_READONLY_WAITING_CERTIFIED_R5_APPLICATION_RECEIPTS',
        observer_r4b='EXISTING_SINGLETON_ALIVE_WAITING_ACTUAL_R3_FAILURE',
        launched_jobs=[], new_requests=[], FPGA_operations=[], CPU_comparison_controls=[],
        root_operations=[], bound_source_changes=[],
        normal_CAD_recheck_seconds=300, whole_CAD_recheck_seconds=600)
    m.save('observation.json', observation)
    m.save('capture-transition.json', dict(
        initial_capture='Static reports and hierarchy succeeded; prior live G PID naturally exited before the identity capture.',
        initial_exception="FileNotFoundError: /proc/3109996/stat",
        evidence='G completed at ' + g['completed_utc'] + '; unchanged existing controller started H.',
        recovery='Preserved partial capture and independently completed identity/receipt capture.',
        CAD_actions=[]))
    report = f"""Round 135 publishes the first completed owner-MCRams complete-host synthesis counts: **2,421,933 LUTs** (185.78% of 1,303,680), **1,696,044 FFs**, **80,994 CARRY8**, **898.5 BRAM tiles**, **192 DSPs**, and **0 URAM**. The synth LUT excess is **1,118,253**. Zero blackboxes and primitive/hierarchy crosschecks pass. These are complete FPGATop OOC synth counts; post-opt remains pending in the captured early receipt and the U280 shell is excluded. No physical FIT or FPGA result follows from them.

The measured hierarchy places 881,587 LUTs in `dcache_/addressStats` and 2,218 LUTs in the hoisted `ownerImageMemory_flattened` wrapper (its RamModel child: 2,217 LUTs, 932 FFs, 1.5 BRAM tiles). Parent/child totals overlap; the top immediate-child LUT sum also exceeds the authoritative top by 7. Use the total report for capacity. A module name alone does not prove source-level ownership after transformations. Future equivalent-host work should use these measured costs and the authoritative post-opt hierarchy; the existing full-address-storage producer remains independent and unchanged. No new synthesis or candidate is launched.

During capture the existing r6 controller naturally finished G: final WNS **{g['timing']['wns']:+.3f} ns**, WHS **{g['timing']['whs']:+.3f} ns**, {g['timing']['setup_failing']} setup failures and {g['timing']['hold_failing']} hold failures. Its result is FAILED_WITH_EVIDENCE with no bitstream. The same controller automatically started H; Vivado PID **{tool[0]['pid']}**, start_ticks **{tool[0]['start_ticks']}**, exact physical-r6 cgroup. H is active; no final H timing or certification is claimed.

The existing MCrams capacity Vivado (2379656/start25825451), r3 continuation, r4b IP-collateral observer, r6 followers and single read-only metrics consumer (2813002/start27638842) match boot ID/start ticks/exact service cgroups. The metrics broker receipt says STARTED, superseding its historical queued memory deferral; it still awaits certified r5 application receipts. No request was duplicated or guard bypassed. Completed owner parity remains finite captured-event parity, without full-state or strict-latency equivalence.

Next automatic actions: existing r6 H -> I -> J, then strict certification and only 0000:21:00.0/serial21770433G02LA directed and same-bit application replay if all gates pass. Existing MCrams capacity continues to post-opt; r3 physical continuation needs actual FIT plus parity, with the existing r4b observer available only after actual shell-contract failure. No complete-host resynthesis, root/device action, or CPU-comparison control was performed. Ordinary CAD checks >=300 seconds; whole-CAD checks >=600 seconds.
"""
    with (O / 'REPORT.md').open('x') as stream:
        stream.write(report)
    print(json.dumps(dict(status='CAPTURE_COMPLETE', synth_LUTs=2421933,
          r6_G_final_timing=g['timing'], r6_H_pid=tool[0]['pid'],
          identity_checks=len(identities), metrics='EXISTING_RUNNING', audit=str(O))))


if __name__ == '__main__':
    main()
