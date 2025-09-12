.PHONY: all clean build README.md

all: $(wildcard *-report.md)

build:
	mkdir -p build

%.md: build
	pandoc -o build/$(basename $@).pdf $@

clean:
	$(RM) -rf build
