FLAGS=  -Wall 
DEBUG= -Wall -g -DDEBUG 
CXX=gcc
RM=rm -rf

main_exe: main.c hamming.o  Makefile
	$(CXX) -o main_exe main.c hamming.o $(FLAGS)

main_debug: main.c hamming.c  hamming.h Makefile
	$(CXX) -o main_debug main.c hamming.o $(DEBUG)

hamming: hamming.c  hamming.h Makefile
	$(CXX) -c hamming.o hamming.c hamming.h $(FLAGS)

hamming_debug: hamming.c  hamming.h Makefile
	$(CXX) -o hamming_exe hamming.c hamming.h  $(DEBUG) -DDEBUGEXE

clean:
	$(RM) *_exe  *_debug *.o