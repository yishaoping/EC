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
  val IF_THERE_IS_CDC = true;
  //===== Runtime Configurable Mapping =====//
  val GH_MAX_BIG_CORES = 2;   // 支持的大核数量
  val GH_CHECKER_MASK_WIDTH = 16; // checker_mask最大位宽
}
