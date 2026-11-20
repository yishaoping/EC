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

    def _base_expression(self, expr):
        pieces = []
        previous = ''
        for m in TOKEN.finditer(expr):
            t = m[0]
            # Named submodule ports and string contents are syntax, not wires.
            pieces.append(self.symbol(t) if IDENT.fullmatch(t) and t in self.types and previous != '.' else t)
            previous = t
        return '|'.join(pieces)

    def expression(self, expr):
        # Only a leading ternary selector is self-determined here. Both
        # operands are explicitly unsigned one-bit declarations. Factoring
        # their AND cannot introduce the complement/context-width bug found
        # in the previous generic Boolean checker. No other AND is rewritten.
        leading = re.match(r'^\s*([A-Za-z_][\w$]*)\s*&\s*([A-Za-z_][\w$]*)\s*\?([\s\S]*)$', expr)
        if leading and all(self.types.get(n) == ('[0:0]', '') for n in leading.groups()[:2]):
            material = repr(('[0:0]', '')) + ':' + self._base_expression(leading[1] + ' & ' + leading[2])
            atom = 'cone:' + hashlib.sha256(material.encode()).hexdigest()
            self.and_selectors = getattr(self, 'and_selectors', 0) + 1
            return atom + '|?|' + self.expression(leading[3])
        # Recognize only the exact, unsigned three-bit equality established by
        # the generated RTL diagnosis. It has a self-determined one-bit result;
        # no arithmetic, complement, general Boolean alias, or wider context is
        # normalized. Unrecognized structure remains conservatively UNPROVEN.
        tokens = TOKEN.findall(expr)
        predicate = ['debug_s2_type', '=', '=', "3'h0"]
        if tokens == predicate:
            return self._base_expression(expr)
        pieces = []
        i = 0
        previous = ''
        while i < len(tokens):
            t = tokens[i]
            if (i + 3 < len(tokens) and tokens[i+1] == '&'
                    and tokens[i+3] == '?'
                    and (i == 0 or tokens[i-1] in ['(', '?', ':'])
                    and all(self.types.get(n) == ('[0:0]', '') for n in [t, tokens[i+2]])):
                material = repr(('[0:0]', '')) + ':' + self._base_expression(t + ' & ' + tokens[i+2])
                pieces.append('cone:' + hashlib.sha256(material.encode()).hexdigest())
                self.and_selectors = getattr(self, 'and_selectors', 0) + 1
                i += 3
                previous = ''
                continue
            if (tokens[i:i+4] == predicate
                    and (i == 0 or tokens[i-1] in ['(', '?', ':'])
                    and (i+4 == len(tokens) or tokens[i+4] in ['?', ')', '&', '|', '^'])
                    and self.types.get('debug_s2_type') == ('[2:0]', '')):
                material = repr(('[0:0]', '')) + ':' + self._base_expression("debug_s2_type == 3'h0")
                pieces.append('cone:' + hashlib.sha256(material.encode()).hexdigest())
                self.equality_atoms = getattr(self, 'equality_atoms', 0) + 1
                i += 4
                previous = ''
                continue
            pieces.append(self.symbol(t) if IDENT.fullmatch(t) and t in self.types and previous != '.' else t)
            previous = t
            i += 1
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
                method='Width-preserving symbolic identity with only exact unsigned debug_s2_type == 3bit zero atom factoring; no ignored statements',
                equality_atoms=dict(parent=getattr(left, 'equality_atoms', 0), candidate=getattr(right, 'equality_atoms', 0)),
                one_bit_and_selectors=dict(parent=getattr(left, 'and_selectors', 0), candidate=getattr(right, 'and_selectors', 0)))
