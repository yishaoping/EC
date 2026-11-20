from adapter_build import *
import struct

out,src=setup('bodytrack_serial_htif');app=EC/'Software/PARSEC/pkgs/apps/bodytrack/src'
original={}
for sub in ['TrackingBenchmark','FlexImageLib']:
 for p in (app/sub).iterdir():
  if p.is_file() and p.suffix in ['.cpp','.h']:
   shutil.copy2(p,src/p.name);original[sub+'/'+p.name]=sha(p)
inputs=EC/'Software/PARSEC/pkgs/apps/bodytrack/inputs/sequenceB_1'
capture=r'''#include "TrackingModel.h"
#include <stdio.h>
#include <assert.h>
class Capture:public TrackingModel{
 public:void save(){
  assert(Initialize(INPUT_PATH,4,1));assert(GetObservation(0));
  bool valid=false;float score=LogLikelihood(InitialState(),valid);assert(valid);
  FILE*f=fopen("measurement-trace.bin","wb");int cams=4;fwrite(&cams,4,1,f);
  float edge=mImageMeasurements[0].ImageErrorEdge(mEdgeMaps,mProjections[0]);
  float inside=mImageMeasurements[0].ImageErrorInside(mFGMaps,mProjections[0]);
  fwrite(&edge,4,1,f);fwrite(&inside,4,1,f);
  for(int c=0;c<cams;c++){
   int w=mEdgeMaps[c].Width(),h=mEdgeMaps[c].Height(),parts=mProjections[0](c).Size();
   fwrite(&w,4,1,f);fwrite(&h,4,1,f);fwrite(&parts,4,1,f);
   for(int y=0;y<h;y++)fwrite(&mEdgeMaps[c](0,y),1,w,f);
   fwrite(mFGMaps[c].ImageStore()->Data(),1,w*h/8+1,f);
   for(int p=0;p<parts;p++)for(int k=0;k<4;k++){
    Point pt=mProjections[0](c)(p).mPts[k];fwrite(&pt.x,4,1,f);fwrite(&pt.y,4,1,f);
   }
  }fclose(f);printf("[CAPTURE] frame=0 cameras=4 initial_pose=valid edge=%.9g inside=%.9g score=%.9g\n",edge,inside,score);
 }
};int main(){Capture m;m.save();}
'''
(src/'capture.cpp').write_text(capture)
hostfiles=['TrackingModel.cpp','BodyPose.cpp','BodyGeometry.cpp','CameraModel.cpp','CovarianceMatrix.cpp','AnnealingFactor.cpp','RandomGenerator.cpp','ImageProjection.cpp','ImageMeasurements.cpp','FlexImage.cpp','FlexIO.cpp','capture.cpp']
with (out/'capture-build.log').open('wb') as log:
 cmd=['/usr/bin/g++','-O2','-std=c++11','-DHAVE_STDINT_H=1','-ffp-contract=off','-I'+str(src),'-DINPUT_PATH='+json.dumps(str(inputs)+'/'),*[str(src/n) for n in hostfiles],'-lm','-o',str(out/'capture-host')]
 subprocess.run(cmd,cwd=out,check=True,stdout=log,stderr=subprocess.STDOUT)
 proc=subprocess.run([str(out/'capture-host')],cwd=out,stdout=subprocess.PIPE,stderr=subprocess.PIPE,text=True,timeout=30)
 (out/'capture.log').write_text(proc.stdout+proc.stderr);assert proc.returncode==0,proc.stderr
