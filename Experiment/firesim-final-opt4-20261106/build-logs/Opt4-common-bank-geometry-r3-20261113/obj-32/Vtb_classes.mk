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
	Vtb___024root__DepSet_ha183790c__1 \
	Vtb___024root__DepSet_ha183790c__2 \
	Vtb___024root__DepSet_ha183790c__3 \
	Vtb___024root__DepSet_ha183790c__4 \
	Vtb___024root__DepSet_ha183790c__5 \
	Vtb___024root__DepSet_ha183790c__6 \
	Vtb___024root__DepSet_ha183790c__7 \
	Vtb___024root__DepSet_ha183790c__8 \
	Vtb___024root__DepSet_ha183790c__9 \
	Vtb___024root__DepSet_ha183790c__10 \
	Vtb___024root__DepSet_ha183790c__11 \
	Vtb___024root__DepSet_ha183790c__12 \
	Vtb___024root__DepSet_ha183790c__13 \
	Vtb___024root__DepSet_ha183790c__14 \
	Vtb___024root__DepSet_ha183790c__15 \
	Vtb___024root__DepSet_ha183790c__16 \
	Vtb___024root__DepSet_ha183790c__17 \
	Vtb___024root__DepSet_ha183790c__18 \
	Vtb___024root__DepSet_ha183790c__19 \
	Vtb___024root__DepSet_ha183790c__20 \
	Vtb___024root__DepSet_ha183790c__21 \
	Vtb___024root__DepSet_ha183790c__22 \
	Vtb___024root__DepSet_ha183790c__23 \
	Vtb___024root__DepSet_ha183790c__24 \
	Vtb___024root__DepSet_ha183790c__25 \
	Vtb___024root__DepSet_ha183790c__26 \
	Vtb___024root__DepSet_ha183790c__27 \
	Vtb___024root__DepSet_ha183790c__28 \
	Vtb___024root__DepSet_ha183790c__29 \
	Vtb___024root__DepSet_ha183790c__30 \
	Vtb___024root__DepSet_ha183790c__31 \
	Vtb___024root__DepSet_ha183790c__32 \
	Vtb___024root__DepSet_ha183790c__33 \
	Vtb___024root__DepSet_ha183790c__34 \
	Vtb___024root__DepSet_ha183790c__35 \
	Vtb___024root__DepSet_ha183790c__36 \
	Vtb___024root__DepSet_ha183790c__37 \
	Vtb___024root__DepSet_ha183790c__38 \
	Vtb___024root__DepSet_ha183790c__39 \
	Vtb___024root__DepSet_ha183790c__40 \
	Vtb___024root__DepSet_ha183790c__41 \
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
	Vtb__main \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
	Vtb___024root__Slow \
	Vtb___024root__DepSet_hfe20aad3__0__Slow \
	Vtb___024root__DepSet_ha183790c__0__Slow \
	Vtb___024root__DepSet_ha183790c__1__Slow \
	Vtb___024root__DepSet_ha183790c__2__Slow \
	Vtb___024root__DepSet_ha183790c__3__Slow \
	Vtb___024root__DepSet_ha183790c__4__Slow \
	Vtb_ReferenceBank__Slow \
	Vtb_ReferenceBank__DepSet_hd69bb6e8__0__Slow \
	Vtb_ReferenceBank__DepSet_hd69bb6e8__1__Slow \
	Vtb_ReferenceBank__DepSet_hc798d588__0__Slow \
	Vtb_ReferenceBank__DepSet_hc798d588__1__Slow \
	Vtb_ReferenceBank__DepSet_hc798d588__2__Slow \

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
