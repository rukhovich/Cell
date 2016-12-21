#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <utility>
#include "Point.hpp"
#include "Cell.hpp"
#include "Organism.hpp"
#include "Iterator.hpp"

using std::cout;
using std::cin;

int main()
{
	Organism a;
	Cell b = Cell(&a);
	cout << "Start\n";
	int i = 0;
	for(Cell *p = &b; a.veccells.size() < 30; p = p->Neig[0])
	{
		(*p).birth(0);
	}
	for(int i = 0; i < a.veccells.size(); i++)
	{
		Cell* p = a.veccells[i];
		cout << p->n << " ";
		int s = 0;
		for(int j = 0; j < 6; j++)
		{
			if(p->Neig[j] != NULL)
				s++;
		}
		cout << s << "\n";
	}
	cout << "Create is done\n";
	for(auto i = b.create_iterator(); !i.is_done(); i.next())
	{
		cout << i.current_item()->n << " ";
	}
	cout << "Finish\n";
	return 0;
}
