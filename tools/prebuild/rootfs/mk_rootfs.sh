#! /bin/bash
sudo ./copy_rootfs.sh
cd /work/qemu_linux/rootfs
find . | cpio -o -H newc |gzip > /work/qemu_linux/kernel/vendor/tools/build/out/platfrom1/ramdisk/rootfs.cpio.gz
