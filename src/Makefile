.SILENT: all boot clean
.PHONY: clean boot

all: boot

boot:
	echo "compiling [$@/]..."
	make -s -C $@/
	mkdir -p ../out/$@/
	cp $@/*.bin ../out/$@/

clean:
	echo "cleaning [src/]..."
	rm -f *~
	make -s -C boot/ clean
