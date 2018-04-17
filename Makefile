all: main

main: main.o helpers.o player.o point.o object.o structure.o map.o enemy.o child.cpp
	g++ main.o helpers.o player.o point.o object.o structure.o map.o enemy.o child.cpp -o Pizza

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

enemy.o: enemy.cpp
	g++ -c enemy.cpp

child.o: child.cpp
	g++ -c child.cpp

clean:
	rm -f player helpers point object structure main map enemy child Pizza *.o
