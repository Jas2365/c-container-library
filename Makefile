cxx = gcc
cflags =

inc = -Iinc
src = $(wildcard src/*.c)

target = out/main.exe

all: build run

build:
	$(cxx) $(inc) $(src) -o $(target)
run:
	./$(target)