"""Fail-closed campaign stop gate for the user-approved functional branch.

This never starts a build or FPGA operation. Control-component simulations and
SVB invalidation tests cannot satisfy the full architectural recovery gate.
"""
from pathlib import Path
from opt4_unattended_common import D, U, read, sha

def valid_recovery_record(record, performance_identity):
    identity = record.get('identity', {})
    recovery = record.get('architectural_recovery', {})
    if not (record.get('valid') and record.get('fpga_execution') and
            record.get('test_kind') == 'architectural_rollback_restart' and
            identity.get('board_bdf') == '0000:21:00.0' and
            identity.get('board_serial') == '21770433G02LA'):
        return False
    for key in ['hardware_commit', 'hardware_profile', 'derived_build_receipt_sha256']:
        if not identity.get(key) or identity.get(key) != performance_identity.get(key):
            return False
    if not (recovery.get('fault_source') == 'real_checker_compare_operand' and
            recovery.get('output_correct') is True and
            recovery.get('unfinished_checker_tasks') == 0 and
            all(recovery.get('restored_state_compared', {}).get(key) is True
                for key in ['integer', 'floating', 'pc', 'csr', 'memory'])):
        return False
    events = recovery.get('events', [])
    if len(events) != 8 or [row.get('kind') for row in events] != list(range(8)):
        return False
    try:
        checkpoint = int(recovery['checkpoint_sequence'])
        failure = int(recovery['failed_sequence'])
        generation = int(recovery['recovery_generation'])
        pc = int(recovery['restart_pc'])
        if not (0 <= checkpoint < failure < 2**32 and 0 < generation < 2**32):
            return False
        ticks = [int(row['target_cycle']) for row in events]
        serials = [int(row['record_sequence']) for row in events]
        if not (all(0 <= value < 2**64 for value in ticks + serials) and
                all(a <= b for a, b in zip(ticks, ticks[1:])) and
                all(a < b for a, b in zip(serials, serials[1:]))):
            return False
        for row in events:
            if not (int(row['checkpoint_sequence']) == checkpoint and
                    int(row['failed_sequence']) == failure and
                    int(row['recovery_generation']) == generation):
                return False
        return int(events[6]['retired_pc']) == pc
    except (KeyError, TypeError, ValueError):
        return False

def complete(performance_identity):
    """Require atomic real collector output, exact hardware, and raw witnesses."""
    index = read(U/'first-valid-architectural-recovery.json')
    if not index:
        return None
    try:
        path = Path(index['result']).resolve()
        if not path.is_relative_to(D/'runs') or path.name != 'result.json':
            return None
        record = read(path)
        completion = read(path.parent/'complete.json')
        if not (sha(path) == index['result_sha256'] == completion['result_sha256'] and
                record['identity_sha256'] == completion['identity_sha256']):
            return None
        from hashlib import sha256
        import json
        if sha256(json.dumps(record['identity'], sort_keys=True).encode()).hexdigest() != record['identity_sha256']:
            return None
        if not valid_recovery_record(record, performance_identity):
            return None
        witness = Path(index['witness']).resolve()
        if not (witness.is_relative_to(path.parent) and
                sha(witness) == index['witness_sha256']):
            return None
        # The collector's immutable witness extracts actual target events from
        # the UART/event stream. Its exact input log is retained in this run.
        raw = read(witness)
        log = Path(raw['raw_event_log']).resolve()
        if not (log.is_relative_to(path.parent) and sha(log) == raw['raw_event_log_sha256'] and
                raw['events'] == record['architectural_recovery']['events'] and
                raw['source'] == 'actual_fpga_target_events'):
            return None
        return dict(result=str(path), result_sha256=sha(path), witness=str(witness),
                    witness_sha256=sha(witness))
    except (OSError, KeyError, TypeError, ValueError):
        return None
