#!/usr/bin/env python3
"""Read-only B v5 passive bridge/software reuse verification, no target execution."""
import argparse
import hashlib
import json
from pathlib import Path
import re
from build_minimal import inventory, sha


def require(value, message):
    if not value:
        raise ValueError(message)


def checked_json(path, expected=None):
    if expected:
        require(sha(path) == expected, 'changed receipt '+str(path))
    return json.loads(path.read_text())


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--hardware-evidence', type=Path, required=True)
    p.add_argument('--software-reuse', type=Path, required=True)
    p.add_argument('--out', type=Path, required=True)
    a = p.parse_args()
    evidence = checked_json(a.hardware_evidence)
    summaries = evidence['builds']['B']
    require(set(summaries) == {'parameters', 'elaborate', 'goldengate', 'driver'}, 'need all four actual build phases')
    rows = {}
    for phase, summary in summaries.items():
        result = checked_json(Path(summary['result']), summary['result_sha256'])
        require(result['returncode'] == 0 and result['phase'] == phase and
                result['config'] == 'DacBaseline' and result['integration'] == 'opt4-roi-v5' and
                result['runtime_validation'] == 'NOT_RUN', 'wrong compile receipt '+phase)
        require(result['outputs'] == summary['outputs'] and result['source_id'] == summary['source_id'], 'summary mismatch')
        for f, expected in result['outputs'].items():
            require(sha(Path(f)) == expected, 'artifact changed '+f)
        require(sha(Path(summary['result']).parent/'build-script.py') == result['build_script_sha256'], 'script snapshot changed')
        rows[phase] = result
    require(len({r['source_id'] for r in rows.values()}) == 1 and
            len({r['source_tree'] for r in rows.values()}) == 1, 'source identity mismatch')
    tree = Path(rows['elaborate']['source_tree'])
    current = hashlib.sha256(json.dumps(inventory(tree), sort_keys=True).encode()).hexdigest()
    require(current == rows['elaborate']['source_id'], 'current sources changed')
    for child, parent in [('goldengate', 'elaborate'), ('driver', 'goldengate')]:
        require(Path(rows[child]['input_result']).resolve() == Path(summaries[parent]['result']).resolve() and
                rows[child]['input_result_sha256'] == summaries[parent]['result_sha256'], 'hardware parent mismatch')
    reuse = checked_json(a.software_reuse)
    require(Path(reuse['new_hardware_receipt']).resolve() == Path(summaries['elaborate']['result']).resolve() and
            reuse['new_hardware_receipt_sha256'] == summaries['elaborate']['result_sha256'], 'software reuse belongs to another hardware build')
    old_hardware = checked_json(Path(reuse['old_hardware_receipt']), reuse['old_hardware_receipt_sha256'])
    old_candidate = checked_json(Path(reuse['old_candidate_content_evidence']), reuse['old_candidate_content_evidence_sha256'])
    require(old_candidate['compile_and_content_checks_passed'] and old_candidate['runtime_validation'] == 'NOT_RUN', 'not a checked software candidate')
    for name, item in old_candidate['receipts'].items():
        receipt = checked_json(Path(item['path']), item['sha256'])
        require(receipt['returncode'] == 0, 'old software receipt failed')
        for f, expected in receipt.get('outputs', {}).items():
            require(sha(Path(f)) == expected, 'reused artifact changed '+f)
    dts = Path(rows['elaborate']['output_dir'])/'firesim.firesim.FireSim.dts'
    old_dts = Path(old_hardware['output_dir'])/dts.name
    require(dts.read_bytes() == old_dts.read_bytes() and sha(dts) == reuse['dts_sha256'], 'software-visible device tree differs')
    g = Path(rows['goldengate']['output_dir'])
    header = (g/'FireSim-generated.const.h').read_text()
    require('new ec_dac_roi_t(' in header and 'bridges/ec_dac_roi.h' in header, 'custom driver not registered in generated header')
    sv = (g/'FireSim-generated.sv').read_text()
    require(re.search(r'\bmodule DacRoiBridgeModule\b', sv), 'host FPGA bridge absent')
    require(re.search(r'\bmodule DacRoiController\b', sv), 'source observer absent')
    fir = (Path(rows['elaborate']['output_dir'])/'firesim.firesim.FireSim.fir').read_text()
    require(not re.search(r'inst \S+ of (RocketTile|Rocket|GHM|GHE|GuardianCouncil)\b', fir), 'B contains checker hardware')
    io = (tree/'sims/firesim/sim/firesim-lib/src/main/scala/bridges/DacRoiBridge.scala').read_text().split('class DacRoiBridgeIO', 1)[1].split('class DacRoiBridge extends', 1)[0]
    require('Output(' not in io and 'Input(Clock())' in io, 'bridge target interface is not input-only')
    report = {'configuration': 'B', 'integration': 'opt4-roi-v5', 'compile_and_content_checks_passed': True,
              'hardware_evidence': str(a.hardware_evidence.resolve()), 'hardware_evidence_sha256': sha(a.hardware_evidence),
              'software_reuse': str(a.software_reuse.resolve()), 'software_reuse_sha256': sha(a.software_reuse),
              'source_id': current, 'raw_passive_bridge_compiled_and_registered': True,
              'source_tick_controller_compiled': True, 'software_payload_unchanged_and_hashed': True,
              'target_execution': 'NOT_RUN', 'driver_executed': False, 'runtime_validation': 'NOT_RUN',
              'formal_sample_pipeline_complete': False, 'certified_bitstream': False,
              'C4_linux_checker_ready': False, 'real_runtime_passed_samples': 0,
              'warning': 'B raw ROI transport only. No runtime timestamps, persistence, outputs, formal completion markers, C4 latency or experiment results have been validated.'}
    a.out.parent.mkdir(parents=True, exist_ok=True)
    with a.out.open('x') as f:
        json.dump(report, f, indent=2); f.write('\n')
    print(a.out)


if __name__ == '__main__':
    main()
