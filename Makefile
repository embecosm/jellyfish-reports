.PHONY: all clean build README.md

all: $(wildcard *-report.md)

build:
	mkdir -p build

%.md: build
	pandoc -V geometry:margin=1cm -o build/$(basename $@).pdf $@

clean:
	$(RM) -rf build
