#!/usr/bin/python3
"""Read complete-module receipts and first utilization rows; never promote."""
from pathlib import Path
import datetime, hashlib, json, os, re

D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
O = D/'build-logs/Opt4-fit-actual-module-ranking-r2-20261111'

def sha(p): return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def parse(text):
    values = {}
    for line in text.splitlines():
        m = re.match(r'^\|\s*(CLB LUTs\*?|CLB Registers|CARRY8|Block RAM Tile|DSPs|URAM)\s*\|\s*([\d,.]+)\s*\|',line)
        if m: values.setdefault(m[1].rstrip('*'),float(m[2].replace(',','')))
    assert set(values) >= {'CLB LUTs','CLB Registers','CARRY8','Block RAM Tile','DSPs'}
    assert values['CLB LUTs'] > 0
    return values
def save(p, value):
    q = p.with_name(p.name+'.tmp-'+str(os.getpid()))
    q.write_text(json.dumps(value,indent=2,sort_keys=True)+'\n'); os.replace(q,p)

def main():
    O.mkdir(exist_ok=True)
    modules, pending, failed = [], [], []
    for p in sorted(D.glob('Opt4-fit-*-state.json')):
        if not any(n in p.name for n in ['address-','retire-read','dcache-result-memory']): continue
        state = json.loads(p.read_text()); name = p.name.removesuffix('-state.json')
        item = dict(name=name,state=str(p),state_sha256=sha(p),
                    hardware_commit=state.get('hardware_commit'),source_id=state.get('source_id'),
                    status=state.get('status'),scope='COMPLETE_MODULE_OOC_ONLY_NOT_WHOLE_FIT')
        receipt = state.get('full_module_map',state.get('full_address_map',{}))
        if not receipt and name == 'Opt4-fit-address-heap-candidate' and state.get('resources'):
            receipt = dict(report=str(D/'build-logs/Opt4-fit-address-heap-candidate-c41d42f-20261110/map/utilization.rpt'))
        report = Path(receipt.get('report','/nonexistent'))
        if report.is_file():
            item.update(report=str(report),report_sha256=sha(report),resources=parse(report.read_text()))
            if receipt.get('report_sha256'): assert receipt['report_sha256'] == item['report_sha256']
            if receipt.get('resources') and receipt['resources'] != {k:v for k,v in item['resources'].items() if k!='URAM'}:
                item['original_summary_parser_mismatch'] = receipt['resources']
                item['correction'] = 'First actual summary row including starred LUT row; ignore later SLR zero rows. Original receipt unchanged.'
            if 'update-share-r1' in name:
                item['admissible'] = False
                item['exclusion'] = 'Unresolved reset/valid-payload invariant; r2 is the isolated correction. Measured r1 area cannot justify promotion.'
            else:
                item['admissible'] = state.get('status','').startswith('VERIFIED_AND_MAPPED')
            modules.append(item)
        elif state.get('status') == 'FAILED_WITH_EVIDENCE':
            item.update(error=state.get('error'),admissible=False); failed.append(item)
        elif state.get('hardware_commit'):
            item['admissible'] = False; item['reason'] = 'No completed complete-module map receipt'
            pending.append(item)
    modules.sort(key=lambda x:x['resources']['CLB LUTs'])
    reference = next(x for x in modules if x['name']=='Opt4-fit-address-bucket-tag-r3')
    for x in modules:
        x['lut_delta_vs_9ae_complete_address_ooc'] = x['resources']['CLB LUTs']-reference['resources']['CLB LUTs']
        if x['name'] != reference['name'] and x['lut_delta_vs_9ae_complete_address_ooc'] >= 0:
            x['selection_reason'] = 'Inferior complete-address LUT count to already-live 9ae; no speculative whole-DUT subtraction'
    predecessor = D/'build-logs/Opt4-fit-cad-8da24a26/top-postopt-utilization.rpt'
    whole = dict(hardware_commit='8da24a269b98a0d6a8f57b030353a310812c4344',
                 report=str(predecessor),report_sha256=sha(predecessor),resources=parse(predecessor.read_text()),
                 status='NOT_FIT_POSTOPT',available_luts=1303680)
    whole['lut_excess'] = whole['resources']['CLB LUTs']-whole['available_luts']
    output = dict(schema='ec-opt4-all-actual-module-comparison/2',
                  utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
                  modules=modules,pending=pending,failed=failed,last_completed_whole_report=whole,
                  live_predecessor_commit='9ae9a7fcf231a75259e23973b12a93896a443cbb',
                  decision='NO_NEW_WHOLE_CAD_WHILE_9AE_LIVE_OR_FOR_SELECTOR_GAIN_ALONE',
                  best_completed_address=reference['hardware_commit'],
                  next_selection_requires='9ae actual predecessor postopt report, controller and child exit, all larger verified module maps, f2 combined source-bound proof, hash-bound selection and exactly one broker CAD request',
                  full_dut_formal=False,fpga_access=False)
    save(O/'result.json',output)
    print(json.dumps(dict(report=str(O/'result.json'),completed=len(modules),pending=len(pending),
                          best_completed_address=reference['hardware_commit'],whole_lut_excess=whole['lut_excess'])))

if __name__ == '__main__': main()
