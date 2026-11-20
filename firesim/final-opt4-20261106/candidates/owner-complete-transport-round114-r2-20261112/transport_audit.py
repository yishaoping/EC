"""Complete stdout comparison; retain exact bytes in three explicit transports."""
import hashlib
import io
import re

# Host efficiency is expected to differ between Plain and MCRams. These six
# driver/Verilator records are retained and validated, but compared as metrics.
NUMBER = rb'[0-9]+(?:\.[0-9]+)?'
HOST_RECORDS = {
    'wallclock': rb'Wallclock Time Elapsed: (' + NUMBER + rb') s\n',
    'host_frequency': rb'Host Frequency: (' + NUMBER + rb') (?:KHz|MHz)\n',
    'target_frequency': rb'Effective Target Frequency: (' + NUMBER + rb') (?:KHz|MHz)\n',
    'fmr': rb'FMR: (' + NUMBER + rb')\n',
    'verilator_wallclock': rb'- Verilator: end at ' + NUMBER + rb'[a-z]+; walltime (' + NUMBER + rb') s; speed ' + NUMBER + rb' [a-z]+/s\n',
    'verilator_cpu': rb'- Verilator: cpu (' + NUMBER + rb') s on [1-9][0-9]* threads; allocated [0-9]+ MB\n',
}


def partition(stream, uart_rows, command_line):
    hashes = {k: hashlib.sha256() for k in ('raw', 'uart', 'host', 'other')}
    stats = dict(raw_bytes=0, raw_lines=0, uart_bytes=0, host_bytes=0,
        other_bytes=0, other_lines=0, partial_bytes=0, uart_rows=[], host_rows=[],
        host_records={}, command_lines=0)

    def lines():
        for line in stream:
            offset = stats['raw_bytes']
            hashes['raw'].update(line)
            stats['raw_bytes'] += len(line)
            stats['raw_lines'] += 1
            if not line.endswith(b'\n'):
                stats['partial_bytes'] += len(line)
                assert not stream.read(1), 'partial row must be final'
                continue
            if line in uart_rows:
                channel = 'uart'
                stats['uart_rows'].append(line.decode())
            else:
                host = next((name for name, pat in HOST_RECORDS.items()
                    if re.fullmatch(pat, line)), None)
                if host:
                    channel = 'host'
                    stats['host_records'].setdefault(host, []).append(line.decode())
                    stats['host_rows'].append(line.decode())
                elif line == command_line:
                    channel = 'host'
                    stats['command_lines'] += 1
                    stats['host_rows'].append(line.decode())
                else:
                    channel = 'other'
                    stats['other_lines'] += 1
            hashes[channel].update(line)
            stats[channel + '_bytes'] += len(line)
            if channel == 'other':
                yield offset, line

    return lines(), stats, hashes


def compare(mc, plain, uart_rows, mc_command, plain_command, target_cycles):
    """Require complete equality; never accept an unfinished prefix as full."""
    left, ls, lh = partition(mc, uart_rows, mc_command)
    right, rs, rh = partition(plain, uart_rows, plain_command)
    first, count, pass_rows, cycle_rows = None, 0, [0, 0], [0, 0]
    exhausted = object()
    while True:
        a, b = next(left, exhausted), next(right, exhausted)
        if a is exhausted and b is exhausted:
            break
        count += 1
        if first is None and (a is exhausted or b is exhausted or a[1] != b[1]):
            first = dict(channel='all_other_lines', index=count,
                mc_offset=None if a is exhausted else a[0],
                plain_offset=None if b is exhausted else b[0],
                mc=None if a is exhausted else a[1][:1000].decode(errors='replace'),
                plain=None if b is exhausted else b[1][:1000].decode(errors='replace'))
        for i, row in enumerate((a, b)):
            if row is not exhausted:
                pass_rows[i] += row[1] == f'*** PASSED *** after {target_cycles} cycles\n'.encode()
                cycle_rows[i] += row[1] == f'Target Cycles Emulated: {target_cycles}\n'.encode()
    expected_uart = [line.decode() for line in uart_rows]
    uart_ok = ls['uart_rows'] == rs['uart_rows'] == expected_uart
    host_ok = True
    for stats in (ls, rs):
        host_ok &= stats['command_lines'] == 1
        host_ok &= set(stats['host_records']) == set(HOST_RECORDS)
        host_ok &= all(len(rows) == 1 for rows in stats['host_records'].values())
        assert stats['raw_bytes'] == sum(stats[k + '_bytes'] for k in ('uart', 'host', 'other')) + stats['partial_bytes']
    complete = pass_rows == cycle_rows == [1, 1] and ls['partial_bytes'] == rs['partial_bytes'] == 0
    counts = {}
    for label, stats, hashes in [('mc', ls, lh), ('plain', rs, rh)]:
        counts[label] = {**stats, **{k + '_sha256': h.hexdigest() for k, h in hashes.items()}}
    return dict(passed=first is None and uart_ok and host_ok and complete,
        all_other_complete_lines_equal=first is None, first_mismatch=first,
        uart_exact_and_ordered=uart_ok, host_record_shapes_and_counts_valid=bool(host_ok),
        successful_target_cycle_counts_valid=complete, compared_rows=count, counts=counts,
        normalized_target_bytes=0, dropped_bytes=0, prefix_accepted_as_complete=False,
        scope='Finite complete stdout within UART and all-other transports; host metrics retained separately. No full-state, scheduler liveness, or cross-transport drain-order equivalence.')


