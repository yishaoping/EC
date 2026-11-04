#include "../measurement/passive_stats.hpp"
// Compile-only check. No target simulator, FPGA or benchmark is run.
void check_interface() {
    ec_dac::ExecutionTracker t;
    ec_dac::PassiveStats s(4,1);
    (void)t;(void)s;
}
