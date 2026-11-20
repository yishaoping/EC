"""Verify retained application sources, inputs, traces and host references."""
from common import *
import csv
os.nice(19-os.getpriority(os.PRIO_PROCESS,0));os.sched_setaffinity(0,{200})
profiles=[];files=[]
for item in read(ROOT/'queue.json')['items']:
 mp=ROOT/item['manifest'];mf=read(mp);expected=[]
 for rel,h in mf.get('source_sha256',{}).items():expected.append(('retained_source',mp.parent/'source'/rel,h))
 inp=mf.get('input',{})
 for pathkey,hashkey in [('path','sha256'),('selected_path','selected_sha256'),('trace','trace_sha256'),('trace_path','trace_sha256'),('input_adapter_original','input_adapter_sha256')]:
  if inp.get(pathkey) and inp.get(hashkey):expected.append(('input_or_trace',Path(inp[pathkey]),inp[hashkey]))
 basedir=inp.get('dataset') or inp.get('official_test_path')
 if basedir:
  for rel,h in inp.get('files_sha256',{}).items():expected.append(('original_input',Path(basedir)/rel,h))
 ref=mf.get('host_reference',{})
 for pathkey,hashkey in [('path','sha256'),('log','log_sha256')]:
  if ref.get(pathkey) and ref.get(hashkey):expected.append(('host_reference',Path(ref[pathkey]),ref[hashkey]))
 local=[]
 for kind,p,h in expected:
  actual=sha(p) if p.is_file() else None
  row=dict(benchmark=mf['benchmark'],kind=kind,path=str(p),expected_sha256=h,actual_sha256=actual,passed=actual==h)
  local.append(row);files.append(row)
 ld=mp.parent/'htif.ld'
 profiles.append(dict(benchmark=mf['benchmark'],manifest_sha256=sha(mp),bound_file_count=len(local),passed=bool(local) and all(x['passed'] for x in local),current_linker_script=str(ld) if ld.exists() else None,current_linker_script_sha256=sha(ld) if ld.exists() else None,linker_script_original_manifest_bound=False))
save(ROOT/'audit/software-source-input-audit.json',dict(created_utc=now(),functional_baseline=BASE,passed=len(profiles)==8 and all(x['passed'] for x in profiles),profiles=profiles,files=files,limitations=['Retained files are checked against original manifest hashes; this does not prove a clean compiler rebuild is bit-identical','The root htif.ld script was not separately hashed in the original software manifests; its current retained hash is supplemental. Original linked ELF hashes remain bound per run.','Host reference execution is functional validation, not a target-cycle measurement']))
with (ROOT/'paper/software-source-input-audit.csv').open('w',newline='') as f:
 writer=csv.DictWriter(f,fieldnames=list(profiles[0]));writer.writeheader();writer.writerows(profiles)
print('Source/input/trace/reference audit:',[(x['benchmark'],x['passed'],x['bound_file_count']) for x in profiles],flush=True)
contracts={
 'blackscholes':('64 finite option prices against supplied DGrefval; abs error <1e-4','FNV hash over binary32 price bits','FNV hashes are compact fingerprints, not a collision-free full result dump'),
 'fluidanimate':('All576 finite p/hv/v values from original AdvanceParticles against actual preintegration-state host replay; abs1e-6+rel1e-5; particle count64 and all4725 grid counts','FNV hash over values rounded after scaling1e5','Original integration component only, not full frame; quantized hash plus per-value tolerance, without raw floating-point identity'),
 'bodytrack':('Finite edge/inside errors against actual captured frame0 likelihood components; abs1e-5','FNV hash of the two results rounded after scaling1e4','Component result only; quantized fingerprint is not raw floating-point identity'),
 'freqmine':('Transaction count3 and exact itemset-count histogram for lengths1..16 against independent inclusion-exclusion oracle','FNV hash over the16 integer counts','Individual itemset identities/supports are not emitted or compared'),
 'swaptions':('Finite nonnegative mean and standard error; reported checksum must equal independent host reference','FNV hash of mean/standard error rounded after scaling1e3','Only quantized reference agreement; no raw floating-point values emitted by the measured artifact'),
 'ferret':('All126 finite distance-matrix values against independent binary32 Python oracle on actual captured signature operands; abs2e-6+rel1e-6; maximum consistency','FNV hash of126 costs rounded after scaling1e5','Only original EMD distance-matrix stage, not complete EMD; quantized fingerprint is not raw floating-point identity'),
 'dedup':('Archive length/type sanity; reported full-byte archive hash must equal host; independent Python zlib host archive decode restores all6 original input bytes','FNV hash over every archive byte','Independent decompression is of host archive; target archive is checked via matching byte hash, not exported for independent target decompression'),
 'streamcluster':('Three expected center IDs and finite coordinates/weights against reference; abs1e-5+rel1e-5; total weight16','FNV hash over IDs and binary32 coordinates/weights','FNV hashes are compact fingerprints, not a collision-free full result dump')}
with (ROOT/'paper/correctness-contracts.csv').open('w',newline='') as f:
 writer=csv.DictWriter(f,fieldnames=['benchmark','per_side_validation','native_ec_reported_output_comparison','limitation','manifest']);writer.writeheader()
 for item in read(ROOT/'queue.json')['items']:
  a,b,c=contracts[item['benchmark']];writer.writerow(dict(benchmark=item['benchmark'],per_side_validation=a,native_ec_reported_output_comparison=b,limitation=c,manifest=str(ROOT/item['manifest'])))
