#!/bin/sh
# Only the user invokes this guest entry. Reboot before each sample in v6.
set -eu
export OMP_NUM_THREADS=1 PARSEC_NUM_THREADS=1
cd /opt/ec-dac
case "${1:-}" in smoke|test|simsmall) mode=$1 ;; *) echo 'usage: manual-link.sh smoke|test|simsmall'; exit 2 ;; esac
test -c /dev/ec_dac_roi || { echo 'EC_OPT4_INVALID reason=missing_real_device'; exit 125; }
# All application files are SHA256-verified in the exact cpio by the host runner.
# The input and BUILD hashes below are still checked in the guest.
echo "8 4 1 7" > /proc/sys/kernel/printk
echo "EC_OPT4_INTEGRITY transport=immutable_initramfs host_verification=REQUIRED"
work=/tmp/ec-opt4-$mode-$$
/bin/busybox mkdir "$work"
/bin/busybox mkfifo "$work/pipe"
echo "EC_OPT4_LINUX_START mode=$mode application_hart=0 application_threads=1 one_roi_per_boot=true"
/bin/busybox sha256sum BUILD.json
/bin/busybox tee "$work/raw.log" <"$work/pipe" &
tee_pid=$!
set +e
if [ "$mode" = smoke ]; then
  ./roi-smoke >"$work/pipe" 2>&1
  rc=$?
else
  case "$mode" in test) input=inputs/test/in_4.txt ;; simsmall) input=inputs/simsmall/in_4K.txt ;; esac
  /bin/busybox sha256sum "$input"
  ./blackscholes 1 "$input" "$work/prices.txt" >"$work/pipe" 2>&1
  rc=$?
fi
wait "$tee_pid"
tee_rc=$?
set -e
echo "EC_OPT4_APPLICATION_EXIT code=$rc capture_exit=$tee_rc"
test "$rc" = 0 && test "$tee_rc" = 0 || exit 1
if [ "$mode" = smoke ]; then
  /bin/busybox grep -qx 'DAC_SMOKE checksum=500500 expected=500500' "$work/raw.log"
else
  /bin/busybox awk '
    function numeric(s) { return s ~ /^[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)([eE][+-]?[0-9]+)?$/ }
    NR==FNR {
      if(FNR==1) { if(NF!=1 || $1 !~ /^[0-9]+$/ || $1<1) bad=1; n=$1; next }
      if(NF!=9 || !numeric($9)) bad=1; ref[FNR-1]=$9+0; rows=FNR-1; next
    }
    FNR==1 { if(NF!=1 || $1 !~ /^[0-9]+$/ || $1!=n) bad=1; header=1; next }
    { i=FNR-1; values=i; if(NF!=1 || !numeric($1) || i>n) { bad=1; next }
      delta=($1+0)-ref[i]; if(delta<0)delta=-delta; if(!(delta<0.0001))bad=1 }
    END { if(!header || rows!=n || values!=n)bad=1
      if(bad) { print "BLACKSCHOLES_OUTPUT_INVALID"; exit 1 }
      print "BLACKSCHOLES_OUTPUT_VALID count=" n " absolute_tolerance=0.0001" }
  ' "$input" "$work/prices.txt"
  /bin/busybox cat "$work/prices.txt"
  /bin/busybox sha256sum "$work/prices.txt"
fi
echo "EC_OPT4_LINUX_END mode=$mode correctness=PASS application_exit=0 hardware_status_requires_host_verification=true"
