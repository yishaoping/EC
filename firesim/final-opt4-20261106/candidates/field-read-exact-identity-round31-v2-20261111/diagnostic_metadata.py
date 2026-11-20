from pathlib import Path
import re, subprocess, difflib, hashlib
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
PARENT='d9d732622601ed792a2647546006b5aae986ab8e'
COMMIT='3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c'

def source_locations(candidate):
    """Map only assertion diagnostic line numbers to identical source lines.

    Conditions, statements, format strings and data fields otherwise remain
    exact. Every changed location is retained in the proof evidence.
    """
    tree = W / 'Opt4-fit-dcache-field-read-prune-r1-20261111'
    rel = 'chipyard/generators/boom/src/main/scala/lsu/dcache.scala'
    get = lambda commit: subprocess.check_output(['git', 'show', commit + ':' + rel], cwd=tree, text=True)
    old = get(PARENT); new = get(COMMIT)
    left = old.splitlines(); right = new.splitlines()
    mapping = {}
    for block in difflib.SequenceMatcher(a=left, b=right, autojunk=False).get_matching_blocks():
        for offset in range(block.size):
            mapping[block.b + offset + 1] = block.a + offset + 1
    records = []

    def string(m):
        raw = m[0]
        if not raw.startswith('"Assertion failed'):
            return raw

        def location(loc):
            line = int(loc[1])
            assert line in mapping, ('unproven assertion source location', line)
            previous = mapping[line]
            assert right[line - 1] == left[previous - 1]
            if line != previous:
                records.append(dict(candidate_line=line, parent_line=previous,
                                    identical_source_line=right[line - 1]))
            return 'at dcache.scala:' + str(previous)

        return re.sub(r'at dcache\.scala:(\d+)', location, raw)

    normalized = re.sub(r'"(?:\\.|[^"\\])*"', string, candidate)
    return normalized, dict(
        method='Only assertion diagnostic source line numbers mapped through exact identical git source lines; every condition/statement/format/data expression retained.',
        parent_source_sha256=hashlib.sha256(old.encode()).hexdigest(),
        candidate_source_sha256=hashlib.sha256(new.encode()).hexdigest(),
        changed_diagnostic_locations=records,
        raw_module_sha256=hashlib.sha256(candidate.encode()).hexdigest(),
        normalized_module_sha256=hashlib.sha256(normalized.encode()).hexdigest())
