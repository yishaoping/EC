#!/usr/bin/env python3
"""Initial saved-FST coverage/final-state audit. Causal transition RCA follows offline."""
import argparse
import json
from pathlib import Path
import re
import subprocess


def summarize(index, inventory):
    signals, final, meta = [], {}, None
    for line in index.splitlines():
        parts = line.split('\t')
        if parts[0] == 'META':
            meta = dict(start=int(parts[1]), end=int(parts[2]), timescale_exponent=int(parts[3]))
        elif parts[0] == 'H':
            path = parts[3]; m = re.search(r'(opt4_wave_\w+)', path)
            if m: signals.append(dict(handle=int(parts[1]), width=int(parts[2]), path=path, alias=m[1]))
        elif parts[0] == 'F':
            bits = parts[2]
            final[int(parts[1])] = int(bits, 2) if re.fullmatch('[01]+', bits) else bits
    declared = {row['alias'] for row in signals}
    missing = sorted({a['name'] for a in inventory['aliases']} - declared)
    missing_instances = []
    # One shared compiled MSHR trace function can serve six instances: check
    # actual FST hierarchy rather than just counting C++ declaration strings.
    for module, paths in inventory['hierarchy'].items():
        for path in paths:
            prefix = path+'.'
            if not any(prefix in s['path'] and s['alias'].startswith('opt4_wave_'+module+'_') for s in signals):
                missing_instances.append(path)
    state = [{**s, 'value': final[s['handle']]} for s in signals if s['handle'] in final]
    values = {s['alias']: s['value'] for s in state}
    essential = {a['name'] for a in inventory['aliases'] if any(
        marker in a['name'] for marker in ('_CORE_WATCHDOG_SNAPSHOT_', '_DCACHE_WATCHDOG_SNAPSHOT_',
                                          '_SVB_HANG_ENTRY_', '_MSHR_HANG_ENTRY_'))}
    missing_final = sorted(essential - values.keys())
    def value(module, event, field):
        return values.get(f'opt4_wave_{module}_{event}_0_{field}')
    progress = dict(commit=value('BoomCore', 'CORE_WATCHDOG_SNAPSHOT', 'last_commit'))
    for field, key in [('last_lsu', 'lsu'), ('last_watermark', 'watermark'),
                       ('last_checker_result', 'checker_result'), ('last_wb', 'wb'),
                       ('last_probe', 'probe'), ('last_mshr_free', 'mshr_free'), ('last_svb', 'svb')]:
        progress[key] = value('BoomNonBlockingDCache', 'DCACHE_WATCHDOG_SNAPSHOT', field)
    return dict(schema=1, coverage='PASS' if meta and not missing and not missing_instances and not missing_final and final else 'FAIL',
                waveform_time=meta, declared_aliases=len(declared), missing_aliases=missing,
                missing_instances=missing_instances, final_state=state,
                missing_final_aliases=missing_final,
                last_progress_core_cycles=progress,
                fastline_valid=value('BoomNonBlockingDCache', 'DCACHE_WATCHDOG_SNAPSHOT', 'fast_valid'),
                last_commit=progress['commit'],
                rootcause='PENDING_OFFLINE_FST_TRANSITION_ANALYSIS',
                evidence_boundary='Final-state values are not by themselves a proven wait-for cycle.')


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('run', type=Path); ap.add_argument('--reader', type=Path, required=True)
    args = ap.parse_args(); run = args.run
    inventory = json.loads((run/'signal_manifest.json').read_text())
    index = run/'waveform_index.tsv'
    with index.open('x') as output, (run/'waveform_reader.stderr.log').open('x') as errors:
        proc = subprocess.Popen([str(args.reader), str(run/'hang.fst')], stdout=output, stderr=errors)
        try:
            while True:
                try: rc = proc.wait(timeout=30); break
                except subprocess.TimeoutExpired:
                    print('FST_OFFLINE_ANALYSIS_IN_PROGRESS='+str(run/'hang.fst'), flush=True)
        except BaseException:
            proc.terminate()
            try: proc.wait(timeout=10)
            except subprocess.TimeoutExpired: proc.kill(); proc.wait()
            raise
    if rc: raise RuntimeError('FST index/value read failed: see waveform_reader.stderr.log')
    summary = summarize(index.read_text(), inventory)
    (run/'waveform_summary.json').write_text(json.dumps(summary, indent=2)+'\n')
    progress_file = run/'last_progress.json'
    progress = json.loads(progress_file.read_text()) if progress_file.exists() else {}
    progress['fst_final_progress_core_cycles'] = summary['last_progress_core_cycles']
    progress['fst_progress_provenance'] = 'waveform_index.tsv F values + signal_manifest.json expressions'
    progress_file.write_text(json.dumps(progress, indent=2)+'\n')
    (run/'waveform_analysis.md').write_text(
        '# Initial waveform evidence\n\n'
        f"FST coverage: **{summary['coverage']}**. Last commit core cycle: `{summary['last_commit']}`. "
        f"Final fast-line valid: `{summary['fastline_valid']}`.\n\n"
        'Use the single saved FST for transition analysis: last commit → ROB head → LSU token/address → '
        'DCache gates → actual owner → owner wait → closed graph or external progress. '
        'The compact wait_for_graph.json is preliminary; verify overlapping wait intervals in FST. '
        'Do not infer a deadlock solely from a final-state snapshot. No automatic rerun is permitted.\n')
    print(json.dumps({k:v for k,v in summary.items() if k!='final_state'}, indent=2))


if __name__ == '__main__': main()
