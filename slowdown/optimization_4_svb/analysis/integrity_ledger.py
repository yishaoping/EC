#!/usr/bin/env python3
"""Allocation-scoped, full-run integrity evidence; no hardware execution.

SC kinds 32..38 schema 2 are mandatory in integrity_v2 runs. A missing hash
never becomes a zero or an inferred PASS. Normal L2 writes are not SVB evidence.
"""
from collections import defaultdict
import argparse
import csv
import json
from pathlib import Path
import sys

MASK = (1 << 64) - 1

def rotate(value, n):
    n %= 64
    return ((value << n) | (value >> ((64-n) % 64))) & MASK


def build(records):
    if not any(32 <= r['kind'] <= 38 for r in records):
        return dict(status='UNOBSERVED',schema=2,allocations=0,terminal_counts={},completions=0,duplicate_beats=0,errors=[],lifecycles=[])
    rows = {}; slots = {}; pending = {}; errors = []; duplicate_beats = 0; last_serial = defaultdict(int)
    def error(r, message):
        errors.append(f"cycle={r['cycle']} kind={r['kind']}: {message}")
    def find(r, serial, entry):
        row = rows.get((r['episode'], serial))
        if row is None or row['entry'] != entry:
            error(r, 'unknown lifecycle/entry'); return None
        return row
    # One synchronous edge has no reliable blackbox callback ordering.
    order = {32:0, 33:1, 36:2, 19:3, 34:4, 20:5, 37:6, 38:7, 21:8, 22:9, 35:10}
    relevant = [r for r in records if r['kind'] in order and r['hart']==0 or
                r['kind'] in (35,36)]
    for r in sorted(relevant, key=lambda r:(r['episode'],r['time'],order[r['kind']],r['hart'])):
        k,n,e = r['kind'],r['nums'],r['episode']
        if k in range(32,39) and n[0]!=2:
            error(r,'unsupported integrity schema'); continue
        if k==32:
            serial, entry = n[1:3]; key=(e,serial); slot=(e,entry)
            if key in rows or slot in slots or serial<=0 or entry>=16:
                error(r,'duplicate serial or stale occupied slot'); continue
            if not 1<=n[10]<=64:error(r,'invalid capture word count')
            if serial != last_serial[e]+1:error(r,'allocation serial gap/reorder')
            last_serial[e]=serial
            row=dict(lifecycle_id=f'{e}:{entry}:{serial}',episode=e,serial=serial,entry=entry,
                     line=n[3],pkg_seq=n[4],generation=n[5],writer=n[6],epoch=n[7],key_valid=n[8],
                     capture_cycle=r['cycle'],capture_hash=n[9],words=n[10],stored_hash=None,
                     promotion_hash=None,safe_cycle=None,promotion_cycle=None,c_hash=0,lower_hash=0,
                     c_mask=0,lower_mask=0,c_beats=0,lower_beats=0,ack_cycle=None,
                     completion_cycle=None,terminal_reason=None,successor_serial=None)
            rows[key]=row; slots[slot]=key
        elif k in (33,34,35,36,37):
            row=find(r,n[1],n[2])
            if row is None:continue
            if row['terminal_reason'] is not None:
                error(r,'event after terminal'); continue
            if k==33:
                if row['stored_hash'] is not None:error(r,'duplicate stored checkpoint')
                row['stored_hash']=n[3]
                if n[3]!=row['capture_hash']:error(r,'capture/stored hash mismatch')
            elif k==34:
                if row['promotion_cycle'] is not None:error(r,'duplicate promotion')
                row['promotion_cycle']=r['cycle'];row['promotion_hash']=n[4]
                if row['safe_cycle'] is None:error(r,'promotion without safe observation')
                if row['stored_hash'] is None or n[3]!=row['stored_hash'] or n[4]!=n[3]:
                    error(r,'stored/promotion hash mismatch or missing checkpoint')
                identity=(e,row['line'],row['pkg_seq'],row['generation'],row['writer'])
                if identity in pending:error(r,'overlapping promotion identity')
                pending[identity]=row
            elif k==36:
                row['safe_cycle']=row['safe_cycle'] or r['cycle']
                if row['key_valid'] and row['pkg_seq']>n[3]:error(r,'unsafe entry declared safe')
            elif k==35:
                reason={1:'PROMOTED_COMPLETED',2:'COALESCED',3:'FLUSH_DISCARDED',4:'INVALIDATED'}.get(n[3])
                if reason is None:error(r,'unknown terminal reason');continue
                if reason=='PROMOTED_COMPLETED' and row['completion_cycle'] is None:
                    error(r,'free without matching completion')
                if reason!='PROMOTED_COMPLETED' and row['promotion_cycle'] is not None:
                    error(r,'discard of selected/inflight entry')
                if reason=='COALESCED':
                    successor=rows.get((e,n[4]))
                    if not successor or (successor['terminal_reason'] is not None and successor.get('free_cycle')!=r['cycle']) or successor['line']!=row['line'] or successor['writer']!=row['writer'] or \
                       (successor['pkg_seq'],successor['generation']) <= (row['pkg_seq'],row['generation']) or \
                       row['safe_cycle'] is None or successor['safe_cycle'] is None:
                        error(r,'illegal coalescing successor')
                    row['successor_serial']=n[4]
                row['terminal_reason']=reason;row['free_cycle']=r['cycle'];slots.pop((e,row['entry']),None)
                pending.pop((e,row['line'],row['pkg_seq'],row['generation'],row['writer']),None)
            else:
                if (n[3],n[4],n[5],n[6],n[7]) != (row['line'],row['pkg_seq'],row['generation'],row['writer'],row['epoch']):
                    error(r,'C beat identity changed')
                if row['promotion_cycle'] is None:error(r,'C beat before promotion')
                duplicate_beats += beat(row,'c',n[8],n[9],n[10],n[11],r,error)
        elif k==38:
            row=pending.get((e,n[1],n[2],n[3],n[4]))
            # Ignore all normal releases and old writes before this promotion.
            if row is not None and row['c_beats']:
                duplicate_beats += beat(row,'lower',n[6],n[7],n[8],n[9],r,error)
        elif k in (21,22) and n[1]==1:
            key=slots.get((e,n[2]));row=rows.get(key)
            if row is None:error(r,'protocol completion without lifecycle');continue
            if (n[3],n[4],n[7],n[8],n[9],n[10]) != (row['line'],row['pkg_seq'],row['generation'],row['writer'],row['key_valid'],row['epoch']):
                error(r,'ACK/completion identity changed')
            if k==21:
                if row['ack_cycle'] is not None:error(r,'duplicate ACK')
                row['ack_cycle']=r['cycle']
                expected=(1<<row['words'])-1
                if row['c_mask']!=expected or row['lower_mask']!=expected:error(r,'ACK before complete data')
                if row['c_hash']!=row['capture_hash'] or row['lower_hash']!=row['capture_hash']:
                    error(r,'same-lifecycle transferred data mismatch')
            else:
                if row['ack_cycle'] is None:error(r,'completion before ACK')
                if row['completion_cycle'] is not None:error(r,'double completion')
                row['completion_cycle']=r['cycle']
    missing=not rows
    for row in rows.values():
        if row['terminal_reason'] is None:errors.append(row['lifecycle_id']+': retained without terminal')
        if row['stored_hash'] is None:errors.append(row['lifecycle_id']+': missing stored checkpoint')
    counts=defaultdict(int)
    for row in rows.values():counts[row['terminal_reason'] or 'RETAINED']+=1
    return dict(status='FAIL' if errors else 'UNOBSERVED' if missing else 'PASS',
                schema=2,allocations=len(rows),terminal_counts=dict(counts),
                completions=sum(x['completion_cycle'] is not None for x in rows.values()),
                duplicate_beats=duplicate_beats,errors=errors,lifecycles=list(rows.values()))