trace=(out/'measurement-trace.bin').read_bytes();cams,edge,inside=struct.unpack('<iff',trace[:12]);assert cams==4
(src/'trace.h').write_text('static unsigned char trace_bytes[] = {'+','.join(map(str,trace))+'};\n')
# Add data-loading accessors only; measurement loops remain byte-identical.
p=src/'ImageProjection.h';t=p.read_text(encoding='latin1').replace('int Size(){return (int)mProjCyls.size(); };','int Size(){return (int)mProjCyls.size(); };\n void TraceResize(int n){mProjCyls.resize(n);}')
t=t.replace('int Size(){return (int)mProjBodies.size(); };','int Size(){return (int)mProjBodies.size(); };\n void TraceResize(int n){mProjBodies.resize(n);}')
p.write_text(t,encoding='latin1')
p=src/'FlexImage.h';t=p.read_text(encoding='latin1').replace('public:','public:\n void TraceAttach(T*p,int w,int h){mStore=NULL;mData=p;mSize.width=w;mSize.height=h;mBpp=sizeof(T)*C;mStepBytes=w*sizeof(T)*C;}\n',1);p.write_text(t,encoding='latin1')
p=src/'BinaryImage.h';t=p.read_text(encoding='latin1').replace('public:','public:\n void TraceAttach(unsigned char*p,int w,int h){mStore=NULL;mData=p;mWidth=w;mHeight=h;}\n',1);p.write_text(t,encoding='latin1')
adapter=r'''#include "ImageMeasurements.h"
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include "trace.h"
static std::vector<FlexImage8u> *edges;
static std::vector<BinaryImage> *foreground;
static MultiCameraProjectedBody *bodies;
static ImageMeasurements *measurement;
static float expected_edge,expected_inside,edge,inside;
static size_t cursor;
static int read_int(){int v;memcpy(&v,trace_bytes+cursor,4);cursor+=4;return v;}
static float read_float(){float v;memcpy(&v,trace_bytes+cursor,4);cursor+=4;return v;}
extern "C" void workload_prepare(void){
 int cams=read_int();expected_edge=read_float();expected_inside=read_float();
 edges=new std::vector<FlexImage8u>(cams);foreground=new std::vector<BinaryImage>(cams);
 bodies=new MultiCameraProjectedBody;measurement=new ImageMeasurements;bodies->TraceResize(cams);
 for(int c=0;c<cams;c++){
  int w=read_int(),h=read_int(),n=read_int();
  (*edges)[c].TraceAttach(trace_bytes+cursor,w,h);cursor+=w*h;
  (*foreground)[c].TraceAttach(trace_bytes+cursor,w,h);cursor+=w*h/8+1;
  (*bodies)(c).TraceResize(n);
  for(int p=0;p<n;p++)for(int k=0;k<4;k++){float x=read_float(),y=read_float();(*bodies)(c)(p).mPts[k].Set(x,y);}
 }assert(cursor==sizeof(trace_bytes));
}
extern "C" void workload_run(void){edge=measurement->ImageErrorEdge(*edges,*bodies);inside=measurement->ImageErrorInside(*foreground,*bodies);}
extern "C" int workload_verify(void){
 int ok=isfinite(edge)&&isfinite(inside)&&fabsf(edge-expected_edge)<1e-5f&&fabsf(inside-expected_inside)<1e-5f;
 uint64_t hash=14695981039346656037ULL;hash^=(uint64_t)llround(edge*10000.0);hash*=1099511628211ULL;hash^=(uint64_t)llround(inside*10000.0);hash*=1099511628211ULL;
 printf("[OUTPUT] benchmark=bodytrack checksum=%016lx verified=%d cameras=4 frame=0 pose=initial components=edge_inside\n",(unsigned long)hash,ok);return ok;
}
'''
(src/'bodytrack-adapter.cpp').write_text(adapter)
(src/'host-reference.cpp').write_text('extern "C" void workload_prepare(void),workload_run(void);extern "C" int workload_verify(void);int main(){workload_prepare();workload_run();return workload_verify()?0:1;}\n')
j=build(out,['ImageMeasurements.cpp','FlexImage.cpp','bodytrack-adapter.cpp'],dict(benchmark='bodytrack',profile='real-frame0-likelihood-measurement-replay',method='CPU_GG_REAL_TRACE_COMPONENT_REPLAY',extra_flags=['-ffp-contract=off'],original_source_sha256=original,input={'dataset':str(inputs),'files_sha256':{str(p.relative_to(inputs)):sha(p) for p in inputs.rglob('*') if p.is_file()},'trace':str(out/'measurement-trace.bin'),'trace_sha256':sha(out/'measurement-trace.bin'),'frame':0,'pose':'official initial pose','cameras':4},roi_scope='Unmodified original ImageErrorEdge and ImageErrorInside on real LogLikelihood initial-pose projection/maps captured from official frame0',correctness={'expected_edge':edge,'expected_inside':inside,'absolute_tolerance':1e-5,'capture_log':str(out/'capture.log'),'capture_binary_sha256':sha(out/'capture-host')},limitations=['Actual likelihood measurement component replay only; excludes pose generation, geometry/projection, image processing and particle filter control','Coverage weight and extrapolation error against full Bodytrack uncalibrated; not full-application slowdown','Only serialization accessors added; original ImageMeasurements.cpp is unchanged'],max_target_cycles=1500000,timeout_seconds=2400))
print(out/'manifest.json')
