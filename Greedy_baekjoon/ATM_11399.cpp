#include <iostream>
#include <algorithm>

using namespace std;

void atm()
{
	int N;
	cin >> N;

	int* p = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> p[i];
	}

	sort(p, p + N);

	int minTotalWaiting = 0;
	for (int i = 0; i < N; i++)
	{
		minTotalWaiting += p[i] * (N - i);
	}

	cout << minTotalWaiting << endl;

}