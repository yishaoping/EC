#!/usr/bin/env python3
"""Read the exact QEMU kernel panic argument, without changing the kernel."""
import datetime as dt
import argparse
import json
import os
from pathlib import Path
import signal
import subprocess
import time
from board_batch import D,save,sha

def main():
    parser=argparse.ArgumentParser();parser.add_argument('--context',action='store_true');parser.add_argument('--padding',action='store_true');options=parser.parse_args()
    result=D/('software/dedup-padding-context.json' if options.padding else 'software/dedup-boot-gdb-context.json' if options.context else 'software/dedup-boot-gdb.json')
    if result.exists() and json.loads(result.read_text()).get('panic_argument_observed'):return
    previous=json.loads((D/'software/dedup-boot-diagnostic.json').read_text());argv=previous['argv']
    logs=D/'software'/('dedup-boot-gdb-'+dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ'));logs.mkdir()
    sock=logs/'gdb.sock';argv=argv+['-S','-gdb','unix:'+str(sock)+',server=on,wait=off']
    image=Path(argv[argv.index('-kernel')+1]);vmlinux=image.parents[3]/'vmlinux'
    # Image is <build>/arch/riscv/boot/Image.
    assert vmlinux.is_file();assert sha(image)==previous['kernel_sha256']
    context=''
    if options.context or options.padding:
        context='''printf "EC_ARCHIVE_CONTEXT\\n"
p/x *(unsigned long*)&this_header
p/x *(unsigned long*)&next_header
p/x *(unsigned long*)&body_len
p/x *(unsigned long*)&byte_count
x/s *(char**)&name_buf
x/32bx *(char**)&victim
'''
    breakpoint='break *panic_show_mem'
    argument='$a1'
    if options.padding:
        # Addresses are tied to this exact vmlinux SHA and disassembly, not a
        # portable assumption. Catch the first error before unpacker cleanup.
        assert previous['kernel_sha256']=='689d981a568d7031ed6e7eecd91457a54f1b1a5fbf76d5009b2e22d8f82cd77d'
        breakpoint='break *0xffffffff80601a0e if $a0 == 0xffffffff83275418'
        argument='$a0'
    gdb=logs/'inspect.gdb';gdb.write_text(f'''set pagination off
set confirm off
file {vmlinux}
target remote {sock}
{breakpoint}
continue
printf "EC_KERNEL_PANIC_FORMAT: "
x/s $a0
printf "EC_KERNEL_PANIC_ARGUMENT: "
x/s {argument}
{context}
bt
monitor quit
''')
    state=dict(status='RUNNING',diagnostic_only=True,unchanged_kernel_sha256=previous['kernel_sha256'],log_dir=str(logs),argv=argv,pid=os.getpid());save(result,state)
    with (logs/'qemu.log').open('wb') as log:
        q=subprocess.Popen(argv,stdin=subprocess.DEVNULL,stdout=log,stderr=subprocess.STDOUT,start_new_session=True,env={**os.environ,'LD_LIBRARY_PATH':''})
        state['child_pid']=q.pid;save(result,state)
        try:
            deadline=time.monotonic()+20
            while not sock.exists() and q.poll() is None and time.monotonic()<deadline:time.sleep(.2)
            assert sock.exists(),str(logs/'qemu.log')
            with (logs/'gdb.log').open('wb') as output:
                debugger=subprocess.Popen(['/usr/bin/gdb-multiarch','-q','-batch','-x',str(gdb)],stdin=subprocess.DEVNULL,stdout=output,stderr=subprocess.STDOUT,start_new_session=True)
                try:rc=debugger.wait(timeout=180)
                except subprocess.TimeoutExpired:os.killpg(debugger.pid,signal.SIGTERM);debugger.wait(timeout=10);raise
            text=(logs/'gdb.log').read_text(errors='replace')
            observed='EC_KERNEL_PANIC_ARGUMENT:' in text
            state.update(status='COMPLETE' if observed else 'FAILED_WITH_EVIDENCE',gdb_returncode=rc,gdb_log=str(logs/'gdb.log'),panic_argument_observed=observed)
        except Exception as exc:state.update(status='FAILED_WITH_EVIDENCE',error=repr(exc));raise
        finally:
            if q.poll() is None:
                os.killpg(q.pid,signal.SIGTERM)
                try:q.wait(timeout=10)
                except subprocess.TimeoutExpired:os.killpg(q.pid,signal.SIGKILL);q.wait()
            save(result,state)

if __name__=='__main__':main()
