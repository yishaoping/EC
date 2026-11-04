#!/bin/sh
# Guest-only prerequisite test. User invokes after boot; no automatic startup.
# This produces no formal completion marker and is not the host collector.
set -eu
export OMP_NUM_THREADS=1
export PARSEC_NUM_THREADS=1
cd /opt/ec-dac
case "${1:-}" in
  smoke|test|simsmall) mode=$1 ;;
  *) echo 'usage: /opt/ec-dac/manual-link.sh smoke|test|simsmall' >&2; exit 2 ;;
esac
if [ ! -c /dev/ec_dac_roi ]; then
  echo 'ROI device missing: matching target controller and B driver must bind first' >&2
  exit 125
fi
/bin/busybox sha256sum -c SHA256SUMS
work=/tmp/ec-dac-link-$mode-$$
/bin/busybox mkdir "$work"
echo "EC_DAC_PREREQUISITE_START mode=$mode formal_sample=false work=$work"
if [ "$mode" = smoke ]; then
  ./roi-smoke >"$work/stdout" 2>"$work/stderr"
  /bin/busybox cat "$work/stdout" "$work/stderr"
  /bin/busybox grep -qx 'DAC_SMOKE checksum=500500 expected=500500' "$work/stdout"
else
  case "$mode" in
    test) input=inputs/test/in_4.txt ;;
    simsmall) input=inputs/simsmall/in_4K.txt ;;
  esac
  ./blackscholes 1 "$input" "$work/prices.txt" >"$work/stdout" 2>"$work/stderr"
  /bin/busybox cat "$work/stdout" "$work/stderr"
  # Same column9 reference and strict 1e-4 absolute bound as pthread ERR_CHK.
  # Reject malformed headers, non-numeric/NaN/Inf, missing/extra output values.
  /bin/busybox awk '
    function numeric(s) { return s ~ /^[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)([eE][+-]?[0-9]+)?$/ }
    NR==FNR {
      if (FNR==1) { if (NF!=1 || $1 !~ /^[0-9]+$/ || $1<1) bad=1; n=$1; next }
      if (NF!=9 || !numeric($9)) bad=1
      ref[FNR-1]=$9+0; rows=FNR-1; next
    }
    FNR==1 { if (NF!=1 || $1 !~ /^[0-9]+$/ || $1!=n) bad=1; header=1; next }
    {
      i=FNR-1; values=i
      if (NF!=1 || !numeric($1) || i>n) { bad=1; next }
      delta=($1+0)-ref[i]; if (delta<0) delta=-delta
      if (!(delta<0.0001)) bad=1
    }
    END {
      if (!header || rows!=n || values!=n) bad=1
      if (bad) { print "BLACKSCHOLES_OUTPUT_INVALID"; exit 1 }
      print "BLACKSCHOLES_OUTPUT_VALID count=" n " absolute_tolerance=0.0001"
    }
  ' "$input" "$work/prices.txt"
  /bin/busybox sha256sum "$work/prices.txt"
fi
echo "EC_DAC_PREREQUISITE_END mode=$mode output_valid=true formal_sample=false"
