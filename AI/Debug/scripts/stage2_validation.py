#!/usr/bin/env python3
"""Stage 2: all runs build -> directed -> system; offline is an explicit option."""
import argparse
import ast
import contextlib
from collections import Counter
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys
import tempfile
import traceback

REPO = Path(__file__).resolve().parents[3]
SCRIPTS = REPO / 'AI/Debug/scripts'
PHASES = ('build', 'directed', 'system')
OPTIONS = ('offline',) + PHASES
MODULE_JVM_ARGS = ('-J-Xms512M', '-J-Xmx8G', '-J-Xss8M', '-J-XX:+ExitOnOutOfMemoryError',
                   '-J-Dsbt.supershell=false')
MODULE_ERROR_LIMIT = '0'  # Verilator: collect all errors within this invocation.
CASES = (
    'safe_predecessor_backpressure_delayed_stale_ack', 'same_package_repeat',
    'cross_package_wait_safe_then_receipt', 'normal_amo_sc_success_failure',
    'cross_package_amo_sc_invalidation_refill', 'speculative_refill_replay_gate',
    'continuous_replacement_refill_seq0_terminal_backpressure', 'real_sourced_commit_before_ack',
    'denied_a_put_preserves_image', 'denied_a_amo_preserves_image')
PHASE_ZH = dict(offline='离线检查', build='编译/硬件生成', directed='定向仿真', system='整机仿真')
STATUS_ZH = dict(PASS='通过', FAIL='失败', UNCOVERED='覆盖不足', NOT_RUN='未运行', RUNNING='运行中/已中断')
BUILD_ENV = ('PATH', 'LD_LIBRARY_PATH', 'VERILATOR_ROOT', 'RISCV', 'JAVA_HOME',
             'JAVA_TOOL_OPTIONS', 'SBT_OPTS', 'SBT_BIN', 'ENABLE_SBT_THIN_CLIENT',
             'MAKEFLAGS', 'CXX', 'CC', 'CFLAGS', 'CXXFLAGS', 'LDFLAGS',
             'FIRTOOL', 'FIRTOOL_PATH', 'JAVA_HEAP_SIZE', 'STAGE1_WAVEFORM')


class Stop(Exception):
    def __init__(self, reason, code=1, *, log=None, first_error=None, raw_code=None, uncovered=False,
                 diagnostics=None):
        super().__init__(reason)
        self.code = code
        self.log = str(log) if log else None
        self.first_error = first_error
        self.raw_code = raw_code
        self.uncovered = uncovered
        self.diagnostics = diagnostics


def process_code(raw_code):
    return raw_code if raw_code >= 0 else 128 - raw_code


def clean_terminal(text):
    # sbt colors prefixes and emits erase-line CSI sequences on task completion.
    return re.sub(r'\x1b\[[0-?]*[ -/]*[@-~]', '', text)


def error_entries(path):
    # Keep every distinct diagnostic, with its original line number/context.
    # sbt repeats exceptions in the task summary and prefixes stack frames
    # with [error]; neither repetition should hide separate useful errors.
    raw_lines = Path(path).read_text(errors='replace').splitlines()
    lines = [clean_terminal(line) for line in raw_lines]
    pattern = r'\[error\]|%Error|fatal error:|\berror:|Assertion.*failed|Assertion failed|=FAIL\b|Traceback|Error [1-9]|OutOfMemoryError|StackOverflowError|Exception in thread|Cannot allocate memory|STAGE2_WIRING_ERROR|STAGE2_CHECK_FAIL'
    entries, seen = [], {}
    for i, line in enumerate(lines):
        if not re.search(pattern, line, re.I):
            continue
        message = re.sub(r'^\s*\[error\]\s*', '', line).strip()
        if not message or re.match(r'^(?:at\s|\.\.\.\s*\d+\s+more|Total time:|\^+$)', message):
            continue
        # A forked JVM writes this informational banner to stderr; sbt labels
        # every stderr line [error]. It is not a compiler/JVM failure.
        if re.match(r'^(?:NOTE: )?Picked up (?:JAVA_TOOL_OPTIONS|_JAVA_OPTIONS|JDK_JAVA_OPTIONS):', message):
            continue
        if message in seen:
            seen[message]['occurrences'] += 1
            continue
        context = []
        raw_context = []
        for j, following in enumerate(lines[i+1:i+5], start=i+1):
            rest = re.sub(r'^\s*\[error\]\s*', '', following).strip()
            if not rest or re.search(pattern, rest, re.I) or re.match(r'^at\s|^\[\w+\]',rest):
                break
            context.append(following)
            raw_context.append(raw_lines[j])
        entry = dict(line=i+1, message=line, raw_message=raw_lines[i], context=context,
                     raw_context=raw_context, occurrences=1)
        entries.append(entry)
        seen[message] = entry
    return entries


