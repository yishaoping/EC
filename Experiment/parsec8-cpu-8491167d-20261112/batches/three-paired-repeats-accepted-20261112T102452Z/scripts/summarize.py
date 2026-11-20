#!/usr/bin/env python3
"""Export accepted pairs, coverage, exclusions and method-separated paper data."""
from common import *
import csv,math,statistics
NAMES=['blackscholes','fluidanimate','bodytrack','freqmine','swaptions','ferret','dedup','streamcluster']
queue=read(ROOT/'queue.json');paper=ROOT/'paper';paper.mkdir(exist_ok=True)
abi=read(ROOT/'audit/abi-audit.json') if (ROOT/'audit/abi-audit.json').exists() else {}
software=read(ROOT/'audit/software-source-input-audit.json') if (ROOT/'audit/software-source-input-audit.json').exists() else {}
progress=read(ROOT/'audit/progress.json') if (ROOT/'audit/progress.json').exists() else {}
def write_csv(name,rows,columns=None):
 columns=columns or list(dict.fromkeys(k for r in rows for k in r))
 with (paper/name).open('w',newline='') as f:
  w=csv.DictWriter(f,fieldnames=columns);w.writeheader();w.writerows(rows)
def selected(name):
 p=next(ROOT/x['manifest'] for x in queue['items'] if x['benchmark']==name)
 return (read(p),p) if p.exists() else ({},p)
def result(mf,mode,repeat=1):
 r,p=selected_result(mf,mode,repeat)
 if mf and (not r or not r.get('valid')):
  for out in run_paths(mf,mode,repeat):
   if not (out/'state.json').exists():continue
   s=read(out/'state.json');child=s.get('child')
   if s.get('status')=='RUNNING' and child and ident(child['pid'])==child:return None,out/'result.json'
 if r:
  receipt=p.parent/'raw-audit.json'
  a=read(receipt) if receipt.exists() else {}
  r={**r,'raw_audit_verified':bool(a.get('passed') and a.get('result_sha256')==sha(p))}
 return r,p

def raw(p):
 if p is None:return {}
 receipt=p.parent/'stdout-integrity.json'
 if not receipt.exists():return {}
 j=read(receipt);return dict(evidence=str(receipt),raw_log_sha256=j['raw_sha256'],compressed_log_sha256=j.get('gzip_sha256'))
def output(r):return (r or {}).get('output')
def scope(mf):
 # Clarify old manifest wording without changing the immutable run contract.
 if mf.get('benchmark')=='blackscholes':return 'One original bs_thread iteration over the same 64 option records in both modes; distinct call/put and price/volatility cases; setup/output outside ROI'
 return mf.get('roi_scope')
def assess(mf,mp,n,e):
 both=bool(n and e);nv=bool(n and n.get('valid'));ev=bool(e and e.get('valid'))
 nc=(n or {}).get('roi_cycles');ec=(e or {}).get('roi_cycles');ni=(n or {}).get('roi_instructions');ei=(e or {}).get('roi_instructions')
 om=bool(both and output(n) and output(n)==output(e))
 im=bool(both and ni is not None and ni==ei)
 irq=bool(both and n.get('interrupt_policy_verified') and e.get('interrupt_policy_verified'))
 bound=bool(both and n.get('manifest_sha256')==e.get('manifest_sha256')==sha(mp)) if mf else False
 ar=next((r for r in abi.get('profiles',[]) if mf and r['benchmark']==mf['benchmark'] and r['manifest_sha256']==sha(mp)),{})
 abi_ok=bool(ar.get('pair_abi_match') and ar.get('shared_objects_hash_match'))
 sr=next((r for r in software.get('profiles',[]) if mf and r['benchmark']==mf['benchmark'] and r['manifest_sha256']==sha(mp)),{})
 software_ok=bool(sr.get('passed'))
 evidence=bool(both and n.get('raw_audit_verified') and e.get('raw_audit_verified'))
 accepted=bool(nv and ev and nc is not None and ec is not None and om and im and irq and bound and evidence and abi_ok and software_ok)
 if accepted:status='VALID_CPU_GG_PAIR'
 elif nv and ev and om and im and irq and bound and (not evidence or not abi_ok or not software_ok):status='EVIDENCE_AUDIT_PENDING'
 elif nv and ev:status='OUTPUT_VALID_PAIR_COMPARABILITY_REJECTED'
 elif n and not nv:status='NATIVE_FAILED_EC_SKIPPED'
 elif e and not ev:status='EC_FAILED_OR_UNVALIDATED'
 elif mf:status='PAIR_PENDING'
 else:status='ADAPTER_NOT_READY'
 return dict(native_cycles=nc,ec_cycles=ec,instructions_native=ni,instructions_ec=ei,slowdown=ec/nc if accepted else None,diagnostic_ratio_excluded=ec/nc if nv and ev and nc and ec and not accepted else None,native_correctness=nv if n else None,ec_correctness=ev if e else None,instruction_match=im if both else None,output_match=om if both else None,interrupt_policy_match=irq if both else None,manifest_match=bound if both else None,abi_shared_object_audit_passed=abi_ok,software_source_input_audit_passed=software_ok,independent_raw_audit_passed=evidence if both else None,status=status)
