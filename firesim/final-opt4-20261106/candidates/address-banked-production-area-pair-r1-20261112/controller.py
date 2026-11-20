#!/usr/bin/python3
"""Adopt validated production hosts; measure their exact serial OOC area pair."""
import fcntl
import importlib.util
import json
import os
from pathlib import Path
import re
import resource
import shutil
import sys
import time

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'build-logs/Opt4-address-banked-production-area-pair-r1-20261112'
P = D/'build-logs/Opt4-address-banked-production-host-r1-20261112'
SOURCE = W/'candidates/address-banked-production-host-r1-20261112'
UNIT = 'ec-opt4-address-banked-production-host-r1-20261112.service'
PASS = 'PASS_COMPLETE_TARGET_FINITE_PARITY_AND_COMPLETE_HOST_TOKENS_NO_AREA_OR_FIT'
TOOL = '/tools/Xilinx/Vivado/2021.1/bin/vivado'
PART = 'xcu280-fsvh2892-2L-e'
spec = importlib.util.spec_from_file_location('immutable_area_tools',
    W/'candidates/address-histogram-fame5-r6-20261112/controller.py')
m = importlib.util.module_from_spec(spec); spec.loader.exec_module(m)
m.C, m.O, m.CPUS = C, O, {212, 213}
from opt4_unattended_common import identity, live, now, read, save, sha

parser_spec = importlib.util.spec_from_file_location('strict_resource_parser',
    W/'candidates/mcrams-full-host-capacity-r1-20261112/resource_parser.py')
parser = importlib.util.module_from_spec(parser_spec); parser_spec.loader.exec_module(parser)


def cgroup_paths(pid):
    try:
        return (Path('/proc')/str(pid)/'cgroup').read_text().splitlines()
    except FileNotFoundError:
        return []


def owner_members():
    """Exact service membership, including descendants; never signal an owner."""
    expected = '/user.slice/user-1008.slice/user@1008.service/'+UNIT
    members = []
    for p in Path('/proc').iterdir():
        if not p.name.isdigit():
            continue
        if any(line.split(':', 2)[-1] == expected for line in cgroup_paths(p.name)):
            row = identity(int(p.name))
            if row and row['process_state'] not in ['Z', 'X']:
                members.append(row)
    return members


def prerequisites(result):
    assert result.get('status') == PASS, 'Production host target/token PASS required'
    assert result.get('finite_parity') is True
    assert result.get('target_cycles') == 6144 and result.get('monitor_outputs') == 5684
    assert result.get('host_tokens') == 3003 and result.get('production_public_outputs') == 52
    assert result.get('geometry') == dict(banks=16, lanes=16, slots=256)
    tokens = result['tokens']
    for name in ['Plain', 'Threaded']:
        assert tokens[name]['target_tokens'] == 3003
        assert tokens[name]['checked_outputs'] == 3000*52
    assert tokens['Plain']['digest'] == tokens['Threaded']['digest']
    assert result['source_binding_sha256'] == sha(SOURCE/'source-binding.json')
    pins = read(P/'inputs.json')['files']
    assert all(sha(p) == h for p, h in pins.items()), 'Production inputs changed'
    receipts = {}
    for name in ['full-target-parity', 'full-target-negative',
                 'token-oracle-Plain', 'token-negative-Plain',
                 'token-oracle-Threaded', 'token-negative-Threaded']:
        path = P/(name+'-receipt.json'); receipt = read(path)
        assert receipt['accepted'] and not receipt['missing_outputs']
        assert receipt['negative'] == ('negative' in name)
        assert (receipt['returncode'] != 0) == receipt['negative']
        assert sha(receipt['log']) == receipt['log_sha256']
        receipts[str(path)] = sha(path)
    return dict(result_sha256=sha(P/'result.json'), receipts=receipts,
                production_inputs_sha256=sha(P/'inputs.json'),
                source_binding_sha256=sha(SOURCE/'source-binding.json'))


def wait_for_owner():
    while True:
        state, result = read(P/'state.json'), read(P/'result.json')
        if result.get('status') == PASS:
            gate = prerequisites(result)
            members = owner_members()
            if not members and not live(state):
                return gate
            m.update('WAITING_EXACT_VALIDATION_OWNER_CGROUP_RELEASE', members=members)
        elif state.get('status', '').startswith('FAILED'):
            raise RuntimeError(('Production validation failed; version diagnosed recovery before area',
                                str(P/'failure.json')))
        else:
            m.update('QUEUED_FOR_COMPLETE_PRODUCTION_TARGET_AND_HOST_TOKEN_PASS',
                     prerequisite_status=state.get('status'), prerequisite_identity=identity(state.get('pid'))
                     if state.get('pid') else {})
        time.sleep(30)


def target_ports(path, top):
    text = path.read_text()
    match = re.search(r'\bmodule '+re.escape(top)+r'\s*\((.*?)\);', text, re.S)
    assert match, ('Missing target module', str(path), top)
    return re.findall(r'\b(input|output)\s*(\[\d+:\d+\])?\s+(\w+)', match.group(1))


