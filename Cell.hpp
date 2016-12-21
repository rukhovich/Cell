#include "Transcendental.hpp"
#include "Point.hpp"
#include <utility>
#include <vector>
#include <iostream>
#pragma once

using std::vector;
using std::pair;
using std::cout;

class Organism;
class Iterator;

class Cell
{
public:
	Organism *parent;
	Point I;
	int n;
	vector <Cell*> Neig{6};
	//Cell();
	int color{0};
	void dfs(vector <Cell*> *h);
	Cell(Organism *p, Point L = Point());
	~Cell();
	Point neig(int k);
	bool neigExistance(int k);
	bool edgeExistance(int k);
	bool createEdge(int k);
	bool removeEdge(int k);
	bool birth(int k);
	void death();
	pair <float, float> coordination();
	Iterator create_iterator();
	
};


