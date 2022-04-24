#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long INF = 1e18;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<int> a(n), d(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i] >> d[i];

	int q; cin >> q;
	while (q--)
	{
		int l, r, k; cin >> l >> r >> k; --l; --r;

		long long res = INF;
		for (int i = l; i <= r; ++i)
			res = min(res, a[i] + d[i] * 1ll * (k - 1));

		cout << res << '\n';
	}

	return 0;
}