def first_error(path):
    entries = error_entries(path)
    if entries:
        # PassExceptions is an aggregate, not the failing signal. Show the
        # first concrete initialization/type/loop diagnostic in the summary;
        # the complete report still retains every entry in its original order.
        if re.search(r'firrtl\.passes\.PassExceptions:', entries[0]['message']):
            detail = next((e for e in entries[1:] if re.search(
                r'firrtl\.[\w.$]+(?:Exception|Error):', e['message']) and
                'firrtl.passes.PassException:' not in e['message']), None)
            if detail:
                return detail['message']
        # FIRRTL's generic wrapper hides the useful cause much later in the
        # same stack. Keep every entry in order, but show that cause in summary.
        if 'firrtl.FirrtlInternalException: Internal Error' in entries[0]['message']:
            cause = next((e for e in reversed(entries) if 'Caused by:' in e['message']), None)
            if cause:
                return cause['message']
        return entries[0]['message']
    lines = Path(path).read_text(errors='replace').splitlines()
    return next((clean_terminal(line) for line in reversed(lines) if line.strip()), '日志为空')


def system_wiring_diagnostics(root):
    # Read the exact FINAL_ANNO_FILE consumed by this run's system FIRRTL step.
    # Never merge duplicate intermediate annotation files or run a transform.
    annotation = root/'system.build/generated-src/chipyard.TestHarness.v1Config/chipyard.TestHarness.v1Config.appended.anno.json'
    report = dict(annotation=str(annotation), status='UNAVAILABLE', errors=[], pins=0)
    if annotation.is_file():
        try:
            report['annotation_sha256'] = sha(annotation)
            annotations = read(annotation)
            if not isinstance(annotations, list):
                raise ValueError('annotation root must be a list')
            sources, sinks = {}, {}
            for item in annotations:
                if not isinstance(item, dict):
                    raise ValueError('annotation entry must be an object')
                kind = item.get('class')
                if kind not in ('firrtl.passes.wiring.SourceAnnotation', 'firrtl.passes.wiring.SinkAnnotation'):
                    continue
                pin, target = item.get('pin'), item.get('target')
                if not isinstance(pin, str) or not isinstance(target, str):
                    raise ValueError('wiring pin and target must be strings')
                group = sources if kind.endswith('SourceAnnotation') else sinks
                group.setdefault(pin, []).append(target)
            pins = sorted(sources.keys() | sinks.keys())
            report['pins'] = len(pins)
            report['errors'] = [dict(pin=pin, sources=sources.get(pin, []), sinks=sinks.get(pin, []))
                                for pin in pins if len(sources.get(pin, [])) != 1 or not sinks.get(pin)]
            report['status'] = 'INVALID_COUNTS' if report['errors'] else 'COUNTS_ONLY' if pins else 'NO_WIRING'
        except (OSError, ValueError) as error:
            report['status'] = 'READ_ERROR'
            report['reason'] = str(error)
    json_path, text_path = root/'system.wiring.json', root/'system.wiring.out'
    save(json_path, report)
    lines = [f"整机 annotation 连线清单：{report['status']}，pins={report['pins']}，异常={len(report['errors'])}；仅检查数量，不代表硬件通过。",
             '本次输入：'+str(annotation)]
    if report.get('reason'):
        lines.append('读取失败：'+report['reason'])
    for error in report['errors']:
        lines.append(f"  pin={error['pin']} sources={len(error['sources'])} sinks={len(error['sinks'])} " +
                     f"source={';'.join(error['sources'])} sink={';'.join(error['sinks'])}")
    text_path.write_text('\n'.join(lines)+'\n')
    return dict(status=report['status'], count=len(report['errors']), json=str(json_path),
                text=str(text_path)), lines


def failure_diagnostics(path, raw_code):
    path = Path(path).resolve()
    entries = error_entries(path)
    report = dict(log=str(path), raw_exit_code=raw_code, log_sha256=sha(path),
                  error_count=len(entries), errors=entries)
    wiring, wiring_lines = None, []
    if path.name == 'system.build.wrapper.log':
        wiring, wiring_lines = system_wiring_diagnostics(path.parent)
        report['wiring'] = wiring
    json_path = path.with_name(path.name+'.errors.json')
    text_path = path.with_name(path.name+'.errors.out')
    save(json_path, report)
    lines = [f'日志中发现 {len(entries)} 条不同的错误/失败诊断；后续阶段停止。', '原始日志：'+str(path)]
    for entry in entries:
        lines.append(f"  L{entry['line']}: {entry['message']}")
        lines.extend('    '+line for line in entry['context'])
    if not entries:
        lines.append('未识别到结构化错误，日志末尾：'+first_error(path))
    lines.extend(wiring_lines)
    if wiring:
        lines.append('整机连线完整清单：'+wiring['text'])
    text_path.write_text('\n'.join(lines)+'\n')
    print('\n'.join(lines), flush=True)
    print('完整错误汇总：'+str(text_path), flush=True)
    result = dict(count=len(entries), json=str(json_path), text=str(text_path))
    if wiring:
        result['wiring'] = wiring
    return result


