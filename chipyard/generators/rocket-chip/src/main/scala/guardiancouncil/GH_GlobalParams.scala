package freechips.rocketchip.guardiancouncil

//修改GH_WIDITH_PACKETS会牵一发动全身
object GH_GlobalParams {
  val GH_NUM_CORES = 5;   // 1 BOOM core + 4 Rocket checker cores
  val GH_NUM_BIG_CORES = 1;
  val GH_DEBUG = 0;
  val GH_WIDITH_PERF = 64;
  val GH_TOTAL_PACKETS = 2;
  val GH_TOTAL_INSTS = 5000; // 论文 Table I：单个 log segment 最长 5000 条指令
  //一次128bit数据+8bit状态
  val GH_WIDITH_PACKETS = 2*GH_WIDITH_PERF+8;//136
  // Package sequence numbers are global within one BOOM/checker group. Zero is
  // reserved for operations that are not associated with a checked package.
  val GH_PACKET_SEQ_BITS = 32
  val GH_CHECKER_STATUS_BITS = 2
  val GH_CHECKER_STATUS_PASS = 0
  val GH_CHECKER_STATUS_FAIL = 1
  val GH_CHECKER_STATUS_CANCELLED = 2
  val GH_CHECKER_RESULT_BITS = GH_PACKET_SEQ_BITS + GH_CHECKER_STATUS_BITS + 1

  // Performance control keeps the legacy selector in bits 4:1 and adds
  // explicit measurement-window pulses above it.
  val GH_PERF_CTRL_BITS = 7
  val GH_PERF_CTRL_RESET_BIT = 0
  val GH_PERF_CTRL_START_BIT = 5
  val GH_PERF_CTRL_STOP_BIT = 6

  // Stable software-visible traffic counter vector. Existing indices 0..34
  // are retained; index 35 appends the number of dirty writebacks whose line
  // attribution requires package verification.
  val GH_TRAFFIC_COUNTERS = 36
  // Index 13 counts the first accepted beat of every L1->L2 C-channel
  // transaction (including clean releases and probe responses).
  val GH_TRAFFIC_L1_L2_C_TOTAL = 13
  // Source compatibility for code that still uses the old, narrower name.
  val GH_TRAFFIC_L1_L2_WB_TOTAL = GH_TRAFFIC_L1_L2_C_TOTAL
  val GH_TRAFFIC_L1_L2_WB_DIRTY = 14
  val GH_TRAFFIC_L2_DRAM_WB_TOTAL = 15
  val GH_TRAFFIC_L2_DRAM_WB_DIRTY = 16
  val GH_TRAFFIC_STORE_UNCACHE_CYCLE_SUM = 17
  val GH_TRAFFIC_UNVERIFIED_DIRTY_WB_SEEN = 18
  val GH_TRAFFIC_UNVERIFIED_DIRTY_WB_RESOLVED = 19
  val GH_TRAFFIC_UNVERIFIED_DIRTY_WB_PENDING = 20
  val GH_TRAFFIC_UNVERIFIED_DIRTY_WB_OTHER = 21
  val GH_TRAFFIC_UNVERIFIED_DIRTY_WB_DROPPED = GH_TRAFFIC_UNVERIFIED_DIRTY_WB_OTHER
  val GH_TRAFFIC_FAILED_PACKAGES = 22
  val GH_TRAFFIC_UNVERIFIED_DIRTY_WB_SAFE_CYCLE_SUM = 23
  val GH_TRAFFIC_UNVERIFIED_DIRTY_WB_CYCLE_SUM = 24
  val GH_TRAFFIC_UNVERIFIED_DIRTY_WB_STATS_VALID = 25
  val GH_TRAFFIC_SAFE_PACKET_WATERMARK = 26
  val GH_TRAFFIC_PACKAGE_RESULT_DROPPED = 27
  val GH_TRAFFIC_VERIFIED_DIRTY_WB = 28
  // Dirty writebacks without a valid verify_required attribution. This is a
  // non-verification diagnostic and is not part of the five verification
  // categories printed by software.
  val GH_TRAFFIC_NONVERIFY_DIRTY_WB = 29
  val GH_TRAFFIC_UNTRACKED_DIRTY_WB = GH_TRAFFIC_NONVERIFY_DIRTY_WB
  val GH_TRAFFIC_ALLOCATED_PACKAGES = 30
  val GH_TRAFFIC_COMPLETED_PACKAGES = 31
  val GH_TRAFFIC_PASSED_PACKAGES = 32
  val GH_TRAFFIC_CANCELLED_PACKAGES = 33
  val GH_TRAFFIC_STATS_ARITHMETIC_OVERFLOW = 34
  val GH_TRAFFIC_L1_L2_WB_DIRTY_VERIFY_REQUIRED = 35
  val GH_L2_WB_CLEAN_GRAY_BORE = "gh_l2_dram_wb_clean_gray"
  val GH_L2_WB_DIRTY_GRAY_BORE = "gh_l2_dram_wb_dirty_gray"
  val IF_THERE_IS_CDC = true;
  //===== Runtime Configurable Mapping =====//
  val GH_MAX_BIG_CORES = 2;   // 支持的大核数量
  val GH_CHECKER_MASK_WIDTH = 16; // checker_mask最大位宽
}
