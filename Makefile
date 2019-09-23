CFLAGS=-Wall -Wextra -DDEBUG -g -std=c++14
proj=program3

all: $(proj).o Planet.o Galaxy.o
	g++ $(proj).o Planet.o Galaxy.o -o $(proj)

$(proj).o: $(proj).cpp 
	g++ -c $(CFLAGS) $(proj).cpp 

Planet.o: Planet.cpp Planet.h 
	g++ -c $(CFLAGS) Planet.cpp

Galaxy.o: Galaxy.cpp Galaxy.h
	g++ -c $(CFLAGS) Galaxy.cpp

run: all
	./$(proj) 

clean:
	rm -rf *.o $(proj)

memcheck: all
	valgrind -v --leak-check=full ./$(proj)
