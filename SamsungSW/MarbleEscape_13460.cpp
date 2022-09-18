#include <iostream>
#include <vector>

using namespace std;

void marbleEscape()
{
	int N, M;
	cin >> N >> M;

	vector<vector<char>> board(N, vector<char>(M));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}

	

}