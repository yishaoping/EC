# Rocket's SynchronizerPrimitiveShiftReg explicitly reserves these primitive
# modules for backend CDC constraints. Preserve the existing register stages.
# Load as a synthesis constraint, before synth_design; applying it after SRL
# extraction cannot restore the synchronizer structure.
set ec_sync_flops [get_cells -hierarchical -regexp {.*output_chain.*/sync_[0-9]+_reg}]
if {[llength $ec_sync_flops] == 0} {
  error "No Rocket synchronizer flops matched; inspect the emitted hierarchy"
}
set_property ASYNC_REG TRUE $ec_sync_flops
set_property SHREG_EXTRACT NO $ec_sync_flops
puts "EC_SYNCHRONIZER_CONSTRAINTS count=[llength $ec_sync_flops]"
