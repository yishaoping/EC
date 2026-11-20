#ifdef __riscv
#include <malloc.h>
#include <stddef.h>
extern "C" int posix_memalign(void **p,size_t align,size_t bytes){*p=memalign(align,bytes);return *p?0:12;}
#endif
