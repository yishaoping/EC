#!/usr/bin/env python3
"""Corrupt real complete IRQ records; require each admission/trap failure rejected."""
import argparse, contextlib, io, json, re
from pathlib import Path
import interrupt_scoreboard as score
from build_io_observer import digest

def main():
 p=argparse.ArgumentParser(description=__doc__)
 for n in ['normal','fault','normal-effects','fault-effects','normal-irq','fault-irq','out']:
  p.add_argument('--'+n,type=Path,required=True)
 a=p.parse_args();a.out.mkdir()
 paths=[getattr(a,n) for n in ['normal','fault','normal_effects','fault_effects','normal_irq','fault_irq']]
 hashes={str(p):digest(p) for p in paths+[Path(__file__).resolve(),Path(score.__file__)]}
 with contextlib.redirect_stdout(io.StringIO()):score.check(*paths)
 rounds=score.effects(a.fault_effects);start=rounds[0]['set']['tick']
 original=a.fault_irq.read_text();lines=original.splitlines(True)
 def sample(line):return {k:int(v,16 if k in {'seq','cause','trap_cause','epc'} else 10) for k,v in re.findall(r'(\w+)=([0-9a-f]+)',line)}
 indices=[i for i,line in enumerate(lines) if line.startswith('IRQ ') and sample(line)['tick']>=start]
 offer=next(i for i in indices if sample(lines[i])['irq'])
 trap=next(i for i in indices if sample(lines[i])['trap'] and sample(lines[i])['trap_cause']==0x8000000000000003)
 ret=next(i for i in indices if i>trap and sample(lines[i])['ret'])
 overlap=next(i for i in indices if sample(lines[i])['pending'] and sample(lines[i])['stop'] and sample(lines[i])['effect_pending'])
 def replace(text,key,val):return re.sub(r'\b'+key+r'=[0-9a-f]+',key+'='+str(val),text)
 cases={
 'offer_during_recovery':(offer,{'stop':1}),
 'offer_during_boundary':(offer,{'boundary':1,'hold':1}),
 'offer_during_starting':(offer,{'starting':1,'hold':1}),
 'offer_during_pending':(offer,{'effect':1,'safe':0,'effect_pending':1,'hold':1}),
 'pending_journal_disagrees':(offer,{'effect_pending':1}),
 'wrong_interrupt_cause':(offer,{'cause':'8000000000000007'}),
 'wrong_trap_cause':(trap,{'trap_cause':'b'}),
 'missing_msip_trap':(trap,{'trap':0}),
 'wrong_return_epc':(ret,{'epc':0}),
 'irq_admitted_in_overlap':(overlap,{'irq':1,'cause':'8000000000000003'}),
 }
 results={}
 for name,(index,changes) in cases.items():
  data=list(lines)
  for k,v in changes.items():data[index]=replace(data[index],k,v)
  target=a.out/(name+'.log');target.write_text(''.join(data))
  try:score.interrupts(target,rounds,True)
  except AssertionError as e:results[name]={'rejected':True,'reason':str(e)}
  else:raise AssertionError('accepted corrupted IRQ record: '+name)
 # Remove every return, preserving full event count/footer and all other data.
 for name,change in [('missing_returns',lambda line:replace(line,'ret',0)),('missing_pending_edges',lambda line:replace(line,'pending',0))]:
  target=a.out/(name+'.log');target.write_text(''.join(change(line) if line.startswith('IRQ ') else line for line in lines))
  try:score.interrupts(target,rounds,True)
  except AssertionError as e:results[name]={'rejected':True,'reason':str(e)}
  else:raise AssertionError('accepted corrupted IRQ record: '+name)
 # Device scope remains all sixteen rounds, even with boot MSIP pulses excluded.
 for name,change in [('missing_protected_clear',lambda line:replace(line,'seq','0') if 'addr=2000000 ' in line and 'operand=0 ' in line else line),('truncated_irq_footer',lambda line:'' if line.startswith('IRQ_OBSERVER_END ') else line)]:
  source=a.fault_effects if name=='missing_protected_clear' else a.fault_irq
  target=a.out/(name+'.log');target.write_text(''.join(change(line) for line in source.read_text().splitlines(True)))
  try:
   if name=='missing_protected_clear':score.effects(target)
   else:score.interrupts(target,rounds,True)
  except AssertionError as e:results[name]={'rejected':True,'reason':str(e)}
  else:raise AssertionError('accepted corrupted record: '+name)
 assert all(digest(Path(p))==h for p,h in hashes.items()),'inputs changed'
 (a.out/'results.json').write_text(json.dumps({'status':'PASS','valid_full_record_passed':True,'inputs':hashes,'mutations':results},indent=2)+'\n')
 print('PALIMPSEST_INTERRUPT_NEGATIVE=PASS rejected='+str(len(results)))
if __name__=='__main__':main()
