from adapter_build import *
import zlib,struct

out,src=setup('dedup_serial_htif_heap512_qword_setup')
(out/'htif.ld').write_text((out/'htif.ld').read_text().replace('PROVIDE(__heap_size = 4M)','PROVIDE(__heap_size = 512M)'))
app=EC/'Software/PARSEC/pkgs/kernels/dedup/src';original={}
for p in app.iterdir():
 if p.is_file() and p.suffix in ['.c','.h']:
  # Keep the measurement harness's config/header directories separate.
  shutil.copy2(p,src/p.name);original[p.name]=sha(p)
# Equivalent 64-bit table initialization is outside the measured pipeline.
p=src/'hashtable.c';t=p.read_text();old='memset(h->table, 0, size * sizeof(struct hash_entry *));'
assert t.count(old)==1
t=t.replace(old,'for (unsigned int zero_i=0; zero_i<size; ++zero_i) ((volatile uintptr_t *)h->table)[zero_i]=0;')
p.write_text('#include <stdint.h>\n'+t)
shutil.copytree(app/'openssl',src/'openssl',dirs_exist_ok=True)
for name in ['e_os2.h','opensslconf.h']:
 p=W/'software/apps-dedup-20261107T051408Z/src/dedup/openssl'/name
 shutil.copy2(p,src/'openssl'/name);original['openssl/'+name]=sha(p)
zsrc=EC/'Software/PARSEC/pkgs/libs/zlib/src'
for p in zsrc.iterdir():
 if p.is_file() and p.suffix in ['.c','.h']:
  shutil.copy2(p,src/p.name);original['zlib/'+p.name]=sha(p)
inputpath=W/'software/apps-dedup-20261107T051408Z/inputs/dedup/test/test.dat';data=inputpath.read_bytes()
(src/'embedded-input.h').write_text('static unsigned char embedded_input[] = {'+','.join(map(str,data))+'};\n')
t='#ifndef SSIZE_MAX\n#define SSIZE_MAX 9223372036854775807L\n#endif\n'+(src/'encoder.c').read_text().split('void Encode(config_t * _conf)')[0]
start=t.index('static int write_file(');stop=t.index('/*',t.index('return fd;',start))
t=t[:start]+'''static unsigned char archive[4096];static size_t archive_size;
static int write_file(int fd,u_char type,u_long len,u_char *content){
 assert(archive_size+1+8+len<=sizeof(archive));archive[archive_size++]=type;
 memcpy(archive+archive_size,&len,8);archive_size+=8;
 memcpy(archive+archive_size,content,len);archive_size+=len;return 0;
}
static int create_output_file(char *outfile){return 0;}
'''+t[stop:]
t=t.replace('close(fd_out);','(void)fd_out;')
adapter=r'''
#include "embedded-input.h"
static config_t config_storage;
config_t *conf=&config_storage;
static struct thread_args args;
void workload_prepare(void){
 conf->compress_type=COMPRESS_GZIP;conf->preloading=1;conf->nthreads=1;
 cache=hashtable_create(65536,hash_from_key_fn,keys_equal_fn,FALSE);assert(cache);
 assert(!mbuffer_system_init());init_stats(&stats);
 args.fd=-1;args.input_file.buffer=embedded_input;args.input_file.size=sizeof(embedded_input);
}
void workload_run(void){SerialIntegratedPipeline(&args);}
int workload_verify(void){
 uint64_t hash=14695981039346656037ULL;
 for(size_t i=0;i<archive_size;i++){hash^=archive[i];hash*=1099511628211ULL;}
 int ok=archive_size>9 && archive[0]==TYPE_COMPRESS;
#ifndef __riscv
 printf("[ARCHIVE] ");for(size_t i=0;i<archive_size;i++)printf("%02x",archive[i]);printf("\n");
#endif
 printf("[OUTPUT] benchmark=dedup checksum=%016lx verified=%d input_bytes=%lu archive_bytes=%lu compression=gzip\n",(unsigned long)hash,ok,(unsigned long)sizeof(embedded_input),(unsigned long)archive_size);return ok;
}
'''
(src/'dedup-adapter.c').write_text(t+adapter)
(src/'host-reference.cpp').write_text('extern "C" void workload_prepare(void),workload_run(void);extern "C" int workload_verify(void);int main(){workload_prepare();workload_run();return workload_verify()?0:1;}\n')
j=build(out,['dedup-adapter.c','rabin.c','hashtable.c','mbuffer.c','sha.c','adler32.c','compress.c','crc32.c','deflate.c','trees.c','zutil.c'],dict(benchmark='dedup',profile='official-test-gzip-serial-qword-setup-heap512',method='CPU_GG_FULL_OFFICIAL_TEST',extra_flags=['-DENABLE_GZIP_COMPRESSION'],original_source_sha256=original,input={'path':str(inputpath),'sha256':sha(inputpath),'bytes':len(data),'compression':'gzip','preloading':True,'profile':'official PARSEC test'},roi_scope='Complete original SerialIntegratedPipeline (Rabin, SHA1, dedup, gzip and archive encoding), preloaded input and RAM archive sink; cache setup and correctness outside ROI',adaptations=['ROI-external hashtable_create clears the identical 98317-entry pointer table with volatile uintptr_t stores instead of bytewise libc memset; table size/hash/pipeline unchanged; Native and EC share the same object', 'Heap reservation raised to 512 MiB for unchanged original 128 MiB streaming buffer','Input provided through original preloading path','Archive xwrite replaced by byte-preserving in-memory output; file open/header/close omitted','Original chunking/hash/dedup/compression computation retained'],max_target_cycles=4000000,timeout_seconds=7200))
line=next(s for s in (out/'host-reference.log').read_text().splitlines() if s.startswith('[ARCHIVE] '));archive=bytes.fromhex(line.split(' ',1)[1]);assert archive[0]==1
length=struct.unpack('<Q',archive[1:9])[0];assert length==len(archive)-9 and zlib.decompress(archive[9:])==data
save(out/'independent-reference.json',{'method':'Python zlib decoder reconstructs archive payload and compares exact bytes with original official test input','archive_sha256':hashlib.sha256(archive).hexdigest(),'input_sha256':sha(inputpath),'passed':True})
print(out/'manifest.json')
