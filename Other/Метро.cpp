#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n, m; cin >> n >> m; ++n;

	vector<long long> a(n - 1);
	for (auto& i : a) cin >> i;

	for (long long ttt = 0; ttt < m; ++ttt)
	{
		long long l, r, k; cin >> l >> r >> k; --l; --r;
		vector<long long> ord(r - l);
		iota(ord.begin(), ord.end(), l);
		sort(ord.begin(), ord.end(), [&](long long x, long long y) {return a[x] < a[y]; });
		for (auto& i : ord)
		{
			k -= (i - l + 1) * (r - i);
			if (k <= 0)
			{
				cout << a[i] << '\n';
				break;
			}
		}
	}

	return 0;
}