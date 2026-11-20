/* RISC-V LP64 port: GCC atomics preserve lock and ordering semantics. */
#ifndef _BSD_MACHINE_ATOMIC_H_
#define _BSD_MACHINE_ATOMIC_H_
#define mb() __atomic_thread_fence(__ATOMIC_SEQ_CST)
#define rmb() __atomic_thread_fence(__ATOMIC_SEQ_CST)
#define wmb() __atomic_thread_fence(__ATOMIC_SEQ_CST)
static __inline void atomic_set_char(volatile u_char *p, u_char v) { __atomic_fetch_or(p,v,__ATOMIC_SEQ_CST); }
static __inline void atomic_set_barr_char(volatile u_char *p, u_char v) { __atomic_fetch_or(p,v,__ATOMIC_SEQ_CST); }
static __inline void atomic_clear_char(volatile u_char *p, u_char v) { __atomic_fetch_and(p,(u_char)~v,__ATOMIC_SEQ_CST); }
static __inline void atomic_clear_barr_char(volatile u_char *p, u_char v) { __atomic_fetch_and(p,(u_char)~v,__ATOMIC_SEQ_CST); }
static __inline void atomic_add_char(volatile u_char *p, u_char v) { __atomic_fetch_add(p,v,__ATOMIC_SEQ_CST); }
static __inline void atomic_add_barr_char(volatile u_char *p, u_char v) { __atomic_fetch_add(p,v,__ATOMIC_SEQ_CST); }
static __inline void atomic_subtract_char(volatile u_char *p, u_char v) { __atomic_fetch_sub(p,v,__ATOMIC_SEQ_CST); }
static __inline void atomic_subtract_barr_char(volatile u_char *p, u_char v) { __atomic_fetch_sub(p,v,__ATOMIC_SEQ_CST); }
static __inline int atomic_cmpset_char(volatile u_char *p,u_char e,u_char v) { return __atomic_compare_exchange_n(p,&e,v,0,__ATOMIC_SEQ_CST,__ATOMIC_SEQ_CST); }
static __inline u_char atomic_fetchadd_char(volatile u_char *p,u_char v) { return __atomic_fetch_add(p,v,__ATOMIC_SEQ_CST); }
static __inline u_char atomic_readandclear_char(volatile u_char *p) { return __atomic_exchange_n(p,0,__ATOMIC_SEQ_CST); }
static __inline u_char atomic_load_acq_char(volatile u_char *p) { return __atomic_load_n(p,__ATOMIC_ACQUIRE); }
static __inline void atomic_store_rel_char(volatile u_char *p,u_char v) { __atomic_store_n(p,v,__ATOMIC_RELEASE); }
static __inline void atomic_set_short(volatile u_short *p, u_short v) { __atomic_fetch_or(p,v,__ATOMIC_SEQ_CST); }
static __inline void atomic_set_barr_short(volatile u_short *p, u_short v) { __atomic_fetch_or(p,v,__ATOMIC_SEQ_CST); }
static __inline void atomic_clear_short(volatile u_short *p, u_short v) { __atomic_fetch_and(p,(u_short)~v,__ATOMIC_SEQ_CST); }
static __inline void atomic_clear_barr_short(volatile u_short *p, u_short v) { __atomic_fetch_and(p,(u_short)~v,__ATOMIC_SEQ_CST); }
static __inline void atomic_add_short(volatile u_short *p, u_short v) { __atomic_fetch_add(p,v,__ATOMIC_SEQ_CST); }
static __inline void atomic_add_barr_short(volatile u_short *p, u_short v) { __atomic_fetch_add(p,v,__ATOMIC_SEQ_CST); }
static __inline void atomic_subtract_short(volatile u_short *p, u_short v) { __atomic_fetch_sub(p,v,__ATOMIC_SEQ_CST); }
static __inline void atomic_subtract_barr_short(volatile u_short *p, u_short v) { __atomic_fetch_sub(p,v,__ATOMIC_SEQ_CST); }
static __inline int atomic_cmpset_short(volatile u_short *p,u_short e,u_short v) { return __atomic_compare_exchange_n(p,&e,v,0,__ATOMIC_SEQ_CST,__ATOMIC_SEQ_CST); }
static __inline u_short atomic_fetchadd_short(volatile u_short *p,u_short v) { return __atomic_fetch_add(p,v,__ATOMIC_SEQ_CST); }
static __inline u_short atomic_readandclear_short(volatile u_short *p) { return __atomic_exchange_n(p,0,__ATOMIC_SEQ_CST); }
static __inline u_short atomic_load_acq_short(volatile u_short *p) { return __atomic_load_n(p,__ATOMIC_ACQUIRE); }
static __inline void atomic_store_rel_short(volatile u_short *p,u_short v) { __atomic_store_n(p,v,__ATOMIC_RELEASE); }
static __inline void atomic_set_int(volatile u_int *p, u_int v) { __atomic_fetch_or(p,v,__ATOMIC_SEQ_CST); }
static __inline void atomic_set_barr_int(volatile u_int *p, u_int v) { __atomic_fetch_or(p,v,__ATOMIC_SEQ_CST); }
static __inline void atomic_clear_int(volatile u_int *p, u_int v) { __atomic_fetch_and(p,(u_int)~v,__ATOMIC_SEQ_CST); }
static __inline void atomic_clear_barr_int(volatile u_int *p, u_int v) { __atomic_fetch_and(p,(u_int)~v,__ATOMIC_SEQ_CST); }
static __inline void atomic_add_int(volatile u_int *p, u_int v) { __atomic_fetch_add(p,v,__ATOMIC_SEQ_CST); }
static __inline void atomic_add_barr_int(volatile u_int *p, u_int v) { __atomic_fetch_add(p,v,__ATOMIC_SEQ_CST); }
static __inline void atomic_subtract_int(volatile u_int *p, u_int v) { __atomic_fetch_sub(p,v,__ATOMIC_SEQ_CST); }
static __inline void atomic_subtract_barr_int(volatile u_int *p, u_int v) { __atomic_fetch_sub(p,v,__ATOMIC_SEQ_CST); }
static __inline int atomic_cmpset_int(volatile u_int *p,u_int e,u_int v) { return __atomic_compare_exchange_n(p,&e,v,0,__ATOMIC_SEQ_CST,__ATOMIC_SEQ_CST); }
static __inline u_int atomic_fetchadd_int(volatile u_int *p,u_int v) { return __atomic_fetch_add(p,v,__ATOMIC_SEQ_CST); }
static __inline u_int atomic_readandclear_int(volatile u_int *p) { return __atomic_exchange_n(p,0,__ATOMIC_SEQ_CST); }
static __inline u_int atomic_load_acq_int(volatile u_int *p) { return __atomic_load_n(p,__ATOMIC_ACQUIRE); }
static __inline void atomic_store_rel_int(volatile u_int *p,u_int v) { __atomic_store_n(p,v,__ATOMIC_RELEASE); }
static __inline void atomic_set_long(volatile u_long *p, u_long v) { __atomic_fetch_or(p,v,__ATOMIC_SEQ_CST); }
static __inline void atomic_set_barr_long(volatile u_long *p, u_long v) { __atomic_fetch_or(p,v,__ATOMIC_SEQ_CST); }
static __inline void atomic_clear_long(volatile u_long *p, u_long v) { __atomic_fetch_and(p,(u_long)~v,__ATOMIC_SEQ_CST); }
static __inline void atomic_clear_barr_long(volatile u_long *p, u_long v) { __atomic_fetch_and(p,(u_long)~v,__ATOMIC_SEQ_CST); }
static __inline void atomic_add_long(volatile u_long *p, u_long v) { __atomic_fetch_add(p,v,__ATOMIC_SEQ_CST); }
static __inline void atomic_add_barr_long(volatile u_long *p, u_long v) { __atomic_fetch_add(p,v,__ATOMIC_SEQ_CST); }
static __inline void atomic_subtract_long(volatile u_long *p, u_long v) { __atomic_fetch_sub(p,v,__ATOMIC_SEQ_CST); }
static __inline void atomic_subtract_barr_long(volatile u_long *p, u_long v) { __atomic_fetch_sub(p,v,__ATOMIC_SEQ_CST); }
static __inline int atomic_cmpset_long(volatile u_long *p,u_long e,u_long v) { return __atomic_compare_exchange_n(p,&e,v,0,__ATOMIC_SEQ_CST,__ATOMIC_SEQ_CST); }
static __inline u_long atomic_fetchadd_long(volatile u_long *p,u_long v) { return __atomic_fetch_add(p,v,__ATOMIC_SEQ_CST); }
static __inline u_long atomic_readandclear_long(volatile u_long *p) { return __atomic_exchange_n(p,0,__ATOMIC_SEQ_CST); }
static __inline u_long atomic_load_acq_long(volatile u_long *p) { return __atomic_load_n(p,__ATOMIC_ACQUIRE); }
static __inline void atomic_store_rel_long(volatile u_long *p,u_long v) { __atomic_store_n(p,v,__ATOMIC_RELEASE); }
#define	atomic_set_acq_char		atomic_set_barr_char
#define	atomic_set_rel_char		atomic_set_barr_char
#define	atomic_clear_acq_char		atomic_clear_barr_char
#define	atomic_clear_rel_char		atomic_clear_barr_char
#define	atomic_add_acq_char		atomic_add_barr_char
#define	atomic_add_rel_char		atomic_add_barr_char
#define	atomic_subtract_acq_char	atomic_subtract_barr_char
#define	atomic_subtract_rel_char	atomic_subtract_barr_char

