#include <iostream>
#include <vector>
#include "GraphA.h"
#include "QueueP.h"
using namespace std;

typedef GraphA* graphPtr;

void dfs(graphPtr g, int startV);
void bfs(graphPtr g, int startV);


void graphTraverse()
{
	int N, M, startV;
	cin >> N >> M >> startV;

	graphPtr g = new GraphA(N);

	int begin, end;
	for (int i = 0; i < M; i++)
	{
		cin >> begin >> end;
		g->insertEdge(begin, end);
		g->insertEdge(end, begin);
	}

	dfs(g, startV);
	cout << endl;
	g->resetVisited();
	bfs(g, startV);


}

void dfs(graphPtr g, int startV) {
	g->markVisited(startV);
	cout << startV << ' ';
	for (int i = 0; i < g->nodes[startV - 1].adjacent.size(); i++)
	{
		if (!(g->nodes[g->nodes[startV - 1].adjacent[i] - 1].visited))
		{
			dfs(g, g->nodes[startV - 1].adjacent[i]);
		}
	}
}

void bfs(graphPtr g, int startV) {
	QueueP bfsQ;
	bfsQ.add(startV);
	g->markVisited(startV);

	int removedItem;
	while (!bfsQ.isEmpty())
	{
		removedItem = bfsQ.getFront();
		cout << removedItem << ' ';
		bfsQ.remove();
		for (int i = 0; i < g->nodes[removedItem - 1].adjacent.size(); i++)
		{
			if (!(g->nodes[g->nodes[removedItem - 1].adjacent[i] - 1].visited))
			{
				bfsQ.add(g->nodes[removedItem - 1].adjacent[i]);
				g->markVisited(g->nodes[removedItem - 1].adjacent[i]);
			}
			
		}

	}
}	