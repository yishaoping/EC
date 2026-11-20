set_param general.maxThreads 2
open_checkpoint {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/round51-v1/spread-replicate/sealed-physopt.dcp}
set old [get_nets -hier -quiet -filter {NAME =~ *SVBProbe_/dut/activeIdx_reg*}]
puts "EC_OLD_NET_QUERY_COUNT [llength $old]"
foreach n $old {puts "EC_OLD_NET $n"}
set all [get_nets -hier -quiet -filter {NAME =~ *activeIdx*}]
puts "EC_BROAD_ACTIVEIDX_NET_COUNT [llength $all]"
foreach n $all {
 set loads [get_pins -leaf -of_objects $n -filter {DIRECTION == IN}]
 set drivers [get_pins -leaf -of_objects $n -filter {DIRECTION == OUT}]
 puts "EC_ACTIVEIDX_NET name=$n fanout=[llength $loads] drivers=$drivers"
}
set cells [get_cells -hier -quiet -filter {NAME =~ *activeIdx*}]
puts "EC_ACTIVEIDX_CELL_COUNT [llength $cells]"
foreach c $cells {puts "EC_ACTIVEIDX_CELL name=$c ref=[get_property REF_NAME $c]"}
puts "EC_ACTIVEIDX_READONLY_PROBE_COMPLETE"
exit 0
