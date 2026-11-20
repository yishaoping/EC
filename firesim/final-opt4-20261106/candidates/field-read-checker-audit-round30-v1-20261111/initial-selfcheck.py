"""Check the exact alias rewrite and reject altered semantics before full RTL proof."""
from pathlib import Path
import hashlib
import json
import subprocess

from canonical import compare


def run(out):
    parent = """module Check(input clock, input [2:0] debug_s2_type,
 input [7:0] a, input [7:0] b, output [7:0] y, output [7:0] q);
 wire predicate = debug_s2_type == 3'h0;
 reg [7:0] state;
 assign y = predicate ? a : b;
 assign q = state;
 always @(posedge clock) begin
   if (predicate) begin
     state <= a;
   end else begin
     state <= b;
   end
 end
 endmodule"""
    child = parent.replace(" wire predicate = debug_s2_type == 3'h0;\n", '')
    child = child.replace('predicate', "debug_s2_type == 3'h0")
    cases = {'exact_alias_factoring': compare(parent, child, set())}
    assert cases['exact_alias_factoring']['identical']
    mutations = {
        'changed_predicate': child.replace("3'h0", "3'h1"),
        'changed_data': child.replace('? a : b', '? b : a'),
        'changed_state_update': child.replace('state <= a;', 'state <= b;'),
        'changed_clock_edge': child.replace('posedge', 'negedge'),
        'changed_context_precedence': child.replace("debug_s2_type == 3'h0 ?", "a + debug_s2_type == 3'h0 ?"),
    }
    for name, text in mutations.items():
        cases[name] = compare(parent, text, set())
        assert not cases[name]['identical'], name
    # This proof is exactly the generated three-bit predicate and its data,
    # admission, epoch, generation and transaction mux widths. It does not
    # assume a legal debug_s2_type value or any payload restriction.
    formal = """module PredicateFactoring(input [2:0] debug_s2_type,
 input [31:0] a, b, input [15:0] c, d, input [2:0] kind,
 input [1:0] way_a, way_b, output equivalent);
 wire predicate = debug_s2_type == 3'h0;
 wire [84:0] parent = {predicate ? a : b, predicate ? b : a,
                      predicate ? c : d, predicate ? 3'h5 : kind,
                      predicate ? way_a : way_b};
 wire [84:0] candidate = {debug_s2_type == 3'h0 ? a : b,
                         debug_s2_type == 3'h0 ? b : a,
                         debug_s2_type == 3'h0 ? c : d,
                         debug_s2_type == 3'h0 ? 3'h5 : kind,
                         debug_s2_type == 3'h0 ? way_a : way_b};
 assign equivalent = parent == candidate;
 endmodule
"""
    rtl = out / 'predicate-factoring.v'
    with rtl.open('x') as f:
        f.write(formal)
    yosys = out / 'predicate-factoring.ys'
    with yosys.open('x') as f:
        f.write(f'read_verilog {rtl}\nprep -top PredicateFactoring\nsat -verify -prove equivalent 1 -show-inputs -timeout 60\n')
    log = out / 'predicate-factoring.log'
    with log.open('xb') as f:
        result = subprocess.run(['/usr/local/bin/yosys', '-s', str(yosys)],
                                stdout=f, stderr=subprocess.STDOUT, timeout=120)
    assert result.returncode == 0 and 'no model found: SUCCESS' in log.read_text()
    receipt = dict(status='PASS_EXACT_PREDICATE_FACTORING_SAT_AND_FIVE_SEMANTIC_MUTATIONS_REJECTED',
                   comparison_cases=cases, predicate_width=3, predicate_value=0,
                   assumptions=[], log=str(log), log_sha256=hashlib.sha256(log.read_bytes()).hexdigest())
    with (out / 'checker-validation.json').open('x') as f:
        json.dump(receipt, f, indent=2, sort_keys=True)
        f.write('\n')
