from adapter_build import *

out,src=setup('blackscholes_no_main_timer')
old=Path('/data1/gzh/EC-opt4-perf/slowdown/parsec_evaluation_20261103/build/blackscholes_project64/source')
for name in ['adapter.c','blackscholes.upstream.c']:
 shutil.copy2(old/name,src/name)
p=src/'blackscholes.upstream.c';p.write_text(p.read_text().replace('#define NUM_RUNS 100','#define NUM_RUNS 1'))
(src/'host-reference.cpp').write_text('extern "C" void workload_prepare(void),workload_run(void);extern "C" int workload_verify(void);int main(){workload_prepare();workload_run();return workload_verify()?0:1;}\n')
j=build(out,['adapter.c'],dict(benchmark='blackscholes',profile='project64-one-iteration-no-main-timer',method='CPU_GG_TEST_DERIVED_REPRESENTATIVE_ROI',input={'options':64,'iterations':1,'input_adapter_original':str(old/'adapter.c'),'input_adapter_sha256':sha(old/'adapter.c')},roi_scope='One original bs_thread iteration over 64 identical options; setup/output outside ROI',limitations=['One iteration, not project64 100-iteration full workload; extrapolation error uncalibrated','Distinct startup/link/cache state; shared application objects'],original_source_sha256={n:sha(old/n) for n in ['adapter.c','blackscholes.upstream.c']},max_target_cycles=1000000,timeout_seconds=2400))
print(out/'manifest.json')

out,src=setup('streamcluster_representative')
old=ROOT/'software/streamcluster_project64/source'
shutil.copy2(old/'streamcluster.cpp',src/'streamcluster.cpp')
t=(old/'adapter.cpp').read_text().replace('SimStream stream(64);streamCluster(&stream,3,10,3,64,32,','SimStream stream(16);streamCluster(&stream,3,5,3,16,16,').replace('count<=10','count<=5').replace('weight-64','weight-16')
(src/'adapter.cpp').write_text(t)
(src/'host-reference.cpp').write_text('extern "C" void workload_prepare(void),workload_run(void);extern "C" int workload_verify(void);int main(){workload_prepare();workload_run();return workload_verify()?0:1;}\n')
j=build(out,['adapter.cpp'],dict(benchmark='streamcluster',profile='representative-16-points-no-main-timer',method='CPU_GG_TEST_DERIVED_REPRESENTATIVE_ROI',input={'points':16,'dimensions':3,'kmin':3,'kmax':5,'chunksize':16,'clustersize':16,'seed':'Original PARSEC SEED constant'},roi_scope='Complete original streamCluster on a 16-point synthetic stream; setup/output outside ROI',limitations=['Reduced point count and kmax; not project64 or official simmedium; extrapolation error uncalibrated'],original_source_sha256={n:sha(old/n) for n in ['adapter.cpp','streamcluster.cpp']},max_target_cycles=2000000,timeout_seconds=3000))
print(out/'manifest.json')
