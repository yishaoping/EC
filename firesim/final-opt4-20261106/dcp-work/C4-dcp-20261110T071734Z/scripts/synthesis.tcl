variable synth_run [get_runs synth_1]

reset_runs ${synth_run}
set_property STEPS.SYNTH_DESIGN.ARGS.DIRECTIVE RuntimeOptimized [get_runs -filter {IS_SYNTHESIS == 1}]
launch_runs ${synth_run} -jobs ${jobs}
wait_on_run ${synth_run}

if {[get_property PROGRESS ${synth_run}] != "100%"} {
    puts "ERROR: synthesis failed"
    exit 1
}
