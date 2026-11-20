#include <vips/vips.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#ifdef ENABLE_PARSEC_HOOKS
#include "hooks.h"
#endif
static void fail(void){fprintf(stderr,"%s\n",im_error_buffer());exit(125);}
static void dump(IMAGE *im) {
 if(im_incheck(im))fail();
 FILE *f=fopen("output.pixels","wb");if(!f)exit(125);
 size_t n=(size_t)IM_IMAGE_SIZEOF_LINE(im)*im->Ysize;
 if(fwrite(im->data,1,n,f)!=n||fclose(f))exit(125);
 f=fopen("output.shape","w");if(!f)exit(125);
 fprintf(f,"%d %d %d %d %d %d %d %d %.17g %.17g\n",im->Xsize,im->Ysize,im->Bands,im->BandFmt,im->Coding,im->Type,im->Xoffset,im->Yoffset,im->Xres,im->Yres);
 if(fclose(f))exit(125);
}
int main(int argc,char **argv){
 setenv("IM_CONCURRENCY","1",1);
 if(im_init_world(argv[0]))fail();
 if(argc==3&&!strcmp(argv[1],"--dump")){
  IMAGE *in=im_open(argv[2],"r");if(!in)fail();dump(in);if(im_close(in))fail();return 0;
 }
 if(argc!=4||strcmp(argv[1],"im_benchmark"))return 125;
 mallopt(M_TRIM_THRESHOLD,-1);mallopt(M_MMAP_MAX,0);
 volatile char *heap=(volatile char*)malloc(512*1024*1024);if(!heap)return 125;
 for(size_t i=0;i<512*1024*1024;i+=4096)heap[i]=0;free((void*)heap);
 IMAGE *in=im_open(argv[2],"r"),*out=im_open("ec-resident-output","t");
 if(!in||!out||im_incheck(in))fail();
 volatile unsigned char *pixels=in->data;volatile unsigned char touch=0;
 for(size_t i=0;i<(size_t)IM_IMAGE_SIZEOF_LINE(in)*in->Ysize;i+=4096)touch^=pixels[i];
 (void)touch;
#ifdef ENABLE_PARSEC_HOOKS
 __parsec_bench_begin(__parsec_vips);__parsec_roi_begin();
#endif
 /* Same original dispatch target. IM_SETBUF invokes vips_sink_memory eagerly:
    all transformations and all output pixels finish before ROI end. */
 if(im_benchmarkn(in,out,1))fail();
#ifdef ENABLE_PARSEC_HOOKS
 __parsec_roi_end();
#endif
 dump(out);
 IMAGE *file=im_open(argv[3],"w");if(!file||im_copy(out,file)||im_close(file))fail();
 if(im_close(out)||im_close(in))fail();
#ifdef ENABLE_PARSEC_HOOKS
 __parsec_bench_end();
#endif
 return 0;
}
