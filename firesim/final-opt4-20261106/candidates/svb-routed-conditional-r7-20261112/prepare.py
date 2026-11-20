#!/usr/bin/python3
"""Prepare a versioned successor without changing or signalling live r6."""
import ast
import hashlib
import json
from pathlib import Path
import re

C = Path(__file__).resolve().parent
W = C.parent.parent
R6 = W/'candidates/svb-r5-routed-repair-r6-20261112'
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')


def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for b in iter(lambda: f.read(1 << 20), b''):
            h.update(b)
    return h.hexdigest()


def write(name, text):
    p = C/name
    if p.exists():
        assert p.read_text() == text, ('immutable prepared file differs', p)
    else:
        p.write_text(text)


def replace_once(text, old, new):
    assert text.count(old) == 1, (old[:70], text.count(old))
    return text.replace(old, new)


def main():
    controller = (R6/'controller.py').read_text().replace('-r6-20261112', '-r7-20261112')
    controller = controller.replace("schema='ec-original-svb-host40-shell-recovery/6'", "schema='ec-original-svb-host40-shell-recovery/7'")
    controller = replace_once(controller, 'C = Path(__file__).resolve().parent', 'C = Path(__file__).resolve().parent')
    # The directory name is intentionally distinct from the prior repair.
    controller = controller.replace('svb-r5-routed-repair-r7-20261112', C.name)
    start, end = controller.index('def best():'), controller.index('\n\ndef attempt(')
    controller = controller[:start] + '''def best():
    choices = [(E/'final.dcp', timing(E/'final-timing.rpt'))]
    roots = [D/'cycleprecise-svb-host40-shell-recovery-r6-20261112', OUT]
    for root in roots:
        for path in root.glob('*/result.json'):
            r = read(path)
            dcp = path.parent/'final.dcp'
            t = timing(path.parent/'final-timing.rpt')
            route = path.parent/'route-final.rpt'
            if not t or t['whs'] < 0 or not dcp.is_file() or not route.is_file():
                continue
            text = route.read_text()
            counts = [re.search(pattern, text) for pattern in [
                r'# of routable nets\\.+\\s*:\\s*(\\d+)',
                r'# of fully routed nets\\.+\\s*:\\s*(\\d+)',
                r'# of nets with routing errors\\.+\\s*:\\s*(\\d+)',
            ]]
            if not all(counts) or counts[0][1] != counts[1][1] or int(counts[2][1]):
                continue
            assert r['functional_baseline'] == BASE and r['source_id'] == SID
            assert r['outputs'].get(str(dcp)) == sha(dcp)
            choices.append((dcp, t))
    checkpoint, metrics = max(choices, key=lambda x: (x[1]['wns'], x[1]['tns'], -x[1]['setup_failing']))
    save(OUT/'selected-checkpoint.json', dict(checkpoint=str(checkpoint), sha256=sha(checkpoint), timing=metrics, utc=now()))
    return checkpoint


def wait_r6():
    root = D/'cycleprecise-svb-host40-shell-recovery-r6-20261112'
    unit = 'ec-opt4-svb-host40-shell-physical-r6.service'
    ST.update(schema='ec-original-svb-host40-shell-recovery/7', **identity(),
        functional_baseline=BASE, source_id=SID, profile=PROFILE, complete_opt4=False,
        fpga_access=False, target_rtl_changed=False, started_utc=now())
    while True:
        row = read(root/'state.json')
        if (root/'chosen-result.json').exists() or row.get('status') == 'HANDED_TO_INDEPENDENT_HOST40_CERTIFICATION':
            update('R6_BITSTREAM_WINS_NO_SUCCESSOR_CAD_OR_FPGA_ACCESS', child={})
            return False
        props = dict(x.split('=', 1) for x in subprocess.check_output(
            ['systemctl', 'show', unit, '-p', 'MainPID', '-p', 'ActiveState'], text=True).splitlines())
        cg = Path('/sys/fs/cgroup/systemd/system.slice')/unit
        tasks = {int(x) for p in cg.rglob('cgroup.procs') for x in p.read_text().split()} if cg.exists() else set()
        ended = row.get('status') in ['BOUNDED_SHELL_STRATEGIES_FAILED_WITH_ALL_CHECKPOINTS_RETAINED', 'FAILED_WITH_EVIDENCE']
        if ended and not live(row) and not live(row.get('child', {})) and not tasks and props['MainPID'] == '0':
            save(OUT/'r6-failure-handoff.json', dict(predecessor_state=row, state_sha256=sha(root/'state.json'),
                properties=props, cgroup_tasks=[], processes_signalled=False, utc=now()))
            return True
        update('WAITING_R6_EXISTING_INCREMENTAL_STRATEGIES_NO_DUPLICATE_CAD', predecessor_status=row.get('status'),
            predecessor_mode=row.get('mode'), predecessor_tasks=sorted(tasks), child={})
        time.sleep(30)
''' + controller[end:]
    controller = replace_once(controller, "    OUT.mkdir(exist_ok=True)\n    # Reuse", "    OUT.mkdir(exist_ok=True)\n    if not wait_r6():\n        return\n    # Reuse")
    # wait_r6 records this process identity; the original stale-run guard
    # must continue rejecting another process while permitting this waiter.
    controller = replace_once(controller, "    assert not live(old) and not live(old.get('child', {})), 'adopt live repair'", "    assert (not live(old) or old.get('pid') == os.getpid()) and not live(old.get('child', {})), 'adopt live repair'")
    begin = controller.index('    for mode, strategy in [')
    finish = controller.index('    ]:', begin) + len('    ]:')
    controller = controller[:begin] + '''    for mode, strategy in [
        ('K-postroute-aggressive-explore', 'phys_opt_design -directive AggressiveExplore'),
        ('L-postroute-alternate-replication', 'phys_opt_design -directive AlternateReplication'),
        ('M-postroute-critical-SRL-output-reroute', 'repair_critical_srl_output_nets'),
    ]:''' + controller[finish:]
    write('controller.py', controller)

    tcl = (R6/'recover.tcl.in').read_text()
    tcl = replace_once(tcl,
        'if {[lindex $s 0]<0 || [lindex $s 1]<0 || [llength $bad]} {\n  route_design -directive Explore -tns_cleanup\n}',
        '# Prior G/H cleanup was reverted without timing benefit. Preserve routed nets.\nif {[llength $bad]} {\n  route_design -directive Explore\n}')
    tcl = replace_once(tcl, 'if {[lindex $s 0]>=0 && [lindex $s 1]<0} {', 'if {[lindex $s 1]<0} {')
    tcl = replace_once(tcl, '  route_design -directive Explore -tns_cleanup\n  snapshot routed-hold-fixed',
        '  set remaining [get_nets -hier -quiet -filter {ROUTE_STATUS == UNROUTED || ROUTE_STATUS == PARTIAL || ROUTE_STATUS == CONFLICTS}]\n  if {[llength $remaining]} {route_design -directive Explore}\n  snapshot routed-hold-fixed')
    srl_proc = '''proc repair_critical_srl_output_nets {} {
  set nets {}
  foreach path [get_timing_paths -delay_type max -slack_lesser_than 0 -max_paths 256 -nworst 1] {
    foreach point [get_property POINTS $path] {
      set pin [get_property PIN $point]
      if {![llength $pin] || [get_property DIRECTION $pin] ne "OUT"} {continue}
      set cell [get_cells -quiet -of_objects $pin]
      if {[llength $cell]!=1 || ![string match design_1_i/xdma_0/* [get_property NAME $cell]]} {continue}
      if {[get_property REF_NAME $cell] ni {SRL16E SRLC32E}} {continue}
      if {[string tolower [get_property DONT_TOUCH $cell]] in {1 true yes}} {continue}
      set net [get_nets -quiet -of_objects $pin]
      if {[llength $net]!=1 || [llength [get_clocks -quiet -of_objects $net]]} {continue}
      if {[string tolower [get_property DONT_TOUCH $net]] in {1 true yes}} {continue}
      if {[lsearch -exact $nets [lindex $net 0]]<0} {lappend nets [lindex $net 0]}
    }
  }
  if {![llength $nets] || [llength $nets]>64} {error "no bounded negative-setup SRL-output routing opportunity"}
  set f [open {@OUT@/selected-critical-srl-output-nets.txt} w];puts $f [join $nets \\n];close $f
  puts "EC_R7_CRITICAL_SRL_OUTPUT_NETS count=[llength $nets]"
  route_design -unroute -nets $nets
  route_design -nets $nets -delay
}

'''
    tcl = replace_once(tcl, '@STRATEGY@', srl_proc + '@STRATEGY@')
    assert not re.search(r'route_design -unroute\s*\n', tcl)
    write('recover.tcl.in', tcl)
    for name in ['runtime.py', 'certificate.py', 'audit.tcl.in', 'application.py']:
        code = (R6/name).read_text().replace('-r6-20261112', '-r7-20261112').replace('HOST40_R6_', 'HOST40_R7_')
        if name == 'runtime.py':
            code = replace_once(code, "'cycleprecise-original-svb-host40-shell-onboard-r4-20261112']:",
                "'cycleprecise-original-svb-host40-shell-onboard-r4-20261112','cycleprecise-original-svb-host40-shell-onboard-r5-20261112','cycleprecise-original-svb-host40-shell-onboard-r6-20261112']:")
        write(name, code)
    write('physical-clock-contract.json', (R6/'physical-clock-contract.json').read_text())
    plan = dict(schema='ec-svb-failed-r6-conditional-physical-successor/1',
        functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8',
        board_allowlist=['0000:21:00.0'], complete_opt4=False,
        predecessor='r6 all bounded strategies must actually exit without bitstream',
        admission='Verified PID/start_ticks/boot_id and empty exact r6 cgroup; same third-component lock and resource gate',
        evidence='G remaining39paths all PCIe coreclk; worstread_ptr has299loads and91.608%route delay, otherCE paths have232loads and93.465%route delay. H improves WNS another3ps with twoequivalentreplicas.',
        strategies=['AggressiveExplore uses different multi-pass algorithms', 'AlternateReplication uses different critical-cell replication algorithms', 'Reroute only failing shell SRL output nets excluded from prior J selection'],
        no_global_unroute=True, no_rtl_changes=True, no_retiming=True, no_constraint_changes=True,
        no_board_access_before_independent_certification=True,
        cleanup_policy='Do not repeat no-benefit TNS cleanup on completely routed snapshots; route only actual incomplete nets, hold-fix negative Hold regardless of Setup')
    write('repair-plan.json', json.dumps(plan, indent=2, sort_keys=True) + '\n')

    base = json.loads((R6/'inputs.json').read_text())
    base['files'].update({str(C/n): sha(C/n) for n in ['controller.py', 'recover.tcl.in', 'physical-clock-contract.json', 'repair-plan.json', 'prepare.py']})
    write('inputs.json', json.dumps(base, indent=2, sort_keys=True) + '\n')
    rt = json.loads((R6/'runtime-inputs.json').read_text())
    rt['files'].update(base['files'])
    rt['files'].update({str(C/n): sha(C/n) for n in ['runtime.py', 'certificate.py', 'audit.tcl.in', 'inputs.json']})
    write('runtime-inputs.json', json.dumps(rt, indent=2, sort_keys=True) + '\n')
    app = json.loads((R6/'application-inputs.json').read_text())
    app['files'].update(rt['files'])
    app['files'].update({str(C/n): sha(C/n) for n in ['runtime-inputs.json', 'application.py']})
    write('application-inputs.json', json.dumps(app, indent=2, sort_keys=True) + '\n')
    for p in C.glob('*.py'):
        ast.parse(p.read_text(), filename=str(p))
    print('Prepared immutable conditional r7, independent certification and 21-only replay followers; no process or device operations.')


if __name__ == '__main__':
    main()
