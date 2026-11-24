#!/usr/bin/env python3
"""Render the implementation baseline from the taskboard and recorded evidence."""
import json
from pathlib import Path
import subprocess

REPO = Path(__file__).resolve().parents[4]
BASE = REPO / 'AI/Design/SingleCore_RTL_Baseline'
TASKBOARD = REPO / 'AI/Design/05_SingleCore_Taskboard.json'
SCRIPTS = 'AI/Debug/scripts/rollback'


def md(value):
    return str(value).replace('|', '&#124;').replace('\n', ' ')


def link(path):
    return f"[{Path(path).name}](../../../{path})"


def main():
    board = json.loads(TASKBOARD.read_text())
    catalog = json.loads((BASE / 'verification_catalog.json').read_text())
    task_map = {t['id']: t for t in board['tasks']}
    tests = catalog['tests']
    audit_path = BASE / 'Function_Closure_Audit.json'
    audit = json.loads(audit_path.read_text())
    audit_tasks = {row['id']: row for row in audit['tasks']}
    assert set(audit_tasks) == set(task_map), 'functional audit must cover all 69 task IDs'
    for name, test in tests.items():
        assert test['status'] in {'PASS', 'FAIL', 'BLOCKED', 'NOT_RUN'}, name
        assert all(key in task_map for key in test['tasks']), name
        assert all((REPO / p).is_file() for p in test['sources']), name
        assert all((REPO / p).is_file() for p in test['evidence']), name
        if test['status'] in {'PASS', 'FAIL'}:
            assert test['evidence'], name
            assert (REPO / test['run_source_manifest']).is_file(), name

    head = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=REPO, text=True).strip()
    feature_rows = [
        '# 功能实现基准', '',
        f"冻结标识 **{catalog['snapshot']}**。Git 基线 `{head}`。源码哈希和修改前后差异见归档。任务 ID 沿用 05 Taskboard。", '',
        '| ID | 功能与语义 | 实现来源 | 信号、不变量与检查 | 测试 | 代码 | 验证证据状态 | 未结事项 |',
        '|---|---|---|---|---|---|---|---|',
    ]
    manifest = {'schema_version': 2, 'snapshot': catalog['snapshot'], 'git_head': head,
                'hash_manifest': catalog['hash_manifest'], 'tasks': [], 'tests': tests,
                'workflows': audit['workflows'], 'stage_definitions': audit['stage_definitions']}
    system_acceptance = BASE / 'System_Acceptance.json'
    if system_acceptance.is_file():
        manifest['system_acceptance'] = json.loads(system_acceptance.read_text())
    contracts = catalog['contracts']
    for t in board['tasks']:
        key = t['id']
        context = contracts[key]
        selected = [name for name, test in tests.items() if key in test['tasks']]
        evidence = {name: tests[name]['status'] for name in selected}
        fields = dict(id=key, name=t['title'], semantics=context['semantics'],
                      implementation_status=t['status'], sources=t['files'],
                      dependencies=t['depends_on'], signals=context['signals'],
                      invariants=context['invariants'], assertions=context['assertions'],
                      tests=selected, verification=evidence, remaining=t['remaining'],
                      evidence_paths=sorted({p for n in selected for p in tests[n]['evidence']}))
        fields['closure'] = {k: audit_tasks[key][k] for k in (
            'workflows', 'implementation', 'primary_stage', 'issues', 'main_blocker', 'acceptance')}
        manifest['tasks'].append(fields)
        state = ', '.join(f'{n}={v}' for n, v in evidence.items()) or '静态审计'
        invariant_text = ', '.join(context['invariants'])
        feature_rows.append('| ' + ' | '.join(map(md, [
            key, t['title'] + ' ' + context['semantics'],
            ', '.join(map(link, t['files'])), ' / '.join(filter(None, [
                context['signals'], invariant_text, context['assertions']])),
            ', '.join(selected) or 'Static', t['status'], state, t['remaining'] or '—'
        ])) + ' |')

    verification_rows = [
        '# 验证基准', '',
        'PASS 表示该行的运行和判定成功。功能完结状态见实施矩阵。源码哈希对应生成 RTL 的时点，单独重编的夹具附输入哈希。', '',
        '| 测试 | 功能 ID | 源码 | 前置与目标 | 不变量 | 命令 | 预期 | 实际 | 状态及证据 |',
        '|---|---|---|---|---|---|---|---|---|',
    ]
    for name, t in tests.items():
        verification_rows.append('| ' + ' | '.join(map(md, [
            name, ', '.join(t['tasks']), ', '.join(map(link, t['sources'])),
            t['setup'] + '。' + t['purpose'], ', '.join(t['invariants']),
            '`' + t['command'] + '`', t['expected'], t['actual'],
            t['status'] + ' ' + ', '.join(map(link, t['evidence'])) +
            (f" ([源码哈希]({ '../../../' + t['run_source_manifest']}))" if 'run_source_manifest' in t else '')
        ])) + ' |')
    paths = {'Feature_Implementation_Matrix.md': '\n'.join(feature_rows) + '\n',
             'Verification_Matrix.md': '\n'.join(verification_rows) + '\n',
             'implementation_manifest.json': json.dumps(manifest, ensure_ascii=False, indent=2) + '\n'}
    stages = audit['stage_definitions']
    closure_rows = ['# 单核功能闭环盘点', '',
                    '覆盖全部69项原始任务。实现阶段、主要阻塞及验收条件独立于原任务状态记录；状态提升必须有实际验证证据。', '',
                    '依赖：B事务生命周期→C恢复控制→A版本基线与D缓存owner→E整核协同。A与D共享发布顺序，不单独构成整核证明。', '',
                    '| ID | 当前状态 | 工作流 | 实现阶段 | 主要阻塞或审查结论 | 验收条件 |',
                    '|---|---|---|---|---|---|']
    for key, t in task_map.items():
        row = audit_tasks[key]
        stage = stages.get(str(row['primary_stage']), '既有验证保留')
        closure_rows.append('| ' + ' | '.join(map(md, [key, t['status'],
            ','.join(row['workflows']), stage, row['main_blocker'], row['acceptance']])) + ' |')
    paths['Function_Closure_Audit.md'] = '\n'.join(closure_rows) + '\n'
    for path, data in paths.items():
        (BASE / path).write_text(data)


if __name__ == '__main__':
    main()
