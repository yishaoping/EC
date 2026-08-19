
= Boom
包号没有循环利用好像？
== Core
val checker_segment_id  = Output(Vec(GH_GlobalParams.GH_NUM_CORES, UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W)))
val active_packet_seq   = Output(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
val packet_alloc_valid  = Output(Bool())
val packet_alloc_seq    = Output(UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))

io.active_packet_seq                           := ic_master.io.active_packet_seq  // 当前包号
io.packet_alloc_valid                         := ic_master.io.packet_alloc_valid  // 同周期有store
io.packet_alloc_seq                           := ic_master.io.packet_alloc_seq    // 有store新包号

core->lsu 
io.lsu.active_packet_seq                      := Mux(ic_master.io.packet_alloc_valid,
  ic_master.io.packet_alloc_seq,
  Mux(ic_master.io.debug_maincore_status === 2.U,
    ic_master.io.active_packet_seq, 0.U))
