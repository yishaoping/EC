#!/usr/bin/env python3
"""Manual C4 Linux RTL validation. prepare/verify do not start a target; run boots to a shell."""
import argparse
import datetime
import gzip
import hashlib
import json
import os
from pathlib import Path
import re
import selectors
import signal
import struct
import subprocess
import time
from build_minimal import ROOT, sha
from opt4_image_integrity import attest

WORK=ROOT/'firesim/dac2026/work/opt4-linux-v6'
RESULTS=ROOT/'Experiment/dac2026/opt4-linux-v6/linux'

def write(path,obj): path.write_text(json.dumps(obj,indent=2)+'\n')
def receipts(console='uart', frozen=None, profile='formal'):
    records={}
    for name in ['native','firmware','apps','rootfs','fdt']:
        directory=WORK/'native-htif' if console=='htif' and name in ['firmware','rootfs','fdt'] else WORK
        if profile=='diagnostic36' and name in ['native','firmware','fdt']:directory=WORK/'diagnostic36'
        if profile=='diagnostic36-small':directory=WORK/('diagnostic36' if name=='native' else 'diagnostic36-small')
        p=directory/(name+'-build.json')
        if frozen is None:
            if not p.is_file():raise ValueError('missing successful build: '+str(p))
            x=json.loads(p.read_text())
        else:x=frozen[name]['value']
        if x.get('returncode')!=0:raise ValueError('failed '+str(p))
        for n,h in x.get('outputs',{}).items():
            if not Path(n).is_file() or sha(n)!=h:raise ValueError('artifact changed: '+n)
        records[name]={'receipt':str(p),'sha256':sha(p),'value':x} if frozen is None else frozen[name]
    # Native DT is bound to the exact native build, never a FireSim memory map.
    native=records['native']['value'];dt=records['fdt']['value']
    if profile.startswith('diagnostic36'):
        if console!='htif' or not native.get('required_events_without_verbose'):
            raise ValueError('diagnostic36 requires independently observable real RTL events')
        if records['firmware']['value'].get('diagnostic_max_physmem_bits')!=36:
            raise ValueError('diagnostic36 firmware receipt mismatch')
    native_dts=Path(native['output_dir'])/'generated/chipyard.TestHarness.DacLinuxC4.dts'
    if sha(native_dts)!=dt['source_dts_sha256']:raise ValueError('native/FDT mismatch')
    apps=records['apps']['value']
    for n,h in apps['binaries'].items():
        if sha(Path(apps['output'])/n)!=h:raise ValueError('software changed')
    for mode,description in apps['inputs'].items():
        for rel,h in description['files'].items():
            if sha(Path(apps['output'])/'inputs'/mode/rel)!=h:
                raise ValueError('PARSEC input changed: '+mode+'/'+rel)
    root=records['rootfs']['value'];fw=records['firmware']['value']
    if sha(root['initramfs'])!=root['sha256']:raise ValueError('initramfs changed')
    if root['apps_manifest_sha256']!=records['apps']['sha256']:raise ValueError('rootfs/apps mismatch')
    if sha(dt['fdt'])!=dt['sha256']:raise ValueError('DTB changed')
    for path,h in fw['input_files'].items():
        if sha(path)!=h:raise ValueError('firmware input changed: '+path)
    if fw['input_files'].get(dt['fdt'])!=dt['sha256']:raise ValueError('firmware/FDT mismatch')
    kernel=json.loads(Path(fw['kernel_result']).read_text())
    if kernel['returncode']!=0 or kernel['input_files'].get(root['initramfs'])!=root['sha256']:
        raise ValueError('kernel/rootfs mismatch')
    if console=='htif':
        config=(Path(kernel['output_dir'])/'.config').read_text()
        if 'CONFIG_HVC_RISCV_SBI=y\n' not in config or 'CONFIG_RISCV_SBI_V01=y\n' not in config:
            raise ValueError('native HTIF kernel lacks the real SBI console')
        attest(root,apps,records['apps']['sha256'])
    return records
