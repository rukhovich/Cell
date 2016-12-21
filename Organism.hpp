#include <vector>
#include <map>
#include <string>
#pragma once

using std::map;
using std::vector;
using std::string;

class Cell;

class Organism
{
public:
	map <string, Cell*> cells;
	vector <Cell*> veccells;
	vector <int> color;
public:
	int add(Cell *p);
	bool remove(int n);
	bool remove(Cell *p);
	bool check();
};
