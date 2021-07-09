#include <iostream>
#include <string>
using namespace std;

const int alphaSize = 26;

void wordStudy()
{
	string input;
	cin >> input;

	for (int i = 0; i < input.size(); i++)
	{
		input[i] = toupper(input[i]);
	}

	int alphaCount[alphaSize] = { 0, };

	for (int i = 0; i < input.size(); i++)
	{
		alphaCount[input[i] - 'A']++;
	}

	int maxCount = 0;
	int max = alphaCount[0];
	int maxIndex = 0;
	for (int i = 1; i < alphaSize; i++)
	{
		if (max < alphaCount[i])
		{
			max = alphaCount[i];
			maxCount = 0;
			maxIndex = i;
		}
		else if (max == alphaCount[i])
		{
			maxCount++;
		}
	}

	if (maxCount > 0)
	{
		cout << '?' << endl;
	}
	else
	{
		char ch('A' + maxIndex);
		cout << ch << endl;
	}
	
}