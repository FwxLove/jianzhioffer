#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int &a, int &b)
{
	return a > b;
}

int main01()
{
	vector<int> a, b;
	int len,n,sum=0;
	cin >> len;
	for (vector<int>::size_type i = 0; i < len; i++)
	{
		cin >> n;
		a.push_back(n);
	}
	for (vector<int>::size_type i = 0; i < len; i++)
	{
		cin >> n;
		b.push_back(n);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(),compare);


	for (vector<int>::size_type i = 0; i < len; i++)
	{
		sum = sum + a[i] * b[i];
	}
	cout << sum << endl;
	return 0;
}