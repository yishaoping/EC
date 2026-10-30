"""Build-local, observation-only overlays for the final Opt4 FST run.

Never edits Scala/resources or previously saved runs. The caller supplies freshly
generated/copied collateral. Existing diagnostic expressions become named trace
aliases; only curated diagnostic printf gates lose their verbose dependency.
"""
import collections
import hashlib
import json
from pathlib import Path
import re

PREFIXES = ('FASTLINE_', 'WB_', 'PROBE_', 'MSHR_', 'PRESERVATION_', 'SVB_',
            'C_CHANNEL ', 'D_ACK ', 'WATERMARK_ADVANCE ', 'LONG_STALL ',
            'CORE_WATCHDOG_SNAPSHOT ', 'DCACHE_WATCHDOG_SNAPSHOT ', 'CACHE_HANG_SNAPSHOT ')
DECL = re.compile(r'^[ \t]+(?:input|output|wire|reg)\s+(?:\[[^\n\]]+\]\s*)*(\w+)\b', re.M)
ALIAS_BEGIN = '  // OPT4_WAVEFORM_ALIASES_BEGIN\n'
ALIAS_END = '  // OPT4_WAVEFORM_ALIASES_END\n'
GROUPS = {
    'BoomCore': {
        'watchdog': [r'ecWatchdogImminent', r'lastRobCommitCycle', r'lastWatchdogProgressCycle'],
        'pipeline': [r'slowdown_rob_gate', r'slowdown_gate_.*', r'csr_commit_num'],
    },
    'Rob': {
        'ROB_head_tail': [r'rob_head', r'rob_tail'],
        'ROB_commit': [r'io_commit_valids_[0-2]', r'io_commit_uops_0_debug_pc',
                       r'io_commit_uops_0_inst', r'io_commit_uops_0_rob_idx'],
        'ROB_exception_flush': [r'io_flush_valid', r'io_com_xcpt_valid'],
        'ROB_head_uop': [r'slowdown_head_busy_[0-2]', r'rob_val__0', r'rob_bsy__0'],
    },
    'LSU': {
        'LSU_request': [r'io_dmem_req_valid', r'io_dmem_req_ready',
                        r'io_dmem_req_bits_0_bits_uop_rob_idx', r'io_dmem_req_bits_0_bits_addr'],
        'LSU_response_nack': [r'io_dmem_resp_0_valid', r'io_dmem_nack_0_valid'],
        'LSU_queues': [r'ldq_0_valid', r'stq_0_valid'],
    },
    'BoomNonBlockingDCache': {
        'fastline': [r'svbFastLineValid', r'svbFastSet', r'svbFastWay', r'svbFastTag',
                     r'svbFastSeq', r'svbFastEpoch', r'svbFastKey_generation',
                     r'svbFastAcquireCycle', r'svbFastReleaseCycle', r'svbFastLineMatch'],
        'handoff_gates': [r'crossPackageBlockCondition', r'crossPackageBlockWithoutFastLine',
                          r'fastLineBlocksOtherLine', r'svbEligibleCandidate', r'svbEligible',
                          r'svbCapturePending', r'svbCaptureIssued', r'svbCaptureResidentMatch',
                          r's2_preservationAllowed', r's3_preservationAllowed',
                          r'preservationWBWaitingReason'],
        'preservation': [r'crossPackagePending', r'crossPackagePendingKey_contentSeq',
                         r'debug_cross_package_wb_(valid|ready|fire)', r'crossPackageWbDone'],
        'watermark_checker_bitmap': [r'debug_safe_packet_watermark', r'slowdown_opt1_safe_advance',
                                    r'slowdown_opt1_result_accepted_[0-3]',
                                    r'slowdown_opt1_prefix_completed(?:_.*)?',
                                    r'slowdown_opt1_prefix_passed(?:_.*)?'],
        'TL_C_D': [r'slowdown_tl_c_(valid|ready|opcode|source|address|size)',
                   r'slowdown_tl_d_(valid|ready|opcode|source)', r'releaseSourceBusy',
                   r'auto_out_c_bits_param', r'auto_out_d_bits_(param|sink)',
                   r'auto_out_[bcd]_(valid|ready)'],
        'MSHR_owners': [r'_mshrs_io_owner_line_valid_[0-5]', r'_mshrs_io_owner_line_addr_[0-5]',
                        r'_mshrs_io_debug_state_[0-5]'],
        'WB_probe': [r'_wb_io_debug_state', r'_prober_io_diagnosticState', r'probeBlockedBySvb'],
    },
    'SpeculativeVersionBuffer': {
        'SVB16': [r'valid_\d+', r'state_\d+', r'line_\d+', r'key_\d+_contentSeq',
                  r'key_\d+_generation', r'epoch_\d+', r'entrySafe_\d+'],
        'promotion': [r'active', r'activeIdx', r'sent', r'io_promote_ready',
                      r'io_capture_ready', r'io_acked'],
    },
    'BoomWritebackUnit': {
        'WB_control': [r'state', r'req_idx', r'req_tag', r'ackPending', r'pendingIsSvb',
                       r'io_req_valid', r'io_req_ready', r'io_release_valid',
                       r'io_release_ready', r'io_mem_grant'],
    },
    'BoomProbeUnit': {
        'probe_control': [r'state', r'req_address', r'req_source', r'req_param',
                          r'io_req_valid', r'io_req_ready', r'io_wb_req_valid', r'io_wb_req_ready'],
    },
    'BoomMSHR': {
        'MSHR_control': [r'state', r'req_addr', r'req_packet_seq', r'req_uop_rob_idx',
                         r'io_wb_req_valid', r'io_wb_req_ready', r'io_mem_grant_valid',
                         r'io_mem_grant_ready', r'io_replay_valid', r'io_replay_ready'],
    },
}


