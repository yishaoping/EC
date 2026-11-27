# Adapted from https://github.com/Xilinx/open-nic-shell

# Directory variables
set script_path [file normalize [info script]]
set script_dir [file dirname $script_path]
set root_dir [file dirname $script_dir]

# Loading options
#   bitstream_path   Path to the bitstream
#   serial           Serial number of FPGA board (without trailing A)
array set options {
    -bitstream_path ""
    -probes_path    ""
    -serial         ""
}

# Expect arguments in the form of `-argument value`
for {set i 0} {$i < $argc} {incr i 2} {
    set arg [lindex $argv $i]
    set val [lindex $argv [expr $i+1]]
    if {[info exists options($arg)]} {
        set options($arg) $val
        puts "Set option $arg to $val"
    } else {
        puts "Skip unknown argument $arg and its value $val"
    }
}

# Settings based on defaults or passed in values
foreach {key value} [array get options] {
    set [string range $key 1 end] $value
}

if {$serial ne "Xilinx/21770433G02LA"} {
    puts stderr "EC_FATAL_21_ONLY: protected e2 target"
    exit 2
}

puts "Program file: $options(-bitstream_path)"
puts "Probes file: $options(-probes_path)"
puts "Serial Number: $options(-serial)"

set_param labtools.enable_cs_server false

open_hw_manager
connect_hw_server -url localhost:3122 -allow_non_jtag

# by default vivado opens a default hw target
if {[llength [current_hw_target -quiet]]} { close_hw_target }

# check if serial is in hw targets
set final_hw_target ""
foreach {hw_target} [get_hw_targets] {
    if {[lindex [split $hw_target /] end] eq "21770433G02LA"} {
        if {$final_hw_target ne ""} { puts stderr "EC_FATAL_21_ONLY: ambiguous JTAG serial"; exit 2 }
        set final_hw_target $hw_target
    }
}

if {$final_hw_target == ""} {
    puts "Unable to find $serial in available HW targets. See available HW targets below:"
    get_hw_targets
    exit 1
}

puts "Programming $final_hw_target with ${options(-bitstream_path)}"
open_hw_target $final_hw_target
set target_devices [get_hw_devices]
if {[llength $target_devices] != 1} { puts stderr "EC_FATAL_21_ONLY: unexpected JTAG chain"; exit 2 }
current_hw_device [lindex $target_devices 0]
set_property PROBES.FILE ${options(-probes_path)} $target_devices
set_property FULL_PROBES.FILE ${options(-probes_path)} $target_devices
set_property PROGRAM.FILE ${options(-bitstream_path)} $target_devices
program_hw_devices $target_devices
refresh_hw_device $target_devices
puts "EC_FPGA_PROGRAMMED serial=$serial file=$options(-bitstream_path) device=$target_devices"
close_hw_target
close_hw_manager

exit
