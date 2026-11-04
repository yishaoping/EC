#!/usr/bin/env python3
"""Build an isolated observation-only derivative of the frozen native model.

No Verilog or functional C++ expression is changed. Only the guard of nine
EC_OPT4 print statements is made independent of +verbose. Existing fatal
assertion/stop blocks remain intact. Reuse compiled objects for unchanged units.
"""
import datetime as dt
import difflib
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import time
from build_minimal import ROOT, ENV, sha

WORK = ROOT / 'firesim/dac2026/work/opt4-linux-v6'


def save(path, value):
    path.write_text(json.dumps(value, indent=2) + '\n')


def main():
    original_path = WORK / 'native-build.json'
    original = json.loads(original_path.read_text())
    assert original['returncode'] == 0
    for path, digest in original['outputs'].items():
        assert sha(path) == digest, path
    stamp = dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%S.%fZ')
    label = 'native-events-' + stamp
    directory = WORK / 'diagnostic36/builds' / label
    logdir = ROOT / 'Experiment/dac2026/build-logs/opt4-linux-v6' / label
    directory.mkdir(parents=True)
    logdir.mkdir(parents=True)
    print(logdir, flush=True)
    generated = Path(original['output_dir']) / 'generated'
    model = directory / 'model'
    subprocess.run(['cp', '-a', '--reflink=auto', str(generated / 'chipyard.TestHarness.DacLinuxC4'), str(model)], check=True)
    edits = []
    inventory = {}
    # Snapshot exactly the compiled model's source; no latest Scala lookup.
    for path in sorted(model.glob('*.cpp')):
        inventory[str(path.name)] = sha(path)
        text = path.read_text()
        changed = text
        for match in reversed(list(re.finditer(r'VL_FWRITEF\([^;]*?"EC_OPT4_', text))):
            guard = text.rfind('verbose&&done_reset', 0, match.start())
            assert guard >= 0
            between = text[guard + len('verbose&&done_reset'):match.start()]
            # This guard belongs directly to a print-only block.
            assert ';' not in between and between.count('{') == 1 and '}' not in between
            end = text.index(';', match.start()) + 1
            assert text[end:].lstrip().startswith('}')
            edits.append({'file':path.name, 'guard_offset':guard,
                          'event':re.search(r'"(EC_OPT4_\w+)', text[match.start():end])[1]})
            changed = changed[:guard] + 'done_reset' + changed[guard + len('verbose&&done_reset'):]
        if changed != text:
            # Invert just the recorded edits and prove byte identity.
            restored = changed
            for item in sorted([e for e in edits if e['file'] == path.name], key=lambda e:e['guard_offset']):
                i = item['guard_offset']
                assert restored[i:i+len('done_reset')] == 'done_reset'
                restored = restored[:i] + 'verbose&&done_reset' + restored[i+len('done_reset'):]
            assert restored == text
            path.write_text(changed)
            (logdir / (path.name + '.patch')).write_text(''.join(difflib.unified_diff(text.splitlines(True), changed.splitlines(True), fromfile=path.name, tofile=path.name)))
    assert len(edits) == 9, edits
    old_emulator = generated / 'gen-collateral/emulator.cc'
    emulator = directory / 'emulator.cc'
    text = old_emulator.read_text()
    anchor = '    trace_count++;\n  }\n  // for verilator'
    assert text.count(anchor) == 1
    replacement = '''    trace_count++;
#ifdef STAGE1_EXIT_PORTS
    if ((trace_count & 0xffffU) == 0) {
      fprintf(stderr, "EC_OPT4_SIM_PROGRESS cycle=%llx harness_cycle=%llx\\n",
              (unsigned long long)tile->io_stage1_cache_0,
              (unsigned long long)trace_count);
      fflush(stderr);
    }
#endif
  }
  // for verilator'''
    emulator.write_text(text.replace(anchor, replacement))
    (logdir / 'emulator.patch').write_text(''.join(difflib.unified_diff(text.splitlines(True), emulator.read_text().splitlines(True), fromfile=str(old_emulator), tofile=str(emulator))))
    simulator = directory / 'simulator-chipyard-DacLinuxC4-events'
    makefile = model / 'VTestHarness.mk'
    raw = makefile.read_bytes().replace(b'\0', b'')
    raw = raw.replace(original['simulator'].encode(), str(simulator).encode())
    raw = raw.replace(('emulator.o: ' + str(old_emulator)).encode(), ('emulator.o: ' + str(emulator)).encode())
    makefile.write_bytes(raw)
    save(logdir / 'observation-audit.json', {'parent_receipt':str(original_path),
        'parent_receipt_sha256':sha(original_path), 'parent_simulator_sha256':sha(original['simulator']),
        'source_id':original['source_id'], 'model_inputs':inventory, 'print_guard_edits':edits,
        'inverse_patch_byte_identity':True, 'functional_rtl_changed':False,
        'fatal_assertions_unchanged':True, 'progress_source':'io_stage1_cache_0 (BOOM cycle)',
        'progress_period_harness_cycles':65536})
    command = ['nice','-n','15','make','-j2','-C',str(model),'-f','VTestHarness.mk','VM_PARALLEL_BUILDS=1']
    env = os.environ.copy()
    env['PATH'] = str(ENV / 'bin') + ':/usr/local/bin:/usr/bin:/bin'
    env['CXX'] = '/usr/bin/g++'
    started = time.monotonic()
    with (logdir / 'build.log').open('wb', buffering=0) as stream:
        rc = subprocess.run(command, env=env, stdout=stream, stderr=subprocess.STDOUT).returncode
        os.fsync(stream.fileno())
    result = {**original, 'configuration':'chipyard.DacLinuxC4-diagnostic36-events',
        'phase':'native-events', 'returncode':rc, 'simulator':str(simulator),
        'parent_native_receipt':str(original_path), 'parent_native_receipt_sha256':sha(original_path),
        'generated_model_directory':str(model), 'observation_audit':str(logdir / 'observation-audit.json'),
        'observation_audit_sha256':sha(logdir / 'observation-audit.json'),
        'required_events_without_verbose':True, 'functional_rtl_changed':False,
        'slowdown_eligible':False, 'diagnostic_max_physmem_bits':36,
        'command':command, 'wall_seconds':time.monotonic()-started,
        'outputs':{p:sha(p) for p in [str(simulator),str(generated / 'chipyard.TestHarness.DacLinuxC4.dts')] if Path(p).exists()},
        'target_execution':'NOT_RUN','runtime_validation':'NOT_RUN'}
    save(logdir / 'result.json', result)
    if rc == 0:
        save(WORK / 'diagnostic36/native-build.json', result)
    print('returncode=' + str(rc), flush=True)
    return rc


if __name__ == '__main__':
    raise SystemExit(main())