class Tee:
    def __init__(self, terminal, log):
        self.terminal, self.log = terminal, log

    def write(self, text):
        self.terminal.write(text)
        self.log.write(text)
        self.flush()
        return len(text)

    def flush(self):
        self.terminal.flush()
        self.log.flush()


def sha(path):
    h = hashlib.sha256()
    with Path(path).open('rb') as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b''):
            h.update(block)
    return h.hexdigest()


def save(path, value):
    path.write_text(json.dumps(value, indent=2, sort_keys=True) + '\n')


def read(path):
    return json.loads(path.read_text())


def tool(name):
    resolved = shutil.which(str(name))
    if not resolved:
        raise Stop('missing executable: ' + str(name), 2)
    path = Path(resolved).resolve()
    return dict(path=str(path), sha256=sha(path))


def inputs():
    from stage1_provenance import source_record
    from stage1_workload import verify
    # No arbitrary build/run overrides: the phase runner owns paths and flags.
    for name in os.environ:
        if name.startswith('STAGE1_') and name not in ('STAGE1_WORKLOAD', 'STAGE1_WAVEFORM'):
            raise Stop('unsupported inherited override: ' + name, 2)
    workload = Path(os.environ.get('STAGE1_WORKLOAD', REPO/'AI/TMP/stage1_workload.json')).resolve()
    verified = verify(workload)  # read/hash only, no objdump, compiler or simulator
    scripts = sorted(p for p in SCRIPTS.rglob('*') if p.is_file() and
                     (p.name.startswith(('stage1_', 'stage2_', 'test_stage1_', 'test_stage2_')) or
                      p.parent == SCRIPTS/'stage2') and p.suffix in ('.py', '.sh', '.scala', '.cpp'))
    java_dir = Path(os.environ.get('STAGE2_JAVA_HOME', REPO/'chipyard/.conda-env/lib/jvm')).resolve()
    tools = {name: tool(value) for name, value in {
        'sbt': os.environ.get('STAGE2_SBT', REPO/'chipyard/.conda-env/bin/sbt'),
        'java_module': java_dir/'bin/java', 'java_system': 'java',
        'verilator': os.environ.get('STAGE2_VERILATOR', 'verilator'),
        'make': 'make', 'g++': 'g++', 'python': sys.executable}.items()}
    # Stage 1's existing Makefile uses PATH's verilator. Record that too.
    tools['verilator_system'] = tool('verilator')
    if shutil.which('firtool'):
        tools['firtool'] = tool('firtool')
    return dict(schema=3, head=subprocess.check_output(['git','-C',str(REPO),'rev-parse','HEAD'], text=True).strip(),
                source=source_record(REPO/'chipyard'),
                scripts={str(p.relative_to(REPO)): sha(p) for p in scripts}, tools=tools,
                java_dir=str(java_dir), workload=str(workload), workload_sha256=sha(workload),
                workload_inputs={k: verified[k+'_sha256'] for k in ('benchmark','loadmem','dump')},
                environment={k: os.environ.get(k) for k in BUILD_ENV},
                build_overrides={k:v for k,v in os.environ.items() if
                    re.match(r'^(STAGE[12]_(?!ROOT$)|VERILATOR|FIR|SBT|JAVA|MAKE|EXTRA|ENABLE|CONFIG|MODEL|GENERATOR)',k)},
                # Make accepts environment variables beyond its documented
                # options. Bind them too, without recording secret values.
                environment_hashes={k:hashlib.sha256(v.encode()).hexdigest() for k,v in os.environ.items()
                    if k not in ('STAGE2_ROOT','PWD','OLDPWD','SHLVL','_')},
                riscv=os.environ.get('RISCV', str(REPO/'chipyard/.conda-env/riscv-tools')),
                build=dict(config='v1Config', module_top='Stage2Harness', fst=1,
                           sim_cxxflags='-DSTAGE1_EXIT_PORTS', module_assert=True, lint_pin_missing=True,
                           module_cxxflags='-std=c++17', lint_error='UNOPTFLAT',
                           module_jvm_args=list(MODULE_JVM_ARGS), module_error_limit=MODULE_ERROR_LIMIT,
                           module_wiring_audit=True))


