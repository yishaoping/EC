set_param general.maxThreads 2
open_checkpoint {/data1/gzh/EC/Experiment/firesim-final-opt4-20261106/cycleprecise-svb-host40-shell-recovery-r6-20261112/I-postroute-clock-skew/final.dcp}
set paths [get_timing_paths -delay_type max -slack_lesser_than 0 -max_paths 1]
if {[llength $paths]!=1} {error "expected remaining negative Setup path"}
set path [lindex $paths 0]
puts "EC_API_PATH_PROPERTIES [list_property $path]"
puts "EC_API_STARTPOINT [get_property STARTPOINT_PIN $path]"
puts "EC_API_ENDPOINT [get_property ENDPOINT_PIN $path]"
foreach name {TIMING_POINTS POINTS INPUT_PINS DATAPATH_PINS} {
  if {[lsearch -exact [list_property $path] $name]>=0} {
    set values [get_property $name $path]
    puts "EC_API_PROPERTY $name COUNT=[llength $values]"
    if {[llength $values]} {
      set item [lindex $values 0]
      puts "EC_API_FIRST_PROPERTIES [list_property $item]"
      if {[lsearch -exact [list_property $item] PIN]>=0} {puts "EC_API_FIRST_PIN [get_property PIN $item]"}
    }
  }
}
if {[catch {get_pins -quiet -of_objects $path} pins]} {puts "EC_API_PATH_PINS_ERROR $pins"} else {puts "EC_API_PATH_PINS_COUNT [llength $pins]"}
set end [get_pins -quiet [get_property ENDPOINT_PIN $path]]
set cone [all_fanin -to $end -flat -only_cells]
set srls [filter $cone {REF_NAME == SRL16E || REF_NAME == SRLC32E}]
puts "EC_API_FANIN_SRL_COUNT [llength $srls]"
foreach cell $srls {puts "EC_API_SRL [get_property NAME $cell]"}
puts "EC_API_PROBE_COMPLETE_NO_PHYSICAL_MUTATION"
exit 0
