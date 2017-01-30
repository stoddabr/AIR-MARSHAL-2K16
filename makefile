#makefile 

#target: dependencies
#	rule to build
#
#

CC = gcc
CXX = g++
CFLAGS = -std=c99
CXXFLAGS = -std=c++0x
#CXXFLAGS += -g
#	CXXFLAGS += -03 #debug
#CXXFLAGS += -Wall #show all warnings
#CXXFLAGS += -pedantic-errors


OBJS = room.o row.o window.o front.o player.o
SRCS = main.cpp room.cpp row.cpp window.cpp front.cpp player.cpp
HEADERS = room.hpp row.hpp window.hpp front.hpp player.hpp

#default: files
#	g++ -std=0x files -o lab1
#


lab1: ${HEADERS} $(SRCS)
	g++ -std=c++0x $(SRCS) -o game


clean:
	rm *o game
