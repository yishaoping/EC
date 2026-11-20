"""Additional exact-profile admission. Importing this module performs no IO."""
from pathlib import Path
import hashlib
import json

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
R = W/'runtime/Opt4-performance-only-6fada307-bound-r1'
PHYSICAL = D/'performance-only-20261113/physical-runtime-admission-r1.json'
HW = '6fada307bb77be90b39720d3f95404fece0e431b'
SID = '461e1b98833d1a78a8bd27c0eed2d3353c648dfbf29ae5588db31bbce0f77369'
RTL = 'd2cfb70488d2826cbd997c47954b2be0fc17a5342a430235481b07539a32cf94'
PROFILE = 'EC Performance-Only: data preservation + cache isolation'
READY = 'PHYSICAL_BITSTREAM_TIMING_DRC_PASSED_REQUIRES_COMPOSITE_HOST_RUNTIME_CERTIFICATION'


def read(p):
    return json.loads(Path(p).read_text())


def sha(p):
    h = hashlib.sha256()
    with Path(p).open('rb') as f:
        for b in iter(lambda: f.read(2**20), b''):
            h.update(b)
    return h.hexdigest()


def pins():
    bundle = read(R/'bundle.json')
    for p, h in {**bundle['scripts'], **bundle['immutable_inputs']}.items():
        assert sha(p) == h, p
    return bundle


def identity(row):
    assert row['hardware_commit'] == HW and row['source_id'] == SID
    assert row['host_rtl_sha256'] == RTL and row['profile'] == PROFILE
    assert row['board_bdf'] == '0000:21:00.0' and row['board_serial'] == '21770433G02LA'
    assert row['full_PALIMPSEST'] is False


def physical():
    """Require an actual separately verified final-checkpoint admission receipt.

    R6's inner certified_bitstream flag alone is insufficient. The supervisor
    supplies the exact-profile receipt after actual all-STA/DRC checks; this
    module does not launch another CAD engine or create that evidence.
    """
    row = read(PHYSICAL)
    identity(row)
    assert row['status'] == READY and row['shell_included'] is True
    assert row['blackboxes'] == 0 and not row['fpga_access']
    assert row['bundle_sha256'] == sha(R/'bundle.json')
    outputs = {}
    assert set(row['actual_stage_receipts']) == {
        'dut_synth', 'top_synth', 'implementation', 'timing_bitstream', 'final_checkpoint_checks'}
    for stage, ref in row['actual_stage_receipts'].items():
        assert sha(ref['path']) == ref['sha256']
        receipt = read(ref['path'])
        assert receipt['hardware_commit'] == HW and receipt['source_id'] == SID
        assert receipt['returncode'] == 0 and receipt['outputs']
        assert all(sha(p) == h for p, h in receipt['outputs'].items())
        outputs.update(receipt['outputs'])
    for name in ['setup', 'hold', 'pulse_width', 'bus_skew', 'clock_coverage',
                 'unconstrained_endpoints', 'route_complete', 'DRC']:
        check = row['checks'][name]
        assert check['passed'] is True and check['scope'] == 'actual_complete_shell_final_checkpoint'
        assert check['evidence'] and all(sha(p) == h for p, h in check['evidence'].items())
        assert all(outputs.get(p) == h for p, h in check['evidence'].items())
    assert sha(row['bitstream']) == row['bitstream_sha256']
    assert outputs.get(row['bitstream']) == row['bitstream_sha256']
    return row


def certify():
    """Certification stays with the existing supervisor, after real evidence."""
    pins()
    if not PHYSICAL.exists():
        return dict(status='WAITING_EXACT_R6_FULL_SHELL_AND_ALL_STA_DRC_ADMISSION',
                    certified_bitstream=False, fpga_access=False)
    physical()
    # The owner must create a certificate binding the physical admission itself.
    # Never turn a legacy inner CAD flag into a runtime certificate.
    cert = R/'certified-build.json'
    if not cert.exists():
        return dict(status='PHYSICAL_CHECKED_EXISTING_OWNER_MUST_BIND_CERTIFICATE',
                    certified_bitstream=False, fpga_access=False)
    row = read(cert)
    assert row['physical_admission_sha256'] == sha(PHYSICAL)
    return row


def integrated(cert):
    row = read(R/'integrated-runtime-validation.json')
    identity(row)
    assert row['bitstream_sha256'] == cert['durable_bitstream_sha256']
    assert row['certificate_sha256'] == sha(R/'certified-build.json')
    assert row['bundle_sha256'] == sha(R/'bundle.json')
    for name in ['checker_execution', 'LSL_SVB_preservation', 'cache_isolation', 'safe_drain']:
        check = row['checks'][name]
        assert check['scope'] == 'integrated_fpga' and check['passed'] is True
        assert check['evidence'] and all(sha(p) == h for p, h in check['evidence'].items())
    assert row['diagnostic_pending_used_as_drain'] is False


def install(ns):
    old_artifact, old_sample, old_identity = ns['artifact'], ns['sample_binding'], ns['add_identity']

    def artifact(receipt):
        pins()
        physical()
        cert = old_artifact(receipt)
        assert cert['physical_admission_sha256'] == sha(PHYSICAL)
        assert cert['runtime_bundle_sha256'] == sha(R/'bundle.json')
        return cert

    def sample_binding(receipt, driver_path, fwpath, apps_path, rootfs_path, program):
        cert = old_sample(receipt, driver_path, fwpath, apps_path, rootfs_path, program)
        # Smoke and finite validation remain available after physical admission;
        # measured simmedium samples require integrated checker/storage evidence.
        return cert

    def add_identity(ident, receipt):
        cert = artifact(receipt)
        if ident.get('formal'):
            integrated(cert)
        ident = old_identity(ident, receipt)
        ident.update(result_scope=PROFILE, full_PALIMPSEST=False,
                     diagnostic_metrics_supported=False,
                     unsupported_metrics=read(R/'bundle.json')['unsupported_metrics'])
        return ident

    ns.update(artifact=artifact, sample_binding=sample_binding, add_identity=add_identity)