rows=[];samples=[];attempts=[]
for name in NAMES:
 mf,mp=selected(name);n,np=result(mf,'native');e,ep=result(mf,'ec');r=assess(mf,mp,n,e)
 if r['slowdown'] is None and any(x['benchmark']==name and x['profile']==mf.get('profile') and x.get('active') for x in progress.get('records',[])):r['status']='PAIR_RUNNING'
 strict=(e or {}).get('strict_acceptance') or {}
 svb={};checker={}
 if e and mf:
  sp=ep.parent/'svb-metrics.json'
  if sp.exists(): svb=read(sp)
  cp=ep.parent/'checker-local-metrics.json'
  if cp.exists():checker=read(cp)
 row=dict(benchmark=name,profile=mf.get('profile'),threads=mf.get('threads'),method=mf.get('method'),measurement_engine='CPU_GG_CYCLE_EXACT',workload_scope=scope(mf),**r,
  instructions_delta_ec_minus_native=(r['instructions_ec']-r['instructions_native']) if r['instructions_ec'] is not None and r['instructions_native'] is not None else None,
  checker_results=strict.get('boom_pass_accepted'),checker_passed=strict.get('passed'),drain_cycles=(e or {}).get('drain_cycles'),checker_acceptance_tail_boom_cycles=(e or {}).get('drain_cycles'),checker_acceptance_tail_definition='max(0,last BOOM_RESULT_ACCEPTED CSR cycle minus ROI end CSR cycle); observed package acceptance only',
  checker_local_mean_cycles=checker.get('stats',{}).get('mean'),checker_local_p95_cycles=checker.get('stats',{}).get('p95'),checker_local_timebase='100MHz checker clock',
  svb_complete_matched_lifetimes=svb.get('complete_matched_lifetimes'),svb_pending_entries=svb.get('unmatched_current_entries'),svb_event_errors=len(svb.get('errors',[])) if svb else None,svb_mean_capture_to_ack=(svb.get('stats',{}).get('capture_to_ack') or {}).get('mean'),svb_mean_promotion_to_ack=(svb.get('stats',{}).get('promotion_to_ack') or {}).get('mean'),
  svb_roi_capture_count=svb.get('roi_capture_count'),svb_roi_complete_matched_lifetimes=svb.get('roi_complete_matched_lifetimes'),svb_roi_mean_capture_to_ack=(svb.get('roi_capture_stats',{}).get('capture_to_ack') or {}).get('mean'),svb_roi_matched_ack_tail=svb.get('roi_capture_matched_ack_tail'),
  svb_roi_superseded_entries=svb.get('roi_superseded_entries'),svb_roi_unmatched_current_entries=svb.get('roi_unmatched_current_entries'),svb_timebase='BOOM CSR cycles',
  strict_detection_latency_cycles=(e or {}).get('strict_detection_latency_cycles'),full_rollback_latency_cycles=(e or {}).get('full_rollback_latency_cycles'),svb_events=(e or {}).get('svb_events'),
  native_evidence=str(np) if np and np.exists() else None,ec_evidence=str(ep) if ep and ep.exists() else None,
  native_raw_log_evidence=raw(np).get('evidence'),ec_raw_log_evidence=raw(ep).get('evidence'),native_raw_log_sha256=raw(np).get('raw_log_sha256'),ec_raw_log_sha256=raw(ep).get('raw_log_sha256'),
  manifest=str(mp) if mf else None,manifest_sha256=sha(mp) if mf else None,
  extrapolation_error_to_full_simmedium='UNMEASURED_NO_EXTRAPOLATION',functional_baseline=BASE)
 rows.append(row)
 for repeat in range(1,4):
  rn,rnp=result(mf,'native',repeat);re,rep=result(mf,'ec',repeat)
  if rn or re:samples.append(dict(benchmark=name,profile=mf.get('profile'),method=mf.get('method'),repeat=repeat,**assess(mf,mp,rn,re),checker_acceptance_tail_boom_cycles=(re or {}).get('drain_cycles'),strict_detection_latency_cycles=(re or {}).get('strict_detection_latency_cycles'),full_rollback_latency_cycles=(re or {}).get('full_rollback_latency_cycles'),native_evidence=str(rnp) if rnp and rnp.exists() else None,ec_evidence=str(rep) if rep and rep.exists() else None))
  if mf:
   for mode in ['native','ec']:
    for p in run_paths(mf,mode,repeat):
     if not (p/'binding.json').exists():continue
     ar=read(p/'result.json') if (p/'result.json').exists() else {}
     reason=next((p/f for f in ['external-stop-reason.json','diagnostic-stop-reason.json'] if (p/f).exists()),None)
     attempts.append(dict(benchmark=name,profile=mf['profile'],mode=mode,repeat=repeat,attempt=p.name.rsplit('-attempt',1)[-1] if '-attempt' in p.name else 1,status=ar.get('status','RUNNING_OR_INTERRUPTED'),valid=ar.get('valid'),roi_cycles=ar.get('roi_cycles'),roi_instructions=ar.get('roi_instructions'),selected_result=str(p/'result.json') in [str(rnp),str(rep)],evidence=str(p/'result.json') if ar else str(p/'binding.json'),external_stop_evidence=str(reason) if reason else None))
