CXX = g++
INCLUDEPATHS = -I.
CFLAGS = -Wall

main : main.o
	${CXX} ${INCLUDEPATHS} ${CFLAGS} -o $@ $@.o

.cpp.o:
	${CXX} ${INCLUDEPATHS} ${CFLAGS} -c $<


