package opt4fit
object EmitScanner extends App { (new chisel3.stage.ChiselStage).emitVerilog(new boom.lsu.SafePrefixScannerBaseline(256,32),Array("--target-dir",args(0))) }
