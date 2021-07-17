#include <iostream>
#include "Croatia_2941.h"

using namespace std;

void croatia()
{
	string input;
	cin >> input;

	int count = 0;
	for (int i = 0; i < input.size(); i++)
	{
		switch (input[i])
		{
		case 'c':
			if (input[i + 1] == '=' || input[i + 1] == '-')
			{
				i++;
			}
			break;
		case 'd':
			if (input[i + 1] == 'z' && input[i + 2] == '=')
			{
				i += 2;
			}
			else if (input[i + 1] == '-')
			{
				i++;
			}
			break;
		case 'l': case 'n':
			if (input[i + 1] == 'j')
			{
				i++;
			}
			break;
		case 's': case'z':
			if (input[i + 1] == '=')
			{
				i++;
			}
			break;
		default:
			break;
		}
		count++;
	}

	cout << count << endl;
}
