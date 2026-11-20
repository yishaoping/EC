#!/usr/bin/python3
"""Host compiler transformation of the already emitted frozen target, no RTL edits.
Only emit Golden Gate collateral here. Whole implementation needs separately
validated target equivalence, measured benefit, ABI and all existing CAD gates.
"""
import collections, importlib.util, os, pathlib, json
P=pathlib.Path;C=P(__file__).resolve().parent
sp=importlib.util.spec_from_file_location('proto',C/'run.py');m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
m.L=m.D/'cycleprecise-frozen-mcrams-20261111';m.S=m.L/'state.json'
def main():
    m.L.mkdir(exist_ok=True);lock=(m.L/'instance.lock').open('a');m.fcntl.flock(lock,m.fcntl.LOCK_EX|m.fcntl.LOCK_NB)
    m.ST.update(schema='ec-opt4-frozen-mcrams-host-only/1',**m.ident(os.getpid()),functional_baseline=m.BASE,started_utc=m.now(),fpga_access=False,production_admission=False,raw_target_fir_changed=False)
    cfg=m.read(m.W/'candidates/dcache-field-read-system-r1-20261111/config.json')
    fir=m.W/'builds/C4-elaborate-20261106T100250.032318Z/firesim.firesim.FireSim.fir'
    anno=fir.with_name('firesim.firesim.FireSim.anno.json')
    annos=m.read(anno);mem=[a for a in annos if 'FirrtlMemModelAnnotation' in a.get('class','')];mt=[a for a in annos if 'EnableModelMultiThreadingAnnotation' in a.get('class','')]
    assert len(mem)==10 and len(mt)==5
    m.save(m.L/'binding.json',dict(functional_baseline=m.BASE,scope='Exact existing frozen target FIRRTL and annotations, only host platform configuration differs',target_fir=str(fir),target_fir_sha256=m.sha(fir),target_annotations=str(anno),target_annotations_sha256=m.sha(anno),memory_annotations=mem,multithread_annotations=mt,platform_config='MCRams_DacXilinxAlveoConfig',new_target_features=False))
    java=[cfg['java'],'-Xmx32G','-Xss8M','-XX:ActiveProcessorCount=4','-Dec.dac.firesim=true','-cp',':'.join(cfg['classpath'])]
    out=m.L/'goldengate';out.mkdir(exist_ok=True)
    m.stage('goldengate',java+['midas.stage.GoldenGateMain','-i',str(fir),'-td',str(out),'-faf',str(anno),'-ggcp','firesim.configs','-ggcs','MCRams_DacXilinxAlveoConfig','--output-filename-base','FireSim-generated','--no-dedup'],C,[out/'FireSim-generated.sv',out/'FireSim-generated.const.h'],timeout=7200)
    sv=out/'FireSim-generated.sv';files=out/'firrtl_black_box_resource_files.f'
    if not (out/'blackboxes-appended.json').exists():
        with sv.open('a') as f:
            for n in files.read_text().splitlines() if files.exists() else []:
                if n.strip():f.write(P(n).read_text())
        m.save(out/'blackboxes-appended.json',dict(sha256=m.sha(sv)))
    m.update(status='HOST_TRANSFORM_COMPLETE_NOT_EQUIVALENCE_OR_FIT_ADMITTED',host_rtl=str(sv),host_rtl_sha256=m.sha(sv),next='Compare same-target metasim and original observations. Measure actual full/memory model area before complete CAD. No hardware admission from compiler completion.')
    m.save(m.L/'result.json',m.ST)
if __name__=='__main__':
    try:main()
    except Exception as e:m.update(status='FAILED_WITH_EVIDENCE',error=repr(e));m.save(m.L/'failure.json',m.ST);raise
