#include "Iterator.hpp"
#include "Cell.hpp"
#include <queue>

using std::queue;

Iterator::Iterator(Cell* a)
{
	Cell* p = a;
	queue <Cell *> q;
	q.push(p);
	while(!q.empty())
	{
		p = q.front();
		p->color = 1;
		bfs.push_back(p);
		q.pop();
		for(int i = 0; i < p->Neig.size(); i++)
		{
			if(p->Neig[i] != NULL && p->Neig[i]->color == 0)
				q.push(p->Neig[i]);
		}
	}
	for(int i = 0; i < bfs.size(); i++)
	{
		bfs[i]->color = 0;
	}
	cout << bfs.size();
}

bool Iterator::is_done()
{
	return cur >= bfs.size();
}

Cell* Iterator::next()
{
	return ++cur < bfs.size() ? bfs[cur] : NULL;
}

Cell* Iterator::current_item()
{
	return bfs[cur];
}
