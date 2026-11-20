#!/usr/bin/env python3
"""One measured, region-specific fallback after the existing physical jobs finish."""
import datetime as dt
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import subprocess
import time

C=Path(__file__).resolve().parent
inputs=json.loads((C/'inputs.json').read_text())
P=Path(inputs['output_dir'])
O=P/'targeted-remap-r4'
UNIT='ec-performance-only-routability-r3-20261114.service'

def save(status,**kw):
    p=O/'state.tmp';p.write_text(json.dumps(dict(status=status,utc=dt.datetime.now(dt.timezone.utc).isoformat(),
        model_requests=False,fpga_access=False,profile='Performance-Only',**kw),indent=2)+'\n')
    os.replace(p,O/'state.json')

def main():
    os.sched_setaffinity(0,set(range(240,248)))
    O.mkdir(exist_ok=False)
    save('WAITING_EXISTING_PHYSICAL_CANDIDATES_NO_RESTART')
    while subprocess.check_output(['systemctl','--user','show',UNIT,'-p','ActiveState','--value'],text=True).strip() in ['active','activating']:
        time.sleep(30)
    parent=json.loads((P/'state.json').read_text())
    candidates=parent.get('candidates',[])
    if any(r.get('routing',{}).get('legal') for r in candidates):
        save('LEGAL_ROUTE_ALREADY_EXISTS_NO_EXTRA_PLACEMENT',next_action='Use the legal checkpoint for constraint/timing and certification recovery',parent_status=parent['status']);return
    congestion=any(r.get('placed_congestion_level',0)>=8 or
        r.get('routing',{}).get('conflicts',0) for r in candidates)
    if not congestion:
        save('NO_MEASURED_CONGESTION_FAILURE_TO_JUSTIFY_EXTRA_PLACEMENT',parent_status=parent['status']);return
    spec=importlib.util.spec_from_file_location('physical_recovery',C/'campaign.py')
    m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
    m.O=O
    m.ST.update(started_utc=m.now(),status='STARTING_TARGETED_REMAP',candidates=[],
        continuation_parent=str(P/'state.json'),inherited_parent_status=parent['status'])
    (O/'candidates').mkdir();(O/'tmp').mkdir()
    cp=inputs['checkpoints']['design_1_wrapper_placed.dcp']
    assert m.digest(cp['path'])==cp['sha256']
    # The previous whole-netlist remap measured 95.27% LUT use. Restrict this
    # fallback to the actual CDC/SVB hotspots while preserving all other MUXFs.
    transform=r'''
set all_mux [get_cells -hier -quiet -filter {REF_NAME =~ MUXF*}]
set hot_mux [get_cells -hier -quiet -filter {REF_NAME =~ MUXF* && (NAME =~ *ghm_u_data_cdc* || NAME =~ */dcache/svb/*)}]
if {[llength $hot_mux] < 1000} {error "hotspot MUXF match unexpectedly small; refuse broad remap"}
set restore [dict create]
set keep [dict create]
foreach c $hot_mux {dict set keep $c 1}
foreach c $all_mux {
    if {![dict exists $keep $c]} {
        dict set restore $c [get_property DONT_TOUCH $c]
        set_property DONT_TOUCH true $c
    }
}
set f [open "$out/muxf-scope.txt" w]
puts $f "all_mux=[llength $all_mux] hot_mux=[llength $hot_mux] protected_other_mux=[dict size $restore]"
close $f
stage muxf_remap {opt_design -muxf_remap}
dict for {name value} $restore {
    set c [get_cells -quiet $name]
    if {[llength $c]!=1} {error "protected MUXF disappeared: $name"}
    set_property DONT_TOUCH $value $c
}
'''
    code=m.physical_code(cp['path'],'AltSpreadLogic_high')
    assert code.count('stage muxf_remap {opt_design -muxf_remap}')==1
    code=code.replace('stage muxf_remap {opt_design -muxf_remap}',transform)
    m.save(O/'decision.json',dict(parent_status=parent['status'],prior_candidates=candidates,
        reason='Whole-netlist remap measured 1242046 LUT. Restrict remapping to measured Level8 GHM data queues and Level6 SVB, leaving other packing intact.',
        source_checkpoint=cp,rtl_changed=False,target_cycle_changed=False))
    result=m.run('cdc-svb-only-remap',code)
    legal=result.get('routing',{}).get('legal',False)
    m.update('BITSTREAM_GENERATED_RUNTIME_CERTIFICATION_PENDING' if legal and result['bitstream_generated'] else
        'LEGAL_ROUTING_TIMING_OR_CONSTRAINT_RECOVERY_REQUIRED' if legal else
        'TARGETED_PHYSICAL_SCREEN_COMPLETE_RTL_RESTRUCTURING_REQUIRED',child_pid=None)

if __name__=='__main__':
    try:main()
    except Exception as e:
        if O.is_dir():save('FAILED_WITH_EVIDENCE',error=repr(e))
        raise
