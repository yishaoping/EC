"""Reject revoked functional-extension inputs in future detached CPU jobs.

This guard enforces the user's scope boundary. Equivalence itself still needs
the source-bound module/composition verification used by the CAD pipeline.
It performs no FPGA operation and never signals an existing job.
"""
import json
from pathlib import Path
import subprocess

from opt4_unattended_common import W, U, read


def enforce(spec):
    policy = read(U/'campaign-policy.json')
    if not policy.get('area_equivalence_only'):
        return {'scope': 'legacy_policy'}
    assert policy.get('functional_baseline_commit') == '8491167d84b6d9521b151a743673c1516926a1f8'
    assert policy.get('functional_extensions_allowed') is False
    forbidden = set(policy.get('forbidden_extension_commits', []))
    trees = set()
    commits = set()

    def visit(value, key=''):
        if isinstance(value, dict):
            for k, v in value.items():
                visit(k)
                visit(v, k)
        elif isinstance(value, list):
            for v in value:
                visit(v)
        elif isinstance(value, str):
            assert 'architectural-recovery' not in value.lower(), 'REVOKED_FUNCTIONAL_EXTENSION_INPUT'
            assert 'PackageRecoveryController' not in value and 'PackageRecoveryState' not in value and 'PackageRecoveryMemory' not in value, 'REVOKED_FUNCTIONAL_EXTENSION_RTL'
            if key in ['hardware_commit', 'commit', 'parent_commit', 'derivation_parent']:
                commits.add(value)
            if value.startswith(str(W)+'/Opt4-'):
                tree = W / Path(value).relative_to(W).parts[0]
                if (tree/'.git').exists():
                    trees.add(tree)

    visit({k: v for k, v in spec.items() if k != 'evidence_inputs'})
    for name in spec.get('inputs', {}):
        p = Path(name)
        if p.suffix == '.json' and p.stat().st_size < 16*2**20:
            visit(json.loads(p.read_text()))
    assert not commits.intersection(forbidden), 'REVOKED_FUNCTIONAL_EXTENSION_COMMIT'
    audited = {}
    for tree in sorted(trees):
        head = subprocess.check_output(['git','rev-parse','HEAD'],cwd=tree,text=True).strip()
        assert head not in forbidden, 'REVOKED_FUNCTIONAL_EXTENSION_HEAD'
        for ancestor in forbidden:
            r = subprocess.run(['git','merge-base','--is-ancestor',ancestor,head],
                               cwd=tree,stdout=subprocess.DEVNULL,stderr=subprocess.DEVNULL)
            assert r.returncode == 1, ('REVOKED_OR_UNAUDITABLE_ANCESTRY',str(tree),ancestor,r.returncode)
        added = subprocess.check_output(['git','ls-tree','-r','--name-only',head,
                 'chipyard/generators/boom/src/main/scala/recovery'],cwd=tree,text=True)
        assert not added.strip(), 'REVOKED_FUNCTIONAL_RECOVERY_MODULES_IN_TREE'
        audited[str(tree)] = head
    return dict(scope='frozen_function_and_cycle_equivalence_only',
                baseline=policy['functional_baseline_commit'],audited_worktrees=audited)