def require_inputs(root):
    if not (root/'inputs.json').is_file():
        raise Stop('input snapshot missing; start a new all/build root')
    current = inputs()
    saved = read(root/'inputs.json')
    if saved != current:
        changed = [key for key in current if saved.get(key) != current[key]]
        raise Stop('inputs changed ('+', '.join(changed)+'); start a new all/build root')
    if not (root/'fixture').is_dir():
        raise Stop('copied fixture missing; start a new all/build root')
    expected={Path(name).name:digest for name,digest in saved['scripts'].items()
              if name.startswith('AI/Debug/scripts/stage2/')}
    actual={p.name:sha(p) for p in (root/'fixture').iterdir() if p.is_file()}
    if expected != actual:
        raise Stop('copied fixture changed; start a new all/build root')
    return current


def command(root, log, argv, *, cwd=REPO, env=None):
    with (root/'commands.jsonl').open('a') as stream:
        stream.write(json.dumps(dict(log=log, cwd=str(cwd), argv=[str(x) for x in argv]))+'\n')
    print('LOG=' + str(root/log), flush=True)
    with (root/log).open('w') as out:
        result = subprocess.run([str(x) for x in argv], cwd=cwd, env=env,
                                stdin=subprocess.DEVNULL, stdout=out, stderr=subprocess.STDOUT)
    with (root/'commands.jsonl').open('a') as stream:
        stream.write(json.dumps(dict(log=log, raw_exit_code=result.returncode,
                                    exit_code=process_code(result.returncode)))+'\n')
    if result.returncode:
        # Print ALL distinct errors, not just a tail dominated by stack frames.
        diagnostics=failure_diagnostics(root/log,result.returncode)
        raise Stop(f'命令退出码 {result.returncode}', process_code(result.returncode),
                   log=root/log, first_error=first_error(root/log), raw_code=result.returncode,
                   diagnostics=diagnostics)


def case_report(text, rc=0):
    counts = Counter(re.findall(r'^CASE (\w+) PASS$', text, re.M))
    missing = sorted(set(CASES) - counts.keys())
    unexpected = sorted(counts.keys() - set(CASES))
    duplicate = sorted(k for k,v in counts.items() if v != 1)
    trusted = Counter(re.findall(r'^STAGE2_MSHR opcode=([02]) denied=([01]) ',text,re.M))
    trusted_missing = sorted(set((str(op),str(deny)) for op in (0,2) for deny in (0,1))-trusted.keys())
    trusted_duplicate = sorted(k for k,v in trusted.items() if v != 1)
    directed_failures = re.findall(r'^STAGE2_DIRECTED=FAIL(?: reason=(.*))?$', text, re.M)
    check_failures = re.findall(r'^STAGE2_CHECK_FAIL(?: case=([^ ]+))? reason=(.*)$', text, re.M)
    # Independent stimulus markers bound real production EFFECT trace events.
    # A held terminal alone would miss an early physical write.
    forbidden, effects, event_errors = set(), set(), []
    guard_count = 0
    for line in text.splitlines():
        marker = re.search(r'STAGE2_STIM (FORBID|ALLOW) req=([0-9a-f]+)', line)
        if marker:
            action, req = marker.group(1), int(marker.group(2),16)
            if action == 'FORBID':
                if req in forbidden: event_errors.append('duplicate_forbid')
                forbidden.add(req)
                guard_count += 1
            elif req not in forbidden:
                event_errors.append('allow_without_forbid')
            else: forbidden.remove(req)
        effect = re.search(r'STAGE1_TX EFFECT .*?\breq=([0-9a-f]+)', line)
        if effect:
            req = int(effect.group(1),16)
            if req in forbidden: event_errors.append('effect_before_independent_permission')
            if req in effects: event_errors.append('duplicate_physical_effect')
            effects.add(req)
    if forbidden: event_errors.append('unclosed_effect_guard')
    failed = bool(rc or directed_failures or check_failures or unexpected or duplicate or event_errors or trusted_duplicate)
    complete = bool(re.search(r'^STAGE2_DIRECTED=PASS cycles=\d+$', text, re.M))
    status = 'FAIL' if failed else 'UNCOVERED' if missing or trusted_missing or not complete or guard_count < 4 or not effects else 'PASS'
    return dict(status=status, cases=dict(counts), missing=missing, unexpected=unexpected,
                duplicate=duplicate, simulator_exit_code=rc, effect_guard_count=guard_count,
                physical_effect_count=len(effects), event_errors=event_errors,
                directed_failures=directed_failures,
                check_failures=[dict(case=case, reason=reason) for case, reason in check_failures],
                trusted_a_events={op+':'+deny:n for (op,deny),n in trusted.items()},
                trusted_a_missing=trusted_missing, trusted_a_duplicate=trusted_duplicate)


