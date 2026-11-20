#!/usr/bin/python3
"""Independent exact-target MCRams host generation, never a CAD/runtime admission."""
import importlib.util
import os
from pathlib import Path
import re
import resource

C = Path(__file__).resolve().parent
W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
helper = W / 'routes/cycleprecise-r2-20261111/run.py'
spec = importlib.util.spec_from_file_location('route_helpers', helper)
m = importlib.util.module_from_spec(spec)
spec.loader.exec_module(m)
m.L = D / 'build-logs/Opt4-dcache-memmodel-host-round41-v1-20261111'
m.S = D / 'Opt4-dcache-memmodel-host-round41-v1-state.json'
BASE = '8491167d84b6d9521b151a743673c1516926a1f8'


def policy():
    p = m.read(D / 'unattended-opt4/campaign-policy.json')
    assert p['functional_baseline_commit'] == BASE
    assert p['native_paused'] and p['area_equivalence_only']
    assert not p['fpga_access'] and not p['functional_extensions_allowed']


def main():
    policy()
    m.L.mkdir(parents=True, exist_ok=True)
    lock = (m.L / 'instance.lock').open('a')
    m.fcntl.flock(lock, m.fcntl.LOCK_EX | m.fcntl.LOCK_NB)
    if (m.L / 'result.json').exists():
        assert m.read(m.L / 'result.json')['status'] == 'HOST_GENERATED_EXACT_TARGET_FOUR_OWNER_MCRAMS_NOT_PARITY_AREA_OR_FIT_ADMITTED'
        return
    os.sched_setaffinity(0, sorted(os.sched_getaffinity(0))[:2])
    resource.setrlimit(resource.RLIMIT_AS, (64*2**30, 64*2**30))
    plan = m.read(C / 'plan.json')
    assert all(m.sha(p) == h for p, h in plan['inputs'].items())
    assert all(m.sha(p) == h for p, h in plan['external_tool_inputs'].items())
    prep = m.read(C / 'evidence/preparation.json')
    assert prep['functional_baseline'] == BASE and prep['derived_hardware_commit'] == plan['derived_hardware_commit']
    assert prep['status'] == 'PASS_EXACT_TARGET_FOUR_MEMORY_ANNOTATIONS_RESOLVED_NOT_TRANSFORMED_OR_ADMITTED'
    assert prep['added_annotations'] == 4 and prep['preserved_memory_annotations'] == 10
    assert prep['negative_cases_rejected'] == 4 and prep['generation_read_ports'] == 518
    area = m.read(C / 'evidence/corrected-area.json')
    assert area['status'] == 'CORRECTED_AREA_COMPLETE_NOT_FULL_DCACHE_OR_OPT4_FIT'
    resources = {k: {n: v['used'] for n, v in result['resources'].items()} for k, result in area['results'].items()}
    saving = resources['PlainConfig']['CLB LUTs'] - resources['MCConfig']['CLB LUTs']
    assert resources['PlainConfig']['CLB LUTs'] == 405706 and resources['MCConfig']['CLB LUTs'] == 24192
    assert saving == 381514 and resources['MCConfig']['Block RAM Tile'] == 1.5
    boundary = m.read(C / 'evidence/finite-entry-parity.json')
    assert boundary['status'] == 'PASS_REAL_DCACHE_MEMORY_INTERFACE_SAME_TARGET_GG_PLAIN_AND_MCRAMS_NOT_FULL_DCACHE'
    results = boundary['results']
    assert results['PlainConfig']['metrics']['checked_values'] == results['MCConfig']['metrics']['checked_values'] == 178857
    assert results['PlainConfig']['target_sha256'] == results['MCConfig']['target_sha256']
    assert all(r['negative_rejected'] for r in results.values())
    raw = Path(plan['target_fir'])
    anno = C / 'four-owner-memories.anno.json'
    assert m.sha(raw) == prep['target_fir_sha256'] and m.sha(anno) == prep['annotated_json_sha256']
    cfg = m.read(plan['config'])
    m.ST.update(schema='ec-opt4-four-owner-memory-mcrams-host/1', **m.ident(os.getpid()), started_utc=m.now(),
        functional_baseline=BASE, derived_hardware_commit=plan['derived_hardware_commit'], source_id=prep['source_id'],
        host_input_id=plan['host_input_id'], fpga_access=False, target_function_changed=False,
        production_admission=False, full_dut_equivalence=False, whole_synthesis=False,
        cpus=sorted(os.sched_getaffinity(0)), memory_limit_gib=64, prerequisite_local_area_saving=saving,
        prerequisite_scope=area['scope'], target_fir=str(raw), target_fir_sha256=prep['target_fir_sha256'])
    m.update(status='STARTED')
    out = m.L / 'goldengate'
    out.mkdir(exist_ok=True)
    java = [cfg['java'], '-Xmx40G', '-Xss8M', '-XX:ActiveProcessorCount=2', '-Dec.dac.firesim=true', '-cp', ':'.join(cfg['classpath'])]
    policy()
    m.stage('goldengate', java + ['midas.stage.GoldenGateMain', '-i', str(raw), '-td', str(out), '-faf', str(anno),
        '-ggcp', 'firesim.configs', '-ggcs', 'MCRams_DacXilinxAlveoConfig', '--output-filename-base', 'FireSim-generated', '--no-dedup'],
        C, [out / 'FireSim-generated.sv', out / 'FireSim-generated.const.h', out / 'post-bridge-extraction.fir'], timeout=14400)
    # Check the unchanged target-side four DefMemory interfaces before claiming
    # even compiler completion. All512 observation readers remain represented.
    text = (out / 'post-bridge-extraction.fir').read_text()
    memories = {}
    expected = dict(ownerImageMemory_flattened=(81,35), ownerGenerationMemory=(32,518), ownerPacketMemory=(32,4), ownerTrackedMemory=(1,4))
    for name, (width, readers) in expected.items():
        match = re.search(r'^    mem ' + name + r' :\n((?:      .*\n)+)', text, re.M)
        assert match, ('original memory missing before host extraction', name)
        block = match.group(1)
        assert re.search(r'^      data-type => UInt<' + str(width) + '>$', block, re.M)
        assert re.search(r'^      depth => 512$', block, re.M)
        assert re.search(r'^      read-latency => 0$', block, re.M)
        assert re.search(r'^      write-latency => 1$', block, re.M)
        assert re.search(r'^      read-under-write => undefined$', block, re.M)
        assert len(re.findall(r'^      reader => ', block, re.M)) == readers
        assert len(re.findall(r'^      writer => ', block, re.M)) == 1
        memories[name] = dict(width=width, depth=512, readers=readers, writers=1,
                              block_sha256=m.hashlib.sha256(match.group(0).encode()).hexdigest())
    m.save(m.L / 'emitted-target-memory-interfaces.json', memories)
    sv = out / 'FireSim-generated.sv'
    if not (out / 'blackboxes-appended.json').exists():
        files = out / 'firrtl_black_box_resource_files.f'
        with sv.open('a') as f:
            for name in files.read_text().splitlines() if files.exists() else []:
                if name.strip():
                    f.write(Path(name).read_text())
        m.save(out / 'blackboxes-appended.json', dict(sha256=m.sha(sv)))
    assert m.sha(raw) == prep['target_fir_sha256']
    m.update(status='HOST_GENERATED_EXACT_TARGET_FOUR_OWNER_MCRAMS_NOT_PARITY_AREA_OR_FIT_ADMITTED',
        host_rtl=str(sv), host_rtl_sha256=m.sha(sv), all_generation_observation_readers_preserved=518,
        next='Authenticate emitted ABI/blackbox closure, compare complete module target cycles and all original observations, then measure real full-module area. Preserve all live full-application jobs. No whole CAD or FPGA admission from host generation.')
    m.save(m.L / 'result.json', m.ST)


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        if m.L.exists():
            m.update(status='FAILED_WITH_EVIDENCE', error=repr(exc))
            m.save(m.L / 'failure.json', m.ST)
        raise
