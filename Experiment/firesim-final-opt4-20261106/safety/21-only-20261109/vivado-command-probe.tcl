open_hw_manager
set rc [catch {get_hw_devices -of_objects fixture} detail]
puts "EC_COMMAND_PROBE rc=$rc detail=$detail"
close_hw_manager
exit
