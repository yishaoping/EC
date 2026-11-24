#!/usr/bin/env python3
"""Source/document checks only. Never compiles/elaborates/runs hardware."""
import ast
from collections import Counter
import json
from pathlib import Path
import re
import runpy
import subprocess

REPO = Path(__file__).resolve().parents[4]


def scala_delimiters(path):
    source = path.read_text()
    stack = []
    i, line = 0, 1
    pairs = {')': '(', ']': '[', '}': '{'}
    while i < len(source):
        if source.startswith('//', i):
            end = source.find('\n', i)
            i = len(source) if end == -1 else end
        elif source.startswith('/*', i):
            depth = 1
            i += 2
            while i < len(source) and depth:
                if source.startswith('/*', i): depth += 1; i += 2
                elif source.startswith('*/', i): depth -= 1; i += 2
                else: line += source[i] == '\n'; i += 1
            assert depth == 0, f'{path}:{line}: unterminated comment'
        elif source.startswith('"""', i):
            end = source.find('"""', i + 3)
            assert end != -1, f'{path}:{line}: unterminated triple string'
            line += source[i:end + 3].count('\n')
            i = end + 3
        elif source[i] == '"' or (source[i] == "'" and re.match(r"'(?:\\.|[^'\\])'", source[i:])):
            quote = source[i]
            i += 1
            while i < len(source):
                if source[i] == '\\': i += 2
                elif source[i] == quote: i += 1; break
                else: line += source[i] == '\n'; i += 1
            else: raise AssertionError(f'{path}:{line}: unterminated string/char')
        else:
            char = source[i]
            if char in '([{': stack.append((char, line))
            elif char in ')]}':
                assert stack and stack[-1][0] == pairs[char], f'{path}:{line}: unmatched {char}'
                stack.pop()
            line += char == '\n'
            i += 1
    assert not stack, f'{path}: unclosed delimiters {stack[-3:]}'


