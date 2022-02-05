#include <iostream>
#include <vector>

using namespace std;

void dividenconquer(int rowIndex, int colIndex, int num, vector<vector<int>>& matrix, int count[2])
{
	int firstColor = matrix[rowIndex][colIndex];

	if (num == 1)
	{
		count[firstColor]++;
		return;
	}
	
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (firstColor != matrix[rowIndex + i][colIndex + j])
			{
				dividenconquer(rowIndex, colIndex, num / 2, matrix, count);
				dividenconquer(rowIndex + (num/2), colIndex, num / 2, matrix, count);
				dividenconquer(rowIndex, colIndex + (num/2), num / 2, matrix, count);
				dividenconquer(rowIndex + (num/2), colIndex + (num/2), num / 2, matrix, count);
				return;
			}
		}
		
	}

	count[firstColor]++;
}

void coloredPaper()
{
	int num;
	cin >> num;
	vector<vector<int>> colorMatrix;

	for (int i = 0; i < num; i++)
	{
		vector<int> row;
		int temp;

		for (int j = 0; j < num; j++)
		{
			cin >> temp;
			row.push_back(temp);
		}

		colorMatrix.push_back(row);
	}

	/*for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			cout << colorMatrix[i][j] << ' ';
		}
		cout << endl;
	}*/

	int count[2] = { 0, };
	int rowIndex = 0;
	int colIndex = 0;

	dividenconquer(rowIndex, colIndex, num, colorMatrix, count);

	for (int i = 0; i < 2; i++)
	{
		cout << count[i] << endl;
	}

}