def production_abi():
    candidate = P/'Module-target/ProductionModuleCandidate.v'
    reference = D/'build-logs/Opt4-address-packed-full-module-r1-20261112/Reference-Module/FPGATop.v'
    ports = target_ports(candidate, 'ProductionModuleCandidate')
    assert ports == target_ports(reference, 'FPGATop')
    outputs = [n for d, w, n in ports if d == 'output']
    assert len(outputs) == 52 and all(not n.startswith('io_debug') for n in outputs)
    # Validate actual generated complete-module host interfaces as well as
    # source declarations. No proof-only channel may enter the area pair.
    for name in ['Plain', 'Threaded']:
        audit = read(P/(name+'-threading-audit.json'))
        assert audit['selected_count'] == 16 and audit['proof_ports_absent']
        rtl = P/name/'FireSim-generated.sv'
        assert sha(rtl) == audit['host_RTL_sha256']
        fir = (P/name/'post-gen-sram-models.fir').read_text()
        assert not re.search(r'io_debug(?:Buckets|Valid|Seq|Bucket)', fir)
        assert ('module BucketBank_threaded :' in fir) == (name == 'Threaded')
    return dict(reference_RTL_sha256=sha(reference), candidate_RTL_sha256=sha(candidate),
                identical_public_ports=ports, public_outputs=52, proof_ports_absent=True,
                reference_host='Plain', candidate_host='Threaded',
                geometry=dict(banks=16, lanes=16, slots=256))


def tcl_text(host):
    collateral = sorted(host.glob('*.v'))+[host/'FireSim-generated.sv']
    return ('set_param general.maxThreads 2\n'+
            ''.join(f'read_verilog -sv {{{p}}}\n' for p in collateral)+
            f'read_xdc {{{host/"FireSim-generated.synthesis.xdc"}}}\n'+
            f'synth_design -mode out_of_context -top FPGATop -part {PART}\n'+
            'if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "blackbox"}\n'+
            f'report_utilization -file {{{host/"utilization.rpt"}}}\n'+
            f'report_utilization -hierarchical -file {{{host/"hierarchical.rpt"}}}\n'+
            f'write_checkpoint -force {{{host/"host.dcp"}}}\nexit 0\n')


def map_signature(tcl):
    """Only accept the exact existing two-thread same-directive mapper."""
    host = tcl.parent
    text = tcl.read_text()
    assert text == tcl_text(host), 'Different CAD directives or source ordering'
    sources = sorted(host.glob('*.v'))+[host/'FireSim-generated.sv',
                                           host/'FireSim-generated.synthesis.xdc']
    return dict(files=[dict(name=p.name, bytes=p.stat().st_size, sha256=sha(p)) for p in sources],
                tool=TOOL, tool_wrapper_sha256=sha(TOOL), part=PART,
                top='FPGATop', mode='out_of_context', max_threads=2,
                no_blackboxes=True)


def measured_result(host):
    total = parser.parse_total((host/'utilization.rpt').read_text())
    parser.parse_hier((host/'hierarchical.rpt').read_text(), total)
    parser.crosschecks((host/'utilization.rpt').read_text(), total)
    return dict(resources={k: v['used'] for k, v in total.items()},
                outputs={str(host/n): sha(host/n) for n in
                         ['utilization.rpt', 'hierarchical.rpt', 'host.dcp', 'map.tcl', 'FireSim-generated.sv']})


def compatible_checkpoint(signature):
    # Completed stage receipts only. Partial/live maps are never restarted
    # or adopted as a completed result. Source bytes and directives must match.
    inspected = 0
    for directory in sorted((D/'build-logs').iterdir()):
        if not directory.is_dir() or directory == O:
            continue
        for receipt_path in sorted(directory.glob('*-receipt.json')):
            receipt = read(receipt_path)
            args = receipt.get('argv', [])
            if not args or args[0] != TOOL or '-source' not in args:
                continue
            if not receipt.get('accepted') or receipt.get('returncode') != 0:
                continue
            inspected += 1
            tcl = Path(args[args.index('-source')+1])
            try:
                if map_signature(tcl) != signature:
                    continue
                host = tcl.parent
                required = [host/n for n in ['utilization.rpt', 'hierarchical.rpt', 'host.dcp']]
                if not all(receipt['outputs'].get(str(p)) == sha(p) for p in required):
                    continue
                result = measured_result(host)
            except (AssertionError, FileNotFoundError, KeyError):
                continue
            return dict(result, reused=True, completed_receipt=str(receipt_path),
                        completed_receipt_sha256=sha(receipt_path), inspected_receipts=inspected)
    return dict(reused=False, inspected_receipts=inspected)


