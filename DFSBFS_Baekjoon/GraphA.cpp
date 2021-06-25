#include "GraphA.h"
#include <algorithm>

GraphA::GraphA(int v)
{
	this->v = v;
	nodes = new nodeR[v];
	for (int i = 0; i < v; i++)
	{
		nodes[i].id = i + 1;
		nodes[i].visited = false;
	}
}
GraphA::~GraphA()
{
	delete[]nodes;
}
void GraphA::insertEdge(int v1, int v2)
{
	nodes[v1 - 1].adjacent.push_back(v2);
	sort(nodes[v1 - 1].adjacent.begin(), nodes[v1 - 1].adjacent.end());
}
void GraphA::markVisited(int v1)
{
	nodes[v1 - 1].visited = true;
}

void GraphA::resetVisited()
{
	for (int i = 0; i < v; i++)
	{
		nodes[i].visited = false;
	}
}