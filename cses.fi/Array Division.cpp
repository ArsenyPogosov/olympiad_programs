#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n, k; cin >> n >> k;
	vector<long long> a(n);
	cin >> a[0];
	for (long long i = 1; i < n; ++i)
	{
		long long h; cin >> h;
		a[i] = a[i - 1] + h;
	}
	long long l = 0, r = a[n - 1];
	while (l + 1 < r)
	{
		long long m = (l + r) / 2;
		long long rr = 0;
		for (long long i = 0; i < k; ++i)
			rr = upper_bound(a.begin(), a.end(), m + (rr ? a[rr - 1] : 0)) - a.begin();
		if (rr < n)
			l = m;
		else
			r = m;
	}
	cout << r << '\n';

	return 0;
}