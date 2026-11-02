"""Read-only inventory of BlackBox inputs; never import or run hardware code."""
from pathlib import Path
import hashlib
import re
import shutil


# Compile source/resource roots from the pinned b3 build.sbt. This deliberately
# excludes src/main/old, src/main/v0 and unrelated test/FPGA/FireSim generators.
MODULES = {
    'rocketchip': 'generators/rocket-chip', 'testchipip': 'generators/testchipip',
    'chipyard': 'generators/chipyard', 'boom': 'generators/boom',
    'hwacha': 'generators/hwacha', 'sifive_blocks': 'generators/sifive-blocks',
    'sifive_cache': 'generators/sifive-cache', 'sha3': 'generators/sha3',
    'gemmini': 'generators/gemmini', 'icenet': 'generators/icenet',
    'tracegen': 'generators/tracegen', 'cva6': 'generators/cva6',
    'nvdla': 'generators/nvdla', 'sodor': 'generators/riscv-sodor',
    'ibex': 'generators/ibex', 'fft_generator': 'generators/fft-generator',
    'constellation': 'generators/constellation', 'mempress': 'generators/mempress',
    'iocell': 'tools/barstools', 'dsptools': 'tools/dsptools',
    'rocket-dsp-utils': 'tools/rocket-dsp-utils',
    'api-config-chipsalliance': 'tools/api-config-chipsalliance',
    'hardfloat': 'generators/rocket-chip/hardfloat',
    'rocketMacros': 'generators/rocket-chip/macros',
    'rocketConfig': 'generators/rocket-chip/api-config-chipsalliance/build-rules/sbt',
    'targetutils': 'sims/firesim/sim/midas/targetutils',
}


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def uncomment(text):
    # Preserve strings (including embedded //) and line numbers. This is a
    # lexical inventory, not a Scala parser or a claim of Config reachability.
    token = r'"""[\s\S]*?"""|"(?:\\.|[^"\\])*"|//[^\n]*|/\*[\s\S]*?\*/'
    return re.sub(token, lambda m: re.sub(r'[^\n]', ' ', m[0])
                  if m[0].startswith(('//', '/*')) else m[0], text)


def source_roots(chipyard):
    result = {}
    for module, relative in MODULES.items():
        base = chipyard / relative
        scala = base / 'src/main/scala'
        if module == 'sifive_cache':
            scala = base / 'design/craft'
        if module == 'iocell':
            scala /= 'barstools/iocell'
        result[module] = (scala, base / 'src/main/resources')
    return result


