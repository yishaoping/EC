#include "ImageMeasurements.h"
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
