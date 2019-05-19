#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
	int num, dis;
	map<int, int> inf;
	int coor, money,sum1=0;
	cin >> num >> dis;
	while (cin>>coor>>money)
	{
		inf[coor] = money;
	}

	for (map<int,int>::iterator it1=inf.begin();it1!=inf.end();it1++)
	{
		for (map<int, int>::iterator it2 = inf.begin(); it2 != inf.end(); it2++)
		{
			if ( (it1!=it2) && (abs((it1->first-it2->first))>dis) )
			{
				int sum2 = 0;
				sum2 = it1->second + it2->second;
				if (sum2>sum1)
				{
					sum1 = sum2;
				}
			}
		}
	}

	cout << sum1;
	return 0;


}