for row in rows:
 tail=row['checker_acceptance_tail_boom_cycles']
 row['ec_roi_plus_checker_acceptance_tail_cycles']=row['ec_cycles']+tail if row['slowdown'] is not None and tail is not None else None
 row['roi_plus_acceptance_tail_over_native_roi']=row['ec_roi_plus_checker_acceptance_tail_cycles']/row['native_cycles'] if row['ec_roi_plus_checker_acceptance_tail_cycles'] is not None else None
write_csv('parsec8-native-ec.csv',rows)
write_csv('checker-acceptance-tail-plot-data.csv',[{k:r.get(k) for k in ['benchmark','profile','native_cycles','ec_cycles','slowdown','checker_acceptance_tail_boom_cycles','ec_roi_plus_checker_acceptance_tail_cycles','roi_plus_acceptance_tail_over_native_roi','status']} for r in rows])
write_csv('measurement-uncertainty.csv',[dict(benchmark=r['benchmark'],profile=r['profile'],measurement_engine=r['measurement_engine'],counter_resolution_target_cycles=1,cycle_values_are_estimates=False,counter_rounding='Exact integer CSR differences; common instrumentation included in both modes',repeatability='See repeatability.csv for accepted paired n and measured range',gg_fidelity_scope='Exact cycles of the retained generated target model and fixed FASED configuration; source/build/clock receipts audited; not a new universal equivalence proof',error_to_real_dram_or_fpga='UNMEASURED_NO_HARDWARE_CALIBRATION',error_to_full_simmedium='UNMEASURED_NO_EXTRAPOLATION',elf_layout_cache_state_error='UNMEASURED_DISTINCT_STARTUP_ELFS',workload_sampling_error='UNMEASURED_SINGLE_DECLARED_INPUT_PROFILE',strict_detection_latency='MISSING_REAL_ENDPOINTS',full_rollback_latency='MISSING_REAL_ENDPOINTS') for r in rows])
write_csv('run-attempts.csv',attempts)
write_csv('samples.csv',samples,columns=list(dict.fromkeys(k for s in samples for k in s)))
write_csv('plot-data.csv',[{k:r.get(k) for k in ['benchmark','profile','method','slowdown','native_cycles','ec_cycles','instructions_native','instructions_ec','status']} for r in rows])
groups={}
for r in rows:
 if r['slowdown'] is not None:groups.setdefault(r['method'],[]).append(r)
by_method={k:dict(slowdown=math.exp(statistics.mean(math.log(r['slowdown']) for r in rs)),includes=[r['benchmark'] for r in rs],benchmark_count=len(rs),scope='FIRST_ROUND_ACCEPTED_SUBSET_ONLY') for k,rs in groups.items()}
accepted_rows=[r for r in rows if r['slowdown'] is not None]
same_engine=len({r['measurement_engine'] for r in accepted_rows})==1
requested_gm=math.exp(statistics.mean(math.log(r['slowdown']) for r in accepted_rows)) if len(accepted_rows)==8 and same_engine else None
gm_scope='Eight declared profiles measured by the same exact CPU GG engine; includes official test, changed/reduced workloads and captured components. Descriptive profile index only; full-application extrapolation error is unmeasured.'
gm_status=('COMPLETE_DECLARED_PROFILE_GEOMEAN_MIXED_SCOPES' if len(by_method)>1 else 'COMPLETE_SAME_SCOPE_EIGHT') if requested_gm is not None else 'UNAVAILABLE_INCOMPLETE_OR_DIFFERENT_MEASUREMENT_ENGINES'
write_csv('geomeans.csv',[dict(method=k,benchmark_count=v['benchmark_count'],includes=';'.join(v['includes']),geomean_slowdown=v['slowdown'],scope=v['scope']) for k,v in by_method.items()]+[dict(method='REQUESTED_EIGHT_DECLARED_PROFILES',benchmark_count=len(accepted_rows),includes=';'.join(NAMES) if requested_gm is not None else '',geomean_slowdown=requested_gm,scope=gm_scope if requested_gm is not None else gm_status)])
stability=[]
for name in NAMES:
 accepted=[s for s in samples if s['benchmark']==name and s['slowdown'] is not None]
 values=[s['slowdown'] for s in accepted]
 if values:
  s=dict(benchmark=name,paired_n=len(values),slowdown_mean=statistics.mean(values),slowdown_min=min(values),slowdown_max=max(values),slowdown_sample_stddev=statistics.stdev(values) if len(values)>1 else None,repeatability_status='N1_NO_VARIANCE_ESTIMATE' if len(values)==1 else 'REPEATED_IDENTICAL_CONFIG_DETERMINISTIC_SIMULATOR')
  for mode in ['native','ec']:
   v=[x[mode+'_cycles'] for x in accepted]
   s.update({mode+'_cycles_mean':statistics.mean(v),mode+'_cycles_min':min(v),mode+'_cycles_max':max(v),mode+'_cycles_sample_stddev':statistics.stdev(v) if len(v)>1 else None})
  s['instructions_identical_across_paired_repeats']=len({x['instructions_native'] for x in accepted})==1
  stability.append(s)