def identity(records):return hashlib.sha256(json.dumps(records,sort_keys=True).encode()).hexdigest()
def preload_image(elf):
    """Flatten the exact ELF PT_LOAD bytes for native SimDRAM's hex loader.

    The existing testchip_tsi loadmem path bypasses serial ELF writes, then
    performs its normal reset/MSIP transaction.  No early custom-boot pulse.
    """
    data=elf.read_bytes()
    if data[:6]!=b'\x7fELF\x02\x01':raise ValueError('expected little-endian ELF64')
    entry,phoff=struct.unpack_from('<QQ',data,24)
    phentsize,phnum=struct.unpack_from('<HH',data,54)
    segments=[]
    for i in range(phnum):
        typ,flags,off,va,pa,filesz,memsz,align=struct.unpack_from('<IIQQQQQQ',data,phoff+i*phentsize)
        if typ==1:
            if not (0x80000000<=pa and pa+memsz<=0x90000000) or filesz>memsz or off+filesz>len(data):
                raise ValueError('PT_LOAD is outside C4 native DRAM')
            segments.append((pa,off,filesz,memsz))
    if entry!=0x80000000 or not segments:raise ValueError('unexpected native boot entry')
    image=bytearray(max(pa+memsz for pa,off,filesz,memsz in segments)-0x80000000)
    for pa,off,filesz,memsz in segments:image[pa-0x80000000:pa-0x80000000+filesz]=data[off:off+filesz]
    image_id=hashlib.sha256(image).hexdigest()
    directory=ROOT/'firesim/dac2026/images/opt4-linux-v6/native-loadmem'
    directory.mkdir(parents=True,exist_ok=True)
    dest=directory/(image_id+'.hex')
    # mm_t::load_mem reads reversed byte pairs on each line, advancing by
    # that line's byte count; 64-byte lines are independent of bus width.
    encoded=''.join(image[i:i+64][::-1].hex()+'\n' for i in range(0,len(image),64)).encode()
    expected=hashlib.sha256(encoded).hexdigest()
    if dest.exists():
        if sha(dest)!=expected:raise ValueError('native preload image changed')
    else:
        with dest.open('xb') as stream:stream.write(encoded);stream.flush();os.fsync(stream.fileno())
    return {'path':str(dest),'sha256':expected,'elf':str(elf),'elf_sha256':sha(elf),
            'flat_sha256':image_id,'size':len(image),'dram_base':0x80000000,
            'loadmem_addr':0,'entry':entry,'segments':segments}
def prepare(mode,console,max_cycles,profile='formal'):
    r=receipts(console,profile=profile);stamp=datetime.datetime.now(datetime.timezone.utc).strftime('%Y%m%dT%H%M%S.%fZ')
    if console=='htif' and r['fdt']['value'].get('guest_mode')!=mode:
        raise ValueError('native HTIF FDT/firmware guest mode differs; build the matching mode first')
    attempt=RESULTS/'partial'/stamp;raw=RESULTS/'raw'/stamp
    attempt.mkdir(parents=True,exist_ok=False);raw.mkdir(parents=True,exist_ok=False)
    native=r['native']['value'];fw=r['firmware']['value']
    elf=Path(fw['output_dir'])/'platform/generic/firmware/fw_payload.elf'
    preload=preload_image(elf)
    cy=Path(native['source_tree'])
    args=['/usr/bin/stdbuf','-oL','-eL',native['simulator'],'-s','1','+cycle-count','+verbose','+permissive','+dramsim',
          '+dramsim_ini_dir='+str(cy/'generators/testchipip/src/main/resources/dramsim2_ini'),
          '+uartlog='+str(raw/'uart'),'+max-cycles='+str(max_cycles),
          '+loadmem='+preload['path'],'+loadmem_addr=0',
          '+permissive-off',str(elf)]
    if native.get('required_events_without_verbose'):args.remove('+verbose')
    if console=='htif':args.insert(args.index('+permissive-off'),'+uart-pty')
    record={'identity':identity(r),'receipts':r,'argv':args,'mode':mode,'raw_dir':str(raw),'profile':profile,
            'runner_sha256':sha(Path(__file__).resolve()),
            'console':console,'console_file':str(raw/('htif-console.log' if console=='htif' else 'uart0')),
            'guest_execution':'version-bound init command' if console=='htif' else 'SimUART stdin',
            'integrity_helper_sha256':sha(Path(__file__).with_name('opt4_image_integrity.py')),
            'image_attestation':attest(r['rootfs']['value'],r['apps']['value'],r['apps']['sha256']) if console=='htif' else None,
            'payload_loader':'native SimDRAM PT_LOAD hex preload; positional ELF symbols and normal TSI reset/MSIP',
            'preload':preload,
            'status':'PREPARED_NOT_RUN','guest_command':'/opt/ec-dac/manual-link.sh '+mode,
            'shutdown_command':'/bin/busybox sync; /bin/busybox poweroff',
            'scope':'C4 native RTL validation; native memory differs from B FireSim, ineligible for slowdown',
            'slowdown_eligible':False,'one_roi_per_boot':True}
    write(attempt/'manifest.json',record);print(attempt)
