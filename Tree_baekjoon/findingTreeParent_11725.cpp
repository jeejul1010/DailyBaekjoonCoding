#include <iostream>
#include <queue>
#include <vector>
#include "findingTreeParent_11725.h"

using namespace std;



void findParent(int a, vector<vector<int>>& neighbors, vector<int>& parent, vector<bool>& visited)
{
	visited[a] = true;
	for (int i = 0; i < neighbors[a].size(); i++)
	{
		if (!visited[neighbors[a][i]])
		{
			parent[neighbors[a][i]] = a;
			findParent(neighbors[a][i], neighbors, parent, visited);
		}
	}
}

void findingTreeParent()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); //속도 향상 위해

	int n;
	cin >> n;

	vector<vector<int>> neighbors(n + 1);
	vector<int> parent(n + 1);
	vector<bool> visited(n + 1, false);

	int temp, temp2;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> temp >> temp2;
		neighbors[temp].push_back(temp2);
		neighbors[temp2].push_back(temp);
	}

	findParent(1, neighbors, parent, visited);

	for (int i = 2; i < n + 1; i++)
	{
		cout << parent[i] << '\n';
	}


}