write_csv('repeatability.csv',stability,columns=list(stability[0]) if stability else ['benchmark','paired_n','slowdown_mean'])
limitations=[
 'These are exact target-cycle simulations of the stated HTIF profiles, not FPGA measurements or full Linux simmedium execution.',
 'Official-test, reduced-input/changed-configuration ROI and real-trace component replay are distinct workload scopes. Method subsets are separate. An all-eight Geomean requires eight accepted pairs measured by the same exact CPU GG engine and is explicitly a descriptive index of these declared profiles, not full-application slowdown.',
 'Representativeness and extrapolation error versus a complete official simmedium run are uncalibrated. No full-workload cycle estimates are produced.',
 'Native and EC share application objects but have distinct boot/test ELF images and linked addresses/cache state. Both clear main-hart MTIE before preparation, and unchanged timer counters are checked across ROI.',
 'A pair requires correct output, strict EC package acceptance, equal ROI instructions, matching interrupt policy and matching bound manifest hashes.',
 'One pair gives no statistical uncertainty estimate. Repeated deterministic simulation assesses repeatability under the same initial state, not workload/input variation.',
 'Checker acceptance and ROI-to-last-acceptance tail do not establish strict detection, SVB lifecycle or full rollback latency. Missing event endpoints remain null.',
 'Historical Blackscholes/Swaptions ratios with different timer policies and Canneal flow validation are excluded from all current performance aggregates.']
summary=dict(schema='parsec8-cpu-gg-summary/4',created_utc=now(),functional_baseline=BASE,valid_pair_count=len(accepted_rows),requested_benchmark_count=8,requested_eight_geomean_slowdown=requested_gm,geomean_slowdown=requested_gm,geomean_includes=NAMES if requested_gm is not None else [],geomean_status=gm_status,geomean_scope=gm_scope,geomean_workload_scope_counts={k:v['benchmark_count'] for k,v in by_method.items()},full_application_geomean_slowdown=None,subset_geomean_by_method=by_method,per_benchmark=rows,repeatability=stability,limitations=limitations)
save(paper/'summary.json',summary)
readme=ROOT/'README.md'
if readme.exists() and '<!-- LIVE-RESULTS-BEGIN -->' in readme.read_text():
 content=readme.read_text();before,rest=content.split('<!-- LIVE-RESULTS-BEGIN -->',1);_,after=rest.split('<!-- LIVE-RESULTS-END -->',1)
 live=f"Accepted first-round pairs: **{len(accepted_rows)}/8**, updated {summary['created_utc']}. The table reports exact target cycles of the declared profiles; full-application extrapolation is uncalibrated.\n\n"
 live+='| Program | Native cycles | EC cycles | EC / Native | ROI instructions each | Paired n |\n| --- | ---: | ---: | ---: | ---: | ---: |\n'
 for r in rows:
  n=next((s['paired_n'] for s in stability if s['benchmark']==r['benchmark']),0)
  live+='| '+ ' | '.join([r['benchmark'].capitalize(),str(r['native_cycles'] or ''),str(r['ec_cycles'] or ''),f"{r['slowdown']:.6f}" if r['slowdown'] is not None else r['status'],str(r['instructions_native'] or ''),str(n)])+' |\n'
 live+='\nEight declared-profile Geomean: '+(f"**{requested_gm:.6f}x**" if requested_gm is not None else '**unavailable until eight pairs pass**')+'. Full-application Geomean is unavailable.\n'
 readme.write_text(before+'<!-- LIVE-RESULTS-BEGIN -->\n'+live+'<!-- LIVE-RESULTS-END -->'+after)
