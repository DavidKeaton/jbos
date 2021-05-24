MOUNT		= "sudo mount"
UMOUNT		= "sudo umount"
LOSETUP		= "sudo losetup"

1_44M		= "1474560"
1_44M_512	= "1474048"
FD_BLOCKS	= "2880"
FD_BLOCKS_MIN_1	= "2879"

LOOP_A		= "/dev/loop30"
MNT_A		= "mnt/a.fd"

DISKS		= a.fd b.cd c.hd d.hd
SKELS		= a.fd.skel b.cd.skel c.hd.skel d.hd.skel
LOOPS		= loop_a

.SILENT: all clean
.PHONY: all clean $(LOOPS)
all: $(DISKS)

a.fd:
	echo "creating [a.fd]..."
	bximage -q -mode=create -fd=1.44M $@.skel
	mkfs.vfat $@.skel 
	dd if=../out/boot/boot.bin of=$@ bs=512 count=1 seek=0
	dd if=$@.skel of=$@ bs=512 count=$(FD_BLOCKS_MIN_1) skip=1 seek=1
	rm -f $@.skel

loop_a: a.fd
	echo "setting up [loop_a]..."
	$(UMOUNT) $(LOOP_A)
	$(LOSETUP) -d $(LOOP_A)
	$(LOSETUP) $(LOOP_A) $<
	mkdir -p $(MNT_A)
	$(MOUNT) $(LOOP_A) $(MNT_A)

b.cd:
	echo "creating [b.cd]..."
	mkisofs -f -no-bak -o $@ "../iso/"

c.hd:
	echo "creating [c.hd]..."
	bximage -q -mode=create -hd=512M $@
	rm -f $@.skel

d.hd:
	echo "creating [d.hd]..."
	bximage -q -mode=create -hd=1G $@
	rm -f $@.skel

clean:
	echo "cleaning [img/]..."
	rm -f *~
	rm -f $(SKELS)
	rm -f $(DISKS)
	#$(LOSETUP) -d $(LOOP_A)