def verify(attempt):
    m=json.loads((attempt/'manifest.json').read_text());raw=Path(m['raw_dir'])
    console=m.get('console','uart');console_file=Path(m.get('console_file',str(raw/'uart0')))
    uart=console_file.read_text(errors='replace') if console_file.exists() else ''
    # Preserve ALL original verbose output in gzip; parse only relevant lines
    # while streaming, so boot/legacy instruction traces cannot exhaust RAM.
    evidence=[]
    if (raw/'rtl.log.gz').exists():
        try:
            with gzip.open(raw/'rtl.log.gz','rt',errors='replace') as stream:
                for line in stream:
                    if 'EC_OPT4_' in line or re.search(r'Assertion failed|%Error|Aborted',line,re.I):evidence.append(line)
        except (EOFError,OSError):evidence.append('%Error: incomplete compressed RTL log\n')
    rtl=''.join(evidence)
    rtl_roi=[]
    for line in re.findall(r'EC_OPT4_ROI ([^\r\n]*)',rtl):
        f=dict(re.findall(r'(\w+)=(\w+)',line))
        try:
            rtl_roi.append({'command':int(f['token'],16)&0xff,
                **{k:int(f[k],16) for k in ['epoch','state','begin','end','generated',
                    'completed','passed','failed','cancelled','dropped','faults']},
                'busy':int(f['busy'],10)})
        except (KeyError,ValueError):
            rtl_roi.append({'malformed':line})
    exitstate=json.loads((attempt/'exit.json').read_text()) if (attempt/'exit.json').exists() else {'returncode':None}
    reasons=[]
    if identity(receipts(console,m['receipts'],m.get('profile','formal')))!=m['identity']:reasons.append('bound artifact identity changed')
    if console=='htif' and attest(m['receipts']['rootfs']['value'],m['receipts']['apps']['value'],m['receipts']['apps']['sha256'])!=m['image_attestation']:
        reasons.append('actual cpio application attestation changed')
    if exitstate['returncode']!=0:reasons.append('simulator exit was nonzero/interrupted')
    command_log=attempt/'commands.jsonl'
    command_records=[json.loads(line) for line in command_log.read_text().splitlines()] if command_log.exists() else []
    sent_guest=[x for x in command_records if x.get('kind')=='guest']
    sent_shutdown=[x for x in command_records if x.get('kind')=='shutdown']
    if len(sent_guest)!=1 or sent_guest[0].get('command')!=m['guest_command']:
        reasons.append('guest command was not sent exactly once through SimUART stdin')
    if len(sent_shutdown)!=1 or sent_shutdown[0].get('command')!=m.get('shutdown_command'):
        reasons.append('sync/poweroff command was not sent exactly once')
    if console=='htif':
        if uart.count('EC_OPT4_COMMAND command='+m['guest_command'])!=1 or uart.count('EC_OPT4_CONSOLE_EXIT code=0')!=1:
            reasons.append('bound init command or actual guest command exit was not uniquely observed')
        if uart.count('EC_OPT4_INTEGRITY transport=immutable_initramfs host_verification=REQUIRED')!=1:
            reasons.append('native host-image integrity profile was not observed in guest')
    if 'reboot: Power down' not in uart and 'Power down' not in uart:
        reasons.append('guest normal poweroff completion was not observed')
    mode=m['mode'];end='EC_OPT4_LINUX_END mode='+mode+' correctness=PASS application_exit=0'
    if uart.count(end)!=1:reasons.append('no unique successful application/output check')
    if uart.count('EC_OPT4_APPLICATION_EXIT code=0 capture_exit=0')!=1:
        reasons.append('application or guest-side output capture did not exit cleanly')
    apps=m['receipts']['apps']['value']
    if mode=='smoke':
        if uart.count('DAC_SMOKE checksum=500500 expected=500500')!=1:
            reasons.append('smoke checksum output missing or incorrect')
    else:
        input_name={'test':'in_4.txt','simsmall':'in_4K.txt'}[mode]
        input_path='inputs/'+mode+'/'+input_name
        expected_input=apps['inputs'][mode]['files'][input_name]
        input_line=expected_input+'  '+input_path
        if uart.count(input_line)!=1:
            reasons.append('executed PARSEC input hash does not match the prepared sample')
        input_file=Path(apps['output'])/input_path
        with input_file.open() as source:
            row_header=source.readline().strip()
        if not row_header.isdecimal() or int(row_header)<1:
            reasons.append('prepared PARSEC input has an invalid output-count header')
            expected_rows=0
        else:
            expected_rows=int(row_header)
        correctness=(f'BLACKSCHOLES_OUTPUT_VALID count={expected_rows} '
                     'absolute_tolerance=0.0001')
        if uart.count(correctness)!=1:
            reasons.append('Blackscholes reference-value check missing or incorrect')
    if 'EC_OPT4_INVALID' in uart or 'Kernel panic' in uart:reasons.append('invalid scope or kernel failure')
    contexts=re.findall(r'EC_OPT4_CONTEXT .*satp=([0-9a-fA-F]+).*hardware_initialized=1',uart)
    if len(contexts)!=1:reasons.append('missing/duplicate Linux checker context')
    snapshots=re.findall(r'EC_OPT4_SNAPSHOT ([^\r\n]*)',uart)
    if len(snapshots)!=2:reasons.append('expected one END and one DRAIN hardware snapshot')
    fields=dict(re.findall(r'(\w+)=(\w+)',snapshots[-1])) if snapshots else {}
    try:
        counts={k:int(fields[k]) for k in ['begin','end','drain','generated','completed','outstanding','faults','passed','failed','cancelled','dropped']}
        if not (counts['end']>counts['begin'] and counts['drain']>=counts['end']):reasons.append('invalid source ROI/drain time')
        if not (counts['generated']>0 and counts['generated']==counts['completed']==counts['passed']):reasons.append('real task accounting failed')
        if any(counts[k] for k in ['outstanding','faults','failed','cancelled','dropped']):reasons.append('checker faults/backlog')
    except (ValueError,KeyError):counts={};reasons.append('missing/malformed hardware snapshot')
    if not counts and rtl_roi and 'malformed' not in rtl_roi[-1]:
        last=rtl_roi[-1]
        counts={'begin':last['begin'],'end':last['end'],'drain':0,
                'generated':last['generated'],'completed':last['completed'],
                'passed':last['passed'],'failed':last['failed'],
                'cancelled':last['cancelled'],'dropped':last['dropped'],
                'faults':last['faults'],
                'outstanding':max(0,last['generated']-last['completed'])}
    fault_bits=counts.get('faults',0)
    fault_flags={'time_overflow':bool(fault_bits & 1),
                 'invalid_roi_marker':bool(fault_bits & 2),
                 'ambiguous_roi_marker':bool(fault_bits & 4),
                 'exception_privilege_or_satp':bool(fault_bits & 8),
                 'failed_cancelled_or_dropped_task':bool(fault_bits & 16)}
    drained=re.findall(r'EC_OPT4_CONTEXT_DRAINED ([^\r\n]*)',uart)
    parked=dict(re.findall(r'(\w+)=(\w+)',drained[0])) if len(drained)==1 else {}
    try:
        if int(parked['firmware'],16)!=15 or parked['epoch']!=fields['epoch'] or parked['satp']!=contexts[0]:
            reasons.append('firmware checker context did not park consistently')
        if any(int(parked[k])!=counts[k] for k in ['generated','completed','outstanding']):
            reasons.append('teardown accounting differs from final hardware snapshot')
    except (ValueError,KeyError,IndexError):reasons.append('missing final context teardown proof')
    installed=re.findall(r'EC_OPT4_INSTALLED hart=(\d+) satp=([0-9a-fA-F]+)',uart)
    if len(installed)!=4 or {int(h) for h,s in installed}!={1,2,3,4} or any(s!=contexts[0] for h,s in installed if contexts):
        reasons.append('missing/mismatched checker address-space installation')
    packages=re.findall(r'EC_OPT4_PACKAGE_BEGIN hart=\s*(\d+) seq=([0-9a-f]+) satp=([0-9a-f]+) prv=\s*(\d+)',rtl)
    results=re.findall(r'EC_OPT4_PACKAGE_RESULT hart=\s*(\d+) seq=([0-9a-f]+) status=\s*(\d+) full_compare=([01]) cancelled=([01])',rtl)
    if not packages or not results:reasons.append('missing actual RTL participation events')
    expected=int(contexts[0],16) if len(contexts)==1 else None
    if any(int(h) not in range(1,5) or int(s,16)!=expected or int(p)!=0 for h,q,s,p in packages):reasons.append('checker hart/satp/privilege mismatch')
    if any(int(s)!=0 or c!='1' or x!='0' for h,q,s,c,x in results):reasons.append('RTL comparison did not PASS')
    begins=[(int(h),int(q,16)) for h,q,s,p in packages]
    ends=[(int(h),int(q,16)) for h,q,s,c,x in results]
    if any(q==0 for h,q in begins+ends):reasons.append('zero is not a valid package sequence')
    if len(set(begins))!=len(begins) or len(set(ends))!=len(ends) or set(begins)!=set(ends):
        reasons.append('RTL package/result sequence mismatch or duplicates')
    if len(begins)!=counts.get('generated') or len(ends)!=counts.get('completed'):
        reasons.append('RTL events disagree with BOOM result/release counters')
    if rtl_roi and 'malformed' not in rtl_roi[-1] and counts:
        last=rtl_roi[-1]
        if any(last[k]!=counts[k] for k in ['generated','completed','passed','failed',
                                             'cancelled','dropped','faults']):
            reasons.append('RTL request snapshot disagrees with Linux hardware snapshot')
    if re.search(r'Assertion failed|%Error|Aborted',rtl,re.I):reasons.append('RTL assertion/fatal')
    appsha=m['receipts']['apps']['sha256']
    if appsha+'  BUILD.json' not in uart:reasons.append('guest software manifest mismatch')
    verdict={'valid':not reasons,'reasons':reasons,'identity':m['identity'],'mode':mode,
             'cycles':counts.get('end',0)-counts.get('begin',0),'drain_cycles':counts.get('drain',0)-counts.get('end',0),
             'hardware':counts,'rtl_packages':len(packages),'rtl_results':len(results),
             'rtl_request_snapshots':rtl_roi,
             'latched_fault_flags':fault_flags,
             'exception_event_count':'not_available; any exception sets exception_privilege_or_satp',
             'raw_files':{str(p):sha(p) for p in raw.iterdir() if p.is_file()},
             'exit':exitstate,'slowdown_eligible':False,'strict_latency':'NOT_IMPLEMENTED',
             'console':console,'image_attestation':m.get('image_attestation'),
             'runtime_validation':'PASS' if not reasons else 'INVALID'}
    write(attempt/'verification.json',verdict)
    if not reasons:
        dest=RESULTS/'complete'/(attempt.name+'.json');dest.parent.mkdir(parents=True,exist_ok=True)
        tmp=attempt/'completion.tmp'
        with tmp.open('x') as f:json.dump({**verdict,'attempt':str(attempt)},f,indent=2);f.flush();os.fsync(f.fileno())
        if dest.exists():
            if json.loads(dest.read_text())!={**verdict,'attempt':str(attempt)}:raise ValueError('existing completion differs')
        else:os.link(tmp,dest)
        tmp.unlink()
        dirfd=os.open(dest.parent,os.O_RDONLY|os.O_DIRECTORY)
        try:os.fsync(dirfd)
        finally:os.close(dirfd)
    print(json.dumps(verdict,indent=2));return 0 if not reasons else 1
