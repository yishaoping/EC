#ifndef CHIPYARD_STAGE1_EXIT_H
#define CHIPYARD_STAGE1_EXIT_H

// Observation only. Stop on host success AND real L1/LSU quiescence; the
// original maximum-cycle bound still detects a drain that never completes.
template <typename Harness>
bool stage1_l1_drained(const Harness& t) {
  if (t.io_stage1_schema != 1 || t.io_stage1_cache_4 != 1) return false;
#define STAGE1_CACHE_IDLE(N) if (t.io_stage1_cache_##N) return false;
  STAGE1_CACHE_IDLE(1) STAGE1_CACHE_IDLE(2) STAGE1_CACHE_IDLE(3)
  STAGE1_CACHE_IDLE(5) STAGE1_CACHE_IDLE(6) STAGE1_CACHE_IDLE(7)
  STAGE1_CACHE_IDLE(8) STAGE1_CACHE_IDLE(9) STAGE1_CACHE_IDLE(10)
  STAGE1_CACHE_IDLE(11) STAGE1_CACHE_IDLE(12) STAGE1_CACHE_IDLE(13)
  STAGE1_CACHE_IDLE(14) STAGE1_CACHE_IDLE(15) STAGE1_CACHE_IDLE(16)
  STAGE1_CACHE_IDLE(17) STAGE1_CACHE_IDLE(18) STAGE1_CACHE_IDLE(19)
  STAGE1_CACHE_IDLE(20) STAGE1_CACHE_IDLE(21) STAGE1_CACHE_IDLE(22)
  STAGE1_CACHE_IDLE(23)
#undef STAGE1_CACHE_IDLE
  // Index 27 is parked prefetch ownership; 24..26 are invalid payload IDs.
#define STAGE1_LSU_IDLE(N) if (t.io_stage1_lsu_##N) return false;
  STAGE1_LSU_IDLE(0) STAGE1_LSU_IDLE(1) STAGE1_LSU_IDLE(2)
  STAGE1_LSU_IDLE(3) STAGE1_LSU_IDLE(4) STAGE1_LSU_IDLE(5)
  STAGE1_LSU_IDLE(6) STAGE1_LSU_IDLE(7) STAGE1_LSU_IDLE(8)
#undef STAGE1_LSU_IDLE
  return true;
}
#endif