def directed_failure_summary(report):
    """Return a compact, actionable summary for the terminal on a failed run."""
    details = []
    for failure in report.get('check_failures', []):
        case = failure.get('case') or '<unknown-case>'
        details.append('case='+case+' reason='+failure.get('reason',''))
    details += ['simulator='+reason for reason in report.get('directed_failures', [])]
    if report.get('missing'):
        details.append('未运行/缺失 case='+','.join(report['missing']))
    if report.get('unexpected'):
        details.append('未知 case='+','.join(report['unexpected']))
    if report.get('event_errors'):
        details.append('事件判据='+','.join(report['event_errors']))
    if report.get('trusted_a_missing'):
        details.append('L2 denied/成功事件缺失='+','.join(
            op+':'+denied for op, denied in report['trusted_a_missing']))
    return '; '.join(details) if details else '没有结构化定向诊断'


def offline(root, record):
    for p in SCRIPTS.glob('*.py'):
        if p.name.startswith(('stage1_', 'stage2_', 'test_stage1_', 'test_stage2_')):
            ast.parse(p.read_text(), filename=str(p))
    for name in ('stage2_build_and_run.sh', 'stage1_build_and_run.sh', 'stage1_run_trace.sh'):
        command(root, name+'.syntax.log', ['bash','-n',SCRIPTS/name])
    command(root, 'diff.check.log', ['git','diff','--check'])
    env = dict(os.environ, PYTHONDONTWRITEBYTECODE='1')
    command(root, 'offline.tests.log', [sys.executable,'-B','-m','unittest','-v',
            'test_stage1_trace_scoreboard', 'test_stage1_provenance',
            'test_stage2_trace_scoreboard', 'test_stage2_validation'], cwd=SCRIPTS, env=env)
    # Declaration-only driver syntax: no generated RTL/model, link or execution.
    stub = root/'host-stub'
    stub.mkdir()
    text = (SCRIPTS/'stage2/stage2_test.cpp').read_text()
    fields = sorted(set(re.findall(r'\b(?:t|x\.t)\.(io_\w+|clock|reset)\b', text)))
    (stub/'VStage2Harness.h').write_text('#include <cstdint>\nstruct VStage2Harness {\n'+
        ''.join('uint64_t '+f+'=0;\n' for f in fields)+'void eval(); void final();\n};\n')
    (stub/'verilated.h').write_text('struct Verilated { static void timeInc(int); static bool gotFinish(); static void commandArgs(int,char**); };\n')
    command(root, 'host.syntax.log', [record['tools']['g++']['path'], '-std=c++17',
            '-fsyntax-only','-Wall','-Wextra','-Werror','-I'+str(stub),SCRIPTS/'stage2/stage2_test.cpp'])


def capture_sources(root, record):
    # Required build inputs, independent of the optional offline test suite.
    shutil.copytree(SCRIPTS/'stage2', root/'fixture')
    (root/'source.patch').write_bytes(subprocess.check_output(['git','diff','--','chipyard/generators'],cwd=REPO))
    save(root/'source.before.json', record['source'])


def emitted_rtl(root):
    generated=root/'generated'
    log=root/'module.emit.log'
    text=log.read_text(errors='replace')
    if error_entries(log):
        raise Stop('硬件生成失败：'+first_error(log),log=log,first_error=first_error(log),raw_code=0,
                   diagnostics=failure_diagnostics(log,0))
    rtl=sorted(generated.rglob('*.v'))+sorted(generated.rglob('*.sv'))
    if not rtl or not (generated/'Stage2Harness.v').is_file():
        raise Stop('硬件生成未完成：缺少新生成的 Stage2Harness.v',log=log,first_error=first_error(log),raw_code=0)
    if not re.search(r'^STAGE2_EMIT=PASS top=Stage2Harness$',text,re.M):
        raise Stop('硬件生成未完成：缺少 STAGE2_EMIT 完成标记',log=log,first_error=first_error(log),raw_code=0)
    audit=generated/'stage2.wiring.out'
    if not audit.is_file() or not re.search(r'^STAGE2_WIRING=PASS pins=[1-9]\d* errors=0$',
                                            audit.read_text(errors='replace'),re.M):
        raise Stop('硬件生成未完成：缺少成功的 wiring 审计报告',log=log,first_error=first_error(log),raw_code=0)
    return rtl


