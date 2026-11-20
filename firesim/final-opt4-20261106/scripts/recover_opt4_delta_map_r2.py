#!/usr/bin/python3
"""Versioned entry point for the corrected delta map recovery checks."""
from pathlib import Path
import datetime as dt
import importlib.util

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
U = D / 'unattended-opt4'
BASE = D / 'build-logs/Opt4-fit-address-delta-r3-56711a00-20261111'
IMPLEMENTATION = W / 'scripts/recover_opt4_delta_map_r1.py'
spec = importlib.util.spec_from_file_location('opt4_delta_map_recovery_impl', IMPLEMENTATION)
impl = importlib.util.module_from_spec(spec)
spec.loader.exec_module(impl)

impl.JOB = U / 'jobs/address-delta-r3-56711a00'
impl.O = BASE / 'map-recovery-r2'
impl.INPUTS = BASE / 'map-recovery-r2-input-hashes.json'
impl.STATE = D / 'Opt4-fit-address-delta-map-recovery-r2-state.json'

try:
    impl.main()
except Exception as error:
    try:
        state = impl.read(impl.STATE)
        if state:
            state.update(status='FAILED_WITH_EVIDENCE', error=repr(error),
                         ended_utc=dt.datetime.now(dt.timezone.utc).isoformat())
            impl.save(impl.STATE, state)
    except (FileNotFoundError, ValueError):
        pass
    raise
