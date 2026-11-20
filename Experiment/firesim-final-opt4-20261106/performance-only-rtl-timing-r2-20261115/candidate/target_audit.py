#!/usr/bin/env python3
"""Hash the complete target graph outside the separately proved queue boundaries.

Module renumbering, source annotations and assertion diagnostic source-line
numbers are ignored. All other FIRRTL,
including every ROM word, register, port and connection, must match exactly.
"""
import hashlib
import json
from pathlib import Path
import re
import sys


def sha(data):
    return hashlib.sha256(data).hexdigest()


def graph(path, result_cdc):
    text = Path(path).read_text()
    chunks = re.split(r'(?m)^  ((?:ext)?module) ', text)
    modules = {}
    for kind, block in zip(chunks[1::2], chunks[2::2]):
        name = block.split(':', 1)[0].strip()
        modules[name] = (kind, block)
    memo = {}
    boundaries = {}

    def digest(name):
        if name in memo:
            return memo[name]
        kind, block = modules[name]
        block = re.sub(r' @\[[^\n]*?\]', '', block)
        # Chisel embeds a redundant source line in assertion printf text.
        # Preserve the full assertion, format text, filename and source code;
        # normalize only that generated diagnostic location's decimal number.
        block = re.sub(r'(\\n    at [A-Za-z0-9_.-]+\.scala:)\d+\b', r'\1<source-line>', block)
        block = block.replace(name, '<module>', 1)

        def instance(match):
            instance_name, child = match.group(1), match.group(2)
            boundary = None
            if re.fullmatch(r'GH_FIFO_SC(?:_\d+)?', child):
                boundary = 'PROVEN_BJL_82x256'
            if result_cdc and name == 'GHM' and re.fullmatch(r'u_result_cdc_\d+', instance_name):
                boundary = 'PROVEN_RESULT_CDC_34x256'
            if boundary:
                boundaries[name+'/'+instance_name] = dict(type=child, proof=boundary)
            return 'inst '+instance_name+' of '+(boundary or digest(child))

        block = re.sub(r'\binst (\w+) of (\w+)\b', instance, block)
        memo[name] = sha((kind+' '+block).encode())
        return memo[name]

    root = digest('FireSim')
    assert sum(x['proof'] == 'PROVEN_BJL_82x256' for x in boundaries.values()) == 8
    if result_cdc:
        assert sum(x['proof'] == 'PROVEN_RESULT_CDC_34x256' for x in boundaries.values()) == 4
    return dict(firrtl_sha256=sha(Path(path).read_bytes()), graph_outside_proven_boundaries=root,
                boundaries=boundaries, reached_modules=len(memo), total_modules=len(modules))


def audit(baseline, candidate, result_cdc, output):
    rows = dict(baseline=graph(baseline, result_cdc), candidate=graph(candidate, result_cdc))
    equal = rows['baseline']['graph_outside_proven_boundaries'] == rows['candidate']['graph_outside_proven_boundaries']
    rows.update(status='PASS_EXACT_TARGET_GRAPH_OUTSIDE_PROVEN_QUEUES' if equal else 'FAIL_TARGET_GRAPH_MISMATCH',
                target_ROM_exactly_equal=equal,
                ignored_metadata=['source annotations', 'module definition numbering',
                                  'decimal source line in assertion diagnostic text'],
                whole_system_runtime_equivalence=False)
    Path(output).write_text(json.dumps(rows, indent=2)+'\n')
    assert equal, 'unexpected target change outside proven queues; refuse Golden Gate/CAD'
    return rows


if __name__ == '__main__':
    audit(sys.argv[1], sys.argv[2], '--result-cdc' in sys.argv, sys.argv[3])
