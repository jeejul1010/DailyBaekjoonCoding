#include <iostream>

using namespace std;

const int maxNum = 1100;

unsigned long long dp[maxNum];

unsigned long long factorial(int num)
{
	if (num == 0) return 1;
	if (num == 1) return 1;
	if (dp[num] != 0) return dp[num];
	return dp[num] = num * factorial(num - 1);
}

unsigned long long comb(int a, int b)
{
	return factorial(a) / (factorial(a-b) * factorial(b));
}

void tiling()
{
	int n, a, b;
	unsigned long long total = 0;
	cin >> n;

	int i = 0;

	if (n % 2 != 0)
	{
		i = 1;
	}

	while(i<=n)
	{
		a = i;
		b = (n - a) / 2;
		total += comb(a+b, b);
		i += 2;
	}

	total %= 10007;

	cout << total << endl;
}