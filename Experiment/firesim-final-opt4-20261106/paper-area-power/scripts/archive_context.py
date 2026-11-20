#!/usr/bin/env python3
"""Save baseline context separately from R6, plus exact revision evidence."""
from pathlib import Path
from datetime import datetime, timezone
import hashlib
import json
import shutil
import subprocess

OUT = Path(__file__).resolve().parents[1]
EXP = OUT.parent
NATIVE = Path('/data1/gzh/EC/firesim/dac2026/work/opt4-roi-v5/builds/B-bitstream-20261102T095746.955739Z')
REPO = Path('/data1/gzh/EC/firesim/final-opt4-20261106/Opt4-performance-only-support-r5-20261113')
COMMIT = '6fada307bb77be90b39720d3f95404fece0e431b'

def main():
    files = []
    def save(src, rel):
        dst = OUT / rel
        dst.parent.mkdir(parents=True, exist_ok=True)
        if not dst.exists():
            shutil.copy2(src, dst)
        sha = hashlib.sha256(dst.read_bytes()).hexdigest()
        assert sha == hashlib.sha256(src.read_bytes()).hexdigest()
        files.append({'source': str(src), 'saved': rel, 'sha256': sha})
    for p in (NATIVE / 'vivado_proj/firesim.runs/impl_1').iterdir():
        if p.suffix == '.rpt':
            save(p, 'raw/native-B/impl_1/' + p.name)
    for name in ['synth_1/design_1_wrapper_utilization_synth.rpt', 'design_1_firesim_wrapper_0_0_synth_1/design_1_firesim_wrapper_0_0_utilization_synth.rpt']:
        save(NATIVE / 'vivado_proj/firesim.runs' / name, 'raw/native-B/' + name)
    save(NATIVE.parent / 'B-parameters-20261102T092950.874012Z/parameters.json', 'raw/native-B/parameters.json')
    save(EXP / 'build-logs/Opt4-performance-only-fpga-r2-20261113/parameters.json', 'raw/profile/parameters.json')
    save(EXP / 'build-logs/Opt4-performance-only-fpga-r2-20261113/frozen-parameters-receipt.json', 'raw/profile/frozen-parameters-receipt.json')
    save(REPO / 'candidates/performance-only-support-r5-20261113/source-binding.json', 'raw/profile/r5-source-binding.json')
    for name in ['PROFILE.md', 'pruning-edits.json']:
        rel = 'candidates/performance-only-fpga-r2-20261113/' + name
        data = subprocess.check_output(['git', '-C', str(REPO), 'show', COMMIT + ':' + rel])
        dst = OUT / 'raw/profile' / ('6fada307-' + name)
        dst.write_bytes(data)
        files.append({'source': str(REPO) + '@' + COMMIT + ':' + rel, 'saved': str(dst.relative_to(OUT)), 'sha256': hashlib.sha256(data).hexdigest()})
    diff = subprocess.check_output(['git', '-C', str(REPO), 'diff', COMMIT, 'HEAD', '--', 'chipyard/generators'], text=True)
    status = subprocess.check_output(['git', '-C', str(REPO), 'status', '--short', '--', 'chipyard/generators'], text=True)
    generated = EXP / 'build-logs/Opt4-performance-only-support-r6-20261113/project/builds/cad-6fada307/design/FireSim-generated.sv'
    h = hashlib.sha256()
    with generated.open('rb') as f:
        for chunk in iter(lambda: f.read(8 * 1024 * 1024), b''):
            h.update(chunk)
    binding = json.loads((OUT / 'raw/profile/r5-source-binding.json').read_text())
    checked = []
    for s, expected in binding['files'].items():
        if '/chipyard/generators/' in s and s.endswith('.scala'):
            p = Path(s)
            actual = hashlib.sha256(p.read_bytes()).hexdigest() if p.exists() else None
            checked.append({'path': s, 'expected': expected, 'actual': actual, 'matches': actual == expected})
    verification = {'hardware_commit': COMMIT, 'source_repo': str(REPO), 'hardware_diff_6fada307_to_checkout_HEAD': diff, 'hardware_worktree_status': status, 'r6_generated_rtl_sha256': h.hexdigest(), 'r6_generated_rtl_matches_cad_receipt': h.hexdigest() == 'd2cfb70488d2826cbd997c47954b2be0fc17a5342a430235481b07539a32cf94', 'bound_scala_sources': checked, 'all_bound_scala_sources_match': all(x['matches'] for x in checked)}
    (OUT / 'evidence/revision_verification.json').write_text(json.dumps(verification, indent=2) + '\n')
    inventories = []
    for root in [EXP, Path('/data1/gzh/EC/firesim/dac2026/work')]:
        proc = subprocess.run(['rg', '--files', '--hidden', '--no-ignore', str(root), '-g', '*.rpt', '-g', '!**/.git/**', '-g', '!**/conda-env/**', '-g', '!**/envs/**', '-g', '!**/target/**', '-g', '!**/paper-area-power/**'], capture_output=True, text=True, check=True)
        inventories.append({'root': str(root), 'reports': proc.stdout.splitlines()})
    (OUT / 'evidence/baseline_report_search.json').write_text(json.dumps(inventories, indent=2) + '\n')
    (OUT / 'evidence/context_manifest.json').write_text(json.dumps({'captured_utc': datetime.now(timezone.utc).isoformat(), 'files': files}, indent=2) + '\n')
    print(json.dumps({'files': len(files), 'bound_scala_sources_checked': len(checked), 'source_binding_matches': verification['all_bound_scala_sources_match'], 'hardware_diff_empty': not diff and not status}))

if __name__ == '__main__':
    main()
