# Reopen the same project after a host interruption; preserve complete IP runs.
set root_dir [file normalize [lindex $argv 0]]
set mode [lindex $argv 1]
set jobs 2
set_param general.maxThreads 2
open_project ${root_dir}/vivado_proj/firesim.xpr
set complete_runs [list]
set incomplete_runs [list]
foreach run [get_runs -filter {IS_SYNTHESIS == 1}] {
    set name [get_property NAME $run]
    set progress [get_property PROGRESS $run]
    set refresh [get_property NEEDS_REFRESH $run]
    puts "EC_CAD_RESUME_RUN name=$name progress=$progress refresh=$refresh status=[get_property STATUS $run]"
    if {$progress == "100%" && !$refresh} {
        lappend complete_runs $name
    } else {
        lappend incomplete_runs $name
    }
}
if {$mode == "inspect"} { close_project; exit 0 }
if {$mode != "resume"} { error "unknown resume mode" }
foreach name $incomplete_runs {
    # Reset only incomplete synthesis, never all IP runs or the project.
    reset_runs [get_runs $name]
}
foreach name $complete_runs {
    if {[get_property PROGRESS [get_runs $name]] != "100%" || [get_property NEEDS_REFRESH [get_runs $name]]} {
        error "completed run invalidated by resume: $name"
    }
    puts "EC_CAD_RESUME_REUSED $name"
}
set synth_run [get_runs synth_1]
if {[get_property PROGRESS $synth_run] != "100%"} {
    # Generate every script before execution. The previous asynchronous job
    # launcher aborted while resolving runme.sh and left wait_on_run blocked.
    # Execute the generated scripts synchronously, preserving all synthesis
    # options and the completed sibling IP DCPs.
    launch_runs $synth_run -scripts_only
    set execute_runs [list]
    foreach name $incomplete_runs {
        if {$name != "synth_1"} { lappend execute_runs $name }
    }
    lappend execute_runs synth_1
    foreach name $execute_runs {
        set directory [get_property DIRECTORY [get_runs $name]]
        set script ${directory}/runme.sh
        if {![file isfile $script]} { error "missing generated run script: $script" }
        puts "EC_CAD_RESUME_EXECUTING $name $script"
        flush stdout
        exec /bin/sh $script >@ stdout 2>@ stderr
        if {![file exists ${directory}/.vivado.end.rst]} {
            error "run exited without completion marker: $name"
        }
    }
    wait_on_run $synth_run
}
if {[get_property PROGRESS $synth_run] != "100%"} { error "resumed synthesis failed" }
# The saved implementation script retains timing closure and bitstream gates.
source ${root_dir}/scripts/implementation_2021.1.tcl
close_project
exit 0
