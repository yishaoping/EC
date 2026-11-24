#!/usr/bin/env python3
"""Link a read-only IOMSHR observer to an already generated Verilator model."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import subprocess

REPO = Path(__file__).resolve().parents[4]


def digest(path):
    h = hashlib.sha256()
    with path.open('rb') as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b''):
            h.update(block)
    return h.hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--model-dir', type=Path, required=True)
    parser.add_argument('--model-library', type=Path,
                        help='explicit existing archive; default VTestHarness__ALL.a')
    parser.add_argument('--out', type=Path, required=True)
    parser.add_argument('--with-rebase', action='store_true',
                        help='also observe physical rebase reservation/reset ownership')
    args = parser.parse_args()
    model, out = args.model_dir.resolve(), args.out.resolve()
    library = (args.model_library or model / 'VTestHarness__ALL.a').resolve()
    for path in (model, out, library):
        assert path.is_relative_to(REPO / 'AI/TMP') and re.fullmatch(r'[\w/.-]+', str(path))
    assert library.is_file() and (model / 'VTestHarness.mk').is_file()
    out.mkdir()  # Preserve all earlier builds and failures.
    observer = Path(__file__).with_name(
        'concurrency_observer.cc' if args.with_rebase else 'io_effect_observer.cc')
    inputs = [p for p in sorted(model.iterdir()) if p.suffix in {'.cpp', '.h', '.mk'}]
    inputs += [library, observer, Path(__file__).resolve()]
    if args.with_rebase:
        inputs.append(Path(__file__).with_name('io_effect_observer.cc'))
    target, obj = out / 'simulator', out / 'io_effect_observer.o'
    makefile = out / 'observer.mk'
    makefile.write_text(
        'include VTestHarness.mk\n'
        f'{obj}: {observer}\n'
        '\t$(CXX) $(CXXFLAGS) $(CPPFLAGS) -O0 -c -o $@ $<\n'
        f'{target}: {obj} {library} $(VK_USER_OBJS) $(VK_GLOBAL_OBJS)\n'
        '\t$(LINK) $(LDFLAGS) ' + str(obj) +
        ' -Wl,--wrap=_ZN12VTestHarness9eval_stepEv $(VK_USER_OBJS) $(VK_GLOBAL_OBJS) ' +
        str(library) + ' $(LOADLIBES) $(LDLIBS) $(LIBS) $(SC_LIBS) -o $@\n')
    with makefile.open('a') as stream:
        stream.write("\n.PHONY: observer_objects\nobserver_objects:\n"
                     "\t@printf '%s\\n' $(VK_USER_OBJS) $(VK_GLOBAL_OBJS)\n")
    objects = subprocess.check_output(
        ['make', '--no-print-directory', '-s', '-f', str(makefile), 'observer_objects'],
        cwd=model, text=True).splitlines()
    inputs += [model / p for p in objects]
    hashes = {str(p.relative_to(REPO)): digest(p) for p in inputs}
    (out / 'inputs.json').write_text(json.dumps(hashes, indent=2) + '\n')
    command = ['make', '-f', str(makefile), str(target)]
    (out / 'command.json').write_text(json.dumps(command, indent=2) + '\n')
    with (out / 'build.log').open('x') as log:
        ret = subprocess.run(command, cwd=model, stdout=log, stderr=subprocess.STDOUT).returncode
    (out / 'build.exit').write_text(f'{ret}\n')
    assert ret == 0, f'see {out / "build.log"}'
    assert all(digest(REPO / p) == h for p, h in hashes.items()), 'build input changed'
    (out / 'simulator.sha256').write_text(digest(target) + '  ' + str(target) + '\n')
    print(target)


if __name__ == '__main__':
    main()
