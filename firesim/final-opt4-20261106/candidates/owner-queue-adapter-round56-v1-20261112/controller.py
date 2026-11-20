#!/usr/bin/python3
"""Prove the exact owner adapter joined with all 109 emitted token queues.

The RAM endpoint is an explicit arbitrary ready/valid cut. This proof never
claims that the cut satisfies RAM semantics or that FAME is equivalent.
"""
import argparse
import fcntl
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
O = D/'build-logs/Opt4-owner-queue-adapter-round56-v1-20261112'
STATE = D/'Opt4-owner-queue-adapter-round56-v1-state.json'
sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, live, now, read, save, sha

BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
READERS = [
    'MPORT_18', 'crossPackageWbPacketSeq_MPORT', 'safeChainLiveKey_MPORT',
    'crossPackageSvbRescue_MPORT_1', 'svbFastKey_MPORT', 'crossPackageSvbRescue_MPORT',
    'opt2bWriteKey_MPORT', 'crossPackageResidentMatch_MPORT', 'MPORT_6', 'MPORT_5',
    'MPORT_10', 'MPORT_8', 's3_l1PreservationAllowed_MPORT', 'crossPackagePendingKey_MPORT',
    'MPORT_7', 'MPORT_13', 'slowdown_opt1_pending_live_key_MPORT', 'MPORT_14',
    'crossPackageSvbRescue_MPORT_2', 'crossPackageWbReq_valid_MPORT',
    'slowdown_opt1_pending_safe_MPORT', 'MPORT_9', 'svbCaptureResidentMatch_MPORT',
    'MPORT_4', 'crossPackagePendingSeq_MPORT', 'refillPreservationAllowed_MPORT',
    'wb_io_image_key_MPORT', 's2_overwrittenKey_MPORT', 'clearFreezeReadBypassWindow_MPORT',
    'MPORT_17', 'MPORT_16', 'MPORT_15', 'MPORT_12', 'installPreservationAllowed_MPORT',
    'preservationWaitWatermark_MPORT']


