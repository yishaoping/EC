#include "RTTL/common/RTInclude.hxx"
#include "LRT/include/lrt.h"
#include "LRT/FrameBuffer.hxx"

#include "Camera.hxx"
#include "ObjParser.hxx"
#include "RTTL/common/Timer.hxx"
#include "RTTL/common/MapOptions.hxx"

#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#ifdef ENABLE_PARSEC_HOOKS
#include <hooks.h>
#endif

using namespace RTTL;
using namespace LRT;

enum MouseButton { M_NONE, M_LEFT, M_MIDDLE, M_RIGHT };

#define INIT_RES 1024

int resX = INIT_RES;
int resY = INIT_RES;

int mouseButton = M_NONE;
int lastMouseX = -1, lastMouseY = -1;
float moveScale = 0.02f;
float rotateScale = 0.1f;

/* set at the command line */
RTVec3f viewerOrigin = RTVec3f(0.0,2.0,0.5);
RTVec3f viewerDirection = RTVec3f(-0.000000,-0.970143,-0.242536);
RTVec3f viewerUp = RTVec3f(0.000000,-0.242536,0.970143);
float viewerAngle = 64;
bool setViewer = false;
Camera camera;

bool glDisplay = true;
int framesToRender = 1;
bool autoMoveCamera = false;

/* new LRT stuff */
LRTFrameBufferHandle lrtFrameBuffer;
LRTContext lrtContext;
LRTCamera  lrtCamera;

void render()
{
  RTVec3f eye    = camera.getOrigin();
  RTVec3f center = camera.getOrigin()+camera.getDirection();
  RTVec3f up     = camera.getUp();

  lrtLookAt(lrtCamera,eye.x,eye.y,eye.z,center.x,center.y,center.z,up.x,up.y,up.z,camera.getAngle(),(float)resX/resY);	    
  lrtRenderFrame(lrtFrameBuffer,lrtContext,lrtCamera); // call ray tracer to trace its frame

  //spin object slowly (by moving camera around it)
  if(autoMoveCamera) {
    const float autoMoveScale = 0.01;

    //move camera perpendicular to the object
    RTVec3f oldOrigin = camera.getOrigin();
    camera.moveLocal(autoMoveScale*oldOrigin.length()*up);
    RTVec3f newOrigin = camera.getOrigin();
    const float driftRatio = newOrigin.length() / oldOrigin.length();

    //rotate camera to point again at object
    oldOrigin.normalize();
    newOrigin.normalize();
    float alpha = acosf(dot(oldOrigin,newOrigin)) * 180.0 / M_PI;
    camera.rotateGlobal(up, alpha);

    //move camera towards object to compensate for drift
    RTVec3f newDirection = camera.getDirection();
    newDirection.normalize();
    camera.setOrigin(camera.getOrigin() + (driftRatio-1.0) * newDirection);
  }
}

void parseRTVec3f(int argc, char* argv[], int& p, RTVec3f& vec)
{
  if (p+3 > argc) {
    exit(-1);
  }

  vec[0] = atof(argv[p+0]);
  vec[1] = atof(argv[p+1]);
  vec[2] = atof(argv[p+2]);
  p+=3;
}

void parseCommandLine(int argc, char* argv[])
{
  options.parse(argc-1, argv+1);
  cout << "Options: " << options << endl;

  setViewer = options.defined("vp, vd, vi, vu, vangle");

  if (options.defined("vp")) {
    viewerOrigin    = options.getVec3f("vp");
  }

  if (options.defined("vd")) {
    viewerDirection = options.getVec3f("vd");
  }
  if (options.defined("vi")) {
    viewerDirection = options.getVec3f("vi");
    viewerDirection -= viewerOrigin;
  }
  if (options.defined("vu")) {
    viewerUp = options.getVec3f("vu");
  }
  viewerAngle = options.get("vangle", viewerAngle);
  glDisplay = options.defined("display");
  framesToRender = options.get("frames", framesToRender);
  autoMoveCamera = options.defined("automove");
  if (options.defined("res")) {
    RTVec2i newRes = options.getVec2i("res");
    resX = newRes.x;
    resY = newRes.y;
  }
}

