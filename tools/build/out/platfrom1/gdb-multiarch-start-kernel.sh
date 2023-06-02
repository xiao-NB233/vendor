# default parameter
KERNEL=./Image
ROOTFS=./rootfs.cpio.gz
DTB=./study.dtb
CMDLINE="nokaslr"
GDB_PORT=$(((RANDOM % 10000) + 10000))

qemu-system-aarch64 --version
QEMU_CMD="qemu-system-aarch64 \
        -machine virt,virtualization=true,gic-version=3 \
        -nographic \
        -m size=2048M \
        -cpu cortex-a72 \
        -smp 8 \
        -kernel $KERNEL \
        -initrd $ROOTFS \
        --append $CMDLINE \
	--gdb tcp::$GDB_PORT \
	-S \
	-fsdev local,security_model=none,id=fsdev0,path=/work/test/ \
	-device virtio-9p-pci,id=fs0,fsdev=fsdev0,mount_tag=hostshare"

xfce4-terminal -e "$QEMU_CMD" -T "QEMU@Localhost:$GDB_PORT" &

KERNEL_PATH="/work/kernel5.15/linux"
GDB_PATH="/usr"
VMLINUX=./vmlinux

gdb-multiarch \
    $VMLINUX \
    --directory $KERNEL_PATH \
    --data-directory $GDB_PATH/share/gdb \
    -ex "set confirm off" \
    -ex "set architecture aarch64" \
    --tui \
    -ex "target remote localhost:$GDB_PORT" \
    -ex "source $KERNEL_PATH/scripts/gdb/vmlinux-gdb.py" \
    -ex "add-symbol-file $VMLINUX 0x40002000 -s .head.text 0x40002000" \
    -ex "break *0x40000000 thread 1" \
    #-ex "continue"

killall qemu-system-aarch64