#define	atomic_set_acq_short		atomic_set_barr_short
#define	atomic_set_rel_short		atomic_set_barr_short
#define	atomic_clear_acq_short		atomic_clear_barr_short
#define	atomic_clear_rel_short		atomic_clear_barr_short
#define	atomic_add_acq_short		atomic_add_barr_short
#define	atomic_add_rel_short		atomic_add_barr_short
#define	atomic_subtract_acq_short	atomic_subtract_barr_short
#define	atomic_subtract_rel_short	atomic_subtract_barr_short

#define	atomic_set_acq_int		atomic_set_barr_int
#define	atomic_set_rel_int		atomic_set_barr_int
#define	atomic_clear_acq_int		atomic_clear_barr_int
#define	atomic_clear_rel_int		atomic_clear_barr_int
#define	atomic_add_acq_int		atomic_add_barr_int
#define	atomic_add_rel_int		atomic_add_barr_int
#define	atomic_subtract_acq_int		atomic_subtract_barr_int
#define	atomic_subtract_rel_int		atomic_subtract_barr_int
#define	atomic_cmpset_acq_int		atomic_cmpset_int
#define	atomic_cmpset_rel_int		atomic_cmpset_int

#define	atomic_set_acq_long		atomic_set_barr_long
#define	atomic_set_rel_long		atomic_set_barr_long
#define	atomic_clear_acq_long		atomic_clear_barr_long
#define	atomic_clear_rel_long		atomic_clear_barr_long
#define	atomic_add_acq_long		atomic_add_barr_long
#define	atomic_add_rel_long		atomic_add_barr_long
#define	atomic_subtract_acq_long	atomic_subtract_barr_long
#define	atomic_subtract_rel_long	atomic_subtract_barr_long
#define	atomic_cmpset_acq_long		atomic_cmpset_long
#define	atomic_cmpset_rel_long		atomic_cmpset_long

