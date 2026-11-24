#define main hierarchy_regression_main
#include "../rollback/hierarchy_test.cpp"
#undef main
int main(int argc,char**argv) {
  Verilated::commandArgs(argc,argv);
  Test t;t.reset();
  t.check(t.d.io_epoch==0xffffffddU,"actual epoch reset seed absent");
  constexpr uint64_t retained=0x80003040ULL;
  t.allocate(1);t.access(1,retained,1,0xc001);t.access(1,B,1,0xd001);t.pass(1);
  t.allocate(2);t.access(1,B,2,0xe002);t.d.io_fail=2;t.step();t.d.io_fail=0;
  t.until([&]{return t.d.io_epoch==0xffffffdeU;},"near-limit rollback did not increment label");
  t.check(t.line(retained)[0]==0xa1,"retained dirty owner was published prematurely");
  t.until([&]{return bool(t.d.io_maintenanceRequest);},"near-limit labels did not request physical maintenance");
  t.holdMemory=true;
  t.until([&]{return t.d.io_mv&&t.d.io_mo==0;},"no real maintenance data write",400000);
  t.ticks(40);t.check(t.d.io_epoch==0xffffffdeU&&!t.restarted&&!t.d.io_maintenanceAck,
    "near-limit label compacted before physical write");
  t.holdWriteAck=true;t.holdMemory=false;
  t.until([&]{return !t.replies.empty()&&t.replies.front().opcode==0;},"no real maintenance ACK",400000);
  t.ticks(40);t.check(t.d.io_epoch==0xffffffdeU&&!t.d.io_maintenanceAck&&!t.restarted,
    "near-limit label compacted before matching memory ACK");
  t.holdWriteAck=false;
  t.until([&]{return t.d.io_epoch==0;},"physical certificate did not reset finite labels",400000);
  t.resume(2,0);
  t.check(t.line(retained)[0]==0xc001&&t.line(B)[0]==0xd001,"maintenance lost safe bytes or published dead data");
  t.allocate(3);t.check(t.access(0,B,3)==0xd001,"post-maintenance lookup revived dead suffix");
  t.allocate(4);t.access(1,B,4,0xe004);t.d.io_fail=4;t.step();t.d.io_fail=0;t.resume(4,1);
  t.allocate(5);t.check(t.access(0,B,5)==0xd001,"new-generation rollback corrupted surviving line");
  t.ticks(1000);
  t.check(t.access(0,B,5)==0xd001,"final post-maintenance installation did not complete");
  std::puts("PALIMPSEST_GENERATION_BOUNDARY=PASS real_physical_certificate=1");
  t.d.final();return 0;
}
