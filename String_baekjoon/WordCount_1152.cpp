#include <iostream>
#include <string>
#include "WordCount_1152.h"

using namespace std;


void wordCount()
{
	string input;
	getline(cin, input);

	int i = 0;
	int wordCount = 0;
	bool wordStart = true;
	while (input[i] != '\0')
	{
		if (wordStart && input[i] != ' ')
		{
			wordCount++;
			wordStart = false;
		}
		else if (input[i] == ' ')
		{
			wordStart = true;
		}
		i++;
	}

	cout << wordCount << endl;
}