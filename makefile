#edward ramos - makefile
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11
edslist: main.o edslist.o
	$(CXX) $(CXXFLAGS) -o edslist $^ 
main.o: main.cpp
edslist.o: edslist.cpp edslist.h
clean:
	rm -f edslist *.o

