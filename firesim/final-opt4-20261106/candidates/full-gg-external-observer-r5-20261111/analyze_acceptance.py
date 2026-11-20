#!/usr/bin/python3
"""Join actual BOOM allocation/acceptance with captured checker local results.

This never assumes local checker clocks share a CSR epoch or converts enqueue
into BOOM completion. Sequence matching and sampled acceptance are independent
evidence. Strict same-unit execution-done latency remains unavailable.
"""
from pathlib import Path
import collections
import hashlib
import importlib.util
import json
import sys
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
PARSER=W/'candidates/full-gg-package-analysis-round37-v1-20261111/controller.py'
def analyze(run):
 run=Path(run)
 s=importlib.util.spec_from_file_location('original_checker_parser',PARSER)
 p=importlib.util.module_from_spec(s);s.loader.exec_module(p)
 local,begins,results=p.parse_prints((run/'rtl-prints-1').read_text())
 events=[];expected_record=1
 for line in (run/'external-events.jsonl').read_text().splitlines():
  e=json.loads(line)
  if 'record' in e:
   assert e['record']==expected_record,('EXTERNAL_RECORD_SEQUENCE',e['record'],expected_record)
   expected_record+=1
  events.append(e)
 assert events[0]['kind']=='HEADER' and events[-1]['kind']=='END','INCOMPLETE_EXTERNAL_RECORDS'
 end=events[-1]
 assert end['sample_errors']==0,'OBSERVER_SAMPLING_ERROR'
 alloc=[e for e in events if e['kind']=='BOOM_ALLOC']
 accepted=[e for e in events if e['kind']=='BOOM_RESULT_ACCEPTED']
 result_events=[e for e in local if e['event']=='LOCAL_RESULT_QUEUE_ENQUEUE']
 seq_alloc=collections.Counter(e['package_seq'] for e in alloc)
 seq_accept=collections.Counter(e['package_seq'] for e in accepted)
 assert accepted and all(n==1 for n in seq_accept.values()),'NO_ACCEPTED_OR_DUPLICATE_SEQUENCE'
 assert all(seq_alloc[k]==1 for k in seq_accept),'ACCEPTED_WITHOUT_OBSERVED_ALLOCATION'
 allocation_by_seq={e['package_seq']:e for e in alloc}
 for e in accepted:
  assert e['status']==0,'NONPASS_ACCEPTED'
  assert e['fastest_target_cycle']>=allocation_by_seq[e['package_seq']]['fastest_target_cycle']
  assert e['boom_csr_cycle']>=allocation_by_seq[e['package_seq']]['boom_csr_cycle']
 local_by_seq={e['seq']:e for e in result_events}
 assert len(local_by_seq)==len(result_events)==len(results),'LOCAL_SEQUENCE_NOT_UNIQUE'
 assert set(local_by_seq)==set(seq_accept),'LOCAL_RESULTS_AND_BOOM_ACCEPTANCE_DIFFER'
 for e in accepted:
  local_result=local_by_seq[e['package_seq']]
  assert e['checker']==local_result['hart'] and e['status']==local_result['status'],'CHECKER_ID_OR_STATUS_MISMATCH'
 # Require full explicit dictionary introspection if parser changes its schema.
 sample=local[:2]
 value=dict(schema='ec-boom-checker-acceptance-analysis/1',sample_errors=end['sample_errors'],
  boom_allocations=len(alloc),boom_accepted=len(accepted),boom_accepted_unique=len(seq_accept),
  unmatched_allocations=sorted(set(seq_alloc)-set(seq_accept)),
  accepted_allocation_cycle_intervals=[dict(package_seq=e['package_seq'],allocation_to_accepted_csr_cycles=e['boom_csr_cycle']-allocation_by_seq[e['package_seq']]['boom_csr_cycle']) for e in accepted],
  checker_local_event_count=len(local),checker_local_begin_count=len(begins),checker_local_result_count=len(results),
  parser_schema_sample=sample,
  status='PASS_FINITE_SAMPLED_BOOM_ACCEPTANCE_AND_EXACT_LOCAL_PACKAGE_PAIRING',
  strict_checkerDone_minus_BOOMDone='NOT_MEASURED_SAME_PACKAGE_BOOM_EXECUTION_DONE_EVENT_ABSENT',
  interval_scope='allocation-to-BOOM-accepted result, not checker execution latency',
  fpga_access=False,limitations=['Do not map checker local CYCLE to CSR cycle without reset/epoch anchor','Finite captured matching is not complete-system formal equivalence'])
 return value
if __name__=='__main__':
 print(json.dumps(analyze(sys.argv[1]),indent=2,sort_keys=True))
