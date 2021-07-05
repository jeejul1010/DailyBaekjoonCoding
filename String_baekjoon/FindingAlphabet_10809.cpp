#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 101;

void findingAlphabet()
{
	char inputWord[MAX];
	cin >> inputWord;

	int alphaIndex[26];
	fill_n(alphaIndex, 26, -1);
	

	for (int i = 0; i < strlen(inputWord); i++)
	{
		if (alphaIndex[inputWord[i] - 'a'] == -1)
		{
			alphaIndex[inputWord[i] - 'a'] = i;
		}
		
	}

	for (int i = 0; i < 26; i++)
	{
		cout<<alphaIndex[i]<<' ';
	}
	cout << endl;
}