#include <iostream>

using namespace std;

int ddd[31];

int dppp(int x)
{
	if (x == 0) return 1;
	if (x == 1) return 0;
	if (x == 2) return 3;
	if (ddd[x] != 0) return ddd[x];
	int result = 3 * dppp(x - 2);
	for (int i = 3; i <= x; i++)
	{
		if (i % 2 == 0) {
			result += 2 * dppp(x - i);
		}
	}

	return ddd[x] = result;

}

void tileFilling()
{
	int n;
	cin >> n;
	cout << dppp(n) << endl;
}