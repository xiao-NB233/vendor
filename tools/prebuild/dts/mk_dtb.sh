#! /bin/bash

dtc -I dts -O dtb -o test.dtb test.dts

cp ./test.dtb ../../build//out/platfrom1/dtb/
