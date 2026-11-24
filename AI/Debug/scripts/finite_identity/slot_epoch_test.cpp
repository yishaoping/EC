#define main hierarchy_regression_main
#include "../rollback/hierarchy_test.cpp"
#undef main

int main(int argc, char **argv) {
  Verilated::commandArgs(argc, argv);
  Test t;
  t.reset();
  // Only the reset values of two EMPTY slots are accelerated by the runner.
  // Requests, reservation checks, MSHR terminal and data remain production.
  auto* root=t.d.rootp;
  t.check(root->HierarchyHarness__DOT__l1__DOT__slotEpoch_64_0==0xffff &&
          root->HierarchyHarness__DOT__l1__DOT__slotEpoch_64_1==0xffff,
          "both actual empty slot epochs must start at the finite boundary");
  t.allocate(1);
  for (unsigned n=0; n<4; ++n) {
    const uint64_t address=A+uint64_t(n)*0x4000;
    t.check(t.access(0,address,1)==0xa1,"finite epoch refill data differs");
    // A load may respond before its MSHR installs the reserved owner. Verify
    // the complete install/refill/terminal before admitting the next request.
    t.ticks(1000);
    t.check(root->HierarchyHarness__DOT__l1__DOT__slotEpoch_64_0!=0xffff ||
            root->HierarchyHarness__DOT__l1__DOT__slotEpoch_64_1!=0xffff,
            "boundary reservation did not commit a new owner");
    t.check(t.access(0,address,1)==0xa1,"committed boundary owner cannot be read");
  }
  t.check(root->HierarchyHarness__DOT__l1__DOT__slotEpoch_64_0!=0xffff &&
          root->HierarchyHarness__DOT__l1__DOT__slotEpoch_64_1!=0xffff,
          "both finite-label slots must complete replacement");
  std::puts("PALIMPSEST_SLOT_EPOCH_BOUNDARY=PASS");
  t.d.final();
  return 0;
}
