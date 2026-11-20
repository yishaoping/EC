#!/usr/bin/python3
from pathlib import Path
import collections,hashlib,json
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');O=D/'strict-latency-observation-boundary-r1-20261112';O.mkdir(exist_ok=False)
BASE='8491167d84b6d9521b151a743673c1516926a1f8';B=Path('/data1/gzh/EC-backups/opt4-final-performance-20261106/source/chipyard')
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
files=['generators/boom/src/main/scala/exu/core.scala','generators/boom/src/main/scala/common/tile.scala','generators/rocket-chip/src/main/scala/rocket/RocketCore.scala']
evidence={};semantics={}
for rel in files:
 p=W/'C4/chipyard'/rel;f=B/rel;t=p.read_text();ft=f.read_text();evidence[str(p)]=sha(p);evidence[str(f)]=sha(f)
 if 'exu/core' in rel:
  tokens=['val producerSealCoreReady = producerSealTargetValid','rob.io.empty','!rob.io.commit.valids.asUInt.orR','!snapshot_commit_prev','!rsu_master.io.rsu_busy.asBool','!rsu_master.io.core_hang_up.asBool','!io.big_hang']
 elif 'common/tile' in rel:tokens=['val producerSeals = RegInit','core.io.producer_seal_candidate && gh_buf.io.ght_filters_empty.asBool','core.io.checker_segment_id(i) === core.io.producer_seal_seq']
 else:tokens=['val package_result_fire = package_result_queue.io.enq.fire','val package_result_event = full_check_complete || package_cancelled']
 for token in tokens:assert token in t and token in ft,token
 semantics[rel]=[dict(token=k,current_line=t[:t.index(k)].count('\n')+1,frozen_line=ft[:ft.index(k)].count('\n')+1) for k in tokens]
counts={}
for program,rel in [('canneal','cycleprecise-frozen-full-gg-external-observer-r5-20261111/canneal-observer-on'),('blackscholes','cycleprecise-frozen-full-gg-blackscholes-observed-r1-20261111')]:
 p=D/rel/'external-events.jsonl';j=D/'overnight-ec-evidence-audit-r4-20261112'/(program+'-strict-join.json');join=json.loads(j.read_text());assert sha(p)==join['evidence'][str(p)];evidence[str(p)]=sha(p);evidence[str(j)]=sha(j)
 c=collections.Counter()
 with p.open() as f:
  for line in f:c[json.loads(line)['kind']]+=1
 assert not any('SEAL' in k or 'RETIRE' in k or 'EXECUTION_DONE' in k for k in c);counts[program]=c
result=dict(status='AUDITED_LIMITED_LATENCY_BOUNDARIES_NO_FABRICATED_STRICT_METRIC',functional_baseline=BASE,fpga_access=False,source_semantics_present_in_frozen_and_integration=semantics,observed_events=counts,
 observations=[dict(level='proven',item='Rocket RESULT print is package_result_queue.enq.fire; strict join separately establishes full_compare=1, status PASS, cancelled=0'),dict(level='proven',item='Producer seal requires ROB empty/no current or delayed retirement, RSU quiet, GH_BUF drain and matching checker-owned sequence'),dict(level='proven',item='Producer seal is an existing package quiescence boundary after execution; it does not timestamp the last same-package retired instruction'),dict(level='proven',item='Current external traces capture allocation and BOOM acceptance but not producer seal or package last-retirement completion'),dict(level='unproven',item='Printed checker local CYCLE and external fastest target tick share an observed epoch/phase; no subtraction is reported')],
 available=['CHECKER_NEW_PACKAGE to validated full PASS local RESULT enqueue within one checker clock domain','ROI-stop BOOM CSR to last matching BOOM accepted result tail','SVB full identity capture to promotion to ownership/writeback ACK within fastest target timebase'],
 unavailable=['Strict Rocket-compare-done minus same-package BOOM execution-done','RESULT-local-clock to BOOM acceptance cross-domain delay','Architectural rollback/restart'],
 smallest_next_observation='External CPU observer on a future already-needed short run could record existing sequenced producer seal plus actual BOOM retirement/package ownership and checker full_check_complete/enq; establish shared target-event epoch before computing strict metric. This audit starts no new run and changes no DUT.')
(O/'result.json').write_text(json.dumps(result,sort_keys=True,indent=2)+'\n');(O/'evidence.json').write_text(json.dumps(evidence,sort_keys=True,indent=2)+'\n');(O/'complete.json').write_text(json.dumps(dict(result_sha256=sha(O/'result.json'),evidence_sha256=sha(O/'evidence.json'),analyzer_sha256=sha(__file__)),indent=2)+'\n');print(json.dumps(dict(status=result['status'],observed_events=counts),indent=2))
