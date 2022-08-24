#include <iostream>
#include <vector>

const int INF = 987654321;

using namespace std;

void particularSP()
{
	
	int N, E;
	cin >> N >> E;

	vector<vector<int>> sp(N + 1, vector<int>(N + 1, INF));

	for (int i = 1; i <= N; i++)
	{
		sp[i][i] = 0;
	}

	int a, b, c;
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		sp[a][b] = c;
		sp[b][a] = c;

	}

	int v1, v2;
	cin >> v1 >> v2;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cout << sp[i][j] << " ";
		}
		cout << endl;
	}

	for (int j = 1; j <= N; j++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int k = 1; k <= N; k++)
			{
				if (sp[i][k] > sp[i][j] + sp[j][k])
				{
					sp[i][k] = sp[i][j] + sp[j][k];
				}
			}
		}

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cout << sp[i][j] << " ";
			}
			cout << endl;
		}

	}

	if ((sp[1][v1] == INF || sp[v1][v2] == INF || sp[v2][N] == INF) && (sp[1][v2] == INF || sp[v2][v1] == INF || sp[v1][N] == INF))
	{
		cout << "-1" << endl;
		return;
	}

	int cand1 = sp[1][v1] + sp[v1][v2] + sp[v2][N];
	int cand2 = sp[1][v2] + sp[v2][v1] + sp[v1][N];

	/*if (cand1 >= INF && cand2 >= INF)
	{
		cout << "-1" << endl;
		return;
	}*/

	if (cand1 < cand2)
	{
		cout << cand1 << endl;
	}
	else
	{
		cout << cand2 << endl;
	}
}
