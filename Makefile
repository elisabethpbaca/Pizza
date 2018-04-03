all: main

main: main.o player.o point.o object.o map.o
	g++ main.o player.o point.o object.o map.o -o main

main.o: main.cpp
	g++ -c main.cpp

player.o: player.cpp
	g++ -c player.cpp

point.o: point.cpp
	g++ -c point.cpp

object.o: object.cpp
	g++ -c object.cpp

map.o: map.cpp
	g++ -c map.cpp



clean:
	rm -f player point object main map *.o
