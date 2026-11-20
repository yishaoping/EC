"""Fail-closed audit of the generated replicated-memory Yosys JSON."""
import copy

def check(design):
    modules = design['modules']
    top = modules['AddressBucketSequenceMemory']
    copies = list(top['cells'].values())
    assert len(copies) == 45 and all(c['type'] == 'AddressBucketSequenceReplica' for c in copies)
    assert 'reset' in top['ports']
    assert all('reset' not in c['connections'] for c in copies), 'leaf must be reset independent'
    covered = set()
    for cell in copies:
        con = cell['connections']
        for name in ['clock','io_writeEnable','io_writeIndex','io_writeData']:
            assert con[name] == top['ports'][name]['bits'], name
        for port in range(2):
            matches = [r for r in range(90)
                       if con[f'io_readIndex_{port}'] == top['ports'][f'io_readIndex_{r}']['bits']]
            assert len(matches) == 1
            reader = matches[0]
            assert reader not in covered
            assert con[f'io_readData_{port}'] == top['ports'][f'io_readData_{reader}']['bits']
            covered.add(reader)
    assert covered == set(range(90))
    leaf = modules['AddressBucketSequenceReplica']
    assert 'reset' not in leaf['ports'], 'reset-free memory leaf required'
    memories = [c for c in leaf['cells'].values() if c['type'] == '$mem_v2']
    assert len(memories) == 1
    memory = memories[0]; p = memory['parameters']; con = memory['connections']
    values = {k:int(p[k],2) for k in ['WIDTH','SIZE','ABITS','RD_PORTS','WR_PORTS','RD_CLK_ENABLE','WR_CLK_ENABLE','WR_CLK_POLARITY']}
    assert values == dict(WIDTH=32,SIZE=256,ABITS=8,RD_PORTS=2,WR_PORTS=1,
                         RD_CLK_ENABLE=0,WR_CLK_ENABLE=1,WR_CLK_POLARITY=1)
    assert con['WR_CLK'] == leaf['ports']['clock']['bits']
    assert all(v == 'x' for v in p['INIT']), 'payload must remain uninitialized'
    pairs = set()
    for port in range(2):
        address = con['RD_ADDR'][port*8:(port+1)*8]
        data = con['RD_DATA'][port*32:(port+1)*32]
        hits = [k for k in range(2) if address == leaf['ports'][f'io_readIndex_{k}']['bits']
                and data == leaf['ports'][f'io_readData_{k}']['bits']]
        assert len(hits) == 1 and hits[0] not in pairs
        pairs.add(hits[0])
    drivers = {}
    for cell in leaf['cells'].values():
        if cell['type'] == '$mux':
            connections = cell['connections']
            for i, bit in enumerate(connections['Y']):
                drivers[bit] = (connections['S'][0],connections['A'][i],connections['B'][i])
    def resolve(bit, enabled):
        if bit == leaf['ports']['io_writeEnable']['bits'][0]: return str(enabled)
        if bit not in drivers: return bit
        select, a, b = drivers[bit]
        select = resolve(select,enabled)
        assert select in ['0','1']
        return resolve(b if select == '1' else a,enabled)
    assert [resolve(v,0) for v in con['WR_EN']] == ['0']*32
    assert [resolve(v,1) for v in con['WR_EN']] == ['1']*32
    assert [resolve(v,1) for v in con['WR_ADDR']] == leaf['ports']['io_writeIndex']['bits']
    assert [resolve(v,1) for v in con['WR_DATA']] == leaf['ports']['io_writeData']['bits']
    return dict(status='PASS_45_EXACT_REPLICAS_90_ASYNC_READS_BROADCAST_FULL32_SINGLE_EDGE_WRITE',
                replicas=45,logical_payload_bits=8192,physical_payload_bits=45*8192,
                covered_read_ports=90,leaf_memory=values,
                reset_independence='No leaf reset; no reset pin or reset-controlled memory write')

def check_with_mutations(design):
    result = check(design)
    rejected = []
    for field in ['io_writeEnable','io_writeIndex','io_writeData','io_readData_0']:
        mutant = copy.deepcopy(design)
        cell = next(iter(mutant['modules']['AddressBucketSequenceMemory']['cells'].values()))
        cell['connections'][field][0] = '0'
        try: check(mutant)
        except AssertionError: rejected.append(field)
        else: raise AssertionError('audit accepted mutation '+field)
    result['rejected_topology_mutations'] = rejected
    return result
