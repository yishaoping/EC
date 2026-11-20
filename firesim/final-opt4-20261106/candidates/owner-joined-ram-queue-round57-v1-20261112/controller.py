#!/usr/bin/python3
"""Connected actual queues, adapter and RAM; no arbitrary RAM endpoint."""
import argparse
import fcntl
import importlib.util
import json
import os
from pathlib import Path
import re
import resource
import shutil
import subprocess
import sys
import time

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D/'unattended-opt4'
O = D/'build-logs/Opt4-owner-joined-ram-queue-round57-v1-20261112'
S = D/'Opt4-owner-joined-ram-queue-round57-v1-state.json'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, live, now, read, save, sha

BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
QPATH = W/'candidates/owner-queue-adapter-round56-v1-20261112/controller.py'
TPATH = W/'candidates/owner-ram-transaction-round55-v1-20261112/controller.py'


def module(path, name):
    spec = importlib.util.spec_from_file_location(name, path)
    obj = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(obj)
    return obj


Q = module(QPATH, 'queue_lemma')
T = module(TPATH, 'transaction_lemma')


def policy():
    p = read(U/'campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE and p['area_equivalence_only']
    assert p['native_paused'] and not p['fpga_access']
    assert not p['functional_extensions_allowed']


def write_new(path, value):
    with Path(path).open('x') as f:
        f.write(value if isinstance(value, str) else json.dumps(value, indent=2, sort_keys=True)+'\n')


PROOF_PORTS = {
    'watch_address': ('input', '[8:0]'),
    'word': ('output', '[80:0]'),
    'phases': ('output', '[69:0]'),
    'advance': ('output', ''),
    'write_complete': ('output', ''),
    'write_enable': ('output', ''),
    'read_address': ('output', '[8:0]')}


def observe_adapter(raw, model):
    """Preserve the model instance and all adapter equations exactly."""
    match = re.search(r'  RamModel model \(.*?\n  \);', raw, re.S)
    assert match and raw.count('RamModel model (') == 1
    pins = Q.ports(model)
    bindings = dict(re.findall(r'\.(\w+)\((\w+)\)', match[0]))
    assert set(pins) == set(bindings)
    extras = [f', output {width} cut_{pin}' for pin, (_, width) in pins.items()]
    extras += [f', {direction} {width} proof_{pin}' for pin, (direction, width) in PROOF_PORTS.items()]
    extras = '\n'+'\n'.join(extras)+'\n'
    aliases = '\n'.join(f'assign cut_{pin} = {bindings[pin]};' for pin in pins)+'\n'
    more = ',\n'+',\n'.join(f'.proof_{pin}(proof_{pin})' for pin in PROOF_PORTS)
    observed_instance = match[0].replace('\n  );', more+'\n  );', 1)
    observed = raw[:match.start()]+observed_instance+raw[match.end():]
    observed = observed.replace('\n);', extras+'\n);', 1).replace('endmodule', aliases+'endmodule', 1)
    reversal = observed.replace(extras+'\n);', '\n);', 1).replace(aliases, '', 1)
    reversal = reversal.replace(observed_instance, match[0], 1)
    assert reversal == raw
    return observed


def monitor(low, names):
    """Reference memory plus snapshot-tag FIFO, independent of actual RAM data."""
    readers = Q.READERS
    vectors = {
        'cmd_valid': [f'ram_channels_read_cmds_{i}_valid' for i in range(35)],
        'cmd_ready': [f'ram_channels_read_cmds_{i}_ready' for i in range(35)],
        'cmd_address': [f'ram_channels_read_cmds_{i}_bits_addr' for i in range(35)],
        'rsp_valid': [f'ram_channels_read_resps_{i}_valid' for i in range(35)],
        'rsp_ready': [f'ram_channels_read_resps_{i}_ready' for i in range(35)],
        'rsp_data': [f'ram_channels_read_resps_{i}_bits[{low} +: 9]' for i in range(35)],
        'response_counts': [names[r+'_data']+'_count' for r in readers],
        'response_d0': [names[r+'_data']+f'_d0[{low} +: 9]' for r in readers],
        'response_d1': [names[r+'_data']+f'_d1[{low} +: 9]' for r in readers],
        'response_outputs': [names[r+'_data']+f'_data[{low} +: 9]' for r in readers],
        'response_out_valid': [names[r+'_data']+'_out_valid' for r in readers],
        'response_out_ready': [names[r+'_data']+'_out_ready' for r in readers]}
    widths = {'cmd_address':315, 'rsp_data':315, 'response_counts':70,
        'response_d0':315, 'response_d1':315, 'response_outputs':315}
    body = [f'wire [{widths.get(name,35)-1}:0] {name} = {{'+', '.join(reversed(items))+'};'
        for name, items in vectors.items()]
    write = {key:names['MPORT_'+key] for key in ['en', 'mask', 'addr', 'data']}
    valid = ' && '.join(write[key]+'_count != 0' for key in write)
    body.append(f'''
wire [1:0] selected_phase = model_phases[2*watched_reader +: 2];
wire selected_accept = cmd_valid[watched_reader] && cmd_ready[watched_reader];
wire [8:0] selected_address = cmd_address[9*watched_reader +: 9];
wire [8:0] selected_response = rsp_data[9*watched_reader +: 9];
wire selected_response_valid = rsp_valid[watched_reader];
wire response_push = selected_response_valid && rsp_ready[watched_reader];
wire response_pop = response_out_valid[watched_reader] && response_out_ready[watched_reader];
wire [1:0] response_count = response_counts[2*watched_reader +: 2];
wire [8:0] response_head = response_d0[9*watched_reader +: 9];
wire [8:0] response_tail = response_d1[9*watched_reader +: 9];
wire [8:0] response_output = response_outputs[9*watched_reader +: 9];
wire [34:0] acquired;
genvar g;
generate for(g=0; g<35; g=g+1) begin: acq
 assign acquired[g] = model_phases[2*g +: 2] != 0;
end endgenerate
wire reference_write = (&acquired) && !model_write_complete && ({valid})
 && {write['en']}_head && {write['mask']}_head && !reset;
reg [8:0] abstract_word, expected_snapshot;
reg tracked;
reg head_tracked, tail_tracked;
reg [8:0] expected_head, expected_tail;
reg [8:0] previous_address;
reg [5:0] previous_reader;
always @(posedge clock) begin
 previous_address <= watched_address;
 previous_reader <= watched_reader;
 if(reference_write && {write['addr']}_head == watched_address)
  abstract_word <= {write['data']}_head[{low} +: 9];
 if(reset || model_advance) tracked <= 0;
 else if(selected_accept) begin
  tracked <= selected_address == watched_address;
  expected_snapshot <= abstract_word;
 end
 if(reset) begin head_tracked <= 0; tail_tracked <= 0; end
 else if(response_pop) begin
  if(response_count == 2) begin
   head_tracked <= tail_tracked; expected_head <= expected_tail;
  end else if(response_push) begin
   head_tracked <= tracked; expected_head <= expected_snapshot;
  end
  if(response_push && response_count == 2) begin
   tail_tracked <= tracked; expected_tail <= expected_snapshot;
  end
 end else if(response_push) begin
  if(response_count == 0) begin
   head_tracked <= tracked; expected_head <= expected_snapshot;
  end else begin
   tail_tracked <= tracked; expected_tail <= expected_snapshot;
  end
 end
end
assign selector_legal = watched_reader < 35;
assign selectors_stable = watched_address == previous_address && watched_reader == previous_reader;
assign word_relation = model_word[{low} +: 9] == abstract_word;
assign transaction_relation = word_relation && (!tracked || selected_phase != 0)
 && (!tracked || !selected_response_valid || selected_response == expected_snapshot)
 && (response_count == 0 || !head_tracked || response_head == expected_head)
 && (response_count != 2 || !tail_tracked || response_tail == expected_tail);
assign delivered_snapshot = !response_out_valid[watched_reader] || !head_tracked
 || response_output == expected_head;
assign write_order = model_write_enable == reference_write
 && !(model_write_enable && (|(cmd_valid & cmd_ready)));
''')
    return '\n'.join(body)


def build_source(low, mutation=None):
    e = C/'evidence'
    raw = (e/'ownerImageMemory_flattened.sv').read_text()
    model = (e/'RamModel.sv').read_text()
    observed_model = T.observe(model)
    if mutation:
        location, old, new = mutation
        text = raw if location == 'adapter' else observed_model
        assert text.count(old) == 1, ('ineffective mutation', old)
        text = text.replace(old, new, 1)
        if location == 'adapter': raw = text
        else: observed_model = text
    harness = Q.harness(raw, model)
    harness = harness.replace('module OwnerQueueAdapter(', 'module OwnerJoinedRamQueue(', 1)
    harness = re.sub(r'\brelation\b', 'queue_relation', harness)
    harness = re.sub(r'\bobservations\b', 'queue_observations', harness)
    for pin, (direction, width) in Q.ports(model).items():
        if direction == 'output':
            line = f'input {width} ram_{pin},\n'
            assert harness.count(line) == 1
            harness = harness.replace(line, '', 1)
    extra_ports = ('input [8:0] watched_address, input [5:0] watched_reader,\n'
        'output transaction_relation, output word_relation, output selector_legal,\n'
        'output selectors_stable, output delivered_snapshot, output write_order,\n')
    harness = harness.replace('output queue_relation', extra_ports+'output queue_relation', 1)
    match = re.search(r'ownerImageMemory_flattened dut\(.*?\);', harness, re.S)
    assert match
    more = ['.proof_watch_address(watched_address)']
    for pin, (direction, width) in PROOF_PORTS.items():
        if direction == 'output':
            more.append(f'.proof_{pin}(model_{pin})')
    instance = match[0][:-2]+',\n'+',\n'.join(more)+');'
    harness = harness[:match.start()]+instance+harness[match.end():]
    wires = '\n'.join(f'wire {width} model_{pin};' for pin, (direction, width) in PROOF_PORTS.items() if direction == 'output')
    harness = harness.replace('wire q0_in_valid', wires+'\nwire q0_in_valid', 1)
    commands = sorted({n[:-len('_sink_valid')] for n in Q.ports(raw) if n.endswith('_sink_valid')})
    responses = sorted({n[:-len('_source_valid')] for n in Q.ports(raw) if n.endswith('_source_valid')})
    names = {stem:'q'+str(i) for i, stem in enumerate(commands+responses)}
    assert len(names) == 109
    harness = harness.replace('endmodule', monitor(low,names)+'\nendmodule',1)
    assert not re.search(r'input\s*(?:\[[^]]+\])?\s*ram_', harness)
    sources = [observe_adapter(raw,model), observed_model]
    sources += [Q.observe_queue((e/n).read_text()) for n in ['ShiftQueue_30.sv','ShiftQueue_40.sv','ShiftQueue_86.sv']]
    sources += [Q.observe_pipe((e/n).read_text()) for n in ['PipeChannel.sv','PipeChannel_10.sv','PipeChannel_56.sv']]
    return '\n'.join(sources+[harness])


def prepare():
    policy()
    assert not (C/'plan.json').exists()
    e = C/'evidence'; e.mkdir()
    originals = {}
    for path in sorted((Q.C/'evidence').iterdir()):
        originals[str(path)] = sha(path)
        shutil.copyfile(path,e/path.name)
    for name, prior in [('queue',Q.O),('transaction',T.O)]:
        r, complete = read(prior/'result.json'), read(prior/'complete.json')
        assert complete['result_sha256'] == sha(prior/'result.json')
        assert r['functional_baseline'] == BASE and r['status'].startswith('PASS_')
        assert all(sha(p)==h for p,h in r['inputs'].items())
        assert all(x['returncode']==0 for x in r['proof_receipts'])
        assert all(x['returncode']!=0 for x in r['mutation_receipts'])
        for leaf in ['result.json','complete.json']:
            path=prior/leaf; originals[str(path)]=sha(path)
            shutil.copyfile(path,e/(name+'-'+leaf))
    source = build_source(0)
    write_new(C/'preflight.json',dict(status='PASS_CONNECTED_EMITTED_RAM_AND_ALL109_QUEUES_OBSERVATION_REVERSAL',
        source_sha256=__import__('hashlib').sha256(source.encode()).hexdigest(),
        ram_endpoint_cut=False,memory_read_cut=False,queue_count=109,
        queue_lemma_assumed=True,complete_fame_equivalence=False))
    inputs = {str(p):sha(p) for p in [C/'controller.py',C/'README.md',C/'preflight.json',QPATH,TPATH,
        W/'scripts/opt4_unattended_common.py',*sorted(e.iterdir())]}
    plan = dict(schema='ec-owner-joined-ram-queue-plan/1',functional_baseline=BASE,
        hardware_commit='3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c',
        source_id='79aedd9ada6137e018d7f9c9c175fd4a06f53820d235ddcbe4b4a185e75fd68d',
        inputs=inputs, originals=originals,cpu=249,memory_limit_gib=8,
        yosys='/usr/local/bin/yosys',yosys_sha256=sha('/usr/local/bin/yosys'),
        ram_endpoint_cut=False,target_changed=False,fpga_access=False,whole_fit=False)
    write_new(C/'plan.json',plan)
    request=dict(action='cpu_job',spec=dict(name='owner-joined-ram-queue-r57-v1-3656aec4',kind='proof',
        cwd=str(C),argv=['/usr/bin/python3',str(C/'controller.py'),'--run'],
        inputs={**inputs,str(C/'plan.json'):sha(C/'plan.json')},
        outputs=[str(O/'complete.json')],checkpoints=[str(S)]))
    write_new(C/'request.json',request)
    print('PREPARED_CONNECTED_OWNER_RAM_QUEUES_NO_RAM_ENDPOINT_CUT')


def run():
    policy()
    plan = read(C/'plan.json')
    assert all(sha(p)==h for p,h in plan['inputs'].items())
    assert sha(plan['yosys']) == plan['yosys_sha256']
    if (O/'complete.json').exists():
        assert read(O/'complete.json')['result_sha256']==sha(O/'result.json')
        print('IMMUTABLE_JOINED_RAM_QUEUE_PROOF_REVALIDATED'); return
    O.mkdir(parents=True,exist_ok=True)
    lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(), 'Preserve partial evidence; use a new recovery version'
    for row in read(U/'snapshot.json')['states'].values():
        if row.get('identity_live'):
            for p in [row,row.get('child',{}),row.get('stage_process',{}),*row.get('worker_processes',[])]:
                if live(p):
                    affinity=os.sched_getaffinity(p['pid'])
                    assert len(affinity)>8 or plan['cpu'] not in affinity, ('CPU conflict',p['pid'])
    os.sched_setaffinity(0,{plan['cpu']})
    resource.setrlimit(resource.RLIMIT_AS,(8*2**30,8*2**30))
    state=dict(schema='ec-owner-joined-ram-queue-proof/1',**identity(),started_utc=now(),
        functional_baseline=BASE,hardware_commit=plan['hardware_commit'],source_id=plan['source_id'],
        cpu=plan['cpu'],ram_endpoint_cut=False,memory_read_cut=False,target_changed=False,
        fpga_access=False,whole_fit=False,complete_fame_equivalence=False,complete_dcache_equivalence=False)

    def status(value,**extra):
        state.update(status=value,updated_utc=now(),**extra);save(O/'state.json',state);save(S,state)

    def stage(label,source,command,positive):
        policy()
        v,y,log=[O/(label+s) for s in ['.sv','.ys','.log']]
        write_new(v,source)
        write_new(y,f'read_verilog -sv -DSYNTHESIS {v}\nprep -top OwnerJoinedRamQueue -flatten\n'
            'memory_map\nopt -full\nopt_clean\n'+command+'\n')
        started=time.monotonic()
        with log.open('xb') as stream:
            child=subprocess.Popen([plan['yosys'],'-s',str(y)],cwd=C,
                stdin=subprocess.DEVNULL,stdout=stream,stderr=subprocess.STDOUT)
            status('RUNNING_'+label,child=identity(child.pid),stage_log=str(log))
            try:code=child.wait(timeout=420)
            except subprocess.TimeoutExpired:
                child.kill();code=child.wait();raise RuntimeError(('Timeout is not PASS',label,code))
        receipt=dict(label=label,returncode=code,seconds=time.monotonic()-started,
            source_sha256=sha(v),script_sha256=sha(y),log_sha256=sha(log))
        save(O/(label+'-receipt.json'),receipt)
        text=log.read_text()
        if positive:assert code==0 and 'SUCCESS!' in text,receipt
        else:assert code!=0 and 'proof did fail' in text and 'TIMEOUT' not in text and 'syntax error' not in text,receipt
        return receipt

    try:
        common='-set selector_legal 1 -set selectors_stable 1 -set queue_relation 1 -set queue_observations 1 '
        reset='sat -seq 2 '+common+'-set-at 1 reset 1 -set-at 1 word_relation 1 -prove-skip 1 -prove transaction_relation 1 -verify -timeout 240'
        step='sat -seq 2 '+common+'-set-at 1 transaction_relation 1 -prove-skip 1 -prove transaction_relation 1 -verify -timeout 240'
        observation='sat -seq 1 '+common+'-set transaction_relation 1 -prove delivered_snapshot 1 -prove write_order 1 -verify -timeout 240'
        proofs=[]
        for low in range(0,81,9):
            source=build_source(low)
            proofs.append(stage(f'bits-{low}-{low+8}-reset',source,reset,True))
            proofs.append(stage(f'bits-{low}-{low+8}-step',source,step,True))
        proofs.append(stage('delivered-and-write-order',build_source(0),observation,True))
        mutants=[('read-address',('model','assign data_read_data_async_data = data[data_read_data_async_addr];',
            "assign data_read_data_async_data = data[data_read_data_async_addr ^ 9'h001];"),0),
            ('write-high-bit',('model','assign data_MPORT_data = channels_write_cmds_0_bits_data;',
            "assign data_MPORT_data = channels_write_cmds_0_bits_data ^ 81'h100000000000000000000;"),72),
            ('held-response',('model',"assign channels_read_resps_34_bits = read_state_34 == 2'h1 ? read_data : read_resp_data_34;",
            'assign channels_read_resps_34_bits = read_data;'),0)]
        negatives=[stage('negative-'+label,build_source(low,mutation),step,False)
            for label,mutation,low in mutants]
        result={**state,'status':'PASS_CONNECTED_109QUEUES_ADAPTER_AND_35R1W_RAM_SNAPSHOTS_WITH_QUEUE_LEMMA',
            'completed_utc':now(),'child':{},'proof_receipts':proofs,'mutation_receipts':negatives,
            'queue_count':109,'readers':35,'memory_words':512,'payload_bits':81,
            'queue_lemma_assumed':True,'queue_lemma_result_sha256':sha(C/'evidence/queue-result.json'),
            'watched_address_and_reader_arbitrary':True,'payload_reset_initialization_assumed':False,
            'inputs':plan['inputs'],'plan_sha256':sha(C/'plan.json'),
            'limitations':['FIFO invariants/atomic joins are assumed from the exact bound round56 universal proof.',
                'RAM endpoints are physically connected; no arbitrary RAM ready/valid/data endpoint remains.',
                'Conditional related arbitrary-memory base; no reset-defined target-memory contents.',
                'FAME target advance, clock/reset tokens and complete target transition equivalence remain unproved.',
                'No full DCache/Opt4 equivalence, liveness, measured area/FIT, bitstream or FPGA admission.']}
        save(O/'result.json',result);save(O/'complete.json',dict(result_sha256=sha(O/'result.json'),completed_utc=now()))
        status(result['status'],child={},result_sha256=sha(O/'result.json'));print(result['status'])
    except Exception as exc:
        status('FAILED_WITH_EVIDENCE',child={},error=repr(exc));save(O/'failure.json',state);raise


if __name__=='__main__':
    ap=argparse.ArgumentParser();ap.add_argument('--prepare',action='store_true');ap.add_argument('--run',action='store_true')
    a=ap.parse_args();assert a.prepare != a.run
    prepare() if a.prepare else run()
