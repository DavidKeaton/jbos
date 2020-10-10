.PHONY: clean
all: a.fd b.cd c.hd d.hd

a.fd:
	bximage -q -mode=create -fd=1.44M $@
b.cd:
	mkisofs -f -no-bak -o $@ "../iso/"
c.hd:
	bximage -q -mode=create -hd=512M $@
d.hd:
	bximage -q -mode=create -hd=1G $@
clean:
	rm -f a.fd b.cd c.hd d.hd