def digest(data):
    return hashlib.sha256(data).hexdigest()


def split_args(text):
    """Split Verilog arguments without splitting concatenations or calls."""
    args, start, depth = [], 0, 0
    for i, char in enumerate(text):
        if char in '({[':
            depth += 1
        elif char in ')}]':
            depth -= 1
        elif char == ',' and depth == 0:
            args.append(text[start:i].strip()); start = i + 1
    args.append(text[start:].strip())
    return args


def identifiers(text):
    names = set(DECL.findall(text))
    # CIRCT shares port direction/width over several comma-separated lines.
    header = re.search(r'\bmodule\s+\w+\s*\((.*?)\);', text, re.S)
    if not header:
        raise RuntimeError('module header missing')
    for port in header[1].split(','):
        m = re.search(r'(\w+)\s*$', port)
        if m: names.add(m[1])
    return names


PRINT = re.compile(r'(?P<gate>^[ \t]*if \([^\n]*`PRINTF_COND_[^\n]*\)[^\n]*\n)'
                   r'(?P<call>[ \t]*\$fwrite\(32\x27h80000002, "(?P<fmt>(?:\\.|[^"\\])*)",'
                   r'(?P<args>.*?)\);)', re.M | re.S)


def diagnostic_overlay(text, module):
    aliases, counts = [], collections.Counter()

    def change(match):
        fmt = match['fmt']
        if not fmt.startswith(PREFIXES):
            return match[0]
        event = fmt.split()[0]
        instance = counts[event]; counts[event] += 1
        args = split_args(match['args'])
        fields = re.findall(r'\b(\w+)=%[xhd]', fmt)
        if len(fields) != len(args):
            raise RuntimeError(f'cannot expose {module}/{event}: format/argument mismatch')
        for field, expr in zip(fields, args):
            aliases.append(dict(module=module, name=f'opt4_wave_{module}_{event}_{instance}_{field}',
                                expression=expr, group='diagnostic_expression', event=event, field=field))
        # Keep reset and all event predicates. The constant applies only to
        # this existing diagnostic statement; no shared macro or RTL gate.
        return match['gate'].replace('`PRINTF_COND_', "1'b1") + match['call']

    result = PRINT.sub(change, text)
    required = {'BoomCore': ['CORE_WATCHDOG_SNAPSHOT'],
                'BoomNonBlockingDCache': ['DCACHE_WATCHDOG_SNAPSHOT', 'FASTLINE_BLOCK_OTHER_LINE',
                                         'MSHR_HANG_ENTRY'],
                'SpeculativeVersionBuffer': ['SVB_HANG_ENTRY']}
    for event in required.get(module, []):
        if not counts[event]:
            raise RuntimeError(f'mandatory existing snapshot/event absent: {module}/{event}')
    return result, aliases, dict(counts)


