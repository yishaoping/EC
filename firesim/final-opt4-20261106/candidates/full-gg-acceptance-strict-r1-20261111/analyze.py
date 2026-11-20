#!/usr/bin/python3
"""Strict finite checker package join; independent from all live r5 inputs."""
from pathlib import Path
import collections,datetime,hashlib,importlib.util,json,os,sys
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
PARSER=W/'candidates/full-gg-package-analysis-round37-v1-20261111/controller.py'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def analyze(run):
 run=Path(run);s=importlib.util.spec_from_file_location('strict_local_parser',PARSER);p=importlib.util.module_from_spec(s);s.loader.exec_module(p)
 local,begins,results=p.parse_prints((run/'rtl-prints-1').read_text())
 events=[json.loads(l) for l in (run/'external-events.jsonl').read_text().splitlines()]
 assert events[0]['kind']=='HEADER' and events[-1]['kind']=='END','INCOMPLETE_EXTERNAL_EVENTS'
 records=[e['record'] for e in events if 'record' in e];assert records==list(range(1,len(records)+1)),'DUPLICATE_OR_MISSING_EVENT_RECORD'
 end=events[-1];assert end['sample_errors']==0 and not any(e['kind']=='SAMPLE_ERROR' for e in events)
 alloc=[e for e in events if e['kind']=='BOOM_ALLOC'];accepted=[e for e in events if e['kind']=='BOOM_RESULT_ACCEPTED']
 a=collections.Counter(e['package_seq'] for e in alloc);b=collections.Counter(e['package_seq'] for e in accepted)
 assert a and all(n==1 for n in a.values()),'DUPLICATE_OR_MISSING_ALLOCATION'
 assert b and all(n==1 for n in b.values()),'DUPLICATE_OR_MISSING_ACCEPTANCE'
 assert a==b,'UNMATCHED_ALLOCATION_OR_ACCEPTANCE_NO_DRAIN'
 assert len(alloc)==end['allocations'] and len(accepted)==end['accepted']==end['passed'] and end['failed']==end['cancelled']==0,'SUMMARY_COUNTER_MISMATCH'
 begin_events=[e for e in local if e['event']=='CHECKER_NEW_PACKAGE'];result_events=[e for e in local if e['event']=='LOCAL_RESULT_QUEUE_ENQUEUE']
 bc=collections.Counter((e['hart'],e['seq']) for e in begin_events);rc=collections.Counter((e['hart'],e['seq']) for e in result_events);ac=collections.Counter((e['checker'],e['package_seq']) for e in accepted)
 assert all(n==1 for n in bc.values()) and all(n==1 for n in rc.values()),'DUPLICATE_LOCAL_BEGIN_OR_RESULT'
 assert bc==rc==ac,'BEGIN_RESULT_ACCEPTANCE_IDENTITY_MISMATCH'
 assert set(begins)==set(results)==set(bc),'PARSER_DICTIONARY_AND_EVENT_MISMATCH'
 for key in bc:assert results[key]>=begins[key],'LOCAL_RESULT_PRECEDES_BEGIN'
 assert all(e['status']==0 and e['full_compare']==1 and e['cancelled']==0 for e in result_events),'NONPASS_CANCELLED_OR_NO_REAL_FULL_COMPARE'
 assert all(e['status']==0 for e in accepted),'NONPASS_ACCEPTANCE'
 by_seq={e['package_seq']:e for e in alloc}
 assert all(e['fastest_target_cycle']>=by_seq[e['package_seq']]['fastest_target_cycle'] and e['boom_csr_cycle']>=by_seq[e['package_seq']]['boom_csr_cycle'] for e in accepted),'ACCEPTANCE_PRECEDES_ALLOCATION'
 return dict(schema='ec-strict-finite-checker-join/1',status='PASS_STRICT_COMPLETE_ALLOCATION_BEGIN_FULLCOMPARE_RESULT_BOOM_ACCEPTANCE_JOIN',passed=True,allocations=len(alloc),local_begins=len(begin_events),full_compare_local_results=len(result_events),boom_pass_accepted=len(accepted),pending=0,duplicate=0,fail=0,cancel=0,sample_errors=0,per_checker=dict(sorted(collections.Counter(e['checker'] for e in accepted).items())),functional_baseline='8491167d84b6d9521b151a743673c1516926a1f8',fpga_access=False,evidence={str(q):sha(q) for q in [run/'external-events.jsonl',run/'rtl-prints-1',PARSER,Path(__file__)]},limitations=['Finite observed package protocol; not universal RTL equivalence','No strict checkerDone minus samepackage BOOMexecutionDone','SVB lifetime/payload drain evaluated separately','No architectural rollback/restart claim'],completed_utc=datetime.datetime.now(datetime.timezone.utc).isoformat())
if __name__=='__main__':
 value=analyze(sys.argv[1]);out=Path(sys.argv[2]);assert not out.exists(),'PRESERVE_EXISTING_RESULT'
 tmp=out.with_name(out.name+'.tmp-'+str(os.getpid()))
 with tmp.open('x') as f:json.dump(value,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(tmp,out);print(json.dumps({k:v for k,v in value.items() if k not in ['evidence','limitations']},indent=2))
