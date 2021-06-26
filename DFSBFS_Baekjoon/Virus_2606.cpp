#include <iostream>
#include "GraphA.h"
using namespace std;

void virusSearch(graphPtr g, int startNum, int* count);

void virus()
{
	int comNum, edge;
	cin >> comNum >> edge;

	graphPtr g = new GraphA(comNum);

	int begin, end;
	for (int i = 0; i < edge; i++)
	{
		cin >> begin >> end;
		g->insertEdge(begin, end);
		g->insertEdge(end, begin);
	}

	int virusCount = 0;
	virusSearch(g, 1, &virusCount);
	cout << virusCount - 1 << endl;
}

void virusSearch(graphPtr g, int startNum, int* count)
{
	g->markVisited(startNum);
	(*count)++;
	for (int i = 0; i < g->nodes[startNum - 1].adjacent.size(); i++)
	{
		if (!g->nodes[g->nodes[startNum - 1].adjacent[i] - 1].visited)
		{
			virusSearch(g, g->nodes[startNum - 1].adjacent[i], count);
		}
	}
}