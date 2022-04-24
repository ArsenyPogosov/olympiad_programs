#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n, a, b; cin >> n >> a >> b;
	vector<long long> s(n + 1);
	for (long long i = 1; i <= n; ++i)
	{
		long long h; cin >> h;
		s[i] = s[i - 1] + h;
	}
	multiset<long long> mx; long long res = -1e18;
	for (long long i = n - a; i >= 0; --i)
	{
		mx.insert(s[i + a]);
		if (i + b + 1 <= n)
			mx.erase(mx.find(s[i + b + 1]));
		res = max(res, *prev(mx.end()) - s[i]);
	}
	cout << res << '\n';

	return 0;
}