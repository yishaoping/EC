#!/usr/bin/python3
"""Run the immutable candidate's validation prefix in independent output paths.

This proof-only auxiliary cannot run Vivado. The original module request stays
queued and untouched. Its complete DCache and whole-DUT admission remain false.
"""
import ast
import hashlib
import json
from pathlib import Path

HERE = Path(__file__).resolve().parent
CONFIG = json.loads((HERE / 'config.json').read_text())
ORIGINAL = Path(CONFIG['controller'])
source = ORIGINAL.read_text()
assert hashlib.sha256(ORIGINAL.read_bytes()).hexdigest() == CONFIG['controller_sha256']
tree = ast.parse(source, filename=str(ORIGINAL))
substitutions = CONFIG['ast_string_substitutions']
counts = {key: 0 for key in substitutions}
for node in ast.walk(tree):
    if isinstance(node, ast.Constant) and isinstance(node.value, str) and node.value in substitutions:
        counts[node.value] += 1
        node.value = substitutions[node.value]
assert counts == CONFIG['expected_substitution_counts'], counts
main = next(n for n in tree.body if isinstance(n, ast.FunctionDef) and n.name == 'main')
cut = next(i for i, n in enumerate(main.body)
           if isinstance(n, ast.FunctionDef) and n.name == 'mapping')
assert isinstance(main.body[cut - 1], ast.Expr)
last = main.body[cut - 1].value
assert isinstance(last, ast.Call) and isinstance(last.func, ast.Name)
assert last.func.id == 'run' and isinstance(last.args[0], ast.Constant)
assert last.args[0].value == 'typecheck-dcache'
# Keep exactly the already bound source contract, helper compilation, generated
# SAT/mutation, actual memory topology, regression and DCache source typecheck.
main.body = main.body[:cut] + ast.parse('''
update(status='PASS_GENERATED_STORAGE_PROOF_TOPOLOGY_8192_CYCLES_AND_DCACHE_TYPECHECK_NOT_ADMITTED',
       child={}, ended_utc=now(), whole_dut_admission=False,
       complete_dcache_comparison='PENDING_NOT_PROVED',
       synthesis_executed=False)
save(O/'result.json', st)
''').body
ast.fix_missing_locations(tree)
assert not any(isinstance(n, ast.Constant) and isinstance(n.value, str)
               and '/tools/Xilinx/' in n.value for n in ast.walk(main))
ns = {'__file__': str(ORIGINAL), '__name__': 'immutable_dcache_validation_prefix'}
exec(compile(tree, str(ORIGINAL), 'exec'), ns)
ns['O'] = Path(CONFIG['output_dir'])
ns['S'] = Path(CONFIG['state_file'])
base_read = ns['read']
def recovery_read(path):
    value = base_read(path)
    if Path(path).resolve() == ORIGINAL.parent / 'config.json':
        jar = Path(CONFIG['firechip_jar'])
        assert hashlib.sha256(jar.read_bytes()).hexdigest() == CONFIG['firechip_sha256']
        value = dict(value, classpath=[str(jar), *value['classpath']])
    return value
ns['read'] = recovery_read
try:
    ns['main']()
except Exception as exc:
    st = ns['read'](ns['S'])
    if st.get('pid') == ns['os'].getpid():
        st.update(status='FAILED_WITH_EVIDENCE', error=repr(exc), ended_utc=ns['now']())
        ns['save'](ns['S'], st)
    raise
