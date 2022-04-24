#include <iostream>
#include <map>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
#include <cmath>
//#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int res = 0;
	int count = 0;
	map<pair<int, int>, int> s;
	for (int i = 1; i <= n; ++i)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (s.find({ x1, y1 }) != s.end())
		{
			if (s[{x1, y1}] == 1)
			{
				--count;
				++s[{x1, y1}];
			}
		}
		else
		{
			s[{ x1, y1 }] = 1;
			++count;
		}
		if (s.find({ x2, y2 }) != s.end())
		{
			if (s[{x2, y2}] == 1)
			{
				--count;
				++s[{x2, y2}];
			}
		}
		else
		{
			s[{ x2, y2 }] = 1;
			++count;
		}
		if (count == 0 && res == 0)
			res = i;
	}
	cout << res;

	return 0;
}