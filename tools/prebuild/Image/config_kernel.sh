#! /bin/bash

BUILD_DIR=../../../../kernel_for_study
if [ ! -z $1 ]
then
	BUILD_DIR=$1
fi

export ARCH=arm64
export CROSS_COMPILE=/usr/bin/aarch64-linux-gnu-
cd $BUILD_DIR
make menuconfig


