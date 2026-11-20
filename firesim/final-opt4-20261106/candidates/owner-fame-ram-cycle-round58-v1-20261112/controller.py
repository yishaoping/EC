#!/usr/bin/python3
"""Join emitted owner scheduling controls to the connected owner RAM proof."""
import argparse
import fcntl
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import re
import resource
import subprocess
import sys
import time

C = Path(__file__).resolve().parent
W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D/'unattended-opt4'
O = D/'build-logs/Opt4-owner-fame-ram-cycle-round58-v1-20261112'
S = D/'Opt4-owner-fame-ram-cycle-round58-v1-state.json'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
HW = '3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c'
SOURCE = '79aedd9ada6137e018d7f9c9c175fd4a06f53820d235ddcbe4b4a185e75fd68d'
PREFIX = 'lazyModule_system_tile_prci_domain_tile_reset_domain_boom_tile_dcache_ownerImageMemory_flattened_'
QPATH = W/'candidates/owner-joined-ram-queue-round57-v1-20261112/controller.py'
APATH = W/'candidates/owner-token-audit-round49-v3-20261111/audit.py'
FIRE = W/'candidates/owner-token-audit-round49-v3-20261111/evidence/FireSim.sv'
R57O = D/'build-logs/Opt4-owner-joined-ram-queue-round57-v1-20261112'
R56O = D/'build-logs/Opt4-owner-queue-adapter-round56-v1-20261112'
R55O = D/'build-logs/Opt4-owner-ram-transaction-round55-v1-20261112'
YOSYS = Path('/usr/local/bin/yosys')
CPU = 249
MEMORY_GIB = 8

sys.path.insert(0, str(W/'scripts'))
from opt4_unattended_common import identity, live, now, read, save, sha


def load_module(path, name):
    spec = importlib.util.spec_from_file_location(name, path)
    obj = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(obj)
    return obj


Q = load_module(QPATH, 'owner_queue_round57')
A = load_module(APATH, 'owner_token_round49')


