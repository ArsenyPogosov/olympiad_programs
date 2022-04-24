#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
#include <string>
using namespace std;

void Zfunc(string &s, vector<int> &z)
{
	int n = s.size();
	z.resize(n);
	z[0] = n;
	int l = 0, r = 0;
	for (int i = 1; i < n; ++i)
	{
		z[i] = max(0, min(z[i - l], r - i + 1));
		while (s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r)
		{
			l = i;
			r = i + z[i] - 1;
		}
	}
}

int main()
{
	string s;
	cin >> s;
	vector<int> z;
	Zfunc(s, z);
	for (auto&i : z)
		cout << i << ' ';

	return 0;
}