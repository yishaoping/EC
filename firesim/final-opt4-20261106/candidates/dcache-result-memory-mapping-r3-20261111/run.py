#!/usr/bin/python3
"""Versioned actual-geometry module recovery; preserve the original request.

Reuse exact passed proof/typecheck files through read-only symlinks. Only the
matched storage maps are new work. No complete-DCache or whole-DUT admission.
"""
import ast
import hashlib
import json
import os
from pathlib import Path

HERE = Path(__file__).resolve().parent
cfg = json.loads((HERE / 'config.json').read_text())
original = Path(cfg['controller'])
assert hashlib.sha256(original.read_bytes()).hexdigest() == cfg['controller_sha256']
proof = Path(cfg['proof_output'])
result = json.loads((proof / 'result.json').read_text())
assert result['status'] == 'PASS_GENERATED_STORAGE_PROOF_TOPOLOGY_8192_CYCLES_AND_DCACHE_TYPECHECK_NOT_ADMITTED'
assert result['hardware_commit'] == cfg['hardware_commit']
assert result['source_id'] == cfg['source_id']
assert result['local_formal'] == 'PASS_ARBITRARY64_WORD_INDEX_UPDATE_NO_RESET_MASKING'
assert result['actual_size_boundary'].startswith('PASS_8192_CYCLES_512X64_')
assert not result['whole_dut_admission'] and not result['synthesis_executed']
for stage in result['stages'].values():
    assert stage['accepted_result'] and not stage['missing_outputs']
    for p, digest in stage['outputs'].items():
        assert hashlib.sha256(Path(p).read_bytes()).hexdigest() == digest
out = Path(cfg['output_dir'])
out.mkdir(exist_ok=True)
# These paths are only consumed by successful receipt-reuse branches. Every
# failed or incomplete receipt is rejected before any stage can write there.
for name in ['classes', 'proof', 'candidate', 'reference', 'pair', 'boundary', 'dcache-typecheck']:
    path = out / name
    if path.is_symlink():
        assert path.resolve() == (proof / name).resolve()
    else:
        assert not path.exists()
        path.symlink_to(proof / name, target_is_directory=True)
for name in ['compile-result.json', 'typecheck-dcache-result.json']:
    path = out / name
    if path.is_symlink():
        assert path.resolve() == (proof / name).resolve()
    else:
        assert not path.exists()
        path.symlink_to(proof / name)
tree = ast.parse(original.read_text(), filename=str(original))
counts = {key: 0 for key in cfg['ast_string_substitutions']}
for node in ast.walk(tree):
    if isinstance(node, ast.Constant) and isinstance(node.value, str) and node.value in counts:
        counts[node.value] += 1
        node.value = cfg['ast_string_substitutions'][node.value]
assert counts == cfg['expected_substitution_counts']
ns = {'__file__': str(original), '__name__': 'immutable_dcache_module_recovery'}
exec(compile(tree, str(original), 'exec'), ns)
ns['O'], ns['S'] = out, Path(cfg['state_file'])
base_read = ns['read']
def recovery_read(path):
    value = base_read(path)
    if Path(path).resolve() == original.parent / 'config.json':
        jar = Path(cfg['firechip_jar'])
        assert hashlib.sha256(jar.read_bytes()).hexdigest() == cfg['firechip_sha256']
        value = dict(value, classpath=[str(jar), *value['classpath']])
    return value
ns['read'] = recovery_read
try:
    ns['main']()
except Exception as exc:
    state = ns['read'](ns['S'])
    if state.get('pid') == os.getpid():
        state.update(status='FAILED_WITH_EVIDENCE', error=repr(exc), ended_utc=ns['now']())
        ns['save'](ns['S'], state)
    raise
