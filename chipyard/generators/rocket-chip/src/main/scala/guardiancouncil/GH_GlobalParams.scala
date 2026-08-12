package freechips.rocketchip.guardiancouncil

//修改GH_WIDITH_PACKETS会牵一发动全身
object GH_GlobalParams {
  val GH_NUM_CORES = 5;   // 1 BOOM core + 4 Rocket checker cores
  val GH_NUM_BIG_CORES = 1;
  val GH_DEBUG = 0;
  val GH_WIDITH_PERF = 64;
  val GH_TOTAL_PACKETS = 2;
  val GH_TOTAL_INSTS = 3970;
  //一次128bit数据+8bit状态
  val GH_WIDITH_PACKETS = 2*GH_WIDITH_PERF+8;//136
  // Stable software-visible traffic counter vector length. Keep existing
  // store/load/LR/SC/AMO indices 0..12, DCache writeback counters at 13..16,
  // and append the local store_uncache completion timestamp sum at index 17.
  val GH_TRAFFIC_COUNTERS = 18
  val GH_TRAFFIC_L1_L2_WB_TOTAL = 13
  val GH_TRAFFIC_L1_L2_WB_DIRTY = 14
  val GH_TRAFFIC_L2_DRAM_WB_TOTAL = 15
  val GH_TRAFFIC_L2_DRAM_WB_DIRTY = 16
  val GH_TRAFFIC_STORE_UNCACHE_CYCLE_SUM = 17
  val GH_L2_WB_CLEAN_GRAY_BORE = "gh_l2_dram_wb_clean_gray"
  val GH_L2_WB_DIRTY_GRAY_BORE = "gh_l2_dram_wb_dirty_gray"
  val IF_THERE_IS_CDC = true;
  //===== Runtime Configurable Mapping =====//
  val GH_MAX_BIG_CORES = 2;   // 支持的大核数量
  val GH_CHECKER_MASK_WIDTH = 16; // checker_mask最大位宽
}
