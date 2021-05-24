INCLUDE	= "../include/"
FASM	= "INCLUDE=\"$(INCLUDE)\" fasm"

OUT	= boot.bin stage2.bin

.SILENT: all clean
.PHONY: all clean
all: $(OUT)

boot.bin: boot.asm
	echo "$(FASM) $< $@"
	$(FASM) $< $@
stage2.bin: stage2.asm
	echo "$(FASM) $< $@"
	$(FASM) $< $@

clean:
	echo "cleaning [src/boot]..."
	rm -f *~
	rm -f $(OUT)
