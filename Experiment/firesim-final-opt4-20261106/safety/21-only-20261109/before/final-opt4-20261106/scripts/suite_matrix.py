#!/usr/bin/env python3
"""Full local PARSEC scope and receipt-backed per-program coverage.

Discovery uses the local package group/parsec alias, including freqmine and
network apps. Missing software/validation remains explicit, never a pass.
"""
import datetime as dt
import json
from pathlib import Path
import re
import subprocess

from board_batch import W,D,save,sha

P=Path('/data1/gzh/EC/Software/PARSEC')
PROFILE={'blackscholes':'formal','canneal':'canneal-formal',
         'streamcluster':'streamcluster-staged-formal','swaptions':'swaptions-preallocated','dedup':'dedup-staged','freqmine':'freqmine-staged-resident','bodytrack':'bodytrack-staged-output'}
BLOCKERS={
 'bodytrack':'Serial build path exists; bound RISC-V ELF and output reference not yet prepared; per-frame image I/O inside ROI needs audit/staging.',
 'dedup':'Serial/preload path exists; compression/crypto dependencies and output/decode comparison not yet prepared; ROI output I/O requires audit.',
 'facesim':'Actual serial RISC-V candidate compiled after using original TaskQ dependency and invalidating incompatible old objects. Complete input/output/ROI validation remains; test -h is not compute smoke.',
 'ferret':'Serial build configuration exists; image/CASS dependencies and bound ELF/reference not yet prepared; serial ROI hooks must be verified (hook search only found parallel variants).',
 'fluidanimate':'Tracked serial.cpp contains legacy CPU3 checker pthread/RoCC harness. Remove only obsolete platform harness in private copy; retain simulation loop and original ROI; compare outputs.',
 'freqmine':'Original ROI syscall proven. Staged input/heap/affinity with auxiliary timing removed under paired-profile validation; all parsing/mining retained.',
 'netdedup':'RISC-V diagnostic server/client and test/small/formal QEMU-user decode evidence exist; single-core Linux stalls. Independent graceful-close candidate remains unverified in Linux. Original multithread/trap ROI is incompatible with current C4 admission; no formal software binding.',
 'netferret':'RISC-V candidate and all three QEMU-user/same-ISA socket output comparisons passed. Single-core Linux original timed out; independent framed protocol candidate hit obj != NULL in t_out. C4 original multithread/trap ROI and formal software binding remain unresolved.',
 'netstreamcluster':'RISC-V pair and all three QEMU-user/same-ISA socket comparisons passed. Single-core Linux evidence is in netstreamcluster-preparation-state.json. Preserve local simmedium -> simlarge mapping. Current C4 rejects original multithread/trap ROI; no formal software binding.',
 'raytrace':'Actual cross CMake configure failed: OpenGL/GLU/GLUT development inputs unavailable. Local RT_EMULATE_SSE is already enabled; do not attribute this build failure to unsupported SIMD.',
 'vips':'No bound RISC-V ELF/reference; library dependencies and original ROI hooks not yet located/validated in this checkout.',
 'x264':'RISC-V serial binary compiled. Exact official test flags fail with invalid argument: b-pyramid = --weightb. Local source has no PARSEC ROI hooks; explicit legacy option/ROI integration needed.',
 'streamcluster':'Official simmedium staged-I/O profile is bound; full original generation/clustering/formatting ROI and exact reference output retained. Native formal sampling in existing queue; C4 real checker/output/drain remains unverified.',
 'swaptions':'Original small/formal ROI calls brk. Preallocated-heap integration under validation; no FPGA result yet.',
 'blackscholes':'Native formal3 valid. Waiting final frozen C4 bitstream and real checker validation.',
 'canneal':'Native formal3 valid. Waiting final frozen C4 bitstream and real checker validation.'}
CORRECTNESS={
 'blackscholes':'prices.txt byte hash vs RISC-V reference; official option values also checked within1e-4',
 'canneal':'Final routing exact value vs deterministic serial RISC-V reference',
 'streamcluster':'output.txt byte hash vs unmodified reference; staged IO labelled separately',
 'swaptions':'all Swaption price/StdError lines, count and byte hash vs unmodified serial reference',
 'bodytrack':'planned: poses.txt numerical output vs serial RISC-V reference',
 'dedup':'planned: decode compressed output and compare original input (and deterministic reference)',
 'facesim':'planned: complete simulation state/output vs serial reference; method not validated',
 'ferret':'planned: complete output.txt query/ranking comparison vs reference',
 'fluidanimate':'planned: out.fluid complete byte/numerical comparison vs serial reference',
 'freqmine':'planned: frequent itemset result/count comparison vs reference',
 'raytrace':'planned: rendered frame/checksum vs reference; output path not validated',
 'vips':'planned: full output.v pixels/metadata vs reference',
 'x264':'planned: full encoded output and decoded-frame check vs reference',
 'netdedup':'planned: server output decode to original client input',
 'netferret':'planned: full server query rankings/output vs reference',
 'netstreamcluster':'planned: full clustering output vs reference for resolved official input'}


