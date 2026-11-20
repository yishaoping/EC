from pathlib import Path
import ast,hashlib,json,os,shutil,subprocess,datetime
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106');D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');U=D/'unattended-opt4'
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def read(p):return json.loads(Path(p).read_text())
def save(p,j):
 p=Path(p);p.parent.mkdir(exist_ok=True,parents=True);t=p.with_name(p.name+'.tmp-recovery');t.write_text(json.dumps(j,indent=2,sort_keys=True)+'\n');os.replace(t,p)
old=W/'candidates/owner-update-sequence-system-r1-20261111';new=W/'candidates/owner-update-sequence-system-r2-20261111';new.mkdir(exist_ok=False)
expected='VERIFIED_AND_MAPPED_COMPLETE_ADDRESS_MODULE_NOT_WHOLE_DUT';wrong='VERIFIED_AND_MAPPED_MODULE_ONLY'
producer=W/'candidates/address-update-sequence-r1-20261111/controller.py';assert "status='"+expected+"'" in producer.read_text()
# Only this newly-created cheap waiting consumer is retired. No Vivado inputs,
# hardware/source files, full-map job, e0 or9ae process is signalled.
p=D/'Opt4-fit-owner-update-sequence-system-r1-state.json';st=read(p);assert st['status']=='WAITING_REAL_FULL_DCACHE_AND_ADDRESS_AREA_GATES' and not st.get('child')
name='owner-update-sequence-system-r1-99c25302';job=read(U/'jobs'/name/'state.json');assert job['child']['pid']==st['pid']
def identity(x):
 s=Path('/proc')/str(x['pid'])/'stat';v=s.read_text().rsplit(')',1)[1].split();assert v[19]==str(x['start_ticks']) and x['host_boot_id']==Path('/proc/sys/kernel/random/boot_id').read_text().strip()
identity(job);identity(st)
cmd=['sudo','-n','systemctl','kill','--kill-who=all','--signal=SIGTERM','ec-opt4-auto-'+name+'.service'];r=subprocess.run(cmd,text=True,capture_output=True);assert r.returncode==0,r.stderr
save(new/'retired-waiter-evidence.json',dict(utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),reason='Consumer expected a different completion status than the actual bound e211 producer. Retire only newly-created idle waiting service; preserve all evidence and all Vivado jobs.',old_domain_state=st,old_job_state=job,producer_sha256=sha(producer),actual_producer_completion_status=expected))
for n in ['controller.py','verify_combination.py']:
 s=(old/n).read_text().replace('owner-update-sequence-system-r1-20261111','owner-update-sequence-system-r2-20261111').replace('owner-update-sequence-system-r1-state.json','owner-update-sequence-system-r2-state.json').replace(wrong,expected);ast.parse(s);(new/n).write_text(s)
for n in ['config.json','binding.json']:shutil.copy2(old/n,new/n)
h=read(old/'input-hashes.json');h={p:v for p,v in h.items() if not p.startswith(str(old))};h.update({str(new/n):sha(new/n) for n in ['config.json','controller.py','verify_combination.py']});save(new/'input-hashes.json',h)
req=read(U/'requests'/(name+'.json'));spec=req['spec'];spec.update(name='owner-update-sequence-system-r2-99c25302',argv=['/usr/bin/python3',str(new/'controller.py')],inputs={**h,str(new/'input-hashes.json'):sha(new/'input-hashes.json')},checkpoints=[str(D/'Opt4-fit-owner-update-sequence-system-r2-state.json'),str(D/'Opt4-fit-owner-update-sequence-rtl-state.json')],outputs=[str(D/'build-logs/Opt4-fit-owner-update-sequence-system-r2-20261111/result.json')]);save(U/'requests'/(spec['name']+'.json'),req)
oldcad=W/'candidates/owner-update-sequence-cad-r1-20261111';newcad=W/'candidates/owner-update-sequence-cad-r2-20261111';newcad.mkdir(exist_ok=False)
s=(oldcad/'build.py').read_text().replace('owner-update-sequence-system-r1-20261111','owner-update-sequence-system-r2-20261111').replace('owner-update-sequence-system-r1-state.json','owner-update-sequence-system-r2-state.json').replace(wrong,expected);ast.parse(s);(newcad/'build.py').write_text(s)
r=read(U/'requests/owner-update-sequence-cad-r1-99c25302.json');r['spec'].update(name='owner-update-sequence-cad-r2-99c25302',argv=['/usr/bin/python3',str(newcad/'build.py')]);r['spec']['inputs']={p:v for p,v in r['spec']['inputs'].items() if not p.startswith(str(oldcad)) and not p.startswith(str(old))};r['spec']['inputs'].update({str(newcad/'build.py'):sha(newcad/'build.py'),str(new/'config.json'):sha(new/'config.json')});save(U/'requests/owner-update-sequence-cad-r2-99c25302.json',r)
p=U/'request-results/owner-update-sequence-cad-r1-99c25302.json';before=read(p);save(newcad/'superseded-queued-request.json',before);save(p,dict(status='SUPERSEDED_BY_STATUS_CONTRACT_RECOVERY',replacement='owner-update-sequence-cad-r2-99c25302',evidence=str(newcad/'superseded-queued-request.json')))
# Producer/consumer compatibility record covers actual source, not invented
# success samples. The area gate is still pending genuine completed reports.
sources=[producer,new/'controller.py',new/'verify_combination.py',newcad/'build.py']
for source in sources:assert expected in source.read_text() and wrong not in source.read_text()
save(new/'producer-consumer-contract.json',dict(status='PASS_BOUND_PRODUCER_CONSUMER_COMPLETION_STATUS_CONTRACT',producer_status=expected,source_sha256={str(p):sha(p) for p in sources},actual_address_area_report_still_pending=True))
p=U/'campaign-policy.json';j=read(p);j['conditional_next_combination'].update(state=str(D/'Opt4-fit-owner-update-sequence-system-r2-state.json'),request=str(U/'requests/owner-update-sequence-system-r2-99c25302.json'),cad_request=str(U/'requests/owner-update-sequence-cad-r2-99c25302.json'),status_contract=str(new/'producer-consumer-contract.json'));save(p,j)
p=U/'foreground-area-owner.json';j=read(p);j['reserved_next_combination_paths']+=[str(new),str(newcad)];save(p,j)
print('Retired only new idle consumer; versioned status-contract recovery submitted')
