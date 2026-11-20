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
        self.boolean_nodes = {}

    def boolean(self, expr):
        """Parse a restricted typed Boolean expression, or return None.

        Keep operator order and every operand. No identities, arithmetic,
        signed conversions, truncations, memory selects or muxes are inferred.
        Only a root proven to have width1 may replace a width1 wire.
        """
        lex = re.compile(r"\d+'[sS]?[hHdDbBoO][0-9a-fA-F_xXzZ]+|[A-Za-z_][\w$]*|===|!==|==|!=|<=|>=|&&|\|\||~\^|\^~|[()~!&|^<>]")
        tokens = lex.findall(expr)
        if ''.join(tokens) != squash(expr):
            return None
        precedence = {'||': 1, '&&': 2, '|': 3, '^': 4, '~^': 4, '^~': 4,
                      '&': 5, '==': 6, '!=': 6, '===': 6, '!==': 6,
                      '<': 7, '>': 7, '<=': 7, '>=': 7}
        at = 0

        def digest_node(value):
            return 'node:' + hashlib.sha256(repr(value).encode()).hexdigest()

        def primary():
            nonlocal at
            if at >= len(tokens):
                raise ValueError('missing Boolean operand')
            t = tokens[at]; at += 1
            if t == '(':
                node, width = parse(0)
                if at >= len(tokens) or tokens[at] != ')':
                    raise ValueError('unbalanced Boolean expression')
                at += 1
                return node, width
            if t in ['!', '~', '&', '|', '^', '~^', '^~']:
                node, width = primary()
                return digest_node(('unary', t, node)), width if t == '~' else 1
            literal = re.fullmatch(r"(\d+)'[sS]?[hHdDbBoO][0-9a-fA-F_xXzZ]+", t)
            if literal:
                return digest_node(('literal', t)), int(literal[1])
            if t not in self.types or self.types[t][1]:
                raise ValueError('untyped/array Boolean operand')
            dims = re.fullmatch(r'\[(\d+):(\d+)\]', self.types[t][0])
            if not dims:
                raise ValueError('unknown width')
            width = abs(int(dims[1]) - int(dims[2])) + 1
            digest = self.symbol(t)
            return self.boolean_nodes.get(t, digest_node(('typed', width, digest))), width

        def parse(minimum):
            nonlocal at
            left, lw = primary()
            while at < len(tokens) and tokens[at] in precedence and precedence[tokens[at]] >= minimum:
                op = tokens[at]; at += 1
                right, rw = parse(precedence[op] + 1)
                left = digest_node(('binary', op, lw, rw, left, right))
                lw = max(lw, rw) if op in ['&', '|', '^', '~^', '^~'] else 1
            return left, lw

        try:
            node, width = parse(0)
            return node if at == len(tokens) and width == 1 else None
        except ValueError:
            return None

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
            if expr in self.boolean_nodes:
                self.boolean_nodes[name] = self.boolean_nodes[expr]
        else:
            boolean = self.boolean(expr) if self.types[name] == ('[0:0]', '') else None
            if boolean is not None:
                self.boolean_nodes[name] = boolean
                result = 'bool:' + hashlib.sha256(repr(boolean).encode()).hexdigest()
            else:
                material = repr(self.types[name]) + ':' + self.expression(expr)
                result = 'cone:' + hashlib.sha256(material.encode()).hexdigest()
        self.visiting.remove(name)
        self.cache[name] = result
        return result

    def normalize_selector(self, expr):
        # Eliminate only a one-bit named comparison/bitwise operation at the leading ternary
        # selector. Both supported forms have exactly1bit in Verilog, and the position
        # before ? preserves grouping without distributive/algebraic changes.
        # Do not inline general arithmetic or arbitrary predicates; bitwise operands must both be explicit1bit declarations.
        lead = re.match(r'^\s*([A-Za-z_][\w$]*)\s*\?([\s\S]*)$', expr)
        if lead:
            name = lead[1]
            visited = set()
            while name in self.defs and self.types.get(name) == ('[0:0]', ''):
                assert name not in visited
                visited.add(name)
                rhs = self.defs[name]
                if IDENT.fullmatch(rhs) and self.types.get(rhs) == ('[0:0]', ''):
                    name = rhs
                    continue
                atom = r"(?:[A-Za-z_][\w$]*|\d+'[sS]?[hHdDbBoO][0-9a-fA-F_xXzZ]+)"
                scalar_compare = re.fullmatch(atom + r'\s*(?:===|!==|==|!=|<=|>=|<|>)\s*' + atom, rhs.strip())
                bits = re.fullmatch(r'([A-Za-z_][\w$]*)\s*(?:&|\||\^|~\^|\^~)\s*([A-Za-z_][\w$]*)', rhs.strip())
                scalar_bitwise = bits and all(self.types.get(n) == ('[0:0]', '') for n in bits.groups())
                if scalar_compare or scalar_bitwise:
                    expr = rhs.strip() + ' ? ' + lead[2]
                break
        return expr

    def expression(self, expr):
        expr = self.normalize_selector(expr)
        if '?' in expr:
            selector, tail = expr.split('?', 1)
            node = self.boolean(selector)
            if node is not None:
                expr = 'WIDTH_ONE_SELECTOR_' + hashlib.sha256(repr(node).encode()).hexdigest() + ' ? ' + tail
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
        # Normalize typed width1 aliases in sequential conditions, preserving
        # every branch/body and every unsupported expression verbatim.
        strings = list(re.finditer(r'"(?:\\.|[^"\\])*"', text))
        ranges = [(m.start(), m.end()) for m in strings]
        edits = []
        string_index = 0
        for m in re.finditer(r'\bif\s*\(', text):
            while string_index < len(ranges) and ranges[string_index][1] <= m.start():
                string_index += 1
            if string_index < len(ranges) and ranges[string_index][0] <= m.start() < ranges[string_index][1]:
                continue
            start = m.end()
            depth = 1
            end = start
            while end < len(text) and depth:
                depth += (text[end] == '(') - (text[end] == ')')
                end += 1
            assert depth == 0, 'unbalanced sequential condition'
            node = self.boolean(text[start:end - 1])
            if node is not None:
                edits.append((start, end - 1, 'WIDTH_ONE_IF_' + hashlib.sha256(repr(node).encode()).hexdigest()))
        chunks = []
        cursor = 0
        for start, end, replacement in edits:
            assert start >= cursor
            chunks.extend([text[cursor:start], replacement])
            cursor = end
        text = ''.join(chunks) + text[cursor:]
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
