#!/usr/bin/python3
"""Run the original immutable runtime with only its task ordering adapted."""
import importlib.util
import json
from pathlib import Path
import sys

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
R = W / 'runtime/Opt4-fit-mcrams-owner-r1'
sys.path.insert(0, str(C))
sys.path.insert(1, str(R / 'scripts'))
sys.path.insert(2, str(W / 'scripts'))
from schedule import PRIORITY, adapt


def load_original():
    spec = importlib.util.spec_from_file_location(
        'ec_mcrams_original_runtime', R / 'scripts/continue_opt4_fit.py')
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def main():
    from follower import verify
    verify()
    module = load_original()
    assert module.BDF == '0000:21:00.0'
    assert module.COMMIT == '3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c'
    module.next_task = adapt(module.next_task)
    if '--offline' in sys.argv:
        suite = module.read(module.SUITE)
        from schedule import ordered_suite
        print(json.dumps(dict(status='OFFLINE_ORIGINAL_RUNTIME_IMPORTED_NO_FPGA_IO',
            board_bdf=module.BDF,
            order=[r['program'] for r in ordered_suite(suite)['programs']],
            original_suite_sha256=module.sha(module.SUITE))))
        return
    policy = json.loads((D / 'FPGA_SESSION_POLICY.json').read_text())
    assert policy['priority_programs'] == list(PRIORITY)
    assert policy['board_allowlist'] == ['0000:21:00.0']
    # main retains its original suite hash, certification, deployment, reset,
    # correctness, checker/drain and atomic completion checks.
    module.main()


if __name__ == '__main__':
    main()
