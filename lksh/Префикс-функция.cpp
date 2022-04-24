#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
#include <string>
using namespace std;

void PrefFunc(string &s, vector<int> &p)
{
	int n = s.size();
	p.resize(n);
	p[0] = 0;
	for (int i = 1; i < n; ++i)
	{
		int l = p[i - 1];
		while (l > 0 && s[l] != s[i])
			l = p[l - 1];
		if (s[l] == s[i])
			++l;
		p[i] = l;
	}
}

int main()
{
	string s;
	cin >> s;
	vector<int> p;
	PrefFunc(s, p);
	for (auto&i : p)
		cout << i << ' ';

	return 0;
}