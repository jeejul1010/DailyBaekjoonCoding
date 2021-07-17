#include <iostream>
#include "Dial_5622.h"

using namespace std;

void dial()
{
	int alphabet[26] = {
		2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9
	};

	string input;
	cin >> input;
	
	int minTime = 0;
	for (int i = 0; i < input.size(); i++)
	{
		minTime += alphabet[input[i] - 'A'] + 1;
	}

	cout << minTime << endl;
}