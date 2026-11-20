#!/usr/bin/python3
"""Conditional checkpoint-only r4 recovery; all original physical gates remain."""
import json
import shutil
from pathlib import Path
import prepare as p


def main():
    p.verify()
    p.admit_failed_r3()
    m = p.module('original_r2_physical', p.R2 / 'physical.py')
    m.O = p.OUTPUT
    m.S = p.D / 'Opt4-mcrams-shell-ipcollateral-r4b-state.json'
    original_stage, original_update = m.stage, m.update
    previous_state_hash = p.sha(p.D / 'Opt4-mcrams-shell-physical-r2-state.json')

    def stage(name, body, outputs):
        if name in ['stub', 'wrapper_only']:
            # Reuse successful exact r3 boundaries. No synthesis is executed.
            old = p.read(p.PREVIOUS / (name + '-receipt.json'))
            assert old['returncode'] == 0
            for path, digest in old['outputs'].items():
                assert p.sha(path) == digest
                dest = m.O / Path(path).name
                assert not dest.exists()
                shutil.copy2(path, dest)
                assert p.sha(dest) == digest
            assert all(Path(path).is_file() for path in outputs)
            receipt = dict(old, reused_previous_receipt=str(p.PREVIOUS / (name + '-receipt.json')),
                reused_previous_receipt_sha256=p.sha(p.PREVIOUS / (name + '-receipt.json')),
                no_synthesis_executed=True, outputs={str(path): p.sha(path) for path in outputs})
            m.save(m.O / (name + '-receipt.json'), receipt)
            return
        if name == 'top_opt':
            body = p.render(m.O / 'wrapper-host-linked.dcp', m.O)
        elif name == 'timing_drc_bitstream':
            assert body.count('scale {1 2}') == 1
            assert body.count('get_clocks -quiet host_clock') == 1
            body = body.replace('scale {1 2}', 'scale {1 1}').replace(
                'get_clocks -quiet host_clock', 'get_clocks -quiet ' + p.NATIVE_CLOCK)
            needle = 'set host [get_clocks -quiet ' + p.NATIVE_CLOCK + ']'
            body = body.replace(needle, p.NATIVE_GATE + p.MASTER_GATE + '\n' + needle)
        return original_stage(name, body, outputs)

    def update(**values):
        return original_update(physical_controller_revision='r4b-unchanged-BD-IP-native-clock-binding',
            physical_controller_source=str(p.C / 'physical.py'),
            physical_controller_sha256=p.sha(p.C / 'physical.py'),
            collateral_manifest_sha256=p.sha(p.AUDIT / 'collateral-manifest.json'),
            original_generated_constraints_changed=False, physical_clock_alias_created=False,
            original_timing_route_DRC_gates_retained=True, **values)

    m.stage, m.update = stage, update
    try:
        m.main()
        assert m.ST['status'] in ['NOT_FIT_COMPLETE_TOP_NO_PLACE',
            'PHYSICAL_BITSTREAM_TIMING_DRC_PASSED_REQUIRES_COMPOSITE_HOST_RUNTIME_CERTIFICATION']
        # The existing independent runtime consumer follows the canonical
        # terminal result, with its original certificate/software/21-only gates.
        canonical = p.D / 'Opt4-mcrams-shell-physical-r2-state.json'
        assert p.sha(canonical) == previous_state_hash, 'canonical predecessor changed'
        p.admit_failed_r3_identity_only()  # recheck exact exited identity/cgroup
        m.save(canonical, m.ST)
    except Exception as exc:
        if m.ST:
            m.update(status='FAILED_WITH_EVIDENCE', error=repr(exc), ended_utc=m.now())
            m.save(m.O / 'failure.json', m.ST)
        raise


if __name__ == '__main__':
    main()
