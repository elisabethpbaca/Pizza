all: main

main: main.o helpers.o player.o point.o object.o structure.o map.o
	g++ main.o helpers.o player.o point.o object.o structure.o map.o -o Pizza

main.o: main.cpp
	g++ -c main.cpp

helpers.o: helpers.cpp
	g++ -c helpers.cpp

player.o: player.cpp
	g++ -c player.cpp

point.o: point.cpp
	g++ -c point.cpp

object.o: object.cpp
	g++ -c object.cpp

structure.o: structure.cpp
	g++ -c structure.cpp

map.o: map.cpp
	g++ -c map.cpp

clean:
	rm -f player helpers point object structure main map Pizza *.o