mesh_t generateUnitCube(node_t root)
{
  static float v[] = {
    -1.0,-1.0,-1.0,
    1.0,-1.0,-1.0,
    1.0,1.0,-1.0,
    -1.0,1.0,-1.0,
    -1.0,-1.0,1.0,
    1.0,-1.0,1.0,
    1.0,1.0,1.0,
    -1.0,1.0,1.0
  };

  static int t[] = {
    0,3,2,
    0,2,1,
    4,0,1,
    4,1,5,
    7,3,0,
    7,0,4,
    3,7,6,
    3,6,2,
    5,6,7,
    5,7,4,
    5,1,2,
    5,2,6
  };

  mesh_t mesh = rtTriangleMesh(root);
  
  /* allocate vertex array of 3-float vertices (hope the mesh's
     implementation likes three-float vertices !)... */
  data_t vertex_array = rtNewCoordArray(mesh,RT_FLOAT3);
  assert(rtValidData(vertex_array));
  
  /*! ... and write data to it. as vertex array data is same as the
    format we write, there's not type conversion, but a single
    memcpy */
  rtCoords3f(vertex_array,v,8,RT_PRIVATE);
  
  /*! same for the connectivity data */
  data_t index_array = rtNewIndexArray(mesh,RT_INT3);
  assert(rtValidData(index_array));
  rtIndices3i(index_array,t,12,RT_PRIVATE);
    
  return mesh;
}

void SetAutoCamera(RTBox3f& box) {
  RTVec3f m_min = box[0];
  RTVec3f m_max = box[1];
  RTVec3f midpoint = 0.5f * (m_min + m_max);
  float height = m_max[1] - m_min[1];
  float width  = m_max[0] - m_min[0];
  float max_size = (height < width) ? width : height;
  float dist = 0.5f * (max_size) / tanf(0.5f * viewerAngle * M_PI / 180.f);
  viewerOrigin    = RTVec3f(midpoint[0], midpoint[1], m_max[2] + dist);
  viewerUp        = RTVec3f(0,1,0);
  viewerDirection = RTVec3f(0, 0, -1);
}

