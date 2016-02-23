CC=g++
CPPFLAGS= -Wall -O3

CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
#LD_FLAGS := ...
CC_FLAGS := -Wall  -std=c++11

#Tell make to make one .out file for each .cpp file found in the current directory
all: $(patsubst src/%.cpp, bin/%.out, $(wildcard src/*.cpp))

#Rule how to create arbitary .out files. 
#First state what is needed for them e.g. additional headers, .cpp files in an include folder...
#Then the command to create the .out file, probably you want to add further options to the g++ call.
bin/%.out: src/%.cpp Makefile
	$(CC) $< -o $@  $(CC_FLAGS)

clean:
	rm bin/*.out
