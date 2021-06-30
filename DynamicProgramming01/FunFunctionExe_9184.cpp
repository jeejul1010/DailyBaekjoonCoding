#include <iostream>
#include <vector>
using namespace std;
const int MAX = 101;

void funFunctionExe()
{
	int x;
	int y;
	int*** w;
	w = new int** [MAX];

	for (x = 0; x < MAX; x++)
	{
		w[x] = new int* [MAX];
		for (y = 0; y < MAX; y++)
		{
			w[x][y] = new int[MAX];
		}
	}

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			for (int k = 0; k < MAX; k++)
			{
				if (i <= 50 || j <= 50 || k <= 50)
				{
					w[i][j][k] = 1;
				}
				else if (i > 70 || j > 70 || k > 70)
				{
					w[i][j][k] = w[70][70][70];
				}
				else if (i < j && j < k)
				{
					w[i][j][k] = w[i][j][k-1]+w[i][j - 1][k - 1] - w[i][j - 1][k];
				}
				else
				{
					w[i][j][k] = w[i - 1][j][k] + w[i-1][j-1][k]+w[i - 1][j][k - 1] - w[i - 1][j - 1][k - 1];
				}
				
			}
		}
	}

	typedef struct node
	{
		int a;
		int b;
		int c;
		int output;
	}node;

	vector<node*> outArr;
	node* n = new node;
	int a, b, c;
	cin >> a >> b >> c;

	while (a != -1 || b != -1 || c != -1)
	{
		node* n = new node;
		n->a = a;
		n->b = b;
		n->c = c;
		n->output = w[a + 50][b + 50][c + 50];
		outArr.push_back(n);
		cin >> a >> b >> c;
	}

	for (int i = 0; i < outArr.size(); i++)
	{
		cout << "w(" << outArr[i]->a << ", " << outArr[i]->b << ", " << outArr[i]->c << ") = " << outArr[i]->output << endl;
	}

	delete n;

	for (x = 0; x < MAX; x++)
	{
		for (y = 0; y < MAX; y++)
		{
			delete[] w[x][y];
		}
	}

	for (x = 0; x < MAX; x++)
	{
		delete[] w[x];
	}

	delete[]w;
	
}