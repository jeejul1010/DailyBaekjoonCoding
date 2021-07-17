#include <iostream>
#include <vector>
#include "GroupWordChecker_1316.h"
using namespace std;

void groupWordChecker()
{
	int n;
	cin >> n;

	vector<int> alphabet(26, 0);

	vector<string> words;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin >> temp;
		words.push_back(temp);
	}

	bool isGroup;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		char ch = words[i][0];
		fill(alphabet.begin(), alphabet.end(), 0);
		isGroup = true;
		for (int j = 1; j < words[i].size(); j++)
		{
			if (ch != words[i][j])
			{
				alphabet[ch - 'a'] = -1;
				ch = words[i][j];
				if (alphabet[ch - 'a'] == -1)
				{
					isGroup = false;
					break;
				}
			}
		}
		if (isGroup)
		{
			count++;
		}
	}

	cout << count << endl;
}