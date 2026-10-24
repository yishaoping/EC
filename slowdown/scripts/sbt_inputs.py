"""Static SBT project inventory. Never run SBT, Scala, or build commands."""
import hashlib
import json
from pathlib import Path
import re

LOCAL_BUILDS = (("chipyard", "."), ("firesim_shared_build", "sims/firesim/sim"))


def uncomment(text):
    token = r'"""[\s\S]*?"""|"(?:\\.|[^"\\])*"|//[^\n]*|/\*[\s\S]*?\*/'
    return re.sub(token, lambda m: re.sub(r'[^\n]', ' ', m[0])
                  if m[0].startswith(('//', '/*')) else m[0], text)


def build_plan(current, target):
    """Recognize the pinned builds' limited project declaration syntax.

    Fail closed for new or changed declaration forms; this is not a Scala
    interpreter. ProjectRefs are references, not additional project definitions.
    """
    current, target = Path(current).resolve(), Path(target).resolve()
    target.relative_to(Path('/data1/gzh/EC/slowdown/build').resolve())
    projects, definitions = [], {}
    declaration = re.compile(r'^lazy val\s+(`[^`]+`|\w+)\s*=\s*([^\n]+)', re.M)
    for namespace, relative in LOCAL_BUILDS:
        build = current / relative
        definition = build / 'build.sbt'
        text = uncomment(definition.read_text())
        definitions[str(definition)] = hashlib.sha256(definition.read_bytes()).hexdigest()
        matches = list(declaration.finditer(text))
        aliases = {}
        for match in matches:
            identifier, expression = match.groups()
            if expression.startswith('ProjectRef'):
                strings = re.findall(r'"([^"\n]*)"', expression)
                other = ('firesim_shared_build' if 'firesimDir' in expression
                         else 'chipyard' if 'chipyardDir' in expression else namespace)
                aliases[identifier.strip('`')] = (other, strings[-1])
        for index, match in enumerate(matches):
            identifier, expression = match.groups()
            identifier = identifier.strip('`')
            if not re.match(r'(?:\(?project\s+in\b|Project\s*\(|freshProject\s*\()', expression):
                continue
            literals = re.findall(r'"([^"\n]*)"', expression)
            if expression.startswith('freshProject'):
                if literals[0] != identifier:
                    raise RuntimeError('SBT project id differs from declaration: ' + match[0])
                base = build / (literals[1] if len(literals) == 2 else 'generators/rocket-chip') / 'src'
            elif expression.startswith('Project'):
                if literals[0] != identifier or len(literals) < 2:
                    raise RuntimeError('Unsupported SBT Project: ' + match[0])
                base = build / Path(*literals[1:])
            elif 'rocketChipDir /' in expression:
                base = build / 'generators/rocket-chip' / literals[0]
            elif re.match(r'\(project in file\("[^"\n]+"\)\)', expression):
                base = build / literals[0]
            else:
                raise RuntimeError('Unsupported SBT project declaration: ' + match[0])
            base = base.resolve()
            base.relative_to(current)
            special = expression.startswith('freshProject') or identifier == 'iocell'
            scala = base / ('main/scala' if special else 'src/main/scala')
            resource = base / ('main/resources' if special else 'src/main/resources')
            if identifier == 'iocell':
                scala /= 'barstools/iocell'
            if identifier == 'sifive_cache':
                scala = base / 'design/craft'
            if identifier == 'rocketConfig':
                scala = base / '../../design/craft/src'
            body = text[match.end():matches[index + 1].start() if index + 1 < len(matches) else len(text)]
            dependencies = []
            for call in re.finditer(r'\.dependsOn\(([^)]*)\)', body):
                names = re.sub(r'"[^"\n]*"', '', call[1])
                for dependency in re.findall(r'`([^`]+)`|\b([A-Za-z_]\w*)\b', names):
                    name = dependency[0] or dependency[1]
                    dep = aliases.get(name, (namespace, name))
                    dependencies.append(list(dep))
            projects.append({'build': namespace, 'build_root': str(build),
                             'id': identifier, 'base': str(base),
                             'scala': str(scala), 'resources': str(resource),
                             'target': str(target / namespace / identifier),
                             'dependencies': dependencies})
    keys = [(p['build'], p['id']) for p in projects]
    destinations = [p['target'] for p in projects]
    if len(keys) != len(set(keys)) or len(destinations) != len(set(destinations)):
        raise RuntimeError('SBT project/output collision')
    for key in [('chipyard', 'rocketchip'), ('chipyard', 'chipyard'),
                ('firesim_shared_build', 'targetutils')]:
        if key not in keys:
            raise RuntimeError('Required SBT project missing: ' + repr(key))
    return {'schema': 1, 'projects': projects, 'build_definitions': definitions,
            'scope': 'static pinned declaration inventory; no SBT evaluation'}


