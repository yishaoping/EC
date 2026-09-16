package boom.lsu

import chisel3._
import freechips.rocketchip.guardiancouncil.GH_GlobalParams

/**
  * L1 -> L2 脏写回（dirty writeback）统计中，用于跟踪「每个校验包（package）」
  * 验证状态的位图。
  *
  * 背景：
  *   DCache 每分配一个校验包（packet）就会拿到一个递增的包序号（`seq`，
  *   位宽 `GH_GlobalParams.GH_PACKET_SEQ_BITS`，当前为 32 位）。该包存续期间产生的
  *   脏行写回都要计入统计，直到 Guardian Council 的 checker 返回该包的校验结果
  *   （PASS / FAIL / CANCELLED）。本 Bundle 就是在硬件中并行跟踪「最近 window 个包」
  *   的三件事：是否已分配（`allocated`）、是否已收到结果（`completed`）、
  *   结果是否为 PASS（`passed`）。
  *
  * 为什么还需要 `seq` 向量：
  *   一个包只占用「槽位下标 = 包序号低位」这一个槽位（环形复用）。当序号回绕、
  *   或同一个测量窗口内新包覆盖了旧槽位时，单看下标无法判断「这个槽位现在属于谁」。
  *   `seq` 保存该槽位当前所属包的**完整**序号，因此所有读操作都必须同时满足
  *   `seq(idx) === 完整包序号` 才算命中；比较时不能只用槽位下标。
  *
  * 一个槽位的典型生命周期（见 `dcache.scala` 中 `bitmapState` 的使用处）：
  *   1) 新包分配（`measuredPacketAlloc`）：`allocated(idx) := true`，
  *      `completed(idx)/passed(idx) := false`，`seq(idx) := 新包完整序号`；
  *      若该槽位仍被一个尚未回收的包占用，则判定为分配冲突（allocationCollision）。
  *   2) checker 返回被接受的结果（有效、非 stale、status 已知、序号匹配）：
  *      `completed(idx) := true`，`passed(idx) := (status === PASS)`。
  *   3) 该包序号被连续的 safe watermark 覆盖后（即它及其之前的所有包都 PASS 了）：
  *      `allocated/completed/passed` 一并清零，槽位归还给环形缓冲复用。
  *      注意 `seq` 此时**不**清零，它对外的有效性完全由 `allocated` 门控。
  *
  * @param window 位图的槽位数量，同时也是被跟踪的测量窗口大小（DCache 中为 256）。
  *               由于包序号靠低位映射到槽位，实际使用中需保证 window <= 2^GH_PACKET_SEQ_BITS，
  *               否则不同序号会无法唯一映射到槽位。
  */
class DirtyWritebackBitmap(val window: Int) extends Bundle {
  require(window > 0)

  /** 分配标志位图，长度 = `window`。
    *
    * `allocated(i) == true` 表示槽位 i 当前被一个「正在被统计」的包占用：该包的
    * 序号低位等于 i，且它已经产生过包分配事件（仅在 `trafficCounting` 有效期内统计，
    * 即测量窗口内）。
    *
    * 它是槽位被占用的标志，也是同一槽位上 `seq` / `completed` / `passed` 三个向量
    * 取值可信的前提；槽位回收时与 `completed` / `passed` 一起清零。
    */
  val allocated = Vec(window, Bool())

  /** 结果到达标志位图，长度 = `window`。
    *
    * `completed(i) == true` 表示槽位 i 所属的包已经收到一个「被接受」的 checker 结果。
    * 注意：它只代表结果已到达，不代表校验通过 —— FAIL / CANCELLED 同样会置位，
    * 具体结论由 `passed` 区分。
    *
    * 单个槽位只会被置位一次：同一包重复到达且内容完全一致的结果会被识别为
    * held duplicate（生产方重发、本地尚未释放），不会重复置位；序号更旧、已经落在
    * 冻结测量窗口之外的迟到结果会被判定为 stale，同样不置位。
    */
  val completed = Vec(window, Bool())

  /** 通过标志位图，长度 = `window`。
    *
    * `passed(i) == true` 表示槽位 i 所属的包收到的被接受结果是 PASS
    * （`status === GH_CHECKER_STATUS_PASS`）。
    *
    * 仅在 `completed(i)` 为真时有意义；新包分配到该槽位时会先清零。
    * 安全水位（safe watermark）的推进要求 `allocated && seq 序号匹配 &&
    * completed && passed` 四项同时成立，也就是说只有「确实通过校验」的包才能让
    * 连续水位前移。
    */
  val passed = Vec(window, Bool())

  /** 槽位归属的完整包序号向量，每个元素宽 `GH_GlobalParams.GH_PACKET_SEQ_BITS` 位。
    *
    * `seq(i)` 记录槽位 i 当前所属包的**完整**序号，用于消除槽位环形复用造成的歧义：
    *   - 读：先用 `idx = 包序号低位` 算出槽位，再校验 `seq(idx) === 完整包序号`；
    *   - 写：新包分配时写入其完整序号；槽位回收时不清零，有效性由 `allocated` 决定，
    *     因此残留的旧值不会造成误命中。
    */
  val seq = Vec(window, UInt(GH_GlobalParams.GH_PACKET_SEQ_BITS.W))
}
