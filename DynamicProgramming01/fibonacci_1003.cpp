#include <iostream>
using namespace std;
const int MAX = 40;

void fibonacci()
{
	int T;
	cin >> T;

	int* N = new int[T];
	for (int i = 0; i < T; i++)
	{
		cin >> N[i];
	}

	typedef struct node
	{
		int a;
		int b;
	}node;

	node nodes[MAX];
	
	for (int i = 0; i < T; i++)
	{
		nodes[0] = { 1,0 };
		nodes[1] = { 0,1 };
		for (int j = 2; j <= N[i]; j++)
		{
			nodes[j] = { nodes[j - 1].a + nodes[j - 2].a, nodes[j - 1].b + nodes[j - 2].b };
		}

		cout << nodes[N[i]].a << ' ' << nodes[N[i]].b << endl;
	}
	

}