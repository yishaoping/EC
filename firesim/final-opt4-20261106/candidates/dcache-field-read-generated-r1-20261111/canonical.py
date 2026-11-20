"""Conservative identity check for a field-reader-only generated RTL rewrite.

This is symbolic expression identity, not a general Verilog equivalence solver.
Any unrecognized structure or nonidentical expression must remain UNPROVEN.
Widths, memories, registers, every sequential statement, assertions, prints,
submodule connections, original outputs and requested observations are checked.
"""
import hashlib
import re
import sys

sys.setrecursionlimit(50000)
LEX = re.compile(r'"(?:\\.|[^"\\])*"|//[^\n]*|/\*[\s\S]*?\*/')
TOKEN = re.compile(r'"(?:\\.|[^"\\])*"|\b\d+\s*\x27[sS]?[hHdDbBoO][0-9a-fA-F_xXzZ?]+|[A-Za-z_$][A-Za-z0-9_$]*|\S')
IDENT = re.compile(r'[A-Za-z_$][A-Za-z0-9_$]*\Z')
DECL = re.compile(r'\b(input|output|wire|reg)\s+(\[[^\]\n]+\]\s*)?([A-Za-z_][\w$]*)(\s*\[[^\]\n]+\])?')
WIRE = re.compile(r'\bwire\s+(?:\[[^\]]+\]\s*)?([A-Za-z_][\w$]*)\s*=\s*([^;]+);')
ASSIGN = re.compile(r'\bassign\s+([A-Za-z_][\w$]*)\s*=\s*([^;]+);')
BARE = re.compile(r'\b(?:wire|reg)\s+(?:\[[^\]\n]+\]\s*)?[A-Za-z_][\w$]*(?:\s*\[[^\]\n]+\])?\s*;')


def strip_comments(s):
    return LEX.sub(lambda m: m[0] if m[0].startswith('"') else ' ', s)


def squash(s):
    return re.sub(r'\s+', '', s)


def modules(s):
    out = {}
    for m in re.finditer(r'^module ([A-Za-z_][\w$]*)\(', s, re.M):
        assert m[1] not in out
        end = s.index('\nendmodule', m.end()) + len('\nendmodule')
        out[m[1]] = strip_comments(s[m.start():end])
    assert out
    return out


class Cone:
    def __init__(self, text):
        header = re.match(r'module \w+\((.*?)\);', text, re.S)
        assert header
        self.header = squash(header[1])
        self.body = text[header.end():]
        self.types = {}
        self.registers = {}
        self.outputs = set()
        for m in DECL.finditer(text):
            kind, width, name, array = m.groups()
            width = squash(width or '[0:0]')
            typ = (width, squash(array or ''))
            assert name not in self.types or self.types[name] == typ, (name, typ)
            self.types[name] = typ
            if kind == 'reg':
                self.registers[name] = typ
            if kind == 'output':
                self.outputs.add(name)
        self.defs = {}
        for pattern in [WIRE, ASSIGN]:
            for m in pattern.finditer(self.body):
                name, expr = m.groups()
                assert name in self.types and name not in self.defs, name
                assert name not in self.registers, name
                self.defs[name] = expr.strip()
        self.cache = {}
        self.visiting = set()

    def symbol(self, name):
        if name in self.cache:
            return self.cache[name]
        assert name not in self.visiting, ('combinational cycle', name)
        if name not in self.defs:
            return 'leaf:' + name + ':' + repr(self.types.get(name))
        self.visiting.add(name)
        expr = self.defs[name]
        if IDENT.fullmatch(expr) and self.types.get(expr) == self.types[name]:
            result = self.symbol(expr)
        else:
            material = repr(self.types[name]) + ':' + self.expression(expr)
            result = 'cone:' + hashlib.sha256(material.encode()).hexdigest()
        self.visiting.remove(name)
        self.cache[name] = result
        return result

    def expression(self, expr):
        pieces = []
        previous = ''
        for m in TOKEN.finditer(expr):
            t = m[0]
            # Named submodule ports and string contents are syntax, not wires.
            pieces.append(self.symbol(t) if IDENT.fullmatch(t) and t in self.types and previous != '.' else t)
            previous = t
        return '|'.join(pieces)

    def residual(self):
        text = ASSIGN.sub('', WIRE.sub('', self.body))
        text = BARE.sub('', text)
        # Source location text is intentionally kept: a mismatch is unproven.
        return self.expression(text)


def compare(a, b, observations):
    left, right = Cone(a), Cone(b)
    assert left.header == right.header, 'original interface changed'
    assert left.registers == right.registers, 'register/memory state or widths changed'
    assert left.outputs == right.outputs
    roots = sorted(left.outputs | set(observations))
    missing = [n for n in roots if n not in left.types or n not in right.types]
    assert not missing, ('missing observation', missing)
    mismatches = [n for n in roots if left.types[n] != right.types[n] or left.symbol(n) != right.symbol(n)]
    residual_equal = left.residual() == right.residual()
    return dict(identical=not mismatches and residual_equal,
                mismatched_observations=mismatches, all_sequential_assert_print_and_instance_statements_identical=residual_equal,
                checked_observations=len(roots), register_and_memory_objects=len(left.registers),
                parent_defined_cones=len(left.defs), candidate_defined_cones=len(right.defs),
                method='Conservative width-preserving symbolic cone identity; no algebraic simplification or ignored statements')
