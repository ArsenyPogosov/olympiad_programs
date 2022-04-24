#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
#include <string>
using namespace std;

void Zfunc(string &s, vector<long long> &z)
{
	long long n = s.size();
	z.resize(n);
	z[0] = n;
	long long l = 0, r = 0;
	for (long long i = 1; i < n; ++i)
	{
		z[i] = max(0ll, min(z[i - l], r - i + 1));
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
	long long n = s.size();
	vector<long long> z;
	Zfunc(s, z);
	long long count = 1;
	for (long long i = 1; i < n; ++i)
	{
		z[i] += i;
		count += z[i] / i;
	}
	cout << count;

	return 0;
}