# Keep earlier diagnostic pairs accessible even when a new manifest supersedes them.
diagnostics=[]
fn=ROOT/'runs/fluidanimate-real-test64-preintegration-AdvanceParticles-4725-cells-native-r1/result.json';fe=ROOT/'runs/fluidanimate-real-test64-preintegration-AdvanceParticles-4725-cells-ec-r1/result.json'
if fn.exists() and fe.exists():
 nj,ej=read(fn),read(fe)
 diagnostics.append(dict(benchmark='fluidanimate',profile='real-test64-preintegration-AdvanceParticles-4725-cells-link-relaxation',native_cycles=nj['roi_cycles'],ec_cycles=ej['roi_cycles'],instructions_native=nj['roi_instructions'],instructions_ec=ej['roi_instructions'],ratio_excluded=ej['roi_cycles']/nj['roi_cycles'],exclusion='LINKER_RELAXATION_ONE_INSTRUCTION_MISMATCH',native_evidence=str(fn),ec_evidence=str(fe)))
bn=D/'cycleprecise-matched-single-boom-gg-r3-20261112/result.json';be=D/'cycleprecise-frozen-full-gg-blackscholes-observed-r1-20261111/result.json'
if bn.exists() and be.exists():
 nj=next(x for x in read(bn)['workloads'] if x.get('benchmark')=='blackscholes');ej=read(be)
 diagnostics.append(dict(benchmark='blackscholes',profile='project64-100-iterations-old-timer-policy',native_cycles=nj['roi_cycles'],ec_cycles=ej['roi_cycles'],instructions_native=nj['roi_instructions'],instructions_ec=ej['roi_instructions'],ratio_excluded=ej['roi_cycles']/nj['roi_cycles'],exclusion='MAIN_TIMER_POLICY_MISMATCH_AND_INSTRUCTION_MISMATCH',native_evidence=str(bn),ec_evidence=str(be)))
sn=ROOT/'runs/swaptions-representative-16-trial-test-native-r1-attempt5/result.json';se=ROOT/'runs/swaptions-representative-16-trial-test-ec-r1-attempt5/result.json'
if sn.exists() and se.exists():
 nj=read(sn);ej=read(se)
 diagnostics.append(dict(benchmark='swaptions',profile='representative-16-trial-old-timer-policy',native_cycles=nj['roi_cycles'],ec_cycles=ej['roi_cycles'],instructions_native=nj['roi_instructions'],instructions_ec=ej['roi_instructions'],ratio_excluded=ej['roi_cycles']/nj['roi_cycles'],exclusion='MAIN_TIMER_POLICY_MISMATCH_AND_INSTRUCTION_MISMATCH',native_evidence=str(sn),ec_evidence=str(se)))
