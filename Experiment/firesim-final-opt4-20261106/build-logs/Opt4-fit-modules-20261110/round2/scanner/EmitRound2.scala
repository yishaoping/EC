package opt4fit
object EmitRound2 extends App {(new chisel3.stage.ChiselStage).emitVerilog(new boom.lsu.SafePrefixScanner(256,32),Array("--target-dir",args(0)))}
