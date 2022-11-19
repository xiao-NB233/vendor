qemu-system-aarch64 \
        -machine virt,virtualization=true,gic-version=3 \
        -nographic \
        -m size=2048M \
        -cpu cortex-a72 \
        -smp 4 \
        -kernel ./image/Image \
        -initrd ./ramdisk/rootfs.cpio.gz \
        -dtb	./dtb/test.dtb \
        --append "nokaslr console=ttyAMA0 rdinit=/linuxrc" \
	-S \
	-gdb tcp::1234