def run(attempt):
    m=json.loads((attempt/'manifest.json').read_text())
    if m.get('runner_sha256') and m['runner_sha256']!=sha(Path(__file__).resolve()):
        raise ValueError('Linux runner changed after preparation')
    console=m.get('console','uart')
    if identity(receipts(console,profile=m.get('profile','formal')))!=m['identity']:raise ValueError('stale preparation')
    if (attempt/'STARTED.json').exists() or (attempt/'exit.json').exists():
        raise ValueError('attempt already started; prepare a new attempt instead of overwriting logs')
    if m.get('integrity_helper_sha256') and sha(Path(__file__).with_name('opt4_image_integrity.py'))!=m['integrity_helper_sha256']:
        raise ValueError('image integrity helper changed after preparation')
    if 'preload' in m:
        for path,key in [(m['preload']['path'],'sha256'),(m['preload']['elf'],'elf_sha256')]:
            if sha(path)!=m['preload'][key]:raise ValueError('stale native preload: '+path)
    raw=Path(m['raw_dir']);uart=Path(m.get('console_file',str(raw/'uart0')));offset=0;rtl_offset=0
    observed_begin=0;observed_result=0;last_snapshot=0;rtl_tail=b''
    console_tail='';guest_sent=False;shutdown_sent=False;returncode=None
    guest_end=f"EC_OPT4_LINUX_END mode={m['mode']} correctness=PASS application_exit=0"
    child=None;host_console=None;last_target_cycle=0;host_start=time.monotonic()
    def terminate(sig,frame):
        if child and child.poll() is None:child.terminate()
    signal.signal(signal.SIGTERM,terminate)
    try:
        with (raw/'rtl.log.gz').open('xb',buffering=0) as log, gzip.GzipFile(fileobj=log,mode='wb',compresslevel=1,mtime=0) as compressed, (raw/'progress.jsonl').open('x') as progress, (attempt/'commands.jsonl').open('x',buffering=1) as command_log:
            env=os.environ.copy();env.pop('LD_PRELOAD',None)
            if console=='htif':host_console=uart.open('xb',buffering=0)
            child=subprocess.Popen(m['argv'],cwd=attempt,env=env,stdin=subprocess.PIPE,
                stdout=host_console if console=='htif' else subprocess.PIPE,
                stderr=subprocess.PIPE if console=='htif' else subprocess.STDOUT)
            rtl_stream=child.stderr if console=='htif' else child.stdout
            os.set_blocking(rtl_stream.fileno(),False)
            selector=selectors.DefaultSelector();selector.register(rtl_stream,selectors.EVENT_READ)
            output_open=True
            started=datetime.datetime.now(datetime.timezone.utc).isoformat()
            process={'pid':child.pid,'started_at':started,'identity':m['identity'],
                     'runner_pid':os.getpid(),'profile':m.get('profile','formal'),
                     'argv':m['argv'],'stdin_transport':'unused; command is bound to guest init' if console=='htif' else 'SimUART UART0 pipe','raw_dir':str(raw)}
            write(attempt/'STARTED.json',process)
            write(attempt/'process.json',process)
            def send_guest(kind,command):
                record={'utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),
                        'kind':kind,'command':command,'transport':'SimUART UART0 stdin'}
                child.stdin.write((command+'\n').encode());child.stdin.flush()
                command_log.write(json.dumps(record)+'\n');command_log.flush();os.fsync(command_log.fileno())
                print('Sent guest '+kind+' command: '+command,flush=True)
            while True:
                for key,event in selector.select(timeout=.2):
                    chunk=os.read(rtl_stream.fileno(),1<<20)
                    if not chunk:
                        selector.unregister(rtl_stream);output_open=False
                    else:
                        compressed.write(chunk);rtl_offset+=len(chunk)
                        lines=(rtl_tail+chunk).split(b'\n');rtl_tail=lines.pop()
                        observed_begin+=sum(b'EC_OPT4_PACKAGE_BEGIN ' in line for line in lines)
                        observed_result+=sum(b'EC_OPT4_PACKAGE_RESULT ' in line for line in lines)
                        cycles=re.findall(rb'(?<![\w_])cycle=([0-9a-fA-F]+)',b'\n'.join(lines))
                        if cycles:last_target_cycle=max(last_target_cycle,int(cycles[-1],16))
                if uart.exists():
                    with uart.open('rb') as stream:stream.seek(offset);data=stream.read();offset+=len(data)
                    if data:
                        decoded=data.decode('utf-8',errors='replace')
                        console_tail=(console_tail+decoded)[-8192:]
                        if console=='htif':
                            for kind,command,seen in [('guest',m['guest_command'],guest_sent),('shutdown',m['shutdown_command'],shutdown_sent)]:
                                if not seen and 'EC_OPT4_COMMAND command='+command in console_tail:
                                    command_log.write(json.dumps({'utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),
                                        'kind':kind,'command':command,'transport':'observed real guest init invocation'})+'\n')
                                    command_log.flush();os.fsync(command_log.fileno())
                                    if kind=='guest':guest_sent=True
                                    else:shutdown_sent=True
                                    print('Observed guest '+kind+' command: '+command,flush=True)
                        elif not guest_sent and 'EC_OPT4_C4_V6_BOOT' in console_tail and \
                                re.search(r'(?:^|[\r\n])[^\r\n]{0,64}[#$] ?$',console_tail):
                            send_guest('guest',m['guest_command']);guest_sent=True
                        if console!='htif' and guest_sent and not shutdown_sent and guest_end in console_tail:
                            send_guest('shutdown',m['shutdown_command']);shutdown_sent=True
                if time.monotonic()-last_snapshot>=5:
                    progress.write(json.dumps({'utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),
                        'identity':m['identity'],'uart_bytes':offset,'rtl_bytes':rtl_offset,
                        'observed_package_begin':observed_begin,'observed_result_enqueue':observed_result,
                        'last_observed_boom_cycle':last_target_cycle,
                        'host_elapsed_seconds':time.monotonic()-host_start,
                        'guest_command_sent':guest_sent,'shutdown_sent':shutdown_sent,
                        'completion':'UNCOMMITTED','formal_sample':False})+'\n')
                    progress.flush();os.fsync(progress.fileno());compressed.flush();os.fsync(log.fileno())
                    if uart.exists():
                        with uart.open('rb') as stream:os.fsync(stream.fileno())
                    last_snapshot=time.monotonic()
                if not output_open:
                    returncode=child.wait()
                    break
            selector.close();compressed.close();os.fsync(log.fileno())
            if child.stdin:child.stdin.close()
            write(attempt/'exit.json',{'returncode':returncode,'identity':m['identity'],
                'wall_seconds':time.monotonic()-host_start,'last_observed_boom_cycle':last_target_cycle,
                'guest_command_sent':guest_sent,'shutdown_sent':shutdown_sent})
    finally:
        if child and child.poll() is None:child.terminate()
        if host_console:os.fsync(host_console.fileno());host_console.close()
    return verify(attempt)
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('action',choices=['prepare','run','verify'])
    p.add_argument('--mode',choices=['smoke','test','simsmall'],default='smoke');p.add_argument('--attempt',type=Path)
    p.add_argument('--console',choices=['uart','htif'],default='htif')
    p.add_argument('--profile',choices=['formal','diagnostic36','diagnostic36-small'],default='formal')
    p.add_argument('--max-cycles',type=int,default=20000000)
    a=p.parse_args()
    if a.max_cycles<=0:p.error('--max-cycles must be positive')
    if a.action=='prepare':prepare(a.mode,a.console,a.max_cycles,a.profile);return 0
    if a.attempt is None:p.error('--attempt required')
    attempt=a.attempt.resolve()
    if attempt.parent!=RESULTS/'partial':p.error('invalid attempt path')
    return run(attempt) if a.action=='run' else verify(attempt)
if __name__=='__main__':raise SystemExit(main())
