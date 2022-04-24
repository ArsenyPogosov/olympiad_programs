#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> a(n), pos(n);
	for (auto& i : a) cin >> i;
	iota(pos.begin(), pos.end(), 0);
	sort(pos.begin(), pos.end(), [&](int x, int y) { return a[x] > a[y]; });
	vector<int> thislen(n);
	int maxlen = 0;
	long long res;
	for (int i = 0; i < n; ++i)
	{
		int L, R; L = R = pos[i];
		if (pos[i] > 0)
			L -= thislen[pos[i] - 1];
		if (pos[i] < n - 1)
			R += thislen[pos[i] + 1];
		thislen[L] = thislen[R] = R - L + 1;
		maxlen = max(maxlen, R - L + 1);
		if (i == n - 1 || a[pos[i]] != a[pos[i + 1]])
			res = max(res, maxlen * 1ll * a[pos[i]]);
	}
	cout << res << '\n';

	return 0;
}