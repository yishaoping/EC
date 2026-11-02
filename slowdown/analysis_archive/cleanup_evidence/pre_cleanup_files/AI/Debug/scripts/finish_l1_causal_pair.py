#!/usr/bin/env python3
"""Follow existing launchers and validate their results; never launches hardware jobs."""
import importlib.util
import json
from pathlib import Path
import subprocess
import time

ROOT = Path(__file__).resolve().parents[3]
SCRIPTS = Path(__file__).resolve().parent
report = Path((ROOT / 'AI/TMP/.l1_causal_active').read_text().strip())
revision = Path((ROOT / 'AI/TMP/.l1_causal_revision').read_text().strip())
spec = importlib.util.spec_from_file_location('pair_analysis', SCRIPTS / 'analyze_l1_causal_pair.py')
pair = importlib.util.module_from_spec(spec)
spec.loader.exec_module(pair)
validated = set()

while True:
    subprocess.run(['python3', '-B', str(SCRIPTS / 'l1_causal_status.py'),
                    '--capture-processes', '--compact'], check=True)
    for name in ['A', 'B']:
        manifest = next((revision / 'arms' / name / 'runs').glob('*/run_manifest.json'))
        obj = json.loads(manifest.read_text())
        if name in validated:
            continue
        if obj.get('simulation') == 'COMPLETED' and (manifest.parent / 'analysis/summary.json').exists():
            result = pair.arm(revision, name)
            pair.dump(report / f'arm_{name}_prevalidation_r2.json', result)
            print(json.dumps({'completed_arm': name, 'valid': result['valid'],
                              'roi_cycles': result['roi_cycles'], 'gates': result['gates']}), flush=True)
            if not result['valid']:
                raise SystemExit(f'Arm {name} validation failed; no performance interpretation')
            validated.add(name)
        elif obj.get('result') in ['FAILED', 'FAIL']:
            raise SystemExit(f'Arm {name} launcher failed; inspect preserved manifest')
    if len(validated) == 2:
        subprocess.run(['python3', '-B', str(SCRIPTS / 'collect_l1_causal_provenance.py'), '--execution'], check=True)
        subprocess.run(['python3', '-B', str(SCRIPTS / 'analyze_l1_causal_pair.py'), str(report),
                        '--revision', str(revision)], check=True)
        subprocess.run(['python3', '-B', str(SCRIPTS / 'review_l1_causal_results.py'), str(report)], check=True)
        print('BOTH_ARMS_ANALYZED; quantitative manual review still required.', flush=True)
        break
    time.sleep(45)
