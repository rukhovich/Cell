#include "Cell.hpp"
#include "Organism.hpp"
#include "Iterator.hpp"

vector <Point> neirs
{
	Point(Trans(-1, 0), Trans(0, 1)),
	Point(Trans(1, 0), Trans(0, 1)),
	Point(Trans(2, 0), Trans(0, 0)),
	Point(Trans(1, 0), Trans(0, -1)),
	Point(Trans(-1, 0), Trans(0, -1)),
	Point(Trans(-2, 0), Trans(0, 0))
};


Cell::Cell(Organism *p, Point L)
{
	parent = p;
	I = L;
	n = p->add(this);
	parent->cells[I.str()] = this;
	//parent->veccells.push_back(this);
	for(int i = 0; i < 6; i++)
		createEdge(i);
	
}
Cell::~Cell()
{
	for(int i = 0; i < 6; i++)
	{
		removeEdge(i);
	}			
	parent->cells.erase(I.str());
	parent->veccells[n] = NULL;
}
Point Cell::neig(int n)
{
	//cout << (I + neirs[n]).value().first << " " << (I + neirs[n]).value().second << " " << (I + neirs[n]).str() << std::endl;
	return I + neirs[n];
}
bool Cell::neigExistance(int n)
{
	if(parent->cells.find(neig(n).str()) == parent->cells.end())
		return false;
	return true;
}
bool Cell::edgeExistance(int n)
{
	if(Neig[n] == NULL)
		return false;
	return true;
}
bool Cell::createEdge(int n)
{
	if(!neigExistance(n))
		return false;
	auto *buf = parent->cells[neig(n).str()];
	buf = this;
	Neig[n] = buf;
	return true;
}
bool Cell::removeEdge(int n)
{
	if(!neigExistance(n) || !edgeExistance(n))
		return false;
	Neig[n]->Neig[(n + 3) % 6 ] = NULL;
	Neig[n] = NULL;
	return true;
}
bool Cell::birth(int n)
{
	if(neigExistance(n))
		return false;
	Cell *leave = new Cell(parent, neig(n));
	Neig[n] = leave;
	leave->Neig[(n + 3) % 6] = this;
	return true;
}
void Cell::death()
{
	vector <Cell*> d;
	for(int i = 0; i < 6; i++)
	{
		if(edgeExistance(i))				
			d.push_back(Neig[i]);
		removeEdge(i);
	}
	cout << n << std::endl;
	for(int i = 0; i < d.size(); i++)
	{
		cout << i << " " << d[i]->n << "\n";
	}
	cout << "\n";
	/*for(int i = 0; i < d.size(); i++)
		DFS(d[i])
	*/
	this->~Cell();
	//delete this;		
}
pair <float, float> Cell::coordination()
{
	return I.value();
}

void Cell::dfs(vector <Cell*> *h)
{
	color = 1;
	h->push_back(this);
	for(int i = 0; i < 6; i++)
	{
		if(edgeExistance(i) && Neig[i]->color == 0)
		{
			Neig[i]->dfs(h);
		}
	}
	return;
}

Iterator Cell::create_iterator()
{
	return Iterator(this);
}

