#include <iostream>
#include <algorithm>
#include <string>
#include "Sangsoo_2908.h"

using namespace std;

void sangSoo()
{
	string a, b;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	if (stoi(a) > stoi(b))
	{
		cout << a << endl;
	}
	else
	{
		cout << b << endl;
	}

}