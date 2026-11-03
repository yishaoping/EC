module EpochCone(input clock,
input reset,
input  cut0,
input  cut1,
input  cut2,
input  cut3,
input  cut4,
input  cut5,
input  cut6,
input  cut7,
input  cut8,
input  cut9,
input  cut10,
input  cut11,
input  cut12,
input  cut13,
input [2:0] cut14,
input  cut15,
input  cut16,
input  cut17,
input  cut18,
input  cut19,
input  cut20,
input  cut21,
input  cut22,
input  cut23,
input  cut24,
input  cut25,
input  cut26,
input  cut27,
input  cut28,
input  cut29,
output wire svbEpochBoundary,
output wire svbEpochWriteBarrier,
output wire svbHeldWriteNeedsLease,
output wire svbFlush,
output wire debug_l1_cross_package_blocked,
output wire svbCaptureDiscard,
output wire s2_write_grant,
output reg svbFlushPending,
output reg svbResetPending);
wire  _cacheObservationEvents_flags_T_25 = cut0;
wire  _cacheObservationEvents_flags_T_26 = cut1;
wire  _cacheObservationEvents_flags_T_28 = cut2;
wire  _cacheObservationEvents_flags_T_30 = cut3;
wire  _cacheObservationEvents_flags_T_31 = cut4;
wire  _cacheObservationEvents_flags_T_32 = cut5;
wire  _cacheObservationEvents_flags_T_33 = cut6;
wire  _cacheObservationEvents_flags_T_37 = cut7;
wire  _cacheObservationEvents_flags_T_38 = cut8;
wire  _cacheObservationEvents_flags_T_39 = cut9;
wire  _cacheObservationEvents_flags_T_40 = cut10;
wire  _cacheObservationEvents_flags_T_41 = cut11;
wire  _s2_write_grant_T = cut12;
wire  debug_s2_nack_0 = cut13;
wire [2:0] debug_s2_type = cut14;
wire  debug_s3_valid = cut15;
wire  io__lsu_exception = cut16;
wire  io__traffic_reset = cut17;
wire  s2_replay_owner_match = cut18;
wire  s3_applied = cut19;
wire  s3_cancelled = cut20;
wire  s3_duplicate_effect = cut21;
wire  s3_l1PreservationAllowed = cut22;
wire  s3_pre_effect_kill = cut23;
wire  s3_svbOwnsPredecessor = cut24;
wire  slowdown_domain_wait = cut25;
wire  slowdown_pending_line = cut26;
wire  svbCaptureCancelled = cut27;
wire  svbCapturePending = cut28;
wire  svbFastLineValid = cut29;
assign svbEpochBoundary = io__traffic_reset | io__lsu_exception | svbFlushPending;
assign svbEpochWriteBarrier = svbEpochBoundary & (svbFastLineValid | svbCapturePending | svbFlushPending);
assign svbHeldWriteNeedsLease = debug_s3_valid & ~s3_applied & ~s3_duplicate_effect & ~s3_cancelled & ~s3_pre_effect_kill & s3_svbOwnsPredecessor & ~s3_l1PreservationAllowed;
assign svbFlush = svbEpochBoundary & ~svbHeldWriteNeedsLease;
assign debug_l1_cross_package_blocked = slowdown_domain_wait | slowdown_pending_line | svbEpochWriteBarrier;
assign svbCaptureDiscard = svbCaptureCancelled | svbEpochBoundary;
assign s2_write_grant = _s2_write_grant_T & (_cacheObservationEvents_flags_T_25 | _cacheObservationEvents_flags_T_26 | _cacheObservationEvents_flags_T_28 | _cacheObservationEvents_flags_T_30 | _cacheObservationEvents_flags_T_31 | _cacheObservationEvents_flags_T_32 | _cacheObservationEvents_flags_T_33 | _cacheObservationEvents_flags_T_37 | _cacheObservationEvents_flags_T_38 | _cacheObservationEvents_flags_T_39 | _cacheObservationEvents_flags_T_40 | _cacheObservationEvents_flags_T_41) & ~debug_s2_nack_0 & ~debug_l1_cross_package_blocked & ~debug_s3_valid & ((|debug_s2_type) | s2_replay_owner_match);
always @(posedge clock) begin
if(reset) begin
svbFlushPending <= 1'h0;
svbResetPending <= 1'h0;
end else begin
svbFlushPending <= svbEpochBoundary & ~svbFlush;
svbResetPending <= ~svbFlush & (io__traffic_reset | svbResetPending);
end
end
endmodule
