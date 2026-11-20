#!/usr/bin/python3
"""Independent mixed-target oracle; unchanged stimulus, one row per token."""
from pathlib import Path
import json
import re
O = None
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
m = None

def ports(path,top):
    head=re.search(r'\bmodule '+top+r'\s*\((.*?)\);',path.read_text(),re.S).group(1)
    return re.findall(r'\b(input|output)\s*(\[\d+:\d+\])?\s+(\w+)',head)


def oracle(rtl):
    ps=ports(rtl,'MixedTarget')
    ins=[n for d,w,n in ps if d=='input' and n!='clock']
    outs=[n for d,w,n in ps if d=='output']
    assert len(outs)==73
    assert not any('debug' in n.lower() for n in outs)
    lines=['module tb;','integer i,phase,seq,trace_fd,valid_edges=0,idle_edges=0;',
        "reg [63:0] rng=64'h4d595df4d0f33173;"]
    lines += [('reg ' if d=='input' else 'wire ')+w+' '+n+';' for d,w,n in ps]
    lines += ['MixedTarget dut('+','.join('.'+n+'('+n+')' for d,w,n in ps)+');',
        'initial begin']
    lines += [n+"='0;" for d,w,n in ps if d=='input']
    trace=O/'target-public-tokens.txt'
    lines += [f'trace_fd=$fopen("{trace}","w");','for(i=0;i<3003;i=i+1)begin']
    prior=D/'build-logs/Opt4-address-packed-full-module-r1-20261112/tb.v'
    s=prior.read_text();stim=s[s.index('reset=(i<3);'):s.index('// A normal reset without resetStats')]
    stim=re.sub(r'\bio_', 'io_address_',stim)
    lines += [stim,'if(i>=3000)begin reset=1;io_address_resetStats=0;end']
    for j in range(3):
        p=f'io_barrier_{j}_'
        lines += ['rng=rng^(rng<<13); rng=rng^(rng>>7); rng=rng^(rng<<17);',
            p+'resetStats=(i<3 || i==2048);',p+'event_valid=(rng[3:0]!=0);',
            p+f'event_bits=(i<512)?(1+(i+{j})%255):rng[11:0];',
            p+'safeWatermark=(i<512)?0:((i<768)?i-511:rng[23:12]);',
            p+f'currentCycle=(i<2500)?(100000+i+{j}):rng;',
            p+f'fatalProtocolError=(i=={2600+j});']
    fmt=' '.join('%h' for _ in ins+outs)+'\n'
    lines += ['#1;clock=1;#1;',
        f'$fwrite(trace_fd,"{fmt}",'+','.join(ins+outs)+');',
        'if(io_address_statsValid)valid_edges=valid_edges+1;',
        'if(io_address_idle)idle_edges=idle_edges+1;',
        'clock=0;#1;end',
        'if(valid_edges<100 || idle_edges<10)begin $display("MIXED_TARGET_INSUFFICIENT_LIVE_COVERAGE");$finish_and_return(1);end',
        '$display("MIXED_TARGET_TOKEN_ORACLE_PASS tokens=3003 outputs=73 valid_edges=%0d idle_edges=%0d",valid_edges,idle_edges);$finish;',
        'end endmodule']
    m.exact(O/'tb.v','\n'.join(lines)+'\n')
    m.exact(O/'trace-ports.h','static const char *input_ports[] = {'+', '.join(json.dumps(n) for n in ins)+'};\n'+
        'static const char *output_ports[] = {'+', '.join(json.dumps(n) for n in outs)+'};\n')
    save(O/'target-token-binding.json',dict(target_RTL_sha256=sha(rtl),testbench_sha256=sha(O/'tb.v'),
        original_stimulus_sha256=sha(prior),tokens=3003,public_outputs=73,
        sample='post_target_rising_edge',invalid_internal_seed=False,
        functional_equivalence_claim=False,scope='Independent target oracle for mixed host transform/token validation.'))
    exe=O/'target.vvp'
    m.stage('compile-token-target',['/usr/bin/iverilog','-g2012','-s','tb','-o',exe,rtl,O/'tb.v'],[exe])
    m.stage('target-token-oracle',['/usr/bin/vvp',exe],marker='MIXED_TARGET_TOKEN_ORACLE_PASS tokens=3003 outputs=73')
    rows=trace.read_text().splitlines()
    assert len(rows)==3003 and all(len(l.split())==len(ins)+73 for l in rows)
    assert all(re.fullmatch('[0-9a-fA-F]+',v) for l in rows[3:] for v in l.split())
    save(O/'target-oracle.json',dict(tokens=3003,public_outputs=73,trace=str(trace),trace_sha256=sha(trace),
        oracle_is_independent_unthreaded_target=True,not_complete_functional_equivalence=True))
    return trace