def wait_for_identical_live_map(signature):
    """A compatible live map has precedence over this queued continuation."""
    while True:
        owners = []
        for proc in Path('/proc').iterdir():
            if not proc.name.isdigit():
                continue
            try:
                args = [a.decode() for a in (proc/'cmdline').read_bytes().split(b'\0') if a]
                if not args or 'vivado' not in args[0].lower() or '-source' not in args:
                    continue
                tcl = Path(args[args.index('-source')+1])
                if map_signature(tcl) == signature:
                    row = identity(int(proc.name))
                    if row and row['process_state'] not in ['Z', 'X']:
                        owners.append(dict(row, cgroups=cgroup_paths(proc.name), tcl=str(tcl)))
            except (AssertionError, FileNotFoundError, KeyError, ValueError,
                    PermissionError, ProcessLookupError, UnicodeDecodeError):
                continue
        if not owners:
            return
        m.update('WAITING_IDENTICAL_LIVE_MAP_NO_DUPLICATE', compatible_live_owners=owners)
        time.sleep(30)


def prepare_host(name):
    host = O/name; host.mkdir()
    source = P/name
    # Copy only immutable synthesis collateral. Never write into validation
    # inputs or duplicate simulation build trees.
    paths = sorted(source.glob('*.v'))+[source/'FireSim-generated.sv',
                                            source/'FireSim-generated.synthesis.xdc']
    for path in paths:
        shutil.copyfile(path, host/path.name)
        assert sha(path) == sha(host/path.name)
    m.exact(host/'map.tcl', tcl_text(host))
    signature = map_signature(host/'map.tcl')
    save(O/(name+'-area-inputs.json'), signature)
    return host, signature


def map_or_reuse(host, name, signature):
    wait_for_identical_live_map(signature)
    reuse = compatible_checkpoint(signature)
    save(O/(name+'-checkpoint-reuse-audit.json'), reuse)
    if reuse['reused']:
        return reuse
    save(O/(name+'-area-admission.json'), m.admission())
    assert map_signature(host/'map.tcl') == signature
    m.stage('map-'+name, [TOOL, '-mode', 'batch', '-nojournal', '-log', host/'vivado.log',
                         '-source', host/'map.tcl'],
            [host/n for n in ['utilization.rpt', 'hierarchical.rpt', 'host.dcp']])
    assert map_signature(host/'map.tcl') == signature
    return dict(measured_result(host), reused=False)


def main():
    O.mkdir(exist_ok=True)
    lock = (O/'instance.lock').open('a'); fcntl.flock(lock, fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(), 'Adopt this owner; never duplicate a live pair'
    os.sched_setaffinity(0, m.CPUS)
    resource.setrlimit(resource.RLIMIT_AS, (64*2**30,)*2)
    m.ST.update(schema='ec-complete-production-host-area-pair/1', **identity(),
        started_utc=now(), functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8',
        cpus=sorted(m.CPUS), memory_limit_gib=64, fpga_access=False,
        whole_synthesis=False, production_admission=False, full_system_fit=False,
        r4_screen_positive_required=False,
        scope='Exact complete production AddressStats same-harness Plain/Threaded generated-host OOC pair, 52 public outputs, no proof ports. No whole EC or FIT claim.')
    pins = {str(p): sha(p) for p in [C/'controller.py', C/'install.py', C/'README.md',
                                   Path(m.__file__), Path(parser.__file__)]}
    save(O/'inputs.json', dict(files=pins, validation_owner=str(P), unit=UNIT))
    m.update('QUEUED_FOR_COMPLETE_PRODUCTION_VALIDATION')
    gate = wait_for_owner()
    save(O/'production-admission.json', gate)
    abi = production_abi(); save(O/'production-ABI.json', abi)
    hosts = {name: prepare_host(name) for name in ['Plain', 'Threaded']}
    results = {}
    for name, (host, signature) in hosts.items():
        results[name] = map_or_reuse(host, name, signature)
        save(O/'paired-progress.json', dict(area=results, production_validation=gate,
                                           public_outputs=52, proof_ports_absent=True))
    assert all(sha(p) == h for p, h in pins.items())
    assert prerequisites(read(P/'result.json')) == gate
    saved = {k: results['Plain']['resources'][k]-results['Threaded']['resources'][k]
             for k in results['Plain']['resources']}
    positive = saved['CLB LUTs'] > 0
    m.update('PASS_COMPLETE_PRODUCTION_HOST_PAIRED_AREA_GAIN_NOT_FULL_EC' if positive else
             'REJECTED_COMPLETE_PRODUCTION_HOST_NO_LUT_GAIN',
             area=results, savings=saved, lut_saved=saved['CLB LUTs'],
             ended_utc=now(), public_outputs=52, proof_ports_absent=True,
             material_gain_for_whole_CAD_not_automatically_admitted=True,
             next='Assess measured same-scope resources, compose useful equivalents, complete cycle/host/ABI validation before expensive whole synthesis; preserve all receipts.')
    save(O/'result.json', m.ST)


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        if m.ST:
            m.update('FAILED_WITH_EVIDENCE_VERSIONED_RECOVERY_REQUIRED',
                     error=repr(exc), ended_utc=now())
            save(O/'failure.json', m.ST)
        raise
