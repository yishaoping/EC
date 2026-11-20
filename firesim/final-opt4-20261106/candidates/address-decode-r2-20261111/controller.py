#!/usr/bin/python3
"""Run the tested address-decode proof/map stages against the R2 binding."""
from pathlib import Path
import importlib.util

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path(__file__).resolve().parent
shared = W/'candidates/address-decode-r1-20261111/controller.py'
spec = importlib.util.spec_from_file_location('opt4_address_decode_shared_runner', shared)
runner = importlib.util.module_from_spec(spec)
spec.loader.exec_module(runner)
runner.C = C
runner.O = D/'build-logs/Opt4-fit-address-decode-r2-20261111'
runner.S = D/'Opt4-fit-address-decode-r2-state.json'
runner.main()
