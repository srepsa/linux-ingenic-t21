#!/usr/bin/env bash

KERNEL_IMAGE_ELF=vmlinux
DTB=arch/mips/boot/dts/ingenic/turkey.dtb
LOADADDR=0x80010000

make ARCH=mips CROSS_COMPILE=mipsel-linux-gnu- CC="ccache mipsel-linux-gnu-gcc" -j4 vmlinux
mipsel-linux-gnu-objcopy -O binary $KERNEL_IMAGE_ELF $KERNEL_IMAGE_ELF.bin

ENTRYPOINT=$(readelf -h $KERNEL_IMAGE_ELF | grep Entry | awk '{print $4}')

cat $KERNEL_IMAGE_ELF.bin $DTB > $KERNEL_IMAGE_ELF.bin.dtb
mkimage -A mips -O linux -T kernel -C none -a $LOADADDR  -e $ENTRYPOINT -d $KERNEL_IMAGE_ELF.bin.dtb uImage
