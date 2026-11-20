from pathlib import Path
import hashlib,json,os,shutil,datetime,ast
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');U=D/'unattended-opt4'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def save(p,j):
 p=Path(p);p.parent.mkdir(exist_ok=True,parents=True);t=p.with_name(p.name+'.tmp-r4');t.write_text(json.dumps(j,indent=2,sort_keys=True)+'\n');os.replace(t,p)
# Recovery is new and immutable; original failure/maps/proofs remain intact.
old=W/'candidates/dcache-owner-system-r2-20261111';new=W/'candidates/dcache-owner-system-r4-20261111';new.mkdir(exist_ok=False)
for n in ['config.json','input-hashes.json']:shutil.copy2(old/n,new/n)
v=(old/'verify_combination.py').read_text().replace('dcache-owner-system-r2-20261111','dcache-owner-system-r4-20261111')
needle="path=D/name;j=json.loads(path.read_text());assert j['hardware_commit']==b['hardware_commit'] and j['source_id']==b['source_id'];assert j['status'].startswith(('PASS_','COMPLETE_'));receipts[name]={'path':str(path),'sha256':sha(path),'status':j['status']}"
replace="""path=D/name;j=json.loads(path.read_text());assert j['hardware_commit']==b['hardware_commit'];assert j['status'].startswith(('PASS_','COMPLETE_'))
 if name=='Opt4-fit-dcache-owner-observed-map-r1-state.json':
  contract_path=D/'build-logs/Opt4-fit-dcache-owner-observed-map-r1-20261111/source-contract.json';contract=json.loads(contract_path.read_text())
  validation=json.loads((D/'Opt4-fit-dcache-owner-memory-validation-r3-state.json').read_text())
  mapcfg_path=W/'candidates/dcache-owner-observed-map-r1-20261111/config.json';mapcfg=json.loads(mapcfg_path.read_text())
  assert mapcfg['binding']['hardware_commit']==b['hardware_commit'] and mapcfg['binding']['source_id']==b['source_id']
  assert contract['hardware_commit']==b['hardware_commit'] and contract['source_sha256']==j['source_validation_receipt']==validation['source_sha256']==sha(src)
  assert validation['source_id']==b['source_id']
  binding_receipt=dict(schema='ec-opt4-existing-map-source-binding/1',hardware_commit=b['hardware_commit'],source_id=b['source_id'],original_receipt=str(path),original_sha256=sha(path),contract_sha256=sha(contract_path),map_config_sha256=sha(mapcfg_path),source_sha256=sha(src),correction='Original complete map omitted source_id. Bound through immutable map config and exact source_validation_receipt; original unchanged.',complete_dcache_area=False)
  (L/'observed-map-source-binding.json').write_text(json.dumps(binding_receipt,indent=2,sort_keys=True)+'\\n')
 else:assert j['source_id']==b['source_id']
 receipts[name]={'path':str(path),'sha256':sha(path),'status':j['status']}"""
assert needle in v;v=v.replace(needle,replace);ast.parse(v);(new/'verify_combination.py').write_text(v)
s=(old/'controller.py').read_text().replace('dcache-owner-system-r2-20261111','dcache-owner-system-r4-20261111').replace('dcache-owner-system-r2-state.json','dcache-owner-system-r4-state.json').replace("+'-r3'","+'-r4'")
ast.parse(s);(new/'controller.py').write_text(s)
h=json.loads((new/'input-hashes.json').read_text());h={p:v for p,v in h.items() if not p.startswith(str(old))};h.update({str(new/n):sha(new/n) for n in ['config.json','controller.py','verify_combination.py']});save(new/'input-hashes.json',h)
r=json.loads((U/'requests/dcache-owner-system-r2-2210930f.json').read_text());r['spec']['name']='dcache-owner-system-r4-2210930f';r['spec']['argv']=['/usr/bin/python3',str(new/'controller.py')];r['spec']['inputs']={**h,str(new/'input-hashes.json'):sha(new/'input-hashes.json')};r['spec']['checkpoints']=[str(D/'Opt4-fit-dcache-owner-system-r4-state.json'),str(D/'Opt4-fit-dcache-owner-rtl-state.json')];r['spec']['outputs']=[str(D/'build-logs/Opt4-fit-dcache-owner-system-r4-20261111/result.json')];save(U/'requests/dcache-owner-system-r4-2210930f.json',r)
# Separate whole CAD controller; unchanged RTL/sourceid/ABI and outputs.
old=W/'candidates/update-share-svb-cad-r3-20261111/build.py';new=W/'candidates/e0-safe-overlap-cad-r4-20261111';new.mkdir(exist_ok=False)
s=old.read_text()
s=s.replace("    assert not alive,'live 9ae predecessor must be preserved'\n    assert predecessor['status'] in ['NOT_FIT_POSTOPT','FAILED_WITH_EVIDENCE'],'current FIT version has implementation/runtime priority'", """    # Latest user authorizes independent e0 DUT synthesis while9ae computes.
    # Preserve predecessor; no parallel top-level implementation.
    assert not alive or predecessor['current_stage']=='dut_synth','FIT/implementation predecessor has priority'
    mem0={l.split(':')[0]:int(l.split()[1]) for l in Path('/proc/meminfo').read_text().splitlines()}
    assert mem0['MemAvailable']>=256*2**20,'require256GiB available for reviewed overlap'
    assert shutil.disk_usage(W).free>=250*2**30
    assert float(Path('/proc/loadavg').read_text().split()[0])<96
    save(L/'overlap-admission.json',dict(schema='ec-opt4-reviewed-dual-dut/1',utc=now(),predecessor_commit=predecessor['hardware_commit'],predecessor_pid=predecessor['pid'],predecessor_start_ticks=predecessor['start_ticks'],predecessor_live=alive,available_memory_gib=mem0['MemAvailable']/2**20,free_disk_gib=shutil.disk_usage(W).free/2**30,observed_prior_whole_peak_gib=33.0,new_service_memory_max_gib=128,new_service_cpu_quota=8,scope='IndependentDUTsynthesis only; existing9ae untouched; serialize top implementation. Not aFITclaim.'))""")
