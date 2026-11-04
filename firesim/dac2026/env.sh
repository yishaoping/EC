#!/usr/bin/env bash
# Source only. No Nix refresh, conda solve, driver access or simulation.
if [ -n "${BASH_VERSION:-}" ]; then
    _dac_source="${BASH_SOURCE[0]}"
elif [ -n "${ZSH_VERSION:-}" ]; then
    _dac_source="${(%):-%N}"
else
    printf 'Source env.sh from bash or zsh.\n' >&2
    return 1
fi
_dac_here="$(cd -- "$(dirname -- "$_dac_source")" && pwd)"
export DAC_KIT="$_dac_here"
export DAC_ROOT="$(cd -- "$DAC_KIT/../.." && pwd)"
export DAC_TARGET_CONFIG="${DAC_TARGET_CONFIG:-C4}"
case "$DAC_TARGET_CONFIG" in
    B|C4) ;;
    *) printf 'Current build environments support B and C4 only.\n' >&2; return 1 ;;
esac
export DAC_INTEGRATION="${DAC_INTEGRATION:-opt4-alveo-v3}"
case "$DAC_INTEGRATION" in
    opt4-minimal-v2|opt4-alveo-v3) ;;
    *) printf 'Unknown DAC integration.\n' >&2; return 1 ;;
esac
export CHIPYARD_ROOT="$DAC_KIT/work/$DAC_INTEGRATION/$DAC_TARGET_CONFIG/chipyard"
export FIRESIM_ROOT="$CHIPYARD_ROOT/sims/firesim"
export DAC_MANAGER_ENV="$DAC_ROOT/firesim/envs/manager-1.17.1"
export FIREMARSHAL_ROOT="$CHIPYARD_ROOT/software/firemarshal"
export PATH="$DAC_MANAGER_ENV/bin:$DAC_MANAGER_ENV/riscv-tools/bin:$FIRESIM_ROOT/deploy:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/tools/Xilinx/Vivado/2021.1/bin"
export CONDA_PREFIX="$DAC_MANAGER_ENV"
export JAVA_HOME="$DAC_MANAGER_ENV/lib/jvm"
export RISCV="$DAC_MANAGER_ENV/riscv-tools"
unset FIRESIM_STANDALONE
export FIRESIM_ENV_SOURCED=1
# Normal Chipyard library integration, entirely inside the independent work copy.
export SBT_BIN="$DAC_MANAGER_ENV/bin/java -jar $DAC_MANAGER_ENV/bin/sbt-launch.jar"
export SBT_OPTS=""
export PYTHONPATH="$DAC_KIT${PYTHONPATH:+:$PYTHONPATH}"
export MAKEFLAGS="-j1"
export OMP_NUM_THREADS=2
export JAVA_TOOL_OPTIONS="-Xmx8G -XX:ActiveProcessorCount=2 -Dsbt.supershell=false"
unset _dac_here _dac_source
