#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n; cin >> n;
	vector<long long> a(n), b(n), p(n);
	vector<pair<long long, pair<long long, long long>>>h(n * 2);
	for (long long i = 0; i < n; ++i)
	{
		cin >> h[i * 2].first >> h[i * 2 + 1].first;
		h[i * 2].second = { i, 0 };
		h[i * 2 + 1].second = { i, 1 };
		cin >> p[i];
	}
	sort(h.begin(), h.end());
	long long tek = 0;
	for (long long i = 0; i < n * 2; ++i)
	{
		if (i && h[i - 1].first != h[i].first) ++tek;
		if (h[i].second.second == 0)
			a[h[i].second.first] = tek;
		if (h[i].second.second == 1)
			b[h[i].second.first] = tek;
	}
	vector<long long> ord(n); iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](long long x, long long y) {return b[x] < b[y]; });
	vector<long long> dp(n * 2 + 1);
	long long from = 1;
	for (auto& i : ord)
	{
		for (; from < b[i]; ++from) dp[from] = dp[from - 1];
		dp[b[i]] = max({ dp[b[i]], (b[i] > 0 ? dp[b[i] - 1] : 0), (a[i] > 0 ? dp[a[i] - 1] : 0) + p[i] });
		from = b[i] + 1;
	}
	for (; from <= n * 2; ++from) dp[from] = dp[from - 1];
	cout << dp[n * 2] << '\n';

	return 0;
}