write_csv('diagnostic-pairs-excluded.csv',diagnostics)
canpath=D/'paper-matched-source-cpu-comparison-r2-20261112/canneal_project400/result.json';can=read(canpath)
write_csv('canneal-flow-validation-excluded.csv',[dict(benchmark='canneal',profile='project400',native_cycles=can['native_roi_cycles'],ec_cycles=can['ec_roi_cycles'],slowdown=can['ratio_ec_native_roi'],instructions=can['native_roi_instructions'],included_in_requested_eight=False,evidence=str(canpath))])
# Methods remain current as queue manifests/results arrive.
text='''# PARSEC CPU Golden Gate measurement method

This CPU-only campaign uses frozen EC functional baseline `8491167d84b6d9521b151a743673c1516926a1f8`. Source/configuration receipts are in `audit/`. It does not require an FPGA bitstream. No FPGA, Vivado or CAD command is part of this campaign.

The clean Native and frozen EC models use the matched single-BOOM target and FASED memory: BOOM 200 MHz, EC checker 100 MHz, read/write latency 30, maximum four requests and relax=0. Both run one application thread. At most four single-threaded simulators use CPUs 200, 201, 202 and 204 at nice 19. CPU 201 prioritizes EC; when all eight first EC runs have been dispatched and no EC task is ready, it prefetches comparable repeats. CPUs 202/204 may serve guarded first Native samples and prefetch a missing earlier Native repeat before a later EC repeat, while sharing locks with their EC slots. CPU 200 serves Native, then an auxiliary EC slot after the selected eight first Native runs pass; a shared CPU lock prevents Native and auxiliary EC from running together. Extra EC slots on CPUs 202 and 204 sample pressure every 10 seconds and pause only their own simulator process groups while global CPU utilization exceeds 65%, the sibling hardware thread exceeds 20%, or available memory is below 64 GiB; per-run pressure events record pauses and resumes, and paused time is excluded from the active host budget. Address-space reservation is capped at 64 GiB because the simulated memory backing needs a large mmap; resident memory is bounded at 16 GiB for new runs. Build/reference tasks use CPU 200 at nice 19. Later runners record an execution policy with a 14,400-second active host-time floor to let target-cycle caps be reached at the observed EC simulation throughput; this host budget does not change the target or ROI. The initial CPU 208 extra slot was retired after sustained sibling-thread pressure; its interrupted attempt is preserved, and subsequent attempts use CPU 204. Earlier runs retain their original bound scheduling policy.

Linux PARSEC ELF files cannot be loaded as valid applications by this bare-metal HTIF environment. Independent HTIF adapters use original PARSEC computational source, embedded byte-identical inputs or explicitly reduced inputs. Native and EC share all compiled application objects and compiler flags (O2, rv64imafd, static HTIF/newlib, lp64d ABI). Their EC initialization and startup ELF images differ; address layout and cache state can differ. This is a paired comparison for the declared profile, with a remaining layout confound. It is not a same-ELF or Linux simmedium comparison. Each manifest records compiler invocations, ELF/source/object/input hashes, independent host reference, ROI and limitations. See `abi-audit.json` for decoded ELF metadata. `software-source-input-audit.json` independently rechecks retained sources, inputs, traces and host references against those hashes. The root htif.ld linker scripts were not separately hashed in the initial manifests; their current retained hashes and snapshot copies are supplemental, while the actual linked ELF hashes remain originally bound.

Both modes clear main-hart MTIE before workload preparation. The frozen checker firmware is unchanged. Timer counter values and MIE are printed across ROI and checked. RD cycle and retired-instruction CSRs surround exactly the shared workload_run call; setup, verification and output are outside ROI. The common timer-counter read contributes the same instrumentation inside each ROI. An output-valid pair is accepted only when the Native and EC instruction counts match, both manifests match their run bindings, and the EC strict join proves every allocated package began, completed full comparison and was accepted by BOOM with zero pending/failure/cancellation/duplicate entries.

The following profiles are independent measurement contracts. Every listed cycle is a measured target cycle if a result has passed; pending cells are empty. Exact simulation of a short profile does not establish its representativeness for simmedium. Counter resolution is one target cycle; the common CSR/instrumentation sequence is included on both sides. Exactness refers to the retained target model with fixed FASED settings. No empirical error bound to physical DRAM/FPGA timing is available. `measurement-uncertainty.csv` records this boundary separately from repeatability, workload representativeness, software layout and missing event endpoints. No extrapolated full-workload cycle estimates are produced.

| Benchmark | Method | ROI profile | Native cycles | EC cycles | Status |
| --- | --- | --- | ---: | ---: | --- |
'''
for r in rows:text+='| '+ ' | '.join(str(x) if x is not None else '' for x in [r['benchmark'],r['method'],r['profile'],r['native_cycles'],r['ec_cycles'],r['status']])+' |\n'
text+='\n'
for name in NAMES:
 mf,_=selected(name)
 if mf:
  scope=mf.get('roi_scope','')
  if name=='blackscholes':scope='One original bs_thread iteration over the same 64 option records in both modes; the records contain distinct call/put and price/volatility cases. Setup/output are outside ROI.'
  text+=f"**{name}**: {scope}\n\n"
  for x in mf.get('limitations',[])+mf.get('adaptations',[]):text+='- '+x+'\n'
  if name=='freqmine':text+='- Verification clarification: the exact per-cardinality itemset-count histogram and transaction count are checked against an independent oracle; individual itemset identities/supports are not emitted or compared.\n'
  if name=='fluidanimate':text+='- Supplemental independent Python binary32 integration oracle matches all576 original host-reference output floats bit-for-bit; see audit/fluid-advance-binary32-oracle.json and scripts/check_fluid_oracle.py. The measured target separately checks every output with the declared tolerance. An earlier component pair differed by one retired instruction because Native linked cells via AUIPC+LD and EC relaxed to gp-relative LD. That pair is excluded. The selected new profile disables target compiler/linker relaxation in both modes and requires a fresh pair; diagnostics/fluid-link-relaxation-mismatch.json binds both disassemblies and proves matching phase mnemonic sequences.\n'
  text+='\n'
