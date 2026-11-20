#!/usr/bin/env python3
"""Host-only derivative: FASED readback and bounded print-log flushing.
No DUT source edits, RTL regeneration, FPGA accesses, or old output mutations.
"""
import datetime as dt
import difflib,hashlib,json,os,shlex,shutil,subprocess,sys,time
from pathlib import Path
W=Path('/data1/gzh/EC/firesim/final-opt4-20261106')
D=Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def main(config):
    n=json.loads((W/'native-reuse.json').read_text())
    receipt=Path(n['driver_receipt']) if config=='Native' else D/'build-logs/C4-driver-20261106T104028.658367Z/result.json'
    r=json.loads(receipt.read_text());old=Path(r['output_dir'])
    assert r['returncode']==0
    for p,h in r['outputs'].items():assert sha(p)==h,p
    stamp=dt.datetime.now(dt.timezone.utc).strftime('%Y%m%dT%H%M%SZ')
    out=W/'builds'/(config+'-observed-driver-'+stamp);logs=D/'build-logs'/out.name
    shutil.copytree(old,out);logs.mkdir()
    src=out/'host-sources';src.mkdir()
    lines=(receipt.parent/'build.log').read_text().splitlines()
    commands=[];patches=[];inputs={str(receipt):sha(receipt)}
    for stem in ['fased_memory_timing_model','synthesized_prints']:
        line=next(x for x in lines if x.startswith('/usr/bin/g++ ') and x.endswith('/'+stem+'.cc') and ' -c ' in x)
        argv=shlex.split(line);source=Path(argv[-1]);before=source.read_text();after=before
        if stem=='fased_memory_timing_model':
            anchor='  for (auto &hist : histograms) {\n    hist.init();'
            addition='''  // Host-only readback before target stepping; never assumes a write succeeded.
  for (const auto &[key, expected] : user_configuration) {
    const auto actual = simif.read(addr_map.r_addr(key));
    fprintf(stderr, "EC_FASED_READBACK key=%s expected=%u actual=%u\\n",
            key.c_str(), expected, actual);
    if (actual != expected) throw std::runtime_error("FASED runtime readback mismatch: " + key);
  }
  fflush(stderr);

'''
            assert after.count(anchor)==1;after=after.replace(anchor,addition+anchor)
        else:
            after=after.replace('#include <cassert>','#include <cassert>\n#include <chrono>\n#include <unordered_map>')
            anchor='  process_tokens(batch_beats, batch_beats);\n}'
            replacement='''  process_tokens(batch_beats, batch_beats);
  using clock = std::chrono::steady_clock;
  static std::unordered_map<const void *, clock::time_point> last_flush;
  auto now = clock::now();
  auto &previous = last_flush[this];
  if (now - previous >= std::chrono::seconds(5)) {
    process_tokens(batch_beats, 0);
    printstream->flush();
    previous = now;
  }
}'''
            assert after.count(anchor)==1;after=after.replace(anchor,replacement)
        dest=src/source.name;dest.write_text(after);inputs[str(source)]=sha(source)
        patches.extend(difflib.unified_diff(before.splitlines(True),after.splitlines(True),fromfile=str(source),tofile=str(dest)))
        argv=[a.replace(str(old),str(out)) for a in argv];argv[-1]=str(dest)
        argv[1:1]=['-I'+str(source.parent)]
        commands.append(argv)
    (logs/'host-only.patch').write_text(''.join(patches))
    link=next(x for x in reversed(lines) if x.startswith('/usr/bin/g++ ') and ' -o '+str(old/'FireSim-xilinx_alveo_u280')+' ' in x)
    commands.append([a.replace(str(old),str(out)) for a in shlex.split(link)])
    start=time.monotonic();rc=0
    with (logs/'build.log').open('wb',buffering=0) as f:
        for argv in commands:
            f.write((json.dumps({'argv':argv})+'\n').encode())
            rc=subprocess.run(['nice','-n','15',*argv],stdin=subprocess.DEVNULL,stdout=f,stderr=subprocess.STDOUT,timeout=180).returncode
            if rc:break
    exe=out/'FireSim-xilinx_alveo_u280'
    record=dict(schema='ec-host-observed-driver/1',configuration=config,returncode=rc,status='BUILT_NOT_RUN' if rc==0 else 'FAILED',
                source_id=r['source_id'],hardware_source_id=r['source_id'],parent_receipt=str(receipt),parent_receipt_sha256=sha(receipt),
                hardware_rtl_unchanged=True,hardware_regeneration=False,patch=str(logs/'host-only.patch'),patch_sha256=sha(logs/'host-only.patch'),
                input_files=inputs,commands=commands,output_dir=str(out),outputs={str(exe):sha(exe)} if exe.exists() else {},
                observed_runtime_readback=False,wall_seconds=time.monotonic()-start)
    (logs/'result.json').write_text(json.dumps(record,indent=2)+'\n')
    if rc==0:(W/'runtime'/(config+'-observed-driver.json')).write_text(json.dumps(record,indent=2)+'\n')
    print(json.dumps({'configuration':config,'returncode':rc,'receipt':str(logs/'result.json')}),flush=True)
    return rc
if __name__=='__main__':raise SystemExit(main(sys.argv[1]))
