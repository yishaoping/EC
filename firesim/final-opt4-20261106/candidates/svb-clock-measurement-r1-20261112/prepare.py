#!/usr/bin/python3
"""Versioned software instrumentation; reuses existing target/model/guard objects."""
from pathlib import Path
import difflib, hashlib, json, subprocess

C = Path(__file__).resolve().parent
OLD = C.parent/'full-svb-gg-stream-replay-r2-20261111'
D = Path('/data1/gzh/EC/Experiment/firesim-final-opt4-20261106')
L = D/'svb-clock-measurement-build-r1-20261112'
L.mkdir(exist_ok=True)
def sha(p): return hashlib.sha256(Path(p).read_bytes()).hexdigest()
s = (OLD/'StreamingReplay.cc').read_text()
original = s
def replace(a,b):
    global s
    assert s.count(a)==1, a
    s=s.replace(a,b)
replace('#include "TestHarness.h"', '#include "TestHarness.h"\n#include "bridges/clock.h"\n#include <iomanip>')
replace(' std::string trace,status_path;', ''' std::string clock_path;
 FILE* event_file=nullptr;
 uint64_t event_rows=0;
 static uint64_t wall_ns(){return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();}
 std::string trace,status_path;''')
replace('  if(trace.empty())throw', '''  for(const auto&s:a)if(s.starts_with("+svb-clock-events="))clock_path=s.substr(std::string("+svb-clock-events=").size());
  if(trace.empty())throw''')
replace('  Row row{};bool known_reset=false;', '''  Row row{};bool known_reset=false;
  if(!clock_path.empty()){
   event_file=fopen(clock_path.c_str(),"wx");if(!event_file)throw std::runtime_error("exclusive clock CSV open failed");
   fprintf(event_file,"source_tick,boom_csr_cycle,capture,promotion,ack,occupancy,empty_observed,fpga_hcycle_before,fpga_hcycle_after,steady_ns_before,steady_ns_after,capture_key_valid,capture_writer,capture_generation,capture_sequence,promotion_entry,promotion_key_valid,promotion_writer,promotion_generation,promotion_sequence,ack_entry,ack_key_valid,ack_writer,ack_generation,ack_sequence\\n");
  }
  const auto loop_wall_before=wall_ns();
  const auto loop_hcycle_begin=get_bridge<clockmodule_t>().hcycle();
  const auto loop_wall_after=wall_ns();''')
replace('   previous=row;step(1);stable();if(row[7]){known_reset=true;++resets;}++rows;', '''   // Existing target pokes, comparisons, step(1), reset, and event accounting are unchanged.
   // A target handshake commits during blocking step. Counter samples bracket it.
   const bool cap=known_reset&&row[9]&&row[8], pro=known_reset&&row[42]&&row[41], ack=known_reset&&row[100];
   const bool empty=known_reset&&rows&&previous[99]&&!row[99];
   const bool stamp=event_file&&(cap||pro||ack||empty||!rows);
   uint64_t wb=0,hb=0,ha=0,wa=0;
   if(stamp){wb=wall_ns();hb=get_bridge<clockmodule_t>().hcycle();}
   previous=row;step(1);stable();
   if(stamp){
    ha=get_bridge<clockmodule_t>().hcycle();wa=wall_ns();
    fprintf(event_file,"%llu,%llu,%u,%u,%u,%u,%u,%llu,%llu,%llu,%llu,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u,%u\\n",
     (unsigned long long)tick,(unsigned long long)number(row,2,2),cap,pro,ack,row[99],empty,
     (unsigned long long)hb,(unsigned long long)ha,(unsigned long long)wb,(unsigned long long)wa,
     row[12],row[13],row[14],row[15],row[67],row[45],row[46],row[47],row[48],row[94],row[95],row[96],row[97],row[98]);
    ++event_rows;
   }
   if(row[7]){known_reset=true;++resets;}++rows;''')
replace('  if(!known_reset)throw', '''  const auto end_wall_before=wall_ns();
  const auto loop_hcycle_end=get_bridge<clockmodule_t>().hcycle();
  const auto end_wall_after=wall_ns();
  if(event_file){if(fflush(event_file)||fsync(fileno(event_file))||fclose(event_file))throw std::runtime_error("clock CSV flush failed");event_file=nullptr;}
  std::cout<<std::setprecision(17)<<"SVB_CLOCK_SUMMARY fpga_hcycle_begin="<<loop_hcycle_begin<<" fpga_hcycle_end="<<loop_hcycle_end<<" fpga_hcycle_elapsed="<<(loop_hcycle_end-loop_hcycle_begin)<<" steady_begin_before_ns="<<loop_wall_before<<" steady_begin_after_ns="<<loop_wall_after<<" steady_end_before_ns="<<end_wall_before<<" steady_end_after_ns="<<end_wall_after<<" event_rows="<<event_rows<<"\\n";
  if(!known_reset)throw''')
assert not (C/'StreamingReplay.cc').exists(), 'preserve any existing version'
(C/'StreamingReplay.cc').write_text(s)
(C/'instrumentation.diff').write_text(''.join(difflib.unified_diff(original.splitlines(True),s.splitlines(True),fromfile=str(OLD/'StreamingReplay.cc'),tofile=str(C/'StreamingReplay.cc'))))
plan=json.loads((OLD/'plan.json').read_text())
for k in ['compile','cpu_link','hardware_link']:
    plan[k]=[v.replace(str(OLD),str(C)) for v in plan[k]]
plan.update(schema='ec-svb-clock-measurement-plan/1',target_or_model_modified=False,bitstream_rebuild_required=False,
            parent_plan_sha256=sha(OLD/'plan.json'),parent_driver_sha256=sha(OLD/'StreamingReplay.cc'),
            instrumentation='Read existing ClockBridge hcycle around selected blocking steps. CSV intervals include MMIO and host stalls. Target edge, inputs, comparisons and resets unchanged.')
plan['inputs'].pop(str(OLD/'StreamingReplay.cc'))
plan['inputs'][str(C/'StreamingReplay.cc')]=sha(C/'StreamingReplay.cc')
(C/'plan.json').write_text(json.dumps(plan,indent=2,sort_keys=True)+'\n')
result={}
for k in ['compile','cpu_link','hardware_link']:
    with (L/(k+'.log')).open('xb') as f:
        p=subprocess.run(plan[k],stdout=f,stderr=subprocess.STDOUT)
    result[k]={'returncode':p.returncode,'log':str(L/(k+'.log'))}
    (L/'build.json').write_text(json.dumps(result,indent=2)+'\n')
    assert p.returncode==0, k
print(json.dumps(result,indent=2))
