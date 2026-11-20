from pathlib import Path
import ast,hashlib,json,os
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');U=D/'unattended-opt4';B=W/'candidates/owner-update-sequence-system-r1-20261111';b=json.loads((B/'binding.json').read_text());COM=b['hardware_commit'];C=W/'candidates/owner-update-sequence-cad-r1-20261111';C.mkdir(exist_ok=False)
def save(p,j):
 p=Path(p);p.parent.mkdir(parents=True,exist_ok=True);t=p.with_name(p.name+'.tmp-cad');t.write_text(json.dumps(j,indent=2,sort_keys=True)+'\n');os.replace(t,p)
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
s=(W/'candidates/e0-safe-overlap-cad-r4-20261111/build.py').read_text()
s=s.replace('e0c3737f989c563f99a00f3fd26c1cbd27421775',COM).replace("F = W/'Opt4-fit-update-share-svb-r2-20261111'","F = W/'Opt4-fit-owner-update-sequence-r1-20261111'")
s=s.replace("('Opt4-fit-update-share-svb-cad-'+COMMIT[:8])","('Opt4-fit-owner-update-sequence-cad-'+COMMIT[:8])").replace('Opt4-fit-update-share-svb-cad-state.json','Opt4-fit-owner-update-sequence-cad-state.json').replace('Opt4-fit-update-share-svb-rtl-state.json','Opt4-fit-owner-update-sequence-rtl-state.json').replace('Opt4-fit-C4-SVB32-update-share-svb-compose-r2','Opt4-fit-C4-SVB32-owner-update-sequence-r1').replace('.opt4-fit-update-share-svb-cad.lock','.opt4-fit-owner-update-sequence-cad.lock')
a=s.index("    L.mkdir(exist_ok=True)\n    predecessor=read(");z=s.index('    O.mkdir(parents=True, exist_ok=True)',a)
s=s[:a]+"""    L.mkdir(exist_ok=True)
    # Third full synthesis is forbidden; broker admission and these identities
    # must both establish that prior whole jobs have reached a safe boundary.
    for path in [D/'Opt4-fit-bucket-tag-cad-state.json',D/'Opt4-fit-update-share-svb-cad-state.json']:
        previous=read(path);ident=proc(previous.get('pid',0))
        alive=bool(ident and previous.get('host_boot_id')==boot() and ident['start_ticks']==str(previous.get('start_ticks')) and ident['process_state'] not in ['X','Z'])
        assert not alive,'live whole predecessor preserved; defer this next CAD'
        cap=Path(previous['log_dir'])/'capacity.complete'
        assert not cap.exists() or not cap.read_text().startswith('CAPACITY_FITS'),'existing FIT design has implementation/runtime priority'
    predecessor=read(D/'Opt4-fit-update-share-svb-cad-state.json')
"""+s[z:]
a=s.index('    # Exact validated combined candidate;');z=s.index('    assert r[\'source_id\']',a)
s=s[:a]+"""    # Admit only actual matched full module gain and exact component proofs.
    prep=read(D/'Opt4-fit-owner-update-sequence-system-r1-state.json')
    assert prep['status']=='RTL_READY_REAL_ABI_CHECKED' and prep['hardware_commit']==COMMIT and prep['source_id']==b['source_id']
    combo_path=D/'build-logs/Opt4-fit-owner-update-sequence-system-r1-20261111/combined-equivalence.json'
    combo=read(combo_path);assert combo['hardware_commit']==COMMIT and combo['source_id']==b['source_id'] and combo['source_files_exact_components'] and not combo['architectural_recovery_added']
    full=read(D/'Opt4-fit-dcache-full-pair-r1-state.json');address=read(D/'Opt4-fit-address-update-sequence-r1-state.json')
    assert full['status']=='COMPLETE_REAL_FULL_DCACHE_OBSERVED_PAIR_NOT_WHOLE_DUT_FIT' and full['lut_saved']>=75000
    assert address['status']=='VERIFIED_AND_MAPPED_MODULE_ONLY' and address['full_module_map']['resources']['CLB LUTs']<872880
    for row in list(full['maps'].values())+[address['full_module_map']]:assert sha(row['report'])==row['report_sha256']
    policy=read(D/'unattended-opt4/campaign-policy.json');assert policy['functional_baseline_commit']==b['frozen_commit'] and policy['area_equivalence_only'] and not policy['functional_extensions_allowed']
    save(L/'selection.json',dict(hardware_commit=COMMIT,source_id=b['source_id'],decision='VERIFIED_EXACT_COMPONENT_COMPOSITION_AND_ACTUAL_FULL_MODULE_GAIN',composition_sha256=sha(combo_path),full_dcache_pair=full['maps'],address_full_module=address['full_module_map'],whole_dut_fit_not_inferred=True,utc=now()))
"""+s[z:]
# Pending GoldenGate failure must surface as evidence, never fallback to oldRTL.
s=s.replace("        r = read(R) if R.exists() else {}", "        r = read(R) if R.exists() else {}\n        control=read(D/'Opt4-fit-owner-update-sequence-system-r1-state.json')\n        assert control.get('status') not in ['FAILED_WITH_EVIDENCE','DEPENDENCY_FAILED_WITH_EVIDENCE','NOT_SELECTED_NO_SIGNIFICANT_COMBINED_MODULE_GAIN'],'candidate preparation/area failed; preserve evidence'")
# Keep top implementation serialized after DUT stage (all earlier CADs exited).
a=s.index('    # Reviewed dualDUT overlap ends here.');z=s.index("    topdir=O/",a)
s=s[:a]+"    # Prior whole identities were checked before admission; no peer CAD is launched by the broker while this service owns its slot.\n"+s[z:]
ast.parse(s);(C/'build.py').write_text(s)
spec=dict(name='owner-update-sequence-cad-r1-'+COM[:8],kind='cad',cwd=str(W/'Opt4-fit-owner-update-sequence-r1-20261111/chipyard'),argv=['/usr/bin/python3',str(C/'build.py')],inputs={str(C/'build.py'):sha(C/'build.py'),str(B/'config.json'):sha(B/'config.json'),str(W/'Opt4-fit-owner-update-sequence-r1-20261111/bindings'/f'{COM}.json'):sha(W/'Opt4-fit-owner-update-sequence-r1-20261111/bindings'/f'{COM}.json')},checkpoints=[str(D/'Opt4-fit-owner-update-sequence-cad-state.json')],outputs=[str(D/'build-logs'/('Opt4-fit-owner-update-sequence-cad-'+COM[:8])/'result.json')]);save(U/'requests'/(spec['name']+'.json'),dict(action='cpu_job',spec=spec))
runtime=dict(schema='ec-opt4-runtime-candidate/1',commit=COM,source_id=b['source_id'],profile=b['profile'],worktree=str(W/'Opt4-fit-owner-update-sequence-r1-20261111'),cad_state=str(D/'Opt4-fit-owner-update-sequence-cad-state.json'),rtl_state=str(D/'Opt4-fit-owner-update-sequence-rtl-state.json'),state_prefix='Opt4-fit-owner-update-sequence',board_bdf='0000:21:00.0',board_serial='21770433G02LA');p=W/'runtime-candidates'/f'{COM[:8]}.json';save(p,runtime)
# Same reviewed runtime generator; no board action until certifiedCAD and21safe boundary.
(W/'runtime'/('Opt4-fit-'+COM[:8])).mkdir(exist_ok=True)
for action in ['prepare_runtime','start_runtime']:save(U/'requests'/f'{COM[:8]}-{action.replace("_","-")}.json',dict(action=action,descriptor=str(p)))
p=U/'campaign-policy.json';j=json.loads(p.read_text());j['conditional_next_combination'].update(cad_request=str(U/'requests'/(spec['name']+'.json')),runtime_descriptor=str(W/'runtime-candidates'/f'{COM[:8]}.json'),automatic_flow='Measured fullDCache+address gains -> exact composition/typecheck/GG/7ABI -> no-livewhole CAD -> postoptcapacity -> FIT place/route/timingDRC/bitstream -> existing21only runtime authentication/smoke/checker/drain/correctness ->13ordinary first rounds. NOTFIT capacity stops beforeplace; autonomousworker continues structural candidates.');save(p,j)
print('Prepared gated full CAD and existing runtime chain',COM)
