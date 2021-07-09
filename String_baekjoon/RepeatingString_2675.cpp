#include <iostream>
#include <vector>
using namespace std;

const int MAX = 21;

void repeatingString()
{
	int testNum;
	cin >> testNum;

	int r;
	vector<int> rArr;
	vector<char*> sArr;
	for (int i = 0; i < testNum; i++)
	{
		char* s = new char[MAX];
		cin >> r >> s;
		rArr.push_back(r);
		sArr.push_back(s);
	}
	for (int i = 0; i < testNum; i++)
	{
		char* temp = sArr[i];
		int j = 0;
		while (temp[j] != '\0')
		{
			for (int k = 0; k < rArr[i]; k++)
			{
				cout << temp[j];
			}
			j++;
		}
		cout << endl;
	}

	for (int i = 0; i < sArr.size(); i++)
	{
		delete[] sArr[i];
	}
	
}