name = tver
includes = $(wildcard inc/*)
testfiles = $(wildcard tst/*)
sourcefiles = $(wildcard src/*)
tests = $(testfiles:%.cxx=obj/%.o)
sources = $(sourcefiles:%.cpp=obj/%.o)
location = /usr/local/lib

compiler = g++
flags = -Iinc -Ilib -std=c++17 -pedantic -Wall

all: obj bin run

obj: obj/src obj/tst

obj/src:
	mkdir -p $@

obj/tst:
	mkdir -p $@

bin:
	mkdir -p $@

run: bin/$(name)
	$<

test: bin/test
	$<

clean:
	rm -f $(tests) $(sources) bin/test bin/$(name)

bin/test: $(tests)
	$(compiler) -o $@ $^

bin/$(name): $(sources)
	$(compiler) -o $@ $^

obj/tst/catch.o: tst/catch.cxx
	$(compiler) -o $@ -c $< $(flags) -g

obj/tst/%.o: tst/%.cxx $(includes)
	$(compiler) -o $@ -c $< $(flags) -g

obj/src/%.o: src/%.cpp $(includes)
	$(compiler) -o $@ -c $< $(flags)

install: $(includes)
	install $(includes) $(location)/$(name)/

.PHONY: all obj bin run test clean install obj/src obj/tst
