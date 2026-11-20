#include "LRT/include/lrt.h"
#include "FrameBuffer.hxx"


#include "FrameBuffer/MemoryFrameBuffer.hxx"

#define DBG(a) /* do nothing */

namespace LRT BEGIN_NAMESPACE

bool FrameBuffer::Options::usePBOs = true;
bool FrameBuffer::Options::useMemoryFB = false;
vec2i FrameBuffer::Options::defaultRes(512,512);



RGBAucharFrameBuffer *RGBAucharFrameBuffer::create()
{
  RGBAucharFrameBuffer *frameBuffer = NULL;

  if (Options::useMemoryFB) {
    cout << "Using memory framebuffer..." << endl;
    return new LRT::MemoryFrameBuffer;
  }

  FATAL("headless build requires memory framebuffer");

  return frameBuffer;
}




END_NAMESPACE


using LRT::RGBAucharFrameBuffer;

LRTFrameBufferHandle lrtCreateTextureFB(LRTuint width,
                                        LRTuint height)
{
  LRT::FrameBuffer *fb = RGBAucharFrameBuffer::create();
  fb->resize(width,height);
  return fb;
}

LRTvoid lrtDestroyFB(LRTFrameBufferHandle fbHandle)
{
  RGBAucharFrameBuffer *fb = reinterpret_cast<RGBAucharFrameBuffer *>(fbHandle);
  if (fb) delete fb;
}
  
LRTvoid lrtDisplayFB(LRTFrameBufferHandle fbHandle)
{
  RGBAucharFrameBuffer *fb = reinterpret_cast<RGBAucharFrameBuffer *>(fbHandle);
  if (fb) fb->display();
}