def inventory(chipyard, extra_files=None):
    """Return every missing literal and unresolved dynamic reference together.

    extra_files maps chipyard-relative overlay targets to verified payloads.
    Resolution uses the actual classpath-relative name, never just a basename.
    """
    chipyard = Path(chipyard)
    extra_files = extra_files or {}
    roots = source_roots(chipyard)
    resources = {}
    for module, (_, directory) in roots.items():
        if directory.is_dir():
            for path in sorted(directory.rglob('*')):
                if path.is_file():
                    name = '/' + path.relative_to(directory).as_posix()
                    resources.setdefault(name, []).append((module, path, 'historical_tree'))
        prefix = directory.relative_to(chipyard).as_posix() + '/'
        for relative, payload in extra_files.items():
            if relative.startswith(prefix):
                name = '/' + relative[len(prefix):]
                resources.setdefault(name, []).append((module, Path(payload), 'restoration_overlay'))
    refs, dynamic, missing, ambiguous = [], [], [], []
    files = 0
    call = re.compile(r'\b(addResource|addPath)\s*\(\s*([^\n)]*)\)')
    for module, (scala, _) in roots.items():
        for path in sorted(scala.rglob('*.scala')) if scala.is_dir() else []:
            files += 1
            text = uncomment(path.read_text(errors='replace'))
            for match in call.finditer(text):
                api, expression = match.groups()
                ref = {'module': module, 'source': path.relative_to(chipyard).as_posix(),
                       'source_sha256': digest(path),
                       'line': text.count('\n', 0, match.start()) + 1,
                       'api': api, 'expression': expression.strip()}
                literal = re.fullmatch(r'"([^"\\]+)"', expression.strip())
                if not literal:
                    ref['status'] = 'UNRESOLVED_DYNAMIC'
                    dynamic.append(ref)
                    continue
                name = literal[1]
                ref['resource'] = name
                candidates = resources.get(name, []) if api == 'addResource' else []
                ref['providers'] = [{'module': m, 'path': str(p), 'kind': kind,
                                     'sha256': digest(p)} for m, p, kind in candidates]
                if not candidates:
                    ref['status'] = 'MISSING' if api == 'addResource' else 'UNRESOLVED_PATH'
                    missing.append(ref)
                elif len({x['sha256'] for x in ref['providers']}) > 1:
                    ref['status'] = 'AMBIGUOUS'
                    ambiguous.append(ref)
                else:
                    ref['status'] = 'PRESENT'
                refs.append(ref)
    # WithClockGateModel is selected through v1Config -> AbstractConfig. The
    # API argument is a variable, so a literal-call scan alone cannot see it.
    name = '/vsrc/EICG_wrapper.v'
    candidates = resources.get(name, [])
    ref = {'module': 'rocketchip',
           'source': 'generators/rocket-chip/src/main/scala/subsystem/Configs.scala',
           'line': 524, 'resource': name, 'expression': 'WithClockGateModel default',
           'api': 'config-selected resource',
           'providers': [{'module': m, 'path': str(p), 'kind': kind,
                          'sha256': digest(p)} for m, p, kind in candidates],
           'status': 'PRESENT' if candidates else 'MISSING'}
    refs.append(ref)
    if not candidates:
        missing.append(ref)
    return {'kind': 'static_blackbox_resource_inventory',
            'scope': 'pinned b3 chipyard Compile dependency source roots; no elaboration',
            'scala_files': files, 'literal_references': refs,
            'missing': missing, 'ambiguous': ambiguous, 'dynamic': dynamic,
            'resource_names': len(resources),
            'limitation': 'Literal presence is not proof of Config reachability or hardware correctness.'}


def restored_inputs(launcher):
    """Verify the offline restoration before allowing it into any fresh copy."""
    config = launcher.inside(launcher.ROOT / 'resource_restoration.json')
    data = launcher.read_json(config)
    if (data.get('schema') != 1 or data.get('baseline_commit') != launcher.REV or
            data.get('config') != 'chipyard.v1Config'):
        launcher.fail('Unexpected resource restoration identity/configuration')
    proof = launcher.inside(launcher.ROOT / data['provenance'])
    if digest(proof) != data['provenance_sha256']:
        launcher.fail('Resource restoration provenance identity mismatch')
    files, errors = {}, []
    for entry in data['files']:
        relative = entry['target']
        target = Path(relative)
        if (target.is_absolute() or '..' in target.parts or
                target.parent.as_posix() != 'generators/rocket-chip/src/main/resources/vsrc' or
                target.suffix != '.v' or relative in files):
            launcher.fail('Unsafe/duplicate restoration target: ' + relative)
        payload = launcher.inside(launcher.ROOT / entry['payload'])
        if not payload.is_file() or digest(payload) != entry['sha256']:
            errors.append('Restoration payload missing/corrupt: ' + relative)
        if (launcher.CHIPYARD / relative).exists():
            errors.append('Restoration may not overwrite canonical input: ' + relative)
        files[relative] = payload
    if errors:
        launcher.fail('\n'.join(errors))
    return data, files, {'path': str(config), 'sha256': digest(config),
                         'provenance': str(proof), 'provenance_sha256': digest(proof),
                         'status': data['identity_status'], 'file_count': len(files)}


def checked_inventory(launcher):
    data, files, identity = restored_inputs(launcher)
    result = inventory(launcher.CHIPYARD, files)
    reviews = {(x['source'], x['api'], x['expression']): x for x in data['dynamic_reviews']}
    unreviewed = []
    for ref in result['dynamic']:
        review = reviews.get((ref['source'], ref['api'], ref['expression']))
        if not review or ref['source_sha256'] != review['source_sha256']:
            unreviewed.append(ref)
        else:
            ref.update({'status': review['status'], 'review': review['reason']})
    result['unreviewed_dynamic'] = unreviewed
    result['restoration'] = identity
    result['status'] = 'FAIL' if (result['missing'] or result['ambiguous'] or unreviewed) else 'PASS'
    return result


