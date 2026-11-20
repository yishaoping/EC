#!/usr/bin/python3
"""Prepare an independently versioned top-opt input; never execute it."""
import hashlib
import importlib.util
import json
from pathlib import Path

C = Path(__file__).resolve().parent
R4B = C.parent / 'mcrams-shell-ipcollateral-r4b-20261112'


def render(wrapper, output):
    pins = json.loads((C / 'inputs.json').read_text())
    for path, expected in pins['files'].items():
        assert hashlib.sha256(Path(path).read_bytes()).hexdigest() == expected, path
    spec = importlib.util.spec_from_file_location('unchanged_r4b_renderer', R4B / 'prepare.py')
    previous = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(previous)
    body = previous.render(Path(wrapper), Path(output))
    needle = f'check_timing -verbose -file {{{output}/top-preplace-check-timing.rpt}}'
    assert body.count(needle) == 1
    addition = (f'source {{{C / "verify.tcl"}}}\n'
                f'ec_target_contract::verify {{{output}/target-exception-contract}}\n')
    body = body.replace(needle, addition + needle)
    assert body.replace(addition, '') == previous.render(Path(wrapper), Path(output))
    return body