def project_ref(project):
    return 'ProjectRef(file(' + json.dumps(project['build_root']) + '), ' + json.dumps(project['id']) + ')'


def target_settings(plan):
    return 'set Seq(' + ', '.join(
        project_ref(p) + ' / target := file(' + json.dumps(p['target']) + ')'
        for p in plan['projects']) + ')'


def reachable_projects(plan):
    by_key = {(p['build'], p['id']): p for p in plan['projects']}
    visited = set()

    def visit(key):
        if key in visited:
            return
        if key not in by_key:
            raise RuntimeError('Unrecognized dependency in static SBT closure: ' + repr(key))
        visited.add(key)
        for dependency in by_key[key]['dependencies']:
            visit(tuple(dependency))
    visit(('chipyard', 'chipyard'))
    return [p for p in plan['projects'] if (p['build'], p['id']) in visited]


def resource_inventory(plan):
    """Scan literal BlackBox references and report all unresolved calls together."""
    current = Path(plan['projects'][0]['build_root'])
    projects = reachable_projects(plan)
    providers, references, dynamic, scanned = {}, [], [], 0
    for project in projects:
        directory = Path(project['resources'])
        for path in sorted(directory.rglob('*')) if directory.is_dir() else []:
            if path.is_file():
                name = '/' + path.relative_to(directory).as_posix()
                providers.setdefault(name, []).append((project['id'], path))
    call = re.compile(r'\b(addResource|addPath)\s*\(\s*([^\n)]*)\)')
    for project in projects:
        directory = Path(project['scala'])
        for path in sorted(directory.rglob('*.scala')) if directory.is_dir() else []:
            scanned += 1
            text = uncomment(path.read_text())
            for match in call.finditer(text):
                api, expression = match.groups()
                item = {'module': project['id'], 'source': path.relative_to(current).as_posix(),
                        'source_sha256': hashlib.sha256(path.read_bytes()).hexdigest(),
                        'line': text.count('\n', 0, match.start()) + 1,
                        'api': api, 'expression': expression.strip()}
                literal = re.fullmatch(r'"([^"\\]+)"', expression.strip())
                if literal and api == 'addResource':
                    item['resource'] = literal[1]
                    references.append(item)
                else:
                    dynamic.append(item)
    # Config-selected variable resource, not recognizable by literal-call scan.
    references.append({'module': 'rocketchip',
                       'source': 'generators/rocket-chip/src/main/scala/subsystem/Configs.scala',
                       'source_sha256': hashlib.sha256((current / 'generators/rocket-chip/src/main/scala/subsystem/Configs.scala').read_bytes()).hexdigest(),
                       'api': 'config-selected resource', 'expression': 'WithClockGateModel default',
                       'resource': '/vsrc/EICG_wrapper.v'})
    missing, ambiguous = [], []
    for item in references:
        candidates = providers.get(item['resource'], [])
        item['providers'] = [{'module': module, 'path': str(path),
                              'sha256': hashlib.sha256(path.read_bytes()).hexdigest()}
                             for module, path in candidates]
        owner = [entry for entry in item['providers'] if entry['module'] == item['module']]
        if len(owner) == 1:
            item['expected_provider'] = owner[0]
        elif len({p['sha256'] for p in item['providers']}) == 1:
            item['expected_provider'] = item['providers'][0]
        else:
            missing.append(item['resource'] + ': missing or no unique source owner')
        if len({p['sha256'] for p in item['providers']}) > 1:
            ambiguous.append(item['resource'])
    return {'schema': 1, 'scope': 'Current chipyard Compile project dependency closure; static lexical scan',
            'projects': [{'build': p['build'], 'id': p['id']} for p in projects],
            'build_definitions': plan['build_definitions'], 'scala_files': scanned,
            'resource_names': len(providers), 'references': references, 'dynamic': dynamic,
            'missing': missing, 'ambiguous_names': sorted(set(ambiguous)),
            'limitation': 'Config reachability is manually reviewed; presence alone is not a classpath or runtime proof'}


