#!/usr/bin/python3
"""Read-only correction of saved utilization reports; no CAD/FPGA changes."""
from pathlib import Path
import argparse, copy, datetime, fcntl, hashlib, json, os, re, time
C=Path(__file__).resolve().parent
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
AREA=D/'build-logs/Opt4-mcrams-dcache-entry-area-r2-20261111'
O=D/'build-logs/Opt4-mcrams-dcache-entry-area-analysis-r2-20261111'
BASE='8491167d84b6d9521b151a743673c1516926a1f8'
CAPACITY={'CLB LUTs':1303680,'CLB Registers':2607360,'CARRY8':162960,'Block RAM Tile':2016,'URAM':960,'DSPs':9024}
SECTIONS={'CLB LUTs':'1. CLB Logic','CLB Registers':'1. CLB Logic','CARRY8':'1. CLB Logic','Block RAM Tile':'2. BLOCKRAM','URAM':'2. BLOCKRAM','DSPs':'3. ARITHMETIC'}
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def sha(p):
 h=hashlib.sha256()
 with Path(p).open('rb') as f:
  for b in iter(lambda:f.read(2**20),b''):h.update(b)
 return h.hexdigest()
def read(p):return json.loads(Path(p).read_text())
def save(p,x):
 p=Path(p);p.parent.mkdir(parents=True,exist_ok=True);t=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with t.open('w') as f:json.dump(x,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(t,p)
def section(text,name):
 # Match rendered section heading with underline, not table-of-contents entry.
 m=re.search(r'^'+re.escape(name)+r'\n-+\n',text,re.M)
 assert m,('section missing',name)
 end=re.search(r'^\d+(?:\.\d+)*\.?.*\n-+\n',text[m.end():],re.M)
 return text[m.end():m.end()+end.start()] if end else text[m.end():]
def table(text,key):
 rows=[];header=None
 for line in text.splitlines():
  if not line.startswith('|'):continue
  cells=[v.strip() for v in line.split('|')[1:-1]]
  if key in cells:
   assert header is None,('multiple table headers',key)
   header=cells
  elif header is not None:
   assert len(cells)==len(header),('table column count',cells,header)
   rows.append(dict(zip(header,cells)))
 assert header is not None,('table header missing',key)
 return rows
def number(s):
 assert re.fullmatch(r'[\d,]+(?:\.\d+)?',s),('invalid number',s)
 return float(s.replace(',',''))
def parse_total(text):
 assert re.search(r'^\| Design\s+: FPGATop\s*$',text,re.M)
 assert re.search(r'^\| Device\s+: xcu280fsvh2892-2L\s*$',text,re.M)
 assert re.search(r'^\| Design State\s+: Synthesized\s*$',text,re.M)
 tables={name:table(section(text,name),'Site Type') for name in set(SECTIONS.values())}
 out={}
 for label,sec in SECTIONS.items():
  matches=[r for r in tables[sec] if r['Site Type'].rstrip('*')==label]
  assert len(matches)==1,('missing or duplicate total row',label,len(matches))
  r=matches[0];assert 'Used' in r and 'Available' in r and 'Util%' in r
  used,available=number(r['Used']),number(r['Available'])
  assert available==CAPACITY[label],('wrong device capacity',label,available,CAPACITY[label])
  assert used>=0
  out[label]={'used':used,'available':available,'percent_computed':100*used/available,'reported_label':r['Site Type'],'section':sec,'source_row':r}
 return out
def parse_hier(text,totals):
 rows=table(section(text,'1. Utilization by Hierarchy'),'Instance')
 tops=[r for r in rows if r['Instance']=='FPGATop' and r['Module']=='(top)'];assert len(tops)==1
 top=tops[0]
 mapped={'CLB LUTs':number(top['Total LUTs']),'CLB Registers':number(top['FFs']),'DSPs':number(top['DSP Blocks']),'URAM':number(top['URAM']),'Block RAM Tile':number(top['RAMB36'])+number(top['RAMB18'])/2}
 for k,v in mapped.items():assert v==totals[k]['used'],('hierarchy top mismatch',k,v,totals[k]['used'])
 models=[r for r in rows if r['Module']=='RamModel' and not r['Instance'].startswith('(')]
 owners=[r for r in rows if r['Module']=='ownerImageMemory' and not r['Instance'].startswith('(')]
 return {'top':top,'validated_resources':mapped,'ram_model_instances':models,'owner_memory_instances':owners}
def crosschecks(text,totals):
 rows=table(section(text,'8. Primitives'),'Ref Name');carry=[r for r in rows if r['Ref Name']=='CARRY8']
 assert len(carry)==1 and number(carry[0]['Used'])==totals['CARRY8']['used'],'CARRY8 primitive mismatch'
 boxes=table(section(text,'9. Black Boxes'),'Ref Name');assert not boxes,('unresolved black boxes',boxes)
 return {'CARRY8_primitive_total':number(carry[0]['Used']),'blackboxes':0}
def rejected(fn):
 try:fn()
 except (AssertionError,KeyError):return True
 raise AssertionError('invalid report mutation accepted')
def test_parser(text,hier):
 total=parse_total(text);check=parse_hier(hier,total);crosschecks(text,total)
 expected=total['CLB LUTs']['used'];assert expected>0
 line=next(l for l in text.splitlines() if '| CLB LUTs*' in l)
 tests={}
 tests['actual_starred_total_positive']=expected
 unstarred=text.replace(line,line.replace('CLB LUTs*','CLB LUTs '));assert parse_total(unstarred)['CLB LUTs']['used']==expected;tests['unstarred_total_supported']=True
 tests['missing_total_does_not_read_SLR_zero']=rejected(lambda:parse_total(text.replace(line,line.replace('CLB LUTs*','CLB LUTx*'))))
 tests['duplicate_total_rejected']=rejected(lambda:parse_total(text.replace(line,line+'\n'+line)))
 tests['wrong_capacity_rejected']=rejected(lambda:parse_total(text.replace(line,line.replace('1303680','1303679'))))
 slr=section(text,'13. SLR CLB Logic and Dedicated Block Utilization');mutated=slr.replace('|    0 |','|  999 |')
 assert parse_total(text.replace(slr,mutated))['CLB LUTs']['used']==expected;tests['SLR_numbers_do_not_affect_total']=True
 bad=copy.deepcopy(total);bad['CLB LUTs']['used']+=1;tests['hierarchy_disagreement_rejected']=rejected(lambda:parse_hier(hier,bad))
 bad=copy.deepcopy(total);bad['CARRY8']['used']+=1;tests['CARRY8_primitive_disagreement_rejected']=rejected(lambda:crosschecks(text,bad))
 tests['actual_hierarchy_top_agrees']=check['validated_resources']
 return tests

def analyze_config(config):
 receipt=AREA/'receipts'/('area-'+config+'.json')
 if not receipt.exists():return None
 r=read(receipt);assert r['returncode']==0 and r['stage']=='area-'+config
 assert all(Path(p).is_file() and sha(p)==h for p,h in r['outputs'].items()),'completed area output changed'
 assert sha(r['log'])==r['log_sha256'] and 'EC_ENTRY_AREA_ZERO_BLACKBOX_PASS' in Path(r['log']).read_text()
 u=AREA/config/'utilization.rpt';h=AREA/config/'hierarchical.rpt'
 text=u.read_text();hier=h.read_text();totals=parse_total(text);details=parse_hier(hier,totals);extra=crosschecks(text,totals)
 if config=='MCConfig':
  assert len(details['ram_model_instances'])==1 and len(details['owner_memory_instances'])==1
  row=details['ram_model_instances'][0];assert number(row['Total LUTs'])>0 and number(row['RAMB36'])+number(row['RAMB18'])>0,'RAM model is absent or dead'
 proof=read(D/'build-logs/Opt4-mcrams-dcache-entry-r5-20261111/result.json')
 assert sha(AREA/config/'host.sv')==proof['results'][config]['host_rtl_sha256']
 return {'resources':totals,'hierarchical':details,'crosschecks':extra,'receipt':str(receipt),'receipt_sha256':sha(receipt),'report':str(u),'report_sha256':sha(u),'hierarchical_report':str(h),'hierarchical_sha256':sha(h),'host_rtl_sha256':sha(AREA/config/'host.sv'),'checkpoint_sha256':sha(AREA/config/'module.dcp'),'stage_wall_seconds':r['host_wall_seconds']}

def publish():
 # Completed scientific evidence is immutable. Timer invocations validate and
 # reuse the exact result, never regenerate utc or overwrite result/complete.
 result_path=O/'result.json';complete_path=O/'complete.json'
 if result_path.exists() or complete_path.exists():
  assert result_path.exists() and complete_path.exists(),'partial commit retained; recovery required'
  complete=read(complete_path);result=read(result_path)
  assert sha(result_path)==complete['result_sha256'],'completed result changed'
  assert sha(__file__)==complete['parser_source_sha256'],'parser version mismatch'
  for config,item in result['results'].items():
   current=analyze_config(config)
   assert current==item,'completed source evidence/version changed'
  save(O/'monitor-state.json',{'status':'IMMUTABLE_COMPLETE_REVALIDATED','checked_utc':now(),'pid':os.getpid(),'result_sha256':complete['result_sha256']})
  return result
 results={};tests={}
 for config in ['MCConfig','PlainConfig']:
  r=analyze_config(config)
  if r is not None:
   results[config]=r;tests[config]=test_parser(Path(r['report']).read_text(),Path(r['hierarchical_report']).read_text())
 complete=len(results)==2
 result={'schema':'ec-immutable-corrected-real-entry-utilization/2','status':'CORRECTED_AREA_COMPLETE_NOT_FULL_DCACHE_OR_OPT4_FIT' if complete else 'CORRECTED_PARTIAL_AREA_WAITING_PLAIN_RECEIPT','utc':now(),'functional_baseline':BASE,'derived_hardware':'3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c','fpga_access':False,'production_admission':False,'whole_fit':False,'full_dut_equivalence':False,'scope':'Isolated real ownerImageMemory host-entry with written-mask/reset,35read ports,35captures and PeekPoke; not complete DCache or Opt4','parser_source_sha256':sha(__file__),'parser_tests':tests,'results':results,'original_controller_changed':False,'original_state_retained':str(O/'original-buggy-state.json'),'error_correction':'r2 regex missed CLB LUTs* total and incorrectly matched zero SLR row; original reported0LUT is invalid; corrected parser selects only total sections with Used/Available and crosschecks hierarchy/primitive counts.'}
 if complete:
  before=results['PlainConfig']['resources'];after=results['MCConfig']['resources'];result['resource_savings']={k:before[k]['used']-after[k]['used'] for k in CAPACITY};result['LUT_reduction_percent']=100*result['resource_savings']['CLB LUTs']/before['CLB LUTs']['used']
  save(O/'result.json',result);save(O/'complete.json',{'result_sha256':sha(O/'result.json'),'parser_source_sha256':sha(__file__)})
 else:save(O/'partial-result.json',result)
 save(O/'state.json',{'status':result['status'],'pid':os.getpid(),'updated_utc':now(),'results_available':list(results),'boot_id':Path('/proc/sys/kernel/random/boot_id').read_text().strip()})
 return result

def main():
 ap=argparse.ArgumentParser();ap.add_argument('--watch',action='store_true');args=ap.parse_args()
 O.mkdir(exist_ok=True);lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
 original=O/'original-buggy-state.json'
 if not original.exists():
  p=D/'Opt4-mcrams-dcache-entry-area-r2-state.json';original.write_bytes(p.read_bytes());save(O/'original-buggy-state-receipt.json',{'source':str(p),'snapshot_sha256':sha(original),'captured_utc':now(),'error':'CLB LUTs0 is invalid; snapshot only, original live state left untouched.'})
 while True:
  r=publish();print(json.dumps({'status':r['status'],'results':{k:{n:v['used'] for n,v in m['resources'].items()} for k,m in r['results'].items()}}),flush=True)
  if len(r['results'])==2 or not args.watch:return
  time.sleep(300)
if __name__=='__main__':main()
