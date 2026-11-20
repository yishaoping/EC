#!/usr/bin/env python3
"""Read completed packed-r1 artifacts only; never launch, signal, or admit work."""
import hashlib
import importlib.util
import json
from pathlib import Path
import re

ROOT = Path('/data1/gzh/EC')
W = ROOT / 'firesim/final-opt4-20261106'
D = ROOT / 'Experiment/firesim-final-opt4-20261106'
C = W / 'candidates/address-packed-full-module-r1-20261112'
O = D / 'build-logs/Opt4-address-packed-full-module-r1-20261112'
INPUT_SHA = '044a7547393c12be496875f70e1357a756b412ee3cd720026dd3c6858ec3affa'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
COMPLETE = 'COMPLETE_PRIVATE_MODULE_PARITY_AND_PAIRED_AREA_NOT_WHOLE_FIT'
LABELS = ('Reference', 'Candidate')


def read(path):
    return json.loads(Path(path).read_text())


def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as f:
        for block in iter(lambda: f.read(2**20), b''):
            h.update(block)
    return h.hexdigest()


def require(ok, message):
    if not ok:
        raise ValueError(message)


def receipt(name, outputs):
    r = read(O / (name + '-receipt.json'))
    require(r['accepted'] and r['returncode'] == 0 and not r['negative'], name + ': unsuccessful stage')
    require(not r['missing_outputs'], name + ': missing outputs')
    require(Path(r['log']) == O / (name + '.log'), name + ': log path')
    require(sha(r['log']) == r['log_sha256'], name + ': log hash')
    for p in outputs:
        require(r['outputs'].get(str(p)) == sha(p), name + ': output hash ' + str(p))
    return r


def source_binding():
    require(sha(C / 'inputs.json') == INPUT_SHA, 'r1 input manifest changed')
    pins = read(C / 'inputs.json')
    # Reuse existing finite parity; no compile, simulation or source regeneration.
    acceptance = read(D / 'status-audits/round142-packed-singleton-contract-20261112/finite-parity-acceptance.json')
    require(acceptance['status'] == 'PASS_EXISTING_COMPLETE_MODULE_FINITE_PARITY_AND_ACTUAL_REGISTER_MUTATION_REJECTION',
            'prior finite parity acceptance')
    require(acceptance['inputs_sha256'] == INPUT_SHA and acceptance['cycles'] == 6144
            and acceptance['monitor_outputs'] == 5684 and acceptance['mutation']['accepted_rejection'],
            'prior finite parity binding')
    for name in ('verified-parity.json', 'parity-positive-receipt.json',
                 'parity-invalid-register-mutation-receipt.json'):
        p = O / name
        require(sha(p) == acceptance['artifacts_sha256'][str(p)], 'finite parity receipt changed: ' + name)
    for name in ('controller.py', 'Emit.scala', 'ReferenceModule.scala', 'CandidateModule.scala',
                 'ReferenceHelper.scala', 'CandidateHelper.scala', 'AddressBucketUpdate.scala'):
        p = C / name
        require(sha(p) == pins['files'][str(p)], 'pinned source changed: ' + name)
    ports = []
    for label in LABELS:
        rtl = O / (label + '-Module/FPGATop.v')
        receipt('elaborate-' + label + '-Module', [rtl])
        header = rtl.read_text().split(');', 1)[0]
        require('io_debug' not in header, 'proof ports in area RTL')
        ports.append(re.findall(r'\b(input|output)\s*(\[\d+:\d+\])?\s+(\w+)', header))
    require(ports[0] == ports[1], 'area RTL interfaces differ')
    require(sum(p[0] == 'output' for p in ports[0]) == 52, 'public output count')
    return pins


