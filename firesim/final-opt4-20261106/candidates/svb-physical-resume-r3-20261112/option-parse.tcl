puts "EC_OPTION_PARSE_BEGIN"
foreach cmd {{route_design -directive Explore -tns_cleanup} {route_design -preserve -directive Explore -tns_cleanup}} {
set rc [catch {eval $cmd} error]
puts "EC_OPTION_PARSE cmd=$cmd rc=$rc message=$error"
}
puts "EC_OPTION_PARSE_COMPLETE"
exit 0
