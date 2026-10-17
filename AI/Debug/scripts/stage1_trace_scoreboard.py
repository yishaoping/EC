#!/usr/bin/env python3
"""Offline Stage 1 streaming analysis. Memory scales with identities, not events.
Hexadecimal numeric fields; preserve text. 0=PASS, 1=FAIL, 2=UNRESOLVED.
"""
import argparse
from collections import Counter, defaultdict
import hashlib
import json
import re
import sys

AMO = {4, 8, 9, 10, 11, 12, 13, 14, 15}  # Rocket Consts.scala
WRITES = AMO | {1, 7}
TEXT = {'source', 'kind', 'class', 'snapshot', 'token_kind', 'reason', 'phase'}
HEX = re.compile(r'(?:0x)?[0-9a-fA-F]+\Z')


def fields(text):
    result = {}
    for token in text.split():
        if '=' in token:
            k, v = token.split('=', 1)
            result[k] = int(v, 16) if k not in TEXT and HEX.fullmatch(v) else v
    return result


def amo_reference(cmd, size, addr, old, operand):
    """RHS is StoreGen replicated XLEN data; old is the complete aligned word."""
    if cmd not in AMO or size not in (2, 3) or addr % (1 << size):
        raise ValueError('unsupported/misaligned AMO')
    bits, shift = 8 << size, (addr & 7) * 8
    mask = (1 << bits) - 1
    a, b = (old >> shift) & mask, (operand >> shift) & mask
    signed = lambda v: v - (1 << bits) if v >> (bits - 1) else v
    operations = {4: lambda: b, 8: lambda: a+b, 9: lambda: a^b,
                  10: lambda: a|b, 11: lambda: a&b,
                  12: lambda: min(signed(a), signed(b)),
                  13: lambda: max(signed(a), signed(b)),
                  14: lambda: min(a, b), 15: lambda: max(a, b)}
    new = (old & ~(mask << shift)) | ((operations[cmd]() & mask) << shift)
    return new, signed(a) & ((1 << 64)-1), ((1 << (1 << size))-1) << (addr & 7)


