#!/usr/bin/env bash

set -e

# this should be run from chipyard repo top
RDIR=$(cd -- "$(dirname -- "$(readlink -f -- "${BASH_SOURCE[0]}")")/.." && pwd)

if [ ! -f "$RDIR/.gitmodules" ]; then
    echo "These dependency sources are tracked by EC; no nested submodule setup is needed."
    exit 0
fi

rm -rf $RDIR/toolchains/libgloss/build.log
rm -rf $RDIR/toolchains/riscv-tools/riscv-isa-sim/build.log
rm -rf $RDIR/toolchains/riscv-tools/riscv-pk/build.log
rm -rf $RDIR/toolchains/riscv-tools/riscv-tests/build.log
rm -rf $RDIR/toolchains/esp-tools/riscv-isa-sim/build.log
rm -rf $RDIR/toolchains/esp-tools/riscv-pk/build.log
rm -rf $RDIR/toolchains/esp-tools/riscv-tests/build.log
(
    pushd $RDIR/generators/constellation
    if [ -d espresso ]
    then
	git submodule deinit -f espresso
    fi
    popd
)
(
    pushd $RDIR/tools/cde
    git config --local status.showUntrackedFiles no
    popd
)
(
    if [ -d $RDIR/generators/cva6/src/main/resources/cva6/vsrc ]
    then
        pushd $RDIR/generators/cva6/src/main/resources/cva6/vsrc
        if [ -d cva6 ]
        then
	    git submodule deinit -f cva6
        fi
        popd
    fi
)