def native_aliases(text, module):
    names = identifiers(text); aliases, groups = [], {}
    chosen = set()
    mandatory = {
        'Rob': [f'io_commit_valids_{i}' for i in range(3)] +
               [f'slowdown_head_busy_{i}' for i in range(3)],
        'BoomNonBlockingDCache':
            ['slowdown_tl_c_'+x for x in ('valid', 'ready', 'opcode', 'source', 'address', 'size')] +
            ['slowdown_tl_d_'+x for x in ('valid', 'ready', 'opcode', 'source')] +
            ['auto_out_'+c+'_'+x for c in 'bcd' for x in ('valid', 'ready')] +
            ['auto_out_c_bits_param', 'auto_out_d_bits_param', 'auto_out_d_bits_sink'] +
            [f'slowdown_opt1_result_accepted_{i}' for i in range(4)],
    }
    missing = sorted(set(mandatory.get(module, [])) - names)
    if missing:
        raise RuntimeError('required interface members absent: '+module+'/'+','.join(missing))
    for group, patterns in GROUPS[module].items():
        matched = set()
        for pattern in patterns:
            hits = {n for n in names if re.fullmatch(pattern, n)}
            if not hits:
                raise RuntimeError(f'missing required generated signal: {module}/{group}/{pattern}')
            matched |= hits
        groups[group] = sorted(matched); chosen |= matched
    if module == 'SpeculativeVersionBuffer':
        for pattern in GROUPS[module]['SVB16']:
            if len([n for n in names if re.fullmatch(pattern, n)]) != 16:
                raise RuntimeError('SVB16 per-entry trace inventory incomplete: ' + pattern)
    if module == 'BoomNonBlockingDCache':
        for pattern in GROUPS[module]['MSHR_owners']:
            if len([n for n in names if re.fullmatch(pattern, n)]) != 6:
                raise RuntimeError('six MSHR ownership records required')
        # Trace all existing slowdown aliases (bitmap, cache slots, request
        # provenance) and each control term used by the captured fast-line gates.
        chosen |= {n for n in names if n.startswith(('slowdown_', 'svb', 'crossPackage',
                                                    'preservation', 'fastOwner', 'releaseSource'))}
        chosen |= {n for n in names if re.fullmatch(r'auto_out_[bcd]_(?:valid|ready|bits_(?:opcode|param|source|sink|address|size))', n)}
        # Retain the immediate combinational terms of every fast-line gate,
        # including generated temporary wires normally hidden by their '_'.
        unpacked = set(re.findall(r'^[ \t]+(?:wire|reg)\s+(?:\[[^\]]+\]\s*)*(\w+)\s+\[', text, re.M))
        roots = {n for n in chosen if n.startswith(('svbFast', 'crossPackageBlock', 'fastLineBlocks'))}
        for root in roots:
            for rhs in re.findall(r'\b'+re.escape(root)+r'\s*(?:<=|=)\s*([^;]+);', text):
                chosen |= (set(re.findall(r'\b\w+\b', rhs)) & names) - unpacked
    if module in ('Rob', 'LSU', 'BoomCore'):
        chosen |= {n for n in names if n.startswith('slowdown_')}
    for n in sorted(chosen):
        aliases.append(dict(module=module, name=f'opt4_wave_{module}_native_{n}',
                            expression=n, group='native_control'))
    # Explicit fire for decoupled interfaces. Valid-only interfaces (ROB commit,
    # LSU response/nack) have no invented ready: retain their real protocol.
    for n in sorted(names):
        if n.endswith('_valid') and n[:-6] + '_ready' in names:
            ready = n[:-6] + '_ready'
            if n.startswith(('io_', 'auto_out_', 'slowdown_', 'debug_', '_wb', '_svb', '_prober', '_mshrs')):
                for suffix, expression in [('valid', n), ('ready', ready), ('fire', f'{n} & {ready}')]:
                    aliases.append(dict(module=module, name=f'opt4_wave_{module}_rv_{n[:-6]}_{suffix}',
                                        expression=expression, group='ready_valid_fire'))
    return aliases, groups


