#! /bin/bash

#删除原路经下的所有文件
rm -rf /work/qemu_linux/rootfs
rm -rf /work/qemu_linux/tmpfs
mkdir /work/qemu_linux/rootfs
#复制busybox工具制成的原始rootfs到/work/qemu_linux/rootfs下
cp  -r /work/qemu_linux/busybox-1.31.0/_install/* /work/qemu_linux/rootfs/

cd /work/qemu_linux/rootfs/
#在rootfs下创建lib目录存放bin工具
mkdir lib 
cp -r /usr/bin/aa* ./lib/
#在rootfs下创建/proc, /sys, /dev, /etc目录
mkdir proc sys dev etc
#dev/下创建以下节点
cd ./dev
sudo mknod -m 666 tty1 c 4 1
sudo mknod -m 666 tty2 c 4 2
sudo mknod -m 666 tty3 c 4 3
sudo mknod -m 666 tty4 c 4 4
sudo mknod -m 666 console c 5 1
sudo mknod -m 666 null c 1 3
cd ..

cd ./etc
touch fstab
echo "proc     /proc                   proc     defaults        0 0" >> fstab
echo "sysfs    /sys                    sysfs    defaults        0 0" >> fstab
echo "debugfs  /sys/kernel/debug       debugfs  defaults        0 0" >> fstab

mkdir ./init.d
cd ./init.d
touch rcS
echo "#!/bin/sh" >> rcS
echo "mount -a" >> rcS
chmod 777 rcS

cd ..
touch inittab
echo "# /etc/inittab" >> inittab
echo "::sysinit:/etc/init.d/rcS" >> inittab
echo "console::respawn:-/bin/sh" >> inittab
echo "::ctrlaltdel:/sbin/reboot" >> inittab
echo "::shutdown:/bin/umount -a -r" >> inittab
#
#mkdir /work/qemu_linux/tmpfs
#cd /work/qemu_linux/tmpfs/
#touch mkrootf.sh
#echo "#!/bin/bash" >> mkrootf.sh
#echo "dd  if=/dev/zero  of=rootfs.ext3  bs=1M  count=256" >> mkrootf.sh    #每个block 1Mb，一共256Mb
#echo "mkfs.ext3 rootfs.ext3" >> mkrootf.sh
#echo "sudo mount -t ext3 rootfs.ext3 /work/qemu_linux/tmpfs -o loop" >> mkrootf.sh
#echo "cp -r /work/qemu_linux/rootfs/* /work/qemu_linux/tmpfs/" >> mkrootf.sh
#echo "umount /work/qemu_linux/tmpfs" >> mkrootf.sh
#
#chmod 777 mkrootf.sh
#./mkrootf.sh