# L is created before admission record; cannot save into nonexistent dir.
s=s.replace("    predecessor=read(D/'Opt4-fit-bucket-tag-cad-state.json')", "    L.mkdir(exist_ok=True)\n    predecessor=read(D/'Opt4-fit-bucket-tag-cad-state.json')",1)
a=s.index('    # Selection uses the actual completed predecessor post-opt capacity report.');z=s.index('    assert verified[',a)
s=s[:a]+"""    # Last completed whole report is evidence, never a proxy for9ae/e0.
    predecessor_report=D/'build-logs/Opt4-fit-cad-8da24a26/top-postopt-utilization.rpt'
    pr=utilization(predecessor_report);assert pr['CLB LUTs']['used']>pr['CLB LUTs']['available']
    paired=read(D/'Opt4-fit-svb-reference-map-r1-state.json')
    assert paired['status']=='COMPLETE_IDENTICAL_HARNESS_FULL_SVB_AREA_COMPARISON_NOT_WHOLE_DUT'
    assert paired['candidate_commit']==combo['svb_candidate'] and paired['lut_saved']==5075
    save(L/'selection.json',dict(hardware_commit=COMMIT,source_id=b['source_id'],decision='REVIEWED_INDEPENDENT_DUT_OVERLAP_WITH_LIVE9AE',historical_completed_report=str(predecessor_report),historical_report_sha256=sha(predecessor_report),historical_resources=pr,address_measured_ooc_lut_saving=118025,svb_measured_lut_saving=5075,whole_dut_fit_not_inferred=True,composition_receipt=combo['hardware_commit'],utc=now()))
"""+s[z:]
s=s.replace("    # The sole overlap allowed is new DUT synthesis versus predecessor opt.\n    # Do not start a second top implementation before its safe exit.", "    # Reviewed dualDUT overlap ends here. Serialize top implementation.")
needle="        if not alive or predecessor.get('status') in ['NOT_FIT_POSTOPT','FAILED_WITH_EVIDENCE']:break"
replace="""        cap=Path(predecessor['log_dir'])/'capacity.complete'
        if cap.exists() and cap.read_text().startswith('CAPACITY_FITS'):
            st.update(status='DUT_READY_PREDECESSOR_FITS_PRIORITY',ended_utc=now(),fpga_access=False);save(S,st);save(L/'result.json',st);return
        if not alive:
            assert predecessor.get('status') in ['NOT_FIT_POSTOPT','FAILED_WITH_EVIDENCE'],'review predecessor terminal state before implementation'
            break"""
assert needle in s;s=s.replace(needle,replace)
# Guard exception when instance already exists: never rewrite another job state.
s=s.replace('        if S.exists():','        if S.exists() and read(S).get("pid")==os.getpid():')
ast.parse(s);(new/'build.py').write_text(s)
spec=json.loads((U/'requests/update-share-svb-cad-r3-e0c3737f.json').read_text())['spec'];spec.update(name='e0-safe-overlap-cad-r4-e0c3737f',argv=['/usr/bin/python3',str(new/'build.py')]);spec['inputs'].pop(str(old));spec['inputs'][str(new/'build.py')]=sha(new/'build.py');save(new/'spec.json',spec)
# Protect against old never-started queued request later duplicating this CAD.
p=U/'request-results/update-share-svb-cad-r3-e0c3737f.json';prior=json.loads(p.read_text());save(new/'old-deferred-request-receipt.json',prior);save(p,dict(status='SUPERSEDED_BY_REVIEWED_DUAL_DUT_CONTROLLER',replacement=str(new/'spec.json'),reason='Explicit latest user instruction to evaluate/use ample idle resources. Same e0 RTL/ABI; new independent bounded service; old request preserved.',previous_receipt=str(new/'old-deferred-request-receipt.json')))
p=U/'campaign-policy.json';j=json.loads(p.read_text());j.update(cad_capsule=str(new/'build.py'),reviewed_overlap_controller=str(new/'spec.json'),latest_user_priority='CompleteDCache verification/map; preserve9ae; safely overlap e0 DUT only; serialize top implementation; no Native; no functional extensions');save(p,j)
print('Created recovery request and reviewed e0 overlap capsule')