def suppress_memories(text, module):
    """Tracing comments only. Never removes a declaration or changes a value."""
    excluded = []
    if re.match(r'^(Rocket(?:$|_)|RocketCore|IBuf|MulDiv|FPU|ICache(?:$|_)|SimDRAM|SimAXIMem)', module):
        return '/*verilator tracing_off*/\n' + text + '\n/*verilator tracing_on*/\n', [dict(module=module, kind='unrelated_datapath_module')]
    lines = text.splitlines(keepends=True); out = []
    for line in lines:
        # SRAM payload arrays and wide data buses; never ROB/LSU control arrays
        # or safe-chain bitmaps. Scalar caches' metadata stays visible.
        m = re.match(r'\s*(?:reg|wire)\s+\[(\d+):0\]\s+(\w+)\s*(\[[^;]+\])?[^;]*;', line)
        skip = bool(m and ((m[3] and re.search(r'(?:^mem|data|ram)', m[2], re.I)) or
                            (int(m[1]) >= 256 and re.search(r'data', m[2], re.I))))
        if skip:
            excluded.append(dict(module=module, name=m[2], kind='payload_declaration'))
            out.extend(['/*verilator tracing_off*/\n', line, '/*verilator tracing_on*/\n'])
        else:
            out.append(line)
    return ''.join(out), excluded


def restore_generated(text):
    """Exact inverse, used before writing to prove functional bytes unchanged."""
    text = re.sub(re.escape(ALIAS_BEGIN) + r'.*?' + re.escape(ALIAS_END), '', text, flags=re.S)
    text = text.replace('/*verilator tracing_off*/\n', '').replace('/*verilator tracing_on*/\n', '')
    # Entire-file suppression has one separating newline after original text.
    return text


def patch_emulator(text):
    replacements = [
        ('#include <getopt.h>', '#include <getopt.h>\n#include "opt4_waveform_runtime.h"'),
        ('  Verilated::randReset(2);', '  Verilated::fatalOnError(false); // finish the failing eval and save its FST edge\n  Verilated::randReset(2);'),
        ('    tfp->open(vcdfile_name);', '    tfp->open(vcdfile_name);\n    opt4_waveform_trace = tfp.get();\n    if (!tfp->isOpen()) { fprintf(stderr, "[OPT4_WAVEFORM] FST open failed\\n"); return 1; }'),
        ('    trace_count++;', '    if (dump && !(trace_count % 16384)) tfp->flush();\n    trace_count++;'),
        ('  while (!simulation_complete() && trace_count < max_cycles);',
         '  while (!Verilated::gotFinish() && !simulation_complete() && trace_count < max_cycles);'),
        ('  if (tfp)\n    tfp->close();', '  if (tfp)\n    tfp->close();\n  opt4_waveform_trace = nullptr;'),
        ('  if (dtm && dtm->exit_code())\n  {',
         '  if (Verilated::gotError())\n  {\n    exit_reason = "rtl_assertion";\n    ret = 1;\n  }\n  else if (Verilated::gotFinish() && !host_success_seen)\n  {\n    exit_reason = "rtl_finish_without_host_success";\n    ret = 1;\n  }\n  else if (dtm && dtm->exit_code())\n  {'),
    ]
    for before, after in replacements:
        if text.count(before) != 1:
            raise RuntimeError('emulator overlay anchor changed: ' + before[:75])
        text = text.replace(before, after)
    return text


