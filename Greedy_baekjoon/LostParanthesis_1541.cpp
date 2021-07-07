#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 51;

void lostParanthesis()
{
	char input[MAX];
	cin >> input;

	vector<int> nums;
	int localSum = 0;
	bool numStart = true;
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] == '-')
		{
			nums.push_back(localSum);
			localSum = 0;
			numStart = true;
		}
		else if (input[i] == '+')
		{
			numStart = true;
		}
		else if(numStart == true)
		{
			int newVal = atoi(&input[i]);
			localSum += newVal;
			numStart = false;
		}
	}
	nums.push_back(localSum);

	int minValue = nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		minValue -= nums[i];
	}
	cout << minValue << endl;
}