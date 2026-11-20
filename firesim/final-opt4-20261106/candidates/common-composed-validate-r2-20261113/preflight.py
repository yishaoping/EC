#!/usr/bin/python3
"""Offline gate rejection and actual reused-class linkage checks; no elaboration.

Future-result fixtures below are deliberately synthetic and never written as
validation, area, or prerequisite receipts. They exercise launch-gate rejection.
"""
from pathlib import Path
import copy
import importlib.util
import json
import subprocess
import symtable
import builtins

C = Path(__file__).resolve().parent
spec = importlib.util.spec_from_file_location('offline_composition_gate', C/'controller.py')
m = importlib.util.module_from_spec(spec); spec.loader.exec_module(m)
binding, inventory = m.verify_binding()
table = symtable.symtable((C/'controller.py').read_text(), str(C/'controller.py'), 'exec')
for function in table.get_children():
    missing = [symbol.get_name() for symbol in function.get_symbols()
        if symbol.is_referenced() and symbol.is_global()
        and symbol.get_name() not in vars(m) and not hasattr(builtins, symbol.get_name())]
    assert not missing, (function.get_name(), missing)

dcache = m.read(m.DCACHE/'result.json')
caller = dict(status='PASS_COMPLETE_ADDRESS_CALLER_8_16_32_FINITE_ALL_STATE_AND_ABI_NOT_HOST_AREA',
    functional_baseline=m.m.BASE, hardware_commit='5a4ec16e4bbd2d6c03e4a5fe8c8965d8aad5af2a',
    validated={str(lanes): dict(cycles=6144, outputs=5684, public_outputs=52, invalid_payload_words=5120,
        before_and_after_edge=True, negative_invalid_payload_rejected=True, oracle_inverse_byte_equal=True)
        for lanes in [8, 16, 32]})
mixed = dict(status='COMPLETE_MIXED_ROLE_HOST_TOKENS_AND_AREA_PAIR_NOT_WHOLE_EC',
    functional_baseline=m.m.BASE, hardware_commit='f4709ea246da55afe4b94c2533247744d90a68f7',
    experiment_commit='a8ec2fd3df371498630b5931023584ca0106f2ae',
    tokens={name: dict(digest='offline-fixture', target_tokens=3003, checked_outputs=219000)
        for name in ['Plain', 'Threaded']}, savings={'CLB LUTs': 300000},
    area={'Plain': dict(resources={'CLB LUTs': 800000}), 'Threaded': dict(resources={'CLB LUTs': 500000})})
assert m.material_gate(mixed, caller, dcache)
rejected = []

def reject(name, change):
    a, b, c = copy.deepcopy((mixed, caller, dcache))
    change(a, b, c)
    try: allowed = m.material_gate(a, b, c)
    except (AssertionError, KeyError): allowed = False
    assert not allowed, name
    rejected.append(name)

reject('unmeasured-area', lambda a,b,c: a.pop('area'))
reject('forged-saving', lambda a,b,c: a['savings'].update({'CLB LUTs': 400000}))
reject('small-actual-gain', lambda a,b,c: (a['area']['Threaded']['resources'].update({'CLB LUTs': 500001}),
    a['savings'].update({'CLB LUTs': 299999})))
reject('partial-tokens', lambda a,b,c: a['tokens']['Threaded'].update(target_tokens=3002))
reject('dropped-public-output', lambda a,b,c: a['tokens']['Plain'].update(checked_outputs=216000))
reject('mismatched-feedback', lambda a,b,c: a['tokens']['Plain'].update(digest='wrong'))
reject('partial-geometry', lambda a,b,c: b['validated'].pop('32'))
reject('invalid-payload-negative-missing', lambda a,b,c: b['validated']['16'].update(negative_invalid_payload_rejected=False))
reject('target-edge-check-missing', lambda a,b,c: b['validated']['8'].update(before_and_after_edge=False))
reject('dcache-area-regression', lambda a,b,c: c.update(module_lut_saved=-1))
reject('dcache-observation-dropped', lambda a,b,c: c.update(observations=24574))
reject('wrong-source', lambda a,b,c: a.update(hardware_commit='wrong'))
reject('wrong-baseline', lambda a,b,c: c.update(functional_baseline='wrong'))

cfg = m.read(C/'config.json')
classes = m.D/'build-logs/Opt4-common-composed-source-r1-20261113/classes'
argv = [cfg['java'], '-Xmx4G', '-Xss32M', '-XX:ActiveProcessorCount=2',
    '-cp', inventory['classpath'], 'eccommoncomposition.CheckComposition', str(classes)]
result = subprocess.run(argv, capture_output=True, text=True, timeout=45, check=True)
assert 'COMMON_COMPOSITION_LINKAGE_PASS classes=9 constructors=3 no_elaboration=true' in result.stdout
negative = subprocess.run(argv[:-1]+[str(C)], capture_output=True, text=True, timeout=45)
assert negative.returncode != 0 and 'Wrong class origin' in negative.stderr
report = dict(schema='ec-common-composition-offline-launch-gate-preflight/1', utc=m.now(),
    hardware_commit=binding['hardware_commit'], source_binding_sha256=m.sha(C/'source-binding.json'),
    synthetic_future_gate_fixtures_only=True, fixture_rejections=rejected,
    actual_reused_class_files=len(inventory['files']), actual_class_origins_checked=9,
    actual_constructors_checked=3, wrong_class_origin_rejected=True,
    actual_linkage_stdout=result.stdout, linkage_argv=argv,
    no_elaboration=True, no_CAD=True, no_FPGA_IO=True, no_target_or_host_validation_claim=True)
out = m.D/'status-audits/full-ec-structural-priority-20261112/round179-common-composed-validation'
out.mkdir(exist_ok=True)
m.save(out/'offline-preflight.json', report)
print(json.dumps({key: value for key, value in report.items()
    if key not in ['linkage_argv', 'actual_linkage_stdout']}, indent=2))