def module_artifacts(root):
    extensions = {'.v','.sv','.fir','.json','.h','.cpp','.mk','.f'}
    paths = [p for directory in ('generated','obj') for p in (root/directory).rglob('*')
             if p.is_file() and p.suffix in extensions]
    paths += [root/'obj/VStage2Harness', root/'rtl.f', root/'system.build/provenance.json',
              root/'generated/stage2.wiring.out']
    if not (root/'generated/Stage2Harness.v').is_file() or not paths or any(not p.is_file() for p in paths):
        raise Stop('build products missing')
    return {str(p.relative_to(root)): sha(p) for p in sorted(paths)}


def verify_build(root):
    if read(root/'build.artifacts.json') != module_artifacts(root):
        raise Stop('generated model/binary/build manifest changed since successful build')
    paths = system_paths(root)
    command(root, 'provenance.verify.'+str(len(list(root.glob('provenance.verify.*.log'))))+'.log',
        [sys.executable,SCRIPTS/'stage1_provenance.py','--root',REPO/'chipyard',
         '--sim',paths['sim'],'--generated',paths['generated'],'--manifest',paths['manifest']])


def system_paths(root):
    build = root/'system.build'
    return dict(sim=build/'simulator-chipyard-v1Config-debug',
                generated=build/'generated-src/chipyard.TestHarness.v1Config/chipyard.TestHarness.v1Config.debug',
                manifest=build/'provenance.json')


def build(root, record):
    generated = root/'generated'
    generated.mkdir()
    # New root + compile before runMain; failed compile cannot fall through.
    command(root, 'module.emit.log', [record['tools']['sbt']['path'],'-java-home',record['java_dir'],
        *record['build']['module_jvm_args'],
        'set chipyard / Compile / unmanagedSources += file("'+str(root/'fixture/Stage2Generate.scala')+'")',
        'project chipyard', 'Compile / compile', 'runMain stage2.EmitModule '+str(generated)],
        cwd=REPO/'chipyard', env=dict(os.environ, RISCV=record['riscv']))
    rtl = emitted_rtl(root)
    (root/'rtl.f').write_text(''.join(str(p)+'\n' for p in rtl))
    args = ['--assert','-Wno-fatal','-Werror-UNOPTFLAT','-Werror-PINMISSING',
            '--error-limit',record['build']['module_error_limit'],'--top-module','Stage2Harness','-f',root/'rtl.f']
    command(root,'module.lint.log',[record['tools']['verilator']['path'],'--lint-only',
        '--Mdir',root/'lint',*args],cwd=root)
    command(root,'module.build.log',[record['tools']['verilator']['path'],'--cc','--exe','--build',
        *args,'--Mdir',root/'obj','-CFLAGS','-std=c++17',root/'fixture/stage2_test.cpp'],cwd=root)
    # Reuse Stage 1's exact fresh-build path, explicitly stop before run_trace.
    command(root,'system.build.wrapper.log',['bash',SCRIPTS/'stage1_build_and_run.sh'],
        env=dict(os.environ,STAGE1_BUILD_ONLY='1',STAGE1_SIM_ROOT=str(root/'system.build'),
                 STAGE1_WORKLOAD=record['workload']))
    require_inputs(root)
    save(root/'build.artifacts.json',module_artifacts(root))
    verify_build(root)


def directed(root, record):
    verify_build(root)
    # A failed/partial run is still summarized, never hidden behind build PASS.
    sim_error = None
    try:
        command(root, 'module.trace.log', [root/'obj/VStage2Harness'], cwd=root)
    except Stop as error:
        sim_error = error
    report = case_report((root/'module.trace.log').read_text(errors='replace'),
                         sim_error.raw_code if sim_error else 0)
    save(root/'directed.coverage.json',report)
    print('STAGE2_DIRECTED='+report['status'], flush=True)
    if report['status'] != 'PASS':
        summary = directed_failure_summary(report)+'; coverage='+str(root/'directed.coverage.json')
        if sim_error:
            raise Stop('定向仿真退出码 '+str(sim_error.raw_code if sim_error.raw_code is not None else sim_error.code)+
                       '；'+summary, sim_error.code, log=sim_error.log,
                       first_error=sim_error.first_error, raw_code=sim_error.raw_code,
                       diagnostics=sim_error.diagnostics)
        raise Stop('定向判据 '+report['status']+'；'+summary,
                   3 if report['status']=='UNCOVERED' else 1, log=root/'directed.coverage.json',
                   uncovered=report['status']=='UNCOVERED')
    require_inputs(root)
    save(root/'directed.artifacts.json',{'module.trace.log':sha(root/'module.trace.log'),
                                       'directed.coverage.json':sha(root/'directed.coverage.json')})