/* Operations on 8-bit bytes. */
#define	atomic_set_8		atomic_set_char
#define	atomic_set_acq_8	atomic_set_acq_char
#define	atomic_set_rel_8	atomic_set_rel_char
#define	atomic_clear_8		atomic_clear_char
#define	atomic_clear_acq_8	atomic_clear_acq_char
#define	atomic_clear_rel_8	atomic_clear_rel_char
#define	atomic_add_8		atomic_add_char
#define	atomic_add_acq_8	atomic_add_acq_char
#define	atomic_add_rel_8	atomic_add_rel_char
#define	atomic_subtract_8	atomic_subtract_char
#define	atomic_subtract_acq_8	atomic_subtract_acq_char
#define	atomic_subtract_rel_8	atomic_subtract_rel_char
#define	atomic_load_acq_8	atomic_load_acq_char
#define	atomic_store_rel_8	atomic_store_rel_char

/* Operations on 16-bit words. */
#define	atomic_set_16		atomic_set_short
#define	atomic_set_acq_16	atomic_set_acq_short
#define	atomic_set_rel_16	atomic_set_rel_short
#define	atomic_clear_16		atomic_clear_short
#define	atomic_clear_acq_16	atomic_clear_acq_short
#define	atomic_clear_rel_16	atomic_clear_rel_short
#define	atomic_add_16		atomic_add_short
#define	atomic_add_acq_16	atomic_add_acq_short
#define	atomic_add_rel_16	atomic_add_rel_short
#define	atomic_subtract_16	atomic_subtract_short
#define	atomic_subtract_acq_16	atomic_subtract_acq_short
#define	atomic_subtract_rel_16	atomic_subtract_rel_short
#define	atomic_load_acq_16	atomic_load_acq_short
#define	atomic_store_rel_16	atomic_store_rel_short

