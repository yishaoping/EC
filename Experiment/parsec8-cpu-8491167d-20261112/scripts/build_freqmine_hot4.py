from adapter_build import *
import re,math

out,src=setup('freqmine_serial_htif_hot4')
(out/'htif.ld').write_text((out/'htif.ld').read_text().replace('PROVIDE(__heap_size = 4M)','PROVIDE(__heap_size = 128M)'))
app=EC/'Software/PARSEC/pkgs/apps/freqmine/src'
original={}
for p in app.iterdir():
 if p.is_file() and p.suffix in ['.cpp','.h']:
  shutil.copy2(p,src/p.name);original[p.name]=sha(p)
inputpath=W/'software/apps-freqmine-20261107T050909Z/inputs/freqmine/test/T10I4D100K_3.dat'
data=inputpath.read_bytes();(src/'input.dat').write_bytes(data)
(src/'embedded-input.h').write_text('static const char embedded_input[] = '+json.dumps(data.decode())+';\n')
# Keep original globals; the unmodified computation lives in fp_tree.cpp.
main=(src/'fpmax.cpp').read_text().split('int main(int argc, char **argv)')[0]
main=main.replace('#include <iostream>','').replace('#include <fstream>','').replace('#include <iomanip>','').replace('using namespace std;','')
(src/'fpmax-globals.cpp').write_text(main)
for name in ['data.h','fp_tree.h']:
 p=src/name;t=p.read_text().replace('#include <fstream>','')
 if name=='data.h':
  t=t.replace('void close(){if(in)fclose(in);}','void close(){}').replace('return ftell(in);','return pos;')
  t=t.replace('return pos;','return cursor;').replace('fseek(in,0,SEEK_END);\n\t\ttotallength=ftell(in);\n\t\tfseek(in,0,SEEK_SET);','totallength=0;').replace('FILE *in;','const char *in;\n long cursor;')
 p.write_text(t)
p=src/'data.cpp';t=p.read_text()
start=t.index('Data::Data(char *filename)');stop=t.index('int *Data::parseDataFile')
t=t[:start]+'''#include "embedded-input.h"
Data::Data(char *) {in=embedded_input;cursor=0;}
Data::~Data() {}
int Data::isOpen() {return 1;}
'''+t[stop:]
t=t.replace('char c;','int c;').replace('c = getc(in);','c = in[cursor] ? (unsigned char)in[cursor++] : EOF;').replace('else if(feof(in))','else if(c==EOF)').replace('rewind(in);','cursor=0;')
p.write_text(t)
p=src/'fp_tree.cpp';t=p.read_text().replace('#include <sys/syscall.h>','')
# Host thread affinity and wall-clock printing are unrelated to serial mining.
t=t.replace('#include <sched.h>','')
start=t.index('#ifdef CPU_SETSIZE');stop=t.index('#endif',start)+len('#endif')
t=t[:start]+t[stop:]
t=t.replace('#define hot_item_num\t16','#define hot_item_num\t4').replace('#define hot_item_num1\t6','#define hot_item_num1\t4')
# Original x86 source packs pointer arrays immediately after int arrays.
# Align typed scratch-array starts for RV64 and reserve bounded padding per block.
t='#include <stdint.h>\n'+t
pattern=r'(=\s*)\(([^;=()]*\*+)\)\s*\(([^;=()]+)\)'
def pad(m):
 return m[1]+'('+m[2]+')(((uintptr_t)('+m[3]+')+7)&~(uintptr_t)7)'