def system(root, record):
    verify_build(root)
    for name,digest in read(root/'directed.artifacts.json').items():
        if sha(root/name) != digest:
            raise Stop('directed validation evidence changed: '+name)
    paths=system_paths(root)
    env=dict(os.environ,STAGE1_SIM=str(paths['sim']),STAGE1_GENERATED=str(paths['generated']),
             STAGE1_PROVENANCE=str(paths['manifest']),STAGE1_RUN_ROOT=str(root/'system.run'),
             STAGE1_WORKLOAD=record['workload'])
    # Keep Stage 2 diagnostics on failed/partial system runs, but never return PASS.
    stage1_error=None
    try:
        command(root,'system.run.wrapper.log',['bash',SCRIPTS/'stage1_run_trace.sh'],env=env)
    except Stop as error:
        stage1_error=error
    trace=root/'system.run/trace.log'
    if not trace.is_file():
        if stage1_error:
            raise stage1_error
        raise Stop('整机仿真 NOT_RUN_NO_TRACE', log=root/'system.run.wrapper.log')
    from stage2_trace_scoreboard import analyze
    with trace.open(errors='replace') as stream:
        report=analyze(stream)
    save(root/'system.run/stage2.scoreboard.json',report)
    (root/'system.run/stage2.scoreboard.out').write_text('STAGE2_TRACE='+report['status']+'\n'+json.dumps(report,indent=2)+'\n')
    print('STAGE2_TRACE='+report['status'],flush=True)
    if stage1_error:
        raise stage1_error
    if report['status']!='PASS':
        raise Stop('Stage 2 '+report['status']+': '+json.dumps(report, ensure_ascii=False),
                   3 if report['status']=='UNCOVERED' else 1, log=root/'system.run/stage2.scoreboard.json',
                   uncovered=report['status']=='UNCOVERED')
    require_inputs(root)


def require_previous(root, phase):
    if phase == 'offline':
        return
    for previous in PHASES[:PHASES.index(phase)]:
        path=root/(previous+'.status.json')
        if not path.is_file() or read(path).get('status')!='PASS':
            raise Stop('prerequisite '+previous+' is not PASS; later phases NOT_RUN')


def execute(root, phase):
    state=root/(phase+'.status.json')
    if state.exists():
        raise Stop('phase already attempted; preserve logs and use a new root: '+phase,2)
    try:
        require_previous(root,phase)
    except Stop as error:
        with (root/'summary.out').open('a') as stream:
            stream.write(phase.upper()+'=NOT_RUN reason='+str(error)+'\n')
        raise
    save(state,dict(phase=phase,status='RUNNING',later_phases='NOT_RUN'))
    print('开始阶段：'+PHASE_ZH[phase]+' ('+phase+')', flush=True)
    try:
        record=require_inputs(root)
        globals()[phase](root,record)
        require_inputs(root)
    except BaseException as error:
        code=error.code if isinstance(error,Stop) else 130 if isinstance(error,KeyboardInterrupt) else 1
        status='UNCOVERED' if isinstance(error,Stop) and error.uncovered else 'FAIL'
        save(state,dict(phase=phase,status=status,exit_code=code,
                        reason=str(error) or type(error).__name__,later_phases='NOT_RUN',
                        log=getattr(error,'log',None) or str(root/'runner.log'),
                        first_error=getattr(error,'first_error',None),
                        raw_exit_code=getattr(error,'raw_code',None),
                        diagnostics=getattr(error,'diagnostics',None)))
        with (root/'summary.out').open('a') as stream:
            stream.write(phase.upper()+'='+status+' reason='+str(error)+'\n')
        raise
    save(state,dict(phase=phase,status='PASS',exit_code=0))
    with (root/'summary.out').open('a') as stream:
        stream.write(phase.upper()+'=PASS\n')
    print(phase.upper()+'=PASS',flush=True)


def choose_root(phase):
    tmp=REPO/'AI/TMP'
    tmp.mkdir(exist_ok=True)
    # all always owns a fresh unique root, even if an old manual root is exported.
    requested=os.environ.get('STAGE2_ROOT') if phase != 'all' else None
    if requested:
        root=Path(requested).resolve()
        if tmp.resolve() not in root.parents or re.search(r'[\s"\\]',str(root)):
            raise Stop('STAGE2_ROOT must be below AI/TMP without whitespace/quotes/backslashes',2)
    elif phase in ('offline','build','all'):
        root=Path(tempfile.mkdtemp(prefix='stage2_validation_',dir=tmp))
    else:
        raise Stop('set STAGE2_ROOT to the root from all/build',2)
    if requested and phase in ('offline','build'):
        if root.exists() and phase == 'offline':
            raise Stop('offline requires a new STAGE2_ROOT; existing logs are preserved',2)
        if root.exists() and not (root/'inputs.json').is_file():
            raise Stop('existing STAGE2_ROOT has no input snapshot; use a new root',2)
        root.mkdir(parents=True,exist_ok=True)
    elif phase not in ('offline','build','all') and not root.is_dir():
        raise Stop('STAGE2_ROOT does not exist; run all/build first',2)
    return root


