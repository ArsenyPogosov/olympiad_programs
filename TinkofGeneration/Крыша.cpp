#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long n; cin >> n;
	vector<long long> a(n);
	for (auto& i : a) cin >> i;

	long long res = 1e18;
	for (long long i = 0; i < n; ++i)
	{
		vector<long long> na(n);
		long long cnt = 0;
		for (long long j = 0; j < n; ++j)
		{
			na[j] = a[j] + abs(i - j);
			cnt += abs(i - j);
		}
		sort(na.begin(), na.end());
		vector<long long> ps(n + 1);
		partial_sum(na.begin(), na.end(), ps.begin() + 1);
		for (long long j = 0; j < n; ++j)
			if (na[j] >= max(i + 1, n - i))
				res = min(res, j * 1ll * na[j] - ps[j] + (ps[n] - ps[j]) - (n - j) * 1ll * na[j]);
	}

	cout << res << '\n';

	return 0;
}