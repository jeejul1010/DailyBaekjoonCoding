#include <iostream>

using namespace std;

int sugarDelivery()
{
	int N;
	cin >> N;

	int count_five = 0;
	int count_three = 0;
	int weight_five = 0;
	int weight_three = 0;

	while (weight_five < N)
	{
		weight_five += 5;
		count_five++;
	}

	if (weight_five == N)
	{
		return count_five;
	}
	else
	{
		while (count_five != 0)
		{
			weight_five -= 5;
			count_five--;

			while (weight_five+weight_three < N)
			{
				weight_three += 3;
				count_three++;
			}
			if (weight_five+weight_three == N)
			{
				return count_five + count_three;
			}
			else
			{
				count_three = 0;
				weight_three = 0;

			}
		}

		return -1;
		
	}
}

void sugarDeliveryMain()
{
	cout << sugarDelivery() << endl;
}