def checked_resource_inventory(plan, pinned_file):
    pinned = json.loads(Path(pinned_file).read_text())
    actual = resource_inventory(plan)
    errors = list(actual['missing'])
    if pinned.get('schema') != 1 or pinned.get('config') != 'chipyard.v1Config':
        errors.append('Unexpected BlackBox review schema/Config')
    if pinned.get('inventory') != actual:
        errors.append('Current BlackBox inputs/definitions changed since resource review')
    reviews = pinned.get('dynamic_reviews', [])
    if len(reviews) != len(actual['dynamic']):
        errors.append('Dynamic resource review count mismatch')
    for item in actual['dynamic']:
        found = [r for r in reviews if r.get('reference') == item]
        if len(found) != 1 or found[0].get('status') not in ('INACTIVE_FOR_PINNED_V1CONFIG', 'RESOLVED_CONFIG_RESOURCE'):
            errors.append('Unreviewed dynamic resource: ' + item['source'] + ':' + item['api'])
    for path, expected in pinned.get('config_sha256', {}).items():
        if hashlib.sha256(Path(path).read_bytes()).hexdigest() != expected:
            errors.append('Reviewed Config source changed: ' + path)
    if not pinned.get('config_sha256'):
        errors.append('Missing Config identity for dynamic-resource review')
    # ClockGate chooses addPath if this absolute OS path exists; the pinned
    # Config review and classpath guard require the addResource branch.
    if Path('/vsrc/EICG_wrapper.v').exists():
        errors.append('Host /vsrc/EICG_wrapper.v shadows the reviewed classpath ClockGate model')
    if errors:
        raise RuntimeError('BlackBox source preflight failures:\n- ' + '\n- '.join(errors))
    return actual


def target_probe_commands(plan):
    commands, expected = [], []
    for project in plan['projects']:
        ref = '{' + Path(project['build_root']).as_uri() + '/}' + project['id']
        commands.append('show ' + ref + ' / target')
        expected.append({'key': 'target', 'path': project['target']})
        commands.append('show ' + ref + ' / Compile / classDirectory')
        expected.append({'key': 'classDirectory', 'path': project['target']})
    return commands, expected


def verify_target_probe(text, expected):
    observed = re.findall(r'^\[info\]\s+(/[^\n\r]+)\s*$', text, re.M)
    observed = [path.strip() for path in observed]
    errors = []
    if len(observed) != len(expected):
        errors.append('Missing/extra SBT target values: ' + str(len(observed)) + '/' + str(len(expected)))
    for actual, entry in zip(observed, expected):
        if entry['key'] == 'target' and actual != entry['path']:
            errors.append('Wrong target: ' + actual + '; expected ' + entry['path'])
        if entry['key'] == 'classDirectory' and Path(entry['path']) not in Path(actual).parents:
            errors.append('classDirectory escaped project target: ' + actual)
    if len(set(observed[::2])) != len(expected) // 2 or len(set(observed[1::2])) != len(expected) // 2:
        errors.append('Multiple SBT projects share target/classes output')
    if errors:
        raise RuntimeError('SBT output isolation failed; refusing compilation:\n- ' + '\n- '.join(errors))
    return {'status': 'PASS', 'projects': len(expected) // 2, 'evaluated_values': observed}


def verify_classpath(plan, inventory, classpath):
    """Validate actual exported JAR contents and classpath resource selection.

    This is run by the user launcher AFTER Scala packaging and BEFORE Generator.
    Read directories/JARs only, never extract or synthesize replacement resources.
    """
    import zipfile
    errors, details = [], []
    entries = [Path(path) for path in classpath]
    for entry in entries:
        if not entry.exists():
            errors.append('Missing exported classpath entry: ' + str(entry))
    archives = {}
    try:
        for entry in entries:
            if entry.is_file() and entry.suffix == '.jar':
                try:
                    archives[str(entry)] = zipfile.ZipFile(entry)
                except (OSError, zipfile.BadZipFile) as exc:
                    errors.append('Unreadable JAR: ' + str(entry) + ': ' + str(exc))
        for item in inventory['references']:
            name = item['resource'].lstrip('/')
            expected = item['expected_provider']
            found = []
            for entry in entries:
                jar = archives.get(str(entry))
                data = None
                if jar and name in jar.namelist():
                    data = jar.read(name)
                elif entry.is_dir() and (entry / name).is_file():
                    data = (entry / name).read_bytes()
                if data is not None:
                    found.append({'classpath': str(entry), 'sha256': hashlib.sha256(data).hexdigest()})
            owner = next(p for p in plan['projects'] if p['id'] == expected['module'] and p in reachable_projects(plan))
            owner_entries = [r for r in found if Path(owner['target']) in Path(r['classpath']).parents]
            if not owner_entries or any(r['sha256'] != expected['sha256'] for r in owner_entries):
                errors.append('Owner JAR resource missing/changed: ' + item['resource'] + ' (' + expected['module'] + ')')
            if not found or found[0]['sha256'] != expected['sha256']:
                errors.append('Classpath selected resource missing/wrong provider: ' + item['resource'])
            details.append({'resource': item['resource'], 'expected': expected, 'found': found})
    finally:
        for jar in archives.values():
            jar.close()
    return {'status': 'FAIL' if errors else 'PASS', 'errors': sorted(set(errors)),
            'checked_references': len(details), 'classpath': list(map(str, entries)),
            'resources': details,
            'scope': 'actual exported classpath order and JAR bytes; not a simulation/correctness proof'}