class Scoreboard:
    def __init__(self, workload=None):
        self.events, self.errors = Counter(), Counter()
        self.tx, self.replay, self.report = {}, {}, {}
        self.boom, self.checker, self.amo_coverage = Counter(), Counter(), Counter()
        self.samples, self.snapshots, self.arch_errors = [], [], []
        self.sim_exit = None
        self.workload = workload or {}
        self.exit_stq, self.exit_drain = {}, {}
        self.verified = None
        self.race_cycle, self.race_batch = None, []
        self.clear_epochs, self.installs, self.race_coverage = {}, {}, Counter()
        self.refill_beats = {}
        self.race_missing_fields = False
        self.boom_seq, self.checker_seq = Counter(), Counter()
        self.seq_missing = False
        self.stat_occurrences = {'MAIN': defaultdict(list), 'CHECKER': defaultdict(list)}
        self.stat_ids = {'MAIN': {}, 'CHECKER': {}}
        self.stat_duplicates = {'MAIN': [], 'CHECKER': []}
        self.checker_identity_missing = False
        self.killed = set()
        self.software_failures, self.software_end = [], None

    def error(self, reason, token, line):
        self.errors[reason] += 1
        if len(self.samples) < 40:
            self.samples.append(dict(reason=reason, token=token, line=line))

    def race_event(self, kind, f, line):
        if 'cycle' not in f:
            self.race_missing_fields = True
            return
        cycle = f['cycle']
        if self.race_cycle is not None and cycle != self.race_cycle:
            if cycle < self.race_cycle:
                self.error('RACE_CYCLE_REVERSED', 0, line)
            self.flush_race()
        self.race_cycle = cycle
        self.race_batch.append((kind, f, line))

    def flush_race(self):
        # printf order within a clock is arbitrary; compare the complete cycle.
        batch, self.race_batch = self.race_batch, []
        clears = {(f['set'], f['way']): f for k, f, _ in batch if k == 'CLEAR'}
        checks = {(f['set'], f['way']): f for k, f, _ in batch
                  if k == 'CLEAR_CHECK' and f.get('fire')}
        installs = [f for k, f, _ in batch if k == 'INSTALL']
        refills = [f for k, f, _ in batch if k == 'REFILL']
        hits = [f for k, f, _ in batch if k == 'S2' and f.get('admission') == 7]
        effects = [f for k, f, _ in batch if k == 'EFFECT']
        # Cycles with concurrent activity, separate from same-slot conflicts.
        for name, a, b in (('clear_refill', clears, refills),
                           ('install_hit', installs, hits), ('refill_hit', refills, hits),
                           ('install_effect', installs, effects), ('refill_effect', refills, effects)):
            self.race_coverage[name] += bool(a and b)
        for kind, f, _ in batch:
            if kind == 'RACE_OBSERVE':
                for name in ('kill_replay', 's1_replay_killed', 's2_replay_killed'):
                    self.race_coverage[name] += bool(f.get(name))
        for slot in clears:
            if slot not in checks:
                self.error('CLEAR_CHECK_MISSING', 0, 0)
        for kind, f, line in batch:
            if kind not in {'CLEAR', 'CLEAR_CHECK', 'INSTALL', 'REFILL', 'EFFECT'}:
                continue
            if not all(k in f for k in ('set', 'way')):
                self.race_missing_fields = True
                continue
            slot = (f['set'], f['way'])
            if kind == 'CLEAR_CHECK':
                self.race_coverage['checks'] += 1
                for stage in ('s1_any', 's2_any', 's1_old', 's2_old'):
                    self.race_coverage[stage] += bool(f.get(stage))
                required = ('fire', 's1_old', 's2_old', 's3', 'completion', 'slot_conflict')
                if not all(k in f for k in required):
                    self.race_missing_fields = True
                elif f['fire'] and any(f[k] for k in required[1:]):
                    self.error('CLEAR_DRAIN_VIOLATION', 0, line)
                continue
            if kind == 'CLEAR':
                self.race_coverage['clear'] += 1
                continue
            if kind in {'INSTALL', 'REFILL'} and slot in clears:
                self.error('CLEAR_INSTALL_REFILL_OVERLAP', f.get('req', 0), line)
            if kind == 'INSTALL':
                self.installs[slot] = {k: f[k] for k in ('line', 'epoch', 'mshr', 'txn')}
                self.refill_beats[slot] = set()
                self.race_coverage['install'] += 1
            elif kind == 'REFILL':
                owner = {k: f[k] for k in ('line', 'epoch', 'mshr', 'txn')}
                if self.installs.get(slot) != owner:
                    self.error('REFILL_OWNER_MISMATCH', f.get('token', 0), line)
                beats = self.refill_beats.setdefault(slot, set())
                if f['beat'] in beats or f['beat'] != len(beats):
                    self.error('REFILL_BEAT_ORDER', f.get('token', 0), line)
                beats.add(f['beat'])
                self.race_coverage['refill'] += 1
            elif kind == 'EFFECT' and f.get('owner_match') != 1:
                self.error('EFFECT_OWNER_MISMATCH', f.get('req', 0), line)
            if kind in {'INSTALL', 'REFILL', 'EFFECT'}:
                last = self.clear_epochs.get(slot)
                if last is not None and f['epoch'] <= last:
                    self.error('STALE_POST_CLEAR_' + kind, f.get('req', 0), line)
                if kind == 'EFFECT' and slot in clears:
                    self.error('CLEAR_EFFECT_OVERLAP', f.get('req', 0), line)
        for slot, f in clears.items():
            self.clear_epochs[slot] = f['epoch']

    def event(self, kind, f, line):
        self.events[kind] += 1
        token, cmd = f.get('req', f.get('token')), f.get('cmd')
        if kind in {'CLEAR', 'CLEAR_CHECK', 'INSTALL', 'REFILL', 'EFFECT', 'S2', 'RACE_OBSERVE'}:
            self.race_event(kind, f, line)
        if kind == 'KILL' and f.get('phase') == 'S3':
            self.killed.add(token)
            if 'effect' in self.tx.get(token, {}):
                self.error('KILLED_EFFECT', token, line)
        if kind == 'EFFECT' and token in self.killed:
            self.error('KILLED_EFFECT', token, line)
        if kind == 'ARCH_STORE':
            t = self.tx.setdefault(token, {})
            if 'arch_commit' in t:
                self.error('DUP_ARCH_STORE', token, line)
            t.update(arch=line, arch_commit=line, pc=f['pc'], addr=f['addr'],
                     cmd=cmd, fence=f.get('fence', 0), stq=f['stq'])
        elif kind == 'EXIT_DRAIN' and f.get('snapshot') == 'sim_exit':
            if f.get('source') in self.exit_drain:
                self.error('DUP_EXIT_DRAIN', 0, line)
            self.exit_drain[f.get('source')] = f
        elif kind == 'EXIT_STQ' and f.get('snapshot') == 'sim_exit':
            if token in self.exit_stq:
                self.error('DUP_EXIT_STQ', token, line)
            self.exit_stq[token] = f
        if kind == 'BOOM_STAT' and f.get('class') == 'ARCH':
            self.stat_event('MAIN', f, line)
            self.boom[(f['kind'], f['pc'], f['addr'], f['cacheable'])] += 1
            if 'seq' in f:
                self.boom_seq[(f['seq'], f['kind'], f['cacheable'])] += 1
            else:
                self.seq_missing = True
            if f['kind'] == 'STORE':
                self.tx.setdefault(token, {}).update(arch=line, pc=f['pc'], addr=f['addr'])
        elif kind == 'CHECKER_STAT':
            self.stat_event('CHECKER', f, line)
            self.checker[(f['kind'], f['pc'], f['addr'], f['cacheable'])] += 1
            self.checker_seq[(token, f['kind'], f['cacheable'])] += 1
        elif kind == 'EXIT_STATE':
            self.snapshots.append(dict(f, line=line))
        if kind in {'ISSUE', 'S2'} and cmd in WRITES:
            t = self.tx.setdefault(token, {})
            for key in ('cmd', 'stq', 'addr', 'seq', 'size', 'admission', 'pc', 'is_hella'):
                if key in f:
                    t[key] = f[key]
            if kind == 'ISSUE':
                t.setdefault('issue', line)
                t['attempts'] = t.get('attempts', 0) + 1
                if 'size' in f and 'addr' not in f or f.get('source') == 'DCACHE':
                    t['grant'] = line
        if kind in {'EFFECT', 'TERMINAL', 'STORE_DONE', 'RELEASE', 'AMO'}:
            t = self.tx.setdefault(token, {})
            if f.get('effect', token) != token:
                self.error('IDENTITY_MISMATCH', token, line)
            if 'stq' in t and 'stq' in f and t['stq'] != f['stq']:
                self.error('STQ_MISMATCH', token, line)
            name = kind.lower()
            if name in t:
                self.error('DUP_' + kind, token, line)
            t[name] = line
            if 'cycle' in f:
                t[name + '_cycle'] = f['cycle']
            if kind == 'EFFECT':
                t['effect_data'] = f['data']
                if cmd in AMO and all(k in f for k in ('old', 'operand', 'new', 'returned', 'mask')):
                    expected = amo_reference(cmd, f['size'], f['addr'], f['old'], f['operand'])
                    t['amo_expected'] = expected[:2]
                    self.amo_coverage[(cmd, f['size'], f['addr'] & 7)] += 1
                    if (f['new'], f['returned'], f['mask']) != expected:
                        self.error('AMO_SEMANTICS', token, line)
            elif kind == 'TERMINAL':
                t.update(cmd=cmd, status=f['status'], terminal_data=f['data'], needs_stq=not f.get('is_hella', 0))
                if 'admission' in f:
                    t['terminal_admission'] = f['admission']
            elif kind == 'STORE_DONE':
                t.update(done_status=f['status'], done_data=f['data'])
            elif kind == 'RELEASE':
                t['fence'] = f.get('fence', int(not f['done']))
                if not f['committed'] or f['inflight']:
                    self.error('EARLY_RELEASE', token, line)
            else:
                expected = amo_reference(cmd, f['size'], f['addr'], f['old'], f['operand'])
                t['amo_expected'] = expected[:2]
                self.amo_coverage[(cmd, f['size'], f['addr'] & 7)] += 1
                if (f['new'], f['returned'], f['mask']) != expected:
                    self.error('AMO_SEMANTICS', token, line)
        if kind in {'REPLAY_GRANT', 'REPLAY_RESULT'}:
            key = (f['mshr'], f['txn'], token)
            r = self.replay.setdefault(key, Counter())
            if kind == 'REPLAY_GRANT':
                r['grant'] += 1
            else:
                r['result'] += 1
                r['status_' + str(f['status'])] += 1

    def stat_event(self, source, f, line):
        seq = f.get('seq') if source == 'MAIN' else f.get('token')
        key = (seq, f['kind'], f['pc'], f['addr'], f['cacheable'])
        record = dict(f, log_line=line)
        self.stat_occurrences[source][key].append(record)
        identity = ((f['kind'], f.get('token')) if source == 'MAIN' else
                    (f['hart'], f['ordinal']) if all(k in f for k in ('hart', 'ordinal')) else None)
        if identity is None:
            self.checker_identity_missing = True
        elif identity in self.stat_ids[source]:
            self.stat_duplicates[source].append(dict(record, first_line=self.stat_ids[source][identity]))
            self.error('DUP_STAT_' + source, f.get('token'), line)
        else:
            self.stat_ids[source][identity] = line

    def consume(self, raw, line):
        # Software's [ASSERT] traffic diagnostics are distinct from an RTL
        # assertion or an architectural data mismatch. Preserve both domains.
        if raw.startswith((b'[ASSERT]', b'[VERIFY', b'[TRAFFIC', b'[ADDRESS_STATS',
                           b'[BARRIER', b'[LATENCY', b'[END]')):
            if re.search(rb'(?:status|result)=(?:FAIL|TIMEOUT|INVARIANT_FAIL)\b|\bFAIL\s*$', raw):
                self.software_failures.append(dict(line=line, text=raw.decode().strip()))
            if raw.startswith(b'[END]'):
                match = re.search(rb'status=(\w+)', raw)
                self.software_end = match[1].decode() if match else None
        if raw.startswith(b'STAGE1_TX '):
            kind, _, tail = raw[10:].decode('utf-8', 'replace').strip().partition(' ')
            self.event(kind, fields(tail), line)
        elif raw.startswith(b'STAGE1_SIM_EXIT '):
            self.sim_exit = raw.decode().strip()
        elif raw.startswith(b'[RUN]') and b'verified=' in raw:
            match = re.search(rb'verified=(\d+)', raw)
            self.verified = int(match.group(1)) if match else None
        elif raw.startswith(b'[TRAFFIC]'):
            tokens = raw.decode().split()
            if len(tokens) >= 8 and tokens[1] in {'boom_arch', 'boom_strict', 'checker_sum'}:
                self.report[tokens[1]] = list(map(int, tokens[2:8]))
        elif any(x in raw for x in (b'Assertion failed', b'Assertion Failure', b'[LSL_MISMATCH]', b'[CHECK_ERROR]')):
            if len(self.arch_errors) < 20:
                self.arch_errors.append(dict(line=line, text=raw.decode('utf-8', 'replace').strip()))

    def finish(self):
        self.flush_race()
        outstanding, terminal_exempt = [], Counter()
        snapshot_ready = (set(self.exit_drain) == {'DCACHE', 'LSU'} and
                          all(f.get('schema') == 1 for f in self.exit_drain.values()))
        if snapshot_ready:
            lsu = self.exit_drain['LSU']
            for name, bit in (('stq_valid', 0), ('stq_committed', 1), ('stq_inflight', 2), ('stq_done', 3)):
                if lsu.get(name) != sum(bool(f['flags'] & (1 << bit)) for f in self.exit_stq.values()):
                    self.error('EXIT_STQ_SNAPSHOT_MISMATCH', 0, 0)
        for token, t in self.tx.items():
            terminal, effect = 'terminal' in t, 'effect' in t
            if effect and not terminal:
                self.error('EFFECT_WITHOUT_TERMINAL', token, t['effect'])
            if terminal:
                status = t['status']
                mmio = t.get('terminal_admission', t.get('admission')) == 4
                if not effect:
                    if mmio or status in (2, 3):
                        terminal_exempt['mmio' if mmio else 'noWriteSC' if status == 2 else 'cancel'] += 1
                    else:
                        self.error('TERMINAL_WITHOUT_EFFECT', token, t['terminal'])
                if effect and status != 0:
                    self.error('EFFECT_WITH_NONAPPLIED_TERMINAL', token, t['terminal'])
                if t.get('needs_stq', True) and 'store_done' not in t:
                    self.error('TERMINAL_WITHOUT_STORE_DONE', token, t['terminal'])
                elif 'store_done' in t and (status, t['terminal_data']) != (t['done_status'], t['done_data']):
                    self.error('STORE_DONE_MISMATCH', token, t['store_done'])
                if t.get('needs_stq', True) and 'release' not in t:
                    self.error('TERMINAL_WITHOUT_RELEASE', token, t['terminal'])
            if 'release' in t and not t['fence'] and not terminal:
                self.error('RELEASE_WITHOUT_TERMINAL', token, t['release'])
            if 'store_done' in t and not terminal:
                self.error('ORPHAN_STORE_DONE', token, t['store_done'])
            # Within-cycle printf ordering is arbitrary. Old logs lack cycles.
            for a, b in (('effect', 'terminal'), ('terminal', 'store_done'), ('store_done', 'release')):
                ac, bc = t.get(a+'_cycle'), t.get(b+'_cycle')
                if ac is not None and bc is not None and ac > bc:
                    self.error('ORDER_'+a+'_'+b, token, t[b])
            if 'amo_expected' in t:
                new, ret = t['amo_expected']
                if effect and t['effect_data'] != new:
                    self.error('AMO_EFFECT', token, t['effect'])
                if terminal and t['terminal_data'] != ret:
                    self.error('AMO_RETURN', token, t['terminal'])
            if ('arch' in t or 'grant' in t) and not terminal and not t.get('fence'):
                outstanding.append(dict(token=token, **t))
        def is_exit_tail(item):
            region = self.workload.get('exit_pc_range')
            return bool(region and item.get('cmd') == 1 and
                        region[0] <= item.get('pc', 0) < region[1] and
                        item.get('addr') in self.workload.get('exit_addresses', []))
        exit_tail = [item for item in outstanding if is_exit_tail(item)]
        for item in outstanding:
            if not snapshot_ready:
                continue
            owner = self.exit_stq.get(item['token'])
            if item.get('is_hella'):
                continue
            if (owner is None or not owner['flags'] & 1 or
                    (owner['pc'], owner['addr'], owner['stq']) !=
                    (item.get('pc'), item.get('addr'), item.get('stq'))):
                self.error('LOST_ARCH_STORE', item['token'], item.get('arch', item.get('grant', 0)))
            else:
                # A software-exit exemption requires a committed ordinary
                # store with physical address + data, and no L1 acceptance.
                ready_store = owner['flags'] & 0xf3 == 0xa3
                item['exit_state'] = ('issued_pending' if owner['flags'] & 4 or 'grant' in item else
                                      'committed_unissued' if ready_store else 'owner_not_ready')
        unclassified_stq = []
        for token, owner in self.exit_stq.items():
            if not owner['flags'] & 2:
                continue
            t = self.tx.get(token)
            if t is None or 'arch_commit' not in t:
                self.error('EXIT_STQ_WITHOUT_ARCH', token, 0)
                unclassified_stq.append(owner)
        # A known _exit PC is a classification only. It never exempts missing
        # effects/terminals/releases, or nonempty RTL state, from a closure gate.
        for key, r in self.replay.items():
            if r['grant'] != r['result'] or r['result']-r['status_4'] != 1:
                self.error('REPLAY_CLOSURE', key[2], 0)
        delta = self.boom.copy()
        delta.subtract(self.checker)
        pc_delta = Counter()
        for (kind, pc, addr, cacheable), count in delta.items():
            pc_delta[(kind, pc, cacheable)] += count
        groups = {
            'effect_terminal': ('EFFECT_WITHOUT_TERMINAL', 'DUP_TERMINAL', 'TERMINAL_WITHOUT_EFFECT', 'IDENTITY_MISMATCH', 'EFFECT_WITH_NONAPPLIED_TERMINAL'),
            'terminal_release': ('TERMINAL_WITHOUT_RELEASE', 'DUP_RELEASE', 'RELEASE_WITHOUT_TERMINAL', 'EARLY_RELEASE', 'STORE_DONE_MISMATCH', 'STQ_MISMATCH', 'DUP_STORE_DONE', 'TERMINAL_WITHOUT_STORE_DONE', 'ORPHAN_STORE_DONE'),
            'duplicate_effect': ('DUP_EFFECT',), 'lost_effect': ('EFFECT_WITHOUT_TERMINAL', 'TERMINAL_WITHOUT_EFFECT', 'LOST_ARCH_STORE', 'EXIT_STQ_WITHOUT_ARCH'),
            'amo_w': ('AMO_SEMANTICS', 'AMO_EFFECT', 'AMO_RETURN')}
        gates = {k: 'FAIL' if any(self.errors[e] for e in v) else 'PASS' for k, v in groups.items()}
        if not self.events['EFFECT'] and not self.events['TERMINAL']:
            for name in ('effect_terminal', 'duplicate_effect', 'lost_effect'):
                if gates[name] != 'FAIL':
                    gates[name] = 'UNRESOLVED'
        if not self.events['RELEASE']:
            if gates['terminal_release'] != 'FAIL':
                gates['terminal_release'] = 'UNRESOLVED'
        if any(k.startswith('ORDER_') for k in self.errors):
            gates['effect_terminal'] = gates['terminal_release'] = 'FAIL'
        amo_w_keys = {(cmd, lane) for cmd, size, lane in self.amo_coverage if size == 2}
        if gates['amo_w'] != 'FAIL' and (not amo_w_keys or
                                          not {lane for _, lane in amo_w_keys}.issuperset({0, 4})):
            gates['amo_w'] = 'UNRESOLVED'
        gates['architectural_data'] = ('FAIL' if self.arch_errors or self.verified == 0 else
                                       'PASS' if self.verified == 1 and self.sim_exit and
                                       'reason=serial_success ' in self.sim_exit else 'UNRESOLVED')
        race_errors = sum(v for k, v in self.errors.items() if k.startswith(
            ('CLEAR_', 'REFILL_', 'STALE_POST_CLEAR_', 'EFFECT_OWNER_', 'RACE_', 'KILLED_EFFECT')))
        gates['clear_s1_s2_refill'] = ('FAIL' if race_errors else 'PASS' if
            not self.race_missing_fields and all(self.race_coverage[k] for k in
                ('clear', 'checks', 'install', 'refill')) else 'UNRESOLVED')
        diffs = None
        if 'boom_arch' in self.report and 'checker_sum' in self.report:
            diffs = [a-b for a, b in zip(self.report['boom_arch'], self.report['checker_sum'])]
        gates['main_checker'] = 'UNRESOLVED' if diffs is None else 'FAIL' if any(diffs) else 'PASS'
        seq_delta = self.boom_seq.copy()
        seq_delta.subtract(self.checker_seq)
        if not self.seq_missing and any(seq_delta.values()):
            gates['main_checker'] = 'FAIL'
        elif self.seq_missing and gates['main_checker'] == 'PASS':
            gates['main_checker'] = 'UNRESOLVED'
        differences = {'MAIN_ONLY': [], 'CHECKER_ONLY': []}
        main, checker = self.stat_occurrences['MAIN'], self.stat_occurrences['CHECKER']
        for key in sorted(main.keys() | checker.keys(), key=str):
            a, b = main[key], checker[key]
            # Multiset subtraction preserves loop multiplicity, never dedup by PC/address.
            differences['MAIN_ONLY'].extend(a[len(b):])
            differences['CHECKER_ONLY'].extend(b[len(a):])
        if any(differences.values()) or any(self.stat_duplicates.values()):
            gates['main_checker'] = 'FAIL'
        for source, label in (('MAIN', 'boom_arch'), ('CHECKER', 'checker_sum')):
            if label in self.report:
                observed = [0]*6
                for (seq, kind, pc, addr, cache), records in self.stat_occurrences[source].items():
                    idx = 0 if kind == 'STORE' else 3
                    observed[idx] += len(records)
                    observed[idx + (1 if cache else 2)] += len(records)
                if observed != self.report[label]:
                    self.error('STAT_COUNTER_MISMATCH_' + source, 0, 0)
                    gates['main_checker'] = 'FAIL'
        if self.checker_identity_missing and gates['main_checker'] == 'PASS':
            gates['main_checker'] = 'UNRESOLVED'
        cache_busy_fields = ('s1_valid', 's2_valid', 'mshr_outstanding', 'replay_valid',
            'replay_busy', 'replay_result_q', 'completion_q', 's3_valid', 'store_done_valid',
            'wb_valid', 'probe_valid', 'refill_valid', 'install_active', 'completion_pending',
            'killed_store', 'slot_reserved', 'cross_package_pending', 'pending_response',
            'response_valid', 'mem_finish', 'mem_grant', 'mem_acquire')
        lsu_busy_fields = ('stq_inflight', 'stq_done', 'hella_pending', 'force_order')
        blockers = {}
        if any(self.errors[k] for k in ('EXIT_STQ_SNAPSHOT_MISMATCH', 'DUP_EXIT_STQ', 'DUP_EXIT_DRAIN')):
            blockers['snapshot_inconsistent'] = 1
        complete_snapshot = snapshot_ready
        for source, names in (('DCACHE', cache_busy_fields), ('LSU', lsu_busy_fields)):
            f = self.exit_drain.get(source, {})
            complete_snapshot &= all(name in f for name in names)
            for name in names:
                if f.get(name):
                    blockers[source + '.' + name] = f[name]
        complete_snapshot &= 'fence_ready' in self.exit_drain.get('DCACHE', {})
        if self.exit_drain.get('DCACHE', {}).get('fence_ready') != 1:
            blockers['DCACHE.not_fence_ready'] = 1
        if unclassified_stq:
            blockers['LSU.unclassified_committed_stq'] = len(unclassified_stq)
        unfinished_cache = [item for item in outstanding if
                            not is_exit_tail(item) or item.get('exit_state') != 'committed_unissued']
        real_outstanding = unfinished_cache
        for name in ('ldq_pending', 'request_valid'):
            if self.exit_drain.get('LSU', {}).get(name):
                blockers['LSU.' + name] = self.exit_drain['LSU'][name]
        # Unissued exit-loop ROB commits are visible software obligations, not
        # accepted L1 operations. They are exempt only while the exact STQ
        # owner remains visible; all actual cache state is still checked.
        exit_real = int(bool(blockers or unfinished_cache)) if complete_snapshot else None
        gates['exit_outstanding'] = ('UNRESOLVED' if not complete_snapshot else
                                     'FAIL' if exit_real else 'PASS')
        if outstanding and not complete_snapshot and gates['lost_effect'] == 'PASS':
            gates['lost_effect'] = 'UNRESOLVED'
        gates['replay'] = ('FAIL' if self.errors['REPLAY_CLOSURE'] else 'PASS' if
                           self.events['REPLAY_GRANT'] else 'UNRESOLVED')
        gates['software_report'] = ('FAIL' if self.software_failures else
                                    'PASS' if self.software_end == 'PASS' else 'UNRESOLVED')
        status = 'FAIL' if 'FAIL' in gates.values() or self.errors else 'UNRESOLVED' if 'UNRESOLVED' in gates.values() else 'PASS'
        return dict(status=status, gates=gates, events=dict(self.events), errors=dict(self.errors), error_samples=self.samples,
                    terminal_exempt=dict(terminal_exempt), outstanding=outstanding,
                    exit_tail=exit_tail, real_outstanding=real_outstanding,
                    snapshots=self.snapshots, sim_exit=self.sim_exit, verified=self.verified,
                    exit_drain=self.exit_drain, exit_stq=list(self.exit_stq.values()),
                    exit_real_outstanding=exit_real, exit_blockers=blockers,
                    race_coverage=dict(self.race_coverage), race_violations=race_errors,
                    accounting_sets=dict(differences, DUP_IN_MAIN=self.stat_duplicates['MAIN'],
                        DUP_IN_CHECKER=self.stat_duplicates['CHECKER']),
                    checker_duplicate_identity=('UNAVAILABLE_IN_TRACE' if self.checker_identity_missing else 'AVAILABLE'),
                    seq_delta=[dict(seq=k[0], kind=k[1], cacheable=k[2], delta=v)
                               for k,v in seq_delta.items() if v],
                    reported_counters=self.report, reported_diff=diffs,
                    full_trace_pc_delta=[dict(kind=k[0], pc=hex(k[1]), cacheable=k[2], delta=v)
                        for k,v in sorted(pc_delta.items(), key=lambda kv: (-abs(kv[1]), kv[0])) if v],
                    amo_coverage=[dict(cmd=k[0], size=k[1], lane=k[2], count=v) for k,v in self.amo_coverage.items()],
                    architectural_errors=self.arch_errors,
                    software_failures=self.software_failures, software_end=self.software_end)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('trace')
    parser.add_argument('--json', help='write detailed offline results')
    parser.add_argument('--workload', help='immutable ELF/symbol identity manifest')
    args = parser.parse_args()
    workload = json.load(open(args.workload)) if args.workload else None
    board, digest = Scoreboard(workload), hashlib.sha256()
    stream = sys.stdin.buffer if args.trace == '-' else open(args.trace, 'rb')
    try:
        for line, raw in enumerate(stream, 1):
            digest.update(raw)
            board.consume(raw, line)
    finally:
        if args.trace != '-':
            stream.close()
    result = board.finish()
    result['trace_sha256'] = digest.hexdigest()
    if args.json:
        with open(args.json, 'w') as output:
            json.dump(result, output, indent=2)
            output.write('\n')
    print('TRACE_SHA256='+result['trace_sha256'])
    for k,v in sorted(board.events.items()):
        print('TRACE_%s=%d' % (k,v))
    for k,v in result['gates'].items():
        print('%s=%s' % (k.upper(),v))
    for k,v in result['errors'].items():
        print('%s=%d' % (k,v))
    for kind, index in (('STORE', 0), ('LOAD', 3)):
        for label, row in (('MAIN', 'boom_arch'), ('CHECKER', 'checker_sum')):
            print('%s_%s_COUNT=%s' % (label, kind, result['reported_counters'].get(row, ['UNRESOLVED']*6)[index]))
    if result['reported_diff'] is not None:
        main_count = sum(result['reported_counters']['boom_arch'][i] for i in (0, 3))
        checker_count = sum(result['reported_counters']['checker_sum'][i] for i in (0, 3))
        print('MAIN_COUNT=%d\nCHECKER_COUNT=%d\nMAIN_CHECKER_DIFF=%d' % (main_count, checker_count, main_count-checker_count))
        print('MAIN_CHECKER_STORE_DIFF=%d\nMAIN_CHECKER_LOAD_DIFF=%d' % (result['reported_diff'][0], result['reported_diff'][3]))
    else:
        print('MAIN_COUNT=UNRESOLVED\nCHECKER_COUNT=UNRESOLVED\nMAIN_CHECKER_DIFF=UNRESOLVED')
    metrics = dict(ARCH_ERROR=len(result['architectural_errors']) + int(result['verified'] == 0),
        AMO_LOW_LANE_SEEN=int(any(f['size'] == 2 and f['lane'] == 0 for f in result['amo_coverage'])),
        AMO_HIGH_LANE_SEEN=int(any(f['size'] == 2 and f['lane'] == 4 for f in result['amo_coverage'])),
        AMO_ERROR=sum(board.errors[k] for k in ('AMO_SEMANTICS','AMO_EFFECT','AMO_RETURN')),
        DUP_EFFECT=board.errors['DUP_EFFECT'], LOST_EFFECT=('UNRESOLVED' if result['gates']['lost_effect'] == 'UNRESOLVED' else sum(board.errors[k] for k in
            ('EFFECT_WITHOUT_TERMINAL', 'TERMINAL_WITHOUT_EFFECT', 'LOST_ARCH_STORE', 'EXIT_STQ_WITHOUT_ARCH'))),
        EFFECT_WITHOUT_TERMINAL=board.errors['EFFECT_WITHOUT_TERMINAL'],
        DUP_TERMINAL=board.errors['DUP_TERMINAL'],
        TERMINAL_WITHOUT_STQ_RELEASE=board.errors['TERMINAL_WITHOUT_RELEASE'],
        DUP_STQ_RELEASE=board.errors['DUP_RELEASE'], REPLAY_UNCLOSED=board.errors['REPLAY_CLOSURE'],
        CLEAR_RACE_VIOLATION=result['race_violations'],
        EXIT_REAL_OUTSTANDING=result['exit_real_outstanding'] if result['exit_real_outstanding'] is not None else 'UNRESOLVED',
        EXIT_LOOP_PENDING=len(result['exit_tail']))
    for k, v in metrics.items():
        print('%s=%s' % (k, v))
    for k,v in result['race_coverage'].items():
        print('CLEAR_COVERAGE_%s=%d' % (k.upper(),v))
    for k, v in result['accounting_sets'].items():
        print('%s=%d' % (k, len(v)))
    print('CHECKER_DUPLICATE_IDENTITY=' + result['checker_duplicate_identity'])
    print('COMMITTED_OR_GRANTED_WITHOUT_TERMINAL=%d' % len(result['outstanding']))
    print('STAGE1_TRACE='+result['status'])
    return {'PASS':0, 'FAIL':1, 'UNRESOLVED':2}[result['status']]


if __name__ == '__main__':
    sys.exit(main())
