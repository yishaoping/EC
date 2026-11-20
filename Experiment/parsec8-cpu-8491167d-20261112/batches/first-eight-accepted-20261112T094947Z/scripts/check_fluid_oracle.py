"""Independent arithmetic oracle for captured pre-integration state, no timing."""
from common import *
import struct

mp=ROOT/next(x['manifest'] for x in read(ROOT/'queue.json')['items'] if x['benchmark']=='fluidanimate')
mf=read(mp);assert 'AdvanceParticles' in mf['profile']
state=Path(mf['input']['trace_path']);reference=Path(mf['correctness']['reference'])
raw=state.read_bytes();nc,np=struct.unpack('<ii',raw[:8])
v=struct.unpack('<'+'f'*(np*12),raw[8+nc*4:]);ref=struct.unpack('<'+'f'*(np*9),reference.read_bytes())
f32=lambda x:struct.unpack('<f',struct.pack('<f',x))[0]
dt=f32(.001);values=[]
for i in range(np):
 pos,hv,vel,acc=[v[12*i+k:12*i+k+3] for k in [0,3,6,9]]
 half=[f32(a+f32(b*dt)) for a,b in zip(hv,acc)]
 outp=[f32(a+f32(b*dt)) for a,b in zip(pos,half)]
 outv=[f32(f32(a+b)*f32(.5)) for a,b in zip(hv,half)]
 values+=outp+half+outv
passed=len(values)==len(ref)==576 and all(struct.pack('<f',a)==struct.pack('<f',b) for a,b in zip(values,ref))
save(ROOT/'audit/fluid-advance-binary32-oracle.json',dict(created_utc=now(),passed=passed,functional_only=True,performance_sample=False,method='Independent Python binary32 multiplication/addition at every original leapfrog integration operation, from actual captured p/hv/v/a; compare every output bit with original host AdvanceParticles',state_path=str(state),state_sha256=sha(state),reference_path=str(reference),reference_sha256=sha(reference),compared_float_values=len(values),bit_exact_reference_match=passed,max_abs_error=max(abs(a-b) for a,b in zip(values,ref)),script_sha256=sha(__file__),manifest_sha256=sha(mp),limitations=['Verifies expected integration outputs on captured state only; no full-frame representation, target timing, or hardware proof']))
assert passed,'Original host integration output disagrees with independent oracle'
print('Fluid independent oracle: 576/576 output floats bit-exact',flush=True)
