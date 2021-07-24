#include <iostream>
#include <algorithm>
#include "FindingNum_1920.h"
using namespace std;

int binarySearch(int* a, int first, int last, int k)
{
	if (first > last) {
		return 0;
	}
	else
	{
		int middle = (first + last) / 2;
		if (a[middle] == k)
		{
			return 1;
		}
		else if (a[middle] > k)
		{
			return binarySearch(a, first, middle - 1, k);
			//last = middle - 1;
		}
		else
		{
			return binarySearch(a, middle + 1, last, k);
			//first = middle + 1;
		}
	}
}

void findingNum()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;

	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	sort(a, a + n);

	cin >> m;
	int temp;
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		cout << binarySearch(a, 0, n - 1, temp) << "\n";
	}

	delete[]a;

}
