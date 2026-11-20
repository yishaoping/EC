"""Fail-closed audit of generated Yosys JSON, including every broadcast bit."""
import copy

def check(design):
    modules = design['modules']
    top = modules['AddressBucketSequenceMemory']
    copies = list(top['cells'].values())
    assert len(copies) == 45 and all(c['type'] == 'AddressBucketSequenceReplica' for c in copies)
    covered = set()
    for cell in copies:
        con = cell['connections']
        for name in ['clock','reset','io_writeEnable','io_writeIndex','io_writeData']:
            assert con[name] == top['ports'][name]['bits'], name
        for port in range(2):
            matches = [r for r in range(90)
                       if con[f'io_readIndex_{port}'] == top['ports'][f'io_readIndex_{r}']['bits']]
            assert len(matches) == 1
            r = matches[0]
            assert r not in covered
            assert con[f'io_readData_{port}'] == top['ports'][f'io_readData_{r}']['bits']
            covered.add(r)
    assert covered == set(range(90))
    leaf = modules['AddressBucketSequenceReplica']
    memories = [c for c in leaf['cells'].values() if c['type'] == '$mem_v2']
    assert len(memories) == 1
    memory = memories[0]; p = memory['parameters']; con = memory['connections']
    values = {k:int(p[k],2) for k in ['WIDTH','SIZE','ABITS','RD_PORTS','WR_PORTS','RD_CLK_ENABLE','WR_CLK_ENABLE','WR_CLK_POLARITY']}
    assert values == dict(WIDTH=32,SIZE=256,ABITS=8,RD_PORTS=2,WR_PORTS=1,
                         RD_CLK_ENABLE=0,WR_CLK_ENABLE=1,WR_CLK_POLARITY=1)
    ports = leaf['ports']
    assert con['WR_CLK'] == ports['clock']['bits']
    assert all(v == 'x' for v in p['INIT']), 'memory payload must remain uninitialized'
    pairs = set()
    for r in range(2):
        address = con['RD_ADDR'][r*8:(r+1)*8]
        data = con['RD_DATA'][r*32:(r+1)*32]
        hits = [k for k in range(2) if address == ports[f'io_readIndex_{k}']['bits']
                and data == ports[f'io_readData_{k}']['bits']]
        assert len(hits) == 1 and hits[0] not in pairs
        pairs.add(hits[0])
    # Resolve only combinational muxes. Unknown structures fail closed.
    drivers = {}
    for c in leaf['cells'].values():
        if c['type'] == '$mux':
            c = c['connections']
            for i, bit in enumerate(c['Y']): drivers[bit] = (c['S'][0],c['A'][i],c['B'][i])
    def resolve(bit, enable):
        if bit == ports['io_writeEnable']['bits'][0]: return str(enable)
        if bit not in drivers: return bit
        sel, a, b = drivers[bit]
        sel = resolve(sel,enable)
        assert sel in ['0','1']
        return resolve(b if sel == '1' else a,enable)
    assert [resolve(v,0) for v in con['WR_EN']] == ['0']*32
    assert [resolve(v,1) for v in con['WR_EN']] == ['1']*32
    assert [resolve(v,1) for v in con['WR_ADDR']] == ports['io_writeIndex']['bits']
    assert [resolve(v,1) for v in con['WR_DATA']] == ports['io_writeData']['bits']
    return dict(status='PASS_45_EXACT_REPLICAS_90_ASYNC_READS_BROADCAST_FULL32_SINGLE_EDGE_WRITE',
                replicas=45,logical_payload_bits=8192,physical_payload_bits=45*8192,
                covered_read_ports=90,leaf_memory=values)

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
