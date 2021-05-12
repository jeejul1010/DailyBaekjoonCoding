#include <iostream>
using namespace std;

void numberSum()
{
	int num;
	cin >> num;

	char* array = new char[num];
	cin >> array;

	int sum = 0;
	for (int i = 0; i < num; i++)
	{
		sum += (array[i] - '0');
	}

	cout << sum << endl;
}