#!/usr/bin/python3
"""Extend accepted round16 ranking with immutable completed round17 receipts.

No live-job polls or changes to old reports. Never treat the flawed update r1
as admitted; preserve both the old summaries and real utilization reports.
"""
from pathlib import Path
import copy, datetime, hashlib, json, re

D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O=D/'build-logs/Opt4-fit-actual-module-ranking-r3-20261111'
PRIOR=D/'build-logs/Opt4-fit-actual-module-ranking-r2-20261111/result.json'

def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def parse(p):
    r={}
    for line in p.read_text().splitlines():
        m=re.match(r'^\|\s*(CLB LUTs\*?|CLB Registers|CARRY8|Block RAM Tile|DSPs|URAM)\s*\|\s*([\d,.]+)\s*\|',line)
        if m:r.setdefault(m[1].rstrip('*'),float(m[2].replace(',','')))
    assert len(r)>=5 and r['CLB LUTs']>0
    return r

def main():
    O.mkdir(exist_ok=True)
    old=json.loads(PRIOR.read_text());r=copy.deepcopy(old)
    r.update(schema='ec-opt4-all-actual-module-comparison/3',utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),prior_report=str(PRIOR),prior_report_sha256=sha(PRIOR))
    for item in r['modules']:
        assert sha(item['report'])==item['report_sha256']
        assert parse(Path(item['report']))==item['resources']
    for name,folder in [('Opt4-fit-address-update-share-r1','Opt4-fit-address-update-share-r1-20261111'),('Opt4-fit-address-tagcompress-cachefix-r3','Opt4-fit-address-tagcompress-cachefix-r3-20261111')]:
        receipt=D/'build-logs'/folder/'result.json';s=json.loads(receipt.read_text())
        assert s['status']=='VERIFIED_AND_MAPPED_MODULE_ONLY'
        m=s['full_module_map'];report=Path(m['report']);assert sha(report)==m['report_sha256']
        x=dict(name=name,hardware_commit=s['hardware_commit'],source_id=s['source_id'],status=s['status'],scope='COMPLETE_MODULE_OOC_ONLY_NOT_WHOLE_FIT',receipt=str(receipt),receipt_sha256=sha(receipt),report=str(report),report_sha256=sha(report),resources=parse(report),admissible='update-share-r1' not in name)
        if not x['admissible']:x['exclusion']='Unresolved reset/invalid-payload invariant. Preserve measured r1 area; only separately verified reset-correct r2 can be considered.'
        r['modules']=[y for y in r['modules'] if y['name']!=name]+[x]
        r['pending']=[y for y in r['pending'] if y['name']!=name]
    r['modules'].sort(key=lambda x:x['resources']['CLB LUTs'])
    reference=next(x for x in r['modules'] if x['name']=='Opt4-fit-address-bucket-tag-r3')
    for x in r['modules']:
        x['lut_delta_vs_9ae_complete_address_ooc']=x['resources']['CLB LUTs']-reference['resources']['CLB LUTs']
    best=min((x for x in r['modules'] if x['admissible']),key=lambda x:x['resources']['CLB LUTs'])
    r.update(best_completed_address=best['hardware_commit'],best_completed_address_resources=best['resources'],best_completed_address_name=best['name'],best_vs_live_9ae_lut_saving=reference['resources']['CLB LUTs']-best['resources']['CLB LUTs'],newly_completed_module_count=2,live_and_pending_states='Inherited from round16 snapshot except the two final completed receipts; no repeated live polling',decision='PRESERVE_LIVE_9AE_NO_NEW_WHOLE_FOR_675_LUT_GAIN_OR_UNRESOLVED_RESET_CANDIDATE')
    r['next_selection_requires']='Actual9ae predecessor report and controller/child exit; unconditional update-r2/other larger actual maps; independent combined proof with f2; exact report-hash selection and one broker CAD.'
    (O/'result.json').write_text(json.dumps(r,indent=2,sort_keys=True)+'\n')
    print(json.dumps(dict(report=str(O/'result.json'),completed=len(r['modules']),best=best['hardware_commit'],best_luts=best['resources']['CLB LUTs'],best_vs_9ae=r['best_vs_live_9ae_lut_saving'],excluded_r1_luts=749673)))

if __name__=='__main__':main()
