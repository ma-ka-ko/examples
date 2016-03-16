CC=g++
CPPFLAGS= -Wall -g

JAVA_FILES := $(wildcard src/*.java)
CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
#LD_FLAGS := ...
CC_FLAGS := -Wall -g -std=c++11

#Tell make to make one .out file for each .cpp file found in the current directory
all: $(patsubst src/%.cpp, bin/%.out, $(wildcard src/*.cpp)) $(patsubst src/%.java, bin/%.class, $(wildcard src/*.java)) 

#Rule how to create arbitary .out files. 
#First state what is needed for them e.g. additional headers, .cpp files in an include folder...
#Then the command to create the .out file, probably you want to add further options to the g++ call.
bin/%.out: src/%.cpp Makefile
	$(CC) $< -o $@  $(CC_FLAGS)

bin/%.class: src/%.java 
	javac $< -d bin
	

clean:
	rm -fv bin/*.out
	rm -fv bin/*.class
