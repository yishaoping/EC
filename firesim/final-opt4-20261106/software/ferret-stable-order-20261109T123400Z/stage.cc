#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <dirent.h>
#include <sys/stat.h>
#include <malloc.h>
#include <map>
#include <string>
#include <vector>
struct Directory {std::vector<struct dirent> entries; size_t next;};
static std::map<std::string,Directory> directories;
static std::map<std::string,struct stat> metadata;
static std::map<std::string,std::vector<char> > bytes;
static char *output_bytes; static size_t output_length;
static FILE *output_stream;
static void preload(const std::string &p) {
 struct stat st;if(stat(p.c_str(),&st))exit(125);metadata[p]=st;
 if(S_ISDIR(st.st_mode)) {
  DIR *d=opendir(p.c_str());if(!d)exit(125);struct dirent *e;
  while((e=readdir(d))) directories[p].entries.push_back(*e);
  if(closedir(d))exit(125);
  std::sort(directories[p].entries.begin(), directories[p].entries.end(), [](const struct dirent &a, const struct dirent &b) { return strcmp(a.d_name, b.d_name) < 0; });
  directories[p].next=0;
  for(size_t i=0;i<directories[p].entries.size();i++) {
   const char *n=directories[p].entries[i].d_name;
   if(!strcmp(n,".")||!strcmp(n,".."))continue;
   preload(p=="."?std::string(n):p+"/"+n);
  }
 } else if(S_ISREG(st.st_mode)) {
  FILE *f=fopen(p.c_str(),"rb");if(!f)exit(125);
  std::vector<char> &v=bytes[p];v.resize(st.st_size);
  if(fread(v.data(),1,v.size(),f)!=v.size()||fclose(f))exit(125);
 }
}
extern "C" void ec_ferret_prepare(const char *p) {
 mallopt(M_TRIM_THRESHOLD,-1);mallopt(M_MMAP_MAX,0);
 volatile char *h=(volatile char*)malloc(512*1024*1024);if(!h)exit(125);
 for(size_t i=0;i<512*1024*1024;i+=4096)h[i]=0;free((void*)h);
 preload(p);
}
extern "C" DIR *ec_ferret_opendir(const char *p) {
 std::string key=p;while(key.size()>1&&key.back()=='/')key.pop_back();
 auto it=directories.find(key);if(it==directories.end())exit(125);
 it->second.next=0;return reinterpret_cast<DIR*>(&it->second);
}
extern "C" struct dirent *ec_ferret_readdir(DIR *p) {
 Directory *d=reinterpret_cast<Directory*>(p);
 return d->next==d->entries.size()?NULL:&d->entries[d->next++];
}
extern "C" int ec_ferret_closedir(DIR *) {return 0;}
extern "C" int ec_ferret_stat(const char *p,struct stat *s) {
 auto it=metadata.find(p);if(it==metadata.end())exit(125);*s=it->second;return 0;
}
extern "C" FILE *ec_ferret_input(const char *p) {
 auto it=bytes.find(p);if(it==bytes.end())exit(125);
 FILE *f=fmemopen(it->second.data(),it->second.size(),"rb");if(!f)exit(125);return f;
}
extern "C" FILE *ec_ferret_output(void) {
 output_stream=open_memstream(&output_bytes,&output_length);if(!output_stream)exit(125);return output_stream;
}
extern "C" void ec_ferret_flush(const char *p) {
 if(fflush(output_stream))exit(125);FILE *f=fopen(p,"wb");if(!f)exit(125);
 if(fwrite(output_bytes,1,output_length,f)!=output_length||fclose(f))exit(125);
}
