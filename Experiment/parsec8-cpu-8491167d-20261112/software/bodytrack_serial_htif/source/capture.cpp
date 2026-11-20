#include "TrackingModel.h"
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
