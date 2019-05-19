#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

string oper(string &s, map<char, int> &def)
{
	string res = s;
	for (map<char, int>::iterator i = def.begin(); i != def.end(); i++)
	{
		if (i->second >= 2)
		{
			auto it1 = find(res.begin(), res.end(), i->first);
			res.erase(it1);
			if (res<s)
			{
				return res;
			}
			else
			{
				return s;
			}
		}
	}


	return res;
}