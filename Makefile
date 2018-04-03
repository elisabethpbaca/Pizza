all: main

main: main.o player.o point.o object.o
	g++ main.o player.o point.o object.o -o main

main.o: main.cpp
	g++ -c main.cpp

player.o: player.cpp
	g++ -c player.cpp

point.o: point.cpp
	g++ -c point.cpp

object.o: object.cpp
	g++ -c object.cpp

clean:
	rm -f player point object main *.o
