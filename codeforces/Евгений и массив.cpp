#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	long long n; cin >> n; ++n;
	vector<long long> s(n);
	for (long long i = 1; i < n; ++i)
	{
		long long h; cin >> h;
		s[i] = s[i - 1] + h;
	}
	unordered_map<long long, long long> la;
	long long tl = 1, res = 0; la[s[0]] = 0;
	for (long long i = 1; i < n; ++i)
	{
		if (la.find(s[i]) != la.end())
			tl = max(tl, la[s[i]] + 2);
		la[s[i]] = i;
		res += max(0ll, i - tl + 1);
	}
	cout << res << '\n';

	return 0;
}