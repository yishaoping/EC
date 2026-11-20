#!/usr/bin/python3
"""Source-bound packed/field-bank induction and actual changed-source compile.
No whole CAD or FPGA admission. Generated full-DCache proof/map still required.
"""
from pathlib import Path
import datetime, fcntl, hashlib, importlib.util, json, os, subprocess, time

W = Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
C = Path(__file__).resolve().parent
O = D / 'build-logs/Opt4-fit-dcache-owner-fieldbanks-r1-20261111'
S = D / 'Opt4-fit-dcache-owner-fieldbanks-r1-state.json'
REL = 'chipyard/generators/boom/src/main/scala/lsu/dcache.scala'


def read(p):
    return json.loads(Path(p).read_text())


def sha(p):
    return hashlib.sha256(Path(p).read_bytes()).hexdigest()


def now():
    return datetime.datetime.now(datetime.timezone.utc).isoformat()


def save(p, j):
    p = Path(p)
    q = p.with_name(p.name + '.tmp-' + str(os.getpid()))
    with q.open('w') as f:
        json.dump(j, f, indent=2, sort_keys=True)
        f.write('\n')
        f.flush()
        os.fsync(f.fileno())
    os.replace(q, p)


def ident(pid):
    try:
        t = Path(f'/proc/{pid}/stat').read_text().rsplit(')', 1)[1].split()
        return dict(pid=pid, start_ticks=t[19], process_state=t[0],
                    host_boot_id=Path('/proc/sys/kernel/random/boot_id').read_text().strip())
    except FileNotFoundError:
        return {}


