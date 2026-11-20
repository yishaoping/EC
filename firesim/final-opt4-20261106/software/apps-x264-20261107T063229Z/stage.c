#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
static char *ec_output_bytes;static size_t ec_output_length;static FILE *ec_output_stream;static char *ec_output_name;
FILE *ec_x264_input(const char *p) {
 FILE *f=fopen(p,"rb");if(!f||fseek(f,0,SEEK_END))exit(125);long n=ftell(f);if(n<=0||fseek(f,0,SEEK_SET))exit(125);
 char *b=malloc(n);if(!b||fread(b,1,n,f)!=(size_t)n||fclose(f))exit(125);
 f=fmemopen(b,n,"rb");if(!f)exit(125);return f;
}
FILE *ec_x264_output(const char *p) {
 ec_output_name=strdup(p);ec_output_stream=open_memstream(&ec_output_bytes,&ec_output_length);if(!ec_output_stream)exit(125);return ec_output_stream;
}
void ec_x264_prepare(void) {
 mallopt(M_TRIM_THRESHOLD,-1);mallopt(M_MMAP_MAX,0);
 volatile char *h=(volatile char*)malloc(768*1024*1024);if(!h)exit(125);
 for(size_t i=0;i<768*1024*1024;i+=4096)h[i]=0;free((void*)h);
}
int ec_x264_close(FILE *f) {
 if(fclose(f))return -1;FILE *out=fopen(ec_output_name,"wb");if(!out)return -1;
 if(fwrite(ec_output_bytes,1,ec_output_length,out)!=ec_output_length)return -1;
 return fclose(out);
}
