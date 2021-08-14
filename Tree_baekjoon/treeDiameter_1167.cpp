#include <iostream>
#include <vector>
#include "treeDiameter_1167.h"

using namespace std;

const int MAX = 100001;

typedef struct node
{
	int near;
	int distance;
}node;

int farVertex;
int longDist = 0;
vector<vector<node>> neighbors(MAX);
vector<bool> visited(MAX, false);

void findFarthestDist(int vertex, int dist)
{
	if (visited[vertex])
	{
		return;
	}
	if (longDist < dist)
	{
		longDist = dist;
		farVertex = vertex;
	}

	visited[vertex] = true;
	int inbetween, near;
	for (long unsigned int i = 0; i < neighbors[vertex].size(); i++)
	{
		inbetween = neighbors[vertex][i].distance;
		near = neighbors[vertex][i].near;
		findFarthestDist(near, dist + inbetween);
	}
}

void treeDiameter()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int vertex;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> vertex >> temp;
		int inbetween;
		while (temp != -1)
		{
			cin >> inbetween;
			neighbors[vertex].push_back({ temp, inbetween });
			neighbors[temp].push_back({ vertex, inbetween });
			cin >> temp;
		}
	}

	findFarthestDist(1, 0);
	visited = vector<bool>(MAX, false);
	findFarthestDist(farVertex, 0);

	cout << longDist << '\n';
}