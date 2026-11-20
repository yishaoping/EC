# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See Vtb.mk for the caller.

### Switches...
# C11 constructs required?  0/1 (always on now)
VM_C11 = 1
# Timing enabled?  0/1
VM_TIMING = 1
# Coverage output mode?  0/1 (from --coverage)
VM_COVERAGE = 0
# Parallel builds?  0/1 (from --output-split)
VM_PARALLEL_BUILDS = 1
# Tracing output mode?  0/1 (from --trace/--trace-fst)
VM_TRACE = 0
# Tracing output mode in VCD format?  0/1 (from --trace)
VM_TRACE_VCD = 0
# Tracing output mode in FST format?  0/1 (from --trace-fst)
VM_TRACE_FST = 0

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
	Vtb \
	Vtb___024root__DepSet_hfe20aad3__0 \
	Vtb___024root__DepSet_hfe20aad3__1 \
	Vtb___024root__DepSet_hfe20aad3__2 \
	Vtb___024root__DepSet_ha183790c__0 \
	Vtb_ReferenceBank__DepSet_hd69bb6e8__0 \
	Vtb_ReferenceBank__DepSet_hd69bb6e8__1 \
	Vtb_ReferenceBank__DepSet_hd69bb6e8__2 \
	Vtb_ReferenceBank__DepSet_hd69bb6e8__3 \
	Vtb_ReferenceBank__DepSet_hd69bb6e8__4 \
	Vtb_ReferenceBank__DepSet_hd69bb6e8__5 \
	Vtb_ReferenceBank__DepSet_hd69bb6e8__6 \
	Vtb_ReferenceBank__DepSet_hd69bb6e8__7 \
	Vtb_ReferenceBank__DepSet_hd69bb6e8__8 \
	Vtb_ReferenceBank__DepSet_hd69bb6e8__9 \
	Vtb_ReferenceBank__DepSet_hd69bb6e8__10 \
	Vtb_ReferenceBank__DepSet_hd69bb6e8__11 \
	Vtb_ReferenceBank__DepSet_hc798d588__0 \
	Vtb_ReferenceBank__DepSet_hc798d588__1 \
	Vtb_ReferenceBank__DepSet_hc798d588__2 \
	Vtb_ReferenceBank__DepSet_hc798d588__3 \
	Vtb_ReferenceBank__DepSet_hc798d588__4 \
	Vtb_ReferenceBank__DepSet_hc798d588__5 \
	Vtb_ReferenceBank__DepSet_hc798d588__6 \
	Vtb_ReferenceBank__DepSet_hc798d588__7 \
	Vtb_ReferenceBank__DepSet_hc798d588__8 \
	Vtb_ReferenceBank__DepSet_hc798d588__9 \
	Vtb_ReferenceBank__DepSet_hc798d588__10 \
	Vtb_ReferenceBank__DepSet_hc798d588__11 \
	Vtb_ReferenceBank__DepSet_hc798d588__12 \
	Vtb_ReferenceBank__DepSet_hc798d588__13 \
	Vtb_ReferenceBank__DepSet_hc798d588__14 \
	Vtb_ReferenceBank__DepSet_hc798d588__15 \
	Vtb_ReferenceBank__DepSet_hc798d588__16 \
	Vtb_ReferenceBank__DepSet_hc798d588__17 \
	Vtb_ReferenceBank__DepSet_hc798d588__18 \
	Vtb_ReferenceBank__DepSet_hc798d588__19 \
	Vtb_GeometryBankProof__DepSet_h41f969f1__0 \
	Vtb_GeometryBankProof__DepSet_h41f969f1__1 \
	Vtb_GeometryBankProof__DepSet_h41f969f1__2 \
	Vtb_GeometryBankProof__DepSet_h41f969f1__3 \
	Vtb_GeometryBankProof__DepSet_h41f969f1__4 \
	Vtb_GeometryBankProof__DepSet_h41f969f1__5 \
	Vtb_GeometryBankProof__DepSet_h41f969f1__6 \
	Vtb_GeometryBankProof__DepSet_h41f969f1__7 \
	Vtb_GeometryBankProof__DepSet_h82befb93__0 \
	Vtb_GeometryBankProof__DepSet_h82befb93__1 \
	Vtb_GeometryBankProof__DepSet_h82befb93__2 \
	Vtb_GeometryBankProof__DepSet_h82befb93__3 \
	Vtb_GeometryBankProof__DepSet_h82befb93__4 \
	Vtb_GeometryBankProof__DepSet_h82befb93__5 \
	Vtb_GeometryBankProof__DepSet_h82befb93__6 \
	Vtb_GeometryBankProof__DepSet_h82befb93__7 \
	Vtb_GeometryBankProof__DepSet_h82befb93__8 \
	Vtb_GeometryBankProof__DepSet_h82befb93__9 \
	Vtb_GeometryBankProof__DepSet_h82befb93__10 \
	Vtb_GeometryBankProof__DepSet_h82befb93__11 \
	Vtb_GeometryBankProof__DepSet_h82befb93__12 \
	Vtb_GeometryBankProof__DepSet_h82befb93__13 \
	Vtb_GeometryBankProof__DepSet_h82befb93__14 \
	Vtb_GeometryBankProof__DepSet_h82befb93__15 \
	Vtb_GeometryBankProof__DepSet_h82befb93__16 \
	Vtb_GeometryBankProof__DepSet_h82befb93__17 \
	Vtb_GeometryBankProof__DepSet_h82befb93__18 \
	Vtb_GeometryBankProof__DepSet_h82befb93__19 \
	Vtb__main \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
	Vtb___024root__Slow \
	Vtb___024root__DepSet_hfe20aad3__0__Slow \
	Vtb___024root__DepSet_ha183790c__0__Slow \
	Vtb_ReferenceBank__Slow \
	Vtb_ReferenceBank__DepSet_hd69bb6e8__0__Slow \
	Vtb_ReferenceBank__DepSet_hd69bb6e8__1__Slow \
	Vtb_ReferenceBank__DepSet_hc798d588__0__Slow \
	Vtb_ReferenceBank__DepSet_hc798d588__1__Slow \
	Vtb_ReferenceBank__DepSet_hc798d588__2__Slow \
	Vtb_GeometryBankProof__Slow \
	Vtb_GeometryBankProof__DepSet_h41f969f1__0__Slow \
	Vtb_GeometryBankProof__DepSet_h41f969f1__1__Slow \
	Vtb_GeometryBankProof__DepSet_h82befb93__0__Slow \
	Vtb_GeometryBankProof__DepSet_h82befb93__1__Slow \
	Vtb_GeometryBankProof__DepSet_h82befb93__2__Slow \
	Vtb_GeometryBankProof__DepSet_h82befb93__3__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
	Vtb__Syms \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
	verilated \
	verilated_timing \
	verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \


# Verilated -*- Makefile -*-
