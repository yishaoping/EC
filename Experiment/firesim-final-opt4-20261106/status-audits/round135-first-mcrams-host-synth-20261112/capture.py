#!/usr/bin/env python3
"""Publish completed synth reports without polling or controlling live CAD."""
import datetime
import hashlib
import importlib.util
import json
from pathlib import Path
import subprocess
import sys

sys.dont_write_bytecode = True
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path('/data1/gzh/EC/firesim/final-opt4-20261106/candidates')
O = Path(__file__).resolve().parent
AREA = D / 'build-logs/Opt4-mcrams-full-host-capacity-r1-20261112'
EARLY = D / 'build-logs/Opt4-mcrams-full-host-continuation-r2-20261112/early-synth-capacity.json'


def sha(data):
    return hashlib.sha256(data).hexdigest()


def save(name, value):
    path = O / name
    with path.open('x') as stream:
        json.dump(value, stream, indent=2, sort_keys=True)
        stream.write('\n')
    return str(path)


def capture(path, name):
    before = path.stat()
    data = path.read_bytes()
    after = path.stat()
    assert (before.st_size, before.st_mtime_ns) == (after.st_size, after.st_mtime_ns)
    with (O / name).open('xb') as stream:
        stream.write(data)
    return data, dict(path=str(path), sha256=sha(data), bytes=len(data),
                      mtime_ns=after.st_mtime_ns, copy=str(O / name))


def hierarchy(text):
    stack, rows = [], []
    for line in text.splitlines():
        if not line.startswith('|'):
            continue
        fields = line.split('|')[1:-1]
        cells = [cell.strip() for cell in fields]
        if len(cells) != 11 or not cells[2].isdigit():
            continue
        indent = len(fields[0]) - len(fields[0].lstrip()) - 1
        assert indent >= 0 and indent % 2 == 0
        depth = indent // 2
        while len(stack) > depth:
            stack.pop()
        assert len(stack) == depth
        own = cells[0].startswith('(')
        rows.append(dict(path='/'.join(stack + [cells[0]]), parent='/'.join(stack),
                         depth=depth, instance=cells[0], module=cells[1],
                         LUTs=int(cells[2]), FFs=int(cells[6]),
                         RAMB36=int(cells[7]), RAMB18=int(cells[8]),
                         DSPs=int(cells[10]), own_row=own))
        if not own:
            stack.append(cells[0])
    return rows


def identity(pid, start, unit, boot):
    p = Path('/proc') / str(pid)
    stat = (p / 'stat').read_text().rsplit(')', 1)[1].split()
    cgroups = (p / 'cgroup').read_text().splitlines()
    exact = [line.split(':', 2)[2] for line in cgroups
             if line.split(':', 2)[1] == 'name=systemd']
    assert stat[19] == start, (pid, stat[19], start)
    assert exact == ['/system.slice/' + unit], (pid, exact, unit)
    return dict(pid=pid, start_ticks=stat[19], host_boot_id=boot,
                process_state=stat[0], cpu_ticks=int(stat[11]) + int(stat[12]),
                exact_cgroup=exact[0],
                argv=(p / 'cmdline').read_bytes().decode().split('\0')[:-1])


