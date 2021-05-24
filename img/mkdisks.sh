#!/bin/sh

# cd image setup
ISO_DIR="../iso/"
ISO_BOOT="boot.img"
#ISO_CATALOG="boot.catalog"
ISO_GENERIC="-G ${ISO_BOOT}"
#ISO_DORITO="-b ${ISO_BOOT} -c ${ISO_CATALOG}"
ISO_OPT="-f -no-bak" #${ISO_GENERIC}"

DISK_A="a.fd"
DISK_B="b.cd"
DISK_C="c.hd"
DISK_D="d.hd"

# TODO: make backups of newly created volumes

# remove old disk files
rm -f ${DISK_A} ${DISK_B} ${DISK_C} ${DISK_D}
# remove old log file
rm -f mkdisks.log
# plop time into log
date >> mkdisks.log
echo "" >> mkdisks.log
# create floppy and hard drives
bximage -q -mode=create -fd=1.44M ${DISK_A} >> mkdisks.log
bximage -q -mode=create -hd=512M ${DISK_C} >> mkdisks.log
bximage -q -mode=create -hd=1G ${DISK_D} >> mkdisks.log
# create cd images
echo "\n\t------Creating [${DISK_B}]------\n" >> mkdisks.log
mkisofs ${ISO_OPT} -o ${DISK_B} "${ISO_DIR}" >> mkdisks.log 2>&1
