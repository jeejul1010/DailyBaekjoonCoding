#include <iostream>
#include <vector>
#include "treeDiameter2_1967.h"

using namespace std;

const int MAX = 10001;
vector<pair<int, int>> nodes[MAX];
vector<int> visited(MAX, 0);

int diameter = 0;
int endNode = 0;

void dfs(int node, int length)
{
	if (visited[node])
	{
		return;
	}

	visited[node] = true;

	if (diameter < length)
	{
		diameter = length;
		endNode = node;
	}

	for (int i = 0; i < nodes[node].size(); i++)
	{
		dfs(nodes[node][i].first, length + nodes[node][i].second);
	}
}

void treeDiameter2()
{
	int num;
	cin >> num;

	int parent, child, length;
	for (int i = 1; i < num; i++)
	{
		cin >> parent >> child >> length;
		nodes[parent].push_back(make_pair(child, length));
		nodes[child].push_back(pair<int, int>(parent, length));
	}

	dfs(1, 0);

	fill(visited.begin(), visited.end(), 0);

	dfs(endNode, 0);

	cout << diameter << endl;

}