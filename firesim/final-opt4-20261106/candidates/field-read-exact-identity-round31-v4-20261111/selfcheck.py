"""SAT and conservative-negative checks for the two exact alias rules."""
from pathlib import Path
import hashlib
import json
import subprocess
from canonical import compare


def run(out):
    def policy():
        p = json.loads(Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/unattended-opt4/campaign-policy.json').read_text())
        assert p['area_equivalence_only'] and not p['functional_extensions_allowed']

    policy()
    parent = """module Check(input a, input b, input clock, input [2:0] debug_s2_type, input [31:0] data, output [31:0] y, output q);\nreg q;
wire selector = a & b;
wire isZero = debug_s2_type == 3'h0;
assign y = isZero ? data : selector ? 32'h5 : 32'h7;
always @(posedge clock) q <= a;
endmodule"""
    candidate = parent.replace('isZero ? data : selector ?', "debug_s2_type == 3'h0 ? data : a & b ?")
    cases = {'positive': compare(parent, candidate, set())}
    assert cases['positive']['identical']
    mutations = {
        'wrong_and_operand': candidate.replace('a & b ?', 'a & a ?'),
        'wrong_and_operator': candidate.replace('a & b ?', 'a | b ?'),
        'wrong_predicate': candidate.replace("debug_s2_type == 3'h0 ?", "debug_s2_type == 3'h1 ?"),
        'wrong_data': candidate.replace('? data :', "? data ^ 32'h1 :"),
        'wrong_clock_edge': candidate.replace('posedge', 'negedge'),
        'wrong_state_update': candidate.replace('q <= a', 'q <= b'),
    }
    for label, text in mutations.items():
        cases[label] = compare(parent, text, set())
        assert not cases[label]['identical'], label
    wider_parent = parent.replace('input a, input b,', 'input [1:0] a, input [1:0] b,')
    wider_candidate = candidate.replace('input a, input b,', 'input [1:0] a, input [1:0] b,')
    cases['wider_and_not_normalized'] = compare(wider_parent, wider_candidate, set())
    assert not cases['wider_and_not_normalized']['identical']
    context_parent = "module Width(input a, output y); wire t = ~a; assign y = t == 2'h2; endmodule"
    context_candidate = "module Width(input a, output y); assign y = ~a == 2'h2; endmodule"
    cases['complement_context_not_normalized'] = compare(context_parent, context_candidate, set())
    assert not cases['complement_context_not_normalized']['identical']
    and_or_parent = 'module Shape(input a, input b, input c, output y); wire select = a & b; assign y = select | c; endmodule'
    and_or_candidate = 'module Shape(input a, input b, input c, output y); assign y = a & b | c; endmodule'
    cases['exact_one_bit_and_or'] = compare(and_or_parent, and_or_candidate, set())
    assert cases['exact_one_bit_and_or']['identical']
    cases['changed_one_bit_and_or'] = compare(and_or_parent, and_or_candidate.replace('a & b', 'a & c'), set())
    assert not cases['changed_one_bit_and_or']['identical']
    if_parent = 'module IfShape(input a, input b, input clock, output q); reg q; wire select = a & b; always @(posedge clock) if (select) q <= a; endmodule'
    if_candidate = if_parent.replace('if (select)', 'if (a & b)')
    cases['exact_if_and'] = compare(if_parent, if_candidate, set())
    assert cases['exact_if_and']['identical']
    cases['changed_if_and'] = compare(if_parent, if_candidate.replace('if (a & b)', 'if (a | b)'), set())
    assert not cases['changed_if_and']['identical']

    rtl = out / 'selector-selfcheck.v'
    rtl.write_text("""module SelectorProof(input a,b, input [2:0] t, input [31:0] data, output equivalent, mutantEquivalent);
wire selector = a & b;
wire isZero = t == 3'h0;
wire [31:0] parent = isZero ? data : selector ? 32'h5 : 32'h7;
wire [31:0] candidate = t == 3'h0 ? data : a & b ? 32'h5 : 32'h7;
wire [31:0] mutant = t == 3'h0 ? data : a | b ? 32'h5 : 32'h7;
wire andOrParent = selector | data[0];
wire andOrCandidate = a & b | data[0];
assign equivalent = parent == candidate && andOrParent == andOrCandidate;
assign mutantEquivalent = parent == mutant;
endmodule
""")
    sat = []
    for label, output, expected in [('equivalence', 'equivalent', True), ('mutation', 'mutantEquivalent', False)]:
        policy()
        script = out / ('selector-' + label + '.ys')
        script.write_text(f'read_verilog {rtl}\nprep -top SelectorProof\nsat -verify -prove {output} 1 -show-inputs -timeout 60\n')
        log = out / ('selector-' + label + '.log')
        with log.open('xb') as f:
            result = subprocess.run(['/usr/local/bin/yosys', '-s', str(script)], stdout=f, stderr=subprocess.STDOUT, timeout=120)
        text = log.read_text()
        assert (result.returncode == 0 and 'no model found: SUCCESS' in text) if expected else (result.returncode != 0 and 'model found: FAIL' in text)
        sat.append(dict(label=label, returncode=result.returncode, log_sha256=hashlib.sha256(log.read_bytes()).hexdigest()))
    (out / 'restricted-checker-selfcheck.json').write_text(json.dumps(dict(status='PASS_TWO_EXACT_PREDICATE_RULES_SAT_AND_EIGHT_CONSERVATIVE_NEGATIVES', cases=cases, sat=sat), indent=2, sort_keys=True) + '\n')
