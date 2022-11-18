#! /bin/bash

BUILD_DIR=/work/qemu_linux/linux-5.15.43

if [ ! -z $1 ]
then
	BUILD_DIR=$1
fi

export ARCH=arm64
export CROSS_COMPILE=/usr/bin/aarch64-linux-gnu-
cd $BUILD_DIR
make -j12
