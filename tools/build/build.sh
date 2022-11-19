#! /bin/bash

rm -rf ./out/platfrom1/ramdisk/*
rm -rf ./out/platfrom1/dtb/*
rm -rf ./out/platfrom1/image/*

cd ../prebuild/Image

./config_kernel.sh
./build_kernel.sh
./copy_image.sh

cd ../rootfs
./mk_rootfs.sh

cd ../dts
./mk_dtb.sh

cd ../../build

echo "********************到./out/platfrom1/目录下运行start_kernel.sh, open_gdb.sh脚本*************************"
