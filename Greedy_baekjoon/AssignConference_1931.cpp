#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 100000; //mergesort 위한

typedef struct Conference {
	int start;
	int finish;
}Conference;

bool cmp(const Conference& a, const Conference& b);
void merge(Conference conf[], int f, int mid, int l);
void mergeSort(Conference conf[], int first, int last);

void assignConference()
{
	int N; //회의 수
	cin >> N;

	Conference *conf = new Conference[N];

	for (int i = 0; i < N; i++)
	{
		cin >> conf[i].start >> conf[i].finish;
	}

	//mergeSort(conf, 0, N - 1); //합병정렬

	sort(conf, conf + N, cmp);

	/*for (int i = 0; i < N; i++)
	{
		cout << conf[i].start << ' ' << conf[i].finish << endl;
	}*/

	int current = 0;
	vector<Conference> allocate;
	allocate.push_back(conf[current]);

	for (int i = 1; i < N; i++)
	{
		if (conf[i].finish < conf[current].finish)
		{
			allocate.pop_back();
			allocate.push_back(conf[i]);
			current = i;
		}
		else if (conf[current].finish <= conf[i].start)
		{
			allocate.push_back(conf[i]);
			current = i;
		}

	}

	/*for (int i = 0; i < allocate.size(); i++)
	{
		cout << allocate[i].start << ' ' << allocate[i].finish << endl;
	}*/

	cout << allocate.size() << endl;

	delete[]conf;

}

bool cmp(const Conference& a, const Conference& b)
{
	if (a.start == b.start)
	{
		return a.finish < b.finish;
	}
	return a.start < b.start;
}

void merge(Conference conf[], int f, int mid, int l)
{
	Conference* temp = new Conference[MAX];
	int first1 = f;
	int last1 = mid;
	int first2 = mid + 1;
	int last2 = l;

	int index = f;
	for (; (first1 <= last1) && (first2 <= last2); index++)
	{
		if (conf[first1].start < conf[first2].start)
		{
			temp[index].start = conf[first1].start;
			temp[index].finish = conf[first1].finish;
			first1++;
		}
		else if (conf[first1].start == conf[first2].start)
		{
			if (conf[first1].finish < conf[first2].finish)
			{
				temp[index].start = conf[first1].start;
				temp[index].finish = conf[first1].finish;
				first1++;
			}
			else
			{
				temp[index].start = conf[first2].start;
				temp[index].finish = conf[first2].finish;
				first2++;
			}
		}
		else
		{
			temp[index].start = conf[first2].start;
			temp[index].finish = conf[first2].finish;
			first2++;
		}
	}

	for (; first1 <= last1; first1++, index++)
	{
		temp[index].start = conf[first1].start;
		temp[index].finish = conf[first1].finish;
	}

	for (; first2 <= last2; first2++, index++)
	{
		temp[index].start = conf[first2].start;
		temp[index].finish = conf[first2].finish;
	}

	for (index = f; index <= l; index++)
	{
		conf[index].start = temp[index].start;
		conf[index].finish = temp[index].finish;
	}

}

void mergeSort(Conference conf[], int first, int last)
{
	if (first < last)
	{
		int middle = (first + last) / 2;
		mergeSort(conf, first, middle);
		mergeSort(conf, middle + 1, last);
		merge(conf, first, middle, last);
	}
}