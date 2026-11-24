#!/usr/bin/env python3
"""Render human taskboard from the authoritative JSON. Runs no hardware tools."""
from collections import Counter
import json
from pathlib import Path

REPO = Path(__file__).resolve().parents[4]
DESIGN = REPO / 'AI/Design'


def render():
    data = json.loads((DESIGN / '05_SingleCore_Taskboard.json').read_text())
    counts = Counter(t['status'] for t in data['tasks'])
    lines = [
        '# 单主核 Rollback 任务板', '',
        '基线 HEAD：`' + data['baseline']['head'] + '`；分支：`' + data['baseline']['branch'] + '`。', '',
        ('**功能任务已完成。**' if counts['VERIFIED'] == len(data['tasks']) else '**功能任务尚未全部验收。**') +
        ' JSON 为当前状态源；每项任务均需对应验收证据。物理综合、布局布线和时序签核独立记录。', '',
        '任务数：69；' + '，'.join(f'{s}={counts[s]}' for s in
            ('CODE_READY', 'IN_PROGRESS', 'BLOCKED', 'TODO', 'NEEDS_FIX', 'VERIFIED', 'DEFERRED')) + '。', '',
        '原始功能 49 项：InScope=47，Deferred=2（C5、D17），N/A=0。多主核项不计入单主核完成率。', '',
        '执行状态见 [验证基准](SingleCore_RTL_Baseline/Verification_Matrix.md)。', '',
        '## 当前阻塞', '',
    ]
    lines += [f'- **{key}**：{value}' for key, value in data['blocker_catalog'].items()]
    lines += ['', '## 已解除的源码阻塞（未经运行验证）', '']
    lines += [f"- **{key}**：{value['resolution']}" for key, value in data.get('resolved_source_blockers', {}).items()]
    lines += ['', '## 实施任务', '',
              '| ID | 任务 | 状态 | 验证 | 直接依赖 | 已写/待完成 |', '|---|---|---|---|---|---|']
    for t in data['tasks']:
        note = t.get('remaining') or '对应实现、用例及证据见实现矩阵。'
        lines.append(f"| {t['id']} | {t['title']} | {t['status']} | {t['verification']} | {', '.join(t['depends_on']) or '—'} | {note.replace('|', '/')} |")
    by_id = {t['id']: t for t in data['tasks']}
    lines += ['', '## 原始 49 项功能完整覆盖', '',
              '| ID | 功能 | 原审计状态 | 单核范围 | 实施任务 | 当前实施状态 |', '|---|---|---|---|---|---|']
    for f in data['features']:
        linked = [by_id[t]['status'] for t in f['tasks']]
        status = ('DEFERRED' if f['scope'] == 'Deferred' else 'BLOCKED' if 'BLOCKED' in linked
                  else 'VERIFIED' if linked and all(s == 'VERIFIED' for s in linked) else 'CODE_READY' if linked and all(s in {'CODE_READY', 'VERIFIED'} for s in linked) else 'IN_PROGRESS')
        lines.append(f"| {f['id']} | {f['name']} | {f['audit_status']} | {f['scope']} | {', '.join(f['tasks']) or '—'} | {status} |")
    lines += ['', '剩余整核和并发用例的实际覆盖见 [验证基准](SingleCore_RTL_Baseline/Verification_Matrix.md)。持续 I/O 重放不匹配按已冻结的假设处理，不计入功能缺口。', '',
              '静态检查入口：`python3 -B AI/Debug/scripts/rollback/static_check.py`。修改 JSON 后用 `python3 -B AI/Debug/scripts/rollback/render_taskboard.py` 同步此表。', '']
    return '\n'.join(lines)


if __name__ == '__main__':
    (DESIGN / '05_SingleCore_Taskboard.md').write_text(render())