def read(p,default=None):
    return json.loads(p.read_text()) if p.exists() else default


def main():
    invpath=D/'parsec-suite-inventory.json'
    if not invpath.exists():
        programs=[]
        for f in sorted((P/'config/packages').glob('parsec.*.pkgconf')):
            text=f.read_text()
            group=re.search(r'^pkg_group="(.*?)"',text,re.M)
            aliases=re.search(r'^pkg_aliases="(.*?)"',text,re.M)
            if not(group and group[1] in ['apps','kernels','netapps'] and aliases and 'parsec' in aliases[1].split()):continue
            name=f.name.split('.')[1];pkg=P/'pkgs'/group[1]/name
            conf=pkg/'parsec/simmedium.runconf';conftext=conf.read_text()
            argv=re.search(r'^run_args="(.*?)"',conftext,re.M)
            executable=re.search(r'^run_exec="(.*?)"',conftext,re.M)
            input_pkg={'netdedup':P/'pkgs/kernels/dedup','netferret':P/'pkgs/apps/ferret','netstreamcluster':P/'pkgs/kernels/streamcluster'}.get(name,pkg)
            archive=input_pkg/'inputs/input_simmedium.tar'
            roi=[]
            for source in (pkg/'src').rglob('*'):
                if source.is_file() and source.suffix in ['.c','.cpp','.cxx','.C','.h']:
                    found=[dict(line=i,text=l.strip()) for i,l in enumerate(source.read_text(errors='replace').splitlines(),1) if re.search(r'__parsec_roi_(begin|end)\s*\(',l)]
                    if found:roi.append(dict(path=str(source),sha256=sha(source),hooks=found))
            installed=[]
            for path in (pkg/'inst').glob('*/bin/*'):
                if path.is_file():
                    with path.open('rb') as stream:magic=stream.read(4)
                    installed.append(dict(path=str(path),elf=magic==b'\x7fELF',verified_for_current_experiment=False))
            programs.append(dict(program=name,group=group[1],package_definition=str(f),package_definition_sha256=sha(f),source_dir=str(pkg/'src'),
                formal_input='simmedium',formal_runconf=str(conf),formal_runconf_sha256=sha(conf),official_run_exec=executable[1] if executable else None,
                formal_argv=argv[1].replace('${NTHREADS}','1') if argv else None,requested_threads=1,warmups=0,
                formal_input_archive=dict(path=str(archive),sha256=sha(archive)) if archive.exists() else None,
                input_generation='original synthetic deterministic generation' if name in ['streamcluster','swaptions'] else None,
                roi_source_hooks=roi,installed_candidates=installed))
        save(invpath,dict(schema='ec-local-parsec-suite/1',root=str(P),parsec_commit=subprocess.check_output(['git','-C',str(P),'rev-parse','HEAD'],text=True).strip(),
            discovery='config/packages/parsec.*.pkgconf: parsec alias AND apps/kernels/netapps group; includes freqmine without workload alias',programs=programs))
    inventory=read(invpath);summary=read(D/'results-summary.json',{})
    plan=read(D/'suite-execution-plan.json',{})
    profiles={t['program']:t['software_profile_prefix'] for t in plan.get('programs',[])}
    live_slots=read(D/'coverage-status-live.json',{})
    live_by_name={r['program']:r for r in live_slots.get('programs',[])}
    rows=[]
    for base in inventory['programs']:
        name=base['program'];row=dict(base)
        profile=profiles.get(name,PROFILE.get(name,name))
        apps_path=W/f'software/{profile}-apps-build.json';apps=read(apps_path,{})
        rootfs=read(W/f'software/{profile}-rootfs-build.json',{})
        row['software_profile']=apps.get('software_profile')
        row['bound_apps_receipt']=str(apps_path) if apps else None
        row['elf']=apps.get('binaries',{}).get(name)
        candidate=read(W/f'software/{name}-candidate-build.json')
        if candidate:row['candidate_build']=candidate
        row['formal_case']=next((c for c in apps.get('cases',[]) if c['program']==name and c['input']=='simmedium'),None)
        row['software_integration_patch']=apps.get('integration_patch')
        row['software_diagnostic_roi_syscalls']={c['input']:c.get('diagnostic_roi_syscalls') for c in apps.get('cases',[]) if c['program']==name}
        row['correctness']=dict(method=CORRECTNESS[name],fpga_verified_configurations=[])
        if row['formal_case']:
            row['correctness']['method']=row['formal_case'].get('validation',CORRECTNESS[name])
            row['bound_roi']=row['formal_case'].get('roi')
        counts={'Native':0,'C4':0};functional=[];groups=[]
        for g in summary.get('formal_groups',[]):
            key=g['matched_identity']
            if key['program']!=name or key['input']!='simmedium':continue
            if not apps or key['apps_manifest_sha256']!=sha(apps_path) or key['elf_sha256']!=row['elf']['sha256']:continue
            if rootfs and key['rootfs_sha256']!=rootfs['sha256']:continue
            groups.append(g)
            for cfg in counts:counts[cfg]=max(counts[cfg],g['configurations'].get(cfg,{}).get('n',0))
        historical_functional=[]
        for r in summary.get('valid_functional',[]):
            if r['program']!=name:continue
            ident=read(Path(r['result']),{}).get('identity',{})
            matching=(apps and row['elf'] and ident.get('apps_manifest_sha256')==sha(apps_path)
                and ident.get('elf_sha256')==row['elf']['sha256'] and ident.get('rootfs_sha256')==rootfs.get('sha256'))
            # Earlier functional passes from a different program profile cannot
            # validate the newly authorized software or any replacement image.
            (functional if matching else historical_functional).append(r)
        row.update(formal_valid_repetitions=counts,formal_target_repetitions=3,formal_groups=groups,functional_samples=functional,
            historical_functional_samples_other_profiles=historical_functional,
            native_formal_passed=counts['Native']>=3,opt4_formal_passed=counts['C4']>=3,
            paired_formal_passed=any(all(g['configurations'].get(cfg,{}).get('n',0)>=3 for cfg in counts) for g in groups),
            blocker=BLOCKERS[name],queue_status='WAITING_C4_CAD' if name in ['blackscholes','canneal','streamcluster'] else 'SOFTWARE_PREPARATION')
        row['correctness']['fpga_verified_configurations']=sorted(set(r['configuration'] for r in functional)|{cfg for cfg,n in counts.items() if n})
        if apps:
            pending=[cfg for cfg in ['Native','C4'] if not (W/f'software/{cfg}/{profile}-firmware-build.json').exists()]
            if name not in ['blackscholes','canneal']:
                row['blocker']=(apps.get('c4_incompatible_reason') or 'C4 real checker/output/drain validation pending; no synchronous ROI syscall in saved QEMU diagnostic. FPGA compatibility is NOT proved by QEMU.')
                row['queue_status']='WAITING_SOFTWARE_PAYLOAD' if pending else 'QUEUED_EXISTING_SUITE_CONTROLLER'
                row['missing_payload_configurations']=pending
                if any(c.get('diagnostic_roi_syscalls') for c in apps.get('cases',[])):
                    row['blocker']=apps.get('c4_incompatible_reason') or 'Saved ROI diagnostic contains synchronous syscalls; C4 compatibility unresolved.'
        row['actual_queue']={}
        for cfg in ['Native','C4']:
            q=read(D/f'suite-{cfg.lower()}-queue-state.json',{})
            recorded=q.get('tasks',{}).get(name)
            if recorded is not None:row['actual_queue'][cfg]=recorded
            elif cfg in next((t for t in plan.get('programs',[]) if t['program']==name),{}).get('managed_by_existing_queue',[]):
                row['actual_queue'][cfg]=dict(status='OWNED_BY_EXISTING_PRIORITY_QUEUE')
            elif not apps:
                row['actual_queue'][cfg]=dict(status='WAITING_SOFTWARE')
            else:
                # A running suite does not imply every unvisited program is running.
                row['actual_queue'][cfg]=dict(status='PENDING_EXISTING_QUEUE',queue_status=q.get('status','NOT_STARTED'))
        if row['actual_queue'].get('Native',{}).get('status')=='FAILED':
            row['blocker']='Native FPGA validation failed; retained sample/queue logs require diagnosis. '+row['blocker']
        if name=='fluidanimate':
            adoption=read(D/'software/fluidanimate-stable-formal-adoption.json',{})
            stable_adopted=(adoption.get('status')=='BOUND_FOR_BOTH_CONFIGURATIONS' and profile=='fluidanimate-stable-formal')
            evidence=read(D/'software/fluidanimate-linux-reference-diagnostic.json',{})
            if evidence.get('status')=='COMPLETE_RECOVERED_FROM_EVIDENCE':
                row['linux_reference_diagnostic']=dict(status=evidence['status'],output_sha256=evidence.get('output_sha256'),
                    system_vs_user_exact=evidence.get('system_vs_user_exact'),receipt=str(D/'software/fluidanimate-linux-reference-diagnostic.json'))
                if not evidence.get('system_vs_user_exact'):
                    row['blocker']='Native simsmall output failed twice. Complete Linux/QEMU reference also differs from QEMU user; FPGA output capture pending. Exact correctness gate retained. C4 not yet validated.'
                    pair=read(D/'software/fluidanimate-pair-selection-diagnostic.json',{})
                    fixed=read(D/'software/fluidanimate-stable-order-candidate.json',{})
                    if pair.get('status')=='COMPLETE_DIAGNOSTIC_ONLY':
                        row['pair_selection_diagnostic']=dict(receipt=str(D/'software/fluidanimate-pair-selection-diagnostic.json'),
                            first_divergence=pair.get('first_observed_pair_count_divergence'))
                        row['blocker']+=' Original cross-allocation pointer filter dynamically proved to omit different interacting pairs in Linux vs QEMU user.'
                    if fixed.get('cross_environment_output_exact'):
                        row['stable_order_candidate']=dict(patch=fixed.get('candidate_patch'),cross_environment_output_exact=True,
                            user_in_radius_omissions=fixed.get('user_in_radius_omissions'),linux_in_radius_omissions=fixed.get('linux_in_radius_omissions'),formal_eligible=False)
                        row['blocker']+=' Two-line index-order candidate gives identical QEMU user/Linux output and zero cross-cell omissions; explicit user decision pending before formal use.'
            if stable_adopted:
                retry=read(D/'fluidanimate-stable-native-state.json',{})
                row['authorized_software_repair']=dict(receipt=str(D/'software/fluidanimate-stable-formal-adoption.json'),
                    user_authorization=adoption.get('user_authorization'),profile='fluidanimate-stable-index-pairing-authorized-repair',
                    original_failures_retained=True,software_semantics_modified=True)
                row['historical_original_native_queue']=row['actual_queue']['Native']
                row['actual_queue']['Native']=dict(status=retry.get('status','WAITING_AUTHORIZED_REPAIR_SERVICE'),
                    state=str(D/'fluidanimate-stable-native-state.json'),service='ec-parsec-fluidanimate-stable-native.service',
                    stage=retry.get('stage'),completed_commands=retry.get('completed_commands',[]))
                row['blocker']='User-authorized stable index-pairing repair bound identically in both groups. Native directed repair waits for original Native queue/idle-repairs; C4 runs in the existing full-suite queue after final bitstream. FPGA functional gates and missing formal repeats remain.'
                if retry.get('status')=='FAILED_WITH_EVIDENCE':row['blocker']='Authorized Native repair failed; '+retry.get('error','see its retained logs')+'. C4 remains queued.'
                if counts['Native']>=3:row['blocker']='Authorized repaired software: Native formal3 valid. Final C4 real checker/output/drain and formal sampling pending.'
                row['queue_status']='AUTHORIZED_REPAIR_QUEUED'
        if name=='dedup' and profile.endswith('-safe-fdt'):
            row['blocker']='Old firmware DTB overlapped initramfs; safe-fdt firmware passed QEMU boot/integrity only. Directed FPGA repair waits for current Native queue idle. C4 not yet validated.'
        network_audit=read(D/'software/network-original-roi-audit.json',{})
        if name in network_audit.get('programs',{}):
            row['network_protocol_evidence']=network_audit['programs'][name]
            probe=read(D/'software/network-riscv-build-probe.json',{})
            if probe:
                row['actual_dependency_build_probe']=dict(receipt=str(D/'software/network-riscv-build-probe.json'),
                    status=probe.get('status'),commands=probe.get('commands'),elf_produced=probe.get('elf_produced'))
            row['blocker']=('Original ROI contains network/thread/blocking paths; current C4 trap/context validity contract and original user TCP RISC-V port are unresolved. '
                'Default path uses user TCP/shared memory; CONFIG_NET=n alone is not proof of incompatibility. '+network_audit['programs'][name].get('input_inconsistency',''))
            row['queue_status']='BLOCKED_PROTOCOL_AND_UNPORTED_DEPENDENCY'
            if probe.get('status')=='BLOCKED_WITH_ACTUAL_BUILD_EVIDENCE':
                row['blocker']+=' Actual RISC-V make failed on missing include/riscv64; separate statistics translation unit failed on x86 register names in inline assembly. Logs are bound in actual_dependency_build_probe.'
        preparation=read(D/f'software/{name}-preparation-state.json',{})
        if preparation:
            row['software_preparation_state']=preparation
            if not apps and preparation.get('status')=='FAILED_WITH_EVIDENCE':
                row['blocker']=preparation.get('error','Software preparation failed; see saved evidence')
        slot_entry=live_by_name.get(name)
        if slot_entry:
            row['stage_slots']={cfg:s['slots'] for cfg,s in slot_entry['configurations'].items()}
            row['legacy_queue_history']=row['actual_queue']
            row['actual_queue']={cfg:dict(status=s['status'],formal_completed=s['formal_completed'],
                future_owner=s.get('future_owner'),boundary=s.get('boundary'),
                state=str(D/'coverage-first-state.json')) for cfg,s in slot_entry['configurations'].items()}
            row['slot_evidence']=str(D/'coverage-status-live.json')
        rows.append(row)
    coverage=dict(total_programs=len(rows),native_formal_passed=sum(r['native_formal_passed'] for r in rows),
        opt4_formal_passed=sum(r['opt4_formal_passed'] for r in rows),paired_formal_passed=sum(r['paired_formal_passed'] for r in rows),
        formal_repetitions_required=3,small_inputs_excluded=True)
    report=dict(schema='ec-parsec-full-suite-progress/1',updated_utc=dt.datetime.now(dt.timezone.utc).isoformat(),inventory=str(invpath),coverage=coverage,programs=rows,
        existing_queue_states=[str(D/n) for n in ['fpga-continuation-state.json','c4-canneal-continuation-state.json','c4-streamcluster-continuation-state.json','suite-native-queue-state.json','suite-c4-queue-state.json']],
        geometry_policy='Only exact matched workload identities; explicitly list actual covered programs; incomplete suite is not full PARSEC')
    save(D/'parsec-suite-progress.json',report)
    lines=['# 本地完整 PARSEC Native / 最终 Opt4 C4 配对进度','',
        f"全套共 {len(rows)} 个程序；Native 正式通过 {coverage['native_formal_passed']}/{len(rows)}；Opt4 正式通过 {coverage['opt4_formal_passed']}/{len(rows)}；有效配对 {coverage['paired_formal_passed']}/{len(rows)}。",'',
        '正式通过要求同一版本三轮有效原子提交。test/simsmall 仅功能验证。完整 ELF、runconf、输入哈希、ROI 行号、参考与逐样本路径见同名 JSON。', '',
        '|程序|Native 正式轮数|Opt4 正式轮数|正式命令（线程1）|当前具体阻碍|','|---|---:|---:|---|---|']
    for r in rows:
        case=r['formal_case']
        argv=' '.join(case['argv']) if case else r['formal_argv']
        executable=r['elf']['path'] if r['elf'] else r['official_run_exec']
        lines.append(f"|{r['program']}|{r['formal_valid_repetitions']['Native']}|{r['formal_valid_repetitions']['C4']}|`{executable} {argv}`|{r['blocker']}|")
    for r in rows:
        lines+=['',f"## {r['program']}",'',f"ELF：{r['elf']['path'] if r['elf'] else '尚无本实验已绑定 ELF'}",f"输入：{r['formal_input_archive'] or r['input_generation']}",f"ROI：{r.get('bound_roi') or '; '.join(x['path']+':'+','.join(str(h['line']) for h in x['hooks']) for x in r['roi_source_hooks']) or '尚未找到/验证；禁止伪造 ROI'}",f"集成补丁：{r['software_integration_patch'] or '无已绑定软件补丁'}",f"正确性：{r['correctness']['method']}",f"功能样本（不计正式）：{', '.join(x['configuration']+' '+x['input']+' '+str(x['roi_cycles'])+' cycles' for x in r['functional_samples']) or '无有效提交'}"]
    (D/'PARSEC_SUITE_PROGRESS.md').write_text('\n'.join(lines)+'\n')
    print(json.dumps(coverage))


if __name__=='__main__':main()