def main():
    O.mkdir(exist_ok=True)
    lock = (O / 'instance.lock').open('a')
    fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
    cfg = read(C / 'config.json')
    b = cfg['binding']
    F = Path(cfg['worktree'])
    assert subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=F, text=True).strip() == b['hardware_commit']
    assert set(subprocess.check_output(['git', 'diff', '--name-only', b['parent_commit'], b['hardware_commit']], cwd=F, text=True).splitlines()) == {REL, 'lineage.json'}
    src = (F / REL).read_text()
    reverse = src
    pairs = read(C / 'reverse-substitutions.json')
    for new, old in reversed(pairs):
        assert reverse.count(new) == 1
        reverse = reverse.replace(new, old)
    assert reverse == subprocess.check_output(['git', 'show', b['parent_commit'] + ':' + REL], cwd=F, text=True)
    assert (F / REL).read_bytes() == subprocess.check_output(['git', 'show', b['hardware_commit'] + ':' + REL], cwd=F)
    inventory_spec = importlib.util.spec_from_file_location('fieldbank_inventory', W / 'scripts/build_hw.py')
    inventory_mod = importlib.util.module_from_spec(inventory_spec)
    inventory_spec.loader.exec_module(inventory_mod)
    assert hashlib.sha256(json.dumps(inventory_mod.inventory(F / 'chipyard'), sort_keys=True).encode()).hexdigest() == b['source_id']
    st = dict(schema='ec-opt4-owner-fieldbank-source-validation/1', **ident(os.getpid()),
              hardware_commit=b['hardware_commit'], source_id=b['source_id'],
              parent_commit=b['parent_commit'], functional_baseline_commit=b['frozen_commit'],
              status='SOURCE_REVERSAL_PASS_VALIDATING', started_utc=now(), stages={},
              exact_parent_reversal=True, fpga_access=False, production_admission=False,
              complete_dcache_formal=False, whole_dut_formal=False, resources=None,
              proof_scope='Only packed146 = image81/generation32/packetSeq32/tracked1 storage relation, unchanged single-edge writes/resetmask and asynchronous reads. Not actual generated fullDCache/formal/area. Inherit parent proofs within their explicit scopes.')

    def update(**kw):
        st.update(kw)
        st['updated_utc'] = now()
        save(S, st)

    update()
    env = {**os.environ, 'LD_LIBRARY_PATH': '', 'JAVA_TOOL_OPTIONS': '', 'CCACHE_DISABLE': '1', 'OMP_NUM_THREADS': '4'}

    def run(name, argv, negative=False):
        log = O / (name + '.log')
        assert not log.exists(), 'preserve failed/incomplete evidence; use new recovery version'
        with log.open('xb', buffering=0) as f:
            child = subprocess.Popen(list(map(str, argv)), cwd=O, env=env,
                                     stdin=subprocess.DEVNULL, stdout=f, stderr=subprocess.STDOUT)
            update(status='RUNNING_' + name.upper(), active_stage=name, child=ident(child.pid))
            while child.poll() is None:
                try:
                    child.wait(timeout=30)
                except subprocess.TimeoutExpired:
                    pass
                update()
                os.fsync(f.fileno())
        text = log.read_text(errors='replace')
        accepted = child.returncode != 0 and 'proof did fail' in text and 'TIMEOUT' not in text if negative else child.returncode == 0
        st['stages'][name] = dict(returncode=child.returncode, accepted=accepted, log=str(log), sha256=sha(log))
        update(child={})
        assert accepted, (name, child.returncode, str(log))
        return text

    # Arbitrary related raw state of a selected word. Same proof lifts to each
    # of512 words because source-bound read/write indices and guards are equal.
    v = O / 'PackedFieldTransition.v'
    v.write_text('''module PackedFieldTransition(
input reset, written, write_enable, selected,
input [145:0] previous_raw, write_data,
output equivalent, mutation_equivalent);
wire write = write_enable && !reset && selected;
wire mask_next = !reset && (written || write);
wire [145:0] packed_next = write ? write_data : previous_raw;
wire [80:0] image_next = write ? write_data[145:65] : previous_raw[145:65];
wire [31:0] generation_next = write ? write_data[64:33] : previous_raw[64:33];
wire [31:0] packet_next = write ? write_data[32:1] : previous_raw[32:1];
wire tracked_next = write ? write_data[0] : previous_raw[0];
wire [145:0] field_next = {image_next,generation_next,packet_next,tracked_next};
wire [145:0] packed_observed = mask_next ? packed_next : 146'h0;
wire [145:0] field_observed = mask_next ? field_next : 146'h0;
// Real candidate field-data corruption, with no change to proof predicate.
wire [145:0] mutated_field_next = {image_next,generation_next,packet_next,write ? !write_data[0] : previous_raw[0]};
assign equivalent = packed_observed == field_observed;
assign mutation_equivalent = packed_observed == (mask_next ? mutated_field_next : 146'h0);
endmodule
''')
    for name, target, negative in [('sat-field-transition', 'equivalent', False), ('sat-field-negative', 'mutation_equivalent', True)]:
        ys = O / (name + '.ys')
        ys.write_text(f'read_verilog {v}\nprep -top PackedFieldTransition\nsat -verify -timeout 60 -prove {target} 1 -show-inputs\n')
        text = run(name, ['/usr/local/bin/yosys', '-s', ys], negative)
        if not negative:
            assert 'SUCCESS' in text
    classes = O / 'classes'
    classes.mkdir()
    sources = [F / p for p in b['changed_files']]
    run('compile-all-changed-sources', [cfg['java'], '-Xmx24G', '-Xss8M', '-XX:ActiveProcessorCount=4',
        '-cp', ':'.join(cfg['compiler']), 'scala.tools.nsc.Main', '-classpath', ':'.join(cfg['classpath']),
        '-Xplugin:' + cfg['plugin'], '-d', classes, *sources])
    assert (classes / 'boom/lsu/BoomNonBlockingDCacheModule.class').is_file()
    params = O / 'parameters.json'
    run('frozen-parameters', [cfg['java'], '-Xmx12G', '-Xss8M', '-XX:ActiveProcessorCount=4',
        '-Dec.dac.firesim=true', '-cp', str(classes) + ':' + cfg['firechip'] + ':' + ':'.join(cfg['classpath']),
        'firesim.firesim.DacParameterAudit', 'firesim.firesim.DacOpt4C4', params])
    assert read(params) == read(cfg['frozen_parameters'])
    update(status='PASS_SOURCE_BOUND_FIELD_STORAGE_RELATION_TYPECHECK_FROZEN_PARAMETERS_NOT_GENERATED_OR_AREA_ADMITTED',
           ended_utc=now(), field_widths=[81, 32, 32, 1], unchanged_read_expressions=50,
           actual_field_write_mutation_rejected=True, frozen_parameters_match=True,
           source_sha256=sha(F / REL), miter_sha256=sha(v), child={})
    save(O / 'result.json', st)


if __name__ == '__main__':
    try:
        main()
    except Exception as exc:
        if S.exists():
            st = read(S)
            if st.get('pid') == os.getpid():
                st.update(status='FAILED_WITH_EVIDENCE', error=repr(exc), ended_utc=now())
                save(S, st)
        raise