def main():
    data = json.loads((REPO / 'AI/Design/05_SingleCore_Taskboard.json').read_text())
    tasks = {t['id']: t for t in data['tasks']}
    expected = {f'P{phase}-{i:02}' for phase, count in enumerate((7, 10, 11, 15, 13, 13))
                for i in range(1, count + 1)}
    assert len(data['tasks']) == len(tasks) == 69 and set(tasks) == expected
    states = {'TODO', 'IN_PROGRESS', 'CODE_READY', 'NEEDS_FIX', 'VERIFIED', 'BLOCKED', 'DEFERRED'}
    visited, active = set(), set()

    def visit(key):
        assert key in tasks and key not in active, f'unknown/cyclic dependency: {key}'
        if key in visited: return
        active.add(key)
        for dep in tasks[key]['depends_on']: visit(dep)
        active.remove(key); visited.add(key)

    for key, task in tasks.items():
        assert task['status'] in states
        assert task['verification'] in {'STATIC', 'PASS', 'PARTIAL', 'FAIL', 'BLOCKED', 'NOT_RUN'}
        if task['status'] == 'VERIFIED':
            assert task['verification'] == 'PASS' and not task['remaining']
        assert task['files'] and all((REPO / p).is_file() for p in task['files'])
        if task['status'] == 'BLOCKED': assert task['blockers']
        visit(key)
    audit = (REPO / 'AI/Design/01_PALIMPSEST_Feature_Matrix.md').read_text()
    original = set(re.findall(r'\|\s*([A-E]\d+)\s*\|', audit))
    assert len(data['features']) == len(original) == 49
    assert {f['id'] for f in data['features']} == original
    for feature in data['features']:
        assert feature['scope'] in {'InScope', 'Deferred', 'N/A'}
        if feature['scope'] == 'InScope':
            assert feature['tasks'] and all(t in tasks for t in feature['tasks'])
        linked = [tasks[t]['status'] for t in feature['tasks']]
        expected_status = ('DEFERRED' if feature['scope'] == 'Deferred' else
                           'BLOCKED' if 'BLOCKED' in linked else
                           'VERIFIED' if linked and all(s == 'VERIFIED' for s in linked) else
                           'CODE_READY' if linked and all(s in {'CODE_READY', 'VERIFIED'} for s in linked) else 'IN_PROGRESS')
        assert feature['implementation_status'] == expected_status, f"stale feature status: {feature['id']}"
    assert {f['id'] for f in data['features'] if f['scope'] == 'Deferred'} == {'C5', 'D17'}
    rendered = runpy.run_path(str(Path(__file__).with_name('render_taskboard.py')))['render']()
    assert rendered == (REPO / 'AI/Design/05_SingleCore_Taskboard.md').read_text(), 'taskboard MD is stale'
    counts = Counter(t['status'] for t in tasks.values())
    summary = (REPO / 'AI/Design/09_SingleCore_Implementation_Summary.md').read_text()
    for status in ('CODE_READY', 'IN_PROGRESS', 'BLOCKED', 'VERIFIED'):
        assert f'{status}={counts[status]}' in summary, f'summary count stale: {status}'
    assert not set(data['blocker_catalog']) & set(data.get('resolved_source_blockers', {}))
    for task in tasks.values():
        assert all(b in data['blocker_catalog'] for b in task['blocker_ids']), f"stale blocker: {task['id']}"
    changed = subprocess.check_output(['git', 'diff', '--name-only', '-z'], cwd=REPO).split(b'\0')
    new = subprocess.check_output(['git', 'ls-files', '--others', '--exclude-standard', '-z', '--',
                                  'chipyard', 'AI/Debug/scripts/rollback'], cwd=REPO).split(b'\0')
    scala = [REPO / raw.decode() for raw in sorted(set(changed + new)) if raw.endswith(b'.scala')]
    for path in scala: scala_delimiters(path)
    # C/C++ fixtures use the same comment/string/delimiter lexical grammar.
    # This deliberately performs no compiler/preprocessor invocation.
    cpp = sorted(set(list(Path(__file__).parent.glob('*.cpp')) + list(Path(__file__).parent.glob('*.c')) +
                 [REPO / raw.decode() for raw in sorted(set(changed + new))
                  if raw.endswith((b'.c', b'.cc', b'.cpp')) and (REPO / raw.decode()).is_file()]))
    for path in cpp: scala_delimiters(path)
    for path in Path(__file__).parent.glob('*.py'): ast.parse(path.read_text(), filename=str(path))
    for path in Path(__file__).parent.glob('*.sh'):
        subprocess.run(['bash', '-n', str(path)], check=True)
    subprocess.run(['git', 'diff', '--check'], cwd=REPO, check=True)
    print(f'STATIC_SOURCE_CHECK=PASS tasks=69 features=49 scala_delimiters={len(scala)} c_cpp_delimiters={len(cpp)}')
    manifest = json.loads((REPO / 'AI/Design/SingleCore_RTL_Baseline/implementation_manifest.json').read_text())
    audit = json.loads((REPO / 'AI/Design/SingleCore_RTL_Baseline/Function_Closure_Audit.json').read_text())
    audited = {row['id']: row for row in audit['tasks']}
    assert set(audited) == expected and len(audit['tasks']) == 69
    assert {t['id'] for t in manifest['tasks']} == expected
    for row in manifest['tasks']:
        task = tasks[row['id']]
        assert row['implementation_status'] == task['status'] and row['remaining'] == task['remaining']
        assert row['closure']['main_blocker'] == audited[row['id']]['main_blocker']
        assert row['closure']['workflows'] and row['closure']['acceptance']
        if task['status'] == 'VERIFIED':
            assert 'PASS' in row['verification'].values() and row['evidence_paths']
            assert audited[row['id']]['primary_stage'] == 0
    print('Scala typing/Chisel/CDC/TileLink/functionality: outside this static check')


if __name__ == '__main__':
    main()
