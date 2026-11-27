# Local environment for the official standalone FireSim checkout.
# Existing package prefix is retained because archived binaries refer to it.
source /home/guozh/miniconda3/etc/profile.d/conda.sh
conda activate /data1/gzh/EC/firesim/envs/manager-1.17.1
export FIRESIM_STANDALONE=1
export FIRESIM_ENV_SOURCED=1
export RISCV="$CONDA_PREFIX/riscv-tools"
export JAVA_HOME="$CONDA_PREFIX/lib/jvm"
export PATH="$CONDA_PREFIX/bin:$RISCV/bin:$JAVA_HOME/bin:$(pwd)/sw/firesim-software:$PATH"
unset CHIPYARD_ROOT FIRESIM_ROOT DAC_KIT DAC_ROOT DAC_INTEGRATION DAC_TARGET_CONFIG
export CPPFLAGS="${CPPFLAGS//-DNDEBUG/}"
unset SBT_BIN SBT_OPTS
