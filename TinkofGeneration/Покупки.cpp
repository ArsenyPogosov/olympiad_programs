#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long n, k; cin >> n >> k;

	vector<long long> a(n);
	for (auto& i : a) cin >> i;
	a.push_back(0); ++n;

	vector<long long> ps(n + 1);
	partial_sum(a.begin(), a.end(), ps.begin() + 1);

	multiset<long long> s;
	vector<long long> dp(n);

	for (int i = n - 1; i >= 0; --i)
	{
		dp[i] = a[i];
		if (s.size())
			dp[i] += *s.begin() - ps[i + 1] / 2;
		if (i + k + 1 < n)
			s.erase(s.find(ps[i + k + 1] / 2 + dp[i + k + 1]));
		s.insert(ps[i] / 2 + dp[i]);
	}

	cout << dp[0] << '\n';

	return 0;
}