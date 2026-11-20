#!/usr/bin/env python3
"""Bind the original CLI's --no-progress option; keep all encode work in ROI."""
import copy
import datetime as dt
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
from board_batch import W, D, save, sha


def main():
    receipt = W/'software/x264-no-progress-apps-build.json'
    if not receipt.exists():
        original = W/'software/x264-apps-build.json'
        prior = json.loads(original.read_text())
        stamp = dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
        out = W/'software'/('apps-x264-no-progress-'+stamp)
        logs = D/'software'/out.name
        out.mkdir(); logs.mkdir()
        shutil.copytree(Path(prior['output_dir'])/'inputs', out/'inputs')
        state = copy.deepcopy(prior)
        state.update(status='VALIDATING', pid=os.getpid(), output_dir=str(out),
                     host_log_dir=str(logs), cases=[], commands=[],
                     software_profile='x264-original-encoder-staged-io-no-progress',
                     reused_apps_receipt=str(original), reused_apps_receipt_sha256=sha(original),
                     auxiliary_progress_policy='Original --no-progress CLI option in both reference and paired FPGA groups; no fake clock, no skipped encode or delayed-frame work')
        path = D/'software/x264-no-progress-preparation-state.json'
        def update(**kw):
            state.update(kw); save(path, state); save(logs/'state.json', state)
        def run(argv, cwd, log):
            state['commands'].append(dict(argv=list(map(str,argv)),cwd=str(cwd)))
            with log.open('wb') as f:
                child = subprocess.Popen(list(map(str,argv)),cwd=cwd,stdin=subprocess.DEVNULL,
                                         stdout=f,stderr=subprocess.STDOUT,start_new_session=True)
                update(child_pid=child.pid)
                try: rc=child.wait(timeout=7200)
                except subprocess.TimeoutExpired:
                    import signal
                    os.killpg(child.pid,signal.SIGTERM); child.wait(timeout=20); raise
            assert rc==0,(rc,str(log))
        try:
            diagnostic=Path(prior['output_dir'])/'x264-diagnostic'
            for old in prior['cases']:
                c=copy.deepcopy(old); size=c['input']; argv=['--no-progress',*c['argv']]
                update(input=size)
                ref=logs/('reference-'+size); diag=logs/('diagnostic-'+size)
                source=out/'inputs/x264'/size
                shutil.copytree(source,ref);shutil.copytree(source,diag)
                run(['/usr/bin/qemu-riscv64',prior['binaries']['x264']['reference_path'],*argv],ref,ref/'stdout.log')
                expected=sha(ref/'eledream.264')
                assert expected==c['validation']['files']['eledream.264'], 'progress option changed encoded output'
                run(['/usr/bin/qemu-riscv64','-strace',diagnostic,*argv],diag,diag/'trace.log')
                assert sha(diag/'eledream.264')==expected
                lines=(diag/'trace.log').read_text().splitlines()
                b=next(i for i,l in enumerate(lines) if l.endswith('EC_DIAGNOSTIC_ROI_BEGIN'))
                e=next(i for i,l in enumerate(lines) if l.endswith('EC_DIAGNOSTIC_ROI_END'))
                calls=[l for l in lines[b+1:e] if re.match(r'^\d+ [a-zA-Z_]\w*\(',l)]
                assert not calls,(size,calls)
                c.update(argv=argv,diagnostic_roi_syscalls=calls,diagnostic_trace=str(diag/'trace.log'),
                         reference_outputs={str(ref/'eledream.264'):expected},
                         auxiliary_progress_option='--no-progress; original supported flag, both groups')
                state['cases'].append(c);update()
            update(status='PREPARED_FPGA_NOT_RUN',c4_incompatible_reason=None,
                   reused_encoder_binary_sha256=prior['binaries']['x264']['sha256'],
                   ended_utc=dt.datetime.now(dt.timezone.utc).isoformat())
            save(logs/'result.json',state);save(out/'manifest.json',state);save(receipt,state)
        except Exception as exc:
            update(status='FAILED_WITH_EVIDENCE',error=repr(exc));raise
    subprocess.run(['python3',W/'scripts/prepare_profile_system.py','x264-no-progress'],check=True)


if __name__=='__main__': main()
