CXX = g++
INCLUDEPATHS = -I.
CXXFLAGS = -Wall -std=c++11

main : main.o
	${CXX} ${INCLUDEPATHS} ${CXXFLAGS} -o $@ $@.o

test : test.o
	${CXX} ${INCLUDEPATHS} ${CXXFLAGS} -o $@ $@.o


.cpp.o:
	${CXX} ${INCLUDEPATHS} ${CXXFLAGS} -c $<