def validate_complete(r, pins):
    require(r['status'] == COMPLETE, 'paired map is incomplete')
    require(r['inputs_sha256'] == INPUT_SHA and r['functional_baseline'] == BASE, 'result source identity')
    require(r['finite_parity_pass'] and r['monitor_outputs'] == 5684, 'finite parity gate')
    require(not r['production_admission'] and not r['fpga_access'] and not r['full_host_synthesis'], 'scope widened')
    require(r['proof_only_ports_excluded_from_area'] and r['full_host_fit_unknown'], 'area scope')
    parser_path = W / 'candidates/mcrams-full-host-capacity-r1-20261112/resource_parser.py'
    require(sha(parser_path) == pins['files'][str(parser_path)], 'resource parser changed')
    spec = importlib.util.spec_from_file_location('packed_r144_resource_parser', parser_path)
    parser = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(parser)
    totals = {}
    artifacts = {str(O / 'result.json'): sha(O / 'result.json')}
    directives = []
    for label in LABELS:
        area = O / (label + '-area')
        rtl = O / (label + '-Module/FPGATop.v')
        util, hier, dcp = [area / n for n in ('utilization.rpt', 'hierarchical.rpt', 'module.dcp')]
        stage = receipt('map-' + label, [util, hier, dcp])
        tcl = area / 'map.tcl'
        expected = ('set_param general.maxThreads 2\n' + f'read_verilog {{{rtl}}}\n' +
                    'synth_design -mode out_of_context -top FPGATop -part xcu280-fsvh2892-2L-e\n' +
                    'if {[llength [get_cells -hier -quiet -filter {IS_BLACKBOX == 1}]]} {error "blackbox"}\n' +
                    f'report_utilization -file {{{util}}}\nreport_utilization -hierarchical -file {{{hier}}}\n' +
                    f'write_checkpoint -force {{{dcp}}}\nexit 0\n')
        require(tcl.read_text() == expected, label + ': unexpected map directives')
        require(stage['argv'] == ['/tools/Xilinx/Vivado/2021.1/bin/vivado', '-mode', 'batch', '-nojournal',
                                  '-log', str(area / 'vivado.log'), '-source', str(tcl)], label + ': map argv')
        directives.append(expected.replace(label, 'SIDE'))
        total = parser.parse_total(util.read_text())
        parser.parse_hier(hier.read_text(), total)
        parser.crosschecks(util.read_text(), total)
        m = r['maps'][label]
        require(m['scope'] == 'Complete target module OOC, not GoldenGate host', label + ': wrong scope')
        require(m['resources'] == total, label + ': saved totals disagree')
        for p, key in ((rtl, 'rtl_sha256'), (util, 'utilization_sha256'),
                       (hier, 'hierarchical_sha256'), (dcp, 'checkpoint_sha256')):
            digest = sha(p)
            require(m[key] == digest, label + ': result hash mismatch ' + key)
            artifacts[str(p)] = digest
        artifacts[str(tcl)] = sha(tcl)
        artifacts[str(O / ('map-' + label + '-receipt.json'))] = sha(O / ('map-' + label + '-receipt.json'))
        totals[label] = {k: v['used'] for k, v in total.items()}
    require(directives[0] == directives[1], 'paired directives differ')
    saving = {k: totals['Reference'][k] - totals['Candidate'][k] for k in totals['Reference']}
    require(saving['CLB LUTs'] == r['complete_module_lut_saving'], 'saved LUT saving disagrees')
    return dict(status='PASS_COMPLETED_PAIRED_MODULE_ARTIFACTS', resources=totals,
                reference_minus_candidate=saving, artifacts_sha256=artifacts,
                positive_module_lut_gain=saving['CLB LUTs'] > 0,
                gain_scope='One complete target module OOC; no extrapolation to host or FPGA',
                production_admission=False, full_ec_fit=False,
                next='Assess measured gain and hierarchy; useful gain requires composition/GoldenGate/ABI/target-cycle gates before whole-host capacity.')


def main():
    pins = source_binding()
    result = O / 'result.json'
    if not result.exists():
        print(json.dumps(dict(status='PENDING_EXISTING_R1_PAIR', source_binding_pass=True,
                              finite_parity_reused=True, actual_area_gain=None,
                              production_admission=False, launched_jobs=[]), sort_keys=True))
        return
    print(json.dumps(validate_complete(read(result), pins), sort_keys=True))


if __name__ == '__main__':
    main()
