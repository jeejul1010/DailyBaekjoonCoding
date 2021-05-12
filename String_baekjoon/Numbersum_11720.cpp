#include <iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;

	int* array = new int[num];
	for (int i = 0; i < num; i++)
	{
		cin >> array[i];
	}

	int sum = 0;
	for (int i = 0; i < num; i++)
	{
		sum += array[i];
	}

	cout << sum << endl;

	return 0;
}