def main():
    observed = datetime.datetime.now(datetime.timezone.utc).isoformat()
    early_data, early_evidence = capture(EARLY, 'early-synth-capacity.json')
    early = json.loads(early_data)
    texts, reports = {}, []
    for tag in ['synth-utilization.rpt', 'synth-hierarchical.rpt']:
        data, evidence = capture(AREA / tag, tag)
        assert early['evidence'][str(AREA / tag)] == evidence['sha256']
        reports.append(evidence)
        texts[tag] = data.decode()
    parser_path = C / 'mcrams-full-host-capacity-r1-20261112/resource_parser.py'
    parser_data, parser_evidence = capture(parser_path, 'resource_parser.py')
    spec = importlib.util.spec_from_file_location('captured_resource_parser', O / 'resource_parser.py')
    parser = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(parser)
    totals = parser.parse_total(texts['synth-utilization.rpt'])
    check = parser.parse_hier(texts['synth-hierarchical.rpt'], totals)
    cross = parser.crosschecks(texts['synth-utilization.rpt'], totals)
    assert totals == early['resources']
    assert check['top'] == early['hierarchy_top']
    assert cross == early['crosschecks']
    rows = hierarchy(texts['synth-hierarchical.rpt'])
    assert rows[0]['LUTs'] == totals['CLB LUTs']['used']
    assert len({r['path'] for r in rows}) == len(rows)
    target = 'FPGATop/sim/target'
    system = target + '/FireSim__/lazyModule_/system_'
    dcache = system + '/tile_prci_domain_/tile_reset_domain__boom_tile_/dcache_'

    def children(parent):
        return sorted([r for r in rows if r['parent'] == parent],
                      key=lambda r: r['LUTs'], reverse=True)

    owner = [r for r in rows if not r['own_row'] and r['module'] == 'ownerImageMemory_flattened']
    models = [r for r in rows if not r['own_row'] and r['module'] == 'RamModel']
    assert len(owner) == len(models) == 1
    assert models[0]['parent'] == owner[0]['path']
    addr = [r for r in children(dcache) if r['instance'] == 'addressStats']
    assert len(addr) == 1
    analysis = dict(schema='ec-completed-full-host-synth-hierarchy/1',
        observed_utc=observed, source_reports=reports, parser=parser_evidence,
        resources=totals, hierarchy_top=check['top'], crosschecks=cross,
        hierarchy_rows=len(rows), top_children=children('FPGATop'),
        sim_children=children('FPGATop/sim'), target_children=children(target),
        system_children=children(system), dcache_children=children(dcache),
        address_stats=addr[0], owner_image_wrapper=owner[0], owner_ram_model=models[0],
        top_child_LUT_sum=sum(r['LUTs'] for r in children('FPGATop')),
        top_child_sum_minus_authoritative_total=sum(r['LUTs'] for r in children('FPGATop')) - rows[0]['LUTs'],
        interpretation='Hierarchy rows describe this synthesized netlist; ancestor and descendant totals overlap. Even immediate-child LUT sums differ by 7 from the authoritative top total; use the top utilization report for capacity. Names alone do not prove original source ownership after transforms/hoisting.',
        physical_FIT=False, postopt_pending_in_captured_early_receipt=True,
        scope='Complete owner-MCRams FPGATop OOC synthesis; U280 shell excluded')
    save('hierarchy.json', analysis)
    boot = Path('/proc/sys/kernel/random/boot_id').read_text().strip()
    expected_boot = 'd6c6e410-10ad-4326-86ba-79b657eabd96'
    assert boot == expected_boot
    expected = [
        (3109899, '28470862', 'ec-opt4-svb-host40-shell-physical-r6.service'),
        (3109996, '28471000', 'ec-opt4-svb-host40-shell-physical-r6.service'),
        (3109930, '28470947', 'ec-opt4-svb-host40-shell-follow-r6.service'),
        (3110004, '28471027', 'ec-opt4-svb-host40-shell-application-follow-r6.service'),
        (2379596, '25825420', 'ec-opt4-auto-mcrams-full-host-capacity-r1-3656aec4.service'),
        (2379656, '25825451', 'ec-opt4-auto-mcrams-full-host-capacity-r1-3656aec4.service'),
        (2759828, '27368804', 'ec-opt4-mcrams-host-continuation-r3-clock-3656aec4.service'),
        (2797798, '27514959', 'ec-opt4-auto-mcrams-ipcollateral-recovery-observer-r4b-3656aec4.service'),
        (2813002, '27638842', 'ec-opt4-auto-svb-application-fpga-metrics-r1-8491167d.service'),
    ]
    identities = [identity(pid, start, unit, boot) for pid, start, unit in expected]
    services = []
    for unit in sorted({item[2] for item in expected}):
        result = subprocess.run(['systemctl', 'show', unit, '-p', 'MainPID', '-p', 'ControlGroup', '-p', 'ActiveState'], check=True, capture_output=True, text=True)
        props = dict(line.split('=', 1) for line in result.stdout.splitlines())
        assert props['ActiveState'] == 'active'
        assert props['ControlGroup'] == '/system.slice/' + unit
        services.append(dict(unit=unit, properties=props))
    save('identities.json', dict(observed_utc=observed, host_boot_id=boot,
         identities=identities, services=services, processes_signalled=[]))
    metrics_q = D / 'unattended-opt4/requests/svb-application-fpga-metrics-r1-8491167d.json'
    metrics_result = D / 'unattended-opt4/request-results/svb-application-fpga-metrics-r1-8491167d.json'
    qbytes, qevidence = capture(metrics_q, 'metrics-request.json')
    rbytes, revidence = capture(metrics_result, 'metrics-request-result.json')
    broker = json.loads(rbytes)
    assert broker['status'] == 'STARTED'
    assert broker['request_sha256'] == sha(qbytes)
    save('observation.json', dict(observed_utc=observed,
        complete_host_LUTs=int(totals['CLB LUTs']['used']),
        synth_LUT_excess=int(early['resource_excess']['CLB LUTs']),
        early_report=early_evidence, reports=reports,
        metrics_request=qevidence, metrics_broker_receipt=revidence,
        metrics_status='EXISTING_SINGLETON_RUNNING_READONLY_WAITING_CERTIFIED_R5_APPLICATION_RECEIPTS',
        r6_status='EXISTING_G_REPAIR_ADOPTED_PROCESS_IDENTITY_ONLY_NO_NEW_TIMING_POLL',
        postopt_final_result_pending=True, physical_FIT=False,
        no_new_CAD=True, no_FPGA_IO=True, no_CPU_comparison_control=True,
        all_bound_sources_unchanged=True, launched_jobs=[], new_requests=[]))
    print(json.dumps(dict(LUTs=int(totals['CLB LUTs']['used']),
        LUT_excess=int(early['resource_excess']['CLB LUTs']),
        addressStats_LUTs=addr[0]['LUTs'], owner_image_LUTs=owner[0]['LUTs'],
        verified_live_identities=len(identities), audit=str(O))))


if __name__ == '__main__':
    main()