def policy():
    p = read(U/'campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE and p['area_equivalence_only']
    assert p['native_paused'] and not p['fpga_access'] and not p['functional_extensions_allowed']
    assert p['board_allowlist'] == ['0000:21:00.0']
    return p


def write_new(path, value):
    path = Path(path)
    raw = value if isinstance(value, str) else json.dumps(value, indent=2, sort_keys=True)+'\n'
    with path.open('x') as stream:
        stream.write(raw)
        stream.flush()
        os.fsync(stream.fileno())


def input_sets():
    w_inputs = {str(p): sha(p) for p in [C/'controller.py', C/'README.md', QPATH,
        APATH, FIRE, W/'scripts/opt4_unattended_common.py']}
    # Seal every transitive helper/evidence file that builds the connected top.
    for prior in [Q.C, Q.Q.C, Q.T.C]:
        path = prior/'plan.json'
        w_inputs[str(path)] = sha(path)
        for name, digest in read(path)['inputs'].items():
            assert Path(name).is_relative_to(W) and sha(name) == digest, name
            if name in w_inputs:
                assert w_inputs[name] == digest
            w_inputs[name] = digest
    for leaf in ['inputs.json', 'result.json', 'complete.json']:
        path = APATH.parent/leaf
        w_inputs[str(path)] = sha(path)
    d_inputs = [R57O/'result.json', R57O/'complete.json',
        R56O/'result.json', R56O/'complete.json',
        R55O/'result.json', R55O/'complete.json']
    return w_inputs, {str(x): sha(x) for x in d_inputs}


def cpu_check(cpu):
    rows = []
    for row in read(U/'snapshot.json')['states'].values():
        if not row.get('identity_live'): continue
        for proc in [row, row.get('child', {}), row.get('stage_process', {}), *row.get('worker_processes', [])]:
            if live(proc) and proc['pid'] != os.getpid():
                affinity = os.sched_getaffinity(proc['pid'])
                assert len(affinity) > 8 or cpu not in affinity, ('CPU conflict', proc['pid'])
                if len(affinity) <= 8:
                    rows.append(dict(pid=proc['pid'], start_ticks=proc['start_ticks'], affinity=sorted(affinity)))
    return rows


def conjunction(node, definitions):
    pending = [(node, frozenset())]
    result = []
    while pending:
        value, ancestors = pending.pop()
        if value[0] == '&':
            pending.extend((x, ancestors) for x in value[1:])
        elif value[0] == 'v' and value[1] in definitions:
            assert value[1] not in ancestors
            pending.append((A.parse(definitions[value[1]]), ancestors | {value[1]}))
        else:
            result.append(value)
    return result


def render(node):
    if node[0] == 'v': return node[1]
    if node[0] == 'c': return "1'h"+str(node[1])
    if node[0] == '~': return '(~'+render(node[1])+')'
    if node[0] == '?':
        return '('+render(node[1])+' ? '+render(node[2])+' : '+render(node[3])+')'
    return '('+render(node[1])+' '+node[0]+' '+render(node[2])+')'


def source_maps():
    raw = re.sub(r'//[^\n]*', '', FIRE.read_text())
    token = A.audit(raw)
    defs = {m[1]: m[2].strip() for m in re.finditer(
        r'\b(?:wire|assign)\s+(\w+)\s*=([^;]+);', raw)}
    adapter = (Q.C/'evidence/ownerImageMemory_flattened.sv').read_text()
    ap = Q.Q.ports(adapter)
    commands = sorted({n[:-len('_sink_valid')] for n in ap if n.endswith('_sink_valid')})
    responses = sorted({n[:-len('_source_valid')] for n in ap if n.endswith('_source_valid')})
    assert len(commands) == 74 and len(responses) == 35
    assert set(token['command_names']) == set(commands)
    assert set(token['response_names']) == set(responses)
    q = {stem: 'q'+str(i) for i, stem in enumerate(commands+responses)}
    command_valid = {}
    response_valid = {}
    for stem in commands:
        name = PREFIX+stem+'_source_valid'
        assert name in defs
        flag = PREFIX+stem+'_fired_0'
        expr = A.parse(defs[name])
        assert A.canonical(A.parse('~'+flag)) in set(map(A.canonical, conjunction(expr, defs)))
        allowed = {PREFIX+x+'_fired_0' for x in commands+responses}
        allowed |= {PREFIX+x+'_sink_valid' for x in responses}
        assert A.variables(expr) <= allowed, (stem, sorted(A.variables(expr)-allowed))
        command_valid[stem] = defs[name]
    for stem in responses:
        ready = PREFIX+stem+'_sink_ready'
        flag = PREFIX+stem+'_fired_0'
        assert A.canonical(A.parse('targetCycleFinishing & ~'+flag)) == A.canonical(A.parse(defs[ready]))
        response_valid[stem] = (ready, flag)
    # Extract the exact branch bodies rather than constructing substitute RTL.
    command_updates, response_updates = {}, {}
    for stem in commands:
        flag = PREFIX+stem+'_fired_0'
        pat = (r'if\s*\(hostReset\)\s*begin\s*'+flag+r'\s*<=([^;]+);\s*end\s*else\s*if\s*'
            r'\(targetCycleFinishing\)\s*begin\s*'+flag+r'\s*<=([^;]+);\s*end\s*else\s*begin\s*'+flag+r'\s*<=([^;]+);\s*end')
        matches = list(re.finditer(pat, raw))
        assert len(matches) == 1
        command_updates[stem] = matches[0][0]
    def inline_gen(node):
        if node[0] == 'v' and node[1].startswith('_GEN_'):
            return inline_gen(A.parse(defs[node[1]]))
        if node[0] in ['v', 'c']: return node
        return (node[0], *(inline_gen(x) for x in node[1:]))
    for stem in responses:
        flag = PREFIX+stem+'_fired_0'
        updates = re.findall(r'\b'+flag+r'\s*<=([^;]+);', raw)
        assert len(updates) == 1
        response_updates[stem] = flag+' <= '+render(inline_gen(A.parse(updates[0])))+';'
    clock_pat = (r'if\s*\(hostReset\)\s*begin\s*clockBridge_clocks_0_enabled\s*<=\s*1\x27h0;\s*'
        r'end\s*else\s*if\s*\(targetCycleFinishing\)\s*begin\s*clockBridge_clocks_0_enabled\s*<=\s*'
        r'clockBridge_clocks_sink_bits__0;\s*end')
    clock_matches = list(re.finditer(clock_pat, raw))
    assert len(clock_matches) == 1
    factors = conjunction(A.parse(defs['targetCycleFinishing']), defs)
    owner_factors = [A.parse(PREFIX+x+'_sink_valid') for x in responses]
    owner_factors += [A.parse(PREFIX+x+'_fired_0 | '+PREFIX+x+'_source_ready & '+PREFIX+x+'_source_valid') for x in commands]
    owned = {A.canonical(x) for x in owner_factors}
    assert len(owned) == 109
    assert owned <= set(map(A.canonical, factors))
    external = [x for x in factors if A.canonical(x) not in owned]
    # Group only factors with no owner token dependency into a symbolic input.
    assert all(not any(v.startswith(PREFIX) for v in A.variables(x)) for x in external)
    token['external_finishing_factors'] = len(external)
    token['external_finishing_sha256'] = hashlib.sha256(repr(sorted(map(A.canonical, external), key=repr)).encode()).hexdigest()
    return dict(token=token, commands=commands, responses=responses, q=q,
        command_valid=command_valid, response_valid=response_valid,
        command_updates=command_updates, response_updates=response_updates,
        clock_update=clock_matches[0][0], owner_factors=owner_factors,
        clock_ce=defs['clockBridge_clocks_0_buffer_CE'])


def compose(low, mutation=None):
    binding = source_maps()
    commands, responses, q = [binding[k] for k in ['commands', 'responses', 'q']]
    src = Q.build_source(low)
    start = src.index('module OwnerJoinedRamQueue(')
    end = src.index('endmodule', start)+len('endmodule')
    unit = src[start:end]
    for stem in commands:
        name = q[stem]+'_in_valid'
        pat = r'(?m)^input\s+'+re.escape(name)+r',\n'
        unit, count = re.subn(pat, '', unit)
        assert count == 1, ('command input', name, count)
    for stem in responses:
        name = q[stem]+'_out_ready'
        pat = r'(?m)^input\s+'+re.escape(name)+r',\n'
        unit, count = re.subn(pat, '', unit)
        assert count == 1, ('response input', name, count)
    assert unit.count('input reset,\n') == 1
    unit = unit.replace('input reset,\n',
        'input reset,\ninput other_completion_ready,\ninput next_clock_enabled,\n', 1)
    assert unit.count('output transaction_relation, output word_relation, output selector_legal,\n') == 1
    unit = unit.replace('output transaction_relation, output word_relation, output selector_legal,\n',
        'output transaction_relation, output word_relation, output selector_legal,\n'
        'output fame_control_ok, output fired_transition_ok, output one_shot_ok,\n'
        'output target_clock_transition_ok, output finish_complete_ok,\n'
        'output target_cycle_finishing, output target_clock_edge,\n', 1)
    marker = 'wire [80:0] model_word;'
    assert unit.count(marker) == 1
    pre, controls = [], []
    pre += ['reg clockBridge_clocks_0_enabled;', 'wire hostReset = reset;',
        'wire clockBridge_clocks_sink_bits__0 = next_clock_enabled;']
    flags = {stem: PREFIX+stem+'_fired_0' for stem in commands+responses}
    pre += ['reg '+flag+';' for flag in flags.values()]
    for stem in responses:
        qn = q[stem]
        valid = PREFIX+stem+'_sink_valid'
        flag = flags[stem]
        pre.append(f'wire {valid} = {qn}_out_valid;')
        ready_expr = 'targetCycleFinishing & ~'+flag
        if mutation == ('response-gate', stem):
            ready_expr = '~'+flag
        pre.append(f'wire {PREFIX+stem}_sink_ready = {ready_expr};')
        pre.append(f'assign {qn}_out_ready = {PREFIX+stem}_sink_ready;')
    for stem in commands:
        qn = q[stem]
        flag = flags[stem]
        expr = binding['command_valid'][stem]
        if mutation == ('command-gate', stem):
            needle = re.compile(r'~\s*'+re.escape(flag)+r'\b')
            expr, count = needle.subn("1'h1", expr, count=1)
            assert count == 1, ('mutation did not hit command suppression', stem)
        name = PREFIX+stem+'_source_valid'
        pre.append(f'wire {name} = {expr};')
        pre.append(f'wire {PREFIX+stem}_source_ready = {qn}_in_ready;')
        pre.append(f'assign {qn}_in_valid = {name};')
    factors = list(binding['owner_factors'])
    if mutation and mutation[0] == 'finish-command':
        drop = A.canonical(A.parse(PREFIX+mutation[1]+'_fired_0 | '+PREFIX+mutation[1]+'_source_ready & '+PREFIX+mutation[1]+'_source_valid'))
        original = len(factors)
        factors = [x for x in factors if A.canonical(x) != drop]
        assert len(factors) == original-1
    pre += ['wire targetCycleFinishing = other_completion_ready &\n'+' &\n'.join(render(x) for x in factors)+';',
        'assign target_cycle_finishing = targetCycleFinishing;',
        'assign target_clock_edge = '+binding['clock_ce']+';']
    controls += ['always @(posedge clock) begin', binding['clock_update']]
    controls += [binding['command_updates'][stem] for stem in commands]
    controls += [binding['response_updates'][stem] for stem in responses]
    controls += ['end']

    # Record pre-edge facts so SAT checks the exact next-state recurrence.
    ordered = commands+responses
    controls += ['reg ['+str(len(ordered)-1)+':0] prior_fired, prior_accept;']
    controls += ['reg prior_reset, prior_finish, prior_enabled, prior_next_clock;']
    controls += ['always @(posedge clock) begin',
        ' prior_fired <= {'+', '.join(reversed([flags[x] for x in ordered]))+'};']
    accepts = []
    for stem in ordered:
        qn = q[stem]
        if stem in commands:
            accepts.append(f'({qn}_in_ready & {qn}_in_valid)')
        else:
            accepts.append(f'({qn}_out_ready & {qn}_out_valid)')
    controls += [' prior_accept <= {'+', '.join(reversed(accepts))+'};',
        ' prior_reset <= reset;', ' prior_finish <= target_cycle_finishing;',
        ' prior_enabled <= clockBridge_clocks_0_enabled;', ' prior_next_clock <= next_clock_enabled;',
        'end']
    transitions, one_shot = [], []
    for i, stem in enumerate(ordered):
        flag = flags[stem]
        accepted = f'prior_accept[{i}]'
        old = f'prior_fired[{i}]'
        if stem in commands:
            expected = (f'(prior_reset ? 1\'b0 : (prior_finish ? ~prior_enabled : '
                f'({old} | {accepted})))')
            one_shot.append(f'(!({accepted} & ~prior_reset & ~prior_finish) | ({flag} & ~{q[stem]}_in_valid))')
        else:
            expected = (f'(prior_reset ? 1\'b1 : (prior_finish ? ~prior_next_clock : '
                f'({old} | {accepted})))')
        transitions.append(f'({flag} == {expected})')
    pre += ['assign fame_control_ok = '+' &\n'.join(
        [f'(~({PREFIX+x}_source_valid) | ~{flags[x]})' for x in commands]+
        [f'(~{q[x]}_out_ready | target_cycle_finishing)' for x in responses])+';']
    pre += ['assign fired_transition_ok = '+' &\n'.join(transitions)+';']
    pre += ['assign one_shot_ok = '+' &\n'.join(one_shot)+';']
    pre += ['assign target_clock_transition_ok = (prior_reset ? ~clockBridge_clocks_0_enabled : '
        '(prior_finish ? (clockBridge_clocks_0_enabled == prior_next_clock) : (clockBridge_clocks_0_enabled == prior_enabled)));']
    pre += ['assign finish_complete_ok = ~target_cycle_finishing | ('+
        ' &\n'.join(render(x) for x in binding['owner_factors'])+');']
    unit = unit.replace(marker, '\n'.join(pre+controls)+'\n'+marker, 1)
    assert 'input other_completion_ready' in unit and 'output fame_control_ok' in unit
    return src[:start]+unit+src[end:]


def prepare():
    p = policy()
    assert not (C/'plan.json').exists() and not O.exists()
    binding = source_maps()
    token, commands, responses = [binding[k] for k in ['token', 'commands', 'responses']]
    r57, c57 = read(R57O/'result.json'), read(R57O/'complete.json')
    r56, c56 = read(R56O/'result.json'), read(R56O/'complete.json')
    r55, c55 = read(R55O/'result.json'), read(R55O/'complete.json')
    assert c57['result_sha256'] == sha(R57O/'result.json')
    assert c56['result_sha256'] == sha(R56O/'result.json')
    assert c55['result_sha256'] == sha(R55O/'result.json')
    assert r57['status'].startswith('PASS_CONNECTED_') and len(r57['proof_receipts']) == 19
    assert len(r57['mutation_receipts']) == 3 and all(x['returncode'] != 0 for x in r57['mutation_receipts'])
    assert r56['status'].startswith('PASS_') and r55['status'].startswith('PASS_')
    assert r57['source_id'] == r56['source_id'] == r55['source_id'] == SOURCE
    assert r57['functional_baseline'] == r56['functional_baseline'] == r55['functional_baseline'] == BASE
    sample = compose(0)
    assert sample.count('module OwnerJoinedRamQueue(') == 1
    preflight = dict(schema='ec-owner-fame-ram-cycle-preflight/1',
        status='PASS_SOURCE_BOUND_74_COMMAND_35_RESPONSE_CONTROL_JOIN_TO_CONNECTED_RAM_QUEUES',
        functional_baseline=BASE, hardware_commit=HW, source_id=SOURCE,
        emitted_fire_sim_sha256=sha(FIRE), emitted_owner_audit=token,
        command_count=len(commands), response_count=len(responses), queue_count=109,
        target_cycle_finishing='exact109owner conjuncts connected; unrelated conjuncts grouped into unconstrained Boolean',
        next_clock_token='symbolic input, exact emitted state recurrence proved in composition',
        unrelated_completion_channels='unconstrained',
        predecessor_queue_ram_receipts={
            'round57': {'path':str(R57O/'result.json'),'sha256':sha(R57O/'result.json')},
            'round56': {'path':str(R56O/'result.json'),'sha256':sha(R56O/'result.json')},
            'round55': {'path':str(R55O/'result.json'),'sha256':sha(R55O/'result.json')}},
        generated_slice0_sha256=hashlib.sha256(sample.encode()).hexdigest(),
        narrow_active_affinities_checked=cpu_check(CPU),
        complete_fame_equivalence=False, complete_dcache_equivalence=False,
        fpga_access=False, whole_fit=False)
    write_new(C/'preflight.json', preflight)
    winputs, dinputs = input_sets()
    plan = dict(schema='ec-owner-fame-ram-cycle-plan/1',functional_baseline=BASE,
        hardware_commit=HW,source_id=SOURCE,inputs=winputs,evidence_inputs=dinputs,
        preflight_sha256=sha(C/'preflight.json'),cpu=CPU,memory_limit_gib=MEMORY_GIB,
        yosys=str(YOSYS),yosys_sha256=sha(YOSYS),command_count=len(commands),
        response_count=len(responses),target_changed=False,fpga_access=False,whole_fit=False)
    write_new(C/'plan.json',plan)
    spec=dict(name='owner-fame-ram-cycle-r58-v1-3656aec4',kind='proof',cwd=str(C),
        argv=['/usr/bin/python3',str(C/'controller.py'),'--run'],
        inputs={**winputs,str(C/'README.md'):sha(C/'README.md'),
            str(C/'preflight.json'):sha(C/'preflight.json'),str(C/'plan.json'):sha(C/'plan.json')},
        evidence_inputs=dinputs,outputs=[str(O/'complete.json')],checkpoints=[str(S)])
    request=dict(action='cpu_job',spec=spec)
    write_new(C/'request.json',request)
    print('PREPARED_OWNER_FAME_RAM_COMPOSITION_REQUEST_NOT_YET_SUBMITTED')


def run():
    policy()
    plan=read(C/'plan.json')
    for path,digest in {**plan['inputs'],**plan['evidence_inputs']}.items():
        assert sha(path)==digest, ('input changed',path)
    assert sha(YOSYS)==plan['yosys_sha256'] and sha(C/'preflight.json')==plan['preflight_sha256']
    if (O/'complete.json').exists():
        assert read(O/'complete.json')['result_sha256']==sha(O/'result.json')
        print('IMMUTABLE_FAME_RAM_CYCLE_PROOF_REVALIDATED'); return
    O.mkdir(parents=True,exist_ok=True)
    lock=(O/'instance.lock').open('a');fcntl.flock(lock,fcntl.LOCK_EX|fcntl.LOCK_NB)
    assert not (O/'state.json').exists(), 'Preserve partial proof; use a new recovery version'
    cpu_check(plan['cpu'])
    os.sched_setaffinity(0,{plan['cpu']})
    resource.setrlimit(resource.RLIMIT_AS,(plan['memory_limit_gib']*2**30,)*2)
    binding=source_maps()
    token,commands,responses,q=[binding[k] for k in ['token','commands','responses','q']]
    state=dict(schema='ec-owner-fame-ram-cycle-proof/1',**identity(),started_utc=now(),
        functional_baseline=BASE,hardware_commit=HW,source_id=SOURCE,cpu=plan['cpu'],
        target_changed=False,fpga_access=False,whole_fit=False,complete_fame_equivalence=False,
        complete_dcache_equivalence=False)
    def status(value,**extra):
        state.update(status=value,updated_utc=now(),**extra);save(O/'state.json',state);save(S,state)
    def stage(label,source,commands_text,positive):
        policy()
        v,y,log=[O/(label+s) for s in ['.sv','.ys','.log']]
        write_new(v,source)
        script=(f'read_verilog -sv -DSYNTHESIS {v}\nprep -top OwnerJoinedRamQueue -flatten\n'
            f'memory_map\nopt -full\nopt_clean\n{commands_text}\n')
        write_new(y,script)
        started=time.monotonic()
        with log.open('xb') as out:
            child=subprocess.Popen([str(YOSYS),'-s',str(y)],cwd=C,stdin=subprocess.DEVNULL,
                stdout=out,stderr=subprocess.STDOUT)
            status('RUNNING_'+label,child=identity(child.pid),stage_log=str(log))
            try:code=child.wait(timeout=900)
            except subprocess.TimeoutExpired:
                child.kill();child.wait();raise RuntimeError(('timeout is not PASS',label))
        receipt=dict(label=label,returncode=code,seconds=time.monotonic()-started,
            source_sha256=sha(v),script_sha256=sha(y),log_sha256=sha(log))
        save(O/(label+'-receipt.json'),receipt)
        text=log.read_text()
        if positive == 'witness':assert code==0 and 'SAT solving finished - model found:' in text,receipt
        elif positive:assert code==0 and 'SUCCESS!' in text,receipt
        else:assert code!=0 and 'proof did fail' in text and 'TIMEOUT' not in text and 'syntax error' not in text,receipt
        return receipt
    try:
        common='-set selector_legal 1 -set selectors_stable 1 -set queue_relation 1 -set queue_observations 1 '
        props='-prove transaction_relation 1 -prove fame_control_ok 1 -prove fired_transition_ok 1 -prove one_shot_ok 1 -prove target_clock_transition_ok 1 -prove finish_complete_ok 1'
        reset=f'sat -seq 2 {common}-set-at 1 reset 1 -set-at 1 word_relation 1 -prove-skip 1 {props} -verify -timeout 600'
        step=f'sat -seq 2 {common}-set-at 1 transaction_relation 1 -prove-skip 1 {props} -verify -timeout 600'
        observed=f'sat -seq 1 {common}-set transaction_relation 1 -prove delivered_snapshot 1 -prove write_order 1 -prove fame_control_ok 1 -prove finish_complete_ok 1 -verify -timeout 600'
        positives=[]
        for low in range(0,81,9):
            src=compose(low)
            positives.append(stage(f'bits-{low}-{low+8}-reset',src,reset,True))
            positives.append(stage(f'bits-{low}-{low+8}-step',src,step,True))
        positives.append(stage('response-observation',compose(0),observed,True))
        witness=f'sat -seq 1 {common}-set transaction_relation 1 -set target_clock_edge 1 -show target_cycle_finishing -show target_clock_edge -timeout 240'
        witness_receipt=stage('nonvacuous-related-state-target-edge',compose(0),witness,'witness')
        mutants=[('command-gate',commands[0]),('response-gate',responses[0]),('finish-command',commands[0])]
        negatives=[]
        for kind,stem in mutants:
            source=compose(0,(kind,stem))
            target='finish_complete_ok' if kind=='finish-command' else 'fame_control_ok'
            negative=f'sat -seq 1 {common}-prove {target} 1 -verify -timeout 240'
            negatives.append(stage('negative-'+kind,source,negative,False))
        result={**state,'status':'PASS_COMPOSED_EMITTED_FAME_OWNER_CONTROLS_WITH_CONNECTED_109_QUEUES_AND_512X81_RAM',
            'completed_utc':now(),'child':{},'positive_receipts':positives,'mutation_receipts':negatives,
            'related_state_witness_receipt':witness_receipt,
            'command_count':len(commands),'response_count':len(responses),'queue_count':109,
            'memory_words':512,'payload_bits':81,'emitted_owner_audit_sha256':sha(APATH),
            'emitted_fire_sim_sha256':sha(FIRE),'preflight_sha256':sha(C/'preflight.json'),
            'inputs':plan['inputs'],'evidence_inputs':plan['evidence_inputs'],'plan_sha256':sha(C/'plan.json'),
            'unrelated_completion_inputs':'all non-owner conjuncts grouped into one unconstrained Boolean',
            'target_cycle_finishing':'exact74command completion plus35response-valid conjuncts, actual queues connected',
            'emitted_owner_binding':token,
            'limitations':['Round56 universal queue invariants and atomic joins are bound predecessor assumptions.',
                'Target payloads and next clock token remain arbitrary; no target reset/architectural transition relation is proved.',
                'Two-host-edge relational base/step obligations cover81bits in nine9bit slices; arbitrary related-memory base.',
                'The related-state target-edge witness proves nonvacuity, not reachability or liveness.',
                'No complete FAME scheduling/full-DCache/full-Opt4 equivalence or liveness proof.',
                'No whole-device area/FIT, physical timing, DRC, bitstream, or FPGA result.'],
            'target_changed':False,'fpga_access':False,'whole_fit':False,
            'complete_fame_equivalence':False,'complete_dcache_equivalence':False}
        save(O/'result.json',result);save(O/'complete.json',dict(result_sha256=sha(O/'result.json'),completed_utc=now()))
        status(result['status'],child={},result_sha256=sha(O/'result.json'))
        print(result['status'])
    except Exception as exc:
        status('FAILED_WITH_EVIDENCE',child={},error=repr(exc));save(O/'failure.json',state);raise


if __name__=='__main__':
    ap=argparse.ArgumentParser();g=ap.add_mutually_exclusive_group(required=True)
    g.add_argument('--prepare',action='store_true');g.add_argument('--run',action='store_true')
    a=ap.parse_args();prepare() if a.prepare else run()