def run_phases(root, phase):
    if phase in ('offline','all') or (phase=='build' and not (root/'inputs.json').is_file()):
        if (root/'summary.out').exists() or (root/'inputs.json').exists() or list(root.glob('*.status.json')):
            raise Stop('root already initialized; preserve evidence and use a new root',2)
        (root/'summary.out').write_text('STAGE2_ROOT='+str(root)+'\nINITIAL_HARDWARE_PHASES=NOT_RUN\n')
        initial='offline' if phase=='offline' else 'build'
        print('保存源码、fixture、工具、环境与构建参数清单；'+
              ('执行独立离线检查。' if phase=='offline' else '不重复执行已通过的离线检查。'),flush=True)
        # Failure to inventory also gets a durable phase failure, no false PASS.
        try:
            record=inputs()
            save(root/'inputs.json',record)
            capture_sources(root,record)
        except Exception as error:
            code=error.code if isinstance(error,Stop) else 1
            save(root/(initial+'.status.json'),dict(phase=initial,status='FAIL',reason=str(error),exit_code=code,
                                                    log=str(root/'runner.log'),later_phases='NOT_RUN'))
            with (root/'summary.out').open('a') as stream:
                stream.write(initial.upper()+'=FAIL reason='+str(error)+'\n')
            print('STAGE2_ROOT='+str(root),flush=True)
            raise Stop('构建输入快照失败: '+str(error),code,log=root/'runner.log') from error
    for step in PHASES if phase=='all' else (phase,):
        execute(root,step)


def finish(root, phase, error=None):
    reported=OPTIONS if phase=='offline' else PHASES
    states={p:read(root/(p+'.status.json')) if (root/(p+'.status.json')).is_file()
            else dict(status='NOT_RUN') for p in reported}
    lines=['阶段结果：']
    lines += ['  '+PHASE_ZH[p]+' ('+p+')：'+STATUS_ZH[states[p]['status']] for p in reported]
    if error:
        failed=next((p for p in reported if states[p]['status'] in ('FAIL','UNCOVERED','RUNNING')),phase)
        detail=states.get(failed,{})
        lines += ['总结果：停止；失败阶段：'+PHASE_ZH.get(failed,failed),
                  '具体原因：'+(str(error) or type(error).__name__),
                  '退出码：'+str(error.code if isinstance(error,Stop) else 130 if isinstance(error,KeyboardInterrupt) else 1),
                  '日志绝对路径：'+(getattr(error,'log',None) or detail.get('log') or str(root/'runner.log'))]
        first=getattr(error,'first_error',None) or detail.get('first_error')
        if first:
            lines.append('首个有意义的错误：'+first)
        diagnostics=getattr(error,'diagnostics',None) or detail.get('diagnostics')
        if diagnostics:
            lines += ['本次日志错误/失败诊断数：'+str(diagnostics['count']),
                      '完整错误汇总：'+diagnostics['text']]
    elif all(states[p]['status']=='PASS' for p in PHASES):
        lines.append('总结果：当前测试通过；不等于已证明所有硬件行为正确。')
    else:
        lines.append('总结果：本阶段通过，其余阶段状态如上；尚未完成全部硬件验证。')
    lines += ['运行记录：'+str(root/'runner.log'), '结果摘要：'+str(root/'summary.out')]
    message='\n'.join(lines)+'\n'
    with (root/'summary.out').open('a') as stream:
        stream.write(message)
    print(message, end='', flush=True)


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('phase',choices=OPTIONS+('all','module'))
    args=parser.parse_args()
    # Resolve all relative inputs/tools from the project, independent of caller cwd.
    os.chdir(REPO)
    phase='directed' if args.phase=='module' else args.phase
    root=choose_root(phase)
    with (root/'runner.log').open('a') as log, \
         contextlib.redirect_stdout(Tee(sys.stdout,log)), contextlib.redirect_stderr(Tee(sys.stderr,log)):
        print('项目根目录：'+str(REPO)+'\n验证目录：'+str(root),flush=True)
        try:
            run_phases(root,phase)
        except BaseException as error:
            if not isinstance(error,(Stop,KeyboardInterrupt)):
                traceback.print_exc()
            finish(root,phase,error)
            return error.code if isinstance(error,Stop) else 130 if isinstance(error,KeyboardInterrupt) else 1
        finish(root,phase)
    return 0


if __name__=='__main__':
    try:
        sys.exit(main())
    except Stop as error:
        print('Stage 2 启动失败：'+str(error),file=sys.stderr)
        sys.exit(error.code)
    except Exception:
        traceback.print_exc()
        sys.exit(1)
