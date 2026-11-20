from adapter_build import *
import re
out,src=setup('streamcluster_portable')
old=ROOT/'software/streamcluster_project64/source'
shutil.copy2(old/'streamcluster.cpp',src/'streamcluster.cpp')
t=(old/'adapter.cpp').read_text().replace('SimStream stream(64);streamCluster(&stream,3,10,3,64,32,','SimStream stream(16);streamCluster(&stream,3,5,3,16,16,').replace('count<=10','count<=5').replace('weight-64','weight-16')
t=t.replace('if(median){count++;', 'if(median){printf("[CENTER] id=%ld weight=%a x=%a y=%a z=%a\\n",ids[i],(double)saved.p[i].weight,(double)saved.p[i].coord[0],(double)saved.p[i].coord[1],(double)saved.p[i].coord[2]);count++;')
(src/'adapter.cpp').write_text(t)
(src/'host-reference.cpp').write_text('extern "C" void workload_prepare(void),workload_run(void);extern "C" int workload_verify(void);int main(){workload_prepare();workload_run();return workload_verify()?0:1;}\n')
meta=dict(benchmark='streamcluster',profile='representative-16-points-fp-contract-off',method='CPU_GG_TEST_DERIVED_REPRESENTATIVE_ROI',extra_flags=['-ffp-contract=off'],input={'points':16,'dimensions':3,'kmin':3,'kmax':5,'chunksize':16,'clustersize':16,'seed':'Original PARSEC SEED constant'},roi_scope='Complete original streamCluster on a 16-point SimStream, matched no-main-timer policy, setup and correctness outside ROI',correctness={'oracle':'Original x86 host scalar kernel with same RNG seed; center IDs/weights/coordinates checked against captured host centers','float_tolerance':'abs 1e-5 + rel 1e-5'},output_acceptance='verified_fields_checksum_may_differ_from_host',limitations=['Reduced point count and kmax, not project64 or full simmedium; extrapolation error uncalibrated','Floating multiply/add contraction disabled in both modes and host reference; target pair still requires identical output checksum'],original_source_sha256={n:sha(old/n) for n in ['adapter.cpp','streamcluster.cpp']},max_target_cycles=2000000,timeout_seconds=3000)
build(out,['adapter.cpp'],meta.copy())
centers=[]
for line in (out/'host-reference.log').read_text().splitlines():
 if line.startswith('[CENTER] '):
  fields=dict(s.split('=',1) for s in line.split()[1:]);centers.append((int(fields['id']),*[float.fromhex(fields[k]) for k in ['weight','x','y','z']]))
assert 3<=len(centers)<=5
header='static const long expected_ids[] = {'+','.join(str(r[0]) for r in centers)+'};\n'
header+='static const float expected_values[][4] = {'+','.join('{'+','.join(float(v).hex()+'f' for v in r[1:])+'}' for r in centers)+'};\n'
(src/'expected-centers.h').write_text(header)
t='#include "expected-centers.h"\n'+t
t=t.replace('count++;weight+=saved.p[i].weight;',f'''int reference=-1;for(int r=0;r<{len(centers)};r++)if(ids[i]==expected_ids[r])reference=r;
if(reference<0)ok=0;else{{float actual[4]={{saved.p[i].weight,saved.p[i].coord[0],saved.p[i].coord[1],saved.p[i].coord[2]}};for(int q=0;q<4;q++)if(fabsf(actual[q]-expected_values[reference][q])>1e-5f+1e-5f*fabsf(expected_values[reference][q]))ok=0;}}
count++;weight+=saved.p[i].weight;''')
t=t.replace('ok=ok&&count>=3',f'ok=ok&&count=={len(centers)}&&count>=3')
(src/'adapter.cpp').write_text(t)
build(out,['adapter.cpp'],meta.copy())
save(out/'independent-reference.json',dict(center_ids_weights_xyz=centers,host_log=str(out/'host-reference.log'),host_log_sha256=sha(out/'host-reference.log'),original_source_sha256=meta['original_source_sha256']))
print(out/'manifest.json')
