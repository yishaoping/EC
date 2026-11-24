#!/usr/bin/env python3
"""Complete I/O/rebase oracle with physical Seq-reset namespaces.

Numeric Seq tags may legitimately recur after a real physical rebase. Preserve
all ledger/footer checks and count actual device effects across the full run.
"""
import argparse
import bisect
import json
from pathlib import Path
import re
import sys
sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'rollback'))
import fullcore_scoreboard as full
import concurrency_scoreboard as control


def ledger(path):
    rows, footer = [], None
    decimal = {'tick','clock','old_state','state','journal','replay','mem_access_fire'}
    required = decimal | {'seq','pc','addr','cmd','size','operand','journal_seq','journal_pc',
        'journal_addr','journal_cmd','journal_size','journal_operand','journal_word','grant_word'}
    for s in Path(path).read_text().splitlines():
        if s.startswith('IO_EFFECT_OBSERVER_END '):
            assert footer is None
            footer = {k:int(v) for k,v in re.findall(r'(\w+)=(\d+)',s)}
            continue
        assert s.startswith('IO_EFFECT_OBSERVER ') and footer is None
        f = {k:int(v,10 if k in decimal else 16) for k,v in re.findall(r'(\w+)=([0-9a-f]+)',s)}
        assert f.keys() == required and f['state'] in range(4)
        assert f['mem_access_fire'] == int(f['old_state']==1 and f['state']==2)
        if rows:
            assert f['old_state']==rows[-1]['state'] and f['tick']>=rows[-1]['tick']
        else:
            assert f['old_state']==(1<<64)-1 and f['state']==0
        rows.append(f)
    assert rows and footer and footer['events']==len(rows) and footer['last_tick']>=rows[-1]['tick']
    return rows,footer


