"""Independent CSV arithmetic and release consistency checks (no simulations)."""
from common import *
import csv,decimal,math

paper=ROOT/'paper';summary=read(paper/'summary.json')
def csvrows(name):
 with (paper/name).open(newline='') as f:return list(csv.DictReader(f))
rows=csvrows('parsec8-native-ec.csv');plots=csvrows('plot-data.csv')
names={x['benchmark'] for x in read(ROOT/'queue.json')['items']}
checks={'exact_eight_unique_rows':len(rows)==len(names)==8 and {x['benchmark'] for x in rows}==names,
        'full_application_geomean_absent':summary['full_application_geomean_slowdown'] is None}
ratios=[];details=[]
with decimal.localcontext() as ctx:
 ctx.prec=50
 for row in rows:
  name=row['benchmark'];checks[name+'_summary_row']=next(x for x in summary['per_benchmark'] if x['benchmark']==name)['status']==row['status']
  plot=next(x for x in plots if x['benchmark']==name)
  checks[name+'_plot_values']=all(plot[k]==row[k] for k in plot)
  checks[name+'_missing_latency_endpoints']=row['strict_detection_latency_cycles']==row['full_rollback_latency_cycles']==''
  if row['status']!='VALID_CPU_GG_PAIR':
   checks[name+'_pending_ratio_empty']=row['slowdown']=='';continue
  nr=Path(row['native_evidence']);er=Path(row['ec_evidence']);n=read(nr);e=read(er);mp=Path(row['manifest']);mf=read(mp)
  nc,ec=int(row['native_cycles']),int(row['ec_cycles']);ratio=decimal.Decimal(ec)/decimal.Decimal(nc);ratios.append(ratio)
  good=n['valid'] and e['valid'] and n['mode']=='native' and e['mode']=='ec'
  good=good and n['benchmark']==e['benchmark']==name and n['profile']==e['profile']==row['profile']==mf['profile']
  good=good and n['functional_baseline']==e['functional_baseline']==mf['functional_baseline']==BASE
  good=good and n['manifest_sha256']==e['manifest_sha256']==row['manifest_sha256']==sha(mp)
  good=good and nc==n['roi_end_csr']-n['roi_start_csr']==n['roi_cycles'] and ec==e['roi_end_csr']-e['roi_start_csr']==e['roi_cycles']
  good=good and int(row['instructions_native'])==int(row['instructions_ec'])==n['roi_instructions']==e['roi_instructions'] and n['output']==e['output']
  good=good and math.isclose(float(row['slowdown']),float(ratio),rel_tol=1e-14)
  strict=read(er.parent/'strict-acceptance.json')
  good=good and strict['passed'] and strict['allocations']==strict['local_begins']==strict['full_compare_local_results']==strict['boom_pass_accepted']>0
  good=good and all(strict[x]==0 for x in ['pending','fail','cancel','duplicate','sample_errors'])
  events=[json.loads(s) for s in (er.parent/'external-events.jsonl').read_text().splitlines()]
  accepts=[x for x in events if x['kind']=='BOOM_RESULT_ACCEPTED']
  tail=max(0,max(x['boom_csr_cycle'] for x in accepts)-e['roi_end_csr'])
  good=good and tail==e['drain_cycles']==int(row['checker_acceptance_tail_boom_cycles'])
  good=good and row['measurement_engine']=='CPU_GG_CYCLE_EXACT' and all(x['status']==0 for x in accepts)
  for rp,r in [(nr,n),(er,e)]:
   raw=read(rp.parent/'raw-audit.json');good=good and raw['passed'] and raw['result_sha256']==sha(rp)
  checks[name+'_accepted_evidence_and_arithmetic']=bool(good)
  details.append(dict(benchmark=name,ratio_decimal=str(ratio),native_result_sha256=sha(nr),ec_result_sha256=sha(er),tail_cycles=tail))
 product=decimal.Decimal(1)
 for ratio in ratios:product*=ratio
 gm=product**(decimal.Decimal(1)/8) if len(ratios)==8 else None
 checks['complete_geomean_or_null']=math.isclose(float(gm),summary['requested_eight_geomean_slowdown'],rel_tol=1e-14) if gm is not None else summary['requested_eight_geomean_slowdown'] is None
 checks['count_matches']=len(ratios)==summary['valid_pair_count']
 checks['mixed_scope_label']=gm is None or summary['geomean_status']=='COMPLETE_DECLARED_PROFILE_GEOMEAN_MIXED_SCOPES'
 samples=csvrows('samples.csv');repeats=csvrows('repeatability.csv')
 for rr in repeats:
  accepted=[s for s in samples if s['benchmark']==rr['benchmark'] and s['status']=='VALID_CPU_GG_PAIR']
  checks[rr['benchmark']+'_repeat_count']=int(rr['paired_n'])==len(accepted)
 out=dict(schema='parsec8-independent-release-consistency/1',created_utc=now(),release_complete=len(ratios)==8,accepted_profile_count=len(ratios),consistency_checks_passed=all(checks.values()),checks=checks,independently_computed_decimal_geomean=str(gm) if gm is not None else None,summary_sha256=sha(paper/'summary.json'),primary_csv_sha256=sha(paper/'parsec8-native-ec.csv'),plot_data_sha256=sha(paper/'plot-data.csv'),details=details,limits=['Checks retained result/audit/event artifacts and exported arithmetic; does not independently prove hardware model fidelity or workload representativeness','Raw decompression/hash re-parsing is provided separately by audit_complete.py; no new simulation or hardware action'])
 save(paper/'release-verification.json',out)
 assert out['consistency_checks_passed'],[k for k,v in checks.items() if not v]
 print('Independent release checks PASS; accepted profiles:',len(ratios),flush=True)
