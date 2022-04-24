#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long t; cin >> t;
	while (t--)
	{
		long long n; cin >> n;
		vector<long long> a(n), b(n);
		for (long long i = 0; i < n; ++i) cin >> a[i] >> b[i];
		long long res = 0;
		for (long long i = 0; i < n; ++i)
		{
			res += max(0ll, a[(i + 1) % n] - b[i]);
			a[(i + 1) % n] = min(a[(i + 1) % n], b[i]);
		}
		long long m = 1e18;
		for (auto& i : a) m = min(m, i);
		cout << res + m << '\n';
	}
	return 0;
}