def mutation_checks(uart_rows):
    target = (b'STAGE1_TX S1 source=DCACHE cycle=0000000000000010 data=01\n',
              b'C1: cycle=0000000000000011 data=02\n')
    summary = (b'*** PASSED *** after 1759002 cycles\n'
        b'Target Cycles Emulated: 1759002\n')
    def metrics(wall, cmd):
        return (f'Wallclock Time Elapsed: {wall} s\n'.encode() +
            b'Host Frequency: 2.433 KHz\nEffective Target Frequency: 0.763 KHz\nFMR: 3.19\n' +
            b'- Verilator: end at 6ms; walltime 2305.484 s; speed 2.448 us/s\n' +
            b'- Verilator: cpu 2291.452 s on 1 threads; allocated 16560 MB\n' + cmd)
    pc, mc = b'+print-file=/plain/rtl-prints- \n', b'+print-file=/mc/rtl-prints- \n'
    reference = b''.join(uart_rows) + b''.join(target) + summary + metrics('2305.4', pc)
    candidate = uart_rows[0] + target[0] + b''.join(uart_rows[1:]) + target[1] + summary + metrics('19005.8', mc)
    def accepted(a, b=reference):
        return compare(io.BytesIO(a), io.BytesIO(b), uart_rows, mc, pc, 1759002)['passed']
    assert accepted(candidate), 'host drain-order/efficiency positive'
    bad = {
        'target_payload': candidate.replace(b'data=01', b'data=ff'),
        'target_cycle': candidate.replace(b'cycle=0000000000000010', b'cycle=0000000000000012'),
        'missing_target_line': candidate.replace(target[0], b''),
        'extra_target_line': candidate + target[0],
        'missing_uart': candidate.replace(uart_rows[-1], b''),
        'duplicate_uart': candidate + uart_rows[-1],
        'unknown_row': candidate + b'[UNKNOWN] event=1\n',
        'unmatched_command': candidate.replace(mc, b'+print-file=/unbound/rtl-prints- \n'),
        'missing_host_metric': candidate.replace(b'FMR: 3.19\n', b''),
        'malformed_host_metric': candidate.replace(b'FMR: 3.19\n', b'FMR: nan\n'),
        'missing_reference_tail': candidate.replace(target[-1], b''),
        'partial_tail': candidate + b'partial',
        'wrong_completion_cycles': candidate.replace(b'after 1759002 cycles', b'after 1759001 cycles'),
        'wrong_emulated_cycles': candidate.replace(b'Emulated: 1759002', b'Emulated: 1759001'),
    }
    rejected = {name: not accepted(data) for name, data in bad.items()}
    assert all(rejected.values()), rejected
    # Reversing which side has an extra tail must also fail.
    reverse_tail = not accepted(candidate, reference + target[0])
    assert reverse_tail
    return dict(status='PASS_COMPLETE_TRANSPORT_COMPARATOR_MUTATIONS', rejected=rejected,
        plain_extra_tail_rejected=reverse_tail, independent_host_drain_order_accepted=True,
        changed_host_efficiency_accepted=True)
