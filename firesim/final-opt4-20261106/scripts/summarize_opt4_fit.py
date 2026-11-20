#!/usr/bin/env python3
"""Publish only completed module evidence; never control builds or FPGA."""
from pathlib import Path
import datetime,json,os
from board_batch import W,D,save,sha
F=W/'Opt4-fit-20261110';O=D/'build-logs/Opt4-fit-modules-20261110'
def read(p):return json.loads(p.read_text()) if p.exists() else {}
def resources(path):
 rows={}
 if not path.exists():return rows
 for l in path.read_text().splitlines():
  f=[x.strip().replace(',','') for x in l.split('|')]
  if len(f)<7 or f[1].rstrip('*') not in ['CLB LUTs','CLB Registers','CARRY8','DSPs','Block RAM Tile']:continue
  try:
   if float(f[5])>0:rows.setdefault(f[1].rstrip('*'),float(f[2]))
  except ValueError:pass
 return rows
def main():
 binding=read(F/'candidate-binding.json');mods=read(D/'Opt4-fit-modules-state.json');mapping=read(D/'Opt4-fit-mapping-state.json');ver=read(D/'Opt4-fit-verification-state.json');scanner=read(D/'Opt4-fit-scanner-state.json');round2=read(D/'Opt4-fit-round2-state.json')
 results={}
 for key,r in mapping.get('modules',{}).items():
  if r.get('status')!='MAPPED_MODULE_ONLY' or r.get('returncode')!=0:continue
  p=Path(r['out'])/'utilization.rpt'
  results[key]=dict(resources=resources(p),report=str(p),report_sha256=sha(p),fit_commit=r.get('fit_commit'),scope='Matched OOC module, RuntimeOptimized directive; no full-DUT fit/timing claim',source_sha256=r.get('source_sha256'),rtl_sha256=r.get('rtl_sha256'))
 for variant,r in scanner.get('modules',{}).items():
  if r.get('status')!='MAPPED_MODULE_ONLY' or r.get('returncode')!=0:continue
  p=O/'scanner'/variant/'utilization.rpt';results[variant+'-scanner']=dict(resources=resources(p),report=str(p),report_sha256=sha(p),fit_commit=scanner.get('fit_commit'),scope='Exact scanner module only, not full design')
 for kind,r in round2.get('modules',{}).items():
  if r.get('status')!='MAPPED_MODULE_ONLY' or r.get('returncode')!=0:continue
  p=O/'round2'/kind/'utilization.rpt'
  results['round2-'+kind]=dict(resources=resources(p),report=str(p),report_sha256=sha(p),fit_commit=r.get('fit_commit'),scope='Pinned second optimization module only; not full design',source_sha256=r.get('source_sha256'),rtl_sha256=r.get('rtl_sha256'),verification=r.get('verification'))
 comparison={}
 for name in ['barrier','address','scanner']:
  a,b=results.get('baseline-'+name),results.get('fit-'+name)
  if a and b:comparison[name]={k:dict(before=a['resources'][k],after=b['resources'][k],delta=b['resources'][k]-a['resources'][k],reduction_percent=100*(a['resources'][k]-b['resources'][k])/a['resources'][k] if a['resources'][k] else None) for k in a['resources'].keys()&b['resources'].keys()}
 for name in ['barrier','scanner']:
  a,b=results.get('fit-'+name),results.get('round2-'+name)
  if a and b:comparison['round2-vs-first-fit-'+name]={k:dict(before=a['resources'][k],after=b['resources'][k],delta=b['resources'][k]-a['resources'][k],reduction_percent=100*(a['resources'][k]-b['resources'][k])/a['resources'][k] if a['resources'][k] else None) for k in a['resources'].keys()&b['resources'].keys()}
 priority=read(D/'Opt4-fit-priority-proof-state.json')
 address_verilator=read(D/'Opt4-fit-address-verilator-state.json')
 integration_compile=read(D/'Opt4-fit-integration-compile-state.json')
 rtl=read(D/'Opt4-fit-rtl-state.json');cad=read(D/'Opt4-fit-cad-state.json')
 address3=read(D/'Opt4-fit-address-round3-state.json')
 probes4=read(D/'Opt4-fit-address-probes4-state.json')
 runtime_preparation=read(W/'runtime/Opt4-fit-8da24a26/software-suite.json')
 runtime_state=read(D/'Opt4-fit-runtime-state.json')
 heap_proof=read(D/'Opt4-fit-address-heap-proof-state.json')
 heap_candidate=read(D/'Opt4-fit-address-heap-candidate-state.json')
 address_attribution=read(D/'Opt4-fit-address-attribution-state.json')
 address_sort=read(D/'Opt4-fit-address-sort-state.json')
 native_pause=read(D/'Native-user-paused.json')
 summary=dict(schema='ec-opt4-fit-summary/1',updated_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),binding=binding,original_optimized_dut=dict(verdict='NOT_FIT',luts=5741353,carry8=366817,dsp=9024,lut_capacity=1303680,carry8_capacity=162960,lut_excess=4437673,carry8_excess=203857),full_fit_verdict='NOT_YET_ESTABLISHED_FOR_OPT4_FIT',module_results=results,comparison=comparison,elaboration_status=mods.get('status'),mapping_status=mapping.get('status'),verification=ver,scanner=scanner,round2=round2,priority_proof=priority,full_dut_build_started=False,formal_admission=False,fpga_access=False,parse_note='Use authoritative positive Available device rows, never the repeated per-SLR zero rows. Do not add disjoint OOC results to infer full-DUT size because DSP allocation and cross-hierarchy optimization differ.')
 summary.update(address_verilator=address_verilator,integration_compile=integration_compile,
  whole_system_rtl={k:rtl.get(k) for k in ['status','hardware_commit','source_id','elaboration_dir','goldengate_dir','configuration_matches_frozen_parameters','modified_class_origins_verified','ended_utc']},
  whole_system_cad={k:cad.get(k) for k in ['status','hardware_commit','source_id','current_stage','pid','start_ticks','child_pid','child_start_ticks','updated_utc','error','dut_resources','top_postopt_resources','bitstream']},
  full_dut_build_started=bool(cad.get('stages',{}).get('dut_synth')),
  independent_address_round3=address3,independent_address_probes4=probes4,
  derived_runtime_preparation=runtime_preparation,derived_runtime=runtime_state,
  independent_heap_certificate=heap_proof,independent_heap_candidate=heap_candidate,
  address_mapped_name_attribution=address_attribution,
  independent_shared_scatter_candidate=address_sort,native_user_pause=native_pause)
 if cad.get('status')=='NOT_FIT_POSTOPT':summary['full_fit_verdict']='NOT_FIT_POSTOPT'
 elif cad.get('certified_bitstream'):summary['full_fit_verdict']='CAPACITY_TIMING_DRC_PASSED_RUNTIME_PENDING'
 save(O/'FIT_STATUS.json',summary)
 lines=['# Opt4-fit module optimization status','',summary['updated_utc'],'',f"Independent branch: `{F}` / `opt4-fit/20261110`. Original frozen hardware remains unchanged. Full Opt4-fit capacity/timing: **NOT YET ESTABLISHED**.",'','Original DUT after opt_design: 5,741,353 LUT (440.40%), 366,817 CARRY8 (225.10%), 9,024 DSP (100%). Remaining excess over U280: 4,437,673 LUT and 203,857 CARRY8. This is not an estimate of candidate size.','','| Module / variant | LUT | CARRY8 | DSP | FF |','|---|---:|---:|---:|---:|']
 for key,r in sorted(results.items()):
  lines.append('| '+key+' | '+' | '.join(f"{r['resources'].get(k,0):,.0f}" for k in ['CLB LUTs','CARRY8','DSPs','CLB Registers'])+' |')
 lines+=['','Only completed actual maps appear above. Matched OOC results use the same tool, part and directive. Isolated modules have different DSP availability from the full design; no extrapolated full-design fit is claimed.','','Changes implemented in independent commits:','','- Exact distributive factor of barrier/L2 current-cycle multiplication; no state/event/width removal.','- Address statistics: reuse exact 65-bit sum for state update and overflow carry; share single-selected-bucket Store/FirstStore arithmetic; exact bounded balanced population-count sums. All 256 slots, queue/table capacity, 64-bit state, errors and drain contract preserved.','- BOOM prefix scanner: replace 256 dynamic reads from a 256-entry full-sequence table with one fixed-slot comparison each. The second candidate shares the high-half increment and uses two priority encoders and one subtraction. No PASS/recovery/watermark semantics change.','- Second candidate balances latency reductions using exact growing widths and preserves the original 73-bit results and every overflow consumer.','','Verification:','',f"- Original/fit selected modules: `{mods.get('status')}`; maps: `{mapping.get('status')}`.",f"- Arithmetic/sequential verification: `{ver.get('status')}`, active step `{ver.get('active_step')}`; all raw failures retained.",f"- Scanner: `{scanner.get('status')}`, step `{scanner.get('active_step')}`; proof `{scanner.get('proof')}`.",f"- Second candidate: `{round2.get('status')}`, step `{round2.get('active_step')}`, pinned commit `{round2.get('fit_commit')}`.",'','Whole-DUT synthesis is tracked separately below. Runtime admission requires real whole-system capacity, timing and bitstream certification. Formal pairing must bind the new profile/source ID, identical Native software/input/threads/ROI, common BOOM/cache/memory/target-clock parameters. Never label derived results as the frozen 8491167 bitstream.','','Recovery states under Experiment root: `Opt4-fit-modules-state.json`, `Opt4-fit-mapping-state.json`, `Opt4-fit-verification-state.json`, `Opt4-fit-scanner-state.json`, `Opt4-fit-round2-state.json`. All are independently service-managed; reconnect audits PID/start_ticks/boot_id and monitors live workers, never duplicates them.']
 lines+=['',f"Universal cyclic priority SAT: `{priority.get('status','NOT_STARTED')}`; {priority.get('input_bits','unknown')} input bits. Evidence: `Opt4-fit-priority-proof-state.json`. This proves the local combinational identity, not full-design equivalence."]
 lines+=['',f"Full-size address verification after original Icarus compile timeout: `{address_verilator.get('status','NOT_STARTED')}`, tool `{address_verilator.get('tool_version','not recorded')}`. Original timeout evidence remains in `Opt4-fit-verification-state.json`; only the failed address stage is retried, using unchanged RTL/testbench.",f"All five modified sources compiled together: `{integration_compile.get('status','NOT_STARTED')}`.",
  '',f"Whole-system RTL: **{rtl.get('status','NOT_STARTED')}**, commit `{rtl.get('hardware_commit')}`, source ID `{rtl.get('source_id')}`. Exact configuration equality: `{rtl.get('configuration_matches_frozen_parameters')}`; private class origins: `{rtl.get('modified_class_origins_verified')}`.",
  f"Whole-system CAD: **{cad.get('status','NOT_STARTED')}** / `{cad.get('current_stage')}`; controller PID `{cad.get('pid')}`, worker PID `{cad.get('child_pid')}`. Service `ec-parsec-opt4-fit-cad.service`. Reuse only 11 unchanged shell IPs; synthesize derived DUT afresh, then top synthesis, link/black-box checks, opt_design and saved physical capacity report. Stop NOT FIT before placement. FIT proceeds automatically to place/route, setup/hold and bitstream gates. No FPGA access or frozen-profile admission."]
 for scope,key in [('DUT synthesized','dut_resources'),('Complete top optimized','top_postopt_resources')]:
  rows=cad.get(key,{})
  lines+=['',scope+': '+('; '.join(f"{n} {v['used']:,.0f}/{v['available']:,.0f} ({v['percent']:.2f}%)" for n,v in rows.items()) if rows else 'Actual resource report not produced yet; no extrapolation from modules.')]
 lines+=['','Original frozen CAD VHDL export intentionally retired after independently optimized DUT NOT FIT; checkpoints and logs retained in `frozen-cad-retirement.json`. Independent frozen full-top opt_design diagnostic remains separate. Native 21-only jobs unchanged.']
 lines+=['','Independent address round 3: **'+str(address3.get('status','NOT_STARTED'))+'** / `'+str(address3.get('active_step'))+'`; commit `'+str(address3.get('fit_commit'))+'`, source ID `'+str(address3.get('source_id'))+'`. Separate worktree `Opt4-fit-address-round3-20261110`; current 8da24a26 whole-DUT build is unchanged. Hit-count bounds [8,3,2,1] follow from original 1/2/4/8-byte accesses; exact growing subtree widths retain full 64-bit state and outputs, original error/drain/event timing. Proofs and 52-output full-size regression are local validation, not full-DUT equivalence or runtime admission.']
 for name,result in address3.get('tests',{}).items():lines.append('- '+name+': `'+str(result.get('status'))+'`.')
 probes=address3.get('micro_maps',{})
 if probes:
  lines+=['','| Address probe | LUT | CARRY8 | DSP |','|---|---:|---:|---:|']
  for name,result in probes.items():lines.append('| '+name+' | '+' | '.join(f"{result.get('resources',{}).get(k,0):,.0f}" for k in ['CLB LUTs','CARRY8','DSPs'])+' |')
  lines+=['','Probe maps isolate combinational kernels. They are not measurements of the full address module or full DUT. Specialized update probes have not been installed in production source.']
 lines+=['','Additional address arithmetic probes: **'+str(probes4.get('status','NOT_STARTED'))+'**. No production hardware changes.']
 for name,result in probes4.get('proofs',{}).items():lines.append('- '+name+': `'+str(result.get('status'))+'`.')
 for name,result in probes4.get('maps',{}).items():
  lines.append('- '+name+': '+', '.join(f'{k} {v:,.0f}' for k,v in result.get('resources',{}).items())+' (micro probe only).')
 lines+=['','Derived software preparation: **'+str(runtime_preparation.get('status','NOT_PREPARED'))+'**; '+str(runtime_preparation.get('program_count',0))+' programs with exact Native references. Derived automatic certification/21-only boundary handoff service: **'+str(runtime_state.get('status','NOT_INSTALLED'))+'**. Service ec-parsec-opt4-fit-runtime; no deployment before real capacity/timing/DRC certification; Native live sample is preserved. Frozen C4 IDs are never reused for derived artifacts.']
 lines+=['','Independent parsed bit-heap compositional arithmetic proof/micro map: **'+str(heap_proof.get('status','NOT_STARTED'))+'**. Prior monolithic SAT timeout is retained. Local exhaustive compressor identities plus parsed weighted conservation and explicit proven leaf bounds; not full module/DUT equivalence. Resources: '+str(heap_proof.get('resources','pending'))+'.']
 lines+=['','Independent Chisel heap candidate: **'+str(heap_candidate.get('status','NOT_STARTED'))+'**, commit `'+str(heap_candidate.get('hardware_commit'))+'`, source ID `'+str(heap_candidate.get('source_id'))+'`. Compile/elaboration and frozen full-module sequential comparison must pass before full-module mapping; no automatic whole-DUT promotion. Failure evidence is retained by revision.']
 lines+=['','Independent shared-scatter candidate: **'+str(address_sort.get('status','NOT_STARTED'))+'**, commit `'+str(address_sort.get('hardware_commit'))+'`. Local generated-RTL proofs, real-size oracle, frozen module cycle comparison, then measured standalone map. No full-DUT promotion. Native scheduling user pause: **'+str(native_pause.get('status','NOT_PAUSED'))+'**; latest authoritative build/recovery notes supersede historical Native scheduling text.']
 p=O/'FIT_STATUS.md';t=p.with_suffix('.summary.tmp');t.write_text('\n'.join(lines)+'\n');t.replace(p)
 print(json.dumps(dict(results=results,comparison=comparison,report=str(p))))
if __name__=='__main__':main()
