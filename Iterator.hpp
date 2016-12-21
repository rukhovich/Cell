#include "Transcendental.hpp"
#include "Point.hpp"
#include <utility>
#include <vector>
#include <iostream>
#pragma once

using std::vector;

class Cell;

class Iterator
{
	vector <Cell*> bfs;
	int cur;
public:
	Iterator(Cell* a);
	bool is_done();
	Cell* next();
	Cell* prev();
	Cell* current_item();
};

