#!/usr/bin/python3
"""Recover proof after controller exit, reusing only hash-validated stages."""
from pathlib import Path
import importlib.util
import sys

C = Path(__file__).resolve().parent
W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
sys.path.insert(0,str(C))
import topology

TARGET = W/'candidates/address-sequence-replicated-r1-20261111/controller.py'
spec = importlib.util.spec_from_file_location('immutable_sequence_r1_controller',TARGET)
module = importlib.util.module_from_spec(spec)
spec.loader.exec_module(module)
D = module.D
R = D/'build-logs/Opt4-fit-address-sequence-replicated-proof-r2-20261111'
R.mkdir(exist_ok=True)
failed = module.read(module.S)
assert failed.get('status') == 'FAILED_WITH_EVIDENCE' and failed.get('error') == "KeyError('reset')"
assert not module.live(failed) and not module.live(failed.get('child',{}))
assert not any(module.live(stage) for stage in failed.get('stages',{}).values())
module.exact_text(R/'original-failure-state.json',module.S.read_text())
module.S = D/'Opt4-fit-address-sequence-replicated-proof-r2-state.json'
sys.argv = [str(TARGET),'--proof-only']
module.main()
module.save(R/'result.json',dict(status='PASS_RECOVERED_LOCAL_PROOF_TOPOLOGY_AND_ACTUAL_SIZE_NOT_FULL_MODULE_EQUIVALENCE',
    hardware_commit=failed['hardware_commit'],source_id=failed['source_id'],
    proof_receipt=str(module.O/'proof-only.json'),proof_receipt_sha256=module.sha(module.O/'proof-only.json'),
    original_failure=str(R/'original-failure-state.json'),new_state=str(module.S),
    recovery_scope='Only topology audit accounts for an eliminated unused leaf reset port; no RTL change. All accepted stages rehashed before reuse.',
    fpga_access=False,full_dut_formal=False))
