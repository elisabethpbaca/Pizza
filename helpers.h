#ifndef _HELPERS
#define _HELPERS

#include <iostream>
#include <string>
#include "player.h"
#include "map.h"
#include "child.h"

using namespace std;

extern Map GAMEMAP;
extern Player P1;

string to_lower(string stringToLower);

bool contains(string container, string str1);

bool contains(string container, string str1, string str2);

bool contains(string container, string str1, string str2, string str3);

bool contains(string container, string str1, string str2, string str3, string str4);

bool contains(string container, string str1, string str2, string str3, string str4, string str5);

void get_object_here(string objectToGet);

void see_obstacles_here(void);

void see_objects_here(void);

void move(string moveCommand);

#endif
