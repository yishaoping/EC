"""Retain immutable first-eight and completed three-repeat paper releases."""
from common import *
import shutil

summary=read(ROOT/'paper/summary.json')
if summary['valid_pair_count']!=8:raise SystemExit(0)
complete_repeats=all(x['paired_n']==3 for x in summary['repeatability']) and len(summary['repeatability'])==8
for label in ['first-eight-accepted']+(['three-paired-repeats-accepted'] if complete_repeats else []):
 marker=ROOT/'batches'/(label+'.json')
 if marker.exists():continue
 stamp=datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
 dest=ROOT/'batches'/(label+'-'+stamp)
 dest.mkdir(parents=True,exist_ok=False)
 shutil.copytree(ROOT/'paper',dest/'paper')
 shutil.copytree(ROOT/'scripts',dest/'scripts',ignore=shutil.ignore_patterns('__pycache__'))
 shutil.copy2(ROOT/'queue.json',dest/'queue.json')
 shutil.copy2(ROOT/'execution-policy.json',dest/'execution-policy.json')
 if (ROOT/'diagnostics').exists():shutil.copytree(ROOT/'diagnostics',dest/'diagnostics')
 evidence={}
 for item in read(ROOT/'queue.json')['items']:
  mp=ROOT/item['manifest'];mf=read(mp)
  shutil.copy2(mp,dest/(mf['benchmark']+'-manifest.json'))
  for name in ['capture-receipt.json','independent-reference.json']:
   if (mp.parent/name).exists():shutil.copy2(mp.parent/name,dest/(mf['benchmark']+'-'+name))
  if (mp.parent/'htif.ld').exists():shutil.copy2(mp.parent/'htif.ld',dest/(mf['benchmark']+'-current-htif.ld'))
  for mode in ['native','ec']:
   for repeat in range(1,4):
    result,rp=selected_result(mf,mode,repeat)
    if not result or not result.get('valid') or not (rp.parent/'complete.json').exists():continue
    out=dest/'run-receipts'/rp.parent.name;out.mkdir(parents=True)
    for name in ['binding.json','result.json','complete.json','stdout-integrity.json','raw-audit.json','strict-acceptance.json','svb-metrics.json','checker-local-metrics.json','external-stop-reason.json']:
     if (rp.parent/name).exists():shutil.copy2(rp.parent/name,out/name)
    evidence[str(rp.parent/'host-complete.log.gz')]=dict(raw_sha256=result['raw_log_sha256'],gzip_sha256=read(rp.parent/'stdout-integrity.json')['gzip_sha256'])
 for name in ['existing-data-audit.json','platform-audit.json','abi-audit.json','software-source-input-audit.json','roi-io-and-instruction-preflight.json','historical-native-fpga-audit.json','completed-raw-audit.json','checker-parser-negative-validation.json','fluid-advance-binary32-oracle.json','fluid-advance-functional.json','fluid-advance-norelax-functional.json','ferret-costmatrix-functional.json','dedup-buffer16-preloaded-functional.json']:
  shutil.copy2(ROOT/'audit'/name,dest/name)
 hashes={str(p.relative_to(dest)):sha(p) for p in sorted(dest.rglob('*')) if p.is_file()}
 receipt=dict(schema='parsec8-immutable-release/1',created_utc=now(),release=label,functional_baseline=BASE,accepted_pairs=8,all_eight_declared_profile_geomean=summary['requested_eight_geomean_slowdown'],full_application_geomean=None,files_sha256=hashes,original_raw_log_sources=evidence,limitation='Snapshot copies paper, scripts and bound receipts; full raw logs remain at the recorded original paths. Declared profiles do not establish full PARSEC performance.')
 save(dest/'snapshot-receipt.json',receipt)
 save(marker,dict(snapshot=str(dest),receipt_sha256=sha(dest/'snapshot-receipt.json'),created_utc=now()))
 print('Immutable release:',dest,flush=True)
