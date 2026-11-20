#!/usr/bin/python3
"""Map only after the exact proof has completed and its processes exited."""
from pathlib import Path
import importlib.util
import sys

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = W/'candidates/address-sequence-replicated-proof-r2-20261111'
sys.path.insert(0,str(C))
import topology

TARGET = W/'candidates/address-sequence-replicated-r1-20261111/controller.py'
spec = importlib.util.spec_from_file_location('immutable_sequence_map_controller',TARGET)
module = importlib.util.module_from_spec(spec); spec.loader.exec_module(module)
receipt = module.read(D/'build-logs/Opt4-fit-address-sequence-replicated-proof-r2-20261111/result.json')
assert receipt['status'] == 'PASS_RECOVERED_LOCAL_PROOF_TOPOLOGY_AND_ACTUAL_SIZE_NOT_FULL_MODULE_EQUIVALENCE'
assert module.sha(receipt['proof_receipt']) == receipt['proof_receipt_sha256']
proof = module.read(receipt['new_state'])
assert proof['hardware_commit'] == receipt['hardware_commit'] == '27f7e7d6d043d2c5e3dff7551fdb0487e5775580'
assert proof['source_id'] == receipt['source_id']
assert not module.live(proof) and not module.live(proof.get('child',{})), 'adopt proof until it exits'
assert not any(module.live(stage) for stage in proof.get('stages',{}).values())
module.S = D/'Opt4-fit-address-sequence-replicated-map-r1-state.json'
sys.argv = [str(TARGET)]
try:
    module.main()
except Exception as exc:
    state = module.read(module.S)
    if state.get('pid') == module.os.getpid():
        state.update(status='FAILED_WITH_EVIDENCE',error=repr(exc),ended_utc=module.now())
        module.save(module.S,state)
    raise