text+='''`correctness-contracts.csv` specifies each verifier, comparison fingerprint and its limits. Output-match columns mean agreement of the reported output rows, including compact FNV fingerprints; several floating-point profiles use quantized fingerprints alongside individual tolerance checks. Swaptions has finite/nonnegative checks and agreement with a host fingerprint quantized to 1e-3, without emitting raw mean/error values. Dedup independently decompresses the host archive; target agreement is checked by its hash over every archive byte, not independent target archive decompression. These scopes must be preserved when describing correctness.

The official Freqmine test has three transactions and Dedup test has six input bytes; results at these tiny sizes cannot substantiate full benchmark performance. Swaptions uses 16 trials because the original 16-wide block kernel gives a NaN standard error for the official five-trial input. Bodytrack, Fluidanimate and Ferret use real application-generated component inputs, but their full-application time coverage and sampling error remain uncalibrated. Fluidanimate captures all12 state components per particle after original grid rebuild, force computation and collision handling, then replays the verbatim original AdvanceParticles on the original4725-cell grid. Its64-particle input is reduced, and the measured integration phase excludes the other frame phases. The original full-frame Fluidanimate and full-EMD Ferret attempts produced actual cancelled checker results; the narrower successful scopes, if accepted, do not repair or validate those failed computations. Dedup's selected profile changes MAXBUF from128MiB to16MiB and preloads its original-size zero hash table; its original128MiB attempt remains a failed observation. These choices create selection and scope limits, so no all-application claim follows from a complete profile table. Failure chains and original raw evidence are preserved in diagnostics/ and runs/.

The primary CSV/plot contains only accepted first-round ratios, after independent raw-stream and binary/ELF/binding hash validation. Interrupted runs retain all evidence and can be retried in a new attempt directory. Selection uses the earliest successful completed attempt, never the fastest result. `run-attempts.csv` lists selected-profile attempts and `all-run-evidence-ledger.csv` retains superseded profiles. Workload-scope subset Geomeans list every included benchmark separately. After all eight accepted pairs use the same exact CPU GG engine, their all-eight declared-profile Geomean is exp(mean(log(EC cycles / Native cycles))). It is explicitly a descriptive index of the eight listed profiles, including reduced/changed workloads and captured component replays. It does not estimate full applications; `full_application_geomean_slowdown` stays null. Different measurement engines or estimates are never mixed in that aggregate. Idle-slot Native repeats may be prepared while a first EC remains pending, after all first EC dispatches; completed noncomparable first contracts remain ineligible. EC repeats and published paired statistics still require actual first-pair comparability. Repeat statistics use complete paired repeats, record n, and leave standard deviation empty at n=1. Repeated deterministic runs do not sample workload diversity or software/hardware configuration uncertainty.

Checker acceptance tail is max(0, last accepted-result BOOM CSR cycle minus ROI-end CSR cycle). It is reported separately from ROI cycles, explicitly as `checker_acceptance_tail_boom_cycles`; the legacy `drain_cycles` column carries the same observed package acceptance tail and does not claim complete architectural drain. Strict checker detection needs same-package actual execution-done and checker-done endpoints; full rollback needs actual rollback begin/end events. These have not been captured, so those latency fields are null. No fault injection means this campaign cannot establish detection or recovery time. Where available, SVB capture/promotion/C-first/C-last/matching-ACK events are joined by full entry/line/sequence/generation key using their BOOM CSR timestamps. `svb-lifetimes.csv` marks captures inside ROI. Whole-run and ROI-capture populations are separate; matching-ACK tail describes completed observed ROI keys only. Missing/coalesced entries and absent payload validation prevent calling this architectural or complete SVB drain. Accepted package counts are not SVB lifetimes. `checker-local-metrics-repeats.csv` and `svb-metrics-repeats.csv` retain the same event metrics for every accepted EC repeat.

Historical Linux Native FPGA simmedium, bare-metal Canneal project400, old project64 runs and new short profiles are never paired across contracts. `diagnostic-pairs-excluded.csv` preserves old output-valid Blackscholes/Swaptions ratios with mismatched timer policies and instruction counts; none enters this plot or a Geomean. Canneal is workflow validation only. The independent historical audit is `audit/existing-data-audit.json`, including the existing Native FPGA repeats, CPU metasim and RTL evidence.

The supplemental `audit/historical-native-fpga-audit.json` rechecks all 24 archived Native FPGA simmedium result hashes, cycles and saved validity/exit evidence for the requested eight. `historical-native-fpga-excluded.csv` records their statistics independently. This read-only audit does not operate hardware or produce a cross-platform performance pair.

`checker-local-metrics.csv` reports real same-package new_package to package_result_queue.io.enq.fire intervals from the synthesized checker print bridge. PASS/full_compare/cancellation flags and package ownership are checked. Intervals use the 100 MHz checker domain; two BOOM-equivalent duration cycles correspond to one checker cycle. Absolute epochs are not aligned from this frequency ratio. These overlapping local intervals include service/stalls and result enqueue waiting. Summing them across four parallel checkers does not yield application overhead, strict detection latency or result transport delay.

Each result points to its original run directory: `binding.json` contains the exact command and binary/ELF/manifest hashes; `host-complete.log.gz` is complete stdout/stderr; `stdout-integrity.json` records raw and compressed stream SHA-256; EC `external-events.jsonl` and `strict-acceptance.json` contain event and package evidence. Independent raw auditing decompresses the full stream and re-parses ROI CSR boundaries, cycle/instruction counts, timer policy, output and end markers against the result. `host-summary.log` is a filtered convenience log, not the complete source. A failed run retains its evidence and cannot yield a ratio. Rebuilds use new profile/directory bindings if an earlier target run exists. Run `python3 scripts/export.py` to refresh all audits and paper exports. First-eight and completed-three-repeat releases are automatically retained under `batches/` with file hashes and original raw-log references.
'''
(paper/'methods.md').write_text(text)
caption=f'''Native/EC target-cycle comparison for eight explicitly specified PARSEC-derived profiles on CPU Golden Gate simulation (frozen EC 8491167d, one BOOM at 200 MHz, four EC checkers at 100 MHz, one application thread, matched FASED settings). Bars show EC/Native cycles between identical ROI instrumentation boundaries and require identical retired-instruction counts, matching outputs, and complete EC package acceptance. Currently {len(accepted_rows)}/8 first-round pairs are accepted. Colors distinguish reduced/changed configurations, the16-trial reduced profile, and captured component replay. These exact-profile results do not estimate complete PARSEC simmedium applications; representativeness and linked-address/cache-state effects are uncalibrated. Repetition counts and cycle ranges are supplied in repeatability.csv. Repeated deterministic simulation measures repeatability under the same configuration, without estimating workload sampling uncertainty.
'''
if requested_gm is not None:caption+=f' The descriptive Geomean of all eight declared profiles is {requested_gm:.6f}x, computed as exp(mean(log(EC/Native))); the full-application Geomean is unavailable.\n'
caption+='\nThe supplemental checker acceptance-tail data adds max(0,last BOOM-accepted result cycle minus ROI-end cycle) to EC ROI cycles and divides by Native ROI cycles. This measured endpoint metric omits EC startup/enable costs and does not assert complete SVB or architectural drain, strict detection latency, or rollback latency. It is excluded from the primary ROI Geomean.\n'
(paper/'figure-caption.md').write_text(caption)
try:
 import matplotlib;matplotlib.use('Agg')
 matplotlib.rcParams.update({'pdf.fonttype':42,'ps.fonttype':42,'svg.fonttype':'none'})
 import matplotlib.pyplot as plt
 from matplotlib.patches import Patch
 palette={'CPU_GG_FULL_OFFICIAL_TEST':'#246a73','CPU_GG_TEST_DERIVED_REPRESENTATIVE_ROI':'#4487b4','CPU_GG_REPRESENTATIVE_TEST_PROFILE':'#43958b','CPU_GG_REAL_TRACE_COMPONENT_REPLAY':'#c18a38'}
 fig,ax=plt.subplots(figsize=(10,4.8));xs=range(8);vals=[r['slowdown'] for r in rows]
 top=max(1.25,max((v or 0 for v in vals),default=0)*1.18)
 for x,r in zip(xs,rows):
  v=r['slowdown']
  if v is None:ax.text(x,.035*top,'failed' if 'FAILED' in r['status'] else 'pending',rotation=90,ha='center',va='bottom',fontsize=9,color='#60676b')
  else:
   ax.bar(x,v,color=palette.get(r['method'],'#4487b4'),width=.65);ax.text(x,v+.02*top,f'{v:.3f}x',ha='center',fontsize=9)
 ax.axhline(1,color='#687275',linewidth=.8,linestyle=':');ax.set_ylim(0,top)
 positions=list(xs);names=[r['benchmark'].capitalize() for r in rows]
 if requested_gm is not None:
  positions.append(8);names.append('Geomean*');ax.bar(8,requested_gm,color='#687275',width=.65);ax.text(8,requested_gm+.02*top,f'{requested_gm:.3f}x',ha='center',fontsize=9)
 ax.set_xticks(positions,names,rotation=20,ha='right');ax.set_ylabel('EC / Native ROI target cycles')
 ax.set_title(f"PARSEC-derived profiles, CPU Golden Gate: {summary['valid_pair_count']}/8 accepted pairs")
 present=set(r['method'] for r in rows if r['slowdown'] is not None)
 labels={'CPU_GG_FULL_OFFICIAL_TEST':'Official test pipeline','CPU_GG_TEST_DERIVED_REPRESENTATIVE_ROI':'Reduced / changed configuration','CPU_GG_REPRESENTATIVE_TEST_PROFILE':'16-trial reduced profile','CPU_GG_REAL_TRACE_COMPONENT_REPLAY':'Captured component replay'}
 handles=[Patch(facecolor=palette[m],label=labels[m]) for m in palette if m in present]
 if handles:ax.legend(handles=handles,loc='upper right',fontsize=7,frameon=False)
 fig.text(.5,.012,'Exact declared profiles; *descriptive profile Geomean. Full-application extrapolation error is uncalibrated.',ha='center',fontsize=8)
 ax.grid(axis='y',alpha=.2);ax.spines[['top','right']].set_visible(False);fig.tight_layout(rect=(0,.05,1,1))
 for ext in ['png','pdf','svg']:fig.savefig(paper/f'parsec8-slowdown.{ext}',dpi=180)
 plt.close(fig)
except Exception as exc:save(paper/'plot-error.json',dict(error=repr(exc),created_utc=now()))
print(json.dumps({'accepted_pairs':summary['valid_pair_count'],'requested_eight_geomean':requested_gm,'subset_geomean_by_method':by_method,'csv':str(paper/'parsec8-native-ec.csv')},indent=2))
