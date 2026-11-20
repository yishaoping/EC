#!/usr/bin/env python3
"""Record actual network app paths and protocol limits without replacing workloads."""
import datetime as dt
import json
from pathlib import Path
from board_batch import W,D,save,sha

P=Path('/data1/gzh/EC/Software/PARSEC')


def witness(path,needles):
    rows=path.read_text().splitlines()
    found=[dict(line=n,text=line.strip()) for n,line in enumerate(rows,1) if any(s in line for s in needles)]
    assert found,path
    return dict(path=str(path),sha256=sha(path),matches=found)


def main():
    facts={}
    for name,source,needles,chain in [
        ('netdedup','server/encoder.c',['__parsec_roi_begin();','__parsec_roi_end();','SerialIntegratedPipeline(&generic_args);','r = recv(','r = uptcp_recv(','int fd_out = create_output_file'],
         'Original serial ROI calls SerialIntegratedPipeline, which creates output, receives data, chunks/deduplicates/compresses and writes the result.'),
        ('netferret','server/benchmark/ferret-pthreads.c',['__parsec_roi_begin();','__parsec_roi_end();','tpool_create(','tpool_join(','accept(fd0','recv(fd,','send(rank->fd,'],
         'Original ROI creates acceptor/load/segment/extract/vector/rank/output thread pools; those workers accept, receive, compute and send rankings. Requested threads=1 does not remove the pipeline threads.'),
        ('netstreamcluster','server/streamcluster.cpp',['__parsec_roi_begin();','__parsec_roi_end();','streamCluster(stream,','thread_count = create_receive_threads','pthread_create(&thread_id','accept(fd0','recv(fd','send(fd','usleep(100)'],
         'Original ROI calls streamCluster, creates receive threads and performs accept/recv/send with explicit sleeps while streaming and computing.')]:
        pkg=P/'pkgs/netapps'/name
        facts[name]=dict(status='BLOCKED_PROTOCOL_AND_UNPORTED_DEPENDENCY',bound_elf=None,fpga_run=False,
            formal_runconf=witness(pkg/'parsec/simmedium.runconf',['run_exec=','run_args=']),
            wrapper=witness(pkg/'src/run.sh',['PROGARGS_SERVER=','PROGARGS_CLIENT=','RUN_SERVER=','RUN_CLIENT=']),
            original_roi_chain=chain,source=witness(pkg/'src'/source,needles),
            required_resolution='Port the original user TCP stack to RISC-V and prove syscall/context/worker support for the complete original ROI. Moving all network work outside ROI or substituting the standalone benchmark cannot satisfy this workload.')
    facts['netdedup']['argument_parser']=witness(P/'pkgs/netapps/netdedup/src/server/dedup.c',['getopt(argc, argv,','case \'?\':','Unknown option'])
    facts['netdedup']['input_inconsistency']='Official simmedium.runconf invokes bin/netdedup directly with -p and -i media.dat, but the actual server getopt string cuvo:w:t:h does not accept p or i. The source wrapper starts a distinct client/server pair and maps simmedium client to test.dat. This is a concrete upstream CLI/input mismatch, not a claimed runtime or cross-compile test; no silent substitution authorized.'
    facts['netstreamcluster']['input_inconsistency']='Official simmedium.runconf literally invokes run.sh 1 simlarge. Preserve that actual workload or explicitly resolve the upstream label; do not silently use standalone simmedium.'
    stack=P/'pkgs/libs/uptcpip/src'
    dependency=dict(
        build_arch=witness(stack/'Makefile',['ARCH =','include/$(ARCH)','in_cksum_$(ARCH)']),
        machine_arch_directories=sorted(x.name for x in (stack/'include').iterdir() if x.is_dir() and x.name in ['i386','x86_64','riscv','riscv64','aarch64']),
        enabled_stack=witness(P/'pkgs/netapps/netdedup/src/server/Makefile',['ENABLE_PARSEC_UPTCPIP','LIB_UPTCP=','LIB_UPTCP_SIM=']),
        host_threads=witness(stack/'host.support/host_serv.c',['int pthread_create_wrapper','int res = pthread_create(','error = pthread_cond_wait','usleep(num)']),
        stack_roi_auxiliary=witness(stack/'lib/uptcp_api.c',['void parsec_enter_tcpip_roi','void parsec_exit_tcpip_roi','gettimeofday(&global_roi']),
        shared_memory=witness(stack/'host.support/if_host.c',['shmget(shm_key','shmat(shmid']),
        distinction='The default original real-machine path uses user TCP and shared memory; CONFIG_NET=n alone does not prove that path impossible. The simulation/socket fallback additionally needs Linux networking. User-stack worker/context and target architecture portability remain separate issues.',
        cross_compile_attempted=False,compile_failure_claimed=False)
    kernels=[]
    for cfg,prefix in [('Native','freqmine-staged-resident'),('C4','formal-earlyconsole')]:
        receipt=W/f'software/{cfg}/{prefix}-kernel-build.json';r=json.loads(receipt.read_text())
        kernels.append(witness(Path(r['output_dir'])/'.config',['# CONFIG_NET is not set','CONFIG_SYSVIPC=','CONFIG_FUTEX=','CONFIG_SMP']))
    controller=witness(W/'C4/chipyard/generators/rocket-chip/src/main/scala/util/DacRoi.scala',
        ['io.trap || io.prv =/= 0.U || io.satp =/= expectedSatp','faults := faults | 8.U','val matches = io.satp'])
    report=dict(schema='ec-network-original-roi-audit/1',observed_utc=dt.datetime.now(dt.timezone.utc).isoformat(),
        programs=facts,dependency=dependency,kernel_configs=kernels,actual_cad_controller=controller,
        source_level_conclusion='Current C4 ROI contract rejects trap/non-user execution/satp changes while running or draining. Original network APIs are not automatically kernel syscalls when user TCP is enabled, but real worker/thread/blocking paths and architecture port are not proven compatible.',
        hardware_modified=False,workloads_removed=False,other_programs_continue=True,
        unresolved_design='A valid original network run needs a supported complete ROI context protocol. Do not merely mask fault8: that would remove the validity guard without proving checker replay/compare across contexts.')
    save(D/'software/network-original-roi-audit.json',report)
    print(json.dumps(dict(programs=list(facts),status='BLOCKED_PROTOCOL_AND_UNPORTED_DEPENDENCY',evidence=str(D/'software/network-original-roi-audit.json'))))


if __name__=='__main__':main()
