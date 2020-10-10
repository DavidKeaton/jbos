.PHONY: clean disks
all: disks

disks:
	make -C img/

clean:
	rm -f *~
	make -C img/ clean
