#!/usr/bin/env python3
"""Enable sparse events and failure snapshots in a fresh, non-trace build only.

The host keeps these in its bounded failure ring. No waveform aliases, trace
switches, datapath edits or global printf enable are added. Reset/event gates
are preserved exactly; a manifest proves only selected printf predicates changed.
"""
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import re

PRINT = re.compile(r'(?P<gate>^[ \t]*if \([^\n]*`PRINTF_COND_[^\n]*\)[^\n]*\n)'
                   r'(?P<call>[ \t]*\$fwrite\(32\x27h80000002, "(?P<fmt>(?:\\.|[^"\\])*)",'
                   r'(?P<args>.*?)\);)', re.M | re.S)
# No whole-address/lookup trace. Named lifecycle/wait events use the host
# bounded failure ring; repeated identical waits are coalesced there.
EVENTS = frozenset('CORE_WATCHDOG_SNAPSHOT DCACHE_WATCHDOG_SNAPSHOT CACHE_HANG_SNAPSHOT '
                   'MSHR_HANG_ENTRY SVB_HANG_ENTRY PRESERVATION_HANG_STATE LONG_STALL MSHR_STATE '
                   'FASTLINE_ACQUIRE FASTLINE_RELEASE FASTLINE_OWNER_CHANGE FASTLINE_BLOCK_OTHER_LINE '
                   'SVB_ENTRY_ALLOC SVB_SAFE SVB_PROMOTION_SELECT SVB_COMPLETION SVB_C_FIRE C_CHANNEL D_ACK '
                   'WB_START WB_BLOCK WB_COMPLETE PROBE_START PROBE_BLOCKED PROBE_COMPLETE '
                   'PRESERVATION_START PRESERVATION_WAIT PRESERVATION_BLOCKED '
                   'PRESERVATION_WB_FIRE PRESERVATION_WB_COMPLETE PRESERVATION_COMPLETE WATERMARK_ADVANCE'.split())
REQUIRED = {'BoomCore': {'CORE_WATCHDOG_SNAPSHOT'},
            'BoomNonBlockingDCache': {'DCACHE_WATCHDOG_SNAPSHOT', 'MSHR_HANG_ENTRY', 'FASTLINE_RELEASE'},
            'SpeculativeVersionBuffer': {'SVB_HANG_ENTRY'}}


def overlay(source, module):
    counts = Counter()
    def replace(match):
        event = match['fmt'].split()[0]
        if event not in EVENTS:
            return match[0]
        counts[event] += 1
        return match['gate'].replace('`PRINTF_COND_', "1'b1") + match['call']
    result = PRINT.sub(replace, source)
    missing = REQUIRED.get(module, set()) - counts.keys()
    if missing:
        raise RuntimeError('failure snapshot missing: '+module+'/'+','.join(sorted(missing)))
    # Source contains no native constant in these shared printf conditions.
    # Every edit has an exact inverse at the same original statement offset.
    expected = []
    for match in PRINT.finditer(source):
        if match['fmt'].split()[0] in EVENTS:
            expected.append((match.start(), match.end(), replace_without_count(match)))
    restored = result
    for start, end, edited in reversed(expected):
        shifted = start + sum(len(e)-(b-a) for a,b,e in expected if a < start)
        if restored[shifted:shifted+len(edited)] != edited:
            raise RuntimeError('diagnostic edit boundary mismatch')
        restored = restored[:shifted]+source[start:end]+restored[shifted+len(edited):]
    if restored != source:
        raise RuntimeError('diagnostic overlay changed non-print RTL')
    return result, dict(counts)


def replace_without_count(match):
    return match['gate'].replace('`PRINTF_COND_', "1'b1") + match['call']


def prepare(generated):
    generated = Path(generated)
    marker = generated/'failure_diagnostics_overlay.json'
    if marker.exists():
        recorded = json.loads(marker.read_text())
        for file, values in recorded['files'].items():
            if hashlib.sha256(Path(file).read_bytes()).hexdigest() != values['after_sha256']:
                raise RuntimeError('generated diagnostics changed since preparation: '+file)
        return recorded
    files = {}
    pending = []
    for module in REQUIRED:
        candidates = list(generated.rglob(module+'.sv'))
        if len(candidates) != 1:
            raise RuntimeError('expected one freshly generated '+module+'.sv')
        file = candidates[0]
        source = file.read_text()
        edited, counts = overlay(source, module)
        pending.append((file, edited))
        files[str(file.resolve())] = dict(before_sha256=hashlib.sha256(source.encode()).hexdigest(),
                         after_sha256=hashlib.sha256(edited.encode()).hexdigest(), events=counts)
    # Validate every file before mutating any of them.
    for file, edited in pending:
        file.write_text(edited)
    report = dict(status='PASS', trace_enabled=False, verbose=False, files=files,
                  proof='exact inverse of selected printf-enable edits equals fresh generated source',
                  storage='host 8192-event bounded ring; failure-only dump')
    marker.write_text(json.dumps(report,indent=2)+'\n')
    return report


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('generated', type=Path)
    args = parser.parse_args()
    print(json.dumps(prepare(args.generated),indent=2))
