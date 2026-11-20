#!/usr/bin/python3
"""Read-only job/schema preflight. Never submits jobs or opens a device."""
from pathlib import Path
import ast,datetime,hashlib,importlib.util,json,os,sys
C=Path(__file__).resolve().parent;W=C.parents[1]
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106');U=D/'unattended-opt4'
sys.path.insert(0,str(W/'scripts'))
from opt4_unattended_common import bound_inputs
from opt4_frozen_scope import enforce
S=W/'candidates/full-svb-binary-replay-r1-20261111';G=W/'candidates/full-svb-gg-stream-replay-r3-20261111';G2=G.with_name('full-svb-gg-stream-replay-r2-20261111');OBS=S.with_name('full-gg-external-observer-r5-20261111')
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def read(p):return json.loads(Path(p).read_text())
def save(p,v):
 tmp=p.with_name(p.name+'.tmp-'+str(os.getpid()))
 with tmp.open('x') as f:json.dump(v,f,indent=2,sort_keys=True);f.write('\n');f.flush();os.fsync(f.fileno())
 os.replace(tmp,p)
# All existing future executable/source inputs must pass the actual root/hash guard.
static_s=[S/n for n in ['run.py','prepare.py','plan.json','binary-layout.json','dispatch.py','replay.cpp','replay']]+[OBS/'validate_binary.py',OBS/'controller.py']
s_inputs={str(p):sha(p) for p in static_s}
spec_s=dict(name='full-svb-binary-replay-r1-full-8491167d',kind='analysis',cwd=str(S),argv=['/usr/bin/python3',str(S/'run.py'),'--full'],inputs=s_inputs,outputs=[str(D/'cycleprecise-original-svb-binary-replay-r1-20261111/full-result.json')])
assert len(bound_inputs(spec_s))==len(s_inputs);scope_s=enforce(spec_s)
g_inputs=dict(read(G/'plan.json')['inputs'])
for p in [G/'run.py',G/'dispatch.py',G/'plan.json']:g_inputs[str(p)]=sha(p)
spec_g=dict(name='full-svb-gg-stream-replay-r3-full-8491167d',kind='analysis',cwd=str(G),argv=['/usr/bin/python3',str(G/'run.py'),'--full'],inputs=g_inputs,outputs=[str(D/'cycleprecise-original-svb-gg-stream-replay-r3-20261111/full-result.json'),str(D/'cycleprecise-original-svb-gg-stream-replay-r3-20261111/board-admission-ready.json')])
assert len(bound_inputs(spec_g))==len(g_inputs);scope_g=enforce(spec_g)
# Reproduce the earlier incorrect root classification, then test its exact staged copy.
actual=D/'cycleprecise-original-svb-binary-replay-r1-20261111/build-receipt.json';capsule=C/'evidence-capsule';capsule.mkdir(exist_ok=True);copy=capsule/(sha(actual)[:16]+'-build-receipt.json')
if not copy.exists():copy.write_bytes(actual.read_bytes())
assert sha(copy)==sha(actual)
bad={**spec_s,'inputs':{**s_inputs,str(actual):sha(actual)}}
try:bound_inputs(bad)
except AssertionError as e:bad_rejected='input root/file' in str(e)
else:bad_rejected=False
assert bad_rejected,'ORIGINAL_D_DIRECT_CLASSIFICATION_DID_NOT_REJECT'
good={**spec_s,'inputs':{**s_inputs,str(copy):sha(copy)}}
assert len(bound_inputs(good))==len(s_inputs)+1
assert "old=read(U/'jobs/full-svb-binary-replay-r1-8491167d/spec.json')" not in (S/'dispatch.py').read_text()
# Validate that the runtime controller explicitly emits the follower's exact admission schema.
tree=ast.parse((G/'run.py').read_text());full=next(x for x in tree.body if isinstance(x,ast.FunctionDef) and x.name=='full')
admission=next(x.value for x in ast.walk(full) if isinstance(x,ast.Assign) and any(isinstance(t,ast.Name) and t.id=='admission' for t in x.targets))
assert isinstance(admission,ast.Call) and isinstance(admission.func,ast.Name) and admission.func.id=='dict'
fields={x.arg:x.value for x in admission.keywords}
required=['status','functional_baseline','profile','source_id','board_allowlist','driver','driver_sha256','driver_args','required_driver_args','host_rtl_sha256','control_header_sha256','trace','trace_sha256','trace_records','expected_summary','cpu_proof','cpu_proof_sha256','fpga_access','complete_opt4']
assert not set(required)-set(fields),('MISSING_ADMISSION_SCHEMA_KEYS',set(required)-set(fields))
assert ast.literal_eval(fields['driver_args'])==['+svb-force-all-inputs']
assert ast.literal_eval(fields['fpga_access']) is False and ast.literal_eval(fields['complete_opt4']) is False
assert ast.literal_eval(fields['status'])=='READY_FOR_CONTROLLED_21_ONLY_BOARD_ADMISSION_NOT_EXECUTED'
req_args=fields['required_driver_args'];assert isinstance(req_args,ast.List)
assert [ast.literal_eval(x) for x in req_args.elts[:-1]]==['+svb-force-all-inputs','+domain=0000','+bus=21','+device=00','+function=0','+bar=0']
run_text=(G/'run.py').read_text();assert "[str(C2/'VSVBStreamingReplay'),'+svb-force-all-inputs'" in run_text
assert "negative=replay(trace,'application-payload-negative',budget,True)" in run_text
assert "summary['records']==summary['target_cycles']==records" in run_text and "summary['input_cache_enabled']==0" in run_text
assert '3*measured*records+600' in run_text and 'budget<=24*3600' in run_text
out=D/'svb-replay-chain-preflight-r1-20261111';out.mkdir(exist_ok=True)
value=dict(schema='ec-svb-replay-chain-preflight/1',status='PASS_STATIC_ROOT_HASH_FROZEN_SCOPE_FORCEALL_ADMISSION_SCHEMA',fpga_access=False,baseline='8491167d84b6d9521b151a743673c1516926a1f8',standalone_static_bound_inputs=len(s_inputs),gg_static_bound_inputs=len(g_inputs),original_direct_D_receipt_rejected=bad_rejected,staged_W_receipt_passed=True,legacy_missing_job_spec_dependency_removed=True,force_all_mandatory=True,admission_schema_required_keys=required,full_timeout_scope='Actualmeasuredperrecord*recordcount*3+600,cap24h; nofullapplicationdataadmittedbythispreflight',root_scope_standalone=scope_s,root_scope_gg=scope_g,observed_state={str(p):read(p) for p in [D/'Opt4-full-gg-external-observer-r5-state.json',D/'Opt4-original-svb-binary-replay-r1-dispatch-state.json',D/'Opt4-original-svb-gg-stream-replay-r3-dispatch-state.json']},evidence={str(p):sha(p) for p in [S/'dispatch.py',S/'dispatch-before-direct-receipt-fix.py',S/'run.py',G/'dispatch.py',G/'run.py',G/'plan.json',W/'scripts/opt4_unattended_common.py',W/'scripts/opt4_frozen_scope.py',Path(__file__)]},limitations=['Existingstaticinputs/scope/schemaonly; completeapplicationtrace notyetfinished','No futurefulldataorrealFPGAvalidationclaimed','No rootbroker mutation/jobsubmission/devicesaccess'],completed_utc=datetime.datetime.now(datetime.timezone.utc).isoformat())
save(out/'result.json',value);print(json.dumps({k:v for k,v in value.items() if k not in ['observed_state','evidence','limitations','admission_schema_required_keys']},indent=2))
