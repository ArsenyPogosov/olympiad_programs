#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long INF = 1e18;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long n; cin >> n;
	vector<long long> h(n), a(n);
	for (auto& i : h) cin >> i;
	for (auto& j : a) cin >> j;

	vector<long long> ord(n); iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](long long x, long long y){ return h[x] < h[y]; });

	long long bh = -1, br = INF, sa = accumulate(a.begin(), a.end(), 0ll), sla = 0, tr = 0, was = h[ord[0]];
	for (long long i = 0; i < n; ++i) tr += a[i] * (h[i] - was);
	for (auto& i : ord)
	{
		long long d = (h[i] - was);
		tr += sla * d - (sa - sla) * d;
		sla += a[i];
		was = h[i];

		if (br > tr)
		{
			br = tr;
			bh = h[i];
		}
	}

	cout << bh << ' ' << br << '\n';

	return 0;
}