#! /bin/bash

gnome-terminal --window -- bash -c "../../../prebuild/gdb-arm/gcc-linaro-7.1.1-2017.08-x86_64_aarch64-linux-gnu/bin/aarch64-linux-gnu-gdb \
      ../../../../../kernel_for_study/vmlinux \
      -data-directory /usr/share/gdb \
      -tui \
      -ex "set confirm" \
      -ex "add-symbol-file vmlinux -s .head.text 0x40200000 -s .text 0x40210000 -s .init.text 0x42870000" \
      -ex "target remote :1234" \
      -ex "b * 0x40200000 thread 1" \
      ;exec bash"

