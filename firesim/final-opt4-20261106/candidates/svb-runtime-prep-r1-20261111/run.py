#!/usr/bin/python3
"""Actual f2 GoldenGate ABI and 13-program software preparation; no FPGA IO."""
from pathlib import Path
import importlib.util
import json
import sys

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
sys.path.insert(0, str(W / 'scripts'))
from opt4_unattended_common import save, sha, now
import prepare_opt4_candidate_runtime as runtime

commit = 'f2d2ca3ea0b12c918f2ccd2d1131be2709960470'
source = 'f678ac806ea4b0f801596b26ec8bf9ef914a3161b39f92564ac25452abd8eafc'
audit_path = D / 'build-logs/Opt4-fit-svb-system-r2-20261111/driver-reuse-seven-file-audit.json'
audit = json.loads(audit_path.read_text())
assert audit['hardware_commit'] == commit and audit['source_id'] == source
assert audit['status'] == 'ALL_7_BYTE_EQUAL_REUSE_ELIGIBLE'
assert len(audit['rows']) == 7 and all(row['byte_equal'] for row in audit['rows'])
desc = runtime.descriptor(W / 'runtime-candidates/f2d2ca3e.json')
out, bundle = runtime.generate(desc)
runtime.compatibility(desc, out)
# Use the separately generated, hash-pinned CPU-only preparation entry. The
# runtime start request still waits for real CAD/timing/DRC/bitstream receipts.
sys.path.insert(0, str(bundle))
spec = importlib.util.spec_from_file_location('f2_cpu_software_preparation', bundle / 'prepare_opt4_fit_runtime.py')
module = importlib.util.module_from_spec(spec)
spec.loader.exec_module(module)
module.prepare()
suite_path = out / 'software-suite.json'
suite = json.loads(suite_path.read_text())
# The template's exact software suite is independently version bound; retain
# its full evidence rather than inferring readiness from the filename.
assert suite['hardware_commit'] == commit and suite['source_id'] == source
assert suite['program_count'] == 13
record = dict(schema='ec-opt4-candidate-software-preparation/1',
              status='PREPARED_REAL_ABI_AND_PAIRED_SOFTWARE_NOT_FPGA_VALIDATED',
              hardware_commit=commit, source_id=source, utc=now(),
              abi_audit=str(audit_path), abi_audit_sha256=sha(audit_path),
              software_suite=str(suite_path), software_suite_sha256=sha(suite_path),
              driver_receipt=str(out / 'driver-receipt.json'),
              driver_receipt_sha256=sha(out / 'driver-receipt.json'),
              fpga_access=False, formal_admission=False)
save(D / 'Opt4-fit-svb-software-prep-r1-state.json', record)
save(Path(__file__).resolve().parent / 'result.json', record)