t=re.sub(pattern,pad,t)
t=t.replace('for (j = num_hot_item - 1; ((1 << j) & i) == 0; j --);','for (j = num_hot_item - 1; j>=0 && ((1U << j) & (unsigned)i) == 0; j --);\n if(j<0){printf(\"[HOTINDEX] invalid i=%d hot=%d items=%d\\n\",i,num_hot_item,itemno);abort();}')
p.write_text(t)
p=src/'buffer.cpp';t=p.read_text().replace('i = num * size;','i = num * size + 256;').replace('(size & L2BITS)','(size & 7)');p.write_text(t)
(src/'wtime.cpp').write_text('#include "wtime.h"\nvoid wtime(double *t){*t=0;}\n')
adapter=r'''#include "common.h"
#include <stdint.h>
#include <stdio.h>
static FP_tree *tree;
static Data *data;
extern "C" void workload_prepare(void) {
 THRESHOLD=1;data=new Data((char*)"embedded");
 fp_buf=new memory*[1];fp_tree_buf=new memory*[1];
 fp_buf[0]=new memory(60,10485760,20971520,2);
 fp_tree_buf[0]=new memory(80,10485760,20971520,2);
 database_buf=new memory(60,4194304L,4194304L,2);
 tree=(FP_tree*)fp_buf[0]->newbuf(1,sizeof(FP_tree));tree->init(-1,0,0);
}
extern "C" void workload_run(void) {tree->scan1_DB(data);tree->scan2_DB(1);tree->FP_growth_first(NULL);}
extern "C" int workload_verify(void) {
 const int expected[16]={34,191,736,2139,4876,8972,13712,17404,18568,16445,12116,7315,3544,1330,376,70};
 uint64_t h=14695981039346656037ULL;int ok=TRANSACTION_NO==3;
 for(int k=0;k<16;k++){printf("[COUNT] length=%d count=%d\n",k+1,ITlen[0][k]);h^=(uint64_t)ITlen[0][k];h*=1099511628211ULL;}
 printf("[OUTPUT] benchmark=freqmine checksum=%016lx verified=%d transactions=%d threshold=1\n",(unsigned long)h,ok,TRANSACTION_NO);return ok;
}
'''
# Independent exact count of distinct frequent itemsets by cardinality, for threshold=1.
sets=[set(map(int,line.split())) for line in data.decode().splitlines() if line.strip()]
expected=[]
for k in range(1,max(map(len,sets))+1):
 total=0
 for mask in range(1,1<<len(sets)):
  intersect=set.intersection(*(sets[i] for i in range(len(sets)) if mask>>i&1))
  total+=(-1 if mask.bit_count()%2==0 else 1)*math.comb(len(intersect),k) if len(intersect)>=k else 0
 expected.append(total)
adapter=re.sub(r'const int expected\[16\]=\{[^}]*\};','const int expected[16]={'+','.join(map(str,expected))+'};',adapter)
adapter=adapter.replace('for(int k=0;k<16;k++){printf','for(int k=0;k<16;k++){ok=ok && ITlen[0][k]==expected[k];printf')
(src/'freqmine-adapter.cpp').write_text(adapter)
(src/'host-reference.cpp').write_text('extern "C" void workload_prepare(void),workload_run(void);extern "C" int workload_verify(void);int main(){workload_prepare();workload_run();return workload_verify()?0:1;}\n')
save(out/'independent-reference.json',{'input_sha256':sha(inputpath),'distinct_frequent_itemsets_by_length':expected,'method':'Exact inclusion/exclusion over all nonempty intersections of the 3 official test transactions; threshold 1'})
j=build(out,['fpmax-globals.cpp','data.cpp','fp_tree.cpp','buffer.cpp','fsout.cpp','fp_node.cpp','wtime.cpp','freqmine-adapter.cpp'],dict(benchmark='freqmine',profile='test-input-hot4-lp64',method='CPU_GG_TEST_DERIVED_REPRESENTATIVE_ROI',original_source_sha256=original,input={'path':str(inputpath),'sha256':sha(inputpath),'transactions':3,'threshold':1,'profile':'official PARSEC test'},limitations=['Original hot-item cache setting reduced 16 to 4 (recursive cache 6 to 4) equally in Native/EC and host; complete official-test itemset output verified but runtime is not original default cache configuration','Full-default test and simmedium extrapolation error uncalibrated'],roi_scope='Hot4 original scan1_DB + scan2_DB + FP_growth_first; memory-pool setup and output verification outside ROI; input bytes read through embedded memory stream',adaptations=['Packed scratch arrays aligned to 8 bytes and each pool allocation reserves 256 bytes of padding; fixes original x86-only unaligned pointer packing with unchanged mining/count semantics',
 'Heap reservation increased from 4 MiB to 128 MiB to fit unchanged original memory pools',
 'Data filesystem reads replaced with byte-identical embedded stream; full original FP-growth computation retained','Unused iostream headers, host thread affinity and original CLI removed; wall-clock function returns zero in both builds; source hashes retained'],independent_reference=str(out/'independent-reference.json'),max_target_cycles=4000000))
print(json.dumps({'manifest':str(out/'manifest.json'),'expected_output':j['expected_output']},indent=2))