def beat(row, prefix, value, offset, span, words, r, error):
    if not (0<span<=64 and 0<=offset<64 and offset+span<=words<=64 and words==row['words']):
        error(r,'invalid beat bounds');return 0
    mask=((1<<span)-1)<<offset
    duplicate=bool(row[prefix+'_mask']&mask)
    if duplicate:error(r,'duplicate/overlapping '+prefix+' beat')
    expected_offset=row[prefix+'_beats_words'] if prefix+'_beats_words' in row else 0
    if offset!=expected_offset:error(r,'out-of-order '+prefix+' beat')
    row[prefix+'_beats_words']=offset+span
    row[prefix+'_mask']|=mask
    row[prefix+'_hash']^=rotate(value,offset*7)
    row[prefix+'_beats']+=1
    return int(duplicate)


def export(result, directory):
    directory=Path(directory);directory.mkdir(parents=True,exist_ok=True)
    (directory/'integrity_ledger.json').write_text(json.dumps(result,indent=2)+'\n')
    if result['lifecycles']:
        with (directory/'svb_lifecycle_ledger.csv').open('w') as f:
            writer=csv.DictWriter(f,fieldnames=list(dict.fromkeys(k for row in result['lifecycles'] for k in row)))
            writer.writeheader();writer.writerows(result['lifecycles'])


def read_events(path):
    records=[]
    for line in Path(path).read_text(errors='replace').splitlines():
        parts=line.split('\t')
        if len(parts)!=23 or parts[0]!='SC1':
            continue
        try:
            records.append(dict(time=int(parts[1]),cycle=int(parts[2]),episode=int(parts[4]),
                                kind=int(parts[5]),hart=int(parts[6]),
                                nums=[int(value,16) for value in parts[7:]]))
        except ValueError:
            continue
    return records


def main(argv=None):
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('run',type=Path,help='completed Opt4 run directory')
    parser.add_argument('--output-dir',type=Path,
                        help='directory for integrity_ledger.json and lifecycle CSV (default: RUN/analysis/integrity)')
    args=parser.parse_args(argv)
    source=args.run/'safe_chain_events.tsv'
    if not source.is_file():
        parser.error('missing lifecycle event stream: '+str(source))
    result=build(read_events(source))
    output=args.output_dir or args.run/'analysis/integrity'
    export(result,output)
    print(json.dumps({key:result[key] for key in
                      ('status','schema','allocations','terminal_counts','completions',
                       'duplicate_beats','errors')},indent=2,sort_keys=True))
    return 0 if result['status']=='PASS' else 2


if __name__=='__main__':
    raise SystemExit(main())
