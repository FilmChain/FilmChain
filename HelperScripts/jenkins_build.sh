#!/bin/bash -xe
cd $WORKSPACE/mccshares
git submodule init
git submodule update
mkdir $WORKSPACE/build
cd $WORKSPACE/build
export BITSHARES_ROOT=$WORKSPACE
. ../mccshares/setenv.sh
cmake -DINCLUDE_QT_WALLET=TRUE -DCMAKE_TOOLCHAIN_FILE=$WORKSPACE/toolchain.invictus/toolchain.invictus.cmake ../mccshares
make -j8 VERBOSE=1
