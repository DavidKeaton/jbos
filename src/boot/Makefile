.PHONY: clean
all: boot.bin stage2.bin

boot.bin: boot.asm
	fasm $< $@
stage2.bin: stage2.asm
	fasm $< $@

clean:
	rm -f *~
	rm -f boot.bin stage2.bin
