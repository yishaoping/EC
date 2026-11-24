#!/usr/bin/env python3
"""Link the read-only interrupt observer to an existing complete Core model."""
import argparse
import json
from pathlib import Path
import subprocess
import sys

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[3]
sys.path.insert(0, str(HERE.parent / 'rollback'))
from build_io_observer import digest


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--model-dir', type=Path, required=True)
    p.add_argument('--model-library', type=Path,
                   help='existing immutable archive; default VTestHarness__ALL.a')
    p.add_argument('--out', type=Path, required=True)
    a = p.parse_args()
    model, out = a.model_dir.resolve(), a.out.resolve()
    library = (a.model_library or model / 'VTestHarness__ALL.a').resolve()
    assert all(x.is_relative_to(ROOT / 'AI/TMP') for x in (model, out, library))
    assert library.is_file()
    out.mkdir()
    src = HERE / 'interrupt_observer.cc'
    obj, sim = out / 'observer.o', out / 'simulator'
    mk = out / 'observer.mk'
    mk.write_text('include VTestHarness.mk\n'
        f'{obj}: {src}\n\t$(CXX) $(CXXFLAGS) $(CPPFLAGS) -O0 -c -o $@ $<\n'
        f'{sim}: {obj} {library} $(VK_USER_OBJS) $(VK_GLOBAL_OBJS)\n'
        f'\t$(LINK) $(LDFLAGS) {obj} -Wl,--wrap=_ZN12VTestHarness9eval_stepEv '
        f'$(VK_USER_OBJS) $(VK_GLOBAL_OBJS) {library} '
        '$(LOADLIBES) $(LDLIBS) $(LIBS) $(SC_LIBS) -o $@\n'
        '.PHONY: observer_objects\nobserver_objects:\n'
        "\t@printf '%s\\n' $(VK_USER_OBJS) $(VK_GLOBAL_OBJS)\n")
    objects = subprocess.check_output(['make', '--no-print-directory', '-s', '-f',
        str(mk), 'observer_objects'], cwd=model, text=True).splitlines()
    inputs = [src, Path(__file__).resolve(), HERE.parent / 'rollback/io_effect_observer.cc',
              library, model / 'VTestHarness___024root.h',
              model / 'VTestHarness.mk'] + [model / x for x in objects]
    hashes = {str(x): digest(x) for x in inputs}
    (out / 'inputs.json').write_text(json.dumps(hashes, indent=2) + '\n')
    args = ['make', '-f', str(mk), str(sim)]
    (out / 'command.json').write_text(json.dumps(args, indent=2) + '\n')
    with (out / 'build.log').open('x') as log:
        ret = subprocess.run(args, cwd=model, stdout=log, stderr=subprocess.STDOUT).returncode
    (out / 'build.exit').write_text(str(ret) + '\n')
    assert ret == 0, out / 'build.log'
    assert all(digest(Path(x)) == h for x, h in hashes.items()), 'observer inputs changed'
    print(sim)


if __name__ == '__main__':
    main()
