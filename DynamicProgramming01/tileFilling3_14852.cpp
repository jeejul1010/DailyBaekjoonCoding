#include <iostream>

using namespace std;

long long int dArry[1000001][2];

//int dpMem(int x)
//{
//	if (x == 0) return 1;
//	if (x == 1) return 2;
//	if (x == 2) return 7;
//	if (dArry[x] != 0) return dArry[x];
//	int result = (2 * dpMem(x - 1) + 3 * dpMem(x - 2))%1000000007;
//	for (int i = 3; i <= x; i++)
//	{
//		result += (2 * dpMem(x - i))%1000000007;
//	}
//	return dArry[x] = result;
//}

long long int dpMem(int x)
{
	dArry[0][0] = 1;
	dArry[1][0] = 2;
	dArry[2][0] = 7;
	dArry[2][1] = 0;

	for (int i = 3; i <= x; i++)
	{
		dArry[i][1] = (dArry[i - 1][1] + dArry[i - 3][0]) % 1000000007;
		dArry[i][0] = (2 * dArry[i - 1][0] + 3 * dArry[i - 2][0] + 2 * dArry[i][1]) % 1000000007;
	}

	return dArry[x][0];
}


void tileFilling3()
{
	int n;
	cin >> n;
	cout << dpMem(n) << endl;
}