def check(normal,fault,effects,overlap):
    signature = control.normal_signature(normal)
    actual, events = full.records(fault,True)
    assert actual == signature
    assert [f['seq'] for n,f in events if n=='PALIMPSEST_RESULT' and f['fail']]==[40]
    assert not any(f['cancelled'] for n,f in events if n=='PALIMPSEST_RESULT')
    _, restart, _, chain = control.control_chain(events,40,-1,0)
    rows = [tuple(map(int,s.split())) for s in Path(overlap).read_text().splitlines()]
    assert rows and all(len(r)==7 for r in rows) and all(a[0]<=b[0] for a,b in zip(rows,rows[1:]))
    reset_ticks = [r[0] for i,r in enumerate(rows) if r[6] and (i==0 or not rows[i-1][6])]
    assert reset_ticks and len(reset_ticks)==sum(n=='PALIMPSEST_SEQ_REBASE_RESET' for n,_ in events)
    phase,target,pc,resets = 'idle',None,None,0
    for n,f in events[restart+1:]:
        if n=='PALIMPSEST_SEQ_REBASE_TARGET':
            assert phase=='idle' and f['seq']>=41
            phase,target='evt',f['seq']
        elif n=='PALIMPSEST_EVT':
            assert phase=='evt' and f['target']==target
            phase='restore'
        elif n=='PALIMPSEST_ARCH_RESTORE':
            assert phase=='restore' and f['seq']==target
            phase,pc='compact',f['pc']
        elif n=='PALIMPSEST_EVT_COMPACT':
            assert phase=='compact' and f['tail']==target
            phase='reset'
        elif n=='PALIMPSEST_SEQ_REBASE_RESET':
            assert phase=='reset' and f['old_tail']==target
            phase='restart'
        elif n=='PALIMPSEST_RESTART':
            assert phase=='restart' and f['target']==target and f['pc']==pc
            assert f['epoch']==0 and f['reconciled']==1
            phase='capture'
        elif n=='PALIMPSEST_SCP_CAPTURE' and phase not in {'idle','pass'}:
            assert phase=='capture' and f['seq']==1 and f['epoch']==0 and f['pc']==pc
            phase='pass'
        elif n=='PALIMPSEST_RESULT' and phase=='pass' and f['seq']==1:
            assert f['pass']
            resets+=1
            phase='idle'
    assert resets==len(reset_ticks) and phase=='idle'
    samples,footer = ledger(effects)
    for s in samples:
        s['namespace']=bisect.bisect_right(reset_ticks,s['tick'])
    first = [(i,s) for i,s in enumerate(samples) if s['namespace']==0 and s['seq']==40 and s['mem_access_fire']]
    assert len(first)==1, 'missing/duplicate original effect within its physical namespace'
    index,original=first[0]
    assert original['addr']==0x200bffc and original['cmd']==0 and original['size']==2
    identity=tuple(original[k] for k in ('pc','addr','cmd','size'))
    def take(predicate,after):
        for i in range(after+1,len(samples)):
            s=samples[i]
            if s['namespace']==0 and predicate(s):return i,s
        raise AssertionError('UNCOVERED: initial namespace journal/replay')
    saved_i,saved=take(lambda s:s['old_state']==2 and s['state']==3 and s['journal'] and s['journal_seq']==40,index)
    assert tuple(saved['journal_'+k] for k in ('pc','addr','cmd','size'))==identity
    assert saved['journal_word']==saved['grant_word']
    invalid_i,invalid=take(lambda s:s['journal'] and s['replay'] and s['journal_seq']==40,saved_i)
    replay_i,replay=take(lambda s:s['old_state']==0 and s['state']==3 and s['seq']>40 and s['journal_seq']==s['seq'] and not s['replay'],invalid_i)
    assert tuple(replay[k] for k in ('pc','addr','cmd','size'))==identity and replay['journal']
    assert replay['grant_word']==replay['journal_word']==saved['journal_word']
    done_i,done=take(lambda s:s['seq']==replay['seq'] and s['old_state']==3 and s['state']==0,replay_i)
    assert sum(s['mem_access_fire'] for s in samples[index:done_i+1] if tuple(s[k] for k in ('pc','addr','cmd','size'))==identity)==1
    allocation=next(r for r in rows if r[2] and r[3]==41)
    assert saved['tick']<=allocation[0]<=invalid['tick'] and allocation[4:]==(0,1,0)
    release=next(r for r in rows if r[0]>=done['tick'] and not r[5])
    assert all(not r[4] and not r[6] for r in rows if allocation[0]<=r[0]<release[0])
    reserve=next(r for r in rows if r[0]>=release[0] and r[4])
    assert release[0]<=reserve[0]<reset_ticks[0] and reserve[5]==0
    assert all(not r[5] for r in rows if r[6]), 'physical reset over unresolved effect'
    # The fixed compact-trap-io binary performs high/low/high mtime reads in
    # each of its 16 rounds. Replay consumes the journal without a second A.
    device=[s for s in samples if s['mem_access_fire'] and s['seq'] and s['addr'] in {0x200bff8,0x200bffc}]
    assert len(device)==48, 'missing/duplicate physical timer effect in complete program'
    assert [s['addr'] for s in device]==[0x200bffc,0x200bff8,0x200bffc]*16
    assert all(s['cmd']==0 and s['size']==2 for s in device)
    return dict(scope='complete_program_all_namespaces_and_all_device_effects',checksum=signature[0],
        resets=resets,fresh_seq1_passes=resets,reset_ticks=reset_ticks,allocation=allocation,
        release=release,reservation=reserve,fault=chain,initial_effect=[original,saved,invalid,replay,done],
        actual_device_reads=device,observer_footer=footer)


def main():
    p=argparse.ArgumentParser(description=__doc__)
    for key in ['normal','fault','effects','overlap','report']:p.add_argument('--'+key,type=Path,required=True)
    a=p.parse_args()
    result=check(a.normal,a.fault,a.effects,a.overlap)
    with a.report.open('x') as f:json.dump(result,f,indent=2);f.write('\n')
    print(f'PALIMPSEST_IO_REBASE_COMPLETE=PASS resets={result["resets"]} actual_device_reads=48')


if __name__=='__main__':main()
