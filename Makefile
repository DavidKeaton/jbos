.PHONY: clean src disks bochs
.SILENT: all clean src disks bochs
all: src disks bochs

src:
	make -s -C src/

disks: src
	make -s -C img/

bochs: disks
	bochs -f emu/bochs.cfg

clean:
	echo "cleaning [./]..."
	rm -f *~
	echo "cleaning [out/]..."
	rm -rf out/*
	echo "cleaning [emu/]..."
	rm -f emu/*.log
	make -s -C src/ clean
	make -s -C img/ clean
