# Run from the existing Verilator model directory. Reuse its objects and archive.
pressure_observer_source := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))pressure_observer.cc
include VTestHarness.mk

pressure-observer/observer.o: $(pressure_observer_source) $(dir $(pressure_observer_source))../rollback/io_effect_observer.cc VTestHarness.h VTestHarness___024root.h
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -O0 -c -o $@ $<

pressure-observer/simulator: pressure-observer/observer.o VTestHarness__ALL.a $(VK_USER_OBJS) $(VK_GLOBAL_OBJS)
	$(LINK) $(LDFLAGS) $< -Wl,--wrap=_ZN12VTestHarness9eval_stepEv $(VK_USER_OBJS) $(VK_GLOBAL_OBJS) VTestHarness__ALL.a $(LOADLIBES) $(LDLIBS) $(LIBS) $(SC_LIBS) -o $@
