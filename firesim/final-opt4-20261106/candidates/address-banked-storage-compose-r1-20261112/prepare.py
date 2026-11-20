#!/usr/bin/python3
"""Bind a private source composition without selecting a production design."""
import hashlib
import json
from pathlib import Path

C = Path(__file__).resolve().parent
W = C.parent.parent
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
PRODUCTION = W/'candidates/address-banked-production-host-r1-20261112'
COMPLETE = W/'candidates/address-banked-complete-module-r1-20261112'
STORAGE = W/'candidates/dcache-storage-compose-r2-20261112'
PARENT = '3656aec4033ae9fb7f06b03eb0a9ace7cdddbf0c'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'
MAIN = 'chipyard/generators/boom/src/main/scala/lsu/PackageAddressStats.scala'


def sha(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def read(path):
    return json.loads(Path(path).read_text())


def exact(path, text):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    if path.exists():
        assert path.read_text() == text, ('Immutable input changed', str(path))
    else:
        path.write_text(text)


def inverse(text, edits):
    for edit in reversed(edits):
        offset = edit['offset']
        assert text[offset:offset+len(edit['new'])] == edit['new']
        text = text[:offset]+edit['old']+text[offset+len(edit['new']):]
    return text


def prepare():
    cfg = read(STORAGE/'config.json')
    storage_contract = read(D/'build-logs/Opt4-dcache-storage-compose-r2-20261112/source-contract.json')
    assert storage_contract['source_variant'] == '5542ec134e5a90657a1f733555a74302e58a50e5dafed99e1affdb47a761efd2'
    assert all(sha(p) == h for p, h in storage_contract['files'].items())
    production = read(PRODUCTION/'source-binding.json')
    complete = read(COMPLETE/'source-binding.json')
    assert production['source_inverse_byte_equal']
    assert production['bank_state_declarations_and_update_expressions_byte_equal']
    assert production['geometry'] == dict(banks=16, lanes=16, slots=256)
    assert production['parent_sha256'] == sha(COMPLETE/'source-binding.json')
    for binding in [production, complete]:
        assert all(sha(p) == h for p, h in binding['generated'].items())
    candidate = (PRODUCTION/'CandidateModule.scala').read_text()
    previous = inverse(candidate, production['edits'])
    assert previous == (COMPLETE/'CandidateModule.scala').read_text()
    original = inverse(previous, complete['edits'])
    original = original.replace('package opt4packedref\nimport boom.lsu.AddressBucketUpdate',
                                'package boom.lsu', 1)
    assert original == (Path(cfg['source_parent'])/MAIN).read_text()
    assert original == (Path(cfg['candidate_source_root'])/MAIN).read_text()

    sources = C/'sources'
    copied = {}
    for relative in cfg['binding']['changed_files']:
        source = Path(cfg['candidate_source_root'])/relative
        destination = sources/relative
        exact(destination, source.read_text()) if relative != MAIN else None
        copied[relative] = dict(source=str(source), sha256=sha(source))
    # Keep the validated bank's namespace and implementation byte-for-byte.
    # Only its caller moves from the private harness into boom.lsu.
    old = 'package opt4bankedproduction'
    new = 'package boom.lsu\nimport opt4bankedproduction.BucketBank'
    assert candidate.count(old) == 1
    transplanted = candidate.replace(old, new, 1)
    assert transplanted.replace(new, old, 1) == candidate
    exact(sources/MAIN, transplanted)
    helper_dir = sources/'chipyard/generators/boom/src/main/scala/lsu/opt4bankedproduction'
    for source_name, name in [('BucketBankModule.scala', 'BucketBank.scala'),
                              ('SourceProjected.scala', 'SourceProjected.scala')]:
        source = PRODUCTION/source_name
        exact(helper_dir/name, source.read_text())
        copied[str((helper_dir/name).relative_to(sources))] = dict(source=str(source), sha256=sha(source))
    assert sha(helper_dir/'BucketBank.scala') == sha(PRODUCTION/'BucketBankModule.scala')
    assert sha(helper_dir/'SourceProjected.scala') == sha(PRODUCTION/'SourceProjected.scala')

    files = {str(p):sha(p) for p in sorted(sources.rglob('*.scala'))}
    variant = hashlib.sha256(json.dumps(files, sort_keys=True).encode()).hexdigest()
    dependencies = [PRODUCTION/'source-binding.json', COMPLETE/'source-binding.json',
                    STORAGE/'config.json', STORAGE/'replacements.json',
                    D/'build-logs/Opt4-dcache-storage-compose-r2-20261112/source-contract.json']
    binding = dict(schema='ec-private-production-bank-storage-composition/1',
        functional_baseline=BASE, parent_commit=PARENT, source_variant=variant,
        private_sources=True, production_selected=False, production_admission=False,
        source_inverse_to_parent_byte_equal=True,
        caller_namespace_substitution=dict(old=old, new=new),
        bank_byte_equal_to_production_validator=True,
        storage_substitutions=15, copied=copied, files=files,
        dependencies={str(p):sha(p) for p in dependencies},
        geometry=production['geometry'], extra_target_registers=0, extra_target_cycles=0,
        public_outputs=52, proof_ports_added=False,
        all_parent_non_address_sources_retained=True,
        scope='Compile-only preparation of complete source composition. Does not establish target/host parity, area saving, whole EC equivalence, or FIT.')
    exact(C/'source-binding.json', json.dumps(binding, indent=2, sort_keys=True)+'\n')
    compile_config = dict(java=cfg['java'], compiler=cfg['compiler'], plugin=cfg['plugin'],
        classpath=cfg['classpath'], firechip=cfg['firechip'],
        source_parent=cfg['source_parent'], frozen_parameters=cfg['frozen_parameters'],
        compile_sources=sorted(files), cpus=[218,219], memory_limit_gib=64)
    exact(C/'config.json', json.dumps(compile_config, indent=2, sort_keys=True)+'\n')
    return binding


if __name__ == '__main__':
    result = prepare()
    print(json.dumps({k:result[k] for k in ['source_variant', 'source_inverse_to_parent_byte_equal',
        'bank_byte_equal_to_production_validator', 'geometry', 'production_selected']}))
