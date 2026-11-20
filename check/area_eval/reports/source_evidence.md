# 关键源码证据索引

以下均为本次实际读取的文件及行号；论文文字另见evidence。

| Evidence | Source | Snippet |
|---|---|---|
| main config | [RocketConfigs.scala:9](/data1/gzh/EC/check/source/chipyard/generators/chipyard/src/main/scala/config/RocketConfigs.scala:9) | `class v1Config extends Config(` |
| BOOM mixin | [config-mixins.scala:177](/data1/gzh/EC/check/source/chipyard/generators/boom/src/main/scala/common/config-mixins.scala:177) | `class WithNLargeBooms(n: Int = 1, overrideIdOffset: Option[Int] = None) extends Config(` |
| ROB96 | [config-mixins.scala:189](/data1/gzh/EC/check/source/chipyard/generators/boom/src/main/scala/common/config-mixins.scala:189) | `numRobEntries = 96,` |
| ROB96 | [config-mixins.scala:399](/data1/gzh/EC/check/source/chipyard/generators/boom/src/main/scala/common/config-mixins.scala:399) | `numRobEntries = 96,               // CS152: Change me (2+)` |
| checker config | [Configs.scala:210](/data1/gzh/EC/check/source/chipyard/generators/rocket-chip/src/main/scala/subsystem/Configs.scala:210) | `class WithNGCCheckers(n: Int, overrideIdOffset: Option[Int] = None,crossing: RocketCrossingParams = RocketCrossingParams()) extends Config((site, here, up) => {` |
| LSL instantiation | [RocketCore.scala:817](/data1/gzh/EC/check/source/chipyard/generators/rocket-chip/src/main/scala/rocket/RocketCore.scala:817) | `val lsl = Module(new R_LSL(R_LSLParams(255, xLen)))` |
| main checkpoint instance | [core.scala:2018](/data1/gzh/EC/check/source/chipyard/generators/boom/src/main/scala/exu/core.scala:2018) | `val rsu_master = Module(new R_RSU(R_RSUParams(xLen, numARFS, 1)))` |
| original snapshot | [R_RSU.scala:61](/data1/gzh/EC/check/source/chipyard/generators/rocket-chip/src/main/scala/r/R_RSU.scala:61) | `val arfs_ss                                     = Reg(Vec(params.numARFS, UInt(params.xLen.W)))` |
| original context arrays | [R_RSUSL.scala:81](/data1/gzh/EC/check/source/chipyard/generators/rocket-chip/src/main/scala/r/R_RSUSL.scala:81) | `val arfs_ss                                     = SyncReadMem(params.numARFS+1, UInt(params.xLen.W))` |
| comparison | [R_RSUSL.scala:308](/data1/gzh/EC/check/source/chipyard/generators/rocket-chip/src/main/scala/r/R_RSUSL.scala:308) | `channel_enq_valid                              := do_check.asBool && (checking_counter =/= 0.U) && !if_check_completed.asBool && ((io.core_arfs_in(checking_counter_memdelay) =/= arf_data_ECP) //  (io.core_farfs_in(checking_counter_memdelay) =/= farf_data_ECP))` |
| CSR shadows | [CSR.scala:539](/data1/gzh/EC/check/source/chipyard/generators/rocket-chip/src/main/scala/rocket/CSR.scala:539) | `val reg_shadow = if(tileParams.hartId != 0) Some(Reg(Vec(CSRshadows.CSRsize, UInt(xLen.W)))) else None` |
| CSR payload definitions | [Instructions.scala:1567](/data1/gzh/EC/check/source/chipyard/generators/rocket-chip/src/main/scala/rocket/Instructions.scala:1567) | `object CSRshadows{` |
| LSL record width | [R_LSL.scala:63](/data1/gzh/EC/check/source/chipyard/generators/rocket-chip/src/main/scala/r/R_LSL.scala:63) | `val fifowidth               = 2*params.xLen + 2 // extra two bits added to indicate inst type` |
| LSL bank instance | [R_LSL.sv:409](/data1/gzh/EC/check/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/R_LSL.sv:409) | `GH_MemFIFO_1 u_channel_0 (	// @[R_LSL.scala:64:83]` |
| LSL bank instance | [R_LSL.sv:420](/data1/gzh/EC/check/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/R_LSL.sv:420) | `GH_MemFIFO_1 u_channel_1 (	// @[R_LSL.scala:64:83]` |
| LSL generated storage | [mem_combMem_0.sv:87](/data1/gzh/EC/check/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/mem_combMem_0.sv:87) | `reg [129:0] Memory[0:254];	// @[GH_FIFO.scala:140:46]` |
| L2 generated geometry | [chipyard.TestHarness.v1Config.dts:186](/data1/gzh/EC/check/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/chipyard.TestHarness.v1Config.dts:186) | `cache-size = <524288>;` |
| L2 generated MSHRs | [chipyard.TestHarness.v1Config.dts:192](/data1/gzh/EC/check/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/chipyard.TestHarness.v1Config.dts:192) | `sifive,mshr-count = <7>;` |
| L2 tag storage | [Directory.scala:27](/data1/gzh/EC/check/source/chipyard/generators/sifive-cache/design/craft/inclusivecache/src/Directory.scala:27) | `class DirectoryEntry(params: InclusiveCacheParameters) extends InclusiveCacheBundle(params)` |
| L2 tag RAM | [Directory.scala:65](/data1/gzh/EC/check/source/chipyard/generators/sifive-cache/design/craft/inclusivecache/src/Directory.scala:65) | `val cc_dir =  DescribedSRAM(` |
| zero sequence output | [R_IC.scala:117](/data1/gzh/EC/check/source/chipyard/generators/rocket-chip/src/main/scala/r/R_IC.scala:117) | `io.checker_segment_id(idx)                  := 0.U` |
| zero sequence output | [R_IC.scala:121](/data1/gzh/EC/check/source/chipyard/generators/rocket-chip/src/main/scala/r/R_IC.scala:121) | `io.checker_segment_id(i)                    := 0.U` |
| forwarding CDC | [GHM.scala:107](/data1/gzh/EC/check/source/chipyard/generators/rocket-chip/src/main/scala/guardiancouncil/GHM.scala:107) | `val u_data_cdc                                      = Seq.fill(params.number_of_little_cores) {Module(new AsyncQueue(UInt((params.width_GH_packet*GH_GlobalParams.GH_TOTAL_PACKETS).W), AsyncQueueParams(256,2)))}` |
