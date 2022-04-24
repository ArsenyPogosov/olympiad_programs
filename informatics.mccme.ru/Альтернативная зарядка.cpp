#include <iostream>
//#include <vector>
//#include <queue>
#include <list>
//#include <map>
//#include <algorithm>
#include <cmath>
//#include <string>
using namespace std;

bool TorD(const list<int>& T, const list<int>&D, long long cperm, double m, double c)
{
	if (T.empty())
		return false;
	if (D.empty())
		return true;

	if (T.front() - c <= (D.front() - m)*cperm)
		return true;
	return false;
}

int main()
{
	int n;
	cin >> n;
	list<int> T, D;
	for (int i = 0; i < n; ++i)
	{
		char h;
		int x;
		cin >> h >> x;
		if (h == 'T')
			T.push_back(x);
		if (h == 'D')
			D.push_back(x);
	}
	T.sort();
	D.sort();
	long long cperm = 1;
	double m = 0, c = 0;
	while ((!T.empty()) || (!D.empty()))
	{
		if (TorD(T, D, cperm, m, c))
		{
			m += double(T.front() - c) / cperm;
			c = T.front();
			T.pop_front();
		}
		else
		{
			c += (D.front() - m) * cperm;
			m = D.front();
			D.pop_front();
		}
		++cperm;
	}
	c += (1000 - m)*cperm;
	cout << fixed << (long long)(round(c));

	return 0;
}