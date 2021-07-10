#include <iostream>
using namespace std;

const int MAXNUM = 10;

void change()
{
	int N;
	int K;
	int coinType[MAXNUM];
	int count = 0;

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> coinType[i];
	}

	for (int i = 0; i < N; i++)
	{
		count += K / coinType[N - 1 - i];
		K %= coinType[N - 1 - i];
		if (K == 0)
		{
			break;
		}
	}

	cout << count << endl;
}