def hierarchy_paths(generated):
    paths = collections.defaultdict(list)
    def walk(node, parent=''):
        path = parent + ('.' if parent else '') + node['instance_name']
        paths[node['module_name']].append(path)
        for child in node.get('instances', []): walk(child, path)
    walk(json.loads((generated/'model_module_hierarchy.json').read_text()))
    for module in GROUPS:
        if len(paths[module]) != (6 if module == 'BoomMSHR' else 1):
            raise RuntimeError('unexpected relevant hierarchy count: ' + module)
    return paths


def prepare(generated, runtime_header, write=True):
    """Apply to a new build only, with an exact reversible observation proof."""
    generated = Path(generated); collateral = generated/'gen-collateral'
    paths = hierarchy_paths(generated)
    inventory = dict(schema=1, aliases=[], groups={}, diagnostics={}, files={}, exclusions=[],
                     hierarchy={m: paths[m] for m in GROUPS},
                     proof='exact inverse of trace comments/alias additions/curated printf-enable replacements')
    pending = {}
    for path in sorted(list(collateral.glob('*.sv')) + list(collateral.glob('*.v'))):
        original = path.read_text()
        module = path.stem
        if 'OPT4_WAVEFORM_ALIASES_BEGIN' in original:
            raise RuntimeError('fresh build required; collateral already overlaid')
        text = original
        if module in GROUPS:
            text, aliases, counts = diagnostic_overlay(text, module)
            native, groups = native_aliases(text, module)
            aliases += native
            inventory['aliases'] += aliases
            inventory['groups'][module] = groups
            inventory['diagnostics'][module] = counts
            addition = ALIAS_BEGIN + ''.join(
                f"  wire [$bits({a['expression']})-1:0] {a['name']} = {a['expression']};\n"
                for a in aliases) + ALIAS_END
            if text.count('endmodule') != 1:
                raise RuntimeError('one module per collateral file required')
            text = text.replace('endmodule', addition + 'endmodule')
        text, excluded = suppress_memories(text, module)
        inventory['exclusions'] += excluded
        inverse = restore_generated(text)
        # Restore only curated printf gates by applying the same matcher to
        # the original: the exact list of allowed changed byte ranges is known.
        expected = diagnostic_overlay(original, module)[0] if module in GROUPS else original
        if inverse != expected and inverse.rstrip('\n') != expected.rstrip('\n'):
            raise RuntimeError('observation-only inverse failed: ' + path.name)
        if text != original:
            inventory['files'][str(path)] = dict(original_sha256=digest(original.encode()),
                                                observed_sha256=digest(text.encode()),
                                                functional_bytes_preserved=True)
            pending[path] = text
    if set(inventory['groups']) != set(GROUPS):
        raise RuntimeError('required module collateral missing')
    emulator = collateral/'emulator.cc'
    original = emulator.read_text(); text = patch_emulator(original)
    pending[emulator] = text
    inventory['emulator'] = dict(original_sha256=digest(original.encode()),
                                 observed_sha256=digest(text.encode()), scope='host trace finalization/exit handling only')
    if write:
        for path, text in pending.items(): path.write_text(text)
        (collateral/'opt4_waveform_runtime.h').write_bytes(Path(runtime_header).read_bytes())
    return inventory


def compiled_audit(build, inventory):
    """Require actual trace declarations, not just source/dontTouch claims."""
    files = sorted(Path(build).rglob('*__Trace*.cpp'))
    names = set()
    for path in files:
        for line in path.read_text().splitlines():
            if re.search(r'\bVL_TRACE_DECL_\w+\s*\(|->decl(?:Bit|Bus|Quad|Array)\s*\(', line):
                names.update(re.findall(r'opt4_wave_\w+', line))
    required = {a['name'] for a in inventory['aliases']}
    missing = sorted(required - names)
    return dict(status='PASS' if files and not missing else 'FAIL', files_scanned=len(files),
                required=len(required), declared=len(required & names), missing=missing,
                scope='compiled trace declarations; FST runtime coverage checked after the single run')
