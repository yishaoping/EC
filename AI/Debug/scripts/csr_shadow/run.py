#!/usr/bin/env python3
"""Compile and exercise the actual CSRFile replay/management bank selection.

Accepts a colon-separated Chipyard runtime classpath export. The optional CSR
source override is for an isolated candidate, never an edit of generated RTL.
"""
import argparse
import hashlib
import json
from pathlib import Path
import resource
import subprocess

ROOT = Path(__file__).resolve().parents[4]
HERE = Path(__file__).resolve().parent


def digest(p):
    h = hashlib.sha256()
    with p.open('rb') as stream:
        for data in iter(lambda: stream.read(1024 * 1024), b''):
            h.update(data)
    return h.hexdigest()


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--out', type=Path, required=True)
    p.add_argument('--classpath-file', type=Path, required=True)
    p.add_argument('--source', type=Path, default=ROOT / 'chipyard/generators/rocket-chip/src/main/scala/rocket/CSR.scala')
    p.add_argument('--java', type=Path, default=ROOT / 'chipyard/.conda-env/lib/jvm/bin/java')
    p.add_argument('--scala-compiler-classpath', required=True)
    p.add_argument('--chisel-plugin', type=Path, required=True)
    p.add_argument('--jobs', type=int, default=4)
    a = p.parse_args()
    out, source = a.out.resolve(), a.source.resolve()
    assert out.is_relative_to(ROOT / 'AI/TMP') and not out.exists()
    out.mkdir()
    classes, gen = out / 'classes', out / 'generated'
    classes.mkdir()
    gen.mkdir()
    cp = a.classpath_file.read_text().strip()
    assert all(Path(x).is_file() for x in cp.split(':')), 'runtime classpath must contain jars'
    inputs = [source, HERE / 'CSRShadowGenerate.scala', HERE / 'csr_shadow_test.cpp',
              Path(__file__).resolve(), a.classpath_file.resolve(), a.chisel_plugin.resolve()]
    inputs += [Path(x) for x in cp.split(':') + a.scala_compiler_classpath.split(':')]
    hashes = {str(p): digest(p) for p in inputs}
    (out / 'inputs.json').write_text(json.dumps(hashes, indent=2) + '\n')
    resource.setrlimit(resource.RLIMIT_CORE, (0, 0))

    def command(args, name):
        (out / (name + '.command.json')).write_text(json.dumps(args, indent=2) + '\n')
        with (out / (name + '.log')).open('x') as log:
            ret = subprocess.run(args, cwd=out, stdout=log, stderr=subprocess.STDOUT).returncode
        (out / (name + '.exit')).write_text(str(ret) + '\n')
        if ret:
            raise RuntimeError(f'{name} exit {ret}')

    status = 'FAIL'
    try:
        command([str(a.java), '-Xmx8G', '-Xss8M', '-cp', a.scala_compiler_classpath,
                 'scala.tools.nsc.Main', '-classpath', cp, '-Xplugin:' + str(a.chisel_plugin),
                 '-language:reflectiveCalls', '-d', str(classes), str(source),
                 str(HERE / 'CSRShadowGenerate.scala')], 'compile')
        command([str(a.java), '-Xmx8G', '-Xss8M', '-cp', str(classes) + ':' + cp,
                 'palimpsesttest.EmitCSRShadow', str(gen)], 'emit')
        command(['verilator', '--cc', '--exe', '--build', '-j', str(a.jobs), '--assert',
                 '-Wno-fatal', '-y', str(gen), '--top-module', 'CSRShadowHarness',
                 '--Mdir', str(out / 'obj'), '-CFLAGS', '-std=c++17',
                 str(gen / 'CSRShadowHarness.v'), str(HERE / 'csr_shadow_test.cpp')], 'build')
        command([str(out / 'obj/VCSRShadowHarness')], 'run')
        assert 'PALIMPSEST_CSR_SHADOW=PASS' in (out / 'run.log').read_text()
        assert all(digest(Path(p)) == h for p, h in hashes.items()), 'inputs changed'
        status = 'PASS'
    finally:
        (out / 'result.json').write_text(json.dumps(dict(status=status,
            scope='Actual production CSRFile, architectural replay bank versus management isolation',
            source=str(source)), indent=2) + '\n')
    print('PALIMPSEST_CSR_SHADOW_RUNNER=PASS')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