/* Operations on 32-bit double words. */
#define	atomic_set_32		atomic_set_int
#define	atomic_set_acq_32	atomic_set_acq_int
#define	atomic_set_rel_32	atomic_set_rel_int
#define	atomic_clear_32		atomic_clear_int
#define	atomic_clear_acq_32	atomic_clear_acq_int
#define	atomic_clear_rel_32	atomic_clear_rel_int
#define	atomic_add_32		atomic_add_int
#define	atomic_add_acq_32	atomic_add_acq_int
#define	atomic_add_rel_32	atomic_add_rel_int
#define	atomic_subtract_32	atomic_subtract_int
#define	atomic_subtract_acq_32	atomic_subtract_acq_int
#define	atomic_subtract_rel_32	atomic_subtract_rel_int
#define	atomic_load_acq_32	atomic_load_acq_int
#define	atomic_store_rel_32	atomic_store_rel_int
#define	atomic_cmpset_32	atomic_cmpset_int
#define	atomic_cmpset_acq_32	atomic_cmpset_acq_int
#define	atomic_cmpset_rel_32	atomic_cmpset_rel_int
#define	atomic_readandclear_32	atomic_readandclear_int
#define	atomic_fetchadd_32	atomic_fetchadd_int

/* Operations on 64-bit quad words. */
#define	atomic_set_64		atomic_set_long
#define	atomic_set_acq_64	atomic_set_acq_long
#define	atomic_set_rel_64	atomic_set_rel_long
#define	atomic_clear_64		atomic_clear_long
#define	atomic_clear_acq_64	atomic_clear_acq_long
#define	atomic_clear_rel_64	atomic_clear_rel_long
#define	atomic_add_64		atomic_add_long
#define	atomic_add_acq_64	atomic_add_acq_long
#define	atomic_add_rel_64	atomic_add_rel_long
#define	atomic_subtract_64	atomic_subtract_long
#define	atomic_subtract_acq_64	atomic_subtract_acq_long
#define	atomic_subtract_rel_64	atomic_subtract_rel_long
#define	atomic_load_acq_64	atomic_load_acq_long
#define	atomic_store_rel_64	atomic_store_rel_long
#define	atomic_cmpset_64	atomic_cmpset_long
#define	atomic_cmpset_acq_64	atomic_cmpset_acq_long
#define	atomic_cmpset_rel_64	atomic_cmpset_rel_long
#define	atomic_readandclear_64	atomic_readandclear_long

/* Operations on pointers. */
#define	atomic_set_ptr		atomic_set_long
#define	atomic_set_acq_ptr	atomic_set_acq_long
#define	atomic_set_rel_ptr	atomic_set_rel_long
#define	atomic_clear_ptr	atomic_clear_long
#define	atomic_clear_acq_ptr	atomic_clear_acq_long
#define	atomic_clear_rel_ptr	atomic_clear_rel_long
#define	atomic_add_ptr		atomic_add_long
#define	atomic_add_acq_ptr	atomic_add_acq_long
#define	atomic_add_rel_ptr	atomic_add_rel_long
#define	atomic_subtract_ptr	atomic_subtract_long
#define	atomic_subtract_acq_ptr	atomic_subtract_acq_long
#define	atomic_subtract_rel_ptr	atomic_subtract_rel_long
#define	atomic_load_acq_ptr	atomic_load_acq_long
#define	atomic_store_rel_ptr	atomic_store_rel_long
#define	atomic_cmpset_ptr	atomic_cmpset_long
#define	atomic_cmpset_acq_ptr	atomic_cmpset_acq_long
#define	atomic_cmpset_rel_ptr	atomic_cmpset_rel_long
#define	atomic_readandclear_ptr	atomic_readandclear_long


#endif
