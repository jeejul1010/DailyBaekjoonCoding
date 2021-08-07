#include <iostream>
#include <vector>
#include <algorithm>
#include "NumberCard2_10816.h"

using namespace std;

//int countCard(vector<int> arr, int first, int last, int k)
//{
//	/*int rememberFirst = first;
//	int rememberLast = last;*/
//	int count = 0;
//
//	while (first <= last)
//	{
//		int middle = (first + last) / 2;
//		if (arr[middle] == k)
//		{
//			count++;
//			arr.erase(arr.begin() + middle);
//			first = 0;
//			last = arr.size() - 1;
//			/*int count = 1;
//			int index = middle;
//			while (++index!=rememberLast+1 && arr[index] == k)
//			{
//				count++;
//			}
//			index = middle;
//			while (--index!=rememberFirst-1 && arr[index] == k)
//			{
//				count++;
//			}
//			return count;*/
//		}
//		else if (arr[middle] > k)
//		{
//			last = middle - 1;
//		}
//		else
//		{
//			first = middle + 1;
//		}
//	}
//
//	if (count > 0)
//	{
//		return count;
//	}
//	else
//	{
//		return 0;
//	}
//
//}

void numberCard()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> nArr;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		nArr.push_back(temp);
	}

	sort(nArr.begin(), nArr.end());

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;

		auto upper = upper_bound(nArr.begin(), nArr.end(), temp);
		auto lower = lower_bound(nArr.begin(), nArr.end(), temp);

		cout << upper - lower << ' ';
	}
	cout << "\n";
}