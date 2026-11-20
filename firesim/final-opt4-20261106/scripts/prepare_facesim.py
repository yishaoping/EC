#!/usr/bin/env python3
"""Reuse compiled PhysBAM, bind original ROI sites, validate official computation."""
import datetime as dt
import argparse
import difflib
import json
import os
from pathlib import Path
import re
import shlex
import shutil
import subprocess
import tarfile
from board_batch import W,D,save,sha

P=Path('/data1/gzh/EC/Software/PARSEC');TOOLS=Path('/data1/gzh/EC/firesim/envs/manager-1.17.1/riscv-tools/bin')


def main():
    ap=argparse.ArgumentParser();ap.add_argument('--stage',action='store_true');ap.add_argument('--preload-controls',action='store_true');a=ap.parse_args();assert not a.preload_controls or a.stage;profile='facesim-staged-resident' if a.preload_controls else ('facesim-staged' if a.stage else 'facesim')
    receipt=W/f'software/{profile}-apps-build.json';assert not receipt.exists()
    candidate_path=W/'software/facesim-candidate-build.json';candidate=json.loads(candidate_path.read_text());assert candidate['status']=='COMPILED_NOT_FPGA_READY'
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out=W/'software'/('apps-'+profile+'-'+stamp);logs=D/'software'/out.name;out.mkdir();logs.mkdir()
    src=Path(candidate['source_dir']);build_log=Path(candidate['active_log']).read_text().splitlines()
    main_cmd=next(shlex.split(l) for l in build_log if ' -c ' in l and ' -o obj/main.o ' in l)
    driver_cmd=next(shlex.split(l) for l in build_log if ' -c ' in l and ' -o obj/Solids_And_Fluids/SOLIDS_FLUIDS_DRIVER.o ' in l)
    link_cmd=next(shlex.split(l) for l in reversed(build_log) if ' -Wl,-o,facesim ' in l)
    if a.stage:
        main=src/'Benchmarks/facesim/main.cpp';driver=src/'Public_Library/Solids_And_Fluids/SOLIDS_FLUIDS_DRIVER.cpp'
        oldmain=main.read_text();newmain=oldmain.replace('#include "FACE_DRIVER.h"','#include "FACE_DRIVER.h"\n#include <malloc.h>')
        newmain=newmain.replace('STORYTELLING_EXAMPLE<float, float> example;', '''// Prepare resident heap before original initialization and full ROI.
        mallopt(M_TRIM_THRESHOLD,-1);mallopt(M_MMAP_MAX,0);
        volatile char *ec_heap=(volatile char*)malloc(768*1024*1024);
        if(!ec_heap)exit(125);
        for(size_t i=0;i<768*1024*1024;i+=4096)ec_heap[i]=0;
        free((void*)ec_heap);
        STORYTELLING_EXAMPLE<float, float> example;''')
        newmain=newmain.replace('LOG::Copy_Log_To_File (example.output_directory + "/log.txt", example.restart);','// Auxiliary timing/OS log disabled via existing PhysBAM API. No synthetic times.\n\tLOG::Initialize_Logging(true,true,0);')
        control_patch=''
        if a.preload_controls:
            header=src/'Benchmarks/facesim/Storytelling/STORYTELLING_EXAMPLE.h';oldheader=header.read_text()
            newheader=oldheader.replace('namespace PhysBAM','#include <map>\n#include <sstream>\nnamespace PhysBAM',1)
            newheader=newheader.replace('T control_frame_rate;','T control_frame_rate;\n\tstd::map<std::string,std::string> ec_control_bytes;')
            anchor='control_directory = data_directory + "/Face_Data/Motion_Data/Storytelling_Controls";'
            assert newheader.count(anchor)==1
            newheader=newheader.replace(anchor,anchor+'''\n        // Official one-frame input consumes control frames 1,2. Stage raw
        // bytes only; Read_Binary and interpolation stay at original ROI sites.
        for(int ec_frame=1;ec_frame<=2;ec_frame++) {
          std::string ec_name=control_directory+"/storytelling_controls."+STRING_UTILITIES::string_sprintf("%d",ec_frame);
          std::istream *ec_in=FILE_UTILITIES::Safe_Open_Input(ec_name);
          std::ostringstream ec_bytes;ec_bytes<<ec_in->rdbuf();delete ec_in;
          ec_control_bytes[ec_name]=ec_bytes.str();
        }''')
            for which in ['last','next']:
                needle=f'FILE_UTILITIES::Read_From_File<RW> ({which}_control_filename, input_control_parameters);'
                assert newheader.count(needle)==1
                newheader=newheader.replace(needle,f'''if(ec_control_bytes.find({which}_control_filename)==ec_control_bytes.end())exit(125);
        std::istringstream ec_{which}(ec_control_bytes[{which}_control_filename],std::ios::in|std::ios::binary);
        Read_Binary<RW>(ec_{which},input_control_parameters);''')
            stagedheader=header.with_name('STORYTELLING_EXAMPLE-ec-staged.h');stagedheader.write_text(newheader)
            newmain=newmain.replace('"Storytelling/STORYTELLING_EXAMPLE.h"','"Storytelling/STORYTELLING_EXAMPLE-ec-staged.h"')
            control_patch=''.join(difflib.unified_diff(oldheader.splitlines(True),newheader.splitlines(True),fromfile=str(header),tofile=str(stagedheader)))
        newpath=main.with_name('main-ec-staged.cpp');newpath.write_text(newmain)
        main_cmd[-1]=str(newpath)
        olddriver=driver.read_text();newdriver=olddriver.replace('#include "SOLIDS_FLUIDS_DRIVER.h"','#include "SOLIDS_FLUIDS_DRIVER.h"\n#include <sstream>')
        newdriver=newdriver.replace('#ifdef ENABLE_PARSEC_HOOKS\n\t__parsec_roi_begin();','std::ostringstream ec_messages,ec_errors;\n\tstd::streambuf *ec_cout=std::cout.rdbuf(ec_messages.rdbuf()),*ec_cerr=std::cerr.rdbuf(ec_errors.rdbuf());\n#ifdef ENABLE_PARSEC_HOOKS\n\t__parsec_roi_begin();')
        newdriver=newdriver.replace('__parsec_roi_end();\n#endif','__parsec_roi_end();\n#endif\n\tstd::cout.rdbuf(ec_cout);std::cerr.rdbuf(ec_cerr);\n\tstd::cout<<ec_messages.str();std::cerr<<ec_errors.str();')
        newpath=driver.with_name('SOLIDS_FLUIDS_DRIVER-ec-staged.cpp');newpath.write_text(newdriver);driver_cmd[-1]=str(newpath)
        (logs/'software-integration.patch').write_text(''.join(difflib.unified_diff(oldmain.splitlines(True),newmain.splitlines(True),fromfile=str(main),tofile=str(main.with_name('main-ec-staged.cpp'))))+''.join(difflib.unified_diff(olddriver.splitlines(True),newdriver.splitlines(True),fromfile=str(driver),tofile=str(newpath)))+control_patch)
    parent=json.loads((W/'software/apps-build.json').read_text());base=Path(parent['output_dir']);hooks=base/'src/hooks'
    state=dict(status='BUILDING',pid=os.getpid(),output_dir=str(out),host_log_dir=str(logs),software_profile=profile+'-serial',formal_eligible=True,commands=[],cases=[],parsec_commit=parent['parsec_commit'],candidate_receipt=str(candidate_path),candidate_receipt_sha256=sha(candidate_path),algorithm_sources_modified=False,fpga_validation='NOT_RUN',reused_physbam_library_sha256=sha(Path(candidate['output_dir'])/'lib/libPhysBAM.a'))
    if a.stage:state.update(integration_patch=str(logs/'software-integration.patch'),integration_patch_sha256=sha(logs/'software-integration.patch'),auxiliary_wallclock_report='Disabled with original LOG::Initialize_Logging(true,true,0); FPGA ROI cycles authoritative, no fake times')
    save(logs/'state.json',state);save(D/'software/facesim-preparation-state.json',state)
    env={**os.environ,'PATH':'/usr/bin:/bin','LD_LIBRARY_PATH':'','PHYSBAM_THREADS':'1'}
    def run(argv,cwd=out,stdout=None,stderr=None,timeout=3600):
        argv=list(map(str,argv));state['commands'].append(dict(argv=argv,cwd=str(cwd)));save(logs/'state.json',state);save(D/'software/facesim-preparation-state.json',state)
        child=subprocess.Popen(['nice','-n','15',*argv],cwd=cwd,env=env,stdin=subprocess.DEVNULL,stdout=stdout,stderr=stderr,start_new_session=True)
        state['child_pid']=child.pid;save(D/'software/facesim-preparation-state.json',state)
        try:rc=child.wait(timeout=timeout)
        except subprocess.TimeoutExpired:
            import signal
            os.killpg(child.pid,signal.SIGTERM)
            try:child.wait(timeout=15)
            except subprocess.TimeoutExpired:os.killpg(child.pid,signal.SIGKILL);child.wait()
            raise
        assert rc==0,(rc,argv)
    (out/'diagnostic-hooks.c').write_text('''#include "hooks.h"
#include <unistd.h>
void __parsec_bench_begin(enum __parsec_benchmark b) {(void)b;}
void __parsec_bench_end(void) {}
void __parsec_roi_begin(void) {write(2,"EC_DIAGNOSTIC_ROI_BEGIN\\n",24);}
void __parsec_roi_end(void) {write(2,"EC_DIAGNOSTIC_ROI_END\\n",22);}
''')
    with (logs/'build.log').open('wb') as log:
        run([TOOLS/'riscv64-unknown-linux-gnu-gcc','-O3','-march=rv64gc','-mabi=lp64d','-I'+str(hooks),'-c',out/'diagnostic-hooks.c','-o',out/'diagnostic-hooks.o'],stdout=log,stderr=log)
        for variant,objects in [('real',[base/'hooks.o',base/'dac_roi.o']),('diagnostic',[out/'diagnostic-hooks.o'])]:
            variant_dir=out/variant;variant_dir.mkdir()
            for command,cwd,obj in [(main_cmd,src/'Benchmarks/facesim','main.o'),(driver_cmd,src/'Public_Library','SOLIDS_FLUIDS_DRIVER.o')]:
                argv=command[:];argv[argv.index('-o')+1]=str(variant_dir/obj);argv+=['-DENABLE_PARSEC_HOOKS','-I'+str(hooks)]
                run(argv,cwd=cwd,stdout=log,stderr=log)
            lib=variant_dir/'libPhysBAM.a';shutil.copy2(Path(candidate['output_dir'])/'lib/libPhysBAM.a',lib)
            run([TOOLS/'riscv64-unknown-linux-gnu-ar','r',lib,variant_dir/'SOLIDS_FLUIDS_DRIVER.o'],stdout=log,stderr=log)
            argv=link_cmd[:];argv[argv.index('-Wl,-o,facesim')]='-o';argv.insert(argv.index('-o')+1,str(out/('facesim' if variant=='real' else 'facesim-diagnostic')))
            argv[argv.index('obj/main.o')]=str(variant_dir/'main.o');argv[argv.index('-lPhysBAM')]=str(lib);argv+=list(map(str,objects))
            run(argv,cwd=src/'Benchmarks/facesim',stdout=log,stderr=log)
    archive=P/'pkgs/apps/facesim/inputs/input_simsmall.tar';dest=out/'inputs/facesim/simsmall';dest.mkdir(parents=True)
    with tarfile.open(archive) as tf:
        for m in tf.getmembers():
            if m.isfile():
                p=Path(m.name);assert not p.is_absolute() and '..' not in p.parts;t=dest/p;t.parent.mkdir(parents=True,exist_ok=True);t.write_bytes(tf.extractfile(m).read())
    ref=logs/'reference';shutil.copytree(dest,ref)
    conf=P/'pkgs/apps/facesim/parsec/simsmall.runconf';argv=re.search(r'^run_args="(.*?)"',conf.read_text(),re.M)[1].replace('${NTHREADS}','1').split()
    state.update(status='QEMU_REFERENCE_RUNNING');save(D/'software/facesim-preparation-state.json',state)
    with (ref/'stdout.log').open('wb') as log:run(['/usr/bin/qemu-riscv64',candidate['binary']['path'],*argv],cwd=ref,stdout=log,stderr=log,timeout=7200)
    outputs={str(f.relative_to(ref)):sha(f) for f in (ref/'Storytelling/output').rglob('*') if f.is_file() and f.name not in ['log.txt','log','time','first_frame','last_frame']}
    assert any('deformable_object_1_position' in n for n in outputs), 'no full simulation particle-position output'
    diag=logs/'diagnostic';shutil.copytree(dest,diag)
    state.update(status='QEMU_DIAGNOSTIC_RUNNING');save(D/'software/facesim-preparation-state.json',state)
    with (diag/'trace.log').open('wb') as log:run(['/usr/bin/qemu-riscv64','-strace',out/'facesim-diagnostic',*argv],cwd=diag,stdout=log,stderr=log,timeout=7200)
    assert all(sha(diag/n)==h for n,h in outputs.items()), 'hook integration changed simulation outputs'
    rows=(diag/'trace.log').read_text().splitlines();bi=next(i for i,l in enumerate(rows) if l.endswith('EC_DIAGNOSTIC_ROI_BEGIN'));ei=next(i for i,l in enumerate(rows) if l.endswith('EC_DIAGNOSTIC_ROI_END'))
    calls=[l for l in rows[bi+1:ei] if re.match(r'^\d+ [a-zA-Z_]\w*\(',l)]
    for size in ['simsmall','simmedium']:
        conf=P/f'pkgs/apps/facesim/parsec/{size}.runconf';ar=P/f'pkgs/apps/facesim/inputs/input_{size}.tar'
        assert sha(ar)==sha(archive),'do not alias different inputs'
        if size!='simsmall':shutil.copytree(dest,out/f'inputs/facesim/{size}',copy_function=os.link)
        state['cases'].append(dict(program='facesim',input=size,argv=argv,runconf=str(conf),runconf_sha256=sha(conf),input_archives={str(ar):sha(ar)},input_files={str(f.relative_to(dest)):sha(f) for f in dest.rglob('*') if f.is_file()},threads=1,warmups=0,validation=dict(kind='files_sha256',files=outputs),reference_outputs={str(ref/n):h for n,h in outputs.items()},diagnostic_roi_syscalls=calls,diagnostic_trace=str(diag/'trace.log'),fpga_validation='NOT_RUN',algorithm_unchanged=True,official_simsmall_simmedium_identical=True))
    binary=out/'facesim';state.update(status='PREPARED_FPGA_NOT_RUN',c4_incompatible_reason='Original Facesim ROI contains synchronous IO/timing syscalls; staging required' if calls else None,
        binaries=dict(facesim=dict(path=str(binary),sha256=sha(binary),reference_path=candidate['binary']['path'],reference_sha256=candidate['binary']['sha256'],application_threads=1,algorithm_sources_modified=False)),smoke=parent['smoke'],formal_input_policy='Exact official simmedium archive/argv and full original Simulate_To_Frame ROI; single thread, no warmup; all simulation output hashes, no help-only smoke')
    save(out/'manifest.json',state);save(logs/'result.json',state);save(receipt,state);save(D/'software/facesim-preparation-state.json',state);print(json.dumps(dict(receipt=str(receipt),roi_syscall_count=len(calls),outputs=len(outputs))),flush=True)


if __name__=='__main__':
    try:main()
    except Exception as exc:
        path=D/'software/facesim-preparation-state.json'
        if path.exists():
            state=json.loads(path.read_text());state.update(status='FAILED_WITH_EVIDENCE',error=repr(exc),ended_utc=dt.datetime.now(dt.timezone.utc).isoformat())
            save(path,state);save(Path(state['host_log_dir'])/'state.json',state)
        raise
