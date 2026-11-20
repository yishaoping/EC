#!/usr/bin/python3
"""Actual SVB capture/promote/ACK lifetimes in one common target timebase.

Never call these checker execution completion or architectural restart latency.
Captures reclaimed without ACK remain explicitly censored, not complete samples.
"""
from pathlib import Path
import collections
import hashlib
import json
import math
import statistics
import struct
import sys

def summary(values):
 v=sorted(values)
 if not v:return dict(n=0,total=0,mean=None,median=None,p95=None,p99=None,maximum=None,histogram={},units='fastest BOOM target cycles')
 return dict(n=len(v),total=sum(v),mean=statistics.mean(v),median=statistics.median(v),p95=v[math.ceil(.95*len(v))-1],p99=v[math.ceil(.99*len(v))-1],maximum=v[-1],
  histogram=dict(sorted(collections.Counter(v).items())),bucket_precision_cycles=1,percentiles='nearest rank',units='fastest BOOM target cycles')
def image_identity(e):
 p=e['payload']
 return (e['entry'],p['line'],p['key_valid'],p['writer'],p['generation'],p['content_seq'],p['epoch'],p['param'],tuple(p['data_words_le']))
def analyze(run,layout_path):
 run=Path(run);layout=json.loads(Path(layout_path).read_text())
 lines=(run/'external-events.jsonl').read_text().splitlines()
 events=[json.loads(l) for l in lines]
 assert events[-1]['kind']=='END' and events[-1]['sample_errors']==0,'INCOMPLETE_OR_INVALID_OBSERVER'
 captures=[];live={};finished=[];censored=[];last_tick=-1
 for e in events:
  kind=e['kind']
  if kind not in ['SVB_CAPTURE_ACCEPTED','SVB_PROMOTE_ACCEPTED','SVB_ACK_ACCEPTED']:continue
  tick=e['fastest_target_cycle'];assert tick>=last_tick,'NONMONOTONIC_TARGET_EVENT'
  last_tick=tick;entry=e['entry'];identity=image_identity(e)
  if kind=='SVB_CAPTURE_ACCEPTED':
   if entry in live:
    old=live.pop(entry);old.update(censored_at_target_cycle=tick,censor_reason='entry_reused_without_ACK_coalesced_or_invalidated_identity_not_observed');censored.append(old)
   row=dict(capture_serial=len(captures)+1,entry=entry,identity=identity,capture_target_cycle=tick,capture_boom_csr_cycle=e['boom_csr_cycle'])
   captures.append(row);live[entry]=row
  elif kind=='SVB_PROMOTE_ACCEPTED':
   assert entry in live,'PROMOTION_WITHOUT_CAPTURE'
   row=live[entry];assert row['identity']==identity,'PROMOTION_PAYLOAD_DIFFERS_FROM_CAPTURE'
   assert 'promotion_target_cycle' not in row,'DUPLICATE_PROMOTION'
   row.update(promotion_target_cycle=tick,promotion_boom_csr_cycle=e['boom_csr_cycle'])
  else:
   assert entry in live,'ACK_WITHOUT_CAPTURE'
   row=live.pop(entry);assert row['identity']==identity and 'promotion_target_cycle' in row,'ACK_IDENTITY_OR_PROMOTION_MISMATCH'
   row.update(ack_target_cycle=tick,ack_boom_csr_cycle=e['boom_csr_cycle'],capture_to_promotion=tick*0+row['promotion_target_cycle']-row['capture_target_cycle'],
    promotion_to_ack=tick-row['promotion_target_cycle'],capture_to_ack=tick-row['capture_target_cycle'])
   finished.append(row)
 for row in live.values():
  row.update(censored_at_target_cycle=events[-1]['last_fastest_target_cycle'],censor_reason='still_live_at_end_no_matching_ACK');censored.append(row)
 # One record per original BOOM edge, no idle compression. Include zeros in
 # occupancy distribution and preserve the exact ending ownership observation.
 fields={f['name']:f for f in layout['fields']};fmt=struct.Struct('<'+'I'*layout['record_words'])
 def value(row,name):
  f=fields[name];return sum(row[f['word_offset']+i]<<(32*i) for i in range(f['word_count']))
 occupancy=collections.Counter();last=None;records=0
 with (run/'external-events.jsonl.svb-full.bin').open('rb') as f:
  assert f.read(16)==b'ECSVBFULLBINv1'.ljust(16,b'\0')
  while chunk:=f.read(fmt.size*4096):
   assert len(chunk)%fmt.size==0
   for row in struct.iter_unpack(fmt.format,chunk):
    records+=1;last=row
    if not value(row,'reset'):occupancy[value(row,'io_occupancy')]+=1
 assert records==events[-1]['boom_edges']
 end_occupancy=value(last,'io_occupancy') if last else None
 zero_ending=(end_occupancy==0 and not live)
 return dict(schema='ec-original-svb-real-trace-latency/1',status='PASS_MATCHED_COMPLETE_LIFETIME_SAMPLES_WITH_EXPLICIT_CENSORING',
  captures=len(captures),complete_ack_lifetimes=len(finished),censored_lifetimes=len(censored),
  metrics={k:summary([e[k] for e in finished]) for k in ['capture_to_promotion','promotion_to_ack','capture_to_ack']},
  sample_lifetimes=finished,censored=censored,occupancy_histogram_target_cycles=dict(sorted(occupancy.items())),
  final_preedge_occupancy=end_occupancy,all_observed_ownership_ended=zero_ending,
  full_sv_replay_admission='Requires independent original target SVB full replay receipt; this analysis alone is insufficient',
  timebase='fastest BOOM target-cycle number from original GoldenGate ClockBridge; CSR values are corroboration and never used across epochs',
  data_kind='CPU GoldenGate metasimulation observations; no FPGA measurements',fpga_access=False,
  strict_checkerDone_minus_BOOMDone='NOT_MEASURED; SVB ACK is writeback ReleaseAck ownership completion',
  limitations=['Reused entries with no ACK are censored, not silently discarded','Final preedge occupancy does not by itself prove complete system checker/architectural drain','No full architectural rollback/restart verification'])

if __name__=='__main__':print(json.dumps(analyze(sys.argv[1],sys.argv[2]),indent=2,sort_keys=True))
