set_param general.maxThreads 2
open_checkpoint {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-postroute-recovery-r1-20261111/round51-v1/spread-replicate/sealed-physopt.dcp}
source {/data1/gzh/EC/firesim/final-opt4-20261106/candidates/svb-activeidx-pinquery-r1-20261112/query.tcl}
set nets [original_activeidx_nets {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-activeidx-pinquery-r1-20261112/query.tsv}]
if {[llength $nets] != 2} {error "invalid query result"}
puts "EC_ACTIVEIDX_EXACT_PINQUERY_PASS nets=[llength $nets]"
exit 0
