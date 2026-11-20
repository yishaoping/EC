#!/usr/bin/python3
"""Bounded short foreground arithmetic-model proof; no compile/map/job control."""
from pathlib import Path
import hashlib,json,subprocess,time
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');C=Path(__file__).resolve().parent;F=W/'Opt4-fit-address-update-share-r2-20261111';O=D/'build-logs/Opt4-fit-address-update-share-r2-20261111/independent-short-proof';O.mkdir(exist_ok=True)
proof=C/'allstate-proof.v';prefix=f'read_verilog {proof}; prep -top AllStateUpdateProof -flatten; '
cases=[('unconditional',prefix+'sat -verify -prove equivalent 1 -prove global_reset_equivalent 1 -prove allocation_equivalent 1 -timeout 5',False),('negative-invalid-zero-mutation',prefix+'sat -verify -set global_reset 1 -set current 1 -set event_commit 1 -set reset_stats 0 -prove mutant_equivalent 1 -show-inputs -timeout 5',True)]
results=[]
for label,script,negative in cases:
 log=O/(label+'.log');assert not log.exists()
 args=['/usr/local/bin/yosys','-Q','-T','-p',script];start=time.monotonic()
 with log.open('xb') as f:r=subprocess.run(args,stdout=f,stderr=subprocess.STDOUT,timeout=15)
 text=log.read_text();assert 'timed out' not in text
 assert ('proof did fail' in text and r.returncode!=0) if negative else ('SUCCESS' in text and r.returncode==0)
 results.append(dict(label=label,argv=args,returncode=r.returncode,accepted=True,negative=negative,wall_seconds=time.monotonic()-start,log=str(log),log_sha256=hashlib.sha256(log.read_bytes()).hexdigest()))
paths=[Path(__file__),proof,C/'review.py',F/'candidate-binding.json',F/'chipyard/generators/boom/src/main/scala/lsu/PackageAddressStats.scala',F/'chipyard/generators/boom/src/main/scala/lsu/AddressBucketUpdate.scala']
report=dict(schema='ec-opt4-independent-allstate-arithmetic-proof/1',status='PASS_UNCONDITIONAL_64BIT_MODEL_AND_REJECTED_GLOBAL_RESET_MUTATION',hardware_commit='00847dc2b8f6be3f1e1ff0639c1104d33334ddc9',source_id='6b0de8636ec9d88f7d9702769c03325df78ab43c3c1fe527fff9dc1a3aafbbdb',inputs={str(p):hashlib.sha256(p.read_bytes()).hexdigest() for p in paths},results=results,scope='All 64-bit counter/delta values and boolean valid/current/event/retire/statistics-reset/global-reset choices in the independent scalar model; source confinement review binds the arithmetic relation to the only changed production block.',limits='This short proof uses a hand-written Verilog arithmetic model. Generated-Chisel proof, 256-slot boundary test, complete-module reset stress comparison and OOC map remain deferred in the exact broker job. It is not full-DUT formal equivalence.',fpga_access=False)
(O/'result.json').write_text(json.dumps(report,indent=2,sort_keys=True)+'\n');print(json.dumps({k:report[k] for k in ['status','hardware_commit','source_id','limits']}));print('proof_wall_seconds',sum(r['wall_seconds'] for r in results))