int main(int argc, char* argv[])
{
#ifdef PARSEC_VERSION
#define __PARSEC_STRING(x) #x
#define __PARSEC_XSTRING(x) __PARSEC_STRING(x)
  cout << "PARSEC Benchmark Suite Version "__PARSEC_XSTRING(PARSEC_VERSION) << endl << flush;
#else
  cout << "PARSEC Benchmark Suite" << endl << flush;
#endif //PARSEC_VERSION
#ifdef ENABLE_PARSEC_HOOKS
  atexit(__parsec_bench_end);
  __parsec_bench_begin(__parsec_raytrace);
#endif

  rtInit(&argc, argv);
  lrtInit(&argc, argv); // idea is that rltInit can parse what it
                        // wants, strip the stuff it knows from the
                        // command line (before the app can actually
                        // see it), and return the rest to the app for
                        // processing. if we want to use the
                        // mapoptions class for that task, we'd have
                        // to extend it to do just that -- strip the
                        // parameters it is queried about, and return
                        // the rest -- then, we can use the mapoptions
                        // class in several different instances (once
                        // in the kernel, once in the app)

  resX = LRT::FrameBuffer::Options::defaultRes.x;
  resY = LRT::FrameBuffer::Options::defaultRes.y;

  parseCommandLine(argc, argv);

  if(glDisplay) FATAL("display unavailable in headless build");
  LRT::FrameBuffer::Options::useMemoryFB=true;
  /* create LRT 'objects' */
  lrtContext     = lrtCreateContext();
  lrtCamera      = lrtCreateCamera();
  lrtFrameBuffer = lrtCreateTextureFB(resX,resY);

  /* initialize MiniRT */
  bool subdiv = options.defined("subdiv");
  if (subdiv) FATAL("Subdivision surface mode currently not available");

  int numThreads = options.get("nthreads", 1);
  lrtSetRenderThreads(lrtContext,numThreads);
  
  int nfiles = options.vector_size("files");

  node_t root = rtNewRoot(RT_VISIBLE);


  if (nfiles == 0) 
    generateUnitCube(root); /* if no obj file is specified use unit cube */
  else
    {
      ObjParser parser;

      for (int fi = 0; fi < nfiles; fi++) {
	const string& fn = (*options["files"])[fi];
	cout << "Adding obj file: " << fn << endl;
	parser.Parse(fn.c_str());
      }

      RTBox3f sceneAABB = parser.getSceneAABB();
      /* initialize camera */
      if (!setViewer)
	{
	  cout << "Using auto camera..." << endl;
	  SetAutoCamera(sceneAABB);
	}

      assert(parser.vertices());

      mesh_t mesh = rtTriangleMesh(root);

      data_t vertex_array = rtNewCoordArray(mesh,RT_FLOAT3);
      assert(rtValidData(vertex_array));
      rtCoords3f(vertex_array,(const float*)parser.getVertexPtr(),parser.vertices(),RT_PRIVATE);


      if (parser.triangles())
	{
	  /*! same for the connectivity data */
	  data_t index_array = rtNewIndexArray(mesh,RT_INT3);
	  assert(rtValidData(index_array));
	  rtIndices3i(index_array,(const int*)parser.getTrianglePtr(),parser.triangles(),RT_PRIVATE);
	}

      if (parser.quads())
	{
	  /*! same for the connectivity data */
	  data_t index_array = rtNewIndexArray(mesh,RT_INT4);
	  assert(rtValidData(index_array));
	  rtIndices4i(index_array,(const int*)parser.getQuadPtr(),parser.quads(),RT_PRIVATE);
	}

      /* -- transfer vertices -- */
      //miniRT.addVertices(parser.getVertexPtr(),parser.getTextureCoordinatePtr(),parser.vertices());
      /* -- transfer materials -- */
      //miniRT.addMaterials(parser.getMaterialPtr(),parser.materials());
      /* -- transfer textures  -- */
      for (int i=0;i<parser.textures();i++)
	{
	  ImagePPM *txt = parser.getTexture(i);
	  //miniRT.addTexture(txt->width(),txt->height(),txt->data(),RT_TEXTURE_FORMAT_RGB_UCHAR);
	}     
      /* -- transfer triangles -- */
      //if (parser.triangles()) miniRT.addTriangleMesh(parser.getTrianglePtr(),parser.triangles(),parser.getTriangleShaderPtr());
      /* -- transfer quads -- */
      //if (parser.quads()) miniRT.addQuadMesh(parser.getQuadPtr(),parser.quads(),parser.getQuadShaderPtr());
      parser.Free();
    }
  if (options.defined("exitafterbuild")) exit(0);


  camera.initMatrix(viewerOrigin,viewerDirection,viewerUp,viewerAngle);
  lrtBuildContext(lrtContext);

  {
    cout << "Rendering " << framesToRender << " frames... " << endl << flush;
    if(framesToRender<=0) FATAL("finite frame count required");
    LRT::FrameBuffer *ec_fb=reinterpret_cast<LRT::FrameBuffer*>(lrtFrameBuffer);
    const size_t ec_w=(resX/8)*8,ec_h=(resY/8)*8,ec_bytes=ec_w*ec_h*4;
    if(!ec_bytes) FATAL("official dimensions render no complete packet");
    unsigned char *ec_frames=(unsigned char*)malloc(ec_bytes*framesToRender);
    if(!ec_frames) exit(125);
    memset(ec_frames,0,ec_bytes*framesToRender);
    mallopt(M_TRIM_THRESHOLD,-1);mallopt(M_MMAP_MAX,0);
    volatile char *ec_heap=(volatile char*)malloc(128*1024*1024);if(!ec_heap)exit(125);
    for(size_t i=0;i<128*1024*1024;i+=4096)ec_heap[i]=0;free((void*)ec_heap);
#ifdef ENABLE_PARSEC_HOOKS
    __parsec_roi_begin();
#endif
    int frame = 0;
    do {
      render();
      for(size_t y=0;y<ec_h;y++) memcpy(ec_frames+frame*ec_bytes+y*ec_w*4,ec_fb->fb+y*ec_fb->res.x*4,ec_w*4);
      frame++;
    } while(!(__builtin_expect(framesToRender > 0,0) && frame >= framesToRender));
#ifdef ENABLE_PARSEC_HOOKS
    __parsec_roi_end();
#endif
    FILE *ec_file=fopen("frames.rgba","wb");if(!ec_file)exit(125);
    if(fwrite(ec_frames,1,ec_bytes*frame,ec_file)!=ec_bytes*frame || fclose(ec_file))exit(125);
    ec_file=fopen("frames.shape","w");if(!ec_file)exit(125);
    fprintf(ec_file,"requested=%dx%d rendered=%zux%zu frames=%d RGBA8\n",resX,resY,ec_w,ec_h,frame);
    if(fclose(ec_file))exit(125);

    cout << "Done" << endl << flush;
  }

  return 0;
}

