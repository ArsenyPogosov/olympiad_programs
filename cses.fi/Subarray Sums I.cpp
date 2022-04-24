#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n, x; cin >> n >> x;
	vector<long long> a(n);
	cin >> a[0];
	for (long long i = 1; i < n; ++i)
	{
		long long h; cin >> h;
		a[i] = a[i - 1] + h;
	}
	map<long long, long long> mp;
	long long res = 0;
	for (long long i = n - 1; i >= 0; --i)
	{
		if (mp.find(a[i] + x) != mp.end())
			res += mp[a[i] + x];
		++mp[a[i]];
	}
	res += mp[x];
	cout << res << '\n';

	return 0;
}