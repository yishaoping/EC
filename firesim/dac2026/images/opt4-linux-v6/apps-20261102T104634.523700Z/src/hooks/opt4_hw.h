#ifndef EC_OPT4_HW_H
#define EC_OPT4_HW_H
/* Exact original GHE instruction ABI, with explicit compiler memory barriers. */
#define EC_RD(fn, input) ({ \
 register unsigned long _a0 __asm__("a0"); \
 register unsigned long _a1 __asm__("a1") = (input); \
 __asm__ volatile(".insn r 0x2b,6," #fn ",a0,a1,zero" \
 : "=r"(_a0) : "r"(_a1) : "memory"); _a0; })
#define EC_SET(fn, input) do { \
 register unsigned long _a1 __asm__("a1") = (input); \
 __asm__ volatile(".insn r 0x2b,2," #fn ",zero,a1,zero" \
 : : "r"(_a1) : "memory"); } while (0)
#define EC_CMD(fn) __asm__ volatile(".insn r 0x2b,0," #fn ",zero,zero,zero" ::: "memory")
static inline void ec_config(unsigned long input)
{
 register unsigned long a1 __asm__("a1") = input;
 register unsigned long a2 __asm__("a2") = 2;
 __asm__ volatile(".insn r 0x2b,3,0x06,zero,a1,a2" : : "r"(a1),"r"(a2) : "memory");
}
static inline void ec_perf(unsigned long command)
{ EC_SET(0x76, command); EC_SET(0x76, 0); }
static inline unsigned long ec_traffic(unsigned index) { return EC_RD(0x7b, index); }
static inline void ec_opt4_configure(void) {
 EC_SET(0x1c, 4);
 ec_config(0x640012UL);
 ec_config(0x10640012UL);
 ec_config(0x20640012UL);
 ec_config(0x40640012UL);
 ec_config(0x50640012UL);
 ec_config(0x30640012UL);
 ec_config(0x60640012UL);
 ec_config(0x20e40012UL);
 ec_config(0x30e40012UL);
 ec_config(0x40e40012UL);
 ec_config(0xa0040012UL);
 ec_config(0xb0040012UL);
 ec_config(0xc0040012UL);
 ec_config(0xd0040012UL);
 ec_config(0xe0040012UL);
 ec_config(0xf0040012UL);
 ec_config(0xa0440012UL);
 ec_config(0xb0440012UL);
 ec_config(0xc0440012UL);
 ec_config(0xd0440012UL);
 ec_config(0xe0440012UL);
 ec_config(0xf0440012UL);
 ec_config(0x4660022UL);
 ec_config(0x14660022UL);
 ec_config(0x24660022UL);
 ec_config(0x34660022UL);
 ec_config(0x24e60022UL);
 ec_config(0x34e60022UL);
 ec_config(0x44e60022UL);
 ec_config(0xa0860022UL);
 ec_config(0xb0860022UL);
 ec_config(0xc0860022UL);
 ec_config(0xd0860022UL);
 ec_config(0xe0860022UL);
 ec_config(0xf0860022UL);
 ec_config(0xa0c60022UL);
 ec_config(0xb0c60022UL);
 ec_config(0xc0c60022UL);
 ec_config(0xd0c60022UL);
 ec_config(0xe0c60022UL);
 ec_config(0xf0c60022UL);
 ec_config(0x1e620032UL);
 ec_config(0x2e620032UL);
 ec_config(0x3e620032UL);
 ec_config(0x5e620032UL);
 ec_config(0x6e620032UL);
 ec_config(0x7e620032UL);
 ec_config(0x25ea0012UL);
 ec_config(0x35ea0012UL);
 ec_config(0x10220004UL);
 ec_config(0x20240014UL);
 ec_config(0x30260024UL);
 ec_config(0x40280034UL);
 for (unsigned hart=1; hart<=4; ++hart) {
  static const unsigned type[] = {0x81,0x82,0x83,0x41,0x42,0x43,0x87,0x47,0xc7,0x85,0x45,0xc5};
  for (unsigned n=0; n<sizeof(type)/sizeof(type[0]); ++n)
   ec_config((((type[n] | (hart<<3)) & 255) << 4) | ((1UL << (hart-1)) << 16) | 3);
 }
 ec_config(5); /* original debug filter width=0 */
 EC_SET(0x7d, 15);
}
#endif