def policy():
    p = read(U/'campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE and p['area_equivalence_only']
    assert p['native_paused'] and not p['fpga_access'] and not p['functional_extensions_allowed']
    return p


def write_new(path, content):
    path = Path(path)
    raw = content if isinstance(content, str) else json.dumps(content, indent=2, sort_keys=True)+'\n'
    with path.open('x') as f:
        f.write(raw)


def ports(raw):
    head = raw[:raw.index(');')]
    found = re.findall(r'\b(input|output)\s*(\[[^\]]+\])?\s*(\w+)\s*(?=,|$)', head)
    result = {name: (direction, width or '') for direction, width, name in found}
    assert len(result) == len(found)
    return result


def observe_queue(raw):
    p = ports(raw)
    width = p['io_deq_bits'][1]
    extra = (',output proof_v0, output proof_v1,\n'
        f'output {width} proof_d0, output {width} proof_d1\n')
    aliases = ('  assign proof_v0 = valid_0;\n  assign proof_v1 = valid_1;\n'
        '  assign proof_d0 = elts_0;\n  assign proof_d1 = elts_1;\n')
    assert raw.count('\n);') == 1 and raw.count('endmodule') == 1
    result = raw.replace('\n);', '\n'+extra+');', 1).replace('endmodule', aliases+'endmodule', 1)
    assert result.replace('\n'+extra+');', '\n);', 1).replace(aliases, '', 1) == raw
    return result


def observe_pipe(raw):
    p = ports(raw)
    width = p['io_out_bits'][1]
    extra = (',output proof_v0, output proof_v1,\n'
        f'output {width} proof_d0, output {width} proof_d1\n')
    bind = ',.proof_v0(proof_v0), .proof_v1(proof_v1), .proof_d0(proof_d0), .proof_d1(proof_d1)'
    assert raw.count('\n);') == 1 and raw.count('\n  );') == 1
    result = raw.replace('\n);', '\n'+extra+');', 1).replace('\n  );', '\n  '+bind+'\n  );', 1)
    assert result.replace('\n'+extra+');', '\n);', 1).replace('\n  '+bind+'\n  );', '\n  );', 1) == raw
    return result


def cut_adapter(raw, model):
    """Remove precisely the model instance, expose each of its pins instead.

    All original adapter ports, wires and equations remain byte-for-byte.
    """
    match = re.search(r'  RamModel model \(.*?\n  \);', raw, re.S)
    assert match and raw.count('RamModel model (') == 1
    assert not re.search(r'\b(reg|always|initial)\b', raw)
    bindings = dict(re.findall(r'\.(\w+)\((\w+)\)', match[0]))
    mp = ports(model)
    assert set(bindings) == set(mp) and len(set(bindings.values())) == len(bindings)
    extra, aliases = [], []
    for pin, (direction, width) in mp.items():
        # Model outputs enter the cut adapter; model inputs are observed.
        invert = 'input' if direction == 'output' else 'output'
        extra.append(f', {invert} {width} cut_{pin}')
        a, b = (bindings[pin], 'cut_'+pin) if invert == 'input' else ('cut_'+pin, bindings[pin])
        aliases.append(f'assign {a} = {b};')
    extra = '\n'+'\n'.join(extra)+'\n'
    aliases = '\n'.join(aliases)+'\n'
    result = raw[:match.start()]+raw[match.end():]
    result = result.replace('\n);', extra+'\n);', 1).replace('endmodule', aliases+'endmodule', 1)
    reversed_raw = result.replace(extra+'\n);', '\n);', 1).replace(aliases, '', 1)
    assert reversed_raw[:match.start()]+match[0]+reversed_raw[match.start():] == raw
    return result


def harness(adapter, model):
    ap, mp = ports(adapter), ports(model)
    commands = {n[:-len('_sink_valid')] for n in ap if n.endswith('_sink_valid')}
    responses = {n[:-len('_source_valid')] for n in ap if n.endswith('_source_valid')}
    expected_commands = {r+s for r in READERS for s in ['_addr', '_en']} | {'MPORT_'+s for s in ['en','mask','addr','data']}
    assert commands == expected_commands and responses == {r+'_data' for r in READERS}
    assert len(commands) == 74 and len(responses) == 35 and len(ap) == 294
    top = ['input clock', 'input reset']
    body, bindings, relation, observations = [], ['.hostClock(clock)', '.hostReset(reset)'], [], []
    names = {}

    def queue(stem, command):
        # The exact PipeChannel+ShiftQueue closure is retained for every channel.
        suffix = '_sink' if command else '_source'
        width = ap.get(stem+suffix+'_bits', ('', ''))[1]
        bits = int(re.fullmatch(r'\[(\d+):0\]', width)[1])+1 if width else 1
        module = {1:'PipeChannel', 9:'PipeChannel_56', 81:'PipeChannel_10'}[bits]
        q = 'q'+str(len(names))
        names[stem] = q
        if command:
            top.extend([f'input {q}_in_valid', f'input {width} {q}_payload'])
        else:
            top.append(f'input {q}_out_ready')
        body.extend([
            f'wire {q}_in_valid, {q}_in_ready, {q}_out_valid, {q}_out_ready;',
            f'wire {width} {q}_payload, {q}_data, {q}_d0, {q}_d1;',
            f'wire {q}_v0, {q}_v1;', f'reg [1:0] {q}_count;',
            f'reg {width} {q}_head, {q}_tail;'])
        bindings.extend([f'.{stem}{suffix}_ready({q}_out_ready)' if command else f'.{stem}{suffix}_ready({q}_in_ready)',
            f'.{stem}{suffix}_valid({q}_out_valid)' if command else f'.{stem}{suffix}_valid({q}_in_valid)'])
        if stem+suffix+'_bits' in ap:
            bindings.append(f'.{stem}{suffix}_bits({q}_data)' if command else f'.{stem}{suffix}_bits({q}_payload)')
        body.append(f'''{module} {q}(.clock(clock), .reset(reset),
 .io_in_valid({q}_in_valid), .io_in_ready({q}_in_ready), .io_in_bits({q}_payload),
 .io_out_valid({q}_out_valid), .io_out_ready({q}_out_ready), .io_out_bits({q}_data),
 .proof_v0({q}_v0), .proof_v1({q}_v1), .proof_d0({q}_d0), .proof_d1({q}_d1));''')
        relation.append(f'''({q}_count <= 2 && {q}_v0 == ({q}_count != 0) && {q}_v1 == ({q}_count == 2)
 && ({q}_count == 0 || {q}_d0 == {q}_head) && ({q}_count != 2 || {q}_d1 == {q}_tail))''')
        observations.append(f'''({q}_in_ready == ({q}_count < 2) && {q}_out_valid == ({q}_count != 0)
 && (!{q}_out_valid || {q}_data == {q}_head))''')
        return q

    for stem in sorted(commands):
        queue(stem, True)
    for stem in sorted(responses):
        queue(stem, False)
    for pin, (direction, width) in mp.items():
        signal = 'ram_'+pin
        if direction == 'output':
            top.append(f'input {width} {signal}')
        body.append(f'wire {width} {signal};')
        bindings.append(f'.cut_{pin}({signal})')
    observations.extend(['ram_clock == clock', 'ram_reset == reset'])
    reference_pop = {}
    for i, stem in enumerate(READERS):
        a, e, r = (names[stem+s] for s in ['_addr', '_en', '_data'])
        valid = f'({a}_count != 0 && {e}_count != 0)'
        fire = f'({valid} && ram_channels_read_cmds_{i}_ready)'
        reference_pop[a] = reference_pop[e] = fire
        observations.extend([
            f'(ram_channels_read_cmds_{i}_valid == {valid})',
            f'(!ram_channels_read_cmds_{i}_valid || ram_channels_read_cmds_{i}_bits_addr == {a}_head)',
            f'(({a}_out_valid && {a}_out_ready) == {fire})',
            f'(({e}_out_valid && {e}_out_ready) == {fire})',
            f'({r}_in_valid == ram_channels_read_resps_{i}_valid)',
            f'({r}_payload == ram_channels_read_resps_{i}_bits)',
            f'(ram_channels_read_resps_{i}_ready == ({r}_count < 2))'])
    write = [names['MPORT_'+field] for field in ['en','mask','addr','data']]
    valid = '('+' && '.join(q+'_count != 0' for q in write)+')'
    fire = f'({valid} && ram_channels_write_cmds_0_ready)'
    observations.append('ram_channels_write_cmds_0_valid == '+valid)
    for field, q in zip(['en','mask','addr','data'], write):
        reference_pop[q] = fire
        observations.extend([
            f'(!ram_channels_write_cmds_0_valid || ram_channels_write_cmds_0_bits_{field} == {q}_head)',
            f'(({q}_out_valid && {q}_out_ready) == {fire})'])
    for stem, q in names.items():
        pop = reference_pop[q] if stem in commands else f'({q}_count != 0 && {q}_out_ready)'
        body.append(f'''wire {q}_push = {q}_in_valid && {q}_count < 2;
wire {q}_pop = {pop};
always @(posedge clock) begin
 if (reset) {q}_count <= 0;
 else begin
  case ({{{q}_push, {q}_pop}})
   2'b10: {q}_count <= {q}_count + 1;
   2'b01: {q}_count <= {q}_count - 1;
   default: {q}_count <= {q}_count;
  endcase
  if ({q}_pop) begin
   if ({q}_count == 2) {q}_head <= {q}_tail;
   else if ({q}_push) {q}_head <= {q}_payload;
   if ({q}_push && {q}_count == 2) {q}_tail <= {q}_payload;
  end else if ({q}_push) begin
   if ({q}_count == 0) {q}_head <= {q}_payload;
   else {q}_tail <= {q}_payload;
  end
 end
end''')
    body.append('ownerImageMemory_flattened dut('+',\n'.join(bindings)+');')
    body.extend(['assign relation = '+' &&\n'.join(relation)+';',
        'assign observations = '+' &&\n'.join('('+x+')' for x in observations)+';'])
    top.extend(['output relation', 'output observations'])
    return 'module OwnerQueueAdapter(\n'+',\n'.join(top)+'\n);\n'+'\n'.join(body)+'\nendmodule\n'


def prepare():
    policy()
    assert not (C/'plan.json').exists()
    evidence = C/'evidence'
    evidence.mkdir()
    source = W/'candidates/owner-channel-composition-round50-v3-20261111/evidence'
    originals = {}
    for name in ['ownerImageMemory_flattened.sv', 'PipeChannel.sv', 'PipeChannel_10.sv',
                 'PipeChannel_56.sv', 'ShiftQueue_30.sv', 'ShiftQueue_40.sv', 'ShiftQueue_86.sv']:
        q = source/name
        originals[str(q)] = sha(q)
        shutil.copyfile(q, evidence/name)
    model = W/'candidates/mcrams-owner-model-reuse-round44-v2-20261111/actual-RamModel.sv'
    originals[str(model)] = sha(model)
    shutil.copyfile(model, evidence/'RamModel.sv')
    assert originals[str(model)] == '46428dc8d9868145ee7636f7da186ea61906da0bb3e0fad3dc756ffd95c135a4'
    text = build_source()
    write_new(C/'preflight.json', dict(status='PASS_ALL109_QUEUE_CLOSURES_AND_REVERSIBLE_RAM_ENDPOINT_CUT',
        generated_source_sha256=__import__('hashlib').sha256(text.encode()).hexdigest(),
        queue_count=109, command_tuples=36, response_channels=35,
        endpoint_cut='Arbitrary RAM ready, response valid and response payload; no memory/FAME proof.'))
    plan = dict(schema='ec-owner-queue-adapter-plan/1', functional_baseline=BASE,
        hardware_commit='3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c',
        source_id='79aedd9ada6137e018d7f9c9c175fd4a06f53820d235ddcbe4b4a185e75fd68d',
        cpu=249, memory_limit_gib=8, yosys='/usr/local/bin/yosys',
        yosys_sha256=sha('/usr/local/bin/yosys'), originals=originals,
        inputs={str(q):sha(q) for q in [C/'controller.py',C/'README.md',C/'preflight.json',
            W/'scripts/opt4_unattended_common.py', *sorted(evidence.iterdir())]},
        target_changed=False, ram_endpoint_cut=True, complete_fame_equivalence=False,
        whole_fit=False, fpga_access=False)
    write_new(C/'plan.json', plan)
    print('PREPARED_ALL109_QUEUE_ADAPTER_COMPOSITION')


def build_source(mutant=None):
    e = C/'evidence'
    raw = (e/'ownerImageMemory_flattened.sv').read_text()
    model = (e/'RamModel.sv').read_text()
    if mutant:
        old, new = mutant
        assert raw.count(old) == 1, ('Ineffective mutation', old, raw.count(old))
        raw = raw.replace(old,new,1)
    source = [cut_adapter(raw,model)]
    for name in ['ShiftQueue_30.sv','ShiftQueue_40.sv','ShiftQueue_86.sv']:
        source.append(observe_queue((e/name).read_text()))
    for name in ['PipeChannel.sv','PipeChannel_10.sv','PipeChannel_56.sv']:
        source.append(observe_pipe((e/name).read_text()))
    source.append(harness(raw,model))
    return '\n'.join(source)


def run():
    policy()
    plan = read(C/'plan.json')
    assert all(sha(q)==h for q,h in plan['inputs'].items())
    assert sha(plan['yosys']) == plan['yosys_sha256']
    if (O/'complete.json').exists():
        assert read(O/'complete.json')['result_sha256'] == sha(O/'result.json')
        print('IMMUTABLE_QUEUE_ADAPTER_PROOF_REVALIDATED')
        return
    O.mkdir(parents=True,exist_ok=True)
    lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(), 'Preserve partial evidence; use a versioned recovery'
    cpu = plan['cpu']
    for row in read(U/'snapshot.json')['states'].values():
        if row.get('identity_live'):
            for proc in [row,row.get('child',{}),row.get('stage_process',{}),*row.get('worker_processes',[])]:
                if live(proc):
                    affinity=os.sched_getaffinity(proc['pid'])
                    assert len(affinity)>8 or cpu not in affinity, ('CPU conflict',proc['pid'])
    os.sched_setaffinity(0,{cpu})
    resource.setrlimit(resource.RLIMIT_AS,(8*2**30,8*2**30))
    state=dict(schema='ec-owner-queue-adapter-proof/1',**identity(),started_utc=now(),
        functional_baseline=BASE,hardware_commit=plan['hardware_commit'],source_id=plan['source_id'],
        cpu=cpu,fpga_access=False,target_changed=False,ram_endpoint_cut=True,
        complete_fame_equivalence=False,complete_dcache_equivalence=False,whole_fit=False)

    def status(value,**extra):
        state.update(status=value,updated_utc=now(),**extra)
        save(O/'state.json',state);save(STATE,state)

    def stage(label,source,command,positive):
        policy()
        v,y,log=[O/(label+x) for x in ['.sv','.ys','.log']]
        write_new(v,source)
        write_new(y,f'read_verilog -sv -DSYNTHESIS {v}\nprep -top OwnerQueueAdapter -flatten\nopt -full\nopt_clean\n'+command+'\n')
        start=time.monotonic()
        with log.open('xb') as f:
            proc=subprocess.Popen([plan['yosys'],'-s',str(y)],cwd=C,stdout=f,stderr=subprocess.STDOUT,stdin=subprocess.DEVNULL)
            status('RUNNING_'+label,child=identity(proc.pid),stage_log=str(log))
            try:code=proc.wait(timeout=240)
            except subprocess.TimeoutExpired:
                proc.kill();code=proc.wait();raise RuntimeError(('Timeout is not PASS',label,code))
        receipt=dict(label=label,returncode=code,seconds=time.monotonic()-start,
            source_sha256=sha(v),script_sha256=sha(y),log_sha256=sha(log))
        save(O/(label+'-receipt.json'),receipt)
        text=log.read_text()
        if positive:assert code==0 and 'SUCCESS!' in text,receipt
        else:assert code!=0 and 'proof did fail' in text and 'TIMEOUT' not in text and 'syntax error' not in text,receipt
        return receipt
    try:
        source=build_source()
        proofs=[stage('reset',source,'sat -seq 2 -set-at 1 reset 1 -prove-skip 1 -prove relation 1 -verify -timeout 120',True),
            stage('step',source,'sat -seq 2 -set-at 1 relation 1 -prove-skip 1 -prove relation 1 -verify -timeout 120',True),
            stage('observations',source,'sat -seq 1 -set relation 1 -prove observations 1 -verify -timeout 120',True)]
        mutations=[
            ('partial-read-pop','assign MPORT_5_addr_sink_ready = model_channels_read_cmds_9_ready & MPORT_5_en_sink_valid;',
             'assign MPORT_5_addr_sink_ready = model_channels_read_cmds_9_ready;'),
            ('read-address','assign model_channels_read_cmds_34_bits_addr = preservationWaitWatermark_MPORT_addr_sink_bits;',
             "assign model_channels_read_cmds_34_bits_addr = preservationWaitWatermark_MPORT_addr_sink_bits ^ 9'h001;"),
            ('write-high-bit','assign model_channels_write_cmds_0_bits_data = MPORT_data_sink_bits;',
             "assign model_channels_write_cmds_0_bits_data = MPORT_data_sink_bits ^ 81'h100000000000000000000;"),
            ('response-swap','assign MPORT_5_data_source_bits = model_channels_read_resps_9_bits;',
             'assign MPORT_5_data_source_bits = model_channels_read_resps_8_bits;'),
            ('write-mask','assign model_channels_write_cmds_0_bits_mask = MPORT_mask_sink_bits;',
             "assign model_channels_write_cmds_0_bits_mask = 1'b1;")]
        negatives=[stage('negative-'+label,build_source((old,new)),
            'sat -seq 1 -set relation 1 -prove observations 1 -verify -timeout 120',False)
            for label,old,new in mutations]
        result={**state,'status':'PASS_ALL109_OWNER_QUEUES_AND_ATOMIC_ADAPTER_JOINS_WITH_RAM_ENDPOINT_CUT',
            'child':{},'completed_utc':now(),'proof_receipts':proofs,'mutation_receipts':negatives,
            'queue_count':109,'read_tuples':35,'write_tuple_fields':4,'response_channels':35,
            'reference':'109 independent two-entry abstract FIFOs; grouped reference dequeues require every tuple member present.',
            'observer_exact_reversal_checked':True,'adapter_cut_exact_reversal_checked':True,
            'reset_base_from_arbitrary_queue_state':True,'payload_initialization_assumption':False,
            'producer_stability_assumption':False,'inputs':plan['inputs'],'plan_sha256':sha(C/'plan.json'),
            'limitations':['RAM ready/valid/data endpoint is arbitrary and explicitly cut.',
                'No RAM transaction, FAME target-advance, clock/reset-token, or complete target-cycle composition claim.',
                'No liveness, smaller area cut, full DCache/Opt4 equivalence, FIT, timing/DRC, bitstream or FPGA admission.']}
        save(O/'result.json',result)
        save(O/'complete.json',dict(result_sha256=sha(O/'result.json'),completed_utc=now()))
        status(result['status'],child={},result_sha256=sha(O/'result.json'))
        print(result['status'])
    except Exception as exc:
        status('FAILED_WITH_EVIDENCE',child={},error=repr(exc));save(O/'failure.json',state);raise


if __name__=='__main__':
    ap=argparse.ArgumentParser();ap.add_argument('--prepare',action='store_true');ap.add_argument('--run',action='store_true')
    args=ap.parse_args();assert args.prepare != args.run
    prepare() if args.prepare else run()
