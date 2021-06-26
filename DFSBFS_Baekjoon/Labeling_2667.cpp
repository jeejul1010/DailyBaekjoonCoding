#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include<algorithm>
using namespace std;

const int MAX = 25 * 25;

void grassfire(int i, int j, int label, char** arr, int** labImage, int* countLabel);

void labeling()
{
	int N;
	cin >> N;

	char** inputArr = new char* [N];
	for (int i = 0; i < N; i++)
	{
		inputArr[i] = new char[N];
		char* line = new char[N];
		cin >> line;
		strcpy(inputArr[i], line);
	}

	char** arr = new char* [N+2];
	for (int i = 1; i <= N; i++)
	{
		arr[i] = new char[N + 2];
		arr[i][0] = '0';
		arr[i][N + 1] = '0';
		for (int j = 1; j <= N; j++)
		{
			arr[i][j] = inputArr[i - 1][j - 1];
		}
		
	}
	arr[0] = new char[N + 2];
	arr[N+1] = new char[N + 2];
	for (int j = 0; j < N+2; j++)
	{
		arr[0][j] = '0';
		arr[N+1][j]='0';
	}

	int** labImage = new int* [N+2];
	for (int i = 0; i < N+2; i++)
	{
		labImage[i] = new int[N+2];
	}
	for (int i = 0; i < N+2; i++)
	{
		for (int j = 0; j < N+2; j++)
		{
			labImage[i][j] = 0;
		}
	}

	int labelNum = 0;
	int countLabel[MAX] = { 0, };
	
	for (int i = 1; i < N+1; i++)
	{
		for (int j = 1; j < N+1; j++)
		{
			if (arr[i][j] == '1' && labImage[i][j] == 0)
			{
				countLabel[++labelNum]++;
				labImage[i][j] = labelNum;
				grassfire(i, j, labelNum, arr, labImage, countLabel);

			}
		}
	}

	/*for (int i = 0; i < N+2; i++)
	{
		for (int j = 0; j < N+2; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < N+2; i++)
	{
		for (int j = 0; j < N+2; j++)
		{
			cout << labImage[i][j];
		}
		cout << endl;
	}*/

	cout << labelNum << endl;
	sort(countLabel + 1, countLabel + 1 + labelNum);
	for (int i = 1; i <= labelNum; i++)
	{
		cout << countLabel[i] << endl;
	}
}

void grassfire(int i, int j, int label, char** arr, int** labImage, int* countLabel)
{
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	for (int k = 0; k < 4; k++)
	{
		int x = i + dx[k];
		int y = j + dy[k];

		if (arr[x][y] == '1' && labImage[x][y] == 0)
		{
			countLabel[label]++;
			labImage[x][y] = label;
			grassfire(x, y, label, arr, labImage, countLabel);
			
		}
	}

}