def apply_restoration(launcher, chipyard):
    """Copy verified missing inputs into a NEW execution/metadata tree only."""
    _, files, identity = restored_inputs(launcher)
    chipyard = launcher.inside(chipyard)
    if chipyard.resolve().is_relative_to(launcher.SOURCE.resolve()):
        launcher.fail('Refusing to augment canonical historical source')
    for relative, payload in files.items():
        target = launcher.inside(chipyard / relative, chipyard)
        if target.exists() or target.is_symlink():
            launcher.fail('Restoration collision: ' + str(target))
    for relative, payload in files.items():
        target = chipyard / relative
        target.parent.mkdir(parents=True, exist_ok=True)
        with target.open('xb') as output, payload.open('rb') as source:
            shutil.copyfileobj(source, output)
        target.chmod(0o644)
        if digest(target) != digest(payload):
            launcher.fail('Restoration copy identity mismatch: ' + str(target))
    return identity


def verify_execution_inputs(launcher, chipyard):
    expected = checked_inventory(launcher)
    actual = inventory(chipyard)

    def signatures(report):
        literal = [(x['source'], x['line'], x['resource'],
                    tuple(sorted((p['module'], p['sha256']) for p in x['providers'])))
                   for x in report['literal_references']]
        dynamic = [(x['source'], x['line'], x['api'], x['expression'], x['source_sha256'])
                   for x in report['dynamic']]
        return sorted(literal), sorted(dynamic)

    if (actual['missing'] or actual['ambiguous'] or
            actual['scala_files'] != expected['scala_files'] or
            signatures(actual) != signatures(expected)):
        launcher.fail('Actual execution-copy resources differ from preflight; no hardware task started')
    actual['status'] = 'PASS_ACTUAL_COPY_INPUTS'
    return actual


def make_inputs(chipyard):
    """Expand only known literal prerequisites. Never evaluate a Makefile."""
    chipyard = Path(chipyard)
    variables = {'base_dir': chipyard,
                 'CHIPYARD_RSRCS_DIR': chipyard / 'generators/chipyard/src/main/resources',
                 'ROCKETCHIP_RSRCS_DIR': chipyard / 'generators/rocket-chip/src/main/resources',
                 'TESTCHIP_RSRCS_DIR': chipyard / 'generators/testchipip/src/main/resources'}
    result = []
    for name in ('sims/verilator/Makefile', 'common.mk', 'variables.mk'):
        path = chipyard / name
        if not path.is_file():
            result.append({'source': name, 'path': str(path), 'present': False})
            continue
        text = path.read_text().replace('\\\n', ' ')
        required = re.findall(r'^SIM_FILE_REQS\s*\+=([^\n]*)', text, re.M)
        tokens = [x for group in required for x in group.split()]
        tokens += re.findall(r'^include\s+(\$\(base_dir\)/[^\s]+)', text, re.M)
        for token in tokens:
            match = re.fullmatch(r'\$\(([^)]+)\)/(.*)', token)
            if not match or match[1] not in variables:
                result.append({'source': name, 'path': token, 'present': False,
                               'error': 'Cannot safely resolve literal Make input'})
                continue
            target = variables[match[1]] / match[2]
            result.append({'source': name, 'path': str(target),
                           'present': target.is_file(),
                           'sha256': digest(target) if target.is_file() else None})
    return result


def failure_summary(log, limit=14):
    """Surface causal errors without flooding the terminal with normal output."""
    candidates = []
    pattern = re.compile(r'\[error\]|(?:fatal error|error:|Exception:|No rule to make target|not found|undefined reference|Error [0-9]|Permission denied|No space left|Killed)', re.I)
    with Path(log).open(errors='replace') as stream:
        for number, line in enumerate(stream, 1):
            if pattern.search(line):
                candidates.append({'line': number, 'text': line.rstrip()[:1200]})
    # Keep the first actual errors as well as the final exception/make exit.
    if len(candidates) <= limit:
        return candidates
    head = limit // 2
    return candidates[:head] + candidates[-(limit - head):]
