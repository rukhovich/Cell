#include "Organism.hpp"
#include "Cell.hpp"

bool Organism::check()
{
	for(int i = 0; i < veccells.size(); i++)
		color[i] = 0;
	vector <vector <Cell*> > H;
	for(int i = 0; i < veccells.size(); i++)
	{
		if(veccells[i] != NULL && color[i] == 0)
		{
			vector <Cell*> h;
			veccells[i]->dfs(&h);
			H.push_back(h);
		}
	}
	vector <Cell*> *max;
	for(int i = 0; i < H.size(); i++)
		if(H[i].size() > max->size())
			max = &H[i];
	for(int i = 0; i < (*max).size(); i++)
		(*max)[i]->color = 0;
	for(int i = 0; i < veccells.size(); i++)
	{
		if(veccells[i]->color == 0)
			veccells[i]->death();
		veccells[i] = NULL;
	}	
	for(int i = 0; i < (*max).size(); i++)
	{
		veccells[i] = (*max)[i];
		(*max)[i]->n = i;
	}
	return true;
}

int Organism::add(Cell *p)
{
	veccells.push_back(p);
	color.push_back(0);
	//p->n = veccells.size()-1;
	return veccells.size()-1;
}

bool Organism::remove(int n)
{
	if(n < veccells.size() && veccells[n] != NULL)
	{
		veccells[n]->death();
		return true;
	}
	return false;
}

bool Organism::remove(Cell *p)
{
	if(p != NULL)
	{
		p->death();
		return true;
	}
	return false;
}
