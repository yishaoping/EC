import sys
sys.path.insert(0, '/data1/gzh/EC/firesim/final-opt4-20261106/runtime/Opt4-fit-11edd719/scripts')
sys.path.insert(1, '/data1/gzh/EC/firesim/final-opt4-20261106/scripts')
#!/usr/bin/env python3
"""Hardware-free integration/failure tests. Fixtures never enter real runs."""
import copy
import contextlib
import fcntl
import hashlib
import json
import io
import os
from pathlib import Path
import tempfile
from unittest.mock import patch

from board_batch import W,D,sha
import board_batch as board
import opt4_fit_runtime_guard as guard
import continue_opt4_fit as run
import run_isolated_sample as runner
import coverage_first
import prepare_opt4_fit_runtime as preparation


def write(p,x):
    p.parent.mkdir(parents=True,exist_ok=True);p.write_text(json.dumps(x,sort_keys=True)+'\n')


def main():
    report=D/'unattended-opt4/11edd719-runtime-offline-validation.json'
    checks=[]
    def good(name,f):f();checks.append(dict(check=name,status='PASS_OFFLINE_FIXTURE'))
    def rejects(name,f):
        try:f()
        except (AssertionError,ValueError,RuntimeError,StopIteration,BlockingIOError):
            checks.append(dict(check=name,status='PASS_REJECTED_FIXTURE'));return
        raise AssertionError('fixture was accepted: '+name)
    with tempfile.TemporaryDirectory(prefix='ec-opt4-fit-offline-',dir=report.parent) as td:
        temp=Path(td);rt=temp/'runtime';certpath=rt/'certified-build.json';priority=temp/'priority.json'
        bit=rt/'firesim.bit';bit.parent.mkdir();bit.write_bytes(b'SYNTHETIC TEST FIXTURE NOT A BITSTREAM')
        cert=dict(status='CERTIFIED_DERIVED_ARTIFACT_NOT_RUNTIME_VALIDATED',hardware_commit=guard.COMMIT,
            source_id=guard.SOURCE,profile=guard.PROFILE,frozen_parent_commit=guard.FROZEN,
            part='xcu280-fsvh2892-2L-e',configuration='DacOpt4C4',returncode=0,
            certified_bitstream=True,formal_admission=False,durable_bitstream=str(bit),durable_bitstream_sha256=sha(bit),
            stages={n:dict(returncode=0,source_id=guard.SOURCE,hardware_commit=guard.COMMIT)
                for n in ['dut_synth','top_synth','implementation','timing_bitstream']},
            top_postopt_resources={n:dict(used=1,available=100) for n in ['CLB LUTs','CARRY8','DSPs','CLB Registers','Block RAM Tile','URAM']})
        write(certpath,cert)
        with patch.multiple(guard,CERT=certpath,RUNTIME=rt,PRIORITY=priority):
            good('exact derived artifact accepted',lambda:guard.artifact(certpath))
            for field,bad in [('source_id','old-source'),('hardware_commit',guard.FROZEN),('profile','C4'),
                              ('status','RUNNING'),('certified_bitstream',False),('durable_bitstream_sha256','bad')]:
                x=copy.deepcopy(cert);x[field]=bad;write(certpath,x)
                rejects('reject '+field,lambda:guard.artifact(certpath))
            write(certpath,cert)
            x=copy.deepcopy(cert);x['top_postopt_resources']['CLB LUTs']['used']=101;write(certpath,x)
            rejects('reject NOT FIT fixture',lambda:guard.artifact(certpath));write(certpath,cert)
            p=dict(status='ACTIVE',board_bdf=guard.BDF,board_serial=guard.SERIAL,hardware_commit=guard.COMMIT,
                   source_id=guard.SOURCE,certificate_sha256=sha(certpath));write(priority,p)
            rejects('legacy new launch yields to derived priority',lambda:guard.priority_guard())
            good('exact derived owner passes priority',lambda:guard.priority_guard(certpath))
            p['board_bdf']='0000:e2:00.0';write(priority,p)
            rejects('priority wrong BDF rejected',lambda:guard.priority_guard(certpath));priority.unlink()

            i=dict(configuration='C4',board_bdf=guard.BDF,board_serial=guard.SERIAL,
                   hardware_source_id=guard.SOURCE,bitstream_sha256=sha(bit))
            good('derived identity records actual commit',lambda:guard.add_identity(i,certpath))
            assert i['hardware_commit']==guard.COMMIT and i['hardware_commit']!=guard.FROZEN
            bad=dict(i,board_bdf='0000:e2:00.0')
            rejects('derived sample e2 rejected',lambda:guard.add_identity(bad,certpath))

            # Exercise actual board deployment function with every IO seam
            # replaced. A real target-card command must name 21 only.
            fakeW=temp/'work';(fakeW/'deployment-tools').mkdir(parents=True)
            (fakeW/'deployment-tools/fpga-util.py').write_text('# inert fixture\n')
            write(fakeW/'native-reuse.json',{})
            out=temp/'deployment';out.mkdir();trace=[]
            def save(p,x):write(p,x)
            def precheck(**kwargs):
                assert kwargs['target_bdfs']==[guard.BDF];return dict(open_devices=[],simulation_processes=[])
            def jtag(out,serials):assert serials==[guard.SERIAL]
            def command(argv,*args,**kwargs):
                trace.append(list(map(str,argv)));assert argv[2:4]==['--extended-bdf',guard.BDF]
                assert not any('e2' in str(v) or str(v) in ['--all-bdfs','--all-serials'] for v in argv)
            with patch.multiple(board,W=fakeW,D=temp,precheck=precheck,ensure_jtag_server=jtag,command=command,save=save):
                with contextlib.redirect_stdout(io.StringIO()):
                    good('real deploy function chooses only 21 tool command',lambda:board.deploy_native(out,single_c4_bdf=guard.BDF,opt4_fit_receipt=certpath))
                assert len(trace)==1
                dep=json.loads((temp/'latest-deployment.json').read_text())
                assert dep['global_operations']==[] and dep['completed_cards'][0]['hardware_commit']==guard.COMMIT
                rejects('real deploy function e2 rejected',lambda:board.deploy_native(out,single_c4_bdf='0000:e2:00.0',opt4_fit_receipt=certpath))
                rejects('real deploy function dual card rejected',lambda:board.deploy_native(out,pair=True,opt4_fit_receipt=certpath))

        lock=temp/'maintenance.lock'
        with lock.open('a') as first,lock.open('a') as second:
            fcntl.flock(first,fcntl.LOCK_SH|fcntl.LOCK_NB)
            rejects('active sample shared lock prevents deployment',lambda:fcntl.flock(second,fcntl.LOCK_EX|fcntl.LOCK_NB))
        with lock.open('a') as first,lock.open('a') as second:
            fcntl.flock(first,fcntl.LOCK_EX|fcntl.LOCK_NB)
            rejects('deployment exclusive lock prevents new sample',lambda:fcntl.flock(second,fcntl.LOCK_SH|fcntl.LOCK_NB))

        suite=json.loads((W/'runtime/Opt4-fit-8da24a26/software-suite.json').read_text());suite.update(hardware_commit=guard.COMMIT,source_id=guard.SOURCE,profile=guard.PROFILE);results=[];bitsha='fixture-bit'
        def add(row,size,rep,name=None):
            name=name or row['program']
            i=dict(configuration='C4',hardware_commit=guard.COMMIT,hardware_source_id=guard.SOURCE,
                hardware_profile=guard.PROFILE,board_bdf=guard.BDF,board_serial=guard.SERIAL,
                program=name,input=size,repetition=rep,threads=1,warmups=0,bitstream_sha256=bitsha,
                rootfs_sha256=row['rootfs_sha256'],elf_sha256=row['elf_sha256'],
                apps_manifest_sha256=row['receipt_sha256']['apps'],
                firmware_receipt_sha256=row['receipt_sha256']['firmware'],driver_receipt_sha256=row['receipt_sha256']['driver'])
            results.append((Path('fixture'),dict(valid=True,formal=size=='simmedium',identity=i)))
        task=run.next_task(suite,[],{},bitsha);assert task[1]=='smoke'
        add(suite['programs'][0],'test',1,'smoke')
        for row in suite['programs']:
            for size in row['input_sizes']:
                if size!='simmedium':add(row,size,1)
        task=run.next_task(suite,results,{},bitsha);assert task[1]==suite['programs'][0]['program'] and task[3]==1
        add(suite['programs'][0],'simmedium',1)
        task=run.next_task(suite,results,{},bitsha);assert task[1]==suite['programs'][1]['program'] and task[3]==1
        failed={task[4]:{'fixture':True}}
        task2=run.next_task(suite,results,failed,bitsha);assert task2[1]==suite['programs'][2]['program'] and task2[3]==1
        checks.append(dict(check='coverage r1 before r2; failed program does not block next',status='PASS_OFFLINE_FIXTURE'))
        old=copy.deepcopy(results);old[0][1]['identity']['hardware_commit']=guard.FROZEN
        assert run.next_task(suite,old,{},bitsha)[1]=='smoke'
        checks.append(dict(check='old frozen C4 result cannot validate derived smoke',status='PASS_OFFLINE_FIXTURE'))
        for row in suite['programs'][1:]:add(row,'simmedium',1)
        assert run.next_task(suite,results,{},bitsha)[3]==2
        for row in suite['programs']:
            for rep in [2,3]:add(row,'simmedium',rep)
        assert run.next_task(suite,results,{},bitsha) is None
        checks.append(dict(check='all 39 valid fixture samples skipped; no duplicate work',status='PASS_OFFLINE_FIXTURE'))

        # Strict existing checker parser: matching full comparison is required.
        out=temp/'checker';out.mkdir();i=dict(configuration='C4',run_id='fixture',memory_model=dict(settings={}))
        uart='EC_SAMPLE_GUEST_DONE run_id=fixture ok\nEC_COMMAND_EXIT=0\n'
        snap='epoch=1 begin=10 end=20 drain=25 generated=1 completed=1 outstanding=0 faults=0 passed=1 failed=0 cancelled=0 dropped=0'
        uart+='EC_OPT4_SNAPSHOT '+snap+'\nEC_OPT4_SNAPSHOT '+snap+'\n'
        uart+='EC_OPT4_CONTEXT satp=abc hardware_initialized=1\n'
        uart+=''.join(f'EC_OPT4_INSTALLED hart={n} satp=abc\n' for n in range(1,5))
        uart+='EC_OPT4_CONTEXT_DRAINED firmware=f satp=abc epoch=1 generated=1 completed=1 outstanding=0\n'
        (out/'uart.log').write_text(uart);(out/'host.log').write_text('')
        event='EC_OPT4_PACKAGE_BEGIN hart=1 seq=1 satp=abc prv=0\nEC_OPT4_PACKAGE_RESULT hart=1 seq=1 status=0 full_compare=1 cancelled=0\n'
        (out/'rtl-events-0').write_text(event)
        assert runner.verify(out,i,0,False,False)['valid']
        (out/'rtl-events-0').write_text(event.replace('full_compare=1','full_compare=0'))
        assert not runner.verify(out,i,0,False,False)['valid']
        checks.append(dict(check='actual checker verifier rejects disabled full comparison',status='PASS_OFFLINE_FIXTURE'))
        (out/'rtl-events-0').write_text(event.splitlines()[0]+'\n')
        assert not runner.verify(out,i,0,False,False)['valid']
        checks.append(dict(check='actual verifier rejects uncompleted checker task',status='PASS_OFFLINE_FIXTURE'))

        # Execute the actual controller with all process/device seams mocked.
        # Exercise ready -> busy -> deploy -> smoke -> skip failure -> 36 valid
        # formal fixture samples -> yield. No fixture enters campaign runs.
        sim=temp/'controller';sim.mkdir();(sim/'locks').mkdir()
        simcert=sim/'cert.json';write(simcert,{'fixture':True})
        simsuite=sim/'suite.json';write(simsuite,suite)
        simstate=sim/'state.json';simlogs=sim/'logs';simpriority=sim/'priority.json'
        simulation_results=[];trace=[];sleeps=[];busy=[True]
        class FakeProcess:
            pid=os.getpid()
            returncode=0
            def __init__(self,argv,**kwargs):
                self.returncode=0;trace.append(list(argv))
                if 'board_batch.py' in argv[1]:
                    assert argv[argv.index('--single-c4-bdf')+1]==guard.BDF
                    write(sim/'latest-deployment.json',dict(host_boot_id='fixture-boot',status='DEPLOYED_NOT_RUN',started_utc='fixture-time',
                        completed_cards=[dict(bdf=guard.BDF,hardware_commit=guard.COMMIT,hardware_profile=guard.PROFILE,
                            bitstream_sha256=bitsha,derived_build_receipt_sha256=sha(simcert))]))
                elif 'run_isolated_sample.py' in argv[1]:
                    program,size=argv[3:5];rep=int(argv[argv.index('--repetition')+1])
                    row=next(r for r in suite['programs'] if r['program']==('blackscholes' if program=='smoke' else program))
                    assert argv[argv.index('--bdf')+1]==guard.BDF
                    assert argv[argv.index('--opt4-fit-receipt')+1]==str(simcert)
                    ident=dict(configuration='C4',hardware_commit=guard.COMMIT,hardware_source_id=guard.SOURCE,
                        hardware_profile=guard.PROFILE,board_bdf=guard.BDF,board_serial=guard.SERIAL,
                        program=program,input=size,repetition=rep,threads=1,warmups=0,bitstream_sha256=bitsha,
                        rootfs_sha256=row['rootfs_sha256'],elf_sha256=row['elf_sha256'],
                        apps_manifest_sha256=row['receipt_sha256']['apps'],firmware_receipt_sha256=row['receipt_sha256']['firmware'],
                        driver_receipt_sha256=row['receipt_sha256']['driver'])
                    write(sim/'active-0000_21_00.0.json',dict(run_id=program+size+str(rep),run_dir=str(sim/'inert-fixture')))
                    if program=='canneal' and size=='test':self.returncode=2
                    else:simulation_results.append((Path('fixture'),dict(valid=True,formal=size=='simmedium',identity=ident)))
            def poll(self):return self.returncode
        def busy_once():return busy.pop() if busy else False
        with patch.multiple(run,D=sim,W=temp,STATE=simstate,LOGS=simlogs,PRIORITY=simpriority,CERT=simcert,SUITE=simsuite,
            artifact=lambda p:dict(durable_bitstream_sha256=bitsha),software_paths=lambda r:r['receipts'],
            records=lambda:simulation_results,boot=lambda:'fixture-boot',save=write), \
            patch.object(run.os,'geteuid',return_value=0), \
            patch.object(run.subprocess,'Popen',FakeProcess), \
            patch.object(run.time,'sleep',lambda n:sleeps.append(n)), \
            patch.object(coverage_first,'sample_busy',busy_once):
            run.main()
        end=json.loads(simstate.read_text());assert end['valid_formal_samples']==36
        assert end['status']=='RUNNABLE_BATCH_EXHAUSTED_FAILURES_RETAINED'
        assert end['matrix']['canneal']==[] and len(end['failures'])==1
        assert sleeps==[60]
        samples=[a for a in trace if 'run_isolated_sample.py' in a[1]]
        formal=[a for a in samples if '--formal' in a]
        assert len(formal)==36
        reps=[int(a[a.index('--repetition')+1]) for a in formal];assert reps==sorted(reps)
        assert json.loads(simpriority.read_text())['status']=='YIELDED_NO_RUNNABLE_DERIVED_TASKS'
        checks.append(dict(check='actual controller simulated end-to-end: live-task wait, one deploy, gates, failed-app skip, 36 formal commits, priority yield',status='PASS_OFFLINE_FIXTURE'))

        # Real certification function: file hashes, complete stages, timing and
        # capacity logs. Git commands alone are simulated for this fixture.
        capsim=temp/'certification';capsim.mkdir();source=capsim/'source';source.mkdir()
        cb=source/'bindings'/(guard.COMMIT+'.json');write(cb,dict(source_id=guard.SOURCE))
        output=capsim/'runtime';output.mkdir();logs=capsim/'logs';logs.mkdir()
        inputsv=capsim/'input.sv';inputsv.write_text('// fixture only\n')
        shells=[]
        for n in range(11):
            p=capsim/f'shell-{n}.dcp';p.write_bytes(b'fixture checkpoint');shells.append(dict(path=str(p),sha256=sha(p)))
        impl=logs/'impl.log';impl.write_text('EC_FIT_LINK_ZERO_FUNCTIONAL_BLACKBOX\n')
        timing=logs/'timing.log';timing.write_text('EC_FIT_TIMING WNS=0.125 WHS=0.005\nEC_FIT_BITSTREAM_COMPLETE\n')
        (logs/'capacity.complete').write_text('CAPACITY_FITS_POSTOPT_TIMING_PENDING\n')
        s=copy.deepcopy(cert);s.update(status='BUILT_TIMING_DRC_PASSED_NOT_RUNTIME_VALIDATED',fpga_access=False,
            log_dir=str(logs),bitstream=str(bit),bitstream_sha256=sha(bit),
            inputs=dict(generated={str(inputsv):sha(inputsv)},shell_checkpoints=shells,frozen_dut_imported=False))
        for name,r in s['stages'].items():
            p=timing if name=='timing_bitstream' else impl
            r.update(log=str(p),outputs={str(p):sha(p)})
        state=capsim/'Opt4-fit-sort-cad-state.json';write(state,s)
        with patch.multiple(preparation,D=capsim,F=source,O=output), \
            patch.object(preparation.subprocess,'check_output',return_value=guard.COMMIT+'\n'), \
            patch.object(preparation.subprocess,'run'):
            receipt=preparation.certify()
            assert receipt['status']=='CERTIFIED_DERIVED_ARTIFACT_NOT_RUNTIME_VALIDATED'
            assert sha(output/'firesim.bit')==sha(bit)
            first_sha=sha(output/'certified-build.json');preparation.certify()
            assert sha(output/'certified-build.json')==first_sha
            bad=copy.deepcopy(s);bad['inputs']['generated'][str(inputsv)]='wrong';write(state,bad)
            rejects('actual certifier rejects modified generated RTL',preparation.certify)
            write(state,s);timing.write_text('EC_FIT_TIMING WNS=-1 WHS=0.005\nEC_FIT_BITSTREAM_COMPLETE\n')
            s['stages']['timing_bitstream']['outputs']={str(timing):sha(timing)};write(state,s)
            rejects('actual certifier rejects negative timing',preparation.certify)
        checks.append(dict(check='actual certifier validates stage/input hashes and creates stable independent receipt',status='PASS_OFFLINE_FIXTURE'))
    write(report,dict(schema='ec-derived-offline-validation/1',status='PASS',checks=checks,
        fixture_only=True,fpga_access=False,real_bitstream_certified=False,real_samples_created=False))
    print(json.dumps(dict(status='PASS_OFFLINE_ONLY',checks=len(checks),report=str(report))))


if __name__=='__main__':main()
